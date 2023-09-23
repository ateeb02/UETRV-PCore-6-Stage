// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vprefetch__Syms.h"


VL_ATTR_COLD void Vprefetch___024root__trace_init_sub__TOP__0(Vprefetch___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vprefetch__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vprefetch___024root__trace_init_sub__TOP__0\n"); );
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBit(c+6,"clk", false,-1);
    tracep->declBit(c+7,"rst_n", false,-1);
    tracep->declBus(c+8,"pf2if_ctrl_o", false,-1, 3,0);
    tracep->declBus(c+9,"pf2if_data_o", false,-1, 31,0);
    tracep->declQuad(c+10,"if2pf_i", false,-1, 34,0);
    tracep->declQuad(c+12,"pf2icache_o", false,-1, 34,0);
    tracep->declQuad(c+14,"icache2pf_i", false,-1, 32,0);
    tracep->declQuad(c+16,"pf2mmu_o", false,-1, 32,0);
    tracep->declQuad(c+18,"mmu2pf_i", false,-1, 35,0);
    tracep->pushNamePrefix("prefetch ");
    tracep->declBit(c+6,"clk", false,-1);
    tracep->declBit(c+7,"rst_n", false,-1);
    tracep->declBus(c+8,"pf2if_ctrl_o", false,-1, 3,0);
    tracep->declBus(c+9,"pf2if_data_o", false,-1, 31,0);
    tracep->declQuad(c+10,"if2pf_i", false,-1, 34,0);
    tracep->declQuad(c+12,"pf2icache_o", false,-1, 34,0);
    tracep->declQuad(c+14,"icache2pf_i", false,-1, 32,0);
    tracep->declQuad(c+16,"pf2mmu_o", false,-1, 32,0);
    tracep->declQuad(c+18,"mmu2pf_i", false,-1, 35,0);
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+1+i*1,"fetch_fifo", true,(i+0), 31,0);
    }
    tracep->declBus(c+3,"fifo_valid", false,-1, 1,0);
    tracep->declBus(c+20,"data_out", false,-1, 31,0);
    tracep->declBus(c+21,"data_in", false,-1, 31,0);
    tracep->declBus(c+4,"pc_fifo", false,-1, 31,0);
    tracep->declBus(c+22,"pc_incr", false,-1, 31,0);
    tracep->declBit(c+23,"pc_hword", false,-1);
    tracep->declBit(c+24,"fifo_clr", false,-1);
    tracep->declBit(c+25,"fifo_update", false,-1);
    tracep->declBit(c+5,"stall", false,-1);
    tracep->popNamePrefix(1);
}

VL_ATTR_COLD void Vprefetch___024root__trace_init_sub__TOP____024unit__0(Vprefetch___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vprefetch__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vprefetch___024root__trace_init_sub__TOP____024unit__0\n"); );
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBus(c+26,"CSR_MTVEC_BASE_ALIGN_VECTOR", false,-1, 31,0);
    tracep->declBus(c+27,"CSR_MTVEC_BASE_ALIGN_DIRECT", false,-1, 31,0);
    tracep->declBus(c+28,"MODE_BIT", false,-1, 31,0);
    tracep->declBus(c+26,"CSR_STVEC_BASE_ALIGN_VECTOR", false,-1, 31,0);
    tracep->declBus(c+27,"CSR_STVEC_BASE_ALIGN_DIRECT", false,-1, 31,0);
    tracep->declBus(c+29,"EXC_CODE_WIDTH", false,-1, 31,0);
    tracep->declBus(c+30,"S_SOFT_INT_IDX", false,-1, 31,0);
    tracep->declBus(c+31,"M_SOFT_INT_IDX", false,-1, 31,0);
    tracep->declBus(c+32,"S_TIMER_INT_IDX", false,-1, 31,0);
    tracep->declBus(c+33,"M_TIMER_INT_IDX", false,-1, 31,0);
    tracep->declBus(c+34,"S_EXT_INT_IDX", false,-1, 31,0);
    tracep->declBus(c+35,"M_EXT_INT_IDX", false,-1, 31,0);
    tracep->declBus(c+36,"MIE_SSIP", false,-1, 31,0);
    tracep->declBus(c+37,"MIE_MSIP", false,-1, 31,0);
    tracep->declBus(c+38,"MIE_STIP", false,-1, 31,0);
    tracep->declBus(c+39,"MIE_MTIP", false,-1, 31,0);
    tracep->declBus(c+40,"MIE_SEIP", false,-1, 31,0);
    tracep->declBus(c+41,"MIE_MEIP", false,-1, 31,0);
    tracep->declBus(c+42,"MIE_MASK", false,-1, 31,0);
    tracep->declBus(c+42,"MIP_MASK", false,-1, 31,0);
    tracep->declBus(c+43,"SIE_MASK", false,-1, 31,0);
    tracep->declBus(c+43,"SIP_MASK", false,-1, 31,0);
    tracep->declBus(c+36,"SIE_SSIP", false,-1, 31,0);
    tracep->declBus(c+36,"SIP_SSIP", false,-1, 31,0);
    tracep->declBus(c+29,"IRQ_CODE_WIDTH", false,-1, 31,0);
    tracep->declBus(c+36,"STATUS_SIE", false,-1, 31,0);
    tracep->declBus(c+38,"STATUS_SPIE", false,-1, 31,0);
    tracep->declBus(c+44,"STATUS_UBE", false,-1, 31,0);
    tracep->declBus(c+45,"STATUS_SPP", false,-1, 31,0);
    tracep->declBus(c+46,"STATUS_VS", false,-1, 31,0);
    tracep->declBus(c+47,"STATUS_FS", false,-1, 31,0);
    tracep->declBus(c+48,"STATUS_XS", false,-1, 31,0);
    tracep->declBus(c+49,"STATUS_SUM", false,-1, 31,0);
    tracep->declBus(c+50,"STATUS_MXR", false,-1, 31,0);
    tracep->declBus(c+51,"STATUS_SD", false,-1, 31,0);
    tracep->declBus(c+52,"SSTATUS_READ_MASK", false,-1, 31,0);
    tracep->declBus(c+53,"SSTATUS_WRITE_MASK", false,-1, 31,0);
    tracep->declBus(c+54,"SATP_ASID_MASK", false,-1, 31,0);
    tracep->declBus(c+55,"SATP_MODE_WIDTH", false,-1, 31,0);
    tracep->declBus(c+56,"SATP_ASID_WIDTH", false,-1, 31,0);
    tracep->declBus(c+57,"SATP_PPN_WIDTH", false,-1, 31,0);
    tracep->declBus(c+55,"MODE_SV32", false,-1, 31,0);
    tracep->declBus(c+58,"TVEC_MODE_WIDTH", false,-1, 31,0);
    tracep->declBus(c+59,"TVEC_BASE_WIDTH", false,-1, 31,0);
    tracep->declBus(c+29,"TLB_ENTRIES", false,-1, 31,0);
    tracep->declBus(c+60,"DTLB_ENTRIES", false,-1, 31,0);
    tracep->declBus(c+29,"DTLB_WIDTH", false,-1, 31,0);
    tracep->declBus(c+61,"ICACHE_ADDR_WIDTH", false,-1, 31,0);
    tracep->declBus(c+61,"ICACHE_DATA_WIDTH", false,-1, 31,0);
    tracep->declBus(c+62,"ICACHE_LINE_WIDTH", false,-1, 31,0);
    tracep->declBus(c+62,"ICACHE_NO_OF_SETS", false,-1, 31,0);
    tracep->declBus(c+63,"ICACHE_OFFSET_BITS", false,-1, 31,0);
    tracep->declBus(c+64,"ICACHE_IDX_BITS", false,-1, 31,0);
    tracep->declBus(c+65,"ICACHE_TAG_BITS", false,-1, 31,0);
    tracep->declBus(c+66,"ICACHE_TAG_LSB", false,-1, 31,0);
    tracep->declBus(c+61,"DCACHE_ADDR_WIDTH", false,-1, 31,0);
    tracep->declBus(c+61,"DCACHE_DATA_WIDTH", false,-1, 31,0);
    tracep->declBus(c+62,"DCACHE_LINE_WIDTH", false,-1, 31,0);
    tracep->declBus(c+67,"DCACHE_NO_OF_SETS", false,-1, 31,0);
    tracep->declBus(c+63,"DCACHE_OFFSET_BITS", false,-1, 31,0);
    tracep->declBus(c+63,"DCACHE_IDX_BITS", false,-1, 31,0);
    tracep->declBus(c+68,"DCACHE_TAG_BITS", false,-1, 31,0);
    tracep->declBus(c+69,"DCACHE_TAG_LSB", false,-1, 31,0);
}

VL_ATTR_COLD void Vprefetch___024root__trace_init_top(Vprefetch___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vprefetch__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vprefetch___024root__trace_init_top\n"); );
    // Body
    Vprefetch___024root__trace_init_sub__TOP__0(vlSelf, tracep);
    tracep->pushNamePrefix("$unit ");
    Vprefetch___024root__trace_init_sub__TOP____024unit__0(vlSelf, tracep);
    tracep->popNamePrefix(1);
}

VL_ATTR_COLD void Vprefetch___024root__trace_full_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vprefetch___024root__trace_chg_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vprefetch___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/);

VL_ATTR_COLD void Vprefetch___024root__trace_register(Vprefetch___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vprefetch__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vprefetch___024root__trace_register\n"); );
    // Body
    tracep->addFullCb(&Vprefetch___024root__trace_full_top_0, vlSelf);
    tracep->addChgCb(&Vprefetch___024root__trace_chg_top_0, vlSelf);
    tracep->addCleanupCb(&Vprefetch___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void Vprefetch___024root__trace_full_sub_0(Vprefetch___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vprefetch___024root__trace_full_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vprefetch___024root__trace_full_top_0\n"); );
    // Init
    Vprefetch___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vprefetch___024root*>(voidSelf);
    Vprefetch__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    Vprefetch___024root__trace_full_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vprefetch___024root__trace_full_sub_0(Vprefetch___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vprefetch__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vprefetch___024root__trace_full_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullIData(oldp+1,(vlSelf->prefetch__DOT__fetch_fifo[0]),32);
    bufp->fullIData(oldp+2,(vlSelf->prefetch__DOT__fetch_fifo[1]),32);
    bufp->fullCData(oldp+3,(vlSelf->prefetch__DOT__fifo_valid),2);
    bufp->fullIData(oldp+4,(vlSelf->prefetch__DOT__pc_fifo),32);
    bufp->fullBit(oldp+5,((1U & (~ ((IData)(vlSelf->prefetch__DOT__fifo_valid) 
                                    >> 1U)))));
    bufp->fullBit(oldp+6,(vlSelf->clk));
    bufp->fullBit(oldp+7,(vlSelf->rst_n));
    bufp->fullCData(oldp+8,(vlSelf->pf2if_ctrl_o),4);
    bufp->fullIData(oldp+9,(vlSelf->pf2if_data_o),32);
    bufp->fullQData(oldp+10,(vlSelf->if2pf_i),35);
    bufp->fullQData(oldp+12,(vlSelf->pf2icache_o),35);
    bufp->fullQData(oldp+14,(vlSelf->icache2pf_i),33);
    bufp->fullQData(oldp+16,(vlSelf->pf2mmu_o),33);
    bufp->fullQData(oldp+18,(vlSelf->mmu2pf_i),36);
    bufp->fullIData(oldp+20,(((1U & (IData)((vlSelf->if2pf_i 
                                             >> 4U)))
                               ? ((0xffff0000U & vlSelf->prefetch__DOT__fetch_fifo
                                   [0U]) | (0xffffU 
                                            & vlSelf->prefetch__DOT__fetch_fifo
                                            [1U])) : 
                              vlSelf->prefetch__DOT__fetch_fifo
                              [1U])),32);
    bufp->fullIData(oldp+21,(((1U & (IData)(vlSelf->icache2pf_i))
                               ? (IData)((vlSelf->icache2pf_i 
                                          >> 1U)) : 0x13U)),32);
    bufp->fullIData(oldp+22,(vlSelf->prefetch__DOT__pc_incr),32);
    bufp->fullBit(oldp+23,((1U & (IData)((vlSelf->if2pf_i 
                                          >> 4U)))));
    bufp->fullBit(oldp+24,(vlSelf->prefetch__DOT__fifo_clr));
    bufp->fullBit(oldp+25,(vlSelf->prefetch__DOT__fifo_update));
    bufp->fullIData(oldp+26,(6U),32);
    bufp->fullIData(oldp+27,(2U),32);
    bufp->fullIData(oldp+28,(0U),32);
    bufp->fullIData(oldp+29,(4U),32);
    bufp->fullIData(oldp+30,(1U),32);
    bufp->fullIData(oldp+31,(3U),32);
    bufp->fullIData(oldp+32,(5U),32);
    bufp->fullIData(oldp+33,(7U),32);
    bufp->fullIData(oldp+34,(9U),32);
    bufp->fullIData(oldp+35,(0xbU),32);
    bufp->fullIData(oldp+36,(2U),32);
    bufp->fullIData(oldp+37,(8U),32);
    bufp->fullIData(oldp+38,(0x20U),32);
    bufp->fullIData(oldp+39,(0x80U),32);
    bufp->fullIData(oldp+40,(0x200U),32);
    bufp->fullIData(oldp+41,(0x800U),32);
    bufp->fullIData(oldp+42,(0xaaaU),32);
    bufp->fullIData(oldp+43,(0x222U),32);
    bufp->fullIData(oldp+44,(0x40U),32);
    bufp->fullIData(oldp+45,(0x100U),32);
    bufp->fullIData(oldp+46,(0x600U),32);
    bufp->fullIData(oldp+47,(0x6000U),32);
    bufp->fullIData(oldp+48,(0x18000U),32);
    bufp->fullIData(oldp+49,(0x40000U),32);
    bufp->fullIData(oldp+50,(0x80000U),32);
    bufp->fullIData(oldp+51,(0x80000000U),32);
    bufp->fullIData(oldp+52,(0x800de762U),32);
    bufp->fullIData(oldp+53,(0xc6122U),32);
    bufp->fullIData(oldp+54,(0x803fffffU),32);
    bufp->fullIData(oldp+55,(1U),32);
    bufp->fullIData(oldp+56,(9U),32);
    bufp->fullIData(oldp+57,(0x16U),32);
    bufp->fullIData(oldp+58,(2U),32);
    bufp->fullIData(oldp+59,(0x1eU),32);
    bufp->fullIData(oldp+60,(0x10U),32);
    bufp->fullIData(oldp+61,(0x20U),32);
    bufp->fullIData(oldp+62,(0x80U),32);
    bufp->fullIData(oldp+63,(4U),32);
    bufp->fullIData(oldp+64,(7U),32);
    bufp->fullIData(oldp+65,(0x15U),32);
    bufp->fullIData(oldp+66,(0xbU),32);
    bufp->fullIData(oldp+67,(0x10U),32);
    bufp->fullIData(oldp+68,(0x18U),32);
    bufp->fullIData(oldp+69,(8U),32);
}
