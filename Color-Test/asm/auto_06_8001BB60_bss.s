.include "macros.inc"
.file "auto_06_8001BB60_bss"

# 0x8001BB60..0x8001EDF8 | size: 0x3298
.section .bss, "wa", @nobits
.balign 8

# .bss:0x0 | 0x8001BB60 | size: 0x40
.obj __OSErrorTable, global
	.skip 0x40
.endobj __OSErrorTable

# .bss:0x40 | 0x8001BBA0 | size: 0x20
.obj lbl_8001BBA0, global
	.skip 0x20
.endobj lbl_8001BBA0

# .bss:0x60 | 0x8001BBC0 | size: 0x54
.obj Scb_8001BBC0, global
	.skip 0x54
.endobj Scb_8001BBC0

# .bss:0xB4 | 0x8001BC14 | size: 0x4
.obj gap_06_8001BC14_bss, global
.hidden gap_06_8001BC14_bss
	.skip 0x4
.endobj gap_06_8001BC14_bss

# .bss:0xB8 | 0x8001BC18 | size: 0x100
.obj RunQueue_8001BC18, global
	.skip 0x100
.endobj RunQueue_8001BC18

# .bss:0x1B8 | 0x8001BD18 | size: 0x8E8
.obj gap_06_8001BD18_bss, global
.hidden gap_06_8001BD18_bss
	.skip 0x8E8
.endobj gap_06_8001BD18_bss

# .bss:0xAA0 | 0x8001C600 | size: 0xC0
.obj Ecb_8001C600, global
	.skip 0xC0
.endobj Ecb_8001C600

# .bss:0xB60 | 0x8001C6C0 | size: 0x80
.obj Packet_8001C6C0, global
	.skip 0x80
.endobj Packet_8001C6C0

# .bss:0xBE0 | 0x8001C740 | size: 0xA0
.obj lbl_8001C740, global
	.skip 0xA0
.endobj lbl_8001C740

# .bss:0xC80 | 0x8001C7E0 | size: 0x20
.obj TypeTime_8001C7E0, global
	.skip 0x20
.endobj TypeTime_8001C7E0

# .bss:0xCA0 | 0x8001C800 | size: 0xC0
.obj lbl_8001C800, global
	.skip 0xC0
.endobj lbl_8001C800

# .bss:0xD60 | 0x8001C8C0 | size: 0x68
.obj lbl_8001C8C0, global
	.skip 0x68
.endobj lbl_8001C8C0

# .bss:0xDC8 | 0x8001C928 | size: 0x78
.obj lbl_8001C928, global
	.skip 0x78
.endobj lbl_8001C928

# .bss:0xE40 | 0x8001C9A0 | size: 0x80
.obj lbl_8001C9A0, global
	.skip 0x80
.endobj lbl_8001C9A0

# .bss:0xEC0 | 0x8001CA20 | size: 0x58
.obj lbl_8001CA20, global
	.skip 0x58
.endobj lbl_8001CA20

# .bss:0xF18 | 0x8001CA78 | size: 0x20
.obj lbl_8001CA78, global
	.skip 0x20
.endobj lbl_8001CA78

# .bss:0xF38 | 0x8001CA98 | size: 0x40
.obj lbl_8001CA98, global
	.skip 0x40
.endobj lbl_8001CA98

# .bss:0xF78 | 0x8001CAD8 | size: 0x30
.obj lbl_8001CAD8, global
	.skip 0x30
.endobj lbl_8001CAD8

# .bss:0xFA8 | 0x8001CB08 | size: 0x78
.obj lbl_8001CB08, global
	.skip 0x78
.endobj lbl_8001CB08

# .bss:0x1020 | 0x8001CB80 | size: 0xD0
.obj lbl_8001CB80, global
	.skip 0xD0
.endobj lbl_8001CB80

# .bss:0x10F0 | 0x8001CC50 | size: 0x100
.obj atexit_funcs_8001CC50, global
	.skip 0x100
.endobj atexit_funcs_8001CC50

# .bss:0x11F0 | 0x8001CD50 | size: 0x100
.obj __atexit_funcs_8001CD50, global
	.skip 0x100
.endobj __atexit_funcs_8001CD50

# .bss:0x12F0 | 0x8001CE50 | size: 0x28
.obj lbl_8001CE50, global
	.skip 0x28
.endobj lbl_8001CE50

# .bss:0x1318 | 0x8001CE78 | size: 0x8
.obj lbl_8001CE78, global
	.skip 0x8
.endobj lbl_8001CE78

# .bss:0x1320 | 0x8001CE80 | size: 0x19B0
.obj lbl_8001CE80, global
	.skip 0x19B0
.endobj lbl_8001CE80

# .bss:0x2CD0 | 0x8001E830 | size: 0x14
.obj lbl_8001E830, global
	.skip 0x14
.endobj lbl_8001E830

# .bss:0x2CE4 | 0x8001E844 | size: 0x4
.obj gTRKInputPendingPtr, global
	.skip 0x4
.endobj gTRKInputPendingPtr

# .bss:0x2CE8 | 0x8001E848 | size: 0x8
.obj lbl_8001E848, global
	.skip 0x8
.endobj lbl_8001E848

# .bss:0x2CF0 | 0x8001E850 | size: 0x2
.obj TRK_saved_exceptionID_8001E850, global
	.skip 0x2
.endobj TRK_saved_exceptionID_8001E850

# .bss:0x2CF2 | 0x8001E852 | size: 0x2
.obj gap_06_8001E852_bss, global
.hidden gap_06_8001E852_bss
	.skip 0x2
.endobj gap_06_8001E852_bss

# .bss:0x2CF4 | 0x8001E854 | size: 0x94
.obj gTRKSaveState, global
	.skip 0x94
.endobj gTRKSaveState

# .bss:0x2D88 | 0x8001E8E8 | size: 0x10
.obj lbl_8001E8E8, global
	.skip 0x10
.endobj lbl_8001E8E8

# .bss:0x2D98 | 0x8001E8F8 | size: 0xA4
.obj gTRKState, global
	.skip 0xA4
.endobj gTRKState

# .bss:0x2E3C | 0x8001E99C | size: 0x4
.obj gap_06_8001E99C_bss, global
.hidden gap_06_8001E99C_bss
	.skip 0x4
.endobj gap_06_8001E99C_bss

# .bss:0x2E40 | 0x8001E9A0 | size: 0x430
.obj gTRKCPUState, global
	.skip 0x430
.endobj gTRKCPUState

# .bss:0x3270 | 0x8001EDD0 | size: 0x8
.obj lbl_8001EDD0, global
	.skip 0x8
.endobj lbl_8001EDD0

# .bss:0x3278 | 0x8001EDD8 | size: 0x4
.obj TRK_mainError_8001EDD8, global
	.skip 0x4
.endobj TRK_mainError_8001EDD8

# .bss:0x327C | 0x8001EDDC | size: 0x4
.obj gap_06_8001EDDC_bss, global
.hidden gap_06_8001EDDC_bss
	.skip 0x4
.endobj gap_06_8001EDDC_bss

# .bss:0x3280 | 0x8001EDE0 | size: 0x18
.obj lbl_8001EDE0, global
	.skip 0x18
.endobj lbl_8001EDE0
