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
extern uint32_t __OSLastInterruptSrr0;
extern uint32_t __OSLastInterruptTime;
extern uint32_t __OSLastInterruptTime+0x4;
extern uint32_t __OSStartTime;
extern uint32_t __OSStartTime+0x4;
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

// Data section: lbl_8001EE60
// Address: 0x8001EE60
uint32_t lbl_8001EE60[] = {
    // Unrecognized: .skip 0x4
};

// Data section: lbl_8001EE64
// Address: 0x8001EE64
uint32_t lbl_8001EE64[] = {
    // Unrecognized: .skip 0x4
};

// Data section: BootInfo_8001EE68
// Address: 0x8001EE68
uint32_t BootInfo_8001EE68[] = {
    // Unrecognized: .skip 0x4
};

// Data section: BI2DebugFlag_8001EE6C
// Address: 0x8001EE6C
uint32_t BI2DebugFlag_8001EE6C[] = {
    // Unrecognized: .skip 0x4
};

// Data section: BI2DebugFlagHolder_8001EE70
// Address: 0x8001EE70
uint32_t BI2DebugFlagHolder_8001EE70[] = {
    // Unrecognized: .skip 0x4
};

// Data section: AreWeInitialized_8001EE74
// Address: 0x8001EE74
uint32_t AreWeInitialized_8001EE74[] = {
    // Unrecognized: .skip 0x4
};

// Data section: OSExceptionTable_8001EE78
// Address: 0x8001EE78
uint32_t OSExceptionTable_8001EE78[] = {
    // Unrecognized: .skip 0x4
};

// Data section: __OSInIPL
// Address: 0x8001EE7C
uint32_t __OSInIPL[] = {
    // Unrecognized: .skip 0x4
};

// Data section: __OSStartTime
// Address: 0x8001EE80
uint32_t __OSStartTime[] = {
    // Unrecognized: .skip 0x8
};

// Data section: AlarmQueue_8001EE88
// Address: 0x8001EE88
uint32_t AlarmQueue_8001EE88[] = {
    // Unrecognized: .skip 0x8
};

// Data section: __OSArenaHi_8001EE90
// Address: 0x8001EE90
uint32_t __OSArenaHi_8001EE90[] = {
    // Unrecognized: .skip 0x4
};

// Data section: gap_08_8001EE94_sbss
// Address: 0x8001EE94
uint32_t gap_08_8001EE94_sbss[] = {
    // Unrecognized: .skip 0x4
};

// Data section: InterruptHandlerTable_8001EE98
// Address: 0x8001EE98
uint32_t InterruptHandlerTable_8001EE98[] = {
    // Unrecognized: .skip 0x4
};

// Data section: __OSLastInterruptSrr0
// Address: 0x8001EE9C
uint32_t __OSLastInterruptSrr0[] = {
    // Unrecognized: .skip 0x4
};

// Data section: __OSLastInterrupt
// Address: 0x8001EEA0
uint32_t __OSLastInterrupt[] = {
    // Unrecognized: .skip 0x2
};

// Data section: gap_08_8001EEA2_sbss
// Address: 0x8001EEA2
uint32_t gap_08_8001EEA2_sbss[] = {
    // Unrecognized: .skip 0x6
};

// Data section: __OSLastInterruptTime
// Address: 0x8001EEA8
uint32_t __OSLastInterruptTime[] = {
    // Unrecognized: .skip 0x8
};

// Data section: lbl_8001EEB0
// Address: 0x8001EEB0
uint32_t lbl_8001EEB0[] = {
    // Unrecognized: .skip 0x4
};

// Data section: lbl_8001EEB4
// Address: 0x8001EEB4
uint32_t lbl_8001EEB4[] = {
    // Unrecognized: .skip 0x4
};

// Data section: lbl_8001EEB8
// Address: 0x8001EEB8
uint32_t lbl_8001EEB8[] = {
    // Unrecognized: .skip 0x8
};

// Data section: ResetFunctionQueue_8001EEC0
// Address: 0x8001EEC0
uint32_t ResetFunctionQueue_8001EEC0[] = {
    // Unrecognized: .skip 0x8
};

// Data section: lbl_8001EEC8
// Address: 0x8001EEC8
uint32_t lbl_8001EEC8[] = {
    // Unrecognized: .skip 0x4
};

// Data section: lbl_8001EECC
// Address: 0x8001EECC
uint32_t lbl_8001EECC[] = {
    // Unrecognized: .skip 0x4
};

// Data section: lbl_8001EED0
// Address: 0x8001EED0
uint32_t lbl_8001EED0[] = {
    // Unrecognized: .skip 0x8
};

// Data section: lbl_8001EED8
// Address: 0x8001EED8
uint32_t lbl_8001EED8[] = {
    // Unrecognized: .skip 0x4
};

// Data section: lbl_8001EEDC
// Address: 0x8001EEDC
uint32_t lbl_8001EEDC[] = {
    // Unrecognized: .skip 0x4
};

// Data section: RunQueueBits_8001EEE0
// Address: 0x8001EEE0
uint32_t RunQueueBits_8001EEE0[] = {
    // Unrecognized: .skip 0x4
};

// Data section: RunQueueHint_8001EEE4
// Address: 0x8001EEE4
uint32_t RunQueueHint_8001EEE4[] = {
    // Unrecognized: .skip 0x4
};

// Data section: Reschedule_8001EEE8
// Address: 0x8001EEE8
uint32_t Reschedule_8001EEE8[] = {
    // Unrecognized: .skip 0x4
};

// Data section: gap_08_8001EEEC_sbss
// Address: 0x8001EEEC
uint32_t gap_08_8001EEEC_sbss[] = {
    // Unrecognized: .skip 0x4
};

// Data section: lbl_8001EEF0
// Address: 0x8001EEF0
uint32_t lbl_8001EEF0[] = {
    // Unrecognized: .skip 0x4
};

// Data section: lbl_8001EEF4
// Address: 0x8001EEF4
uint32_t lbl_8001EEF4[] = {
    // Unrecognized: .skip 0x4
};

// Data section: lbl_8001EEF8
// Address: 0x8001EEF8
uint32_t lbl_8001EEF8[] = {
    // Unrecognized: .skip 0x4
};

// Data section: lbl_8001EEFC
// Address: 0x8001EEFC
uint32_t lbl_8001EEFC[] = {
    // Unrecognized: .skip 0x4
};

// Data section: lbl_8001EF00
// Address: 0x8001EF00
uint32_t lbl_8001EF00[] = {
    // Unrecognized: .skip 0x4
};

// Data section: cmdTypeAndStatus$371_8001EF04
// Address: 0x8001EF04
uint32_t cmdTypeAndStatus$371_8001EF04[] = {
    // Unrecognized: .skip 0x4
};

// Data section: lbl_8001EF08
// Address: 0x8001EF08
uint32_t lbl_8001EF08[] = {
    // Unrecognized: .skip 0x8
};

// Data section: SamplingRate_8001EF10
// Address: 0x8001EF10
uint32_t SamplingRate_8001EF10[] = {
    // Unrecognized: .skip 0x4
};

// Data section: gap_08_8001EF14_sbss
// Address: 0x8001EF14
uint32_t gap_08_8001EF14_sbss[] = {
    // Unrecognized: .skip 0x4
};

// Data section: __DBInterface
// Address: 0x8001EF18
uint32_t __DBInterface[] = {
    // Unrecognized: .skip 0x4
};

// Data section: DBVerbose
// Address: 0x8001EF1C
uint32_t DBVerbose[] = {
    // Unrecognized: .skip 0x4
};

// Data section: lbl_8001EF20
// Address: 0x8001EF20
uint32_t lbl_8001EF20[] = {
    // Unrecognized: .skip 0x4
};

// Data section: lbl_8001EF24
// Address: 0x8001EF24
uint32_t lbl_8001EF24[] = {
    // Unrecognized: .skip 0x4
};

// Data section: lbl_8001EF28
// Address: 0x8001EF28
uint32_t lbl_8001EF28[] = {
    // Unrecognized: .skip 0x4
};

// Data section: lbl_8001EF2C
// Address: 0x8001EF2C
uint32_t lbl_8001EF2C[] = {
    // Unrecognized: .skip 0x4
};

// Data section: lbl_8001EF30
// Address: 0x8001EF30
uint32_t lbl_8001EF30[] = {
    // Unrecognized: .skip 0x4
};

// Data section: lbl_8001EF34
// Address: 0x8001EF34
uint32_t lbl_8001EF34[] = {
    // Unrecognized: .skip 0x4
};

// Data section: lbl_8001EF38
// Address: 0x8001EF38
uint32_t lbl_8001EF38[] = {
    // Unrecognized: .skip 0x4
};

// Data section: lbl_8001EF3C
// Address: 0x8001EF3C
uint32_t lbl_8001EF3C[] = {
    // Unrecognized: .skip 0x4
};

// Data section: lbl_8001EF40
// Address: 0x8001EF40
uint32_t lbl_8001EF40[] = {
    // Unrecognized: .skip 0x4
};

// Data section: lbl_8001EF44
// Address: 0x8001EF44
uint32_t lbl_8001EF44[] = {
    // Unrecognized: .skip 0x4
};

// Data section: lbl_8001EF48
// Address: 0x8001EF48
uint32_t lbl_8001EF48[] = {
    // Unrecognized: .skip 0x8
};

// Data section: lbl_8001EF50
// Address: 0x8001EF50
uint32_t lbl_8001EF50[] = {
    // Unrecognized: .skip 0x4
};

// Data section: lbl_8001EF54
// Address: 0x8001EF54
uint32_t lbl_8001EF54[] = {
    // Unrecognized: .skip 0x4
};

// Data section: lbl_8001EF58
// Address: 0x8001EF58
uint32_t lbl_8001EF58[] = {
    // Unrecognized: .skip 0x4
};

// Data section: lbl_8001EF5C
// Address: 0x8001EF5C
uint32_t lbl_8001EF5C[] = {
    // Unrecognized: .skip 0x4
};

// Data section: lbl_8001EF60
// Address: 0x8001EF60
uint32_t lbl_8001EF60[] = {
    // Unrecognized: .skip 0x4
};

// Data section: lbl_8001EF64
// Address: 0x8001EF64
uint32_t lbl_8001EF64[] = {
    // Unrecognized: .skip 0x4
};

// Data section: lbl_8001EF68
// Address: 0x8001EF68
uint32_t lbl_8001EF68[] = {
    // Unrecognized: .skip 0x4
};

// Data section: lbl_8001EF6C
// Address: 0x8001EF6C
uint32_t lbl_8001EF6C[] = {
    // Unrecognized: .skip 0x4
};

// Data section: lbl_8001EF70
// Address: 0x8001EF70
uint32_t lbl_8001EF70[] = {
    // Unrecognized: .skip 0x4
};

// Data section: lbl_8001EF74
// Address: 0x8001EF74
uint32_t lbl_8001EF74[] = {
    // Unrecognized: .skip 0x4
};

// Data section: __DVDLongFileNameFlag
// Address: 0x8001EF78
uint32_t __DVDLongFileNameFlag[] = {
    // Unrecognized: .skip 0x4
};

// Data section: lbl_8001EF7C
// Address: 0x8001EF7C
uint32_t lbl_8001EF7C[] = {
    // Unrecognized: .skip 0xC
};

// Data section: lbl_8001EF88
// Address: 0x8001EF88
uint32_t lbl_8001EF88[] = {
    // Unrecognized: .skip 0x4
};

// Data section: lbl_8001EF8C
// Address: 0x8001EF8C
uint32_t lbl_8001EF8C[] = {
    // Unrecognized: .skip 0x4
};

// Data section: lbl_8001EF90
// Address: 0x8001EF90
uint32_t lbl_8001EF90[] = {
    // Unrecognized: .skip 0x4
};

// Data section: lbl_8001EF94
// Address: 0x8001EF94
uint32_t lbl_8001EF94[] = {
    // Unrecognized: .skip 0x4
};

// Data section: lbl_8001EF98
// Address: 0x8001EF98
uint32_t lbl_8001EF98[] = {
    // Unrecognized: .skip 0x4
};

// Data section: lbl_8001EF9C
// Address: 0x8001EF9C
uint32_t lbl_8001EF9C[] = {
    // Unrecognized: .skip 0x4
};

// Data section: lbl_8001EFA0
// Address: 0x8001EFA0
uint32_t lbl_8001EFA0[] = {
    // Unrecognized: .skip 0x4
};

// Data section: lbl_8001EFA4
// Address: 0x8001EFA4
uint32_t lbl_8001EFA4[] = {
    // Unrecognized: .skip 0x4
};

// Data section: lbl_8001EFA8
// Address: 0x8001EFA8
uint32_t lbl_8001EFA8[] = {
    // Unrecognized: .skip 0x4
};

// Data section: lbl_8001EFAC
// Address: 0x8001EFAC
uint32_t lbl_8001EFAC[] = {
    // Unrecognized: .skip 0x4
};

// Data section: lbl_8001EFB0
// Address: 0x8001EFB0
uint32_t lbl_8001EFB0[] = {
    // Unrecognized: .skip 0x4
};

// Data section: lbl_8001EFB4
// Address: 0x8001EFB4
uint32_t lbl_8001EFB4[] = {
    // Unrecognized: .skip 0x4
};

// Data section: lbl_8001EFB8
// Address: 0x8001EFB8
uint32_t lbl_8001EFB8[] = {
    // Unrecognized: .skip 0x4
};

// Data section: lbl_8001EFBC
// Address: 0x8001EFBC
uint32_t lbl_8001EFBC[] = {
    // Unrecognized: .skip 0x4
};

// Data section: lbl_8001EFC0
// Address: 0x8001EFC0
uint32_t lbl_8001EFC0[] = {
    // Unrecognized: .skip 0x4
};

// Data section: lbl_8001EFC4
// Address: 0x8001EFC4
uint32_t lbl_8001EFC4[] = {
    // Unrecognized: .skip 0x4
};

// Data section: lbl_8001EFC8
// Address: 0x8001EFC8
uint32_t lbl_8001EFC8[] = {
    // Unrecognized: .skip 0x4
};

// Data section: lbl_8001EFCC
// Address: 0x8001EFCC
uint32_t lbl_8001EFCC[] = {
    // Unrecognized: .skip 0x4
};

// Data section: lbl_8001EFD0
// Address: 0x8001EFD0
uint32_t lbl_8001EFD0[] = {
    // Unrecognized: .skip 0x4
};

// Data section: lbl_8001EFD4
// Address: 0x8001EFD4
uint32_t lbl_8001EFD4[] = {
    // Unrecognized: .skip 0x4
};

// Data section: lbl_8001EFD8
// Address: 0x8001EFD8
uint32_t lbl_8001EFD8[] = {
    // Unrecognized: .skip 0x8
};

// Data section: lbl_8001EFE0
// Address: 0x8001EFE0
uint32_t lbl_8001EFE0[] = {
    // Unrecognized: .skip 0x4
};

// Data section: lbl_8001EFE4
// Address: 0x8001EFE4
uint32_t lbl_8001EFE4[] = {
    // Unrecognized: .skip 0x4
};

// Data section: lbl_8001EFE8
// Address: 0x8001EFE8
uint32_t lbl_8001EFE8[] = {
    // Unrecognized: .skip 0x8
};

// Data section: lbl_8001EFF0
// Address: 0x8001EFF0
uint32_t lbl_8001EFF0[] = {
    // Unrecognized: .skip 0x4
};

// Data section: lbl_8001EFF4
// Address: 0x8001EFF4
uint32_t lbl_8001EFF4[] = {
    // Unrecognized: .skip 0x4
};

// Data section: lbl_8001EFF8
// Address: 0x8001EFF8
uint32_t lbl_8001EFF8[] = {
    // Unrecognized: .skip 0x4
};

// Data section: lbl_8001EFFC
// Address: 0x8001EFFC
uint32_t lbl_8001EFFC[] = {
    // Unrecognized: .skip 0x2
};

// Data section: lbl_8001EFFE
// Address: 0x8001EFFE
uint32_t lbl_8001EFFE[] = {
    // Unrecognized: .skip 0x2
};

// Data section: lbl_8001F000
// Address: 0x8001F000
uint32_t lbl_8001F000[] = {
    // Unrecognized: .skip 0x8
};

// Data section: lbl_8001F008
// Address: 0x8001F008
uint32_t lbl_8001F008[] = {
    // Unrecognized: .skip 0x4
};

// Data section: lbl_8001F00C
// Address: 0x8001F00C
uint32_t lbl_8001F00C[] = {
    // Unrecognized: .skip 0x4
};

// Data section: lbl_8001F010
// Address: 0x8001F010
uint32_t lbl_8001F010[] = {
    // Unrecognized: .skip 0x8
};

// Data section: lbl_8001F018
// Address: 0x8001F018
uint32_t lbl_8001F018[] = {
    // Unrecognized: .skip 0x4
};

// Data section: lbl_8001F01C
// Address: 0x8001F01C
uint32_t lbl_8001F01C[] = {
    // Unrecognized: .skip 0x4
};

// Data section: lbl_8001F020
// Address: 0x8001F020
uint32_t lbl_8001F020[] = {
    // Unrecognized: .skip 0x4
};

// Data section: CurrTvMode_8001F024
// Address: 0x8001F024
uint32_t CurrTvMode_8001F024[] = {
    // Unrecognized: .skip 0x4
};

// Data section: lbl_8001F028
// Address: 0x8001F028
uint32_t lbl_8001F028[] = {
    // Unrecognized: .skip 0x4
};

// Data section: lbl_8001F02C
// Address: 0x8001F02C
uint32_t lbl_8001F02C[] = {
    // Unrecognized: .skip 0x4
};

// Data section: __PADSpec
// Address: 0x8001F030
uint32_t __PADSpec[] = {
    // Unrecognized: .skip 0x4
};

// Data section: gap_08_8001F034_sbss
// Address: 0x8001F034
uint32_t gap_08_8001F034_sbss[] = {
    // Unrecognized: .skip 0x4
};

// Data section: __global_destructor_chain
// Address: 0x8001F038
uint32_t __global_destructor_chain[] = {
    // Unrecognized: .skip 0x4
};

// Data section: gap_08_8001F03C_sbss
// Address: 0x8001F03C
uint32_t gap_08_8001F03C_sbss[] = {
    // Unrecognized: .skip 0x4
};

// Data section: __aborting
// Address: 0x8001F040
uint32_t __aborting[] = {
    // Unrecognized: .skip 0x4
};

// Data section: atexit_curr_func_8001F044
// Address: 0x8001F044
uint32_t atexit_curr_func_8001F044[] = {
    // Unrecognized: .skip 0x4
};

// Data section: __atexit_curr_func_8001F048
// Address: 0x8001F048
uint32_t __atexit_curr_func_8001F048[] = {
    // Unrecognized: .skip 0x4
};

// Data section: __stdio_exit
// Address: 0x8001F04C
uint32_t __stdio_exit[] = {
    // Unrecognized: .skip 0x4
};

// Data section: __console_exit
// Address: 0x8001F050
uint32_t __console_exit[] = {
    // Unrecognized: .skip 0x4
};

// Data section: gap_08_8001F054_sbss
// Address: 0x8001F054
uint32_t gap_08_8001F054_sbss[] = {
    // Unrecognized: .skip 0x4
};

// Data section: lbl_8001F058
// Address: 0x8001F058
uint32_t lbl_8001F058[] = {
    // Unrecognized: .skip 0x8
};

// Data section: lbl_8001F060
// Address: 0x8001F060
uint32_t lbl_8001F060[] = {
    // Unrecognized: .skip 0x4
};

// Data section: lbl_8001F064
// Address: 0x8001F064
uint32_t lbl_8001F064[] = {
    // Unrecognized: .skip 0x4
};

// Data section: lbl_8001F068
// Address: 0x8001F068
uint32_t lbl_8001F068[] = {
    // Unrecognized: .skip 0x8
};

// Data section: lbl_8001F070
// Address: 0x8001F070
uint32_t lbl_8001F070[] = {
    // Unrecognized: .skip 0x4
};

// Data section: lbl_8001F074
// Address: 0x8001F074
uint32_t lbl_8001F074[] = {
    // Unrecognized: .skip 0x4
};

// Data section: lbl_8001F078
// Address: 0x8001F078
uint32_t lbl_8001F078[] = {
    // Unrecognized: .skip 0x4
};

// Data section: lbl_8001F07C
// Address: 0x8001F07C
uint32_t lbl_8001F07C[] = {
    // Unrecognized: .skip 0x4
};

// Data section: lbl_8001F080
// Address: 0x8001F080
uint32_t lbl_8001F080[] = {
    // Unrecognized: .skip 0x4
};

// Data section: lbl_8001F084
// Address: 0x8001F084
uint32_t lbl_8001F084[] = {
    // Unrecognized: .skip 0x1
};
