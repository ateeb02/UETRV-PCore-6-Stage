// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vprefetch.h for the primary calling header

#include "verilated.h"

#include "Vprefetch__Syms.h"
#include "Vprefetch__Syms.h"
#include "Vprefetch___024unit.h"

void Vprefetch___024unit___ctor_var_reset(Vprefetch___024unit* vlSelf);

Vprefetch___024unit::Vprefetch___024unit(Vprefetch__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    Vprefetch___024unit___ctor_var_reset(this);
}

void Vprefetch___024unit::__Vconfigure(bool first) {
    if (false && first) {}  // Prevent unused
}

Vprefetch___024unit::~Vprefetch___024unit() {
}
