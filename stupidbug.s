.include "macros.inc"
.file "auto_00_80003100_init"

# 0x80003100..0x80005470 | size: 0x2370
.section .init, "ax"
.balign 4

# .init:0x0 | 0x80003100 | size: 0x40
.fn __check_pad3, local
/* 80003114 00000114  70 00 0E EF */	andi. r0, r0, 0xeef
.endfn __check_pad3
