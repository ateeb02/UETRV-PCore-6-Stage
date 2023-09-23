// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vprefetch.h for the primary calling header

#include "verilated.h"

#include "Vprefetch__Syms.h"
#include "Vprefetch___024root.h"

VL_ATTR_COLD void Vprefetch___024root___eval_static(Vprefetch___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vprefetch__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vprefetch___024root___eval_static\n"); );
}

VL_ATTR_COLD void Vprefetch___024root___eval_initial(Vprefetch___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vprefetch__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vprefetch___024root___eval_initial\n"); );
    // Body
    vlSelf->__Vtrigprevexpr___TOP__clk__0 = vlSelf->clk;
    vlSelf->__Vtrigprevexpr___TOP__rst_n__0 = vlSelf->rst_n;
}

VL_ATTR_COLD void Vprefetch___024root___eval_final(Vprefetch___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vprefetch__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vprefetch___024root___eval_final\n"); );
}

VL_ATTR_COLD void Vprefetch___024root___eval_triggers__stl(Vprefetch___024root* vlSelf);
#ifdef VL_DEBUG
VL_ATTR_COLD void Vprefetch___024root___dump_triggers__stl(Vprefetch___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD void Vprefetch___024root___eval_stl(Vprefetch___024root* vlSelf);

VL_ATTR_COLD void Vprefetch___024root___eval_settle(Vprefetch___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vprefetch__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vprefetch___024root___eval_settle\n"); );
    // Init
    CData/*0:0*/ __VstlContinue;
    // Body
    vlSelf->__VstlIterCount = 0U;
    __VstlContinue = 1U;
    while (__VstlContinue) {
        __VstlContinue = 0U;
        Vprefetch___024root___eval_triggers__stl(vlSelf);
        if (vlSelf->__VstlTriggered.any()) {
            __VstlContinue = 1U;
            if (VL_UNLIKELY((0x64U < vlSelf->__VstlIterCount))) {
#ifdef VL_DEBUG
                Vprefetch___024root___dump_triggers__stl(vlSelf);
#endif
                VL_FATAL_MT("prefetch.sv", 23, "", "Settle region did not converge.");
            }
            vlSelf->__VstlIterCount = ((IData)(1U) 
                                       + vlSelf->__VstlIterCount);
            Vprefetch___024root___eval_stl(vlSelf);
        }
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vprefetch___024root___dump_triggers__stl(Vprefetch___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vprefetch__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vprefetch___024root___dump_triggers__stl\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VstlTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VstlTriggered.word(0U))) {
        VL_DBG_MSGF("         'stl' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vprefetch___024root___stl_sequent__TOP__0(Vprefetch___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vprefetch__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vprefetch___024root___stl_sequent__TOP__0\n"); );
    // Body
    vlSelf->pf2icache_o = ((3ULL & vlSelf->pf2icache_o) 
                           | (0x7fffffffcULL & (vlSelf->mmu2pf_i 
                                                << 1U)));
    vlSelf->pf2mmu_o = (1ULL | ((QData)((IData)(vlSelf->prefetch__DOT__pc_fifo)) 
                                << 1U));
    if ((1U & (~ ((IData)(vlSelf->prefetch__DOT__fifo_valid) 
                  >> 1U)))) {
        vlSelf->prefetch__DOT__pc_incr = ((1U & (IData)(vlSelf->prefetch__DOT__fifo_valid))
                                           ? 0U : 4U);
    }
    if ((1U & (IData)((vlSelf->if2pf_i >> 4U)))) {
        vlSelf->prefetch__DOT__pc_incr = 2U;
        vlSelf->pf2if_data_o = ((0xffff0000U & vlSelf->prefetch__DOT__fetch_fifo
                                 [0U]) | (0xffffU & 
                                          vlSelf->prefetch__DOT__fetch_fifo
                                          [1U]));
    } else {
        vlSelf->prefetch__DOT__pc_incr = 4U;
        vlSelf->pf2if_data_o = vlSelf->prefetch__DOT__fetch_fifo
            [1U];
    }
    vlSelf->pf2if_ctrl_o = ((0xdU & (IData)(vlSelf->pf2if_ctrl_o)) 
                            | (2U & (((~ ((IData)(vlSelf->prefetch__DOT__fifo_valid) 
                                          >> 1U)) | 
                                      (~ (IData)(vlSelf->icache2pf_i))) 
                                     << 1U)));
    vlSelf->prefetch__DOT__fifo_clr = (1U & ((~ (IData)(vlSelf->rst_n)) 
                                             | (IData)(vlSelf->if2pf_i)));
    vlSelf->prefetch__DOT__fifo_update = (1U & ((IData)(
                                                        (vlSelf->if2pf_i 
                                                         >> 2U)) 
                                                | (IData)(vlSelf->prefetch__DOT__fifo_clr)));
    if (vlSelf->prefetch__DOT__fifo_clr) {
        vlSelf->pf2if_ctrl_o = (3U & (IData)(vlSelf->pf2if_ctrl_o));
        vlSelf->pf2if_ctrl_o = (0xeU & (IData)(vlSelf->pf2if_ctrl_o));
    }
    vlSelf->pf2if_ctrl_o = ((0xeU & (IData)(vlSelf->pf2if_ctrl_o)) 
                            | (1U & ((1U & (IData)(
                                                   (vlSelf->if2pf_i 
                                                    >> 4U)))
                                      ? (3U == (IData)(vlSelf->prefetch__DOT__fifo_valid))
                                      : ((IData)(vlSelf->prefetch__DOT__fifo_valid) 
                                         >> 1U))));
}

VL_ATTR_COLD void Vprefetch___024root___eval_stl(Vprefetch___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vprefetch__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vprefetch___024root___eval_stl\n"); );
    // Body
    if ((1ULL & vlSelf->__VstlTriggered.word(0U))) {
        Vprefetch___024root___stl_sequent__TOP__0(vlSelf);
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vprefetch___024root___dump_triggers__ico(Vprefetch___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vprefetch__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vprefetch___024root___dump_triggers__ico\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VicoTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VicoTriggered.word(0U))) {
        VL_DBG_MSGF("         'ico' region trigger index 0 is active: Internal 'ico' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vprefetch___024root___dump_triggers__act(Vprefetch___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vprefetch__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vprefetch___024root___dump_triggers__act\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VactTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 0 is active: @(posedge clk or negedge rst_n)\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vprefetch___024root___dump_triggers__nba(Vprefetch___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vprefetch__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vprefetch___024root___dump_triggers__nba\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VnbaTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @(posedge clk or negedge rst_n)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vprefetch___024root___ctor_var_reset(Vprefetch___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vprefetch__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vprefetch___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->clk = VL_RAND_RESET_I(1);
    vlSelf->rst_n = VL_RAND_RESET_I(1);
    vlSelf->pf2if_ctrl_o = VL_RAND_RESET_I(4);
    vlSelf->pf2if_data_o = VL_RAND_RESET_I(32);
    vlSelf->if2pf_i = VL_RAND_RESET_Q(35);
    vlSelf->pf2icache_o = VL_RAND_RESET_Q(35);
    vlSelf->icache2pf_i = VL_RAND_RESET_Q(33);
    vlSelf->pf2mmu_o = VL_RAND_RESET_Q(33);
    vlSelf->mmu2pf_i = VL_RAND_RESET_Q(36);
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->prefetch__DOT__fetch_fifo[__Vi0] = VL_RAND_RESET_I(32);
    }
    vlSelf->prefetch__DOT__fifo_valid = VL_RAND_RESET_I(2);
    vlSelf->prefetch__DOT__pc_fifo = VL_RAND_RESET_I(32);
    vlSelf->prefetch__DOT__pc_incr = VL_RAND_RESET_I(32);
    vlSelf->prefetch__DOT__fifo_clr = VL_RAND_RESET_I(1);
    vlSelf->prefetch__DOT__fifo_update = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__clk__0 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__rst_n__0 = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->__Vm_traceActivity[__Vi0] = 0;
    }
}
