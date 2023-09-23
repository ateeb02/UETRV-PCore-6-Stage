// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vprefetch.h for the primary calling header

#ifndef VERILATED_VPREFETCH___024UNIT_H_
#define VERILATED_VPREFETCH___024UNIT_H_  // guard

#include "verilated.h"

class Vprefetch__Syms;

class Vprefetch___024unit final : public VerilatedModule {
  public:

    // INTERNAL VARIABLES
    Vprefetch__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vprefetch___024unit(Vprefetch__Syms* symsp, const char* v__name);
    ~Vprefetch___024unit();
    VL_UNCOPYABLE(Vprefetch___024unit);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);


#endif  // guard
