// Copyright 2023 University of Engineering and Technology Lahore.
// Licensed under the Apache License, Version 2.0, see LICENSE file for details.
// SPDX-License-Identifier: Apache-2.0
//
// Description:  Prefetch stage; an instruction fetch fifo to enable halfword-aligned access.
//
// Author: Ateeb Tahir, RA @ DDRC, UET Lahore
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

//FLip-flops declarations
logic   [`XLEN-1:0]     fetch_fifo      [2]; //fifo direction from 0 to 1
logic         [1:0]     fifo_valid;
logic   [`XLEN-1:0]     data_out;
logic   [`XLEN-1:0]     data_in;
logic   [`XLEN-1:0]     pc_fifo;


logic   [`XLEN-1:0]     pc_incr;
logic                   pc_hword;

logic                   fifo_clr;
logic                   fifo_update;

logic                   stall;


//Receiving the data from icache and sending it to IF stage
assign pf2if_data_o.instr = data_out;
assign data_in   = icache2pf_i.ack ? icache2pf_i.r_data : `INSTR_NOP;

//Icache-MMU Logic to update signals for new address
assign pf2mmu_o.i_vaddr = if2pf_i.instr_req ? pc_fifo : 32'b0;
assign pf2mmu_o.i_req   = (if2pf_i.instr_req & ~(&fifo_valid)) ?`IMEM_INST_REQ : 1'b0; 

//Icache-Prefetch Logic to update signals for new instruction
assign pf2icache_o.addr = mmu2pf_i.i_paddr[`XLEN-1:0]; // pc_next; 
assign pf2icache_o.req  = mmu2pf_i.i_hit;              // `IMEM_INST_REQ;

assign pf2if_ctrl_o.stall = ~(if2pf_i.clear) &(stall | (~icache2pf_i.ack & pf2icache_o.req));

//Local signals
assign fifo_clr = if2pf_i.clear | ~rst_n;  //TODO: clear/stall/flush signals here to clear the fifo
assign fifo_update = icache2pf_i.ack | fifo_clr;

//If PC is halfword it'll align it to the next 4th multiple
//assign pc_incr = pc_hword ? 4'd2 : 4'd4; 
assign pc_hword  = if2pf_i.pc_ff[1];

assign stall = ~fifo_valid[1];


// FIFO Logic:
//
// The FIFO implemented here has 2 full-word entries, but the instructions 
// in each entry might be half-word aligned (due to compressed instructions), 
// Therefore to access them properly, we concatenate the parts of both entries,
// as shown in the example below:
//              | 31               16 | 15               0 |
// FIFO entry 0 | Instr 1 [15:0]      | Instr 0 [15:0]     |
// FIFO entry 1 | Instr 2 [15:0]      | Instr 1 [31:16]    |

always_comb begin
    
    // In case of any jump or reset, the fifo will be cleared.
    // In this case it'll stall the pipeline and fill the fifo first,
    // at the expense of 1 (or 2) clock cycle(s).
    if (~(fifo_valid[1])) begin
        pc_incr = fifo_valid[0] ? 32'd0 : 32'd4;
    end


    //State if jump/invalid instruction or reset occurs
    if (fifo_clr) begin
        pf2if_ctrl_o.fifo_valid = 2'b00;
        pf2if_ctrl_o.ack        = 1'b0;
    end

    if (pc_hword) begin
        data_out = {fetch_fifo[0][31:16], fetch_fifo[1][15:0]};
        pf2if_ctrl_o.ack = &fifo_valid;
        pc_incr = 32'd2; 
    end else begin
        data_out = fetch_fifo[1];
        pf2if_ctrl_o.ack = fifo_valid[1];
        pc_incr = 32'd4;
    end
end


always_comb begin 
     
     if (fifo_clr | (fifo_valid == 2'b0))  pc_fifo = if2pf_i.pc_ff ;
     else if (fifo_valid == 2'b01)  pc_fifo = if2pf_i.pc_ff + pc_incr;
     else if (pc_hword) pc_fifo = if2pf_i.pc_ff - pc_incr;

    end
    
always_ff @ (posedge clk, negedge rst_n) begin

    //PC realignment for the icache access
    //Note that this pc is different from the actual pc from the fetch onward stages
   if (fifo_clr) begin
        fetch_fifo[1] <= 32'b0;
        fetch_fifo[0] <= 32'b0;;
        
        fifo_valid[1] <= 1'b0;
        fifo_valid[0] <= 1'b0;
   end
    else begin 
    //FIFO updating at each cycle
    if (fifo_update) begin
        //Updating the fifo
        fetch_fifo[1] <= fetch_fifo[0];
        fetch_fifo[0] <= data_in;
        //Updating the valid signals
        fifo_valid[1] <= fifo_valid[0];
        fifo_valid[0] <= icache2pf_i.ack;

    end else begin
        //Retaining the values in case if instr request is not made by the fetch
        fetch_fifo[1] <= fetch_fifo[1];
        fetch_fifo[0] <= fetch_fifo[0];

        fifo_valid[1] <= fifo_valid[1];
        fifo_valid[0] <= fifo_valid[0];
        
    end
    end
end


endmodule : prefetch



