// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vprefetch.h for the primary calling header

#ifndef VERILATED_VPREFETCH___024ROOT_H_
#define VERILATED_VPREFETCH___024ROOT_H_  // guard

#include "verilated.h"

class Vprefetch__Syms;

class Vprefetch___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(clk,0,0);
    VL_IN8(rst_n,0,0);
    VL_OUT8(pf2if_ctrl_o,3,0);
    CData/*1:0*/ prefetch__DOT__fifo_valid;
    CData/*0:0*/ prefetch__DOT__fifo_clr;
    CData/*0:0*/ prefetch__DOT__fifo_update;
    CData/*0:0*/ __Vtrigprevexpr___TOP__clk__0;
    CData/*0:0*/ __Vtrigprevexpr___TOP__rst_n__0;
    CData/*0:0*/ __VactContinue;
    VL_OUT(pf2if_data_o,31,0);
    IData/*31:0*/ prefetch__DOT__pc_fifo;
    IData/*31:0*/ prefetch__DOT__pc_incr;
    IData/*31:0*/ __VstlIterCount;
    IData/*31:0*/ __VicoIterCount;
    IData/*31:0*/ __VactIterCount;
    VL_IN64(if2pf_i,34,0);
    VL_OUT64(pf2icache_o,34,0);
    VL_IN64(icache2pf_i,32,0);
    VL_OUT64(pf2mmu_o,32,0);
    VL_IN64(mmu2pf_i,35,0);
    VlUnpacked<IData/*31:0*/, 2> prefetch__DOT__fetch_fifo;
    VlUnpacked<CData/*0:0*/, 2> __Vm_traceActivity;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<1> __VicoTriggered;
    VlTriggerVec<1> __VactTriggered;
    VlTriggerVec<1> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vprefetch__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vprefetch___024root(Vprefetch__Syms* symsp, const char* v__name);
    ~Vprefetch___024root();
    VL_UNCOPYABLE(Vprefetch___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);


#endif  // guard
