// Copyright 2023 University of Engineering and Technology Lahore.
// Licensed under the Apache License, Version 2.0, see LICENSE file for details.
// SPDX-License-Identifier: Apache-2.0
//
// Description:  Prefetch stage; an instruction fetch fifo to enable halfword-aligned access.
//
// Author: Ateeb Tahir, RA @ DDRC, UET Lahore
// Date: 25.8.2023


`ifndef VERILATOR
`include "../../defines/pcore_interface_defs.svh"
`include "../../defines/mmu_defs.svh"
`include "../../defines/cache_defs.svh"
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
logic   [`XLEN-1:0]  fetch_fifo      [2]; //fifo direction from 0 to 1
logic         [1:0]  fifo_valid;
logic   [`XLEN-1:0]  data_out;
logic   [`XLEN-1:0]  data_in;
logic   [`XLEN-1:0]  pc_fifo;


logic    [3:0]  pc_incr;
logic           pc_misalign;

logic           fifo_clr;
logic           fifo_update;

logic           stall;

//Receiving the data from icache and sending it to IF stage
assign pf2if_data_o.instr = data_out;
assign data_in   = icache2pf_i.ack ? icache2pf_i.instr : `INSTR_NOP;

//Icache-MMU Logic to update signals for new address
assign pf2mmu_o.i_vaddr = pc_fifo;
assign pf2mmu_o.i_req   = `IMEM_INST_REQ; 

//Icache-Prefetch Logic to update signals for new instruction
assign pf2icache_o.addr = mmu2pf_i.i_paddr[`XLEN-1:0]; // pc_next; 
assign pf2icache_o.req  = mmu2pf_i.i_hit;              // `IMEM_INST_REQ;

assign pc_misalign  = if2pf_i.pc_ff[1];
//assign pc_fifo = if2pf_i.pc_ff + pc_incr;
assign pf2if_ctrl_o.stall = ~fifo_valid[1];
assign fifo_clr = if2pf_i.clear || ~rst_n;  //TODO: Add clear signals from jump/branch and CSR here
assign fifo_update = if2pf_i.instr_req;     //Related signals here


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
    if (pc_misalign) begin
        data_out = {fetch_fifo[1][15:0], fetch_fifo[0][31:16]};
        pf2if_ctrl_o.ack = &fifo_valid;
    end else begin
        data_out = fetch_fifo[1];
        pf2if_ctrl_o.ack = fifo_valid[1];
    end

    //In case of jump, it gives one stall cycle to fill the fifo.
    //Meanwhile the latest fetched instruction will bypass the fifo.
    //  (Not sure about this logic, either too optimised or stupid)
    if (~(fifo_valid[1])) begin
        pc_incr = 4'b0;
        data_out = fetch_fifo[0];
    end
end

always_ff @ (posedge clk, negedge rst_n) begin

    //PC realignment for the icache access
    pc_fifo = if2pf_i.pc_ff + pc_incr;

    if (fifo_clr) begin
        pf2if_ctrl_o.fifo_valid = 2'b00;
        pf2if_ctrl_o.ack        = 1'b0;

    end else if (fifo_update) begin
        //Updating the fifo
        fetch_fifo[1] <= fetch_fifo[0];
        fetch_fifo[0] <= data_in;
        //Updating the valid signals
        fifo_valid[1] <= fifo_valid[0];
        fifo_valid[0] <= 1'b1;

        if (pc_misalign) begin
            pc_incr = 4'd6;
        end else begin
            pc_incr = 4'd8;
        end
    end
end


endmodule : prefetch