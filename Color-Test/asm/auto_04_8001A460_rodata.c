#include "all_headers.h"
#include "auto_04_8001A460_rodata.h"
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

// Data section: lbl_8001A460
// Address: 0x8001A460
uint32_t lbl_8001A460[] = {
    0x00000000, // .double 0 (hi)
    0x00000000, // .double 0 (lo)
    0x41F00000, // .double 4294967296 (hi)
    0x00000000, // .double 4294967296 (lo)
    0x41E00000, // .double 2147483648 (hi)
    0x00000000, // .double 2147483648 (lo)
};

// Data section: lbl_8001A478
// Address: 0x8001A478
uint32_t lbl_8001A478[] = {
    0x40240000, // .double 10 (hi)
    0x00000000, // .double 10 (lo)
    0x40590000, // .double 100 (hi)
    0x00000000, // .double 100 (lo)
    0x40C38800, // .double 10000 (hi)
    0x00000000, // .double 10000 (lo)
    0x4197D784, // .double 100000000 (hi)
    0x00000000, // .double 100000000 (lo)
    0x4341C379, // .double 10000000000000000 (hi)
    0x37E08000, // .double 10000000000000000 (lo)
    0x4693B8B5, // .double 100000000000000000000000000000000 (hi)
    0xB5056E17, // .double 100000000000000000000000000000000 (lo)
    0x4D384F03, // .double 10000000000000000000000000000000000000000000000000000000000000000 (hi)
    0xE93FF9F5, // .double 10000000000000000000000000000000000000000000000000000000000000000 (lo)
    0x5A827748, // .double 100000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000 (hi)
    0xF9301D32, // .double 100000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000 (lo)
    0x75154FDD, // .double 10000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000 (hi)
    0x7F73BF3C, // .double 10000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000 (lo)
};

// Data section: lbl_8001A4C0
// Address: 0x8001A4C0
uint32_t lbl_8001A4C0[] = {
    0x40240000, // .4byte 0x40240000
    0x00000000, // .4byte 0x00000000
    0x40590000, // .4byte 0x40590000
    0x00000000, // .4byte 0x00000000
    0x408F4000, // .4byte 0x408F4000
    0x00000000, // .4byte 0x00000000
    0x40C38800, // .4byte 0x40C38800
    0x00000000, // .4byte 0x00000000
    0x40F86A00, // .4byte 0x40F86A00
    0x00000000, // .4byte 0x00000000
    0x412E8480, // .4byte 0x412E8480
    0x00000000, // .4byte 0x00000000
    0x416312D0, // .4byte 0x416312D0
    0x00000000, // .4byte 0x00000000
    0x4197D784, // .4byte 0x4197D784
    0x00000000, // .4byte 0x00000000
};

// Data section: lbl_8001A500
// Address: 0x8001A500
uint32_t lbl_8001A500[] = {
    0x01010101, // .4byte 0x01010101
    0x01010101, // .4byte 0x01010101
    0x01020202, // .4byte 0x01020202
    0x02020101, // .4byte 0x02020101
    0x01010101, // .4byte 0x01010101
    0x01010101, // .4byte 0x01010101
    0x01010101, // .4byte 0x01010101
    0x01010101, // .4byte 0x01010101
    0x04080808, // .4byte 0x04080808
    0x08080808, // .4byte 0x08080808
    0x08080808, // .4byte 0x08080808
    0x08080808, // .4byte 0x08080808
    0x30303030, // .4byte 0x30303030
    0x30303030, // .4byte 0x30303030
    0x30300808, // .4byte 0x30300808
    0x08080808, // .4byte 0x08080808
    0x08A0A0A0, // .4byte 0x08A0A0A0
    0xA0A0A080, // .4byte 0xA0A0A080
    0x80808080, // .4byte 0x80808080
    0x80808080, // .4byte 0x80808080
    0x80808080, // .4byte 0x80808080
    0x80808080, // .4byte 0x80808080
    0x80808008, // .4byte 0x80808008
    0x08080808, // .4byte 0x08080808
    0x08606060, // .4byte 0x08606060
    0x60606040, // .4byte 0x60606040
    0x40404040, // .4byte 0x40404040
    0x40404040, // .4byte 0x40404040
    0x40404040, // .4byte 0x40404040
    0x40404040, // .4byte 0x40404040
    0x40404008, // .4byte 0x40404008
    0x08080801, // .4byte 0x08080801
    0x00000000, // .4byte 0x00000000
    0x00000000, // .4byte 0x00000000
    0x00000000, // .4byte 0x00000000
    0x00000000, // .4byte 0x00000000
    0x00000000, // .4byte 0x00000000
    0x00000000, // .4byte 0x00000000
    0x00000000, // .4byte 0x00000000
    0x00000000, // .4byte 0x00000000
    0x00000000, // .4byte 0x00000000
    0x00000000, // .4byte 0x00000000
    0x00000000, // .4byte 0x00000000
    0x00000000, // .4byte 0x00000000
    0x00000000, // .4byte 0x00000000
    0x00000000, // .4byte 0x00000000
    0x00000000, // .4byte 0x00000000
    0x00000000, // .4byte 0x00000000
    0x00000000, // .4byte 0x00000000
    0x00000000, // .4byte 0x00000000
    0x00000000, // .4byte 0x00000000
    0x00000000, // .4byte 0x00000000
    0x00000000, // .4byte 0x00000000
    0x00000000, // .4byte 0x00000000
    0x00000000, // .4byte 0x00000000
    0x00000000, // .4byte 0x00000000
    0x00000000, // .4byte 0x00000000
    0x00000000, // .4byte 0x00000000
    0x00000000, // .4byte 0x00000000
    0x00000000, // .4byte 0x00000000
    0x00000000, // .4byte 0x00000000
    0x00000000, // .4byte 0x00000000
    0x00000000, // .4byte 0x00000000
    0x00000000, // .4byte 0x00000000
};

// Data section: _stringBase0_8001A600
// Address: 0x8001A600
uint32_t _stringBase0_8001A600[] = {
    // Unrecognized: .string ""
    // Unrecognized: .string "-Inf"
    // Unrecognized: .string "Inf"
    // Unrecognized: .string "NaN"
};

// Data section: gap_04_8001A60E_rodata
// Address: 0x8001A60E
uint32_t gap_04_8001A60E_rodata[] = {
    // Unrecognized: .2byte 0x0000
};

// Data section: _40_8001A610
// Address: 0x8001A610
uint32_t _40_8001A610[] = {
    // Unrecognized: .string "MetroTRK for Dolphin v0.8"
};

// Data section: gap_04_8001A62A_rodata
// Address: 0x8001A62A
uint32_t gap_04_8001A62A_rodata[] = {
    0x00000000, // .4byte 0x00000000
    // Unrecognized: .2byte 0x0000
};

// Data section: lbl_8001A630
// Address: 0x8001A630
uint32_t lbl_8001A630[] = {
    0x00000000, // .4byte 0x00000000
    0xFFFFFFFF, // .4byte 0xFFFFFFFF
    0x00000001, // .4byte 0x00000001
    0x00000001, // .4byte 0x00000001
};

// Data section: lbl_8001A640
// Address: 0x8001A640
uint32_t lbl_8001A640[] = {
    0x60000000, // .4byte 0x60000000
    0x60000000, // .4byte 0x60000000
    0x60000000, // .4byte 0x60000000
    0x60000000, // .4byte 0x60000000
    0x60000000, // .4byte 0x60000000
};

// Data section: lbl_8001A654
// Address: 0x8001A654
uint32_t lbl_8001A654[] = {
    0x60000000, // .4byte 0x60000000
    0x60000000, // .4byte 0x60000000
    0x60000000, // .4byte 0x60000000
    0x60000000, // .4byte 0x60000000
    0x60000000, // .4byte 0x60000000
};

// Data section: lbl_8001A668
// Address: 0x8001A668
uint32_t lbl_8001A668[] = {
    0x60000000, // .4byte 0x60000000
    0x60000000, // .4byte 0x60000000
    0x60000000, // .4byte 0x60000000
    0x60000000, // .4byte 0x60000000
    0x60000000, // .4byte 0x60000000
};
