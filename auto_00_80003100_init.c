#include "auto_00_80003100_init.h"
#include <stdint.h>
#include <stdio.h>

#include "gc_env.h"

// Function: __check_pad3
void __check_pad3(void) {
    gc_env.r[0] = gc_env.lr; // Move from link register
    gc_env.r[3] = (0x8000) << 16;
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x4, gc_env.r[0]);
    gc_mem_write32(gc_env.ram, gc_env.r[1] + -0x8, gc_env.r[1]);
    gc_env.r[1] = gc_env.r[1] + -0x8;
    gc_env.r[0] = gc_mem_read16(gc_env.ram, gc_env.r[3] + 0x30e4);
    gc_env.r[0] = gc_env.r[0] & 0xeef;
    gc_env.cr[0] = (gc_env.r[0] == 0xeef) ? 0 : (gc_env.r[0] < 0xeef ? -1 : 1); // Compare with immediate
    if (gc_env.cr[0] != 0) goto L_80003130;
    gc_env.r[3] = 0x0;
    gc_env.r[4] = 0x0;
    gc_env.r[5] = 0x0;
    OSReset();
    L_80003130:
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0xc);
    gc_env.r[1] = gc_env.r[1] + 0x8;
    gc_env.lr = gc_env.r[0]; // Move to link register
    return;
}

// Function: __start
void __start(void) {
    OSReset();
    OSReset();
    gc_env.r[0] = -0x1;
    gc_mem_write32(gc_env.ram, gc_env.r[1] + -0x8, gc_env.r[1]);
    gc_env.r[1] = gc_env.r[1] + -0x8;
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x4, gc_env.r[0]);
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x0, gc_env.r[0]);
    OSReset();
    gc_env.r[0] = 0x0;
    gc_env.r[6] = (0x8000) << 16;
    gc_env.r[6] = gc_env.r[6] + 0x44;
    gc_mem_write32(gc_env.ram, gc_env.r[6] + 0x0, gc_env.r[0]);
    gc_env.r[6] = (0x8000) << 16;
    gc_env.r[6] = gc_env.r[6] + 0xf4;
    gc_env.r[6] = gc_mem_read32(gc_env.ram, gc_env.r[6] + 0x0);
    // Unknown opcode: cmplwi r6 0x0
    // Unknown opcode: beq .L_800031AC
    gc_env.r[7] = gc_mem_read32(gc_env.ram, gc_env.r[6] + 0xc);
    gc_env.r[5] = 0x0;
    // Unknown opcode: cmplwi r7 0x2
    // Unknown opcode: beq .L_8000319C
    // Unknown opcode: cmplwi r7 0x3
    if (gc_env.cr[0] != 0) goto L_800031AC;
    gc_env.r[5] = 0x1;
    L_8000319C:
    gc_env.r[6] = (InitMetroTRK@ha) << 16;
    gc_env.r[6] = gc_env.r[6] + InitMetroTRK@l;
    gc_env.lr = gc_env.r[6]; // Move to link register
    // Unknown opcode: blrl 
    L_800031AC:
    gc_env.r[6] = (0x8000) << 16;
    gc_env.r[6] = gc_env.r[6] + 0xf4;
    gc_env.r[5] = gc_mem_read32(gc_env.ram, gc_env.r[6] + 0x0);
    // Unknown opcode: cmplwi r5 0x0
    // Unknown opcode: beq + .L_8000320C
    gc_env.r[6] = gc_mem_read32(gc_env.ram, gc_env.r[5] + 0x8);
    // Unknown opcode: cmplwi r6 0x0
    // Unknown opcode: beq + .L_8000320C
    // Unknown opcode: add r6 r5 r6
    gc_env.r[14] = gc_mem_read32(gc_env.ram, gc_env.r[6] + 0x0);
    // Unknown opcode: cmplwi r14 0x0
    // Unknown opcode: beq .L_8000320C
    gc_env.r[15] = gc_env.r[6] + 0x4;
    // Unknown opcode: mtctr r14
    L_800031E4:
    gc_env.r[6] = gc_env.r[6] + 0x4;
    gc_env.r[7] = gc_mem_read32(gc_env.ram, gc_env.r[6] + 0x0);
    // Unknown opcode: add r7 r7 r5
    gc_mem_write32(gc_env.ram, gc_env.r[6] + 0x0, gc_env.r[7]);
    // Unknown opcode: bdnz .L_800031E4
    gc_env.r[5] = (0x8000) << 16;
    gc_env.r[5] = gc_env.r[5] + 0x34;
    // Unknown opcode: clrrwi r7 r15 5
    gc_mem_write32(gc_env.ram, gc_env.r[5] + 0x0, gc_env.r[7]);
    // Unknown opcode: b .L_80003214
    L_8000320C:
    gc_env.r[14] = 0x0;
    gc_env.r[15] = 0x0;
    L_80003214:
    OSReset();
    OSReset();
    gc_env.r[4] = (0x8000) << 16;
    gc_env.r[4] = gc_env.r[4] + 0x30e6;
    gc_env.r[3] = gc_mem_read16(gc_env.ram, gc_env.r[4] + 0x0);
    gc_env.r[5] = gc_env.r[3] & 0x8000;
    // Unknown opcode: beq .L_8000323C
    gc_env.r[3] = gc_env.r[3] & 0x7fff;
    // Unknown opcode: cmplwi r3 0x1
    if (gc_env.cr[0] != 0) goto L_80003240;
    L_8000323C:
    OSReset();
    L_80003240:
    OSReset();
    // Unknown opcode: mr r3 r14
    // Unknown opcode: mr r4 r15
    OSReset();
    // Unknown opcode: b exit
}

// Function: __init_registers
void __init_registers(void) {
    gc_env.r[1] = (_stack_addr@h) << 16;
    // Unknown opcode: ori r1 r1 _stack_addr@l
    gc_env.r[2] = (_SDA2_BASE_@h) << 16;
    // Unknown opcode: ori r2 r2 _SDA2_BASE_@l
    gc_env.r[13] = (_SDA_BASE_@h) << 16;
    // Unknown opcode: ori r13 r13 _SDA_BASE_@l
    return;
}

// Function: __init_data
void __init_data(void) {
    gc_env.r[0] = gc_env.lr; // Move from link register
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x4, gc_env.r[0]);
    gc_mem_write32(gc_env.ram, gc_env.r[1] + -0x18, gc_env.r[1]);
    gc_env.r[1] = gc_env.r[1] + -0x18;
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x14, gc_env.r[31]);
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x10, gc_env.r[30]);
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0xc, gc_env.r[29]);
    gc_env.r[3] = (_rom_copy_info@ha) << 16;
    gc_env.r[0] = gc_env.r[3] + _rom_copy_info@l;
    // Unknown opcode: mr r29 r0
    // Unknown opcode: b .L_80003298
    L_80003298:
    // Unknown opcode: b .L_8000329C
    L_8000329C:
    gc_env.r[30] = gc_mem_read32(gc_env.ram, gc_env.r[29] + 0x8);
    // Unknown opcode: cmplwi r30 0x0
    // Unknown opcode: beq .L_800032DC
    gc_env.r[4] = gc_mem_read32(gc_env.ram, gc_env.r[29] + 0x0);
    gc_env.r[31] = gc_mem_read32(gc_env.ram, gc_env.r[29] + 0x4);
    // Unknown opcode: beq .L_800032D4
    // Unknown opcode: cmplw r31 r4
    // Unknown opcode: beq .L_800032D4
    // Unknown opcode: mr r3 r31
    // Unknown opcode: mr r5 r30
    OSReset();
    // Unknown opcode: mr r3 r31
    // Unknown opcode: mr r4 r30
    OSReset();
    L_800032D4:
    gc_env.r[29] = gc_env.r[29] + 0xc;
    // Unknown opcode: b .L_8000329C
    L_800032DC:
    gc_env.r[3] = (_bss_init_info@ha) << 16;
    gc_env.r[0] = gc_env.r[3] + _bss_init_info@l;
    // Unknown opcode: mr r29 r0
    // Unknown opcode: b .L_800032EC
    L_800032EC:
    // Unknown opcode: b .L_800032F0
    L_800032F0:
    gc_env.r[5] = gc_mem_read32(gc_env.ram, gc_env.r[29] + 0x4);
    // Unknown opcode: cmplwi r5 0x0
    // Unknown opcode: beq .L_80003314
    gc_env.r[3] = gc_mem_read32(gc_env.ram, gc_env.r[29] + 0x0);
    // Unknown opcode: beq .L_8000330C
    gc_env.r[4] = 0x0;
    OSReset();
    L_8000330C:
    gc_env.r[29] = gc_env.r[29] + 0x8;
    // Unknown opcode: b .L_800032F0
    L_80003314:
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x1c);
    gc_env.r[31] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x14);
    gc_env.r[30] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x10);
    gc_env.r[29] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0xc);
    gc_env.r[1] = gc_env.r[1] + 0x18;
    gc_env.lr = gc_env.r[0]; // Move to link register
    return;
}

// Function: __init_hardware
void __init_hardware(void) {
    // Unknown opcode: mfmsr r0
    // Unknown opcode: ori r0 r0 0x2000
    // Unknown opcode: mtmsr r0
    gc_env.r[31] = gc_env.lr; // Move from link register
    OSReset();
    OSReset();
    gc_env.lr = gc_env.r[31]; // Move to link register
    return;
}

// Function: __flush_cache
void __flush_cache(void) {
    gc_env.r[5] = (0xffff) << 16;
    // Unknown opcode: ori r5 r5 0xfff1
    // Unknown opcode: and r5 r5 r3
    // Unknown opcode: subf r3 r5 r3
    // Unknown opcode: add r4 r4 r3
    L_80003364:
    // Unknown opcode: dcbst r0 r5
    // Unknown opcode: sync 
    // Unknown opcode: icbi r0 r5
    // Unknown opcode: addic r5 r5 0x8
    // Unknown opcode: subic. r4 r4 0x8
    // Unknown opcode: bge .L_80003364
    // Unknown opcode: isync 
    return;
}

// Function: memset
void memset(void) {
    gc_env.r[0] = gc_env.lr; // Move from link register
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x4, gc_env.r[0]);
    gc_mem_write32(gc_env.ram, gc_env.r[1] + -0x20, gc_env.r[1]);
    gc_env.r[1] = gc_env.r[1] + -0x20;
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x1c, gc_env.r[31]);
    // Unknown opcode: mr r31 r3
    OSReset();
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x24);
    // Unknown opcode: mr r3 r31
    gc_env.r[31] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x1c);
    gc_env.r[1] = gc_env.r[1] + 0x20;
    gc_env.lr = gc_env.r[0]; // Move to link register
    return;
}

// Function: __fill_mem
void __fill_mem(void) {
    // Unknown opcode: cmplwi r5 0x20
    // Unknown opcode: clrlwi r0 r4 24
    // Unknown opcode: mr r7 r0
    // Unknown opcode: subi r6 r3 0x1
    // Unknown opcode: blt .L_8000345C
    // Unknown opcode: nor r0 r6 r6
    // Unknown opcode: clrlwi. r0 r0 30
    // Unknown opcode: mr r3 r0
    // Unknown opcode: beq .L_800033EC
    // Unknown opcode: subf r5 r3 r5
    // Unknown opcode: clrlwi r0 r7 24
    L_800033E0:
    // Unknown opcode: subic. r3 r3 0x1
    // Unknown opcode: stbu r0 0x1(r6)
    if (gc_env.cr[0] != 0) goto L_800033E0;
    L_800033EC:
    // Unknown opcode: cmplwi r7 0x0
    // Unknown opcode: beq .L_8000340C
    // Unknown opcode: slwi r3 r7 24
    // Unknown opcode: slwi r0 r7 16
    // Unknown opcode: slwi r4 r7 8
    // Unknown opcode: or r0 r3 r0
    // Unknown opcode: or r0 r4 r0
    // Unknown opcode: or r7 r7 r0
    L_8000340C:
    // Unknown opcode: srwi. r0 r5 5
    // Unknown opcode: subi r3 r6 0x3
    // Unknown opcode: beq .L_80003440
    L_80003418:
    gc_mem_write32(gc_env.ram, gc_env.r[3] + 0x4, gc_env.r[7]);
    // Unknown opcode: subic. r0 r0 0x1
    gc_mem_write32(gc_env.ram, gc_env.r[3] + 0x8, gc_env.r[7]);
    gc_mem_write32(gc_env.ram, gc_env.r[3] + 0xc, gc_env.r[7]);
    gc_mem_write32(gc_env.ram, gc_env.r[3] + 0x10, gc_env.r[7]);
    gc_mem_write32(gc_env.ram, gc_env.r[3] + 0x14, gc_env.r[7]);
    gc_mem_write32(gc_env.ram, gc_env.r[3] + 0x18, gc_env.r[7]);
    gc_mem_write32(gc_env.ram, gc_env.r[3] + 0x1c, gc_env.r[7]);
    gc_mem_write32(gc_env.ram, gc_env.r[3] + 0x20, gc_env.r[7]);
    gc_env.r[3] = gc_env.r[3] + 0x20;
    if (gc_env.cr[0] != 0) goto L_80003418;
    L_80003440:
    // Unknown opcode: extrwi. r0 r5 3 27
    // Unknown opcode: beq .L_80003454
    L_80003448:
    // Unknown opcode: subic. r0 r0 0x1
    gc_mem_write32(gc_env.ram, gc_env.r[3] + 0x4, gc_env.r[7]);
    gc_env.r[3] = gc_env.r[3] + 0x4;
    if (gc_env.cr[0] != 0) goto L_80003448;
    L_80003454:
    gc_env.r[6] = gc_env.r[3] + 0x3;
    // Unknown opcode: clrlwi r5 r5 30
    L_8000345C:
    // Unknown opcode: cmplwi r5 0x0
    // Unknown opcode: beqlr 
    // Unknown opcode: clrlwi r0 r7 24
    L_80003468:
    // Unknown opcode: subic. r5 r5 0x1
    // Unknown opcode: stbu r0 0x1(r6)
    if (gc_env.cr[0] != 0) goto L_80003468;
    return;
}

// Function: memcpy
void memcpy(void) {
    // Unknown opcode: cmplw r4 r3
    // Unknown opcode: blt .L_800034A4
    // Unknown opcode: subi r4 r4 0x1
    // Unknown opcode: subi r6 r3 0x1
    gc_env.r[5] = gc_env.r[5] + 0x1;
    // Unknown opcode: b .L_80003498
    L_80003490:
    // Unknown opcode: lbzu r0 0x1(r4)
    // Unknown opcode: stbu r0 0x1(r6)
    L_80003498:
    // Unknown opcode: subic. r5 r5 0x1
    if (gc_env.cr[0] != 0) goto L_80003490;
    return;
    L_800034A4:
    // Unknown opcode: add r4 r4 r5
    // Unknown opcode: add r6 r3 r5
    gc_env.r[5] = gc_env.r[5] + 0x1;
    // Unknown opcode: b .L_800034BC
    L_800034B4:
    // Unknown opcode: lbzu r0 -0x1(r4)
    // Unknown opcode: stbu r0 -0x1(r6)
    L_800034BC:
    // Unknown opcode: subic. r5 r5 0x1
    if (gc_env.cr[0] != 0) goto L_800034B4;
    return;
}

// Function: fn_800034C8
void fn_800034C8(void) {
    // Unknown opcode: subi r4 r4 0x1
    // Unknown opcode: subi r6 r3 0x1
    gc_env.r[5] = gc_env.r[5] + 0x1;
    // Unknown opcode: b .L_800034E0
    L_800034D8:
    // Unknown opcode: lbzu r0 0x1(r4)
    // Unknown opcode: stbu r0 0x1(r6)
    L_800034E0:
    // Unknown opcode: subic. r5 r5 0x1
    if (gc_env.cr[0] != 0) goto L_800034D8;
    return;
}

// Function: fn_800034EC
void fn_800034EC(void) {
    gc_env.r[0] = gc_env.lr; // Move from link register
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x4, gc_env.r[0]);
    gc_mem_write32(gc_env.ram, gc_env.r[1] + -0x10, gc_env.r[1]);
    gc_env.r[1] = gc_env.r[1] + -0x10;
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0xc, gc_env.r[31]);
    // Unknown opcode: mr r31 r3
    OSReset();
    // Unknown opcode: mr r3 r31
    gc_env.r[31] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0xc);
    gc_env.r[1] = gc_env.r[1] + 0x10;
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x4);
    gc_env.lr = gc_env.r[0]; // Move to link register
    return;
}

// Function: gap_00_8000351C_init
void gap_00_8000351C_init(void) {
    // Unknown opcode: xoris r23 r27 0x6572
    // Unknown opcode: xori r19 r27 0x2054
    // Unknown opcode: ori r18 r11 0x6765
    // Unknown opcode: andis. r0 r1 0x5265
    gc_env.r[9] = gc_env.r[27] & 0x6465;
    // Unknown opcode: xoris r20 r19 0x204b
    // Unknown opcode: oris r18 r11 0x6e65
    // Unknown opcode: xoris r0 r1 0x666f
    gc_env.r[0] = gc_env.r[17] & 0x506f;
    // Unknown opcode: andis. r5 r27 0x7250
    L_80003548:
    // Unknown opcode: b fn_80005450
    // Unknown opcode: mtsprg 1 r2
    // Unknown opcode: mfsrr0 r2
    // Unknown opcode: icbi r0 r2
    // Unknown opcode: mfdar r2
    // Unknown opcode: dcbi r0 r2
    // Unknown opcode: mfsprg r2 1
    // Unknown opcode: mtsprg 1 r2
    // Unknown opcode: mtsprg 2 r3
    // Unknown opcode: mtsprg 3 r4
    // Unknown opcode: mfsrr0 r2
    // Unknown opcode: mfsrr1 r4
    // Unknown opcode: mfmsr r3
    // Unknown opcode: ori r3 r3 0x30
    // Unknown opcode: mtsrr1 r3
    gc_env.r[3] = (0x8001) << 16;
    // Unknown opcode: ori r3 r3 0x75a8
    // Unknown opcode: mtsrr0 r3
    gc_env.r[3] = 0x200;
    // Unknown opcode: rfi 
    // Unknown opcode: mtsprg 1 r2
    // Unknown opcode: mtsprg 2 r3
    // Unknown opcode: mtsprg 3 r4
    // Unknown opcode: mfsrr0 r2
    // Unknown opcode: mfsrr1 r4
    // Unknown opcode: mfmsr r3
    // Unknown opcode: ori r3 r3 0x30
    // Unknown opcode: mtsrr1 r3
    gc_env.r[3] = (0x8001) << 16;
    // Unknown opcode: ori r3 r3 0x75a8
    // Unknown opcode: mtsrr0 r3
    gc_env.r[3] = 0x300;
    // Unknown opcode: rfi 
    // Unknown opcode: mtsprg 1 r2
    // Unknown opcode: mtsprg 2 r3
    // Unknown opcode: mtsprg 3 r4
    // Unknown opcode: mfsrr0 r2
    // Unknown opcode: mfsrr1 r4
    // Unknown opcode: mfmsr r3
    // Unknown opcode: ori r3 r3 0x30
    // Unknown opcode: mtsrr1 r3
    gc_env.r[3] = (0x8001) << 16;
    // Unknown opcode: ori r3 r3 0x75a8
    // Unknown opcode: mtsrr0 r3
    gc_env.r[3] = 0x400;
    // Unknown opcode: rfi 
    // Unknown opcode: mtsprg 1 r2
    // Unknown opcode: mtsprg 2 r3
    // Unknown opcode: mtsprg 3 r4
    // Unknown opcode: mfsrr0 r2
    // Unknown opcode: mfsrr1 r4
    // Unknown opcode: mfmsr r3
    // Unknown opcode: ori r3 r3 0x30
    // Unknown opcode: mtsrr1 r3
    gc_env.r[3] = (0x8001) << 16;
    // Unknown opcode: ori r3 r3 0x75a8
    // Unknown opcode: mtsrr0 r3
    gc_env.r[3] = 0x500;
    // Unknown opcode: rfi 
    // Unknown opcode: mtsprg 1 r2
    // Unknown opcode: mtsprg 2 r3
    // Unknown opcode: mtsprg 3 r4
    // Unknown opcode: mfsrr0 r2
    // Unknown opcode: mfsrr1 r4
    // Unknown opcode: mfmsr r3
    // Unknown opcode: ori r3 r3 0x30
    // Unknown opcode: mtsrr1 r3
    gc_env.r[3] = (0x8001) << 16;
    // Unknown opcode: ori r3 r3 0x75a8
    // Unknown opcode: mtsrr0 r3
    gc_env.r[3] = 0x600;
    // Unknown opcode: rfi 
    // Unknown opcode: mtsprg 1 r2
    // Unknown opcode: mtsprg 2 r3
    // Unknown opcode: mtsprg 3 r4
    // Unknown opcode: mfsrr0 r2
    // Unknown opcode: mfsrr1 r4
    // Unknown opcode: mfmsr r3
    // Unknown opcode: ori r3 r3 0x30
    // Unknown opcode: mtsrr1 r3
    gc_env.r[3] = (0x8001) << 16;
    // Unknown opcode: ori r3 r3 0x75a8
    // Unknown opcode: mtsrr0 r3
    gc_env.r[3] = 0x700;
    // Unknown opcode: rfi 
    // Unknown opcode: mtsprg 1 r2
    // Unknown opcode: mtsprg 2 r3
    // Unknown opcode: mtsprg 3 r4
    // Unknown opcode: mfsrr0 r2
    // Unknown opcode: mfsrr1 r4
    // Unknown opcode: mfmsr r3
    // Unknown opcode: ori r3 r3 0x30
    // Unknown opcode: mtsrr1 r3
    gc_env.r[3] = (0x8001) << 16;
    // Unknown opcode: ori r3 r3 0x75a8
    // Unknown opcode: mtsrr0 r3
    gc_env.r[3] = 0x800;
    // Unknown opcode: rfi 
    // Unknown opcode: mtsprg 1 r2
    // Unknown opcode: mtsprg 2 r3
    // Unknown opcode: mtsprg 3 r4
    // Unknown opcode: mfsrr0 r2
    // Unknown opcode: mfsrr1 r4
    // Unknown opcode: mfmsr r3
    // Unknown opcode: ori r3 r3 0x30
    // Unknown opcode: mtsrr1 r3
    gc_env.r[3] = (0x8001) << 16;
    // Unknown opcode: ori r3 r3 0x75a8
    // Unknown opcode: mtsrr0 r3
    gc_env.r[3] = 0x900;
    // Unknown opcode: rfi 
    // Unknown opcode: mtsprg 1 r2
    // Unknown opcode: mtsprg 2 r3
    // Unknown opcode: mtsprg 3 r4
    // Unknown opcode: mfsrr0 r2
    // Unknown opcode: mfsrr1 r4
    // Unknown opcode: mfmsr r3
    // Unknown opcode: ori r3 r3 0x30
    // Unknown opcode: mtsrr1 r3
    gc_env.r[3] = (0x8001) << 16;
    // Unknown opcode: ori r3 r3 0x75a8
    // Unknown opcode: mtsrr0 r3
    gc_env.r[3] = 0xc00;
    // Unknown opcode: rfi 
    // Unknown opcode: mtsprg 1 r2
    // Unknown opcode: mtsprg 2 r3
    // Unknown opcode: mtsprg 3 r4
    // Unknown opcode: mfsrr0 r2
    // Unknown opcode: mfsrr1 r4
    // Unknown opcode: mfmsr r3
    // Unknown opcode: ori r3 r3 0x30
    // Unknown opcode: mtsrr1 r3
    gc_env.r[3] = (0x8001) << 16;
    // Unknown opcode: ori r3 r3 0x75a8
    // Unknown opcode: mtsrr0 r3
    gc_env.r[3] = 0xd00;
    // Unknown opcode: rfi 
    // Unknown opcode: mtsprg 1 r2
    // Unknown opcode: mtsprg 2 r3
    // Unknown opcode: mtsprg 3 r4
    // Unknown opcode: mfsrr0 r2
    // Unknown opcode: mfsrr1 r4
    // Unknown opcode: mfmsr r3
    // Unknown opcode: ori r3 r3 0x30
    // Unknown opcode: mtsrr1 r3
    gc_env.r[3] = (0x8001) << 16;
    // Unknown opcode: ori r3 r3 0x75a8
    // Unknown opcode: mtsrr0 r3
    gc_env.r[3] = 0xe00;
    // Unknown opcode: rfi 
    // Unknown opcode: b .L_80004470
    // Unknown opcode: mtsprg 1 r2
    // Unknown opcode: mtsprg 2 r3
    // Unknown opcode: mtsprg 3 r4
    // Unknown opcode: mfsrr0 r2
    // Unknown opcode: mfsrr1 r4
    // Unknown opcode: mfmsr r3
    // Unknown opcode: ori r3 r3 0x30
    // Unknown opcode: mtsrr1 r3
    gc_env.r[3] = (0x8001) << 16;
    // Unknown opcode: ori r3 r3 0x75a8
    // Unknown opcode: mtsrr0 r3
    gc_env.r[3] = 0xf20;
    // Unknown opcode: rfi 
    L_80004470:
    // Unknown opcode: mtsprg 1 r2
    // Unknown opcode: mtsprg 2 r3
    // Unknown opcode: mtsprg 3 r4
    // Unknown opcode: mfsrr0 r2
    // Unknown opcode: mfsrr1 r4
    // Unknown opcode: mfmsr r3
    // Unknown opcode: ori r3 r3 0x30
    // Unknown opcode: mtsrr1 r3
    gc_env.r[3] = (0x8001) << 16;
    // Unknown opcode: ori r3 r3 0x75a8
    // Unknown opcode: mtsrr0 r3
    gc_env.r[3] = 0xf00;
    // Unknown opcode: rfi 
    // Unknown opcode: mtsprg 1 r2
    // Unknown opcode: mfcr r2
    // Unknown opcode: mtsprg 2 r2
    // Unknown opcode: mfmsr r2
    // Unknown opcode: andis. r2 r2 0x2
    // Unknown opcode: beq .L_8000454C
    // Unknown opcode: mfmsr r2
    // Unknown opcode: xoris r2 r2 0x2
    // Unknown opcode: sync 
    // Unknown opcode: mtmsr r2
    // Unknown opcode: sync 
    // Unknown opcode: mtsprg 1 r2
    L_8000454C:
    // Unknown opcode: mfsprg r2 2
    // Unknown opcode: mtcrf 255 r2
    // Unknown opcode: mfsprg r2 1
    // Unknown opcode: mtsprg 1 r2
    // Unknown opcode: mtsprg 2 r3
    // Unknown opcode: mtsprg 3 r4
    // Unknown opcode: mfsrr0 r2
    // Unknown opcode: mfsrr1 r4
    // Unknown opcode: mfmsr r3
    // Unknown opcode: ori r3 r3 0x30
    // Unknown opcode: mtsrr1 r3
    gc_env.r[3] = (0x8001) << 16;
    // Unknown opcode: ori r3 r3 0x75a8
    // Unknown opcode: mtsrr0 r3
    gc_env.r[3] = 0x1000;
    // Unknown opcode: rfi 
    // Unknown opcode: mtsprg 1 r2
    // Unknown opcode: mfcr r2
    // Unknown opcode: mtsprg 2 r2
    // Unknown opcode: mfmsr r2
    // Unknown opcode: andis. r2 r2 0x2
    // Unknown opcode: beq .L_8000464C
    // Unknown opcode: mfmsr r2
    // Unknown opcode: xoris r2 r2 0x2
    // Unknown opcode: sync 
    // Unknown opcode: mtmsr r2
    // Unknown opcode: sync 
    // Unknown opcode: mtsprg 1 r2
    L_8000464C:
    // Unknown opcode: mfsprg r2 2
    // Unknown opcode: mtcrf 255 r2
    // Unknown opcode: mfsprg r2 1
    // Unknown opcode: mtsprg 1 r2
    // Unknown opcode: mtsprg 2 r3
    // Unknown opcode: mtsprg 3 r4
    // Unknown opcode: mfsrr0 r2
    // Unknown opcode: mfsrr1 r4
    // Unknown opcode: mfmsr r3
    // Unknown opcode: ori r3 r3 0x30
    // Unknown opcode: mtsrr1 r3
    gc_env.r[3] = (0x8001) << 16;
    // Unknown opcode: ori r3 r3 0x75a8
    // Unknown opcode: mtsrr0 r3
    gc_env.r[3] = 0x1100;
    // Unknown opcode: rfi 
    // Unknown opcode: mtsprg 1 r2
    // Unknown opcode: mfcr r2
    // Unknown opcode: mtsprg 2 r2
    // Unknown opcode: mfmsr r2
    // Unknown opcode: andis. r2 r2 0x2
    // Unknown opcode: beq .L_8000474C
    // Unknown opcode: mfmsr r2
    // Unknown opcode: xoris r2 r2 0x2
    // Unknown opcode: sync 
    // Unknown opcode: mtmsr r2
    // Unknown opcode: sync 
    // Unknown opcode: mtsprg 1 r2
    L_8000474C:
    // Unknown opcode: mfsprg r2 2
    // Unknown opcode: mtcrf 255 r2
    // Unknown opcode: mfsprg r2 1
    // Unknown opcode: mtsprg 1 r2
    // Unknown opcode: mtsprg 2 r3
    // Unknown opcode: mtsprg 3 r4
    // Unknown opcode: mfsrr0 r2
    // Unknown opcode: mfsrr1 r4
    // Unknown opcode: mfmsr r3
    // Unknown opcode: ori r3 r3 0x30
    // Unknown opcode: mtsrr1 r3
    gc_env.r[3] = (0x8001) << 16;
    // Unknown opcode: ori r3 r3 0x75a8
    // Unknown opcode: mtsrr0 r3
    gc_env.r[3] = 0x1200;
    // Unknown opcode: rfi 
    // Unknown opcode: mtsprg 1 r2
    // Unknown opcode: mtsprg 2 r3
    // Unknown opcode: mtsprg 3 r4
    // Unknown opcode: mfsrr0 r2
    // Unknown opcode: mfsrr1 r4
    // Unknown opcode: mfmsr r3
    // Unknown opcode: ori r3 r3 0x30
    // Unknown opcode: mtsrr1 r3
    gc_env.r[3] = (0x8001) << 16;
    // Unknown opcode: ori r3 r3 0x75a8
    // Unknown opcode: mtsrr0 r3
    gc_env.r[3] = 0x1300;
    // Unknown opcode: rfi 
    // Unknown opcode: mtsprg 1 r2
    // Unknown opcode: mtsprg 2 r3
    // Unknown opcode: mtsprg 3 r4
    // Unknown opcode: mfsrr0 r2
    // Unknown opcode: mfsrr1 r4
    // Unknown opcode: mfmsr r3
    // Unknown opcode: ori r3 r3 0x30
    // Unknown opcode: mtsrr1 r3
    gc_env.r[3] = (0x8001) << 16;
    // Unknown opcode: ori r3 r3 0x75a8
    // Unknown opcode: mtsrr0 r3
    gc_env.r[3] = 0x1400;
    // Unknown opcode: rfi 
    // Unknown opcode: mtsprg 1 r2
    // Unknown opcode: mtsprg 2 r3
    // Unknown opcode: mtsprg 3 r4
    // Unknown opcode: mfsrr0 r2
    // Unknown opcode: mfsrr1 r4
    // Unknown opcode: mfmsr r3
    // Unknown opcode: ori r3 r3 0x30
    // Unknown opcode: mtsrr1 r3
    gc_env.r[3] = (0x8001) << 16;
    // Unknown opcode: ori r3 r3 0x75a8
    // Unknown opcode: mtsrr0 r3
    gc_env.r[3] = 0x1600;
    // Unknown opcode: rfi 
    // Unknown opcode: mtsprg 1 r2
    // Unknown opcode: mtsprg 2 r3
    // Unknown opcode: mtsprg 3 r4
    // Unknown opcode: mfsrr0 r2
    // Unknown opcode: mfsrr1 r4
    // Unknown opcode: mfmsr r3
    // Unknown opcode: ori r3 r3 0x30
    // Unknown opcode: mtsrr1 r3
    gc_env.r[3] = (0x8001) << 16;
    // Unknown opcode: ori r3 r3 0x75a8
    // Unknown opcode: mtsrr0 r3
    gc_env.r[3] = 0x1700;
    // Unknown opcode: rfi 
    // Unknown opcode: mtsprg 1 r2
    // Unknown opcode: mtsprg 2 r3
    // Unknown opcode: mtsprg 3 r4
    // Unknown opcode: mfsrr0 r2
    // Unknown opcode: mfsrr1 r4
    // Unknown opcode: mfmsr r3
    // Unknown opcode: ori r3 r3 0x30
    // Unknown opcode: mtsrr1 r3
    gc_env.r[3] = (0x8001) << 16;
    // Unknown opcode: ori r3 r3 0x75a8
    // Unknown opcode: mtsrr0 r3
    gc_env.r[3] = 0x1c00;
    // Unknown opcode: rfi 
    // Unknown opcode: mtsprg 1 r2
    // Unknown opcode: mtsprg 2 r3
    // Unknown opcode: mtsprg 3 r4
    // Unknown opcode: mfsrr0 r2
    // Unknown opcode: mfsrr1 r4
    // Unknown opcode: mfmsr r3
    // Unknown opcode: ori r3 r3 0x30
    // Unknown opcode: mtsrr1 r3
    gc_env.r[3] = (0x8001) << 16;
    // Unknown opcode: ori r3 r3 0x75a8
    // Unknown opcode: mtsrr0 r3
    gc_env.r[3] = 0x1d00;
    // Unknown opcode: rfi 
    // Unknown opcode: mtsprg 1 r2
    // Unknown opcode: mtsprg 2 r3
    // Unknown opcode: mtsprg 3 r4
    // Unknown opcode: mfsrr0 r2
    // Unknown opcode: mfsrr1 r4
    // Unknown opcode: mfmsr r3
    // Unknown opcode: ori r3 r3 0x30
    // Unknown opcode: mtsrr1 r3
    gc_env.r[3] = (0x8001) << 16;
    // Unknown opcode: ori r3 r3 0x75a8
    // Unknown opcode: mtsrr0 r3
    gc_env.r[3] = 0x1e00;
    // Unknown opcode: rfi 
    // Unknown opcode: mtsprg 1 r2
    // Unknown opcode: mtsprg 2 r3
    // Unknown opcode: mtsprg 3 r4
    // Unknown opcode: mfsrr0 r2
    // Unknown opcode: mfsrr1 r4
    // Unknown opcode: mfmsr r3
    // Unknown opcode: ori r3 r3 0x30
    // Unknown opcode: mtsrr1 r3
    gc_env.r[3] = (0x8001) << 16;
    // Unknown opcode: ori r3 r3 0x75a8
    // Unknown opcode: mtsrr0 r3
    gc_env.r[3] = 0x1f00;
    // Unknown opcode: rfi 
}

// Function: fn_80005450
void fn_80005450(void) {
    gc_env.r[0] = gc_env.lr; // Move from link register
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x4, gc_env.r[0]);
    gc_mem_write32(gc_env.ram, gc_env.r[1] + -0x8, gc_env.r[1]);
    gc_env.r[1] = gc_env.r[1] + -0x8;
    OSReset();
    gc_env.r[1] = gc_env.r[1] + 0x8;
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x4);
    gc_env.lr = gc_env.r[0]; // Move to link register
    return;
}
