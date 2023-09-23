// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vprefetch__Syms.h"


void Vprefetch___024root__trace_chg_sub_0(Vprefetch___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Vprefetch___024root__trace_chg_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vprefetch___024root__trace_chg_top_0\n"); );
    // Init
    Vprefetch___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vprefetch___024root*>(voidSelf);
    Vprefetch__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    Vprefetch___024root__trace_chg_sub_0((&vlSymsp->TOP), bufp);
}

void Vprefetch___024root__trace_chg_sub_0(Vprefetch___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vprefetch__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vprefetch___024root__trace_chg_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    // Body
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[1U])) {
        bufp->chgIData(oldp+0,(vlSelf->prefetch__DOT__fetch_fifo[0]),32);
        bufp->chgIData(oldp+1,(vlSelf->prefetch__DOT__fetch_fifo[1]),32);
        bufp->chgCData(oldp+2,(vlSelf->prefetch__DOT__fifo_valid),2);
        bufp->chgIData(oldp+3,(vlSelf->prefetch__DOT__pc_fifo),32);
        bufp->chgBit(oldp+4,((1U & (~ ((IData)(vlSelf->prefetch__DOT__fifo_valid) 
                                       >> 1U)))));
    }
    bufp->chgBit(oldp+5,(vlSelf->clk));
    bufp->chgBit(oldp+6,(vlSelf->rst_n));
    bufp->chgCData(oldp+7,(vlSelf->pf2if_ctrl_o),4);
    bufp->chgIData(oldp+8,(vlSelf->pf2if_data_o),32);
    bufp->chgQData(oldp+9,(vlSelf->if2pf_i),35);
    bufp->chgQData(oldp+11,(vlSelf->pf2icache_o),35);
    bufp->chgQData(oldp+13,(vlSelf->icache2pf_i),33);
    bufp->chgQData(oldp+15,(vlSelf->pf2mmu_o),33);
    bufp->chgQData(oldp+17,(vlSelf->mmu2pf_i),36);
    bufp->chgIData(oldp+19,(((1U & (IData)((vlSelf->if2pf_i 
                                            >> 4U)))
                              ? ((0xffff0000U & vlSelf->prefetch__DOT__fetch_fifo
                                  [0U]) | (0xffffU 
                                           & vlSelf->prefetch__DOT__fetch_fifo
                                           [1U])) : 
                             vlSelf->prefetch__DOT__fetch_fifo
                             [1U])),32);
    bufp->chgIData(oldp+20,(((1U & (IData)(vlSelf->icache2pf_i))
                              ? (IData)((vlSelf->icache2pf_i 
                                         >> 1U)) : 0x13U)),32);
    bufp->chgIData(oldp+21,(vlSelf->prefetch__DOT__pc_incr),32);
    bufp->chgBit(oldp+22,((1U & (IData)((vlSelf->if2pf_i 
                                         >> 4U)))));
    bufp->chgBit(oldp+23,(vlSelf->prefetch__DOT__fifo_clr));
    bufp->chgBit(oldp+24,(vlSelf->prefetch__DOT__fifo_update));
}

void Vprefetch___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vprefetch___024root__trace_cleanup\n"); );
    // Init
    Vprefetch___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vprefetch___024root*>(voidSelf);
    Vprefetch__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
}
