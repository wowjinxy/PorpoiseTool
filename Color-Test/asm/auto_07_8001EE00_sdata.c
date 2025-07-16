#include "all_headers.h"
#include "auto_07_8001EE00_sdata.h"
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

// Data section: lbl_8001EE00
// Address: 0x8001EE00
uint32_t lbl_8001EE00[] = {
    (uint32_t)&lbl_8001B6A0, // .4byte lbl_8001B6A0
    0x00000000, // .4byte 0x00000000
};

// Data section: __OSArenaLo_8001EE08
// Address: 0x8001EE08
uint32_t __OSArenaLo_8001EE08[] = {
    0xFFFFFFFF, // .4byte 0xFFFFFFFF
};

// Data section: gap_07_8001EE0C_sdata
// Address: 0x8001EE0C
uint32_t gap_07_8001EE0C_sdata[] = {
    0x00000000, // .4byte 0x00000000
};

// Data section: _32_8001EE10
// Address: 0x8001EE10
uint32_t _32_8001EE10[] = {
    0x0A000000, // .string "\n"
};

// Data section: gap_07_8001EE12_sdata
// Address: 0x8001EE12
uint32_t gap_07_8001EE12_sdata[] = {
    0x00000000, // .4byte 0x00000000
    0x00000000, // .2byte 0x0000
};

// Data section: lbl_8001EE18
// Address: 0x8001EE18
uint32_t lbl_8001EE18[] = {
    0x00000001, // .4byte 0x00000001
    0x00000000, // .4byte 0x00000000
};

// Data section: lbl_8001EE20
// Address: 0x8001EE20
uint32_t lbl_8001EE20[] = {
    0x00000001, // .4byte 0x00000001
    0x00000000, // .4byte 0x00000000
};

// Data section: lbl_8001EE28
// Address: 0x8001EE28
uint32_t lbl_8001EE28[] = {
    0x0A000000, // .4byte 0x0A000000
};

// Data section: lbl_8001EE2C
// Address: 0x8001EE2C
uint32_t lbl_8001EE2C[] = {
    0x4F464600, // .string "OFF"
};

// Data section: lbl_8001EE30
// Address: 0x8001EE30
uint32_t lbl_8001EE30[] = {
    0x4F4E0000, // .4byte 0x4F4E0000
    0x00000000, // .4byte 0x00000000
};

// Data section: _wstringBase0_8001EE38
// Address: 0x8001EE38
uint32_t _wstringBase0_8001EE38[] = {
    0x00000000, // .2byte 0x0000
};

// Data section: gap_07_8001EE3A_sdata
// Address: 0x8001EE3A
uint32_t gap_07_8001EE3A_sdata[] = {
    0x00000000, // .4byte 0x00000000
    0x00000000, // .2byte 0x0000
};

// Data section: lbl_8001EE40
// Address: 0x8001EE40
uint32_t lbl_8001EE40[] = {
    0x80808080, // .4byte 0x80808080
};

// Data section: lbl_8001EE44
// Address: 0x8001EE44
uint32_t lbl_8001EE44[] = {
    0xFEFEFEFF, // .4byte 0xFEFEFEFF
};

// Data section: lbl_8001EE48
// Address: 0x8001EE48
uint32_t lbl_8001EE48[] = {
    (uint32_t)&lbl_8001EDE0, // .4byte lbl_8001EDE0
    0x00000000, // .4byte 0x00000000
};

// Data section: lbl_8001EE50
// Address: 0x8001EE50
uint32_t lbl_8001EE50[] = {
    (uint32_t)&lbl_8001F060, // .4byte lbl_8001F060
    0x00000000, // .4byte 0x00000000
};

// Data section: lbl_8001EE58
// Address: 0x8001EE58
uint32_t lbl_8001EE58[] = {
    0x80000000, // .byte 0x80
};
