.include "macros.inc"
.file "auto_07_8001EE00_sdata"

# 0x8001EE00..0x8001EE59 | size: 0x59
.section .sdata, "wa"
.balign 8

# .sdata:0x0 | 0x8001EE00 | size: 0x8
.obj lbl_8001EE00, global
	.4byte lbl_8001B6A0
	.4byte 0x00000000
.endobj lbl_8001EE00

# .sdata:0x8 | 0x8001EE08 | size: 0x4
.obj __OSArenaLo_8001EE08, global
	.4byte 0xFFFFFFFF
.endobj __OSArenaLo_8001EE08

# .sdata:0xC | 0x8001EE0C | size: 0x4
.obj gap_07_8001EE0C_sdata, global
.hidden gap_07_8001EE0C_sdata
	.4byte 0x00000000
.endobj gap_07_8001EE0C_sdata

# .sdata:0x10 | 0x8001EE10 | size: 0x2
.obj "@32_8001EE10", global
	.string "\n"
.endobj "@32_8001EE10"

# .sdata:0x12 | 0x8001EE12 | size: 0x6
.obj gap_07_8001EE12_sdata, global
.hidden gap_07_8001EE12_sdata
	.4byte 0x00000000
	.2byte 0x0000
.endobj gap_07_8001EE12_sdata

# .sdata:0x18 | 0x8001EE18 | size: 0x8
.obj lbl_8001EE18, global
	.4byte 0x00000001
	.4byte 0x00000000
.endobj lbl_8001EE18

# .sdata:0x20 | 0x8001EE20 | size: 0x8
.obj lbl_8001EE20, global
	.4byte 0x00000001
	.4byte 0x00000000
.endobj lbl_8001EE20

# .sdata:0x28 | 0x8001EE28 | size: 0x4
.obj lbl_8001EE28, global
	.4byte 0x0A000000
.endobj lbl_8001EE28

# .sdata:0x2C | 0x8001EE2C | size: 0x4
.obj lbl_8001EE2C, global
	.string "OFF"
.endobj lbl_8001EE2C

# .sdata:0x30 | 0x8001EE30 | size: 0x8
.obj lbl_8001EE30, global
	.4byte 0x4F4E0000
	.4byte 0x00000000
.endobj lbl_8001EE30

# .sdata:0x38 | 0x8001EE38 | size: 0x2
.obj "@wstringBase0_8001EE38", global
	.2byte 0x0000
.endobj "@wstringBase0_8001EE38"

# .sdata:0x3A | 0x8001EE3A | size: 0x6
.obj gap_07_8001EE3A_sdata, global
.hidden gap_07_8001EE3A_sdata
	.4byte 0x00000000
	.2byte 0x0000
.endobj gap_07_8001EE3A_sdata

# .sdata:0x40 | 0x8001EE40 | size: 0x4
.obj lbl_8001EE40, global
	.4byte 0x80808080
.endobj lbl_8001EE40

# .sdata:0x44 | 0x8001EE44 | size: 0x4
.obj lbl_8001EE44, global
	.4byte 0xFEFEFEFF
.endobj lbl_8001EE44

# .sdata:0x48 | 0x8001EE48 | size: 0x8
.obj lbl_8001EE48, global
	.4byte lbl_8001EDE0
	.4byte 0x00000000
.endobj lbl_8001EE48

# .sdata:0x50 | 0x8001EE50 | size: 0x8
.obj lbl_8001EE50, global
	.4byte lbl_8001F060
	.4byte 0x00000000
.endobj lbl_8001EE50

# .sdata:0x58 | 0x8001EE58 | size: 0x1
.obj lbl_8001EE58, global
	.byte 0x80
.endobj lbl_8001EE58
