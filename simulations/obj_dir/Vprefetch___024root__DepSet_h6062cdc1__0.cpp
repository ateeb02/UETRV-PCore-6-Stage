// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vprefetch.h for the primary calling header

#include "verilated.h"

#include "Vprefetch__Syms.h"
#include "Vprefetch___024root.h"

VL_INLINE_OPT void Vprefetch___024root___ico_sequent__TOP__0(Vprefetch___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vprefetch__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vprefetch___024root___ico_sequent__TOP__0\n"); );
    // Body
    vlSelf->pf2icache_o = ((3ULL & vlSelf->pf2icache_o) 
                           | (0x7fffffffcULL & (vlSelf->mmu2pf_i 
                                                << 1U)));
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

void Vprefetch___024root___eval_ico(Vprefetch___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vprefetch__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vprefetch___024root___eval_ico\n"); );
    // Body
    if ((1ULL & vlSelf->__VicoTriggered.word(0U))) {
        Vprefetch___024root___ico_sequent__TOP__0(vlSelf);
    }
}

void Vprefetch___024root___eval_act(Vprefetch___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vprefetch__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vprefetch___024root___eval_act\n"); );
}

VL_INLINE_OPT void Vprefetch___024root___nba_sequent__TOP__0(Vprefetch___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vprefetch__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vprefetch___024root___nba_sequent__TOP__0\n"); );
    // Init
    IData/*31:0*/ __Vdlyvval__prefetch__DOT__fetch_fifo__v0;
    __Vdlyvval__prefetch__DOT__fetch_fifo__v0 = 0;
    CData/*0:0*/ __Vdlyvset__prefetch__DOT__fetch_fifo__v0;
    __Vdlyvset__prefetch__DOT__fetch_fifo__v0 = 0;
    IData/*31:0*/ __Vdlyvval__prefetch__DOT__fetch_fifo__v1;
    __Vdlyvval__prefetch__DOT__fetch_fifo__v1 = 0;
    IData/*31:0*/ __Vdlyvval__prefetch__DOT__fetch_fifo__v2;
    __Vdlyvval__prefetch__DOT__fetch_fifo__v2 = 0;
    CData/*0:0*/ __Vdlyvset__prefetch__DOT__fetch_fifo__v2;
    __Vdlyvset__prefetch__DOT__fetch_fifo__v2 = 0;
    IData/*31:0*/ __Vdlyvval__prefetch__DOT__fetch_fifo__v3;
    __Vdlyvval__prefetch__DOT__fetch_fifo__v3 = 0;
    // Body
    __Vdlyvset__prefetch__DOT__fetch_fifo__v0 = 0U;
    __Vdlyvset__prefetch__DOT__fetch_fifo__v2 = 0U;
    if (vlSelf->prefetch__DOT__fifo_update) {
        vlSelf->prefetch__DOT__fifo_valid = (1U | (2U 
                                                   & ((IData)(vlSelf->prefetch__DOT__fifo_valid) 
                                                      << 1U)));
        __Vdlyvval__prefetch__DOT__fetch_fifo__v0 = 
            vlSelf->prefetch__DOT__fetch_fifo[0U];
        __Vdlyvset__prefetch__DOT__fetch_fifo__v0 = 1U;
        __Vdlyvval__prefetch__DOT__fetch_fifo__v1 = 
            ((1U & (IData)(vlSelf->icache2pf_i)) ? (IData)(
                                                           (vlSelf->icache2pf_i 
                                                            >> 1U))
              : 0x13U);
    } else {
        vlSelf->prefetch__DOT__fifo_valid = vlSelf->prefetch__DOT__fifo_valid;
        __Vdlyvval__prefetch__DOT__fetch_fifo__v2 = 
            vlSelf->prefetch__DOT__fetch_fifo[1U];
        __Vdlyvset__prefetch__DOT__fetch_fifo__v2 = 1U;
        __Vdlyvval__prefetch__DOT__fetch_fifo__v3 = 
            vlSelf->prefetch__DOT__fetch_fifo[0U];
    }
    vlSelf->prefetch__DOT__pc_fifo = ((IData)((vlSelf->if2pf_i 
                                               >> 3U)) 
                                      + vlSelf->prefetch__DOT__pc_incr);
    if (__Vdlyvset__prefetch__DOT__fetch_fifo__v0) {
        vlSelf->prefetch__DOT__fetch_fifo[1U] = __Vdlyvval__prefetch__DOT__fetch_fifo__v0;
        vlSelf->prefetch__DOT__fetch_fifo[0U] = __Vdlyvval__prefetch__DOT__fetch_fifo__v1;
    }
    if (__Vdlyvset__prefetch__DOT__fetch_fifo__v2) {
        vlSelf->prefetch__DOT__fetch_fifo[1U] = __Vdlyvval__prefetch__DOT__fetch_fifo__v2;
        vlSelf->prefetch__DOT__fetch_fifo[0U] = __Vdlyvval__prefetch__DOT__fetch_fifo__v3;
    }
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
    vlSelf->pf2mmu_o = (1ULL | ((QData)((IData)(vlSelf->prefetch__DOT__pc_fifo)) 
                                << 1U));
}

VL_INLINE_OPT void Vprefetch___024root___nba_sequent__TOP__1(Vprefetch___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vprefetch__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vprefetch___024root___nba_sequent__TOP__1\n"); );
    // Body
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

void Vprefetch___024root___eval_nba(Vprefetch___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vprefetch__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vprefetch___024root___eval_nba\n"); );
    // Body
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vprefetch___024root___nba_sequent__TOP__0(vlSelf);
        vlSelf->__Vm_traceActivity[1U] = 1U;
        Vprefetch___024root___nba_sequent__TOP__1(vlSelf);
    }
}

void Vprefetch___024root___eval_triggers__ico(Vprefetch___024root* vlSelf);
#ifdef VL_DEBUG
VL_ATTR_COLD void Vprefetch___024root___dump_triggers__ico(Vprefetch___024root* vlSelf);
#endif  // VL_DEBUG
void Vprefetch___024root___eval_triggers__act(Vprefetch___024root* vlSelf);
#ifdef VL_DEBUG
VL_ATTR_COLD void Vprefetch___024root___dump_triggers__act(Vprefetch___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vprefetch___024root___dump_triggers__nba(Vprefetch___024root* vlSelf);
#endif  // VL_DEBUG

void Vprefetch___024root___eval(Vprefetch___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vprefetch__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vprefetch___024root___eval\n"); );
    // Init
    CData/*0:0*/ __VicoContinue;
    VlTriggerVec<1> __VpreTriggered;
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    vlSelf->__VicoIterCount = 0U;
    __VicoContinue = 1U;
    while (__VicoContinue) {
        __VicoContinue = 0U;
        Vprefetch___024root___eval_triggers__ico(vlSelf);
        if (vlSelf->__VicoTriggered.any()) {
            __VicoContinue = 1U;
            if (VL_UNLIKELY((0x64U < vlSelf->__VicoIterCount))) {
#ifdef VL_DEBUG
                Vprefetch___024root___dump_triggers__ico(vlSelf);
#endif
                VL_FATAL_MT("prefetch.sv", 23, "", "Input combinational region did not converge.");
            }
            vlSelf->__VicoIterCount = ((IData)(1U) 
                                       + vlSelf->__VicoIterCount);
            Vprefetch___024root___eval_ico(vlSelf);
        }
    }
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        __VnbaContinue = 0U;
        vlSelf->__VnbaTriggered.clear();
        vlSelf->__VactIterCount = 0U;
        vlSelf->__VactContinue = 1U;
        while (vlSelf->__VactContinue) {
            vlSelf->__VactContinue = 0U;
            Vprefetch___024root___eval_triggers__act(vlSelf);
            if (vlSelf->__VactTriggered.any()) {
                vlSelf->__VactContinue = 1U;
                if (VL_UNLIKELY((0x64U < vlSelf->__VactIterCount))) {
#ifdef VL_DEBUG
                    Vprefetch___024root___dump_triggers__act(vlSelf);
#endif
                    VL_FATAL_MT("prefetch.sv", 23, "", "Active region did not converge.");
                }
                vlSelf->__VactIterCount = ((IData)(1U) 
                                           + vlSelf->__VactIterCount);
                __VpreTriggered.andNot(vlSelf->__VactTriggered, vlSelf->__VnbaTriggered);
                vlSelf->__VnbaTriggered.thisOr(vlSelf->__VactTriggered);
                Vprefetch___024root___eval_act(vlSelf);
            }
        }
        if (vlSelf->__VnbaTriggered.any()) {
            __VnbaContinue = 1U;
            if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
                Vprefetch___024root___dump_triggers__nba(vlSelf);
#endif
                VL_FATAL_MT("prefetch.sv", 23, "", "NBA region did not converge.");
            }
            __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
            Vprefetch___024root___eval_nba(vlSelf);
        }
    }
}

#ifdef VL_DEBUG
void Vprefetch___024root___eval_debug_assertions(Vprefetch___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vprefetch__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vprefetch___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((vlSelf->rst_n & 0xfeU))) {
        Verilated::overWidthError("rst_n");}
}
#endif  // VL_DEBUG
