.include "macros.inc"
.file "auto_08_8001EE60_sbss"

# 0x8001EE60..0x8001F085 | size: 0x225
.section .sbss, "wa", @nobits
.balign 8

# .sbss:0x0 | 0x8001EE60 | size: 0x4
.obj lbl_8001EE60, global
	.skip 0x4
.endobj lbl_8001EE60

# .sbss:0x4 | 0x8001EE64 | size: 0x4
.obj lbl_8001EE64, global
	.skip 0x4
.endobj lbl_8001EE64

# .sbss:0x8 | 0x8001EE68 | size: 0x4
.obj BootInfo_8001EE68, global
	.skip 0x4
.endobj BootInfo_8001EE68

# .sbss:0xC | 0x8001EE6C | size: 0x4
.obj BI2DebugFlag_8001EE6C, global
	.skip 0x4
.endobj BI2DebugFlag_8001EE6C

# .sbss:0x10 | 0x8001EE70 | size: 0x4
.obj BI2DebugFlagHolder_8001EE70, global
	.skip 0x4
.endobj BI2DebugFlagHolder_8001EE70

# .sbss:0x14 | 0x8001EE74 | size: 0x4
.obj AreWeInitialized_8001EE74, global
	.skip 0x4
.endobj AreWeInitialized_8001EE74

# .sbss:0x18 | 0x8001EE78 | size: 0x4
.obj OSExceptionTable_8001EE78, global
	.skip 0x4
.endobj OSExceptionTable_8001EE78

# .sbss:0x1C | 0x8001EE7C | size: 0x4
.obj __OSInIPL, global
	.skip 0x4
.endobj __OSInIPL

# .sbss:0x20 | 0x8001EE80 | size: 0x8
.obj __OSStartTime, global
	.skip 0x8
.endobj __OSStartTime

# .sbss:0x28 | 0x8001EE88 | size: 0x8
.obj AlarmQueue_8001EE88, global
	.skip 0x8
.endobj AlarmQueue_8001EE88

# .sbss:0x30 | 0x8001EE90 | size: 0x4
.obj __OSArenaHi_8001EE90, global
	.skip 0x4
.endobj __OSArenaHi_8001EE90

# .sbss:0x34 | 0x8001EE94 | size: 0x4
.obj gap_08_8001EE94_sbss, global
.hidden gap_08_8001EE94_sbss
	.skip 0x4
.endobj gap_08_8001EE94_sbss

# .sbss:0x38 | 0x8001EE98 | size: 0x4
.obj InterruptHandlerTable_8001EE98, global
	.skip 0x4
.endobj InterruptHandlerTable_8001EE98

# .sbss:0x3C | 0x8001EE9C | size: 0x4
.obj __OSLastInterruptSrr0, global
	.skip 0x4
.endobj __OSLastInterruptSrr0

# .sbss:0x40 | 0x8001EEA0 | size: 0x2
.obj __OSLastInterrupt, global
	.skip 0x2
.endobj __OSLastInterrupt

# .sbss:0x42 | 0x8001EEA2 | size: 0x6
.obj gap_08_8001EEA2_sbss, global
.hidden gap_08_8001EEA2_sbss
	.skip 0x6
.endobj gap_08_8001EEA2_sbss

# .sbss:0x48 | 0x8001EEA8 | size: 0x8
.obj __OSLastInterruptTime, global
	.skip 0x8
.endobj __OSLastInterruptTime

# .sbss:0x50 | 0x8001EEB0 | size: 0x4
.obj lbl_8001EEB0, global
	.skip 0x4
.endobj lbl_8001EEB0

# .sbss:0x54 | 0x8001EEB4 | size: 0x4
.obj lbl_8001EEB4, global
	.skip 0x4
.endobj lbl_8001EEB4

# .sbss:0x58 | 0x8001EEB8 | size: 0x8
.obj lbl_8001EEB8, global
	.skip 0x8
.endobj lbl_8001EEB8

# .sbss:0x60 | 0x8001EEC0 | size: 0x8
.obj ResetFunctionQueue_8001EEC0, global
	.skip 0x8
.endobj ResetFunctionQueue_8001EEC0

# .sbss:0x68 | 0x8001EEC8 | size: 0x4
.obj lbl_8001EEC8, global
	.skip 0x4
.endobj lbl_8001EEC8

# .sbss:0x6C | 0x8001EECC | size: 0x4
.obj lbl_8001EECC, global
	.skip 0x4
.endobj lbl_8001EECC

# .sbss:0x70 | 0x8001EED0 | size: 0x8
.obj lbl_8001EED0, global
	.skip 0x8
.endobj lbl_8001EED0

# .sbss:0x78 | 0x8001EED8 | size: 0x4
.obj lbl_8001EED8, global
	.skip 0x4
.endobj lbl_8001EED8

# .sbss:0x7C | 0x8001EEDC | size: 0x4
.obj lbl_8001EEDC, global
	.skip 0x4
.endobj lbl_8001EEDC

# .sbss:0x80 | 0x8001EEE0 | size: 0x4
.obj RunQueueBits_8001EEE0, global
	.skip 0x4
.endobj RunQueueBits_8001EEE0

# .sbss:0x84 | 0x8001EEE4 | size: 0x4
.obj RunQueueHint_8001EEE4, global
	.skip 0x4
.endobj RunQueueHint_8001EEE4

# .sbss:0x88 | 0x8001EEE8 | size: 0x4
.obj Reschedule_8001EEE8, global
	.skip 0x4
.endobj Reschedule_8001EEE8

# .sbss:0x8C | 0x8001EEEC | size: 0x4
.obj gap_08_8001EEEC_sbss, global
.hidden gap_08_8001EEEC_sbss
	.skip 0x4
.endobj gap_08_8001EEEC_sbss

# .sbss:0x90 | 0x8001EEF0 | size: 0x4
.obj lbl_8001EEF0, global
	.skip 0x4
.endobj lbl_8001EEF0

# .sbss:0x94 | 0x8001EEF4 | size: 0x4
.obj lbl_8001EEF4, global
	.skip 0x4
.endobj lbl_8001EEF4

# .sbss:0x98 | 0x8001EEF8 | size: 0x4
.obj lbl_8001EEF8, global
	.skip 0x4
.endobj lbl_8001EEF8

# .sbss:0x9C | 0x8001EEFC | size: 0x4
.obj lbl_8001EEFC, global
	.skip 0x4
.endobj lbl_8001EEFC

# .sbss:0xA0 | 0x8001EF00 | size: 0x4
.obj lbl_8001EF00, global
	.skip 0x4
.endobj lbl_8001EF00

# .sbss:0xA4 | 0x8001EF04 | size: 0x4
.obj cmdTypeAndStatus$371_8001EF04, global
	.skip 0x4
.endobj cmdTypeAndStatus$371_8001EF04

# .sbss:0xA8 | 0x8001EF08 | size: 0x8
.obj lbl_8001EF08, global
	.skip 0x8
.endobj lbl_8001EF08

# .sbss:0xB0 | 0x8001EF10 | size: 0x4
.obj SamplingRate_8001EF10, global
	.skip 0x4
.endobj SamplingRate_8001EF10

# .sbss:0xB4 | 0x8001EF14 | size: 0x4
.obj gap_08_8001EF14_sbss, global
.hidden gap_08_8001EF14_sbss
	.skip 0x4
.endobj gap_08_8001EF14_sbss

# .sbss:0xB8 | 0x8001EF18 | size: 0x4
.obj __DBInterface, global
	.skip 0x4
.endobj __DBInterface

# .sbss:0xBC | 0x8001EF1C | size: 0x4
.obj DBVerbose, global
	.skip 0x4
.endobj DBVerbose

# .sbss:0xC0 | 0x8001EF20 | size: 0x4
.obj lbl_8001EF20, global
	.skip 0x4
.endobj lbl_8001EF20

# .sbss:0xC4 | 0x8001EF24 | size: 0x4
.obj lbl_8001EF24, global
	.skip 0x4
.endobj lbl_8001EF24

# .sbss:0xC8 | 0x8001EF28 | size: 0x4
.obj lbl_8001EF28, global
	.skip 0x4
.endobj lbl_8001EF28

# .sbss:0xCC | 0x8001EF2C | size: 0x4
.obj lbl_8001EF2C, global
	.skip 0x4
.endobj lbl_8001EF2C

# .sbss:0xD0 | 0x8001EF30 | size: 0x4
.obj lbl_8001EF30, global
	.skip 0x4
.endobj lbl_8001EF30

# .sbss:0xD4 | 0x8001EF34 | size: 0x4
.obj lbl_8001EF34, global
	.skip 0x4
.endobj lbl_8001EF34

# .sbss:0xD8 | 0x8001EF38 | size: 0x4
.obj lbl_8001EF38, global
	.skip 0x4
.endobj lbl_8001EF38

# .sbss:0xDC | 0x8001EF3C | size: 0x4
.obj lbl_8001EF3C, global
	.skip 0x4
.endobj lbl_8001EF3C

# .sbss:0xE0 | 0x8001EF40 | size: 0x4
.obj lbl_8001EF40, global
	.skip 0x4
.endobj lbl_8001EF40

# .sbss:0xE4 | 0x8001EF44 | size: 0x4
.obj lbl_8001EF44, global
	.skip 0x4
.endobj lbl_8001EF44

# .sbss:0xE8 | 0x8001EF48 | size: 0x8
.obj lbl_8001EF48, global
	.skip 0x8
.endobj lbl_8001EF48

# .sbss:0xF0 | 0x8001EF50 | size: 0x4
.obj lbl_8001EF50, global
	.skip 0x4
.endobj lbl_8001EF50

# .sbss:0xF4 | 0x8001EF54 | size: 0x4
.obj lbl_8001EF54, global
	.skip 0x4
.endobj lbl_8001EF54

# .sbss:0xF8 | 0x8001EF58 | size: 0x4
.obj lbl_8001EF58, global
	.skip 0x4
.endobj lbl_8001EF58

# .sbss:0xFC | 0x8001EF5C | size: 0x4
.obj lbl_8001EF5C, global
	.skip 0x4
.endobj lbl_8001EF5C

# .sbss:0x100 | 0x8001EF60 | size: 0x4
.obj lbl_8001EF60, global
	.skip 0x4
.endobj lbl_8001EF60

# .sbss:0x104 | 0x8001EF64 | size: 0x4
.obj lbl_8001EF64, global
	.skip 0x4
.endobj lbl_8001EF64

# .sbss:0x108 | 0x8001EF68 | size: 0x4
.obj lbl_8001EF68, global
	.skip 0x4
.endobj lbl_8001EF68

# .sbss:0x10C | 0x8001EF6C | size: 0x4
.obj lbl_8001EF6C, global
	.skip 0x4
.endobj lbl_8001EF6C

# .sbss:0x110 | 0x8001EF70 | size: 0x4
.obj lbl_8001EF70, global
	.skip 0x4
.endobj lbl_8001EF70

# .sbss:0x114 | 0x8001EF74 | size: 0x4
.obj lbl_8001EF74, global
	.skip 0x4
.endobj lbl_8001EF74

# .sbss:0x118 | 0x8001EF78 | size: 0x4
.obj __DVDLongFileNameFlag, global
	.skip 0x4
.endobj __DVDLongFileNameFlag

# .sbss:0x11C | 0x8001EF7C | size: 0xC
.obj lbl_8001EF7C, global
	.skip 0xC
.endobj lbl_8001EF7C

# .sbss:0x128 | 0x8001EF88 | size: 0x4
.obj lbl_8001EF88, global
	.skip 0x4
.endobj lbl_8001EF88

# .sbss:0x12C | 0x8001EF8C | size: 0x4
.obj lbl_8001EF8C, global
	.skip 0x4
.endobj lbl_8001EF8C

# .sbss:0x130 | 0x8001EF90 | size: 0x4
.obj lbl_8001EF90, global
	.skip 0x4
.endobj lbl_8001EF90

# .sbss:0x134 | 0x8001EF94 | size: 0x4
.obj lbl_8001EF94, global
	.skip 0x4
.endobj lbl_8001EF94

# .sbss:0x138 | 0x8001EF98 | size: 0x4
.obj lbl_8001EF98, global
	.skip 0x4
.endobj lbl_8001EF98

# .sbss:0x13C | 0x8001EF9C | size: 0x4
.obj lbl_8001EF9C, global
	.skip 0x4
.endobj lbl_8001EF9C

# .sbss:0x140 | 0x8001EFA0 | size: 0x4
.obj lbl_8001EFA0, global
	.skip 0x4
.endobj lbl_8001EFA0

# .sbss:0x144 | 0x8001EFA4 | size: 0x4
.obj lbl_8001EFA4, global
	.skip 0x4
.endobj lbl_8001EFA4

# .sbss:0x148 | 0x8001EFA8 | size: 0x4
.obj lbl_8001EFA8, global
	.skip 0x4
.endobj lbl_8001EFA8

# .sbss:0x14C | 0x8001EFAC | size: 0x4
.obj lbl_8001EFAC, global
	.skip 0x4
.endobj lbl_8001EFAC

# .sbss:0x150 | 0x8001EFB0 | size: 0x4
.obj lbl_8001EFB0, global
	.skip 0x4
.endobj lbl_8001EFB0

# .sbss:0x154 | 0x8001EFB4 | size: 0x4
.obj lbl_8001EFB4, global
	.skip 0x4
.endobj lbl_8001EFB4

# .sbss:0x158 | 0x8001EFB8 | size: 0x4
.obj lbl_8001EFB8, global
	.skip 0x4
.endobj lbl_8001EFB8

# .sbss:0x15C | 0x8001EFBC | size: 0x4
.obj lbl_8001EFBC, global
	.skip 0x4
.endobj lbl_8001EFBC

# .sbss:0x160 | 0x8001EFC0 | size: 0x4
.obj lbl_8001EFC0, global
	.skip 0x4
.endobj lbl_8001EFC0

# .sbss:0x164 | 0x8001EFC4 | size: 0x4
.obj lbl_8001EFC4, global
	.skip 0x4
.endobj lbl_8001EFC4

# .sbss:0x168 | 0x8001EFC8 | size: 0x4
.obj lbl_8001EFC8, global
	.skip 0x4
.endobj lbl_8001EFC8

# .sbss:0x16C | 0x8001EFCC | size: 0x4
.obj lbl_8001EFCC, global
	.skip 0x4
.endobj lbl_8001EFCC

# .sbss:0x170 | 0x8001EFD0 | size: 0x4
.obj lbl_8001EFD0, global
	.skip 0x4
.endobj lbl_8001EFD0

# .sbss:0x174 | 0x8001EFD4 | size: 0x4
.obj lbl_8001EFD4, global
	.skip 0x4
.endobj lbl_8001EFD4

# .sbss:0x178 | 0x8001EFD8 | size: 0x8
.obj lbl_8001EFD8, global
	.skip 0x8
.endobj lbl_8001EFD8

# .sbss:0x180 | 0x8001EFE0 | size: 0x4
.obj lbl_8001EFE0, global
	.skip 0x4
.endobj lbl_8001EFE0

# .sbss:0x184 | 0x8001EFE4 | size: 0x4
.obj lbl_8001EFE4, global
	.skip 0x4
.endobj lbl_8001EFE4

# .sbss:0x188 | 0x8001EFE8 | size: 0x8
.obj lbl_8001EFE8, global
	.skip 0x8
.endobj lbl_8001EFE8

# .sbss:0x190 | 0x8001EFF0 | size: 0x4
.obj lbl_8001EFF0, global
	.skip 0x4
.endobj lbl_8001EFF0

# .sbss:0x194 | 0x8001EFF4 | size: 0x4
.obj lbl_8001EFF4, global
	.skip 0x4
.endobj lbl_8001EFF4

# .sbss:0x198 | 0x8001EFF8 | size: 0x4
.obj lbl_8001EFF8, global
	.skip 0x4
.endobj lbl_8001EFF8

# .sbss:0x19C | 0x8001EFFC | size: 0x2
.obj lbl_8001EFFC, global
	.skip 0x2
.endobj lbl_8001EFFC

# .sbss:0x19E | 0x8001EFFE | size: 0x2
.obj lbl_8001EFFE, global
	.skip 0x2
.endobj lbl_8001EFFE

# .sbss:0x1A0 | 0x8001F000 | size: 0x8
.obj lbl_8001F000, global
	.skip 0x8
.endobj lbl_8001F000

# .sbss:0x1A8 | 0x8001F008 | size: 0x4
.obj lbl_8001F008, global
	.skip 0x4
.endobj lbl_8001F008

# .sbss:0x1AC | 0x8001F00C | size: 0x4
.obj lbl_8001F00C, global
	.skip 0x4
.endobj lbl_8001F00C

# .sbss:0x1B0 | 0x8001F010 | size: 0x8
.obj lbl_8001F010, global
	.skip 0x8
.endobj lbl_8001F010

# .sbss:0x1B8 | 0x8001F018 | size: 0x4
.obj lbl_8001F018, global
	.skip 0x4
.endobj lbl_8001F018

# .sbss:0x1BC | 0x8001F01C | size: 0x4
.obj lbl_8001F01C, global
	.skip 0x4
.endobj lbl_8001F01C

# .sbss:0x1C0 | 0x8001F020 | size: 0x4
.obj lbl_8001F020, global
	.skip 0x4
.endobj lbl_8001F020

# .sbss:0x1C4 | 0x8001F024 | size: 0x4
.obj CurrTvMode_8001F024, global
	.skip 0x4
.endobj CurrTvMode_8001F024

# .sbss:0x1C8 | 0x8001F028 | size: 0x4
.obj lbl_8001F028, global
	.skip 0x4
.endobj lbl_8001F028

# .sbss:0x1CC | 0x8001F02C | size: 0x4
.obj lbl_8001F02C, global
	.skip 0x4
.endobj lbl_8001F02C

# .sbss:0x1D0 | 0x8001F030 | size: 0x4
.obj __PADSpec, global
	.skip 0x4
.endobj __PADSpec

# .sbss:0x1D4 | 0x8001F034 | size: 0x4
.obj gap_08_8001F034_sbss, global
.hidden gap_08_8001F034_sbss
	.skip 0x4
.endobj gap_08_8001F034_sbss

# .sbss:0x1D8 | 0x8001F038 | size: 0x4
.obj __global_destructor_chain, global
	.skip 0x4
.endobj __global_destructor_chain

# .sbss:0x1DC | 0x8001F03C | size: 0x4
.obj gap_08_8001F03C_sbss, global
.hidden gap_08_8001F03C_sbss
	.skip 0x4
.endobj gap_08_8001F03C_sbss

# .sbss:0x1E0 | 0x8001F040 | size: 0x4
.obj __aborting, global
	.skip 0x4
.endobj __aborting

# .sbss:0x1E4 | 0x8001F044 | size: 0x4
.obj atexit_curr_func_8001F044, global
	.skip 0x4
.endobj atexit_curr_func_8001F044

# .sbss:0x1E8 | 0x8001F048 | size: 0x4
.obj __atexit_curr_func_8001F048, global
	.skip 0x4
.endobj __atexit_curr_func_8001F048

# .sbss:0x1EC | 0x8001F04C | size: 0x4
.obj __stdio_exit, global
	.skip 0x4
.endobj __stdio_exit

# .sbss:0x1F0 | 0x8001F050 | size: 0x4
.obj __console_exit, global
	.skip 0x4
.endobj __console_exit

# .sbss:0x1F4 | 0x8001F054 | size: 0x4
.obj gap_08_8001F054_sbss, global
.hidden gap_08_8001F054_sbss
	.skip 0x4
.endobj gap_08_8001F054_sbss

# .sbss:0x1F8 | 0x8001F058 | size: 0x8
.obj lbl_8001F058, global
	.skip 0x8
.endobj lbl_8001F058

# .sbss:0x200 | 0x8001F060 | size: 0x4
.obj lbl_8001F060, global
	.skip 0x4
.endobj lbl_8001F060

# .sbss:0x204 | 0x8001F064 | size: 0x4
.obj lbl_8001F064, global
	.skip 0x4
.endobj lbl_8001F064

# .sbss:0x208 | 0x8001F068 | size: 0x8
.obj lbl_8001F068, global
	.skip 0x8
.endobj lbl_8001F068

# .sbss:0x210 | 0x8001F070 | size: 0x4
.obj lbl_8001F070, global
	.skip 0x4
.endobj lbl_8001F070

# .sbss:0x214 | 0x8001F074 | size: 0x4
.obj lbl_8001F074, global
	.skip 0x4
.endobj lbl_8001F074

# .sbss:0x218 | 0x8001F078 | size: 0x4
.obj lbl_8001F078, global
	.skip 0x4
.endobj lbl_8001F078

# .sbss:0x21C | 0x8001F07C | size: 0x4
.obj lbl_8001F07C, global
	.skip 0x4
.endobj lbl_8001F07C

# .sbss:0x220 | 0x8001F080 | size: 0x4
.obj lbl_8001F080, global
	.skip 0x4
.endobj lbl_8001F080

# .sbss:0x224 | 0x8001F084 | size: 0x1
.obj lbl_8001F084, global
	.skip 0x1
.endobj lbl_8001F084
