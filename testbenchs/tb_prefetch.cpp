#include <stdlib.h>
#include <iostream>
#include <verilated.h>
#include <verilated_vcd_c.h>
#include "Vprefetch.h"





#include "Vprefetch___024unit.h"

#define MAX_SIM_TIME 100
vluint64_t sim_time = 0;
vluint64_t posedge_cnt = 0;

int main(int argc, char** argv, char** env) {
	Verilated::commandArgs(argc, argv);
    	Vprefetch *dut = new Vprefetch;

    Verilated::traceEverOn(true);
    VerilatedVcdC *m_trace = new VerilatedVcdC;
    dut->trace(m_trace, 5);
    m_trace->open("waveform.vcd");

    while (sim_time < MAX_SIM_TIME) {
    
    	dut->clk ^= 1;
    	dut->rst_n=0;
    	dut->eval();
    	if(dut->clk == 1){
    		posedge_cnt++;        		// Increment posedge counter if clk is 1
	}


         if (posedge_cnt <= 3){		        //reset
            	dut->rst_n =1;
    	
        }
        if (posedge_cnt == 4){            	
    		dut->rst_n =0;
              	  dut->if2pf_i= 0x400000004;
              	   	
        }              
          	    		
	

    	
           
        m_trace->dump(sim_time);
        sim_time++;
    }

    m_trace->close();
    delete dut;
    exit(EXIT_SUCCESS);
}
