#include "all_headers.h"
#include "auto_08_8001EE60_sbss.h"
#include <stdint.h>
#include <stdio.h>

#include "gc_env.h"
#include <stdlib.h>

// Global variables
extern double lbl_8001F0A0;
extern double lbl_8001F0A8;
extern double lbl_8001F0B0;
extern double lbl_8001F0B8;
extern double lbl_8001F0C0;
extern double lbl_8001F0C8;
extern double lbl_8001F0D0;
extern uint32_t AlarmQueue_8001EE88;
extern uint32_t AreWeInitialized_8001EE74;
extern uint32_t BI2DebugFlagHolder_8001EE70;
extern uint32_t BI2DebugFlag_8001EE6C;
extern uint32_t BootInfo_8001EE68;
extern uint32_t CurrTvMode_8001F024;
extern uint32_t DBVerbose;
extern uint32_t InterruptHandlerTable_8001EE98;
extern uint32_t OSExceptionTable_8001EE78;
extern uint32_t Reschedule_8001EEE8;
extern uint32_t ResetFunctionQueue_8001EEC0;
extern uint32_t RunQueueBits_8001EEE0;
extern uint32_t RunQueueHint_8001EEE4;
extern uint32_t SamplingRate_8001EF10;
extern uint32_t Si_8001B088;
extern uint32_t TRK_mainError_8001EDD8;
extern uint32_t __DBInterface;
extern uint32_t __DVDLongFileNameFlag;
extern uint32_t __OSArenaHi_8001EE90;
extern uint32_t __OSArenaLo_8001EE08;
extern uint32_t __OSInIPL;
extern uint32_t __OSLastInterrupt;
extern uint32_t __OSLastInterruptSrr0;
extern uint32_t __OSLastInterruptTime;
extern uint32_t __OSStartTime;
extern uint32_t __PADSpec;
extern uint32_t __global_destructor_chain;
extern uint32_t lbl_8001C8C0;
extern uint32_t lbl_8001CE78;
extern uint32_t lbl_8001E848;
extern uint32_t lbl_8001EE00;
extern uint32_t lbl_8001EE18;
extern uint32_t lbl_8001EE20;
extern uint32_t lbl_8001EE40;
extern uint32_t lbl_8001EE44;
extern uint32_t lbl_8001EE48;
extern uint32_t lbl_8001EE50;
extern uint32_t lbl_8001EE60;
extern uint32_t lbl_8001EE64;
extern uint32_t lbl_8001EEB0;
extern uint32_t lbl_8001EEB4;
extern uint32_t lbl_8001EEB8;
extern uint32_t lbl_8001EEC8;
extern uint32_t lbl_8001EECC;
extern uint32_t lbl_8001EED0;
extern uint32_t lbl_8001EED8;
extern uint32_t lbl_8001EEDC;
extern uint32_t lbl_8001EEF0;
extern uint32_t lbl_8001EEF4;
extern uint32_t lbl_8001EEF8;
extern uint32_t lbl_8001EEFC;
extern uint32_t lbl_8001EF08;
extern uint32_t lbl_8001EF20;
extern uint32_t lbl_8001EF24;
extern uint32_t lbl_8001EF28;
extern uint32_t lbl_8001EF2C;
extern uint32_t lbl_8001EF30;
extern uint32_t lbl_8001EF34;
extern uint32_t lbl_8001EF38;
extern uint32_t lbl_8001EF3C;
extern uint32_t lbl_8001EF40;
extern uint32_t lbl_8001EF44;
extern uint32_t lbl_8001EF48;
extern uint32_t lbl_8001EF50;
extern uint32_t lbl_8001EF54;
extern uint32_t lbl_8001EF58;
extern uint32_t lbl_8001EF5C;
extern uint32_t lbl_8001EF60;
extern uint32_t lbl_8001EF64;
extern uint32_t lbl_8001EF68;
extern uint32_t lbl_8001EF6C;
extern uint32_t lbl_8001EF70;
extern uint32_t lbl_8001EF74;
extern uint32_t lbl_8001EF88;
extern uint32_t lbl_8001EF8C;
extern uint32_t lbl_8001EF90;
extern uint32_t lbl_8001EF94;
extern uint32_t lbl_8001EF98;
extern uint32_t lbl_8001EF9C;
extern uint32_t lbl_8001EFA0;
extern uint32_t lbl_8001EFA4;
extern uint32_t lbl_8001EFA8;
extern uint32_t lbl_8001EFAC;
extern uint32_t lbl_8001EFB0;
extern uint32_t lbl_8001EFB4;
extern uint32_t lbl_8001EFB8;
extern uint32_t lbl_8001EFBC;
extern uint32_t lbl_8001EFC0;
extern uint32_t lbl_8001EFC4;
extern uint32_t lbl_8001EFC8;
extern uint32_t lbl_8001EFCC;
extern uint32_t lbl_8001EFD0;
extern uint32_t lbl_8001EFD4;
extern uint32_t lbl_8001EFD8;
extern uint32_t lbl_8001EFE0;
extern uint32_t lbl_8001EFE4;
extern uint32_t lbl_8001EFF0;
extern uint32_t lbl_8001EFF4;
extern uint32_t lbl_8001EFF8;
extern uint32_t lbl_8001EFFC;
extern uint32_t lbl_8001EFFE;
extern uint32_t lbl_8001F000;
extern uint32_t lbl_8001F008;
extern uint32_t lbl_8001F00C;
extern uint32_t lbl_8001F010;
extern uint32_t lbl_8001F018;
extern uint32_t lbl_8001F01C;
extern uint32_t lbl_8001F020;
extern uint32_t lbl_8001F028;
extern uint32_t lbl_8001F02C;
extern uint32_t lbl_8001F058;
extern uint32_t lbl_8001F064;
extern uint32_t lbl_8001F068;
extern uint32_t lbl_8001F070;
extern uint32_t lbl_8001F074;
extern uint32_t lbl_8001F078;
extern uint32_t lbl_8001F07C;
extern uint32_t lbl_8001F080;
extern uint8_t lbl_8001EE58;
extern uint8_t lbl_8001F084;

// Data section: lbl_8001EE60
// Address: 0x8001EE60
uint8_t lbl_8001EE60[0x4];

// Data section: lbl_8001EE64
// Address: 0x8001EE64
uint8_t lbl_8001EE64[0x4];

// Data section: BootInfo_8001EE68
// Address: 0x8001EE68
uint8_t BootInfo_8001EE68[0x4];

// Data section: BI2DebugFlag_8001EE6C
// Address: 0x8001EE6C
uint8_t BI2DebugFlag_8001EE6C[0x4];

// Data section: BI2DebugFlagHolder_8001EE70
// Address: 0x8001EE70
uint8_t BI2DebugFlagHolder_8001EE70[0x4];

// Data section: AreWeInitialized_8001EE74
// Address: 0x8001EE74
uint8_t AreWeInitialized_8001EE74[0x4];

// Data section: OSExceptionTable_8001EE78
// Address: 0x8001EE78
uint8_t OSExceptionTable_8001EE78[0x4];

// Data section: __OSInIPL
// Address: 0x8001EE7C
uint8_t __OSInIPL[0x4];

// Data section: __OSStartTime
// Address: 0x8001EE80
uint8_t __OSStartTime[0x8];

// Data section: AlarmQueue_8001EE88
// Address: 0x8001EE88
uint8_t AlarmQueue_8001EE88[0x8];

// Data section: __OSArenaHi_8001EE90
// Address: 0x8001EE90
uint8_t __OSArenaHi_8001EE90[0x4];

// Data section: gap_08_8001EE94_sbss
// Address: 0x8001EE94
uint8_t gap_08_8001EE94_sbss[0x4];

// Data section: InterruptHandlerTable_8001EE98
// Address: 0x8001EE98
uint8_t InterruptHandlerTable_8001EE98[0x4];

// Data section: __OSLastInterruptSrr0
// Address: 0x8001EE9C
uint8_t __OSLastInterruptSrr0[0x4];

// Data section: __OSLastInterrupt
// Address: 0x8001EEA0
uint8_t __OSLastInterrupt[0x2];

// Data section: gap_08_8001EEA2_sbss
// Address: 0x8001EEA2
uint8_t gap_08_8001EEA2_sbss[0x6];

// Data section: __OSLastInterruptTime
// Address: 0x8001EEA8
uint8_t __OSLastInterruptTime[0x8];

// Data section: lbl_8001EEB0
// Address: 0x8001EEB0
uint8_t lbl_8001EEB0[0x4];

// Data section: lbl_8001EEB4
// Address: 0x8001EEB4
uint8_t lbl_8001EEB4[0x4];

// Data section: lbl_8001EEB8
// Address: 0x8001EEB8
uint8_t lbl_8001EEB8[0x8];

// Data section: ResetFunctionQueue_8001EEC0
// Address: 0x8001EEC0
uint8_t ResetFunctionQueue_8001EEC0[0x8];

// Data section: lbl_8001EEC8
// Address: 0x8001EEC8
uint8_t lbl_8001EEC8[0x4];

// Data section: lbl_8001EECC
// Address: 0x8001EECC
uint8_t lbl_8001EECC[0x4];

// Data section: lbl_8001EED0
// Address: 0x8001EED0
uint8_t lbl_8001EED0[0x8];

// Data section: lbl_8001EED8
// Address: 0x8001EED8
uint8_t lbl_8001EED8[0x4];

// Data section: lbl_8001EEDC
// Address: 0x8001EEDC
uint8_t lbl_8001EEDC[0x4];

// Data section: RunQueueBits_8001EEE0
// Address: 0x8001EEE0
uint8_t RunQueueBits_8001EEE0[0x4];

// Data section: RunQueueHint_8001EEE4
// Address: 0x8001EEE4
uint8_t RunQueueHint_8001EEE4[0x4];

// Data section: Reschedule_8001EEE8
// Address: 0x8001EEE8
uint8_t Reschedule_8001EEE8[0x4];

// Data section: gap_08_8001EEEC_sbss
// Address: 0x8001EEEC
uint8_t gap_08_8001EEEC_sbss[0x4];

// Data section: lbl_8001EEF0
// Address: 0x8001EEF0
uint8_t lbl_8001EEF0[0x4];

// Data section: lbl_8001EEF4
// Address: 0x8001EEF4
uint8_t lbl_8001EEF4[0x4];

// Data section: lbl_8001EEF8
// Address: 0x8001EEF8
uint8_t lbl_8001EEF8[0x4];

// Data section: lbl_8001EEFC
// Address: 0x8001EEFC
uint8_t lbl_8001EEFC[0x4];

// Data section: lbl_8001EF00
// Address: 0x8001EF00
uint8_t lbl_8001EF00[0x4];

// Data section: cmdTypeAndStatus_371_8001EF04
// Address: 0x8001EF04
uint8_t cmdTypeAndStatus_371_8001EF04[0x4];

// Data section: lbl_8001EF08
// Address: 0x8001EF08
uint8_t lbl_8001EF08[0x8];

// Data section: SamplingRate_8001EF10
// Address: 0x8001EF10
uint8_t SamplingRate_8001EF10[0x4];

// Data section: gap_08_8001EF14_sbss
// Address: 0x8001EF14
uint8_t gap_08_8001EF14_sbss[0x4];

// Data section: __DBInterface
// Address: 0x8001EF18
uint8_t __DBInterface[0x4];

// Data section: DBVerbose
// Address: 0x8001EF1C
uint8_t DBVerbose[0x4];

// Data section: lbl_8001EF20
// Address: 0x8001EF20
uint8_t lbl_8001EF20[0x4];

// Data section: lbl_8001EF24
// Address: 0x8001EF24
uint8_t lbl_8001EF24[0x4];

// Data section: lbl_8001EF28
// Address: 0x8001EF28
uint8_t lbl_8001EF28[0x4];

// Data section: lbl_8001EF2C
// Address: 0x8001EF2C
uint8_t lbl_8001EF2C[0x4];

// Data section: lbl_8001EF30
// Address: 0x8001EF30
uint8_t lbl_8001EF30[0x4];

// Data section: lbl_8001EF34
// Address: 0x8001EF34
uint8_t lbl_8001EF34[0x4];

// Data section: lbl_8001EF38
// Address: 0x8001EF38
uint8_t lbl_8001EF38[0x4];

// Data section: lbl_8001EF3C
// Address: 0x8001EF3C
uint8_t lbl_8001EF3C[0x4];

// Data section: lbl_8001EF40
// Address: 0x8001EF40
uint8_t lbl_8001EF40[0x4];

// Data section: lbl_8001EF44
// Address: 0x8001EF44
uint8_t lbl_8001EF44[0x4];

// Data section: lbl_8001EF48
// Address: 0x8001EF48
uint8_t lbl_8001EF48[0x8];

// Data section: lbl_8001EF50
// Address: 0x8001EF50
uint8_t lbl_8001EF50[0x4];

// Data section: lbl_8001EF54
// Address: 0x8001EF54
uint8_t lbl_8001EF54[0x4];

// Data section: lbl_8001EF58
// Address: 0x8001EF58
uint8_t lbl_8001EF58[0x4];

// Data section: lbl_8001EF5C
// Address: 0x8001EF5C
uint8_t lbl_8001EF5C[0x4];

// Data section: lbl_8001EF60
// Address: 0x8001EF60
uint8_t lbl_8001EF60[0x4];

// Data section: lbl_8001EF64
// Address: 0x8001EF64
uint8_t lbl_8001EF64[0x4];

// Data section: lbl_8001EF68
// Address: 0x8001EF68
uint8_t lbl_8001EF68[0x4];

// Data section: lbl_8001EF6C
// Address: 0x8001EF6C
uint8_t lbl_8001EF6C[0x4];

// Data section: lbl_8001EF70
// Address: 0x8001EF70
uint8_t lbl_8001EF70[0x4];

// Data section: lbl_8001EF74
// Address: 0x8001EF74
uint8_t lbl_8001EF74[0x4];

// Data section: __DVDLongFileNameFlag
// Address: 0x8001EF78
uint8_t __DVDLongFileNameFlag[0x4];

// Data section: lbl_8001EF7C
// Address: 0x8001EF7C
uint8_t lbl_8001EF7C[0xC];

// Data section: lbl_8001EF88
// Address: 0x8001EF88
uint8_t lbl_8001EF88[0x4];

// Data section: lbl_8001EF8C
// Address: 0x8001EF8C
uint8_t lbl_8001EF8C[0x4];

// Data section: lbl_8001EF90
// Address: 0x8001EF90
uint8_t lbl_8001EF90[0x4];

// Data section: lbl_8001EF94
// Address: 0x8001EF94
uint8_t lbl_8001EF94[0x4];

// Data section: lbl_8001EF98
// Address: 0x8001EF98
uint8_t lbl_8001EF98[0x4];

// Data section: lbl_8001EF9C
// Address: 0x8001EF9C
uint8_t lbl_8001EF9C[0x4];

// Data section: lbl_8001EFA0
// Address: 0x8001EFA0
uint8_t lbl_8001EFA0[0x4];

// Data section: lbl_8001EFA4
// Address: 0x8001EFA4
uint8_t lbl_8001EFA4[0x4];

// Data section: lbl_8001EFA8
// Address: 0x8001EFA8
uint8_t lbl_8001EFA8[0x4];

// Data section: lbl_8001EFAC
// Address: 0x8001EFAC
uint8_t lbl_8001EFAC[0x4];

// Data section: lbl_8001EFB0
// Address: 0x8001EFB0
uint8_t lbl_8001EFB0[0x4];

// Data section: lbl_8001EFB4
// Address: 0x8001EFB4
uint8_t lbl_8001EFB4[0x4];

// Data section: lbl_8001EFB8
// Address: 0x8001EFB8
uint8_t lbl_8001EFB8[0x4];

// Data section: lbl_8001EFBC
// Address: 0x8001EFBC
uint8_t lbl_8001EFBC[0x4];

// Data section: lbl_8001EFC0
// Address: 0x8001EFC0
uint8_t lbl_8001EFC0[0x4];

// Data section: lbl_8001EFC4
// Address: 0x8001EFC4
uint8_t lbl_8001EFC4[0x4];

// Data section: lbl_8001EFC8
// Address: 0x8001EFC8
uint8_t lbl_8001EFC8[0x4];

// Data section: lbl_8001EFCC
// Address: 0x8001EFCC
uint8_t lbl_8001EFCC[0x4];

// Data section: lbl_8001EFD0
// Address: 0x8001EFD0
uint8_t lbl_8001EFD0[0x4];

// Data section: lbl_8001EFD4
// Address: 0x8001EFD4
uint8_t lbl_8001EFD4[0x4];

// Data section: lbl_8001EFD8
// Address: 0x8001EFD8
uint8_t lbl_8001EFD8[0x8];

// Data section: lbl_8001EFE0
// Address: 0x8001EFE0
uint8_t lbl_8001EFE0[0x4];

// Data section: lbl_8001EFE4
// Address: 0x8001EFE4
uint8_t lbl_8001EFE4[0x4];

// Data section: lbl_8001EFE8
// Address: 0x8001EFE8
uint8_t lbl_8001EFE8[0x8];

// Data section: lbl_8001EFF0
// Address: 0x8001EFF0
uint8_t lbl_8001EFF0[0x4];

// Data section: lbl_8001EFF4
// Address: 0x8001EFF4
uint8_t lbl_8001EFF4[0x4];

// Data section: lbl_8001EFF8
// Address: 0x8001EFF8
uint8_t lbl_8001EFF8[0x4];

// Data section: lbl_8001EFFC
// Address: 0x8001EFFC
uint8_t lbl_8001EFFC[0x2];

// Data section: lbl_8001EFFE
// Address: 0x8001EFFE
uint8_t lbl_8001EFFE[0x2];

// Data section: lbl_8001F000
// Address: 0x8001F000
uint8_t lbl_8001F000[0x8];

// Data section: lbl_8001F008
// Address: 0x8001F008
uint8_t lbl_8001F008[0x4];

// Data section: lbl_8001F00C
// Address: 0x8001F00C
uint8_t lbl_8001F00C[0x4];

// Data section: lbl_8001F010
// Address: 0x8001F010
uint8_t lbl_8001F010[0x8];

// Data section: lbl_8001F018
// Address: 0x8001F018
uint8_t lbl_8001F018[0x4];

// Data section: lbl_8001F01C
// Address: 0x8001F01C
uint8_t lbl_8001F01C[0x4];

// Data section: lbl_8001F020
// Address: 0x8001F020
uint8_t lbl_8001F020[0x4];

// Data section: CurrTvMode_8001F024
// Address: 0x8001F024
uint8_t CurrTvMode_8001F024[0x4];

// Data section: lbl_8001F028
// Address: 0x8001F028
uint8_t lbl_8001F028[0x4];

// Data section: lbl_8001F02C
// Address: 0x8001F02C
uint8_t lbl_8001F02C[0x4];

// Data section: __PADSpec
// Address: 0x8001F030
uint8_t __PADSpec[0x4];

// Data section: gap_08_8001F034_sbss
// Address: 0x8001F034
uint8_t gap_08_8001F034_sbss[0x4];

// Data section: __global_destructor_chain
// Address: 0x8001F038
uint8_t __global_destructor_chain[0x4];

// Data section: gap_08_8001F03C_sbss
// Address: 0x8001F03C
uint8_t gap_08_8001F03C_sbss[0x4];

// Data section: __aborting
// Address: 0x8001F040
uint8_t __aborting[0x4];

// Data section: atexit_curr_func_8001F044
// Address: 0x8001F044
uint8_t atexit_curr_func_8001F044[0x4];

// Data section: __atexit_curr_func_8001F048
// Address: 0x8001F048
uint8_t __atexit_curr_func_8001F048[0x4];

// Data section: __stdio_exit
// Address: 0x8001F04C
uint8_t __stdio_exit[0x4];

// Data section: __console_exit
// Address: 0x8001F050
uint8_t __console_exit[0x4];

// Data section: gap_08_8001F054_sbss
// Address: 0x8001F054
uint8_t gap_08_8001F054_sbss[0x4];

// Data section: lbl_8001F058
// Address: 0x8001F058
uint8_t lbl_8001F058[0x8];

// Data section: lbl_8001F060
// Address: 0x8001F060
uint8_t lbl_8001F060[0x4];

// Data section: lbl_8001F064
// Address: 0x8001F064
uint8_t lbl_8001F064[0x4];

// Data section: lbl_8001F068
// Address: 0x8001F068
uint8_t lbl_8001F068[0x8];

// Data section: lbl_8001F070
// Address: 0x8001F070
uint8_t lbl_8001F070[0x4];

// Data section: lbl_8001F074
// Address: 0x8001F074
uint8_t lbl_8001F074[0x4];

// Data section: lbl_8001F078
// Address: 0x8001F078
uint8_t lbl_8001F078[0x4];

// Data section: lbl_8001F07C
// Address: 0x8001F07C
uint8_t lbl_8001F07C[0x4];

// Data section: lbl_8001F080
// Address: 0x8001F080
uint8_t lbl_8001F080[0x4];

// Data section: lbl_8001F084
// Address: 0x8001F084
uint8_t lbl_8001F084[0x1];
