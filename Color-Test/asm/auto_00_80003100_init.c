#include "all_headers.h"
#include "auto_00_80003100_init.h"
#include <stdint.h>
#include <stdio.h>

#include "gc_env.h"
#include <stdlib.h>

// Function: __check_pad3
// Address: 0x80003100
void __check_pad3(void) {
    gc_env.r[0] = gc_env.lr; // Move from link register
    gc_env.r[3] = -32768 << 16; // lis r3, 0x8000
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x4, gc_env.r[0]); // stw r0, 0x4(r1)
    gc_mem_write32(gc_env.ram, gc_env.r[1] + -0x8, gc_env.r[1]); // stwu r1, -0x8(r1)
    gc_env.r[1] = gc_env.r[1] + -0x8;
    gc_env.r[0] = gc_mem_read16(gc_env.ram, gc_env.r[3] + 0x30e4); // lhz r0, 0x30e4(r3)
    gc_env.r[0] = gc_env.r[0] & 0xeef;
    gc_env.cr[0] = (gc_env.r[0] == 0xeef) ? 0 : (gc_env.r[0] < 0xeef ? -1 : 1); // Compare with immediate
    if (gc_env.cr[0] != 0) goto L_80003130;
    gc_env.r[3] = 0x0; // li r3, 0x0
    gc_env.r[4] = 0x0; // li r4, 0x0
    gc_env.r[5] = 0x0; // li r5, 0x0
    OSResetSystem();
    L_80003130:
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0xC); // lwz r0, 0xC(r1)
    gc_env.r[1] += 8; // addi r1, r1, 0x8
    gc_env.lr = gc_env.r[0]; // Move to link register
    return;
}

// Function: __start
// Address: 0x80003140
void __start(void) {
    __init_registers();
    __init_hardware();
    gc_env.r[0] = -0x1; // li r0, -0x1
    gc_mem_write32(gc_env.ram, gc_env.r[1] + -0x8, gc_env.r[1]); // stwu r1, -0x8(r1)
    gc_env.r[1] = gc_env.r[1] + -0x8;
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x4, gc_env.r[0]); // stw r0, 0x4(r1)
    gc_mem_write32(gc_env.ram, gc_env.r[1], gc_env.r[0]); // stw r0, (r1)
    __init_data();
    gc_env.r[0] = 0x0; // li r0, 0x0
    gc_env.r[6] = -32768 << 16; // lis r6, 0x8000
    gc_env.r[6] += 68; // addi r6, r6, 0x44
    gc_mem_write32(gc_env.ram, gc_env.r[6], gc_env.r[0]); // stw r0, (r6)
    gc_env.r[6] = -32768 << 16; // lis r6, 0x8000
    gc_env.r[6] += 244; // addi r6, r6, 0xf4
    gc_env.r[6] = gc_mem_read32(gc_env.ram, gc_env.r[6]); // lwz r6, (r6)
    gc_env.cr[0] = ((uint32_t)gc_env.r[6] == 0x0) ? 0 : ((uint32_t)gc_env.r[6] < 0x0 ? -1 : 1); // Logical compare with immediate
    if (gc_env.cr[0] == 0) goto L_800031AC;
    gc_env.r[7] = gc_mem_read32(gc_env.ram, gc_env.r[6] + 0xC); // lwz r7, 0xC(r6)
    gc_env.r[5] = 0x0; // li r5, 0x0
    gc_env.cr[0] = ((uint32_t)gc_env.r[7] == 0x2) ? 0 : ((uint32_t)gc_env.r[7] < 0x2 ? -1 : 1); // Logical compare with immediate
    if (gc_env.cr[0] == 0) goto L_8000319C;
    gc_env.cr[0] = ((uint32_t)gc_env.r[7] == 0x3) ? 0 : ((uint32_t)gc_env.r[7] < 0x3 ? -1 : 1); // Logical compare with immediate
    if (gc_env.cr[0] != 0) goto L_800031AC;
    gc_env.r[5] = 0x1; // li r5, 0x1
    L_8000319C:
    gc_env.r[6] = ((uint32_t)&InitMetroTRK >> 16) & 0xFFFF; // lis r6, InitMetroTRK@ha
    gc_env.r[6] = (uint32_t)&InitMetroTRK; // lis + addi InitMetroTRK (completing pattern)
    gc_env.lr = gc_env.r[6]; // Move to link register
    // Call function at gc_env.lr; // Branch to link register
    L_800031AC:
    gc_env.r[6] = -32768 << 16; // lis r6, 0x8000
    gc_env.r[6] += 244; // addi r6, r6, 0xf4
    gc_env.r[5] = gc_mem_read32(gc_env.ram, gc_env.r[6]); // lwz r5, (r6)
    gc_env.cr[0] = ((uint32_t)gc_env.r[5] == 0x0) ? 0 : ((uint32_t)gc_env.r[5] < 0x0 ? -1 : 1); // Logical compare with immediate
    if (gc_env.cr[0] == 0) goto L_8000320C;
    gc_env.r[6] = gc_mem_read32(gc_env.ram, gc_env.r[5] + 0x8); // lwz r6, 0x8(r5)
    gc_env.cr[0] = ((uint32_t)gc_env.r[6] == 0x0) ? 0 : ((uint32_t)gc_env.r[6] < 0x0 ? -1 : 1); // Logical compare with immediate
    if (gc_env.cr[0] == 0) goto L_8000320C;
    gc_env.r[6] = gc_env.r[5] + gc_env.r[6]; // add r6, r5, r6
    gc_env.r[14] = gc_mem_read32(gc_env.ram, gc_env.r[6]); // lwz r14, (r6)
    gc_env.cr[0] = ((uint32_t)gc_env.r[14] == 0x0) ? 0 : ((uint32_t)gc_env.r[14] < 0x0 ? -1 : 1); // Logical compare with immediate
    if (gc_env.cr[0] == 0) goto L_8000320C;
    gc_env.r[15] = gc_env.r[6] + 4; // addi r15, r6, 0x4
    gc_env.ctr = gc_env.r[14]; // Move to count register
    L_800031E4:
    gc_env.r[6] += 4; // addi r6, r6, 0x4
    gc_env.r[7] = gc_mem_read32(gc_env.ram, gc_env.r[6]); // lwz r7, (r6)
    gc_env.r[7] = gc_env.r[7] + gc_env.r[5]; // add r7, r7, r5
    gc_mem_write32(gc_env.ram, gc_env.r[6], gc_env.r[7]); // stw r7, (r6)
    gc_env.ctr -= 1;
    if (gc_env.ctr != 0) goto L_800031E4;
    gc_env.r[5] = -32768 << 16; // lis r5, 0x8000
    gc_env.r[5] += 52; // addi r5, r5, 0x34
    gc_env.r[7] = gc_env.r[15] & ~((1ULL << 5) - 1); // Clear rightmost 5 bits
    gc_mem_write32(gc_env.ram, gc_env.r[5], gc_env.r[7]); // stw r7, (r5)
    goto L_80003214;
    L_8000320C:
    gc_env.r[14] = 0x0; // li r14, 0x0
    gc_env.r[15] = 0x0; // li r15, 0x0
    L_80003214:
    DBInit();
    OSInit();
    gc_env.r[4] = -32768 << 16; // lis r4, 0x8000
    gc_env.r[4] += 12518; // addi r4, r4, 0x30e6
    gc_env.r[3] = gc_mem_read16(gc_env.ram, gc_env.r[4] + 0x0); // lhz r3, 0x0(r4)
    gc_env.r[5] = gc_env.r[3] & 0x8000;
    if (gc_env.cr[0] == 0) goto L_8000323C;
    gc_env.r[3] = gc_env.r[3] & 0x7fff;
    gc_env.cr[0] = ((uint32_t)gc_env.r[3] == 0x1) ? 0 : ((uint32_t)gc_env.r[3] < 0x1 ? -1 : 1); // Logical compare with immediate
    if (gc_env.cr[0] != 0) goto L_80003240;
    L_8000323C:
    __check_pad3();
    L_80003240:
    __init_user();
    gc_env.r[3] = gc_env.r[14]; // Move register
    gc_env.r[4] = gc_env.r[15]; // Move register
    main();
    exit(gc_env.r[3]);
}

// Function: __init_registers
// Address: 0x80003254
void __init_registers(void) {
    gc_env.r[1] = ((uint32_t)&_stack_addr >> 16) & 0xFFFF; // lis r1, _stack_addr@h
    gc_env.r[1] = (uint32_t)&_stack_addr; // lis + ori _stack_addr
    gc_env.r[2] = ((uint32_t)&_SDA2_BASE_ >> 16) & 0xFFFF; // lis r2, _SDA2_BASE_@h
    gc_env.r[2] = (uint32_t)&_SDA2_BASE_; // lis + ori _SDA2_BASE_
    gc_env.r[13] = ((uint32_t)&_SDA_BASE_ >> 16) & 0xFFFF; // lis r13, _SDA_BASE_@h
    gc_env.r[13] = (uint32_t)&_SDA_BASE_; // lis + ori _SDA_BASE_
    return;
}

// Function: __init_data
// Address: 0x80003270
void __init_data(void) {
    gc_env.r[0] = gc_env.lr; // Move from link register
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x4, gc_env.r[0]); // stw r0, 0x4(r1)
    gc_mem_write32(gc_env.ram, gc_env.r[1] + -0x18, gc_env.r[1]); // stwu r1, -0x18(r1)
    gc_env.r[1] = gc_env.r[1] + -0x18;
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x14, gc_env.r[31]); // stw r31, 0x14(r1)
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x10, gc_env.r[30]); // stw r30, 0x10(r1)
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0xC, gc_env.r[29]); // stw r29, 0xC(r1)
    gc_env.r[3] = ((uint32_t)&_rom_copy_info >> 16) & 0xFFFF; // lis r3, _rom_copy_info@ha
    gc_env.r[0] = (uint32_t)&_rom_copy_info; // lis + addi _rom_copy_info (completing pattern)
    gc_env.r[29] = gc_env.r[0]; // Move register
    goto L_80003298;
    L_80003298:
    goto L_8000329C;
    L_8000329C:
    gc_env.r[30] = gc_mem_read32(gc_env.ram, gc_env.r[29] + 0x8); // lwz r30, 0x8(r29)
    gc_env.cr[0] = ((uint32_t)gc_env.r[30] == 0x0) ? 0 : ((uint32_t)gc_env.r[30] < 0x0 ? -1 : 1); // Logical compare with immediate
    if (gc_env.cr[0] == 0) goto L_800032DC;
    gc_env.r[4] = gc_mem_read32(gc_env.ram, gc_env.r[29]); // lwz r4, (r29)
    gc_env.r[31] = gc_mem_read32(gc_env.ram, gc_env.r[29] + 0x4); // lwz r31, 0x4(r29)
    if (gc_env.cr[0] == 0) goto L_800032D4;
    gc_env.cr[0] = ((uint32_t)gc_env.r[31] == (uint32_t)gc_env.r[4]) ? 0 : ((uint32_t)gc_env.r[31] < (uint32_t)gc_env.r[4] ? -1 : 1); // Logical compare word
    if (gc_env.cr[0] == 0) goto L_800032D4;
    gc_env.r[3] = gc_env.r[31]; // Move register
    gc_env.r[5] = gc_env.r[30]; // Move register
    memcpy();
    gc_env.r[3] = gc_env.r[31]; // Move register
    gc_env.r[4] = gc_env.r[30]; // Move register
    __flush_cache();
    L_800032D4:
    gc_env.r[29] += 12; // addi r29, r29, 0xc
    goto L_8000329C;
    L_800032DC:
    gc_env.r[3] = ((uint32_t)&_bss_init_info >> 16) & 0xFFFF; // lis r3, _bss_init_info@ha
    gc_env.r[0] = (uint32_t)&_bss_init_info; // lis + addi _bss_init_info (completing pattern)
    gc_env.r[29] = gc_env.r[0]; // Move register
    goto L_800032EC;
    L_800032EC:
    goto L_800032F0;
    L_800032F0:
    gc_env.r[5] = gc_mem_read32(gc_env.ram, gc_env.r[29] + 0x4); // lwz r5, 0x4(r29)
    gc_env.cr[0] = ((uint32_t)gc_env.r[5] == 0x0) ? 0 : ((uint32_t)gc_env.r[5] < 0x0 ? -1 : 1); // Logical compare with immediate
    if (gc_env.cr[0] == 0) goto L_80003314;
    gc_env.r[3] = gc_mem_read32(gc_env.ram, gc_env.r[29]); // lwz r3, (r29)
    if (gc_env.cr[0] == 0) goto L_8000330C;
    gc_env.r[4] = 0x0; // li r4, 0x0
    memset();
    L_8000330C:
    gc_env.r[29] += 8; // addi r29, r29, 0x8
    goto L_800032F0;
    L_80003314:
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x1C); // lwz r0, 0x1C(r1)
    gc_env.r[31] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x14); // lwz r31, 0x14(r1)
    gc_env.r[30] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x10); // lwz r30, 0x10(r1)
    gc_env.r[29] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0xC); // lwz r29, 0xC(r1)
    gc_env.r[1] += 24; // addi r1, r1, 0x18
    gc_env.lr = gc_env.r[0]; // Move to link register
    return;
}

// Function: __init_hardware
// Address: 0x80003330
void __init_hardware(void) {
    gc_env.r[0] = gc_env.msr; // Move from machine state register
    gc_env.r[0] |= 8192; // ori r0, r0, 0x2000
    gc_env.msr = gc_env.r[0]; // Move to machine state register
    gc_env.r[31] = gc_env.lr; // Move from link register
    __OSPSInit();
    __OSCacheInit();
    gc_env.lr = gc_env.r[31]; // Move to link register
    return;
}

// Function: __flush_cache
// Address: 0x80003350
void __flush_cache(void) {
    gc_env.r[5] = -1 << 16; // lis r5, 0xffff
    gc_env.r[5] |= 65521; // ori r5, r5, 0xfff1
    gc_env.r[5] = gc_env.r[5] & gc_env.r[3];
    gc_env.r[3] = gc_env.r[3] - gc_env.r[5]; // subf r3, r5, r3
    gc_env.r[4] = gc_env.r[4] + gc_env.r[3]; // add r4, r4, r3
    L_80003364:
    // dcbst: Data cache block store (no-op in this context)
    // sync: Memory barrier (no-op in this context)
    // icbi: Instruction cache block invalidate (no-op in this context)
    gc_env.r[5] = gc_env.r[5] + 8; // addic r5, r5, 8
    gc_env.xer = (gc_env.xer & ~0x20000000) | (((uint64_t)gc_env.r[5] + 8) > 0xFFFFFFFF ? 0x20000000 : 0);
    gc_env.r[4] = gc_env.r[4] - 8; // subic. r4, r4, 8
    gc_env.xer = (gc_env.xer & ~0x20000000) | (gc_env.r[4] >= 8 ? 0x20000000 : 0);
    gc_env.cr[0] = (gc_env.r[4] == 0) ? 0x2 : ((int32_t)gc_env.r[4] < 0 ? 0x8 : 0x4);
    if (gc_env.cr[0] >= 0) goto L_80003364;
    // isync: Instruction synchronize (no-op in this context)
    return;
}

// Function: memset
// Address: 0x80003384
void memset(void) {
    gc_env.r[0] = gc_env.lr; // Move from link register
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x4, gc_env.r[0]); // stw r0, 0x4(r1)
    gc_mem_write32(gc_env.ram, gc_env.r[1] + -0x20, gc_env.r[1]); // stwu r1, -0x20(r1)
    gc_env.r[1] = gc_env.r[1] + -0x20;
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x1C, gc_env.r[31]); // stw r31, 0x1C(r1)
    gc_env.r[31] = gc_env.r[3]; // Move register
    __fill_mem();
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x24); // lwz r0, 0x24(r1)
    gc_env.r[3] = gc_env.r[31]; // Move register
    gc_env.r[31] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x1C); // lwz r31, 0x1C(r1)
    gc_env.r[1] += 32; // addi r1, r1, 0x20
    gc_env.lr = gc_env.r[0]; // Move to link register
    return;
}

// Function: __fill_mem
// Address: 0x800033B4
void __fill_mem(void) {
    gc_env.cr[0] = ((uint32_t)gc_env.r[5] == 0x20) ? 0 : ((uint32_t)gc_env.r[5] < 0x20 ? -1 : 1); // Logical compare with immediate
    gc_env.r[0] = gc_env.r[4] & 0xFF; // clrlwi r0, r4, 24
    gc_env.r[7] = gc_env.r[0]; // Move register
    gc_env.r[6] = gc_env.r[3] - 1; // subi r6, r3, 1
    if (gc_env.cr[0] & 0x8) goto L_8000345C; // blt .L_8000345C
    gc_env.r[0] = ~gc_env.r[6]; // nor r0, r6, r6
    gc_env.r[0] = gc_env.r[0] & 0x3; // clrlwi r0, r0, 30
    gc_env.r[3] = gc_env.r[0]; // Move register
    if (gc_env.cr[0] == 0) goto L_800033EC;
    gc_env.r[5] = gc_env.r[5] - gc_env.r[3]; // subf r5, r3, r5
    gc_env.r[0] = gc_env.r[7] & 0xFF; // clrlwi r0, r7, 24
    L_800033E0:
    gc_env.r[3] = gc_env.r[3] - 1; // subic. r3, r3, 1
    gc_env.xer = (gc_env.xer & ~0x20000000) | (gc_env.r[3] >= 1 ? 0x20000000 : 0);
    gc_env.cr[0] = (gc_env.r[3] == 0) ? 0x2 : ((int32_t)gc_env.r[3] < 0 ? 0x8 : 0x4);
    gc_mem_write8(gc_env.ram, gc_env.r[6] + 0x1, gc_env.r[0]); // stbu r0, 0x1(r6)
    gc_env.r[6] = gc_env.r[6] + 0x1;
    if (gc_env.cr[0] != 0) goto L_800033E0;
    L_800033EC:
    gc_env.cr[0] = ((uint32_t)gc_env.r[7] == 0x0) ? 0 : ((uint32_t)gc_env.r[7] < 0x0 ? -1 : 1); // Logical compare with immediate
    if (gc_env.cr[0] == 0) goto L_8000340C;
    gc_env.r[3] = gc_env.r[7] << 24; // slwi r3, r7, 24
    gc_env.r[0] = gc_env.r[7] << 16; // slwi r0, r7, 16
    gc_env.r[4] = gc_env.r[7] << 8; // slwi r4, r7, 8
    gc_env.r[0] = gc_env.r[3] | gc_env.r[0]; // or r0, r3, r0
    gc_env.r[0] = gc_env.r[4] | gc_env.r[0]; // or r0, r4, r0
    gc_env.r[7] = gc_env.r[7] | gc_env.r[0]; // or r7, r7, r0
    L_8000340C:
    gc_env.r[0] = gc_env.r[5] >> 5; // srwi r0, r5, 5
    gc_env.cr[0] = (gc_env.r[0] == 0) ? 0x2 : ((int32_t)gc_env.r[0] < 0 ? 0x8 : 0x4);
    gc_env.r[3] = gc_env.r[6] - 3; // subi r3, r6, 3
    if (gc_env.cr[0] == 0) goto L_80003440;
    L_80003418:
    gc_mem_write32(gc_env.ram, gc_env.r[3] + 0x4, gc_env.r[7]); // stw r7, 0x4(r3)
    gc_env.r[0] = gc_env.r[0] - 1; // subic. r0, r0, 1
    gc_env.xer = (gc_env.xer & ~0x20000000) | (gc_env.r[0] >= 1 ? 0x20000000 : 0);
    gc_env.cr[0] = (gc_env.r[0] == 0) ? 0x2 : ((int32_t)gc_env.r[0] < 0 ? 0x8 : 0x4);
    gc_mem_write32(gc_env.ram, gc_env.r[3] + 0x8, gc_env.r[7]); // stw r7, 0x8(r3)
    gc_mem_write32(gc_env.ram, gc_env.r[3] + 0xC, gc_env.r[7]); // stw r7, 0xC(r3)
    gc_mem_write32(gc_env.ram, gc_env.r[3] + 0x10, gc_env.r[7]); // stw r7, 0x10(r3)
    gc_mem_write32(gc_env.ram, gc_env.r[3] + 0x14, gc_env.r[7]); // stw r7, 0x14(r3)
    gc_mem_write32(gc_env.ram, gc_env.r[3] + 0x18, gc_env.r[7]); // stw r7, 0x18(r3)
    gc_mem_write32(gc_env.ram, gc_env.r[3] + 0x1C, gc_env.r[7]); // stw r7, 0x1C(r3)
    gc_mem_write32(gc_env.ram, gc_env.r[3] + 0x20, gc_env.r[7]); // stwu r7, 0x20(r3)
    gc_env.r[3] = gc_env.r[3] + 0x20;
    if (gc_env.cr[0] != 0) goto L_80003418;
    L_80003440:
    gc_env.r[0] = (gc_env.r[5] >> 2) & 0x7; // extrwi r0, r5, 3, 27
    gc_env.cr[0] = (gc_env.r[0] == 0) ? 0x2 : ((int32_t)gc_env.r[0] < 0 ? 0x8 : 0x4);
    if (gc_env.cr[0] == 0) goto L_80003454;
    L_80003448:
    gc_env.r[0] = gc_env.r[0] - 1; // subic. r0, r0, 1
    gc_env.xer = (gc_env.xer & ~0x20000000) | (gc_env.r[0] >= 1 ? 0x20000000 : 0);
    gc_env.cr[0] = (gc_env.r[0] == 0) ? 0x2 : ((int32_t)gc_env.r[0] < 0 ? 0x8 : 0x4);
    gc_mem_write32(gc_env.ram, gc_env.r[3] + 0x4, gc_env.r[7]); // stwu r7, 0x4(r3)
    gc_env.r[3] = gc_env.r[3] + 0x4;
    if (gc_env.cr[0] != 0) goto L_80003448;
    L_80003454:
    gc_env.r[6] = gc_env.r[3] + 3; // addi r6, r3, 0x3
    gc_env.r[5] = gc_env.r[5] & 0x3; // clrlwi r5, r5, 30
    L_8000345C:
    gc_env.cr[0] = ((uint32_t)gc_env.r[5] == 0x0) ? 0 : ((uint32_t)gc_env.r[5] < 0x0 ? -1 : 1); // Logical compare with immediate
    if (gc_env.cr[0] & 0x2) return; // beqlr
    gc_env.r[0] = gc_env.r[7] & 0xFF; // clrlwi r0, r7, 24
    L_80003468:
    gc_env.r[5] = gc_env.r[5] - 1; // subic. r5, r5, 1
    gc_env.xer = (gc_env.xer & ~0x20000000) | (gc_env.r[5] >= 1 ? 0x20000000 : 0);
    gc_env.cr[0] = (gc_env.r[5] == 0) ? 0x2 : ((int32_t)gc_env.r[5] < 0 ? 0x8 : 0x4);
    gc_mem_write8(gc_env.ram, gc_env.r[6] + 0x1, gc_env.r[0]); // stbu r0, 0x1(r6)
    gc_env.r[6] = gc_env.r[6] + 0x1;
    if (gc_env.cr[0] != 0) goto L_80003468;
    return;
}

// Function: fn_800034C8
// Address: 0x800034C8
void fn_800034C8(void) {
    gc_env.r[4] = gc_env.r[4] - 1; // subi r4, r4, 1
    gc_env.r[6] = gc_env.r[3] - 1; // subi r6, r3, 1
    gc_env.r[5] += 1; // addi r5, r5, 0x1
    goto L_800034E0;
    L_800034D8:
    gc_env.r[0] = gc_mem_read8(gc_env.ram, gc_env.r[4] + 1); // lbzu r0, 1(r4)
    gc_env.r[4] = gc_env.r[4] + 1;
    gc_mem_write8(gc_env.ram, gc_env.r[6] + 0x1, gc_env.r[0]); // stbu r0, 0x1(r6)
    gc_env.r[6] = gc_env.r[6] + 0x1;
    L_800034E0:
    gc_env.r[5] = gc_env.r[5] - 1; // subic. r5, r5, 1
    gc_env.xer = (gc_env.xer & ~0x20000000) | (gc_env.r[5] >= 1 ? 0x20000000 : 0);
    gc_env.cr[0] = (gc_env.r[5] == 0) ? 0x2 : ((int32_t)gc_env.r[5] < 0 ? 0x8 : 0x4);
    if (gc_env.cr[0] != 0) goto L_800034D8;
    return;
}

// Function: fn_800034EC
// Address: 0x800034EC
void fn_800034EC(void) {
    gc_env.r[0] = gc_env.lr; // Move from link register
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x4, gc_env.r[0]); // stw r0, 0x4(r1)
    gc_mem_write32(gc_env.ram, gc_env.r[1] + -0x10, gc_env.r[1]); // stwu r1, -0x10(r1)
    gc_env.r[1] = gc_env.r[1] + -0x10;
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0xC, gc_env.r[31]); // stw r31, 0xC(r1)
    gc_env.r[31] = gc_env.r[3]; // Move register
    fn_80016B44();
    gc_env.r[3] = gc_env.r[31]; // Move register
    gc_env.r[31] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0xC); // lwz r31, 0xC(r1)
    gc_env.r[1] += 16; // addi r1, r1, 0x10
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x4); // lwz r0, 0x4(r1)
    gc_env.lr = gc_env.r[0]; // Move to link register
    return;
}

// Function: fn_80005450
// Address: 0x80005450
void fn_80005450(void) {
    gc_env.r[0] = gc_env.lr; // Move from link register
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x4, gc_env.r[0]); // stw r0, 0x4(r1)
    gc_mem_write32(gc_env.ram, gc_env.r[1] + -0x8, gc_env.r[1]); // stwu r1, -0x8(r1)
    gc_env.r[1] = gc_env.r[1] + -0x8;
    fn_80018340();
    gc_env.r[1] += 8; // addi r1, r1, 0x8
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x4); // lwz r0, 0x4(r1)
    gc_env.lr = gc_env.r[0]; // Move to link register
    return;
}

// Data section: gap_00_8000351C_init
// Address: 0x8000351C
uint32_t gap_00_8000351C_init[] = {
    0x4D657472, // .4byte 0x4D657472 /* invalid */
    0x6F776572, // xoris r23, r27, 0x6572
    0x6B732054, // xori r19, r27, 0x2054
    0x61726765, // ori r18, r11, 0x6765
    0x74205265, // andis. r0, r1, 0x5265
    0x73696465, // andi. r9, r27, 0x6465
    0x6E74204B, // xoris r20, r19, 0x204b
    0x65726E65, // oris r18, r11, 0x6e65
    0x6C20666F, // xoris r0, r1, 0x666f
    0x7220506F, // andi. r0, r17, 0x506f
    0x77657250, // andis. r5, r27, 0x7250
    // Label: L_80003548:
    0x43000000, // .4byte 0x43000000 /* illegal: bc 24, lt, 0x0 */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x48001E34, // b fn_80005450
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x7C5143A6, // mtsprg 1, r2
    0x7C5A02A6, // mfsrr0 r2
    0x7C0017AC, // icbi r0, r2
    0x7C5302A6, // mfdar r2
    0x7C0013AC, // dcbi r0, r2
    0x7C5142A6, // mfsprg r2, 1
    0x7C5143A6, // mtsprg 1, r2
    0x7C7243A6, // mtsprg 2, r3
    0x7C9343A6, // mtsprg 3, r4
    0x7C5A02A6, // mfsrr0 r2
    0x7C9B02A6, // mfsrr1 r4
    0x7C6000A6, // mfmsr r3
    0x60630030, // ori r3, r3, 0x30
    0x7C7B03A6, // mtsrr1 r3
    0x3C608001, // lis r3, 0x8001
    0x606375A8, // ori r3, r3, 0x75a8
    0x7C7A03A6, // mtsrr0 r3
    0x38600200, // li r3, 0x200
    0x4C000064, // rfi
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x7C5143A6, // mtsprg 1, r2
    0x7C7243A6, // mtsprg 2, r3
    0x7C9343A6, // mtsprg 3, r4
    0x7C5A02A6, // mfsrr0 r2
    0x7C9B02A6, // mfsrr1 r4
    0x7C6000A6, // mfmsr r3
    0x60630030, // ori r3, r3, 0x30
    0x7C7B03A6, // mtsrr1 r3
    0x3C608001, // lis r3, 0x8001
    0x606375A8, // ori r3, r3, 0x75a8
    0x7C7A03A6, // mtsrr0 r3
    0x38600300, // li r3, 0x300
    0x4C000064, // rfi
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x7C5143A6, // mtsprg 1, r2
    0x7C7243A6, // mtsprg 2, r3
    0x7C9343A6, // mtsprg 3, r4
    0x7C5A02A6, // mfsrr0 r2
    0x7C9B02A6, // mfsrr1 r4
    0x7C6000A6, // mfmsr r3
    0x60630030, // ori r3, r3, 0x30
    0x7C7B03A6, // mtsrr1 r3
    0x3C608001, // lis r3, 0x8001
    0x606375A8, // ori r3, r3, 0x75a8
    0x7C7A03A6, // mtsrr0 r3
    0x38600400, // li r3, 0x400
    0x4C000064, // rfi
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x7C5143A6, // mtsprg 1, r2
    0x7C7243A6, // mtsprg 2, r3
    0x7C9343A6, // mtsprg 3, r4
    0x7C5A02A6, // mfsrr0 r2
    0x7C9B02A6, // mfsrr1 r4
    0x7C6000A6, // mfmsr r3
    0x60630030, // ori r3, r3, 0x30
    0x7C7B03A6, // mtsrr1 r3
    0x3C608001, // lis r3, 0x8001
    0x606375A8, // ori r3, r3, 0x75a8
    0x7C7A03A6, // mtsrr0 r3
    0x38600500, // li r3, 0x500
    0x4C000064, // rfi
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x7C5143A6, // mtsprg 1, r2
    0x7C7243A6, // mtsprg 2, r3
    0x7C9343A6, // mtsprg 3, r4
    0x7C5A02A6, // mfsrr0 r2
    0x7C9B02A6, // mfsrr1 r4
    0x7C6000A6, // mfmsr r3
    0x60630030, // ori r3, r3, 0x30
    0x7C7B03A6, // mtsrr1 r3
    0x3C608001, // lis r3, 0x8001
    0x606375A8, // ori r3, r3, 0x75a8
    0x7C7A03A6, // mtsrr0 r3
    0x38600600, // li r3, 0x600
    0x4C000064, // rfi
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x7C5143A6, // mtsprg 1, r2
    0x7C7243A6, // mtsprg 2, r3
    0x7C9343A6, // mtsprg 3, r4
    0x7C5A02A6, // mfsrr0 r2
    0x7C9B02A6, // mfsrr1 r4
    0x7C6000A6, // mfmsr r3
    0x60630030, // ori r3, r3, 0x30
    0x7C7B03A6, // mtsrr1 r3
    0x3C608001, // lis r3, 0x8001
    0x606375A8, // ori r3, r3, 0x75a8
    0x7C7A03A6, // mtsrr0 r3
    0x38600700, // li r3, 0x700
    0x4C000064, // rfi
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x7C5143A6, // mtsprg 1, r2
    0x7C7243A6, // mtsprg 2, r3
    0x7C9343A6, // mtsprg 3, r4
    0x7C5A02A6, // mfsrr0 r2
    0x7C9B02A6, // mfsrr1 r4
    0x7C6000A6, // mfmsr r3
    0x60630030, // ori r3, r3, 0x30
    0x7C7B03A6, // mtsrr1 r3
    0x3C608001, // lis r3, 0x8001
    0x606375A8, // ori r3, r3, 0x75a8
    0x7C7A03A6, // mtsrr0 r3
    0x38600800, // li r3, 0x800
    0x4C000064, // rfi
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x7C5143A6, // mtsprg 1, r2
    0x7C7243A6, // mtsprg 2, r3
    0x7C9343A6, // mtsprg 3, r4
    0x7C5A02A6, // mfsrr0 r2
    0x7C9B02A6, // mfsrr1 r4
    0x7C6000A6, // mfmsr r3
    0x60630030, // ori r3, r3, 0x30
    0x7C7B03A6, // mtsrr1 r3
    0x3C608001, // lis r3, 0x8001
    0x606375A8, // ori r3, r3, 0x75a8
    0x7C7A03A6, // mtsrr0 r3
    0x38600900, // li r3, 0x900
    0x4C000064, // rfi
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x7C5143A6, // mtsprg 1, r2
    0x7C7243A6, // mtsprg 2, r3
    0x7C9343A6, // mtsprg 3, r4
    0x7C5A02A6, // mfsrr0 r2
    0x7C9B02A6, // mfsrr1 r4
    0x7C6000A6, // mfmsr r3
    0x60630030, // ori r3, r3, 0x30
    0x7C7B03A6, // mtsrr1 r3
    0x3C608001, // lis r3, 0x8001
    0x606375A8, // ori r3, r3, 0x75a8
    0x7C7A03A6, // mtsrr0 r3
    0x38600C00, // li r3, 0xc00
    0x4C000064, // rfi
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x7C5143A6, // mtsprg 1, r2
    0x7C7243A6, // mtsprg 2, r3
    0x7C9343A6, // mtsprg 3, r4
    0x7C5A02A6, // mfsrr0 r2
    0x7C9B02A6, // mfsrr1 r4
    0x7C6000A6, // mfmsr r3
    0x60630030, // ori r3, r3, 0x30
    0x7C7B03A6, // mtsrr1 r3
    0x3C608001, // lis r3, 0x8001
    0x606375A8, // ori r3, r3, 0x75a8
    0x7C7A03A6, // mtsrr0 r3
    0x38600D00, // li r3, 0xd00
    0x4C000064, // rfi
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x7C5143A6, // mtsprg 1, r2
    0x7C7243A6, // mtsprg 2, r3
    0x7C9343A6, // mtsprg 3, r4
    0x7C5A02A6, // mfsrr0 r2
    0x7C9B02A6, // mfsrr1 r4
    0x7C6000A6, // mfmsr r3
    0x60630030, // ori r3, r3, 0x30
    0x7C7B03A6, // mtsrr1 r3
    0x3C608001, // lis r3, 0x8001
    0x606375A8, // ori r3, r3, 0x75a8
    0x7C7A03A6, // mtsrr0 r3
    0x38600E00, // li r3, 0xe00
    0x4C000064, // rfi
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x48000054, // b .L_80004470
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x7C5143A6, // mtsprg 1, r2
    0x7C7243A6, // mtsprg 2, r3
    0x7C9343A6, // mtsprg 3, r4
    0x7C5A02A6, // mfsrr0 r2
    0x7C9B02A6, // mfsrr1 r4
    0x7C6000A6, // mfmsr r3
    0x60630030, // ori r3, r3, 0x30
    0x7C7B03A6, // mtsrr1 r3
    0x3C608001, // lis r3, 0x8001
    0x606375A8, // ori r3, r3, 0x75a8
    0x7C7A03A6, // mtsrr0 r3
    0x38600F20, // li r3, 0xf20
    0x4C000064, // rfi
    // Label: L_80004470:
    0x7C5143A6, // mtsprg 1, r2
    0x7C7243A6, // mtsprg 2, r3
    0x7C9343A6, // mtsprg 3, r4
    0x7C5A02A6, // mfsrr0 r2
    0x7C9B02A6, // mfsrr1 r4
    0x7C6000A6, // mfmsr r3
    0x60630030, // ori r3, r3, 0x30
    0x7C7B03A6, // mtsrr1 r3
    0x3C608001, // lis r3, 0x8001
    0x606375A8, // ori r3, r3, 0x75a8
    0x7C7A03A6, // mtsrr0 r3
    0x38600F00, // li r3, 0xf00
    0x4C000064, // rfi
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x7C5143A6, // mtsprg 1, r2
    0x7C400026, // mfcr r2
    0x7C5243A6, // mtsprg 2, r2
    0x7C4000A6, // mfmsr r2
    0x74420002, // andis. r2, r2, 0x2
    0x4182001C, // beq .L_8000454C
    0x7C4000A6, // mfmsr r2
    0x6C420002, // xoris r2, r2, 0x2
    0x7C0004AC, // sync
    0x7C400124, // mtmsr r2
    0x7C0004AC, // sync
    0x7C5143A6, // mtsprg 1, r2
    // Label: L_8000454C:
    0x7C5242A6, // mfsprg r2, 2
    0x7C4FF120, // mtcrf 255, r2
    0x7C5142A6, // mfsprg r2, 1
    0x7C5143A6, // mtsprg 1, r2
    0x7C7243A6, // mtsprg 2, r3
    0x7C9343A6, // mtsprg 3, r4
    0x7C5A02A6, // mfsrr0 r2
    0x7C9B02A6, // mfsrr1 r4
    0x7C6000A6, // mfmsr r3
    0x60630030, // ori r3, r3, 0x30
    0x7C7B03A6, // mtsrr1 r3
    0x3C608001, // lis r3, 0x8001
    0x606375A8, // ori r3, r3, 0x75a8
    0x7C7A03A6, // mtsrr0 r3
    0x38601000, // li r3, 0x1000
    0x4C000064, // rfi
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x7C5143A6, // mtsprg 1, r2
    0x7C400026, // mfcr r2
    0x7C5243A6, // mtsprg 2, r2
    0x7C4000A6, // mfmsr r2
    0x74420002, // andis. r2, r2, 0x2
    0x4182001C, // beq .L_8000464C
    0x7C4000A6, // mfmsr r2
    0x6C420002, // xoris r2, r2, 0x2
    0x7C0004AC, // sync
    0x7C400124, // mtmsr r2
    0x7C0004AC, // sync
    0x7C5143A6, // mtsprg 1, r2
    // Label: L_8000464C:
    0x7C5242A6, // mfsprg r2, 2
    0x7C4FF120, // mtcrf 255, r2
    0x7C5142A6, // mfsprg r2, 1
    0x7C5143A6, // mtsprg 1, r2
    0x7C7243A6, // mtsprg 2, r3
    0x7C9343A6, // mtsprg 3, r4
    0x7C5A02A6, // mfsrr0 r2
    0x7C9B02A6, // mfsrr1 r4
    0x7C6000A6, // mfmsr r3
    0x60630030, // ori r3, r3, 0x30
    0x7C7B03A6, // mtsrr1 r3
    0x3C608001, // lis r3, 0x8001
    0x606375A8, // ori r3, r3, 0x75a8
    0x7C7A03A6, // mtsrr0 r3
    0x38601100, // li r3, 0x1100
    0x4C000064, // rfi
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x7C5143A6, // mtsprg 1, r2
    0x7C400026, // mfcr r2
    0x7C5243A6, // mtsprg 2, r2
    0x7C4000A6, // mfmsr r2
    0x74420002, // andis. r2, r2, 0x2
    0x4182001C, // beq .L_8000474C
    0x7C4000A6, // mfmsr r2
    0x6C420002, // xoris r2, r2, 0x2
    0x7C0004AC, // sync
    0x7C400124, // mtmsr r2
    0x7C0004AC, // sync
    0x7C5143A6, // mtsprg 1, r2
    // Label: L_8000474C:
    0x7C5242A6, // mfsprg r2, 2
    0x7C4FF120, // mtcrf 255, r2
    0x7C5142A6, // mfsprg r2, 1
    0x7C5143A6, // mtsprg 1, r2
    0x7C7243A6, // mtsprg 2, r3
    0x7C9343A6, // mtsprg 3, r4
    0x7C5A02A6, // mfsrr0 r2
    0x7C9B02A6, // mfsrr1 r4
    0x7C6000A6, // mfmsr r3
    0x60630030, // ori r3, r3, 0x30
    0x7C7B03A6, // mtsrr1 r3
    0x3C608001, // lis r3, 0x8001
    0x606375A8, // ori r3, r3, 0x75a8
    0x7C7A03A6, // mtsrr0 r3
    0x38601200, // li r3, 0x1200
    0x4C000064, // rfi
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x7C5143A6, // mtsprg 1, r2
    0x7C7243A6, // mtsprg 2, r3
    0x7C9343A6, // mtsprg 3, r4
    0x7C5A02A6, // mfsrr0 r2
    0x7C9B02A6, // mfsrr1 r4
    0x7C6000A6, // mfmsr r3
    0x60630030, // ori r3, r3, 0x30
    0x7C7B03A6, // mtsrr1 r3
    0x3C608001, // lis r3, 0x8001
    0x606375A8, // ori r3, r3, 0x75a8
    0x7C7A03A6, // mtsrr0 r3
    0x38601300, // li r3, 0x1300
    0x4C000064, // rfi
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x7C5143A6, // mtsprg 1, r2
    0x7C7243A6, // mtsprg 2, r3
    0x7C9343A6, // mtsprg 3, r4
    0x7C5A02A6, // mfsrr0 r2
    0x7C9B02A6, // mfsrr1 r4
    0x7C6000A6, // mfmsr r3
    0x60630030, // ori r3, r3, 0x30
    0x7C7B03A6, // mtsrr1 r3
    0x3C608001, // lis r3, 0x8001
    0x606375A8, // ori r3, r3, 0x75a8
    0x7C7A03A6, // mtsrr0 r3
    0x38601400, // li r3, 0x1400
    0x4C000064, // rfi
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x7C5143A6, // mtsprg 1, r2
    0x7C7243A6, // mtsprg 2, r3
    0x7C9343A6, // mtsprg 3, r4
    0x7C5A02A6, // mfsrr0 r2
    0x7C9B02A6, // mfsrr1 r4
    0x7C6000A6, // mfmsr r3
    0x60630030, // ori r3, r3, 0x30
    0x7C7B03A6, // mtsrr1 r3
    0x3C608001, // lis r3, 0x8001
    0x606375A8, // ori r3, r3, 0x75a8
    0x7C7A03A6, // mtsrr0 r3
    0x38601600, // li r3, 0x1600
    0x4C000064, // rfi
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x7C5143A6, // mtsprg 1, r2
    0x7C7243A6, // mtsprg 2, r3
    0x7C9343A6, // mtsprg 3, r4
    0x7C5A02A6, // mfsrr0 r2
    0x7C9B02A6, // mfsrr1 r4
    0x7C6000A6, // mfmsr r3
    0x60630030, // ori r3, r3, 0x30
    0x7C7B03A6, // mtsrr1 r3
    0x3C608001, // lis r3, 0x8001
    0x606375A8, // ori r3, r3, 0x75a8
    0x7C7A03A6, // mtsrr0 r3
    0x38601700, // li r3, 0x1700
    0x4C000064, // rfi
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x7C5143A6, // mtsprg 1, r2
    0x7C7243A6, // mtsprg 2, r3
    0x7C9343A6, // mtsprg 3, r4
    0x7C5A02A6, // mfsrr0 r2
    0x7C9B02A6, // mfsrr1 r4
    0x7C6000A6, // mfmsr r3
    0x60630030, // ori r3, r3, 0x30
    0x7C7B03A6, // mtsrr1 r3
    0x3C608001, // lis r3, 0x8001
    0x606375A8, // ori r3, r3, 0x75a8
    0x7C7A03A6, // mtsrr0 r3
    0x38601C00, // li r3, 0x1c00
    0x4C000064, // rfi
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x7C5143A6, // mtsprg 1, r2
    0x7C7243A6, // mtsprg 2, r3
    0x7C9343A6, // mtsprg 3, r4
    0x7C5A02A6, // mfsrr0 r2
    0x7C9B02A6, // mfsrr1 r4
    0x7C6000A6, // mfmsr r3
    0x60630030, // ori r3, r3, 0x30
    0x7C7B03A6, // mtsrr1 r3
    0x3C608001, // lis r3, 0x8001
    0x606375A8, // ori r3, r3, 0x75a8
    0x7C7A03A6, // mtsrr0 r3
    0x38601D00, // li r3, 0x1d00
    0x4C000064, // rfi
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x7C5143A6, // mtsprg 1, r2
    0x7C7243A6, // mtsprg 2, r3
    0x7C9343A6, // mtsprg 3, r4
    0x7C5A02A6, // mfsrr0 r2
    0x7C9B02A6, // mfsrr1 r4
    0x7C6000A6, // mfmsr r3
    0x60630030, // ori r3, r3, 0x30
    0x7C7B03A6, // mtsrr1 r3
    0x3C608001, // lis r3, 0x8001
    0x606375A8, // ori r3, r3, 0x75a8
    0x7C7A03A6, // mtsrr0 r3
    0x38601E00, // li r3, 0x1e00
    0x4C000064, // rfi
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x00000000, // .4byte 0x00000000 /* invalid */
    0x7C5143A6, // mtsprg 1, r2
    0x7C7243A6, // mtsprg 2, r3
    0x7C9343A6, // mtsprg 3, r4
    0x7C5A02A6, // mfsrr0 r2
    0x7C9B02A6, // mfsrr1 r4
    0x7C6000A6, // mfmsr r3
    0x60630030, // ori r3, r3, 0x30
    0x7C7B03A6, // mtsrr1 r3
    0x3C608001, // lis r3, 0x8001
    0x606375A8, // ori r3, r3, 0x75a8
    0x7C7A03A6, // mtsrr0 r3
    0x38601F00, // li r3, 0x1f00
    0x4C000064, // rfi
};
