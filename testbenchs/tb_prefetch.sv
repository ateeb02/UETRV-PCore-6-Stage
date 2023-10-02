`include "../defines/pcore_interface_defs.svh"
`include "../defines/pcore_config_defs.svh"
`include "../defines/mmu_defs.svh"
`include "../defines/cache_defs.svh"

module tb_prefetch;

	logic 								clk;
	logic								rst_n;

	type_if2pf_s 						if2pf;			//output
	type_pf2if_ctrl_s 					pf2if_ctrl_c;
	type_pf2if_data_s 					pf2if_data_c;

	type_if2icache_s 					pf2icache_c;
	type_icache2if_s 					icache2pf;		//output

	type_if2mmu_s 						pf2mmu_c;
	type_mmu2if_s 						mmu2pf;			//output


	//assign hword = if2pf.pc_ff[1];
	logic hword;

	prefetch DUT(	
		.clk							(clk			),
		.rst_n							(rst_n			),

		.mmu2pf_i						(mmu2pf			),
		.pf2mmu_o						(pf2mmu_c		), 

		.icache2pf_i					(icache2pf		),
		.pf2icache_o					(pf2icache_c	),

		.if2pf_i						(if2pf			),
		.pf2if_data_o					(pf2if_data_c	), 
		.pf2if_ctrl_o					(pf2if_ctrl_c	)
	);


	initial begin
		clk = 0;
		forever #10 clk = ~clk;
	end

	initial begin 
		if2pf= 0;
		icache2pf =0;
		mmu2pf =0;
		
		rst_n = 1; #4;
		rst_n = 0; #10;
		rst_n = 1;
	end


/* these signals wont change in value should i add them in combinatoinal block

	initial begin
		@(posedge clk);
		if2pf.pc_ff = hword ? if2pf.pc_ff + 2 : if2pf.pc_ff + 4;
		mmu2pf.i_paddr = pf2mmu_c.i_req ? if2pf.pc_ff : 32'h0e0e0e0e;
		icache2pf.r_data = pf2icache_c.req ? ~pf2icache_c.addr : 32'h0e0e0e0e;
	end
*/

	initial begin

		//--------------Cycle 1--------------
		@(posedge clk);begin 

		hword = 1'b0;

		if2pf.pc_ff = hword ? if2pf.pc_ff + 2 : if2pf.pc_ff + 4;
		if2pf.instr_req = 1'b1;
		if2pf.is_comp = 1'b0;
		if2pf.clear = 1'b0;

		mmu2pf.i_paddr = pf2mmu_c.i_req ? if2pf.pc_ff : 32'h0;
		mmu2pf.i_hit = 1'b1; 
		mmu2pf.i_page_fault = 1'b0;

		icache2pf.r_data = pf2icache_c.req ? pf2icache_c.addr : 32'h2020_2020;
		icache2pf.ack = 1'b1;
		end

		
		//--------------Cycle 2--------------
		@(negedge pf2if_ctrl_c.stall); begin 
				@(posedge clk );
		hword = 1'b0;

		if2pf.pc_ff = hword ? if2pf.pc_ff + 2 : if2pf.pc_ff + 4;
		if2pf.instr_req = 1'b1;
		if2pf.is_comp = 1'b0;
		if2pf.clear = 1'b0;

		mmu2pf.i_paddr = pf2mmu_c.i_req ? if2pf.pc_ff : 32'h2020_2020;
		mmu2pf.i_hit = 1'b1; 
		mmu2pf.i_page_fault = 1'b0;

		icache2pf.r_data = pf2icache_c.req ? ~pf2icache_c.addr : 32'h2020_2020;
		icache2pf.ack = 1'b1;
		end
		//--------------Cycle 3--------------


	repeat (14) begin 
		@(posedge clk); begin 

		hword = 1'b0;

		if2pf.pc_ff = hword ? if2pf.pc_ff + 2 : if2pf.pc_ff + 4;
		if2pf.instr_req = 1'b1;
		if2pf.is_comp = 1'b0;
		if2pf.clear = 1'b0;

		mmu2pf.i_paddr = pf2mmu_c.i_req ? if2pf.pc_ff : 32'h0;
		mmu2pf.i_hit = 1'b1; 
		mmu2pf.i_page_fault = 1'b0;

		icache2pf.r_data = pf2icache_c.req ? pf2icache_c.addr : 32'h2020_2020;
		icache2pf.ack = 1'b1;
		end 
	end


	end



endmodule

