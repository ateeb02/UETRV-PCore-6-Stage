// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vprefetch.h for the primary calling header

#include "verilated.h"

#include "Vprefetch__Syms.h"
#include "Vprefetch__Syms.h"
#include "Vprefetch___024root.h"

void Vprefetch___024root___ctor_var_reset(Vprefetch___024root* vlSelf);

Vprefetch___024root::Vprefetch___024root(Vprefetch__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    Vprefetch___024root___ctor_var_reset(this);
}

void Vprefetch___024root::__Vconfigure(bool first) {
    if (false && first) {}  // Prevent unused
}

Vprefetch___024root::~Vprefetch___024root() {
}
