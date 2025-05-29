#include "auto_00_80003100_init.h"
#include <stdint.h>
#include <stdio.h>

#include "gc_env.h"

// Function: __check_pad3
// Address: 0x80003100
void __check_pad3(void) {
    gc_env.r[0] = gc_env.lr; // Move from link register
    gc_env.r[3] = -32768 << 16; // lis r3, 0x8000
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
    OSResetSystem();
L_80003130:
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0xc);
    gc_env.r[1] += 8; // addi r1, r1, 0x8
    gc_env.lr = gc_env.r[0]; // Move to link register
    return;
}

// Function: __start
// Address: 0x80003140
void __start(void) {
    __init_registers();
    __init_hardware();
    gc_env.r[0] = -0x1;
    gc_mem_write32(gc_env.ram, gc_env.r[1] + -0x8, gc_env.r[1]);
    gc_env.r[1] = gc_env.r[1] + -0x8;
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x4, gc_env.r[0]);
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x0, gc_env.r[0]);
    __init_data();
    gc_env.r[0] = 0x0;
    gc_env.r[6] = -32768 << 16; // lis r6, 0x8000
    gc_env.r[6] += 68; // addi r6, r6, 0x44
    gc_mem_write32(gc_env.ram, gc_env.r[6] + 0x0, gc_env.r[0]);
    gc_env.r[6] = -32768 << 16; // lis r6, 0x8000
    gc_env.r[6] += 244; // addi r6, r6, 0xf4
    gc_env.r[6] = gc_mem_read32(gc_env.ram, gc_env.r[6] + 0x0);
    gc_env.cr[0] = ((uint32_t)gc_env.r[6] == 0x0) ? 0 : ((uint32_t)gc_env.r[6] < 0x0 ? -1 : 1); // Logical compare with immediate
    if (gc_env.cr[0] == 0) goto L_800031AC;
    gc_env.r[7] = gc_mem_read32(gc_env.ram, gc_env.r[6] + 0xc);
    gc_env.r[5] = 0x0;
    gc_env.cr[0] = ((uint32_t)gc_env.r[7] == 0x2) ? 0 : ((uint32_t)gc_env.r[7] < 0x2 ? -1 : 1); // Logical compare with immediate
    if (gc_env.cr[0] == 0) goto L_8000319C;
    gc_env.cr[0] = ((uint32_t)gc_env.r[7] == 0x3) ? 0 : ((uint32_t)gc_env.r[7] < 0x3 ? -1 : 1); // Logical compare with immediate
    if (gc_env.cr[0] != 0) goto L_800031AC;
    gc_env.r[5] = 0x1;
L_8000319C:
    //gc_env.r[6] = ((uint32_t)&InitMetroTRK >> 16) & 0xFFFF; // lis r6, InitMetroTRK@ha
    //gc_env.r[6] = gc_env.r[6] + ((uint32_t)&InitMetroTRK & 0xFFFF); // addi r6, r6, InitMetroTRK@l
    gc_env.lr = gc_env.r[6]; // Move to link register
    // Call function at gc_env.lr; // Branch to link register
L_800031AC:
    gc_env.r[6] = -32768 << 16; // lis r6, 0x8000
    gc_env.r[6] += 244; // addi r6, r6, 0xf4
    gc_env.r[5] = gc_mem_read32(gc_env.ram, gc_env.r[6] + 0x0);
    gc_env.cr[0] = ((uint32_t)gc_env.r[5] == 0x0) ? 0 : ((uint32_t)gc_env.r[5] < 0x0 ? -1 : 1); // Logical compare with immediate
    if (gc_env.cr[0] == 0) goto L_8000320C;
    gc_env.r[6] = gc_mem_read32(gc_env.ram, gc_env.r[5] + 0x8);
    gc_env.cr[0] = ((uint32_t)gc_env.r[6] == 0x0) ? 0 : ((uint32_t)gc_env.r[6] < 0x0 ? -1 : 1); // Logical compare with immediate
    if (gc_env.cr[0] == 0) goto L_8000320C;
    gc_env.r[6] = gc_env.r[5] + gc_env.r[6];
    gc_env.r[14] = gc_mem_read32(gc_env.ram, gc_env.r[6] + 0x0);
    gc_env.cr[0] = ((uint32_t)gc_env.r[14] == 0x0) ? 0 : ((uint32_t)gc_env.r[14] < 0x0 ? -1 : 1); // Logical compare with immediate
    if (gc_env.cr[0] == 0) goto L_8000320C;
    gc_env.r[15] = gc_env.r[6] + 4; // addi r15, r6, 0x4
    gc_env.ctr = gc_env.r[14]; // Move to count register
L_800031E4:
    gc_env.r[6] += 4; // addi r6, r6, 0x4
    gc_env.r[7] = gc_mem_read32(gc_env.ram, gc_env.r[6] + 0x0);
    gc_env.r[7] = gc_env.r[7] + gc_env.r[5];
    gc_mem_write32(gc_env.ram, gc_env.r[6] + 0x0, gc_env.r[7]);
    gc_env.ctr -= 1;
    if (gc_env.ctr != 0) goto L_800031E4;
    gc_env.r[5] = -32768 << 16; // lis r5, 0x8000
    gc_env.r[5] += 52; // addi r5, r5, 0x34
    gc_env.r[7] = gc_env.r[15] & ~((1ULL << 5) - 1); // Clear rightmost 5 bits
    gc_mem_write32(gc_env.ram, gc_env.r[5] + 0x0, gc_env.r[7]);
    goto L_80003214;
L_8000320C:
    gc_env.r[14] = 0x0;
    gc_env.r[15] = 0x0;
L_80003214:
    DBInit();
    OSInit();
    gc_env.r[4] = -32768 << 16; // lis r4, 0x8000
    gc_env.r[4] += 12518; // addi r4, r4, 0x30e6
    gc_env.r[3] = gc_mem_read16(gc_env.ram, gc_env.r[4] + 0x0);
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
    //goto exit;
}

// Function: __init_registers
// Address: 0x80003254
void __init_registers(void) {
    //gc_env.r[1] = ((uint32_t)&_stack_addr >> 16) & 0xFFFF; // lis r1, _stack_addr@h
    //gc_env.r[1] = gc_env.r[1] | ((uint32_t)&_stack_addr & 0xFFFF); // ori r1, r1, _stack_addr@l
    //gc_env.r[2] = ((uint32_t)&_SDA2_BASE_ >> 16) & 0xFFFF; // lis r2, _SDA2_BASE_@h
    //gc_env.r[2] = gc_env.r[2] | ((uint32_t)&_SDA2_BASE_ & 0xFFFF); // ori r2, r2, _SDA2_BASE_@l
    //gc_env.r[13] = ((uint32_t)&_SDA_BASE_ >> 16) & 0xFFFF; // lis r13, _SDA_BASE_@h
    //gc_env.r[13] = gc_env.r[13] | ((uint32_t)&_SDA_BASE_ & 0xFFFF); // ori r13, r13, _SDA_BASE_@l
    return;
}

// Function: __init_data
// Address: 0x80003270
void __init_data(void) {
    gc_env.r[0] = gc_env.lr; // Move from link register
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x4, gc_env.r[0]);
    gc_mem_write32(gc_env.ram, gc_env.r[1] + -0x18, gc_env.r[1]);
    gc_env.r[1] = gc_env.r[1] + -0x18;
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x14, gc_env.r[31]);
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x10, gc_env.r[30]);
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0xc, gc_env.r[29]);
    //gc_env.r[3] = ((uint32_t)&_rom_copy_info >> 16) & 0xFFFF; // lis r3, _rom_copy_info@ha
    //gc_env.r[0] = gc_env.r[3] + ((uint32_t)&_rom_copy_info & 0xFFFF); // addi r0, r3, _rom_copy_info@l
    gc_env.r[29] = gc_env.r[0]; // Move register
    goto L_80003298;
L_80003298:
    goto L_8000329C;
L_8000329C:
    gc_env.r[30] = gc_mem_read32(gc_env.ram, gc_env.r[29] + 0x8);
    gc_env.cr[0] = ((uint32_t)gc_env.r[30] == 0x0) ? 0 : ((uint32_t)gc_env.r[30] < 0x0 ? -1 : 1); // Logical compare with immediate
    if (gc_env.cr[0] == 0) goto L_800032DC;
    gc_env.r[4] = gc_mem_read32(gc_env.ram, gc_env.r[29] + 0x0);
    gc_env.r[31] = gc_mem_read32(gc_env.ram, gc_env.r[29] + 0x4);
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
    //gc_env.r[3] = ((uint32_t)&_bss_init_info >> 16) & 0xFFFF; // lis r3, _bss_init_info@ha
    //gc_env.r[0] = gc_env.r[3] + ((uint32_t)&_bss_init_info & 0xFFFF); // addi r0, r3, _bss_init_info@l
    gc_env.r[29] = gc_env.r[0]; // Move register
    goto L_800032EC;
L_800032EC:
    goto L_800032F0;
L_800032F0:
    gc_env.r[5] = gc_mem_read32(gc_env.ram, gc_env.r[29] + 0x4);
    gc_env.cr[0] = ((uint32_t)gc_env.r[5] == 0x0) ? 0 : ((uint32_t)gc_env.r[5] < 0x0 ? -1 : 1); // Logical compare with immediate
    if (gc_env.cr[0] == 0) goto L_80003314;
    gc_env.r[3] = gc_mem_read32(gc_env.ram, gc_env.r[29] + 0x0);
    if (gc_env.cr[0] == 0) goto L_8000330C;
    gc_env.r[4] = 0x0;
    memset();
L_8000330C:
    gc_env.r[29] += 8; // addi r29, r29, 0x8
    goto L_800032F0;
L_80003314:
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x1c);
    gc_env.r[31] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x14);
    gc_env.r[30] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x10);
    gc_env.r[29] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0xc);
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
    gc_env.r[3] = gc_env.r[3] - gc_env.r[5];
    gc_env.r[4] = gc_env.r[4] + gc_env.r[3];
L_80003364:
    // dcbst: Data cache block store (no-op in this context)
    // sync: Memory barrier (no-op in this context)
    // icbi: Instruction cache block invalidate (no-op in this context)
    gc_env.r[5] = gc_env.r[5] + 8;
    gc_env.xer = (gc_env.xer & ~0x20000000) | (((uint64_t)gc_env.r[5] + 8) > 0xFFFFFFFF ? 0x20000000 : 0);
    gc_env.r[4] = gc_env.r[4] - 8;
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
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x4, gc_env.r[0]);
    gc_mem_write32(gc_env.ram, gc_env.r[1] + -0x20, gc_env.r[1]);
    gc_env.r[1] = gc_env.r[1] + -0x20;
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x1c, gc_env.r[31]);
    gc_env.r[31] = gc_env.r[3]; // Move register
    //__fill_mem();
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x24);
    gc_env.r[3] = gc_env.r[31]; // Move register
    gc_env.r[31] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x1c);
    gc_env.r[1] += 32; // addi r1, r1, 0x20
    gc_env.lr = gc_env.r[0]; // Move to link register
    return;
}

int main() {
    return 0;
}
