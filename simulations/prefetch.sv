// Copyright 2023 University of Engineering and Technology Lahore.
// Licensed under the Apache License, Version 2.0, see LICENSE file for details.
// SPDX-License-Identifier: Apache-2.0
//
// Description:  Prefetch stage; an instruction fetch fifo to enable halfword-aligned access.
//
// Author: Ateeb Tahir, RA @ DDRC UET Lahore
// Date: 25.8.2023



`ifndef VERILATOR
`include "pcore_interface_defs.svh"
`include "mmu_defs.svh"
`include "cache_defs.svh"
`else
`include "pcore_interface_defs.svh"
`include "mmu_defs.svh"
`include "cache_defs.svh"
`endif


module prefetch (

    input   logic                                   clk,
    input   logic                                   rst_n,

    output          type_pf2if_ctrl_s               pf2if_ctrl_o,
    output          type_pf2if_data_s               pf2if_data_o,
    input   wire    type_if2pf_s                    if2pf_i,

    output          type_if2icache_s                pf2icache_o,     // Instruction cache memory request
    input   wire    type_icache2if_s                icache2pf_i,     // Instruction cache memory response

    output          type_if2mmu_s                   pf2mmu_o,        // Instruction memory request
    input   wire    type_mmu2if_s                   mmu2pf_i         // Instruction memory response
);


logic   [`XLEN-1:0]     fetch_fifo      [2]; //fifo direction from 0 to 1
logic   [`XLEN-1:0]     value_pc        [2];
logic         [1:0]     fifo_valid;
logic   [`XLEN-1:0]     data_out;
logic   [`XLEN-1:0]     data_in;
logic   [`XLEN-1:0]     pc_prefetch;


logic         [3:0]     pc_incr;
logic                   pc_hword;

logic                   fifo_clr;
logic                   fifo_update;

logic                   mismatch_fault;
//logic                   stall;


//Receiving the data from icache and sending it to IF stage
assign pf2if_data_o.instr = data_out;
assign data_in   = icache2pf_i.ack ? icache2pf_i.r_data : `INSTR_NOP;

//Icache-MMU Logic to update signals for new address
assign pf2mmu_o.i_vaddr = if2pf_i.instr_req ? pc_prefetch : 32'b0;
assign pf2mmu_o.i_req   = if2pf_i.instr_req ?`IMEM_INST_REQ : 1'b0; 

//Icache-Prefetch Logic to update signals for new instruction
assign pf2icache_o.addr = mmu2pf_i.i_paddr[`XLEN-1:0]; // pc_next; 
assign pf2icache_o.req  = mmu2pf_i.i_hit;              // `IMEM_INST_REQ;

assign pf2if_ctrl_o.stall = ~fifo_valid[1];

//Local signals
assign fifo_clr = ~rst_n | if2pf_i.clear | mismatch_fault;  //TODO: Clear/stall/flush signals from other stages to be added here

assign pf2if_ctrl_o.fifo_valid = fifo_valid;

//If PC is halfword it'll align it to the next 4th multiple
//assign pc_incr = pc_hword ? 4'd2 : 4'd4; 
assign pc_hword  = if2pf_i.pc_ff[1];

//assign stall = ~fifo_valid[1];


// FIFO Logic:
//
// The FIFO implemented here has 2 full-word entries, but the instructions 
// in each entry might be half-word aligned (due to compressed instructions), 
// Therefore to access them properly, we concatenate the parts of both entries,
// as shown in the example below:
//              | 31               16 | 15               0 |
// FIFO entry 0 | Instr 1 [15:0]      | Instr 0 [15:0]     |
// FIFO entry 1 | Instr 2 [15:0]      | Instr 1 [31:16]    |


//Combinational block to handle fifo updating
always_comb begin
    if ((icache2pf_i.ack & if2pf_i.req) | fifo_clr) begin
        fifo_update = (if2pf_i.is_comp & ~pc_hword) ? 1'b0 : 1'b1;
    end else begin
        fifo_update = 1'b0;
    end
end

//Combinational block to manage fifo signals
always_comb begin

    //Note: this pc is different from the actual pc from the fetch stage
    pc_prefetch = if2pf_i.pc_ff + pc_incr;

    // In case of any jump or reset, the fifo will be cleared.
    // In this case it'll stall the pipeline and fill the fifo first,
    // at the expense of extra clock cycle(s).
    if (~(fifo_valid[1])) begin
        pc_incr = fifo_valid[0] ? 4'd0 : 4'd4;
    end

    //State if jump/invalid instruction or reset occurs
    if (fifo_clr) begin
        pf2if_ctrl_o.ack = 1'b0;
        pc_incr = 4'd0;
        mismatch_fault = 1'b0;
    end

    if (pc_hword) begin
        if (value_pc[1] == (if2pf_i.pc_ff - 2'd2)) begin
            data_out = {fetch_fifo[0][31:16], fetch_fifo[1][15:0]};
            pf2if_ctrl_o.ack = &fifo_valid;
            pc_incr = 4'd6; 
        end else begin
            pf2if_ctrl_o.ack = 1'b0;
            mismatch_fault = 1'b1;
        end

    end else begin
        if (value_pc[1] == if2pf_i.pc_ff) begin 
            data_out = fetch_fifo[1];
            pf2if_ctrl_o.ack = fifo_valid[1];
            pc_incr = 4'd8;
        end else begin
            pf2if_ctrl_o.ack = 1'b0;
            mismatch_fault = 1'b1;
        end
    end
end

//FIFO Flip-FLop logic
always_ff @ (posedge clk, negedge rst_n) begin

    if (~rst_n) begin
        fetch_fifo[1] <= 32'b0;                 //32-bit fifo registers
        fetch_fifo[0] <= 32'b0;                 //32-bit fifo registers
        
        fifo_valid[1] <= 1'b0;                  //valid bits
        fifo_valid[0] <= 1'b0;                  //valid bits

        value_pc[1]   <= 32'b0;                 //32-bit PC registers
        value_pc[0]   <= 32'b0;                 //32-bit PC registers

    //FIFO updating at each cycle
    end else if (fifo_update) begin
        fetch_fifo[1] <= fetch_fifo[0];         //32-bit fifo registers
        fetch_fifo[0] <= data_in;               //32-bit fifo registers

        fifo_valid[1] <= fifo_valid[0];         //valid bits
        fifo_valid[0] <= icache2pf_i.ack;       //valid bits

        value_pc[1]   <= value_pc[0];           //32-bit PC registers
        value_pc[0]   <= pf2mmu_o.i_vaddr;      //32-bit PC registers

        //Retains the values in case if instr request is not made by IF
    end else begin
        fetch_fifo[1] <= fetch_fifo[1];         //32-bit fifo registers
        fetch_fifo[0] <= fetch_fifo[0];         //32-bit fifo registers

        fifo_valid[1] <= fifo_valid[1];         //valid bits
        fifo_valid[0] <= fifo_valid[0];         //valid bits
        
        value_pc[1]   <= value_pc[1];           //32-bit PC registers
        value_pc[0]   <= value_pc[0];           //32-bit PC registers
    end
end


endmodule : prefetch















