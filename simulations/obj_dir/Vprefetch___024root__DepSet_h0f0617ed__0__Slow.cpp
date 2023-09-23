// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vprefetch.h for the primary calling header

#include "verilated.h"

#include "Vprefetch__Syms.h"
#include "Vprefetch__Syms.h"
#include "Vprefetch___024root.h"

#ifdef VL_DEBUG
VL_ATTR_COLD void Vprefetch___024root___dump_triggers__stl(Vprefetch___024root* vlSelf);
#endif  // VL_DEBUG

VL_ATTR_COLD void Vprefetch___024root___eval_triggers__stl(Vprefetch___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vprefetch__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vprefetch___024root___eval_triggers__stl\n"); );
    // Body
    vlSelf->__VstlTriggered.set(0U, (0U == vlSelf->__VstlIterCount));
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vprefetch___024root___dump_triggers__stl(vlSelf);
    }
#endif
}
