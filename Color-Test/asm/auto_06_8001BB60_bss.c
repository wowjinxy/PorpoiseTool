#include "all_headers.h"
#include "auto_06_8001BB60_bss.h"
#include <stdint.h>
#include <stdio.h>

#include "gc_env.h"

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

// Data section: __OSErrorTable
// Address: 0x8001BB60
uint32_t __OSErrorTable[] = {
    // Unrecognized: .skip 0x40
};

// Data section: lbl_8001BBA0
// Address: 0x8001BBA0
uint32_t lbl_8001BBA0[] = {
    // Unrecognized: .skip 0x20
};

// Data section: Scb_8001BBC0
// Address: 0x8001BBC0
uint32_t Scb_8001BBC0[] = {
    // Unrecognized: .skip 0x54
};

// Data section: gap_06_8001BC14_bss
// Address: 0x8001BC14
uint32_t gap_06_8001BC14_bss[] = {
    // Unrecognized: .skip 0x4
};

// Data section: RunQueue_8001BC18
// Address: 0x8001BC18
uint32_t RunQueue_8001BC18[] = {
    // Unrecognized: .skip 0x100
};

// Data section: gap_06_8001BD18_bss
// Address: 0x8001BD18
uint32_t gap_06_8001BD18_bss[] = {
    // Unrecognized: .skip 0x8E8
};

// Data section: Ecb_8001C600
// Address: 0x8001C600
uint32_t Ecb_8001C600[] = {
    // Unrecognized: .skip 0xC0
};

// Data section: Packet_8001C6C0
// Address: 0x8001C6C0
uint32_t Packet_8001C6C0[] = {
    // Unrecognized: .skip 0x80
};

// Data section: lbl_8001C740
// Address: 0x8001C740
uint32_t lbl_8001C740[] = {
    // Unrecognized: .skip 0xA0
};

// Data section: TypeTime_8001C7E0
// Address: 0x8001C7E0
uint32_t TypeTime_8001C7E0[] = {
    // Unrecognized: .skip 0x20
};

// Data section: lbl_8001C800
// Address: 0x8001C800
uint32_t lbl_8001C800[] = {
    // Unrecognized: .skip 0xC0
};

// Data section: lbl_8001C8C0
// Address: 0x8001C8C0
uint32_t lbl_8001C8C0[] = {
    // Unrecognized: .skip 0x68
};

// Data section: lbl_8001C928
// Address: 0x8001C928
uint32_t lbl_8001C928[] = {
    // Unrecognized: .skip 0x78
};

// Data section: lbl_8001C9A0
// Address: 0x8001C9A0
uint32_t lbl_8001C9A0[] = {
    // Unrecognized: .skip 0x80
};

// Data section: lbl_8001CA20
// Address: 0x8001CA20
uint32_t lbl_8001CA20[] = {
    // Unrecognized: .skip 0x58
};

// Data section: lbl_8001CA78
// Address: 0x8001CA78
uint32_t lbl_8001CA78[] = {
    // Unrecognized: .skip 0x20
};

// Data section: lbl_8001CA98
// Address: 0x8001CA98
uint32_t lbl_8001CA98[] = {
    // Unrecognized: .skip 0x40
};

// Data section: lbl_8001CAD8
// Address: 0x8001CAD8
uint32_t lbl_8001CAD8[] = {
    // Unrecognized: .skip 0x30
};

// Data section: lbl_8001CB08
// Address: 0x8001CB08
uint32_t lbl_8001CB08[] = {
    // Unrecognized: .skip 0x78
};

// Data section: lbl_8001CB80
// Address: 0x8001CB80
uint32_t lbl_8001CB80[] = {
    // Unrecognized: .skip 0xD0
};

// Data section: atexit_funcs_8001CC50
// Address: 0x8001CC50
uint32_t atexit_funcs_8001CC50[] = {
    // Unrecognized: .skip 0x100
};

// Data section: __atexit_funcs_8001CD50
// Address: 0x8001CD50
uint32_t __atexit_funcs_8001CD50[] = {
    // Unrecognized: .skip 0x100
};

// Data section: lbl_8001CE50
// Address: 0x8001CE50
uint32_t lbl_8001CE50[] = {
    // Unrecognized: .skip 0x28
};

// Data section: lbl_8001CE78
// Address: 0x8001CE78
uint32_t lbl_8001CE78[] = {
    // Unrecognized: .skip 0x8
};

// Data section: lbl_8001CE80
// Address: 0x8001CE80
uint32_t lbl_8001CE80[] = {
    // Unrecognized: .skip 0x19B0
};

// Data section: lbl_8001E830
// Address: 0x8001E830
uint32_t lbl_8001E830[] = {
    // Unrecognized: .skip 0x14
};

// Data section: gTRKInputPendingPtr
// Address: 0x8001E844
uint32_t gTRKInputPendingPtr[] = {
    // Unrecognized: .skip 0x4
};

// Data section: lbl_8001E848
// Address: 0x8001E848
uint32_t lbl_8001E848[] = {
    // Unrecognized: .skip 0x8
};

// Data section: TRK_saved_exceptionID_8001E850
// Address: 0x8001E850
uint32_t TRK_saved_exceptionID_8001E850[] = {
    // Unrecognized: .skip 0x2
};

// Data section: gap_06_8001E852_bss
// Address: 0x8001E852
uint32_t gap_06_8001E852_bss[] = {
    // Unrecognized: .skip 0x2
};

// Data section: gTRKSaveState
// Address: 0x8001E854
uint32_t gTRKSaveState[] = {
    // Unrecognized: .skip 0x94
};

// Data section: lbl_8001E8E8
// Address: 0x8001E8E8
uint32_t lbl_8001E8E8[] = {
    // Unrecognized: .skip 0x10
};

// Data section: gTRKState
// Address: 0x8001E8F8
uint32_t gTRKState[] = {
    // Unrecognized: .skip 0xA4
};

// Data section: gap_06_8001E99C_bss
// Address: 0x8001E99C
uint32_t gap_06_8001E99C_bss[] = {
    // Unrecognized: .skip 0x4
};

// Data section: gTRKCPUState
// Address: 0x8001E9A0
uint32_t gTRKCPUState[] = {
    // Unrecognized: .skip 0x430
};

// Data section: lbl_8001EDD0
// Address: 0x8001EDD0
uint32_t lbl_8001EDD0[] = {
    // Unrecognized: .skip 0x8
};

// Data section: TRK_mainError_8001EDD8
// Address: 0x8001EDD8
uint32_t TRK_mainError_8001EDD8[] = {
    // Unrecognized: .skip 0x4
};

// Data section: gap_06_8001EDDC_bss
// Address: 0x8001EDDC
uint32_t gap_06_8001EDDC_bss[] = {
    // Unrecognized: .skip 0x4
};

// Data section: lbl_8001EDE0
// Address: 0x8001EDE0
uint32_t lbl_8001EDE0[] = {
    // Unrecognized: .skip 0x18
};
