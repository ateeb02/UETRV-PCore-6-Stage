`include "pcore_interface_defs.svh"
`include "pcore_config_defs.svh"
`include "mmu_defs.svh"
`include "cache_defs.svh"


module tb_prefetch;
	logic clk,reset;
	type_if2pf_s if2pf_i;
	type_pf2if_ctrl_s pref2if_ctrl_o;
	type_pf2if_data_s pref2if_data_o;
	type_if2icache_s pref2icache_o;
	type_icache2if_s icache2pref_i;
	type_if2mmu_s pref2mmu_o;
	type_mmu2if_s mmu2pref_i;

	prefetch DUT(	.clk(clk),
			.rst_n(reset),
			.mmu2pf_i(mmu2pref_i),
			.pf2mmu_o(pref2mmu_o), 
			.icache2pf_i(icache2pref_i),
			.if2pf_i(if2pf_i),
			.pf2icache_o(pref2icache_o),
			.pf2if_data_o(pref2if_data_o), 
			.pf2if_ctrl_o(pref2if_ctrl_o));
	initial begin
		clk=0;
		forever #5 clk=~clk;
	end
	initial begin		
		reset = 1;
		
		mmu2pref_i='0;
		icache2pref_i='0;
		if2pf_i='0;

		@(posedge clk);
		reset = 0;
		if2pf_i.clear =1'b1;

		@(posedge clk);
		reset =1;
		if2pf_i.clear=1'b0;
		@(posedge clk);
		if2pf_i.pc_ff=32'h0;
		if2pf_i.instr_req =1'b1;
		if2pf_i.is_comp =1'b0;
		if2pf_i.clear =1'b0;

		@(posedge pref2mmu_o.i_req);
		mmu2pref_i.i_paddr=32'h4;
		mmu2pref_i.i_hit=1'b1;
		mmu2pref_i.i_page_fault=1'b0;

		@(posedge pref2icache_o.req);
		
		icache2pref_i.r_data=32'h00200093;
		icache2pref_i.ack=1'b1;

		@(posedge clk) 
		mmu2pref_i.i_hit=1'b0;
		icache2pref_i.ack =0;
		if (pref2mmu_o.i_req) begin 
			mmu2pref_i.i_paddr = 32'h6;
			mmu2pref_i.i_hit =1'b1;
		end


		@(negedge clk) 
		if(pref2icache_o.req & (pref2icache_o.addr == 32'h6))
			begin 
				icache2pref_i.ack =1'b1;
				icache2pref_i.r_data = 32'h1234_3321;

			end
		

		

		
		// @(posedge clk);
		// if2pf_i.pc_ff=32'h4;
		// if2pf_i.instr_req =1'b1;
		// if2pf_i.is_comp =1'b0;
		// if2pf_i.clear =1'b0;
		
		// icache2pref_i.r_data=32'h00400113;
		// icache2pref_i.ack=1'b1;
		// mmu2pref_i.i_paddr=32'h4;
		// mmu2pref_i.i_hit=1'b1;
		// mmu2pref_i.i_page_fault=1'b0;
		// @(posedge clk);
		// if2pf_i.pc_ff=32'h6;
		// if2pf_i.instr_req =1'b1;
		// if2pf_i.is_comp =1'b1;
		// if2pf_i.clear =1'b0;

		// icache2pref_i.r_data=32'h002081B3;
		// icache2pref_i.ack=1'b1;
		// mmu2pref_i.i_paddr=32'h6;
		// mmu2pref_i.i_hit=1'b1;
		// mmu2pref_i.i_page_fault=1'b0;
		// @(posedge clk);
		// if2pf_i.pc_ff=32'hA;
		// if2pf_i.instr_req =1'b1;
		// if2pf_i.is_comp =1'b0;
		// if2pf_i.clear =1'b0;

		// mmu2pref_i.i_paddr=32'hA;
		// mmu2pref_i.i_hit=1'b1;
		// mmu2pref_i.i_page_fault=1'b0;
	end
endmodule

