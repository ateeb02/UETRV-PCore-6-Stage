`include "pcore_interface_defs.svh"
`include "pcore_config_defs.svh"
`include "mmu_defs.svh"
`include "cache_defs.svh"


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
		rst_n = 1; #3;
		rst_n = 0; #10;
		rst_n = 1; #2;
	end



	initial begin

		//Residual time		
		@(posedge clk);
		if2pf.pc_ff = 32'd0;

		//--------------Cycle 1--------------
		@(posedge clk);

		if2pf.pc_ff = if2pf.pc_ff;
		if2pf.req = 1'b1;
		if2pf.is_comp = 1'b0;
		if2pf.clear = 1'b0;

		mmu2pf.i_paddr = pf2mmu_c.i_req ? pf2mmu_c.i_vaddr : 32'hffff_ffff;
		mmu2pf.i_hit = 1'b1; 
		mmu2pf.i_page_fault = 1'b0;

		icache2pf.r_data = pf2icache_c.req ? 32'd15 : 32'hffff_ffff;
		icache2pf.ack = 1'b1;

		//--------------Cycle 2--------------
		@(posedge clk);

		hword = 1'b0;

		if2pf.pc_ff = if2pf.pc_ff + 4;
		if2pf.req = 1'b1;
		if2pf.is_comp = 1'b0;
		if2pf.clear = 1'b0;

		mmu2pf.i_paddr = pf2mmu_c.i_req ? pf2mmu_c.i_vaddr : 32'hffff_ffff;
		mmu2pf.i_hit = 1'b1; 
		mmu2pf.i_page_fault = 1'b0;

		icache2pf.r_data = pf2icache_c.req ? 32'd31 : 32'hffff_ffff;
		icache2pf.ack = 1'b1;

		//--------------Cycle 3--------------
		@(posedge clk);

		if2pf.pc_ff = if2pf.pc_ff + 4;
		if2pf.req = 1'b1;
		if2pf.is_comp = 1'b0;
		if2pf.clear = 1'b0;

		mmu2pf.i_paddr = pf2mmu_c.i_req ? pf2mmu_c.i_vaddr : 32'hffff_ffff;
		mmu2pf.i_hit = 1'b1; 
		mmu2pf.i_page_fault = 1'b0;

		icache2pf.r_data = pf2icache_c.req ? 32'd63 : 32'hffff_ffff;
		icache2pf.ack = 1'b1;

		//--------------Cycle 4--------------
		@(posedge clk);

		if2pf.pc_ff = if2pf.pc_ff + 4;
		if2pf.req = 1'b1;
		if2pf.is_comp = 1'b0;
		if2pf.clear = 1'b0;

		mmu2pf.i_paddr = pf2mmu_c.i_req ? pf2mmu_c.i_vaddr : 32'hffff_ffff;
		mmu2pf.i_hit = 1'b1; 
		mmu2pf.i_page_fault = 1'b0;

		icache2pf.r_data = pf2icache_c.req ? 32'd127 : 32'hffff_ffff;
		icache2pf.ack = 1'b1;

		//--------------Cycle 5--------------
		@(posedge clk);

		if2pf.pc_ff = if2pf.pc_ff + 4;
		if2pf.req = 1'b1;
		if2pf.is_comp = 1'b0;
		if2pf.clear = 1'b0;

		mmu2pf.i_paddr = pf2mmu_c.i_req ? pf2mmu_c.i_vaddr : 32'hffff_ffff;
		mmu2pf.i_hit = 1'b1; 
		mmu2pf.i_page_fault = 1'b0;

		icache2pf.r_data = pf2icache_c.req ? 32'd255 : 32'hffff_ffff;
		icache2pf.ack = 1'b1;

		//--------------Cycle 6--------------
		@(posedge clk);

		if2pf.pc_ff = if2pf.pc_ff + 4;
		if2pf.req = 1'b1;
		if2pf.is_comp = 1'b0;
		if2pf.clear = 1'b0;

		mmu2pf.i_paddr = pf2mmu_c.i_req ? pf2mmu_c.i_vaddr : 32'hffff_ffff;
		mmu2pf.i_hit = 1'b1; 
		mmu2pf.i_page_fault = 1'b0;

		icache2pf.r_data = pf2icache_c.req ? 32'd511 : 32'hffff_ffff;
		icache2pf.ack = 1'b1;


	end


endmodule

