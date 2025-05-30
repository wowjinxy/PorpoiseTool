#include "camera.h"
#include <stdint.h>
#include <stdio.h>

#include <math.h>

#include "gc_env.h"

// Function: Camera_80028B9C
void Camera_80028B9C(void) {
    gc_env.r[0] = gc_env.lr; // Move from link register
    gc_env.r[4] = ((uint32_t)&cm_803BCB18 >> 16) & 0xFFFF; // lis r4, cm_803BCB18@ha
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x4, gc_env.r[0]);
    gc_env.r[6] = gc_env.r[4] + ((uint32_t)&cm_803BCB18 & 0xFFFF); // addi r6, r4, cm_803BCB18@l
    gc_env.r[5] = ((uint32_t)&cm_80452C68 >> 16) & 0xFFFF; // lis r5, cm_80452C68@ha
    gc_mem_write32(gc_env.ram, gc_env.r[1] + -0x28, gc_env.r[1]);
    gc_env.r[1] = gc_env.r[1] + -0x28;
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x14, gc_env.r[27]); // stmw r27, 0x14(r1)
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x18, gc_env.r[28]); // stmw r27, 0x14(r1)
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x1C, gc_env.r[29]); // stmw r27, 0x14(r1)
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x20, gc_env.r[30]); // stmw r27, 0x14(r1)
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x24, gc_env.r[31]); // stmw r27, 0x14(r1)
    gc_env.r[31] = gc_env.r[5] + ((uint32_t)&cm_80452C68 & 0xFFFF); // addi r31, r5, cm_80452C68@l
    gc_env.r[27] = gc_env.r[3]; // Move register
    gc_env.r[30] = 0x0;
    gc_env.r[28] = gc_env.r[31] + 4; // addi r28, r31, 0x4
    gc_env.r[3] = gc_env.r[31] + 140; // addi r3, r31, 0x8c
    gc_env.r[4] = gc_mem_read32(gc_env.ram, gc_env.r[6] + 0x68);
    gc_env.r[7] = gc_env.r[4] + 4; // addi r7, r4, 0x4
    gc_env.r[4] = gc_mem_read32(gc_env.ram, gc_env.r[4] + 0x4);
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[7] + 0x4);
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x14, gc_env.r[4]);
    gc_env.r[4] = 0x224;
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x18, gc_env.r[0]);
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[7] + 0x8);
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x1c, gc_env.r[0]);
    gc_env.r[5] = gc_mem_read32(gc_env.ram, gc_env.r[7] + 0x0);
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[7] + 0x4);
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x20, gc_env.r[5]);
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x24, gc_env.r[0]);
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[7] + 0x8);
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x28, gc_env.r[0]);
    gc_env.r[5] = gc_mem_read32(gc_env.ram, gc_env.r[6] + 0x64);
    gc_env.r[8] = gc_env.r[5] + 4; // addi r8, r5, 0x4
    gc_env.r[5] = gc_mem_read32(gc_env.ram, gc_env.r[5] + 0x4);
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[8] + 0x4);
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x2c, gc_env.r[5]);
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x30, gc_env.r[0]);
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[8] + 0x8);
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x34, gc_env.r[0]);
    gc_env.r[5] = gc_mem_read32(gc_env.ram, gc_env.r[8] + 0x0);
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[8] + 0x4);
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x38, gc_env.r[5]);
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x3c, gc_env.r[0]);
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[8] + 0x8);
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x40, gc_env.r[0]);
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[6] + 0x7C); // lfs f0, 0x7C(r6)
    gc_env.f[0] = *(float*)&temp;
    float temp = (float)gc_env.f[0]; // stfs f0, 0x48(r31)
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x48, *(uint32_t*)&temp);
    float temp = (float)gc_env.f[0]; // stfs f0, 0x44(r31)
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x44, *(uint32_t*)&temp);
    gc_env.r[5] = gc_mem_read32(gc_env.ram, gc_env.r[7] + 0x0);
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[7] + 0x4);
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x4c, gc_env.r[5]);
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x50, gc_env.r[0]);
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[7] + 0x8);
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x54, gc_env.r[0]);
    gc_env.r[5] = gc_mem_read32(gc_env.ram, gc_env.r[7] + 0x0);
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[7] + 0x4);
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x58, gc_env.r[5]);
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x5c, gc_env.r[0]);
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[7] + 0x8);
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x60, gc_env.r[0]);
    gc_env.r[5] = gc_mem_read32(gc_env.ram, gc_env.r[8] + 0x0);
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[8] + 0x4);
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x64, gc_env.r[5]);
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x68, gc_env.r[0]);
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[8] + 0x8);
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x6c, gc_env.r[0]);
    gc_env.r[5] = gc_mem_read32(gc_env.ram, gc_env.r[8] + 0x0);
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[8] + 0x4);
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x70, gc_env.r[5]);
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x74, gc_env.r[0]);
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[8] + 0x8);
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x78, gc_env.r[0]);
    float temp = (float)gc_env.f[0]; // stfs f0, 0x80(r31)
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x80, *(uint32_t*)&temp);
    float temp = (float)gc_env.f[0]; // stfs f0, 0x7C(r31)
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x7C, *(uint32_t*)&temp);
    gc_mem_write8(gc_env.ram, gc_env.r[31] + 0xa, gc_env.r[30]);
    gc_mem_write8(gc_env.ram, gc_env.r[31] + 0x9, gc_env.r[30]);
    gc_mem_write8(gc_env.ram, gc_env.r[31] + 0x8, gc_env.r[30]);
    gc_env.f[0] = cm_804D7E08; // lfs f0, cm_804D7E08@sda21(r0)
    float temp = (float)gc_env.f[0]; // stfs f0, 0xC(r31)
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0xC, *(uint32_t*)&temp);
    gc_env.f[0] = cm_804D7E0C; // lfs f0, cm_804D7E0C@sda21(r0)
    float temp = (float)gc_env.f[0]; // stfs f0, 0x10(r31)
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x10, *(uint32_t*)&temp);
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x4, gc_env.r[30]);
    lb_8000C160();
    gc_env.f[0] = cm_804D7E04; // lfs f0, cm_804D7E04@sda21(r0)
    gc_env.r[29] = gc_env.r[31] + 921; // addi r29, r31, 0x399
    gc_env.r[3] = gc_env.r[31] + 896; // addi r3, r31, 0x380
    float temp = (float)gc_env.f[0]; // stfs f0, 0xAC(r31)
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0xAC, *(uint32_t*)&temp);
    gc_env.r[4] = 0x18;
    float temp = (float)gc_env.f[0]; // stfs f0, 0x2BC(r31)
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x2BC, *(uint32_t*)&temp);
    gc_env.f[0] = cm_804D7E10; // lfs f0, cm_804D7E10@sda21(r0)
    float temp = (float)gc_env.f[0]; // stfs f0, 0x2C0(r31)
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x2C0, *(uint32_t*)&temp);
    gc_env.r[0] = gc_mem_read8(gc_env.ram, gc_env.r[31] + 0x398);
    uint32_t rotated = gc_env.r[30] << 7; // rlwimi r0, r30, 7, 24, 24
    gc_env.r[0] = (gc_env.r[0] & ~0x80) | (rotated & 0x80);
    gc_mem_write8(gc_env.ram, gc_env.r[31] + 0x398, gc_env.r[0]);
    gc_env.r[0] = gc_mem_read8(gc_env.ram, gc_env.r[31] + 0x398);
    uint32_t rotated = gc_env.r[30] << 6; // rlwimi r0, r30, 6, 25, 25
    gc_env.r[0] = (gc_env.r[0] & ~0x40) | (rotated & 0x40);
    gc_mem_write8(gc_env.ram, gc_env.r[31] + 0x398, gc_env.r[0]);
    gc_env.r[0] = gc_mem_read8(gc_env.ram, gc_env.r[31] + 0x398);
    uint32_t rotated = gc_env.r[30] << 5; // rlwimi r0, r30, 5, 26, 26
    gc_env.r[0] = (gc_env.r[0] & ~0x20) | (rotated & 0x20);
    gc_mem_write8(gc_env.ram, gc_env.r[31] + 0x398, gc_env.r[0]);
    gc_env.r[0] = gc_mem_read8(gc_env.ram, gc_env.r[31] + 0x398);
    uint32_t rotated = gc_env.r[30] << 4; // rlwimi r0, r30, 4, 27, 27
    gc_env.r[0] = (gc_env.r[0] & ~0x10) | (rotated & 0x10);
    gc_mem_write8(gc_env.ram, gc_env.r[31] + 0x398, gc_env.r[0]);
    gc_env.r[0] = gc_mem_read8(gc_env.ram, gc_env.r[31] + 0x398);
    uint32_t rotated = gc_env.r[30] << 3; // rlwimi r0, r30, 3, 28, 28
    gc_env.r[0] = (gc_env.r[0] & ~0x8) | (rotated & 0x8);
    gc_mem_write8(gc_env.ram, gc_env.r[31] + 0x398, gc_env.r[0]);
    gc_env.r[0] = gc_mem_read8(gc_env.ram, gc_env.r[31] + 0x398);
    uint32_t rotated = gc_env.r[30] << 2; // rlwimi r0, r30, 2, 29, 29
    gc_env.r[0] = (gc_env.r[0] & ~0x4) | (rotated & 0x4);
    gc_mem_write8(gc_env.ram, gc_env.r[31] + 0x398, gc_env.r[0]);
    gc_env.r[0] = gc_mem_read8(gc_env.ram, gc_env.r[31] + 0x399);
    uint32_t rotated = gc_env.r[30] << 6; // rlwimi r0, r30, 6, 24, 25
    gc_env.r[0] = (gc_env.r[0] & ~0xC0) | (rotated & 0xC0);
    gc_mem_write8(gc_env.ram, gc_env.r[31] + 0x399, gc_env.r[0]);
    gc_env.r[0] = gc_mem_read8(gc_env.ram, gc_env.r[31] + 0x399);
    uint32_t rotated = gc_env.r[30] << 5; // rlwimi r0, r30, 5, 26, 26
    gc_env.r[0] = (gc_env.r[0] & ~0x20) | (rotated & 0x20);
    gc_mem_write8(gc_env.ram, gc_env.r[31] + 0x399, gc_env.r[0]);
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[28] + 0x0);
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x39c, gc_env.r[0]);
    gc_env.r[0] = gc_mem_read8(gc_env.ram, gc_env.r[31] + 0x399);
    uint32_t rotated = gc_env.r[30] << 4; // rlwimi r0, r30, 4, 27, 27
    gc_env.r[0] = (gc_env.r[0] & ~0x10) | (rotated & 0x10);
    gc_mem_write8(gc_env.ram, gc_env.r[31] + 0x399, gc_env.r[0]);
    gc_env.r[0] = gc_mem_read8(gc_env.ram, gc_env.r[31] + 0x399);
    uint32_t rotated = gc_env.r[30] << 3; // rlwimi r0, r30, 3, 28, 28
    gc_env.r[0] = (gc_env.r[0] & ~0x8) | (rotated & 0x8);
    gc_mem_write8(gc_env.ram, gc_env.r[31] + 0x399, gc_env.r[0]);
    gc_env.r[0] = gc_mem_read8(gc_env.ram, gc_env.r[31] + 0x399);
    uint32_t rotated = gc_env.r[30] << 2; // rlwimi r0, r30, 2, 29, 29
    gc_env.r[0] = (gc_env.r[0] & ~0x4) | (rotated & 0x4);
    gc_mem_write8(gc_env.ram, gc_env.r[31] + 0x399, gc_env.r[0]);
    gc_env.r[0] = gc_mem_read8(gc_env.ram, gc_env.r[31] + 0x399);
    uint32_t rotated = gc_env.r[30] << 1; // rlwimi r0, r30, 1, 30, 30
    gc_env.r[0] = (gc_env.r[0] & ~0x2) | (rotated & 0x2);
    gc_mem_write8(gc_env.ram, gc_env.r[31] + 0x399, gc_env.r[0]);
    lb_8000C160();
    gc_env.r[0] = gc_mem_read8(gc_env.ram, gc_env.r[29] + 0x0);
    uint32_t rotated = gc_env.r[30] << 0; // rlwimi r0, r30, 0, 31, 31
    gc_env.r[0] = (gc_env.r[0] & ~0x1) | (rotated & 0x1);
    gc_env.r[28] = gc_env.r[27] * 108;
    gc_mem_write8(gc_env.ram, gc_env.r[29] + 0x0, gc_env.r[0]);
    gc_env.r[0] = gc_mem_read8(gc_env.ram, gc_env.r[31] + 0x39a);
    uint32_t rotated = gc_env.r[30] << 7; // rlwimi r0, r30, 7, 24, 24
    gc_env.r[0] = (gc_env.r[0] & ~0x80) | (rotated & 0x80);
    gc_env.r[3] = gc_env.r[28] + 0; // addi r3, r28, 0x0
    gc_mem_write8(gc_env.ram, gc_env.r[31] + 0x39a, gc_env.r[0]);
    gc_env.r[0] = gc_mem_read8(gc_env.ram, gc_env.r[31] + 0x39a);
    uint32_t rotated = gc_env.r[30] << 6; // rlwimi r0, r30, 6, 25, 25
    gc_env.r[0] = (gc_env.r[0] & ~0x40) | (rotated & 0x40);
    gc_mem_write8(gc_env.ram, gc_env.r[31] + 0x39a, gc_env.r[0]);
    gc_env.r[0] = gc_mem_read8(gc_env.ram, gc_env.r[31] + 0x39a);
    uint32_t rotated = gc_env.r[30] << 5; // rlwimi r0, r30, 5, 26, 26
    gc_env.r[0] = (gc_env.r[0] & ~0x20) | (rotated & 0x20);
    gc_mem_write8(gc_env.ram, gc_env.r[31] + 0x39a, gc_env.r[0]);
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x0, gc_env.r[30]);
    HSD_MemAlloc();
    gc_mem_write32(gc_env.ram, gc_env.r[0] + cm_804D6458@sda21, gc_env.r[3]);
    gc_env.r[4] = gc_env.r[28]; // Move register
    gc_mem_write32(gc_env.ram, gc_env.r[0] + cm_804D645C@sda21, gc_env.r[3]);
    gc_env.r[3] = gc_mem_read32(gc_env.ram, gc_env.r[0] + cm_804D6458@sda21);
    lb_8000C160();
    gc_env.r[0] = gc_env.r[27] - 1;
    gc_env.xer = (gc_env.xer & ~0x20000000) | (gc_env.r[27] >= 1 ? 0x20000000 : 0);
    gc_env.cr[0] = (gc_env.r[0] == 0) ? 0x2 : ((int32_t)gc_env.r[0] < 0 ? 0x8 : 0x4);
    gc_env.r[3] = 0x0;
    if (gc_env.cr[0] & (0x8 | 0x2)) goto L_80028F20; // ble .L_80028F20
    gc_env.r[0] = gc_env.r[27] - 1;
    gc_env.cr[0] = (gc_env.r[0] == 0x8) ? 0 : (gc_env.r[0] < 0x8 ? -1 : 1); // Compare with immediate
    gc_env.r[4] = gc_env.r[27] - 9;
    if (gc_env.cr[0] & (0x8 | 0x2)) goto L_80028F40; // ble .L_80028F40
    gc_env.r[0] = gc_env.r[4] + 7; // addi r0, r4, 0x7
    gc_env.r[0] = gc_env.r[0] >> 3; // srwi r0, r0, 3
    gc_env.cr[0] = (gc_env.r[4] == 0x0) ? 0 : (gc_env.r[4] < 0x0 ? -1 : 1); // Compare with immediate
    gc_env.ctr = gc_env.r[0]; // Move to count register
    if (gc_env.cr[0] & (0x8 | 0x2)) goto L_80028F40; // ble .L_80028F40
    L_80028E18:
    gc_env.r[0] = gc_env.r[3] + 1; // addi r0, r3, 0x1
    gc_env.r[5] = gc_mem_read32(gc_env.ram, gc_env.r[0] + cm_804D645C@sda21);
    gc_env.r[0] = gc_env.r[0] * 108;
    gc_env.r[4] = gc_env.r[5] + gc_env.r[0];
    gc_env.r[0] = gc_env.r[30] + 4; // addi r0, r30, 0x4
    gc_mem_write32(gc_env.ram, gc_env.r[5] + gc_env.r[0], gc_env.r[4]); // stwx r4, r5, r0
    gc_env.r[0] = gc_env.r[3] + 2; // addi r0, r3, 0x2
    gc_env.r[4] = gc_env.r[0] * 108;
    gc_env.r[6] = gc_mem_read32(gc_env.ram, gc_env.r[0] + cm_804D645C@sda21);
    gc_env.r[0] = gc_env.r[3] + 3; // addi r0, r3, 0x3
    gc_env.r[5] = gc_env.r[6] + gc_env.r[4];
    gc_env.r[4] = gc_env.r[30] + 112; // addi r4, r30, 0x70
    gc_mem_write32(gc_env.ram, gc_env.r[6] + gc_env.r[4], gc_env.r[5]); // stwx r5, r6, r4
    gc_env.r[4] = gc_env.r[0] * 108;
    gc_env.r[6] = gc_mem_read32(gc_env.ram, gc_env.r[0] + cm_804D645C@sda21);
    gc_env.r[0] = gc_env.r[3] + 4; // addi r0, r3, 0x4
    gc_env.r[5] = gc_env.r[6] + gc_env.r[4];
    gc_env.r[4] = gc_env.r[30] + 220; // addi r4, r30, 0xdc
    gc_mem_write32(gc_env.ram, gc_env.r[6] + gc_env.r[4], gc_env.r[5]); // stwx r5, r6, r4
    gc_env.r[4] = gc_env.r[0] * 108;
    gc_env.r[6] = gc_mem_read32(gc_env.ram, gc_env.r[0] + cm_804D645C@sda21);
    gc_env.r[0] = gc_env.r[3] + 5; // addi r0, r3, 0x5
    gc_env.r[5] = gc_env.r[6] + gc_env.r[4];
    gc_env.r[4] = gc_env.r[30] + 328; // addi r4, r30, 0x148
    gc_mem_write32(gc_env.ram, gc_env.r[6] + gc_env.r[4], gc_env.r[5]); // stwx r5, r6, r4
    gc_env.r[4] = gc_env.r[3] + 6; // addi r4, r3, 0x6
    gc_env.r[0] = gc_env.r[0] * 108;
    gc_env.r[6] = gc_mem_read32(gc_env.ram, gc_env.r[0] + cm_804D645C@sda21);
    gc_env.r[5] = gc_env.r[6] + gc_env.r[0];
    gc_env.r[0] = gc_env.r[30] + 436; // addi r0, r30, 0x1b4
    gc_mem_write32(gc_env.ram, gc_env.r[6] + gc_env.r[0], gc_env.r[5]); // stwx r5, r6, r0
    gc_env.r[0] = gc_env.r[3] + 7; // addi r0, r3, 0x7
    gc_env.r[5] = gc_env.r[4] * 108;
    gc_env.r[7] = gc_mem_read32(gc_env.ram, gc_env.r[0] + cm_804D645C@sda21);
    gc_env.r[4] = gc_env.r[3] + 8; // addi r4, r3, 0x8
    gc_env.r[6] = gc_env.r[7] + gc_env.r[5];
    gc_env.r[5] = gc_env.r[30] + 544; // addi r5, r30, 0x220
    gc_mem_write32(gc_env.ram, gc_env.r[7] + gc_env.r[5], gc_env.r[6]); // stwx r6, r7, r5
    gc_env.r[5] = gc_env.r[0] * 108;
    gc_env.r[6] = gc_mem_read32(gc_env.ram, gc_env.r[0] + cm_804D645C@sda21);
    gc_env.r[0] = gc_env.r[30] + 652; // addi r0, r30, 0x28c
    gc_env.r[5] = gc_env.r[6] + gc_env.r[5];
    gc_mem_write32(gc_env.ram, gc_env.r[6] + gc_env.r[0], gc_env.r[5]); // stwx r5, r6, r0
    gc_env.r[0] = gc_env.r[30] + 760; // addi r0, r30, 0x2f8
    gc_env.r[4] = gc_env.r[4] * 108;
    gc_env.r[5] = gc_mem_read32(gc_env.ram, gc_env.r[0] + cm_804D645C@sda21);
    gc_env.r[4] = gc_env.r[5] + gc_env.r[4];
    gc_mem_write32(gc_env.ram, gc_env.r[5] + gc_env.r[0], gc_env.r[4]); // stwx r4, r5, r0
    gc_env.r[30] += 864; // addi r30, r30, 0x360
    gc_env.r[3] += 8; // addi r3, r3, 0x8
    gc_env.ctr -= 1;
    if (gc_env.ctr != 0) goto L_80028E18;
    goto L_80028F40;
    L_80028EE8:
    gc_env.r[4] = gc_env.r[27] - 1;
    gc_env.r[0] = gc_env.r[4] - gc_env.r[3];
    gc_env.cr[0] = (int32_t)gc_env.r[3] < (int32_t)gc_env.r[4] ? 0x8 : ((int32_t)gc_env.r[3] > (int32_t)gc_env.r[4] ? 0x4 : 0x2); // cmpw r3, r4
    gc_env.ctr = gc_env.r[0]; // Move to count register
    if (gc_env.cr[0] >= 0) goto L_80028F20;
    L_80028EFC:
    gc_env.r[0] = gc_env.r[3] + 1; // addi r0, r3, 0x1
    gc_env.r[6] = gc_mem_read32(gc_env.ram, gc_env.r[0] + cm_804D645C@sda21);
    gc_env.r[4] = gc_env.r[0] * 108;
    gc_env.r[0] = gc_env.r[5] + 4; // addi r0, r5, 0x4
    gc_env.r[4] = gc_env.r[6] + gc_env.r[4];
    gc_mem_write32(gc_env.ram, gc_env.r[6] + gc_env.r[0], gc_env.r[4]); // stwx r4, r6, r0
    gc_env.r[5] += 108; // addi r5, r5, 0x6c
    gc_env.r[3] += 1; // addi r3, r3, 0x1
    gc_env.ctr -= 1;
    if (gc_env.ctr != 0) goto L_80028EFC;
    L_80028F20:
    gc_env.r[0] = gc_env.r[3] * 108;
    gc_env.r[3] = gc_mem_read32(gc_env.ram, gc_env.r[0] + cm_804D645C@sda21);
    gc_env.r[3] = gc_env.r[3] + gc_env.r[0];
    gc_env.r[0] = 0x0;
    gc_mem_write32(gc_env.ram, gc_env.r[3] + 0x4, gc_env.r[0]);
    gc_mem_write32(gc_env.ram, gc_env.r[0] + cm_804D6460@sda21, gc_env.r[0]);
    gc_mem_write32(gc_env.ram, gc_env.r[0] + cm_804D6468@sda21, gc_env.r[0]);
    goto L_80028F48;
    L_80028F40:
    gc_env.r[5] = gc_env.r[3] * 108;
    goto L_80028EE8;
    L_80028F48:
    gc_env.r[27] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x14); // lmw r27, 0x14(r1)
    gc_env.r[28] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x18); // lmw r27, 0x14(r1)
    gc_env.r[29] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x1C); // lmw r27, 0x14(r1)
    gc_env.r[30] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x20); // lmw r27, 0x14(r1)
    gc_env.r[31] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x24); // lmw r27, 0x14(r1)
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x2c);
    gc_env.r[1] += 40; // addi r1, r1, 0x28
    gc_env.lr = gc_env.r[0]; // Move to link register
    return;
}

// Function: Camera_80028F5C
void Camera_80028F5C(void) {
    gc_env.cr[0] = ((uint32_t)gc_env.r[3] == 0x0) ? 0 : ((uint32_t)gc_env.r[3] < 0x0 ? -1 : 1); // Logical compare with immediate
    if (gc_env.cr[0] & 0x2) return; // beqlr
    gc_mem_write32(gc_env.ram, gc_env.r[3] + 0x8, gc_env.r[4]);
    gc_env.r[4] = 0x0;
    gc_env.f[2] = cm_804D7E14; // lfs f2, cm_804D7E14@sda21(r0)
    float temp = (float)gc_env.f[2]; // stfs f2, 0x18(r3)
    gc_mem_write32(gc_env.ram, gc_env.r[3] + 0x18, *(uint32_t*)&temp);
    float temp = (float)gc_env.f[2]; // stfs f2, 0x14(r3)
    gc_mem_write32(gc_env.ram, gc_env.r[3] + 0x14, *(uint32_t*)&temp);
    float temp = (float)gc_env.f[2]; // stfs f2, 0x10(r3)
    gc_mem_write32(gc_env.ram, gc_env.r[3] + 0x10, *(uint32_t*)&temp);
    gc_env.r[5] = gc_mem_read32(gc_env.ram, gc_env.r[3] + 0x10);
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[3] + 0x14);
    gc_mem_write32(gc_env.ram, gc_env.r[3] + 0x1c, gc_env.r[5]);
    gc_mem_write32(gc_env.ram, gc_env.r[3] + 0x20, gc_env.r[0]);
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[3] + 0x18);
    gc_mem_write32(gc_env.ram, gc_env.r[3] + 0x24, gc_env.r[0]);
    float temp = (float)gc_env.f[2]; // stfs f2, 0x28(r3)
    gc_mem_write32(gc_env.ram, gc_env.r[3] + 0x28, *(uint32_t*)&temp);
    gc_env.r[0] = gc_mem_read8(gc_env.ram, gc_env.r[3] + 0xc);
    uint32_t rotated = gc_env.r[4] << 7; // rlwimi r0, r4, 7, 24, 24
    gc_env.r[0] = (gc_env.r[0] & ~0x80) | (rotated & 0x80);
    gc_mem_write8(gc_env.ram, gc_env.r[3] + 0xc, gc_env.r[0]);
    gc_env.r[0] = gc_mem_read8(gc_env.ram, gc_env.r[3] + 0xc);
    uint32_t rotated = gc_env.r[4] << 6; // rlwimi r0, r4, 6, 25, 25
    gc_env.r[0] = (gc_env.r[0] & ~0x40) | (rotated & 0x40);
    gc_mem_write8(gc_env.ram, gc_env.r[3] + 0xc, gc_env.r[0]);
    gc_env.r[0] = gc_mem_read8(gc_env.ram, gc_env.r[3] + 0xc);
    uint32_t rotated = gc_env.r[4] << 5; // rlwimi r0, r4, 5, 26, 26
    gc_env.r[0] = (gc_env.r[0] & ~0x20) | (rotated & 0x20);
    gc_mem_write8(gc_env.ram, gc_env.r[3] + 0xc, gc_env.r[0]);
    gc_mem_write16(gc_env.ram, gc_env.r[3] + 0xe, gc_env.r[4]);
    gc_env.f[1] = cm_804D7E10; // lfs f1, cm_804D7E10@sda21(r0)
    float temp = (float)gc_env.f[1]; // stfs f1, 0x2C(r3)
    gc_mem_write32(gc_env.ram, gc_env.r[3] + 0x2C, *(uint32_t*)&temp);
    gc_env.f[0] = cm_804D7E04; // lfs f0, cm_804D7E04@sda21(r0)
    float temp = (float)gc_env.f[0]; // stfs f0, 0x30(r3)
    gc_mem_write32(gc_env.ram, gc_env.r[3] + 0x30, *(uint32_t*)&temp);
    float temp = (float)gc_env.f[0]; // stfs f0, 0x34(r3)
    gc_mem_write32(gc_env.ram, gc_env.r[3] + 0x34, *(uint32_t*)&temp);
    float temp = (float)gc_env.f[1]; // stfs f1, 0x38(r3)
    gc_mem_write32(gc_env.ram, gc_env.r[3] + 0x38, *(uint32_t*)&temp);
    float temp = (float)gc_env.f[0]; // stfs f0, 0x3C(r3)
    gc_mem_write32(gc_env.ram, gc_env.r[3] + 0x3C, *(uint32_t*)&temp);
    gc_env.r[4] = gc_mem_read32(gc_env.ram, gc_env.r[3] + 0x2c);
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[3] + 0x30);
    gc_mem_write32(gc_env.ram, gc_env.r[3] + 0x40, gc_env.r[4]);
    gc_mem_write32(gc_env.ram, gc_env.r[3] + 0x44, gc_env.r[0]);
    gc_env.r[4] = gc_mem_read32(gc_env.ram, gc_env.r[3] + 0x34);
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[3] + 0x38);
    gc_mem_write32(gc_env.ram, gc_env.r[3] + 0x48, gc_env.r[4]);
    gc_mem_write32(gc_env.ram, gc_env.r[3] + 0x4c, gc_env.r[0]);
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[3] + 0x3c);
    gc_mem_write32(gc_env.ram, gc_env.r[3] + 0x50, gc_env.r[0]);
    float temp = (float)gc_env.f[2]; // stfs f2, 0x54(r3)
    gc_mem_write32(gc_env.ram, gc_env.r[3] + 0x54, *(uint32_t*)&temp);
    float temp = (float)gc_env.f[2]; // stfs f2, 0x58(r3)
    gc_mem_write32(gc_env.ram, gc_env.r[3] + 0x58, *(uint32_t*)&temp);
    float temp = (float)gc_env.f[2]; // stfs f2, 0x5C(r3)
    gc_mem_write32(gc_env.ram, gc_env.r[3] + 0x5C, *(uint32_t*)&temp);
    float temp = (float)gc_env.f[2]; // stfs f2, 0x60(r3)
    gc_mem_write32(gc_env.ram, gc_env.r[3] + 0x60, *(uint32_t*)&temp);
    float temp = (float)gc_env.f[2]; // stfs f2, 0x64(r3)
    gc_mem_write32(gc_env.ram, gc_env.r[3] + 0x64, *(uint32_t*)&temp);
    float temp = (float)gc_env.f[2]; // stfs f2, 0x68(r3)
    gc_mem_write32(gc_env.ram, gc_env.r[3] + 0x68, *(uint32_t*)&temp);
    return;
}

// Function: Camera_80029020
void Camera_80029020(void) {
    gc_env.r[0] = gc_env.lr; // Move from link register
    gc_env.r[3] = 0x0;
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x4, gc_env.r[0]);
    gc_mem_write32(gc_env.ram, gc_env.r[1] + -0x8, gc_env.r[1]);
    gc_env.r[1] = gc_env.r[1] + -0x8;
    Camera_80029044();
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0xc);
    gc_env.r[1] += 8; // addi r1, r1, 0x8
    gc_env.lr = gc_env.r[0]; // Move to link register
    return;
}

// Function: Camera_80029044
void Camera_80029044(void) {
    gc_env.r[0] = gc_env.lr; // Move from link register
    gc_env.r[4] = gc_env.r[3] + 0; // addi r4, r3, 0x0
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x4, gc_env.r[0]);
    gc_mem_write32(gc_env.ram, gc_env.r[1] + -0x18, gc_env.r[1]);
    gc_env.r[1] = gc_env.r[1] + -0x18;
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x14, gc_env.r[31]);
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[0] + cm_804D6458@sda21);
    gc_env.cr[0] = ((uint32_t)gc_env.r[0] == 0x0) ? 0 : ((uint32_t)gc_env.r[0] < 0x0 ? -1 : 1); // Logical compare with immediate
    gc_env.r[31] = gc_env.r[0]; // Move register
    if (gc_env.cr[0] != 0) goto L_8002907C;
    gc_env.r[3] = ((uint32_t)&cm_803BCBB0 >> 16) & 0xFFFF; // lis r3, cm_803BCBB0@ha
    gc_env.cr[1] &= ~0x2; // crclr cr1eq
    gc_env.r[3] = gc_env.r[3] + ((uint32_t)&cm_803BCBB0 & 0xFFFF); // addi r3, r3, cm_803BCBB0@l
    OSReport();
    L_80029078:
    goto L_80029078;
    L_8002907C:
    gc_env.r[3] = gc_mem_read32(gc_env.ram, gc_env.r[31] + 0x4);
    gc_env.r[0] = 0x0;
    gc_mem_write32(gc_env.ram, gc_env.r[0] + cm_804D6458@sda21, gc_env.r[3]);
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x0, gc_env.r[0]);
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[0] + cm_804D6460@sda21);
    gc_env.cr[0] = ((uint32_t)gc_env.r[0] == 0x0) ? 0 : ((uint32_t)gc_env.r[0] < 0x0 ? -1 : 1); // Logical compare with immediate
    if (gc_env.cr[0] == 0) goto L_800290A4;
    gc_env.r[3] = gc_mem_read32(gc_env.ram, gc_env.r[0] + cm_804D6468@sda21);
    gc_mem_write32(gc_env.ram, gc_env.r[3] + 0x0, gc_env.r[31]);
    goto L_800290A8;
    L_800290A4:
    gc_mem_write32(gc_env.ram, gc_env.r[0] + cm_804D6460@sda21, gc_env.r[31]);
    L_800290A8:
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[0] + cm_804D6468@sda21);
    gc_env.r[3] = gc_env.r[31]; // Move register
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x4, gc_env.r[0]);
    gc_mem_write32(gc_env.ram, gc_env.r[0] + cm_804D6468@sda21, gc_env.r[31]);
    Camera_80028F5C();
    gc_env.r[3] = gc_env.r[31]; // Move register
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x1c);
    gc_env.r[31] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x14);
    gc_env.r[1] += 24; // addi r1, r1, 0x18
    gc_env.lr = gc_env.r[0]; // Move to link register
    return;
}

// Function: Camera_800290D4
void Camera_800290D4(void) {
    gc_env.r[4] = gc_mem_read32(gc_env.ram, gc_env.r[3] + 0x0);
    gc_env.cr[0] = ((uint32_t)gc_env.r[4] == 0x0) ? 0 : ((uint32_t)gc_env.r[4] < 0x0 ? -1 : 1); // Logical compare with immediate
    if (gc_env.cr[0] == 0) goto L_800290EC;
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[3] + 0x4);
    gc_mem_write32(gc_env.ram, gc_env.r[4] + 0x4, gc_env.r[0]);
    goto L_800290F4;
    L_800290EC:
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[3] + 0x4);
    gc_mem_write32(gc_env.ram, gc_env.r[0] + cm_804D6468@sda21, gc_env.r[0]);
    L_800290F4:
    gc_env.r[4] = gc_mem_read32(gc_env.ram, gc_env.r[3] + 0x4);
    gc_env.cr[0] = ((uint32_t)gc_env.r[4] == 0x0) ? 0 : ((uint32_t)gc_env.r[4] < 0x0 ? -1 : 1); // Logical compare with immediate
    if (gc_env.cr[0] == 0) goto L_8002910C;
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[3] + 0x0);
    gc_mem_write32(gc_env.ram, gc_env.r[4] + 0x0, gc_env.r[0]);
    goto L_80029114;
    L_8002910C:
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[3] + 0x0);
    gc_mem_write32(gc_env.ram, gc_env.r[0] + cm_804D6460@sda21, gc_env.r[0]);
    L_80029114:
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[0] + cm_804D6458@sda21);
    gc_mem_write32(gc_env.ram, gc_env.r[3] + 0x4, gc_env.r[0]);
    gc_mem_write32(gc_env.ram, gc_env.r[0] + cm_804D6458@sda21, gc_env.r[3]);
    return;
}

// Function: Camera_80029124
void Camera_80029124(void) {
    gc_env.r[0] = gc_env.lr; // Move from link register
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x4, gc_env.r[0]);
    gc_mem_write32(gc_env.ram, gc_env.r[1] + -0x50, gc_env.r[1]);
    gc_env.r[1] = gc_env.r[1] + -0x50;
    uint64_t temp;
    memcpy(&temp, &gc_env.f[31], sizeof(double));
    gc_mem_write64(gc_env.ram, gc_env.r[1] + 0x48, temp); // stfd f31, 0x48(r1)
    uint64_t temp;
    memcpy(&temp, &gc_env.f[30], sizeof(double));
    gc_mem_write64(gc_env.ram, gc_env.r[1] + 0x40, temp); // stfd f30, 0x40(r1)
    uint64_t temp;
    memcpy(&temp, &gc_env.f[29], sizeof(double));
    gc_mem_write64(gc_env.ram, gc_env.r[1] + 0x38, temp); // stfd f29, 0x38(r1)
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x34, gc_env.r[31]);
    gc_env.r[31] = 0x0;
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x30, gc_env.r[30]);
    gc_env.r[30] = gc_env.r[4] + 0; // addi r30, r4, 0x0
    gc_env.r[4] = gc_env.r[1] + 16; // addi r4, r1, 0x10
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x2c, gc_env.r[29]);
    gc_env.r[29] = gc_env.r[3] + 0; // addi r29, r3, 0x0
    gc_env.r[3] = gc_env.r[1] + 20; // addi r3, r1, 0x14
    Ground_801C4368();
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x14); // lfs f1, 0x14(r1)
    gc_env.f[1] = *(float*)&temp;
    gc_env.d[0] = cm_804D7E18; // lfd f0, cm_804D7E18@sda21(r0)
    gc_env.f[0] = gc_env.f[1] + gc_env.f[0]; // fadd f0, f1, f0
    gc_env.f[0] = (float)gc_env.f[0]; // frsp f0, f0
    float temp = (float)gc_env.f[0]; // stfs f0, 0x14(r1)
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x14, *(uint32_t*)&temp);
    Stage_GetCamBoundsLeftOffset();
    gc_env.f[29] = gc_env.f[1]; // fmr f29, f1
    Stage_GetCamBoundsRightOffset();
    gc_env.f[30] = gc_env.f[1]; // fmr f30, f1
    Stage_GetCamBoundsTopOffset();
    gc_env.f[31] = gc_env.f[1]; // fmr f31, f1
    Stage_GetCamBoundsBottomOffset();
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x14); // lfs f0, 0x14(r1)
    gc_env.f[0] = *(float*)&temp;
    gc_env.cr[0] = isnan(gc_env.f[1]) || isnan(gc_env.f[0]) ? 0x1 : (gc_env.f[1] < gc_env.f[0] ? 0x8 : (gc_env.f[1] > gc_env.f[0] ? 0x4 : 0x2)); // fcmpo cr0, f1, f0
    if (gc_env.cr[0] & (0x8 | 0x2)) goto L_800291A4; // ble .L_800291A4
    Stage_GetCamBoundsBottomOffset();
    goto L_800291A8;
    L_800291A4:
    gc_env.f[1] = gc_env.f[0]; // fmr f1, f0
    L_800291A8:
    gc_env.r[0] = gc_env.r[30] ^ 0x80000000; // xoris r0, r30, 0x8000
    gc_env.d[2] = cm_804D7E20; // lfd f2, cm_804D7E20@sda21(r0)
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x24, gc_env.r[0]);
    gc_env.r[0] = 17200 << 16; // lis r0, 0x4330
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[29] + 0x0); // lfs f3, 0x0(r29)
    gc_env.f[3] = *(float*)&temp;
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x20, gc_env.r[0]);
    uint64_t temp = gc_mem_read64(gc_env.ram, gc_env.r[1] + 0x20); // lfd f0, 0x20(r1)
    gc_env.d[0] = *(double*)&temp;
    gc_env.f[0] = (float)gc_env.f[0] - (float)gc_env.f[2]; // fsubs f0, f0, f2
    gc_env.f[0] = (float)gc_env.f[29] - (float)gc_env.f[0]; // fsubs f0, f29, f0
    gc_env.cr[0] = isnan(gc_env.f[3]) || isnan(gc_env.f[0]) ? 0x1 : (gc_env.f[3] < gc_env.f[0] ? 0x8 : (gc_env.f[3] > gc_env.f[0] ? 0x4 : 0x2)); // fcmpo cr0, f3, f0
    if (gc_env.cr[0] >= 0) goto L_800291D8;
    gc_env.r[31] |= 4; // ori r31, r31, 0x4
    L_800291D8:
    gc_env.r[0] = gc_env.r[30] ^ 0x80000000; // xoris r0, r30, 0x8000
    gc_env.d[2] = cm_804D7E20; // lfd f2, cm_804D7E20@sda21(r0)
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x24, gc_env.r[0]);
    gc_env.r[0] = 17200 << 16; // lis r0, 0x4330
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x20, gc_env.r[0]);
    uint64_t temp = gc_mem_read64(gc_env.ram, gc_env.r[1] + 0x20); // lfd f0, 0x20(r1)
    gc_env.d[0] = *(double*)&temp;
    gc_env.f[0] = (float)gc_env.f[0] - (float)gc_env.f[2]; // fsubs f0, f0, f2
    gc_env.f[0] = (float)gc_env.f[30] + (float)gc_env.f[0]; // fadds f0, f30, f0
    gc_env.cr[0] = isnan(gc_env.f[3]) || isnan(gc_env.f[0]) ? 0x1 : (gc_env.f[3] < gc_env.f[0] ? 0x8 : (gc_env.f[3] > gc_env.f[0] ? 0x4 : 0x2)); // fcmpo cr0, f3, f0
    if (gc_env.cr[0] & (0x8 | 0x2)) goto L_80029204; // ble .L_80029204
    gc_env.r[31] |= 8; // ori r31, r31, 0x8
    L_80029204:
    gc_env.r[0] = gc_env.r[30] ^ 0x80000000; // xoris r0, r30, 0x8000
    gc_env.d[2] = cm_804D7E20; // lfd f2, cm_804D7E20@sda21(r0)
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x24, gc_env.r[0]);
    gc_env.r[0] = 17200 << 16; // lis r0, 0x4330
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[29] + 0x4); // lfs f3, 0x4(r29)
    gc_env.f[3] = *(float*)&temp;
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x20, gc_env.r[0]);
    uint64_t temp = gc_mem_read64(gc_env.ram, gc_env.r[1] + 0x20); // lfd f0, 0x20(r1)
    gc_env.d[0] = *(double*)&temp;
    gc_env.f[0] = (float)gc_env.f[0] - (float)gc_env.f[2]; // fsubs f0, f0, f2
    gc_env.f[0] = (float)gc_env.f[31] + (float)gc_env.f[0]; // fadds f0, f31, f0
    gc_env.cr[0] = isnan(gc_env.f[3]) || isnan(gc_env.f[0]) ? 0x1 : (gc_env.f[3] < gc_env.f[0] ? 0x8 : (gc_env.f[3] > gc_env.f[0] ? 0x4 : 0x2)); // fcmpo cr0, f3, f0
    if (gc_env.cr[0] & (0x8 | 0x2)) goto L_80029234; // ble .L_80029234
    gc_env.r[31] |= 1; // ori r31, r31, 0x1
    L_80029234:
    gc_env.r[0] = gc_env.r[30] ^ 0x80000000; // xoris r0, r30, 0x8000
    gc_env.d[2] = cm_804D7E20; // lfd f2, cm_804D7E20@sda21(r0)
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x24, gc_env.r[0]);
    gc_env.r[0] = 17200 << 16; // lis r0, 0x4330
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x20, gc_env.r[0]);
    uint64_t temp = gc_mem_read64(gc_env.ram, gc_env.r[1] + 0x20); // lfd f0, 0x20(r1)
    gc_env.d[0] = *(double*)&temp;
    gc_env.f[0] = (float)gc_env.f[0] - (float)gc_env.f[2]; // fsubs f0, f0, f2
    gc_env.f[0] = (float)gc_env.f[1] - (float)gc_env.f[0]; // fsubs f0, f1, f0
    gc_env.cr[0] = isnan(gc_env.f[3]) || isnan(gc_env.f[0]) ? 0x1 : (gc_env.f[3] < gc_env.f[0] ? 0x8 : (gc_env.f[3] > gc_env.f[0] ? 0x4 : 0x2)); // fcmpo cr0, f3, f0
    if (gc_env.cr[0] >= 0) goto L_80029260;
    gc_env.r[31] |= 2; // ori r31, r31, 0x2
    L_80029260:
    gc_env.r[3] = gc_env.r[31]; // Move register
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x54);
    uint64_t temp = gc_mem_read64(gc_env.ram, gc_env.r[1] + 0x48); // lfd f31, 0x48(r1)
    gc_env.d[31] = *(double*)&temp;
    uint64_t temp = gc_mem_read64(gc_env.ram, gc_env.r[1] + 0x40); // lfd f30, 0x40(r1)
    gc_env.d[30] = *(double*)&temp;
    uint64_t temp = gc_mem_read64(gc_env.ram, gc_env.r[1] + 0x38); // lfd f29, 0x38(r1)
    gc_env.d[29] = *(double*)&temp;
    gc_env.r[31] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x34);
    gc_env.r[30] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x30);
    gc_env.r[29] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x2c);
    gc_env.r[1] += 80; // addi r1, r1, 0x50
    gc_env.lr = gc_env.r[0]; // Move to link register
    return;
}

// Function: Camera_8002928C
void Camera_8002928C(void) {
    gc_env.r[0] = gc_env.lr; // Move from link register
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x4, gc_env.r[0]);
    gc_mem_write32(gc_env.ram, gc_env.r[1] + -0x30, gc_env.r[1]);
    gc_env.r[1] = gc_env.r[1] + -0x30;
    uint64_t temp;
    memcpy(&temp, &gc_env.f[31], sizeof(double));
    gc_mem_write64(gc_env.ram, gc_env.r[1] + 0x28, temp); // stfd f31, 0x28(r1)
    uint64_t temp;
    memcpy(&temp, &gc_env.f[30], sizeof(double));
    gc_mem_write64(gc_env.ram, gc_env.r[1] + 0x20, temp); // stfd f30, 0x20(r1)
    uint64_t temp;
    memcpy(&temp, &gc_env.f[29], sizeof(double));
    gc_mem_write64(gc_env.ram, gc_env.r[1] + 0x18, temp); // stfd f29, 0x18(r1)
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x14, gc_env.r[31]);
    gc_env.r[31] = gc_env.r[3]; // Move register
    gc_env.r[3] = gc_mem_read32(gc_env.ram, gc_env.r[3] + 0x8);
    gc_env.cr[0] = (gc_env.r[3] == 0x1) ? 0 : (gc_env.r[3] < 0x1 ? -1 : 1); // Compare with immediate
    if (gc_env.cr[0] == 0) goto L_800293BC;
    gc_env.r[0] = gc_mem_read8(gc_env.ram, gc_env.r[31] + 0xc);
    gc_env.r[0] = (gc_env.r[0] >> 6) & 0x1; // extrwi r0, r0, 1, 25
    gc_env.cr[0] = (gc_env.r[0] == 0) ? 0x2 : ((int32_t)gc_env.r[0] < 0 ? 0x8 : 0x4);
    if (gc_env.cr[0] != 0) goto L_800293BC;
    gc_env.cr[0] = (gc_env.r[3] == 0x2) ? 0 : (gc_env.r[3] < 0x2 ? -1 : 1); // Compare with immediate
    if (gc_env.cr[0] != 0) goto L_800293A4;
    gc_env.r[3] = (int32_t)(int16_t)gc_mem_read16(gc_env.ram, gc_env.r[31] + 0xE); // lha r3, 0xE(r31)
    gc_env.cr[0] = (gc_env.r[3] == 0x0) ? 0 : (gc_env.r[3] < 0x0 ? -1 : 1); // Compare with immediate
    if (gc_env.cr[0] == 0) goto L_800292E8;
    gc_env.r[0] = gc_env.r[3] - 1;
    gc_mem_write16(gc_env.ram, gc_env.r[31] + 0xe, gc_env.r[0]);
    gc_env.r[3] = 0x0;
    goto L_800293C0;
    L_800292E8:
    Stage_GetCamBoundsLeftOffset();
    gc_env.f[29] = gc_env.f[1]; // fmr f29, f1
    Stage_GetCamBoundsRightOffset();
    gc_env.f[30] = gc_env.f[1]; // fmr f30, f1
    Stage_GetCamBoundsTopOffset();
    gc_env.f[31] = gc_env.f[1]; // fmr f31, f1
    Stage_GetCamBoundsBottomOffset();
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[31] + 0x10); // lfs f3, 0x10(r31)
    gc_env.f[3] = *(float*)&temp;
    gc_env.f[2] = (float)gc_env.f[30] - (float)gc_env.f[29]; // fsubs f2, f30, f29
    gc_env.f[0] = cm_804D7E28; // lfs f0, cm_804D7E28@sda21(r0)
    gc_env.r[0] = 0x1;
    gc_env.f[3] = (float)gc_env.f[3] - (float)gc_env.f[29]; // fsubs f3, f3, f29
    gc_env.f[2] = (float)gc_env.f[3] / (float)gc_env.f[2]; // fdivs f2, f3, f2
    gc_env.cr[0] = isnan(gc_env.f[2]) || isnan(gc_env.f[0]) ? 0x1 : (gc_env.f[2] < gc_env.f[0] ? 0x8 : (gc_env.f[2] > gc_env.f[0] ? 0x4 : 0x2)); // fcmpo cr0, f2, f0
    if (gc_env.cr[0] & 0x4) goto L_80029334; // bgt .L_80029334
    gc_env.f[0] = cm_804D7E2C; // lfs f0, cm_804D7E2C@sda21(r0)
    gc_env.cr[0] = isnan(gc_env.f[2]) || isnan(gc_env.f[0]) ? 0x1 : (gc_env.f[2] < gc_env.f[0] ? 0x8 : (gc_env.f[2] > gc_env.f[0] ? 0x4 : 0x2)); // fcmpo cr0, f2, f0
    if (gc_env.cr[0] & 0x8) goto L_80029334; // blt .L_80029334
    gc_env.r[0] = 0x0;
    L_80029334:
    gc_env.cr[0] = (gc_env.r[0] == 0x0) ? 0 : (gc_env.r[0] < 0x0 ? -1 : 1); // Compare with immediate
    if (gc_env.cr[0] != 0) goto L_80029374;
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[31] + 0x14); // lfs f3, 0x14(r31)
    gc_env.f[3] = *(float*)&temp;
    gc_env.f[2] = (float)gc_env.f[31] - (float)gc_env.f[1]; // fsubs f2, f31, f1
    gc_env.f[0] = cm_804D7E28; // lfs f0, cm_804D7E28@sda21(r0)
    gc_env.r[0] = 0x1;
    gc_env.f[1] = (float)gc_env.f[3] - (float)gc_env.f[1]; // fsubs f1, f3, f1
    gc_env.f[1] = (float)gc_env.f[1] / (float)gc_env.f[2]; // fdivs f1, f1, f2
    gc_env.cr[0] = isnan(gc_env.f[1]) || isnan(gc_env.f[0]) ? 0x1 : (gc_env.f[1] < gc_env.f[0] ? 0x8 : (gc_env.f[1] > gc_env.f[0] ? 0x4 : 0x2)); // fcmpo cr0, f1, f0
    if (gc_env.cr[0] & 0x4) goto L_8002936C; // bgt .L_8002936C
    gc_env.f[0] = cm_804D7E2C; // lfs f0, cm_804D7E2C@sda21(r0)
    gc_env.cr[0] = isnan(gc_env.f[1]) || isnan(gc_env.f[0]) ? 0x1 : (gc_env.f[1] < gc_env.f[0] ? 0x8 : (gc_env.f[1] > gc_env.f[0] ? 0x4 : 0x2)); // fcmpo cr0, f1, f0
    if (gc_env.cr[0] & 0x8) goto L_8002936C; // blt .L_8002936C
    gc_env.r[0] = 0x0;
    L_8002936C:
    gc_env.cr[0] = (gc_env.r[0] == 0x0) ? 0 : (gc_env.r[0] < 0x0 ? -1 : 1); // Compare with immediate
    if (gc_env.cr[0] == 0) goto L_8002939C;
    L_80029374:
    gc_env.r[3] = gc_mem_read8(gc_env.ram, gc_env.r[31] + 0xc);
    gc_env.r[0] = (gc_env.r[3] >> 5) & 0x1; // extrwi r0, r3, 1, 26
    gc_env.cr[0] = (gc_env.r[0] == 0) ? 0x2 : ((int32_t)gc_env.r[0] < 0 ? 0x8 : 0x4);
    if (gc_env.cr[0] == 0) goto L_80029394;
    gc_env.r[0] = 0x0;
    uint32_t rotated = gc_env.r[0] << 5; // rlwimi r3, r0, 5, 26, 26
    gc_env.r[3] = (gc_env.r[3] & ~0x20) | (rotated & 0x20);
    gc_mem_write8(gc_env.ram, gc_env.r[31] + 0xc, gc_env.r[3]);
    gc_env.r[0] = 0x258;
    gc_mem_write16(gc_env.ram, gc_env.r[31] + 0xe, gc_env.r[0]);
    L_80029394:
    gc_env.r[3] = 0x0;
    goto L_800293C0;
    L_8002939C:
    gc_env.r[0] = 0x0;
    gc_mem_write16(gc_env.ram, gc_env.r[31] + 0xe, gc_env.r[0]);
    L_800293A4:
    gc_env.r[0] = gc_mem_read8(gc_env.ram, gc_env.r[31] + 0xc);
    gc_env.r[3] = 0x1;
    uint32_t rotated = gc_env.r[3] << 5; // rlwimi r0, r3, 5, 26, 26
    gc_env.r[0] = (gc_env.r[0] & ~0x20) | (rotated & 0x20);
    gc_mem_write8(gc_env.ram, gc_env.r[31] + 0xc, gc_env.r[0]);
    gc_env.r[3] = 0x1;
    goto L_800293C0;
    L_800293BC:
    gc_env.r[3] = 0x0;
    L_800293C0:
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x34);
    uint64_t temp = gc_mem_read64(gc_env.ram, gc_env.r[1] + 0x28); // lfd f31, 0x28(r1)
    gc_env.d[31] = *(double*)&temp;
    uint64_t temp = gc_mem_read64(gc_env.ram, gc_env.r[1] + 0x20); // lfd f30, 0x20(r1)
    gc_env.d[30] = *(double*)&temp;
    uint64_t temp = gc_mem_read64(gc_env.ram, gc_env.r[1] + 0x18); // lfd f29, 0x18(r1)
    gc_env.d[29] = *(double*)&temp;
    gc_env.r[31] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x14);
    gc_env.r[1] += 48; // addi r1, r1, 0x30
    gc_env.lr = gc_env.r[0]; // Move to link register
    return;
}

// Function: Camera_800293E0
void Camera_800293E0(void) {
    gc_env.r[0] = gc_env.lr; // Move from link register
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x4, gc_env.r[0]);
    gc_mem_write32(gc_env.ram, gc_env.r[1] + -0x28, gc_env.r[1]);
    gc_env.r[1] = gc_env.r[1] + -0x28;
    uint64_t temp;
    memcpy(&temp, &gc_env.f[31], sizeof(double));
    gc_mem_write64(gc_env.ram, gc_env.r[1] + 0x20, temp); // stfd f31, 0x20(r1)
    uint64_t temp;
    memcpy(&temp, &gc_env.f[30], sizeof(double));
    gc_mem_write64(gc_env.ram, gc_env.r[1] + 0x18, temp); // stfd f30, 0x18(r1)
    uint64_t temp;
    memcpy(&temp, &gc_env.f[29], sizeof(double));
    gc_mem_write64(gc_env.ram, gc_env.r[1] + 0x10, temp); // stfd f29, 0x10(r1)
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0xc, gc_env.r[31]);
    gc_env.r[31] = gc_mem_read32(gc_env.ram, gc_env.r[0] + cm_804D6468@sda21);
    gc_env.f[31] = cm_804D7E34; // lfs f31, cm_804D7E34@sda21(r0)
    gc_env.f[30] = cm_804D7E30; // lfs f30, cm_804D7E30@sda21(r0)
    gc_env.f[29] = cm_804D7E14; // lfs f29, cm_804D7E14@sda21(r0)
    goto L_80029564;
    L_80029410:
    gc_env.r[3] = gc_env.r[31]; // Move register
    Camera_8002928C();
    gc_env.cr[0] = (gc_env.r[3] == 0x0) ? 0 : (gc_env.r[3] < 0x0 ? -1 : 1); // Compare with immediate
    if (gc_env.cr[0] == 0) goto L_80029560;
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[31] + 0x40); // lfs f1, 0x40(r31)
    gc_env.f[1] = *(float*)&temp;
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[31] + 0x2C); // lfs f0, 0x2C(r31)
    gc_env.f[0] = *(float*)&temp;
    gc_env.f[2] = (float)gc_env.f[1] - (float)gc_env.f[0]; // fsubs f2, f1, f0
    gc_env.cr[0] = isnan(gc_env.f[29]) || isnan(gc_env.f[2]) ? 0x1 : (gc_env.f[29] < gc_env.f[2] ? 0x8 : (gc_env.f[29] > gc_env.f[2] ? 0x4 : 0x2)); // fcmpu cr0, f29, f2
    if (gc_env.cr[0] == 0) goto L_80029460;
    gc_env.cr[0] = isnan(gc_env.f[2]) || isnan(gc_env.f[30]) ? 0x1 : (gc_env.f[2] < gc_env.f[30] ? 0x8 : (gc_env.f[2] > gc_env.f[30] ? 0x4 : 0x2)); // fcmpo cr0, f2, f30
    if (gc_env.cr[0] & (0x8 | 0x2)) goto L_80029448; // ble .L_80029448
    gc_env.f[0] = (float)gc_env.f[0] + (float)gc_env.f[30]; // fadds f0, f0, f30
    float temp = (float)gc_env.f[0]; // stfs f0, 0x2C(r31)
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x2C, *(uint32_t*)&temp);
    goto L_80029460;
    L_80029448:
    gc_env.cr[0] = isnan(gc_env.f[2]) || isnan(gc_env.f[31]) ? 0x1 : (gc_env.f[2] < gc_env.f[31] ? 0x8 : (gc_env.f[2] > gc_env.f[31] ? 0x4 : 0x2)); // fcmpo cr0, f2, f31
    if (gc_env.cr[0] >= 0) goto L_8002945C;
    gc_env.f[0] = (float)gc_env.f[0] - (float)gc_env.f[30]; // fsubs f0, f0, f30
    float temp = (float)gc_env.f[0]; // stfs f0, 0x2C(r31)
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x2C, *(uint32_t*)&temp);
    goto L_80029460;
    L_8002945C:
    float temp = (float)gc_env.f[1]; // stfs f1, 0x2C(r31)
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x2C, *(uint32_t*)&temp);
    L_80029460:
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[31] + 0x44); // lfs f1, 0x44(r31)
    gc_env.f[1] = *(float*)&temp;
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[31] + 0x30); // lfs f0, 0x30(r31)
    gc_env.f[0] = *(float*)&temp;
    gc_env.f[2] = (float)gc_env.f[1] - (float)gc_env.f[0]; // fsubs f2, f1, f0
    gc_env.cr[0] = isnan(gc_env.f[29]) || isnan(gc_env.f[2]) ? 0x1 : (gc_env.f[29] < gc_env.f[2] ? 0x8 : (gc_env.f[29] > gc_env.f[2] ? 0x4 : 0x2)); // fcmpu cr0, f29, f2
    if (gc_env.cr[0] == 0) goto L_800294A0;
    gc_env.cr[0] = isnan(gc_env.f[2]) || isnan(gc_env.f[30]) ? 0x1 : (gc_env.f[2] < gc_env.f[30] ? 0x8 : (gc_env.f[2] > gc_env.f[30] ? 0x4 : 0x2)); // fcmpo cr0, f2, f30
    if (gc_env.cr[0] & (0x8 | 0x2)) goto L_80029488; // ble .L_80029488
    gc_env.f[0] = (float)gc_env.f[0] + (float)gc_env.f[30]; // fadds f0, f0, f30
    float temp = (float)gc_env.f[0]; // stfs f0, 0x30(r31)
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x30, *(uint32_t*)&temp);
    goto L_800294A0;
    L_80029488:
    gc_env.cr[0] = isnan(gc_env.f[2]) || isnan(gc_env.f[31]) ? 0x1 : (gc_env.f[2] < gc_env.f[31] ? 0x8 : (gc_env.f[2] > gc_env.f[31] ? 0x4 : 0x2)); // fcmpo cr0, f2, f31
    if (gc_env.cr[0] >= 0) goto L_8002949C;
    gc_env.f[0] = (float)gc_env.f[0] - (float)gc_env.f[30]; // fsubs f0, f0, f30
    float temp = (float)gc_env.f[0]; // stfs f0, 0x30(r31)
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x30, *(uint32_t*)&temp);
    goto L_800294A0;
    L_8002949C:
    float temp = (float)gc_env.f[1]; // stfs f1, 0x30(r31)
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x30, *(uint32_t*)&temp);
    L_800294A0:
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[31] + 0x48); // lfs f1, 0x48(r31)
    gc_env.f[1] = *(float*)&temp;
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[31] + 0x34); // lfs f0, 0x34(r31)
    gc_env.f[0] = *(float*)&temp;
    gc_env.f[2] = (float)gc_env.f[1] - (float)gc_env.f[0]; // fsubs f2, f1, f0
    gc_env.cr[0] = isnan(gc_env.f[29]) || isnan(gc_env.f[2]) ? 0x1 : (gc_env.f[29] < gc_env.f[2] ? 0x8 : (gc_env.f[29] > gc_env.f[2] ? 0x4 : 0x2)); // fcmpu cr0, f29, f2
    if (gc_env.cr[0] == 0) goto L_800294E0;
    gc_env.cr[0] = isnan(gc_env.f[2]) || isnan(gc_env.f[30]) ? 0x1 : (gc_env.f[2] < gc_env.f[30] ? 0x8 : (gc_env.f[2] > gc_env.f[30] ? 0x4 : 0x2)); // fcmpo cr0, f2, f30
    if (gc_env.cr[0] & (0x8 | 0x2)) goto L_800294C8; // ble .L_800294C8
    gc_env.f[0] = (float)gc_env.f[0] + (float)gc_env.f[30]; // fadds f0, f0, f30
    float temp = (float)gc_env.f[0]; // stfs f0, 0x34(r31)
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x34, *(uint32_t*)&temp);
    goto L_800294E0;
    L_800294C8:
    gc_env.cr[0] = isnan(gc_env.f[2]) || isnan(gc_env.f[31]) ? 0x1 : (gc_env.f[2] < gc_env.f[31] ? 0x8 : (gc_env.f[2] > gc_env.f[31] ? 0x4 : 0x2)); // fcmpo cr0, f2, f31
    if (gc_env.cr[0] >= 0) goto L_800294DC;
    gc_env.f[0] = (float)gc_env.f[0] - (float)gc_env.f[30]; // fsubs f0, f0, f30
    float temp = (float)gc_env.f[0]; // stfs f0, 0x34(r31)
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x34, *(uint32_t*)&temp);
    goto L_800294E0;
    L_800294DC:
    float temp = (float)gc_env.f[1]; // stfs f1, 0x34(r31)
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x34, *(uint32_t*)&temp);
    L_800294E0:
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[31] + 0x4C); // lfs f1, 0x4C(r31)
    gc_env.f[1] = *(float*)&temp;
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[31] + 0x38); // lfs f0, 0x38(r31)
    gc_env.f[0] = *(float*)&temp;
    gc_env.f[2] = (float)gc_env.f[1] - (float)gc_env.f[0]; // fsubs f2, f1, f0
    gc_env.cr[0] = isnan(gc_env.f[29]) || isnan(gc_env.f[2]) ? 0x1 : (gc_env.f[29] < gc_env.f[2] ? 0x8 : (gc_env.f[29] > gc_env.f[2] ? 0x4 : 0x2)); // fcmpu cr0, f29, f2
    if (gc_env.cr[0] == 0) goto L_80029520;
    gc_env.cr[0] = isnan(gc_env.f[2]) || isnan(gc_env.f[30]) ? 0x1 : (gc_env.f[2] < gc_env.f[30] ? 0x8 : (gc_env.f[2] > gc_env.f[30] ? 0x4 : 0x2)); // fcmpo cr0, f2, f30
    if (gc_env.cr[0] & (0x8 | 0x2)) goto L_80029508; // ble .L_80029508
    gc_env.f[0] = (float)gc_env.f[0] + (float)gc_env.f[30]; // fadds f0, f0, f30
    float temp = (float)gc_env.f[0]; // stfs f0, 0x38(r31)
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x38, *(uint32_t*)&temp);
    goto L_80029520;
    L_80029508:
    gc_env.cr[0] = isnan(gc_env.f[2]) || isnan(gc_env.f[31]) ? 0x1 : (gc_env.f[2] < gc_env.f[31] ? 0x8 : (gc_env.f[2] > gc_env.f[31] ? 0x4 : 0x2)); // fcmpo cr0, f2, f31
    if (gc_env.cr[0] >= 0) goto L_8002951C;
    gc_env.f[0] = (float)gc_env.f[0] - (float)gc_env.f[30]; // fsubs f0, f0, f30
    float temp = (float)gc_env.f[0]; // stfs f0, 0x38(r31)
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x38, *(uint32_t*)&temp);
    goto L_80029520;
    L_8002951C:
    float temp = (float)gc_env.f[1]; // stfs f1, 0x38(r31)
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x38, *(uint32_t*)&temp);
    L_80029520:
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[31] + 0x50); // lfs f1, 0x50(r31)
    gc_env.f[1] = *(float*)&temp;
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[31] + 0x3C); // lfs f0, 0x3C(r31)
    gc_env.f[0] = *(float*)&temp;
    gc_env.f[2] = (float)gc_env.f[1] - (float)gc_env.f[0]; // fsubs f2, f1, f0
    gc_env.cr[0] = isnan(gc_env.f[29]) || isnan(gc_env.f[2]) ? 0x1 : (gc_env.f[29] < gc_env.f[2] ? 0x8 : (gc_env.f[29] > gc_env.f[2] ? 0x4 : 0x2)); // fcmpu cr0, f29, f2
    if (gc_env.cr[0] == 0) goto L_80029560;
    gc_env.cr[0] = isnan(gc_env.f[2]) || isnan(gc_env.f[30]) ? 0x1 : (gc_env.f[2] < gc_env.f[30] ? 0x8 : (gc_env.f[2] > gc_env.f[30] ? 0x4 : 0x2)); // fcmpo cr0, f2, f30
    if (gc_env.cr[0] & (0x8 | 0x2)) goto L_80029548; // ble .L_80029548
    gc_env.f[0] = (float)gc_env.f[0] + (float)gc_env.f[30]; // fadds f0, f0, f30
    float temp = (float)gc_env.f[0]; // stfs f0, 0x3C(r31)
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x3C, *(uint32_t*)&temp);
    goto L_80029560;
    L_80029548:
    gc_env.cr[0] = isnan(gc_env.f[2]) || isnan(gc_env.f[31]) ? 0x1 : (gc_env.f[2] < gc_env.f[31] ? 0x8 : (gc_env.f[2] > gc_env.f[31] ? 0x4 : 0x2)); // fcmpo cr0, f2, f31
    if (gc_env.cr[0] >= 0) goto L_8002955C;
    gc_env.f[0] = (float)gc_env.f[0] - (float)gc_env.f[30]; // fsubs f0, f0, f30
    float temp = (float)gc_env.f[0]; // stfs f0, 0x3C(r31)
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x3C, *(uint32_t*)&temp);
    goto L_80029560;
    L_8002955C:
    float temp = (float)gc_env.f[1]; // stfs f1, 0x3C(r31)
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x3C, *(uint32_t*)&temp);
    L_80029560:
    gc_env.r[31] = gc_mem_read32(gc_env.ram, gc_env.r[31] + 0x4);
    L_80029564:
    gc_env.cr[0] = ((uint32_t)gc_env.r[31] == 0x0) ? 0 : ((uint32_t)gc_env.r[31] < 0x0 ? -1 : 1); // Logical compare with immediate
    if (gc_env.cr[0] != 0) goto L_80029410;
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x2c);
    uint64_t temp = gc_mem_read64(gc_env.ram, gc_env.r[1] + 0x20); // lfd f31, 0x20(r1)
    gc_env.d[31] = *(double*)&temp;
    uint64_t temp = gc_mem_read64(gc_env.ram, gc_env.r[1] + 0x18); // lfd f30, 0x18(r1)
    gc_env.d[30] = *(double*)&temp;
    uint64_t temp = gc_mem_read64(gc_env.ram, gc_env.r[1] + 0x10); // lfd f29, 0x10(r1)
    gc_env.d[29] = *(double*)&temp;
    gc_env.r[31] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0xc);
    gc_env.r[1] += 40; // addi r1, r1, 0x28
    gc_env.lr = gc_env.r[0]; // Move to link register
    return;
}

// Function: Camera_8002958C
void Camera_8002958C(void) {
    gc_env.r[0] = gc_env.lr; // Move from link register
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x4, gc_env.r[0]);
    gc_mem_write32(gc_env.ram, gc_env.r[1] + -0xb0, gc_env.r[1]);
    gc_env.r[1] = gc_env.r[1] + -0xb0;
    uint64_t temp;
    memcpy(&temp, &gc_env.f[31], sizeof(double));
    gc_mem_write64(gc_env.ram, gc_env.r[1] + 0xA8, temp); // stfd f31, 0xA8(r1)
    uint64_t temp;
    memcpy(&temp, &gc_env.f[30], sizeof(double));
    gc_mem_write64(gc_env.ram, gc_env.r[1] + 0xA0, temp); // stfd f30, 0xA0(r1)
    uint64_t temp;
    memcpy(&temp, &gc_env.f[29], sizeof(double));
    gc_mem_write64(gc_env.ram, gc_env.r[1] + 0x98, temp); // stfd f29, 0x98(r1)
    uint64_t temp;
    memcpy(&temp, &gc_env.f[28], sizeof(double));
    gc_mem_write64(gc_env.ram, gc_env.r[1] + 0x90, temp); // stfd f28, 0x90(r1)
    uint64_t temp;
    memcpy(&temp, &gc_env.f[27], sizeof(double));
    gc_mem_write64(gc_env.ram, gc_env.r[1] + 0x88, temp); // stfd f27, 0x88(r1)
    uint64_t temp;
    memcpy(&temp, &gc_env.f[26], sizeof(double));
    gc_mem_write64(gc_env.ram, gc_env.r[1] + 0x80, temp); // stfd f26, 0x80(r1)
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x6C, gc_env.r[27]); // stmw r27, 0x6C(r1)
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x70, gc_env.r[28]); // stmw r27, 0x6C(r1)
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x74, gc_env.r[29]); // stmw r27, 0x6C(r1)
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x78, gc_env.r[30]); // stmw r27, 0x6C(r1)
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x7C, gc_env.r[31]); // stmw r27, 0x6C(r1)
    gc_env.r[28] = gc_env.r[3] + 0; // addi r28, r3, 0x0
    gc_env.r[29] = gc_env.r[4] + 0; // addi r29, r4, 0x0
    gc_env.r[30] = 0x0;
    gc_env.r[27] = gc_mem_read32(gc_env.ram, gc_env.r[0] + cm_804D6468@sda21);
    goto L_800295E0;
    L_800295C8:
    gc_env.r[3] = gc_env.r[27]; // Move register
    Camera_8002928C();
    gc_env.cr[0] = (gc_env.r[3] == 0x0) ? 0 : (gc_env.r[3] < 0x0 ? -1 : 1); // Compare with immediate
    if (gc_env.cr[0] == 0) goto L_800295DC;
    gc_env.r[30] += 1; // addi r30, r30, 0x1
    L_800295DC:
    gc_env.r[27] = gc_mem_read32(gc_env.ram, gc_env.r[27] + 0x4);
    L_800295E0:
    gc_env.cr[0] = ((uint32_t)gc_env.r[27] == 0x0) ? 0 : ((uint32_t)gc_env.r[27] < 0x0 ? -1 : 1); // Logical compare with immediate
    if (gc_env.cr[0] != 0) goto L_800295C8;
    gc_env.cr[0] = (gc_env.r[30] == 0x0) ? 0 : (gc_env.r[30] < 0x0 ? -1 : 1); // Compare with immediate
    if (gc_env.cr[0] == 0) goto L_800299E4;
    gc_env.cr[0] = ((uint32_t)gc_env.r[30] == 0x5) ? 0 : ((uint32_t)gc_env.r[30] < 0x5 ? -1 : 1); // Logical compare with immediate
    if (gc_env.cr[0] >= 0) goto L_80029610;
    gc_env.r[3] = ((uint32_t)&cm_803BCB9C >> 16) & 0xFFFF; // lis r3, cm_803BCB9C@ha
    gc_env.r[4] = gc_env.r[30] << 2; // slwi r4, r30, 2
    gc_env.r[0] = gc_env.r[3] + ((uint32_t)&cm_803BCB9C & 0xFFFF); // addi r0, r3, cm_803BCB9C@l
    gc_env.r[3] = gc_env.r[0] + gc_env.r[4];
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[3] + 0x0); // lfs f26, 0x0(r3)
    gc_env.f[26] = *(float*)&temp;
    goto L_80029614;
    L_80029610:
    gc_env.f[26] = cm_804D7E04; // lfs f26, cm_804D7E04@sda21(r0)
    L_80029614:
    Stage_GetCamTrackRatio();
    gc_env.f[30] = cm_804D7E38; // lfs f30, cm_804D7E38@sda21(r0)
    gc_env.f[27] = (float)gc_env.f[26] * (float)gc_env.f[1]; // fmuls f27, f26, f1
    gc_env.f[28] = cm_804D7E00; // lfs f28, cm_804D7E00@sda21(r0)
    gc_env.r[30] = 0x0;
    gc_env.f[31] = gc_env.f[30]; // fmr f31, f30
    gc_env.f[29] = gc_env.f[28]; // fmr f29, f28
    gc_env.r[31] = gc_mem_read32(gc_env.ram, gc_env.r[0] + cm_804D6468@sda21);
    gc_env.d[26] = cm_804D7E18; // lfd f26, cm_804D7E18@sda21(r0)
    goto L_800299DC;
    L_8002963C:
    gc_env.r[3] = gc_env.r[31]; // Move register
    Camera_8002928C();
    gc_env.cr[0] = (gc_env.r[3] == 0x0) ? 0 : (gc_env.r[3] < 0x0 ? -1 : 1); // Compare with immediate
    if (gc_env.cr[0] == 0) goto L_800299D8;
    gc_env.r[5] = gc_mem_read32(gc_env.ram, gc_env.r[31] + 0x10);
    gc_env.r[3] = gc_env.r[1] + 80; // addi r3, r1, 0x50
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[31] + 0x14);
    gc_env.r[4] = 0x0;
    gc_env.r[30] += 1; // addi r30, r30, 0x1
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x50, gc_env.r[5]);
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x54, gc_env.r[0]);
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[31] + 0x18);
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x58, gc_env.r[0]);
    gc_env.r[5] = gc_mem_read32(gc_env.ram, gc_env.r[31] + 0x10);
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[31] + 0x14);
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x44, gc_env.r[5]);
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x48, gc_env.r[0]);
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[31] + 0x18);
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x4c, gc_env.r[0]);
    Camera_80029124();
    gc_env.r[27] = gc_env.r[3]; // Move register
    if (gc_env.cr[0] == 0) goto L_80029708;
    gc_env.r[3] = gc_env.r[1] + 48; // addi r3, r1, 0x30
    gc_env.r[4] = gc_env.r[1] + 52; // addi r4, r1, 0x34
    Ground_801C4368();
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x30); // lfs f0, 0x30(r1)
    gc_env.f[0] = *(float*)&temp;
    gc_env.r[0] = (gc_env.r[27] << 0) & 0x4; // rlwinm r0, r27, 0, 29, 29
    gc_env.cr[0] = (gc_env.r[0] == 0) ? 0x2 : ((int32_t)gc_env.r[0] < 0 ? 0x8 : 0x4);
    gc_env.f[0] = gc_env.f[0] + gc_env.f[26]; // fadd f0, f0, f26
    gc_env.f[0] = (float)gc_env.f[0]; // frsp f0, f0
    float temp = (float)gc_env.f[0]; // stfs f0, 0x30(r1)
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x30, *(uint32_t*)&temp);
    if (gc_env.cr[0] == 0) goto L_800296C0;
    Stage_GetCamBoundsLeftOffset();
    float temp = (float)gc_env.f[1]; // stfs f1, 0x50(r1)
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x50, *(uint32_t*)&temp);
    L_800296C0:
    gc_env.r[0] = (gc_env.r[27] << 0) & 0x8; // rlwinm r0, r27, 0, 28, 28
    gc_env.cr[0] = (gc_env.r[0] == 0) ? 0x2 : ((int32_t)gc_env.r[0] < 0 ? 0x8 : 0x4);
    if (gc_env.cr[0] == 0) goto L_800296D0;
    Stage_GetCamBoundsRightOffset();
    float temp = (float)gc_env.f[1]; // stfs f1, 0x50(r1)
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x50, *(uint32_t*)&temp);
    L_800296D0:
    gc_env.r[0] = gc_env.r[27] & 0x1; // clrlwi r0, r27, 31
    if (gc_env.cr[0] == 0) goto L_800296E0;
    Stage_GetCamBoundsTopOffset();
    float temp = (float)gc_env.f[1]; // stfs f1, 0x54(r1)
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x54, *(uint32_t*)&temp);
    L_800296E0:
    gc_env.r[0] = (gc_env.r[27] << 0) & 0x2; // rlwinm r0, r27, 0, 30, 30
    gc_env.cr[0] = (gc_env.r[0] == 0) ? 0x2 : ((int32_t)gc_env.r[0] < 0 ? 0x8 : 0x4);
    if (gc_env.cr[0] == 0) goto L_80029708;
    Stage_GetCamBoundsBottomOffset();
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x30); // lfs f0, 0x30(r1)
    gc_env.f[0] = *(float*)&temp;
    gc_env.cr[0] = isnan(gc_env.f[1]) || isnan(gc_env.f[0]) ? 0x1 : (gc_env.f[1] < gc_env.f[0] ? 0x8 : (gc_env.f[1] > gc_env.f[0] ? 0x4 : 0x2)); // fcmpo cr0, f1, f0
    if (gc_env.cr[0] & (0x8 | 0x2)) goto L_80029700; // ble .L_80029700
    Stage_GetCamBoundsBottomOffset();
    goto L_80029704;
    L_80029700:
    gc_env.f[1] = gc_env.f[0]; // fmr f1, f0
    L_80029704:
    float temp = (float)gc_env.f[1]; // stfs f1, 0x54(r1)
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x54, *(uint32_t*)&temp);
    L_80029708:
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[31] + 0x2C); // lfs f1, 0x2C(r31)
    gc_env.f[1] = *(float*)&temp;
    gc_env.r[3] = gc_env.r[1] + 68; // addi r3, r1, 0x44
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x50); // lfs f0, 0x50(r1)
    gc_env.f[0] = *(float*)&temp;
    gc_env.r[4] = 0x0;
    gc_env.f[0] = (float)gc_env.f[1] * (float)gc_env.f[27] + (float)gc_env.f[0]; // fmadds f0, f1, f27, f0
    float temp = (float)gc_env.f[0]; // stfs f0, 0x44(r1)
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x44, *(uint32_t*)&temp);
    Camera_80029124();
    gc_env.r[27] = gc_env.r[3]; // Move register
    if (gc_env.cr[0] == 0) goto L_800297A0;
    gc_env.r[3] = gc_env.r[1] + 40; // addi r3, r1, 0x28
    gc_env.r[4] = gc_env.r[1] + 44; // addi r4, r1, 0x2c
    Ground_801C4368();
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x28); // lfs f0, 0x28(r1)
    gc_env.f[0] = *(float*)&temp;
    gc_env.r[0] = (gc_env.r[27] << 0) & 0x4; // rlwinm r0, r27, 0, 29, 29
    gc_env.cr[0] = (gc_env.r[0] == 0) ? 0x2 : ((int32_t)gc_env.r[0] < 0 ? 0x8 : 0x4);
    gc_env.f[0] = gc_env.f[0] + gc_env.f[26]; // fadd f0, f0, f26
    gc_env.f[0] = (float)gc_env.f[0]; // frsp f0, f0
    float temp = (float)gc_env.f[0]; // stfs f0, 0x28(r1)
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x28, *(uint32_t*)&temp);
    if (gc_env.cr[0] == 0) goto L_80029758;
    Stage_GetCamBoundsLeftOffset();
    float temp = (float)gc_env.f[1]; // stfs f1, 0x44(r1)
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x44, *(uint32_t*)&temp);
    L_80029758:
    gc_env.r[0] = (gc_env.r[27] << 0) & 0x8; // rlwinm r0, r27, 0, 28, 28
    gc_env.cr[0] = (gc_env.r[0] == 0) ? 0x2 : ((int32_t)gc_env.r[0] < 0 ? 0x8 : 0x4);
    if (gc_env.cr[0] == 0) goto L_80029768;
    Stage_GetCamBoundsRightOffset();
    float temp = (float)gc_env.f[1]; // stfs f1, 0x44(r1)
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x44, *(uint32_t*)&temp);
    L_80029768:
    gc_env.r[0] = gc_env.r[27] & 0x1; // clrlwi r0, r27, 31
    if (gc_env.cr[0] == 0) goto L_80029778;
    Stage_GetCamBoundsTopOffset();
    float temp = (float)gc_env.f[1]; // stfs f1, 0x48(r1)
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x48, *(uint32_t*)&temp);
    L_80029778:
    gc_env.r[0] = (gc_env.r[27] << 0) & 0x2; // rlwinm r0, r27, 0, 30, 30
    gc_env.cr[0] = (gc_env.r[0] == 0) ? 0x2 : ((int32_t)gc_env.r[0] < 0 ? 0x8 : 0x4);
    if (gc_env.cr[0] == 0) goto L_800297A0;
    Stage_GetCamBoundsBottomOffset();
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x28); // lfs f0, 0x28(r1)
    gc_env.f[0] = *(float*)&temp;
    gc_env.cr[0] = isnan(gc_env.f[1]) || isnan(gc_env.f[0]) ? 0x1 : (gc_env.f[1] < gc_env.f[0] ? 0x8 : (gc_env.f[1] > gc_env.f[0] ? 0x4 : 0x2)); // fcmpo cr0, f1, f0
    if (gc_env.cr[0] & (0x8 | 0x2)) goto L_80029798; // ble .L_80029798
    Stage_GetCamBoundsBottomOffset();
    goto L_8002979C;
    L_80029798:
    gc_env.f[1] = gc_env.f[0]; // fmr f1, f0
    L_8002979C:
    float temp = (float)gc_env.f[1]; // stfs f1, 0x48(r1)
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x48, *(uint32_t*)&temp);
    L_800297A0:
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x44); // lfs f0, 0x44(r1)
    gc_env.f[0] = *(float*)&temp;
    gc_env.cr[0] = isnan(gc_env.f[0]) || isnan(gc_env.f[31]) ? 0x1 : (gc_env.f[0] < gc_env.f[31] ? 0x8 : (gc_env.f[0] > gc_env.f[31] ? 0x4 : 0x2)); // fcmpo cr0, f0, f31
    if (gc_env.cr[0] >= 0) goto L_800297B0;
    gc_env.f[31] = gc_env.f[0]; // fmr f31, f0
    L_800297B0:
    gc_env.cr[0] = isnan(gc_env.f[0]) || isnan(gc_env.f[29]) ? 0x1 : (gc_env.f[0] < gc_env.f[29] ? 0x8 : (gc_env.f[0] > gc_env.f[29] ? 0x4 : 0x2)); // fcmpo cr0, f0, f29
    if (gc_env.cr[0] & (0x8 | 0x2)) goto L_800297BC; // ble .L_800297BC
    gc_env.f[29] = gc_env.f[0]; // fmr f29, f0
    L_800297BC:
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[31] + 0x30); // lfs f1, 0x30(r31)
    gc_env.f[1] = *(float*)&temp;
    gc_env.r[3] = gc_env.r[1] + 68; // addi r3, r1, 0x44
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x50); // lfs f0, 0x50(r1)
    gc_env.f[0] = *(float*)&temp;
    gc_env.r[4] = 0x0;
    gc_env.f[0] = (float)gc_env.f[1] * (float)gc_env.f[27] + (float)gc_env.f[0]; // fmadds f0, f1, f27, f0
    float temp = (float)gc_env.f[0]; // stfs f0, 0x44(r1)
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x44, *(uint32_t*)&temp);
    Camera_80029124();
    gc_env.r[27] = gc_env.r[3]; // Move register
    if (gc_env.cr[0] == 0) goto L_80029854;
    gc_env.r[3] = gc_env.r[1] + 32; // addi r3, r1, 0x20
    gc_env.r[4] = gc_env.r[1] + 36; // addi r4, r1, 0x24
    Ground_801C4368();
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x20); // lfs f0, 0x20(r1)
    gc_env.f[0] = *(float*)&temp;
    gc_env.r[0] = (gc_env.r[27] << 0) & 0x4; // rlwinm r0, r27, 0, 29, 29
    gc_env.cr[0] = (gc_env.r[0] == 0) ? 0x2 : ((int32_t)gc_env.r[0] < 0 ? 0x8 : 0x4);
    gc_env.f[0] = gc_env.f[0] + gc_env.f[26]; // fadd f0, f0, f26
    gc_env.f[0] = (float)gc_env.f[0]; // frsp f0, f0
    float temp = (float)gc_env.f[0]; // stfs f0, 0x20(r1)
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x20, *(uint32_t*)&temp);
    if (gc_env.cr[0] == 0) goto L_8002980C;
    Stage_GetCamBoundsLeftOffset();
    float temp = (float)gc_env.f[1]; // stfs f1, 0x44(r1)
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x44, *(uint32_t*)&temp);
    L_8002980C:
    gc_env.r[0] = (gc_env.r[27] << 0) & 0x8; // rlwinm r0, r27, 0, 28, 28
    gc_env.cr[0] = (gc_env.r[0] == 0) ? 0x2 : ((int32_t)gc_env.r[0] < 0 ? 0x8 : 0x4);
    if (gc_env.cr[0] == 0) goto L_8002981C;
    Stage_GetCamBoundsRightOffset();
    float temp = (float)gc_env.f[1]; // stfs f1, 0x44(r1)
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x44, *(uint32_t*)&temp);
    L_8002981C:
    gc_env.r[0] = gc_env.r[27] & 0x1; // clrlwi r0, r27, 31
    if (gc_env.cr[0] == 0) goto L_8002982C;
    Stage_GetCamBoundsTopOffset();
    float temp = (float)gc_env.f[1]; // stfs f1, 0x48(r1)
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x48, *(uint32_t*)&temp);
    L_8002982C:
    gc_env.r[0] = (gc_env.r[27] << 0) & 0x2; // rlwinm r0, r27, 0, 30, 30
    gc_env.cr[0] = (gc_env.r[0] == 0) ? 0x2 : ((int32_t)gc_env.r[0] < 0 ? 0x8 : 0x4);
    if (gc_env.cr[0] == 0) goto L_80029854;
    Stage_GetCamBoundsBottomOffset();
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x20); // lfs f0, 0x20(r1)
    gc_env.f[0] = *(float*)&temp;
    gc_env.cr[0] = isnan(gc_env.f[1]) || isnan(gc_env.f[0]) ? 0x1 : (gc_env.f[1] < gc_env.f[0] ? 0x8 : (gc_env.f[1] > gc_env.f[0] ? 0x4 : 0x2)); // fcmpo cr0, f1, f0
    if (gc_env.cr[0] & (0x8 | 0x2)) goto L_8002984C; // ble .L_8002984C
    Stage_GetCamBoundsBottomOffset();
    goto L_80029850;
    L_8002984C:
    gc_env.f[1] = gc_env.f[0]; // fmr f1, f0
    L_80029850:
    float temp = (float)gc_env.f[1]; // stfs f1, 0x48(r1)
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x48, *(uint32_t*)&temp);
    L_80029854:
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x44); // lfs f0, 0x44(r1)
    gc_env.f[0] = *(float*)&temp;
    gc_env.cr[0] = isnan(gc_env.f[0]) || isnan(gc_env.f[31]) ? 0x1 : (gc_env.f[0] < gc_env.f[31] ? 0x8 : (gc_env.f[0] > gc_env.f[31] ? 0x4 : 0x2)); // fcmpo cr0, f0, f31
    if (gc_env.cr[0] >= 0) goto L_80029864;
    gc_env.f[31] = gc_env.f[0]; // fmr f31, f0
    L_80029864:
    gc_env.cr[0] = isnan(gc_env.f[0]) || isnan(gc_env.f[29]) ? 0x1 : (gc_env.f[0] < gc_env.f[29] ? 0x8 : (gc_env.f[0] > gc_env.f[29] ? 0x4 : 0x2)); // fcmpo cr0, f0, f29
    if (gc_env.cr[0] & (0x8 | 0x2)) goto L_80029870; // ble .L_80029870
    gc_env.f[29] = gc_env.f[0]; // fmr f29, f0
    L_80029870:
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[31] + 0x38); // lfs f1, 0x38(r31)
    gc_env.f[1] = *(float*)&temp;
    gc_env.r[3] = gc_env.r[1] + 68; // addi r3, r1, 0x44
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x54); // lfs f0, 0x54(r1)
    gc_env.f[0] = *(float*)&temp;
    gc_env.r[4] = 0x0;
    gc_env.f[0] = (float)gc_env.f[1] * (float)gc_env.f[27] + (float)gc_env.f[0]; // fmadds f0, f1, f27, f0
    float temp = (float)gc_env.f[0]; // stfs f0, 0x48(r1)
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x48, *(uint32_t*)&temp);
    Camera_80029124();
    gc_env.r[27] = gc_env.r[3]; // Move register
    if (gc_env.cr[0] == 0) goto L_80029908;
    gc_env.r[3] = gc_env.r[1] + 24; // addi r3, r1, 0x18
    gc_env.r[4] = gc_env.r[1] + 28; // addi r4, r1, 0x1c
    Ground_801C4368();
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x18); // lfs f0, 0x18(r1)
    gc_env.f[0] = *(float*)&temp;
    gc_env.r[0] = (gc_env.r[27] << 0) & 0x4; // rlwinm r0, r27, 0, 29, 29
    gc_env.cr[0] = (gc_env.r[0] == 0) ? 0x2 : ((int32_t)gc_env.r[0] < 0 ? 0x8 : 0x4);
    gc_env.f[0] = gc_env.f[0] + gc_env.f[26]; // fadd f0, f0, f26
    gc_env.f[0] = (float)gc_env.f[0]; // frsp f0, f0
    float temp = (float)gc_env.f[0]; // stfs f0, 0x18(r1)
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x18, *(uint32_t*)&temp);
    if (gc_env.cr[0] == 0) goto L_800298C0;
    Stage_GetCamBoundsLeftOffset();
    float temp = (float)gc_env.f[1]; // stfs f1, 0x44(r1)
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x44, *(uint32_t*)&temp);
    L_800298C0:
    gc_env.r[0] = (gc_env.r[27] << 0) & 0x8; // rlwinm r0, r27, 0, 28, 28
    gc_env.cr[0] = (gc_env.r[0] == 0) ? 0x2 : ((int32_t)gc_env.r[0] < 0 ? 0x8 : 0x4);
    if (gc_env.cr[0] == 0) goto L_800298D0;
    Stage_GetCamBoundsRightOffset();
    float temp = (float)gc_env.f[1]; // stfs f1, 0x44(r1)
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x44, *(uint32_t*)&temp);
    L_800298D0:
    gc_env.r[0] = gc_env.r[27] & 0x1; // clrlwi r0, r27, 31
    if (gc_env.cr[0] == 0) goto L_800298E0;
    Stage_GetCamBoundsTopOffset();
    float temp = (float)gc_env.f[1]; // stfs f1, 0x48(r1)
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x48, *(uint32_t*)&temp);
    L_800298E0:
    gc_env.r[0] = (gc_env.r[27] << 0) & 0x2; // rlwinm r0, r27, 0, 30, 30
    gc_env.cr[0] = (gc_env.r[0] == 0) ? 0x2 : ((int32_t)gc_env.r[0] < 0 ? 0x8 : 0x4);
    if (gc_env.cr[0] == 0) goto L_80029908;
    Stage_GetCamBoundsBottomOffset();
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x18); // lfs f0, 0x18(r1)
    gc_env.f[0] = *(float*)&temp;
    gc_env.cr[0] = isnan(gc_env.f[1]) || isnan(gc_env.f[0]) ? 0x1 : (gc_env.f[1] < gc_env.f[0] ? 0x8 : (gc_env.f[1] > gc_env.f[0] ? 0x4 : 0x2)); // fcmpo cr0, f1, f0
    if (gc_env.cr[0] & (0x8 | 0x2)) goto L_80029900; // ble .L_80029900
    Stage_GetCamBoundsBottomOffset();
    goto L_80029904;
    L_80029900:
    gc_env.f[1] = gc_env.f[0]; // fmr f1, f0
    L_80029904:
    float temp = (float)gc_env.f[1]; // stfs f1, 0x48(r1)
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x48, *(uint32_t*)&temp);
    L_80029908:
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x48); // lfs f0, 0x48(r1)
    gc_env.f[0] = *(float*)&temp;
    gc_env.cr[0] = isnan(gc_env.f[0]) || isnan(gc_env.f[30]) ? 0x1 : (gc_env.f[0] < gc_env.f[30] ? 0x8 : (gc_env.f[0] > gc_env.f[30] ? 0x4 : 0x2)); // fcmpo cr0, f0, f30
    if (gc_env.cr[0] >= 0) goto L_80029918;
    gc_env.f[30] = gc_env.f[0]; // fmr f30, f0
    L_80029918:
    gc_env.cr[0] = isnan(gc_env.f[0]) || isnan(gc_env.f[28]) ? 0x1 : (gc_env.f[0] < gc_env.f[28] ? 0x8 : (gc_env.f[0] > gc_env.f[28] ? 0x4 : 0x2)); // fcmpo cr0, f0, f28
    if (gc_env.cr[0] & (0x8 | 0x2)) goto L_80029924; // ble .L_80029924
    gc_env.f[28] = gc_env.f[0]; // fmr f28, f0
    L_80029924:
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[31] + 0x34); // lfs f1, 0x34(r31)
    gc_env.f[1] = *(float*)&temp;
    gc_env.r[3] = gc_env.r[1] + 68; // addi r3, r1, 0x44
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x54); // lfs f0, 0x54(r1)
    gc_env.f[0] = *(float*)&temp;
    gc_env.r[4] = 0x0;
    gc_env.f[0] = (float)gc_env.f[1] * (float)gc_env.f[27] + (float)gc_env.f[0]; // fmadds f0, f1, f27, f0
    float temp = (float)gc_env.f[0]; // stfs f0, 0x48(r1)
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x48, *(uint32_t*)&temp);
    Camera_80029124();
    gc_env.r[27] = gc_env.r[3]; // Move register
    if (gc_env.cr[0] == 0) goto L_800299BC;
    gc_env.r[3] = gc_env.r[1] + 16; // addi r3, r1, 0x10
    gc_env.r[4] = gc_env.r[1] + 20; // addi r4, r1, 0x14
    Ground_801C4368();
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x10); // lfs f0, 0x10(r1)
    gc_env.f[0] = *(float*)&temp;
    gc_env.r[0] = (gc_env.r[27] << 0) & 0x4; // rlwinm r0, r27, 0, 29, 29
    gc_env.cr[0] = (gc_env.r[0] == 0) ? 0x2 : ((int32_t)gc_env.r[0] < 0 ? 0x8 : 0x4);
    gc_env.f[0] = gc_env.f[0] + gc_env.f[26]; // fadd f0, f0, f26
    gc_env.f[0] = (float)gc_env.f[0]; // frsp f0, f0
    float temp = (float)gc_env.f[0]; // stfs f0, 0x10(r1)
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x10, *(uint32_t*)&temp);
    if (gc_env.cr[0] == 0) goto L_80029974;
    Stage_GetCamBoundsLeftOffset();
    float temp = (float)gc_env.f[1]; // stfs f1, 0x44(r1)
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x44, *(uint32_t*)&temp);
    L_80029974:
    gc_env.r[0] = (gc_env.r[27] << 0) & 0x8; // rlwinm r0, r27, 0, 28, 28
    gc_env.cr[0] = (gc_env.r[0] == 0) ? 0x2 : ((int32_t)gc_env.r[0] < 0 ? 0x8 : 0x4);
    if (gc_env.cr[0] == 0) goto L_80029984;
    Stage_GetCamBoundsRightOffset();
    float temp = (float)gc_env.f[1]; // stfs f1, 0x44(r1)
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x44, *(uint32_t*)&temp);
    L_80029984:
    gc_env.r[0] = gc_env.r[27] & 0x1; // clrlwi r0, r27, 31
    if (gc_env.cr[0] == 0) goto L_80029994;
    Stage_GetCamBoundsTopOffset();
    float temp = (float)gc_env.f[1]; // stfs f1, 0x48(r1)
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x48, *(uint32_t*)&temp);
    L_80029994:
    gc_env.r[0] = (gc_env.r[27] << 0) & 0x2; // rlwinm r0, r27, 0, 30, 30
    gc_env.cr[0] = (gc_env.r[0] == 0) ? 0x2 : ((int32_t)gc_env.r[0] < 0 ? 0x8 : 0x4);
    if (gc_env.cr[0] == 0) goto L_800299BC;
    Stage_GetCamBoundsBottomOffset();
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x10); // lfs f0, 0x10(r1)
    gc_env.f[0] = *(float*)&temp;
    gc_env.cr[0] = isnan(gc_env.f[1]) || isnan(gc_env.f[0]) ? 0x1 : (gc_env.f[1] < gc_env.f[0] ? 0x8 : (gc_env.f[1] > gc_env.f[0] ? 0x4 : 0x2)); // fcmpo cr0, f1, f0
    if (gc_env.cr[0] & (0x8 | 0x2)) goto L_800299B4; // ble .L_800299B4
    Stage_GetCamBoundsBottomOffset();
    goto L_800299B8;
    L_800299B4:
    gc_env.f[1] = gc_env.f[0]; // fmr f1, f0
    L_800299B8:
    float temp = (float)gc_env.f[1]; // stfs f1, 0x48(r1)
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x48, *(uint32_t*)&temp);
    L_800299BC:
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x48); // lfs f0, 0x48(r1)
    gc_env.f[0] = *(float*)&temp;
    gc_env.cr[0] = isnan(gc_env.f[0]) || isnan(gc_env.f[30]) ? 0x1 : (gc_env.f[0] < gc_env.f[30] ? 0x8 : (gc_env.f[0] > gc_env.f[30] ? 0x4 : 0x2)); // fcmpo cr0, f0, f30
    if (gc_env.cr[0] >= 0) goto L_800299CC;
    gc_env.f[30] = gc_env.f[0]; // fmr f30, f0
    L_800299CC:
    gc_env.cr[0] = isnan(gc_env.f[0]) || isnan(gc_env.f[28]) ? 0x1 : (gc_env.f[0] < gc_env.f[28] ? 0x8 : (gc_env.f[0] > gc_env.f[28] ? 0x4 : 0x2)); // fcmpo cr0, f0, f28
    if (gc_env.cr[0] & (0x8 | 0x2)) goto L_800299D8; // ble .L_800299D8
    gc_env.f[28] = gc_env.f[0]; // fmr f28, f0
    L_800299D8:
    gc_env.r[31] = gc_mem_read32(gc_env.ram, gc_env.r[31] + 0x4);
    L_800299DC:
    gc_env.cr[0] = ((uint32_t)gc_env.r[31] == 0x0) ? 0 : ((uint32_t)gc_env.r[31] < 0x0 ? -1 : 1); // Logical compare with immediate
    if (gc_env.cr[0] != 0) goto L_8002963C;
    L_800299E4:
    gc_env.cr[0] = (gc_env.r[30] == 0x0) ? 0 : (gc_env.r[30] < 0x0 ? -1 : 1); // Compare with immediate
    if (gc_env.cr[0] != 0) goto L_80029A10;
    gc_env.r[3] = gc_env.r[1] + 56; // addi r3, r1, 0x38
    Stage_UnkSetVec3TCam_Offset();
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x38); // lfs f1, 0x38(r1)
    gc_env.f[1] = *(float*)&temp;
    gc_env.f[0] = cm_804D7E3C; // lfs f0, cm_804D7E3C@sda21(r0)
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x3C); // lfs f2, 0x3C(r1)
    gc_env.f[2] = *(float*)&temp;
    gc_env.f[31] = (float)gc_env.f[1] - (float)gc_env.f[0]; // fsubs f31, f1, f0
    gc_env.f[30] = (float)gc_env.f[2] - (float)gc_env.f[0]; // fsubs f30, f2, f0
    gc_env.f[29] = (float)gc_env.f[0] + (float)gc_env.f[1]; // fadds f29, f0, f1
    gc_env.f[28] = (float)gc_env.f[0] + (float)gc_env.f[2]; // fadds f28, f0, f2
    L_80029A10:
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[29] + 0x20); // lfs f2, 0x20(r29)
    gc_env.f[2] = *(float*)&temp;
    gc_env.f[0] = cm_804D7E14; // lfs f0, cm_804D7E14@sda21(r0)
    gc_env.cr[0] = isnan(gc_env.f[2]) || isnan(gc_env.f[0]) ? 0x1 : (gc_env.f[2] < gc_env.f[0] ? 0x8 : (gc_env.f[2] > gc_env.f[0] ? 0x4 : 0x2)); // fcmpo cr0, f2, f0
    if (gc_env.cr[0] >= 0) goto L_80029A24;
    gc_env.f[2] = -gc_env.f[2]; // fneg f2, f2
    L_80029A24:
    gc_env.f[1] = cm_804D7E40; // lfs f1, cm_804D7E40@sda21(r0)
    gc_env.cr[0] = isnan(gc_env.f[2]) || isnan(gc_env.f[1]) ? 0x1 : (gc_env.f[2] < gc_env.f[1] ? 0x8 : (gc_env.f[2] > gc_env.f[1] ? 0x4 : 0x2)); // fcmpo cr0, f2, f1
    if (gc_env.cr[0] >= 0) goto L_80029A38;
    gc_env.f[3] = cm_804D7E14; // lfs f3, cm_804D7E14@sda21(r0)
    goto L_80029A58;
    L_80029A38:
    gc_env.f[0] = cm_804D7E44; // lfs f0, cm_804D7E44@sda21(r0)
    gc_env.cr[0] = isnan(gc_env.f[2]) || isnan(gc_env.f[0]) ? 0x1 : (gc_env.f[2] < gc_env.f[0] ? 0x8 : (gc_env.f[2] > gc_env.f[0] ? 0x4 : 0x2)); // fcmpo cr0, f2, f0
    if (gc_env.cr[0] & (0x8 | 0x2)) goto L_80029A4C; // ble .L_80029A4C
    gc_env.f[3] = cm_804D7E04; // lfs f3, cm_804D7E04@sda21(r0)
    goto L_80029A58;
    L_80029A4C:
    gc_env.f[1] = (float)gc_env.f[2] - (float)gc_env.f[1]; // fsubs f1, f2, f1
    gc_env.f[0] = cm_804D7E48; // lfs f0, cm_804D7E48@sda21(r0)
    gc_env.f[3] = (float)gc_env.f[1] / (float)gc_env.f[0]; // fdivs f3, f1, f0
    L_80029A58:
    float temp = (float)gc_env.f[31]; // stfs f31, 0x0(r28)
    gc_mem_write32(gc_env.ram, gc_env.r[28] + 0x0, *(uint32_t*)&temp);
    gc_env.f[1] = cm_804D7E50; // lfs f1, cm_804D7E50@sda21(r0)
    gc_env.f[0] = cm_804D7E4C; // lfs f0, cm_804D7E4C@sda21(r0)
    gc_env.f[0] = (float)gc_env.f[1] * (float)gc_env.f[3] + (float)gc_env.f[0]; // fmadds f0, f1, f3, f0
    gc_env.f[0] = (float)gc_env.f[30] - (float)gc_env.f[0]; // fsubs f0, f30, f0
    float temp = (float)gc_env.f[0]; // stfs f0, 0x4(r28)
    gc_mem_write32(gc_env.ram, gc_env.r[28] + 0x4, *(uint32_t*)&temp);
    float temp = (float)gc_env.f[29]; // stfs f29, 0x8(r28)
    gc_mem_write32(gc_env.ram, gc_env.r[28] + 0x8, *(uint32_t*)&temp);
    float temp = (float)gc_env.f[28]; // stfs f28, 0xC(r28)
    gc_mem_write32(gc_env.ram, gc_env.r[28] + 0xC, *(uint32_t*)&temp);
    gc_mem_write32(gc_env.ram, gc_env.r[28] + 0x10, gc_env.r[30]);
    float temp = (float)gc_env.f[2]; // stfs f2, 0x14(r28)
    gc_mem_write32(gc_env.ram, gc_env.r[28] + 0x14, *(uint32_t*)&temp);
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0xb4);
    uint64_t temp = gc_mem_read64(gc_env.ram, gc_env.r[1] + 0xA8); // lfd f31, 0xA8(r1)
    gc_env.d[31] = *(double*)&temp;
    uint64_t temp = gc_mem_read64(gc_env.ram, gc_env.r[1] + 0xA0); // lfd f30, 0xA0(r1)
    gc_env.d[30] = *(double*)&temp;
    uint64_t temp = gc_mem_read64(gc_env.ram, gc_env.r[1] + 0x98); // lfd f29, 0x98(r1)
    gc_env.d[29] = *(double*)&temp;
    uint64_t temp = gc_mem_read64(gc_env.ram, gc_env.r[1] + 0x90); // lfd f28, 0x90(r1)
    gc_env.d[28] = *(double*)&temp;
    uint64_t temp = gc_mem_read64(gc_env.ram, gc_env.r[1] + 0x88); // lfd f27, 0x88(r1)
    gc_env.d[27] = *(double*)&temp;
    uint64_t temp = gc_mem_read64(gc_env.ram, gc_env.r[1] + 0x80); // lfd f26, 0x80(r1)
    gc_env.d[26] = *(double*)&temp;
    gc_env.r[27] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x6C); // lmw r27, 0x6C(r1)
    gc_env.r[28] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x70); // lmw r27, 0x6C(r1)
    gc_env.r[29] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x74); // lmw r27, 0x6C(r1)
    gc_env.r[30] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x78); // lmw r27, 0x6C(r1)
    gc_env.r[31] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x7C); // lmw r27, 0x6C(r1)
    gc_env.r[1] += 176; // addi r1, r1, 0xb0
    gc_env.lr = gc_env.r[0]; // Move to link register
    return;
}

// Function: Camera_80029AAC
void Camera_80029AAC(void) {
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[3] + 0x10);
    gc_env.cr[0] = (gc_env.r[0] == 0x0) ? 0 : (gc_env.r[0] < 0x0 ? -1 : 1); // Compare with immediate
    if (gc_env.cr[0] == 0) goto L_80029AEC;
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[3] + 0x8); // lfs f4, 0x8(r3)
    gc_env.f[4] = *(float*)&temp;
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[3] + 0x0); // lfs f3, 0x0(r3)
    gc_env.f[3] = *(float*)&temp;
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[3] + 0xC); // lfs f2, 0xC(r3)
    gc_env.f[2] = *(float*)&temp;
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[3] + 0x4); // lfs f0, 0x4(r3)
    gc_env.f[0] = *(float*)&temp;
    gc_env.f[3] = (float)gc_env.f[4] - (float)gc_env.f[3]; // fsubs f3, f4, f3
    gc_env.f[0] = (float)gc_env.f[2] - (float)gc_env.f[0]; // fsubs f0, f2, f0
    gc_env.f[2] = gc_env.f[3]; // fmr f2, f3
    gc_env.cr[0] = isnan(gc_env.f[3]) || isnan(gc_env.f[0]) ? 0x1 : (gc_env.f[3] < gc_env.f[0] ? 0x8 : (gc_env.f[3] > gc_env.f[0] ? 0x4 : 0x2)); // fcmpo cr0, f3, f0
    if (gc_env.cr[0] & (0x8 | 0x2)) goto L_80029AE4; // ble .L_80029AE4
    gc_env.f[5] = gc_env.f[2]; // fmr f5, f2
    goto L_80029AF0;
    L_80029AE4:
    gc_env.f[5] = gc_env.f[0]; // fmr f5, f0
    goto L_80029AF0;
    L_80029AEC:
    gc_env.f[5] = cm_804D7E54; // lfs f5, cm_804D7E54@sda21(r0)
    L_80029AF0:
    gc_env.r[3] = ((uint32_t)&cm_803BCCA0 >> 16) & 0xFFFF; // lis r3, cm_803BCCA0@ha
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[4] + 0xC); // lfs f3, 0xC(r4)
    gc_env.f[3] = *(float*)&temp;
    gc_env.r[3] = gc_env.r[3] + ((uint32_t)&cm_803BCCA0 & 0xFFFF); // addi r3, r3, cm_803BCCA0@l
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[4] + 0x0); // lfs f0, 0x0(r4)
    gc_env.f[0] = *(float*)&temp;
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[3] + 0x38); // lfs f4, 0x38(r3)
    gc_env.f[4] = *(float*)&temp;
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[4] + 0x10); // lfs f2, 0x10(r4)
    gc_env.f[2] = *(float*)&temp;
    gc_env.f[6] = (float)gc_env.f[3] - (float)gc_env.f[0]; // fsubs f6, f3, f0
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[4] + 0x4); // lfs f0, 0x4(r4)
    gc_env.f[0] = *(float*)&temp;
    gc_env.cr[0] = isnan(gc_env.f[5]) || isnan(gc_env.f[4]) ? 0x1 : (gc_env.f[5] < gc_env.f[4] ? 0x8 : (gc_env.f[5] > gc_env.f[4] ? 0x4 : 0x2)); // fcmpo cr0, f5, f4
    gc_env.f[7] = (float)gc_env.f[2] - (float)gc_env.f[0]; // fsubs f7, f2, f0
    if (gc_env.cr[0] & (0x8 | 0x2)) goto L_80029B24; // ble .L_80029B24
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[3] + 0x30); // lfs f2, 0x30(r3)
    gc_env.f[2] = *(float*)&temp;
    goto L_80029B54;
    L_80029B24:
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[3] + 0x34); // lfs f0, 0x34(r3)
    gc_env.f[0] = *(float*)&temp;
    gc_env.cr[0] = isnan(gc_env.f[5]) || isnan(gc_env.f[0]) ? 0x1 : (gc_env.f[5] < gc_env.f[0] ? 0x8 : (gc_env.f[5] > gc_env.f[0] ? 0x4 : 0x2)); // fcmpo cr0, f5, f0
    if (gc_env.cr[0] >= 0) goto L_80029B38;
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[3] + 0x2C); // lfs f2, 0x2C(r3)
    gc_env.f[2] = *(float*)&temp;
    goto L_80029B54;
    L_80029B38:
    gc_env.f[2] = (float)gc_env.f[5] - (float)gc_env.f[0]; // fsubs f2, f5, f0
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[3] + 0x2C); // lfs f5, 0x2C(r3)
    gc_env.f[5] = *(float*)&temp;
    gc_env.f[0] = (float)gc_env.f[4] - (float)gc_env.f[0]; // fsubs f0, f4, f0
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[3] + 0x30); // lfs f3, 0x30(r3)
    gc_env.f[3] = *(float*)&temp;
    gc_env.f[3] = (float)gc_env.f[3] - (float)gc_env.f[5]; // fsubs f3, f3, f5
    gc_env.f[0] = (float)gc_env.f[2] / (float)gc_env.f[0]; // fdivs f0, f2, f0
    gc_env.f[2] = (float)gc_env.f[3] * (float)gc_env.f[0] + (float)gc_env.f[5]; // fmadds f2, f3, f0, f5
    L_80029B54:
    gc_env.r[3] = ((uint32_t)&cm_80452C68 >> 16) & 0xFFFF; // lis r3, cm_80452C68@ha
    gc_env.f[0] = cm_804D7E58; // lfs f0, cm_804D7E58@sda21(r0)
    gc_env.r[3] = gc_env.r[3] + ((uint32_t)&cm_80452C68 & 0xFFFF); // addi r3, r3, cm_80452C68@l
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[3] + 0x2BC); // lfs f3, 0x2BC(r3)
    gc_env.f[3] = *(float*)&temp;
    gc_env.cr[0] = isnan(gc_env.f[3]) || isnan(gc_env.f[0]) ? 0x1 : (gc_env.f[3] < gc_env.f[0] ? 0x8 : (gc_env.f[3] > gc_env.f[0] ? 0x4 : 0x2)); // fcmpo cr0, f3, f0
    if (gc_env.cr[0] & (0x8 | 0x2)) goto L_80029B78; // ble .L_80029B78
    gc_env.f[0] = cm_804D7E04; // lfs f0, cm_804D7E04@sda21(r0)
    gc_env.f[3] = (float)gc_env.f[0] / (float)gc_env.f[3]; // fdivs f3, f0, f3
    goto L_80029B7C;
    L_80029B78:
    gc_env.f[3] = cm_804D7E5C; // lfs f3, cm_804D7E5C@sda21(r0)
    L_80029B7C:
    gc_env.f[1] = (float)gc_env.f[2] * (float)gc_env.f[1]; // fmuls f1, f2, f1
    gc_env.f[0] = cm_804D7E04; // lfs f0, cm_804D7E04@sda21(r0)
    gc_env.f[1] = (float)gc_env.f[3] * (float)gc_env.f[1]; // fmuls f1, f3, f1
    gc_env.cr[0] = isnan(gc_env.f[1]) || isnan(gc_env.f[0]) ? 0x1 : (gc_env.f[1] < gc_env.f[0] ? 0x8 : (gc_env.f[1] > gc_env.f[0] ? 0x4 : 0x2)); // fcmpo cr0, f1, f0
    if (gc_env.cr[0] & (0x8 | 0x2)) goto L_80029B98; // ble .L_80029B98
    gc_env.f[1] = gc_env.f[0]; // fmr f1, f0
    goto L_80029BA8;
    L_80029B98:
    gc_env.f[0] = cm_804D7E58; // lfs f0, cm_804D7E58@sda21(r0)
    gc_env.cr[0] = isnan(gc_env.f[1]) || isnan(gc_env.f[0]) ? 0x1 : (gc_env.f[1] < gc_env.f[0] ? 0x8 : (gc_env.f[1] > gc_env.f[0] ? 0x4 : 0x2)); // fcmpo cr0, f1, f0
    if (gc_env.cr[0] >= 0) goto L_80029BA8;
    gc_env.f[1] = gc_env.f[0]; // fmr f1, f0
    L_80029BA8:
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[4] + 0x0); // lfs f0, 0x0(r4)
    gc_env.f[0] = *(float*)&temp;
    gc_env.f[0] = (float)gc_env.f[6] * (float)gc_env.f[1] + (float)gc_env.f[0]; // fmadds f0, f6, f1, f0
    float temp = (float)gc_env.f[0]; // stfs f0, 0x0(r4)
    gc_mem_write32(gc_env.ram, gc_env.r[4] + 0x0, *(uint32_t*)&temp);
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[4] + 0x4); // lfs f0, 0x4(r4)
    gc_env.f[0] = *(float*)&temp;
    gc_env.f[0] = (float)gc_env.f[7] * (float)gc_env.f[1] + (float)gc_env.f[0]; // fmadds f0, f7, f1, f0
    float temp = (float)gc_env.f[0]; // stfs f0, 0x4(r4)
    gc_mem_write32(gc_env.ram, gc_env.r[4] + 0x4, *(uint32_t*)&temp);
    return;
}

// Function: Camera_80029BC4
void Camera_80029BC4(void) {
    gc_env.r[0] = gc_env.lr; // Move from link register
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x4, gc_env.r[0]);
    gc_mem_write32(gc_env.ram, gc_env.r[1] + -0x20, gc_env.r[1]);
    gc_env.r[1] = gc_env.r[1] + -0x20;
    uint64_t temp;
    memcpy(&temp, &gc_env.f[31], sizeof(double));
    gc_mem_write64(gc_env.ram, gc_env.r[1] + 0x18, temp); // stfd f31, 0x18(r1)
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x14, gc_env.r[31]);
    gc_env.r[31] = gc_env.r[4]; // Move register
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x10, gc_env.r[30]);
    gc_env.r[30] = gc_env.r[3]; // Move register
    gc_env.f[1] = cm_804D7E60; // lfs f1, cm_804D7E60@sda21(r0)
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[4] + 0x34); // lfs f0, 0x34(r4)
    gc_env.f[0] = *(float*)&temp;
    gc_env.f[1] = (float)gc_env.f[1] * (float)gc_env.f[0]; // fmuls f1, f1, f0
    tanf();
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[30] + 0xC); // lfs f3, 0xC(r30)
    gc_env.f[3] = *(float*)&temp;
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[30] + 0x4); // lfs f0, 0x4(r30)
    gc_env.f[0] = *(float*)&temp;
    gc_env.f[2] = cm_804D7E60; // lfs f2, cm_804D7E60@sda21(r0)
    gc_env.f[3] = (float)gc_env.f[3] - (float)gc_env.f[0]; // fsubs f3, f3, f0
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[31] + 0x34); // lfs f0, 0x34(r31)
    gc_env.f[0] = *(float*)&temp;
    gc_env.f[31] = (float)gc_env.f[3] / (float)gc_env.f[1]; // fdivs f31, f3, f1
    gc_env.f[1] = (float)gc_env.f[2] * (float)gc_env.f[0]; // fmuls f1, f2, f0
    tanf();
    gc_env.r[3] = ((uint32_t)&cm_803BCB64 >> 16) & 0xFFFF; // lis r3, cm_803BCB64@ha
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[30] + 0x8); // lfs f2, 0x8(r30)
    gc_env.f[2] = *(float*)&temp;
    gc_env.r[3] = gc_env.r[3] + ((uint32_t)&cm_803BCB64 & 0xFFFF); // addi r3, r3, cm_803BCB64@l
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[30] + 0x0); // lfs f0, 0x0(r30)
    gc_env.f[0] = *(float*)&temp;
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[3] + 0x34); // lfs f3, 0x34(r3)
    gc_env.f[3] = *(float*)&temp;
    gc_env.f[0] = (float)gc_env.f[2] - (float)gc_env.f[0]; // fsubs f0, f2, f0
    gc_env.f[1] = (float)gc_env.f[3] * (float)gc_env.f[1]; // fmuls f1, f3, f1
    gc_env.f[0] = (float)gc_env.f[0] / (float)gc_env.f[1]; // fdivs f0, f0, f1
    gc_env.cr[0] = isnan(gc_env.f[0]) || isnan(gc_env.f[31]) ? 0x1 : (gc_env.f[0] < gc_env.f[31] ? 0x8 : (gc_env.f[0] > gc_env.f[31] ? 0x4 : 0x2)); // fcmpo cr0, f0, f31
    if (gc_env.cr[0] & (0x8 | 0x2)) goto L_80029C40; // ble .L_80029C40
    gc_env.f[31] = gc_env.f[0]; // fmr f31, f0
    L_80029C40:
    Stage_GetCamZoomRate();
    gc_env.cr[0] = isnan(gc_env.f[31]) || isnan(gc_env.f[1]) ? 0x1 : (gc_env.f[31] < gc_env.f[1] ? 0x8 : (gc_env.f[31] > gc_env.f[1] ? 0x4 : 0x2)); // fcmpo cr0, f31, f1
    if (gc_env.cr[0] >= 0) goto L_80029C54;
    Stage_GetCamZoomRate();
    gc_env.f[31] = gc_env.f[1]; // fmr f31, f1
    L_80029C54:
    Stage_GetCamMaxDepth();
    gc_env.cr[0] = isnan(gc_env.f[31]) || isnan(gc_env.f[1]) ? 0x1 : (gc_env.f[31] < gc_env.f[1] ? 0x8 : (gc_env.f[31] > gc_env.f[1] ? 0x4 : 0x2)); // fcmpo cr0, f31, f1
    if (gc_env.cr[0] & (0x8 | 0x2)) goto L_80029C68; // ble .L_80029C68
    Stage_GetCamMaxDepth();
    gc_env.f[31] = gc_env.f[1]; // fmr f31, f1
    L_80029C68:
    float temp = (float)gc_env.f[31]; // stfs f31, 0x14(r30)
    gc_mem_write32(gc_env.ram, gc_env.r[30] + 0x14, *(uint32_t*)&temp);
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x24);
    uint64_t temp = gc_mem_read64(gc_env.ram, gc_env.r[1] + 0x18); // lfd f31, 0x18(r1)
    gc_env.d[31] = *(double*)&temp;
    gc_env.r[31] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x14);
    gc_env.r[30] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x10);
    gc_env.r[1] += 32; // addi r1, r1, 0x20
    gc_env.lr = gc_env.r[0]; // Move to link register
    return;
}

// Function: Camera_80029C88
void Camera_80029C88(void) {
    gc_env.r[3] = ((uint32_t)&cm_803BCCA0 >> 16) & 0xFFFF; // lis r3, cm_803BCCA0@ha
    gc_env.f[0] = cm_804D7E04; // lfs f0, cm_804D7E04@sda21(r0)
    gc_env.r[3] = gc_env.r[3] + ((uint32_t)&cm_803BCCA0 & 0xFFFF); // addi r3, r3, cm_803BCCA0@l
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[4] + 0x24); // lfs f6, 0x24(r4)
    gc_env.f[6] = *(float*)&temp;
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[3] + 0x3C); // lfs f2, 0x3C(r3)
    gc_env.f[2] = *(float*)&temp;
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[4] + 0x18); // lfs f5, 0x18(r4)
    gc_env.f[5] = *(float*)&temp;
    gc_env.f[7] = (float)gc_env.f[2] * (float)gc_env.f[1]; // fmuls f7, f2, f1
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[4] + 0x28); // lfs f4, 0x28(r4)
    gc_env.f[4] = *(float*)&temp;
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[4] + 0x1C); // lfs f3, 0x1C(r4)
    gc_env.f[3] = *(float*)&temp;
    gc_env.f[5] = (float)gc_env.f[6] - (float)gc_env.f[5]; // fsubs f5, f6, f5
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[4] + 0x2C); // lfs f2, 0x2C(r4)
    gc_env.f[2] = *(float*)&temp;
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[4] + 0x20); // lfs f1, 0x20(r4)
    gc_env.f[1] = *(float*)&temp;
    gc_env.cr[0] = isnan(gc_env.f[7]) || isnan(gc_env.f[0]) ? 0x1 : (gc_env.f[7] < gc_env.f[0] ? 0x8 : (gc_env.f[7] > gc_env.f[0] ? 0x4 : 0x2)); // fcmpo cr0, f7, f0
    gc_env.f[6] = gc_env.f[7]; // fmr f6, f7
    gc_env.f[3] = (float)gc_env.f[4] - (float)gc_env.f[3]; // fsubs f3, f4, f3
    gc_env.f[1] = (float)gc_env.f[2] - (float)gc_env.f[1]; // fsubs f1, f2, f1
    if (gc_env.cr[0] & (0x8 | 0x2)) goto L_80029CD0; // ble .L_80029CD0
    gc_env.f[6] = gc_env.f[0]; // fmr f6, f0
    L_80029CD0:
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[4] + 0x18); // lfs f0, 0x18(r4)
    gc_env.f[0] = *(float*)&temp;
    gc_env.f[0] = (float)gc_env.f[5] * (float)gc_env.f[6] + (float)gc_env.f[0]; // fmadds f0, f5, f6, f0
    float temp = (float)gc_env.f[0]; // stfs f0, 0x18(r4)
    gc_mem_write32(gc_env.ram, gc_env.r[4] + 0x18, *(uint32_t*)&temp);
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[4] + 0x1C); // lfs f0, 0x1C(r4)
    gc_env.f[0] = *(float*)&temp;
    gc_env.f[0] = (float)gc_env.f[3] * (float)gc_env.f[6] + (float)gc_env.f[0]; // fmadds f0, f3, f6, f0
    float temp = (float)gc_env.f[0]; // stfs f0, 0x1C(r4)
    gc_mem_write32(gc_env.ram, gc_env.r[4] + 0x1C, *(uint32_t*)&temp);
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[4] + 0x20); // lfs f0, 0x20(r4)
    gc_env.f[0] = *(float*)&temp;
    gc_env.f[0] = (float)gc_env.f[1] * (float)gc_env.f[6] + (float)gc_env.f[0]; // fmadds f0, f1, f6, f0
    float temp = (float)gc_env.f[0]; // stfs f0, 0x20(r4)
    gc_mem_write32(gc_env.ram, gc_env.r[4] + 0x20, *(uint32_t*)&temp);
    return;
}

// Function: Camera_80029CF8
void Camera_80029CF8(void) {
    gc_env.r[0] = gc_env.lr; // Move from link register
    gc_env.r[5] = ((uint32_t)&cm_803BCB18 >> 16) & 0xFFFF; // lis r5, cm_803BCB18@ha
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x4, gc_env.r[0]);
    gc_mem_write32(gc_env.ram, gc_env.r[1] + -0x80, gc_env.r[1]);
    gc_env.r[1] = gc_env.r[1] + -0x80;
    uint64_t temp;
    memcpy(&temp, &gc_env.f[31], sizeof(double));
    gc_mem_write64(gc_env.ram, gc_env.r[1] + 0x78, temp); // stfd f31, 0x78(r1)
    uint64_t temp;
    memcpy(&temp, &gc_env.f[30], sizeof(double));
    gc_mem_write64(gc_env.ram, gc_env.r[1] + 0x70, temp); // stfd f30, 0x70(r1)
    uint64_t temp;
    memcpy(&temp, &gc_env.f[29], sizeof(double));
    gc_mem_write64(gc_env.ram, gc_env.r[1] + 0x68, temp); // stfd f29, 0x68(r1)
    uint64_t temp;
    memcpy(&temp, &gc_env.f[28], sizeof(double));
    gc_mem_write64(gc_env.ram, gc_env.r[1] + 0x60, temp); // stfd f28, 0x60(r1)
    uint64_t temp;
    memcpy(&temp, &gc_env.f[27], sizeof(double));
    gc_mem_write64(gc_env.ram, gc_env.r[1] + 0x58, temp); // stfd f27, 0x58(r1)
    uint64_t temp;
    memcpy(&temp, &gc_env.f[26], sizeof(double));
    gc_mem_write64(gc_env.ram, gc_env.r[1] + 0x50, temp); // stfd f26, 0x50(r1)
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x4c, gc_env.r[31]);
    gc_env.r[31] = gc_env.r[5] + ((uint32_t)&cm_803BCB18 & 0xFFFF); // addi r31, r5, cm_803BCB18@l
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x48, gc_env.r[30]);
    gc_env.r[30] = gc_env.r[4] + 0; // addi r30, r4, 0x0
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x44, gc_env.r[29]);
    gc_env.r[29] = gc_env.r[3] + 0; // addi r29, r3, 0x0
    gc_env.r[3] = gc_env.r[1] + 36; // addi r3, r1, 0x24
    Stage_UnkSetVec3TCam_Offset();
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[29] + 0x8); // lfs f1, 0x8(r29)
    gc_env.f[1] = *(float*)&temp;
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[29] + 0x0); // lfs f0, 0x0(r29)
    gc_env.f[0] = *(float*)&temp;
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[29] + 0xC); // lfs f4, 0xC(r29)
    gc_env.f[4] = *(float*)&temp;
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[29] + 0x4); // lfs f6, 0x4(r29)
    gc_env.f[6] = *(float*)&temp;
    gc_env.f[1] = (float)gc_env.f[1] - (float)gc_env.f[0]; // fsubs f1, f1, f0
    gc_env.f[0] = (float)gc_env.f[4] - (float)gc_env.f[6]; // fsubs f0, f4, f6
    gc_env.cr[0] = isnan(gc_env.f[1]) || isnan(gc_env.f[0]) ? 0x1 : (gc_env.f[1] < gc_env.f[0] ? 0x8 : (gc_env.f[1] > gc_env.f[0] ? 0x4 : 0x2)); // fcmpo cr0, f1, f0
    if (gc_env.cr[0] & (0x8 | 0x2)) goto L_80029D64; // ble .L_80029D64
    goto L_80029D68;
    L_80029D64:
    gc_env.f[1] = gc_env.f[0]; // fmr f1, f0
    L_80029D68:
    gc_env.r[3] = ((uint32_t)&cm_803BCCA0 >> 16) & 0xFFFF; // lis r3, cm_803BCCA0@ha
    gc_env.r[3] = gc_env.r[3] + ((uint32_t)&cm_803BCCA0 & 0xFFFF); // addi r3, r3, cm_803BCCA0@l
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[3] + 0x28); // lfs f2, 0x28(r3)
    gc_env.f[2] = *(float*)&temp;
    gc_env.cr[0] = isnan(gc_env.f[1]) || isnan(gc_env.f[2]) ? 0x1 : (gc_env.f[1] < gc_env.f[2] ? 0x8 : (gc_env.f[1] > gc_env.f[2] ? 0x4 : 0x2)); // fcmpo cr0, f1, f2
    if (gc_env.cr[0] & (0x8 | 0x2)) goto L_80029D84; // ble .L_80029D84
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[3] + 0x20); // lfs f3, 0x20(r3)
    gc_env.f[3] = *(float*)&temp;
    goto L_80029DB4;
    L_80029D84:
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[3] + 0x24); // lfs f0, 0x24(r3)
    gc_env.f[0] = *(float*)&temp;
    gc_env.cr[0] = isnan(gc_env.f[1]) || isnan(gc_env.f[0]) ? 0x1 : (gc_env.f[1] < gc_env.f[0] ? 0x8 : (gc_env.f[1] > gc_env.f[0] ? 0x4 : 0x2)); // fcmpo cr0, f1, f0
    if (gc_env.cr[0] >= 0) goto L_80029D98;
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[3] + 0x1C); // lfs f3, 0x1C(r3)
    gc_env.f[3] = *(float*)&temp;
    goto L_80029DB4;
    L_80029D98:
    gc_env.f[1] = (float)gc_env.f[1] - (float)gc_env.f[0]; // fsubs f1, f1, f0
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[3] + 0x1C); // lfs f3, 0x1C(r3)
    gc_env.f[3] = *(float*)&temp;
    gc_env.f[0] = (float)gc_env.f[2] - (float)gc_env.f[0]; // fsubs f0, f2, f0
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[3] + 0x20); // lfs f2, 0x20(r3)
    gc_env.f[2] = *(float*)&temp;
    gc_env.f[2] = (float)gc_env.f[2] - (float)gc_env.f[3]; // fsubs f2, f2, f3
    gc_env.f[0] = (float)gc_env.f[1] / (float)gc_env.f[0]; // fdivs f0, f1, f0
    gc_env.f[3] = (float)gc_env.f[2] * (float)gc_env.f[0] + (float)gc_env.f[3]; // fmadds f3, f2, f0, f3
    L_80029DB4:
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x28); // lfs f5, 0x28(r1)
    gc_env.f[5] = *(float*)&temp;
    gc_env.f[0] = cm_804D7E30; // lfs f0, cm_804D7E30@sda21(r0)
    gc_env.f[2] = (float)gc_env.f[6] - (float)gc_env.f[5]; // fsubs f2, f6, f5
    gc_env.f[1] = (float)gc_env.f[4] - (float)gc_env.f[5]; // fsubs f1, f4, f5
    gc_env.f[0] = (float)gc_env.f[0] - (float)gc_env.f[3]; // fsubs f0, f0, f3
    gc_env.f[1] = (float)gc_env.f[2] + (float)gc_env.f[1]; // fadds f1, f2, f1
    gc_env.f[29] = (float)gc_env.f[1] * (float)gc_env.f[0] + (float)gc_env.f[5]; // fmadds f29, f1, f0, f5
    Stage_GetCamInfoX24();
    gc_env.r[3] = ((uint32_t)&cm_803BCCA0 >> 16) & 0xFFFF; // lis r3, cm_803BCCA0@ha
    gc_env.f[2] = cm_804D7E60; // lfs f2, cm_804D7E60@sda21(r0)
    gc_env.r[3] = gc_env.r[3] + ((uint32_t)&cm_803BCCA0 & 0xFFFF); // addi r3, r3, cm_803BCCA0@l
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[3] + 0x8); // lfs f3, 0x8(r3)
    gc_env.f[3] = *(float*)&temp;
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[3] + 0xC); // lfs f0, 0xC(r3)
    gc_env.f[0] = *(float*)&temp;
    gc_env.f[3] = (float)gc_env.f[29] + (float)gc_env.f[3]; // fadds f3, f29, f3
    gc_env.f[4] = (float)gc_env.f[2] * (float)gc_env.f[0]; // fmuls f4, f2, f0
    gc_env.f[0] = (float)gc_env.f[3] * (float)gc_env.f[1]; // fmuls f0, f3, f1
    gc_env.f[0] = (float)gc_env.f[2] * (float)gc_env.f[0]; // fmuls f0, f2, f0
    gc_env.f[29] = -gc_env.f[0]; // fneg f29, f0
    gc_env.cr[0] = isnan(gc_env.f[29]) || isnan(gc_env.f[4]) ? 0x1 : (gc_env.f[29] < gc_env.f[4] ? 0x8 : (gc_env.f[29] > gc_env.f[4] ? 0x4 : 0x2)); // fcmpo cr0, f29, f4
    if (gc_env.cr[0] & (0x8 | 0x2)) goto L_80029E08; // ble .L_80029E08
    gc_env.f[29] = gc_env.f[4]; // fmr f29, f4
    L_80029E08:
    gc_env.r[3] = ((uint32_t)&cm_803BCCA0 >> 16) & 0xFFFF; // lis r3, cm_803BCCA0@ha
    gc_env.f[1] = cm_804D7E60; // lfs f1, cm_804D7E60@sda21(r0)
    gc_env.r[3] = gc_env.r[3] + ((uint32_t)&cm_803BCCA0 & 0xFFFF); // addi r3, r3, cm_803BCCA0@l
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[3] + 0x10); // lfs f0, 0x10(r3)
    gc_env.f[0] = *(float*)&temp;
    gc_env.f[0] = (float)gc_env.f[1] * (float)gc_env.f[0]; // fmuls f0, f1, f0
    gc_env.cr[0] = isnan(gc_env.f[29]) || isnan(gc_env.f[0]) ? 0x1 : (gc_env.f[29] < gc_env.f[0] ? 0x8 : (gc_env.f[29] > gc_env.f[0] ? 0x4 : 0x2)); // fcmpo cr0, f29, f0
    if (gc_env.cr[0] >= 0) goto L_80029E28;
    gc_env.f[29] = gc_env.f[0]; // fmr f29, f0
    L_80029E28:
    Stage_GetCamPanAngleRadians();
    gc_env.f[2] = cm_804D7E60; // lfs f2, cm_804D7E60@sda21(r0)
    gc_env.f[29] = (float)gc_env.f[29] + (float)gc_env.f[1]; // fadds f29, f29, f1
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[30] + 0x30); // lfs f0, 0x30(r30)
    gc_env.f[0] = *(float*)&temp;
    gc_env.f[3] = cm_804D7E30; // lfs f3, cm_804D7E30@sda21(r0)
    gc_env.f[1] = (float)gc_env.f[2] * (float)gc_env.f[0]; // fmuls f1, f2, f0
    gc_env.f[0] = cm_804D7E64; // lfs f0, cm_804D7E64@sda21(r0)
    gc_env.f[30] = gc_env.f[29]; // fmr f30, f29
    gc_env.f[1] = (float)gc_env.f[3] * (float)gc_env.f[1] + (float)gc_env.f[29]; // fmadds f1, f3, f1, f29
    gc_env.cr[0] = isnan(gc_env.f[1]) || isnan(gc_env.f[0]) ? 0x1 : (gc_env.f[1] < gc_env.f[0] ? 0x8 : (gc_env.f[1] > gc_env.f[0] ? 0x4 : 0x2)); // fcmpo cr0, f1, f0
    gc_env.f[28] = gc_env.f[1]; // fmr f28, f1
    if (gc_env.cr[0] & 0x8) goto L_80029E68; // blt .L_80029E68
    gc_env.r[3] = gc_env.r[31] + 184; // addi r3, r31, 0xb8
    gc_env.r[5] = gc_env.r[31] + 196; // addi r5, r31, 0xc4
    gc_env.r[4] = 0x4fa;
    __assert();
    L_80029E68:
    gc_env.f[1] = cm_804D7E60; // lfs f1, cm_804D7E60@sda21(r0)
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[30] + 0x30); // lfs f0, 0x30(r30)
    gc_env.f[0] = *(float*)&temp;
    gc_env.f[2] = cm_804D7E30; // lfs f2, cm_804D7E30@sda21(r0)
    gc_env.f[1] = (float)gc_env.f[1] * (float)gc_env.f[0]; // fmuls f1, f1, f0
    gc_env.f[0] = cm_804D7E64; // lfs f0, cm_804D7E64@sda21(r0)
    gc_env.f[1] = (float)gc_env.f[2] * (float)gc_env.f[1] - (float)gc_env.f[29]; // fmsubs f1, f2, f1, f29
    gc_env.cr[0] = isnan(gc_env.f[1]) || isnan(gc_env.f[0]) ? 0x1 : (gc_env.f[1] < gc_env.f[0] ? 0x8 : (gc_env.f[1] > gc_env.f[0] ? 0x4 : 0x2)); // fcmpo cr0, f1, f0
    gc_env.f[29] = gc_env.f[1]; // fmr f29, f1
    if (gc_env.cr[0] & 0x8) goto L_80029E9C; // blt .L_80029E9C
    gc_env.r[3] = gc_env.r[31] + 184; // addi r3, r31, 0xb8
    gc_env.r[5] = gc_env.r[31] + 224; // addi r5, r31, 0xe0
    gc_env.r[4] = 0x4fb;
    __assert();
    L_80029E9C:
    gc_env.f[1] = gc_env.f[28]; // fmr f1, f28
    tanf();
    gc_env.f[31] = gc_env.f[1]; // fmr f31, f1
    gc_env.f[1] = gc_env.f[29]; // fmr f1, f29
    tanf();
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[29] + 0xC); // lfs f2, 0xC(r29)
    gc_env.f[2] = *(float*)&temp;
    gc_env.f[0] = (float)gc_env.f[31] + (float)gc_env.f[1]; // fadds f0, f31, f1
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[29] + 0x4); // lfs f1, 0x4(r29)
    gc_env.f[1] = *(float*)&temp;
    gc_env.f[1] = (float)gc_env.f[2] - (float)gc_env.f[1]; // fsubs f1, f2, f1
    gc_env.f[29] = (float)gc_env.f[1] / (float)gc_env.f[0]; // fdivs f29, f1, f0
    Stage_GetCamBoundsBottomOffset();
    Stage_GetCamBoundsTopOffset();
    gc_env.f[1] = gc_env.f[30]; // fmr f1, f30
    tanf();
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[29] + 0xC); // lfs f0, 0xC(r29)
    gc_env.f[0] = *(float*)&temp;
    gc_env.f[30] = (float)gc_env.f[29] * (float)gc_env.f[1]; // fmuls f30, f29, f1
    gc_env.r[3] = gc_env.r[1] + 20; // addi r3, r1, 0x14
    gc_env.f[0] = -((float)gc_env.f[29] * (float)gc_env.f[31] - (float)gc_env.f[0]); // fnmsubs f0, f29, f31, f0
    gc_env.f[0] = (float)gc_env.f[30] + (float)gc_env.f[0]; // fadds f0, f30, f0
    float temp = (float)gc_env.f[0]; // stfs f0, 0x10(r30)
    gc_mem_write32(gc_env.ram, gc_env.r[30] + 0x10, *(uint32_t*)&temp);
    Stage_UnkSetVec3TCam_Offset();
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[29] + 0x0); // lfs f1, 0x0(r29)
    gc_env.f[1] = *(float*)&temp;
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[29] + 0x8); // lfs f0, 0x8(r29)
    gc_env.f[0] = *(float*)&temp;
    gc_env.f[2] = cm_804D7E30; // lfs f2, cm_804D7E30@sda21(r0)
    gc_env.f[0] = (float)gc_env.f[1] + (float)gc_env.f[0]; // fadds f0, f1, f0
    gc_env.f[31] = (float)gc_env.f[2] * (float)gc_env.f[0]; // fmuls f31, f2, f0
    Stage_GetCamInfoX20();
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x14); // lfs f0, 0x14(r1)
    gc_env.f[0] = *(float*)&temp;
    gc_env.r[3] = ((uint32_t)&cm_803BCCA0 >> 16) & 0xFFFF; // lis r3, cm_803BCCA0@ha
    gc_env.r[3] = gc_env.r[3] + ((uint32_t)&cm_803BCCA0 & 0xFFFF); // addi r3, r3, cm_803BCCA0@l
    gc_env.f[2] = cm_804D7E60; // lfs f2, cm_804D7E60@sda21(r0)
    gc_env.f[3] = (float)gc_env.f[31] - (float)gc_env.f[0]; // fsubs f3, f31, f0
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[3] + 0x14); // lfs f0, 0x14(r3)
    gc_env.f[0] = *(float*)&temp;
    gc_env.f[1] = (float)gc_env.f[3] * (float)gc_env.f[1]; // fmuls f1, f3, f1
    gc_env.f[3] = (float)gc_env.f[2] * (float)gc_env.f[0]; // fmuls f3, f2, f0
    gc_env.f[0] = (float)gc_env.f[2] * (float)gc_env.f[1]; // fmuls f0, f2, f1
    gc_env.f[31] = -gc_env.f[0]; // fneg f31, f0
    gc_env.cr[0] = isnan(gc_env.f[31]) || isnan(gc_env.f[3]) ? 0x1 : (gc_env.f[31] < gc_env.f[3] ? 0x8 : (gc_env.f[31] > gc_env.f[3] ? 0x4 : 0x2)); // fcmpo cr0, f31, f3
    if (gc_env.cr[0] & (0x8 | 0x2)) goto L_80029F3C; // ble .L_80029F3C
    gc_env.f[31] = gc_env.f[3]; // fmr f31, f3
    L_80029F3C:
    gc_env.r[3] = ((uint32_t)&cm_803BCCA0 >> 16) & 0xFFFF; // lis r3, cm_803BCCA0@ha
    gc_env.f[1] = cm_804D7E60; // lfs f1, cm_804D7E60@sda21(r0)
    gc_env.r[3] = gc_env.r[3] + ((uint32_t)&cm_803BCCA0 & 0xFFFF); // addi r3, r3, cm_803BCCA0@l
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[3] + 0x18); // lfs f0, 0x18(r3)
    gc_env.f[0] = *(float*)&temp;
    gc_env.f[0] = (float)gc_env.f[1] * (float)gc_env.f[0]; // fmuls f0, f1, f0
    gc_env.cr[0] = isnan(gc_env.f[31]) || isnan(gc_env.f[0]) ? 0x1 : (gc_env.f[31] < gc_env.f[0] ? 0x8 : (gc_env.f[31] > gc_env.f[0] ? 0x4 : 0x2)); // fcmpo cr0, f31, f0
    if (gc_env.cr[0] >= 0) goto L_80029F5C;
    gc_env.f[31] = gc_env.f[0]; // fmr f31, f0
    L_80029F5C:
    gc_env.f[1] = cm_804D7E60; // lfs f1, cm_804D7E60@sda21(r0)
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[30] + 0x30); // lfs f0, 0x30(r30)
    gc_env.f[0] = *(float*)&temp;
    gc_env.f[2] = cm_804D7E30; // lfs f2, cm_804D7E30@sda21(r0)
    gc_env.f[1] = (float)gc_env.f[1] * (float)gc_env.f[0]; // fmuls f1, f1, f0
    gc_env.f[0] = cm_804D7E64; // lfs f0, cm_804D7E64@sda21(r0)
    gc_env.f[1] = (float)gc_env.f[2] * (float)gc_env.f[1] - (float)gc_env.f[31]; // fmsubs f1, f2, f1, f31
    gc_env.cr[0] = isnan(gc_env.f[1]) || isnan(gc_env.f[0]) ? 0x1 : (gc_env.f[1] < gc_env.f[0] ? 0x8 : (gc_env.f[1] > gc_env.f[0] ? 0x4 : 0x2)); // fcmpo cr0, f1, f0
    gc_env.f[28] = gc_env.f[1]; // fmr f28, f1
    if (gc_env.cr[0] & 0x8) goto L_80029F90; // blt .L_80029F90
    gc_env.r[3] = gc_env.r[31] + 184; // addi r3, r31, 0xb8
    gc_env.r[5] = gc_env.r[31] + 252; // addi r5, r31, 0xfc
    gc_env.r[4] = 0x508;
    __assert();
    L_80029F90:
    gc_env.f[1] = cm_804D7E60; // lfs f1, cm_804D7E60@sda21(r0)
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[30] + 0x30); // lfs f0, 0x30(r30)
    gc_env.f[0] = *(float*)&temp;
    gc_env.f[2] = cm_804D7E30; // lfs f2, cm_804D7E30@sda21(r0)
    gc_env.f[1] = (float)gc_env.f[1] * (float)gc_env.f[0]; // fmuls f1, f1, f0
    gc_env.f[0] = cm_804D7E64; // lfs f0, cm_804D7E64@sda21(r0)
    gc_env.f[1] = (float)gc_env.f[2] * (float)gc_env.f[1] + (float)gc_env.f[31]; // fmadds f1, f2, f1, f31
    gc_env.cr[0] = isnan(gc_env.f[1]) || isnan(gc_env.f[0]) ? 0x1 : (gc_env.f[1] < gc_env.f[0] ? 0x8 : (gc_env.f[1] > gc_env.f[0] ? 0x4 : 0x2)); // fcmpo cr0, f1, f0
    gc_env.f[27] = gc_env.f[1]; // fmr f27, f1
    if (gc_env.cr[0] & 0x8) goto L_80029FC4; // blt .L_80029FC4
    gc_env.r[3] = gc_env.r[31] + 184; // addi r3, r31, 0xb8
    gc_env.r[5] = gc_env.r[31] + 280; // addi r5, r31, 0x118
    gc_env.r[4] = 0x509;
    __assert();
    L_80029FC4:
    gc_env.f[1] = gc_env.f[28]; // fmr f1, f28
    tanf();
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[31] + 0x80); // lfsu f0, 0x80(r31)
    gc_env.f[0] = *(float*)&temp;
    gc_env.r[31] = gc_env.r[31] + 0x80;
    gc_env.f[26] = (float)gc_env.f[0] * (float)gc_env.f[1]; // fmuls f26, f0, f1
    gc_env.f[1] = gc_env.f[27]; // fmr f1, f27
    tanf();
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[31] + 0x0); // lfs f0, 0x0(r31)
    gc_env.f[0] = *(float*)&temp;
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[29] + 0x8); // lfs f2, 0x8(r29)
    gc_env.f[2] = *(float*)&temp;
    gc_env.f[3] = (float)gc_env.f[0] * (float)gc_env.f[1]; // fmuls f3, f0, f1
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[29] + 0x0); // lfs f0, 0x0(r29)
    gc_env.f[0] = *(float*)&temp;
    gc_env.f[1] = (float)gc_env.f[2] - (float)gc_env.f[0]; // fsubs f1, f2, f0
    gc_env.f[0] = (float)gc_env.f[26] + (float)gc_env.f[3]; // fadds f0, f26, f3
    gc_env.f[28] = (float)gc_env.f[1] / (float)gc_env.f[0]; // fdivs f28, f1, f0
    Stage_GetCamBoundsLeftOffset();
    Stage_GetCamBoundsRightOffset();
    gc_env.f[1] = gc_env.f[31]; // fmr f1, f31
    tanf();
    gc_env.f[2] = (float)gc_env.f[28] * (float)gc_env.f[1]; // fmuls f2, f28, f1
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[31] + 0x0); // lfs f1, 0x0(r31)
    gc_env.f[1] = *(float*)&temp;
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[29] + 0x8); // lfs f0, 0x8(r29)
    gc_env.f[0] = *(float*)&temp;
    gc_env.cr[0] = isnan(gc_env.f[29]) || isnan(gc_env.f[28]) ? 0x1 : (gc_env.f[29] < gc_env.f[28] ? 0x8 : (gc_env.f[29] > gc_env.f[28] ? 0x4 : 0x2)); // fcmpo cr0, f29, f28
    gc_env.f[31] = (float)gc_env.f[1] * (float)gc_env.f[2]; // fmuls f31, f1, f2
    gc_env.f[0] = -((float)gc_env.f[28] * (float)gc_env.f[26] - (float)gc_env.f[0]); // fnmsubs f0, f28, f26, f0
    gc_env.f[0] = (float)gc_env.f[0] - (float)gc_env.f[31]; // fsubs f0, f0, f31
    float temp = (float)gc_env.f[0]; // stfs f0, 0xC(r30)
    gc_mem_write32(gc_env.ram, gc_env.r[30] + 0xC, *(uint32_t*)&temp);
    gc_env.f[0] = cm_804D7E14; // lfs f0, cm_804D7E14@sda21(r0)
    float temp = (float)gc_env.f[0]; // stfs f0, 0x14(r30)
    gc_mem_write32(gc_env.ram, gc_env.r[30] + 0x14, *(uint32_t*)&temp);
    if (gc_env.cr[0] & (0x8 | 0x2)) goto L_8002A038; // ble .L_8002A038
    goto L_8002A03C;
    L_8002A038:
    gc_env.f[29] = gc_env.f[28]; // fmr f29, f28
    L_8002A03C:
    gc_env.f[28] = gc_env.f[29]; // fmr f28, f29
    Stage_GetCamZoomRate();
    gc_env.cr[0] = isnan(gc_env.f[29]) || isnan(gc_env.f[1]) ? 0x1 : (gc_env.f[29] < gc_env.f[1] ? 0x8 : (gc_env.f[29] > gc_env.f[1] ? 0x4 : 0x2)); // fcmpo cr0, f29, f1
    if (gc_env.cr[0] >= 0) goto L_8002A054;
    Stage_GetCamZoomRate();
    gc_env.f[28] = gc_env.f[1]; // fmr f28, f1
    L_8002A054:
    Stage_GetCamMaxDepth();
    gc_env.cr[0] = isnan(gc_env.f[28]) || isnan(gc_env.f[1]) ? 0x1 : (gc_env.f[28] < gc_env.f[1] ? 0x8 : (gc_env.f[28] > gc_env.f[1] ? 0x4 : 0x2)); // fcmpo cr0, f28, f1
    if (gc_env.cr[0] & (0x8 | 0x2)) goto L_8002A068; // ble .L_8002A068
    Stage_GetCamMaxDepth();
    gc_env.f[28] = gc_env.f[1]; // fmr f28, f1
    L_8002A068:
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[30] + 0xC); // lfs f0, 0xC(r30)
    gc_env.f[0] = *(float*)&temp;
    gc_env.f[0] = (float)gc_env.f[0] + (float)gc_env.f[31]; // fadds f0, f0, f31
    float temp = (float)gc_env.f[0]; // stfs f0, 0x24(r30)
    gc_mem_write32(gc_env.ram, gc_env.r[30] + 0x24, *(uint32_t*)&temp);
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[30] + 0x10); // lfs f0, 0x10(r30)
    gc_env.f[0] = *(float*)&temp;
    gc_env.f[0] = (float)gc_env.f[0] - (float)gc_env.f[30]; // fsubs f0, f0, f30
    float temp = (float)gc_env.f[0]; // stfs f0, 0x28(r30)
    gc_mem_write32(gc_env.ram, gc_env.r[30] + 0x28, *(uint32_t*)&temp);
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[30] + 0x14); // lfs f0, 0x14(r30)
    gc_env.f[0] = *(float*)&temp;
    gc_env.f[0] = (float)gc_env.f[0] + (float)gc_env.f[28]; // fadds f0, f0, f28
    float temp = (float)gc_env.f[0]; // stfs f0, 0x2C(r30)
    gc_mem_write32(gc_env.ram, gc_env.r[30] + 0x2C, *(uint32_t*)&temp);
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x84);
    uint64_t temp = gc_mem_read64(gc_env.ram, gc_env.r[1] + 0x78); // lfd f31, 0x78(r1)
    gc_env.d[31] = *(double*)&temp;
    uint64_t temp = gc_mem_read64(gc_env.ram, gc_env.r[1] + 0x70); // lfd f30, 0x70(r1)
    gc_env.d[30] = *(double*)&temp;
    uint64_t temp = gc_mem_read64(gc_env.ram, gc_env.r[1] + 0x68); // lfd f29, 0x68(r1)
    gc_env.d[29] = *(double*)&temp;
    uint64_t temp = gc_mem_read64(gc_env.ram, gc_env.r[1] + 0x60); // lfd f28, 0x60(r1)
    gc_env.d[28] = *(double*)&temp;
    uint64_t temp = gc_mem_read64(gc_env.ram, gc_env.r[1] + 0x58); // lfd f27, 0x58(r1)
    gc_env.d[27] = *(double*)&temp;
    uint64_t temp = gc_mem_read64(gc_env.ram, gc_env.r[1] + 0x50); // lfd f26, 0x50(r1)
    gc_env.d[26] = *(double*)&temp;
    gc_env.r[31] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x4c);
    gc_env.r[30] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x48);
    gc_env.r[29] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x44);
    gc_env.r[1] += 128; // addi r1, r1, 0x80
    gc_env.lr = gc_env.r[0]; // Move to link register
    return;
}

// Function: Camera_8002A0C0
void Camera_8002A0C0(void) {
    gc_env.r[0] = gc_env.lr; // Move from link register
    gc_env.r[5] = ((uint32_t)&cm_80452C68 >> 16) & 0xFFFF; // lis r5, cm_80452C68@ha
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x4, gc_env.r[0]);
    gc_mem_write32(gc_env.ram, gc_env.r[1] + -0x60, gc_env.r[1]);
    gc_env.r[1] = gc_env.r[1] + -0x60;
    uint64_t temp;
    memcpy(&temp, &gc_env.f[31], sizeof(double));
    gc_mem_write64(gc_env.ram, gc_env.r[1] + 0x58, temp); // stfd f31, 0x58(r1)
    uint64_t temp;
    memcpy(&temp, &gc_env.f[30], sizeof(double));
    gc_mem_write64(gc_env.ram, gc_env.r[1] + 0x50, temp); // stfd f30, 0x50(r1)
    uint64_t temp;
    memcpy(&temp, &gc_env.f[29], sizeof(double));
    gc_mem_write64(gc_env.ram, gc_env.r[1] + 0x48, temp); // stfd f29, 0x48(r1)
    uint64_t temp;
    memcpy(&temp, &gc_env.f[28], sizeof(double));
    gc_mem_write64(gc_env.ram, gc_env.r[1] + 0x40, temp); // stfd f28, 0x40(r1)
    uint64_t temp;
    memcpy(&temp, &gc_env.f[27], sizeof(double));
    gc_mem_write64(gc_env.ram, gc_env.r[1] + 0x38, temp); // stfd f27, 0x38(r1)
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x20, gc_env.r[26]); // stmw r26, 0x20(r1)
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x24, gc_env.r[27]); // stmw r26, 0x20(r1)
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x28, gc_env.r[28]); // stmw r26, 0x20(r1)
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x2C, gc_env.r[29]); // stmw r26, 0x20(r1)
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x30, gc_env.r[30]); // stmw r26, 0x20(r1)
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x34, gc_env.r[31]); // stmw r26, 0x20(r1)
    gc_env.r[27] = gc_env.r[5] + ((uint32_t)&cm_80452C68 & 0xFFFF); // addi r27, r5, cm_80452C68@l
    gc_env.r[5] = ((uint32_t)&cm_803BCB18 >> 16) & 0xFFFF; // lis r5, cm_803BCB18@ha
    gc_env.r[31] = gc_env.r[27] + 164; // addi r31, r27, 0xa4
    gc_env.r[30] = gc_env.r[27] + 168; // addi r30, r27, 0xa8
    gc_env.r[29] = gc_env.r[3]; // Move register
    gc_env.r[26] = gc_env.r[4]; // Move register
    gc_env.r[28] = gc_env.r[5] + ((uint32_t)&cm_803BCB18 & 0xFFFF); // addi r28, r5, cm_803BCB18@l
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[27] + 0xAC); // lfs f3, 0xAC(r27)
    gc_env.f[3] = *(float*)&temp;
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[27] + 0xA4); // lfs f2, 0xA4(r27)
    gc_env.f[2] = *(float*)&temp;
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[27] + 0xA8); // lfs f1, 0xA8(r27)
    gc_env.f[1] = *(float*)&temp;
    gc_env.f[31] = (float)gc_env.f[2] * (float)gc_env.f[3]; // fmuls f31, f2, f3
    gc_env.f[0] = cm_804D7E4C; // lfs f0, cm_804D7E4C@sda21(r0)
    gc_env.f[30] = (float)gc_env.f[1] * (float)gc_env.f[3]; // fmuls f30, f1, f3
    gc_env.f[31] = (float)gc_env.f[31] * (float)gc_env.f[0]; // fmuls f31, f31, f0
    gc_env.f[30] = (float)gc_env.f[30] * (float)gc_env.f[0]; // fmuls f30, f30, f0
    gm_8016B41C();
    gc_env.cr[0] = (gc_env.r[3] == 0x0) ? 0 : (gc_env.r[3] < 0x0 ? -1 : 1); // Compare with immediate
    if (gc_env.cr[0] == 0) goto L_8002A144;
    gc_env.r[3] = ((uint32_t)&cm_803BCCA0 >> 16) & 0xFFFF; // lis r3, cm_803BCCA0@ha
    gc_env.r[3] = gc_env.r[3] + ((uint32_t)&cm_803BCCA0 & 0xFFFF); // addi r3, r3, cm_803BCCA0@l
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[3] + 0xE8); // lfs f0, 0xE8(r3)
    gc_env.f[0] = *(float*)&temp;
    gc_env.f[31] = (float)gc_env.f[31] * (float)gc_env.f[0]; // fmuls f31, f31, f0
    gc_env.f[30] = (float)gc_env.f[30] * (float)gc_env.f[0]; // fmuls f30, f30, f0
    L_8002A144:
    gc_env.f[1] = cm_804D7E60; // lfs f1, cm_804D7E60@sda21(r0)
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[26] + 0x30); // lfs f0, 0x30(r26)
    gc_env.f[0] = *(float*)&temp;
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[27] + 0x2BC); // lfs f2, 0x2BC(r27)
    gc_env.f[2] = *(float*)&temp;
    gc_env.f[0] = (float)gc_env.f[1] * (float)gc_env.f[0]; // fmuls f0, f1, f0
    gc_env.f[1] = cm_804D7E30; // lfs f1, cm_804D7E30@sda21(r0)
    gc_env.f[31] = (float)gc_env.f[31] * (float)gc_env.f[2]; // fmuls f31, f31, f2
    gc_env.f[30] = (float)gc_env.f[30] * (float)gc_env.f[2]; // fmuls f30, f30, f2
    gc_env.f[1] = (float)gc_env.f[1] * (float)gc_env.f[0]; // fmuls f1, f1, f0
    tanf();
    gc_env.r[3] = (int32_t)(int16_t)gc_mem_read16(gc_env.ram, gc_env.r[28] + 0x54); // lha r3, 0x54(r28)
    gc_env.r[4] = 17200 << 16; // lis r4, 0x4330
    gc_env.r[0] = (int32_t)(int16_t)gc_mem_read16(gc_env.ram, gc_env.r[28] + 0x56); // lha r0, 0x56(r28)
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[29] + 0x14); // lfs f0, 0x14(r29)
    gc_env.f[0] = *(float*)&temp;
    gc_env.r[0] = gc_env.r[0] - gc_env.r[3];
    gc_env.r[3] = (int32_t)(int16_t)gc_mem_read16(gc_env.ram, gc_env.r[28] + 0x58); // lha r3, 0x58(r28)
    gc_env.r[5] = gc_env.r[0] ^ 0x80000000; // xoris r5, r0, 0x8000
    gc_env.r[0] = (int32_t)(int16_t)gc_mem_read16(gc_env.ram, gc_env.r[28] + 0x5A); // lha r0, 0x5A(r28)
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x1c, gc_env.r[5]);
    gc_env.f[5] = (float)gc_env.f[0] * (float)gc_env.f[1]; // fmuls f5, f0, f1
    gc_env.r[0] = gc_env.r[0] - gc_env.r[3];
    gc_env.d[2] = cm_804D7E20; // lfd f2, cm_804D7E20@sda21(r0)
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x18, gc_env.r[4]);
    gc_env.r[0] = gc_env.r[0] ^ 0x80000000; // xoris r0, r0, 0x8000
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x14, gc_env.r[0]);
    uint64_t temp = gc_mem_read64(gc_env.ram, gc_env.r[1] + 0x18); // lfd f0, 0x18(r1)
    gc_env.d[0] = *(double*)&temp;
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x10, gc_env.r[4]);
    gc_env.f[1] = (float)gc_env.f[0] - (float)gc_env.f[2]; // fsubs f1, f0, f2
    gc_env.f[3] = cm_804D7E30; // lfs f3, cm_804D7E30@sda21(r0)
    uint64_t temp = gc_mem_read64(gc_env.ram, gc_env.r[1] + 0x10); // lfd f0, 0x10(r1)
    gc_env.d[0] = *(double*)&temp;
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[28] + 0x80); // lfs f4, 0x80(r28)
    gc_env.f[4] = *(float*)&temp;
    gc_env.f[1] = (float)gc_env.f[3] * (float)gc_env.f[1]; // fmuls f1, f3, f1
    gc_env.f[0] = (float)gc_env.f[0] - (float)gc_env.f[2]; // fsubs f0, f0, f2
    gc_env.f[1] = (float)gc_env.f[5] / (float)gc_env.f[1]; // fdivs f1, f5, f1
    gc_env.f[0] = (float)gc_env.f[3] * (float)gc_env.f[0]; // fmuls f0, f3, f0
    gc_env.f[28] = (float)gc_env.f[4] * (float)gc_env.f[1]; // fmuls f28, f4, f1
    gc_env.f[27] = (float)gc_env.f[5] / (float)gc_env.f[0]; // fdivs f27, f5, f0
    Stage_GetCamZoomRate();
    gc_env.f[29] = gc_env.f[1]; // fmr f29, f1
    Stage_GetCamMaxDepth();
    gc_env.f[29] = (float)gc_env.f[1] - (float)gc_env.f[29]; // fsubs f29, f1, f29
    gc_env.f[0] = cm_804D7E68; // lfs f0, cm_804D7E68@sda21(r0)
    gc_env.cr[0] = isnan(gc_env.f[29]) || isnan(gc_env.f[0]) ? 0x1 : (gc_env.f[29] < gc_env.f[0] ? 0x8 : (gc_env.f[29] > gc_env.f[0] ? 0x4 : 0x2)); // fcmpo cr0, f29, f0
    if (gc_env.cr[0] >= 0) goto L_8002A1F8;
    gc_env.f[6] = cm_804D7E30; // lfs f6, cm_804D7E30@sda21(r0)
    goto L_8002A208;
    L_8002A1F8:
    Stage_GetCamZoomRate();
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[29] + 0x14); // lfs f0, 0x14(r29)
    gc_env.f[0] = *(float*)&temp;
    gc_env.f[0] = (float)gc_env.f[0] - (float)gc_env.f[1]; // fsubs f0, f0, f1
    gc_env.f[6] = (float)gc_env.f[0] / (float)gc_env.f[29]; // fdivs f6, f0, f29
    L_8002A208:
    gc_env.r[3] = ((uint32_t)&cm_803BCCA0 >> 16) & 0xFFFF; // lis r3, cm_803BCCA0@ha
    gc_env.f[1] = (float)gc_env.f[31] * (float)gc_env.f[28]; // fmuls f1, f31, f28
    gc_env.r[3] = gc_env.r[3] + ((uint32_t)&cm_803BCCA0 & 0xFFFF); // addi r3, r3, cm_803BCCA0@l
    gc_env.f[0] = (float)gc_env.f[30] * (float)gc_env.f[27]; // fmuls f0, f30, f27
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[3] + 0x54); // lfs f4, 0x54(r3)
    gc_env.f[4] = *(float*)&temp;
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[3] + 0x5C); // lfs f3, 0x5C(r3)
    gc_env.f[3] = *(float*)&temp;
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[3] + 0x58); // lfs f5, 0x58(r3)
    gc_env.f[5] = *(float*)&temp;
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[3] + 0x60); // lfs f2, 0x60(r3)
    gc_env.f[2] = *(float*)&temp;
    gc_env.f[3] = (float)gc_env.f[3] - (float)gc_env.f[4]; // fsubs f3, f3, f4
    gc_env.f[2] = (float)gc_env.f[2] - (float)gc_env.f[5]; // fsubs f2, f2, f5
    gc_env.f[3] = (float)gc_env.f[6] * (float)gc_env.f[3] + (float)gc_env.f[4]; // fmadds f3, f6, f3, f4
    gc_env.f[4] = (float)gc_env.f[6] * (float)gc_env.f[2] + (float)gc_env.f[5]; // fmadds f4, f6, f2, f5
    gc_env.f[2] = (float)gc_env.f[3] * (float)gc_env.f[0]; // fmuls f2, f3, f0
    gc_env.f[1] = (float)gc_env.f[4] * (float)gc_env.f[1]; // fmuls f1, f4, f1
    Camera_80030DE4();
    gc_env.f[0] = cm_804D7E14; // lfs f0, cm_804D7E14@sda21(r0)
    float temp = (float)gc_env.f[0]; // stfs f0, 0x0(r31)
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x0, *(uint32_t*)&temp);
    float temp = (float)gc_env.f[0]; // stfs f0, 0x0(r30)
    gc_mem_write32(gc_env.ram, gc_env.r[30] + 0x0, *(uint32_t*)&temp);
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x64);
    uint64_t temp = gc_mem_read64(gc_env.ram, gc_env.r[1] + 0x58); // lfd f31, 0x58(r1)
    gc_env.d[31] = *(double*)&temp;
    uint64_t temp = gc_mem_read64(gc_env.ram, gc_env.r[1] + 0x50); // lfd f30, 0x50(r1)
    gc_env.d[30] = *(double*)&temp;
    uint64_t temp = gc_mem_read64(gc_env.ram, gc_env.r[1] + 0x48); // lfd f29, 0x48(r1)
    gc_env.d[29] = *(double*)&temp;
    uint64_t temp = gc_mem_read64(gc_env.ram, gc_env.r[1] + 0x40); // lfd f28, 0x40(r1)
    gc_env.d[28] = *(double*)&temp;
    uint64_t temp = gc_mem_read64(gc_env.ram, gc_env.r[1] + 0x38); // lfd f27, 0x38(r1)
    gc_env.d[27] = *(double*)&temp;
    gc_env.r[26] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x20); // lmw r26, 0x20(r1)
    gc_env.r[27] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x24); // lmw r26, 0x20(r1)
    gc_env.r[28] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x28); // lmw r26, 0x20(r1)
    gc_env.r[29] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x2C); // lmw r26, 0x20(r1)
    gc_env.r[30] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x30); // lmw r26, 0x20(r1)
    gc_env.r[31] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x34); // lmw r26, 0x20(r1)
    gc_env.r[1] += 96; // addi r1, r1, 0x60
    gc_env.lr = gc_env.r[0]; // Move to link register
    return;
}

// Function: Camera_8002A278
void Camera_8002A278(void) {
    gc_env.r[3] = ((uint32_t)&cm_80452C68 >> 16) & 0xFFFF; // lis r3, cm_80452C68@ha
    gc_env.r[3] = gc_env.r[3] + ((uint32_t)&cm_80452C68 & 0xFFFF); // addi r3, r3, cm_80452C68@l
    float temp = (float)gc_env.f[1]; // stfs f1, 0xA4(r3)
    gc_mem_write32(gc_env.ram, gc_env.r[3] + 0xA4, *(uint32_t*)&temp);
    float temp = (float)gc_env.f[2]; // stfs f2, 0xA8(r3)
    gc_mem_write32(gc_env.ram, gc_env.r[3] + 0xA8, *(uint32_t*)&temp);
    return;
}

// Function: Camera_8002A28C
void Camera_8002A28C(void) {
    gc_env.r[0] = gc_env.lr; // Move from link register
    gc_env.r[3] = ((uint32_t)&cm_80452C68 >> 16) & 0xFFFF; // lis r3, cm_80452C68@ha
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x4, gc_env.r[0]);
    gc_env.r[0] = 0x2;
    gc_env.r[4] = gc_env.r[3] + ((uint32_t)&cm_80452C68 & 0xFFFF); // addi r4, r3, cm_80452C68@l
    gc_env.ctr = gc_env.r[0]; // Move to count register
    gc_mem_write32(gc_env.ram, gc_env.r[1] + -0x30, gc_env.r[1]);
    gc_env.r[1] = gc_env.r[1] + -0x30;
    gc_env.r[3] = gc_env.r[4] + 0; // addi r3, r4, 0x0
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x2c, gc_env.r[31]);
    gc_env.r[5] = -0x1;
    L_8002A2B4:
    gc_env.r[7] = gc_mem_read32(gc_env.ram, gc_env.r[3] + 0xb0);
    gc_env.r[0] = 0x0;
    gc_env.r[6] = gc_mem_read32(gc_env.ram, gc_env.r[3] + 0xb4);
    gc_mem_write32(gc_env.ram, gc_env.r[3] + 0x1b0, gc_env.r[7]);
    gc_mem_write32(gc_env.ram, gc_env.r[3] + 0x1b4, gc_env.r[6]);
    gc_env.r[7] = gc_mem_read32(gc_env.ram, gc_env.r[3] + 0xb8);
    gc_env.r[6] = gc_mem_read32(gc_env.ram, gc_env.r[3] + 0xbc);
    gc_mem_write32(gc_env.ram, gc_env.r[3] + 0x1b8, gc_env.r[7]);
    gc_mem_write32(gc_env.ram, gc_env.r[3] + 0x1bc, gc_env.r[6]);
    gc_mem_write32(gc_env.ram, gc_env.r[3] + 0xbc, gc_env.r[0]);
    gc_env.r[7] = gc_mem_read32(gc_env.ram, gc_env.r[3] + 0xc0);
    gc_env.r[6] = gc_mem_read32(gc_env.ram, gc_env.r[3] + 0xc4);
    gc_mem_write32(gc_env.ram, gc_env.r[3] + 0x1c0, gc_env.r[7]);
    gc_mem_write32(gc_env.ram, gc_env.r[3] + 0x1c4, gc_env.r[6]);
    gc_env.r[7] = gc_mem_read32(gc_env.ram, gc_env.r[3] + 0xc8);
    gc_env.r[6] = gc_mem_read32(gc_env.ram, gc_env.r[3] + 0xcc);
    gc_mem_write32(gc_env.ram, gc_env.r[3] + 0x1c8, gc_env.r[7]);
    gc_mem_write32(gc_env.ram, gc_env.r[3] + 0x1cc, gc_env.r[6]);
    gc_mem_write32(gc_env.ram, gc_env.r[3] + 0xcc, gc_env.r[0]);
    gc_env.r[7] = gc_mem_read32(gc_env.ram, gc_env.r[3] + 0xd0);
    gc_env.r[6] = gc_mem_read32(gc_env.ram, gc_env.r[3] + 0xd4);
    gc_mem_write32(gc_env.ram, gc_env.r[3] + 0x1d0, gc_env.r[7]);
    gc_mem_write32(gc_env.ram, gc_env.r[3] + 0x1d4, gc_env.r[6]);
    gc_env.r[7] = gc_mem_read32(gc_env.ram, gc_env.r[3] + 0xd8);
    gc_env.r[6] = gc_mem_read32(gc_env.ram, gc_env.r[3] + 0xdc);
    gc_mem_write32(gc_env.ram, gc_env.r[3] + 0x1d8, gc_env.r[7]);
    gc_mem_write32(gc_env.ram, gc_env.r[3] + 0x1dc, gc_env.r[6]);
    gc_mem_write32(gc_env.ram, gc_env.r[3] + 0xdc, gc_env.r[0]);
    gc_env.r[7] = gc_mem_read32(gc_env.ram, gc_env.r[3] + 0xe0);
    gc_env.r[6] = gc_mem_read32(gc_env.ram, gc_env.r[3] + 0xe4);
    gc_mem_write32(gc_env.ram, gc_env.r[3] + 0x1e0, gc_env.r[7]);
    gc_mem_write32(gc_env.ram, gc_env.r[3] + 0x1e4, gc_env.r[6]);
    gc_env.r[7] = gc_mem_read32(gc_env.ram, gc_env.r[3] + 0xe8);
    gc_env.r[6] = gc_mem_read32(gc_env.ram, gc_env.r[3] + 0xec);
    gc_mem_write32(gc_env.ram, gc_env.r[3] + 0x1e8, gc_env.r[7]);
    gc_mem_write32(gc_env.ram, gc_env.r[3] + 0x1ec, gc_env.r[6]);
    gc_mem_write32(gc_env.ram, gc_env.r[3] + 0xec, gc_env.r[0]);
    gc_env.r[7] = gc_mem_read32(gc_env.ram, gc_env.r[3] + 0xf0);
    gc_env.r[6] = gc_mem_read32(gc_env.ram, gc_env.r[3] + 0xf4);
    gc_mem_write32(gc_env.ram, gc_env.r[3] + 0x1f0, gc_env.r[7]);
    gc_mem_write32(gc_env.ram, gc_env.r[3] + 0x1f4, gc_env.r[6]);
    gc_env.r[7] = gc_mem_read32(gc_env.ram, gc_env.r[3] + 0xf8);
    gc_env.r[6] = gc_mem_read32(gc_env.ram, gc_env.r[3] + 0xfc);
    gc_mem_write32(gc_env.ram, gc_env.r[3] + 0x1f8, gc_env.r[7]);
    gc_mem_write32(gc_env.ram, gc_env.r[3] + 0x1fc, gc_env.r[6]);
    gc_mem_write32(gc_env.ram, gc_env.r[3] + 0xfc, gc_env.r[0]);
    gc_env.r[7] = gc_mem_read32(gc_env.ram, gc_env.r[3] + 0x100);
    gc_env.r[6] = gc_mem_read32(gc_env.ram, gc_env.r[3] + 0x104);
    gc_mem_write32(gc_env.ram, gc_env.r[3] + 0x200, gc_env.r[7]);
    gc_mem_write32(gc_env.ram, gc_env.r[3] + 0x204, gc_env.r[6]);
    gc_env.r[7] = gc_mem_read32(gc_env.ram, gc_env.r[3] + 0x108);
    gc_env.r[6] = gc_mem_read32(gc_env.ram, gc_env.r[3] + 0x10c);
    gc_mem_write32(gc_env.ram, gc_env.r[3] + 0x208, gc_env.r[7]);
    gc_mem_write32(gc_env.ram, gc_env.r[3] + 0x20c, gc_env.r[6]);
    gc_mem_write32(gc_env.ram, gc_env.r[3] + 0x10c, gc_env.r[0]);
    gc_env.r[7] = gc_mem_read32(gc_env.ram, gc_env.r[3] + 0x110);
    gc_env.r[6] = gc_mem_read32(gc_env.ram, gc_env.r[3] + 0x114);
    gc_mem_write32(gc_env.ram, gc_env.r[3] + 0x210, gc_env.r[7]);
    gc_mem_write32(gc_env.ram, gc_env.r[3] + 0x214, gc_env.r[6]);
    gc_env.r[7] = gc_mem_read32(gc_env.ram, gc_env.r[3] + 0x118);
    gc_env.r[6] = gc_mem_read32(gc_env.ram, gc_env.r[3] + 0x11c);
    gc_mem_write32(gc_env.ram, gc_env.r[3] + 0x218, gc_env.r[7]);
    gc_mem_write32(gc_env.ram, gc_env.r[3] + 0x21c, gc_env.r[6]);
    gc_mem_write32(gc_env.ram, gc_env.r[3] + 0x11c, gc_env.r[0]);
    gc_env.r[7] = gc_mem_read32(gc_env.ram, gc_env.r[3] + 0x120);
    gc_env.r[6] = gc_mem_read32(gc_env.ram, gc_env.r[3] + 0x124);
    gc_mem_write32(gc_env.ram, gc_env.r[3] + 0x220, gc_env.r[7]);
    gc_mem_write32(gc_env.ram, gc_env.r[3] + 0x224, gc_env.r[6]);
    gc_env.r[7] = gc_mem_read32(gc_env.ram, gc_env.r[3] + 0x128);
    gc_env.r[6] = gc_mem_read32(gc_env.ram, gc_env.r[3] + 0x12c);
    gc_mem_write32(gc_env.ram, gc_env.r[3] + 0x228, gc_env.r[7]);
    gc_mem_write32(gc_env.ram, gc_env.r[3] + 0x22c, gc_env.r[6]);
    gc_mem_write32(gc_env.ram, gc_env.r[3] + 0x12c, gc_env.r[0]);
    gc_env.r[3] += 128; // addi r3, r3, 0x80
    gc_env.ctr -= 1;
    if (gc_env.ctr != 0) goto L_8002A2B4;
    gc_env.r[3] = gc_mem_read32(gc_env.ram, gc_env.r[4] + 0x8c);
    gc_env.cr[0] = (gc_env.r[3] == 0x0) ? 0 : (gc_env.r[3] < 0x0 ? -1 : 1); // Compare with immediate
    if (gc_env.cr[0] == 0) goto L_8002A3F8;
    gc_env.r[0] = gc_env.r[3] - 1;
    gc_mem_write32(gc_env.ram, gc_env.r[4] + 0x8c, gc_env.r[0]);
    gc_env.r[5] = 0x0;
    L_8002A3F8:
    gc_env.r[6] = gc_env.r[4] + 4; // addi r6, r4, 0x4
    gc_env.r[3] = gc_mem_read32(gc_env.ram, gc_env.r[4] + 0x90);
    gc_env.cr[0] = (gc_env.r[3] == 0x0) ? 0 : (gc_env.r[3] < 0x0 ? -1 : 1); // Compare with immediate
    if (gc_env.cr[0] == 0) goto L_8002A414;
    gc_env.r[0] = gc_env.r[3] - 1;
    gc_mem_write32(gc_env.ram, gc_env.r[6] + 0x8c, gc_env.r[0]);
    gc_env.r[5] = 0x1;
    L_8002A414:
    gc_env.r[3] = gc_mem_read32(gc_env.ram, gc_env.r[6] + 0x90);
    gc_env.r[6] += 4; // addi r6, r6, 0x4
    gc_env.cr[0] = (gc_env.r[3] == 0x0) ? 0 : (gc_env.r[3] < 0x0 ? -1 : 1); // Compare with immediate
    if (gc_env.cr[0] == 0) goto L_8002A430;
    gc_env.r[0] = gc_env.r[3] - 1;
    gc_mem_write32(gc_env.ram, gc_env.r[6] + 0x8c, gc_env.r[0]);
    gc_env.r[5] = 0x2;
    L_8002A430:
    gc_env.r[3] = gc_mem_read32(gc_env.ram, gc_env.r[6] + 0x90);
    gc_env.r[6] += 4; // addi r6, r6, 0x4
    gc_env.cr[0] = (gc_env.r[3] == 0x0) ? 0 : (gc_env.r[3] < 0x0 ? -1 : 1); // Compare with immediate
    if (gc_env.cr[0] == 0) goto L_8002A44C;
    gc_env.r[0] = gc_env.r[3] - 1;
    gc_mem_write32(gc_env.ram, gc_env.r[6] + 0x8c, gc_env.r[0]);
    gc_env.r[5] = 0x3;
    L_8002A44C:
    gc_env.r[3] = gc_mem_read32(gc_env.ram, gc_env.r[6] + 0x90);
    gc_env.r[6] += 4; // addi r6, r6, 0x4
    gc_env.cr[0] = (gc_env.r[3] == 0x0) ? 0 : (gc_env.r[3] < 0x0 ? -1 : 1); // Compare with immediate
    if (gc_env.cr[0] == 0) goto L_8002A468;
    gc_env.r[0] = gc_env.r[3] - 1;
    gc_mem_write32(gc_env.ram, gc_env.r[6] + 0x8c, gc_env.r[0]);
    gc_env.r[5] = 0x4;
    L_8002A468:
    gc_env.cr[0] = (gc_env.r[5] == -0x1) ? 0 : (gc_env.r[5] < -0x1 ? -1 : 1); // Compare with immediate
    if (gc_env.cr[0] == 0) goto L_8002A498;
    gc_env.r[31] = gc_env.r[4] + 160; // addi r31, r4, 0xa0
    gc_env.r[3] = gc_mem_read32(gc_env.ram, gc_env.r[4] + 0xa0);
    gc_env.cr[0] = ((uint32_t)gc_env.r[3] == 0x0) ? 0 : ((uint32_t)gc_env.r[3] < 0x0 ? -1 : 1); // Logical compare with immediate
    if (gc_env.cr[0] == 0) goto L_8002A498;
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[4] + 0x90);
    gc_env.cr[0] = (gc_env.r[0] == 0x0) ? 0 : (gc_env.r[0] < 0x0 ? -1 : 1); // Compare with immediate
    if (gc_env.cr[0] != 0) goto L_8002A498;
    HSD_GObjPLink_80390228();
    gc_env.r[0] = 0x0;
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x0, gc_env.r[0]);
    L_8002A498:
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x34);
    gc_env.r[31] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x2c);
    gc_env.r[1] += 48; // addi r1, r1, 0x30
    gc_env.lr = gc_env.r[0]; // Move to link register
    return;
}

// Function: Camera_8002A4AC
void Camera_8002A4AC(void) {
    gc_env.r[0] = gc_env.lr; // Move from link register
    gc_env.r[4] = ((uint32_t)&cm_80452C68 >> 16) & 0xFFFF; // lis r4, cm_80452C68@ha
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x4, gc_env.r[0]);
    gc_mem_write32(gc_env.ram, gc_env.r[1] + -0x38, gc_env.r[1]);
    gc_env.r[1] = gc_env.r[1] + -0x38;
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x34, gc_env.r[31]);
    gc_env.r[31] = gc_env.r[4] + ((uint32_t)&cm_80452C68 & 0xFFFF); // addi r31, r4, cm_80452C68@l
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x30, gc_env.r[30]);
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x2c, gc_env.r[29]);
    gc_env.r[29] = gc_env.r[31] + 20; // addi r29, r31, 0x14
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[31] + 0x4);
    gc_env.r[30] = gc_mem_read32(gc_env.ram, gc_env.r[3] + 0x28);
    gc_env.cr[0] = ((uint32_t)gc_env.r[0] == 0x8) ? 0 : ((uint32_t)gc_env.r[0] < 0x8 ? -1 : 1); // Logical compare with immediate
    if (gc_env.cr[0] & 0x4) goto L_8002A74C; // bgt .L_8002A74C
    gc_env.r[3] = ((uint32_t)&jumptable_803BCC4C >> 16) & 0xFFFF; // lis r3, jumptable_803BCC4C@ha
    gc_env.r[3] = gc_env.r[3] + ((uint32_t)&jumptable_803BCC4C & 0xFFFF); // addi r3, r3, jumptable_803BCC4C@l
    gc_env.r[0] = gc_env.r[0] << 2; // slwi r0, r0, 2
    // Unknown opcode: lwzx r0 r3 r0
    gc_env.ctr = gc_env.r[0]; // Move to count register
    // Unknown opcode: bctr 
    L_8002A4F8:
    gc_env.r[3] = gc_env.r[30] + 0; // addi r3, r30, 0x0
    gc_env.r[4] = gc_env.r[29] + 0; // addi r4, r29, 0x0
    Camera_8002AF68();
    gc_env.r[3] = gc_mem_read32(gc_env.ram, gc_env.r[0] + cm_804D6464@sda21);
    gc_env.r[4] = gc_env.r[31] + 76; // addi r4, r31, 0x4c
    Camera_8002AF68();
    gc_env.r[3] = gc_env.r[30]; // Move register
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[31] + 0xC); // lfs f1, 0xC(r31)
    gc_env.f[1] = *(float*)&temp;
    HSD_CObjSetNear();
    gc_env.r[3] = gc_env.r[30]; // Move register
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[31] + 0x10); // lfs f1, 0x10(r31)
    gc_env.f[1] = *(float*)&temp;
    HSD_CObjSetFar();
    goto L_8002A74C;
    L_8002A52C:
    gc_env.r[3] = gc_env.r[30] + 0; // addi r3, r30, 0x0
    gc_env.r[4] = gc_env.r[29] + 0; // addi r4, r29, 0x0
    Camera_8002AF68();
    gc_env.r[3] = gc_env.r[30]; // Move register
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[31] + 0xC); // lfs f1, 0xC(r31)
    gc_env.f[1] = *(float*)&temp;
    HSD_CObjSetNear();
    gc_env.r[3] = gc_env.r[30]; // Move register
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[31] + 0x10); // lfs f1, 0x10(r31)
    gc_env.f[1] = *(float*)&temp;
    HSD_CObjSetFar();
    goto L_8002A74C;
    L_8002A554:
    gc_env.r[4] = gc_mem_read32(gc_env.ram, gc_env.r[29] + 0x18);
    gc_env.r[3] = ((uint32_t)&stage_info >> 16) & 0xFFFF; // lis r3, stage_info@ha
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[29] + 0x1c);
    gc_env.r[3] = gc_env.r[3] + ((uint32_t)&stage_info & 0xFFFF); // addi r3, r3, stage_info@l
    gc_env.r[31] = gc_env.r[3] + 136; // addi r31, r3, 0x88
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x18, gc_env.r[4]);
    gc_env.f[1] = cm_804D7E00; // lfs f1, cm_804D7E00@sda21(r0)
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x1c, gc_env.r[0]);
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[29] + 0x20);
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x20, gc_env.r[0]);
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[3] + 0x88);
    gc_env.cr[0] = (gc_env.r[0] == 0xe) ? 0 : (gc_env.r[0] < 0xe ? -1 : 1); // Compare with immediate
    if (gc_env.cr[0] == 0) goto L_8002A5D0;
    if (gc_env.cr[0] >= 0) goto L_8002A5B0;
    gc_env.cr[0] = (gc_env.r[0] == 0x5) ? 0 : (gc_env.r[0] < 0x5 ? -1 : 1); // Compare with immediate
    if (gc_env.cr[0] == 0) goto L_8002A5E0;
    if (gc_env.cr[0] >= 0) goto L_8002A5A4;
    gc_env.cr[0] = (gc_env.r[0] == 0x2) ? 0 : (gc_env.r[0] < 0x2 ? -1 : 1); // Compare with immediate
    if (gc_env.cr[0] == 0) goto L_8002A5C8;
    goto L_8002A5F4;
    L_8002A5A4:
    gc_env.cr[0] = (gc_env.r[0] == 0x8) ? 0 : (gc_env.r[0] < 0x8 ? -1 : 1); // Compare with immediate
    if (gc_env.cr[0] == 0) goto L_8002A5D8;
    goto L_8002A5F4;
    L_8002A5B0:
    gc_env.cr[0] = (gc_env.r[0] == 0x43) ? 0 : (gc_env.r[0] < 0x43 ? -1 : 1); // Compare with immediate
    if (gc_env.cr[0] == 0) goto L_8002A5F0;
    if (gc_env.cr[0] >= 0) goto L_8002A5F4;
    gc_env.cr[0] = (gc_env.r[0] == 0x1f) ? 0 : (gc_env.r[0] < 0x1f ? -1 : 1); // Compare with immediate
    if (gc_env.cr[0] == 0) goto L_8002A5E8;
    goto L_8002A5F4;
    L_8002A5C8:
    grCastle_801D0FF0();
    goto L_8002A5F4;
    L_8002A5D0:
    grCorneria_801E2FCC();
    goto L_8002A5F4;
    L_8002A5D8:
    grZebes_801DCCC8();
    goto L_8002A5F4;
    L_8002A5E0:
    grGarden_80203624();
    goto L_8002A5F4;
    L_8002A5E8:
    grShrineRoute_802087B0();
    goto L_8002A5F4;
    L_8002A5F0:
    grHomeRun_8021EF10();
    L_8002A5F4:
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x1C); // lfs f0, 0x1C(r1)
    gc_env.f[0] = *(float*)&temp;
    gc_env.cr[0] = isnan(gc_env.f[0]) || isnan(gc_env.f[1]) ? 0x1 : (gc_env.f[0] < gc_env.f[1] ? 0x8 : (gc_env.f[0] > gc_env.f[1] ? 0x4 : 0x2)); // fcmpo cr0, f0, f1
    if (gc_env.cr[0] >= 0) goto L_8002A680;
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[31] + 0x0);
    gc_env.f[1] = cm_804D7E00; // lfs f1, cm_804D7E00@sda21(r0)
    gc_env.cr[0] = (gc_env.r[0] == 0xe) ? 0 : (gc_env.r[0] < 0xe ? -1 : 1); // Compare with immediate
    if (gc_env.cr[0] == 0) goto L_8002A658;
    if (gc_env.cr[0] >= 0) goto L_8002A638;
    gc_env.cr[0] = (gc_env.r[0] == 0x5) ? 0 : (gc_env.r[0] < 0x5 ? -1 : 1); // Compare with immediate
    if (gc_env.cr[0] == 0) goto L_8002A668;
    if (gc_env.cr[0] >= 0) goto L_8002A62C;
    gc_env.cr[0] = (gc_env.r[0] == 0x2) ? 0 : (gc_env.r[0] < 0x2 ? -1 : 1); // Compare with immediate
    if (gc_env.cr[0] == 0) goto L_8002A650;
    goto L_8002A67C;
    L_8002A62C:
    gc_env.cr[0] = (gc_env.r[0] == 0x8) ? 0 : (gc_env.r[0] < 0x8 ? -1 : 1); // Compare with immediate
    if (gc_env.cr[0] == 0) goto L_8002A660;
    goto L_8002A67C;
    L_8002A638:
    gc_env.cr[0] = (gc_env.r[0] == 0x43) ? 0 : (gc_env.r[0] < 0x43 ? -1 : 1); // Compare with immediate
    if (gc_env.cr[0] == 0) goto L_8002A678;
    if (gc_env.cr[0] >= 0) goto L_8002A67C;
    gc_env.cr[0] = (gc_env.r[0] == 0x1f) ? 0 : (gc_env.r[0] < 0x1f ? -1 : 1); // Compare with immediate
    if (gc_env.cr[0] == 0) goto L_8002A670;
    goto L_8002A67C;
    L_8002A650:
    grCastle_801D0FF0();
    goto L_8002A67C;
    L_8002A658:
    grCorneria_801E2FCC();
    goto L_8002A67C;
    L_8002A660:
    grZebes_801DCCC8();
    goto L_8002A67C;
    L_8002A668:
    grGarden_80203624();
    goto L_8002A67C;
    L_8002A670:
    grShrineRoute_802087B0();
    goto L_8002A67C;
    L_8002A678:
    grHomeRun_8021EF10();
    L_8002A67C:
    float temp = (float)gc_env.f[1]; // stfs f1, 0x1C(r1)
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x1C, *(uint32_t*)&temp);
    L_8002A680:
    gc_env.r[3] = gc_env.r[30]; // Move register
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[29] + 0x30); // lfs f1, 0x30(r29)
    gc_env.f[1] = *(float*)&temp;
    HSD_CObjSetFov();
    gc_env.r[3] = gc_env.r[30] + 0; // addi r3, r30, 0x0
    gc_env.r[4] = gc_env.r[29] + 0; // addi r4, r29, 0x0
    HSD_CObjSetInterest();
    gc_env.r[3] = gc_env.r[30] + 0; // addi r3, r30, 0x0
    gc_env.r[4] = gc_env.r[1] + 24; // addi r4, r1, 0x18
    HSD_CObjSetEyePosition();
    gc_env.r[3] = gc_env.r[30]; // Move register
    gc_env.f[1] = cm_804D7E08; // lfs f1, cm_804D7E08@sda21(r0)
    HSD_CObjSetNear();
    gc_env.r[3] = gc_env.r[30]; // Move register
    gc_env.f[1] = cm_804D7E0C; // lfs f1, cm_804D7E0C@sda21(r0)
    HSD_CObjSetFar();
    goto L_8002A74C;
    L_8002A6C0:
    gc_env.r[3] = gc_env.r[30]; // Move register
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[29] + 0x30); // lfs f1, 0x30(r29)
    gc_env.f[1] = *(float*)&temp;
    HSD_CObjSetFov();
    gc_env.r[3] = gc_env.r[30] + 0; // addi r3, r30, 0x0
    gc_env.r[4] = gc_env.r[29] + 0; // addi r4, r29, 0x0
    HSD_CObjSetInterest();
    gc_env.r[3] = gc_env.r[30] + 0; // addi r3, r30, 0x0
    gc_env.r[4] = gc_env.r[29] + 24; // addi r4, r29, 0x18
    HSD_CObjSetEyePosition();
    gc_env.r[3] = gc_env.r[30]; // Move register
    gc_env.f[1] = cm_804D7E08; // lfs f1, cm_804D7E08@sda21(r0)
    HSD_CObjSetNear();
    gc_env.r[3] = gc_env.r[30]; // Move register
    gc_env.f[1] = cm_804D7E0C; // lfs f1, cm_804D7E0C@sda21(r0)
    HSD_CObjSetFar();
    goto L_8002A74C;
    L_8002A700:
    gc_env.r[3] = gc_env.r[30]; // Move register
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[31] + 0x3D4); // lfs f1, 0x3D4(r31)
    gc_env.f[1] = *(float*)&temp;
    HSD_CObjSetFov();
    gc_env.r[3] = gc_env.r[30] + 0; // addi r3, r30, 0x0
    gc_env.r[4] = gc_env.r[31] + 956; // addi r4, r31, 0x3bc
    HSD_CObjSetInterest();
    gc_env.r[3] = gc_env.r[30] + 0; // addi r3, r30, 0x0
    gc_env.r[4] = gc_env.r[31] + 968; // addi r4, r31, 0x3c8
    HSD_CObjSetEyePosition();
    goto L_8002A74C;
    L_8002A728:
    gc_env.r[3] = gc_env.r[30]; // Move register
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[31] + 0x3F0); // lfs f1, 0x3F0(r31)
    gc_env.f[1] = *(float*)&temp;
    HSD_CObjSetFov();
    gc_env.r[3] = gc_env.r[30] + 0; // addi r3, r30, 0x0
    gc_env.r[4] = gc_env.r[31] + 984; // addi r4, r31, 0x3d8
    HSD_CObjSetInterest();
    gc_env.r[3] = gc_env.r[30] + 0; // addi r3, r30, 0x0
    gc_env.r[4] = gc_env.r[31] + 996; // addi r4, r31, 0x3e4
    HSD_CObjSetEyePosition();
    L_8002A74C:
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x3c);
    gc_env.r[31] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x34);
    gc_env.r[30] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x30);
    gc_env.r[29] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x2c);
    gc_env.r[1] += 56; // addi r1, r1, 0x38
    gc_env.lr = gc_env.r[0]; // Move to link register
    return;
}

// Function: Camera_8002A768
void Camera_8002A768(void) {
    gc_env.r[0] = gc_env.lr; // Move from link register
    gc_env.r[5] = ((uint32_t)&cm_803B73B8 >> 16) & 0xFFFF; // lis r5, cm_803B73B8@ha
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x4, gc_env.r[0]);
    gc_env.r[6] = gc_env.r[5] + ((uint32_t)&cm_803B73B8 & 0xFFFF); // addi r6, r5, cm_803B73B8@l
    gc_mem_write32(gc_env.ram, gc_env.r[1] + -0xa0, gc_env.r[1]);
    gc_env.r[1] = gc_env.r[1] + -0xa0;
    uint64_t temp;
    memcpy(&temp, &gc_env.f[31], sizeof(double));
    gc_mem_write64(gc_env.ram, gc_env.r[1] + 0x98, temp); // stfd f31, 0x98(r1)
    uint64_t temp;
    memcpy(&temp, &gc_env.f[30], sizeof(double));
    gc_mem_write64(gc_env.ram, gc_env.r[1] + 0x90, temp); // stfd f30, 0x90(r1)
    uint64_t temp;
    memcpy(&temp, &gc_env.f[29], sizeof(double));
    gc_mem_write64(gc_env.ram, gc_env.r[1] + 0x88, temp); // stfd f29, 0x88(r1)
    uint64_t temp;
    memcpy(&temp, &gc_env.f[28], sizeof(double));
    gc_mem_write64(gc_env.ram, gc_env.r[1] + 0x80, temp); // stfd f28, 0x80(r1)
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x6C, gc_env.r[27]); // stmw r27, 0x6C(r1)
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x70, gc_env.r[28]); // stmw r27, 0x6C(r1)
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x74, gc_env.r[29]); // stmw r27, 0x6C(r1)
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x78, gc_env.r[30]); // stmw r27, 0x6C(r1)
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x7C, gc_env.r[31]); // stmw r27, 0x6C(r1)
    gc_env.r[28] = gc_env.r[3]; // Move register
    gc_env.r[29] = gc_env.r[4]; // Move register
    gc_env.r[4] = gc_env.r[28] + 36; // addi r4, r28, 0x24
    gc_env.r[31] = 0x0;
    gc_env.r[30] = 0x0;
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[3] + 0x34); // lfs f0, 0x34(r3)
    gc_env.f[0] = *(float*)&temp;
    gc_env.r[3] = gc_env.r[28] + 12; // addi r3, r28, 0xc
    gc_env.r[5] = gc_mem_read32(gc_env.ram, gc_env.r[6] + 0x0);
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[6] + 0x4);
    gc_env.f[1] = cm_804D7E60; // lfs f1, cm_804D7E60@sda21(r0)
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x4c, gc_env.r[5]);
    gc_env.r[5] = gc_env.r[1] + 88; // addi r5, r1, 0x58
    gc_env.f[0] = (float)gc_env.f[1] * (float)gc_env.f[0]; // fmuls f0, f1, f0
    gc_env.f[2] = cm_804D7E30; // lfs f2, cm_804D7E30@sda21(r0)
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x50, gc_env.r[0]);
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[6] + 0x8);
    gc_env.f[30] = (float)gc_env.f[2] * (float)gc_env.f[0]; // fmuls f30, f2, f0
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x54, gc_env.r[0]);
    lbVector_Diff();
    gc_env.r[3] = gc_env.r[1] + 88; // addi r3, r1, 0x58
    lbVector_Normalize();
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x60); // lfs f0, 0x60(r1)
    gc_env.f[0] = *(float*)&temp;
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x5C); // lfs f1, 0x5C(r1)
    gc_env.f[1] = *(float*)&temp;
    gc_env.f[2] = -gc_env.f[0]; // fneg f2, f0
    atan2f();
    gc_env.f[2] = gc_env.f[1]; // fmr f2, f1
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x58); // lfs f1, 0x58(r1)
    gc_env.f[1] = *(float*)&temp;
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x60); // lfs f0, 0x60(r1)
    gc_env.f[0] = *(float*)&temp;
    gc_env.f[1] = -gc_env.f[1]; // fneg f1, f1
    gc_env.f[28] = gc_env.f[2]; // fmr f28, f2
    gc_env.f[2] = -gc_env.f[0]; // fneg f2, f0
    atan2f();
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x4c);
    gc_env.f[0] = gc_env.f[1]; // fmr f0, f1
    gc_env.r[3] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x50);
    gc_env.f[1] = gc_env.f[30]; // fmr f1, f30
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x1c, gc_env.r[0]);
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x54);
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x20, gc_env.r[3]);
    gc_env.f[29] = gc_env.f[0]; // fmr f29, f0
    gc_env.r[3] = gc_env.r[1] + 64; // addi r3, r1, 0x40
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x24, gc_env.r[0]);
    gc_env.r[4] = 0x1;
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x1c);
    gc_env.r[5] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x20);
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x28, gc_env.r[0]);
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x24);
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x2c, gc_env.r[5]);
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x30, gc_env.r[0]);
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x28);
    gc_env.r[5] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x2c);
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x34, gc_env.r[0]);
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x30);
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x38, gc_env.r[5]);
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x3c, gc_env.r[0]);
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x34);
    gc_env.r[5] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x38);
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x40, gc_env.r[0]);
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x3c);
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x44, gc_env.r[5]);
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x48, gc_env.r[0]);
    lbVector_Rotate();
    gc_env.f[1] = gc_env.f[30]; // fmr f1, f30
    gc_env.r[3] = gc_env.r[1] + 64; // addi r3, r1, 0x40
    gc_env.r[4] = 0x2;
    lbVector_Rotate();
    gc_env.r[3] = ((uint32_t)&cm_803BCB64 >> 16) & 0xFFFF; // lis r3, cm_803BCB64@ha
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x40); // lfs f1, 0x40(r1)
    gc_env.f[1] = *(float*)&temp;
    gc_env.r[3] = gc_env.r[3] + ((uint32_t)&cm_803BCB64 & 0xFFFF); // addi r3, r3, cm_803BCB64@l
    gc_env.r[27] = gc_env.r[3] + 52; // addi r27, r3, 0x34
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[3] + 0x34); // lfs f0, 0x34(r3)
    gc_env.f[0] = *(float*)&temp;
    gc_env.r[3] = gc_env.r[1] + 64; // addi r3, r1, 0x40
    gc_env.f[0] = (float)gc_env.f[1] * (float)gc_env.f[0]; // fmuls f0, f1, f0
    float temp = (float)gc_env.f[0]; // stfs f0, 0x40(r1)
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x40, *(uint32_t*)&temp);
    lbVector_Normalize();
    gc_env.f[1] = gc_env.f[28]; // fmr f1, f28
    gc_env.r[3] = gc_env.r[1] + 64; // addi r3, r1, 0x40
    gc_env.r[4] = 0x1;
    lbVector_Rotate();
    gc_env.f[1] = gc_env.f[29]; // fmr f1, f29
    gc_env.r[3] = gc_env.r[1] + 64; // addi r3, r1, 0x40
    gc_env.r[4] = 0x2;
    lbVector_Rotate();
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x48); // lfs f2, 0x48(r1)
    gc_env.f[2] = *(float*)&temp;
    gc_env.f[0] = cm_804D7E6C; // lfs f0, cm_804D7E6C@sda21(r0)
    gc_env.cr[0] = isnan(gc_env.f[2]) || isnan(gc_env.f[0]) ? 0x1 : (gc_env.f[2] < gc_env.f[0] ? 0x8 : (gc_env.f[2] > gc_env.f[0] ? 0x4 : 0x2)); // fcmpo cr0, f2, f0
    if (gc_env.cr[0] >= 0) goto L_8002A92C;
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[28] + 0x2C); // lfs f1, 0x2C(r28)
    gc_env.f[1] = *(float*)&temp;
    gc_env.r[3] = gc_env.r[1] + 64; // addi r3, r1, 0x40
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x40); // lfs f0, 0x40(r1)
    gc_env.f[0] = *(float*)&temp;
    gc_env.r[4] = gc_env.r[28] + 36; // addi r4, r28, 0x24
    gc_env.f[1] = -gc_env.f[1]; // fneg f1, f1
    gc_env.f[1] = (float)gc_env.f[1] / (float)gc_env.f[2]; // fdivs f1, f1, f2
    gc_env.f[0] = (float)gc_env.f[0] * (float)gc_env.f[1]; // fmuls f0, f0, f1
    float temp = (float)gc_env.f[0]; // stfs f0, 0x40(r1)
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x40, *(uint32_t*)&temp);
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x44); // lfs f0, 0x44(r1)
    gc_env.f[0] = *(float*)&temp;
    gc_env.f[0] = (float)gc_env.f[0] * (float)gc_env.f[1]; // fmuls f0, f0, f1
    float temp = (float)gc_env.f[0]; // stfs f0, 0x44(r1)
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x44, *(uint32_t*)&temp);
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x48); // lfs f0, 0x48(r1)
    gc_env.f[0] = *(float*)&temp;
    gc_env.f[0] = (float)gc_env.f[0] * (float)gc_env.f[1]; // fmuls f0, f0, f1
    float temp = (float)gc_env.f[0]; // stfs f0, 0x48(r1)
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x48, *(uint32_t*)&temp);
    lbVector_Add();
    goto L_8002A930;
    L_8002A92C:
    gc_env.r[30] |= 1; // ori r30, r30, 0x1
    L_8002A930:
    gc_env.f[1] = gc_env.f[30]; // fmr f1, f30
    gc_env.r[3] = gc_env.r[1] + 52; // addi r3, r1, 0x34
    gc_env.r[4] = 0x1;
    lbVector_Rotate();
    gc_env.f[31] = -gc_env.f[30]; // fneg f31, f30
    gc_env.r[3] = gc_env.r[1] + 52; // addi r3, r1, 0x34
    gc_env.r[4] = 0x2;
    gc_env.f[1] = gc_env.f[31]; // fmr f1, f31
    lbVector_Rotate();
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x34); // lfs f1, 0x34(r1)
    gc_env.f[1] = *(float*)&temp;
    gc_env.r[3] = gc_env.r[1] + 52; // addi r3, r1, 0x34
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[27] + 0x0); // lfs f0, 0x0(r27)
    gc_env.f[0] = *(float*)&temp;
    gc_env.f[0] = (float)gc_env.f[1] * (float)gc_env.f[0]; // fmuls f0, f1, f0
    float temp = (float)gc_env.f[0]; // stfs f0, 0x34(r1)
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x34, *(uint32_t*)&temp);
    lbVector_Normalize();
    gc_env.f[1] = gc_env.f[28]; // fmr f1, f28
    gc_env.r[3] = gc_env.r[1] + 52; // addi r3, r1, 0x34
    gc_env.r[4] = 0x1;
    lbVector_Rotate();
    gc_env.f[1] = gc_env.f[29]; // fmr f1, f29
    gc_env.r[3] = gc_env.r[1] + 52; // addi r3, r1, 0x34
    gc_env.r[4] = 0x2;
    lbVector_Rotate();
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x3C); // lfs f2, 0x3C(r1)
    gc_env.f[2] = *(float*)&temp;
    gc_env.f[0] = cm_804D7E6C; // lfs f0, cm_804D7E6C@sda21(r0)
    gc_env.cr[0] = isnan(gc_env.f[2]) || isnan(gc_env.f[0]) ? 0x1 : (gc_env.f[2] < gc_env.f[0] ? 0x8 : (gc_env.f[2] > gc_env.f[0] ? 0x4 : 0x2)); // fcmpo cr0, f2, f0
    if (gc_env.cr[0] >= 0) goto L_8002A9DC;
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[28] + 0x2C); // lfs f1, 0x2C(r28)
    gc_env.f[1] = *(float*)&temp;
    gc_env.r[3] = gc_env.r[1] + 52; // addi r3, r1, 0x34
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x34); // lfs f0, 0x34(r1)
    gc_env.f[0] = *(float*)&temp;
    gc_env.r[4] = gc_env.r[28] + 36; // addi r4, r28, 0x24
    gc_env.f[1] = -gc_env.f[1]; // fneg f1, f1
    gc_env.f[1] = (float)gc_env.f[1] / (float)gc_env.f[2]; // fdivs f1, f1, f2
    gc_env.f[0] = (float)gc_env.f[0] * (float)gc_env.f[1]; // fmuls f0, f0, f1
    float temp = (float)gc_env.f[0]; // stfs f0, 0x34(r1)
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x34, *(uint32_t*)&temp);
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x38); // lfs f0, 0x38(r1)
    gc_env.f[0] = *(float*)&temp;
    gc_env.f[0] = (float)gc_env.f[0] * (float)gc_env.f[1]; // fmuls f0, f0, f1
    float temp = (float)gc_env.f[0]; // stfs f0, 0x38(r1)
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x38, *(uint32_t*)&temp);
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x3C); // lfs f0, 0x3C(r1)
    gc_env.f[0] = *(float*)&temp;
    gc_env.f[0] = (float)gc_env.f[0] * (float)gc_env.f[1]; // fmuls f0, f0, f1
    float temp = (float)gc_env.f[0]; // stfs f0, 0x3C(r1)
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x3C, *(uint32_t*)&temp);
    lbVector_Add();
    goto L_8002A9E0;
    L_8002A9DC:
    gc_env.r[30] |= 2; // ori r30, r30, 0x2
    L_8002A9E0:
    gc_env.f[1] = gc_env.f[31]; // fmr f1, f31
    gc_env.r[3] = gc_env.r[1] + 40; // addi r3, r1, 0x28
    gc_env.r[4] = 0x1;
    lbVector_Rotate();
    gc_env.f[1] = gc_env.f[30]; // fmr f1, f30
    gc_env.r[3] = gc_env.r[1] + 40; // addi r3, r1, 0x28
    gc_env.r[4] = 0x2;
    lbVector_Rotate();
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x28); // lfs f1, 0x28(r1)
    gc_env.f[1] = *(float*)&temp;
    gc_env.r[3] = gc_env.r[1] + 40; // addi r3, r1, 0x28
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[27] + 0x0); // lfs f0, 0x0(r27)
    gc_env.f[0] = *(float*)&temp;
    gc_env.f[0] = (float)gc_env.f[1] * (float)gc_env.f[0]; // fmuls f0, f1, f0
    float temp = (float)gc_env.f[0]; // stfs f0, 0x28(r1)
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x28, *(uint32_t*)&temp);
    lbVector_Normalize();
    gc_env.f[1] = gc_env.f[28]; // fmr f1, f28
    gc_env.r[3] = gc_env.r[1] + 40; // addi r3, r1, 0x28
    gc_env.r[4] = 0x1;
    lbVector_Rotate();
    gc_env.f[1] = gc_env.f[29]; // fmr f1, f29
    gc_env.r[3] = gc_env.r[1] + 40; // addi r3, r1, 0x28
    gc_env.r[4] = 0x2;
    lbVector_Rotate();
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x30); // lfs f2, 0x30(r1)
    gc_env.f[2] = *(float*)&temp;
    gc_env.f[0] = cm_804D7E6C; // lfs f0, cm_804D7E6C@sda21(r0)
    gc_env.cr[0] = isnan(gc_env.f[2]) || isnan(gc_env.f[0]) ? 0x1 : (gc_env.f[2] < gc_env.f[0] ? 0x8 : (gc_env.f[2] > gc_env.f[0] ? 0x4 : 0x2)); // fcmpo cr0, f2, f0
    if (gc_env.cr[0] >= 0) goto L_8002AA88;
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[28] + 0x2C); // lfs f1, 0x2C(r28)
    gc_env.f[1] = *(float*)&temp;
    gc_env.r[3] = gc_env.r[1] + 40; // addi r3, r1, 0x28
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x28); // lfs f0, 0x28(r1)
    gc_env.f[0] = *(float*)&temp;
    gc_env.r[4] = gc_env.r[28] + 36; // addi r4, r28, 0x24
    gc_env.f[1] = -gc_env.f[1]; // fneg f1, f1
    gc_env.f[1] = (float)gc_env.f[1] / (float)gc_env.f[2]; // fdivs f1, f1, f2
    gc_env.f[0] = (float)gc_env.f[0] * (float)gc_env.f[1]; // fmuls f0, f0, f1
    float temp = (float)gc_env.f[0]; // stfs f0, 0x28(r1)
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x28, *(uint32_t*)&temp);
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x2C); // lfs f0, 0x2C(r1)
    gc_env.f[0] = *(float*)&temp;
    gc_env.f[0] = (float)gc_env.f[0] * (float)gc_env.f[1]; // fmuls f0, f0, f1
    float temp = (float)gc_env.f[0]; // stfs f0, 0x2C(r1)
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x2C, *(uint32_t*)&temp);
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x30); // lfs f0, 0x30(r1)
    gc_env.f[0] = *(float*)&temp;
    gc_env.f[0] = (float)gc_env.f[0] * (float)gc_env.f[1]; // fmuls f0, f0, f1
    float temp = (float)gc_env.f[0]; // stfs f0, 0x30(r1)
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x30, *(uint32_t*)&temp);
    lbVector_Add();
    goto L_8002AA8C;
    L_8002AA88:
    gc_env.r[30] |= 4; // ori r30, r30, 0x4
    L_8002AA8C:
    gc_env.f[1] = gc_env.f[31]; // fmr f1, f31
    gc_env.r[3] = gc_env.r[1] + 28; // addi r3, r1, 0x1c
    gc_env.r[4] = 0x1;
    lbVector_Rotate();
    gc_env.f[1] = gc_env.f[31]; // fmr f1, f31
    gc_env.r[3] = gc_env.r[1] + 28; // addi r3, r1, 0x1c
    gc_env.r[4] = 0x2;
    lbVector_Rotate();
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x1C); // lfs f1, 0x1C(r1)
    gc_env.f[1] = *(float*)&temp;
    gc_env.r[3] = gc_env.r[1] + 28; // addi r3, r1, 0x1c
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[27] + 0x0); // lfs f0, 0x0(r27)
    gc_env.f[0] = *(float*)&temp;
    gc_env.f[0] = (float)gc_env.f[1] * (float)gc_env.f[0]; // fmuls f0, f1, f0
    float temp = (float)gc_env.f[0]; // stfs f0, 0x1C(r1)
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x1C, *(uint32_t*)&temp);
    lbVector_Normalize();
    gc_env.f[1] = gc_env.f[28]; // fmr f1, f28
    gc_env.r[3] = gc_env.r[1] + 28; // addi r3, r1, 0x1c
    gc_env.r[4] = 0x1;
    lbVector_Rotate();
    gc_env.f[1] = gc_env.f[29]; // fmr f1, f29
    gc_env.r[3] = gc_env.r[1] + 28; // addi r3, r1, 0x1c
    gc_env.r[4] = 0x2;
    lbVector_Rotate();
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x24); // lfs f2, 0x24(r1)
    gc_env.f[2] = *(float*)&temp;
    gc_env.f[0] = cm_804D7E6C; // lfs f0, cm_804D7E6C@sda21(r0)
    gc_env.cr[0] = isnan(gc_env.f[2]) || isnan(gc_env.f[0]) ? 0x1 : (gc_env.f[2] < gc_env.f[0] ? 0x8 : (gc_env.f[2] > gc_env.f[0] ? 0x4 : 0x2)); // fcmpo cr0, f2, f0
    if (gc_env.cr[0] >= 0) goto L_8002AB34;
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[28] + 0x2C); // lfs f1, 0x2C(r28)
    gc_env.f[1] = *(float*)&temp;
    gc_env.r[3] = gc_env.r[1] + 28; // addi r3, r1, 0x1c
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x1C); // lfs f0, 0x1C(r1)
    gc_env.f[0] = *(float*)&temp;
    gc_env.r[4] = gc_env.r[28] + 36; // addi r4, r28, 0x24
    gc_env.f[1] = -gc_env.f[1]; // fneg f1, f1
    gc_env.f[1] = (float)gc_env.f[1] / (float)gc_env.f[2]; // fdivs f1, f1, f2
    gc_env.f[0] = (float)gc_env.f[0] * (float)gc_env.f[1]; // fmuls f0, f0, f1
    float temp = (float)gc_env.f[0]; // stfs f0, 0x1C(r1)
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x1C, *(uint32_t*)&temp);
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x20); // lfs f0, 0x20(r1)
    gc_env.f[0] = *(float*)&temp;
    gc_env.f[0] = (float)gc_env.f[0] * (float)gc_env.f[1]; // fmuls f0, f0, f1
    float temp = (float)gc_env.f[0]; // stfs f0, 0x20(r1)
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x20, *(uint32_t*)&temp);
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x24); // lfs f0, 0x24(r1)
    gc_env.f[0] = *(float*)&temp;
    gc_env.f[0] = (float)gc_env.f[0] * (float)gc_env.f[1]; // fmuls f0, f0, f1
    float temp = (float)gc_env.f[0]; // stfs f0, 0x24(r1)
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x24, *(uint32_t*)&temp);
    lbVector_Add();
    goto L_8002AB38;
    L_8002AB34:
    gc_env.r[30] |= 8; // ori r30, r30, 0x8
    L_8002AB38:
    gc_env.f[28] = cm_804D7E14; // lfs f28, cm_804D7E14@sda21(r0)
    gc_env.cr[0] = (gc_env.r[29] == 0x0) ? 0 : (gc_env.r[29] < 0x0 ? -1 : 1); // Compare with immediate
    gc_env.f[29] = gc_env.f[28]; // fmr f29, f28
    gc_env.f[30] = gc_env.f[29]; // fmr f30, f29
    gc_env.f[31] = gc_env.f[30]; // fmr f31, f30
    if (gc_env.cr[0] == 0) goto L_8002ACD8;
    gc_env.r[0] = gc_env.r[30] & 0x1; // clrlwi r0, r30, 31
    if (gc_env.cr[0] != 0) goto L_8002ABB4;
    Stage_GetBlastZoneLeftOffset();
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x40); // lfs f0, 0x40(r1)
    gc_env.f[0] = *(float*)&temp;
    gc_env.cr[0] = isnan(gc_env.f[0]) || isnan(gc_env.f[1]) ? 0x1 : (gc_env.f[0] < gc_env.f[1] ? 0x8 : (gc_env.f[0] > gc_env.f[1] ? 0x4 : 0x2)); // fcmpo cr0, f0, f1
    if (gc_env.cr[0] >= 0) goto L_8002AB84;
    Stage_GetBlastZoneLeftOffset();
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x40); // lfs f0, 0x40(r1)
    gc_env.f[0] = *(float*)&temp;
    gc_env.f[0] = (float)gc_env.f[1] - (float)gc_env.f[0]; // fsubs f0, f1, f0
    gc_env.cr[0] = isnan(gc_env.f[0]) || isnan(gc_env.f[31]) ? 0x1 : (gc_env.f[0] < gc_env.f[31] ? 0x8 : (gc_env.f[0] > gc_env.f[31] ? 0x4 : 0x2)); // fcmpo cr0, f0, f31
    if (gc_env.cr[0] & (0x8 | 0x2)) goto L_8002AB84; // ble .L_8002AB84
    gc_env.f[31] = gc_env.f[0]; // fmr f31, f0
    gc_env.r[31] |= 4; // ori r31, r31, 0x4
    L_8002AB84:
    Stage_GetBlastZoneTopOffset();
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x44); // lfs f0, 0x44(r1)
    gc_env.f[0] = *(float*)&temp;
    gc_env.cr[0] = isnan(gc_env.f[0]) || isnan(gc_env.f[1]) ? 0x1 : (gc_env.f[0] < gc_env.f[1] ? 0x8 : (gc_env.f[0] > gc_env.f[1] ? 0x4 : 0x2)); // fcmpo cr0, f0, f1
    if (gc_env.cr[0] & (0x8 | 0x2)) goto L_8002ABB4; // ble .L_8002ABB4
    Stage_GetBlastZoneTopOffset();
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x44); // lfs f2, 0x44(r1)
    gc_env.f[2] = *(float*)&temp;
    gc_env.f[0] = cm_804D7E14; // lfs f0, cm_804D7E14@sda21(r0)
    gc_env.f[1] = (float)gc_env.f[1] - (float)gc_env.f[2]; // fsubs f1, f1, f2
    gc_env.cr[0] = isnan(gc_env.f[1]) || isnan(gc_env.f[0]) ? 0x1 : (gc_env.f[1] < gc_env.f[0] ? 0x8 : (gc_env.f[1] > gc_env.f[0] ? 0x4 : 0x2)); // fcmpo cr0, f1, f0
    if (gc_env.cr[0] >= 0) goto L_8002ABB4;
    gc_env.f[28] = gc_env.f[1]; // fmr f28, f1
    gc_env.r[31] |= 1; // ori r31, r31, 0x1
    L_8002ABB4:
    gc_env.r[0] = (gc_env.r[30] << 0) & 0x2; // rlwinm r0, r30, 0, 30, 30
    gc_env.cr[0] = (gc_env.r[0] == 0) ? 0x2 : ((int32_t)gc_env.r[0] < 0 ? 0x8 : 0x4);
    if (gc_env.cr[0] != 0) goto L_8002AC14;
    Stage_GetBlastZoneRightOffset();
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x34); // lfs f0, 0x34(r1)
    gc_env.f[0] = *(float*)&temp;
    gc_env.cr[0] = isnan(gc_env.f[0]) || isnan(gc_env.f[1]) ? 0x1 : (gc_env.f[0] < gc_env.f[1] ? 0x8 : (gc_env.f[0] > gc_env.f[1] ? 0x4 : 0x2)); // fcmpo cr0, f0, f1
    if (gc_env.cr[0] & (0x8 | 0x2)) goto L_8002ABE8; // ble .L_8002ABE8
    Stage_GetBlastZoneRightOffset();
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x34); // lfs f0, 0x34(r1)
    gc_env.f[0] = *(float*)&temp;
    gc_env.f[0] = (float)gc_env.f[1] - (float)gc_env.f[0]; // fsubs f0, f1, f0
    gc_env.cr[0] = isnan(gc_env.f[0]) || isnan(gc_env.f[29]) ? 0x1 : (gc_env.f[0] < gc_env.f[29] ? 0x8 : (gc_env.f[0] > gc_env.f[29] ? 0x4 : 0x2)); // fcmpo cr0, f0, f29
    if (gc_env.cr[0] >= 0) goto L_8002ABE8;
    gc_env.f[29] = gc_env.f[0]; // fmr f29, f0
    gc_env.r[31] |= 8; // ori r31, r31, 0x8
    L_8002ABE8:
    Stage_GetBlastZoneTopOffset();
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x38); // lfs f0, 0x38(r1)
    gc_env.f[0] = *(float*)&temp;
    gc_env.cr[0] = isnan(gc_env.f[0]) || isnan(gc_env.f[1]) ? 0x1 : (gc_env.f[0] < gc_env.f[1] ? 0x8 : (gc_env.f[0] > gc_env.f[1] ? 0x4 : 0x2)); // fcmpo cr0, f0, f1
    if (gc_env.cr[0] & (0x8 | 0x2)) goto L_8002AC14; // ble .L_8002AC14
    Stage_GetBlastZoneTopOffset();
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x38); // lfs f0, 0x38(r1)
    gc_env.f[0] = *(float*)&temp;
    gc_env.f[0] = (float)gc_env.f[1] - (float)gc_env.f[0]; // fsubs f0, f1, f0
    gc_env.cr[0] = isnan(gc_env.f[0]) || isnan(gc_env.f[28]) ? 0x1 : (gc_env.f[0] < gc_env.f[28] ? 0x8 : (gc_env.f[0] > gc_env.f[28] ? 0x4 : 0x2)); // fcmpo cr0, f0, f28
    if (gc_env.cr[0] >= 0) goto L_8002AC14;
    gc_env.f[28] = gc_env.f[0]; // fmr f28, f0
    gc_env.r[31] |= 1; // ori r31, r31, 0x1
    L_8002AC14:
    gc_env.r[0] = (gc_env.r[30] << 0) & 0x4; // rlwinm r0, r30, 0, 29, 29
    gc_env.cr[0] = (gc_env.r[0] == 0) ? 0x2 : ((int32_t)gc_env.r[0] < 0 ? 0x8 : 0x4);
    if (gc_env.cr[0] != 0) goto L_8002AC74;
    Stage_GetBlastZoneLeftOffset();
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x28); // lfs f0, 0x28(r1)
    gc_env.f[0] = *(float*)&temp;
    gc_env.cr[0] = isnan(gc_env.f[0]) || isnan(gc_env.f[1]) ? 0x1 : (gc_env.f[0] < gc_env.f[1] ? 0x8 : (gc_env.f[0] > gc_env.f[1] ? 0x4 : 0x2)); // fcmpo cr0, f0, f1
    if (gc_env.cr[0] >= 0) goto L_8002AC48;
    Stage_GetBlastZoneLeftOffset();
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x28); // lfs f0, 0x28(r1)
    gc_env.f[0] = *(float*)&temp;
    gc_env.f[0] = (float)gc_env.f[1] - (float)gc_env.f[0]; // fsubs f0, f1, f0
    gc_env.cr[0] = isnan(gc_env.f[0]) || isnan(gc_env.f[31]) ? 0x1 : (gc_env.f[0] < gc_env.f[31] ? 0x8 : (gc_env.f[0] > gc_env.f[31] ? 0x4 : 0x2)); // fcmpo cr0, f0, f31
    if (gc_env.cr[0] & (0x8 | 0x2)) goto L_8002AC48; // ble .L_8002AC48
    gc_env.f[31] = gc_env.f[0]; // fmr f31, f0
    gc_env.r[31] |= 4; // ori r31, r31, 0x4
    L_8002AC48:
    Stage_GetBlastZoneBottomOffset();
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x2C); // lfs f0, 0x2C(r1)
    gc_env.f[0] = *(float*)&temp;
    gc_env.cr[0] = isnan(gc_env.f[0]) || isnan(gc_env.f[1]) ? 0x1 : (gc_env.f[0] < gc_env.f[1] ? 0x8 : (gc_env.f[0] > gc_env.f[1] ? 0x4 : 0x2)); // fcmpo cr0, f0, f1
    if (gc_env.cr[0] >= 0) goto L_8002AC74;
    Stage_GetBlastZoneBottomOffset();
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x2C); // lfs f0, 0x2C(r1)
    gc_env.f[0] = *(float*)&temp;
    gc_env.f[0] = (float)gc_env.f[1] - (float)gc_env.f[0]; // fsubs f0, f1, f0
    gc_env.cr[0] = isnan(gc_env.f[0]) || isnan(gc_env.f[30]) ? 0x1 : (gc_env.f[0] < gc_env.f[30] ? 0x8 : (gc_env.f[0] > gc_env.f[30] ? 0x4 : 0x2)); // fcmpo cr0, f0, f30
    if (gc_env.cr[0] & (0x8 | 0x2)) goto L_8002AC74; // ble .L_8002AC74
    gc_env.f[30] = gc_env.f[0]; // fmr f30, f0
    gc_env.r[31] |= 2; // ori r31, r31, 0x2
    L_8002AC74:
    gc_env.r[0] = (gc_env.r[30] << 0) & 0x8; // rlwinm r0, r30, 0, 28, 28
    gc_env.cr[0] = (gc_env.r[0] == 0) ? 0x2 : ((int32_t)gc_env.r[0] < 0 ? 0x8 : 0x4);
    if (gc_env.cr[0] != 0) goto L_8002AE5C;
    Stage_GetBlastZoneRightOffset();
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x1C); // lfs f0, 0x1C(r1)
    gc_env.f[0] = *(float*)&temp;
    gc_env.cr[0] = isnan(gc_env.f[0]) || isnan(gc_env.f[1]) ? 0x1 : (gc_env.f[0] < gc_env.f[1] ? 0x8 : (gc_env.f[0] > gc_env.f[1] ? 0x4 : 0x2)); // fcmpo cr0, f0, f1
    if (gc_env.cr[0] & (0x8 | 0x2)) goto L_8002ACA8; // ble .L_8002ACA8
    Stage_GetBlastZoneRightOffset();
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x1C); // lfs f0, 0x1C(r1)
    gc_env.f[0] = *(float*)&temp;
    gc_env.f[0] = (float)gc_env.f[1] - (float)gc_env.f[0]; // fsubs f0, f1, f0
    gc_env.cr[0] = isnan(gc_env.f[0]) || isnan(gc_env.f[29]) ? 0x1 : (gc_env.f[0] < gc_env.f[29] ? 0x8 : (gc_env.f[0] > gc_env.f[29] ? 0x4 : 0x2)); // fcmpo cr0, f0, f29
    if (gc_env.cr[0] >= 0) goto L_8002ACA8;
    gc_env.f[29] = gc_env.f[0]; // fmr f29, f0
    gc_env.r[31] |= 8; // ori r31, r31, 0x8
    L_8002ACA8:
    Stage_GetBlastZoneBottomOffset();
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x20); // lfs f0, 0x20(r1)
    gc_env.f[0] = *(float*)&temp;
    gc_env.cr[0] = isnan(gc_env.f[0]) || isnan(gc_env.f[1]) ? 0x1 : (gc_env.f[0] < gc_env.f[1] ? 0x8 : (gc_env.f[0] > gc_env.f[1] ? 0x4 : 0x2)); // fcmpo cr0, f0, f1
    if (gc_env.cr[0] >= 0) goto L_8002AE5C;
    Stage_GetBlastZoneBottomOffset();
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x20); // lfs f0, 0x20(r1)
    gc_env.f[0] = *(float*)&temp;
    gc_env.f[0] = (float)gc_env.f[1] - (float)gc_env.f[0]; // fsubs f0, f1, f0
    gc_env.cr[0] = isnan(gc_env.f[0]) || isnan(gc_env.f[30]) ? 0x1 : (gc_env.f[0] < gc_env.f[30] ? 0x8 : (gc_env.f[0] > gc_env.f[30] ? 0x4 : 0x2)); // fcmpo cr0, f0, f30
    if (gc_env.cr[0] & (0x8 | 0x2)) goto L_8002AE5C; // ble .L_8002AE5C
    gc_env.f[30] = gc_env.f[0]; // fmr f30, f0
    gc_env.r[31] |= 2; // ori r31, r31, 0x2
    goto L_8002AE5C;
    L_8002ACD8:
    gc_env.r[0] = gc_env.r[30] & 0x1; // clrlwi r0, r30, 31
    if (gc_env.cr[0] != 0) goto L_8002AD3C;
    Stage_GetCamBoundsLeftOffset();
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x40); // lfs f0, 0x40(r1)
    gc_env.f[0] = *(float*)&temp;
    gc_env.cr[0] = isnan(gc_env.f[0]) || isnan(gc_env.f[1]) ? 0x1 : (gc_env.f[0] < gc_env.f[1] ? 0x8 : (gc_env.f[0] > gc_env.f[1] ? 0x4 : 0x2)); // fcmpo cr0, f0, f1
    if (gc_env.cr[0] >= 0) goto L_8002AD0C;
    Stage_GetCamBoundsLeftOffset();
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x40); // lfs f0, 0x40(r1)
    gc_env.f[0] = *(float*)&temp;
    gc_env.f[0] = (float)gc_env.f[1] - (float)gc_env.f[0]; // fsubs f0, f1, f0
    gc_env.cr[0] = isnan(gc_env.f[0]) || isnan(gc_env.f[31]) ? 0x1 : (gc_env.f[0] < gc_env.f[31] ? 0x8 : (gc_env.f[0] > gc_env.f[31] ? 0x4 : 0x2)); // fcmpo cr0, f0, f31
    if (gc_env.cr[0] & (0x8 | 0x2)) goto L_8002AD0C; // ble .L_8002AD0C
    gc_env.f[31] = gc_env.f[0]; // fmr f31, f0
    gc_env.r[31] |= 4; // ori r31, r31, 0x4
    L_8002AD0C:
    Stage_GetCamBoundsTopOffset();
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x44); // lfs f0, 0x44(r1)
    gc_env.f[0] = *(float*)&temp;
    gc_env.cr[0] = isnan(gc_env.f[0]) || isnan(gc_env.f[1]) ? 0x1 : (gc_env.f[0] < gc_env.f[1] ? 0x8 : (gc_env.f[0] > gc_env.f[1] ? 0x4 : 0x2)); // fcmpo cr0, f0, f1
    if (gc_env.cr[0] & (0x8 | 0x2)) goto L_8002AD3C; // ble .L_8002AD3C
    Stage_GetCamBoundsTopOffset();
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x44); // lfs f2, 0x44(r1)
    gc_env.f[2] = *(float*)&temp;
    gc_env.f[0] = cm_804D7E14; // lfs f0, cm_804D7E14@sda21(r0)
    gc_env.f[1] = (float)gc_env.f[1] - (float)gc_env.f[2]; // fsubs f1, f1, f2
    gc_env.cr[0] = isnan(gc_env.f[1]) || isnan(gc_env.f[0]) ? 0x1 : (gc_env.f[1] < gc_env.f[0] ? 0x8 : (gc_env.f[1] > gc_env.f[0] ? 0x4 : 0x2)); // fcmpo cr0, f1, f0
    if (gc_env.cr[0] >= 0) goto L_8002AD3C;
    gc_env.f[28] = gc_env.f[1]; // fmr f28, f1
    gc_env.r[31] |= 1; // ori r31, r31, 0x1
    L_8002AD3C:
    gc_env.r[0] = (gc_env.r[30] << 0) & 0x2; // rlwinm r0, r30, 0, 30, 30
    gc_env.cr[0] = (gc_env.r[0] == 0) ? 0x2 : ((int32_t)gc_env.r[0] < 0 ? 0x8 : 0x4);
    if (gc_env.cr[0] != 0) goto L_8002AD9C;
    Stage_GetCamBoundsRightOffset();
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x34); // lfs f0, 0x34(r1)
    gc_env.f[0] = *(float*)&temp;
    gc_env.cr[0] = isnan(gc_env.f[0]) || isnan(gc_env.f[1]) ? 0x1 : (gc_env.f[0] < gc_env.f[1] ? 0x8 : (gc_env.f[0] > gc_env.f[1] ? 0x4 : 0x2)); // fcmpo cr0, f0, f1
    if (gc_env.cr[0] & (0x8 | 0x2)) goto L_8002AD70; // ble .L_8002AD70
    Stage_GetCamBoundsRightOffset();
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x34); // lfs f0, 0x34(r1)
    gc_env.f[0] = *(float*)&temp;
    gc_env.f[0] = (float)gc_env.f[1] - (float)gc_env.f[0]; // fsubs f0, f1, f0
    gc_env.cr[0] = isnan(gc_env.f[0]) || isnan(gc_env.f[29]) ? 0x1 : (gc_env.f[0] < gc_env.f[29] ? 0x8 : (gc_env.f[0] > gc_env.f[29] ? 0x4 : 0x2)); // fcmpo cr0, f0, f29
    if (gc_env.cr[0] >= 0) goto L_8002AD70;
    gc_env.f[29] = gc_env.f[0]; // fmr f29, f0
    gc_env.r[31] |= 8; // ori r31, r31, 0x8
    L_8002AD70:
    Stage_GetCamBoundsTopOffset();
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x38); // lfs f0, 0x38(r1)
    gc_env.f[0] = *(float*)&temp;
    gc_env.cr[0] = isnan(gc_env.f[0]) || isnan(gc_env.f[1]) ? 0x1 : (gc_env.f[0] < gc_env.f[1] ? 0x8 : (gc_env.f[0] > gc_env.f[1] ? 0x4 : 0x2)); // fcmpo cr0, f0, f1
    if (gc_env.cr[0] & (0x8 | 0x2)) goto L_8002AD9C; // ble .L_8002AD9C
    Stage_GetCamBoundsTopOffset();
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x38); // lfs f0, 0x38(r1)
    gc_env.f[0] = *(float*)&temp;
    gc_env.f[0] = (float)gc_env.f[1] - (float)gc_env.f[0]; // fsubs f0, f1, f0
    gc_env.cr[0] = isnan(gc_env.f[0]) || isnan(gc_env.f[28]) ? 0x1 : (gc_env.f[0] < gc_env.f[28] ? 0x8 : (gc_env.f[0] > gc_env.f[28] ? 0x4 : 0x2)); // fcmpo cr0, f0, f28
    if (gc_env.cr[0] >= 0) goto L_8002AD9C;
    gc_env.f[28] = gc_env.f[0]; // fmr f28, f0
    gc_env.r[31] |= 1; // ori r31, r31, 0x1
    L_8002AD9C:
    gc_env.r[0] = (gc_env.r[30] << 0) & 0x4; // rlwinm r0, r30, 0, 29, 29
    gc_env.cr[0] = (gc_env.r[0] == 0) ? 0x2 : ((int32_t)gc_env.r[0] < 0 ? 0x8 : 0x4);
    if (gc_env.cr[0] != 0) goto L_8002ADFC;
    Stage_GetCamBoundsLeftOffset();
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x28); // lfs f0, 0x28(r1)
    gc_env.f[0] = *(float*)&temp;
    gc_env.cr[0] = isnan(gc_env.f[0]) || isnan(gc_env.f[1]) ? 0x1 : (gc_env.f[0] < gc_env.f[1] ? 0x8 : (gc_env.f[0] > gc_env.f[1] ? 0x4 : 0x2)); // fcmpo cr0, f0, f1
    if (gc_env.cr[0] >= 0) goto L_8002ADD0;
    Stage_GetCamBoundsLeftOffset();
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x28); // lfs f0, 0x28(r1)
    gc_env.f[0] = *(float*)&temp;
    gc_env.f[0] = (float)gc_env.f[1] - (float)gc_env.f[0]; // fsubs f0, f1, f0
    gc_env.cr[0] = isnan(gc_env.f[0]) || isnan(gc_env.f[31]) ? 0x1 : (gc_env.f[0] < gc_env.f[31] ? 0x8 : (gc_env.f[0] > gc_env.f[31] ? 0x4 : 0x2)); // fcmpo cr0, f0, f31
    if (gc_env.cr[0] & (0x8 | 0x2)) goto L_8002ADD0; // ble .L_8002ADD0
    gc_env.f[31] = gc_env.f[0]; // fmr f31, f0
    gc_env.r[31] |= 4; // ori r31, r31, 0x4
    L_8002ADD0:
    Stage_GetCamBoundsBottomOffset();
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x2C); // lfs f0, 0x2C(r1)
    gc_env.f[0] = *(float*)&temp;
    gc_env.cr[0] = isnan(gc_env.f[0]) || isnan(gc_env.f[1]) ? 0x1 : (gc_env.f[0] < gc_env.f[1] ? 0x8 : (gc_env.f[0] > gc_env.f[1] ? 0x4 : 0x2)); // fcmpo cr0, f0, f1
    if (gc_env.cr[0] >= 0) goto L_8002ADFC;
    Stage_GetCamBoundsBottomOffset();
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x2C); // lfs f0, 0x2C(r1)
    gc_env.f[0] = *(float*)&temp;
    gc_env.f[0] = (float)gc_env.f[1] - (float)gc_env.f[0]; // fsubs f0, f1, f0
    gc_env.cr[0] = isnan(gc_env.f[0]) || isnan(gc_env.f[30]) ? 0x1 : (gc_env.f[0] < gc_env.f[30] ? 0x8 : (gc_env.f[0] > gc_env.f[30] ? 0x4 : 0x2)); // fcmpo cr0, f0, f30
    if (gc_env.cr[0] & (0x8 | 0x2)) goto L_8002ADFC; // ble .L_8002ADFC
    gc_env.f[30] = gc_env.f[0]; // fmr f30, f0
    gc_env.r[31] |= 2; // ori r31, r31, 0x2
    L_8002ADFC:
    gc_env.r[0] = (gc_env.r[30] << 0) & 0x8; // rlwinm r0, r30, 0, 28, 28
    gc_env.cr[0] = (gc_env.r[0] == 0) ? 0x2 : ((int32_t)gc_env.r[0] < 0 ? 0x8 : 0x4);
    if (gc_env.cr[0] != 0) goto L_8002AE5C;
    Stage_GetCamBoundsRightOffset();
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x1C); // lfs f0, 0x1C(r1)
    gc_env.f[0] = *(float*)&temp;
    gc_env.cr[0] = isnan(gc_env.f[0]) || isnan(gc_env.f[1]) ? 0x1 : (gc_env.f[0] < gc_env.f[1] ? 0x8 : (gc_env.f[0] > gc_env.f[1] ? 0x4 : 0x2)); // fcmpo cr0, f0, f1
    if (gc_env.cr[0] & (0x8 | 0x2)) goto L_8002AE30; // ble .L_8002AE30
    Stage_GetCamBoundsRightOffset();
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x1C); // lfs f0, 0x1C(r1)
    gc_env.f[0] = *(float*)&temp;
    gc_env.f[0] = (float)gc_env.f[1] - (float)gc_env.f[0]; // fsubs f0, f1, f0
    gc_env.cr[0] = isnan(gc_env.f[0]) || isnan(gc_env.f[29]) ? 0x1 : (gc_env.f[0] < gc_env.f[29] ? 0x8 : (gc_env.f[0] > gc_env.f[29] ? 0x4 : 0x2)); // fcmpo cr0, f0, f29
    if (gc_env.cr[0] >= 0) goto L_8002AE30;
    gc_env.f[29] = gc_env.f[0]; // fmr f29, f0
    gc_env.r[31] |= 8; // ori r31, r31, 0x8
    L_8002AE30:
    Stage_GetCamBoundsBottomOffset();
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x20); // lfs f0, 0x20(r1)
    gc_env.f[0] = *(float*)&temp;
    gc_env.cr[0] = isnan(gc_env.f[0]) || isnan(gc_env.f[1]) ? 0x1 : (gc_env.f[0] < gc_env.f[1] ? 0x8 : (gc_env.f[0] > gc_env.f[1] ? 0x4 : 0x2)); // fcmpo cr0, f0, f1
    if (gc_env.cr[0] >= 0) goto L_8002AE5C;
    Stage_GetCamBoundsBottomOffset();
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x20); // lfs f0, 0x20(r1)
    gc_env.f[0] = *(float*)&temp;
    gc_env.f[0] = (float)gc_env.f[1] - (float)gc_env.f[0]; // fsubs f0, f1, f0
    gc_env.cr[0] = isnan(gc_env.f[0]) || isnan(gc_env.f[30]) ? 0x1 : (gc_env.f[0] < gc_env.f[30] ? 0x8 : (gc_env.f[0] > gc_env.f[30] ? 0x4 : 0x2)); // fcmpo cr0, f0, f30
    if (gc_env.cr[0] & (0x8 | 0x2)) goto L_8002AE5C; // ble .L_8002AE5C
    gc_env.f[30] = gc_env.f[0]; // fmr f30, f0
    gc_env.r[31] |= 2; // ori r31, r31, 0x2
    L_8002AE5C:
    gc_env.cr[0] = (gc_env.r[31] == 0x0) ? 0 : (gc_env.r[31] < 0x0 ? -1 : 1); // Compare with immediate
    if (gc_env.cr[0] == 0) goto L_8002AF44;
    gc_env.r[3] = ((uint32_t)&cm_803B73C4 >> 16) & 0xFFFF; // lis r3, cm_803B73C4@ha
    gc_env.r[4] = gc_env.r[3] + ((uint32_t)&cm_803B73C4 & 0xFFFF); // addi r4, r3, cm_803B73C4@l
    gc_env.r[3] = gc_mem_read32(gc_env.ram, gc_env.r[4] + 0x0);
    gc_env.r[5] = (gc_env.r[31] << 0) & 0x4; // rlwinm r5, r31, 0, 29, 29
    gc_env.cr[0] = (gc_env.r[5] == 0) ? 0x2 : ((int32_t)gc_env.r[5] < 0 ? 0x8 : 0x4);
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[4] + 0x4);
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x10, gc_env.r[3]);
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x14, gc_env.r[0]);
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[4] + 0x8);
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x18, gc_env.r[0]);
    if (gc_env.cr[0] == 0) goto L_8002AEA8;
    gc_env.r[0] = (gc_env.r[31] << 0) & 0x8; // rlwinm r0, r31, 0, 28, 28
    gc_env.cr[0] = (gc_env.r[0] == 0) ? 0x2 : ((int32_t)gc_env.r[0] < 0 ? 0x8 : 0x4);
    if (gc_env.cr[0] == 0) goto L_8002AEA8;
    gc_env.f[0] = (float)gc_env.f[31] + (float)gc_env.f[29]; // fadds f0, f31, f29
    gc_env.f[1] = cm_804D7E30; // lfs f1, cm_804D7E30@sda21(r0)
    gc_env.f[0] = (float)gc_env.f[1] * (float)gc_env.f[0]; // fmuls f0, f1, f0
    float temp = (float)gc_env.f[0]; // stfs f0, 0x10(r1)
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x10, *(uint32_t*)&temp);
    goto L_8002AEC4;
    L_8002AEA8:
    gc_env.cr[0] = (gc_env.r[5] == 0x0) ? 0 : (gc_env.r[5] < 0x0 ? -1 : 1); // Compare with immediate
    if (gc_env.cr[0] == 0) goto L_8002AEB8;
    float temp = (float)gc_env.f[31]; // stfs f31, 0x10(r1)
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x10, *(uint32_t*)&temp);
    goto L_8002AEC4;
    L_8002AEB8:
    gc_env.r[0] = (gc_env.r[31] << 0) & 0x8; // rlwinm r0, r31, 0, 28, 28
    gc_env.cr[0] = (gc_env.r[0] == 0) ? 0x2 : ((int32_t)gc_env.r[0] < 0 ? 0x8 : 0x4);
    if (gc_env.cr[0] == 0) goto L_8002AEC4;
    float temp = (float)gc_env.f[29]; // stfs f29, 0x10(r1)
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x10, *(uint32_t*)&temp);
    L_8002AEC4:
    gc_env.r[3] = gc_env.r[31] & 0x1; // clrlwi r3, r31, 31
    if (gc_env.cr[0] == 0) goto L_8002AEE8;
    gc_env.r[0] = (gc_env.r[31] << 0) & 0x2; // rlwinm r0, r31, 0, 30, 30
    gc_env.cr[0] = (gc_env.r[0] == 0) ? 0x2 : ((int32_t)gc_env.r[0] < 0 ? 0x8 : 0x4);
    if (gc_env.cr[0] == 0) goto L_8002AEE8;
    gc_env.f[0] = (float)gc_env.f[30] + (float)gc_env.f[28]; // fadds f0, f30, f28
    gc_env.f[1] = cm_804D7E30; // lfs f1, cm_804D7E30@sda21(r0)
    gc_env.f[0] = (float)gc_env.f[1] * (float)gc_env.f[0]; // fmuls f0, f1, f0
    float temp = (float)gc_env.f[0]; // stfs f0, 0x14(r1)
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x14, *(uint32_t*)&temp);
    goto L_8002AF04;
    L_8002AEE8:
    gc_env.cr[0] = (gc_env.r[3] == 0x0) ? 0 : (gc_env.r[3] < 0x0 ? -1 : 1); // Compare with immediate
    if (gc_env.cr[0] == 0) goto L_8002AEF8;
    float temp = (float)gc_env.f[28]; // stfs f28, 0x14(r1)
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x14, *(uint32_t*)&temp);
    goto L_8002AF04;
    L_8002AEF8:
    gc_env.r[0] = (gc_env.r[31] << 0) & 0x2; // rlwinm r0, r31, 0, 30, 30
    gc_env.cr[0] = (gc_env.r[0] == 0) ? 0x2 : ((int32_t)gc_env.r[0] < 0 ? 0x8 : 0x4);
    if (gc_env.cr[0] == 0) goto L_8002AF04;
    float temp = (float)gc_env.f[30]; // stfs f30, 0x14(r1)
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x14, *(uint32_t*)&temp);
    L_8002AF04:
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x10); // lfs f0, 0x10(r1)
    gc_env.f[0] = *(float*)&temp;
    gc_env.r[3] = gc_env.r[28] + 36; // addi r3, r28, 0x24
    gc_env.f[1] = cm_804D7E04; // lfs f1, cm_804D7E04@sda21(r0)
    gc_env.r[4] = gc_env.r[1] + 16; // addi r4, r1, 0x10
    gc_env.f[0] = (float)gc_env.f[0] * (float)gc_env.f[1]; // fmuls f0, f0, f1
    float temp = (float)gc_env.f[0]; // stfs f0, 0x10(r1)
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x10, *(uint32_t*)&temp);
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x14); // lfs f0, 0x14(r1)
    gc_env.f[0] = *(float*)&temp;
    gc_env.f[0] = (float)gc_env.f[0] * (float)gc_env.f[1]; // fmuls f0, f0, f1
    float temp = (float)gc_env.f[0]; // stfs f0, 0x14(r1)
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x14, *(uint32_t*)&temp);
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x18); // lfs f0, 0x18(r1)
    gc_env.f[0] = *(float*)&temp;
    gc_env.f[0] = (float)gc_env.f[0] * (float)gc_env.f[1]; // fmuls f0, f0, f1
    float temp = (float)gc_env.f[0]; // stfs f0, 0x18(r1)
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x18, *(uint32_t*)&temp);
    lbVector_Add();
    gc_env.r[3] = gc_env.r[28] + 12; // addi r3, r28, 0xc
    gc_env.r[4] = gc_env.r[1] + 16; // addi r4, r1, 0x10
    lbVector_Add();
    L_8002AF44:
    gc_env.r[27] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x6C); // lmw r27, 0x6C(r1)
    gc_env.r[28] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x70); // lmw r27, 0x6C(r1)
    gc_env.r[29] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x74); // lmw r27, 0x6C(r1)
    gc_env.r[30] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x78); // lmw r27, 0x6C(r1)
    gc_env.r[31] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x7C); // lmw r27, 0x6C(r1)
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0xa4);
    uint64_t temp = gc_mem_read64(gc_env.ram, gc_env.r[1] + 0x98); // lfd f31, 0x98(r1)
    gc_env.d[31] = *(double*)&temp;
    uint64_t temp = gc_mem_read64(gc_env.ram, gc_env.r[1] + 0x90); // lfd f30, 0x90(r1)
    gc_env.d[30] = *(double*)&temp;
    uint64_t temp = gc_mem_read64(gc_env.ram, gc_env.r[1] + 0x88); // lfd f29, 0x88(r1)
    gc_env.d[29] = *(double*)&temp;
    uint64_t temp = gc_mem_read64(gc_env.ram, gc_env.r[1] + 0x80); // lfd f28, 0x80(r1)
    gc_env.d[28] = *(double*)&temp;
    gc_env.r[1] += 160; // addi r1, r1, 0xa0
    gc_env.lr = gc_env.r[0]; // Move to link register
    return;
}

// Function: Camera_8002AF68
void Camera_8002AF68(void) {
    gc_env.r[0] = gc_env.lr; // Move from link register
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x4, gc_env.r[0]);
    gc_mem_write32(gc_env.ram, gc_env.r[1] + -0x38, gc_env.r[1]);
    gc_env.r[1] = gc_env.r[1] + -0x38;
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x34, gc_env.r[31]);
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x30, gc_env.r[30]);
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x2c, gc_env.r[29]);
    gc_env.r[29] = gc_env.r[4] + 0; // addi r29, r4, 0x0
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x28, gc_env.r[28]);
    gc_env.r[28] = gc_env.r[3] + 0; // addi r28, r3, 0x0
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[4] + 0x30); // lfs f1, 0x30(r4)
    gc_env.f[1] = *(float*)&temp;
    HSD_CObjSetFov();
    gc_env.r[4] = gc_mem_read32(gc_env.ram, gc_env.r[29] + 0x0);
    gc_env.r[3] = ((uint32_t)&cm_80452C68 >> 16) & 0xFFFF; // lis r3, cm_80452C68@ha
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[29] + 0x4);
    gc_env.r[3] = gc_env.r[3] + ((uint32_t)&cm_80452C68 & 0xFFFF); // addi r3, r3, cm_80452C68@l
    gc_env.r[31] = gc_env.r[3] + 132; // addi r31, r3, 0x84
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x14, gc_env.r[4]);
    gc_env.r[30] = gc_env.r[3] + 136; // addi r30, r3, 0x88
    gc_env.r[3] = gc_env.r[28] + 0; // addi r3, r28, 0x0
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x18, gc_env.r[0]);
    gc_env.r[4] = gc_env.r[1] + 20; // addi r4, r1, 0x14
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[29] + 0x8);
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x1c, gc_env.r[0]);
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x14); // lfs f1, 0x14(r1)
    gc_env.f[1] = *(float*)&temp;
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[31] + 0x0); // lfs f0, 0x0(r31)
    gc_env.f[0] = *(float*)&temp;
    gc_env.f[0] = (float)gc_env.f[1] + (float)gc_env.f[0]; // fadds f0, f1, f0
    float temp = (float)gc_env.f[0]; // stfs f0, 0x14(r1)
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x14, *(uint32_t*)&temp);
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x18); // lfs f1, 0x18(r1)
    gc_env.f[1] = *(float*)&temp;
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[30] + 0x0); // lfs f0, 0x0(r30)
    gc_env.f[0] = *(float*)&temp;
    gc_env.f[0] = (float)gc_env.f[1] + (float)gc_env.f[0]; // fadds f0, f1, f0
    float temp = (float)gc_env.f[0]; // stfs f0, 0x18(r1)
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x18, *(uint32_t*)&temp);
    HSD_CObjSetInterest();
    gc_env.r[4] = gc_mem_read32(gc_env.ram, gc_env.r[29] + 0x18);
    gc_env.r[3] = ((uint32_t)&stage_info >> 16) & 0xFFFF; // lis r3, stage_info@ha
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[29] + 0x1c);
    gc_env.r[3] = gc_env.r[3] + ((uint32_t)&stage_info & 0xFFFF); // addi r3, r3, stage_info@l
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x14, gc_env.r[4]);
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x18, gc_env.r[0]);
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[29] + 0x20);
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x1c, gc_env.r[0]);
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x14); // lfs f1, 0x14(r1)
    gc_env.f[1] = *(float*)&temp;
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[31] + 0x0); // lfs f0, 0x0(r31)
    gc_env.f[0] = *(float*)&temp;
    gc_env.f[0] = (float)gc_env.f[1] + (float)gc_env.f[0]; // fadds f0, f1, f0
    float temp = (float)gc_env.f[0]; // stfs f0, 0x14(r1)
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x14, *(uint32_t*)&temp);
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x18); // lfs f1, 0x18(r1)
    gc_env.f[1] = *(float*)&temp;
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[30] + 0x0); // lfs f0, 0x0(r30)
    gc_env.f[0] = *(float*)&temp;
    gc_env.f[0] = (float)gc_env.f[1] + (float)gc_env.f[0]; // fadds f0, f1, f0
    float temp = (float)gc_env.f[0]; // stfs f0, 0x18(r1)
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x18, *(uint32_t*)&temp);
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[3] + 0x88);
    gc_env.f[1] = cm_804D7E00; // lfs f1, cm_804D7E00@sda21(r0)
    gc_env.cr[0] = (gc_env.r[0] == 0xe) ? 0 : (gc_env.r[0] < 0xe ? -1 : 1); // Compare with immediate
    if (gc_env.cr[0] == 0) goto L_8002B080;
    if (gc_env.cr[0] >= 0) goto L_8002B060;
    gc_env.cr[0] = (gc_env.r[0] == 0x5) ? 0 : (gc_env.r[0] < 0x5 ? -1 : 1); // Compare with immediate
    if (gc_env.cr[0] == 0) goto L_8002B090;
    if (gc_env.cr[0] >= 0) goto L_8002B054;
    gc_env.cr[0] = (gc_env.r[0] == 0x2) ? 0 : (gc_env.r[0] < 0x2 ? -1 : 1); // Compare with immediate
    if (gc_env.cr[0] == 0) goto L_8002B078;
    goto L_8002B0A4;
    L_8002B054:
    gc_env.cr[0] = (gc_env.r[0] == 0x8) ? 0 : (gc_env.r[0] < 0x8 ? -1 : 1); // Compare with immediate
    if (gc_env.cr[0] == 0) goto L_8002B088;
    goto L_8002B0A4;
    L_8002B060:
    gc_env.cr[0] = (gc_env.r[0] == 0x43) ? 0 : (gc_env.r[0] < 0x43 ? -1 : 1); // Compare with immediate
    if (gc_env.cr[0] == 0) goto L_8002B0A0;
    if (gc_env.cr[0] >= 0) goto L_8002B0A4;
    gc_env.cr[0] = (gc_env.r[0] == 0x1f) ? 0 : (gc_env.r[0] < 0x1f ? -1 : 1); // Compare with immediate
    if (gc_env.cr[0] == 0) goto L_8002B098;
    goto L_8002B0A4;
    L_8002B078:
    grCastle_801D0FF0();
    goto L_8002B0A4;
    L_8002B080:
    grCorneria_801E2FCC();
    goto L_8002B0A4;
    L_8002B088:
    grZebes_801DCCC8();
    goto L_8002B0A4;
    L_8002B090:
    grGarden_80203624();
    goto L_8002B0A4;
    L_8002B098:
    grShrineRoute_802087B0();
    goto L_8002B0A4;
    L_8002B0A0:
    grHomeRun_8021EF10();
    L_8002B0A4:
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x18); // lfs f0, 0x18(r1)
    gc_env.f[0] = *(float*)&temp;
    gc_env.cr[0] = isnan(gc_env.f[0]) || isnan(gc_env.f[1]) ? 0x1 : (gc_env.f[0] < gc_env.f[1] ? 0x8 : (gc_env.f[0] > gc_env.f[1] ? 0x4 : 0x2)); // fcmpo cr0, f0, f1
    if (gc_env.cr[0] >= 0) goto L_8002B0B4;
    float temp = (float)gc_env.f[1]; // stfs f1, 0x18(r1)
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x18, *(uint32_t*)&temp);
    L_8002B0B4:
    gc_env.r[3] = gc_env.r[28] + 0; // addi r3, r28, 0x0
    gc_env.r[4] = gc_env.r[1] + 20; // addi r4, r1, 0x14
    HSD_CObjSetEyePosition();
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x3c);
    gc_env.r[31] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x34);
    gc_env.r[30] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x30);
    gc_env.r[29] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x2c);
    gc_env.r[28] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x28);
    gc_env.r[1] += 56; // addi r1, r1, 0x38
    gc_env.lr = gc_env.r[0]; // Move to link register
    return;
}

// Function: Camera_8002B0E0
void Camera_8002B0E0(void) {
    gc_env.r[0] = gc_env.lr; // Move from link register
    gc_env.r[3] = ((uint32_t)&cm_80452C68 >> 16) & 0xFFFF; // lis r3, cm_80452C68@ha
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x4, gc_env.r[0]);
    gc_mem_write32(gc_env.ram, gc_env.r[1] + -0x20, gc_env.r[1]);
    gc_env.r[1] = gc_env.r[1] + -0x20;
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x1c, gc_env.r[31]);
    gc_env.r[31] = gc_env.r[3] + ((uint32_t)&cm_80452C68 & 0xFFFF); // addi r31, r3, cm_80452C68@l
    gm_8016B41C();
    gc_env.cr[0] = (gc_env.r[3] == 0x0) ? 0 : (gc_env.r[3] < 0x0 ? -1 : 1); // Compare with immediate
    if (gc_env.cr[0] == 0) goto L_8002B1E4;
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[31] + 0x2C0); // lfs f1, 0x2C0(r31)
    gc_env.f[1] = *(float*)&temp;
    gc_env.f[0] = cm_804D7E14; // lfs f0, cm_804D7E14@sda21(r0)
    gc_env.cr[0] = isnan(gc_env.f[1]) || isnan(gc_env.f[0]) ? 0x1 : (gc_env.f[1] < gc_env.f[0] ? 0x8 : (gc_env.f[1] > gc_env.f[0] ? 0x4 : 0x2)); // fcmpo cr0, f1, f0
    if (gc_env.cr[0] & (0x8 | 0x2)) goto L_8002B1E4; // ble .L_8002B1E4
    gc_env.r[3] = 0x0;
    Player_GetPlayerId();
    gc_env.r[0] = gc_env.r[3] & 0xFF; // clrlwi r0, r3, 24
    gc_env.f[0] = cm_804D7E14; // lfs f0, cm_804D7E14@sda21(r0)
    gc_env.r[0] = gc_env.r[0] * 68;
    gc_env.r[3] = ((uint32_t)&HSD_PadCopyStatus >> 16) & 0xFFFF; // lis r3, HSD_PadCopyStatus@ha
    gc_env.r[3] = gc_env.r[3] + ((uint32_t)&HSD_PadCopyStatus & 0xFFFF); // addi r3, r3, HSD_PadCopyStatus@l
    gc_env.r[3] = gc_env.r[3] + gc_env.r[0];
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[3] + 0x2C); // lfs f1, 0x2C(r3)
    gc_env.f[1] = *(float*)&temp;
    gc_env.cr[0] = isnan(gc_env.f[1]) || isnan(gc_env.f[0]) ? 0x1 : (gc_env.f[1] < gc_env.f[0] ? 0x8 : (gc_env.f[1] > gc_env.f[0] ? 0x4 : 0x2)); // fcmpo cr0, f1, f0
    gc_env.f[2] = gc_env.f[1]; // fmr f2, f1
    if (gc_env.cr[0] >= 0) goto L_8002B148;
    gc_env.f[1] = -gc_env.f[1]; // fneg f1, f1
    L_8002B148:
    gc_env.f[0] = cm_804D7E74; // lfs f0, cm_804D7E74@sda21(r0)
    gc_env.cr[0] = isnan(gc_env.f[1]) || isnan(gc_env.f[0]) ? 0x1 : (gc_env.f[1] < gc_env.f[0] ? 0x8 : (gc_env.f[1] > gc_env.f[0] ? 0x4 : 0x2)); // fcmpo cr0, f1, f0
    if (gc_env.cr[0] >= 0) goto L_8002B184;
    gc_env.r[4] = gc_env.r[31] + 698; // addi r4, r31, 0x2ba
    gc_env.f[2] = cm_804D7E14; // lfs f2, cm_804D7E14@sda21(r0)
    gc_env.r[3] = (int32_t)(int16_t)gc_mem_read16(gc_env.ram, gc_env.r[31] + 0x2BA); // lha r3, 0x2BA(r31)
    gc_env.cr[0] = (gc_env.r[3] == 0x0) ? 0 : (gc_env.r[3] < 0x0 ? -1 : 1); // Compare with immediate
    if (gc_env.cr[0] & (0x8 | 0x2)) goto L_8002B174; // ble .L_8002B174
    gc_env.r[0] = gc_env.r[3] - 1;
    gc_mem_write16(gc_env.ram, gc_env.r[4] + 0x0, gc_env.r[0]);
    goto L_8002B1A0;
    L_8002B174:
    gc_env.r[3] = ((uint32_t)&cm_803BCCA0 >> 16) & 0xFFFF; // lis r3, cm_803BCCA0@ha
    gc_env.r[3] = gc_env.r[3] + ((uint32_t)&cm_803BCCA0 & 0xFFFF); // addi r3, r3, cm_803BCCA0@l
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[3] + 0xE4); // lfs f2, 0xE4(r3)
    gc_env.f[2] = *(float*)&temp;
    goto L_8002B1A0;
    L_8002B184:
    gc_env.r[3] = ((uint32_t)&cm_803BCCA0 >> 16) & 0xFFFF; // lis r3, cm_803BCCA0@ha
    gc_env.r[3] = gc_env.r[3] + ((uint32_t)&cm_803BCCA0 & 0xFFFF); // addi r3, r3, cm_803BCCA0@l
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[3] + 0xE0); // lfs f0, 0xE0(r3)
    gc_env.f[0] = *(float*)&temp;
    // Unknown opcode: fctiwz f0 f0
    uint64_t temp;
    memcpy(&temp, &gc_env.f[0], sizeof(double));
    gc_mem_write64(gc_env.ram, gc_env.r[1] + 0x10, temp); // stfd f0, 0x10(r1)
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x14);
    gc_mem_write16(gc_env.ram, gc_env.r[31] + 0x2ba, gc_env.r[0]);
    L_8002B1A0:
    gc_env.r[3] = ((uint32_t)&cm_803BCCA0 >> 16) & 0xFFFF; // lis r3, cm_803BCCA0@ha
    gc_env.r[3] = gc_env.r[3] + ((uint32_t)&cm_803BCCA0 & 0xFFFF); // addi r3, r3, cm_803BCCA0@l
    gc_env.r[4] = gc_env.r[31] + 700; // addi r4, r31, 0x2bc
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[3] + 0xD4); // lfs f1, 0xD4(r3)
    gc_env.f[1] = *(float*)&temp;
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[31] + 0x2BC); // lfs f0, 0x2BC(r31)
    gc_env.f[0] = *(float*)&temp;
    gc_env.f[0] = -((float)gc_env.f[2] * (float)gc_env.f[1] - (float)gc_env.f[0]); // fnmsubs f0, f2, f1, f0
    float temp = (float)gc_env.f[0]; // stfs f0, 0x2BC(r31)
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x2BC, *(uint32_t*)&temp);
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[31] + 0x2BC); // lfs f1, 0x2BC(r31)
    gc_env.f[1] = *(float*)&temp;
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[3] + 0xDC); // lfs f0, 0xDC(r3)
    gc_env.f[0] = *(float*)&temp;
    gc_env.cr[0] = isnan(gc_env.f[1]) || isnan(gc_env.f[0]) ? 0x1 : (gc_env.f[1] < gc_env.f[0] ? 0x8 : (gc_env.f[1] > gc_env.f[0] ? 0x4 : 0x2)); // fcmpo cr0, f1, f0
    if (gc_env.cr[0] >= 0) goto L_8002B1D4;
    float temp = (float)gc_env.f[0]; // stfs f0, 0x0(r4)
    gc_mem_write32(gc_env.ram, gc_env.r[4] + 0x0, *(uint32_t*)&temp);
    goto L_8002B1E4;
    L_8002B1D4:
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[3] + 0xD8); // lfs f0, 0xD8(r3)
    gc_env.f[0] = *(float*)&temp;
    gc_env.cr[0] = isnan(gc_env.f[1]) || isnan(gc_env.f[0]) ? 0x1 : (gc_env.f[1] < gc_env.f[0] ? 0x8 : (gc_env.f[1] > gc_env.f[0] ? 0x4 : 0x2)); // fcmpo cr0, f1, f0
    if (gc_env.cr[0] & (0x8 | 0x2)) goto L_8002B1E4; // ble .L_8002B1E4
    float temp = (float)gc_env.f[0]; // stfs f0, 0x0(r4)
    gc_mem_write32(gc_env.ram, gc_env.r[4] + 0x0, *(uint32_t*)&temp);
    L_8002B1E4:
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x24);
    gc_env.r[31] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x1c);
    gc_env.r[1] += 32; // addi r1, r1, 0x20
    gc_env.lr = gc_env.r[0]; // Move to link register
    return;
}

// Function: Camera_8002B1F8
void Camera_8002B1F8(void) {
    gc_env.r[0] = gc_env.lr; // Move from link register
    gc_env.r[4] = ((uint32_t)&cm_80452C68 >> 16) & 0xFFFF; // lis r4, cm_80452C68@ha
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x4, gc_env.r[0]);
    gc_env.r[4] = gc_env.r[4] + ((uint32_t)&cm_80452C68 & 0xFFFF); // addi r4, r4, cm_80452C68@l
    gc_mem_write32(gc_env.ram, gc_env.r[1] + -0x30, gc_env.r[1]);
    gc_env.r[1] = gc_env.r[1] + -0x30;
    uint64_t temp;
    memcpy(&temp, &gc_env.f[31], sizeof(double));
    gc_mem_write64(gc_env.ram, gc_env.r[1] + 0x28, temp); // stfd f31, 0x28(r1)
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x24, gc_env.r[31]);
    gc_env.r[31] = gc_env.r[4] + 700; // addi r31, r4, 0x2bc
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x20, gc_env.r[30]);
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x1c, gc_env.r[29]);
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x18, gc_env.r[28]);
    gc_env.r[28] = gc_env.r[3]; // Move register
    gc_env.f[1] = cm_804D7E04; // lfs f1, cm_804D7E04@sda21(r0)
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[4] + 0x2BC); // lfs f0, 0x2BC(r4)
    gc_env.f[0] = *(float*)&temp;
    gc_env.cr[0] = isnan(gc_env.f[1]) || isnan(gc_env.f[0]) ? 0x1 : (gc_env.f[1] < gc_env.f[0] ? 0x8 : (gc_env.f[1] > gc_env.f[0] ? 0x4 : 0x2)); // fcmpu cr0, f1, f0
    if (gc_env.cr[0] == 0) goto L_8002B3B0;
    gc_env.r[3] = 0x0;
    Player_GetEntity();
    gc_env.r[30] = gc_env.r[3]; // Move register
    if (gc_env.cr[0] == 0) goto L_8002B28C;
    gc_env.r[3] = gc_env.r[30]; // Move register
    ftLib_80086B74();
    gc_env.r[29] = gc_env.r[3]; // Move register
    if (gc_env.cr[0] == 0) goto L_8002B28C;
    gc_env.r[3] = gc_env.r[29]; // Move register
    Camera_8002928C();
    gc_env.cr[0] = (gc_env.r[3] == 0x0) ? 0 : (gc_env.r[3] < 0x0 ? -1 : 1); // Compare with immediate
    if (gc_env.cr[0] == 0) goto L_8002B28C;
    gc_env.r[3] = gc_env.r[29] + 28; // addi r3, r29, 0x1c
    gc_env.r[4] = 0x0;
    Camera_80029124();
    gc_env.cr[0] = ((uint32_t)gc_env.r[3] == 0x0) ? 0 : ((uint32_t)gc_env.r[3] < 0x0 ? -1 : 1); // Logical compare with immediate
    if (gc_env.cr[0] != 0) goto L_8002B28C;
    gc_env.r[3] = gc_env.r[30]; // Move register
    ftLib_8008732C();
    gc_env.cr[0] = (gc_env.r[3] == 0x0) ? 0 : (gc_env.r[3] < 0x0 ? -1 : 1); // Compare with immediate
    if (gc_env.cr[0] == 0) goto L_8002B2DC;
    L_8002B28C:
    gc_env.r[3] = 0x1;
    Player_GetPlayerCharacter();
    gc_env.cr[0] = (gc_env.r[3] == 0x1f) ? 0 : (gc_env.r[3] < 0x1f ? -1 : 1); // Compare with immediate
    if (gc_env.cr[0] != 0) goto L_8002B3B0;
    gc_env.r[3] = 0x1;
    Player_GetEntity();
    gc_env.cr[0] = ((uint32_t)gc_env.r[3] == 0x0) ? 0 : ((uint32_t)gc_env.r[3] < 0x0 ? -1 : 1); // Logical compare with immediate
    if (gc_env.cr[0] == 0) goto L_8002B3B0;
    ftLib_80086B74();
    gc_env.r[29] = gc_env.r[3]; // Move register
    if (gc_env.cr[0] == 0) goto L_8002B3B0;
    gc_env.r[3] = gc_env.r[29]; // Move register
    Camera_8002928C();
    gc_env.cr[0] = (gc_env.r[3] == 0x0) ? 0 : (gc_env.r[3] < 0x0 ? -1 : 1); // Compare with immediate
    if (gc_env.cr[0] == 0) goto L_8002B3B0;
    gc_env.r[3] = gc_env.r[29] + 28; // addi r3, r29, 0x1c
    gc_env.r[4] = 0x0;
    Camera_80029124();
    gc_env.cr[0] = ((uint32_t)gc_env.r[3] == 0x0) ? 0 : ((uint32_t)gc_env.r[3] < 0x0 ? -1 : 1); // Logical compare with immediate
    if (gc_env.cr[0] != 0) goto L_8002B3B0;
    L_8002B2DC:
    gc_env.r[3] = gc_env.r[28] + 12; // addi r3, r28, 0xc
    gc_env.r[4] = gc_env.r[29] + 28; // addi r4, r29, 0x1c
    gc_env.r[5] = gc_env.r[1] + 12; // addi r5, r1, 0xc
    lbVector_Diff();
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[31] + 0x0); // lfs f1, 0x0(r31)
    gc_env.f[1] = *(float*)&temp;
    gc_env.r[3] = gc_env.r[1] + 12; // addi r3, r1, 0xc
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0xC); // lfs f0, 0xC(r1)
    gc_env.f[0] = *(float*)&temp;
    gc_env.r[4] = gc_env.r[29] + 28; // addi r4, r29, 0x1c
    gc_env.f[1] = (float)gc_env.f[1] * (float)gc_env.f[1]; // fmuls f1, f1, f1
    gc_env.f[0] = (float)gc_env.f[0] * (float)gc_env.f[1]; // fmuls f0, f0, f1
    float temp = (float)gc_env.f[0]; // stfs f0, 0xC(r1)
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0xC, *(uint32_t*)&temp);
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x10); // lfs f0, 0x10(r1)
    gc_env.f[0] = *(float*)&temp;
    gc_env.f[0] = (float)gc_env.f[0] * (float)gc_env.f[1]; // fmuls f0, f0, f1
    float temp = (float)gc_env.f[0]; // stfs f0, 0x10(r1)
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x10, *(uint32_t*)&temp);
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x14); // lfs f0, 0x14(r1)
    gc_env.f[0] = *(float*)&temp;
    gc_env.f[0] = (float)gc_env.f[0] * (float)gc_env.f[1]; // fmuls f0, f0, f1
    float temp = (float)gc_env.f[0]; // stfs f0, 0x14(r1)
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x14, *(uint32_t*)&temp);
    lbVector_Add();
    gc_env.r[6] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0xc);
    gc_env.r[3] = gc_env.r[28] + 36; // addi r3, r28, 0x24
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x10);
    gc_env.r[4] = gc_env.r[28] + 12; // addi r4, r28, 0xc
    gc_env.r[5] = gc_env.r[1] + 12; // addi r5, r1, 0xc
    gc_mem_write32(gc_env.ram, gc_env.r[28] + 0xc, gc_env.r[6]);
    gc_mem_write32(gc_env.ram, gc_env.r[28] + 0x10, gc_env.r[0]);
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x14);
    gc_mem_write32(gc_env.ram, gc_env.r[28] + 0x14, gc_env.r[0]);
    lbVector_Diff();
    gc_env.r[3] = ((uint32_t)&cm_80452C68 >> 16) & 0xFFFF; // lis r3, cm_80452C68@ha
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[31] + 0x0); // lfs f0, 0x0(r31)
    gc_env.f[0] = *(float*)&temp;
    gc_env.r[3] = gc_env.r[3] + ((uint32_t)&cm_80452C68 & 0xFFFF); // addi r3, r3, cm_80452C68@l
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[3] + 0x2C0); // lfs f1, 0x2C0(r3)
    gc_env.f[1] = *(float*)&temp;
    gc_env.r[3] = gc_env.r[1] + 12; // addi r3, r1, 0xc
    gc_env.f[31] = (float)gc_env.f[1] * (float)gc_env.f[0]; // fmuls f31, f1, f0
    lbVector_Normalize();
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0xC); // lfs f0, 0xC(r1)
    gc_env.f[0] = *(float*)&temp;
    gc_env.r[3] = gc_env.r[1] + 12; // addi r3, r1, 0xc
    gc_env.r[4] = gc_env.r[28] + 12; // addi r4, r28, 0xc
    gc_env.f[0] = (float)gc_env.f[0] * (float)gc_env.f[31]; // fmuls f0, f0, f31
    float temp = (float)gc_env.f[0]; // stfs f0, 0xC(r1)
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0xC, *(uint32_t*)&temp);
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x10); // lfs f0, 0x10(r1)
    gc_env.f[0] = *(float*)&temp;
    gc_env.f[0] = (float)gc_env.f[0] * (float)gc_env.f[31]; // fmuls f0, f0, f31
    float temp = (float)gc_env.f[0]; // stfs f0, 0x10(r1)
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x10, *(uint32_t*)&temp);
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x14); // lfs f0, 0x14(r1)
    gc_env.f[0] = *(float*)&temp;
    gc_env.f[0] = (float)gc_env.f[0] * (float)gc_env.f[31]; // fmuls f0, f0, f31
    float temp = (float)gc_env.f[0]; // stfs f0, 0x14(r1)
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x14, *(uint32_t*)&temp);
    lbVector_Add();
    gc_env.r[3] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0xc);
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x10);
    gc_mem_write32(gc_env.ram, gc_env.r[28] + 0x24, gc_env.r[3]);
    gc_mem_write32(gc_env.ram, gc_env.r[28] + 0x28, gc_env.r[0]);
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x14);
    gc_mem_write32(gc_env.ram, gc_env.r[28] + 0x2c, gc_env.r[0]);
    L_8002B3B0:
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x34);
    uint64_t temp = gc_mem_read64(gc_env.ram, gc_env.r[1] + 0x28); // lfd f31, 0x28(r1)
    gc_env.d[31] = *(double*)&temp;
    gc_env.r[31] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x24);
    gc_env.r[30] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x20);
    gc_env.r[29] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x1c);
    gc_env.r[28] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x18);
    gc_env.r[1] += 48; // addi r1, r1, 0x30
    gc_env.lr = gc_env.r[0]; // Move to link register
    return;
}

// Function: Camera_8002B3D4
void Camera_8002B3D4(void) {
    gc_env.r[0] = gc_env.lr; // Move from link register
    gc_env.r[3] = ((uint32_t)&cm_80452C68 >> 16) & 0xFFFF; // lis r3, cm_80452C68@ha
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x4, gc_env.r[0]);
    gc_mem_write32(gc_env.ram, gc_env.r[1] + -0x88, gc_env.r[1]);
    gc_env.r[1] = gc_env.r[1] + -0x88;
    uint64_t temp;
    memcpy(&temp, &gc_env.f[31], sizeof(double));
    gc_mem_write64(gc_env.ram, gc_env.r[1] + 0x80, temp); // stfd f31, 0x80(r1)
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x6C, gc_env.r[27]); // stmw r27, 0x6C(r1)
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x70, gc_env.r[28]); // stmw r27, 0x6C(r1)
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x74, gc_env.r[29]); // stmw r27, 0x6C(r1)
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x78, gc_env.r[30]); // stmw r27, 0x6C(r1)
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x7C, gc_env.r[31]); // stmw r27, 0x6C(r1)
    gc_env.r[31] = gc_env.r[3] + ((uint32_t)&cm_80452C68 & 0xFFFF); // addi r31, r3, cm_80452C68@l
    Camera_80030DF8();
    Camera_800293E0();
    Camera_8002B0E0();
    gc_env.r[30] = gc_env.r[31] + 20; // addi r30, r31, 0x14
    gc_env.r[4] = gc_env.r[30] + 0; // addi r4, r30, 0x0
    gc_env.r[3] = gc_env.r[1] + 68; // addi r3, r1, 0x44
    Camera_8002958C();
    gc_env.r[3] = ((uint32_t)&cm_803BCCA0 >> 16) & 0xFFFF; // lis r3, cm_803BCCA0@ha
    gc_env.r[3] = gc_env.r[3] + ((uint32_t)&cm_803BCCA0 & 0xFFFF); // addi r3, r3, cm_803BCCA0@l
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[3] + 0x40); // lfs f0, 0x40(r3)
    gc_env.f[0] = *(float*)&temp;
    gc_env.r[28] = gc_env.r[3] + 68; // addi r28, r3, 0x44
    gc_env.r[29] = gc_env.r[3] + 64; // addi r29, r3, 0x40
    float temp = (float)gc_env.f[0]; // stfs f0, 0x48(r31)
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x48, *(uint32_t*)&temp);
    gc_env.r[4] = gc_env.r[30] + 0; // addi r4, r30, 0x0
    gc_env.r[3] = gc_env.r[1] + 68; // addi r3, r1, 0x44
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[31] + 0x48); // lfs f1, 0x48(r31)
    gc_env.f[1] = *(float*)&temp;
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[31] + 0x44); // lfs f2, 0x44(r31)
    gc_env.f[2] = *(float*)&temp;
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[28] + 0x0); // lfs f0, 0x0(r28)
    gc_env.f[0] = *(float*)&temp;
    gc_env.f[1] = (float)gc_env.f[1] - (float)gc_env.f[2]; // fsubs f1, f1, f2
    gc_env.f[0] = (float)gc_env.f[1] * (float)gc_env.f[0] + (float)gc_env.f[2]; // fmadds f0, f1, f0, f2
    float temp = (float)gc_env.f[0]; // stfs f0, 0x44(r31)
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x44, *(uint32_t*)&temp);
    Camera_80029BC4();
    Camera_80030AF8();
    gc_env.cr[0] = (gc_env.r[3] == 0x0) ? 0 : (gc_env.r[3] < 0x0 ? -1 : 1); // Compare with immediate
    if (gc_env.cr[0] == 0) goto L_8002B490;
    Ground_801C57A4();
    gc_env.cr[0] = ((uint32_t)gc_env.r[3] == 0x0) ? 0 : ((uint32_t)gc_env.r[3] < 0x0 ? -1 : 1); // Logical compare with immediate
    if (gc_env.cr[0] == 0) goto L_8002B490;
    gc_env.r[4] = gc_env.r[1] + 28; // addi r4, r1, 0x1c
    ftLib_80086644();
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x24); // lfs f1, 0x24(r1)
    gc_env.f[1] = *(float*)&temp;
    gc_env.f[0] = cm_804D7E14; // lfs f0, cm_804D7E14@sda21(r0)
    gc_env.cr[0] = isnan(gc_env.f[1]) || isnan(gc_env.f[0]) ? 0x1 : (gc_env.f[1] < gc_env.f[0] ? 0x8 : (gc_env.f[1] > gc_env.f[0] ? 0x4 : 0x2)); // fcmpo cr0, f1, f0
    if (gc_env.cr[0] >= 0) goto L_8002B47C;
    gc_env.f[1] = -gc_env.f[1]; // fneg f1, f1
    L_8002B47C:
    gc_env.f[0] = cm_804D7E70; // lfs f0, cm_804D7E70@sda21(r0)
    gc_env.cr[0] = isnan(gc_env.f[1]) || isnan(gc_env.f[0]) ? 0x1 : (gc_env.f[1] < gc_env.f[0] ? 0x8 : (gc_env.f[1] > gc_env.f[0] ? 0x4 : 0x2)); // fcmpo cr0, f1, f0
    if (gc_env.cr[0] & (0x8 | 0x2)) goto L_8002B490; // ble .L_8002B490
    gc_env.r[0] = 0x1;
    goto L_8002B494;
    L_8002B490:
    gc_env.r[0] = 0x0;
    L_8002B494:
    gc_env.cr[0] = (gc_env.r[0] == 0x0) ? 0 : (gc_env.r[0] < 0x0 ? -1 : 1); // Compare with immediate
    if (gc_env.cr[0] != 0) goto L_8002B4B4;
    gc_env.r[3] = gc_env.r[1] + 68; // addi r3, r1, 0x44
    gc_env.r[4] = gc_env.r[30] + 0; // addi r4, r30, 0x0
    Camera_80029CF8();
    gc_env.r[3] = gc_env.r[30] + 0; // addi r3, r30, 0x0
    gc_env.r[4] = 0x0;
    Camera_8002A768();
    L_8002B4B4:
    gc_env.r[27] = gc_env.r[31] + 76; // addi r27, r31, 0x4c
    gc_env.r[4] = gc_env.r[27] + 0; // addi r4, r27, 0x0
    gc_env.r[3] = gc_env.r[1] + 44; // addi r3, r1, 0x2c
    Camera_8002958C();
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[29] + 0x0); // lfs f0, 0x0(r29)
    gc_env.f[0] = *(float*)&temp;
    gc_env.r[4] = gc_env.r[27] + 0; // addi r4, r27, 0x0
    gc_env.r[3] = gc_env.r[1] + 44; // addi r3, r1, 0x2c
    float temp = (float)gc_env.f[0]; // stfs f0, 0x80(r31)
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x80, *(uint32_t*)&temp);
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[31] + 0x80); // lfs f1, 0x80(r31)
    gc_env.f[1] = *(float*)&temp;
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[31] + 0x7C); // lfs f2, 0x7C(r31)
    gc_env.f[2] = *(float*)&temp;
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[28] + 0x0); // lfs f0, 0x0(r28)
    gc_env.f[0] = *(float*)&temp;
    gc_env.f[1] = (float)gc_env.f[1] - (float)gc_env.f[2]; // fsubs f1, f1, f2
    gc_env.f[0] = (float)gc_env.f[1] * (float)gc_env.f[0] + (float)gc_env.f[2]; // fmadds f0, f1, f0, f2
    float temp = (float)gc_env.f[0]; // stfs f0, 0x7C(r31)
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x7C, *(uint32_t*)&temp);
    Camera_80029BC4();
    Camera_80030AF8();
    gc_env.cr[0] = (gc_env.r[3] == 0x0) ? 0 : (gc_env.r[3] < 0x0 ? -1 : 1); // Compare with immediate
    if (gc_env.cr[0] == 0) goto L_8002B538;
    Ground_801C57A4();
    gc_env.cr[0] = ((uint32_t)gc_env.r[3] == 0x0) ? 0 : ((uint32_t)gc_env.r[3] < 0x0 ? -1 : 1); // Logical compare with immediate
    if (gc_env.cr[0] == 0) goto L_8002B538;
    gc_env.r[4] = gc_env.r[1] + 12; // addi r4, r1, 0xc
    ftLib_80086644();
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x14); // lfs f1, 0x14(r1)
    gc_env.f[1] = *(float*)&temp;
    gc_env.f[0] = cm_804D7E14; // lfs f0, cm_804D7E14@sda21(r0)
    gc_env.cr[0] = isnan(gc_env.f[1]) || isnan(gc_env.f[0]) ? 0x1 : (gc_env.f[1] < gc_env.f[0] ? 0x8 : (gc_env.f[1] > gc_env.f[0] ? 0x4 : 0x2)); // fcmpo cr0, f1, f0
    if (gc_env.cr[0] >= 0) goto L_8002B524;
    gc_env.f[1] = -gc_env.f[1]; // fneg f1, f1
    L_8002B524:
    gc_env.f[0] = cm_804D7E70; // lfs f0, cm_804D7E70@sda21(r0)
    gc_env.cr[0] = isnan(gc_env.f[1]) || isnan(gc_env.f[0]) ? 0x1 : (gc_env.f[1] < gc_env.f[0] ? 0x8 : (gc_env.f[1] > gc_env.f[0] ? 0x4 : 0x2)); // fcmpo cr0, f1, f0
    if (gc_env.cr[0] & (0x8 | 0x2)) goto L_8002B538; // ble .L_8002B538
    gc_env.r[0] = 0x1;
    goto L_8002B53C;
    L_8002B538:
    gc_env.r[0] = 0x0;
    L_8002B53C:
    gc_env.cr[0] = (gc_env.r[0] == 0x0) ? 0 : (gc_env.r[0] < 0x0 ? -1 : 1); // Compare with immediate
    if (gc_env.cr[0] != 0) goto L_8002B55C;
    gc_env.r[3] = gc_env.r[1] + 44; // addi r3, r1, 0x2c
    gc_env.r[4] = gc_env.r[27] + 0; // addi r4, r27, 0x0
    Camera_80029CF8();
    gc_env.r[3] = gc_env.r[27] + 0; // addi r3, r27, 0x0
    gc_env.r[4] = 0x0;
    Camera_8002A768();
    L_8002B55C:
    gc_env.f[1] = cm_804D7E04; // lfs f1, cm_804D7E04@sda21(r0)
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[31] + 0x2BC); // lfs f0, 0x2BC(r31)
    gc_env.f[0] = *(float*)&temp;
    gc_env.cr[0] = isnan(gc_env.f[1]) || isnan(gc_env.f[0]) ? 0x1 : (gc_env.f[1] < gc_env.f[0] ? 0x8 : (gc_env.f[1] > gc_env.f[0] ? 0x4 : 0x2)); // fcmpu cr0, f1, f0
    if (gc_env.cr[0] != 0) goto L_8002B5AC;
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[31] + 0x38); // lfs f3, 0x38(r31)
    gc_env.f[3] = *(float*)&temp;
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[31] + 0x20); // lfs f2, 0x20(r31)
    gc_env.f[2] = *(float*)&temp;
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[31] + 0x3C); // lfs f1, 0x3C(r31)
    gc_env.f[1] = *(float*)&temp;
    gc_env.f[4] = (float)gc_env.f[3] - (float)gc_env.f[2]; // fsubs f4, f3, f2
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[31] + 0x24); // lfs f0, 0x24(r31)
    gc_env.f[0] = *(float*)&temp;
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[31] + 0x40); // lfs f2, 0x40(r31)
    gc_env.f[2] = *(float*)&temp;
    gc_env.f[3] = (float)gc_env.f[1] - (float)gc_env.f[0]; // fsubs f3, f1, f0
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[31] + 0x28); // lfs f0, 0x28(r31)
    gc_env.f[0] = *(float*)&temp;
    gc_env.f[2] = (float)gc_env.f[2] - (float)gc_env.f[0]; // fsubs f2, f2, f0
    gc_env.f[1] = (float)gc_env.f[4] * (float)gc_env.f[4]; // fmuls f1, f4, f4
    gc_env.f[0] = (float)gc_env.f[3] * (float)gc_env.f[3]; // fmuls f0, f3, f3
    gc_env.f[2] = (float)gc_env.f[2] * (float)gc_env.f[2]; // fmuls f2, f2, f2
    gc_env.f[0] = (float)gc_env.f[1] + (float)gc_env.f[0]; // fadds f0, f1, f0
    gc_env.f[1] = (float)gc_env.f[2] + (float)gc_env.f[0]; // fadds f1, f2, f0
    sqrtf__Ff();
    float temp = (float)gc_env.f[1]; // stfs f1, 0x2C0(r31)
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x2C0, *(uint32_t*)&temp);
    L_8002B5AC:
    gc_env.r[3] = gc_env.r[30]; // Move register
    Camera_8002B1F8();
    Stage_GetCamTrackSmooth();
    gc_env.r[4] = gc_env.r[30] + 0; // addi r4, r30, 0x0
    gc_env.r[3] = gc_env.r[1] + 68; // addi r3, r1, 0x44
    Camera_80029AAC();
    Stage_GetCamTrackSmooth();
    gc_env.r[4] = gc_env.r[30] + 0; // addi r4, r30, 0x0
    gc_env.r[3] = gc_env.r[1] + 68; // addi r3, r1, 0x44
    Camera_80029C88();
    Stage_GetCamTrackSmooth();
    gc_env.r[4] = gc_env.r[27] + 0; // addi r4, r27, 0x0
    gc_env.r[3] = gc_env.r[1] + 44; // addi r3, r1, 0x2c
    Camera_80029AAC();
    Stage_GetCamTrackSmooth();
    gc_env.r[4] = gc_env.r[27] + 0; // addi r4, r27, 0x0
    gc_env.r[3] = gc_env.r[1] + 44; // addi r3, r1, 0x2c
    Camera_80029C88();
    gc_env.r[3] = gc_env.r[1] + 68; // addi r3, r1, 0x44
    Camera_8002A28C();
    gc_env.r[3] = gc_env.r[1] + 68; // addi r3, r1, 0x44
    gc_env.r[4] = gc_env.r[30] + 0; // addi r4, r30, 0x0
    Camera_8002A0C0();
    gc_env.r[27] = gc_env.r[31] + 696; // addi r27, r31, 0x2b8
    gc_env.r[0] = (int32_t)(int16_t)gc_mem_read16(gc_env.ram, gc_env.r[31] + 0x2B8); // lha r0, 0x2B8(r31)
    gc_env.cr[0] = (gc_env.r[0] == 0x3e8) ? 0 : (gc_env.r[0] < 0x3e8 ? -1 : 1); // Compare with immediate
    if (gc_env.cr[0] & (0x8 | 0x2)) goto L_8002B628; // ble .L_8002B628
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[31] + 0x2B0); // lfs f0, 0x2B0(r31)
    gc_env.f[0] = *(float*)&temp;
    gc_env.r[0] = 0x1;
    float temp = (float)gc_env.f[0]; // stfs f0, 0x2B4(r31)
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x2B4, *(uint32_t*)&temp);
    gc_mem_write16(gc_env.ram, gc_env.r[27] + 0x0, gc_env.r[0]);
    L_8002B628:
    Stage_GetCamBoundsLeftOffset();
    gc_env.f[31] = gc_env.f[1]; // fmr f31, f1
    Stage_GetCamBoundsRightOffset();
    gc_env.f[1] = (float)gc_env.f[1] - (float)gc_env.f[31]; // fsubs f1, f1, f31
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[31] + 0x2B4); // lfs f0, 0x2B4(r31)
    gc_env.f[0] = *(float*)&temp;
    gc_env.r[0] = 17200 << 16; // lis r0, 0x4330
    gc_env.f[0] = (float)gc_env.f[0] + (float)gc_env.f[1]; // fadds f0, f0, f1
    float temp = (float)gc_env.f[0]; // stfs f0, 0x2B4(r31)
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x2B4, *(uint32_t*)&temp);
    gc_env.r[3] = (int32_t)(int16_t)gc_mem_read16(gc_env.ram, gc_env.r[27] + 0x0); // lha r3, 0x0(r27)
    gc_env.r[3] += 1; // addi r3, r3, 0x1
    gc_mem_write16(gc_env.ram, gc_env.r[27] + 0x0, gc_env.r[3]);
    gc_env.r[3] = (int32_t)(int16_t)gc_mem_read16(gc_env.ram, gc_env.r[27] + 0x0); // lha r3, 0x0(r27)
    gc_env.d[1] = cm_804D7E20; // lfd f1, cm_804D7E20@sda21(r0)
    gc_env.r[3] = gc_env.r[3] ^ 0x80000000; // xoris r3, r3, 0x8000
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[31] + 0x2B4); // lfs f2, 0x2B4(r31)
    gc_env.f[2] = *(float*)&temp;
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x64, gc_env.r[3]);
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x60, gc_env.r[0]);
    uint64_t temp = gc_mem_read64(gc_env.ram, gc_env.r[1] + 0x60); // lfd f0, 0x60(r1)
    gc_env.d[0] = *(double*)&temp;
    gc_env.f[0] = (float)gc_env.f[0] - (float)gc_env.f[1]; // fsubs f0, f0, f1
    gc_env.f[0] = (float)gc_env.f[2] / (float)gc_env.f[0]; // fdivs f0, f2, f0
    float temp = (float)gc_env.f[0]; // stfs f0, 0x2B0(r31)
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x2B0, *(uint32_t*)&temp);
    gc_env.r[27] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x6C); // lmw r27, 0x6C(r1)
    gc_env.r[28] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x70); // lmw r27, 0x6C(r1)
    gc_env.r[29] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x74); // lmw r27, 0x6C(r1)
    gc_env.r[30] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x78); // lmw r27, 0x6C(r1)
    gc_env.r[31] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x7C); // lmw r27, 0x6C(r1)
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x8c);
    uint64_t temp = gc_mem_read64(gc_env.ram, gc_env.r[1] + 0x80); // lfd f31, 0x80(r1)
    gc_env.d[31] = *(double*)&temp;
    gc_env.r[1] += 136; // addi r1, r1, 0x88
    gc_env.lr = gc_env.r[0]; // Move to link register
    return;
}

// Function: Camera_8002B694
void Camera_8002B694(void) {
    gc_env.r[0] = gc_env.lr; // Move from link register
    gc_env.cr[0] = (gc_env.r[4] == 0x5) ? 0 : (gc_env.r[4] < 0x5 ? -1 : 1); // Compare with immediate
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x4, gc_env.r[0]);
    gc_mem_write32(gc_env.ram, gc_env.r[1] + -0x28, gc_env.r[1]);
    gc_env.r[1] = gc_env.r[1] + -0x28;
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x24, gc_env.r[31]);
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x20, gc_env.r[30]);
    gc_env.r[30] = gc_env.r[3] + 0; // addi r30, r3, 0x0
    if (gc_env.cr[0] != 0) goto L_8002B6E0;
    gc_env.f[0] = cm_804D7E14; // lfs f0, cm_804D7E14@sda21(r0)
    gc_env.r[0] = 0x0;
    float temp = (float)gc_env.f[0]; // stfs f0, 0x0(r30)
    gc_mem_write32(gc_env.ram, gc_env.r[30] + 0x0, *(uint32_t*)&temp);
    float temp = (float)gc_env.f[0]; // stfs f0, 0x4(r30)
    gc_mem_write32(gc_env.ram, gc_env.r[30] + 0x4, *(uint32_t*)&temp);
    float temp = (float)gc_env.f[0]; // stfs f0, 0x8(r30)
    gc_mem_write32(gc_env.ram, gc_env.r[30] + 0x8, *(uint32_t*)&temp);
    float temp = (float)gc_env.f[0]; // stfs f0, 0xC(r30)
    gc_mem_write32(gc_env.ram, gc_env.r[30] + 0xC, *(uint32_t*)&temp);
    gc_mem_write32(gc_env.ram, gc_env.r[30] + 0x1c, gc_env.r[0]);
    gc_mem_write32(gc_env.ram, gc_env.r[30] + 0x18, gc_env.r[0]);
    gc_mem_write32(gc_env.ram, gc_env.r[30] + 0x14, gc_env.r[0]);
    gc_mem_write32(gc_env.ram, gc_env.r[30] + 0x10, gc_env.r[0]);
    goto L_8002B9E8;
    L_8002B6E0:
    gc_env.cr[0] = (gc_env.r[4] == 0x4) ? 0 : (gc_env.r[4] < 0x4 ? -1 : 1); // Compare with immediate
    if (gc_env.cr[0] != 0) goto L_8002B994;
    gc_env.r[3] = 0x0;
    gc_env.f[1] = cm_804D7E14; // lfs f1, cm_804D7E14@sda21(r0)
    gc_env.r[4] = gc_env.r[3] * 68;
    gc_env.f[0] = cm_804D7E74; // lfs f0, cm_804D7E74@sda21(r0)
    gc_env.r[3] = ((uint32_t)&HSD_PadCopyStatus >> 16) & 0xFFFF; // lis r3, HSD_PadCopyStatus@ha
    gc_env.r[0] = gc_env.r[3] + ((uint32_t)&HSD_PadCopyStatus & 0xFFFF); // addi r0, r3, HSD_PadCopyStatus@l
    gc_env.r[3] = gc_env.r[0] + gc_env.r[4];
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[3] + 0x20); // lfs f2, 0x20(r3)
    gc_env.f[2] = *(float*)&temp;
    gc_env.r[4] = 0x0;
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[3] + 0x24); // lfs f3, 0x24(r3)
    gc_env.f[3] = *(float*)&temp;
    gc_env.cr[0] = isnan(gc_env.f[2]) || isnan(gc_env.f[1]) ? 0x1 : (gc_env.f[2] < gc_env.f[1] ? 0x8 : (gc_env.f[2] > gc_env.f[1] ? 0x4 : 0x2)); // fcmpo cr0, f2, f1
    gc_env.f[4] = gc_env.f[2]; // fmr f4, f2
    gc_env.f[5] = gc_env.f[3]; // fmr f5, f3
    if (gc_env.cr[0] >= 0) goto L_8002B724;
    gc_env.f[2] = -gc_env.f[2]; // fneg f2, f2
    L_8002B724:
    gc_env.cr[0] = isnan(gc_env.f[2]) || isnan(gc_env.f[0]) ? 0x1 : (gc_env.f[2] < gc_env.f[0] ? 0x8 : (gc_env.f[2] > gc_env.f[0] ? 0x4 : 0x2)); // fcmpo cr0, f2, f0
    if (gc_env.cr[0] & 0x4) goto L_8002B81C; // bgt .L_8002B81C
    gc_env.cr[0] = isnan(gc_env.f[3]) || isnan(gc_env.f[1]) ? 0x1 : (gc_env.f[3] < gc_env.f[1] ? 0x8 : (gc_env.f[3] > gc_env.f[1] ? 0x4 : 0x2)); // fcmpo cr0, f3, f1
    if (gc_env.cr[0] >= 0) goto L_8002B738;
    gc_env.f[3] = -gc_env.f[3]; // fneg f3, f3
    L_8002B738:
    gc_env.cr[0] = isnan(gc_env.f[3]) || isnan(gc_env.f[0]) ? 0x1 : (gc_env.f[3] < gc_env.f[0] ? 0x8 : (gc_env.f[3] > gc_env.f[0] ? 0x4 : 0x2)); // fcmpo cr0, f3, f0
    if (gc_env.cr[0] & 0x4) goto L_8002B81C; // bgt .L_8002B81C
    gc_env.r[3] = 0x1;
    gc_env.r[4] = gc_env.r[3] * 68;
    gc_env.r[3] = gc_env.r[0] + gc_env.r[4];
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[3] + 0x20); // lfs f2, 0x20(r3)
    gc_env.f[2] = *(float*)&temp;
    gc_env.r[4] = 0x1;
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[3] + 0x24); // lfs f3, 0x24(r3)
    gc_env.f[3] = *(float*)&temp;
    gc_env.cr[0] = isnan(gc_env.f[2]) || isnan(gc_env.f[1]) ? 0x1 : (gc_env.f[2] < gc_env.f[1] ? 0x8 : (gc_env.f[2] > gc_env.f[1] ? 0x4 : 0x2)); // fcmpo cr0, f2, f1
    gc_env.f[4] = gc_env.f[2]; // fmr f4, f2
    gc_env.f[5] = gc_env.f[3]; // fmr f5, f3
    if (gc_env.cr[0] >= 0) goto L_8002B76C;
    gc_env.f[2] = -gc_env.f[2]; // fneg f2, f2
    L_8002B76C:
    gc_env.cr[0] = isnan(gc_env.f[2]) || isnan(gc_env.f[0]) ? 0x1 : (gc_env.f[2] < gc_env.f[0] ? 0x8 : (gc_env.f[2] > gc_env.f[0] ? 0x4 : 0x2)); // fcmpo cr0, f2, f0
    if (gc_env.cr[0] & 0x4) goto L_8002B81C; // bgt .L_8002B81C
    gc_env.cr[0] = isnan(gc_env.f[3]) || isnan(gc_env.f[1]) ? 0x1 : (gc_env.f[3] < gc_env.f[1] ? 0x8 : (gc_env.f[3] > gc_env.f[1] ? 0x4 : 0x2)); // fcmpo cr0, f3, f1
    if (gc_env.cr[0] >= 0) goto L_8002B780;
    gc_env.f[3] = -gc_env.f[3]; // fneg f3, f3
    L_8002B780:
    gc_env.cr[0] = isnan(gc_env.f[3]) || isnan(gc_env.f[0]) ? 0x1 : (gc_env.f[3] < gc_env.f[0] ? 0x8 : (gc_env.f[3] > gc_env.f[0] ? 0x4 : 0x2)); // fcmpo cr0, f3, f0
    if (gc_env.cr[0] & 0x4) goto L_8002B81C; // bgt .L_8002B81C
    gc_env.r[3] = 0x2;
    gc_env.r[4] = gc_env.r[3] * 68;
    gc_env.r[3] = gc_env.r[0] + gc_env.r[4];
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[3] + 0x20); // lfs f2, 0x20(r3)
    gc_env.f[2] = *(float*)&temp;
    gc_env.r[4] = 0x2;
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[3] + 0x24); // lfs f3, 0x24(r3)
    gc_env.f[3] = *(float*)&temp;
    gc_env.cr[0] = isnan(gc_env.f[2]) || isnan(gc_env.f[1]) ? 0x1 : (gc_env.f[2] < gc_env.f[1] ? 0x8 : (gc_env.f[2] > gc_env.f[1] ? 0x4 : 0x2)); // fcmpo cr0, f2, f1
    gc_env.f[4] = gc_env.f[2]; // fmr f4, f2
    gc_env.f[5] = gc_env.f[3]; // fmr f5, f3
    if (gc_env.cr[0] >= 0) goto L_8002B7B4;
    gc_env.f[2] = -gc_env.f[2]; // fneg f2, f2
    L_8002B7B4:
    gc_env.cr[0] = isnan(gc_env.f[2]) || isnan(gc_env.f[0]) ? 0x1 : (gc_env.f[2] < gc_env.f[0] ? 0x8 : (gc_env.f[2] > gc_env.f[0] ? 0x4 : 0x2)); // fcmpo cr0, f2, f0
    if (gc_env.cr[0] & 0x4) goto L_8002B81C; // bgt .L_8002B81C
    gc_env.cr[0] = isnan(gc_env.f[3]) || isnan(gc_env.f[1]) ? 0x1 : (gc_env.f[3] < gc_env.f[1] ? 0x8 : (gc_env.f[3] > gc_env.f[1] ? 0x4 : 0x2)); // fcmpo cr0, f3, f1
    if (gc_env.cr[0] >= 0) goto L_8002B7C8;
    gc_env.f[3] = -gc_env.f[3]; // fneg f3, f3
    L_8002B7C8:
    gc_env.cr[0] = isnan(gc_env.f[3]) || isnan(gc_env.f[0]) ? 0x1 : (gc_env.f[3] < gc_env.f[0] ? 0x8 : (gc_env.f[3] > gc_env.f[0] ? 0x4 : 0x2)); // fcmpo cr0, f3, f0
    if (gc_env.cr[0] & 0x4) goto L_8002B81C; // bgt .L_8002B81C
    gc_env.r[3] = 0x3;
    gc_env.r[4] = gc_env.r[3] * 68;
    gc_env.r[3] = gc_env.r[0] + gc_env.r[4];
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[3] + 0x20); // lfs f2, 0x20(r3)
    gc_env.f[2] = *(float*)&temp;
    gc_env.r[4] = 0x3;
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[3] + 0x24); // lfs f3, 0x24(r3)
    gc_env.f[3] = *(float*)&temp;
    gc_env.cr[0] = isnan(gc_env.f[2]) || isnan(gc_env.f[1]) ? 0x1 : (gc_env.f[2] < gc_env.f[1] ? 0x8 : (gc_env.f[2] > gc_env.f[1] ? 0x4 : 0x2)); // fcmpo cr0, f2, f1
    gc_env.f[4] = gc_env.f[2]; // fmr f4, f2
    gc_env.f[5] = gc_env.f[3]; // fmr f5, f3
    if (gc_env.cr[0] >= 0) goto L_8002B7FC;
    gc_env.f[2] = -gc_env.f[2]; // fneg f2, f2
    L_8002B7FC:
    gc_env.cr[0] = isnan(gc_env.f[2]) || isnan(gc_env.f[0]) ? 0x1 : (gc_env.f[2] < gc_env.f[0] ? 0x8 : (gc_env.f[2] > gc_env.f[0] ? 0x4 : 0x2)); // fcmpo cr0, f2, f0
    if (gc_env.cr[0] & 0x4) goto L_8002B81C; // bgt .L_8002B81C
    gc_env.cr[0] = isnan(gc_env.f[3]) || isnan(gc_env.f[1]) ? 0x1 : (gc_env.f[3] < gc_env.f[1] ? 0x8 : (gc_env.f[3] > gc_env.f[1] ? 0x4 : 0x2)); // fcmpo cr0, f3, f1
    if (gc_env.cr[0] >= 0) goto L_8002B810;
    gc_env.f[3] = -gc_env.f[3]; // fneg f3, f3
    L_8002B810:
    gc_env.cr[0] = isnan(gc_env.f[3]) || isnan(gc_env.f[0]) ? 0x1 : (gc_env.f[3] < gc_env.f[0] ? 0x8 : (gc_env.f[3] > gc_env.f[0] ? 0x4 : 0x2)); // fcmpo cr0, f3, f0
    if (gc_env.cr[0] & 0x4) goto L_8002B81C; // bgt .L_8002B81C
    gc_env.r[4] = 0x4;
    L_8002B81C:
    gc_env.cr[0] = (gc_env.r[4] == 0x4) ? 0 : (gc_env.r[4] < 0x4 ? -1 : 1); // Compare with immediate
    if (gc_env.cr[0] != 0) goto L_8002B82C;
    gc_env.f[5] = cm_804D7E14; // lfs f5, cm_804D7E14@sda21(r0)
    gc_env.f[4] = gc_env.f[5]; // fmr f4, f5
    L_8002B82C:
    gc_env.r[5] = 0x0;
    gc_env.f[1] = cm_804D7E14; // lfs f1, cm_804D7E14@sda21(r0)
    gc_env.r[4] = gc_env.r[5] * 68;
    gc_env.f[0] = cm_804D7E74; // lfs f0, cm_804D7E74@sda21(r0)
    gc_env.r[3] = ((uint32_t)&HSD_PadCopyStatus >> 16) & 0xFFFF; // lis r3, HSD_PadCopyStatus@ha
    gc_env.r[0] = gc_env.r[3] + ((uint32_t)&HSD_PadCopyStatus & 0xFFFF); // addi r0, r3, HSD_PadCopyStatus@l
    gc_env.r[3] = gc_env.r[0] + gc_env.r[4];
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[3] + 0x28); // lfs f2, 0x28(r3)
    gc_env.f[2] = *(float*)&temp;
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[3] + 0x2C); // lfs f3, 0x2C(r3)
    gc_env.f[3] = *(float*)&temp;
    gc_env.cr[0] = isnan(gc_env.f[2]) || isnan(gc_env.f[1]) ? 0x1 : (gc_env.f[2] < gc_env.f[1] ? 0x8 : (gc_env.f[2] > gc_env.f[1] ? 0x4 : 0x2)); // fcmpo cr0, f2, f1
    gc_env.f[6] = gc_env.f[2]; // fmr f6, f2
    gc_env.f[7] = gc_env.f[3]; // fmr f7, f3
    if (gc_env.cr[0] >= 0) goto L_8002B864;
    gc_env.f[2] = -gc_env.f[2]; // fneg f2, f2
    L_8002B864:
    gc_env.cr[0] = isnan(gc_env.f[2]) || isnan(gc_env.f[0]) ? 0x1 : (gc_env.f[2] < gc_env.f[0] ? 0x8 : (gc_env.f[2] > gc_env.f[0] ? 0x4 : 0x2)); // fcmpo cr0, f2, f0
    if (gc_env.cr[0] & 0x4) goto L_8002B950; // bgt .L_8002B950
    gc_env.cr[0] = isnan(gc_env.f[3]) || isnan(gc_env.f[1]) ? 0x1 : (gc_env.f[3] < gc_env.f[1] ? 0x8 : (gc_env.f[3] > gc_env.f[1] ? 0x4 : 0x2)); // fcmpo cr0, f3, f1
    if (gc_env.cr[0] >= 0) goto L_8002B878;
    gc_env.f[3] = -gc_env.f[3]; // fneg f3, f3
    L_8002B878:
    gc_env.cr[0] = isnan(gc_env.f[3]) || isnan(gc_env.f[0]) ? 0x1 : (gc_env.f[3] < gc_env.f[0] ? 0x8 : (gc_env.f[3] > gc_env.f[0] ? 0x4 : 0x2)); // fcmpo cr0, f3, f0
    if (gc_env.cr[0] & 0x4) goto L_8002B950; // bgt .L_8002B950
    gc_env.r[5] = 0x1;
    gc_env.r[4] = gc_env.r[5] * 68;
    gc_env.r[3] = gc_env.r[0] + gc_env.r[4];
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[3] + 0x28); // lfs f2, 0x28(r3)
    gc_env.f[2] = *(float*)&temp;
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[3] + 0x2C); // lfs f3, 0x2C(r3)
    gc_env.f[3] = *(float*)&temp;
    gc_env.cr[0] = isnan(gc_env.f[2]) || isnan(gc_env.f[1]) ? 0x1 : (gc_env.f[2] < gc_env.f[1] ? 0x8 : (gc_env.f[2] > gc_env.f[1] ? 0x4 : 0x2)); // fcmpo cr0, f2, f1
    gc_env.f[6] = gc_env.f[2]; // fmr f6, f2
    gc_env.f[7] = gc_env.f[3]; // fmr f7, f3
    if (gc_env.cr[0] >= 0) goto L_8002B8A8;
    gc_env.f[2] = -gc_env.f[2]; // fneg f2, f2
    L_8002B8A8:
    gc_env.cr[0] = isnan(gc_env.f[2]) || isnan(gc_env.f[0]) ? 0x1 : (gc_env.f[2] < gc_env.f[0] ? 0x8 : (gc_env.f[2] > gc_env.f[0] ? 0x4 : 0x2)); // fcmpo cr0, f2, f0
    if (gc_env.cr[0] & 0x4) goto L_8002B950; // bgt .L_8002B950
    gc_env.cr[0] = isnan(gc_env.f[3]) || isnan(gc_env.f[1]) ? 0x1 : (gc_env.f[3] < gc_env.f[1] ? 0x8 : (gc_env.f[3] > gc_env.f[1] ? 0x4 : 0x2)); // fcmpo cr0, f3, f1
    if (gc_env.cr[0] >= 0) goto L_8002B8BC;
    gc_env.f[3] = -gc_env.f[3]; // fneg f3, f3
    L_8002B8BC:
    gc_env.cr[0] = isnan(gc_env.f[3]) || isnan(gc_env.f[0]) ? 0x1 : (gc_env.f[3] < gc_env.f[0] ? 0x8 : (gc_env.f[3] > gc_env.f[0] ? 0x4 : 0x2)); // fcmpo cr0, f3, f0
    if (gc_env.cr[0] & 0x4) goto L_8002B950; // bgt .L_8002B950
    gc_env.r[5] = 0x2;
    gc_env.r[4] = gc_env.r[5] * 68;
    gc_env.r[3] = gc_env.r[0] + gc_env.r[4];
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[3] + 0x28); // lfs f2, 0x28(r3)
    gc_env.f[2] = *(float*)&temp;
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[3] + 0x2C); // lfs f3, 0x2C(r3)
    gc_env.f[3] = *(float*)&temp;
    gc_env.cr[0] = isnan(gc_env.f[2]) || isnan(gc_env.f[1]) ? 0x1 : (gc_env.f[2] < gc_env.f[1] ? 0x8 : (gc_env.f[2] > gc_env.f[1] ? 0x4 : 0x2)); // fcmpo cr0, f2, f1
    gc_env.f[6] = gc_env.f[2]; // fmr f6, f2
    gc_env.f[7] = gc_env.f[3]; // fmr f7, f3
    if (gc_env.cr[0] >= 0) goto L_8002B8EC;
    gc_env.f[2] = -gc_env.f[2]; // fneg f2, f2
    L_8002B8EC:
    gc_env.cr[0] = isnan(gc_env.f[2]) || isnan(gc_env.f[0]) ? 0x1 : (gc_env.f[2] < gc_env.f[0] ? 0x8 : (gc_env.f[2] > gc_env.f[0] ? 0x4 : 0x2)); // fcmpo cr0, f2, f0
    if (gc_env.cr[0] & 0x4) goto L_8002B950; // bgt .L_8002B950
    gc_env.cr[0] = isnan(gc_env.f[3]) || isnan(gc_env.f[1]) ? 0x1 : (gc_env.f[3] < gc_env.f[1] ? 0x8 : (gc_env.f[3] > gc_env.f[1] ? 0x4 : 0x2)); // fcmpo cr0, f3, f1
    if (gc_env.cr[0] >= 0) goto L_8002B900;
    gc_env.f[3] = -gc_env.f[3]; // fneg f3, f3
    L_8002B900:
    gc_env.cr[0] = isnan(gc_env.f[3]) || isnan(gc_env.f[0]) ? 0x1 : (gc_env.f[3] < gc_env.f[0] ? 0x8 : (gc_env.f[3] > gc_env.f[0] ? 0x4 : 0x2)); // fcmpo cr0, f3, f0
    if (gc_env.cr[0] & 0x4) goto L_8002B950; // bgt .L_8002B950
    gc_env.r[5] = 0x3;
    gc_env.r[4] = gc_env.r[5] * 68;
    gc_env.r[3] = gc_env.r[0] + gc_env.r[4];
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[3] + 0x28); // lfs f2, 0x28(r3)
    gc_env.f[2] = *(float*)&temp;
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[3] + 0x2C); // lfs f3, 0x2C(r3)
    gc_env.f[3] = *(float*)&temp;
    gc_env.cr[0] = isnan(gc_env.f[2]) || isnan(gc_env.f[1]) ? 0x1 : (gc_env.f[2] < gc_env.f[1] ? 0x8 : (gc_env.f[2] > gc_env.f[1] ? 0x4 : 0x2)); // fcmpo cr0, f2, f1
    gc_env.f[6] = gc_env.f[2]; // fmr f6, f2
    gc_env.f[7] = gc_env.f[3]; // fmr f7, f3
    if (gc_env.cr[0] >= 0) goto L_8002B930;
    gc_env.f[2] = -gc_env.f[2]; // fneg f2, f2
    L_8002B930:
    gc_env.cr[0] = isnan(gc_env.f[2]) || isnan(gc_env.f[0]) ? 0x1 : (gc_env.f[2] < gc_env.f[0] ? 0x8 : (gc_env.f[2] > gc_env.f[0] ? 0x4 : 0x2)); // fcmpo cr0, f2, f0
    if (gc_env.cr[0] & 0x4) goto L_8002B950; // bgt .L_8002B950
    gc_env.cr[0] = isnan(gc_env.f[3]) || isnan(gc_env.f[1]) ? 0x1 : (gc_env.f[3] < gc_env.f[1] ? 0x8 : (gc_env.f[3] > gc_env.f[1] ? 0x4 : 0x2)); // fcmpo cr0, f3, f1
    if (gc_env.cr[0] >= 0) goto L_8002B944;
    gc_env.f[3] = -gc_env.f[3]; // fneg f3, f3
    L_8002B944:
    gc_env.cr[0] = isnan(gc_env.f[3]) || isnan(gc_env.f[0]) ? 0x1 : (gc_env.f[3] < gc_env.f[0] ? 0x8 : (gc_env.f[3] > gc_env.f[0] ? 0x4 : 0x2)); // fcmpo cr0, f3, f0
    if (gc_env.cr[0] & 0x4) goto L_8002B950; // bgt .L_8002B950
    gc_env.r[5] = 0x4;
    L_8002B950:
    gc_env.cr[0] = (gc_env.r[5] == 0x4) ? 0 : (gc_env.r[5] < 0x4 ? -1 : 1); // Compare with immediate
    if (gc_env.cr[0] != 0) goto L_8002B960;
    gc_env.f[7] = cm_804D7E14; // lfs f7, cm_804D7E14@sda21(r0)
    gc_env.f[6] = gc_env.f[7]; // fmr f6, f7
    L_8002B960:
    float temp = (float)gc_env.f[4]; // stfs f4, 0x0(r30)
    gc_mem_write32(gc_env.ram, gc_env.r[30] + 0x0, *(uint32_t*)&temp);
    gc_env.r[3] = 0x4;
    float temp = (float)gc_env.f[5]; // stfs f5, 0x4(r30)
    gc_mem_write32(gc_env.ram, gc_env.r[30] + 0x4, *(uint32_t*)&temp);
    float temp = (float)gc_env.f[6]; // stfs f6, 0x8(r30)
    gc_mem_write32(gc_env.ram, gc_env.r[30] + 0x8, *(uint32_t*)&temp);
    float temp = (float)gc_env.f[7]; // stfs f7, 0xC(r30)
    gc_mem_write32(gc_env.ram, gc_env.r[30] + 0xC, *(uint32_t*)&temp);
    gm_801A3680();
    gc_mem_write32(gc_env.ram, gc_env.r[30] + 0x14, gc_env.r[4]);
    gc_mem_write32(gc_env.ram, gc_env.r[30] + 0x10, gc_env.r[3]);
    gc_env.r[3] = 0x4;
    gm_801A36A0();
    gc_mem_write32(gc_env.ram, gc_env.r[30] + 0x1c, gc_env.r[4]);
    gc_mem_write32(gc_env.ram, gc_env.r[30] + 0x18, gc_env.r[3]);
    goto L_8002B9E8;
    L_8002B994:
    gc_env.r[31] = gc_env.r[4] & 0xFF; // clrlwi r31, r4, 24
    gc_env.r[4] = gc_env.r[31] * 68;
    gc_env.r[3] = ((uint32_t)&HSD_PadCopyStatus >> 16) & 0xFFFF; // lis r3, HSD_PadCopyStatus@ha
    gc_env.r[0] = gc_env.r[3] + ((uint32_t)&HSD_PadCopyStatus & 0xFFFF); // addi r0, r3, HSD_PadCopyStatus@l
    gc_env.r[4] = gc_env.r[0] + gc_env.r[4];
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[4] + 0x20); // lfs f0, 0x20(r4)
    gc_env.f[0] = *(float*)&temp;
    gc_env.r[3] = gc_env.r[31]; // Move register
    float temp = (float)gc_env.f[0]; // stfs f0, 0x0(r30)
    gc_mem_write32(gc_env.ram, gc_env.r[30] + 0x0, *(uint32_t*)&temp);
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[4] + 0x24); // lfs f0, 0x24(r4)
    gc_env.f[0] = *(float*)&temp;
    float temp = (float)gc_env.f[0]; // stfs f0, 0x4(r30)
    gc_mem_write32(gc_env.ram, gc_env.r[30] + 0x4, *(uint32_t*)&temp);
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[4] + 0x28); // lfs f0, 0x28(r4)
    gc_env.f[0] = *(float*)&temp;
    float temp = (float)gc_env.f[0]; // stfs f0, 0x8(r30)
    gc_mem_write32(gc_env.ram, gc_env.r[30] + 0x8, *(uint32_t*)&temp);
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[4] + 0x2C); // lfs f0, 0x2C(r4)
    gc_env.f[0] = *(float*)&temp;
    float temp = (float)gc_env.f[0]; // stfs f0, 0xC(r30)
    gc_mem_write32(gc_env.ram, gc_env.r[30] + 0xC, *(uint32_t*)&temp);
    gm_801A3680();
    gc_mem_write32(gc_env.ram, gc_env.r[30] + 0x14, gc_env.r[4]);
    gc_mem_write32(gc_env.ram, gc_env.r[30] + 0x10, gc_env.r[3]);
    gc_env.r[3] = gc_env.r[31]; // Move register
    gm_801A36A0();
    gc_mem_write32(gc_env.ram, gc_env.r[30] + 0x1c, gc_env.r[4]);
    gc_mem_write32(gc_env.ram, gc_env.r[30] + 0x18, gc_env.r[3]);
    L_8002B9E8:
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x2c);
    gc_env.r[31] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x24);
    gc_env.r[30] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x20);
    gc_env.r[1] += 40; // addi r1, r1, 0x28
    gc_env.lr = gc_env.r[0]; // Move to link register
    return;
}

// Function: Camera_8002BA00
void Camera_8002BA00(void) {
    gc_env.r[0] = gc_env.lr; // Move from link register
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x4, gc_env.r[0]);
    gc_mem_write32(gc_env.ram, gc_env.r[1] + -0x18, gc_env.r[1]);
    gc_env.r[1] = gc_env.r[1] + -0x18;
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x14, gc_env.r[31]);
    gc_env.r[31] = gc_env.r[4] + 0; // addi r31, r4, 0x0
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x10, gc_env.r[30]);
    gc_env.r[30] = gc_env.r[3] + 0; // addi r30, r3, 0x0
    gc_env.cr[0] = (gc_env.r[30] == 0xa) ? 0 : (gc_env.r[30] < 0xa ? -1 : 1); // Compare with immediate
    if (gc_env.cr[0] != 0) goto L_8002BA40;
    gc_env.cr[0] = (gc_env.r[31] == 0x0) ? 0 : (gc_env.r[31] < 0x0 ? -1 : 1); // Compare with immediate
    if (gc_env.cr[0] & (0x8 | 0x2)) goto L_8002BA34; // ble .L_8002BA34
    gc_env.r[30] = 0x0;
    goto L_8002BA5C;
    L_8002BA34:
    if (gc_env.cr[0] >= 0) goto L_8002BA5C;
    gc_env.r[30] = 0x5;
    goto L_8002BA5C;
    L_8002BA40:
    gc_env.r[30] = gc_env.r[30] + gc_env.r[31];
    if (gc_env.cr[0] >= 0) goto L_8002BA50;
    gc_env.r[30] = 0xa;
    goto L_8002BA5C;
    L_8002BA50:
    gc_env.cr[0] = (gc_env.r[30] == 0x5) ? 0 : (gc_env.r[30] < 0x5 ? -1 : 1); // Compare with immediate
    if (gc_env.cr[0] & (0x8 | 0x2)) goto L_8002BA5C; // ble .L_8002BA5C
    gc_env.r[30] = 0xa;
    L_8002BA5C:
    gc_env.cr[0] = (gc_env.r[30] == 0xa) ? 0 : (gc_env.r[30] < 0xa ? -1 : 1); // Compare with immediate
    if (gc_env.cr[0] != 0) goto L_8002BA6C;
    gc_env.r[3] = 0xa;
    goto L_8002BA90;
    L_8002BA6C:
    gc_env.r[3] = gc_env.r[30]; // Move register
    Player_GetEntity();
    gc_env.cr[0] = ((uint32_t)gc_env.r[3] == 0x0) ? 0 : ((uint32_t)gc_env.r[3] < 0x0 ? -1 : 1); // Logical compare with immediate
    if (gc_env.cr[0] == 0) goto L_8002BA84;
    gc_env.r[3] = gc_env.r[30]; // Move register
    goto L_8002BA90;
    L_8002BA84:
    gc_env.r[3] = gc_env.r[30] + 0; // addi r3, r30, 0x0
    gc_env.r[4] = gc_env.r[31] + 0; // addi r4, r31, 0x0
    Camera_8002BA00();
    L_8002BA90:
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x1c);
    gc_env.r[31] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x14);
    gc_env.r[30] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x10);
    gc_env.r[1] += 24; // addi r1, r1, 0x18
    gc_env.lr = gc_env.r[0]; // Move to link register
    return;
}

// Function: Camera_8002BAA8
void Camera_8002BAA8(void) {
    gc_env.r[0] = gc_env.lr; // Move from link register
    gc_env.r[3] = ((uint32_t)&cm_80452C68 >> 16) & 0xFFFF; // lis r3, cm_80452C68@ha
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x4, gc_env.r[0]);
    gc_env.r[4] = gc_env.r[3] + ((uint32_t)&cm_80452C68 & 0xFFFF); // addi r4, r3, cm_80452C68@l
    gc_mem_write32(gc_env.ram, gc_env.r[1] + -0x38, gc_env.r[1]);
    gc_env.r[1] = gc_env.r[1] + -0x38;
    uint64_t temp;
    memcpy(&temp, &gc_env.f[31], sizeof(double));
    gc_mem_write64(gc_env.ram, gc_env.r[1] + 0x30, temp); // stfd f31, 0x30(r1)
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x2c, gc_env.r[31]);
    gc_env.r[31] = gc_env.r[4] + 800; // addi r31, r4, 0x320
    gc_env.r[3] = gc_mem_read32(gc_env.ram, gc_env.r[4] + 0x320);
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[4] + 0x324);
    gc_env.f[2] = cm_804D7E10; // lfs f2, cm_804D7E10@sda21(r0)
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x18, gc_env.r[3]);
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x1c, gc_env.r[0]);
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[4] + 0x328);
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x20, gc_env.r[0]);
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x18); // lfs f0, 0x18(r1)
    gc_env.f[0] = *(float*)&temp;
    gc_env.f[0] = (float)gc_env.f[0] * (float)gc_env.f[2]; // fmuls f0, f0, f2
    float temp = (float)gc_env.f[0]; // stfs f0, 0x18(r1)
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x18, *(uint32_t*)&temp);
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x1C); // lfs f0, 0x1C(r1)
    gc_env.f[0] = *(float*)&temp;
    gc_env.f[0] = (float)gc_env.f[0] * (float)gc_env.f[2]; // fmuls f0, f0, f2
    float temp = (float)gc_env.f[0]; // stfs f0, 0x1C(r1)
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x1C, *(uint32_t*)&temp);
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x20); // lfs f0, 0x20(r1)
    gc_env.f[0] = *(float*)&temp;
    gc_env.f[0] = (float)gc_env.f[0] * (float)gc_env.f[2]; // fmuls f0, f0, f2
    float temp = (float)gc_env.f[0]; // stfs f0, 0x20(r1)
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x20, *(uint32_t*)&temp);
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x18); // lfs f2, 0x18(r1)
    gc_env.f[2] = *(float*)&temp;
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x1C); // lfs f0, 0x1C(r1)
    gc_env.f[0] = *(float*)&temp;
    gc_env.f[3] = (float)gc_env.f[2] * (float)gc_env.f[2]; // fmuls f3, f2, f2
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x20); // lfs f4, 0x20(r1)
    gc_env.f[4] = *(float*)&temp;
    gc_env.f[2] = (float)gc_env.f[0] * (float)gc_env.f[0]; // fmuls f2, f0, f0
    gc_env.f[0] = cm_804D7E14; // lfs f0, cm_804D7E14@sda21(r0)
    gc_env.f[4] = (float)gc_env.f[4] * (float)gc_env.f[4]; // fmuls f4, f4, f4
    gc_env.f[2] = (float)gc_env.f[3] + (float)gc_env.f[2]; // fadds f2, f3, f2
    gc_env.f[5] = (float)gc_env.f[4] + (float)gc_env.f[2]; // fadds f5, f4, f2
    gc_env.cr[0] = isnan(gc_env.f[5]) || isnan(gc_env.f[0]) ? 0x1 : (gc_env.f[5] < gc_env.f[0] ? 0x8 : (gc_env.f[5] > gc_env.f[0] ? 0x4 : 0x2)); // fcmpo cr0, f5, f0
    if (gc_env.cr[0] & (0x8 | 0x2)) goto L_8002BB80; // ble .L_8002BB80
    // Unknown opcode: frsqrte f2 f5
    gc_env.d[4] = cm_804D7E78; // lfd f4, cm_804D7E78@sda21(r0)
    gc_env.d[3] = cm_804D7E80; // lfd f3, cm_804D7E80@sda21(r0)
    // Unknown opcode: fmul f0 f2 f2
    // Unknown opcode: fmul f2 f4 f2
    // Unknown opcode: fnmsub f0 f5 f0 f3
    // Unknown opcode: fmul f2 f2 f0
    // Unknown opcode: fmul f0 f2 f2
    // Unknown opcode: fmul f2 f4 f2
    // Unknown opcode: fnmsub f0 f5 f0 f3
    // Unknown opcode: fmul f2 f2 f0
    // Unknown opcode: fmul f0 f2 f2
    // Unknown opcode: fmul f2 f4 f2
    // Unknown opcode: fnmsub f0 f5 f0 f3
    // Unknown opcode: fmul f0 f2 f0
    // Unknown opcode: fmul f0 f5 f0
    gc_env.f[0] = (float)gc_env.f[0]; // frsp f0, f0
    float temp = (float)gc_env.f[0]; // stfs f0, 0x10(r1)
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x10, *(uint32_t*)&temp);
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x10); // lfs f5, 0x10(r1)
    gc_env.f[5] = *(float*)&temp;
    L_8002BB80:
    gc_env.f[2] = cm_804D7E04; // lfs f2, cm_804D7E04@sda21(r0)
    gc_env.cr[0] = isnan(gc_env.f[5]) || isnan(gc_env.f[2]) ? 0x1 : (gc_env.f[5] < gc_env.f[2] ? 0x8 : (gc_env.f[5] > gc_env.f[2] ? 0x4 : 0x2)); // fcmpo cr0, f5, f2
    if (gc_env.cr[0] >= 0) goto L_8002BBA4;
    gc_env.f[0] = cm_804D7E14; // lfs f0, cm_804D7E14@sda21(r0)
    float temp = (float)gc_env.f[0]; // stfs f0, 0x1C(r1)
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x1C, *(uint32_t*)&temp);
    float temp = (float)gc_env.f[0]; // stfs f0, 0x18(r1)
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x18, *(uint32_t*)&temp);
    float temp = (float)gc_env.f[2]; // stfs f2, 0x20(r1)
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x20, *(uint32_t*)&temp);
    gc_env.f[0] = cm_804D7E4C; // lfs f0, cm_804D7E4C@sda21(r0)
    float temp = (float)gc_env.f[0]; // stfs f0, 0x330(r4)
    gc_mem_write32(gc_env.ram, gc_env.r[4] + 0x330, *(uint32_t*)&temp);
    L_8002BBA4:
    gc_env.r[3] = ((uint32_t)&cm_803BCCA0 >> 16) & 0xFFFF; // lis r3, cm_803BCCA0@ha
    gc_env.r[3] = gc_env.r[3] + ((uint32_t)&cm_803BCCA0 & 0xFFFF); // addi r3, r3, cm_803BCCA0@l
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[3] + 0x9C); // lfs f3, 0x9C(r3)
    gc_env.f[3] = *(float*)&temp;
    gc_env.r[5] = gc_env.r[4] + 816; // addi r5, r4, 0x330
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[3] + 0xA0); // lfs f2, 0xA0(r3)
    gc_env.f[2] = *(float*)&temp;
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[4] + 0x330); // lfs f0, 0x330(r4)
    gc_env.f[0] = *(float*)&temp;
    gc_env.f[2] = (float)gc_env.f[5] * (float)gc_env.f[3] + (float)gc_env.f[2]; // fmadds f2, f5, f3, f2
    gc_env.f[0] = (float)gc_env.f[1] * (float)gc_env.f[2] + (float)gc_env.f[0]; // fmadds f0, f1, f2, f0
    float temp = (float)gc_env.f[0]; // stfs f0, 0x330(r4)
    gc_mem_write32(gc_env.ram, gc_env.r[4] + 0x330, *(uint32_t*)&temp);
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[4] + 0x330); // lfs f1, 0x330(r4)
    gc_env.f[1] = *(float*)&temp;
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[4] + 0x2F8); // lfs f0, 0x2F8(r4)
    gc_env.f[0] = *(float*)&temp;
    gc_env.cr[0] = isnan(gc_env.f[1]) || isnan(gc_env.f[0]) ? 0x1 : (gc_env.f[1] < gc_env.f[0] ? 0x8 : (gc_env.f[1] > gc_env.f[0] ? 0x4 : 0x2)); // fcmpo cr0, f1, f0
    if (gc_env.cr[0] >= 0) goto L_8002BBE0;
    float temp = (float)gc_env.f[0]; // stfs f0, 0x0(r5)
    gc_mem_write32(gc_env.ram, gc_env.r[5] + 0x0, *(uint32_t*)&temp);
    goto L_8002BBF0;
    L_8002BBE0:
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[4] + 0x2FC); // lfs f0, 0x2FC(r4)
    gc_env.f[0] = *(float*)&temp;
    gc_env.cr[0] = isnan(gc_env.f[1]) || isnan(gc_env.f[0]) ? 0x1 : (gc_env.f[1] < gc_env.f[0] ? 0x8 : (gc_env.f[1] > gc_env.f[0] ? 0x4 : 0x2)); // fcmpo cr0, f1, f0
    if (gc_env.cr[0] & (0x8 | 0x2)) goto L_8002BBF0; // ble .L_8002BBF0
    float temp = (float)gc_env.f[0]; // stfs f0, 0x0(r5)
    gc_mem_write32(gc_env.ram, gc_env.r[5] + 0x0, *(uint32_t*)&temp);
    L_8002BBF0:
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[5] + 0x0); // lfs f31, 0x0(r5)
    gc_env.f[31] = *(float*)&temp;
    gc_env.r[3] = gc_env.r[1] + 24; // addi r3, r1, 0x18
    lbVector_Normalize();
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x18); // lfs f0, 0x18(r1)
    gc_env.f[0] = *(float*)&temp;
    gc_env.f[0] = (float)gc_env.f[0] * (float)gc_env.f[31]; // fmuls f0, f0, f31
    float temp = (float)gc_env.f[0]; // stfs f0, 0x18(r1)
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x18, *(uint32_t*)&temp);
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x1C); // lfs f0, 0x1C(r1)
    gc_env.f[0] = *(float*)&temp;
    gc_env.f[0] = (float)gc_env.f[0] * (float)gc_env.f[31]; // fmuls f0, f0, f31
    float temp = (float)gc_env.f[0]; // stfs f0, 0x1C(r1)
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x1C, *(uint32_t*)&temp);
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x20); // lfs f0, 0x20(r1)
    gc_env.f[0] = *(float*)&temp;
    gc_env.f[0] = (float)gc_env.f[0] * (float)gc_env.f[31]; // fmuls f0, f0, f31
    float temp = (float)gc_env.f[0]; // stfs f0, 0x20(r1)
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x20, *(uint32_t*)&temp);
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x18); // lfs f0, 0x18(r1)
    gc_env.f[0] = *(float*)&temp;
    gc_env.f[1] = cm_804D7E10; // lfs f1, cm_804D7E10@sda21(r0)
    gc_env.f[0] = (float)gc_env.f[0] * (float)gc_env.f[1]; // fmuls f0, f0, f1
    float temp = (float)gc_env.f[0]; // stfs f0, 0x18(r1)
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x18, *(uint32_t*)&temp);
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x1C); // lfs f0, 0x1C(r1)
    gc_env.f[0] = *(float*)&temp;
    gc_env.f[0] = (float)gc_env.f[0] * (float)gc_env.f[1]; // fmuls f0, f0, f1
    float temp = (float)gc_env.f[0]; // stfs f0, 0x1C(r1)
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x1C, *(uint32_t*)&temp);
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x20); // lfs f0, 0x20(r1)
    gc_env.f[0] = *(float*)&temp;
    gc_env.f[0] = (float)gc_env.f[0] * (float)gc_env.f[1]; // fmuls f0, f0, f1
    float temp = (float)gc_env.f[0]; // stfs f0, 0x20(r1)
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x20, *(uint32_t*)&temp);
    gc_env.r[3] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x18);
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x1c);
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x0, gc_env.r[3]);
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x4, gc_env.r[0]);
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x20);
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x8, gc_env.r[0]);
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x3c);
    uint64_t temp = gc_mem_read64(gc_env.ram, gc_env.r[1] + 0x30); // lfd f31, 0x30(r1)
    gc_env.d[31] = *(double*)&temp;
    gc_env.r[31] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x2c);
    gc_env.r[1] += 56; // addi r1, r1, 0x38
    gc_env.lr = gc_env.r[0]; // Move to link register
    return;
}

// Function: Camera_8002BC78
void Camera_8002BC78(void) {
    gc_env.r[0] = gc_env.lr; // Move from link register
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x4, gc_env.r[0]);
    gc_mem_write32(gc_env.ram, gc_env.r[1] + -0x28, gc_env.r[1]);
    gc_env.r[1] = gc_env.r[1] + -0x28;
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x24, gc_env.r[31]);
    gc_env.r[31] = 0x0;
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x20, gc_env.r[30]);
    gc_env.r[30] = gc_env.r[5] + 0; // addi r30, r5, 0x0
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x1c, gc_env.r[29]);
    gc_env.r[29] = gc_env.r[4] + 0; // addi r29, r4, 0x0
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x18, gc_env.r[28]);
    gc_env.r[28] = gc_env.r[3]; // Move register
    gc_env.f[0] = cm_804D7E88; // lfs f0, cm_804D7E88@sda21(r0)
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[3] + 0x4); // lfs f1, 0x4(r3)
    gc_env.f[1] = *(float*)&temp;
    gc_env.cr[0] = isnan(gc_env.f[1]) || isnan(gc_env.f[0]) ? 0x1 : (gc_env.f[1] < gc_env.f[0] ? 0x8 : (gc_env.f[1] > gc_env.f[0] ? 0x4 : 0x2)); // fcmpo cr0, f1, f0
    if (gc_env.cr[0] & (0x8 | 0x2)) goto L_8002BCF0; // ble .L_8002BCF0
    gc_env.f[0] = cm_804D7E04; // lfs f0, cm_804D7E04@sda21(r0)
    gc_env.r[3] = ((uint32_t)&cm_80452C68 >> 16) & 0xFFFF; // lis r3, cm_80452C68@ha
    gc_env.r[4] = gc_env.r[3] + ((uint32_t)&cm_80452C68 & 0xFFFF); // addi r4, r3, cm_80452C68@l
    float temp = (float)gc_env.f[0]; // stfs f0, 0x4(r28)
    gc_mem_write32(gc_env.ram, gc_env.r[28] + 0x4, *(uint32_t*)&temp);
    gc_env.r[31] = 0x1;
    gc_env.f[0] = cm_804D7E14; // lfs f0, cm_804D7E14@sda21(r0)
    float temp = (float)gc_env.f[0]; // stfs f0, 0x8(r28)
    gc_mem_write32(gc_env.ram, gc_env.r[28] + 0x8, *(uint32_t*)&temp);
    float temp = (float)gc_env.f[0]; // stfs f0, 0x0(r28)
    gc_mem_write32(gc_env.ram, gc_env.r[28] + 0x0, *(uint32_t*)&temp);
    gc_env.r[3] = gc_mem_read32(gc_env.ram, gc_env.r[4] + 0x334);
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[4] + 0x338);
    gc_mem_write32(gc_env.ram, gc_env.r[29] + 0x0, gc_env.r[3]);
    gc_mem_write32(gc_env.ram, gc_env.r[29] + 0x4, gc_env.r[0]);
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[4] + 0x33c);
    gc_mem_write32(gc_env.ram, gc_env.r[29] + 0x8, gc_env.r[0]);
    goto L_8002BD34;
    L_8002BCF0:
    gc_env.f[0] = cm_804D7E8C; // lfs f0, cm_804D7E8C@sda21(r0)
    gc_env.cr[0] = isnan(gc_env.f[1]) || isnan(gc_env.f[0]) ? 0x1 : (gc_env.f[1] < gc_env.f[0] ? 0x8 : (gc_env.f[1] > gc_env.f[0] ? 0x4 : 0x2)); // fcmpo cr0, f1, f0
    if (gc_env.cr[0] >= 0) goto L_8002BD34;
    gc_env.f[0] = cm_804D7E10; // lfs f0, cm_804D7E10@sda21(r0)
    gc_env.r[3] = ((uint32_t)&cm_80452C68 >> 16) & 0xFFFF; // lis r3, cm_80452C68@ha
    gc_env.r[4] = gc_env.r[3] + ((uint32_t)&cm_80452C68 & 0xFFFF); // addi r4, r3, cm_80452C68@l
    float temp = (float)gc_env.f[0]; // stfs f0, 0x4(r28)
    gc_mem_write32(gc_env.ram, gc_env.r[28] + 0x4, *(uint32_t*)&temp);
    gc_env.r[31] = -0x1;
    gc_env.f[0] = cm_804D7E14; // lfs f0, cm_804D7E14@sda21(r0)
    float temp = (float)gc_env.f[0]; // stfs f0, 0x8(r28)
    gc_mem_write32(gc_env.ram, gc_env.r[28] + 0x8, *(uint32_t*)&temp);
    float temp = (float)gc_env.f[0]; // stfs f0, 0x0(r28)
    gc_mem_write32(gc_env.ram, gc_env.r[28] + 0x0, *(uint32_t*)&temp);
    gc_env.r[3] = gc_mem_read32(gc_env.ram, gc_env.r[4] + 0x334);
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[4] + 0x338);
    gc_mem_write32(gc_env.ram, gc_env.r[29] + 0x0, gc_env.r[3]);
    gc_mem_write32(gc_env.ram, gc_env.r[29] + 0x4, gc_env.r[0]);
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[4] + 0x33c);
    gc_mem_write32(gc_env.ram, gc_env.r[29] + 0x8, gc_env.r[0]);
    L_8002BD34:
    gc_env.r[3] = gc_env.r[29] + 0; // addi r3, r29, 0x0
    gc_env.r[4] = gc_env.r[28] + 0; // addi r4, r28, 0x0
    gc_env.r[5] = gc_env.r[30] + 0; // addi r5, r30, 0x0
    PSVECCrossProduct();
    gc_env.r[3] = gc_env.r[30]; // Move register
    lbVector_Normalize();
    gc_env.r[3] = gc_env.r[28] + 0; // addi r3, r28, 0x0
    gc_env.r[4] = gc_env.r[30] + 0; // addi r4, r30, 0x0
    gc_env.r[5] = gc_env.r[29] + 0; // addi r5, r29, 0x0
    PSVECCrossProduct();
    gc_env.r[3] = gc_env.r[29]; // Move register
    lbVector_Normalize();
    gc_env.r[3] = gc_env.r[31]; // Move register
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x2c);
    gc_env.r[31] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x24);
    gc_env.r[30] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x20);
    gc_env.r[29] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x1c);
    gc_env.r[28] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x18);
    gc_env.r[1] += 40; // addi r1, r1, 0x28
    gc_env.lr = gc_env.r[0]; // Move to link register
    return;
}

// Function: Camera_8002BD88
void Camera_8002BD88(void) {
    gc_env.r[0] = gc_env.lr; // Move from link register
    gc_env.r[3] = ((uint32_t)&cm_803B73D0 >> 16) & 0xFFFF; // lis r3, cm_803B73D0@ha
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x4, gc_env.r[0]);
    gc_env.r[4] = gc_env.r[3] + ((uint32_t)&cm_803B73D0 & 0xFFFF); // addi r4, r3, cm_803B73D0@l
    gc_env.r[5] = ((uint32_t)&cm_80452C68 >> 16) & 0xFFFF; // lis r5, cm_80452C68@ha
    gc_mem_write32(gc_env.ram, gc_env.r[1] + -0x60, gc_env.r[1]);
    gc_env.r[1] = gc_env.r[1] + -0x60;
    uint64_t temp;
    memcpy(&temp, &gc_env.f[31], sizeof(double));
    gc_mem_write64(gc_env.ram, gc_env.r[1] + 0x58, temp); // stfd f31, 0x58(r1)
    uint64_t temp;
    memcpy(&temp, &gc_env.f[30], sizeof(double));
    gc_mem_write64(gc_env.ram, gc_env.r[1] + 0x50, temp); // stfd f30, 0x50(r1)
    gc_env.f[30] = gc_env.f[2]; // fmr f30, f2
    uint64_t temp;
    memcpy(&temp, &gc_env.f[29], sizeof(double));
    gc_mem_write64(gc_env.ram, gc_env.r[1] + 0x48, temp); // stfd f29, 0x48(r1)
    gc_env.f[29] = gc_env.f[1]; // fmr f29, f1
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x44, gc_env.r[31]);
    gc_env.r[31] = gc_env.r[5] + ((uint32_t)&cm_80452C68 & 0xFFFF); // addi r31, r5, cm_80452C68@l
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x40, gc_env.r[30]);
    gc_env.r[30] = gc_env.r[31] + 800; // addi r30, r31, 0x320
    gc_env.r[3] = gc_mem_read32(gc_env.ram, gc_env.r[4] + 0x0);
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[4] + 0x4);
    gc_env.f[3] = cm_804D7E10; // lfs f3, cm_804D7E10@sda21(r0)
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x34, gc_env.r[3]);
    gc_env.r[3] = gc_env.r[1] + 40; // addi r3, r1, 0x28
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x38, gc_env.r[0]);
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[4] + 0x8);
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x3c, gc_env.r[0]);
    gc_env.r[4] = gc_mem_read32(gc_env.ram, gc_env.r[31] + 0x320);
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[31] + 0x324);
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x10, gc_env.r[4]);
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x14, gc_env.r[0]);
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[31] + 0x328);
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x18, gc_env.r[0]);
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x10);
    gc_env.r[4] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x14);
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x28, gc_env.r[0]);
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x18);
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x2c, gc_env.r[4]);
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x30, gc_env.r[0]);
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x28); // lfs f0, 0x28(r1)
    gc_env.f[0] = *(float*)&temp;
    gc_env.f[0] = (float)gc_env.f[0] * (float)gc_env.f[3]; // fmuls f0, f0, f3
    float temp = (float)gc_env.f[0]; // stfs f0, 0x28(r1)
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x28, *(uint32_t*)&temp);
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x2C); // lfs f0, 0x2C(r1)
    gc_env.f[0] = *(float*)&temp;
    gc_env.f[0] = (float)gc_env.f[0] * (float)gc_env.f[3]; // fmuls f0, f0, f3
    float temp = (float)gc_env.f[0]; // stfs f0, 0x2C(r1)
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x2C, *(uint32_t*)&temp);
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x30); // lfs f0, 0x30(r1)
    gc_env.f[0] = *(float*)&temp;
    gc_env.f[0] = (float)gc_env.f[0] * (float)gc_env.f[3]; // fmuls f0, f0, f3
    float temp = (float)gc_env.f[0]; // stfs f0, 0x30(r1)
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x30, *(uint32_t*)&temp);
    lbVector_Normalize();
    gc_env.f[31] = gc_env.f[1]; // fmr f31, f1
    gc_env.f[1] = cm_804D7E04; // lfs f1, cm_804D7E04@sda21(r0)
    gc_env.cr[0] = isnan(gc_env.f[31]) || isnan(gc_env.f[1]) ? 0x1 : (gc_env.f[31] < gc_env.f[1] ? 0x8 : (gc_env.f[31] > gc_env.f[1] ? 0x4 : 0x2)); // fcmpo cr0, f31, f1
    if (gc_env.cr[0] >= 0) goto L_8002BE64;
    gc_env.f[0] = cm_804D7E14; // lfs f0, cm_804D7E14@sda21(r0)
    float temp = (float)gc_env.f[0]; // stfs f0, 0x2C(r1)
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x2C, *(uint32_t*)&temp);
    float temp = (float)gc_env.f[0]; // stfs f0, 0x28(r1)
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x28, *(uint32_t*)&temp);
    float temp = (float)gc_env.f[1]; // stfs f1, 0x30(r1)
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x30, *(uint32_t*)&temp);
    gc_env.f[0] = cm_804D7E4C; // lfs f0, cm_804D7E4C@sda21(r0)
    float temp = (float)gc_env.f[0]; // stfs f0, 0x330(r31)
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x330, *(uint32_t*)&temp);
    L_8002BE64:
    gc_env.r[3] = gc_env.r[1] + 40; // addi r3, r1, 0x28
    gc_env.r[4] = gc_env.r[1] + 52; // addi r4, r1, 0x34
    gc_env.r[5] = gc_env.r[1] + 28; // addi r5, r1, 0x1c
    Camera_8002BC78();
    gc_env.cr[0] = (gc_env.r[3] == 0x1) ? 0 : (gc_env.r[3] < 0x1 ? -1 : 1); // Compare with immediate
    if (gc_env.cr[0] != 0) goto L_8002BE94;
    gc_env.f[0] = cm_804D7E14; // lfs f0, cm_804D7E14@sda21(r0)
    gc_env.cr[0] = isnan(gc_env.f[30]) || isnan(gc_env.f[0]) ? 0x1 : (gc_env.f[30] < gc_env.f[0] ? 0x8 : (gc_env.f[30] > gc_env.f[0] ? 0x4 : 0x2)); // fcmpo cr0, f30, f0
    if (gc_env.cr[0] >= 0) goto L_8002BE8C;
    gc_env.f[30] = gc_env.f[0]; // fmr f30, f0
    L_8002BE8C:
    gc_env.f[29] = cm_804D7E14; // lfs f29, cm_804D7E14@sda21(r0)
    goto L_8002BEB0;
    L_8002BE94:
    gc_env.cr[0] = (gc_env.r[3] == -0x1) ? 0 : (gc_env.r[3] < -0x1 ? -1 : 1); // Compare with immediate
    if (gc_env.cr[0] != 0) goto L_8002BEB0;
    gc_env.f[0] = cm_804D7E14; // lfs f0, cm_804D7E14@sda21(r0)
    gc_env.cr[0] = isnan(gc_env.f[30]) || isnan(gc_env.f[0]) ? 0x1 : (gc_env.f[30] < gc_env.f[0] ? 0x8 : (gc_env.f[30] > gc_env.f[0] ? 0x4 : 0x2)); // fcmpo cr0, f30, f0
    if (gc_env.cr[0] & (0x8 | 0x2)) goto L_8002BEAC; // ble .L_8002BEAC
    gc_env.f[30] = gc_env.f[0]; // fmr f30, f0
    L_8002BEAC:
    gc_env.f[29] = cm_804D7E14; // lfs f29, cm_804D7E14@sda21(r0)
    L_8002BEB0:
    gc_env.r[3] = gc_env.r[1] + 52; // addi r3, r1, 0x34
    gc_env.r[4] = gc_env.r[1] + 40; // addi r4, r1, 0x28
    gc_env.r[5] = gc_env.r[1] + 28; // addi r5, r1, 0x1c
    PSVECCrossProduct();
    gc_env.r[3] = gc_env.r[1] + 28; // addi r3, r1, 0x1c
    lbVector_Normalize();
    gc_env.r[3] = gc_env.r[1] + 40; // addi r3, r1, 0x28
    gc_env.r[4] = gc_env.r[1] + 28; // addi r4, r1, 0x1c
    gc_env.r[5] = gc_env.r[1] + 52; // addi r5, r1, 0x34
    PSVECCrossProduct();
    gc_env.r[3] = gc_env.r[1] + 52; // addi r3, r1, 0x34
    lbVector_Normalize();
    gc_env.r[3] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x34);
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x38);
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x334, gc_env.r[3]);
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x338, gc_env.r[0]);
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x3c);
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x33c, gc_env.r[0]);
    gc_env.f[0] = cm_804D7E14; // lfs f0, cm_804D7E14@sda21(r0)
    gc_env.cr[0] = isnan(gc_env.f[0]) || isnan(gc_env.f[30]) ? 0x1 : (gc_env.f[0] < gc_env.f[30] ? 0x8 : (gc_env.f[0] > gc_env.f[30] ? 0x4 : 0x2)); // fcmpu cr0, f0, f30
    if (gc_env.cr[0] == 0) goto L_8002BF4C;
    gc_env.r[3] = ((uint32_t)&cm_803BCCA0 >> 16) & 0xFFFF; // lis r3, cm_803BCCA0@ha
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x34); // lfs f0, 0x34(r1)
    gc_env.f[0] = *(float*)&temp;
    gc_env.r[4] = gc_env.r[3] + ((uint32_t)&cm_803BCCA0 & 0xFFFF); // addi r4, r3, cm_803BCCA0@l
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[4] + 0xBC); // lfs f2, 0xBC(r4)
    gc_env.f[2] = *(float*)&temp;
    gc_env.r[3] = gc_env.r[1] + 16; // addi r3, r1, 0x10
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[4] + 0xC0); // lfs f1, 0xC0(r4)
    gc_env.f[1] = *(float*)&temp;
    gc_env.r[4] = gc_env.r[1] + 52; // addi r4, r1, 0x34
    gc_env.f[1] = (float)gc_env.f[31] * (float)gc_env.f[2] + (float)gc_env.f[1]; // fmadds f1, f31, f2, f1
    gc_env.f[1] = (float)gc_env.f[30] * (float)gc_env.f[1]; // fmuls f1, f30, f1
    gc_env.f[0] = (float)gc_env.f[0] * (float)gc_env.f[1]; // fmuls f0, f0, f1
    float temp = (float)gc_env.f[0]; // stfs f0, 0x34(r1)
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x34, *(uint32_t*)&temp);
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x38); // lfs f0, 0x38(r1)
    gc_env.f[0] = *(float*)&temp;
    gc_env.f[0] = (float)gc_env.f[0] * (float)gc_env.f[1]; // fmuls f0, f0, f1
    float temp = (float)gc_env.f[0]; // stfs f0, 0x38(r1)
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x38, *(uint32_t*)&temp);
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x3C); // lfs f0, 0x3C(r1)
    gc_env.f[0] = *(float*)&temp;
    gc_env.f[0] = (float)gc_env.f[0] * (float)gc_env.f[1]; // fmuls f0, f0, f1
    float temp = (float)gc_env.f[0]; // stfs f0, 0x3C(r1)
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x3C, *(uint32_t*)&temp);
    lbVector_Add();
    L_8002BF4C:
    gc_env.f[0] = cm_804D7E14; // lfs f0, cm_804D7E14@sda21(r0)
    gc_env.cr[0] = isnan(gc_env.f[0]) || isnan(gc_env.f[29]) ? 0x1 : (gc_env.f[0] < gc_env.f[29] ? 0x8 : (gc_env.f[0] > gc_env.f[29] ? 0x4 : 0x2)); // fcmpu cr0, f0, f29
    if (gc_env.cr[0] == 0) goto L_8002BFA4;
    gc_env.r[3] = ((uint32_t)&cm_803BCCA0 >> 16) & 0xFFFF; // lis r3, cm_803BCCA0@ha
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x1C); // lfs f2, 0x1C(r1)
    gc_env.f[2] = *(float*)&temp;
    gc_env.r[4] = gc_env.r[3] + ((uint32_t)&cm_803BCCA0 & 0xFFFF); // addi r4, r3, cm_803BCCA0@l
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[4] + 0xBC); // lfs f1, 0xBC(r4)
    gc_env.f[1] = *(float*)&temp;
    gc_env.r[3] = gc_env.r[1] + 16; // addi r3, r1, 0x10
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[4] + 0xC0); // lfs f0, 0xC0(r4)
    gc_env.f[0] = *(float*)&temp;
    gc_env.r[4] = gc_env.r[1] + 28; // addi r4, r1, 0x1c
    gc_env.f[0] = (float)gc_env.f[31] * (float)gc_env.f[1] + (float)gc_env.f[0]; // fmadds f0, f31, f1, f0
    gc_env.f[0] = (float)gc_env.f[29] * (float)gc_env.f[0]; // fmuls f0, f29, f0
    gc_env.f[1] = -gc_env.f[0]; // fneg f1, f0
    gc_env.f[0] = (float)gc_env.f[2] * (float)gc_env.f[1]; // fmuls f0, f2, f1
    float temp = (float)gc_env.f[0]; // stfs f0, 0x1C(r1)
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x1C, *(uint32_t*)&temp);
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x20); // lfs f0, 0x20(r1)
    gc_env.f[0] = *(float*)&temp;
    gc_env.f[0] = (float)gc_env.f[0] * (float)gc_env.f[1]; // fmuls f0, f0, f1
    float temp = (float)gc_env.f[0]; // stfs f0, 0x20(r1)
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x20, *(uint32_t*)&temp);
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x24); // lfs f0, 0x24(r1)
    gc_env.f[0] = *(float*)&temp;
    gc_env.f[0] = (float)gc_env.f[0] * (float)gc_env.f[1]; // fmuls f0, f0, f1
    float temp = (float)gc_env.f[0]; // stfs f0, 0x24(r1)
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x24, *(uint32_t*)&temp);
    lbVector_Add();
    L_8002BFA4:
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[31] + 0x330); // lfs f29, 0x330(r31)
    gc_env.f[29] = *(float*)&temp;
    gc_env.r[3] = gc_env.r[1] + 16; // addi r3, r1, 0x10
    lbVector_Normalize();
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x10); // lfs f0, 0x10(r1)
    gc_env.f[0] = *(float*)&temp;
    gc_env.f[0] = (float)gc_env.f[0] * (float)gc_env.f[29]; // fmuls f0, f0, f29
    float temp = (float)gc_env.f[0]; // stfs f0, 0x10(r1)
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x10, *(uint32_t*)&temp);
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x14); // lfs f0, 0x14(r1)
    gc_env.f[0] = *(float*)&temp;
    gc_env.f[0] = (float)gc_env.f[0] * (float)gc_env.f[29]; // fmuls f0, f0, f29
    float temp = (float)gc_env.f[0]; // stfs f0, 0x14(r1)
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x14, *(uint32_t*)&temp);
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x18); // lfs f0, 0x18(r1)
    gc_env.f[0] = *(float*)&temp;
    gc_env.f[0] = (float)gc_env.f[0] * (float)gc_env.f[29]; // fmuls f0, f0, f29
    float temp = (float)gc_env.f[0]; // stfs f0, 0x18(r1)
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x18, *(uint32_t*)&temp);
    gc_env.r[3] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x10);
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x14);
    gc_mem_write32(gc_env.ram, gc_env.r[30] + 0x0, gc_env.r[3]);
    gc_mem_write32(gc_env.ram, gc_env.r[30] + 0x4, gc_env.r[0]);
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x18);
    gc_mem_write32(gc_env.ram, gc_env.r[30] + 0x8, gc_env.r[0]);
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x64);
    uint64_t temp = gc_mem_read64(gc_env.ram, gc_env.r[1] + 0x58); // lfd f31, 0x58(r1)
    gc_env.d[31] = *(double*)&temp;
    uint64_t temp = gc_mem_read64(gc_env.ram, gc_env.r[1] + 0x50); // lfd f30, 0x50(r1)
    gc_env.d[30] = *(double*)&temp;
    uint64_t temp = gc_mem_read64(gc_env.ram, gc_env.r[1] + 0x48); // lfd f29, 0x48(r1)
    gc_env.d[29] = *(double*)&temp;
    gc_env.r[31] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x44);
    gc_env.r[30] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x40);
    gc_env.r[1] += 96; // addi r1, r1, 0x60
    gc_env.lr = gc_env.r[0]; // Move to link register
    return;
}

// Function: Camera_8002C010
void Camera_8002C010(void) {
    gc_env.r[0] = gc_env.lr; // Move from link register
    gc_env.r[3] = ((uint32_t)&cm_803B73DC >> 16) & 0xFFFF; // lis r3, cm_803B73DC@ha
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x4, gc_env.r[0]);
    gc_env.r[4] = gc_env.r[3] + ((uint32_t)&cm_803B73DC & 0xFFFF); // addi r4, r3, cm_803B73DC@l
    gc_env.r[5] = ((uint32_t)&cm_80452C68 >> 16) & 0xFFFF; // lis r5, cm_80452C68@ha
    gc_mem_write32(gc_env.ram, gc_env.r[1] + -0x58, gc_env.r[1]);
    gc_env.r[1] = gc_env.r[1] + -0x58;
    uint64_t temp;
    memcpy(&temp, &gc_env.f[31], sizeof(double));
    gc_mem_write64(gc_env.ram, gc_env.r[1] + 0x50, temp); // stfd f31, 0x50(r1)
    gc_env.f[31] = gc_env.f[1]; // fmr f31, f1
    uint64_t temp;
    memcpy(&temp, &gc_env.f[30], sizeof(double));
    gc_mem_write64(gc_env.ram, gc_env.r[1] + 0x48, temp); // stfd f30, 0x48(r1)
    uint64_t temp;
    memcpy(&temp, &gc_env.f[29], sizeof(double));
    gc_mem_write64(gc_env.ram, gc_env.r[1] + 0x40, temp); // stfd f29, 0x40(r1)
    gc_env.f[29] = gc_env.f[2]; // fmr f29, f2
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x3c, gc_env.r[31]);
    gc_env.r[31] = gc_env.r[5] + ((uint32_t)&cm_80452C68 & 0xFFFF); // addi r31, r5, cm_80452C68@l
    gc_env.r[3] = gc_mem_read32(gc_env.ram, gc_env.r[4] + 0x0);
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[4] + 0x4);
    gc_env.f[3] = cm_804D7E10; // lfs f3, cm_804D7E10@sda21(r0)
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x2c, gc_env.r[3]);
    gc_env.r[3] = gc_env.r[1] + 32; // addi r3, r1, 0x20
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x30, gc_env.r[0]);
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[4] + 0x8);
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x34, gc_env.r[0]);
    gc_env.r[4] = gc_mem_read32(gc_env.ram, gc_env.r[31] + 0x320);
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[31] + 0x324);
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x20, gc_env.r[4]);
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x24, gc_env.r[0]);
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[31] + 0x328);
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x28, gc_env.r[0]);
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x20); // lfs f0, 0x20(r1)
    gc_env.f[0] = *(float*)&temp;
    gc_env.f[0] = (float)gc_env.f[0] * (float)gc_env.f[3]; // fmuls f0, f0, f3
    float temp = (float)gc_env.f[0]; // stfs f0, 0x20(r1)
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x20, *(uint32_t*)&temp);
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x24); // lfs f0, 0x24(r1)
    gc_env.f[0] = *(float*)&temp;
    gc_env.f[0] = (float)gc_env.f[0] * (float)gc_env.f[3]; // fmuls f0, f0, f3
    float temp = (float)gc_env.f[0]; // stfs f0, 0x24(r1)
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x24, *(uint32_t*)&temp);
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x28); // lfs f0, 0x28(r1)
    gc_env.f[0] = *(float*)&temp;
    gc_env.f[0] = (float)gc_env.f[0] * (float)gc_env.f[3]; // fmuls f0, f0, f3
    float temp = (float)gc_env.f[0]; // stfs f0, 0x28(r1)
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x28, *(uint32_t*)&temp);
    lbVector_Normalize();
    gc_env.f[30] = gc_env.f[1]; // fmr f30, f1
    gc_env.f[2] = cm_804D7E04; // lfs f2, cm_804D7E04@sda21(r0)
    gc_env.cr[0] = isnan(gc_env.f[30]) || isnan(gc_env.f[2]) ? 0x1 : (gc_env.f[30] < gc_env.f[2] ? 0x8 : (gc_env.f[30] > gc_env.f[2] ? 0x4 : 0x2)); // fcmpo cr0, f30, f2
    if (gc_env.cr[0] >= 0) goto L_8002C0CC;
    gc_env.f[0] = cm_804D7E14; // lfs f0, cm_804D7E14@sda21(r0)
    gc_env.f[30] = gc_env.f[2]; // fmr f30, f2
    float temp = (float)gc_env.f[0]; // stfs f0, 0x24(r1)
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x24, *(uint32_t*)&temp);
    float temp = (float)gc_env.f[0]; // stfs f0, 0x20(r1)
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x20, *(uint32_t*)&temp);
    float temp = (float)gc_env.f[2]; // stfs f2, 0x28(r1)
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x28, *(uint32_t*)&temp);
    float temp = (float)gc_env.f[2]; // stfs f2, 0x330(r31)
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x330, *(uint32_t*)&temp);
    L_8002C0CC:
    gc_env.r[3] = gc_env.r[1] + 32; // addi r3, r1, 0x20
    gc_env.r[4] = gc_env.r[1] + 44; // addi r4, r1, 0x2c
    gc_env.r[5] = gc_env.r[1] + 20; // addi r5, r1, 0x14
    Camera_8002BC78();
    gc_env.f[0] = cm_804D7E14; // lfs f0, cm_804D7E14@sda21(r0)
    gc_env.cr[0] = isnan(gc_env.f[0]) || isnan(gc_env.f[29]) ? 0x1 : (gc_env.f[0] < gc_env.f[29] ? 0x8 : (gc_env.f[0] > gc_env.f[29] ? 0x4 : 0x2)); // fcmpu cr0, f0, f29
    if (gc_env.cr[0] == 0) goto L_8002C130;
    gc_env.r[3] = ((uint32_t)&cm_803BCCA0 >> 16) & 0xFFFF; // lis r3, cm_803BCCA0@ha
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x2C); // lfs f0, 0x2C(r1)
    gc_env.f[0] = *(float*)&temp;
    gc_env.r[4] = gc_env.r[3] + ((uint32_t)&cm_803BCCA0 & 0xFFFF); // addi r4, r3, cm_803BCCA0@l
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[4] + 0xB4); // lfs f2, 0xB4(r4)
    gc_env.f[2] = *(float*)&temp;
    gc_env.r[3] = gc_env.r[31] + 788; // addi r3, r31, 0x314
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[4] + 0xB8); // lfs f1, 0xB8(r4)
    gc_env.f[1] = *(float*)&temp;
    gc_env.r[4] = gc_env.r[1] + 44; // addi r4, r1, 0x2c
    gc_env.f[1] = (float)gc_env.f[30] * (float)gc_env.f[2] + (float)gc_env.f[1]; // fmadds f1, f30, f2, f1
    gc_env.f[1] = (float)gc_env.f[29] * (float)gc_env.f[1]; // fmuls f1, f29, f1
    gc_env.f[0] = (float)gc_env.f[0] * (float)gc_env.f[1]; // fmuls f0, f0, f1
    float temp = (float)gc_env.f[0]; // stfs f0, 0x2C(r1)
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x2C, *(uint32_t*)&temp);
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x30); // lfs f0, 0x30(r1)
    gc_env.f[0] = *(float*)&temp;
    gc_env.f[0] = (float)gc_env.f[0] * (float)gc_env.f[1]; // fmuls f0, f0, f1
    float temp = (float)gc_env.f[0]; // stfs f0, 0x30(r1)
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x30, *(uint32_t*)&temp);
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x34); // lfs f0, 0x34(r1)
    gc_env.f[0] = *(float*)&temp;
    gc_env.f[0] = (float)gc_env.f[0] * (float)gc_env.f[1]; // fmuls f0, f0, f1
    float temp = (float)gc_env.f[0]; // stfs f0, 0x34(r1)
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x34, *(uint32_t*)&temp);
    lbVector_Add();
    L_8002C130:
    gc_env.f[0] = cm_804D7E14; // lfs f0, cm_804D7E14@sda21(r0)
    gc_env.cr[0] = isnan(gc_env.f[0]) || isnan(gc_env.f[31]) ? 0x1 : (gc_env.f[0] < gc_env.f[31] ? 0x8 : (gc_env.f[0] > gc_env.f[31] ? 0x4 : 0x2)); // fcmpu cr0, f0, f31
    if (gc_env.cr[0] == 0) goto L_8002C188;
    gc_env.r[3] = ((uint32_t)&cm_803BCCA0 >> 16) & 0xFFFF; // lis r3, cm_803BCCA0@ha
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x14); // lfs f2, 0x14(r1)
    gc_env.f[2] = *(float*)&temp;
    gc_env.r[4] = gc_env.r[3] + ((uint32_t)&cm_803BCCA0 & 0xFFFF); // addi r4, r3, cm_803BCCA0@l
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[4] + 0xB4); // lfs f1, 0xB4(r4)
    gc_env.f[1] = *(float*)&temp;
    gc_env.r[3] = gc_env.r[31] + 788; // addi r3, r31, 0x314
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[4] + 0xB8); // lfs f0, 0xB8(r4)
    gc_env.f[0] = *(float*)&temp;
    gc_env.r[4] = gc_env.r[1] + 20; // addi r4, r1, 0x14
    gc_env.f[0] = (float)gc_env.f[30] * (float)gc_env.f[1] + (float)gc_env.f[0]; // fmadds f0, f30, f1, f0
    gc_env.f[0] = (float)gc_env.f[31] * (float)gc_env.f[0]; // fmuls f0, f31, f0
    gc_env.f[1] = -gc_env.f[0]; // fneg f1, f0
    gc_env.f[0] = (float)gc_env.f[2] * (float)gc_env.f[1]; // fmuls f0, f2, f1
    float temp = (float)gc_env.f[0]; // stfs f0, 0x14(r1)
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x14, *(uint32_t*)&temp);
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x18); // lfs f0, 0x18(r1)
    gc_env.f[0] = *(float*)&temp;
    gc_env.f[0] = (float)gc_env.f[0] * (float)gc_env.f[1]; // fmuls f0, f0, f1
    float temp = (float)gc_env.f[0]; // stfs f0, 0x18(r1)
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x18, *(uint32_t*)&temp);
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x1C); // lfs f0, 0x1C(r1)
    gc_env.f[0] = *(float*)&temp;
    gc_env.f[0] = (float)gc_env.f[0] * (float)gc_env.f[1]; // fmuls f0, f0, f1
    float temp = (float)gc_env.f[0]; // stfs f0, 0x1C(r1)
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x1C, *(uint32_t*)&temp);
    lbVector_Add();
    L_8002C188:
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x5c);
    uint64_t temp = gc_mem_read64(gc_env.ram, gc_env.r[1] + 0x50); // lfd f31, 0x50(r1)
    gc_env.d[31] = *(double*)&temp;
    uint64_t temp = gc_mem_read64(gc_env.ram, gc_env.r[1] + 0x48); // lfd f30, 0x48(r1)
    gc_env.d[30] = *(double*)&temp;
    uint64_t temp = gc_mem_read64(gc_env.ram, gc_env.r[1] + 0x40); // lfd f29, 0x40(r1)
    gc_env.d[29] = *(double*)&temp;
    gc_env.r[31] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x3c);
    gc_env.r[1] += 88; // addi r1, r1, 0x58
    gc_env.lr = gc_env.r[0]; // Move to link register
    return;
}

// Function: Camera_8002C1A8
void Camera_8002C1A8(void) {
    gc_env.r[0] = gc_env.lr; // Move from link register
    gc_env.r[3] = ((uint32_t)&cm_80452C68 >> 16) & 0xFFFF; // lis r3, cm_80452C68@ha
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x4, gc_env.r[0]);
    gc_mem_write32(gc_env.ram, gc_env.r[1] + -0x68, gc_env.r[1]);
    gc_env.r[1] = gc_env.r[1] + -0x68;
    uint64_t temp;
    memcpy(&temp, &gc_env.f[31], sizeof(double));
    gc_mem_write64(gc_env.ram, gc_env.r[1] + 0x60, temp); // stfd f31, 0x60(r1)
    uint64_t temp;
    memcpy(&temp, &gc_env.f[30], sizeof(double));
    gc_mem_write64(gc_env.ram, gc_env.r[1] + 0x58, temp); // stfd f30, 0x58(r1)
    uint64_t temp;
    memcpy(&temp, &gc_env.f[29], sizeof(double));
    gc_mem_write64(gc_env.ram, gc_env.r[1] + 0x50, temp); // stfd f29, 0x50(r1)
    uint64_t temp;
    memcpy(&temp, &gc_env.f[28], sizeof(double));
    gc_mem_write64(gc_env.ram, gc_env.r[1] + 0x48, temp); // stfd f28, 0x48(r1)
    uint64_t temp;
    memcpy(&temp, &gc_env.f[27], sizeof(double));
    gc_mem_write64(gc_env.ram, gc_env.r[1] + 0x40, temp); // stfd f27, 0x40(r1)
    uint64_t temp;
    memcpy(&temp, &gc_env.f[26], sizeof(double));
    gc_mem_write64(gc_env.ram, gc_env.r[1] + 0x38, temp); // stfd f26, 0x38(r1)
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x34, gc_env.r[31]);
    gc_env.r[31] = gc_env.r[3] + ((uint32_t)&cm_80452C68 & 0xFFFF); // addi r31, r3, cm_80452C68@l
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x30, gc_env.r[30]);
    gc_env.r[0] = gc_mem_read8(gc_env.ram, gc_env.r[31] + 0x305);
    // Unknown opcode: extsb r4 r0
    gc_env.cr[0] = (gc_env.r[4] == 0x5) ? 0 : (gc_env.r[4] < 0x5 ? -1 : 1); // Compare with immediate
    if (gc_env.cr[0] == 0) goto L_8002C584;
    gc_env.r[3] = gc_env.r[1] + 16; // addi r3, r1, 0x10
    Camera_8002B694();
    gc_env.f[27] = cm_804D7E14; // lfs f27, cm_804D7E14@sda21(r0)
    gc_env.r[0] = 0x20;
    gc_env.r[6] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x2c);
    gc_env.r[8] = 0x0;
    gc_env.f[28] = gc_env.f[27]; // fmr f28, f27
    gc_env.r[4] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x28);
    gc_env.r[0] = gc_env.r[6] & gc_env.r[0];
    // Unknown opcode: xor r3 r0 r8
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x10); // lfs f2, 0x10(r1)
    gc_env.f[2] = *(float*)&temp;
    gc_env.f[29] = gc_env.f[28]; // fmr f29, f28
    gc_env.r[7] = gc_env.r[4] & gc_env.r[8];
    // Unknown opcode: xor r0 r7 r8
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x14); // lfs f3, 0x14(r1)
    gc_env.f[3] = *(float*)&temp;
    gc_env.r[0] = gc_env.r[3] | gc_env.r[0]; // or r0, r3, r0
    gc_env.f[30] = gc_env.f[29]; // fmr f30, f29
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x18); // lfs f4, 0x18(r1)
    gc_env.f[4] = *(float*)&temp;
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x1C); // lfs f5, 0x1C(r1)
    gc_env.f[5] = *(float*)&temp;
    gc_env.r[4] = 0x0;
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x20);
    gc_env.f[31] = gc_env.f[30]; // fmr f31, f30
    gc_env.r[3] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x24);
    if (gc_env.cr[0] == 0) goto L_8002C254;
    gc_env.r[4] = 0x1;
    goto L_8002C270;
    L_8002C254:
    gc_env.r[5] = 0x40;
    gc_env.r[5] = gc_env.r[6] & gc_env.r[5];
    // Unknown opcode: xor r6 r5 r8
    // Unknown opcode: xor r5 r7 r8
    gc_env.r[5] = gc_env.r[6] | gc_env.r[5]; // or r5, r6, r5
    if (gc_env.cr[0] == 0) goto L_8002C270;
    gc_env.r[4] = -0x1;
    L_8002C270:
    gc_env.r[5] = 0x8;
    gc_env.r[8] = 0x0;
    gc_env.r[5] = gc_env.r[3] & gc_env.r[5];
    gc_env.r[7] = gc_env.r[0] & gc_env.r[8];
    // Unknown opcode: xor r6 r5 r8
    // Unknown opcode: xor r5 r7 r8
    gc_env.r[5] = gc_env.r[6] | gc_env.r[5]; // or r5, r6, r5
    if (gc_env.cr[0] == 0) goto L_8002C298;
    gc_env.f[29] = cm_804D7E04; // lfs f29, cm_804D7E04@sda21(r0)
    goto L_8002C2B4;
    L_8002C298:
    gc_env.r[5] = 0x4;
    gc_env.r[5] = gc_env.r[3] & gc_env.r[5];
    // Unknown opcode: xor r6 r5 r8
    // Unknown opcode: xor r5 r7 r8
    gc_env.r[5] = gc_env.r[6] | gc_env.r[5]; // or r5, r6, r5
    if (gc_env.cr[0] == 0) goto L_8002C2B4;
    gc_env.f[29] = cm_804D7E10; // lfs f29, cm_804D7E10@sda21(r0)
    L_8002C2B4:
    gc_env.r[5] = 0x1;
    gc_env.r[8] = 0x0;
    gc_env.r[5] = gc_env.r[3] & gc_env.r[5];
    gc_env.r[7] = gc_env.r[0] & gc_env.r[8];
    // Unknown opcode: xor r6 r5 r8
    // Unknown opcode: xor r5 r7 r8
    gc_env.r[5] = gc_env.r[6] | gc_env.r[5]; // or r5, r6, r5
    if (gc_env.cr[0] == 0) goto L_8002C2DC;
    gc_env.f[30] = cm_804D7E10; // lfs f30, cm_804D7E10@sda21(r0)
    goto L_8002C2F8;
    L_8002C2DC:
    gc_env.r[5] = 0x2;
    gc_env.r[5] = gc_env.r[3] & gc_env.r[5];
    // Unknown opcode: xor r6 r5 r8
    // Unknown opcode: xor r5 r7 r8
    gc_env.r[5] = gc_env.r[6] | gc_env.r[5]; // or r5, r6, r5
    if (gc_env.cr[0] == 0) goto L_8002C2F8;
    gc_env.f[30] = cm_804D7E04; // lfs f30, cm_804D7E04@sda21(r0)
    L_8002C2F8:
    gc_env.r[5] = 0x400;
    gc_env.r[8] = 0x0;
    gc_env.r[5] = gc_env.r[3] & gc_env.r[5];
    gc_env.r[7] = gc_env.r[0] & gc_env.r[8];
    // Unknown opcode: xor r6 r5 r8
    // Unknown opcode: xor r5 r7 r8
    gc_env.r[5] = gc_env.r[6] | gc_env.r[5]; // or r5, r6, r5
    if (gc_env.cr[0] == 0) goto L_8002C320;
    gc_env.f[31] = cm_804D7E04; // lfs f31, cm_804D7E04@sda21(r0)
    goto L_8002C33C;
    L_8002C320:
    gc_env.r[5] = 0x800;
    gc_env.r[5] = gc_env.r[3] & gc_env.r[5];
    // Unknown opcode: xor r6 r5 r8
    // Unknown opcode: xor r5 r7 r8
    gc_env.r[5] = gc_env.r[6] | gc_env.r[5]; // or r5, r6, r5
    if (gc_env.cr[0] == 0) goto L_8002C33C;
    gc_env.f[31] = cm_804D7E10; // lfs f31, cm_804D7E10@sda21(r0)
    L_8002C33C:
    gc_env.r[6] = 0x100;
    gc_env.r[5] = 0x0;
    gc_env.r[3] = gc_env.r[3] & gc_env.r[6];
    gc_env.r[0] = gc_env.r[0] & gc_env.r[5];
    // Unknown opcode: xor r3 r3 r5
    // Unknown opcode: xor r0 r0 r5
    gc_env.r[0] = gc_env.r[3] | gc_env.r[0]; // or r0, r3, r0
    if (gc_env.cr[0] == 0) goto L_8002C3B0;
    gc_env.f[0] = cm_804D7E14; // lfs f0, cm_804D7E14@sda21(r0)
    gc_env.cr[0] = isnan(gc_env.f[2]) || isnan(gc_env.f[0]) ? 0x1 : (gc_env.f[2] < gc_env.f[0] ? 0x8 : (gc_env.f[2] > gc_env.f[0] ? 0x4 : 0x2)); // fcmpo cr0, f2, f0
    if (gc_env.cr[0] >= 0) goto L_8002C370;
    gc_env.f[1] = -gc_env.f[2]; // fneg f1, f2
    goto L_8002C374;
    L_8002C370:
    gc_env.f[1] = gc_env.f[2]; // fmr f1, f2
    L_8002C374:
    gc_env.d[0] = cm_804D7EA0; // lfd f0, cm_804D7EA0@sda21(r0)
    gc_env.cr[0] = isnan(gc_env.f[1]) || isnan(gc_env.f[0]) ? 0x1 : (gc_env.f[1] < gc_env.f[0] ? 0x8 : (gc_env.f[1] > gc_env.f[0] ? 0x4 : 0x2)); // fcmpo cr0, f1, f0
    if (gc_env.cr[0] & (0x8 | 0x2)) goto L_8002C384; // ble .L_8002C384
    gc_env.f[30] = gc_env.f[2]; // fmr f30, f2
    L_8002C384:
    gc_env.f[0] = cm_804D7E14; // lfs f0, cm_804D7E14@sda21(r0)
    gc_env.cr[0] = isnan(gc_env.f[3]) || isnan(gc_env.f[0]) ? 0x1 : (gc_env.f[3] < gc_env.f[0] ? 0x8 : (gc_env.f[3] > gc_env.f[0] ? 0x4 : 0x2)); // fcmpo cr0, f3, f0
    if (gc_env.cr[0] >= 0) goto L_8002C398;
    gc_env.f[1] = -gc_env.f[3]; // fneg f1, f3
    goto L_8002C39C;
    L_8002C398:
    gc_env.f[1] = gc_env.f[3]; // fmr f1, f3
    L_8002C39C:
    gc_env.d[0] = cm_804D7EA0; // lfd f0, cm_804D7EA0@sda21(r0)
    gc_env.cr[0] = isnan(gc_env.f[1]) || isnan(gc_env.f[0]) ? 0x1 : (gc_env.f[1] < gc_env.f[0] ? 0x8 : (gc_env.f[1] > gc_env.f[0] ? 0x4 : 0x2)); // fcmpo cr0, f1, f0
    if (gc_env.cr[0] & (0x8 | 0x2)) goto L_8002C3AC; // ble .L_8002C3AC
    gc_env.f[29] = gc_env.f[3]; // fmr f29, f3
    L_8002C3AC:
    gc_env.f[3] = cm_804D7E14; // lfs f3, cm_804D7E14@sda21(r0)
    L_8002C3B0:
    gc_env.f[0] = cm_804D7E14; // lfs f0, cm_804D7E14@sda21(r0)
    gc_env.cr[0] = isnan(gc_env.f[3]) || isnan(gc_env.f[0]) ? 0x1 : (gc_env.f[3] < gc_env.f[0] ? 0x8 : (gc_env.f[3] > gc_env.f[0] ? 0x4 : 0x2)); // fcmpo cr0, f3, f0
    if (gc_env.cr[0] >= 0) goto L_8002C3C4;
    gc_env.f[1] = -gc_env.f[3]; // fneg f1, f3
    goto L_8002C3C8;
    L_8002C3C4:
    gc_env.f[1] = gc_env.f[3]; // fmr f1, f3
    L_8002C3C8:
    gc_env.d[0] = cm_804D7EA0; // lfd f0, cm_804D7EA0@sda21(r0)
    gc_env.cr[0] = isnan(gc_env.f[1]) || isnan(gc_env.f[0]) ? 0x1 : (gc_env.f[1] < gc_env.f[0] ? 0x8 : (gc_env.f[1] > gc_env.f[0] ? 0x4 : 0x2)); // fcmpo cr0, f1, f0
    if (gc_env.cr[0] & (0x8 | 0x2)) goto L_8002C3D8; // ble .L_8002C3D8
    gc_env.f[31] = -gc_env.f[3]; // fneg f31, f3
    L_8002C3D8:
    gc_env.f[0] = cm_804D7E14; // lfs f0, cm_804D7E14@sda21(r0)
    gc_env.cr[0] = isnan(gc_env.f[4]) || isnan(gc_env.f[0]) ? 0x1 : (gc_env.f[4] < gc_env.f[0] ? 0x8 : (gc_env.f[4] > gc_env.f[0] ? 0x4 : 0x2)); // fcmpo cr0, f4, f0
    if (gc_env.cr[0] >= 0) goto L_8002C3EC;
    gc_env.f[1] = -gc_env.f[4]; // fneg f1, f4
    goto L_8002C3F0;
    L_8002C3EC:
    gc_env.f[1] = gc_env.f[4]; // fmr f1, f4
    L_8002C3F0:
    gc_env.d[0] = cm_804D7EA0; // lfd f0, cm_804D7EA0@sda21(r0)
    gc_env.cr[0] = isnan(gc_env.f[1]) || isnan(gc_env.f[0]) ? 0x1 : (gc_env.f[1] < gc_env.f[0] ? 0x8 : (gc_env.f[1] > gc_env.f[0] ? 0x4 : 0x2)); // fcmpo cr0, f1, f0
    if (gc_env.cr[0] & (0x8 | 0x2)) goto L_8002C400; // ble .L_8002C400
    gc_env.f[28] = gc_env.f[4]; // fmr f28, f4
    L_8002C400:
    gc_env.f[0] = cm_804D7E14; // lfs f0, cm_804D7E14@sda21(r0)
    gc_env.cr[0] = isnan(gc_env.f[5]) || isnan(gc_env.f[0]) ? 0x1 : (gc_env.f[5] < gc_env.f[0] ? 0x8 : (gc_env.f[5] > gc_env.f[0] ? 0x4 : 0x2)); // fcmpo cr0, f5, f0
    if (gc_env.cr[0] >= 0) goto L_8002C414;
    gc_env.f[1] = -gc_env.f[5]; // fneg f1, f5
    goto L_8002C418;
    L_8002C414:
    gc_env.f[1] = gc_env.f[5]; // fmr f1, f5
    L_8002C418:
    gc_env.d[0] = cm_804D7EA0; // lfd f0, cm_804D7EA0@sda21(r0)
    gc_env.cr[0] = isnan(gc_env.f[1]) || isnan(gc_env.f[0]) ? 0x1 : (gc_env.f[1] < gc_env.f[0] ? 0x8 : (gc_env.f[1] > gc_env.f[0] ? 0x4 : 0x2)); // fcmpo cr0, f1, f0
    if (gc_env.cr[0] & (0x8 | 0x2)) goto L_8002C428; // ble .L_8002C428
    gc_env.f[27] = gc_env.f[5]; // fmr f27, f5
    L_8002C428:
    gc_env.cr[0] = (gc_env.r[4] == 0x0) ? 0 : (gc_env.r[4] < 0x0 ? -1 : 1); // Compare with immediate
    if (gc_env.cr[0] == 0) goto L_8002C4BC;
    gc_env.r[3] = ((uint32_t)&cm_803BCCA0 >> 16) & 0xFFFF; // lis r3, cm_803BCCA0@ha
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[31] + 0x32C); // lfs f2, 0x32C(r31)
    gc_env.f[2] = *(float*)&temp;
    gc_env.r[3] = gc_env.r[3] + ((uint32_t)&cm_803BCCA0 & 0xFFFF); // addi r3, r3, cm_803BCCA0@l
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[3] + 0x8C); // lfs f1, 0x8C(r3)
    gc_env.f[1] = *(float*)&temp;
    gc_env.r[30] = gc_env.r[31] + 772; // addi r30, r31, 0x304
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[3] + 0x90); // lfs f0, 0x90(r3)
    gc_env.f[0] = *(float*)&temp;
    gc_env.r[3] = gc_mem_read8(gc_env.ram, gc_env.r[31] + 0x304);
    gc_env.f[26] = (float)gc_env.f[2] * (float)gc_env.f[1] + (float)gc_env.f[0]; // fmadds f26, f2, f1, f0
    // Unknown opcode: extsb r3 r3
    Camera_8002BA00();
    // Unknown opcode: extsb r0 r3
    gc_mem_write8(gc_env.ram, gc_env.r[30] + 0x0, gc_env.r[0]);
    gc_env.r[0] = gc_mem_read8(gc_env.ram, gc_env.r[30] + 0x0);
    gc_env.f[1] = cm_804D7E14; // lfs f1, cm_804D7E14@sda21(r0)
    gc_env.cr[0] = (gc_env.r[0] == 0xa) ? 0 : (gc_env.r[0] < 0xa ? -1 : 1); // Compare with immediate
    float temp = (float)gc_env.f[1]; // stfs f1, 0x31C(r31)
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x31C, *(uint32_t*)&temp);
    float temp = (float)gc_env.f[1]; // stfs f1, 0x318(r31)
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x318, *(uint32_t*)&temp);
    float temp = (float)gc_env.f[1]; // stfs f1, 0x314(r31)
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x314, *(uint32_t*)&temp);
    float temp = (float)gc_env.f[1]; // stfs f1, 0x320(r31)
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x320, *(uint32_t*)&temp);
    gc_env.f[0] = cm_804D7E90; // lfs f0, cm_804D7E90@sda21(r0)
    float temp = (float)gc_env.f[0]; // stfs f0, 0x324(r31)
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x324, *(uint32_t*)&temp);
    gc_env.f[0] = cm_804D7E94; // lfs f0, cm_804D7E94@sda21(r0)
    float temp = (float)gc_env.f[0]; // stfs f0, 0x328(r31)
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x328, *(uint32_t*)&temp);
    float temp = (float)gc_env.f[1]; // stfs f1, 0x334(r31)
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x334, *(uint32_t*)&temp);
    gc_env.f[0] = cm_804D7E04; // lfs f0, cm_804D7E04@sda21(r0)
    float temp = (float)gc_env.f[0]; // stfs f0, 0x338(r31)
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x338, *(uint32_t*)&temp);
    float temp = (float)gc_env.f[1]; // stfs f1, 0x33C(r31)
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x33C, *(uint32_t*)&temp);
    if (gc_env.cr[0] != 0) goto L_8002C4B0;
    gc_env.f[0] = cm_804D7E98; // lfs f0, cm_804D7E98@sda21(r0)
    gc_env.f[0] = (float)gc_env.f[0] * (float)gc_env.f[26]; // fmuls f0, f0, f26
    float temp = (float)gc_env.f[0]; // stfs f0, 0x330(r31)
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x330, *(uint32_t*)&temp);
    goto L_8002C4B4;
    L_8002C4B0:
    float temp = (float)gc_env.f[26]; // stfs f26, 0x330(r31)
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x330, *(uint32_t*)&temp);
    L_8002C4B4:
    gc_env.f[1] = cm_804D7E14; // lfs f1, cm_804D7E14@sda21(r0)
    Camera_8002BAA8();
    L_8002C4BC:
    gc_env.f[0] = cm_804D7E14; // lfs f0, cm_804D7E14@sda21(r0)
    gc_env.cr[0] = isnan(gc_env.f[0]) || isnan(gc_env.f[31]) ? 0x1 : (gc_env.f[0] < gc_env.f[31] ? 0x8 : (gc_env.f[0] > gc_env.f[31] ? 0x4 : 0x2)); // fcmpu cr0, f0, f31
    if (gc_env.cr[0] == 0) goto L_8002C4D0;
    gc_env.f[1] = gc_env.f[31]; // fmr f1, f31
    Camera_8002BAA8();
    L_8002C4D0:
    gc_env.f[0] = cm_804D7E14; // lfs f0, cm_804D7E14@sda21(r0)
    gc_env.cr[0] = isnan(gc_env.f[0]) || isnan(gc_env.f[30]) ? 0x1 : (gc_env.f[0] < gc_env.f[30] ? 0x8 : (gc_env.f[0] > gc_env.f[30] ? 0x4 : 0x2)); // fcmpu cr0, f0, f30
    if (gc_env.cr[0] != 0) goto L_8002C4E4;
    gc_env.cr[0] = isnan(gc_env.f[0]) || isnan(gc_env.f[29]) ? 0x1 : (gc_env.f[0] < gc_env.f[29] ? 0x8 : (gc_env.f[0] > gc_env.f[29] ? 0x4 : 0x2)); // fcmpu cr0, f0, f29
    if (gc_env.cr[0] == 0) goto L_8002C564;
    L_8002C4E4:
    gc_env.r[0] = gc_mem_read8(gc_env.ram, gc_env.r[31] + 0x304);
    gc_env.cr[0] = (gc_env.r[0] == 0xa) ? 0 : (gc_env.r[0] < 0xa ? -1 : 1); // Compare with immediate
    if (gc_env.cr[0] != 0) goto L_8002C558;
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[31] + 0x320); // lfs f1, 0x320(r31)
    gc_env.f[1] = *(float*)&temp;
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[31] + 0x324); // lfs f0, 0x324(r31)
    gc_env.f[0] = *(float*)&temp;
    gc_env.f[1] = (float)gc_env.f[1] * (float)gc_env.f[1]; // fmuls f1, f1, f1
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[31] + 0x328); // lfs f2, 0x328(r31)
    gc_env.f[2] = *(float*)&temp;
    gc_env.f[0] = (float)gc_env.f[0] * (float)gc_env.f[0]; // fmuls f0, f0, f0
    gc_env.f[2] = (float)gc_env.f[2] * (float)gc_env.f[2]; // fmuls f2, f2, f2
    gc_env.f[0] = (float)gc_env.f[1] + (float)gc_env.f[0]; // fadds f0, f1, f0
    gc_env.f[1] = (float)gc_env.f[2] + (float)gc_env.f[0]; // fadds f1, f2, f0
    sqrtf__Ff();
    gc_env.f[0] = cm_804D7E04; // lfs f0, cm_804D7E04@sda21(r0)
    gc_env.cr[0] = isnan(gc_env.f[1]) || isnan(gc_env.f[0]) ? 0x1 : (gc_env.f[1] < gc_env.f[0] ? 0x8 : (gc_env.f[1] > gc_env.f[0] ? 0x4 : 0x2)); // fcmpo cr0, f1, f0
    if (gc_env.cr[0] >= 0) goto L_8002C524;
    float temp = (float)gc_env.f[0]; // stfs f0, 0x330(r31)
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x330, *(uint32_t*)&temp);
    L_8002C524:
    gc_env.f[0] = cm_804D7E14; // lfs f0, cm_804D7E14@sda21(r0)
    gc_env.cr[0] = isnan(gc_env.f[0]) || isnan(gc_env.f[29]) ? 0x1 : (gc_env.f[0] < gc_env.f[29] ? 0x8 : (gc_env.f[0] > gc_env.f[29] ? 0x4 : 0x2)); // fcmpu cr0, f0, f29
    if (gc_env.cr[0] == 0) goto L_8002C53C;
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[31] + 0x318); // lfs f0, 0x318(r31)
    gc_env.f[0] = *(float*)&temp;
    gc_env.f[0] = (float)gc_env.f[0] + (float)gc_env.f[29]; // fadds f0, f0, f29
    float temp = (float)gc_env.f[0]; // stfs f0, 0x318(r31)
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x318, *(uint32_t*)&temp);
    L_8002C53C:
    gc_env.f[0] = cm_804D7E14; // lfs f0, cm_804D7E14@sda21(r0)
    gc_env.cr[0] = isnan(gc_env.f[0]) || isnan(gc_env.f[30]) ? 0x1 : (gc_env.f[0] < gc_env.f[30] ? 0x8 : (gc_env.f[0] > gc_env.f[30] ? 0x4 : 0x2)); // fcmpu cr0, f0, f30
    if (gc_env.cr[0] == 0) goto L_8002C564;
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[31] + 0x314); // lfs f0, 0x314(r31)
    gc_env.f[0] = *(float*)&temp;
    gc_env.f[0] = (float)gc_env.f[0] + (float)gc_env.f[30]; // fadds f0, f0, f30
    float temp = (float)gc_env.f[0]; // stfs f0, 0x314(r31)
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x314, *(uint32_t*)&temp);
    goto L_8002C564;
    L_8002C558:
    gc_env.f[1] = gc_env.f[30]; // fmr f1, f30
    gc_env.f[2] = gc_env.f[29]; // fmr f2, f29
    Camera_8002C010();
    L_8002C564:
    gc_env.f[0] = cm_804D7E14; // lfs f0, cm_804D7E14@sda21(r0)
    gc_env.cr[0] = isnan(gc_env.f[0]) || isnan(gc_env.f[28]) ? 0x1 : (gc_env.f[0] < gc_env.f[28] ? 0x8 : (gc_env.f[0] > gc_env.f[28] ? 0x4 : 0x2)); // fcmpu cr0, f0, f28
    if (gc_env.cr[0] != 0) goto L_8002C578;
    gc_env.cr[0] = isnan(gc_env.f[0]) || isnan(gc_env.f[27]) ? 0x1 : (gc_env.f[0] < gc_env.f[27] ? 0x8 : (gc_env.f[0] > gc_env.f[27] ? 0x4 : 0x2)); // fcmpu cr0, f0, f27
    if (gc_env.cr[0] == 0) goto L_8002C584;
    L_8002C578:
    gc_env.f[1] = gc_env.f[28]; // fmr f1, f28
    gc_env.f[2] = gc_env.f[27]; // fmr f2, f27
    Camera_8002BD88();
    L_8002C584:
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x6c);
    uint64_t temp = gc_mem_read64(gc_env.ram, gc_env.r[1] + 0x60); // lfd f31, 0x60(r1)
    gc_env.d[31] = *(double*)&temp;
    uint64_t temp = gc_mem_read64(gc_env.ram, gc_env.r[1] + 0x58); // lfd f30, 0x58(r1)
    gc_env.d[30] = *(double*)&temp;
    uint64_t temp = gc_mem_read64(gc_env.ram, gc_env.r[1] + 0x50); // lfd f29, 0x50(r1)
    gc_env.d[29] = *(double*)&temp;
    uint64_t temp = gc_mem_read64(gc_env.ram, gc_env.r[1] + 0x48); // lfd f28, 0x48(r1)
    gc_env.d[28] = *(double*)&temp;
    uint64_t temp = gc_mem_read64(gc_env.ram, gc_env.r[1] + 0x40); // lfd f27, 0x40(r1)
    gc_env.d[27] = *(double*)&temp;
    uint64_t temp = gc_mem_read64(gc_env.ram, gc_env.r[1] + 0x38); // lfd f26, 0x38(r1)
    gc_env.d[26] = *(double*)&temp;
    gc_env.r[31] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x34);
    gc_env.r[30] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x30);
    gc_env.r[1] += 104; // addi r1, r1, 0x68
    gc_env.lr = gc_env.r[0]; // Move to link register
    return;
}

// Function: Camera_8002C5B4
void Camera_8002C5B4(void) {
    gc_env.r[0] = gc_env.lr; // Move from link register
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x4, gc_env.r[0]);
    gc_mem_write32(gc_env.ram, gc_env.r[1] + -0x68, gc_env.r[1]);
    gc_env.r[1] = gc_env.r[1] + -0x68;
    uint64_t temp;
    memcpy(&temp, &gc_env.f[31], sizeof(double));
    gc_mem_write64(gc_env.ram, gc_env.r[1] + 0x60, temp); // stfd f31, 0x60(r1)
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x48, gc_env.r[26]); // stmw r26, 0x48(r1)
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x4C, gc_env.r[27]); // stmw r26, 0x48(r1)
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x50, gc_env.r[28]); // stmw r26, 0x48(r1)
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x54, gc_env.r[29]); // stmw r26, 0x48(r1)
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x58, gc_env.r[30]); // stmw r26, 0x48(r1)
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x5C, gc_env.r[31]); // stmw r26, 0x48(r1)
    gc_env.r[26] = gc_env.r[3]; // Move register
    gc_env.r[12] = gc_mem_read32(gc_env.ram, gc_env.r[3] + 0x30);
    gc_env.r[3] = ((uint32_t)&cm_80452C68 >> 16) & 0xFFFF; // lis r3, cm_80452C68@ha
    gc_env.r[31] = gc_env.r[3] + ((uint32_t)&cm_80452C68 & 0xFFFF); // addi r31, r3, cm_80452C68@l
    gc_env.cr[0] = ((uint32_t)gc_env.r[12] == 0x0) ? 0 : ((uint32_t)gc_env.r[12] < 0x0 ? -1 : 1); // Logical compare with immediate
    if (gc_env.cr[0] == 0) goto L_8002C5EC;
    gc_env.lr = gc_env.r[12]; // Move to link register
    gc_env.r[3] = gc_env.r[26] + 0; // addi r3, r26, 0x0
    // Call function at gc_env.lr; // Branch to link register
    L_8002C5EC:
    gc_env.r[30] = gc_env.r[31] + 776; // addi r30, r31, 0x308
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[26] + 0xC); // lfs f0, 0xC(r26)
    gc_env.f[0] = *(float*)&temp;
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[31] + 0x308); // lfs f1, 0x308(r31)
    gc_env.f[1] = *(float*)&temp;
    gc_env.cr[0] = isnan(gc_env.f[1]) || isnan(gc_env.f[0]) ? 0x1 : (gc_env.f[1] < gc_env.f[0] ? 0x8 : (gc_env.f[1] > gc_env.f[0] ? 0x4 : 0x2)); // fcmpo cr0, f1, f0
    if (gc_env.cr[0] & (0x8 | 0x2)) goto L_8002C608; // ble .L_8002C608
    float temp = (float)gc_env.f[0]; // stfs f0, 0x0(r30)
    gc_mem_write32(gc_env.ram, gc_env.r[30] + 0x0, *(uint32_t*)&temp);
    goto L_8002C618;
    L_8002C608:
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[26] + 0x8); // lfs f0, 0x8(r26)
    gc_env.f[0] = *(float*)&temp;
    gc_env.cr[0] = isnan(gc_env.f[1]) || isnan(gc_env.f[0]) ? 0x1 : (gc_env.f[1] < gc_env.f[0] ? 0x8 : (gc_env.f[1] > gc_env.f[0] ? 0x4 : 0x2)); // fcmpo cr0, f1, f0
    if (gc_env.cr[0] >= 0) goto L_8002C618;
    float temp = (float)gc_env.f[0]; // stfs f0, 0x0(r30)
    gc_mem_write32(gc_env.ram, gc_env.r[30] + 0x0, *(uint32_t*)&temp);
    L_8002C618:
    gc_env.r[3] = gc_env.r[31] + 780; // addi r3, r31, 0x30c
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[26] + 0x0); // lfs f0, 0x0(r26)
    gc_env.f[0] = *(float*)&temp;
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[31] + 0x30C); // lfs f1, 0x30C(r31)
    gc_env.f[1] = *(float*)&temp;
    gc_env.cr[0] = isnan(gc_env.f[1]) || isnan(gc_env.f[0]) ? 0x1 : (gc_env.f[1] < gc_env.f[0] ? 0x8 : (gc_env.f[1] > gc_env.f[0] ? 0x4 : 0x2)); // fcmpo cr0, f1, f0
    if (gc_env.cr[0] & (0x8 | 0x2)) goto L_8002C634; // ble .L_8002C634
    float temp = (float)gc_env.f[0]; // stfs f0, 0x0(r3)
    gc_mem_write32(gc_env.ram, gc_env.r[3] + 0x0, *(uint32_t*)&temp);
    goto L_8002C644;
    L_8002C634:
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[26] + 0x4); // lfs f0, 0x4(r26)
    gc_env.f[0] = *(float*)&temp;
    gc_env.cr[0] = isnan(gc_env.f[1]) || isnan(gc_env.f[0]) ? 0x1 : (gc_env.f[1] < gc_env.f[0] ? 0x8 : (gc_env.f[1] > gc_env.f[0] ? 0x4 : 0x2)); // fcmpo cr0, f1, f0
    if (gc_env.cr[0] >= 0) goto L_8002C644;
    float temp = (float)gc_env.f[0]; // stfs f0, 0x0(r3)
    gc_mem_write32(gc_env.ram, gc_env.r[3] + 0x0, *(uint32_t*)&temp);
    L_8002C644:
    gc_env.r[3] = gc_env.r[31] + 784; // addi r3, r31, 0x310
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[26] + 0x10); // lfs f0, 0x10(r26)
    gc_env.f[0] = *(float*)&temp;
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[31] + 0x310); // lfs f1, 0x310(r31)
    gc_env.f[1] = *(float*)&temp;
    gc_env.cr[0] = isnan(gc_env.f[1]) || isnan(gc_env.f[0]) ? 0x1 : (gc_env.f[1] < gc_env.f[0] ? 0x8 : (gc_env.f[1] > gc_env.f[0] ? 0x4 : 0x2)); // fcmpo cr0, f1, f0
    if (gc_env.cr[0] & (0x8 | 0x2)) goto L_8002C660; // ble .L_8002C660
    float temp = (float)gc_env.f[0]; // stfs f0, 0x0(r3)
    gc_mem_write32(gc_env.ram, gc_env.r[3] + 0x0, *(uint32_t*)&temp);
    goto L_8002C670;
    L_8002C660:
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[26] + 0x14); // lfs f0, 0x14(r26)
    gc_env.f[0] = *(float*)&temp;
    gc_env.cr[0] = isnan(gc_env.f[1]) || isnan(gc_env.f[0]) ? 0x1 : (gc_env.f[1] < gc_env.f[0] ? 0x8 : (gc_env.f[1] > gc_env.f[0] ? 0x4 : 0x2)); // fcmpo cr0, f1, f0
    if (gc_env.cr[0] >= 0) goto L_8002C670;
    float temp = (float)gc_env.f[0]; // stfs f0, 0x0(r3)
    gc_mem_write32(gc_env.ram, gc_env.r[3] + 0x0, *(uint32_t*)&temp);
    L_8002C670:
    gc_env.r[29] = gc_env.r[31] + 788; // addi r29, r31, 0x314
    gc_env.r[5] = gc_mem_read32(gc_env.ram, gc_env.r[31] + 0x314);
    gc_env.r[4] = gc_env.r[30]; // Move register
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[31] + 0x318);
    gc_env.r[3] = gc_env.r[1] + 52; // addi r3, r1, 0x34
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x34, gc_env.r[5]);
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x38, gc_env.r[0]);
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[31] + 0x31c);
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x3c, gc_env.r[0]);
    lbVector_Add();
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x34); // lfs f1, 0x34(r1)
    gc_env.f[1] = *(float*)&temp;
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[26] + 0xC); // lfs f0, 0xC(r26)
    gc_env.f[0] = *(float*)&temp;
    gc_env.cr[0] = isnan(gc_env.f[1]) || isnan(gc_env.f[0]) ? 0x1 : (gc_env.f[1] < gc_env.f[0] ? 0x8 : (gc_env.f[1] > gc_env.f[0] ? 0x4 : 0x2)); // fcmpo cr0, f1, f0
    if (gc_env.cr[0] & (0x8 | 0x2)) goto L_8002C6B0; // ble .L_8002C6B0
    float temp = (float)gc_env.f[0]; // stfs f0, 0x34(r1)
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x34, *(uint32_t*)&temp);
    goto L_8002C6C0;
    L_8002C6B0:
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[26] + 0x8); // lfs f0, 0x8(r26)
    gc_env.f[0] = *(float*)&temp;
    gc_env.cr[0] = isnan(gc_env.f[1]) || isnan(gc_env.f[0]) ? 0x1 : (gc_env.f[1] < gc_env.f[0] ? 0x8 : (gc_env.f[1] > gc_env.f[0] ? 0x4 : 0x2)); // fcmpo cr0, f1, f0
    if (gc_env.cr[0] >= 0) goto L_8002C6C0;
    float temp = (float)gc_env.f[0]; // stfs f0, 0x34(r1)
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x34, *(uint32_t*)&temp);
    L_8002C6C0:
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x38); // lfs f1, 0x38(r1)
    gc_env.f[1] = *(float*)&temp;
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[26] + 0x0); // lfs f0, 0x0(r26)
    gc_env.f[0] = *(float*)&temp;
    gc_env.cr[0] = isnan(gc_env.f[1]) || isnan(gc_env.f[0]) ? 0x1 : (gc_env.f[1] < gc_env.f[0] ? 0x8 : (gc_env.f[1] > gc_env.f[0] ? 0x4 : 0x2)); // fcmpo cr0, f1, f0
    if (gc_env.cr[0] & (0x8 | 0x2)) goto L_8002C6D8; // ble .L_8002C6D8
    float temp = (float)gc_env.f[0]; // stfs f0, 0x38(r1)
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x38, *(uint32_t*)&temp);
    goto L_8002C6E8;
    L_8002C6D8:
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[26] + 0x4); // lfs f0, 0x4(r26)
    gc_env.f[0] = *(float*)&temp;
    gc_env.cr[0] = isnan(gc_env.f[1]) || isnan(gc_env.f[0]) ? 0x1 : (gc_env.f[1] < gc_env.f[0] ? 0x8 : (gc_env.f[1] > gc_env.f[0] ? 0x4 : 0x2)); // fcmpo cr0, f1, f0
    if (gc_env.cr[0] >= 0) goto L_8002C6E8;
    float temp = (float)gc_env.f[0]; // stfs f0, 0x38(r1)
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x38, *(uint32_t*)&temp);
    L_8002C6E8:
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x3C); // lfs f1, 0x3C(r1)
    gc_env.f[1] = *(float*)&temp;
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[26] + 0x10); // lfs f0, 0x10(r26)
    gc_env.f[0] = *(float*)&temp;
    gc_env.cr[0] = isnan(gc_env.f[1]) || isnan(gc_env.f[0]) ? 0x1 : (gc_env.f[1] < gc_env.f[0] ? 0x8 : (gc_env.f[1] > gc_env.f[0] ? 0x4 : 0x2)); // fcmpo cr0, f1, f0
    if (gc_env.cr[0] & (0x8 | 0x2)) goto L_8002C700; // ble .L_8002C700
    float temp = (float)gc_env.f[0]; // stfs f0, 0x3C(r1)
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x3C, *(uint32_t*)&temp);
    goto L_8002C710;
    L_8002C700:
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[26] + 0x14); // lfs f0, 0x14(r26)
    gc_env.f[0] = *(float*)&temp;
    gc_env.cr[0] = isnan(gc_env.f[1]) || isnan(gc_env.f[0]) ? 0x1 : (gc_env.f[1] < gc_env.f[0] ? 0x8 : (gc_env.f[1] > gc_env.f[0] ? 0x4 : 0x2)); // fcmpo cr0, f1, f0
    if (gc_env.cr[0] >= 0) goto L_8002C710;
    float temp = (float)gc_env.f[0]; // stfs f0, 0x3C(r1)
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x3C, *(uint32_t*)&temp);
    L_8002C710:
    gc_env.r[3] = gc_env.r[1] + 52; // addi r3, r1, 0x34
    gc_env.r[4] = gc_env.r[30] + 0; // addi r4, r30, 0x0
    lbVector_Sub();
    gc_env.r[3] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x34);
    gc_env.r[28] = gc_env.r[31] + 800; // addi r28, r31, 0x320
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x38);
    gc_env.r[27] = gc_env.r[31] + 804; // addi r27, r31, 0x324
    gc_env.r[30] = gc_env.r[31] + 808; // addi r30, r31, 0x328
    gc_mem_write32(gc_env.ram, gc_env.r[29] + 0x0, gc_env.r[3]);
    gc_mem_write32(gc_env.ram, gc_env.r[29] + 0x4, gc_env.r[0]);
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x3c);
    gc_mem_write32(gc_env.ram, gc_env.r[29] + 0x8, gc_env.r[0]);
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[31] + 0x320); // lfs f1, 0x320(r31)
    gc_env.f[1] = *(float*)&temp;
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[31] + 0x324); // lfs f0, 0x324(r31)
    gc_env.f[0] = *(float*)&temp;
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[31] + 0x328); // lfs f3, 0x328(r31)
    gc_env.f[3] = *(float*)&temp;
    gc_env.f[2] = (float)gc_env.f[1] * (float)gc_env.f[1]; // fmuls f2, f1, f1
    gc_env.f[1] = (float)gc_env.f[0] * (float)gc_env.f[0]; // fmuls f1, f0, f0
    gc_env.f[0] = cm_804D7E14; // lfs f0, cm_804D7E14@sda21(r0)
    gc_env.f[3] = (float)gc_env.f[3] * (float)gc_env.f[3]; // fmuls f3, f3, f3
    gc_env.f[1] = (float)gc_env.f[2] + (float)gc_env.f[1]; // fadds f1, f2, f1
    gc_env.f[4] = (float)gc_env.f[3] + (float)gc_env.f[1]; // fadds f4, f3, f1
    gc_env.cr[0] = isnan(gc_env.f[4]) || isnan(gc_env.f[0]) ? 0x1 : (gc_env.f[4] < gc_env.f[0] ? 0x8 : (gc_env.f[4] > gc_env.f[0] ? 0x4 : 0x2)); // fcmpo cr0, f4, f0
    if (gc_env.cr[0] & (0x8 | 0x2)) goto L_8002C7B8; // ble .L_8002C7B8
    // Unknown opcode: frsqrte f1 f4
    gc_env.d[3] = cm_804D7E78; // lfd f3, cm_804D7E78@sda21(r0)
    gc_env.d[2] = cm_804D7E80; // lfd f2, cm_804D7E80@sda21(r0)
    // Unknown opcode: fmul f0 f1 f1
    // Unknown opcode: fmul f1 f3 f1
    // Unknown opcode: fnmsub f0 f4 f0 f2
    // Unknown opcode: fmul f1 f1 f0
    // Unknown opcode: fmul f0 f1 f1
    // Unknown opcode: fmul f1 f3 f1
    // Unknown opcode: fnmsub f0 f4 f0 f2
    // Unknown opcode: fmul f1 f1 f0
    // Unknown opcode: fmul f0 f1 f1
    // Unknown opcode: fmul f1 f3 f1
    // Unknown opcode: fnmsub f0 f4 f0 f2
    // Unknown opcode: fmul f0 f1 f0
    // Unknown opcode: fmul f0 f4 f0
    gc_env.f[0] = (float)gc_env.f[0]; // frsp f0, f0
    float temp = (float)gc_env.f[0]; // stfs f0, 0x10(r1)
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x10, *(uint32_t*)&temp);
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x10); // lfs f0, 0x10(r1)
    gc_env.f[0] = *(float*)&temp;
    L_8002C7B8:
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[28] + 0x0); // lfs f0, 0x0(r28)
    gc_env.f[0] = *(float*)&temp;
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[30] + 0x0); // lfs f1, 0x0(r30)
    gc_env.f[1] = *(float*)&temp;
    gc_env.f[2] = (float)gc_env.f[0] * (float)gc_env.f[0]; // fmuls f2, f0, f0
    gc_env.f[0] = cm_804D7E14; // lfs f0, cm_804D7E14@sda21(r0)
    gc_env.f[1] = (float)gc_env.f[1] * (float)gc_env.f[1]; // fmuls f1, f1, f1
    gc_env.f[4] = (float)gc_env.f[2] + (float)gc_env.f[1]; // fadds f4, f2, f1
    gc_env.cr[0] = isnan(gc_env.f[4]) || isnan(gc_env.f[0]) ? 0x1 : (gc_env.f[4] < gc_env.f[0] ? 0x8 : (gc_env.f[4] > gc_env.f[0] ? 0x4 : 0x2)); // fcmpo cr0, f4, f0
    if (gc_env.cr[0] & (0x8 | 0x2)) goto L_8002C824; // ble .L_8002C824
    // Unknown opcode: frsqrte f1 f4
    gc_env.d[3] = cm_804D7E78; // lfd f3, cm_804D7E78@sda21(r0)
    gc_env.d[2] = cm_804D7E80; // lfd f2, cm_804D7E80@sda21(r0)
    // Unknown opcode: fmul f0 f1 f1
    // Unknown opcode: fmul f1 f3 f1
    // Unknown opcode: fnmsub f0 f4 f0 f2
    // Unknown opcode: fmul f1 f1 f0
    // Unknown opcode: fmul f0 f1 f1
    // Unknown opcode: fmul f1 f3 f1
    // Unknown opcode: fnmsub f0 f4 f0 f2
    // Unknown opcode: fmul f1 f1 f0
    // Unknown opcode: fmul f0 f1 f1
    // Unknown opcode: fmul f1 f3 f1
    // Unknown opcode: fnmsub f0 f4 f0 f2
    // Unknown opcode: fmul f0 f1 f0
    // Unknown opcode: fmul f0 f4 f0
    gc_env.f[0] = (float)gc_env.f[0]; // frsp f0, f0
    float temp = (float)gc_env.f[0]; // stfs f0, 0x18(r1)
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x18, *(uint32_t*)&temp);
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x18); // lfs f4, 0x18(r1)
    gc_env.f[4] = *(float*)&temp;
    L_8002C824:
    gc_env.f[31] = gc_env.f[4]; // fmr f31, f4
    gc_env.r[3] = gc_env.r[28] + 0; // addi r3, r28, 0x0
    gc_env.r[4] = gc_env.r[31] + 820; // addi r4, r31, 0x334
    gc_env.r[5] = gc_env.r[1] + 40; // addi r5, r1, 0x28
    PSVECCrossProduct();
    gc_env.r[3] = gc_env.r[1] + 40; // addi r3, r1, 0x28
    lbVector_Normalize();
    gc_env.r[4] = gc_env.r[28] + 0; // addi r4, r28, 0x0
    gc_env.r[3] = gc_env.r[1] + 40; // addi r3, r1, 0x28
    gc_env.r[5] = gc_env.r[1] + 28; // addi r5, r1, 0x1c
    PSVECCrossProduct();
    gc_env.r[3] = gc_env.r[1] + 28; // addi r3, r1, 0x1c
    lbVector_Normalize();
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[27] + 0x0); // lfs f1, 0x0(r27)
    gc_env.f[1] = *(float*)&temp;
    gc_env.f[2] = gc_env.f[31]; // fmr f2, f31
    atan2f();
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[26] + 0x1C); // lfs f0, 0x1C(r26)
    gc_env.f[0] = *(float*)&temp;
    gc_env.cr[0] = isnan(gc_env.f[1]) || isnan(gc_env.f[0]) ? 0x1 : (gc_env.f[1] < gc_env.f[0] ? 0x8 : (gc_env.f[1] > gc_env.f[0] ? 0x4 : 0x2)); // fcmpo cr0, f1, f0
    if (gc_env.cr[0] & (0x8 | 0x2)) goto L_8002C884; // ble .L_8002C884
    gc_env.f[1] = (float)gc_env.f[0] - (float)gc_env.f[1]; // fsubs f1, f0, f1
    gc_env.r[3] = gc_env.r[28] + 0; // addi r3, r28, 0x0
    gc_env.r[4] = gc_env.r[1] + 40; // addi r4, r1, 0x28
    lbVector_RotateAboutUnitAxis();
    goto L_8002C8A4;
    L_8002C884:
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[26] + 0x18); // lfs f0, 0x18(r26)
    gc_env.f[0] = *(float*)&temp;
    gc_env.f[0] = -gc_env.f[0]; // fneg f0, f0
    gc_env.cr[0] = isnan(gc_env.f[1]) || isnan(gc_env.f[0]) ? 0x1 : (gc_env.f[1] < gc_env.f[0] ? 0x8 : (gc_env.f[1] > gc_env.f[0] ? 0x4 : 0x2)); // fcmpo cr0, f1, f0
    if (gc_env.cr[0] >= 0) goto L_8002C8A4;
    gc_env.f[1] = (float)gc_env.f[0] - (float)gc_env.f[1]; // fsubs f1, f0, f1
    gc_env.r[3] = gc_env.r[28] + 0; // addi r3, r28, 0x0
    gc_env.r[4] = gc_env.r[1] + 40; // addi r4, r1, 0x28
    lbVector_RotateAboutUnitAxis();
    L_8002C8A4:
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[28] + 0x0); // lfs f1, 0x0(r28)
    gc_env.f[1] = *(float*)&temp;
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[30] + 0x0); // lfs f2, 0x0(r30)
    gc_env.f[2] = *(float*)&temp;
    atan2f();
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[26] + 0x20); // lfs f0, 0x20(r26)
    gc_env.f[0] = *(float*)&temp;
    gc_env.cr[0] = isnan(gc_env.f[1]) || isnan(gc_env.f[0]) ? 0x1 : (gc_env.f[1] < gc_env.f[0] ? 0x8 : (gc_env.f[1] > gc_env.f[0] ? 0x4 : 0x2)); // fcmpo cr0, f1, f0
    if (gc_env.cr[0] & (0x8 | 0x2)) goto L_8002C8D0; // ble .L_8002C8D0
    gc_env.f[1] = (float)gc_env.f[0] - (float)gc_env.f[1]; // fsubs f1, f0, f1
    gc_env.r[3] = gc_env.r[28] + 0; // addi r3, r28, 0x0
    gc_env.r[4] = gc_env.r[1] + 28; // addi r4, r1, 0x1c
    lbVector_RotateAboutUnitAxis();
    goto L_8002C8F0;
    L_8002C8D0:
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[26] + 0x24); // lfs f0, 0x24(r26)
    gc_env.f[0] = *(float*)&temp;
    gc_env.f[0] = -gc_env.f[0]; // fneg f0, f0
    gc_env.cr[0] = isnan(gc_env.f[1]) || isnan(gc_env.f[0]) ? 0x1 : (gc_env.f[1] < gc_env.f[0] ? 0x8 : (gc_env.f[1] > gc_env.f[0] ? 0x4 : 0x2)); // fcmpo cr0, f1, f0
    if (gc_env.cr[0] >= 0) goto L_8002C8F0;
    gc_env.f[1] = (float)gc_env.f[0] - (float)gc_env.f[1]; // fsubs f1, f0, f1
    gc_env.r[3] = gc_env.r[28] + 0; // addi r3, r28, 0x0
    gc_env.r[4] = gc_env.r[1] + 28; // addi r4, r1, 0x1c
    lbVector_RotateAboutUnitAxis();
    L_8002C8F0:
    gc_env.r[26] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x48); // lmw r26, 0x48(r1)
    gc_env.r[27] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x4C); // lmw r26, 0x48(r1)
    gc_env.r[28] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x50); // lmw r26, 0x48(r1)
    gc_env.r[29] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x54); // lmw r26, 0x48(r1)
    gc_env.r[30] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x58); // lmw r26, 0x48(r1)
    gc_env.r[31] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x5C); // lmw r26, 0x48(r1)
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x6c);
    uint64_t temp = gc_mem_read64(gc_env.ram, gc_env.r[1] + 0x60); // lfd f31, 0x60(r1)
    gc_env.d[31] = *(double*)&temp;
    gc_env.r[1] += 104; // addi r1, r1, 0x68
    gc_env.lr = gc_env.r[0]; // Move to link register
    return;
}

// Function: Camera_8002C908
void Camera_8002C908(void) {
    gc_env.r[0] = gc_env.lr; // Move from link register
    gc_env.r[3] = ((uint32_t)&cm_80452C68 >> 16) & 0xFFFF; // lis r3, cm_80452C68@ha
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x4, gc_env.r[0]);
    gc_mem_write32(gc_env.ram, gc_env.r[1] + -0x70, gc_env.r[1]);
    gc_env.r[1] = gc_env.r[1] + -0x70;
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x58, gc_env.r[26]); // stmw r26, 0x58(r1)
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x5C, gc_env.r[27]); // stmw r26, 0x58(r1)
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x60, gc_env.r[28]); // stmw r26, 0x58(r1)
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x64, gc_env.r[29]); // stmw r26, 0x58(r1)
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x68, gc_env.r[30]); // stmw r26, 0x58(r1)
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x6C, gc_env.r[31]); // stmw r26, 0x58(r1)
    gc_env.r[31] = gc_env.r[3] + ((uint32_t)&cm_80452C68 & 0xFFFF); // addi r31, r3, cm_80452C68@l
    Camera_80030DF8();
    Camera_800293E0();
    gc_env.r[30] = gc_env.r[31] + 20; // addi r30, r31, 0x14
    gc_env.r[4] = gc_env.r[30] + 0; // addi r4, r30, 0x0
    gc_env.r[3] = gc_env.r[1] + 64; // addi r3, r1, 0x40
    Camera_8002958C();
    Camera_8002C1A8();
    gc_env.r[27] = gc_env.r[31] + 776; // addi r27, r31, 0x308
    gc_env.r[28] = gc_env.r[31] + 772; // addi r28, r31, 0x304
    goto L_8002C960;
    L_8002C948:
    gc_env.r[3] = gc_mem_read8(gc_env.ram, gc_env.r[28] + 0x0);
    gc_env.r[4] = 0x1;
    // Unknown opcode: extsb r3 r3
    Camera_8002BA00();
    // Unknown opcode: extsb r0 r3
    gc_mem_write8(gc_env.ram, gc_env.r[28] + 0x0, gc_env.r[0]);
    L_8002C960:
    gc_env.r[3] = gc_mem_read8(gc_env.ram, gc_env.r[28] + 0x0);
    gc_env.r[29] = 0x1;
    // Unknown opcode: extsb r3 r3
    gc_env.cr[0] = (gc_env.r[3] == 0xb) ? 0 : (gc_env.r[3] < 0xb ? -1 : 1); // Compare with immediate
    if (gc_env.cr[0] != 0) goto L_8002C97C;
    gc_env.r[29] = 0x0;
    goto L_8002C9C8;
    L_8002C97C:
    gc_env.cr[0] = (gc_env.r[3] == 0xa) ? 0 : (gc_env.r[3] < 0xa ? -1 : 1); // Compare with immediate
    if (gc_env.cr[0] != 0) goto L_8002C990;
    gc_env.r[3] = gc_env.r[27]; // Move register
    Stage_UnkSetVec3TCam_Offset();
    goto L_8002C9C8;
    L_8002C990:
    Player_GetEntity();
    gc_env.cr[0] = ((uint32_t)gc_env.r[3] == 0x0) ? 0 : ((uint32_t)gc_env.r[3] < 0x0 ? -1 : 1); // Logical compare with immediate
    if (gc_env.cr[0] == 0) goto L_8002C9C4;
    ftLib_80086B74();
    gc_env.cr[0] = ((uint32_t)gc_env.r[3] == 0x0) ? 0 : ((uint32_t)gc_env.r[3] < 0x0 ? -1 : 1); // Logical compare with immediate
    if (gc_env.cr[0] == 0) goto L_8002C9C4;
    gc_env.r[4] = gc_mem_read32(gc_env.ram, gc_env.r[3] + 0x1c);
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[3] + 0x20);
    gc_mem_write32(gc_env.ram, gc_env.r[27] + 0x0, gc_env.r[4]);
    gc_mem_write32(gc_env.ram, gc_env.r[27] + 0x4, gc_env.r[0]);
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[3] + 0x24);
    gc_mem_write32(gc_env.ram, gc_env.r[27] + 0x8, gc_env.r[0]);
    goto L_8002C9C8;
    L_8002C9C4:
    gc_env.r[29] = 0x0;
    L_8002C9C8:
    gc_env.cr[0] = (gc_env.r[29] == 0x0) ? 0 : (gc_env.r[29] < 0x0 ? -1 : 1); // Compare with immediate
    if (gc_env.cr[0] == 0) goto L_8002C948;
    gc_env.r[3] = gc_env.r[31] + 720; // addi r3, r31, 0x2d0
    Camera_8002C5B4();
    gc_env.r[4] = gc_mem_read32(gc_env.ram, gc_env.r[27] + 0x0);
    gc_env.r[26] = gc_env.r[30] + 12; // addi r26, r30, 0xc
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[27] + 0x4);
    gc_env.r[28] = gc_env.r[31] + 32; // addi r28, r31, 0x20
    gc_env.r[3] = gc_env.r[26] + 0; // addi r3, r26, 0x0
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x20, gc_env.r[4]);
    gc_env.r[4] = gc_env.r[31] + 788; // addi r4, r31, 0x314
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x24, gc_env.r[0]);
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[27] + 0x8);
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x28, gc_env.r[0]);
    lbVector_Add();
    gc_env.r[5] = gc_mem_read32(gc_env.ram, gc_env.r[28] + 0x0);
    gc_env.r[27] = gc_env.r[30] + 36; // addi r27, r30, 0x24
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[28] + 0x4);
    gc_env.r[3] = gc_env.r[27] + 0; // addi r3, r27, 0x0
    gc_env.r[4] = gc_env.r[31] + 800; // addi r4, r31, 0x320
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x38, gc_env.r[5]);
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x3c, gc_env.r[0]);
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[28] + 0x8);
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x40, gc_env.r[0]);
    lbVector_Add();
    gc_env.r[28] = gc_env.r[30] + 24; // addi r28, r30, 0x18
    gc_env.r[3] = gc_env.r[27] + 0; // addi r3, r27, 0x0
    gc_env.r[4] = gc_env.r[28] + 0; // addi r4, r28, 0x0
    gc_env.r[5] = gc_env.r[1] + 28; // addi r5, r1, 0x1c
    lbVector_Diff();
    gc_env.r[3] = ((uint32_t)&cm_803BCCA0 >> 16) & 0xFFFF; // lis r3, cm_803BCCA0@ha
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x1C); // lfs f0, 0x1C(r1)
    gc_env.f[0] = *(float*)&temp;
    gc_env.r[29] = gc_env.r[3] + ((uint32_t)&cm_803BCCA0 & 0xFFFF); // addi r29, r3, cm_803BCCA0@l
    gc_env.r[27] = gc_env.r[29] + 132; // addi r27, r29, 0x84
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[29] + 0x84); // lfs f1, 0x84(r29)
    gc_env.f[1] = *(float*)&temp;
    gc_env.r[3] = gc_env.r[28] + 0; // addi r3, r28, 0x0
    gc_env.r[4] = gc_env.r[1] + 28; // addi r4, r1, 0x1c
    gc_env.f[0] = (float)gc_env.f[0] * (float)gc_env.f[1]; // fmuls f0, f0, f1
    float temp = (float)gc_env.f[0]; // stfs f0, 0x1C(r1)
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x1C, *(uint32_t*)&temp);
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x20); // lfs f0, 0x20(r1)
    gc_env.f[0] = *(float*)&temp;
    gc_env.f[0] = (float)gc_env.f[0] * (float)gc_env.f[1]; // fmuls f0, f0, f1
    float temp = (float)gc_env.f[0]; // stfs f0, 0x20(r1)
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x20, *(uint32_t*)&temp);
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x24); // lfs f0, 0x24(r1)
    gc_env.f[0] = *(float*)&temp;
    gc_env.f[0] = (float)gc_env.f[0] * (float)gc_env.f[1]; // fmuls f0, f0, f1
    float temp = (float)gc_env.f[0]; // stfs f0, 0x24(r1)
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x24, *(uint32_t*)&temp);
    lbVector_Add();
    gc_env.r[3] = gc_env.r[26] + 0; // addi r3, r26, 0x0
    gc_env.r[4] = gc_env.r[30] + 0; // addi r4, r30, 0x0
    gc_env.r[5] = gc_env.r[1] + 16; // addi r5, r1, 0x10
    lbVector_Diff();
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[27] + 0x0); // lfs f1, 0x0(r27)
    gc_env.f[1] = *(float*)&temp;
    gc_env.r[3] = gc_env.r[30]; // Move register
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x10); // lfs f0, 0x10(r1)
    gc_env.f[0] = *(float*)&temp;
    gc_env.r[4] = gc_env.r[1] + 16; // addi r4, r1, 0x10
    gc_env.f[0] = (float)gc_env.f[0] * (float)gc_env.f[1]; // fmuls f0, f0, f1
    float temp = (float)gc_env.f[0]; // stfs f0, 0x10(r1)
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x10, *(uint32_t*)&temp);
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x14); // lfs f0, 0x14(r1)
    gc_env.f[0] = *(float*)&temp;
    gc_env.f[0] = (float)gc_env.f[0] * (float)gc_env.f[1]; // fmuls f0, f0, f1
    float temp = (float)gc_env.f[0]; // stfs f0, 0x14(r1)
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x14, *(uint32_t*)&temp);
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x18); // lfs f0, 0x18(r1)
    gc_env.f[0] = *(float*)&temp;
    gc_env.f[0] = (float)gc_env.f[0] * (float)gc_env.f[1]; // fmuls f0, f0, f1
    float temp = (float)gc_env.f[0]; // stfs f0, 0x18(r1)
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x18, *(uint32_t*)&temp);
    lbVector_Add();
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[31] + 0x32C); // lfs f0, 0x32C(r31)
    gc_env.f[0] = *(float*)&temp;
    gc_env.r[3] = gc_env.r[1] + 64; // addi r3, r1, 0x40
    float temp = (float)gc_env.f[0]; // stfs f0, 0x48(r31)
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x48, *(uint32_t*)&temp);
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[31] + 0x48); // lfs f1, 0x48(r31)
    gc_env.f[1] = *(float*)&temp;
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[31] + 0x44); // lfs f2, 0x44(r31)
    gc_env.f[2] = *(float*)&temp;
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[29] + 0x88); // lfs f0, 0x88(r29)
    gc_env.f[0] = *(float*)&temp;
    gc_env.f[1] = (float)gc_env.f[1] - (float)gc_env.f[2]; // fsubs f1, f1, f2
    gc_env.f[0] = (float)gc_env.f[1] * (float)gc_env.f[0] + (float)gc_env.f[2]; // fmadds f0, f1, f0, f2
    float temp = (float)gc_env.f[0]; // stfs f0, 0x44(r31)
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x44, *(uint32_t*)&temp);
    Camera_8002A28C();
    gc_env.r[3] = gc_env.r[1] + 64; // addi r3, r1, 0x40
    gc_env.r[4] = gc_env.r[30] + 0; // addi r4, r30, 0x0
    Camera_8002A0C0();
    gc_env.r[26] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x58); // lmw r26, 0x58(r1)
    gc_env.r[27] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x5C); // lmw r26, 0x58(r1)
    gc_env.r[28] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x60); // lmw r26, 0x58(r1)
    gc_env.r[29] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x64); // lmw r26, 0x58(r1)
    gc_env.r[30] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x68); // lmw r26, 0x58(r1)
    gc_env.r[31] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x6C); // lmw r26, 0x58(r1)
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x74);
    gc_env.r[1] += 112; // addi r1, r1, 0x70
    gc_env.lr = gc_env.r[0]; // Move to link register
    return;
}

// Function: Camera_8002CB0C
void Camera_8002CB0C(void) {
    gc_env.r[0] = gc_env.lr; // Move from link register
    gc_env.r[3] = ((uint32_t)&cm_80452C68 >> 16) & 0xFFFF; // lis r3, cm_80452C68@ha
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x4, gc_env.r[0]);
    gc_mem_write32(gc_env.ram, gc_env.r[1] + -0x68, gc_env.r[1]);
    gc_env.r[1] = gc_env.r[1] + -0x68;
    uint64_t temp;
    memcpy(&temp, &gc_env.f[31], sizeof(double));
    gc_mem_write64(gc_env.ram, gc_env.r[1] + 0x60, temp); // stfd f31, 0x60(r1)
    uint64_t temp;
    memcpy(&temp, &gc_env.f[30], sizeof(double));
    gc_mem_write64(gc_env.ram, gc_env.r[1] + 0x58, temp); // stfd f30, 0x58(r1)
    uint64_t temp;
    memcpy(&temp, &gc_env.f[29], sizeof(double));
    gc_mem_write64(gc_env.ram, gc_env.r[1] + 0x50, temp); // stfd f29, 0x50(r1)
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x3C, gc_env.r[27]); // stmw r27, 0x3C(r1)
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x40, gc_env.r[28]); // stmw r27, 0x3C(r1)
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x44, gc_env.r[29]); // stmw r27, 0x3C(r1)
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x48, gc_env.r[30]); // stmw r27, 0x3C(r1)
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x4C, gc_env.r[31]); // stmw r27, 0x3C(r1)
    gc_env.r[31] = gc_env.r[3] + ((uint32_t)&cm_80452C68 & 0xFFFF); // addi r31, r3, cm_80452C68@l
    gc_env.r[0] = gc_mem_read8(gc_env.ram, gc_env.r[31] + 0x2c5);
    // Unknown opcode: extsb r4 r0
    gc_env.cr[0] = (gc_env.r[4] == 0x5) ? 0 : (gc_env.r[4] < 0x5 ? -1 : 1); // Compare with immediate
    if (gc_env.cr[0] == 0) goto L_8002CDBC;
    gc_env.r[3] = gc_env.r[1] + 24; // addi r3, r1, 0x18
    Camera_8002B694();
    gc_env.f[30] = cm_804D7E14; // lfs f30, cm_804D7E14@sda21(r0)
    gc_env.r[0] = 0x20;
    gc_env.r[6] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x34);
    gc_env.r[5] = 0x0;
    gc_env.r[3] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x30);
    gc_env.f[31] = gc_env.f[30]; // fmr f31, f30
    gc_env.r[0] = gc_env.r[6] & gc_env.r[0];
    gc_env.r[4] = gc_env.r[3] & gc_env.r[5];
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x18); // lfs f2, 0x18(r1)
    gc_env.f[2] = *(float*)&temp;
    // Unknown opcode: xor r3 r0 r5
    // Unknown opcode: xor r0 r4 r5
    gc_env.f[29] = gc_env.f[31]; // fmr f29, f31
    gc_env.r[0] = gc_env.r[3] | gc_env.r[0]; // or r0, r3, r0
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x1C); // lfs f3, 0x1C(r1)
    gc_env.f[3] = *(float*)&temp;
    gc_env.r[7] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x28);
    gc_env.r[30] = 0x0;
    gc_env.r[8] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x2c);
    if (gc_env.cr[0] == 0) goto L_8002CB98;
    gc_env.r[30] = 0x1;
    goto L_8002CBB4;
    L_8002CB98:
    gc_env.r[0] = 0x40;
    gc_env.r[0] = gc_env.r[6] & gc_env.r[0];
    // Unknown opcode: xor r3 r0 r5
    // Unknown opcode: xor r0 r4 r5
    gc_env.r[0] = gc_env.r[3] | gc_env.r[0]; // or r0, r3, r0
    if (gc_env.cr[0] == 0) goto L_8002CBB4;
    gc_env.r[30] = -0x1;
    L_8002CBB4:
    gc_env.r[0] = 0x400;
    gc_env.r[5] = 0x0;
    gc_env.r[0] = gc_env.r[8] & gc_env.r[0];
    gc_env.r[4] = gc_env.r[7] & gc_env.r[5];
    // Unknown opcode: xor r3 r0 r5
    // Unknown opcode: xor r0 r4 r5
    gc_env.r[0] = gc_env.r[3] | gc_env.r[0]; // or r0, r3, r0
    if (gc_env.cr[0] == 0) goto L_8002CBDC;
    gc_env.f[29] = cm_804D7E04; // lfs f29, cm_804D7E04@sda21(r0)
    goto L_8002CBF8;
    L_8002CBDC:
    gc_env.r[0] = 0x800;
    gc_env.r[0] = gc_env.r[8] & gc_env.r[0];
    // Unknown opcode: xor r3 r0 r5
    // Unknown opcode: xor r0 r4 r5
    gc_env.r[0] = gc_env.r[3] | gc_env.r[0]; // or r0, r3, r0
    if (gc_env.cr[0] == 0) goto L_8002CBF8;
    gc_env.f[29] = cm_804D7E10; // lfs f29, cm_804D7E10@sda21(r0)
    L_8002CBF8:
    gc_env.f[0] = cm_804D7E14; // lfs f0, cm_804D7E14@sda21(r0)
    gc_env.cr[0] = isnan(gc_env.f[2]) || isnan(gc_env.f[0]) ? 0x1 : (gc_env.f[2] < gc_env.f[0] ? 0x8 : (gc_env.f[2] > gc_env.f[0] ? 0x4 : 0x2)); // fcmpo cr0, f2, f0
    if (gc_env.cr[0] >= 0) goto L_8002CC0C;
    gc_env.f[1] = -gc_env.f[2]; // fneg f1, f2
    goto L_8002CC10;
    L_8002CC0C:
    gc_env.f[1] = gc_env.f[2]; // fmr f1, f2
    L_8002CC10:
    gc_env.d[0] = cm_804D7EA0; // lfd f0, cm_804D7EA0@sda21(r0)
    gc_env.cr[0] = isnan(gc_env.f[1]) || isnan(gc_env.f[0]) ? 0x1 : (gc_env.f[1] < gc_env.f[0] ? 0x8 : (gc_env.f[1] > gc_env.f[0] ? 0x4 : 0x2)); // fcmpo cr0, f1, f0
    if (gc_env.cr[0] & (0x8 | 0x2)) goto L_8002CC20; // ble .L_8002CC20
    gc_env.f[31] = gc_env.f[2]; // fmr f31, f2
    L_8002CC20:
    gc_env.f[0] = cm_804D7E14; // lfs f0, cm_804D7E14@sda21(r0)
    gc_env.cr[0] = isnan(gc_env.f[3]) || isnan(gc_env.f[0]) ? 0x1 : (gc_env.f[3] < gc_env.f[0] ? 0x8 : (gc_env.f[3] > gc_env.f[0] ? 0x4 : 0x2)); // fcmpo cr0, f3, f0
    if (gc_env.cr[0] >= 0) goto L_8002CC34;
    gc_env.f[1] = -gc_env.f[3]; // fneg f1, f3
    goto L_8002CC38;
    L_8002CC34:
    gc_env.f[1] = gc_env.f[3]; // fmr f1, f3
    L_8002CC38:
    gc_env.d[0] = cm_804D7EA0; // lfd f0, cm_804D7EA0@sda21(r0)
    gc_env.cr[0] = isnan(gc_env.f[1]) || isnan(gc_env.f[0]) ? 0x1 : (gc_env.f[1] < gc_env.f[0] ? 0x8 : (gc_env.f[1] > gc_env.f[0] ? 0x4 : 0x2)); // fcmpo cr0, f1, f0
    if (gc_env.cr[0] & (0x8 | 0x2)) goto L_8002CC48; // ble .L_8002CC48
    gc_env.f[30] = gc_env.f[3]; // fmr f30, f3
    L_8002CC48:
    gc_env.cr[0] = (gc_env.r[30] == 0x0) ? 0 : (gc_env.r[30] < 0x0 ? -1 : 1); // Compare with immediate
    if (gc_env.cr[0] == 0) goto L_8002CD88;
    gc_env.r[28] = gc_env.r[31] + 708; // addi r28, r31, 0x2c4
    gc_env.r[3] = gc_mem_read8(gc_env.ram, gc_env.r[31] + 0x2c4);
    gc_env.r[4] = gc_env.r[30] + 0; // addi r4, r30, 0x0
    // Unknown opcode: extsb r3 r3
    Camera_8002BA00();
    // Unknown opcode: extsb r0 r3
    gc_mem_write8(gc_env.ram, gc_env.r[28] + 0x0, gc_env.r[0]);
    gc_env.r[27] = gc_env.r[31] + 776; // addi r27, r31, 0x308
    goto L_8002CC8C;
    L_8002CC74:
    gc_env.r[3] = gc_mem_read8(gc_env.ram, gc_env.r[28] + 0x0);
    gc_env.r[4] = gc_env.r[30] + 0; // addi r4, r30, 0x0
    // Unknown opcode: extsb r3 r3
    Camera_8002BA00();
    // Unknown opcode: extsb r0 r3
    gc_mem_write8(gc_env.ram, gc_env.r[28] + 0x0, gc_env.r[0]);
    L_8002CC8C:
    gc_env.r[0] = gc_mem_read8(gc_env.ram, gc_env.r[28] + 0x0);
    // Unknown opcode: extsb r3 r0
    gc_env.cr[0] = (gc_env.r[3] == 0xa) ? 0 : (gc_env.r[3] < 0xa ? -1 : 1); // Compare with immediate
    if (gc_env.cr[0] == 0) goto L_8002CC74;
    gc_env.cr[0] = (gc_env.r[3] == 0xb) ? 0 : (gc_env.r[3] < 0xb ? -1 : 1); // Compare with immediate
    gc_env.r[29] = 0x1;
    if (gc_env.cr[0] != 0) goto L_8002CCB0;
    gc_env.r[29] = 0x0;
    goto L_8002CCFC;
    L_8002CCB0:
    gc_env.cr[0] = (gc_env.r[3] == 0xa) ? 0 : (gc_env.r[3] < 0xa ? -1 : 1); // Compare with immediate
    if (gc_env.cr[0] != 0) goto L_8002CCC4;
    gc_env.r[3] = gc_env.r[27]; // Move register
    Stage_UnkSetVec3TCam_Offset();
    goto L_8002CCFC;
    L_8002CCC4:
    Player_GetEntity();
    gc_env.cr[0] = ((uint32_t)gc_env.r[3] == 0x0) ? 0 : ((uint32_t)gc_env.r[3] < 0x0 ? -1 : 1); // Logical compare with immediate
    if (gc_env.cr[0] == 0) goto L_8002CCF8;
    ftLib_80086B74();
    gc_env.cr[0] = ((uint32_t)gc_env.r[3] == 0x0) ? 0 : ((uint32_t)gc_env.r[3] < 0x0 ? -1 : 1); // Logical compare with immediate
    if (gc_env.cr[0] == 0) goto L_8002CCF8;
    gc_env.r[4] = gc_mem_read32(gc_env.ram, gc_env.r[3] + 0x1c);
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[3] + 0x20);
    gc_mem_write32(gc_env.ram, gc_env.r[27] + 0x0, gc_env.r[4]);
    gc_mem_write32(gc_env.ram, gc_env.r[27] + 0x4, gc_env.r[0]);
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[3] + 0x24);
    gc_mem_write32(gc_env.ram, gc_env.r[27] + 0x8, gc_env.r[0]);
    goto L_8002CCFC;
    L_8002CCF8:
    gc_env.r[29] = 0x0;
    L_8002CCFC:
    gc_env.cr[0] = (gc_env.r[29] == 0x0) ? 0 : (gc_env.r[29] < 0x0 ? -1 : 1); // Compare with immediate
    if (gc_env.cr[0] == 0) goto L_8002CC74;
    gc_env.r[3] = gc_mem_read8(gc_env.ram, gc_env.r[28] + 0x0);
    // Unknown opcode: extsb r3 r3
    Player_GetEntity();
    gc_env.cr[0] = ((uint32_t)gc_env.r[3] == 0x0) ? 0 : ((uint32_t)gc_env.r[3] < 0x0 ? -1 : 1); // Logical compare with immediate
    if (gc_env.cr[0] == 0) goto L_8002CC74;
    ftLib_8008701C();
    gc_env.cr[0] = (gc_env.r[3] == 0x0) ? 0 : (gc_env.r[3] < 0x0 ? -1 : 1); // Compare with immediate
    if (gc_env.cr[0] != 0) goto L_8002CC74;
    gc_env.r[29] = gc_mem_read8(gc_env.ram, gc_env.r[28] + 0x0);
    // Unknown opcode: extsb r29 r29
    Stage_GetPauseCamZPosInit();
    gc_env.f[2] = cm_804D7E14; // lfs f2, cm_804D7E14@sda21(r0)
    gc_env.cr[0] = (gc_env.r[29] == 0xa) ? 0 : (gc_env.r[29] < 0xa ? -1 : 1); // Compare with immediate
    float temp = (float)gc_env.f[2]; // stfs f2, 0x31C(r31)
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x31C, *(uint32_t*)&temp);
    float temp = (float)gc_env.f[2]; // stfs f2, 0x318(r31)
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x318, *(uint32_t*)&temp);
    float temp = (float)gc_env.f[2]; // stfs f2, 0x314(r31)
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x314, *(uint32_t*)&temp);
    float temp = (float)gc_env.f[2]; // stfs f2, 0x320(r31)
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x320, *(uint32_t*)&temp);
    gc_env.f[0] = cm_804D7E90; // lfs f0, cm_804D7E90@sda21(r0)
    float temp = (float)gc_env.f[0]; // stfs f0, 0x324(r31)
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x324, *(uint32_t*)&temp);
    gc_env.f[0] = cm_804D7E94; // lfs f0, cm_804D7E94@sda21(r0)
    float temp = (float)gc_env.f[0]; // stfs f0, 0x328(r31)
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x328, *(uint32_t*)&temp);
    float temp = (float)gc_env.f[2]; // stfs f2, 0x334(r31)
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x334, *(uint32_t*)&temp);
    gc_env.f[0] = cm_804D7E04; // lfs f0, cm_804D7E04@sda21(r0)
    float temp = (float)gc_env.f[0]; // stfs f0, 0x338(r31)
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x338, *(uint32_t*)&temp);
    float temp = (float)gc_env.f[2]; // stfs f2, 0x33C(r31)
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x33C, *(uint32_t*)&temp);
    if (gc_env.cr[0] != 0) goto L_8002CD7C;
    gc_env.f[0] = cm_804D7E98; // lfs f0, cm_804D7E98@sda21(r0)
    gc_env.f[0] = (float)gc_env.f[0] * (float)gc_env.f[1]; // fmuls f0, f0, f1
    float temp = (float)gc_env.f[0]; // stfs f0, 0x330(r31)
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x330, *(uint32_t*)&temp);
    goto L_8002CD80;
    L_8002CD7C:
    float temp = (float)gc_env.f[1]; // stfs f1, 0x330(r31)
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x330, *(uint32_t*)&temp);
    L_8002CD80:
    gc_env.f[1] = cm_804D7E14; // lfs f1, cm_804D7E14@sda21(r0)
    Camera_8002BAA8();
    L_8002CD88:
    gc_env.f[0] = cm_804D7E14; // lfs f0, cm_804D7E14@sda21(r0)
    gc_env.cr[0] = isnan(gc_env.f[0]) || isnan(gc_env.f[29]) ? 0x1 : (gc_env.f[0] < gc_env.f[29] ? 0x8 : (gc_env.f[0] > gc_env.f[29] ? 0x4 : 0x2)); // fcmpu cr0, f0, f29
    if (gc_env.cr[0] == 0) goto L_8002CD9C;
    gc_env.f[1] = gc_env.f[29]; // fmr f1, f29
    Camera_8002BAA8();
    L_8002CD9C:
    gc_env.f[0] = cm_804D7E14; // lfs f0, cm_804D7E14@sda21(r0)
    gc_env.cr[0] = isnan(gc_env.f[0]) || isnan(gc_env.f[31]) ? 0x1 : (gc_env.f[0] < gc_env.f[31] ? 0x8 : (gc_env.f[0] > gc_env.f[31] ? 0x4 : 0x2)); // fcmpu cr0, f0, f31
    if (gc_env.cr[0] != 0) goto L_8002CDB0;
    gc_env.cr[0] = isnan(gc_env.f[0]) || isnan(gc_env.f[30]) ? 0x1 : (gc_env.f[0] < gc_env.f[30] ? 0x8 : (gc_env.f[0] > gc_env.f[30] ? 0x4 : 0x2)); // fcmpu cr0, f0, f30
    if (gc_env.cr[0] == 0) goto L_8002CDBC;
    L_8002CDB0:
    gc_env.f[1] = gc_env.f[31]; // fmr f1, f31
    gc_env.f[2] = gc_env.f[30]; // fmr f2, f30
    Camera_8002BD88();
    L_8002CDBC:
    gc_env.r[27] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x3C); // lmw r27, 0x3C(r1)
    gc_env.r[28] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x40); // lmw r27, 0x3C(r1)
    gc_env.r[29] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x44); // lmw r27, 0x3C(r1)
    gc_env.r[30] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x48); // lmw r27, 0x3C(r1)
    gc_env.r[31] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x4C); // lmw r27, 0x3C(r1)
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x6c);
    uint64_t temp = gc_mem_read64(gc_env.ram, gc_env.r[1] + 0x60); // lfd f31, 0x60(r1)
    gc_env.d[31] = *(double*)&temp;
    uint64_t temp = gc_mem_read64(gc_env.ram, gc_env.r[1] + 0x58); // lfd f30, 0x58(r1)
    gc_env.d[30] = *(double*)&temp;
    uint64_t temp = gc_mem_read64(gc_env.ram, gc_env.r[1] + 0x50); // lfd f29, 0x50(r1)
    gc_env.d[29] = *(double*)&temp;
    gc_env.r[1] += 104; // addi r1, r1, 0x68
    gc_env.lr = gc_env.r[0]; // Move to link register
    return;
}

// Function: Camera_8002CDDC
void Camera_8002CDDC(void) {
    gc_env.r[0] = gc_env.lr; // Move from link register
    gc_env.r[3] = ((uint32_t)&cm_80452C68 >> 16) & 0xFFFF; // lis r3, cm_80452C68@ha
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x4, gc_env.r[0]);
    gc_mem_write32(gc_env.ram, gc_env.r[1] + -0xb8, gc_env.r[1]);
    gc_env.r[1] = gc_env.r[1] + -0xb8;
    uint64_t temp;
    memcpy(&temp, &gc_env.f[31], sizeof(double));
    gc_mem_write64(gc_env.ram, gc_env.r[1] + 0xB0, temp); // stfd f31, 0xB0(r1)
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x98, gc_env.r[26]); // stmw r26, 0x98(r1)
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x9C, gc_env.r[27]); // stmw r26, 0x98(r1)
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0xA0, gc_env.r[28]); // stmw r26, 0x98(r1)
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0xA4, gc_env.r[29]); // stmw r26, 0x98(r1)
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0xA8, gc_env.r[30]); // stmw r26, 0x98(r1)
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0xAC, gc_env.r[31]); // stmw r26, 0x98(r1)
    gc_env.r[31] = gc_env.r[3] + ((uint32_t)&cm_80452C68 & 0xFFFF); // addi r31, r3, cm_80452C68@l
    Camera_80030DF8();
    Camera_800293E0();
    gc_env.r[30] = gc_env.r[31] + 20; // addi r30, r31, 0x14
    gc_env.r[4] = gc_env.r[30] + 0; // addi r4, r30, 0x0
    gc_env.r[3] = gc_env.r[1] + 120; // addi r3, r1, 0x78
    Camera_8002958C();
    gc_env.r[0] = gc_mem_read8(gc_env.ram, gc_env.r[31] + 0x2c4);
    gc_env.r[29] = gc_env.r[31] + 708; // addi r29, r31, 0x2c4
    gc_env.cr[0] = (gc_env.r[0] == 0xb) ? 0 : (gc_env.r[0] < 0xb ? -1 : 1); // Compare with immediate
    if (gc_env.cr[0] == 0) goto L_8002CED8;
    gc_env.r[27] = gc_env.r[31] + 776; // addi r27, r31, 0x308
    goto L_8002CE40;
    L_8002CE28:
    gc_env.r[3] = gc_mem_read8(gc_env.ram, gc_env.r[29] + 0x0);
    gc_env.r[4] = 0x1;
    // Unknown opcode: extsb r3 r3
    Camera_8002BA00();
    // Unknown opcode: extsb r0 r3
    gc_mem_write8(gc_env.ram, gc_env.r[29] + 0x0, gc_env.r[0]);
    L_8002CE40:
    gc_env.r[0] = gc_mem_read8(gc_env.ram, gc_env.r[29] + 0x0);
    // Unknown opcode: extsb r3 r0
    gc_env.cr[0] = (gc_env.r[3] == 0xa) ? 0 : (gc_env.r[3] < 0xa ? -1 : 1); // Compare with immediate
    if (gc_env.cr[0] == 0) goto L_8002CE28;
    gc_env.cr[0] = (gc_env.r[3] == 0xb) ? 0 : (gc_env.r[3] < 0xb ? -1 : 1); // Compare with immediate
    gc_env.r[28] = 0x1;
    if (gc_env.cr[0] != 0) goto L_8002CE64;
    gc_env.r[28] = 0x0;
    goto L_8002CEB0;
    L_8002CE64:
    gc_env.cr[0] = (gc_env.r[3] == 0xa) ? 0 : (gc_env.r[3] < 0xa ? -1 : 1); // Compare with immediate
    if (gc_env.cr[0] != 0) goto L_8002CE78;
    gc_env.r[3] = gc_env.r[27]; // Move register
    Stage_UnkSetVec3TCam_Offset();
    goto L_8002CEB0;
    L_8002CE78:
    Player_GetEntity();
    gc_env.cr[0] = ((uint32_t)gc_env.r[3] == 0x0) ? 0 : ((uint32_t)gc_env.r[3] < 0x0 ? -1 : 1); // Logical compare with immediate
    if (gc_env.cr[0] == 0) goto L_8002CEAC;
    ftLib_80086B74();
    gc_env.cr[0] = ((uint32_t)gc_env.r[3] == 0x0) ? 0 : ((uint32_t)gc_env.r[3] < 0x0 ? -1 : 1); // Logical compare with immediate
    if (gc_env.cr[0] == 0) goto L_8002CEAC;
    gc_env.r[4] = gc_mem_read32(gc_env.ram, gc_env.r[3] + 0x1c);
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[3] + 0x20);
    gc_mem_write32(gc_env.ram, gc_env.r[27] + 0x0, gc_env.r[4]);
    gc_mem_write32(gc_env.ram, gc_env.r[27] + 0x4, gc_env.r[0]);
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[3] + 0x24);
    gc_mem_write32(gc_env.ram, gc_env.r[27] + 0x8, gc_env.r[0]);
    goto L_8002CEB0;
    L_8002CEAC:
    gc_env.r[28] = 0x0;
    L_8002CEB0:
    gc_env.cr[0] = (gc_env.r[28] == 0x0) ? 0 : (gc_env.r[28] < 0x0 ? -1 : 1); // Compare with immediate
    if (gc_env.cr[0] == 0) goto L_8002CE28;
    gc_env.r[3] = gc_mem_read8(gc_env.ram, gc_env.r[29] + 0x0);
    // Unknown opcode: extsb r3 r3
    Player_GetEntity();
    gc_env.cr[0] = ((uint32_t)gc_env.r[3] == 0x0) ? 0 : ((uint32_t)gc_env.r[3] < 0x0 ? -1 : 1); // Logical compare with immediate
    if (gc_env.cr[0] == 0) goto L_8002CE28;
    ftLib_8008701C();
    gc_env.cr[0] = (gc_env.r[3] == 0x0) ? 0 : (gc_env.r[3] < 0x0 ? -1 : 1); // Compare with immediate
    if (gc_env.cr[0] != 0) goto L_8002CE28;
    L_8002CED8:
    gc_env.r[3] = gc_env.r[1] + 120; // addi r3, r1, 0x78
    Camera_8002CB0C();
    gc_env.r[0] = gc_mem_read8(gc_env.ram, gc_env.r[29] + 0x0);
    // Unknown opcode: extsb r3 r0
    gc_env.cr[0] = (gc_env.r[3] == 0xa) ? 0 : (gc_env.r[3] < 0xa ? -1 : 1); // Compare with immediate
    if (gc_env.cr[0] == 0) goto L_8002D078;
    gc_env.cr[0] = (gc_env.r[3] == 0xb) ? 0 : (gc_env.r[3] < 0xb ? -1 : 1); // Compare with immediate
    if (gc_env.cr[0] == 0) goto L_8002D078;
    Player_GetEntity();
    gc_env.cr[0] = ((uint32_t)gc_env.r[3] == 0x0) ? 0 : ((uint32_t)gc_env.r[3] < 0x0 ? -1 : 1); // Logical compare with immediate
    if (gc_env.cr[0] == 0) goto L_8002D078;
    ftLib_80086B74();
    gc_env.r[26] = gc_env.r[3]; // Move register
    if (gc_env.cr[0] == 0) goto L_8002D078;
    gc_env.r[3] = gc_env.r[26]; // Move register
    Camera_8002928C();
    gc_env.cr[0] = (gc_env.r[3] == 0x0) ? 0 : (gc_env.r[3] < 0x0 ? -1 : 1); // Compare with immediate
    if (gc_env.cr[0] == 0) goto L_8002D078;
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[26] + 0x8);
    gc_env.cr[0] = (gc_env.r[0] == 0x0) ? 0 : (gc_env.r[0] < 0x0 ? -1 : 1); // Compare with immediate
    if (gc_env.cr[0] != 0) goto L_8002D078;
    gc_env.r[3] = gc_env.r[26] + 28; // addi r3, r26, 0x1c
    gc_env.r[4] = 0x0;
    Camera_80029124();
    gc_env.cr[0] = ((uint32_t)gc_env.r[3] == 0x0) ? 0 : ((uint32_t)gc_env.r[3] < 0x0 ? -1 : 1); // Logical compare with immediate
    if (gc_env.cr[0] != 0) goto L_8002D078;
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[26] + 0x24); // lfs f1, 0x24(r26)
    gc_env.f[1] = *(float*)&temp;
    gc_env.f[0] = cm_804D7E14; // lfs f0, cm_804D7E14@sda21(r0)
    gc_env.cr[0] = isnan(gc_env.f[1]) || isnan(gc_env.f[0]) ? 0x1 : (gc_env.f[1] < gc_env.f[0] ? 0x8 : (gc_env.f[1] > gc_env.f[0] ? 0x4 : 0x2)); // fcmpo cr0, f1, f0
    if (gc_env.cr[0] >= 0) goto L_8002CF54;
    gc_env.f[1] = -gc_env.f[1]; // fneg f1, f1
    L_8002CF54:
    gc_env.f[0] = cm_804D7E70; // lfs f0, cm_804D7E70@sda21(r0)
    gc_env.cr[0] = isnan(gc_env.f[1]) || isnan(gc_env.f[0]) ? 0x1 : (gc_env.f[1] < gc_env.f[0] ? 0x8 : (gc_env.f[1] > gc_env.f[0] ? 0x4 : 0x2)); // fcmpo cr0, f1, f0
    if (gc_env.cr[0] >= 0) goto L_8002D078;
    gc_env.r[3] = gc_env.r[31] + 720; // addi r3, r31, 0x2d0
    Camera_8002C5B4();
    gc_env.r[4] = gc_mem_read32(gc_env.ram, gc_env.r[31] + 0x308);
    gc_env.r[26] = gc_env.r[30] + 12; // addi r26, r30, 0xc
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[31] + 0x30c);
    gc_env.r[27] = gc_env.r[31] + 32; // addi r27, r31, 0x20
    gc_env.r[3] = gc_env.r[26] + 0; // addi r3, r26, 0x0
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x20, gc_env.r[4]);
    gc_env.r[4] = gc_env.r[31] + 788; // addi r4, r31, 0x314
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x24, gc_env.r[0]);
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[31] + 0x310);
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x28, gc_env.r[0]);
    lbVector_Add();
    gc_env.r[5] = gc_mem_read32(gc_env.ram, gc_env.r[27] + 0x0);
    gc_env.r[28] = gc_env.r[30] + 36; // addi r28, r30, 0x24
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[27] + 0x4);
    gc_env.r[3] = gc_env.r[28] + 0; // addi r3, r28, 0x0
    gc_env.r[4] = gc_env.r[31] + 800; // addi r4, r31, 0x320
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x38, gc_env.r[5]);
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x3c, gc_env.r[0]);
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[27] + 0x8);
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x40, gc_env.r[0]);
    lbVector_Add();
    gc_env.r[27] = gc_env.r[30] + 24; // addi r27, r30, 0x18
    gc_env.r[3] = gc_env.r[28] + 0; // addi r3, r28, 0x0
    gc_env.r[4] = gc_env.r[27] + 0; // addi r4, r27, 0x0
    gc_env.r[5] = gc_env.r[1] + 108; // addi r5, r1, 0x6c
    lbVector_Diff();
    gc_env.r[3] = ((uint32_t)&cm_803BCCA0 >> 16) & 0xFFFF; // lis r3, cm_803BCCA0@ha
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x6C); // lfs f0, 0x6C(r1)
    gc_env.f[0] = *(float*)&temp;
    gc_env.r[29] = gc_env.r[3] + ((uint32_t)&cm_803BCCA0 & 0xFFFF); // addi r29, r3, cm_803BCCA0@l
    gc_env.r[28] = gc_env.r[29] + 132; // addi r28, r29, 0x84
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[29] + 0x84); // lfs f1, 0x84(r29)
    gc_env.f[1] = *(float*)&temp;
    gc_env.r[3] = gc_env.r[27] + 0; // addi r3, r27, 0x0
    gc_env.r[4] = gc_env.r[1] + 108; // addi r4, r1, 0x6c
    gc_env.f[0] = (float)gc_env.f[0] * (float)gc_env.f[1]; // fmuls f0, f0, f1
    float temp = (float)gc_env.f[0]; // stfs f0, 0x6C(r1)
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x6C, *(uint32_t*)&temp);
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x70); // lfs f0, 0x70(r1)
    gc_env.f[0] = *(float*)&temp;
    gc_env.f[0] = (float)gc_env.f[0] * (float)gc_env.f[1]; // fmuls f0, f0, f1
    float temp = (float)gc_env.f[0]; // stfs f0, 0x70(r1)
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x70, *(uint32_t*)&temp);
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x74); // lfs f0, 0x74(r1)
    gc_env.f[0] = *(float*)&temp;
    gc_env.f[0] = (float)gc_env.f[0] * (float)gc_env.f[1]; // fmuls f0, f0, f1
    float temp = (float)gc_env.f[0]; // stfs f0, 0x74(r1)
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x74, *(uint32_t*)&temp);
    lbVector_Add();
    gc_env.r[3] = gc_env.r[26] + 0; // addi r3, r26, 0x0
    gc_env.r[4] = gc_env.r[30] + 0; // addi r4, r30, 0x0
    gc_env.r[5] = gc_env.r[1] + 96; // addi r5, r1, 0x60
    lbVector_Diff();
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[28] + 0x0); // lfs f1, 0x0(r28)
    gc_env.f[1] = *(float*)&temp;
    gc_env.r[3] = gc_env.r[30]; // Move register
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x60); // lfs f0, 0x60(r1)
    gc_env.f[0] = *(float*)&temp;
    gc_env.r[4] = gc_env.r[1] + 96; // addi r4, r1, 0x60
    gc_env.f[0] = (float)gc_env.f[0] * (float)gc_env.f[1]; // fmuls f0, f0, f1
    float temp = (float)gc_env.f[0]; // stfs f0, 0x60(r1)
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x60, *(uint32_t*)&temp);
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x64); // lfs f0, 0x64(r1)
    gc_env.f[0] = *(float*)&temp;
    gc_env.f[0] = (float)gc_env.f[0] * (float)gc_env.f[1]; // fmuls f0, f0, f1
    float temp = (float)gc_env.f[0]; // stfs f0, 0x64(r1)
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x64, *(uint32_t*)&temp);
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x68); // lfs f0, 0x68(r1)
    gc_env.f[0] = *(float*)&temp;
    gc_env.f[0] = (float)gc_env.f[0] * (float)gc_env.f[1]; // fmuls f0, f0, f1
    float temp = (float)gc_env.f[0]; // stfs f0, 0x68(r1)
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x68, *(uint32_t*)&temp);
    lbVector_Add();
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[29] + 0x6C); // lfs f0, 0x6C(r29)
    gc_env.f[0] = *(float*)&temp;
    float temp = (float)gc_env.f[0]; // stfs f0, 0x48(r31)
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x48, *(uint32_t*)&temp);
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[31] + 0x48); // lfs f1, 0x48(r31)
    gc_env.f[1] = *(float*)&temp;
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[31] + 0x44); // lfs f2, 0x44(r31)
    gc_env.f[2] = *(float*)&temp;
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[29] + 0x70); // lfs f0, 0x70(r29)
    gc_env.f[0] = *(float*)&temp;
    gc_env.f[1] = (float)gc_env.f[1] - (float)gc_env.f[2]; // fsubs f1, f1, f2
    gc_env.f[0] = (float)gc_env.f[1] * (float)gc_env.f[0] + (float)gc_env.f[2]; // fmadds f0, f1, f0, f2
    float temp = (float)gc_env.f[0]; // stfs f0, 0x44(r31)
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x44, *(uint32_t*)&temp);
    goto L_8002D300;
    L_8002D078:
    Camera_80030DF8();
    Camera_800293E0();
    Camera_8002B0E0();
    gc_env.r[3] = gc_env.r[1] + 44; // addi r3, r1, 0x2c
    gc_env.r[4] = gc_env.r[30] + 0; // addi r4, r30, 0x0
    Camera_8002958C();
    gc_env.r[3] = ((uint32_t)&cm_803BCCA0 >> 16) & 0xFFFF; // lis r3, cm_803BCCA0@ha
    gc_env.r[3] = gc_env.r[3] + ((uint32_t)&cm_803BCCA0 & 0xFFFF); // addi r3, r3, cm_803BCCA0@l
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[3] + 0x40); // lfs f0, 0x40(r3)
    gc_env.f[0] = *(float*)&temp;
    gc_env.r[27] = gc_env.r[3] + 68; // addi r27, r3, 0x44
    gc_env.r[26] = gc_env.r[3] + 64; // addi r26, r3, 0x40
    float temp = (float)gc_env.f[0]; // stfs f0, 0x48(r31)
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x48, *(uint32_t*)&temp);
    gc_env.r[4] = gc_env.r[30] + 0; // addi r4, r30, 0x0
    gc_env.r[3] = gc_env.r[1] + 44; // addi r3, r1, 0x2c
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[31] + 0x48); // lfs f1, 0x48(r31)
    gc_env.f[1] = *(float*)&temp;
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[31] + 0x44); // lfs f2, 0x44(r31)
    gc_env.f[2] = *(float*)&temp;
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[27] + 0x0); // lfs f0, 0x0(r27)
    gc_env.f[0] = *(float*)&temp;
    gc_env.f[1] = (float)gc_env.f[1] - (float)gc_env.f[2]; // fsubs f1, f1, f2
    gc_env.f[0] = (float)gc_env.f[1] * (float)gc_env.f[0] + (float)gc_env.f[2]; // fmadds f0, f1, f0, f2
    float temp = (float)gc_env.f[0]; // stfs f0, 0x44(r31)
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x44, *(uint32_t*)&temp);
    Camera_80029BC4();
    Camera_80030AF8();
    gc_env.cr[0] = (gc_env.r[3] == 0x0) ? 0 : (gc_env.r[3] < 0x0 ? -1 : 1); // Compare with immediate
    if (gc_env.cr[0] == 0) goto L_8002D114;
    Ground_801C57A4();
    gc_env.cr[0] = ((uint32_t)gc_env.r[3] == 0x0) ? 0 : ((uint32_t)gc_env.r[3] < 0x0 ? -1 : 1); // Logical compare with immediate
    if (gc_env.cr[0] == 0) goto L_8002D114;
    gc_env.r[4] = gc_env.r[1] + 28; // addi r4, r1, 0x1c
    ftLib_80086644();
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x24); // lfs f1, 0x24(r1)
    gc_env.f[1] = *(float*)&temp;
    gc_env.f[0] = cm_804D7E14; // lfs f0, cm_804D7E14@sda21(r0)
    gc_env.cr[0] = isnan(gc_env.f[1]) || isnan(gc_env.f[0]) ? 0x1 : (gc_env.f[1] < gc_env.f[0] ? 0x8 : (gc_env.f[1] > gc_env.f[0] ? 0x4 : 0x2)); // fcmpo cr0, f1, f0
    if (gc_env.cr[0] >= 0) goto L_8002D100;
    gc_env.f[1] = -gc_env.f[1]; // fneg f1, f1
    L_8002D100:
    gc_env.f[0] = cm_804D7E70; // lfs f0, cm_804D7E70@sda21(r0)
    gc_env.cr[0] = isnan(gc_env.f[1]) || isnan(gc_env.f[0]) ? 0x1 : (gc_env.f[1] < gc_env.f[0] ? 0x8 : (gc_env.f[1] > gc_env.f[0] ? 0x4 : 0x2)); // fcmpo cr0, f1, f0
    if (gc_env.cr[0] & (0x8 | 0x2)) goto L_8002D114; // ble .L_8002D114
    gc_env.r[0] = 0x1;
    goto L_8002D118;
    L_8002D114:
    gc_env.r[0] = 0x0;
    L_8002D118:
    gc_env.cr[0] = (gc_env.r[0] == 0x0) ? 0 : (gc_env.r[0] < 0x0 ? -1 : 1); // Compare with immediate
    if (gc_env.cr[0] != 0) goto L_8002D138;
    gc_env.r[3] = gc_env.r[1] + 44; // addi r3, r1, 0x2c
    gc_env.r[4] = gc_env.r[30] + 0; // addi r4, r30, 0x0
    Camera_80029CF8();
    gc_env.r[3] = gc_env.r[30] + 0; // addi r3, r30, 0x0
    gc_env.r[4] = 0x0;
    Camera_8002A768();
    L_8002D138:
    gc_env.r[28] = gc_env.r[31] + 76; // addi r28, r31, 0x4c
    gc_env.r[4] = gc_env.r[28] + 0; // addi r4, r28, 0x0
    gc_env.r[3] = gc_env.r[1] + 68; // addi r3, r1, 0x44
    Camera_8002958C();
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[26] + 0x0); // lfs f0, 0x0(r26)
    gc_env.f[0] = *(float*)&temp;
    gc_env.r[4] = gc_env.r[28] + 0; // addi r4, r28, 0x0
    gc_env.r[3] = gc_env.r[1] + 68; // addi r3, r1, 0x44
    float temp = (float)gc_env.f[0]; // stfs f0, 0x80(r31)
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x80, *(uint32_t*)&temp);
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[31] + 0x80); // lfs f1, 0x80(r31)
    gc_env.f[1] = *(float*)&temp;
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[31] + 0x7C); // lfs f2, 0x7C(r31)
    gc_env.f[2] = *(float*)&temp;
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[27] + 0x0); // lfs f0, 0x0(r27)
    gc_env.f[0] = *(float*)&temp;
    gc_env.f[1] = (float)gc_env.f[1] - (float)gc_env.f[2]; // fsubs f1, f1, f2
    gc_env.f[0] = (float)gc_env.f[1] * (float)gc_env.f[0] + (float)gc_env.f[2]; // fmadds f0, f1, f0, f2
    float temp = (float)gc_env.f[0]; // stfs f0, 0x7C(r31)
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x7C, *(uint32_t*)&temp);
    Camera_80029BC4();
    Camera_80030AF8();
    gc_env.cr[0] = (gc_env.r[3] == 0x0) ? 0 : (gc_env.r[3] < 0x0 ? -1 : 1); // Compare with immediate
    if (gc_env.cr[0] == 0) goto L_8002D1BC;
    Ground_801C57A4();
    gc_env.cr[0] = ((uint32_t)gc_env.r[3] == 0x0) ? 0 : ((uint32_t)gc_env.r[3] < 0x0 ? -1 : 1); // Logical compare with immediate
    if (gc_env.cr[0] == 0) goto L_8002D1BC;
    gc_env.r[4] = gc_env.r[1] + 12; // addi r4, r1, 0xc
    ftLib_80086644();
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x14); // lfs f1, 0x14(r1)
    gc_env.f[1] = *(float*)&temp;
    gc_env.f[0] = cm_804D7E14; // lfs f0, cm_804D7E14@sda21(r0)
    gc_env.cr[0] = isnan(gc_env.f[1]) || isnan(gc_env.f[0]) ? 0x1 : (gc_env.f[1] < gc_env.f[0] ? 0x8 : (gc_env.f[1] > gc_env.f[0] ? 0x4 : 0x2)); // fcmpo cr0, f1, f0
    if (gc_env.cr[0] >= 0) goto L_8002D1A8;
    gc_env.f[1] = -gc_env.f[1]; // fneg f1, f1
    L_8002D1A8:
    gc_env.f[0] = cm_804D7E70; // lfs f0, cm_804D7E70@sda21(r0)
    gc_env.cr[0] = isnan(gc_env.f[1]) || isnan(gc_env.f[0]) ? 0x1 : (gc_env.f[1] < gc_env.f[0] ? 0x8 : (gc_env.f[1] > gc_env.f[0] ? 0x4 : 0x2)); // fcmpo cr0, f1, f0
    if (gc_env.cr[0] & (0x8 | 0x2)) goto L_8002D1BC; // ble .L_8002D1BC
    gc_env.r[0] = 0x1;
    goto L_8002D1C0;
    L_8002D1BC:
    gc_env.r[0] = 0x0;
    L_8002D1C0:
    gc_env.cr[0] = (gc_env.r[0] == 0x0) ? 0 : (gc_env.r[0] < 0x0 ? -1 : 1); // Compare with immediate
    if (gc_env.cr[0] != 0) goto L_8002D1E0;
    gc_env.r[3] = gc_env.r[1] + 68; // addi r3, r1, 0x44
    gc_env.r[4] = gc_env.r[28] + 0; // addi r4, r28, 0x0
    Camera_80029CF8();
    gc_env.r[3] = gc_env.r[28] + 0; // addi r3, r28, 0x0
    gc_env.r[4] = 0x0;
    Camera_8002A768();
    L_8002D1E0:
    gc_env.f[1] = cm_804D7E04; // lfs f1, cm_804D7E04@sda21(r0)
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[31] + 0x2BC); // lfs f0, 0x2BC(r31)
    gc_env.f[0] = *(float*)&temp;
    gc_env.cr[0] = isnan(gc_env.f[1]) || isnan(gc_env.f[0]) ? 0x1 : (gc_env.f[1] < gc_env.f[0] ? 0x8 : (gc_env.f[1] > gc_env.f[0] ? 0x4 : 0x2)); // fcmpu cr0, f1, f0
    if (gc_env.cr[0] != 0) goto L_8002D230;
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[31] + 0x38); // lfs f3, 0x38(r31)
    gc_env.f[3] = *(float*)&temp;
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[31] + 0x20); // lfs f2, 0x20(r31)
    gc_env.f[2] = *(float*)&temp;
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[31] + 0x3C); // lfs f1, 0x3C(r31)
    gc_env.f[1] = *(float*)&temp;
    gc_env.f[4] = (float)gc_env.f[3] - (float)gc_env.f[2]; // fsubs f4, f3, f2
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[31] + 0x24); // lfs f0, 0x24(r31)
    gc_env.f[0] = *(float*)&temp;
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[31] + 0x40); // lfs f2, 0x40(r31)
    gc_env.f[2] = *(float*)&temp;
    gc_env.f[3] = (float)gc_env.f[1] - (float)gc_env.f[0]; // fsubs f3, f1, f0
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[31] + 0x28); // lfs f0, 0x28(r31)
    gc_env.f[0] = *(float*)&temp;
    gc_env.f[2] = (float)gc_env.f[2] - (float)gc_env.f[0]; // fsubs f2, f2, f0
    gc_env.f[1] = (float)gc_env.f[4] * (float)gc_env.f[4]; // fmuls f1, f4, f4
    gc_env.f[0] = (float)gc_env.f[3] * (float)gc_env.f[3]; // fmuls f0, f3, f3
    gc_env.f[2] = (float)gc_env.f[2] * (float)gc_env.f[2]; // fmuls f2, f2, f2
    gc_env.f[0] = (float)gc_env.f[1] + (float)gc_env.f[0]; // fadds f0, f1, f0
    gc_env.f[1] = (float)gc_env.f[2] + (float)gc_env.f[0]; // fadds f1, f2, f0
    sqrtf__Ff();
    float temp = (float)gc_env.f[1]; // stfs f1, 0x2C0(r31)
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x2C0, *(uint32_t*)&temp);
    L_8002D230:
    gc_env.r[3] = gc_env.r[30]; // Move register
    Camera_8002B1F8();
    Stage_GetCamTrackSmooth();
    gc_env.r[4] = gc_env.r[30] + 0; // addi r4, r30, 0x0
    gc_env.r[3] = gc_env.r[1] + 44; // addi r3, r1, 0x2c
    Camera_80029AAC();
    Stage_GetCamTrackSmooth();
    gc_env.r[4] = gc_env.r[30] + 0; // addi r4, r30, 0x0
    gc_env.r[3] = gc_env.r[1] + 44; // addi r3, r1, 0x2c
    Camera_80029C88();
    Stage_GetCamTrackSmooth();
    gc_env.r[4] = gc_env.r[28] + 0; // addi r4, r28, 0x0
    gc_env.r[3] = gc_env.r[1] + 68; // addi r3, r1, 0x44
    Camera_80029AAC();
    Stage_GetCamTrackSmooth();
    gc_env.r[4] = gc_env.r[28] + 0; // addi r4, r28, 0x0
    gc_env.r[3] = gc_env.r[1] + 68; // addi r3, r1, 0x44
    Camera_80029C88();
    gc_env.r[3] = gc_env.r[1] + 44; // addi r3, r1, 0x2c
    Camera_8002A28C();
    gc_env.r[3] = gc_env.r[1] + 44; // addi r3, r1, 0x2c
    gc_env.r[4] = gc_env.r[30] + 0; // addi r4, r30, 0x0
    Camera_8002A0C0();
    gc_env.r[26] = gc_env.r[31] + 696; // addi r26, r31, 0x2b8
    gc_env.r[0] = (int32_t)(int16_t)gc_mem_read16(gc_env.ram, gc_env.r[31] + 0x2B8); // lha r0, 0x2B8(r31)
    gc_env.cr[0] = (gc_env.r[0] == 0x3e8) ? 0 : (gc_env.r[0] < 0x3e8 ? -1 : 1); // Compare with immediate
    if (gc_env.cr[0] & (0x8 | 0x2)) goto L_8002D2AC; // ble .L_8002D2AC
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[31] + 0x2B0); // lfs f0, 0x2B0(r31)
    gc_env.f[0] = *(float*)&temp;
    gc_env.r[0] = 0x1;
    float temp = (float)gc_env.f[0]; // stfs f0, 0x2B4(r31)
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x2B4, *(uint32_t*)&temp);
    gc_mem_write16(gc_env.ram, gc_env.r[26] + 0x0, gc_env.r[0]);
    L_8002D2AC:
    Stage_GetCamBoundsLeftOffset();
    gc_env.f[31] = gc_env.f[1]; // fmr f31, f1
    Stage_GetCamBoundsRightOffset();
    gc_env.f[1] = (float)gc_env.f[1] - (float)gc_env.f[31]; // fsubs f1, f1, f31
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[31] + 0x2B4); // lfs f0, 0x2B4(r31)
    gc_env.f[0] = *(float*)&temp;
    gc_env.r[0] = 17200 << 16; // lis r0, 0x4330
    gc_env.f[0] = (float)gc_env.f[0] + (float)gc_env.f[1]; // fadds f0, f0, f1
    float temp = (float)gc_env.f[0]; // stfs f0, 0x2B4(r31)
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x2B4, *(uint32_t*)&temp);
    gc_env.r[3] = (int32_t)(int16_t)gc_mem_read16(gc_env.ram, gc_env.r[26] + 0x0); // lha r3, 0x0(r26)
    gc_env.r[3] += 1; // addi r3, r3, 0x1
    gc_mem_write16(gc_env.ram, gc_env.r[26] + 0x0, gc_env.r[3]);
    gc_env.r[3] = (int32_t)(int16_t)gc_mem_read16(gc_env.ram, gc_env.r[26] + 0x0); // lha r3, 0x0(r26)
    gc_env.d[1] = cm_804D7E20; // lfd f1, cm_804D7E20@sda21(r0)
    gc_env.r[3] = gc_env.r[3] ^ 0x80000000; // xoris r3, r3, 0x8000
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[31] + 0x2B4); // lfs f2, 0x2B4(r31)
    gc_env.f[2] = *(float*)&temp;
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x94, gc_env.r[3]);
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x90, gc_env.r[0]);
    uint64_t temp = gc_mem_read64(gc_env.ram, gc_env.r[1] + 0x90); // lfd f0, 0x90(r1)
    gc_env.d[0] = *(double*)&temp;
    gc_env.f[0] = (float)gc_env.f[0] - (float)gc_env.f[1]; // fsubs f0, f0, f1
    gc_env.f[0] = (float)gc_env.f[2] / (float)gc_env.f[0]; // fdivs f0, f2, f0
    float temp = (float)gc_env.f[0]; // stfs f0, 0x2B0(r31)
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x2B0, *(uint32_t*)&temp);
    L_8002D300:
    gc_env.r[26] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x98); // lmw r26, 0x98(r1)
    gc_env.r[27] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x9C); // lmw r26, 0x98(r1)
    gc_env.r[28] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0xA0); // lmw r26, 0x98(r1)
    gc_env.r[29] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0xA4); // lmw r26, 0x98(r1)
    gc_env.r[30] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0xA8); // lmw r26, 0x98(r1)
    gc_env.r[31] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0xAC); // lmw r26, 0x98(r1)
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0xbc);
    uint64_t temp = gc_mem_read64(gc_env.ram, gc_env.r[1] + 0xB0); // lfd f31, 0xB0(r1)
    gc_env.d[31] = *(double*)&temp;
    gc_env.r[1] += 184; // addi r1, r1, 0xb8
    gc_env.lr = gc_env.r[0]; // Move to link register
    return;
}

// Function: Camera_8002D318
void Camera_8002D318(void) {
    gc_env.r[0] = gc_env.lr; // Move from link register
    gc_env.r[3] = ((uint32_t)&cm_80452C68 >> 16) & 0xFFFF; // lis r3, cm_80452C68@ha
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x4, gc_env.r[0]);
    gc_mem_write32(gc_env.ram, gc_env.r[1] + -0xb0, gc_env.r[1]);
    gc_env.r[1] = gc_env.r[1] + -0xb0;
    uint64_t temp;
    memcpy(&temp, &gc_env.f[31], sizeof(double));
    gc_mem_write64(gc_env.ram, gc_env.r[1] + 0xA8, temp); // stfd f31, 0xA8(r1)
    uint64_t temp;
    memcpy(&temp, &gc_env.f[30], sizeof(double));
    gc_mem_write64(gc_env.ram, gc_env.r[1] + 0xA0, temp); // stfd f30, 0xA0(r1)
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x88, gc_env.r[26]); // stmw r26, 0x88(r1)
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x8C, gc_env.r[27]); // stmw r26, 0x88(r1)
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x90, gc_env.r[28]); // stmw r26, 0x88(r1)
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x94, gc_env.r[29]); // stmw r26, 0x88(r1)
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x98, gc_env.r[30]); // stmw r26, 0x88(r1)
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x9C, gc_env.r[31]); // stmw r26, 0x88(r1)
    gc_env.r[31] = gc_env.r[3] + ((uint32_t)&cm_80452C68 & 0xFFFF); // addi r31, r3, cm_80452C68@l
    gc_env.r[29] = gc_env.r[31] + 708; // addi r29, r31, 0x2c4
    gc_env.r[3] = gc_mem_read8(gc_env.ram, gc_env.r[31] + 0x2c4);
    // Unknown opcode: extsb r3 r3
    Player_GetEntity();
    gc_env.r[26] = gc_env.r[3]; // Move register
    if (gc_env.cr[0] == 0) goto L_8002D5B4;
    gc_env.r[3] = gc_env.r[26]; // Move register
    ftLib_8008701C();
    gc_env.cr[0] = (gc_env.r[3] == 0x0) ? 0 : (gc_env.r[3] < 0x0 ? -1 : 1); // Compare with immediate
    if (gc_env.cr[0] != 0) goto L_8002D5B4;
    gc_env.r[3] = gc_env.r[26]; // Move register
    ftLib_80086B74();
    gc_env.r[26] = gc_env.r[3]; // Move register
    if (gc_env.cr[0] == 0) goto L_8002D5B4;
    gc_env.r[3] = gc_env.r[26]; // Move register
    Camera_8002928C();
    gc_env.cr[0] = (gc_env.r[3] == 0x0) ? 0 : (gc_env.r[3] < 0x0 ? -1 : 1); // Compare with immediate
    if (gc_env.cr[0] == 0) goto L_8002D5B4;
    gc_env.r[3] = gc_env.r[26] + 28; // addi r3, r26, 0x1c
    gc_env.r[4] = 0x0;
    Camera_80029124();
    gc_env.cr[0] = ((uint32_t)gc_env.r[3] == 0x0) ? 0 : ((uint32_t)gc_env.r[3] < 0x0 ? -1 : 1); // Logical compare with immediate
    if (gc_env.cr[0] != 0) goto L_8002D5B4;
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[26] + 0x24); // lfs f1, 0x24(r26)
    gc_env.f[1] = *(float*)&temp;
    gc_env.f[0] = cm_804D7E14; // lfs f0, cm_804D7E14@sda21(r0)
    gc_env.cr[0] = isnan(gc_env.f[1]) || isnan(gc_env.f[0]) ? 0x1 : (gc_env.f[1] < gc_env.f[0] ? 0x8 : (gc_env.f[1] > gc_env.f[0] ? 0x4 : 0x2)); // fcmpo cr0, f1, f0
    if (gc_env.cr[0] >= 0) goto L_8002D3A8;
    gc_env.f[1] = -gc_env.f[1]; // fneg f1, f1
    L_8002D3A8:
    gc_env.f[0] = cm_804D7E4C; // lfs f0, cm_804D7E4C@sda21(r0)
    gc_env.cr[0] = isnan(gc_env.f[1]) || isnan(gc_env.f[0]) ? 0x1 : (gc_env.f[1] < gc_env.f[0] ? 0x8 : (gc_env.f[1] > gc_env.f[0] ? 0x4 : 0x2)); // fcmpo cr0, f1, f0
    if (gc_env.cr[0] >= 0) goto L_8002D5B4;
    Camera_80030DF8();
    gc_env.r[3] = gc_mem_read8(gc_env.ram, gc_env.r[29] + 0x0);
    // Unknown opcode: extsb r3 r3
    Player_GetEntity();
    gc_env.cr[0] = ((uint32_t)gc_env.r[3] == 0x0) ? 0 : ((uint32_t)gc_env.r[3] < 0x0 ? -1 : 1); // Logical compare with immediate
    if (gc_env.cr[0] == 0) goto L_8002D474;
    ftLib_80086B74();
    gc_env.cr[0] = ((uint32_t)gc_env.r[3] == 0x0) ? 0 : ((uint32_t)gc_env.r[3] < 0x0 ? -1 : 1); // Logical compare with immediate
    if (gc_env.cr[0] == 0) goto L_8002D474;
    gc_env.f[2] = cm_804D7E30; // lfs f2, cm_804D7E30@sda21(r0)
    gc_env.r[28] = gc_env.r[31] + 716; // addi r28, r31, 0x2cc
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[3] + 0x3C); // lfs f0, 0x3C(r3)
    gc_env.f[0] = *(float*)&temp;
    gc_env.r[30] = gc_env.r[3] + 28; // addi r30, r3, 0x1c
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[31] + 0x2CC); // lfs f1, 0x2CC(r31)
    gc_env.f[1] = *(float*)&temp;
    gc_env.f[31] = (float)gc_env.f[2] * (float)gc_env.f[0]; // fmuls f31, f2, f0
    cosf();
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[30] + 0x0); // lfs f0, 0x0(r30)
    gc_env.f[0] = *(float*)&temp;
    gc_env.r[26] = gc_env.r[31] + 32; // addi r26, r31, 0x20
    gc_env.r[27] = gc_env.r[31] + 36; // addi r27, r31, 0x24
    gc_env.f[0] = -((float)gc_env.f[31] * (float)gc_env.f[1] - (float)gc_env.f[0]); // fnmsubs f0, f31, f1, f0
    float temp = (float)gc_env.f[0]; // stfs f0, 0x20(r31)
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x20, *(uint32_t*)&temp);
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[30] + 0x4); // lfs f0, 0x4(r30)
    gc_env.f[0] = *(float*)&temp;
    float temp = (float)gc_env.f[0]; // stfs f0, 0x24(r31)
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x24, *(uint32_t*)&temp);
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[28] + 0x0); // lfs f1, 0x0(r28)
    gc_env.f[1] = *(float*)&temp;
    sinf();
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[30] + 0x8); // lfs f0, 0x8(r30)
    gc_env.f[0] = *(float*)&temp;
    gc_env.r[3] = ((uint32_t)&cm_803BCCA0 >> 16) & 0xFFFF; // lis r3, cm_803BCCA0@ha
    gc_env.r[3] = gc_env.r[3] + ((uint32_t)&cm_803BCCA0 & 0xFFFF); // addi r3, r3, cm_803BCCA0@l
    gc_env.f[0] = (float)gc_env.f[31] * (float)gc_env.f[1] + (float)gc_env.f[0]; // fmadds f0, f31, f1, f0
    float temp = (float)gc_env.f[0]; // stfs f0, 0x28(r31)
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x28, *(uint32_t*)&temp);
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[26] + 0x0); // lfs f0, 0x0(r26)
    gc_env.f[0] = *(float*)&temp;
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[31] + 0x14); // lfs f1, 0x14(r31)
    gc_env.f[1] = *(float*)&temp;
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[3] + 0x64); // lfs f6, 0x64(r3)
    gc_env.f[6] = *(float*)&temp;
    gc_env.f[0] = (float)gc_env.f[0] - (float)gc_env.f[1]; // fsubs f0, f0, f1
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[27] + 0x0); // lfs f5, 0x0(r27)
    gc_env.f[5] = *(float*)&temp;
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[31] + 0x18); // lfs f4, 0x18(r31)
    gc_env.f[4] = *(float*)&temp;
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[31] + 0x28); // lfs f3, 0x28(r31)
    gc_env.f[3] = *(float*)&temp;
    gc_env.f[0] = (float)gc_env.f[0] * (float)gc_env.f[6] + (float)gc_env.f[1]; // fmadds f0, f0, f6, f1
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[31] + 0x1C); // lfs f2, 0x1C(r31)
    gc_env.f[2] = *(float*)&temp;
    gc_env.f[4] = (float)gc_env.f[5] - (float)gc_env.f[4]; // fsubs f4, f5, f4
    float temp = (float)gc_env.f[0]; // stfs f0, 0x14(r31)
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x14, *(uint32_t*)&temp);
    gc_env.f[1] = (float)gc_env.f[3] - (float)gc_env.f[2]; // fsubs f1, f3, f2
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[31] + 0x18); // lfs f0, 0x18(r31)
    gc_env.f[0] = *(float*)&temp;
    gc_env.f[0] = (float)gc_env.f[4] * (float)gc_env.f[6] + (float)gc_env.f[0]; // fmadds f0, f4, f6, f0
    float temp = (float)gc_env.f[0]; // stfs f0, 0x18(r31)
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x18, *(uint32_t*)&temp);
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[31] + 0x1C); // lfs f0, 0x1C(r31)
    gc_env.f[0] = *(float*)&temp;
    gc_env.f[0] = (float)gc_env.f[1] * (float)gc_env.f[6] + (float)gc_env.f[0]; // fmadds f0, f1, f6, f0
    float temp = (float)gc_env.f[0]; // stfs f0, 0x1C(r31)
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x1C, *(uint32_t*)&temp);
    L_8002D474:
    gc_env.r[3] = ((uint32_t)&cm_803BCCA0 >> 16) & 0xFFFF; // lis r3, cm_803BCCA0@ha
    gc_env.r[3] = gc_env.r[3] + ((uint32_t)&cm_803BCCA0 & 0xFFFF); // addi r3, r3, cm_803BCCA0@l
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[3] + 0x6C); // lfs f0, 0x6C(r3)
    gc_env.f[0] = *(float*)&temp;
    gc_env.r[26] = gc_env.r[31] + 72; // addi r26, r31, 0x48
    float temp = (float)gc_env.f[0]; // stfs f0, 0x48(r31)
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x48, *(uint32_t*)&temp);
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[31] + 0x48); // lfs f1, 0x48(r31)
    gc_env.f[1] = *(float*)&temp;
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[31] + 0x44); // lfs f2, 0x44(r31)
    gc_env.f[2] = *(float*)&temp;
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[3] + 0x70); // lfs f0, 0x70(r3)
    gc_env.f[0] = *(float*)&temp;
    gc_env.f[1] = (float)gc_env.f[1] - (float)gc_env.f[2]; // fsubs f1, f1, f2
    gc_env.f[0] = (float)gc_env.f[1] * (float)gc_env.f[0] + (float)gc_env.f[2]; // fmadds f0, f1, f0, f2
    float temp = (float)gc_env.f[0]; // stfs f0, 0x44(r31)
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x44, *(uint32_t*)&temp);
    gc_env.r[3] = gc_mem_read8(gc_env.ram, gc_env.r[29] + 0x0);
    // Unknown opcode: extsb r3 r3
    gc_env.cr[0] = (gc_env.r[3] == 0xa) ? 0 : (gc_env.r[3] < 0xa ? -1 : 1); // Compare with immediate
    if (gc_env.cr[0] == 0) goto L_8002D504;
    gc_env.cr[0] = (gc_env.r[3] == 0xb) ? 0 : (gc_env.r[3] < 0xb ? -1 : 1); // Compare with immediate
    if (gc_env.cr[0] == 0) goto L_8002D504;
    gc_env.cr[0] = (gc_env.r[3] == 0x0) ? 0 : (gc_env.r[3] < 0x0 ? -1 : 1); // Compare with immediate
    if (gc_env.cr[0] & 0x8) goto L_8002D504; // blt .L_8002D504
    gc_env.cr[0] = (gc_env.r[3] == 0x6) ? 0 : (gc_env.r[3] < 0x6 ? -1 : 1); // Compare with immediate
    if (gc_env.cr[0] >= 0) goto L_8002D504;
    Player_GetEntity();
    gc_env.cr[0] = ((uint32_t)gc_env.r[3] == 0x0) ? 0 : ((uint32_t)gc_env.r[3] < 0x0 ? -1 : 1); // Logical compare with immediate
    if (gc_env.cr[0] == 0) goto L_8002D504;
    ftLib_80086B74();
    gc_env.r[30] = gc_env.r[3]; // Move register
    if (gc_env.cr[0] == 0) goto L_8002D504;
    gc_env.f[1] = cm_804D7E60; // lfs f1, cm_804D7E60@sda21(r0)
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[26] + 0x0); // lfs f0, 0x0(r26)
    gc_env.f[0] = *(float*)&temp;
    gc_env.f[1] = (float)gc_env.f[1] * (float)gc_env.f[0]; // fmuls f1, f1, f0
    tanf();
    gc_env.f[2] = cm_804D7EA8; // lfs f2, cm_804D7EA8@sda21(r0)
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[30] + 0x3C); // lfs f0, 0x3C(r30)
    gc_env.f[0] = *(float*)&temp;
    gc_env.f[0] = (float)gc_env.f[2] * (float)gc_env.f[0]; // fmuls f0, f2, f0
    gc_env.f[30] = (float)gc_env.f[0] / (float)gc_env.f[1]; // fdivs f30, f0, f1
    goto L_8002D508;
    L_8002D504:
    gc_env.f[30] = cm_804D7E5C; // lfs f30, cm_804D7E5C@sda21(r0)
    L_8002D508:
    gc_env.r[26] = gc_env.r[31] + 712; // addi r26, r31, 0x2c8
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[31] + 0x2C8); // lfs f1, 0x2C8(r31)
    gc_env.f[1] = *(float*)&temp;
    cosf();
    gc_env.f[31] = (float)gc_env.f[30] * (float)gc_env.f[1]; // fmuls f31, f30, f1
    gc_env.r[27] = gc_env.r[31] + 716; // addi r27, r31, 0x2cc
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[31] + 0x2CC); // lfs f1, 0x2CC(r31)
    gc_env.f[1] = *(float*)&temp;
    sinf();
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[31] + 0x20); // lfs f0, 0x20(r31)
    gc_env.f[0] = *(float*)&temp;
    gc_env.r[28] = gc_env.r[31] + 56; // addi r28, r31, 0x38
    gc_env.f[0] = (float)gc_env.f[31] * (float)gc_env.f[1] + (float)gc_env.f[0]; // fmadds f0, f31, f1, f0
    float temp = (float)gc_env.f[0]; // stfs f0, 0x38(r31)
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x38, *(uint32_t*)&temp);
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[26] + 0x0); // lfs f1, 0x0(r26)
    gc_env.f[1] = *(float*)&temp;
    sinf();
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[31] + 0x24); // lfs f0, 0x24(r31)
    gc_env.f[0] = *(float*)&temp;
    gc_env.r[26] = gc_env.r[31] + 60; // addi r26, r31, 0x3c
    gc_env.f[0] = (float)gc_env.f[30] * (float)gc_env.f[1] + (float)gc_env.f[0]; // fmadds f0, f30, f1, f0
    float temp = (float)gc_env.f[0]; // stfs f0, 0x3C(r31)
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x3C, *(uint32_t*)&temp);
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[27] + 0x0); // lfs f1, 0x0(r27)
    gc_env.f[1] = *(float*)&temp;
    cosf();
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[31] + 0x28); // lfs f0, 0x28(r31)
    gc_env.f[0] = *(float*)&temp;
    gc_env.r[3] = ((uint32_t)&cm_803BCCA0 >> 16) & 0xFFFF; // lis r3, cm_803BCCA0@ha
    gc_env.r[3] = gc_env.r[3] + ((uint32_t)&cm_803BCCA0 & 0xFFFF); // addi r3, r3, cm_803BCCA0@l
    gc_env.f[0] = (float)gc_env.f[31] * (float)gc_env.f[1] + (float)gc_env.f[0]; // fmadds f0, f31, f1, f0
    float temp = (float)gc_env.f[0]; // stfs f0, 0x40(r31)
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x40, *(uint32_t*)&temp);
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[28] + 0x0); // lfs f0, 0x0(r28)
    gc_env.f[0] = *(float*)&temp;
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[31] + 0x2C); // lfs f1, 0x2C(r31)
    gc_env.f[1] = *(float*)&temp;
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[3] + 0x68); // lfs f6, 0x68(r3)
    gc_env.f[6] = *(float*)&temp;
    gc_env.f[0] = (float)gc_env.f[0] - (float)gc_env.f[1]; // fsubs f0, f0, f1
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[26] + 0x0); // lfs f5, 0x0(r26)
    gc_env.f[5] = *(float*)&temp;
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[31] + 0x30); // lfs f4, 0x30(r31)
    gc_env.f[4] = *(float*)&temp;
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[31] + 0x40); // lfs f3, 0x40(r31)
    gc_env.f[3] = *(float*)&temp;
    gc_env.f[0] = (float)gc_env.f[0] * (float)gc_env.f[6] + (float)gc_env.f[1]; // fmadds f0, f0, f6, f1
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[31] + 0x34); // lfs f2, 0x34(r31)
    gc_env.f[2] = *(float*)&temp;
    gc_env.f[4] = (float)gc_env.f[5] - (float)gc_env.f[4]; // fsubs f4, f5, f4
    float temp = (float)gc_env.f[0]; // stfs f0, 0x2C(r31)
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x2C, *(uint32_t*)&temp);
    gc_env.f[1] = (float)gc_env.f[3] - (float)gc_env.f[2]; // fsubs f1, f3, f2
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[31] + 0x30); // lfs f0, 0x30(r31)
    gc_env.f[0] = *(float*)&temp;
    gc_env.f[0] = (float)gc_env.f[4] * (float)gc_env.f[6] + (float)gc_env.f[0]; // fmadds f0, f4, f6, f0
    float temp = (float)gc_env.f[0]; // stfs f0, 0x30(r31)
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x30, *(uint32_t*)&temp);
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[31] + 0x34); // lfs f0, 0x34(r31)
    gc_env.f[0] = *(float*)&temp;
    gc_env.f[0] = (float)gc_env.f[1] * (float)gc_env.f[6] + (float)gc_env.f[0]; // fmadds f0, f1, f6, f0
    float temp = (float)gc_env.f[0]; // stfs f0, 0x34(r31)
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x34, *(uint32_t*)&temp);
    goto L_8002D840;
    L_8002D5B4:
    Camera_80030DF8();
    Camera_800293E0();
    Camera_8002B0E0();
    gc_env.r[26] = gc_env.r[31] + 20; // addi r26, r31, 0x14
    gc_env.r[4] = gc_env.r[26] + 0; // addi r4, r26, 0x0
    gc_env.r[3] = gc_env.r[1] + 44; // addi r3, r1, 0x2c
    Camera_8002958C();
    gc_env.r[3] = ((uint32_t)&cm_803BCCA0 >> 16) & 0xFFFF; // lis r3, cm_803BCCA0@ha
    gc_env.r[3] = gc_env.r[3] + ((uint32_t)&cm_803BCCA0 & 0xFFFF); // addi r3, r3, cm_803BCCA0@l
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[3] + 0x40); // lfs f0, 0x40(r3)
    gc_env.f[0] = *(float*)&temp;
    gc_env.r[28] = gc_env.r[3] + 68; // addi r28, r3, 0x44
    gc_env.r[27] = gc_env.r[3] + 64; // addi r27, r3, 0x40
    float temp = (float)gc_env.f[0]; // stfs f0, 0x48(r31)
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x48, *(uint32_t*)&temp);
    gc_env.r[4] = gc_env.r[26] + 0; // addi r4, r26, 0x0
    gc_env.r[3] = gc_env.r[1] + 44; // addi r3, r1, 0x2c
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[31] + 0x48); // lfs f1, 0x48(r31)
    gc_env.f[1] = *(float*)&temp;
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[31] + 0x44); // lfs f2, 0x44(r31)
    gc_env.f[2] = *(float*)&temp;
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[28] + 0x0); // lfs f0, 0x0(r28)
    gc_env.f[0] = *(float*)&temp;
    gc_env.f[1] = (float)gc_env.f[1] - (float)gc_env.f[2]; // fsubs f1, f1, f2
    gc_env.f[0] = (float)gc_env.f[1] * (float)gc_env.f[0] + (float)gc_env.f[2]; // fmadds f0, f1, f0, f2
    float temp = (float)gc_env.f[0]; // stfs f0, 0x44(r31)
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x44, *(uint32_t*)&temp);
    Camera_80029BC4();
    Camera_80030AF8();
    gc_env.cr[0] = (gc_env.r[3] == 0x0) ? 0 : (gc_env.r[3] < 0x0 ? -1 : 1); // Compare with immediate
    if (gc_env.cr[0] == 0) goto L_8002D654;
    Ground_801C57A4();
    gc_env.cr[0] = ((uint32_t)gc_env.r[3] == 0x0) ? 0 : ((uint32_t)gc_env.r[3] < 0x0 ? -1 : 1); // Logical compare with immediate
    if (gc_env.cr[0] == 0) goto L_8002D654;
    gc_env.r[4] = gc_env.r[1] + 28; // addi r4, r1, 0x1c
    ftLib_80086644();
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x24); // lfs f1, 0x24(r1)
    gc_env.f[1] = *(float*)&temp;
    gc_env.f[0] = cm_804D7E14; // lfs f0, cm_804D7E14@sda21(r0)
    gc_env.cr[0] = isnan(gc_env.f[1]) || isnan(gc_env.f[0]) ? 0x1 : (gc_env.f[1] < gc_env.f[0] ? 0x8 : (gc_env.f[1] > gc_env.f[0] ? 0x4 : 0x2)); // fcmpo cr0, f1, f0
    if (gc_env.cr[0] >= 0) goto L_8002D640;
    gc_env.f[1] = -gc_env.f[1]; // fneg f1, f1
    L_8002D640:
    gc_env.f[0] = cm_804D7E70; // lfs f0, cm_804D7E70@sda21(r0)
    gc_env.cr[0] = isnan(gc_env.f[1]) || isnan(gc_env.f[0]) ? 0x1 : (gc_env.f[1] < gc_env.f[0] ? 0x8 : (gc_env.f[1] > gc_env.f[0] ? 0x4 : 0x2)); // fcmpo cr0, f1, f0
    if (gc_env.cr[0] & (0x8 | 0x2)) goto L_8002D654; // ble .L_8002D654
    gc_env.r[0] = 0x1;
    goto L_8002D658;
    L_8002D654:
    gc_env.r[0] = 0x0;
    L_8002D658:
    gc_env.cr[0] = (gc_env.r[0] == 0x0) ? 0 : (gc_env.r[0] < 0x0 ? -1 : 1); // Compare with immediate
    if (gc_env.cr[0] != 0) goto L_8002D678;
    gc_env.r[3] = gc_env.r[1] + 44; // addi r3, r1, 0x2c
    gc_env.r[4] = gc_env.r[26] + 0; // addi r4, r26, 0x0
    Camera_80029CF8();
    gc_env.r[3] = gc_env.r[26] + 0; // addi r3, r26, 0x0
    gc_env.r[4] = 0x0;
    Camera_8002A768();
    L_8002D678:
    gc_env.r[29] = gc_env.r[31] + 76; // addi r29, r31, 0x4c
    gc_env.r[4] = gc_env.r[29] + 0; // addi r4, r29, 0x0
    gc_env.r[3] = gc_env.r[1] + 68; // addi r3, r1, 0x44
    Camera_8002958C();
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[27] + 0x0); // lfs f0, 0x0(r27)
    gc_env.f[0] = *(float*)&temp;
    gc_env.r[4] = gc_env.r[29] + 0; // addi r4, r29, 0x0
    gc_env.r[3] = gc_env.r[1] + 68; // addi r3, r1, 0x44
    float temp = (float)gc_env.f[0]; // stfs f0, 0x80(r31)
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x80, *(uint32_t*)&temp);
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[31] + 0x80); // lfs f1, 0x80(r31)
    gc_env.f[1] = *(float*)&temp;
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[31] + 0x7C); // lfs f2, 0x7C(r31)
    gc_env.f[2] = *(float*)&temp;
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[28] + 0x0); // lfs f0, 0x0(r28)
    gc_env.f[0] = *(float*)&temp;
    gc_env.f[1] = (float)gc_env.f[1] - (float)gc_env.f[2]; // fsubs f1, f1, f2
    gc_env.f[0] = (float)gc_env.f[1] * (float)gc_env.f[0] + (float)gc_env.f[2]; // fmadds f0, f1, f0, f2
    float temp = (float)gc_env.f[0]; // stfs f0, 0x7C(r31)
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x7C, *(uint32_t*)&temp);
    Camera_80029BC4();
    Camera_80030AF8();
    gc_env.cr[0] = (gc_env.r[3] == 0x0) ? 0 : (gc_env.r[3] < 0x0 ? -1 : 1); // Compare with immediate
    if (gc_env.cr[0] == 0) goto L_8002D6FC;
    Ground_801C57A4();
    gc_env.cr[0] = ((uint32_t)gc_env.r[3] == 0x0) ? 0 : ((uint32_t)gc_env.r[3] < 0x0 ? -1 : 1); // Logical compare with immediate
    if (gc_env.cr[0] == 0) goto L_8002D6FC;
    gc_env.r[4] = gc_env.r[1] + 12; // addi r4, r1, 0xc
    ftLib_80086644();
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x14); // lfs f1, 0x14(r1)
    gc_env.f[1] = *(float*)&temp;
    gc_env.f[0] = cm_804D7E14; // lfs f0, cm_804D7E14@sda21(r0)
    gc_env.cr[0] = isnan(gc_env.f[1]) || isnan(gc_env.f[0]) ? 0x1 : (gc_env.f[1] < gc_env.f[0] ? 0x8 : (gc_env.f[1] > gc_env.f[0] ? 0x4 : 0x2)); // fcmpo cr0, f1, f0
    if (gc_env.cr[0] >= 0) goto L_8002D6E8;
    gc_env.f[1] = -gc_env.f[1]; // fneg f1, f1
    L_8002D6E8:
    gc_env.f[0] = cm_804D7E70; // lfs f0, cm_804D7E70@sda21(r0)
    gc_env.cr[0] = isnan(gc_env.f[1]) || isnan(gc_env.f[0]) ? 0x1 : (gc_env.f[1] < gc_env.f[0] ? 0x8 : (gc_env.f[1] > gc_env.f[0] ? 0x4 : 0x2)); // fcmpo cr0, f1, f0
    if (gc_env.cr[0] & (0x8 | 0x2)) goto L_8002D6FC; // ble .L_8002D6FC
    gc_env.r[0] = 0x1;
    goto L_8002D700;
    L_8002D6FC:
    gc_env.r[0] = 0x0;
    L_8002D700:
    gc_env.cr[0] = (gc_env.r[0] == 0x0) ? 0 : (gc_env.r[0] < 0x0 ? -1 : 1); // Compare with immediate
    if (gc_env.cr[0] != 0) goto L_8002D720;
    gc_env.r[3] = gc_env.r[1] + 68; // addi r3, r1, 0x44
    gc_env.r[4] = gc_env.r[29] + 0; // addi r4, r29, 0x0
    Camera_80029CF8();
    gc_env.r[3] = gc_env.r[29] + 0; // addi r3, r29, 0x0
    gc_env.r[4] = 0x0;
    Camera_8002A768();
    L_8002D720:
    gc_env.f[1] = cm_804D7E04; // lfs f1, cm_804D7E04@sda21(r0)
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[31] + 0x2BC); // lfs f0, 0x2BC(r31)
    gc_env.f[0] = *(float*)&temp;
    gc_env.cr[0] = isnan(gc_env.f[1]) || isnan(gc_env.f[0]) ? 0x1 : (gc_env.f[1] < gc_env.f[0] ? 0x8 : (gc_env.f[1] > gc_env.f[0] ? 0x4 : 0x2)); // fcmpu cr0, f1, f0
    if (gc_env.cr[0] != 0) goto L_8002D770;
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[31] + 0x38); // lfs f3, 0x38(r31)
    gc_env.f[3] = *(float*)&temp;
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[31] + 0x20); // lfs f2, 0x20(r31)
    gc_env.f[2] = *(float*)&temp;
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[31] + 0x3C); // lfs f1, 0x3C(r31)
    gc_env.f[1] = *(float*)&temp;
    gc_env.f[4] = (float)gc_env.f[3] - (float)gc_env.f[2]; // fsubs f4, f3, f2
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[31] + 0x24); // lfs f0, 0x24(r31)
    gc_env.f[0] = *(float*)&temp;
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[31] + 0x40); // lfs f2, 0x40(r31)
    gc_env.f[2] = *(float*)&temp;
    gc_env.f[3] = (float)gc_env.f[1] - (float)gc_env.f[0]; // fsubs f3, f1, f0
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[31] + 0x28); // lfs f0, 0x28(r31)
    gc_env.f[0] = *(float*)&temp;
    gc_env.f[2] = (float)gc_env.f[2] - (float)gc_env.f[0]; // fsubs f2, f2, f0
    gc_env.f[1] = (float)gc_env.f[4] * (float)gc_env.f[4]; // fmuls f1, f4, f4
    gc_env.f[0] = (float)gc_env.f[3] * (float)gc_env.f[3]; // fmuls f0, f3, f3
    gc_env.f[2] = (float)gc_env.f[2] * (float)gc_env.f[2]; // fmuls f2, f2, f2
    gc_env.f[0] = (float)gc_env.f[1] + (float)gc_env.f[0]; // fadds f0, f1, f0
    gc_env.f[1] = (float)gc_env.f[2] + (float)gc_env.f[0]; // fadds f1, f2, f0
    sqrtf__Ff();
    float temp = (float)gc_env.f[1]; // stfs f1, 0x2C0(r31)
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x2C0, *(uint32_t*)&temp);
    L_8002D770:
    gc_env.r[3] = gc_env.r[26]; // Move register
    Camera_8002B1F8();
    Stage_GetCamTrackSmooth();
    gc_env.r[4] = gc_env.r[26] + 0; // addi r4, r26, 0x0
    gc_env.r[3] = gc_env.r[1] + 44; // addi r3, r1, 0x2c
    Camera_80029AAC();
    Stage_GetCamTrackSmooth();
    gc_env.r[4] = gc_env.r[26] + 0; // addi r4, r26, 0x0
    gc_env.r[3] = gc_env.r[1] + 44; // addi r3, r1, 0x2c
    Camera_80029C88();
    Stage_GetCamTrackSmooth();
    gc_env.r[4] = gc_env.r[29] + 0; // addi r4, r29, 0x0
    gc_env.r[3] = gc_env.r[1] + 68; // addi r3, r1, 0x44
    Camera_80029AAC();
    Stage_GetCamTrackSmooth();
    gc_env.r[4] = gc_env.r[29] + 0; // addi r4, r29, 0x0
    gc_env.r[3] = gc_env.r[1] + 68; // addi r3, r1, 0x44
    Camera_80029C88();
    gc_env.r[3] = gc_env.r[1] + 44; // addi r3, r1, 0x2c
    Camera_8002A28C();
    gc_env.r[3] = gc_env.r[1] + 44; // addi r3, r1, 0x2c
    gc_env.r[4] = gc_env.r[26] + 0; // addi r4, r26, 0x0
    Camera_8002A0C0();
    gc_env.r[26] = gc_env.r[31] + 696; // addi r26, r31, 0x2b8
    gc_env.r[0] = (int32_t)(int16_t)gc_mem_read16(gc_env.ram, gc_env.r[31] + 0x2B8); // lha r0, 0x2B8(r31)
    gc_env.cr[0] = (gc_env.r[0] == 0x3e8) ? 0 : (gc_env.r[0] < 0x3e8 ? -1 : 1); // Compare with immediate
    if (gc_env.cr[0] & (0x8 | 0x2)) goto L_8002D7EC; // ble .L_8002D7EC
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[31] + 0x2B0); // lfs f0, 0x2B0(r31)
    gc_env.f[0] = *(float*)&temp;
    gc_env.r[0] = 0x1;
    float temp = (float)gc_env.f[0]; // stfs f0, 0x2B4(r31)
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x2B4, *(uint32_t*)&temp);
    gc_mem_write16(gc_env.ram, gc_env.r[26] + 0x0, gc_env.r[0]);
    L_8002D7EC:
    Stage_GetCamBoundsLeftOffset();
    gc_env.f[31] = gc_env.f[1]; // fmr f31, f1
    Stage_GetCamBoundsRightOffset();
    gc_env.f[1] = (float)gc_env.f[1] - (float)gc_env.f[31]; // fsubs f1, f1, f31
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[31] + 0x2B4); // lfs f0, 0x2B4(r31)
    gc_env.f[0] = *(float*)&temp;
    gc_env.r[0] = 17200 << 16; // lis r0, 0x4330
    gc_env.f[0] = (float)gc_env.f[0] + (float)gc_env.f[1]; // fadds f0, f0, f1
    float temp = (float)gc_env.f[0]; // stfs f0, 0x2B4(r31)
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x2B4, *(uint32_t*)&temp);
    gc_env.r[3] = (int32_t)(int16_t)gc_mem_read16(gc_env.ram, gc_env.r[26] + 0x0); // lha r3, 0x0(r26)
    gc_env.r[3] += 1; // addi r3, r3, 0x1
    gc_mem_write16(gc_env.ram, gc_env.r[26] + 0x0, gc_env.r[3]);
    gc_env.r[3] = (int32_t)(int16_t)gc_mem_read16(gc_env.ram, gc_env.r[26] + 0x0); // lha r3, 0x0(r26)
    gc_env.d[1] = cm_804D7E20; // lfd f1, cm_804D7E20@sda21(r0)
    gc_env.r[3] = gc_env.r[3] ^ 0x80000000; // xoris r3, r3, 0x8000
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[31] + 0x2B4); // lfs f2, 0x2B4(r31)
    gc_env.f[2] = *(float*)&temp;
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x84, gc_env.r[3]);
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x80, gc_env.r[0]);
    uint64_t temp = gc_mem_read64(gc_env.ram, gc_env.r[1] + 0x80); // lfd f0, 0x80(r1)
    gc_env.d[0] = *(double*)&temp;
    gc_env.f[0] = (float)gc_env.f[0] - (float)gc_env.f[1]; // fsubs f0, f0, f1
    gc_env.f[0] = (float)gc_env.f[2] / (float)gc_env.f[0]; // fdivs f0, f2, f0
    float temp = (float)gc_env.f[0]; // stfs f0, 0x2B0(r31)
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x2B0, *(uint32_t*)&temp);
    L_8002D840:
    gc_env.r[26] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x88); // lmw r26, 0x88(r1)
    gc_env.r[27] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x8C); // lmw r26, 0x88(r1)
    gc_env.r[28] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x90); // lmw r26, 0x88(r1)
    gc_env.r[29] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x94); // lmw r26, 0x88(r1)
    gc_env.r[30] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x98); // lmw r26, 0x88(r1)
    gc_env.r[31] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x9C); // lmw r26, 0x88(r1)
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0xb4);
    uint64_t temp = gc_mem_read64(gc_env.ram, gc_env.r[1] + 0xA8); // lfd f31, 0xA8(r1)
    gc_env.d[31] = *(double*)&temp;
    uint64_t temp = gc_mem_read64(gc_env.ram, gc_env.r[1] + 0xA0); // lfd f30, 0xA0(r1)
    gc_env.d[30] = *(double*)&temp;
    gc_env.r[1] += 176; // addi r1, r1, 0xb0
    gc_env.lr = gc_env.r[0]; // Move to link register
    return;
}

// Function: Camera_8002D85C
void Camera_8002D85C(void) {
    gc_env.r[0] = gc_env.lr; // Move from link register
    gc_env.r[3] = ((uint32_t)&cm_80452C68 >> 16) & 0xFFFF; // lis r3, cm_80452C68@ha
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x4, gc_env.r[0]);
    gc_mem_write32(gc_env.ram, gc_env.r[1] + -0xb0, gc_env.r[1]);
    gc_env.r[1] = gc_env.r[1] + -0xb0;
    uint64_t temp;
    memcpy(&temp, &gc_env.f[31], sizeof(double));
    gc_mem_write64(gc_env.ram, gc_env.r[1] + 0xA8, temp); // stfd f31, 0xA8(r1)
    uint64_t temp;
    memcpy(&temp, &gc_env.f[30], sizeof(double));
    gc_mem_write64(gc_env.ram, gc_env.r[1] + 0xA0, temp); // stfd f30, 0xA0(r1)
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x8C, gc_env.r[27]); // stmw r27, 0x8C(r1)
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x90, gc_env.r[28]); // stmw r27, 0x8C(r1)
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x94, gc_env.r[29]); // stmw r27, 0x8C(r1)
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x98, gc_env.r[30]); // stmw r27, 0x8C(r1)
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x9C, gc_env.r[31]); // stmw r27, 0x8C(r1)
    gc_env.r[31] = gc_env.r[3] + ((uint32_t)&cm_80452C68 & 0xFFFF); // addi r31, r3, cm_80452C68@l
    gc_env.r[29] = gc_env.r[31] + 708; // addi r29, r31, 0x2c4
    gc_env.r[3] = gc_mem_read8(gc_env.ram, gc_env.r[31] + 0x2c4);
    // Unknown opcode: extsb r3 r3
    Player_GetEntity();
    gc_env.cr[0] = ((uint32_t)gc_env.r[3] == 0x0) ? 0 : ((uint32_t)gc_env.r[3] < 0x0 ? -1 : 1); // Logical compare with immediate
    if (gc_env.cr[0] == 0) goto L_8002DB1C;
    ftLib_80086B74();
    gc_env.r[30] = gc_env.r[3]; // Move register
    if (gc_env.cr[0] == 0) goto L_8002DB1C;
    gc_env.r[3] = gc_env.r[30] + 28; // addi r3, r30, 0x1c
    gc_env.r[4] = 0x0;
    Camera_80029124();
    gc_env.cr[0] = ((uint32_t)gc_env.r[3] == 0x0) ? 0 : ((uint32_t)gc_env.r[3] < 0x0 ? -1 : 1); // Logical compare with immediate
    if (gc_env.cr[0] != 0) goto L_8002DB1C;
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[30] + 0x24); // lfs f1, 0x24(r30)
    gc_env.f[1] = *(float*)&temp;
    gc_env.f[0] = cm_804D7E14; // lfs f0, cm_804D7E14@sda21(r0)
    gc_env.cr[0] = isnan(gc_env.f[1]) || isnan(gc_env.f[0]) ? 0x1 : (gc_env.f[1] < gc_env.f[0] ? 0x8 : (gc_env.f[1] > gc_env.f[0] ? 0x4 : 0x2)); // fcmpo cr0, f1, f0
    if (gc_env.cr[0] >= 0) goto L_8002D8C8;
    gc_env.f[1] = -gc_env.f[1]; // fneg f1, f1
    L_8002D8C8:
    gc_env.f[0] = cm_804D7E70; // lfs f0, cm_804D7E70@sda21(r0)
    gc_env.cr[0] = isnan(gc_env.f[1]) || isnan(gc_env.f[0]) ? 0x1 : (gc_env.f[1] < gc_env.f[0] ? 0x8 : (gc_env.f[1] > gc_env.f[0] ? 0x4 : 0x2)); // fcmpo cr0, f1, f0
    if (gc_env.cr[0] >= 0) goto L_8002DB1C;
    Camera_80030DF8();
    gc_env.r[3] = gc_mem_read8(gc_env.ram, gc_env.r[29] + 0x0);
    // Unknown opcode: extsb r3 r3
    Player_GetEntity();
    gc_env.cr[0] = ((uint32_t)gc_env.r[3] == 0x0) ? 0 : ((uint32_t)gc_env.r[3] < 0x0 ? -1 : 1); // Logical compare with immediate
    if (gc_env.cr[0] == 0) goto L_8002D964;
    ftLib_80086B74();
    gc_env.cr[0] = ((uint32_t)gc_env.r[3] == 0x0) ? 0 : ((uint32_t)gc_env.r[3] < 0x0 ? -1 : 1); // Logical compare with immediate
    if (gc_env.cr[0] == 0) goto L_8002D964;
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[3] + 0x1C); // lfs f0, 0x1C(r3)
    gc_env.f[0] = *(float*)&temp;
    gc_env.r[4] = gc_env.r[3] + 28; // addi r4, r3, 0x1c
    gc_env.r[3] = ((uint32_t)&cm_803BCCA0 >> 16) & 0xFFFF; // lis r3, cm_803BCCA0@ha
    float temp = (float)gc_env.f[0]; // stfs f0, 0x20(r31)
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x20, *(uint32_t*)&temp);
    gc_env.r[3] = gc_env.r[3] + ((uint32_t)&cm_803BCCA0 & 0xFFFF); // addi r3, r3, cm_803BCCA0@l
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[4] + 0x4); // lfs f0, 0x4(r4)
    gc_env.f[0] = *(float*)&temp;
    float temp = (float)gc_env.f[0]; // stfs f0, 0x24(r31)
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x24, *(uint32_t*)&temp);
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[4] + 0x8); // lfs f0, 0x8(r4)
    gc_env.f[0] = *(float*)&temp;
    float temp = (float)gc_env.f[0]; // stfs f0, 0x28(r31)
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x28, *(uint32_t*)&temp);
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[31] + 0x20); // lfs f0, 0x20(r31)
    gc_env.f[0] = *(float*)&temp;
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[31] + 0x14); // lfs f1, 0x14(r31)
    gc_env.f[1] = *(float*)&temp;
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[3] + 0x64); // lfs f6, 0x64(r3)
    gc_env.f[6] = *(float*)&temp;
    gc_env.f[0] = (float)gc_env.f[0] - (float)gc_env.f[1]; // fsubs f0, f0, f1
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[31] + 0x24); // lfs f5, 0x24(r31)
    gc_env.f[5] = *(float*)&temp;
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[31] + 0x18); // lfs f4, 0x18(r31)
    gc_env.f[4] = *(float*)&temp;
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[31] + 0x28); // lfs f3, 0x28(r31)
    gc_env.f[3] = *(float*)&temp;
    gc_env.f[0] = (float)gc_env.f[0] * (float)gc_env.f[6] + (float)gc_env.f[1]; // fmadds f0, f0, f6, f1
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[31] + 0x1C); // lfs f2, 0x1C(r31)
    gc_env.f[2] = *(float*)&temp;
    gc_env.f[4] = (float)gc_env.f[5] - (float)gc_env.f[4]; // fsubs f4, f5, f4
    float temp = (float)gc_env.f[0]; // stfs f0, 0x14(r31)
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x14, *(uint32_t*)&temp);
    gc_env.f[1] = (float)gc_env.f[3] - (float)gc_env.f[2]; // fsubs f1, f3, f2
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[31] + 0x18); // lfs f0, 0x18(r31)
    gc_env.f[0] = *(float*)&temp;
    gc_env.f[0] = (float)gc_env.f[4] * (float)gc_env.f[6] + (float)gc_env.f[0]; // fmadds f0, f4, f6, f0
    float temp = (float)gc_env.f[0]; // stfs f0, 0x18(r31)
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x18, *(uint32_t*)&temp);
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[31] + 0x1C); // lfs f0, 0x1C(r31)
    gc_env.f[0] = *(float*)&temp;
    gc_env.f[0] = (float)gc_env.f[1] * (float)gc_env.f[6] + (float)gc_env.f[0]; // fmadds f0, f1, f6, f0
    float temp = (float)gc_env.f[0]; // stfs f0, 0x1C(r31)
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x1C, *(uint32_t*)&temp);
    L_8002D964:
    gc_env.r[3] = ((uint32_t)&cm_803BCCA0 >> 16) & 0xFFFF; // lis r3, cm_803BCCA0@ha
    gc_env.r[3] = gc_env.r[3] + ((uint32_t)&cm_803BCCA0 & 0xFFFF); // addi r3, r3, cm_803BCCA0@l
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[3] + 0x6C); // lfs f0, 0x6C(r3)
    gc_env.f[0] = *(float*)&temp;
    gc_env.r[28] = gc_env.r[31] + 72; // addi r28, r31, 0x48
    float temp = (float)gc_env.f[0]; // stfs f0, 0x48(r31)
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x48, *(uint32_t*)&temp);
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[31] + 0x48); // lfs f1, 0x48(r31)
    gc_env.f[1] = *(float*)&temp;
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[31] + 0x44); // lfs f2, 0x44(r31)
    gc_env.f[2] = *(float*)&temp;
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[3] + 0x70); // lfs f0, 0x70(r3)
    gc_env.f[0] = *(float*)&temp;
    gc_env.f[1] = (float)gc_env.f[1] - (float)gc_env.f[2]; // fsubs f1, f1, f2
    gc_env.f[0] = (float)gc_env.f[1] * (float)gc_env.f[0] + (float)gc_env.f[2]; // fmadds f0, f1, f0, f2
    float temp = (float)gc_env.f[0]; // stfs f0, 0x44(r31)
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x44, *(uint32_t*)&temp);
    gc_env.r[3] = gc_mem_read8(gc_env.ram, gc_env.r[29] + 0x0);
    // Unknown opcode: extsb r3 r3
    gc_env.cr[0] = (gc_env.r[3] == 0xa) ? 0 : (gc_env.r[3] < 0xa ? -1 : 1); // Compare with immediate
    if (gc_env.cr[0] == 0) goto L_8002D9F4;
    gc_env.cr[0] = (gc_env.r[3] == 0xb) ? 0 : (gc_env.r[3] < 0xb ? -1 : 1); // Compare with immediate
    if (gc_env.cr[0] == 0) goto L_8002D9F4;
    gc_env.cr[0] = (gc_env.r[3] == 0x0) ? 0 : (gc_env.r[3] < 0x0 ? -1 : 1); // Compare with immediate
    if (gc_env.cr[0] & 0x8) goto L_8002D9F4; // blt .L_8002D9F4
    gc_env.cr[0] = (gc_env.r[3] == 0x6) ? 0 : (gc_env.r[3] < 0x6 ? -1 : 1); // Compare with immediate
    if (gc_env.cr[0] >= 0) goto L_8002D9F4;
    Player_GetEntity();
    gc_env.cr[0] = ((uint32_t)gc_env.r[3] == 0x0) ? 0 : ((uint32_t)gc_env.r[3] < 0x0 ? -1 : 1); // Logical compare with immediate
    if (gc_env.cr[0] == 0) goto L_8002D9F4;
    ftLib_80086B74();
    gc_env.r[30] = gc_env.r[3]; // Move register
    if (gc_env.cr[0] == 0) goto L_8002D9F4;
    gc_env.f[1] = cm_804D7E60; // lfs f1, cm_804D7E60@sda21(r0)
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[28] + 0x0); // lfs f0, 0x0(r28)
    gc_env.f[0] = *(float*)&temp;
    gc_env.f[1] = (float)gc_env.f[1] * (float)gc_env.f[0]; // fmuls f1, f1, f0
    tanf();
    gc_env.f[2] = cm_804D7EA8; // lfs f2, cm_804D7EA8@sda21(r0)
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[30] + 0x3C); // lfs f0, 0x3C(r30)
    gc_env.f[0] = *(float*)&temp;
    gc_env.f[0] = (float)gc_env.f[2] * (float)gc_env.f[0]; // fmuls f0, f2, f0
    gc_env.f[30] = (float)gc_env.f[0] / (float)gc_env.f[1]; // fdivs f30, f0, f1
    goto L_8002D9F8;
    L_8002D9F4:
    gc_env.f[30] = cm_804D7E5C; // lfs f30, cm_804D7E5C@sda21(r0)
    L_8002D9F8:
    Stage_GetCamAngleRadiansUp();
    gc_env.r[28] = gc_env.r[31] + 712; // addi r28, r31, 0x2c8
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[31] + 0x2C8); // lfs f0, 0x2C8(r31)
    gc_env.f[0] = *(float*)&temp;
    gc_env.cr[0] = isnan(gc_env.f[0]) || isnan(gc_env.f[1]) ? 0x1 : (gc_env.f[0] < gc_env.f[1] ? 0x8 : (gc_env.f[0] > gc_env.f[1] ? 0x4 : 0x2)); // fcmpo cr0, f0, f1
    if (gc_env.cr[0] & (0x8 | 0x2)) goto L_8002DA18; // ble .L_8002DA18
    Stage_GetCamAngleRadiansUp();
    float temp = (float)gc_env.f[1]; // stfs f1, 0x0(r28)
    gc_mem_write32(gc_env.ram, gc_env.r[28] + 0x0, *(uint32_t*)&temp);
    goto L_8002DA38;
    L_8002DA18:
    Stage_GetCamAngleRadiansDown();
    gc_env.f[1] = -gc_env.f[1]; // fneg f1, f1
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[28] + 0x0); // lfs f0, 0x0(r28)
    gc_env.f[0] = *(float*)&temp;
    gc_env.cr[0] = isnan(gc_env.f[0]) || isnan(gc_env.f[1]) ? 0x1 : (gc_env.f[0] < gc_env.f[1] ? 0x8 : (gc_env.f[0] > gc_env.f[1] ? 0x4 : 0x2)); // fcmpo cr0, f0, f1
    if (gc_env.cr[0] >= 0) goto L_8002DA38;
    Stage_GetCamAngleRadiansDown();
    gc_env.f[0] = -gc_env.f[1]; // fneg f0, f1
    float temp = (float)gc_env.f[0]; // stfs f0, 0x0(r28)
    gc_mem_write32(gc_env.ram, gc_env.r[28] + 0x0, *(uint32_t*)&temp);
    L_8002DA38:
    Stage_GetCamAngleRadiansLeft();
    gc_env.r[29] = gc_env.r[31] + 716; // addi r29, r31, 0x2cc
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[31] + 0x2CC); // lfs f0, 0x2CC(r31)
    gc_env.f[0] = *(float*)&temp;
    gc_env.cr[0] = isnan(gc_env.f[0]) || isnan(gc_env.f[1]) ? 0x1 : (gc_env.f[0] < gc_env.f[1] ? 0x8 : (gc_env.f[0] > gc_env.f[1] ? 0x4 : 0x2)); // fcmpo cr0, f0, f1
    if (gc_env.cr[0] & (0x8 | 0x2)) goto L_8002DA58; // ble .L_8002DA58
    Stage_GetCamAngleRadiansLeft();
    float temp = (float)gc_env.f[1]; // stfs f1, 0x0(r29)
    gc_mem_write32(gc_env.ram, gc_env.r[29] + 0x0, *(uint32_t*)&temp);
    goto L_8002DA78;
    L_8002DA58:
    Stage_GetCamAngleRadiansRight();
    gc_env.f[1] = -gc_env.f[1]; // fneg f1, f1
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[29] + 0x0); // lfs f0, 0x0(r29)
    gc_env.f[0] = *(float*)&temp;
    gc_env.cr[0] = isnan(gc_env.f[0]) || isnan(gc_env.f[1]) ? 0x1 : (gc_env.f[0] < gc_env.f[1] ? 0x8 : (gc_env.f[0] > gc_env.f[1] ? 0x4 : 0x2)); // fcmpo cr0, f0, f1
    if (gc_env.cr[0] >= 0) goto L_8002DA78;
    Stage_GetCamAngleRadiansRight();
    gc_env.f[0] = -gc_env.f[1]; // fneg f0, f1
    float temp = (float)gc_env.f[0]; // stfs f0, 0x0(r29)
    gc_mem_write32(gc_env.ram, gc_env.r[29] + 0x0, *(uint32_t*)&temp);
    L_8002DA78:
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[28] + 0x0); // lfs f1, 0x0(r28)
    gc_env.f[1] = *(float*)&temp;
    cosf();
    gc_env.f[31] = (float)gc_env.f[30] * (float)gc_env.f[1]; // fmuls f31, f30, f1
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[29] + 0x0); // lfs f1, 0x0(r29)
    gc_env.f[1] = *(float*)&temp;
    sinf();
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[31] + 0x20); // lfs f0, 0x20(r31)
    gc_env.f[0] = *(float*)&temp;
    gc_env.r[30] = gc_env.r[31] + 56; // addi r30, r31, 0x38
    gc_env.f[0] = (float)gc_env.f[31] * (float)gc_env.f[1] + (float)gc_env.f[0]; // fmadds f0, f31, f1, f0
    float temp = (float)gc_env.f[0]; // stfs f0, 0x38(r31)
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x38, *(uint32_t*)&temp);
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[28] + 0x0); // lfs f1, 0x0(r28)
    gc_env.f[1] = *(float*)&temp;
    sinf();
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[31] + 0x24); // lfs f0, 0x24(r31)
    gc_env.f[0] = *(float*)&temp;
    gc_env.r[28] = gc_env.r[31] + 60; // addi r28, r31, 0x3c
    gc_env.f[0] = (float)gc_env.f[30] * (float)gc_env.f[1] + (float)gc_env.f[0]; // fmadds f0, f30, f1, f0
    float temp = (float)gc_env.f[0]; // stfs f0, 0x3C(r31)
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x3C, *(uint32_t*)&temp);
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[29] + 0x0); // lfs f1, 0x0(r29)
    gc_env.f[1] = *(float*)&temp;
    cosf();
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[31] + 0x28); // lfs f0, 0x28(r31)
    gc_env.f[0] = *(float*)&temp;
    gc_env.r[3] = ((uint32_t)&cm_803BCCA0 >> 16) & 0xFFFF; // lis r3, cm_803BCCA0@ha
    gc_env.r[3] = gc_env.r[3] + ((uint32_t)&cm_803BCCA0 & 0xFFFF); // addi r3, r3, cm_803BCCA0@l
    gc_env.f[0] = (float)gc_env.f[31] * (float)gc_env.f[1] + (float)gc_env.f[0]; // fmadds f0, f31, f1, f0
    float temp = (float)gc_env.f[0]; // stfs f0, 0x40(r31)
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x40, *(uint32_t*)&temp);
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[30] + 0x0); // lfs f0, 0x0(r30)
    gc_env.f[0] = *(float*)&temp;
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[31] + 0x2C); // lfs f1, 0x2C(r31)
    gc_env.f[1] = *(float*)&temp;
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[3] + 0x68); // lfs f6, 0x68(r3)
    gc_env.f[6] = *(float*)&temp;
    gc_env.f[0] = (float)gc_env.f[0] - (float)gc_env.f[1]; // fsubs f0, f0, f1
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[28] + 0x0); // lfs f5, 0x0(r28)
    gc_env.f[5] = *(float*)&temp;
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[31] + 0x30); // lfs f4, 0x30(r31)
    gc_env.f[4] = *(float*)&temp;
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[31] + 0x40); // lfs f3, 0x40(r31)
    gc_env.f[3] = *(float*)&temp;
    gc_env.f[0] = (float)gc_env.f[0] * (float)gc_env.f[6] + (float)gc_env.f[1]; // fmadds f0, f0, f6, f1
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[31] + 0x34); // lfs f2, 0x34(r31)
    gc_env.f[2] = *(float*)&temp;
    gc_env.f[4] = (float)gc_env.f[5] - (float)gc_env.f[4]; // fsubs f4, f5, f4
    float temp = (float)gc_env.f[0]; // stfs f0, 0x2C(r31)
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x2C, *(uint32_t*)&temp);
    gc_env.f[1] = (float)gc_env.f[3] - (float)gc_env.f[2]; // fsubs f1, f3, f2
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[31] + 0x30); // lfs f0, 0x30(r31)
    gc_env.f[0] = *(float*)&temp;
    gc_env.f[0] = (float)gc_env.f[4] * (float)gc_env.f[6] + (float)gc_env.f[0]; // fmadds f0, f4, f6, f0
    float temp = (float)gc_env.f[0]; // stfs f0, 0x30(r31)
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x30, *(uint32_t*)&temp);
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[31] + 0x34); // lfs f0, 0x34(r31)
    gc_env.f[0] = *(float*)&temp;
    gc_env.f[0] = (float)gc_env.f[1] * (float)gc_env.f[6] + (float)gc_env.f[0]; // fmadds f0, f1, f6, f0
    float temp = (float)gc_env.f[0]; // stfs f0, 0x34(r31)
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x34, *(uint32_t*)&temp);
    goto L_8002DDA8;
    L_8002DB1C:
    Camera_80030DF8();
    Camera_800293E0();
    Camera_8002B0E0();
    gc_env.r[28] = gc_env.r[31] + 20; // addi r28, r31, 0x14
    gc_env.r[4] = gc_env.r[28] + 0; // addi r4, r28, 0x0
    gc_env.r[3] = gc_env.r[1] + 44; // addi r3, r1, 0x2c
    Camera_8002958C();
    gc_env.r[3] = ((uint32_t)&cm_803BCCA0 >> 16) & 0xFFFF; // lis r3, cm_803BCCA0@ha
    gc_env.r[3] = gc_env.r[3] + ((uint32_t)&cm_803BCCA0 & 0xFFFF); // addi r3, r3, cm_803BCCA0@l
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[3] + 0x40); // lfs f0, 0x40(r3)
    gc_env.f[0] = *(float*)&temp;
    gc_env.r[30] = gc_env.r[3] + 68; // addi r30, r3, 0x44
    gc_env.r[29] = gc_env.r[3] + 64; // addi r29, r3, 0x40
    float temp = (float)gc_env.f[0]; // stfs f0, 0x48(r31)
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x48, *(uint32_t*)&temp);
    gc_env.r[4] = gc_env.r[28] + 0; // addi r4, r28, 0x0
    gc_env.r[3] = gc_env.r[1] + 44; // addi r3, r1, 0x2c
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[31] + 0x48); // lfs f1, 0x48(r31)
    gc_env.f[1] = *(float*)&temp;
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[31] + 0x44); // lfs f2, 0x44(r31)
    gc_env.f[2] = *(float*)&temp;
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[30] + 0x0); // lfs f0, 0x0(r30)
    gc_env.f[0] = *(float*)&temp;
    gc_env.f[1] = (float)gc_env.f[1] - (float)gc_env.f[2]; // fsubs f1, f1, f2
    gc_env.f[0] = (float)gc_env.f[1] * (float)gc_env.f[0] + (float)gc_env.f[2]; // fmadds f0, f1, f0, f2
    float temp = (float)gc_env.f[0]; // stfs f0, 0x44(r31)
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x44, *(uint32_t*)&temp);
    Camera_80029BC4();
    Camera_80030AF8();
    gc_env.cr[0] = (gc_env.r[3] == 0x0) ? 0 : (gc_env.r[3] < 0x0 ? -1 : 1); // Compare with immediate
    if (gc_env.cr[0] == 0) goto L_8002DBBC;
    Ground_801C57A4();
    gc_env.cr[0] = ((uint32_t)gc_env.r[3] == 0x0) ? 0 : ((uint32_t)gc_env.r[3] < 0x0 ? -1 : 1); // Logical compare with immediate
    if (gc_env.cr[0] == 0) goto L_8002DBBC;
    gc_env.r[4] = gc_env.r[1] + 28; // addi r4, r1, 0x1c
    ftLib_80086644();
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x24); // lfs f1, 0x24(r1)
    gc_env.f[1] = *(float*)&temp;
    gc_env.f[0] = cm_804D7E14; // lfs f0, cm_804D7E14@sda21(r0)
    gc_env.cr[0] = isnan(gc_env.f[1]) || isnan(gc_env.f[0]) ? 0x1 : (gc_env.f[1] < gc_env.f[0] ? 0x8 : (gc_env.f[1] > gc_env.f[0] ? 0x4 : 0x2)); // fcmpo cr0, f1, f0
    if (gc_env.cr[0] >= 0) goto L_8002DBA8;
    gc_env.f[1] = -gc_env.f[1]; // fneg f1, f1
    L_8002DBA8:
    gc_env.f[0] = cm_804D7E70; // lfs f0, cm_804D7E70@sda21(r0)
    gc_env.cr[0] = isnan(gc_env.f[1]) || isnan(gc_env.f[0]) ? 0x1 : (gc_env.f[1] < gc_env.f[0] ? 0x8 : (gc_env.f[1] > gc_env.f[0] ? 0x4 : 0x2)); // fcmpo cr0, f1, f0
    if (gc_env.cr[0] & (0x8 | 0x2)) goto L_8002DBBC; // ble .L_8002DBBC
    gc_env.r[0] = 0x1;
    goto L_8002DBC0;
    L_8002DBBC:
    gc_env.r[0] = 0x0;
    L_8002DBC0:
    gc_env.cr[0] = (gc_env.r[0] == 0x0) ? 0 : (gc_env.r[0] < 0x0 ? -1 : 1); // Compare with immediate
    if (gc_env.cr[0] != 0) goto L_8002DBE0;
    gc_env.r[3] = gc_env.r[1] + 44; // addi r3, r1, 0x2c
    gc_env.r[4] = gc_env.r[28] + 0; // addi r4, r28, 0x0
    Camera_80029CF8();
    gc_env.r[3] = gc_env.r[28] + 0; // addi r3, r28, 0x0
    gc_env.r[4] = 0x0;
    Camera_8002A768();
    L_8002DBE0:
    gc_env.r[27] = gc_env.r[31] + 76; // addi r27, r31, 0x4c
    gc_env.r[4] = gc_env.r[27] + 0; // addi r4, r27, 0x0
    gc_env.r[3] = gc_env.r[1] + 68; // addi r3, r1, 0x44
    Camera_8002958C();
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[29] + 0x0); // lfs f0, 0x0(r29)
    gc_env.f[0] = *(float*)&temp;
    gc_env.r[4] = gc_env.r[27] + 0; // addi r4, r27, 0x0
    gc_env.r[3] = gc_env.r[1] + 68; // addi r3, r1, 0x44
    float temp = (float)gc_env.f[0]; // stfs f0, 0x80(r31)
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x80, *(uint32_t*)&temp);
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[31] + 0x80); // lfs f1, 0x80(r31)
    gc_env.f[1] = *(float*)&temp;
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[31] + 0x7C); // lfs f2, 0x7C(r31)
    gc_env.f[2] = *(float*)&temp;
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[30] + 0x0); // lfs f0, 0x0(r30)
    gc_env.f[0] = *(float*)&temp;
    gc_env.f[1] = (float)gc_env.f[1] - (float)gc_env.f[2]; // fsubs f1, f1, f2
    gc_env.f[0] = (float)gc_env.f[1] * (float)gc_env.f[0] + (float)gc_env.f[2]; // fmadds f0, f1, f0, f2
    float temp = (float)gc_env.f[0]; // stfs f0, 0x7C(r31)
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x7C, *(uint32_t*)&temp);
    Camera_80029BC4();
    Camera_80030AF8();
    gc_env.cr[0] = (gc_env.r[3] == 0x0) ? 0 : (gc_env.r[3] < 0x0 ? -1 : 1); // Compare with immediate
    if (gc_env.cr[0] == 0) goto L_8002DC64;
    Ground_801C57A4();
    gc_env.cr[0] = ((uint32_t)gc_env.r[3] == 0x0) ? 0 : ((uint32_t)gc_env.r[3] < 0x0 ? -1 : 1); // Logical compare with immediate
    if (gc_env.cr[0] == 0) goto L_8002DC64;
    gc_env.r[4] = gc_env.r[1] + 12; // addi r4, r1, 0xc
    ftLib_80086644();
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x14); // lfs f1, 0x14(r1)
    gc_env.f[1] = *(float*)&temp;
    gc_env.f[0] = cm_804D7E14; // lfs f0, cm_804D7E14@sda21(r0)
    gc_env.cr[0] = isnan(gc_env.f[1]) || isnan(gc_env.f[0]) ? 0x1 : (gc_env.f[1] < gc_env.f[0] ? 0x8 : (gc_env.f[1] > gc_env.f[0] ? 0x4 : 0x2)); // fcmpo cr0, f1, f0
    if (gc_env.cr[0] >= 0) goto L_8002DC50;
    gc_env.f[1] = -gc_env.f[1]; // fneg f1, f1
    L_8002DC50:
    gc_env.f[0] = cm_804D7E70; // lfs f0, cm_804D7E70@sda21(r0)
    gc_env.cr[0] = isnan(gc_env.f[1]) || isnan(gc_env.f[0]) ? 0x1 : (gc_env.f[1] < gc_env.f[0] ? 0x8 : (gc_env.f[1] > gc_env.f[0] ? 0x4 : 0x2)); // fcmpo cr0, f1, f0
    if (gc_env.cr[0] & (0x8 | 0x2)) goto L_8002DC64; // ble .L_8002DC64
    gc_env.r[0] = 0x1;
    goto L_8002DC68;
    L_8002DC64:
    gc_env.r[0] = 0x0;
    L_8002DC68:
    gc_env.cr[0] = (gc_env.r[0] == 0x0) ? 0 : (gc_env.r[0] < 0x0 ? -1 : 1); // Compare with immediate
    if (gc_env.cr[0] != 0) goto L_8002DC88;
    gc_env.r[3] = gc_env.r[1] + 68; // addi r3, r1, 0x44
    gc_env.r[4] = gc_env.r[27] + 0; // addi r4, r27, 0x0
    Camera_80029CF8();
    gc_env.r[3] = gc_env.r[27] + 0; // addi r3, r27, 0x0
    gc_env.r[4] = 0x0;
    Camera_8002A768();
    L_8002DC88:
    gc_env.f[1] = cm_804D7E04; // lfs f1, cm_804D7E04@sda21(r0)
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[31] + 0x2BC); // lfs f0, 0x2BC(r31)
    gc_env.f[0] = *(float*)&temp;
    gc_env.cr[0] = isnan(gc_env.f[1]) || isnan(gc_env.f[0]) ? 0x1 : (gc_env.f[1] < gc_env.f[0] ? 0x8 : (gc_env.f[1] > gc_env.f[0] ? 0x4 : 0x2)); // fcmpu cr0, f1, f0
    if (gc_env.cr[0] != 0) goto L_8002DCD8;
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[31] + 0x38); // lfs f3, 0x38(r31)
    gc_env.f[3] = *(float*)&temp;
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[31] + 0x20); // lfs f2, 0x20(r31)
    gc_env.f[2] = *(float*)&temp;
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[31] + 0x3C); // lfs f1, 0x3C(r31)
    gc_env.f[1] = *(float*)&temp;
    gc_env.f[4] = (float)gc_env.f[3] - (float)gc_env.f[2]; // fsubs f4, f3, f2
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[31] + 0x24); // lfs f0, 0x24(r31)
    gc_env.f[0] = *(float*)&temp;
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[31] + 0x40); // lfs f2, 0x40(r31)
    gc_env.f[2] = *(float*)&temp;
    gc_env.f[3] = (float)gc_env.f[1] - (float)gc_env.f[0]; // fsubs f3, f1, f0
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[31] + 0x28); // lfs f0, 0x28(r31)
    gc_env.f[0] = *(float*)&temp;
    gc_env.f[2] = (float)gc_env.f[2] - (float)gc_env.f[0]; // fsubs f2, f2, f0
    gc_env.f[1] = (float)gc_env.f[4] * (float)gc_env.f[4]; // fmuls f1, f4, f4
    gc_env.f[0] = (float)gc_env.f[3] * (float)gc_env.f[3]; // fmuls f0, f3, f3
    gc_env.f[2] = (float)gc_env.f[2] * (float)gc_env.f[2]; // fmuls f2, f2, f2
    gc_env.f[0] = (float)gc_env.f[1] + (float)gc_env.f[0]; // fadds f0, f1, f0
    gc_env.f[1] = (float)gc_env.f[2] + (float)gc_env.f[0]; // fadds f1, f2, f0
    sqrtf__Ff();
    float temp = (float)gc_env.f[1]; // stfs f1, 0x2C0(r31)
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x2C0, *(uint32_t*)&temp);
    L_8002DCD8:
    gc_env.r[3] = gc_env.r[28]; // Move register
    Camera_8002B1F8();
    Stage_GetCamTrackSmooth();
    gc_env.r[4] = gc_env.r[28] + 0; // addi r4, r28, 0x0
    gc_env.r[3] = gc_env.r[1] + 44; // addi r3, r1, 0x2c
    Camera_80029AAC();
    Stage_GetCamTrackSmooth();
    gc_env.r[4] = gc_env.r[28] + 0; // addi r4, r28, 0x0
    gc_env.r[3] = gc_env.r[1] + 44; // addi r3, r1, 0x2c
    Camera_80029C88();
    Stage_GetCamTrackSmooth();
    gc_env.r[4] = gc_env.r[27] + 0; // addi r4, r27, 0x0
    gc_env.r[3] = gc_env.r[1] + 68; // addi r3, r1, 0x44
    Camera_80029AAC();
    Stage_GetCamTrackSmooth();
    gc_env.r[4] = gc_env.r[27] + 0; // addi r4, r27, 0x0
    gc_env.r[3] = gc_env.r[1] + 68; // addi r3, r1, 0x44
    Camera_80029C88();
    gc_env.r[3] = gc_env.r[1] + 44; // addi r3, r1, 0x2c
    Camera_8002A28C();
    gc_env.r[3] = gc_env.r[1] + 44; // addi r3, r1, 0x2c
    gc_env.r[4] = gc_env.r[28] + 0; // addi r4, r28, 0x0
    Camera_8002A0C0();
    gc_env.r[27] = gc_env.r[31] + 696; // addi r27, r31, 0x2b8
    gc_env.r[0] = (int32_t)(int16_t)gc_mem_read16(gc_env.ram, gc_env.r[31] + 0x2B8); // lha r0, 0x2B8(r31)
    gc_env.cr[0] = (gc_env.r[0] == 0x3e8) ? 0 : (gc_env.r[0] < 0x3e8 ? -1 : 1); // Compare with immediate
    if (gc_env.cr[0] & (0x8 | 0x2)) goto L_8002DD54; // ble .L_8002DD54
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[31] + 0x2B0); // lfs f0, 0x2B0(r31)
    gc_env.f[0] = *(float*)&temp;
    gc_env.r[0] = 0x1;
    float temp = (float)gc_env.f[0]; // stfs f0, 0x2B4(r31)
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x2B4, *(uint32_t*)&temp);
    gc_mem_write16(gc_env.ram, gc_env.r[27] + 0x0, gc_env.r[0]);
    L_8002DD54:
    Stage_GetCamBoundsLeftOffset();
    gc_env.f[31] = gc_env.f[1]; // fmr f31, f1
    Stage_GetCamBoundsRightOffset();
    gc_env.f[1] = (float)gc_env.f[1] - (float)gc_env.f[31]; // fsubs f1, f1, f31
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[31] + 0x2B4); // lfs f0, 0x2B4(r31)
    gc_env.f[0] = *(float*)&temp;
    gc_env.r[0] = 17200 << 16; // lis r0, 0x4330
    gc_env.f[0] = (float)gc_env.f[0] + (float)gc_env.f[1]; // fadds f0, f0, f1
    float temp = (float)gc_env.f[0]; // stfs f0, 0x2B4(r31)
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x2B4, *(uint32_t*)&temp);
    gc_env.r[3] = (int32_t)(int16_t)gc_mem_read16(gc_env.ram, gc_env.r[27] + 0x0); // lha r3, 0x0(r27)
    gc_env.r[3] += 1; // addi r3, r3, 0x1
    gc_mem_write16(gc_env.ram, gc_env.r[27] + 0x0, gc_env.r[3]);
    gc_env.r[3] = (int32_t)(int16_t)gc_mem_read16(gc_env.ram, gc_env.r[27] + 0x0); // lha r3, 0x0(r27)
    gc_env.d[1] = cm_804D7E20; // lfd f1, cm_804D7E20@sda21(r0)
    gc_env.r[3] = gc_env.r[3] ^ 0x80000000; // xoris r3, r3, 0x8000
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[31] + 0x2B4); // lfs f2, 0x2B4(r31)
    gc_env.f[2] = *(float*)&temp;
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x84, gc_env.r[3]);
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x80, gc_env.r[0]);
    uint64_t temp = gc_mem_read64(gc_env.ram, gc_env.r[1] + 0x80); // lfd f0, 0x80(r1)
    gc_env.d[0] = *(double*)&temp;
    gc_env.f[0] = (float)gc_env.f[0] - (float)gc_env.f[1]; // fsubs f0, f0, f1
    gc_env.f[0] = (float)gc_env.f[2] / (float)gc_env.f[0]; // fdivs f0, f2, f0
    float temp = (float)gc_env.f[0]; // stfs f0, 0x2B0(r31)
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x2B0, *(uint32_t*)&temp);
    L_8002DDA8:
    gc_env.r[27] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x8C); // lmw r27, 0x8C(r1)
    gc_env.r[28] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x90); // lmw r27, 0x8C(r1)
    gc_env.r[29] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x94); // lmw r27, 0x8C(r1)
    gc_env.r[30] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x98); // lmw r27, 0x8C(r1)
    gc_env.r[31] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x9C); // lmw r27, 0x8C(r1)
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0xb4);
    uint64_t temp = gc_mem_read64(gc_env.ram, gc_env.r[1] + 0xA8); // lfd f31, 0xA8(r1)
    gc_env.d[31] = *(double*)&temp;
    uint64_t temp = gc_mem_read64(gc_env.ram, gc_env.r[1] + 0xA0); // lfd f30, 0xA0(r1)
    gc_env.d[30] = *(double*)&temp;
    gc_env.r[1] += 176; // addi r1, r1, 0xb0
    gc_env.lr = gc_env.r[0]; // Move to link register
    return;
}

// Function: Camera_8002DDC4
void Camera_8002DDC4(void) {
    gc_env.r[0] = gc_env.lr; // Move from link register
    gc_env.r[3] = ((uint32_t)&cm_80452C68 >> 16) & 0xFFFF; // lis r3, cm_80452C68@ha
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x4, gc_env.r[0]);
    gc_mem_write32(gc_env.ram, gc_env.r[1] + -0x68, gc_env.r[1]);
    gc_env.r[1] = gc_env.r[1] + -0x68;
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x4C, gc_env.r[25]); // stmw r25, 0x4C(r1)
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x50, gc_env.r[26]); // stmw r25, 0x4C(r1)
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x54, gc_env.r[27]); // stmw r25, 0x4C(r1)
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x58, gc_env.r[28]); // stmw r25, 0x4C(r1)
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x5C, gc_env.r[29]); // stmw r25, 0x4C(r1)
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x60, gc_env.r[30]); // stmw r25, 0x4C(r1)
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x64, gc_env.r[31]); // stmw r25, 0x4C(r1)
    gc_env.r[29] = gc_env.r[3] + ((uint32_t)&cm_80452C68 & 0xFFFF); // addi r29, r3, cm_80452C68@l
    Camera_80030DF8();
    gc_env.r[28] = gc_env.r[29] + 20; // addi r28, r29, 0x14
    gc_env.r[31] = gc_env.r[28] + 12; // addi r31, r28, 0xc
    gc_env.r[3] = gc_env.r[31] + 0; // addi r3, r31, 0x0
    Stage_80224CAC();
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[29] + 0x20); // lfs f0, 0x20(r29)
    gc_env.f[0] = *(float*)&temp;
    gc_env.r[3] = ((uint32_t)&cm_803BCCA0 >> 16) & 0xFFFF; // lis r3, cm_803BCCA0@ha
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[28] + 0x0); // lfs f1, 0x0(r28)
    gc_env.f[1] = *(float*)&temp;
    gc_env.r[30] = gc_env.r[3] + ((uint32_t)&cm_803BCCA0 & 0xFFFF); // addi r30, r3, cm_803BCCA0@l
    gc_env.r[26] = gc_env.r[29] + 76; // addi r26, r29, 0x4c
    gc_env.f[0] = (float)gc_env.f[0] - (float)gc_env.f[1]; // fsubs f0, f0, f1
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[30] + 0x74); // lfs f5, 0x74(r30)
    gc_env.f[5] = *(float*)&temp;
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[29] + 0x24); // lfs f4, 0x24(r29)
    gc_env.f[4] = *(float*)&temp;
    gc_env.r[27] = gc_env.r[30] + 116; // addi r27, r30, 0x74
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[29] + 0x18); // lfs f3, 0x18(r29)
    gc_env.f[3] = *(float*)&temp;
    gc_env.f[0] = (float)gc_env.f[0] * (float)gc_env.f[5] + (float)gc_env.f[1]; // fmadds f0, f0, f5, f1
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[29] + 0x28); // lfs f2, 0x28(r29)
    gc_env.f[2] = *(float*)&temp;
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[29] + 0x1C); // lfs f1, 0x1C(r29)
    gc_env.f[1] = *(float*)&temp;
    gc_env.f[3] = (float)gc_env.f[4] - (float)gc_env.f[3]; // fsubs f3, f4, f3
    gc_env.r[3] = gc_env.r[26] + 12; // addi r3, r26, 0xc
    float temp = (float)gc_env.f[0]; // stfs f0, 0x0(r28)
    gc_mem_write32(gc_env.ram, gc_env.r[28] + 0x0, *(uint32_t*)&temp);
    gc_env.f[1] = (float)gc_env.f[2] - (float)gc_env.f[1]; // fsubs f1, f2, f1
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[29] + 0x18); // lfs f0, 0x18(r29)
    gc_env.f[0] = *(float*)&temp;
    gc_env.f[0] = (float)gc_env.f[3] * (float)gc_env.f[5] + (float)gc_env.f[0]; // fmadds f0, f3, f5, f0
    float temp = (float)gc_env.f[0]; // stfs f0, 0x18(r29)
    gc_mem_write32(gc_env.ram, gc_env.r[29] + 0x18, *(uint32_t*)&temp);
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[29] + 0x1C); // lfs f0, 0x1C(r29)
    gc_env.f[0] = *(float*)&temp;
    gc_env.f[0] = (float)gc_env.f[1] * (float)gc_env.f[5] + (float)gc_env.f[0]; // fmadds f0, f1, f5, f0
    float temp = (float)gc_env.f[0]; // stfs f0, 0x1C(r29)
    gc_mem_write32(gc_env.ram, gc_env.r[29] + 0x1C, *(uint32_t*)&temp);
    Stage_80224CAC();
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[29] + 0x58); // lfs f0, 0x58(r29)
    gc_env.f[0] = *(float*)&temp;
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[26] + 0x0); // lfs f1, 0x0(r26)
    gc_env.f[1] = *(float*)&temp;
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[27] + 0x0); // lfs f6, 0x0(r27)
    gc_env.f[6] = *(float*)&temp;
    gc_env.f[0] = (float)gc_env.f[0] - (float)gc_env.f[1]; // fsubs f0, f0, f1
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[29] + 0x5C); // lfs f5, 0x5C(r29)
    gc_env.f[5] = *(float*)&temp;
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[29] + 0x50); // lfs f4, 0x50(r29)
    gc_env.f[4] = *(float*)&temp;
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[29] + 0x60); // lfs f3, 0x60(r29)
    gc_env.f[3] = *(float*)&temp;
    gc_env.f[0] = (float)gc_env.f[0] * (float)gc_env.f[6] + (float)gc_env.f[1]; // fmadds f0, f0, f6, f1
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[29] + 0x54); // lfs f2, 0x54(r29)
    gc_env.f[2] = *(float*)&temp;
    gc_env.f[4] = (float)gc_env.f[5] - (float)gc_env.f[4]; // fsubs f4, f5, f4
    float temp = (float)gc_env.f[0]; // stfs f0, 0x0(r26)
    gc_mem_write32(gc_env.ram, gc_env.r[26] + 0x0, *(uint32_t*)&temp);
    gc_env.f[1] = (float)gc_env.f[3] - (float)gc_env.f[2]; // fsubs f1, f3, f2
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[29] + 0x50); // lfs f0, 0x50(r29)
    gc_env.f[0] = *(float*)&temp;
    gc_env.f[0] = (float)gc_env.f[4] * (float)gc_env.f[6] + (float)gc_env.f[0]; // fmadds f0, f4, f6, f0
    float temp = (float)gc_env.f[0]; // stfs f0, 0x50(r29)
    gc_mem_write32(gc_env.ram, gc_env.r[29] + 0x50, *(uint32_t*)&temp);
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[29] + 0x54); // lfs f0, 0x54(r29)
    gc_env.f[0] = *(float*)&temp;
    gc_env.f[0] = (float)gc_env.f[1] * (float)gc_env.f[6] + (float)gc_env.f[0]; // fmadds f0, f1, f6, f0
    float temp = (float)gc_env.f[0]; // stfs f0, 0x54(r29)
    gc_mem_write32(gc_env.ram, gc_env.r[29] + 0x54, *(uint32_t*)&temp);
    Stage_GetCamFixedFov();
    float temp = (float)gc_env.f[1]; // stfs f1, 0x48(r29)
    gc_mem_write32(gc_env.ram, gc_env.r[29] + 0x48, *(uint32_t*)&temp);
    gc_env.r[27] = gc_env.r[30] + 124; // addi r27, r30, 0x7c
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[29] + 0x48); // lfs f1, 0x48(r29)
    gc_env.f[1] = *(float*)&temp;
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[29] + 0x44); // lfs f2, 0x44(r29)
    gc_env.f[2] = *(float*)&temp;
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[30] + 0x7C); // lfs f0, 0x7C(r30)
    gc_env.f[0] = *(float*)&temp;
    gc_env.f[1] = (float)gc_env.f[1] - (float)gc_env.f[2]; // fsubs f1, f1, f2
    gc_env.f[0] = (float)gc_env.f[1] * (float)gc_env.f[0] + (float)gc_env.f[2]; // fmadds f0, f1, f0, f2
    float temp = (float)gc_env.f[0]; // stfs f0, 0x44(r29)
    gc_mem_write32(gc_env.ram, gc_env.r[29] + 0x44, *(uint32_t*)&temp);
    Stage_GetCamFixedFov();
    float temp = (float)gc_env.f[1]; // stfs f1, 0x80(r29)
    gc_mem_write32(gc_env.ram, gc_env.r[29] + 0x80, *(uint32_t*)&temp);
    gc_env.r[25] = gc_env.r[28] + 36; // addi r25, r28, 0x24
    gc_env.r[3] = gc_env.r[25]; // Move register
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[29] + 0x80); // lfs f1, 0x80(r29)
    gc_env.f[1] = *(float*)&temp;
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[29] + 0x7C); // lfs f2, 0x7C(r29)
    gc_env.f[2] = *(float*)&temp;
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[27] + 0x0); // lfs f0, 0x0(r27)
    gc_env.f[0] = *(float*)&temp;
    gc_env.f[1] = (float)gc_env.f[1] - (float)gc_env.f[2]; // fsubs f1, f1, f2
    gc_env.f[0] = (float)gc_env.f[1] * (float)gc_env.f[0] + (float)gc_env.f[2]; // fmadds f0, f1, f0, f2
    float temp = (float)gc_env.f[0]; // stfs f0, 0x7C(r29)
    gc_mem_write32(gc_env.ram, gc_env.r[29] + 0x7C, *(uint32_t*)&temp);
    Stage_SetVecToFixedCamPos();
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[29] + 0x38); // lfs f0, 0x38(r29)
    gc_env.f[0] = *(float*)&temp;
    gc_env.r[27] = gc_env.r[30] + 120; // addi r27, r30, 0x78
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[29] + 0x2C); // lfs f1, 0x2C(r29)
    gc_env.f[1] = *(float*)&temp;
    gc_env.r[3] = gc_env.r[26] + 36; // addi r3, r26, 0x24
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[30] + 0x78); // lfs f5, 0x78(r30)
    gc_env.f[5] = *(float*)&temp;
    gc_env.f[0] = (float)gc_env.f[0] - (float)gc_env.f[1]; // fsubs f0, f0, f1
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[29] + 0x3C); // lfs f4, 0x3C(r29)
    gc_env.f[4] = *(float*)&temp;
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[29] + 0x30); // lfs f3, 0x30(r29)
    gc_env.f[3] = *(float*)&temp;
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[29] + 0x40); // lfs f2, 0x40(r29)
    gc_env.f[2] = *(float*)&temp;
    gc_env.f[0] = (float)gc_env.f[0] * (float)gc_env.f[5] + (float)gc_env.f[1]; // fmadds f0, f0, f5, f1
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[29] + 0x34); // lfs f1, 0x34(r29)
    gc_env.f[1] = *(float*)&temp;
    gc_env.f[3] = (float)gc_env.f[4] - (float)gc_env.f[3]; // fsubs f3, f4, f3
    float temp = (float)gc_env.f[0]; // stfs f0, 0x2C(r29)
    gc_mem_write32(gc_env.ram, gc_env.r[29] + 0x2C, *(uint32_t*)&temp);
    gc_env.f[1] = (float)gc_env.f[2] - (float)gc_env.f[1]; // fsubs f1, f2, f1
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[29] + 0x30); // lfs f0, 0x30(r29)
    gc_env.f[0] = *(float*)&temp;
    gc_env.f[0] = (float)gc_env.f[3] * (float)gc_env.f[5] + (float)gc_env.f[0]; // fmadds f0, f3, f5, f0
    float temp = (float)gc_env.f[0]; // stfs f0, 0x30(r29)
    gc_mem_write32(gc_env.ram, gc_env.r[29] + 0x30, *(uint32_t*)&temp);
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[29] + 0x34); // lfs f0, 0x34(r29)
    gc_env.f[0] = *(float*)&temp;
    gc_env.f[0] = (float)gc_env.f[1] * (float)gc_env.f[5] + (float)gc_env.f[0]; // fmadds f0, f1, f5, f0
    float temp = (float)gc_env.f[0]; // stfs f0, 0x34(r29)
    gc_mem_write32(gc_env.ram, gc_env.r[29] + 0x34, *(uint32_t*)&temp);
    Stage_SetVecToFixedCamPos();
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[29] + 0x70); // lfs f0, 0x70(r29)
    gc_env.f[0] = *(float*)&temp;
    gc_env.r[3] = gc_env.r[31]; // Move register
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[29] + 0x64); // lfs f1, 0x64(r29)
    gc_env.f[1] = *(float*)&temp;
    gc_env.r[4] = gc_env.r[25]; // Move register
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[27] + 0x0); // lfs f5, 0x0(r27)
    gc_env.f[5] = *(float*)&temp;
    gc_env.f[0] = (float)gc_env.f[0] - (float)gc_env.f[1]; // fsubs f0, f0, f1
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[29] + 0x74); // lfs f4, 0x74(r29)
    gc_env.f[4] = *(float*)&temp;
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[29] + 0x68); // lfs f3, 0x68(r29)
    gc_env.f[3] = *(float*)&temp;
    gc_env.r[5] = gc_env.r[1] + 12; // addi r5, r1, 0xc
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[29] + 0x78); // lfs f2, 0x78(r29)
    gc_env.f[2] = *(float*)&temp;
    gc_env.f[0] = (float)gc_env.f[0] * (float)gc_env.f[5] + (float)gc_env.f[1]; // fmadds f0, f0, f5, f1
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[29] + 0x6C); // lfs f1, 0x6C(r29)
    gc_env.f[1] = *(float*)&temp;
    gc_env.f[3] = (float)gc_env.f[4] - (float)gc_env.f[3]; // fsubs f3, f4, f3
    gc_env.f[1] = (float)gc_env.f[2] - (float)gc_env.f[1]; // fsubs f1, f2, f1
    float temp = (float)gc_env.f[0]; // stfs f0, 0x64(r29)
    gc_mem_write32(gc_env.ram, gc_env.r[29] + 0x64, *(uint32_t*)&temp);
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[29] + 0x68); // lfs f0, 0x68(r29)
    gc_env.f[0] = *(float*)&temp;
    gc_env.f[0] = (float)gc_env.f[3] * (float)gc_env.f[5] + (float)gc_env.f[0]; // fmadds f0, f3, f5, f0
    float temp = (float)gc_env.f[0]; // stfs f0, 0x68(r29)
    gc_mem_write32(gc_env.ram, gc_env.r[29] + 0x68, *(uint32_t*)&temp);
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[29] + 0x6C); // lfs f0, 0x6C(r29)
    gc_env.f[0] = *(float*)&temp;
    gc_env.f[0] = (float)gc_env.f[1] * (float)gc_env.f[5] + (float)gc_env.f[0]; // fmadds f0, f1, f5, f0
    float temp = (float)gc_env.f[0]; // stfs f0, 0x6C(r29)
    gc_mem_write32(gc_env.ram, gc_env.r[29] + 0x6C, *(uint32_t*)&temp);
    lbVector_Diff();
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0xC); // lfs f1, 0xC(r1)
    gc_env.f[1] = *(float*)&temp;
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x10); // lfs f0, 0x10(r1)
    gc_env.f[0] = *(float*)&temp;
    gc_env.f[1] = (float)gc_env.f[1] * (float)gc_env.f[1]; // fmuls f1, f1, f1
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x14); // lfs f2, 0x14(r1)
    gc_env.f[2] = *(float*)&temp;
    gc_env.f[0] = (float)gc_env.f[0] * (float)gc_env.f[0]; // fmuls f0, f0, f0
    gc_env.f[2] = (float)gc_env.f[2] * (float)gc_env.f[2]; // fmuls f2, f2, f2
    gc_env.f[0] = (float)gc_env.f[1] + (float)gc_env.f[0]; // fadds f0, f1, f0
    gc_env.f[1] = (float)gc_env.f[2] + (float)gc_env.f[0]; // fadds f1, f2, f0
    sqrtf__Ff();
    float temp = (float)gc_env.f[1]; // stfs f1, 0x44(r1)
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x44, *(uint32_t*)&temp);
    gc_env.r[3] = gc_env.r[1] + 48; // addi r3, r1, 0x30
    Camera_8002A28C();
    gc_env.r[3] = gc_env.r[1] + 48; // addi r3, r1, 0x30
    gc_env.r[4] = gc_env.r[28] + 0; // addi r4, r28, 0x0
    Camera_8002A0C0();
    gc_env.r[25] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x4C); // lmw r25, 0x4C(r1)
    gc_env.r[26] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x50); // lmw r25, 0x4C(r1)
    gc_env.r[27] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x54); // lmw r25, 0x4C(r1)
    gc_env.r[28] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x58); // lmw r25, 0x4C(r1)
    gc_env.r[29] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x5C); // lmw r25, 0x4C(r1)
    gc_env.r[30] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x60); // lmw r25, 0x4C(r1)
    gc_env.r[31] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x64); // lmw r25, 0x4C(r1)
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x6c);
    gc_env.r[1] += 104; // addi r1, r1, 0x68
    gc_env.lr = gc_env.r[0]; // Move to link register
    return;
}

// Function: Camera_8002DFE4
void Camera_8002DFE4(void) {
    gc_env.r[0] = gc_env.lr; // Move from link register
    gc_env.r[6] = ((uint32_t)&cm_80452C68 >> 16) & 0xFFFF; // lis r6, cm_80452C68@ha
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x4, gc_env.r[0]);
    gc_env.r[6] = gc_env.r[6] + ((uint32_t)&cm_80452C68 & 0xFFFF); // addi r6, r6, cm_80452C68@l
    gc_mem_write32(gc_env.ram, gc_env.r[1] + -0x48, gc_env.r[1]);
    gc_env.r[1] = gc_env.r[1] + -0x48;
    uint64_t temp;
    memcpy(&temp, &gc_env.f[31], sizeof(double));
    gc_mem_write64(gc_env.ram, gc_env.r[1] + 0x40, temp); // stfd f31, 0x40(r1)
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x3c, gc_env.r[31]);
    gc_env.r[31] = 0x0;
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x38, gc_env.r[30]);
    gc_env.r[30] = gc_env.r[5] + 0; // addi r30, r5, 0x0
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x34, gc_env.r[29]);
    gc_env.r[29] = gc_env.r[3] + 0; // addi r29, r3, 0x0
    gc_env.r[0] = gc_mem_read8(gc_env.ram, gc_env.r[6] + 0x341);
    gc_env.r[0] = (gc_env.r[0] >> 1) & 0x3; // extrwi r0, r0, 2, 29
    gc_env.cr[0] = (gc_env.r[0] == 0x1) ? 0 : (gc_env.r[0] < 0x1 ? -1 : 1); // Compare with immediate
    if (gc_env.cr[0] == 0) goto L_8002E048;
    if (gc_env.cr[0] >= 0) goto L_8002E034;
    gc_env.cr[0] = (gc_env.r[0] == 0x0) ? 0 : (gc_env.r[0] < 0x0 ? -1 : 1); // Compare with immediate
    if (gc_env.cr[0] >= 0) goto L_8002E040;
    goto L_8002E0B8;
    L_8002E034:
    gc_env.cr[0] = (gc_env.r[0] == 0x3) ? 0 : (gc_env.r[0] < 0x3 ? -1 : 1); // Compare with immediate
    if (gc_env.cr[0] >= 0) goto L_8002E0B8;
    goto L_8002E098;
    L_8002E040:
    gc_env.r[31] = 0x1;
    goto L_8002E0B8;
    L_8002E048:
    gc_env.r[3] = gc_mem_read32(gc_env.ram, gc_env.r[6] + 0x378);
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[6] + 0x37c);
    gc_env.cr[0] = (int32_t)gc_env.r[3] < (int32_t)gc_env.r[0] ? 0x8 : ((int32_t)gc_env.r[3] > (int32_t)gc_env.r[0] ? 0x4 : 0x2); // cmpw r3, r0
    if (gc_env.cr[0] != 0) goto L_8002E060;
    gc_env.r[31] = 0x1;
    goto L_8002E0B8;
    L_8002E060:
    gc_env.r[3] = gc_env.r[3] ^ 0x80000000; // xoris r3, r3, 0x8000
    gc_env.d[2] = cm_804D7E20; // lfd f2, cm_804D7E20@sda21(r0)
    gc_env.r[0] = gc_env.r[0] ^ 0x80000000; // xoris r0, r0, 0x8000
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x2c, gc_env.r[3]);
    gc_env.r[3] = 17200 << 16; // lis r3, 0x4330
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x24, gc_env.r[0]);
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x28, gc_env.r[3]);
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x20, gc_env.r[3]);
    uint64_t temp = gc_mem_read64(gc_env.ram, gc_env.r[1] + 0x28); // lfd f1, 0x28(r1)
    gc_env.d[1] = *(double*)&temp;
    uint64_t temp = gc_mem_read64(gc_env.ram, gc_env.r[1] + 0x20); // lfd f0, 0x20(r1)
    gc_env.d[0] = *(double*)&temp;
    gc_env.f[1] = (float)gc_env.f[1] - (float)gc_env.f[2]; // fsubs f1, f1, f2
    gc_env.f[0] = (float)gc_env.f[0] - (float)gc_env.f[2]; // fsubs f0, f0, f2
    gc_env.f[31] = (float)gc_env.f[1] / (float)gc_env.f[0]; // fdivs f31, f1, f0
    goto L_8002E0B8;
    L_8002E098:
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[6] + 0x378); // lfs f1, 0x378(r6)
    gc_env.f[1] = *(float*)&temp;
    gc_env.f[0] = cm_804D7E04; // lfs f0, cm_804D7E04@sda21(r0)
    gc_env.cr[0] = isnan(gc_env.f[1]) || isnan(gc_env.f[0]) ? 0x1 : (gc_env.f[1] < gc_env.f[0] ? 0x8 : (gc_env.f[1] > gc_env.f[0] ? 0x4 : 0x2)); // fcmpo cr0, f1, f0
    // Unknown opcode: cror eq gt eq
    if (gc_env.cr[0] != 0) goto L_8002E0B4;
    gc_env.r[31] = 0x1;
    goto L_8002E0B8;
    L_8002E0B4:
    gc_env.f[31] = gc_env.f[1]; // fmr f31, f1
    L_8002E0B8:
    gc_env.cr[0] = (gc_env.r[31] == 0x0) ? 0 : (gc_env.r[31] < 0x0 ? -1 : 1); // Compare with immediate
    if (gc_env.cr[0] == 0) goto L_8002E0DC;
    gc_env.r[3] = gc_mem_read32(gc_env.ram, gc_env.r[4] + 0x0);
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[4] + 0x4);
    gc_mem_write32(gc_env.ram, gc_env.r[30] + 0x0, gc_env.r[3]);
    gc_mem_write32(gc_env.ram, gc_env.r[30] + 0x4, gc_env.r[0]);
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[4] + 0x8);
    gc_mem_write32(gc_env.ram, gc_env.r[30] + 0x8, gc_env.r[0]);
    goto L_8002E134;
    L_8002E0DC:
    gc_env.r[3] = gc_env.r[4] + 0; // addi r3, r4, 0x0
    gc_env.r[4] = gc_env.r[29] + 0; // addi r4, r29, 0x0
    gc_env.r[5] = gc_env.r[1] + 20; // addi r5, r1, 0x14
    lbVector_Diff();
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x14); // lfs f0, 0x14(r1)
    gc_env.f[0] = *(float*)&temp;
    gc_env.r[4] = gc_env.r[29] + 0; // addi r4, r29, 0x0
    gc_env.r[3] = gc_env.r[1] + 20; // addi r3, r1, 0x14
    gc_env.f[0] = (float)gc_env.f[0] * (float)gc_env.f[31]; // fmuls f0, f0, f31
    float temp = (float)gc_env.f[0]; // stfs f0, 0x14(r1)
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x14, *(uint32_t*)&temp);
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x18); // lfs f0, 0x18(r1)
    gc_env.f[0] = *(float*)&temp;
    gc_env.f[0] = (float)gc_env.f[0] * (float)gc_env.f[31]; // fmuls f0, f0, f31
    float temp = (float)gc_env.f[0]; // stfs f0, 0x18(r1)
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x18, *(uint32_t*)&temp);
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x1C); // lfs f0, 0x1C(r1)
    gc_env.f[0] = *(float*)&temp;
    gc_env.f[0] = (float)gc_env.f[0] * (float)gc_env.f[31]; // fmuls f0, f0, f31
    float temp = (float)gc_env.f[0]; // stfs f0, 0x1C(r1)
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x1C, *(uint32_t*)&temp);
    lbVector_Add();
    gc_env.r[3] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x14);
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x18);
    gc_mem_write32(gc_env.ram, gc_env.r[30] + 0x0, gc_env.r[3]);
    gc_mem_write32(gc_env.ram, gc_env.r[30] + 0x4, gc_env.r[0]);
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x1c);
    gc_mem_write32(gc_env.ram, gc_env.r[30] + 0x8, gc_env.r[0]);
    L_8002E134:
    gc_env.r[3] = gc_env.r[31]; // Move register
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x4c);
    uint64_t temp = gc_mem_read64(gc_env.ram, gc_env.r[1] + 0x40); // lfd f31, 0x40(r1)
    gc_env.d[31] = *(double*)&temp;
    gc_env.r[31] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x3c);
    gc_env.r[30] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x38);
    gc_env.r[29] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x34);
    gc_env.r[1] += 72; // addi r1, r1, 0x48
    gc_env.lr = gc_env.r[0]; // Move to link register
    return;
}

// Function: Camera_8002E158
void Camera_8002E158(void) {
    gc_env.r[4] = ((uint32_t)&cm_80452C68 >> 16) & 0xFFFF; // lis r4, cm_80452C68@ha
    gc_mem_write32(gc_env.ram, gc_env.r[1] + -0x28, gc_env.r[1]);
    gc_env.r[1] = gc_env.r[1] + -0x28;
    gc_env.r[4] = gc_env.r[4] + ((uint32_t)&cm_80452C68 & 0xFFFF); // addi r4, r4, cm_80452C68@l
    gc_env.r[0] = gc_mem_read8(gc_env.ram, gc_env.r[4] + 0x341);
    gc_env.r[6] = 0x0;
    gc_env.r[0] = (gc_env.r[0] >> 1) & 0x3; // extrwi r0, r0, 2, 29
    gc_env.cr[0] = (gc_env.r[0] == 0x1) ? 0 : (gc_env.r[0] < 0x1 ? -1 : 1); // Compare with immediate
    if (gc_env.cr[0] == 0) goto L_8002E19C;
    if (gc_env.cr[0] >= 0) goto L_8002E188;
    gc_env.cr[0] = (gc_env.r[0] == 0x0) ? 0 : (gc_env.r[0] < 0x0 ? -1 : 1); // Compare with immediate
    if (gc_env.cr[0] >= 0) goto L_8002E194;
    goto L_8002E20C;
    L_8002E188:
    gc_env.cr[0] = (gc_env.r[0] == 0x3) ? 0 : (gc_env.r[0] < 0x3 ? -1 : 1); // Compare with immediate
    if (gc_env.cr[0] >= 0) goto L_8002E20C;
    goto L_8002E1EC;
    L_8002E194:
    gc_env.r[6] = 0x1;
    goto L_8002E20C;
    L_8002E19C:
    gc_env.r[5] = gc_mem_read32(gc_env.ram, gc_env.r[4] + 0x378);
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[4] + 0x37c);
    gc_env.cr[0] = (int32_t)gc_env.r[5] < (int32_t)gc_env.r[0] ? 0x8 : ((int32_t)gc_env.r[5] > (int32_t)gc_env.r[0] ? 0x4 : 0x2); // cmpw r5, r0
    if (gc_env.cr[0] != 0) goto L_8002E1B4;
    gc_env.r[6] = 0x1;
    goto L_8002E20C;
    L_8002E1B4:
    gc_env.r[4] = gc_env.r[5] ^ 0x80000000; // xoris r4, r5, 0x8000
    gc_env.d[4] = cm_804D7E20; // lfd f4, cm_804D7E20@sda21(r0)
    gc_env.r[0] = gc_env.r[0] ^ 0x80000000; // xoris r0, r0, 0x8000
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x24, gc_env.r[4]);
    gc_env.r[4] = 17200 << 16; // lis r4, 0x4330
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x1c, gc_env.r[0]);
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x20, gc_env.r[4]);
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x18, gc_env.r[4]);
    uint64_t temp = gc_mem_read64(gc_env.ram, gc_env.r[1] + 0x20); // lfd f3, 0x20(r1)
    gc_env.d[3] = *(double*)&temp;
    uint64_t temp = gc_mem_read64(gc_env.ram, gc_env.r[1] + 0x18); // lfd f0, 0x18(r1)
    gc_env.d[0] = *(double*)&temp;
    gc_env.f[3] = (float)gc_env.f[3] - (float)gc_env.f[4]; // fsubs f3, f3, f4
    gc_env.f[0] = (float)gc_env.f[0] - (float)gc_env.f[4]; // fsubs f0, f0, f4
    gc_env.f[4] = (float)gc_env.f[3] / (float)gc_env.f[0]; // fdivs f4, f3, f0
    goto L_8002E20C;
    L_8002E1EC:
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[4] + 0x378); // lfs f3, 0x378(r4)
    gc_env.f[3] = *(float*)&temp;
    gc_env.f[0] = cm_804D7E04; // lfs f0, cm_804D7E04@sda21(r0)
    gc_env.cr[0] = isnan(gc_env.f[3]) || isnan(gc_env.f[0]) ? 0x1 : (gc_env.f[3] < gc_env.f[0] ? 0x8 : (gc_env.f[3] > gc_env.f[0] ? 0x4 : 0x2)); // fcmpo cr0, f3, f0
    // Unknown opcode: cror eq gt eq
    if (gc_env.cr[0] != 0) goto L_8002E208;
    gc_env.r[6] = 0x1;
    goto L_8002E20C;
    L_8002E208:
    gc_env.f[4] = gc_env.f[3]; // fmr f4, f3
    L_8002E20C:
    gc_env.cr[0] = (gc_env.r[6] == 0x0) ? 0 : (gc_env.r[6] < 0x0 ? -1 : 1); // Compare with immediate
    if (gc_env.cr[0] == 0) goto L_8002E21C;
    float temp = (float)gc_env.f[2]; // stfs f2, 0x0(r3)
    gc_mem_write32(gc_env.ram, gc_env.r[3] + 0x0, *(uint32_t*)&temp);
    goto L_8002E228;
    L_8002E21C:
    gc_env.f[0] = (float)gc_env.f[2] - (float)gc_env.f[1]; // fsubs f0, f2, f1
    gc_env.f[0] = (float)gc_env.f[4] * (float)gc_env.f[0] + (float)gc_env.f[1]; // fmadds f0, f4, f0, f1
    float temp = (float)gc_env.f[0]; // stfs f0, 0x0(r3)
    gc_mem_write32(gc_env.ram, gc_env.r[3] + 0x0, *(uint32_t*)&temp);
    L_8002E228:
    gc_env.r[3] = gc_env.r[6]; // Move register
    gc_env.r[1] += 40; // addi r1, r1, 0x28
    return;
}

// Function: Camera_8002E234
void Camera_8002E234(void) {
    gc_env.r[0] = gc_env.lr; // Move from link register
    gc_env.r[3] = ((uint32_t)&cm_80452C68 >> 16) & 0xFFFF; // lis r3, cm_80452C68@ha
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x4, gc_env.r[0]);
    gc_mem_write32(gc_env.ram, gc_env.r[1] + -0x48, gc_env.r[1]);
    gc_env.r[1] = gc_env.r[1] + -0x48;
    uint64_t temp;
    memcpy(&temp, &gc_env.f[31], sizeof(double));
    gc_mem_write64(gc_env.ram, gc_env.r[1] + 0x40, temp); // stfd f31, 0x40(r1)
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x3c, gc_env.r[31]);
    gc_env.r[31] = gc_env.r[3] + ((uint32_t)&cm_80452C68 & 0xFFFF); // addi r31, r3, cm_80452C68@l
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x38, gc_env.r[30]);
    gc_env.r[30] = 0x0;
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x34, gc_env.r[29]);
    gc_env.r[0] = gc_mem_read8(gc_env.ram, gc_env.r[31] + 0x341);
    gc_env.r[0] = (gc_env.r[0] >> 3) & 0x3; // extrwi r0, r0, 2, 27
    gc_env.cr[0] = (gc_env.r[0] == 0x2) ? 0 : (gc_env.r[0] < 0x2 ? -1 : 1); // Compare with immediate
    if (gc_env.cr[0] == 0) goto L_8002E29C;
    if (gc_env.cr[0] >= 0) goto L_8002E27C;
    gc_env.cr[0] = (gc_env.r[0] == 0x0) ? 0 : (gc_env.r[0] < 0x0 ? -1 : 1); // Compare with immediate
    if (gc_env.cr[0] >= 0) goto L_8002E284;
    goto L_8002E46C;
    L_8002E27C:
    gc_env.cr[0] = (gc_env.r[0] == 0x4) ? 0 : (gc_env.r[0] < 0x4 ? -1 : 1); // Compare with immediate
    if (gc_env.cr[0] >= 0) goto L_8002E46C;
    L_8002E284:
    gc_env.r[3] = gc_env.r[31] + 872; // addi r3, r31, 0x368
    gc_env.r[4] = gc_env.r[31] + 56; // addi r4, r31, 0x38
    gc_env.r[5] = gc_env.r[31] + 44; // addi r5, r31, 0x2c
    Camera_8002DFE4();
    gc_env.r[30] = gc_env.r[3]; // Move register
    goto L_8002E46C;
    L_8002E29C:
    gc_env.r[0] = gc_mem_read8(gc_env.ram, gc_env.r[31] + 0x35c);
    gc_env.r[29] = gc_env.r[31] + 860; // addi r29, r31, 0x35c
    gc_env.r[30] = 0x1;
    gc_env.r[0] = (gc_env.r[0] >> 6) & 0x1; // extrwi r0, r0, 1, 25
    gc_env.cr[0] = (gc_env.r[0] == 0) ? 0x2 : ((int32_t)gc_env.r[0] < 0 ? 0x8 : 0x4);
    if (gc_env.cr[0] == 0) goto L_8002E2C4;
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[31] + 0x36C); // lfs f1, 0x36C(r31)
    gc_env.f[1] = *(float*)&temp;
    gc_env.r[3] = gc_env.r[1] + 16; // addi r3, r1, 0x10
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[31] + 0x360); // lfs f2, 0x360(r31)
    gc_env.f[2] = *(float*)&temp;
    Camera_8002E158();
    gc_env.r[30] = gc_env.r[30] & gc_env.r[3];
    L_8002E2C4:
    gc_env.r[0] = gc_mem_read8(gc_env.ram, gc_env.r[29] + 0x0);
    gc_env.r[0] = (gc_env.r[0] >> 5) & 0x1; // extrwi r0, r0, 1, 26
    gc_env.cr[0] = (gc_env.r[0] == 0) ? 0x2 : ((int32_t)gc_env.r[0] < 0 ? 0x8 : 0x4);
    if (gc_env.cr[0] == 0) goto L_8002E2E4;
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[31] + 0x370); // lfs f1, 0x370(r31)
    gc_env.f[1] = *(float*)&temp;
    gc_env.r[3] = gc_env.r[1] + 12; // addi r3, r1, 0xc
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[31] + 0x364); // lfs f2, 0x364(r31)
    gc_env.f[2] = *(float*)&temp;
    Camera_8002E158();
    gc_env.r[30] = gc_env.r[30] & gc_env.r[3];
    L_8002E2E4:
    gc_env.r[0] = gc_mem_read8(gc_env.ram, gc_env.r[29] + 0x0);
    gc_env.r[0] = (gc_env.r[0] >> 7) & 0x1; // extrwi r0, r0, 1, 24
    gc_env.cr[0] = (gc_env.r[0] == 0) ? 0x2 : ((int32_t)gc_env.r[0] < 0 ? 0x8 : 0x4);
    if (gc_env.cr[0] == 0) goto L_8002E334;
    gc_env.r[5] = (int32_t)(int16_t)gc_mem_read16(gc_env.ram, gc_env.r[31] + 0x368); // lha r5, 0x368(r31)
    gc_env.r[4] = 17200 << 16; // lis r4, 0x4330
    gc_env.r[0] = (int32_t)(int16_t)gc_mem_read16(gc_env.ram, gc_env.r[31] + 0x35E); // lha r0, 0x35E(r31)
    gc_env.r[3] = gc_env.r[1] + 8; // addi r3, r1, 0x8
    gc_env.r[5] = gc_env.r[5] ^ 0x80000000; // xoris r5, r5, 0x8000
    gc_env.r[0] = gc_env.r[0] ^ 0x80000000; // xoris r0, r0, 0x8000
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x2c, gc_env.r[5]);
    gc_env.d[2] = cm_804D7E20; // lfd f2, cm_804D7E20@sda21(r0)
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x24, gc_env.r[0]);
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x28, gc_env.r[4]);
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x20, gc_env.r[4]);
    uint64_t temp = gc_mem_read64(gc_env.ram, gc_env.r[1] + 0x28); // lfd f1, 0x28(r1)
    gc_env.d[1] = *(double*)&temp;
    uint64_t temp = gc_mem_read64(gc_env.ram, gc_env.r[1] + 0x20); // lfd f0, 0x20(r1)
    gc_env.d[0] = *(double*)&temp;
    gc_env.f[1] = (float)gc_env.f[1] - (float)gc_env.f[2]; // fsubs f1, f1, f2
    gc_env.f[2] = (float)gc_env.f[0] - (float)gc_env.f[2]; // fsubs f2, f0, f2
    Camera_8002E158();
    gc_env.r[30] = gc_env.r[30] & gc_env.r[3];
    L_8002E334:
    gc_env.f[0] = cm_804D7E14; // lfs f0, cm_804D7E14@sda21(r0)
    gc_env.r[3] = gc_env.r[1] + 20; // addi r3, r1, 0x14
    gc_env.r[4] = 0x1;
    float temp = (float)gc_env.f[0]; // stfs f0, 0x18(r1)
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x18, *(uint32_t*)&temp);
    float temp = (float)gc_env.f[0]; // stfs f0, 0x14(r1)
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x14, *(uint32_t*)&temp);
    gc_env.f[0] = cm_804D7E04; // lfs f0, cm_804D7E04@sda21(r0)
    float temp = (float)gc_env.f[0]; // stfs f0, 0x1C(r1)
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x1C, *(uint32_t*)&temp);
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[31] + 0x360); // lfs f0, 0x360(r31)
    gc_env.f[0] = *(float*)&temp;
    gc_env.f[1] = -gc_env.f[0]; // fneg f1, f0
    lbVector_Rotate();
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[31] + 0x364); // lfs f1, 0x364(r31)
    gc_env.f[1] = *(float*)&temp;
    gc_env.r[3] = gc_env.r[1] + 20; // addi r3, r1, 0x14
    gc_env.r[4] = 0x2;
    lbVector_Rotate();
    gc_env.r[4] = (int32_t)(int16_t)gc_mem_read16(gc_env.ram, gc_env.r[31] + 0x35E); // lha r4, 0x35E(r31)
    gc_env.r[0] = 17200 << 16; // lis r0, 0x4330
    gc_env.d[1] = cm_804D7E20; // lfd f1, cm_804D7E20@sda21(r0)
    gc_env.r[3] = gc_env.r[1] + 20; // addi r3, r1, 0x14
    gc_env.r[4] = gc_env.r[4] ^ 0x80000000; // xoris r4, r4, 0x8000
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x24, gc_env.r[4]);
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x20, gc_env.r[0]);
    uint64_t temp = gc_mem_read64(gc_env.ram, gc_env.r[1] + 0x20); // lfd f0, 0x20(r1)
    gc_env.d[0] = *(double*)&temp;
    gc_env.f[31] = (float)gc_env.f[0] - (float)gc_env.f[1]; // fsubs f31, f0, f1
    lbVector_Normalize();
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x14); // lfs f0, 0x14(r1)
    gc_env.f[0] = *(float*)&temp;
    gc_env.r[29] = gc_env.r[31] + 20; // addi r29, r31, 0x14
    gc_env.r[4] = gc_env.r[29] + 0; // addi r4, r29, 0x0
    gc_env.f[0] = (float)gc_env.f[0] * (float)gc_env.f[31]; // fmuls f0, f0, f31
    gc_env.r[3] = gc_env.r[1] + 20; // addi r3, r1, 0x14
    float temp = (float)gc_env.f[0]; // stfs f0, 0x14(r1)
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x14, *(uint32_t*)&temp);
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x18); // lfs f0, 0x18(r1)
    gc_env.f[0] = *(float*)&temp;
    gc_env.f[0] = (float)gc_env.f[0] * (float)gc_env.f[31]; // fmuls f0, f0, f31
    float temp = (float)gc_env.f[0]; // stfs f0, 0x18(r1)
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x18, *(uint32_t*)&temp);
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x1C); // lfs f0, 0x1C(r1)
    gc_env.f[0] = *(float*)&temp;
    gc_env.f[0] = (float)gc_env.f[0] * (float)gc_env.f[31]; // fmuls f0, f0, f31
    float temp = (float)gc_env.f[0]; // stfs f0, 0x1C(r1)
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x1C, *(uint32_t*)&temp);
    lbVector_Add();
    gc_env.r[5] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x14);
    gc_env.r[3] = gc_env.r[1] + 20; // addi r3, r1, 0x14
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x18);
    gc_env.r[4] = 0x1;
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x38, gc_env.r[5]);
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x3c, gc_env.r[0]);
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x1c);
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x40, gc_env.r[0]);
    gc_env.f[0] = cm_804D7E14; // lfs f0, cm_804D7E14@sda21(r0)
    float temp = (float)gc_env.f[0]; // stfs f0, 0x18(r1)
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x18, *(uint32_t*)&temp);
    float temp = (float)gc_env.f[0]; // stfs f0, 0x14(r1)
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x14, *(uint32_t*)&temp);
    gc_env.f[0] = cm_804D7E04; // lfs f0, cm_804D7E04@sda21(r0)
    float temp = (float)gc_env.f[0]; // stfs f0, 0x1C(r1)
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x1C, *(uint32_t*)&temp);
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x10); // lfs f0, 0x10(r1)
    gc_env.f[0] = *(float*)&temp;
    gc_env.f[1] = -gc_env.f[0]; // fneg f1, f0
    lbVector_Rotate();
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0xC); // lfs f1, 0xC(r1)
    gc_env.f[1] = *(float*)&temp;
    gc_env.r[3] = gc_env.r[1] + 20; // addi r3, r1, 0x14
    gc_env.r[4] = 0x2;
    lbVector_Rotate();
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x8); // lfs f31, 0x8(r1)
    gc_env.f[31] = *(float*)&temp;
    gc_env.r[3] = gc_env.r[1] + 20; // addi r3, r1, 0x14
    lbVector_Normalize();
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x14); // lfs f0, 0x14(r1)
    gc_env.f[0] = *(float*)&temp;
    gc_env.r[4] = gc_env.r[29] + 0; // addi r4, r29, 0x0
    gc_env.r[3] = gc_env.r[1] + 20; // addi r3, r1, 0x14
    gc_env.f[0] = (float)gc_env.f[0] * (float)gc_env.f[31]; // fmuls f0, f0, f31
    float temp = (float)gc_env.f[0]; // stfs f0, 0x14(r1)
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x14, *(uint32_t*)&temp);
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x18); // lfs f0, 0x18(r1)
    gc_env.f[0] = *(float*)&temp;
    gc_env.f[0] = (float)gc_env.f[0] * (float)gc_env.f[31]; // fmuls f0, f0, f31
    float temp = (float)gc_env.f[0]; // stfs f0, 0x18(r1)
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x18, *(uint32_t*)&temp);
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x1C); // lfs f0, 0x1C(r1)
    gc_env.f[0] = *(float*)&temp;
    gc_env.f[0] = (float)gc_env.f[0] * (float)gc_env.f[31]; // fmuls f0, f0, f31
    float temp = (float)gc_env.f[0]; // stfs f0, 0x1C(r1)
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x1C, *(uint32_t*)&temp);
    lbVector_Add();
    gc_env.r[3] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x14);
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x18);
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x2c, gc_env.r[3]);
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x30, gc_env.r[0]);
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x1c);
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x34, gc_env.r[0]);
    L_8002E46C:
    gc_env.r[3] = gc_env.r[30]; // Move register
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x4c);
    uint64_t temp = gc_mem_read64(gc_env.ram, gc_env.r[1] + 0x40); // lfd f31, 0x40(r1)
    gc_env.d[31] = *(double*)&temp;
    gc_env.r[31] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x3c);
    gc_env.r[30] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x38);
    gc_env.r[29] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x34);
    gc_env.r[1] += 72; // addi r1, r1, 0x48
    gc_env.lr = gc_env.r[0]; // Move to link register
    return;
}

// Function: Camera_8002E490
void Camera_8002E490(void) {
    gc_env.r[0] = gc_env.lr; // Move from link register
    gc_env.r[3] = ((uint32_t)&cm_80452C68 >> 16) & 0xFFFF; // lis r3, cm_80452C68@ha
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x4, gc_env.r[0]);
    gc_mem_write32(gc_env.ram, gc_env.r[1] + -0x38, gc_env.r[1]);
    gc_env.r[1] = gc_env.r[1] + -0x38;
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x34, gc_env.r[31]);
    gc_env.r[31] = gc_env.r[3] + ((uint32_t)&cm_80452C68 & 0xFFFF); // addi r31, r3, cm_80452C68@l
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x30, gc_env.r[30]);
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x2c, gc_env.r[29]);
    Camera_80030DF8();
    gc_env.r[30] = gc_env.r[31] + 833; // addi r30, r31, 0x341
    gc_env.r[0] = gc_mem_read8(gc_env.ram, gc_env.r[31] + 0x341);
    gc_env.r[0] = (gc_env.r[0] >> 5) & 0x3; // extrwi r0, r0, 2, 25
    gc_env.cr[0] = (gc_env.r[0] == 0x2) ? 0 : (gc_env.r[0] < 0x2 ? -1 : 1); // Compare with immediate
    if (gc_env.cr[0] == 0) goto L_8002E520;
    if (gc_env.cr[0] >= 0) goto L_8002E4DC;
    gc_env.cr[0] = (gc_env.r[0] == 0x0) ? 0 : (gc_env.r[0] < 0x0 ? -1 : 1); // Compare with immediate
    if (gc_env.cr[0] == 0) goto L_8002E574;
    if (gc_env.cr[0] >= 0) goto L_8002E4E8;
    goto L_8002E574;
    L_8002E4DC:
    gc_env.cr[0] = (gc_env.r[0] == 0x4) ? 0 : (gc_env.r[0] < 0x4 ? -1 : 1); // Compare with immediate
    if (gc_env.cr[0] >= 0) goto L_8002E574;
    goto L_8002E53C;
    L_8002E4E8:
    gc_env.r[3] = gc_mem_read32(gc_env.ram, gc_env.r[31] + 0x344);
    Player_GetEntity();
    gc_env.cr[0] = ((uint32_t)gc_env.r[3] == 0x0) ? 0 : ((uint32_t)gc_env.r[3] < 0x0 ? -1 : 1); // Logical compare with immediate
    if (gc_env.cr[0] == 0) goto L_8002E574;
    ftLib_80086B74();
    gc_env.cr[0] = ((uint32_t)gc_env.r[3] == 0x0) ? 0 : ((uint32_t)gc_env.r[3] < 0x0 ? -1 : 1); // Logical compare with immediate
    if (gc_env.cr[0] == 0) goto L_8002E574;
    gc_env.r[4] = gc_mem_read32(gc_env.ram, gc_env.r[3] + 0x1c);
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[3] + 0x20);
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x20, gc_env.r[4]);
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x24, gc_env.r[0]);
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[3] + 0x24);
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x28, gc_env.r[0]);
    goto L_8002E574;
    L_8002E520:
    gc_env.r[3] = gc_mem_read32(gc_env.ram, gc_env.r[31] + 0x344);
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[31] + 0x348);
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x20, gc_env.r[3]);
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x24, gc_env.r[0]);
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[31] + 0x34c);
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x28, gc_env.r[0]);
    goto L_8002E574;
    L_8002E53C:
    gc_env.r[12] = gc_mem_read32(gc_env.ram, gc_env.r[31] + 0x344);
    gc_env.cr[0] = ((uint32_t)gc_env.r[12] == 0x0) ? 0 : ((uint32_t)gc_env.r[12] < 0x0 ? -1 : 1); // Logical compare with immediate
    if (gc_env.cr[0] == 0) goto L_8002E574;
    gc_env.lr = gc_env.r[12]; // Move to link register
    gc_env.r[3] = gc_env.r[1] + 28; // addi r3, r1, 0x1c
    // Call function at gc_env.lr; // Branch to link register
    gc_env.cr[0] = (gc_env.r[3] == 0x0) ? 0 : (gc_env.r[3] < 0x0 ? -1 : 1); // Compare with immediate
    if (gc_env.cr[0] == 0) goto L_8002E574;
    gc_env.r[3] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x1c);
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x20);
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x20, gc_env.r[3]);
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x24, gc_env.r[0]);
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x24);
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x28, gc_env.r[0]);
    L_8002E574:
    gc_env.r[0] = gc_mem_read8(gc_env.ram, gc_env.r[30] + 0x0);
    gc_env.r[0] = (gc_env.r[0] >> 3) & 0x3; // extrwi r0, r0, 2, 27
    gc_env.cr[0] = (gc_env.r[0] == 0x2) ? 0 : (gc_env.r[0] < 0x2 ? -1 : 1); // Compare with immediate
    if (gc_env.cr[0] == 0) goto L_8002E5F8;
    if (gc_env.cr[0] >= 0) goto L_8002E598;
    gc_env.cr[0] = (gc_env.r[0] == 0x0) ? 0 : (gc_env.r[0] < 0x0 ? -1 : 1); // Compare with immediate
    if (gc_env.cr[0] == 0) goto L_8002E5F8;
    if (gc_env.cr[0] >= 0) goto L_8002E5A4;
    goto L_8002E5F8;
    L_8002E598:
    gc_env.cr[0] = (gc_env.r[0] == 0x4) ? 0 : (gc_env.r[0] < 0x4 ? -1 : 1); // Compare with immediate
    if (gc_env.cr[0] >= 0) goto L_8002E5F8;
    goto L_8002E5C0;
    L_8002E5A4:
    gc_env.r[3] = gc_mem_read32(gc_env.ram, gc_env.r[31] + 0x35c);
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[31] + 0x360);
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x38, gc_env.r[3]);
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x3c, gc_env.r[0]);
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[31] + 0x364);
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x40, gc_env.r[0]);
    goto L_8002E5F8;
    L_8002E5C0:
    gc_env.r[12] = gc_mem_read32(gc_env.ram, gc_env.r[31] + 0x35c);
    gc_env.cr[0] = ((uint32_t)gc_env.r[12] == 0x0) ? 0 : ((uint32_t)gc_env.r[12] < 0x0 ? -1 : 1); // Logical compare with immediate
    if (gc_env.cr[0] == 0) goto L_8002E5F8;
    gc_env.lr = gc_env.r[12]; // Move to link register
    gc_env.r[3] = gc_env.r[1] + 16; // addi r3, r1, 0x10
    // Call function at gc_env.lr; // Branch to link register
    gc_env.cr[0] = (gc_env.r[3] == 0x0) ? 0 : (gc_env.r[3] < 0x0 ? -1 : 1); // Compare with immediate
    if (gc_env.cr[0] == 0) goto L_8002E5F8;
    gc_env.r[3] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x10);
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x14);
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x38, gc_env.r[3]);
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x3c, gc_env.r[0]);
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x18);
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x40, gc_env.r[0]);
    L_8002E5F8:
    gc_env.r[0] = gc_mem_read8(gc_env.ram, gc_env.r[30] + 0x0);
    gc_env.r[29] = 0x0;
    gc_env.r[0] = (gc_env.r[0] >> 5) & 0x3; // extrwi r0, r0, 2, 25
    gc_env.cr[0] = (gc_env.r[0] == 0x4) ? 0 : (gc_env.r[0] < 0x4 ? -1 : 1); // Compare with immediate
    if (gc_env.cr[0] >= 0) goto L_8002E62C;
    gc_env.cr[0] = (gc_env.r[0] == 0x0) ? 0 : (gc_env.r[0] < 0x0 ? -1 : 1); // Compare with immediate
    if (gc_env.cr[0] >= 0) goto L_8002E618;
    goto L_8002E62C;
    L_8002E618:
    gc_env.r[3] = gc_env.r[31] + 848; // addi r3, r31, 0x350
    gc_env.r[4] = gc_env.r[31] + 32; // addi r4, r31, 0x20
    gc_env.r[5] = gc_env.r[31] + 20; // addi r5, r31, 0x14
    Camera_8002DFE4();
    gc_env.r[29] = gc_env.r[3]; // Move register
    L_8002E62C:
    Camera_8002E234();
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[31] + 0x374); // lfs f1, 0x374(r31)
    gc_env.f[1] = *(float*)&temp;
    gc_env.r[29] = gc_env.r[29] & gc_env.r[3];
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[31] + 0x48); // lfs f2, 0x48(r31)
    gc_env.f[2] = *(float*)&temp;
    gc_env.r[3] = gc_env.r[31] + 68; // addi r3, r31, 0x44
    Camera_8002E158();
    gc_env.r[0] = gc_mem_read8(gc_env.ram, gc_env.r[30] + 0x0);
    gc_env.r[29] = gc_env.r[29] & gc_env.r[3];
    gc_env.r[0] = (gc_env.r[0] >> 1) & 0x3; // extrwi r0, r0, 2, 29
    gc_env.cr[0] = (gc_env.r[0] == 0x1) ? 0 : (gc_env.r[0] < 0x1 ? -1 : 1); // Compare with immediate
    if (gc_env.cr[0] == 0) goto L_8002E66C;
    if (gc_env.cr[0] >= 0) goto L_8002E660;
    goto L_8002E6BC;
    L_8002E660:
    gc_env.cr[0] = (gc_env.r[0] == 0x3) ? 0 : (gc_env.r[0] < 0x3 ? -1 : 1); // Compare with immediate
    if (gc_env.cr[0] >= 0) goto L_8002E6BC;
    goto L_8002E68C;
    L_8002E66C:
    gc_env.r[4] = gc_env.r[31] + 888; // addi r4, r31, 0x378
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[31] + 0x37c);
    gc_env.r[3] = gc_mem_read32(gc_env.ram, gc_env.r[31] + 0x378);
    gc_env.cr[0] = (int32_t)gc_env.r[3] < (int32_t)gc_env.r[0] ? 0x8 : ((int32_t)gc_env.r[3] > (int32_t)gc_env.r[0] ? 0x4 : 0x2); // cmpw r3, r0
    if (gc_env.cr[0] >= 0) goto L_8002E6BC;
    gc_env.r[0] = gc_env.r[3] + 1; // addi r0, r3, 0x1
    gc_mem_write32(gc_env.ram, gc_env.r[4] + 0x0, gc_env.r[0]);
    goto L_8002E6BC;
    L_8002E68C:
    gc_env.r[3] = gc_env.r[31] + 888; // addi r3, r31, 0x378
    gc_env.f[3] = cm_804D7E04; // lfs f3, cm_804D7E04@sda21(r0)
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[31] + 0x378); // lfs f2, 0x378(r31)
    gc_env.f[2] = *(float*)&temp;
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[31] + 0x37C); // lfs f0, 0x37C(r31)
    gc_env.f[0] = *(float*)&temp;
    gc_env.f[1] = (float)gc_env.f[3] - (float)gc_env.f[2]; // fsubs f1, f3, f2
    gc_env.f[0] = (float)gc_env.f[1] * (float)gc_env.f[0] + (float)gc_env.f[2]; // fmadds f0, f1, f0, f2
    float temp = (float)gc_env.f[0]; // stfs f0, 0x378(r31)
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x378, *(uint32_t*)&temp);
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[31] + 0x378); // lfs f1, 0x378(r31)
    gc_env.f[1] = *(float*)&temp;
    gc_env.f[0] = cm_804D7E88; // lfs f0, cm_804D7E88@sda21(r0)
    gc_env.cr[0] = isnan(gc_env.f[1]) || isnan(gc_env.f[0]) ? 0x1 : (gc_env.f[1] < gc_env.f[0] ? 0x8 : (gc_env.f[1] > gc_env.f[0] ? 0x4 : 0x2)); // fcmpo cr0, f1, f0
    if (gc_env.cr[0] & (0x8 | 0x2)) goto L_8002E6BC; // ble .L_8002E6BC
    float temp = (float)gc_env.f[3]; // stfs f3, 0x0(r3)
    gc_mem_write32(gc_env.ram, gc_env.r[3] + 0x0, *(uint32_t*)&temp);
    L_8002E6BC:
    gc_env.cr[0] = (gc_env.r[29] == 0x0) ? 0 : (gc_env.r[29] < 0x0 ? -1 : 1); // Compare with immediate
    if (gc_env.cr[0] == 0) goto L_8002E6CC;
    gc_env.r[0] = 0x1;
    goto L_8002E6D0;
    L_8002E6CC:
    gc_env.r[0] = 0x0;
    L_8002E6D0:
    gc_env.r[3] = gc_env.r[0] & 0xFF; // clrlwi r3, r0, 24
    gc_env.r[0] = gc_mem_read8(gc_env.ram, gc_env.r[30] + 0x0);
    uint32_t rotated = gc_env.r[3] << 0; // rlwimi r0, r3, 0, 31, 31
    gc_env.r[0] = (gc_env.r[0] & ~0x1) | (rotated & 0x1);
    gc_mem_write8(gc_env.ram, gc_env.r[30] + 0x0, gc_env.r[0]);
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x3c);
    gc_env.r[31] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x34);
    gc_env.r[30] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x30);
    gc_env.r[29] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x2c);
    gc_env.r[1] += 56; // addi r1, r1, 0x38
    gc_env.lr = gc_env.r[0]; // Move to link register
    return;
}

// Function: Camera_8002E6FC
void Camera_8002E6FC(void) {
    gc_env.r[0] = gc_env.lr; // Move from link register
    gc_env.r[4] = ((uint32_t)&cm_80452C68 >> 16) & 0xFFFF; // lis r4, cm_80452C68@ha
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x4, gc_env.r[0]);
    gc_mem_write32(gc_env.ram, gc_env.r[1] + -0x20, gc_env.r[1]);
    gc_env.r[1] = gc_env.r[1] + -0x20;
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x1c, gc_env.r[31]);
    gc_env.r[31] = gc_env.r[4] + ((uint32_t)&cm_80452C68 & 0xFFFF); // addi r31, r4, cm_80452C68@l
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x18, gc_env.r[30]);
    gc_env.r[30] = gc_env.r[3] + 0; // addi r30, r3, 0x0
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[31] + 0x4);
    gc_env.cr[0] = (gc_env.r[0] == 0x6) ? 0 : (gc_env.r[0] < 0x6 ? -1 : 1); // Compare with immediate
    if (gc_env.cr[0] == 0) goto L_8002E72C;
    Camera_8002FE38();
    L_8002E72C:
    gc_env.r[0] = gc_mem_read8(gc_env.ram, gc_env.r[31] + 0x341);
    gc_env.r[3] = 0x1;
    uint32_t rotated = gc_env.r[3] << 5; // rlwimi r0, r3, 5, 25, 26
    gc_env.r[0] = (gc_env.r[0] & ~0x60) | (rotated & 0x60);
    gc_mem_write8(gc_env.ram, gc_env.r[31] + 0x341, gc_env.r[0]);
    gc_env.r[5] = gc_env.r[31] + 836; // addi r5, r31, 0x344
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x344, gc_env.r[30]);
    gc_env.r[0] = gc_mem_read8(gc_env.ram, gc_env.r[31] + 0x341);
    gc_env.r[0] = (gc_env.r[0] >> 5) & 0x3; // extrwi r0, r0, 2, 25
    gc_env.cr[0] = (gc_env.r[0] == 0x2) ? 0 : (gc_env.r[0] < 0x2 ? -1 : 1); // Compare with immediate
    if (gc_env.cr[0] == 0) goto L_8002E7AC;
    if (gc_env.cr[0] >= 0) goto L_8002E768;
    gc_env.cr[0] = (gc_env.r[0] == 0x0) ? 0 : (gc_env.r[0] < 0x0 ? -1 : 1); // Compare with immediate
    if (gc_env.cr[0] == 0) goto L_8002E800;
    if (gc_env.cr[0] >= 0) goto L_8002E774;
    goto L_8002E800;
    L_8002E768:
    gc_env.cr[0] = (gc_env.r[0] == 0x4) ? 0 : (gc_env.r[0] < 0x4 ? -1 : 1); // Compare with immediate
    if (gc_env.cr[0] >= 0) goto L_8002E800;
    goto L_8002E7C8;
    L_8002E774:
    gc_env.r[3] = gc_mem_read32(gc_env.ram, gc_env.r[5] + 0x0);
    Player_GetEntity();
    gc_env.cr[0] = ((uint32_t)gc_env.r[3] == 0x0) ? 0 : ((uint32_t)gc_env.r[3] < 0x0 ? -1 : 1); // Logical compare with immediate
    if (gc_env.cr[0] == 0) goto L_8002E800;
    ftLib_80086B74();
    gc_env.cr[0] = ((uint32_t)gc_env.r[3] == 0x0) ? 0 : ((uint32_t)gc_env.r[3] < 0x0 ? -1 : 1); // Logical compare with immediate
    if (gc_env.cr[0] == 0) goto L_8002E800;
    gc_env.r[4] = gc_mem_read32(gc_env.ram, gc_env.r[3] + 0x1c);
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[3] + 0x20);
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x20, gc_env.r[4]);
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x24, gc_env.r[0]);
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[3] + 0x24);
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x28, gc_env.r[0]);
    goto L_8002E800;
    L_8002E7AC:
    gc_env.r[3] = gc_mem_read32(gc_env.ram, gc_env.r[5] + 0x0);
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[5] + 0x4);
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x20, gc_env.r[3]);
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x24, gc_env.r[0]);
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[5] + 0x8);
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x28, gc_env.r[0]);
    goto L_8002E800;
    L_8002E7C8:
    gc_env.r[12] = gc_mem_read32(gc_env.ram, gc_env.r[5] + 0x0);
    gc_env.cr[0] = ((uint32_t)gc_env.r[12] == 0x0) ? 0 : ((uint32_t)gc_env.r[12] < 0x0 ? -1 : 1); // Logical compare with immediate
    if (gc_env.cr[0] == 0) goto L_8002E800;
    gc_env.lr = gc_env.r[12]; // Move to link register
    gc_env.r[3] = gc_env.r[1] + 12; // addi r3, r1, 0xc
    // Call function at gc_env.lr; // Branch to link register
    gc_env.cr[0] = (gc_env.r[3] == 0x0) ? 0 : (gc_env.r[3] < 0x0 ? -1 : 1); // Compare with immediate
    if (gc_env.cr[0] == 0) goto L_8002E800;
    gc_env.r[3] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0xc);
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x10);
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x20, gc_env.r[3]);
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x24, gc_env.r[0]);
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x14);
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x28, gc_env.r[0]);
    L_8002E800:
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x24);
    gc_env.r[31] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x1c);
    gc_env.r[30] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x18);
    gc_env.r[1] += 32; // addi r1, r1, 0x20
    gc_env.lr = gc_env.r[0]; // Move to link register
    return;
}

// Function: Camera_8002E818
void Camera_8002E818(void) {
    gc_env.r[0] = gc_env.lr; // Move from link register
    gc_env.r[4] = ((uint32_t)&cm_80452C68 >> 16) & 0xFFFF; // lis r4, cm_80452C68@ha
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x4, gc_env.r[0]);
    gc_mem_write32(gc_env.ram, gc_env.r[1] + -0x20, gc_env.r[1]);
    gc_env.r[1] = gc_env.r[1] + -0x20;
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x1c, gc_env.r[31]);
    gc_env.r[31] = gc_env.r[4] + ((uint32_t)&cm_80452C68 & 0xFFFF); // addi r31, r4, cm_80452C68@l
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x18, gc_env.r[30]);
    gc_env.r[30] = gc_env.r[3] + 0; // addi r30, r3, 0x0
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[31] + 0x4);
    gc_env.cr[0] = (gc_env.r[0] == 0x6) ? 0 : (gc_env.r[0] < 0x6 ? -1 : 1); // Compare with immediate
    if (gc_env.cr[0] == 0) goto L_8002E848;
    Camera_8002FE38();
    L_8002E848:
    gc_env.r[0] = gc_mem_read8(gc_env.ram, gc_env.r[31] + 0x341);
    gc_env.r[3] = 0x2;
    uint32_t rotated = gc_env.r[3] << 5; // rlwimi r0, r3, 5, 25, 26
    gc_env.r[0] = (gc_env.r[0] & ~0x60) | (rotated & 0x60);
    gc_mem_write8(gc_env.ram, gc_env.r[31] + 0x341, gc_env.r[0]);
    gc_env.r[5] = gc_env.r[31] + 836; // addi r5, r31, 0x344
    gc_env.r[3] = gc_mem_read32(gc_env.ram, gc_env.r[30] + 0x0);
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[30] + 0x4);
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x344, gc_env.r[3]);
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x348, gc_env.r[0]);
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[30] + 0x8);
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x34c, gc_env.r[0]);
    gc_env.r[0] = gc_mem_read8(gc_env.ram, gc_env.r[31] + 0x341);
    gc_env.r[0] = (gc_env.r[0] >> 5) & 0x3; // extrwi r0, r0, 2, 25
    gc_env.cr[0] = (gc_env.r[0] == 0x2) ? 0 : (gc_env.r[0] < 0x2 ? -1 : 1); // Compare with immediate
    if (gc_env.cr[0] == 0) goto L_8002E8DC;
    if (gc_env.cr[0] >= 0) goto L_8002E898;
    gc_env.cr[0] = (gc_env.r[0] == 0x0) ? 0 : (gc_env.r[0] < 0x0 ? -1 : 1); // Compare with immediate
    if (gc_env.cr[0] == 0) goto L_8002E930;
    if (gc_env.cr[0] >= 0) goto L_8002E8A4;
    goto L_8002E930;
    L_8002E898:
    gc_env.cr[0] = (gc_env.r[0] == 0x4) ? 0 : (gc_env.r[0] < 0x4 ? -1 : 1); // Compare with immediate
    if (gc_env.cr[0] >= 0) goto L_8002E930;
    goto L_8002E8F8;
    L_8002E8A4:
    gc_env.r[3] = gc_mem_read32(gc_env.ram, gc_env.r[5] + 0x0);
    Player_GetEntity();
    gc_env.cr[0] = ((uint32_t)gc_env.r[3] == 0x0) ? 0 : ((uint32_t)gc_env.r[3] < 0x0 ? -1 : 1); // Logical compare with immediate
    if (gc_env.cr[0] == 0) goto L_8002E930;
    ftLib_80086B74();
    gc_env.cr[0] = ((uint32_t)gc_env.r[3] == 0x0) ? 0 : ((uint32_t)gc_env.r[3] < 0x0 ? -1 : 1); // Logical compare with immediate
    if (gc_env.cr[0] == 0) goto L_8002E930;
    gc_env.r[4] = gc_mem_read32(gc_env.ram, gc_env.r[3] + 0x1c);
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[3] + 0x20);
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x20, gc_env.r[4]);
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x24, gc_env.r[0]);
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[3] + 0x24);
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x28, gc_env.r[0]);
    goto L_8002E930;
    L_8002E8DC:
    gc_env.r[3] = gc_mem_read32(gc_env.ram, gc_env.r[5] + 0x0);
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[5] + 0x4);
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x20, gc_env.r[3]);
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x24, gc_env.r[0]);
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[5] + 0x8);
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x28, gc_env.r[0]);
    goto L_8002E930;
    L_8002E8F8:
    gc_env.r[12] = gc_mem_read32(gc_env.ram, gc_env.r[5] + 0x0);
    gc_env.cr[0] = ((uint32_t)gc_env.r[12] == 0x0) ? 0 : ((uint32_t)gc_env.r[12] < 0x0 ? -1 : 1); // Logical compare with immediate
    if (gc_env.cr[0] == 0) goto L_8002E930;
    gc_env.lr = gc_env.r[12]; // Move to link register
    gc_env.r[3] = gc_env.r[1] + 12; // addi r3, r1, 0xc
    // Call function at gc_env.lr; // Branch to link register
    gc_env.cr[0] = (gc_env.r[3] == 0x0) ? 0 : (gc_env.r[3] < 0x0 ? -1 : 1); // Compare with immediate
    if (gc_env.cr[0] == 0) goto L_8002E930;
    gc_env.r[3] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0xc);
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x10);
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x20, gc_env.r[3]);
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x24, gc_env.r[0]);
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x14);
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x28, gc_env.r[0]);
    L_8002E930:
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x24);
    gc_env.r[31] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x1c);
    gc_env.r[30] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x18);
    gc_env.r[1] += 32; // addi r1, r1, 0x20
    gc_env.lr = gc_env.r[0]; // Move to link register
    return;
}

// Function: Camera_8002E948
void Camera_8002E948(void) {
    gc_env.r[0] = gc_env.lr; // Move from link register
    gc_env.r[4] = ((uint32_t)&cm_80452C68 >> 16) & 0xFFFF; // lis r4, cm_80452C68@ha
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x4, gc_env.r[0]);
    gc_mem_write32(gc_env.ram, gc_env.r[1] + -0x20, gc_env.r[1]);
    gc_env.r[1] = gc_env.r[1] + -0x20;
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x1c, gc_env.r[31]);
    gc_env.r[31] = gc_env.r[4] + ((uint32_t)&cm_80452C68 & 0xFFFF); // addi r31, r4, cm_80452C68@l
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x18, gc_env.r[30]);
    gc_env.r[30] = gc_env.r[3] + 0; // addi r30, r3, 0x0
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[31] + 0x4);
    gc_env.cr[0] = (gc_env.r[0] == 0x6) ? 0 : (gc_env.r[0] < 0x6 ? -1 : 1); // Compare with immediate
    if (gc_env.cr[0] == 0) goto L_8002E978;
    Camera_8002FE38();
    L_8002E978:
    gc_env.r[0] = gc_mem_read8(gc_env.ram, gc_env.r[31] + 0x341);
    gc_env.r[3] = 0x3;
    uint32_t rotated = gc_env.r[3] << 5; // rlwimi r0, r3, 5, 25, 26
    gc_env.r[0] = (gc_env.r[0] & ~0x60) | (rotated & 0x60);
    gc_mem_write8(gc_env.ram, gc_env.r[31] + 0x341, gc_env.r[0]);
    gc_env.r[5] = gc_env.r[31] + 836; // addi r5, r31, 0x344
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x344, gc_env.r[30]);
    gc_env.r[0] = gc_mem_read8(gc_env.ram, gc_env.r[31] + 0x341);
    gc_env.r[0] = (gc_env.r[0] >> 5) & 0x3; // extrwi r0, r0, 2, 25
    gc_env.cr[0] = (gc_env.r[0] == 0x2) ? 0 : (gc_env.r[0] < 0x2 ? -1 : 1); // Compare with immediate
    if (gc_env.cr[0] == 0) goto L_8002E9F8;
    if (gc_env.cr[0] >= 0) goto L_8002E9B4;
    gc_env.cr[0] = (gc_env.r[0] == 0x0) ? 0 : (gc_env.r[0] < 0x0 ? -1 : 1); // Compare with immediate
    if (gc_env.cr[0] == 0) goto L_8002EA4C;
    if (gc_env.cr[0] >= 0) goto L_8002E9C0;
    goto L_8002EA4C;
    L_8002E9B4:
    gc_env.cr[0] = (gc_env.r[0] == 0x4) ? 0 : (gc_env.r[0] < 0x4 ? -1 : 1); // Compare with immediate
    if (gc_env.cr[0] >= 0) goto L_8002EA4C;
    goto L_8002EA14;
    L_8002E9C0:
    gc_env.r[3] = gc_mem_read32(gc_env.ram, gc_env.r[5] + 0x0);
    Player_GetEntity();
    gc_env.cr[0] = ((uint32_t)gc_env.r[3] == 0x0) ? 0 : ((uint32_t)gc_env.r[3] < 0x0 ? -1 : 1); // Logical compare with immediate
    if (gc_env.cr[0] == 0) goto L_8002EA4C;
    ftLib_80086B74();
    gc_env.cr[0] = ((uint32_t)gc_env.r[3] == 0x0) ? 0 : ((uint32_t)gc_env.r[3] < 0x0 ? -1 : 1); // Logical compare with immediate
    if (gc_env.cr[0] == 0) goto L_8002EA4C;
    gc_env.r[4] = gc_mem_read32(gc_env.ram, gc_env.r[3] + 0x1c);
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[3] + 0x20);
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x20, gc_env.r[4]);
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x24, gc_env.r[0]);
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[3] + 0x24);
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x28, gc_env.r[0]);
    goto L_8002EA4C;
    L_8002E9F8:
    gc_env.r[3] = gc_mem_read32(gc_env.ram, gc_env.r[5] + 0x0);
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[5] + 0x4);
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x20, gc_env.r[3]);
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x24, gc_env.r[0]);
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[5] + 0x8);
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x28, gc_env.r[0]);
    goto L_8002EA4C;
    L_8002EA14:
    gc_env.r[12] = gc_mem_read32(gc_env.ram, gc_env.r[5] + 0x0);
    gc_env.cr[0] = ((uint32_t)gc_env.r[12] == 0x0) ? 0 : ((uint32_t)gc_env.r[12] < 0x0 ? -1 : 1); // Logical compare with immediate
    if (gc_env.cr[0] == 0) goto L_8002EA4C;
    gc_env.lr = gc_env.r[12]; // Move to link register
    gc_env.r[3] = gc_env.r[1] + 12; // addi r3, r1, 0xc
    // Call function at gc_env.lr; // Branch to link register
    gc_env.cr[0] = (gc_env.r[3] == 0x0) ? 0 : (gc_env.r[3] < 0x0 ? -1 : 1); // Compare with immediate
    if (gc_env.cr[0] == 0) goto L_8002EA4C;
    gc_env.r[3] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0xc);
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x10);
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x20, gc_env.r[3]);
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x24, gc_env.r[0]);
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x14);
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x28, gc_env.r[0]);
    L_8002EA4C:
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x24);
    gc_env.r[31] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x1c);
    gc_env.r[30] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x18);
    gc_env.r[1] += 32; // addi r1, r1, 0x20
    gc_env.lr = gc_env.r[0]; // Move to link register
    return;
}

// Function: Camera_8002EA64
void Camera_8002EA64(void) {
    gc_env.r[0] = gc_env.lr; // Move from link register
    gc_env.r[4] = ((uint32_t)&cm_80452C68 >> 16) & 0xFFFF; // lis r4, cm_80452C68@ha
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x4, gc_env.r[0]);
    gc_mem_write32(gc_env.ram, gc_env.r[1] + -0x20, gc_env.r[1]);
    gc_env.r[1] = gc_env.r[1] + -0x20;
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x1c, gc_env.r[31]);
    gc_env.r[31] = gc_env.r[4] + ((uint32_t)&cm_80452C68 & 0xFFFF); // addi r31, r4, cm_80452C68@l
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x18, gc_env.r[30]);
    gc_env.r[30] = gc_env.r[3] + 0; // addi r30, r3, 0x0
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[31] + 0x4);
    gc_env.cr[0] = (gc_env.r[0] == 0x6) ? 0 : (gc_env.r[0] < 0x6 ? -1 : 1); // Compare with immediate
    if (gc_env.cr[0] == 0) goto L_8002EA94;
    Camera_8002FE38();
    L_8002EA94:
    gc_env.r[0] = gc_mem_read8(gc_env.ram, gc_env.r[31] + 0x341);
    gc_env.r[3] = 0x1;
    uint32_t rotated = gc_env.r[3] << 3; // rlwimi r0, r3, 3, 27, 28
    gc_env.r[0] = (gc_env.r[0] & ~0x18) | (rotated & 0x18);
    gc_mem_write8(gc_env.ram, gc_env.r[31] + 0x341, gc_env.r[0]);
    gc_env.r[5] = gc_env.r[31] + 860; // addi r5, r31, 0x35c
    gc_env.r[3] = gc_mem_read32(gc_env.ram, gc_env.r[30] + 0x0);
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[30] + 0x4);
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x35c, gc_env.r[3]);
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x360, gc_env.r[0]);
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[30] + 0x8);
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x364, gc_env.r[0]);
    gc_env.r[0] = gc_mem_read8(gc_env.ram, gc_env.r[31] + 0x341);
    gc_env.r[0] = (gc_env.r[0] >> 3) & 0x3; // extrwi r0, r0, 2, 27
    gc_env.cr[0] = (gc_env.r[0] == 0x2) ? 0 : (gc_env.r[0] < 0x2 ? -1 : 1); // Compare with immediate
    if (gc_env.cr[0] == 0) goto L_8002EB44;
    if (gc_env.cr[0] >= 0) goto L_8002EAE4;
    gc_env.cr[0] = (gc_env.r[0] == 0x0) ? 0 : (gc_env.r[0] < 0x0 ? -1 : 1); // Compare with immediate
    if (gc_env.cr[0] == 0) goto L_8002EB44;
    if (gc_env.cr[0] >= 0) goto L_8002EAF0;
    goto L_8002EB44;
    L_8002EAE4:
    gc_env.cr[0] = (gc_env.r[0] == 0x4) ? 0 : (gc_env.r[0] < 0x4 ? -1 : 1); // Compare with immediate
    if (gc_env.cr[0] >= 0) goto L_8002EB44;
    goto L_8002EB0C;
    L_8002EAF0:
    gc_env.r[3] = gc_mem_read32(gc_env.ram, gc_env.r[5] + 0x0);
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[5] + 0x4);
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x38, gc_env.r[3]);
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x3c, gc_env.r[0]);
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[5] + 0x8);
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x40, gc_env.r[0]);
    goto L_8002EB44;
    L_8002EB0C:
    gc_env.r[12] = gc_mem_read32(gc_env.ram, gc_env.r[5] + 0x0);
    gc_env.cr[0] = ((uint32_t)gc_env.r[12] == 0x0) ? 0 : ((uint32_t)gc_env.r[12] < 0x0 ? -1 : 1); // Logical compare with immediate
    if (gc_env.cr[0] == 0) goto L_8002EB44;
    gc_env.lr = gc_env.r[12]; // Move to link register
    gc_env.r[3] = gc_env.r[1] + 12; // addi r3, r1, 0xc
    // Call function at gc_env.lr; // Branch to link register
    gc_env.cr[0] = (gc_env.r[3] == 0x0) ? 0 : (gc_env.r[3] < 0x0 ? -1 : 1); // Compare with immediate
    if (gc_env.cr[0] == 0) goto L_8002EB44;
    gc_env.r[3] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0xc);
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x10);
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x38, gc_env.r[3]);
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x3c, gc_env.r[0]);
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x14);
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x40, gc_env.r[0]);
    L_8002EB44:
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x24);
    gc_env.r[31] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x1c);
    gc_env.r[30] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x18);
    gc_env.r[1] += 32; // addi r1, r1, 0x20
    gc_env.lr = gc_env.r[0]; // Move to link register
    return;
}

// Function: Camera_8002EB5C
void Camera_8002EB5C(void) {
    gc_env.r[0] = gc_env.lr; // Move from link register
    gc_env.r[3] = ((uint32_t)&cm_80452C68 >> 16) & 0xFFFF; // lis r3, cm_80452C68@ha
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x4, gc_env.r[0]);
    gc_mem_write32(gc_env.ram, gc_env.r[1] + -0x28, gc_env.r[1]);
    gc_env.r[1] = gc_env.r[1] + -0x28;
    uint64_t temp;
    memcpy(&temp, &gc_env.f[31], sizeof(double));
    gc_mem_write64(gc_env.ram, gc_env.r[1] + 0x20, temp); // stfd f31, 0x20(r1)
    gc_env.f[31] = gc_env.f[1]; // fmr f31, f1
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x1c, gc_env.r[31]);
    gc_env.r[31] = gc_env.r[3] + ((uint32_t)&cm_80452C68 & 0xFFFF); // addi r31, r3, cm_80452C68@l
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[31] + 0x4);
    gc_env.cr[0] = (gc_env.r[0] == 0x6) ? 0 : (gc_env.r[0] < 0x6 ? -1 : 1); // Compare with immediate
    if (gc_env.cr[0] == 0) goto L_8002EB8C;
    Camera_8002FE38();
    L_8002EB8C:
    gc_env.r[4] = gc_env.r[31] + 833; // addi r4, r31, 0x341
    gc_env.r[3] = gc_mem_read8(gc_env.ram, gc_env.r[31] + 0x341);
    gc_env.r[0] = (gc_env.r[3] >> 3) & 0x3; // extrwi r0, r3, 2, 27
    gc_env.cr[0] = ((uint32_t)gc_env.r[0] == 0x2) ? 0 : ((uint32_t)gc_env.r[0] < 0x2 ? -1 : 1); // Logical compare with immediate
    if (gc_env.cr[0] == 0) goto L_8002EBC8;
    gc_env.r[0] = 0x2;
    uint32_t rotated = gc_env.r[0] << 3; // rlwimi r3, r0, 3, 27, 28
    gc_env.r[3] = (gc_env.r[3] & ~0x18) | (rotated & 0x18);
    gc_mem_write8(gc_env.ram, gc_env.r[4] + 0x0, gc_env.r[3]);
    gc_env.r[3] = 0x0;
    gc_env.r[0] = gc_mem_read8(gc_env.ram, gc_env.r[31] + 0x35c);
    uint32_t rotated = gc_env.r[3] << 7; // rlwimi r0, r3, 7, 24, 24
    gc_env.r[0] = (gc_env.r[0] & ~0x80) | (rotated & 0x80);
    gc_mem_write8(gc_env.ram, gc_env.r[31] + 0x35c, gc_env.r[0]);
    gc_env.r[0] = gc_mem_read8(gc_env.ram, gc_env.r[31] + 0x35c);
    uint32_t rotated = gc_env.r[3] << 5; // rlwimi r0, r3, 5, 26, 26
    gc_env.r[0] = (gc_env.r[0] & ~0x20) | (rotated & 0x20);
    gc_mem_write8(gc_env.ram, gc_env.r[31] + 0x35c, gc_env.r[0]);
    L_8002EBC8:
    float temp = (float)gc_env.f[31]; // stfs f31, 0x360(r31)
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x360, *(uint32_t*)&temp);
    gc_env.r[5] = gc_env.r[31] + 860; // addi r5, r31, 0x35c
    gc_env.r[3] = 0x1;
    gc_env.r[0] = gc_mem_read8(gc_env.ram, gc_env.r[31] + 0x35c);
    uint32_t rotated = gc_env.r[3] << 6; // rlwimi r0, r3, 6, 25, 25
    gc_env.r[0] = (gc_env.r[0] & ~0x40) | (rotated & 0x40);
    gc_mem_write8(gc_env.ram, gc_env.r[31] + 0x35c, gc_env.r[0]);
    gc_env.r[0] = gc_mem_read8(gc_env.ram, gc_env.r[4] + 0x0);
    gc_env.r[0] = (gc_env.r[0] >> 3) & 0x3; // extrwi r0, r0, 2, 27
    gc_env.cr[0] = (gc_env.r[0] == 0x2) ? 0 : (gc_env.r[0] < 0x2 ? -1 : 1); // Compare with immediate
    if (gc_env.cr[0] == 0) goto L_8002EC64;
    if (gc_env.cr[0] >= 0) goto L_8002EC04;
    gc_env.cr[0] = (gc_env.r[0] == 0x0) ? 0 : (gc_env.r[0] < 0x0 ? -1 : 1); // Compare with immediate
    if (gc_env.cr[0] == 0) goto L_8002EC64;
    if (gc_env.cr[0] >= 0) goto L_8002EC10;
    goto L_8002EC64;
    L_8002EC04:
    gc_env.cr[0] = (gc_env.r[0] == 0x4) ? 0 : (gc_env.r[0] < 0x4 ? -1 : 1); // Compare with immediate
    if (gc_env.cr[0] >= 0) goto L_8002EC64;
    goto L_8002EC2C;
    L_8002EC10:
    gc_env.r[3] = gc_mem_read32(gc_env.ram, gc_env.r[5] + 0x0);
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[5] + 0x4);
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x38, gc_env.r[3]);
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x3c, gc_env.r[0]);
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[5] + 0x8);
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x40, gc_env.r[0]);
    goto L_8002EC64;
    L_8002EC2C:
    gc_env.r[12] = gc_mem_read32(gc_env.ram, gc_env.r[5] + 0x0);
    gc_env.cr[0] = ((uint32_t)gc_env.r[12] == 0x0) ? 0 : ((uint32_t)gc_env.r[12] < 0x0 ? -1 : 1); // Logical compare with immediate
    if (gc_env.cr[0] == 0) goto L_8002EC64;
    gc_env.lr = gc_env.r[12]; // Move to link register
    gc_env.r[3] = gc_env.r[1] + 12; // addi r3, r1, 0xc
    // Call function at gc_env.lr; // Branch to link register
    gc_env.cr[0] = (gc_env.r[3] == 0x0) ? 0 : (gc_env.r[3] < 0x0 ? -1 : 1); // Compare with immediate
    if (gc_env.cr[0] == 0) goto L_8002EC64;
    gc_env.r[3] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0xc);
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x10);
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x38, gc_env.r[3]);
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x3c, gc_env.r[0]);
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x14);
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x40, gc_env.r[0]);
    L_8002EC64:
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x2c);
    uint64_t temp = gc_mem_read64(gc_env.ram, gc_env.r[1] + 0x20); // lfd f31, 0x20(r1)
    gc_env.d[31] = *(double*)&temp;
    gc_env.r[31] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x1c);
    gc_env.r[1] += 40; // addi r1, r1, 0x28
    gc_env.lr = gc_env.r[0]; // Move to link register
    return;
}

// Function: Camera_8002EC7C
void Camera_8002EC7C(void) {
    gc_env.r[0] = gc_env.lr; // Move from link register
    gc_env.r[3] = ((uint32_t)&cm_80452C68 >> 16) & 0xFFFF; // lis r3, cm_80452C68@ha
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x4, gc_env.r[0]);
    gc_mem_write32(gc_env.ram, gc_env.r[1] + -0x28, gc_env.r[1]);
    gc_env.r[1] = gc_env.r[1] + -0x28;
    uint64_t temp;
    memcpy(&temp, &gc_env.f[31], sizeof(double));
    gc_mem_write64(gc_env.ram, gc_env.r[1] + 0x20, temp); // stfd f31, 0x20(r1)
    gc_env.f[31] = gc_env.f[1]; // fmr f31, f1
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x1c, gc_env.r[31]);
    gc_env.r[31] = gc_env.r[3] + ((uint32_t)&cm_80452C68 & 0xFFFF); // addi r31, r3, cm_80452C68@l
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[31] + 0x4);
    gc_env.cr[0] = (gc_env.r[0] == 0x6) ? 0 : (gc_env.r[0] < 0x6 ? -1 : 1); // Compare with immediate
    if (gc_env.cr[0] == 0) goto L_8002ECAC;
    Camera_8002FE38();
    L_8002ECAC:
    gc_env.r[4] = gc_env.r[31] + 833; // addi r4, r31, 0x341
    gc_env.r[3] = gc_mem_read8(gc_env.ram, gc_env.r[31] + 0x341);
    gc_env.r[0] = (gc_env.r[3] >> 3) & 0x3; // extrwi r0, r3, 2, 27
    gc_env.cr[0] = ((uint32_t)gc_env.r[0] == 0x2) ? 0 : ((uint32_t)gc_env.r[0] < 0x2 ? -1 : 1); // Logical compare with immediate
    if (gc_env.cr[0] == 0) goto L_8002ECE8;
    gc_env.r[0] = 0x2;
    uint32_t rotated = gc_env.r[0] << 3; // rlwimi r3, r0, 3, 27, 28
    gc_env.r[3] = (gc_env.r[3] & ~0x18) | (rotated & 0x18);
    gc_mem_write8(gc_env.ram, gc_env.r[4] + 0x0, gc_env.r[3]);
    gc_env.r[3] = 0x0;
    gc_env.r[0] = gc_mem_read8(gc_env.ram, gc_env.r[31] + 0x35c);
    uint32_t rotated = gc_env.r[3] << 7; // rlwimi r0, r3, 7, 24, 24
    gc_env.r[0] = (gc_env.r[0] & ~0x80) | (rotated & 0x80);
    gc_mem_write8(gc_env.ram, gc_env.r[31] + 0x35c, gc_env.r[0]);
    gc_env.r[0] = gc_mem_read8(gc_env.ram, gc_env.r[31] + 0x35c);
    uint32_t rotated = gc_env.r[3] << 6; // rlwimi r0, r3, 6, 25, 25
    gc_env.r[0] = (gc_env.r[0] & ~0x40) | (rotated & 0x40);
    gc_mem_write8(gc_env.ram, gc_env.r[31] + 0x35c, gc_env.r[0]);
    L_8002ECE8:
    float temp = (float)gc_env.f[31]; // stfs f31, 0x364(r31)
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x364, *(uint32_t*)&temp);
    gc_env.r[5] = gc_env.r[31] + 860; // addi r5, r31, 0x35c
    gc_env.r[3] = 0x1;
    gc_env.r[0] = gc_mem_read8(gc_env.ram, gc_env.r[31] + 0x35c);
    uint32_t rotated = gc_env.r[3] << 5; // rlwimi r0, r3, 5, 26, 26
    gc_env.r[0] = (gc_env.r[0] & ~0x20) | (rotated & 0x20);
    gc_mem_write8(gc_env.ram, gc_env.r[31] + 0x35c, gc_env.r[0]);
    gc_env.r[0] = gc_mem_read8(gc_env.ram, gc_env.r[4] + 0x0);
    gc_env.r[0] = (gc_env.r[0] >> 3) & 0x3; // extrwi r0, r0, 2, 27
    gc_env.cr[0] = (gc_env.r[0] == 0x2) ? 0 : (gc_env.r[0] < 0x2 ? -1 : 1); // Compare with immediate
    if (gc_env.cr[0] == 0) goto L_8002ED84;
    if (gc_env.cr[0] >= 0) goto L_8002ED24;
    gc_env.cr[0] = (gc_env.r[0] == 0x0) ? 0 : (gc_env.r[0] < 0x0 ? -1 : 1); // Compare with immediate
    if (gc_env.cr[0] == 0) goto L_8002ED84;
    if (gc_env.cr[0] >= 0) goto L_8002ED30;
    goto L_8002ED84;
    L_8002ED24:
    gc_env.cr[0] = (gc_env.r[0] == 0x4) ? 0 : (gc_env.r[0] < 0x4 ? -1 : 1); // Compare with immediate
    if (gc_env.cr[0] >= 0) goto L_8002ED84;
    goto L_8002ED4C;
    L_8002ED30:
    gc_env.r[3] = gc_mem_read32(gc_env.ram, gc_env.r[5] + 0x0);
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[5] + 0x4);
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x38, gc_env.r[3]);
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x3c, gc_env.r[0]);
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[5] + 0x8);
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x40, gc_env.r[0]);
    goto L_8002ED84;
    L_8002ED4C:
    gc_env.r[12] = gc_mem_read32(gc_env.ram, gc_env.r[5] + 0x0);
    gc_env.cr[0] = ((uint32_t)gc_env.r[12] == 0x0) ? 0 : ((uint32_t)gc_env.r[12] < 0x0 ? -1 : 1); // Logical compare with immediate
    if (gc_env.cr[0] == 0) goto L_8002ED84;
    gc_env.lr = gc_env.r[12]; // Move to link register
    gc_env.r[3] = gc_env.r[1] + 12; // addi r3, r1, 0xc
    // Call function at gc_env.lr; // Branch to link register
    gc_env.cr[0] = (gc_env.r[3] == 0x0) ? 0 : (gc_env.r[3] < 0x0 ? -1 : 1); // Compare with immediate
    if (gc_env.cr[0] == 0) goto L_8002ED84;
    gc_env.r[3] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0xc);
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x10);
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x38, gc_env.r[3]);
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x3c, gc_env.r[0]);
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x14);
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x40, gc_env.r[0]);
    L_8002ED84:
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x2c);
    uint64_t temp = gc_mem_read64(gc_env.ram, gc_env.r[1] + 0x20); // lfd f31, 0x20(r1)
    gc_env.d[31] = *(double*)&temp;
    gc_env.r[31] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x1c);
    gc_env.r[1] += 40; // addi r1, r1, 0x28
    gc_env.lr = gc_env.r[0]; // Move to link register
    return;
}

// Function: Camera_8002ED9C
void Camera_8002ED9C(void) {
    gc_env.r[0] = gc_env.lr; // Move from link register
    gc_env.r[3] = ((uint32_t)&cm_80452C68 >> 16) & 0xFFFF; // lis r3, cm_80452C68@ha
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x4, gc_env.r[0]);
    gc_mem_write32(gc_env.ram, gc_env.r[1] + -0x30, gc_env.r[1]);
    gc_env.r[1] = gc_env.r[1] + -0x30;
    uint64_t temp;
    memcpy(&temp, &gc_env.f[31], sizeof(double));
    gc_mem_write64(gc_env.ram, gc_env.r[1] + 0x28, temp); // stfd f31, 0x28(r1)
    gc_env.f[31] = gc_env.f[1]; // fmr f31, f1
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x24, gc_env.r[31]);
    gc_env.r[31] = gc_env.r[3] + ((uint32_t)&cm_80452C68 & 0xFFFF); // addi r31, r3, cm_80452C68@l
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[31] + 0x4);
    gc_env.cr[0] = (gc_env.r[0] == 0x6) ? 0 : (gc_env.r[0] < 0x6 ? -1 : 1); // Compare with immediate
    if (gc_env.cr[0] == 0) goto L_8002EDCC;
    Camera_8002FE38();
    L_8002EDCC:
    gc_env.r[4] = gc_env.r[31] + 833; // addi r4, r31, 0x341
    gc_env.r[3] = gc_mem_read8(gc_env.ram, gc_env.r[31] + 0x341);
    gc_env.r[0] = (gc_env.r[3] >> 3) & 0x3; // extrwi r0, r3, 2, 27
    gc_env.cr[0] = ((uint32_t)gc_env.r[0] == 0x2) ? 0 : ((uint32_t)gc_env.r[0] < 0x2 ? -1 : 1); // Logical compare with immediate
    if (gc_env.cr[0] == 0) goto L_8002EE08;
    gc_env.r[0] = 0x2;
    uint32_t rotated = gc_env.r[0] << 3; // rlwimi r3, r0, 3, 27, 28
    gc_env.r[3] = (gc_env.r[3] & ~0x18) | (rotated & 0x18);
    gc_mem_write8(gc_env.ram, gc_env.r[4] + 0x0, gc_env.r[3]);
    gc_env.r[3] = 0x0;
    gc_env.r[0] = gc_mem_read8(gc_env.ram, gc_env.r[31] + 0x35c);
    uint32_t rotated = gc_env.r[3] << 6; // rlwimi r0, r3, 6, 25, 25
    gc_env.r[0] = (gc_env.r[0] & ~0x40) | (rotated & 0x40);
    gc_mem_write8(gc_env.ram, gc_env.r[31] + 0x35c, gc_env.r[0]);
    gc_env.r[0] = gc_mem_read8(gc_env.ram, gc_env.r[31] + 0x35c);
    uint32_t rotated = gc_env.r[3] << 5; // rlwimi r0, r3, 5, 26, 26
    gc_env.r[0] = (gc_env.r[0] & ~0x20) | (rotated & 0x20);
    gc_mem_write8(gc_env.ram, gc_env.r[31] + 0x35c, gc_env.r[0]);
    L_8002EE08:
    // Unknown opcode: fctiwz f0 f31
    gc_env.r[5] = gc_env.r[31] + 860; // addi r5, r31, 0x35c
    gc_env.r[3] = 0x1;
    uint64_t temp;
    memcpy(&temp, &gc_env.f[0], sizeof(double));
    gc_mem_write64(gc_env.ram, gc_env.r[1] + 0x18, temp); // stfd f0, 0x18(r1)
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x1c);
    gc_mem_write16(gc_env.ram, gc_env.r[31] + 0x35e, gc_env.r[0]);
    gc_env.r[0] = gc_mem_read8(gc_env.ram, gc_env.r[31] + 0x35c);
    uint32_t rotated = gc_env.r[3] << 7; // rlwimi r0, r3, 7, 24, 24
    gc_env.r[0] = (gc_env.r[0] & ~0x80) | (rotated & 0x80);
    gc_mem_write8(gc_env.ram, gc_env.r[31] + 0x35c, gc_env.r[0]);
    gc_env.r[0] = gc_mem_read8(gc_env.ram, gc_env.r[4] + 0x0);
    gc_env.r[0] = (gc_env.r[0] >> 3) & 0x3; // extrwi r0, r0, 2, 27
    gc_env.cr[0] = (gc_env.r[0] == 0x2) ? 0 : (gc_env.r[0] < 0x2 ? -1 : 1); // Compare with immediate
    if (gc_env.cr[0] == 0) goto L_8002EEB0;
    if (gc_env.cr[0] >= 0) goto L_8002EE50;
    gc_env.cr[0] = (gc_env.r[0] == 0x0) ? 0 : (gc_env.r[0] < 0x0 ? -1 : 1); // Compare with immediate
    if (gc_env.cr[0] == 0) goto L_8002EEB0;
    if (gc_env.cr[0] >= 0) goto L_8002EE5C;
    goto L_8002EEB0;
    L_8002EE50:
    gc_env.cr[0] = (gc_env.r[0] == 0x4) ? 0 : (gc_env.r[0] < 0x4 ? -1 : 1); // Compare with immediate
    if (gc_env.cr[0] >= 0) goto L_8002EEB0;
    goto L_8002EE78;
    L_8002EE5C:
    gc_env.r[3] = gc_mem_read32(gc_env.ram, gc_env.r[5] + 0x0);
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[5] + 0x4);
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x38, gc_env.r[3]);
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x3c, gc_env.r[0]);
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[5] + 0x8);
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x40, gc_env.r[0]);
    goto L_8002EEB0;
    L_8002EE78:
    gc_env.r[12] = gc_mem_read32(gc_env.ram, gc_env.r[5] + 0x0);
    gc_env.cr[0] = ((uint32_t)gc_env.r[12] == 0x0) ? 0 : ((uint32_t)gc_env.r[12] < 0x0 ? -1 : 1); // Logical compare with immediate
    if (gc_env.cr[0] == 0) goto L_8002EEB0;
    gc_env.lr = gc_env.r[12]; // Move to link register
    gc_env.r[3] = gc_env.r[1] + 12; // addi r3, r1, 0xc
    // Call function at gc_env.lr; // Branch to link register
    gc_env.cr[0] = (gc_env.r[3] == 0x0) ? 0 : (gc_env.r[3] < 0x0 ? -1 : 1); // Compare with immediate
    if (gc_env.cr[0] == 0) goto L_8002EEB0;
    gc_env.r[3] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0xc);
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x10);
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x38, gc_env.r[3]);
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x3c, gc_env.r[0]);
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x14);
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x40, gc_env.r[0]);
    L_8002EEB0:
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x34);
    uint64_t temp = gc_mem_read64(gc_env.ram, gc_env.r[1] + 0x28); // lfd f31, 0x28(r1)
    gc_env.d[31] = *(double*)&temp;
    gc_env.r[31] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x24);
    gc_env.r[1] += 48; // addi r1, r1, 0x30
    gc_env.lr = gc_env.r[0]; // Move to link register
    return;
}

// Function: Camera_8002EEC8
void Camera_8002EEC8(void) {
    gc_env.r[0] = gc_env.lr; // Move from link register
    gc_env.r[3] = ((uint32_t)&cm_80452C68 >> 16) & 0xFFFF; // lis r3, cm_80452C68@ha
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x4, gc_env.r[0]);
    gc_env.r[3] = gc_env.r[3] + ((uint32_t)&cm_80452C68 & 0xFFFF); // addi r3, r3, cm_80452C68@l
    gc_mem_write32(gc_env.ram, gc_env.r[1] + -0x18, gc_env.r[1]);
    gc_env.r[1] = gc_env.r[1] + -0x18;
    uint64_t temp;
    memcpy(&temp, &gc_env.f[31], sizeof(double));
    gc_mem_write64(gc_env.ram, gc_env.r[1] + 0x10, temp); // stfd f31, 0x10(r1)
    gc_env.f[31] = gc_env.f[1]; // fmr f31, f1
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[3] + 0x4);
    gc_env.cr[0] = (gc_env.r[0] == 0x6) ? 0 : (gc_env.r[0] < 0x6 ? -1 : 1); // Compare with immediate
    if (gc_env.cr[0] == 0) goto L_8002EEF4;
    Camera_8002FE38();
    L_8002EEF4:
    gc_env.r[3] = ((uint32_t)&cm_80452C68 >> 16) & 0xFFFF; // lis r3, cm_80452C68@ha
    gc_env.r[3] = gc_env.r[3] + ((uint32_t)&cm_80452C68 & 0xFFFF); // addi r3, r3, cm_80452C68@l
    float temp = (float)gc_env.f[31]; // stfs f31, 0x48(r3)
    gc_mem_write32(gc_env.ram, gc_env.r[3] + 0x48, *(uint32_t*)&temp);
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x1c);
    uint64_t temp = gc_mem_read64(gc_env.ram, gc_env.r[1] + 0x10); // lfd f31, 0x10(r1)
    gc_env.d[31] = *(double*)&temp;
    gc_env.r[1] += 24; // addi r1, r1, 0x18
    gc_env.lr = gc_env.r[0]; // Move to link register
    return;
}

// Function: Camera_8002EF14
void Camera_8002EF14(void) {
    gc_env.r[0] = gc_env.lr; // Move from link register
    gc_env.r[3] = ((uint32_t)&cm_80452C68 >> 16) & 0xFFFF; // lis r3, cm_80452C68@ha
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x4, gc_env.r[0]);
    gc_mem_write32(gc_env.ram, gc_env.r[1] + -0x30, gc_env.r[1]);
    gc_env.r[1] = gc_env.r[1] + -0x30;
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x2c, gc_env.r[31]);
    gc_env.r[31] = gc_env.r[3] + ((uint32_t)&cm_80452C68 & 0xFFFF); // addi r31, r3, cm_80452C68@l
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x28, gc_env.r[30]);
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[31] + 0x4);
    gc_env.cr[0] = (gc_env.r[0] == 0x6) ? 0 : (gc_env.r[0] < 0x6 ? -1 : 1); // Compare with immediate
    if (gc_env.cr[0] == 0) goto L_8002EF40;
    Camera_8002FE38();
    L_8002EF40:
    gc_env.r[30] = gc_env.r[31] + 833; // addi r30, r31, 0x341
    gc_env.r[0] = gc_mem_read8(gc_env.ram, gc_env.r[31] + 0x341);
    gc_env.r[3] = 0x0;
    uint32_t rotated = gc_env.r[3] << 1; // rlwimi r0, r3, 1, 29, 30
    gc_env.r[0] = (gc_env.r[0] & ~0x6) | (rotated & 0x6);
    gc_mem_write8(gc_env.ram, gc_env.r[31] + 0x341, gc_env.r[0]);
    gc_env.r[0] = gc_mem_read8(gc_env.ram, gc_env.r[31] + 0x341);
    gc_env.r[0] = (gc_env.r[0] >> 5) & 0x3; // extrwi r0, r0, 2, 25
    gc_env.cr[0] = (gc_env.r[0] == 0x2) ? 0 : (gc_env.r[0] < 0x2 ? -1 : 1); // Compare with immediate
    if (gc_env.cr[0] == 0) goto L_8002EFBC;
    if (gc_env.cr[0] >= 0) goto L_8002EF78;
    gc_env.cr[0] = (gc_env.r[0] == 0x0) ? 0 : (gc_env.r[0] < 0x0 ? -1 : 1); // Compare with immediate
    if (gc_env.cr[0] == 0) goto L_8002F010;
    if (gc_env.cr[0] >= 0) goto L_8002EF84;
    goto L_8002F010;
    L_8002EF78:
    gc_env.cr[0] = (gc_env.r[0] == 0x4) ? 0 : (gc_env.r[0] < 0x4 ? -1 : 1); // Compare with immediate
    if (gc_env.cr[0] >= 0) goto L_8002F010;
    goto L_8002EFD8;
    L_8002EF84:
    gc_env.r[3] = gc_mem_read32(gc_env.ram, gc_env.r[31] + 0x344);
    Player_GetEntity();
    gc_env.cr[0] = ((uint32_t)gc_env.r[3] == 0x0) ? 0 : ((uint32_t)gc_env.r[3] < 0x0 ? -1 : 1); // Logical compare with immediate
    if (gc_env.cr[0] == 0) goto L_8002F010;
    ftLib_80086B74();
    gc_env.cr[0] = ((uint32_t)gc_env.r[3] == 0x0) ? 0 : ((uint32_t)gc_env.r[3] < 0x0 ? -1 : 1); // Logical compare with immediate
    if (gc_env.cr[0] == 0) goto L_8002F010;
    gc_env.r[4] = gc_mem_read32(gc_env.ram, gc_env.r[3] + 0x1c);
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[3] + 0x20);
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x20, gc_env.r[4]);
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x24, gc_env.r[0]);
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[3] + 0x24);
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x28, gc_env.r[0]);
    goto L_8002F010;
    L_8002EFBC:
    gc_env.r[3] = gc_mem_read32(gc_env.ram, gc_env.r[31] + 0x344);
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[31] + 0x348);
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x20, gc_env.r[3]);
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x24, gc_env.r[0]);
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[31] + 0x34c);
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x28, gc_env.r[0]);
    goto L_8002F010;
    L_8002EFD8:
    gc_env.r[12] = gc_mem_read32(gc_env.ram, gc_env.r[31] + 0x344);
    gc_env.cr[0] = ((uint32_t)gc_env.r[12] == 0x0) ? 0 : ((uint32_t)gc_env.r[12] < 0x0 ? -1 : 1); // Logical compare with immediate
    if (gc_env.cr[0] == 0) goto L_8002F010;
    gc_env.lr = gc_env.r[12]; // Move to link register
    gc_env.r[3] = gc_env.r[1] + 24; // addi r3, r1, 0x18
    // Call function at gc_env.lr; // Branch to link register
    gc_env.cr[0] = (gc_env.r[3] == 0x0) ? 0 : (gc_env.r[3] < 0x0 ? -1 : 1); // Compare with immediate
    if (gc_env.cr[0] == 0) goto L_8002F010;
    gc_env.r[3] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x18);
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x1c);
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x20, gc_env.r[3]);
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x24, gc_env.r[0]);
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x20);
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x28, gc_env.r[0]);
    L_8002F010:
    gc_env.r[0] = gc_mem_read8(gc_env.ram, gc_env.r[30] + 0x0);
    gc_env.r[0] = (gc_env.r[0] >> 5) & 0x3; // extrwi r0, r0, 2, 25
    gc_env.cr[0] = (gc_env.r[0] == 0x4) ? 0 : (gc_env.r[0] < 0x4 ? -1 : 1); // Compare with immediate
    if (gc_env.cr[0] >= 0) goto L_8002F03C;
    gc_env.cr[0] = (gc_env.r[0] == 0x0) ? 0 : (gc_env.r[0] < 0x0 ? -1 : 1); // Compare with immediate
    if (gc_env.cr[0] >= 0) goto L_8002F02C;
    goto L_8002F03C;
    L_8002F02C:
    gc_env.r[3] = gc_env.r[31] + 848; // addi r3, r31, 0x350
    gc_env.r[4] = gc_env.r[31] + 32; // addi r4, r31, 0x20
    gc_env.r[5] = gc_env.r[31] + 20; // addi r5, r31, 0x14
    Camera_8002DFE4();
    L_8002F03C:
    gc_env.r[0] = gc_mem_read8(gc_env.ram, gc_env.r[30] + 0x0);
    gc_env.r[0] = (gc_env.r[0] >> 3) & 0x3; // extrwi r0, r0, 2, 27
    gc_env.cr[0] = (gc_env.r[0] == 0x2) ? 0 : (gc_env.r[0] < 0x2 ? -1 : 1); // Compare with immediate
    if (gc_env.cr[0] == 0) goto L_8002F0C0;
    if (gc_env.cr[0] >= 0) goto L_8002F060;
    gc_env.cr[0] = (gc_env.r[0] == 0x0) ? 0 : (gc_env.r[0] < 0x0 ? -1 : 1); // Compare with immediate
    if (gc_env.cr[0] == 0) goto L_8002F0C0;
    if (gc_env.cr[0] >= 0) goto L_8002F06C;
    goto L_8002F0C0;
    L_8002F060:
    gc_env.cr[0] = (gc_env.r[0] == 0x4) ? 0 : (gc_env.r[0] < 0x4 ? -1 : 1); // Compare with immediate
    if (gc_env.cr[0] >= 0) goto L_8002F0C0;
    goto L_8002F088;
    L_8002F06C:
    gc_env.r[3] = gc_mem_read32(gc_env.ram, gc_env.r[31] + 0x35c);
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[31] + 0x360);
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x38, gc_env.r[3]);
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x3c, gc_env.r[0]);
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[31] + 0x364);
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x40, gc_env.r[0]);
    goto L_8002F0C0;
    L_8002F088:
    gc_env.r[12] = gc_mem_read32(gc_env.ram, gc_env.r[31] + 0x35c);
    gc_env.cr[0] = ((uint32_t)gc_env.r[12] == 0x0) ? 0 : ((uint32_t)gc_env.r[12] < 0x0 ? -1 : 1); // Logical compare with immediate
    if (gc_env.cr[0] == 0) goto L_8002F0C0;
    gc_env.lr = gc_env.r[12]; // Move to link register
    gc_env.r[3] = gc_env.r[1] + 8; // addi r3, r1, 0x8
    // Call function at gc_env.lr; // Branch to link register
    gc_env.cr[0] = (gc_env.r[3] == 0x0) ? 0 : (gc_env.r[3] < 0x0 ? -1 : 1); // Compare with immediate
    if (gc_env.cr[0] == 0) goto L_8002F0C0;
    gc_env.r[3] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x8);
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0xc);
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x38, gc_env.r[3]);
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x3c, gc_env.r[0]);
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x10);
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x40, gc_env.r[0]);
    L_8002F0C0:
    Camera_8002E234();
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[31] + 0x48); // lfs f0, 0x48(r31)
    gc_env.f[0] = *(float*)&temp;
    float temp = (float)gc_env.f[0]; // stfs f0, 0x44(r31)
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x44, *(uint32_t*)&temp);
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x34);
    gc_env.r[31] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x2c);
    gc_env.r[30] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x28);
    gc_env.r[1] += 48; // addi r1, r1, 0x30
    gc_env.lr = gc_env.r[0]; // Move to link register
    return;
}

// Function: Camera_8002F0E4
void Camera_8002F0E4(void) {
    gc_env.r[0] = gc_env.lr; // Move from link register
    gc_env.r[4] = ((uint32_t)&cm_80452C68 >> 16) & 0xFFFF; // lis r4, cm_80452C68@ha
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x4, gc_env.r[0]);
    gc_mem_write32(gc_env.ram, gc_env.r[1] + -0x40, gc_env.r[1]);
    gc_env.r[1] = gc_env.r[1] + -0x40;
    uint64_t temp;
    memcpy(&temp, &gc_env.f[31], sizeof(double));
    gc_mem_write64(gc_env.ram, gc_env.r[1] + 0x38, temp); // stfd f31, 0x38(r1)
    uint64_t temp;
    memcpy(&temp, &gc_env.f[30], sizeof(double));
    gc_mem_write64(gc_env.ram, gc_env.r[1] + 0x30, temp); // stfd f30, 0x30(r1)
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x2c, gc_env.r[31]);
    gc_env.r[31] = gc_env.r[4] + ((uint32_t)&cm_80452C68 & 0xFFFF); // addi r31, r4, cm_80452C68@l
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x28, gc_env.r[30]);
    gc_env.r[30] = gc_env.r[3] + 0; // addi r30, r3, 0x0
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[31] + 0x4);
    gc_env.cr[0] = (gc_env.r[0] == 0x6) ? 0 : (gc_env.r[0] < 0x6 ? -1 : 1); // Compare with immediate
    if (gc_env.cr[0] == 0) goto L_8002F11C;
    Camera_8002FE38();
    L_8002F11C:
    gc_env.r[4] = gc_env.r[31] + 833; // addi r4, r31, 0x341
    gc_env.r[0] = gc_mem_read8(gc_env.ram, gc_env.r[31] + 0x341);
    gc_env.r[3] = 0x1;
    uint32_t rotated = gc_env.r[3] << 1; // rlwimi r0, r3, 1, 29, 30
    gc_env.r[0] = (gc_env.r[0] & ~0x6) | (rotated & 0x6);
    gc_mem_write8(gc_env.ram, gc_env.r[31] + 0x341, gc_env.r[0]);
    gc_env.r[0] = 0x0;
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x378, gc_env.r[0]);
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x37c, gc_env.r[30]);
    gc_env.r[0] = gc_mem_read8(gc_env.ram, gc_env.r[31] + 0x341);
    gc_env.r[0] = (gc_env.r[0] >> 5) & 0x3; // extrwi r0, r0, 2, 25
    gc_env.cr[0] = (gc_env.r[0] == 0x4) ? 0 : (gc_env.r[0] < 0x4 ? -1 : 1); // Compare with immediate
    if (gc_env.cr[0] >= 0) goto L_8002F170;
    gc_env.cr[0] = (gc_env.r[0] == 0x0) ? 0 : (gc_env.r[0] < 0x0 ? -1 : 1); // Compare with immediate
    if (gc_env.cr[0] >= 0) goto L_8002F158;
    goto L_8002F170;
    L_8002F158:
    gc_env.r[3] = gc_mem_read32(gc_env.ram, gc_env.r[31] + 0x14);
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[31] + 0x18);
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x350, gc_env.r[3]);
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x354, gc_env.r[0]);
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[31] + 0x1c);
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x358, gc_env.r[0]);
    L_8002F170:
    gc_env.r[0] = gc_mem_read8(gc_env.ram, gc_env.r[4] + 0x0);
    gc_env.r[0] = (gc_env.r[0] >> 3) & 0x3; // extrwi r0, r0, 2, 27
    gc_env.cr[0] = (gc_env.r[0] == 0x2) ? 0 : (gc_env.r[0] < 0x2 ? -1 : 1); // Compare with immediate
    if (gc_env.cr[0] == 0) goto L_8002F1B4;
    if (gc_env.cr[0] >= 0) goto L_8002F190;
    gc_env.cr[0] = (gc_env.r[0] == 0x0) ? 0 : (gc_env.r[0] < 0x0 ? -1 : 1); // Compare with immediate
    if (gc_env.cr[0] >= 0) goto L_8002F198;
    goto L_8002F238;
    L_8002F190:
    gc_env.cr[0] = (gc_env.r[0] == 0x4) ? 0 : (gc_env.r[0] < 0x4 ? -1 : 1); // Compare with immediate
    if (gc_env.cr[0] >= 0) goto L_8002F238;
    L_8002F198:
    gc_env.r[3] = gc_mem_read32(gc_env.ram, gc_env.r[31] + 0x2c);
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[31] + 0x30);
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x368, gc_env.r[3]);
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x36c, gc_env.r[0]);
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[31] + 0x34);
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x370, gc_env.r[0]);
    goto L_8002F238;
    L_8002F1B4:
    gc_env.r[3] = gc_env.r[31] + 44; // addi r3, r31, 0x2c
    gc_env.r[4] = gc_env.r[31] + 20; // addi r4, r31, 0x14
    gc_env.r[5] = gc_env.r[1] + 12; // addi r5, r1, 0xc
    lbVector_Diff();
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0xC); // lfs f1, 0xC(r1)
    gc_env.f[1] = *(float*)&temp;
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x14); // lfs f0, 0x14(r1)
    gc_env.f[0] = *(float*)&temp;
    gc_env.f[1] = (float)gc_env.f[1] * (float)gc_env.f[1]; // fmuls f1, f1, f1
    gc_env.f[0] = (float)gc_env.f[0] * (float)gc_env.f[0]; // fmuls f0, f0, f0
    gc_env.f[1] = (float)gc_env.f[1] + (float)gc_env.f[0]; // fadds f1, f1, f0
    sqrtf__Ff();
    gc_env.f[2] = gc_env.f[1]; // fmr f2, f1
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x10); // lfs f1, 0x10(r1)
    gc_env.f[1] = *(float*)&temp;
    atan2f();
    gc_env.f[30] = gc_env.f[1]; // fmr f30, f1
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0xC); // lfs f1, 0xC(r1)
    gc_env.f[1] = *(float*)&temp;
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x14); // lfs f2, 0x14(r1)
    gc_env.f[2] = *(float*)&temp;
    atan2f();
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0xC); // lfs f2, 0xC(r1)
    gc_env.f[2] = *(float*)&temp;
    gc_env.f[31] = gc_env.f[1]; // fmr f31, f1
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x10); // lfs f0, 0x10(r1)
    gc_env.f[0] = *(float*)&temp;
    gc_env.f[1] = (float)gc_env.f[2] * (float)gc_env.f[2]; // fmuls f1, f2, f2
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x14); // lfs f2, 0x14(r1)
    gc_env.f[2] = *(float*)&temp;
    gc_env.f[0] = (float)gc_env.f[0] * (float)gc_env.f[0]; // fmuls f0, f0, f0
    gc_env.f[2] = (float)gc_env.f[2] * (float)gc_env.f[2]; // fmuls f2, f2, f2
    gc_env.f[0] = (float)gc_env.f[1] + (float)gc_env.f[0]; // fadds f0, f1, f0
    gc_env.f[1] = (float)gc_env.f[2] + (float)gc_env.f[0]; // fadds f1, f2, f0
    sqrtf__Ff();
    // Unknown opcode: fctiwz f0 f1
    uint64_t temp;
    memcpy(&temp, &gc_env.f[0], sizeof(double));
    gc_mem_write64(gc_env.ram, gc_env.r[1] + 0x20, temp); // stfd f0, 0x20(r1)
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x24);
    gc_mem_write16(gc_env.ram, gc_env.r[31] + 0x368, gc_env.r[0]);
    float temp = (float)gc_env.f[30]; // stfs f30, 0x36C(r31)
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x36C, *(uint32_t*)&temp);
    float temp = (float)gc_env.f[31]; // stfs f31, 0x370(r31)
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x370, *(uint32_t*)&temp);
    L_8002F238:
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[31] + 0x44); // lfs f0, 0x44(r31)
    gc_env.f[0] = *(float*)&temp;
    float temp = (float)gc_env.f[0]; // stfs f0, 0x374(r31)
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x374, *(uint32_t*)&temp);
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x44);
    uint64_t temp = gc_mem_read64(gc_env.ram, gc_env.r[1] + 0x38); // lfd f31, 0x38(r1)
    gc_env.d[31] = *(double*)&temp;
    uint64_t temp = gc_mem_read64(gc_env.ram, gc_env.r[1] + 0x30); // lfd f30, 0x30(r1)
    gc_env.d[30] = *(double*)&temp;
    gc_env.r[31] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x2c);
    gc_env.r[30] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x28);
    gc_env.r[1] += 64; // addi r1, r1, 0x40
    gc_env.lr = gc_env.r[0]; // Move to link register
    return;
}

// Function: Camera_8002F260
void Camera_8002F260(void) {
    gc_env.r[3] = ((uint32_t)&cm_80452C68 >> 16) & 0xFFFF; // lis r3, cm_80452C68@ha
    gc_env.r[3] = gc_env.r[3] + ((uint32_t)&cm_80452C68 & 0xFFFF); // addi r3, r3, cm_80452C68@l
    gc_env.r[3] = gc_mem_read8(gc_env.ram, gc_env.r[3] + 0x341);
    gc_env.r[3] = gc_env.r[3] & 0x1; // clrlwi r3, r3, 31
    return;
}

// Function: Camera_8002F274
void Camera_8002F274(void) {
    gc_env.r[0] = gc_env.lr; // Move from link register
    gc_env.r[3] = ((uint32_t)&cm_80452C68 >> 16) & 0xFFFF; // lis r3, cm_80452C68@ha
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x4, gc_env.r[0]);
    gc_mem_write32(gc_env.ram, gc_env.r[1] + -0x20, gc_env.r[1]);
    gc_env.r[1] = gc_env.r[1] + -0x20;
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x1c, gc_env.r[31]);
    gc_env.r[31] = gc_env.r[3] + ((uint32_t)&cm_80452C68 & 0xFFFF); // addi r31, r3, cm_80452C68@l
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[31] + 0x4);
    gc_env.cr[0] = (gc_env.r[0] == 0x6) ? 0 : (gc_env.r[0] < 0x6 ? -1 : 1); // Compare with immediate
    if (gc_env.cr[0] == 0) goto L_8002F29C;
    Camera_8002FE38();
    L_8002F29C:
    gc_env.r[0] = gc_mem_read8(gc_env.ram, gc_env.r[31] + 0x341);
    gc_env.r[3] = 0x1;
    uint32_t rotated = gc_env.r[3] << 3; // rlwimi r0, r3, 3, 27, 28
    gc_env.r[0] = (gc_env.r[0] & ~0x18) | (rotated & 0x18);
    gc_mem_write8(gc_env.ram, gc_env.r[31] + 0x341, gc_env.r[0]);
    gc_env.r[5] = gc_env.r[31] + 860; // addi r5, r31, 0x35c
    gc_env.r[3] = gc_mem_read32(gc_env.ram, gc_env.r[31] + 0x2c);
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[31] + 0x30);
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x35c, gc_env.r[3]);
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x360, gc_env.r[0]);
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[31] + 0x34);
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x364, gc_env.r[0]);
    gc_env.r[0] = gc_mem_read8(gc_env.ram, gc_env.r[31] + 0x341);
    gc_env.r[0] = (gc_env.r[0] >> 3) & 0x3; // extrwi r0, r0, 2, 27
    gc_env.cr[0] = (gc_env.r[0] == 0x2) ? 0 : (gc_env.r[0] < 0x2 ? -1 : 1); // Compare with immediate
    if (gc_env.cr[0] == 0) goto L_8002F34C;
    if (gc_env.cr[0] >= 0) goto L_8002F2EC;
    gc_env.cr[0] = (gc_env.r[0] == 0x0) ? 0 : (gc_env.r[0] < 0x0 ? -1 : 1); // Compare with immediate
    if (gc_env.cr[0] == 0) goto L_8002F34C;
    if (gc_env.cr[0] >= 0) goto L_8002F2F8;
    goto L_8002F34C;
    L_8002F2EC:
    gc_env.cr[0] = (gc_env.r[0] == 0x4) ? 0 : (gc_env.r[0] < 0x4 ? -1 : 1); // Compare with immediate
    if (gc_env.cr[0] >= 0) goto L_8002F34C;
    goto L_8002F314;
    L_8002F2F8:
    gc_env.r[3] = gc_mem_read32(gc_env.ram, gc_env.r[5] + 0x0);
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[5] + 0x4);
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x38, gc_env.r[3]);
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x3c, gc_env.r[0]);
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[5] + 0x8);
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x40, gc_env.r[0]);
    goto L_8002F34C;
    L_8002F314:
    gc_env.r[12] = gc_mem_read32(gc_env.ram, gc_env.r[5] + 0x0);
    gc_env.cr[0] = ((uint32_t)gc_env.r[12] == 0x0) ? 0 : ((uint32_t)gc_env.r[12] < 0x0 ? -1 : 1); // Logical compare with immediate
    if (gc_env.cr[0] == 0) goto L_8002F34C;
    gc_env.lr = gc_env.r[12]; // Move to link register
    gc_env.r[3] = gc_env.r[1] + 8; // addi r3, r1, 0x8
    // Call function at gc_env.lr; // Branch to link register
    gc_env.cr[0] = (gc_env.r[3] == 0x0) ? 0 : (gc_env.r[3] < 0x0 ? -1 : 1); // Compare with immediate
    if (gc_env.cr[0] == 0) goto L_8002F34C;
    gc_env.r[3] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x8);
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0xc);
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x38, gc_env.r[3]);
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x3c, gc_env.r[0]);
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x10);
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x40, gc_env.r[0]);
    L_8002F34C:
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x24);
    gc_env.r[31] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x1c);
    gc_env.r[1] += 32; // addi r1, r1, 0x20
    gc_env.lr = gc_env.r[0]; // Move to link register
    return;
}

// Function: fn_8002F360
void fn_8002F360(void) {
    gc_env.r[0] = gc_env.lr; // Move from link register
    gc_env.r[4] = ((uint32_t)&cm_80452C68 >> 16) & 0xFFFF; // lis r4, cm_80452C68@ha
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x4, gc_env.r[0]);
    gc_env.r[4] = gc_env.r[4] + ((uint32_t)&cm_80452C68 & 0xFFFF); // addi r4, r4, cm_80452C68@l
    gc_mem_write32(gc_env.ram, gc_env.r[1] + -0x8, gc_env.r[1]);
    gc_env.r[1] = gc_env.r[1] + -0x8;
    gc_env.r[5] = gc_mem_read32(gc_env.ram, gc_env.r[4] + 0x4);
    gc_env.r[4] = ((uint32_t)&cm_803BCB18 >> 16) & 0xFFFF; // lis r4, cm_803BCB18@ha
    gc_env.r[0] = gc_env.r[4] + ((uint32_t)&cm_803BCB18 & 0xFFFF); // addi r0, r4, cm_803BCB18@l
    gc_env.r[4] = gc_env.r[5] << 2; // slwi r4, r5, 2
    gc_env.r[4] = gc_env.r[0] + gc_env.r[4];
    gc_env.r[12] = gc_mem_read32(gc_env.ram, gc_env.r[4] + 0x0);
    gc_env.cr[0] = ((uint32_t)gc_env.r[12] == 0x0) ? 0 : ((uint32_t)gc_env.r[12] < 0x0 ? -1 : 1); // Logical compare with immediate
    if (gc_env.cr[0] == 0) goto L_8002F39C;
    gc_env.lr = gc_env.r[12]; // Move to link register
    // Call function at gc_env.lr; // Branch to link register
    L_8002F39C:
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0xc);
    gc_env.r[1] += 8; // addi r1, r1, 0x8
    gc_env.lr = gc_env.r[0]; // Move to link register
    return;
}

// Function: Camera_8002F3AC
void Camera_8002F3AC(void) {
    gc_env.r[0] = gc_env.lr; // Move from link register
    gc_env.r[3] = ((uint32_t)&cm_80452C68 >> 16) & 0xFFFF; // lis r3, cm_80452C68@ha
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x4, gc_env.r[0]);
    gc_mem_write32(gc_env.ram, gc_env.r[1] + -0x18, gc_env.r[1]);
    gc_env.r[1] = gc_env.r[1] + -0x18;
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x14, gc_env.r[31]);
    gc_env.r[31] = gc_env.r[3] + ((uint32_t)&cm_80452C68 & 0xFFFF); // addi r31, r3, cm_80452C68@l
    gc_env.r[3] = ((uint32_t)&cm_803BCB18 >> 16) & 0xFFFF; // lis r3, cm_803BCB18@ha
    gc_env.r[4] = gc_mem_read32(gc_env.ram, gc_env.r[31] + 0x4);
    gc_env.r[0] = gc_env.r[3] + ((uint32_t)&cm_803BCB18 & 0xFFFF); // addi r0, r3, cm_803BCB18@l
    gc_env.r[3] = gc_mem_read32(gc_env.ram, gc_env.r[31] + 0x0);
    gc_env.r[4] = gc_env.r[4] << 2; // slwi r4, r4, 2
    gc_env.r[4] = gc_env.r[0] + gc_env.r[4];
    gc_env.r[12] = gc_mem_read32(gc_env.ram, gc_env.r[4] + 0x0);
    gc_env.cr[0] = ((uint32_t)gc_env.r[12] == 0x0) ? 0 : ((uint32_t)gc_env.r[12] < 0x0 ? -1 : 1); // Logical compare with immediate
    if (gc_env.cr[0] == 0) goto L_8002F3F0;
    gc_env.lr = gc_env.r[12]; // Move to link register
    // Call function at gc_env.lr; // Branch to link register
    L_8002F3F0:
    gc_env.r[3] = gc_mem_read32(gc_env.ram, gc_env.r[31] + 0x38);
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[31] + 0x3c);
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x2c, gc_env.r[3]);
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x30, gc_env.r[0]);
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[31] + 0x40);
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x34, gc_env.r[0]);
    gc_env.r[3] = gc_mem_read32(gc_env.ram, gc_env.r[31] + 0x20);
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[31] + 0x24);
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x14, gc_env.r[3]);
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x18, gc_env.r[0]);
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[31] + 0x28);
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x1c, gc_env.r[0]);
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[31] + 0x48); // lfs f0, 0x48(r31)
    gc_env.f[0] = *(float*)&temp;
    float temp = (float)gc_env.f[0]; // stfs f0, 0x44(r31)
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x44, *(uint32_t*)&temp);
    gc_env.r[3] = gc_mem_read32(gc_env.ram, gc_env.r[31] + 0x70);
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[31] + 0x74);
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x64, gc_env.r[3]);
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x68, gc_env.r[0]);
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[31] + 0x78);
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x6c, gc_env.r[0]);
    gc_env.r[3] = gc_mem_read32(gc_env.ram, gc_env.r[31] + 0x58);
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[31] + 0x5c);
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x4c, gc_env.r[3]);
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x50, gc_env.r[0]);
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[31] + 0x60);
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x54, gc_env.r[0]);
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[31] + 0x80); // lfs f0, 0x80(r31)
    gc_env.f[0] = *(float*)&temp;
    float temp = (float)gc_env.f[0]; // stfs f0, 0x7C(r31)
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x7C, *(uint32_t*)&temp);
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x1c);
    gc_env.r[31] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x14);
    gc_env.r[1] += 24; // addi r1, r1, 0x18
    gc_env.lr = gc_env.r[0]; // Move to link register
    return;
}

// Function: Camera_8002F474
void Camera_8002F474(void) {
    gc_env.r[3] = ((uint32_t)&cm_80452C68 >> 16) & 0xFFFF; // lis r3, cm_80452C68@ha
    gc_env.r[3] = gc_env.r[3] + ((uint32_t)&cm_80452C68 & 0xFFFF); // addi r3, r3, cm_80452C68@l
    gc_env.r[0] = 0x0;
    gc_mem_write32(gc_env.ram, gc_env.r[3] + 0x4, gc_env.r[0]);
    return;
}

// Function: fn_8002F488
void fn_8002F488(void) {
    gc_env.r[0] = gc_env.lr; // Move from link register
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x4, gc_env.r[0]);
    gc_mem_write32(gc_env.ram, gc_env.r[1] + -0x18, gc_env.r[1]);
    gc_env.r[1] = gc_env.r[1] + -0x18;
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x14, gc_env.r[31]);
    gc_env.r[31] = gc_env.r[3]; // Move register
    Stage_GetCamBoundsLeftOffset();
    float temp = (float)gc_env.f[1]; // stfs f1, 0x8(r31)
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x8, *(uint32_t*)&temp);
    Stage_GetCamBoundsRightOffset();
    float temp = (float)gc_env.f[1]; // stfs f1, 0xC(r31)
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0xC, *(uint32_t*)&temp);
    Stage_GetCamBoundsTopOffset();
    float temp = (float)gc_env.f[1]; // stfs f1, 0x0(r31)
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x0, *(uint32_t*)&temp);
    Stage_GetCamBoundsBottomOffset();
    float temp = (float)gc_env.f[1]; // stfs f1, 0x4(r31)
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x4, *(uint32_t*)&temp);
    gc_env.r[3] = 0x1;
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x1c);
    gc_env.r[31] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x14);
    gc_env.r[1] += 24; // addi r1, r1, 0x18
    gc_env.lr = gc_env.r[0]; // Move to link register
    return;
}

// Function: Camera_8002F4D4
void Camera_8002F4D4(void) {
    gc_env.r[0] = gc_env.lr; // Move from link register
    gc_env.r[6] = ((uint32_t)&cm_80452C68 >> 16) & 0xFFFF; // lis r6, cm_80452C68@ha
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x4, gc_env.r[0]);
    // Unknown opcode: extsb. r0 r3
    gc_mem_write32(gc_env.ram, gc_env.r[1] + -0x50, gc_env.r[1]);
    gc_env.r[1] = gc_env.r[1] + -0x50;
    uint64_t temp;
    memcpy(&temp, &gc_env.f[31], sizeof(double));
    gc_mem_write64(gc_env.ram, gc_env.r[1] + 0x48, temp); // stfd f31, 0x48(r1)
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x34, gc_env.r[27]); // stmw r27, 0x34(r1)
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x38, gc_env.r[28]); // stmw r27, 0x34(r1)
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x3C, gc_env.r[29]); // stmw r27, 0x34(r1)
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x40, gc_env.r[30]); // stmw r27, 0x34(r1)
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x44, gc_env.r[31]); // stmw r27, 0x34(r1)
    gc_env.r[27] = gc_env.r[5] + 0; // addi r27, r5, 0x0
    gc_env.r[31] = gc_env.r[6] + ((uint32_t)&cm_80452C68 & 0xFFFF); // addi r31, r6, cm_80452C68@l
    if (gc_env.cr[0] & 0x8) goto L_8002F508; // blt .L_8002F508
    // Unknown opcode: extsb r0 r3
    gc_env.cr[0] = (gc_env.r[0] == 0x6) ? 0 : (gc_env.r[0] < 0x6 ? -1 : 1); // Compare with immediate
    if (gc_env.cr[0] & 0x8) goto L_8002F51C; // blt .L_8002F51C
    L_8002F508:
    gc_env.r[0] = gc_env.r[3] - 10;
    gc_env.r[0] = gc_env.r[0] & 0xFF; // clrlwi r0, r0, 24
    gc_env.cr[0] = ((uint32_t)gc_env.r[0] == 0x1) ? 0 : ((uint32_t)gc_env.r[0] < 0x1 ? -1 : 1); // Logical compare with immediate
    if (gc_env.cr[0] & (0x8 | 0x2)) goto L_8002F51C; // ble .L_8002F51C
    gc_env.r[3] = 0x0;
    L_8002F51C:
    // Unknown opcode: extsb. r0 r4
    if (gc_env.cr[0] & 0x8) goto L_8002F530; // blt .L_8002F530
    // Unknown opcode: extsb r0 r4
    gc_env.cr[0] = (gc_env.r[0] == 0x4) ? 0 : (gc_env.r[0] < 0x4 ? -1 : 1); // Compare with immediate
    if (gc_env.cr[0] & 0x8) goto L_8002F544; // blt .L_8002F544
    L_8002F530:
    gc_env.r[0] = gc_env.r[4] - 4;
    gc_env.r[0] = gc_env.r[0] & 0xFF; // clrlwi r0, r0, 24
    gc_env.cr[0] = ((uint32_t)gc_env.r[0] == 0x1) ? 0 : ((uint32_t)gc_env.r[0] < 0x1 ? -1 : 1); // Logical compare with immediate
    if (gc_env.cr[0] & (0x8 | 0x2)) goto L_8002F544; // ble .L_8002F544
    gc_env.r[4] = 0x4;
    L_8002F544:
    gc_env.r[0] = 0x1;
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x4, gc_env.r[0]);
    gc_env.r[29] = gc_env.r[31] + 708; // addi r29, r31, 0x2c4
    gc_mem_write8(gc_env.ram, gc_env.r[31] + 0x2c4, gc_env.r[3]);
    gc_mem_write8(gc_env.ram, gc_env.r[31] + 0x2c5, gc_env.r[4]);
    Stage_GetCamBoundsLeftOffset();
    float temp = (float)gc_env.f[1]; // stfs f1, 0x2D8(r31)
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x2D8, *(uint32_t*)&temp);
    Stage_GetCamBoundsRightOffset();
    float temp = (float)gc_env.f[1]; // stfs f1, 0x2DC(r31)
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x2DC, *(uint32_t*)&temp);
    Stage_GetCamBoundsTopOffset();
    float temp = (float)gc_env.f[1]; // stfs f1, 0x2D0(r31)
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x2D0, *(uint32_t*)&temp);
    Stage_GetCamBoundsBottomOffset();
    float temp = (float)gc_env.f[1]; // stfs f1, 0x2D4(r31)
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x2D4, *(uint32_t*)&temp);
    gc_env.f[0] = cm_804D7EAC; // lfs f0, cm_804D7EAC@sda21(r0)
    float temp = (float)gc_env.f[0]; // stfs f0, 0x2E0(r31)
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x2E0, *(uint32_t*)&temp);
    gc_env.f[0] = cm_804D7EB0; // lfs f0, cm_804D7EB0@sda21(r0)
    float temp = (float)gc_env.f[0]; // stfs f0, 0x2E4(r31)
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x2E4, *(uint32_t*)&temp);
    Stage_GetCamAngleRadiansUp();
    float temp = (float)gc_env.f[1]; // stfs f1, 0x2E8(r31)
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x2E8, *(uint32_t*)&temp);
    Stage_GetCamAngleRadiansDown();
    float temp = (float)gc_env.f[1]; // stfs f1, 0x2EC(r31)
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x2EC, *(uint32_t*)&temp);
    Stage_GetCamAngleRadiansRight();
    float temp = (float)gc_env.f[1]; // stfs f1, 0x2F0(r31)
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x2F0, *(uint32_t*)&temp);
    Stage_GetCamAngleRadiansLeft();
    float temp = (float)gc_env.f[1]; // stfs f1, 0x2F4(r31)
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x2F4, *(uint32_t*)&temp);
    Stage_GetPauseCamZPosMin();
    gc_env.r[30] = gc_env.r[31] + 760; // addi r30, r31, 0x2f8
    float temp = (float)gc_env.f[1]; // stfs f1, 0x2F8(r31)
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x2F8, *(uint32_t*)&temp);
    Stage_GetPauseCamZPosMax();
    gc_env.r[3] = ((uint32_t)&fn_8002F488 >> 16) & 0xFFFF; // lis r3, fn_8002F488@ha
    float temp = (float)gc_env.f[1]; // stfs f1, 0x2FC(r31)
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x2FC, *(uint32_t*)&temp);
    gc_env.r[0] = gc_env.r[3] + ((uint32_t)&fn_8002F488 & 0xFFFF); // addi r0, r3, fn_8002F488@l
    gc_env.cr[0] = (gc_env.r[27] == 0x1) ? 0 : (gc_env.r[27] < 0x1 ? -1 : 1); // Compare with immediate
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x300, gc_env.r[0]);
    if (gc_env.cr[0] == 0) goto L_8002F5EC;
    if (gc_env.cr[0] >= 0) goto L_8002F5F4;
    gc_env.cr[0] = (gc_env.r[27] == 0x0) ? 0 : (gc_env.r[27] < 0x0 ? -1 : 1); // Compare with immediate
    if (gc_env.cr[0] >= 0) goto L_8002F5E0;
    goto L_8002F5F4;
    L_8002F5E0:
    Stage_GetPauseCamZPosInit();
    gc_env.f[31] = gc_env.f[1]; // fmr f31, f1
    goto L_8002F608;
    L_8002F5EC:
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[30] + 0x0); // lfs f31, 0x0(r30)
    gc_env.f[31] = *(float*)&temp;
    goto L_8002F608;
    L_8002F5F4:
    gc_env.r[3] = ((uint32_t)&cm_803BCBD0 >> 16) & 0xFFFF; // lis r3, cm_803BCBD0@ha
    gc_env.r[3] = gc_env.r[3] + ((uint32_t)&cm_803BCBD0 & 0xFFFF); // addi r3, r3, cm_803BCBD0@l
    gc_env.r[4] = 0xedf;
    gc_env.r[5] = cm_804D3938@sda21;
    __assert();
    L_8002F608:
    gc_env.r[3] = gc_mem_read8(gc_env.ram, gc_env.r[29] + 0x0);
    // Unknown opcode: extsb r3 r3
    gc_env.cr[0] = (gc_env.r[3] == 0xa) ? 0 : (gc_env.r[3] < 0xa ? -1 : 1); // Compare with immediate
    if (gc_env.cr[0] == 0) goto L_8002F658;
    gc_env.cr[0] = (gc_env.r[3] == 0xb) ? 0 : (gc_env.r[3] < 0xb ? -1 : 1); // Compare with immediate
    if (gc_env.cr[0] == 0) goto L_8002F658;
    gc_env.cr[0] = (gc_env.r[3] == 0x0) ? 0 : (gc_env.r[3] < 0x0 ? -1 : 1); // Compare with immediate
    if (gc_env.cr[0] & 0x8) goto L_8002F658; // blt .L_8002F658
    gc_env.cr[0] = (gc_env.r[3] == 0x6) ? 0 : (gc_env.r[3] < 0x6 ? -1 : 1); // Compare with immediate
    if (gc_env.cr[0] >= 0) goto L_8002F658;
    Player_GetEntity();
    gc_env.cr[0] = ((uint32_t)gc_env.r[3] == 0x0) ? 0 : ((uint32_t)gc_env.r[3] < 0x0 ? -1 : 1); // Logical compare with immediate
    if (gc_env.cr[0] == 0) goto L_8002F658;
    ftLib_80086B74();
    gc_env.cr[0] = ((uint32_t)gc_env.r[3] == 0x0) ? 0 : ((uint32_t)gc_env.r[3] < 0x0 ? -1 : 1); // Logical compare with immediate
    if (gc_env.cr[0] == 0) goto L_8002F658;
    gc_env.f[1] = cm_804D7E60; // lfs f1, cm_804D7E60@sda21(r0)
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[31] + 0x48); // lfs f0, 0x48(r31)
    gc_env.f[0] = *(float*)&temp;
    gc_env.f[1] = (float)gc_env.f[1] * (float)gc_env.f[0]; // fmuls f1, f1, f0
    tanf();
    L_8002F658:
    gc_env.r[0] = gc_mem_read8(gc_env.ram, gc_env.r[29] + 0x0);
    gc_env.r[29] = gc_env.r[31] + 788; // addi r29, r31, 0x314
    gc_env.f[1] = cm_804D7E14; // lfs f1, cm_804D7E14@sda21(r0)
    gc_env.r[28] = gc_env.r[31] + 800; // addi r28, r31, 0x320
    gc_env.cr[0] = (gc_env.r[0] == 0xa) ? 0 : (gc_env.r[0] < 0xa ? -1 : 1); // Compare with immediate
    float temp = (float)gc_env.f[1]; // stfs f1, 0x31C(r31)
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x31C, *(uint32_t*)&temp);
    float temp = (float)gc_env.f[1]; // stfs f1, 0x318(r31)
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x318, *(uint32_t*)&temp);
    float temp = (float)gc_env.f[1]; // stfs f1, 0x314(r31)
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x314, *(uint32_t*)&temp);
    float temp = (float)gc_env.f[1]; // stfs f1, 0x320(r31)
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x320, *(uint32_t*)&temp);
    gc_env.f[0] = cm_804D7E90; // lfs f0, cm_804D7E90@sda21(r0)
    float temp = (float)gc_env.f[0]; // stfs f0, 0x324(r31)
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x324, *(uint32_t*)&temp);
    gc_env.f[0] = cm_804D7E94; // lfs f0, cm_804D7E94@sda21(r0)
    float temp = (float)gc_env.f[0]; // stfs f0, 0x328(r31)
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x328, *(uint32_t*)&temp);
    float temp = (float)gc_env.f[1]; // stfs f1, 0x334(r31)
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x334, *(uint32_t*)&temp);
    gc_env.f[0] = cm_804D7E04; // lfs f0, cm_804D7E04@sda21(r0)
    float temp = (float)gc_env.f[0]; // stfs f0, 0x338(r31)
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x338, *(uint32_t*)&temp);
    float temp = (float)gc_env.f[1]; // stfs f1, 0x33C(r31)
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x33C, *(uint32_t*)&temp);
    if (gc_env.cr[0] != 0) goto L_8002F6B0;
    gc_env.f[0] = cm_804D7E98; // lfs f0, cm_804D7E98@sda21(r0)
    gc_env.f[0] = (float)gc_env.f[0] * (float)gc_env.f[31]; // fmuls f0, f0, f31
    float temp = (float)gc_env.f[0]; // stfs f0, 0x330(r31)
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x330, *(uint32_t*)&temp);
    goto L_8002F6B4;
    L_8002F6B0:
    float temp = (float)gc_env.f[31]; // stfs f31, 0x330(r31)
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x330, *(uint32_t*)&temp);
    L_8002F6B4:
    gc_env.f[1] = cm_804D7E14; // lfs f1, cm_804D7E14@sda21(r0)
    Camera_8002BAA8();
    gc_env.f[1] = cm_804D7E14; // lfs f1, cm_804D7E14@sda21(r0)
    gc_env.f[2] = gc_env.f[1]; // fmr f2, f1
    Camera_8002BD88();
    gc_env.f[1] = cm_804D7E14; // lfs f1, cm_804D7E14@sda21(r0)
    gc_env.f[2] = gc_env.f[1]; // fmr f2, f1
    Camera_8002C010();
    gc_env.r[3] = gc_mem_read32(gc_env.ram, gc_env.r[31] + 0x308);
    gc_env.r[27] = gc_env.r[31] + 20; // addi r27, r31, 0x14
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[31] + 0x30c);
    gc_env.r[30] = gc_env.r[31] + 32; // addi r30, r31, 0x20
    gc_env.r[4] = gc_env.r[29] + 0; // addi r4, r29, 0x0
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x20, gc_env.r[3]);
    gc_env.r[3] = gc_env.r[27] + 12; // addi r3, r27, 0xc
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x24, gc_env.r[0]);
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[31] + 0x310);
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x28, gc_env.r[0]);
    lbVector_Add();
    gc_env.r[5] = gc_mem_read32(gc_env.ram, gc_env.r[30] + 0x0);
    gc_env.r[4] = gc_env.r[28]; // Move register
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[30] + 0x4);
    gc_env.r[3] = gc_env.r[27] + 36; // addi r3, r27, 0x24
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x38, gc_env.r[5]);
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x3c, gc_env.r[0]);
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[30] + 0x8);
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x40, gc_env.r[0]);
    lbVector_Add();
    gc_env.r[27] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x34); // lmw r27, 0x34(r1)
    gc_env.r[28] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x38); // lmw r27, 0x34(r1)
    gc_env.r[29] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x3C); // lmw r27, 0x34(r1)
    gc_env.r[30] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x40); // lmw r27, 0x34(r1)
    gc_env.r[31] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x44); // lmw r27, 0x34(r1)
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x54);
    uint64_t temp = gc_mem_read64(gc_env.ram, gc_env.r[1] + 0x48); // lfd f31, 0x48(r1)
    gc_env.d[31] = *(double*)&temp;
    gc_env.r[1] += 80; // addi r1, r1, 0x50
    gc_env.lr = gc_env.r[0]; // Move to link register
    return;
}

// Function: Camera_8002F73C
void Camera_8002F73C(void) {
    gc_env.r[0] = gc_env.lr; // Move from link register
    gc_env.r[5] = 0x0;
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x4, gc_env.r[0]);
    gc_mem_write32(gc_env.ram, gc_env.r[1] + -0x8, gc_env.r[1]);
    gc_env.r[1] = gc_env.r[1] + -0x8;
    Camera_8002F4D4();
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0xc);
    gc_env.r[1] += 8; // addi r1, r1, 0x8
    gc_env.lr = gc_env.r[0]; // Move to link register
    return;
}

// Function: Camera_8002F760
void Camera_8002F760(void) {
    gc_env.r[0] = gc_env.lr; // Move from link register
    gc_env.r[5] = 0x1;
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x4, gc_env.r[0]);
    gc_mem_write32(gc_env.ram, gc_env.r[1] + -0x8, gc_env.r[1]);
    gc_env.r[1] = gc_env.r[1] + -0x8;
    Camera_8002F4D4();
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0xc);
    gc_env.r[1] += 8; // addi r1, r1, 0x8
    gc_env.lr = gc_env.r[0]; // Move to link register
    return;
}

// Function: Camera_8002F784
void Camera_8002F784(void) {
    gc_env.r[5] = ((uint32_t)&cm_80452C68 >> 16) & 0xFFFF; // lis r5, cm_80452C68@ha
    gc_env.r[5] = gc_env.r[5] + ((uint32_t)&cm_80452C68 & 0xFFFF); // addi r5, r5, cm_80452C68@l
    gc_env.r[0] = 0x2;
    gc_mem_write32(gc_env.ram, gc_env.r[5] + 0x4, gc_env.r[0]);
    gc_mem_write8(gc_env.ram, gc_env.r[5] + 0x2c4, gc_env.r[3]);
    gc_mem_write8(gc_env.ram, gc_env.r[5] + 0x2c5, gc_env.r[4]);
    gc_env.f[0] = cm_804D7E14; // lfs f0, cm_804D7E14@sda21(r0)
    float temp = (float)gc_env.f[0]; // stfs f0, 0x2C8(r5)
    gc_mem_write32(gc_env.ram, gc_env.r[5] + 0x2C8, *(uint32_t*)&temp);
    float temp = (float)gc_env.f[0]; // stfs f0, 0x2CC(r5)
    gc_mem_write32(gc_env.ram, gc_env.r[5] + 0x2CC, *(uint32_t*)&temp);
    return;
}

// Function: Camera_8002F7AC
void Camera_8002F7AC(void) {
    gc_env.r[0] = gc_env.lr; // Move from link register
    gc_env.r[4] = ((uint32_t)&cm_80452C68 >> 16) & 0xFFFF; // lis r4, cm_80452C68@ha
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x4, gc_env.r[0]);
    gc_env.r[0] = 0x3;
    gc_mem_write32(gc_env.ram, gc_env.r[1] + -0x20, gc_env.r[1]);
    gc_env.r[1] = gc_env.r[1] + -0x20;
    uint64_t temp;
    memcpy(&temp, &gc_env.f[31], sizeof(double));
    gc_mem_write64(gc_env.ram, gc_env.r[1] + 0x18, temp); // stfd f31, 0x18(r1)
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x14, gc_env.r[31]);
    gc_env.r[31] = gc_env.r[4] + ((uint32_t)&cm_80452C68 & 0xFFFF); // addi r31, r4, cm_80452C68@l
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x4, gc_env.r[0]);
    gc_mem_write8(gc_env.ram, gc_env.r[31] + 0x2c4, gc_env.r[3]);
    gc_env.r[3] = gc_mem_read8(gc_env.ram, gc_env.r[31] + 0x2c4);
    // Unknown opcode: extsb r3 r3
    Player_GetEntity();
    gc_env.cr[0] = ((uint32_t)gc_env.r[3] == 0x0) ? 0 : ((uint32_t)gc_env.r[3] < 0x0 ? -1 : 1); // Logical compare with immediate
    if (gc_env.cr[0] == 0) goto L_8002F8AC;
    ftLib_80086B74();
    gc_env.cr[0] = ((uint32_t)gc_env.r[3] == 0x0) ? 0 : ((uint32_t)gc_env.r[3] < 0x0 ? -1 : 1); // Logical compare with immediate
    if (gc_env.cr[0] == 0) goto L_8002F8AC;
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[3] + 0x28); // lfs f1, 0x28(r3)
    gc_env.f[1] = *(float*)&temp;
    gc_env.f[0] = cm_804D7E14; // lfs f0, cm_804D7E14@sda21(r0)
    gc_env.cr[0] = isnan(gc_env.f[1]) || isnan(gc_env.f[0]) ? 0x1 : (gc_env.f[1] < gc_env.f[0] ? 0x8 : (gc_env.f[1] > gc_env.f[0] ? 0x4 : 0x2)); // fcmpo cr0, f1, f0
    if (gc_env.cr[0] & (0x8 | 0x2)) goto L_8002F80C; // ble .L_8002F80C
    gc_env.f[31] = cm_804D7E04; // lfs f31, cm_804D7E04@sda21(r0)
    goto L_8002F838;
    L_8002F80C:
    if (gc_env.cr[0] >= 0) goto L_8002F818;
    gc_env.f[31] = cm_804D7E10; // lfs f31, cm_804D7E10@sda21(r0)
    goto L_8002F838;
    L_8002F818:
    gc_env.r[3] = 0x2;
    HSD_Randi();
    gc_env.cr[0] = (gc_env.r[3] == 0x0) ? 0 : (gc_env.r[3] < 0x0 ? -1 : 1); // Compare with immediate
    if (gc_env.cr[0] == 0) goto L_8002F830;
    gc_env.d[0] = cm_804D7E18; // lfd f0, cm_804D7E18@sda21(r0)
    goto L_8002F834;
    L_8002F830:
    gc_env.d[0] = cm_804D7EB8; // lfd f0, cm_804D7EB8@sda21(r0)
    L_8002F834:
    gc_env.f[31] = (float)gc_env.f[0]; // frsp f31, f0
    L_8002F838:
    HSD_Randf();
    gc_env.f[2] = cm_804D7EC0; // lfs f2, cm_804D7EC0@sda21(r0)
    gc_env.f[0] = cm_804D7E04; // lfs f0, cm_804D7E04@sda21(r0)
    gc_env.f[1] = (float)gc_env.f[2] * (float)gc_env.f[1]; // fmuls f1, f2, f1
    gc_env.cr[0] = isnan(gc_env.f[1]) || isnan(gc_env.f[0]) ? 0x1 : (gc_env.f[1] < gc_env.f[0] ? 0x8 : (gc_env.f[1] > gc_env.f[0] ? 0x4 : 0x2)); // fcmpo cr0, f1, f0
    if (gc_env.cr[0] >= 0) goto L_8002F854;
    gc_env.f[31] = -gc_env.f[31]; // fneg f31, f31
    L_8002F854:
    gc_env.f[0] = cm_804D7E14; // lfs f0, cm_804D7E14@sda21(r0)
    gc_env.cr[0] = isnan(gc_env.f[31]) || isnan(gc_env.f[0]) ? 0x1 : (gc_env.f[31] < gc_env.f[0] ? 0x8 : (gc_env.f[31] > gc_env.f[0] ? 0x4 : 0x2)); // fcmpo cr0, f31, f0
    if (gc_env.cr[0] & (0x8 | 0x2)) goto L_8002F878; // ble .L_8002F878
    HSD_Randf();
    gc_env.f[31] = gc_env.f[1]; // fmr f31, f1
    Stage_GetCamAngleRadiansLeft();
    gc_env.f[0] = (float)gc_env.f[31] * (float)gc_env.f[1]; // fmuls f0, f31, f1
    float temp = (float)gc_env.f[0]; // stfs f0, 0x2CC(r31)
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x2CC, *(uint32_t*)&temp);
    goto L_8002F890;
    L_8002F878:
    HSD_Randf();
    gc_env.f[31] = gc_env.f[1]; // fmr f31, f1
    Stage_GetCamAngleRadiansRight();
    gc_env.f[0] = -gc_env.f[1]; // fneg f0, f1
    gc_env.f[0] = (float)gc_env.f[31] * (float)gc_env.f[0]; // fmuls f0, f31, f0
    float temp = (float)gc_env.f[0]; // stfs f0, 0x2CC(r31)
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x2CC, *(uint32_t*)&temp);
    L_8002F890:
    HSD_Randf();
    gc_env.d[2] = cm_804D7EC8; // lfd f2, cm_804D7EC8@sda21(r0)
    gc_env.d[0] = cm_804D7ED0; // lfd f0, cm_804D7ED0@sda21(r0)
    // Unknown opcode: fmsub f0 f2 f1 f0
    gc_env.f[0] = (float)gc_env.f[0]; // frsp f0, f0
    float temp = (float)gc_env.f[0]; // stfs f0, 0x2C8(r31)
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x2C8, *(uint32_t*)&temp);
    goto L_8002F8DC;
    L_8002F8AC:
    HSD_Randf();
    gc_env.d[2] = cm_804D7EC8; // lfd f2, cm_804D7EC8@sda21(r0)
    gc_env.d[0] = cm_804D7ED0; // lfd f0, cm_804D7ED0@sda21(r0)
    // Unknown opcode: fmsub f0 f2 f1 f0
    gc_env.f[0] = (float)gc_env.f[0]; // frsp f0, f0
    float temp = (float)gc_env.f[0]; // stfs f0, 0x2C8(r31)
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x2C8, *(uint32_t*)&temp);
    HSD_Randf();
    gc_env.d[2] = cm_804D7ED8; // lfd f2, cm_804D7ED8@sda21(r0)
    gc_env.d[0] = cm_804D7EE0; // lfd f0, cm_804D7EE0@sda21(r0)
    // Unknown opcode: fmsub f0 f2 f1 f0
    gc_env.f[0] = (float)gc_env.f[0]; // frsp f0, f0
    float temp = (float)gc_env.f[0]; // stfs f0, 0x2CC(r31)
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x2CC, *(uint32_t*)&temp);
    L_8002F8DC:
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x24);
    uint64_t temp = gc_mem_read64(gc_env.ram, gc_env.r[1] + 0x18); // lfd f31, 0x18(r1)
    gc_env.d[31] = *(double*)&temp;
    gc_env.r[31] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x14);
    gc_env.r[1] += 32; // addi r1, r1, 0x20
    gc_env.lr = gc_env.r[0]; // Move to link register
    return;
}

// Function: Camera_8002F8F4
void Camera_8002F8F4(void) {
    gc_env.r[3] = ((uint32_t)&cm_80452C68 >> 16) & 0xFFFF; // lis r3, cm_80452C68@ha
    gc_env.r[3] = gc_env.r[3] + ((uint32_t)&cm_80452C68 & 0xFFFF); // addi r3, r3, cm_80452C68@l
    gc_env.r[0] = 0x4;
    gc_mem_write32(gc_env.ram, gc_env.r[3] + 0x4, gc_env.r[0]);
    return;
}

// Function: fn_8002F908
void fn_8002F908(void) {
    gc_env.r[0] = gc_env.lr; // Move from link register
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x4, gc_env.r[0]);
    gc_mem_write32(gc_env.ram, gc_env.r[1] + -0x28, gc_env.r[1]);
    gc_env.r[1] = gc_env.r[1] + -0x28;
    uint64_t temp;
    memcpy(&temp, &gc_env.f[31], sizeof(double));
    gc_mem_write64(gc_env.ram, gc_env.r[1] + 0x20, temp); // stfd f31, 0x20(r1)
    uint64_t temp;
    memcpy(&temp, &gc_env.f[30], sizeof(double));
    gc_mem_write64(gc_env.ram, gc_env.r[1] + 0x18, temp); // stfd f30, 0x18(r1)
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x14, gc_env.r[31]);
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x10, gc_env.r[30]);
    gc_env.r[30] = gc_env.r[3]; // Move register
    Stage_GetCamBoundsLeftOffset();
    gc_env.f[31] = gc_env.f[1]; // fmr f31, f1
    Stage_GetCamBoundsRightOffset();
    gc_env.f[1] = (float)gc_env.f[1] + (float)gc_env.f[31]; // fadds f1, f1, f31
    gc_env.f[0] = cm_804D7E30; // lfs f0, cm_804D7E30@sda21(r0)
    gc_env.f[30] = (float)gc_env.f[0] * (float)gc_env.f[1]; // fmuls f30, f0, f1
    Stage_GetCamBoundsLeftOffset();
    gc_env.f[31] = gc_env.f[1]; // fmr f31, f1
    Stage_GetCamBoundsRightOffset();
    gc_env.f[1] = (float)gc_env.f[1] - (float)gc_env.f[31]; // fsubs f1, f1, f31
    gc_env.f[0] = cm_804D7E30; // lfs f0, cm_804D7E30@sda21(r0)
    gc_env.r[3] = ((uint32_t)&cm_803BCCA0 >> 16) & 0xFFFF; // lis r3, cm_803BCCA0@ha
    gc_env.r[31] = gc_env.r[3] + ((uint32_t)&cm_803BCCA0 & 0xFFFF); // addi r31, r3, cm_803BCCA0@l
    gc_env.f[1] = (float)gc_env.f[0] * (float)gc_env.f[1]; // fmuls f1, f0, f1
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[31] + 0xAC); // lfs f0, 0xAC(r31)
    gc_env.f[0] = *(float*)&temp;
    gc_env.f[0] = (float)gc_env.f[0] * (float)gc_env.f[1]; // fmuls f0, f0, f1
    gc_env.f[1] = (float)gc_env.f[30] + (float)gc_env.f[0]; // fadds f1, f30, f0
    gc_env.f[0] = (float)gc_env.f[30] - (float)gc_env.f[0]; // fsubs f0, f30, f0
    float temp = (float)gc_env.f[1]; // stfs f1, 0xC(r30)
    gc_mem_write32(gc_env.ram, gc_env.r[30] + 0xC, *(uint32_t*)&temp);
    float temp = (float)gc_env.f[0]; // stfs f0, 0x8(r30)
    gc_mem_write32(gc_env.ram, gc_env.r[30] + 0x8, *(uint32_t*)&temp);
    Stage_GetCamBoundsBottomOffset();
    gc_env.f[31] = gc_env.f[1]; // fmr f31, f1
    Stage_GetCamBoundsTopOffset();
    gc_env.f[1] = (float)gc_env.f[1] + (float)gc_env.f[31]; // fadds f1, f1, f31
    gc_env.f[0] = cm_804D7E30; // lfs f0, cm_804D7E30@sda21(r0)
    gc_env.f[30] = (float)gc_env.f[0] * (float)gc_env.f[1]; // fmuls f30, f0, f1
    Stage_GetCamBoundsBottomOffset();
    gc_env.f[31] = gc_env.f[1]; // fmr f31, f1
    Stage_GetCamBoundsTopOffset();
    gc_env.f[2] = (float)gc_env.f[1] - (float)gc_env.f[31]; // fsubs f2, f1, f31
    gc_env.f[1] = cm_804D7E30; // lfs f1, cm_804D7E30@sda21(r0)
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[31] + 0xB0); // lfs f0, 0xB0(r31)
    gc_env.f[0] = *(float*)&temp;
    gc_env.r[3] = 0x1;
    gc_env.f[1] = (float)gc_env.f[1] * (float)gc_env.f[2]; // fmuls f1, f1, f2
    gc_env.f[0] = (float)gc_env.f[0] * (float)gc_env.f[1]; // fmuls f0, f0, f1
    gc_env.f[1] = (float)gc_env.f[30] + (float)gc_env.f[0]; // fadds f1, f30, f0
    gc_env.f[0] = (float)gc_env.f[30] - (float)gc_env.f[0]; // fsubs f0, f30, f0
    float temp = (float)gc_env.f[1]; // stfs f1, 0x0(r30)
    gc_mem_write32(gc_env.ram, gc_env.r[30] + 0x0, *(uint32_t*)&temp);
    float temp = (float)gc_env.f[0]; // stfs f0, 0x4(r30)
    gc_mem_write32(gc_env.ram, gc_env.r[30] + 0x4, *(uint32_t*)&temp);
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x2c);
    uint64_t temp = gc_mem_read64(gc_env.ram, gc_env.r[1] + 0x20); // lfd f31, 0x20(r1)
    gc_env.d[31] = *(double*)&temp;
    uint64_t temp = gc_mem_read64(gc_env.ram, gc_env.r[1] + 0x18); // lfd f30, 0x18(r1)
    gc_env.d[30] = *(double*)&temp;
    gc_env.r[31] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x14);
    gc_env.r[30] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x10);
    gc_env.r[1] += 40; // addi r1, r1, 0x28
    gc_env.lr = gc_env.r[0]; // Move to link register
    return;
}

// Function: Camera_8002F9E4
void Camera_8002F9E4(void) {
    gc_env.r[0] = gc_env.lr; // Move from link register
    // Unknown opcode: extsb r3 r3
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x4, gc_env.r[0]);
    gc_env.r[5] = ((uint32_t)&cm_80452C68 >> 16) & 0xFFFF; // lis r5, cm_80452C68@ha
    gc_env.r[0] = 0x5;
    gc_mem_write32(gc_env.ram, gc_env.r[1] + -0x28, gc_env.r[1]);
    gc_env.r[1] = gc_env.r[1] + -0x28;
    gc_env.r[3] = gc_env.r[3] - 1;
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x14, gc_env.r[27]); // stmw r27, 0x14(r1)
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x18, gc_env.r[28]); // stmw r27, 0x14(r1)
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x1C, gc_env.r[29]); // stmw r27, 0x14(r1)
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x20, gc_env.r[30]); // stmw r27, 0x14(r1)
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x24, gc_env.r[31]); // stmw r27, 0x14(r1)
    gc_env.r[30] = gc_env.r[5] + ((uint32_t)&cm_80452C68 & 0xFFFF); // addi r30, r5, cm_80452C68@l
    gc_env.r[27] = gc_env.r[4] + 0; // addi r27, r4, 0x0
    gc_env.r[4] = 0x1;
    gc_mem_write32(gc_env.ram, gc_env.r[30] + 0x4, gc_env.r[0]);
    Camera_8002BA00();
    // Unknown opcode: extsb r0 r3
    gc_env.r[28] = gc_env.r[30] + 772; // addi r28, r30, 0x304
    gc_mem_write8(gc_env.ram, gc_env.r[30] + 0x304, gc_env.r[0]);
    gc_env.r[3] = ((uint32_t)&cm_803BCCA0 >> 16) & 0xFFFF; // lis r3, cm_803BCCA0@ha
    gc_env.r[31] = gc_env.r[3] + ((uint32_t)&cm_803BCCA0 & 0xFFFF); // addi r31, r3, cm_803BCCA0@l
    gc_mem_write8(gc_env.ram, gc_env.r[30] + 0x305, gc_env.r[27]);
    gc_env.r[29] = gc_env.r[30] + 812; // addi r29, r30, 0x32c
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[31] + 0x40); // lfs f0, 0x40(r31)
    gc_env.f[0] = *(float*)&temp;
    float temp = (float)gc_env.f[0]; // stfs f0, 0x32C(r30)
    gc_mem_write32(gc_env.ram, gc_env.r[30] + 0x32C, *(uint32_t*)&temp);
    Stage_GetCamBoundsLeftOffset();
    float temp = (float)gc_env.f[1]; // stfs f1, 0x2D8(r30)
    gc_mem_write32(gc_env.ram, gc_env.r[30] + 0x2D8, *(uint32_t*)&temp);
    Stage_GetCamBoundsRightOffset();
    float temp = (float)gc_env.f[1]; // stfs f1, 0x2DC(r30)
    gc_mem_write32(gc_env.ram, gc_env.r[30] + 0x2DC, *(uint32_t*)&temp);
    Stage_GetCamBoundsTopOffset();
    float temp = (float)gc_env.f[1]; // stfs f1, 0x2D0(r30)
    gc_mem_write32(gc_env.ram, gc_env.r[30] + 0x2D0, *(uint32_t*)&temp);
    Stage_GetCamBoundsBottomOffset();
    float temp = (float)gc_env.f[1]; // stfs f1, 0x2D4(r30)
    gc_mem_write32(gc_env.ram, gc_env.r[30] + 0x2D4, *(uint32_t*)&temp);
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[31] + 0xA8); // lfs f0, 0xA8(r31)
    gc_env.f[0] = *(float*)&temp;
    float temp = (float)gc_env.f[0]; // stfs f0, 0x2E0(r30)
    gc_mem_write32(gc_env.ram, gc_env.r[30] + 0x2E0, *(uint32_t*)&temp);
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[31] + 0xA4); // lfs f0, 0xA4(r31)
    gc_env.f[0] = *(float*)&temp;
    float temp = (float)gc_env.f[0]; // stfs f0, 0x2E4(r30)
    gc_mem_write32(gc_env.ram, gc_env.r[30] + 0x2E4, *(uint32_t*)&temp);
    Stage_GetCamAngleRadiansUp();
    float temp = (float)gc_env.f[1]; // stfs f1, 0x2E8(r30)
    gc_mem_write32(gc_env.ram, gc_env.r[30] + 0x2E8, *(uint32_t*)&temp);
    Stage_GetCamAngleRadiansDown();
    float temp = (float)gc_env.f[1]; // stfs f1, 0x2EC(r30)
    gc_mem_write32(gc_env.ram, gc_env.r[30] + 0x2EC, *(uint32_t*)&temp);
    Stage_GetCamAngleRadiansRight();
    float temp = (float)gc_env.f[1]; // stfs f1, 0x2F0(r30)
    gc_mem_write32(gc_env.ram, gc_env.r[30] + 0x2F0, *(uint32_t*)&temp);
    Stage_GetCamAngleRadiansLeft();
    float temp = (float)gc_env.f[1]; // stfs f1, 0x2F4(r30)
    gc_mem_write32(gc_env.ram, gc_env.r[30] + 0x2F4, *(uint32_t*)&temp);
    gc_env.r[3] = ((uint32_t)&fn_8002F908 >> 16) & 0xFFFF; // lis r3, fn_8002F908@ha
    gc_env.r[0] = gc_env.r[3] + ((uint32_t)&fn_8002F908 & 0xFFFF); // addi r0, r3, fn_8002F908@l
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[29] + 0x0); // lfs f3, 0x0(r29)
    gc_env.f[3] = *(float*)&temp;
    gc_env.r[29] = gc_env.r[30] + 788; // addi r29, r30, 0x314
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[31] + 0x8C); // lfs f2, 0x8C(r31)
    gc_env.f[2] = *(float*)&temp;
    gc_env.r[27] = gc_env.r[30] + 800; // addi r27, r30, 0x320
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[31] + 0x90); // lfs f1, 0x90(r31)
    gc_env.f[1] = *(float*)&temp;
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[31] + 0x94); // lfs f0, 0x94(r31)
    gc_env.f[0] = *(float*)&temp;
    gc_env.f[2] = (float)gc_env.f[3] * (float)gc_env.f[2] + (float)gc_env.f[1]; // fmadds f2, f3, f2, f1
    gc_env.f[0] = (float)gc_env.f[2] * (float)gc_env.f[0]; // fmuls f0, f2, f0
    float temp = (float)gc_env.f[0]; // stfs f0, 0x2F8(r30)
    gc_mem_write32(gc_env.ram, gc_env.r[30] + 0x2F8, *(uint32_t*)&temp);
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[31] + 0x98); // lfs f0, 0x98(r31)
    gc_env.f[0] = *(float*)&temp;
    gc_env.f[0] = (float)gc_env.f[2] * (float)gc_env.f[0]; // fmuls f0, f2, f0
    float temp = (float)gc_env.f[0]; // stfs f0, 0x2FC(r30)
    gc_mem_write32(gc_env.ram, gc_env.r[30] + 0x2FC, *(uint32_t*)&temp);
    gc_mem_write32(gc_env.ram, gc_env.r[30] + 0x300, gc_env.r[0]);
    gc_env.r[0] = gc_mem_read8(gc_env.ram, gc_env.r[28] + 0x0);
    gc_env.f[1] = cm_804D7E14; // lfs f1, cm_804D7E14@sda21(r0)
    gc_env.cr[0] = (gc_env.r[0] == 0xa) ? 0 : (gc_env.r[0] < 0xa ? -1 : 1); // Compare with immediate
    float temp = (float)gc_env.f[1]; // stfs f1, 0x31C(r30)
    gc_mem_write32(gc_env.ram, gc_env.r[30] + 0x31C, *(uint32_t*)&temp);
    float temp = (float)gc_env.f[1]; // stfs f1, 0x318(r30)
    gc_mem_write32(gc_env.ram, gc_env.r[30] + 0x318, *(uint32_t*)&temp);
    float temp = (float)gc_env.f[1]; // stfs f1, 0x314(r30)
    gc_mem_write32(gc_env.ram, gc_env.r[30] + 0x314, *(uint32_t*)&temp);
    float temp = (float)gc_env.f[1]; // stfs f1, 0x320(r30)
    gc_mem_write32(gc_env.ram, gc_env.r[30] + 0x320, *(uint32_t*)&temp);
    gc_env.f[0] = cm_804D7E90; // lfs f0, cm_804D7E90@sda21(r0)
    float temp = (float)gc_env.f[0]; // stfs f0, 0x324(r30)
    gc_mem_write32(gc_env.ram, gc_env.r[30] + 0x324, *(uint32_t*)&temp);
    gc_env.f[0] = cm_804D7E94; // lfs f0, cm_804D7E94@sda21(r0)
    float temp = (float)gc_env.f[0]; // stfs f0, 0x328(r30)
    gc_mem_write32(gc_env.ram, gc_env.r[30] + 0x328, *(uint32_t*)&temp);
    float temp = (float)gc_env.f[1]; // stfs f1, 0x334(r30)
    gc_mem_write32(gc_env.ram, gc_env.r[30] + 0x334, *(uint32_t*)&temp);
    gc_env.f[0] = cm_804D7E04; // lfs f0, cm_804D7E04@sda21(r0)
    float temp = (float)gc_env.f[0]; // stfs f0, 0x338(r30)
    gc_mem_write32(gc_env.ram, gc_env.r[30] + 0x338, *(uint32_t*)&temp);
    float temp = (float)gc_env.f[1]; // stfs f1, 0x33C(r30)
    gc_mem_write32(gc_env.ram, gc_env.r[30] + 0x33C, *(uint32_t*)&temp);
    if (gc_env.cr[0] != 0) goto L_8002FB18;
    gc_env.f[0] = cm_804D7E98; // lfs f0, cm_804D7E98@sda21(r0)
    gc_env.f[0] = (float)gc_env.f[0] * (float)gc_env.f[2]; // fmuls f0, f0, f2
    float temp = (float)gc_env.f[0]; // stfs f0, 0x330(r30)
    gc_mem_write32(gc_env.ram, gc_env.r[30] + 0x330, *(uint32_t*)&temp);
    goto L_8002FB1C;
    L_8002FB18:
    float temp = (float)gc_env.f[2]; // stfs f2, 0x330(r30)
    gc_mem_write32(gc_env.ram, gc_env.r[30] + 0x330, *(uint32_t*)&temp);
    L_8002FB1C:
    gc_env.f[1] = cm_804D7E14; // lfs f1, cm_804D7E14@sda21(r0)
    Camera_8002BAA8();
    gc_env.f[1] = cm_804D7E14; // lfs f1, cm_804D7E14@sda21(r0)
    gc_env.f[2] = gc_env.f[1]; // fmr f2, f1
    Camera_8002BD88();
    gc_env.f[1] = cm_804D7E14; // lfs f1, cm_804D7E14@sda21(r0)
    gc_env.f[2] = gc_env.f[1]; // fmr f2, f1
    Camera_8002C010();
    gc_env.r[3] = gc_mem_read32(gc_env.ram, gc_env.r[30] + 0x308);
    gc_env.r[31] = gc_env.r[30] + 20; // addi r31, r30, 0x14
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[30] + 0x30c);
    gc_env.r[28] = gc_env.r[30] + 32; // addi r28, r30, 0x20
    gc_env.r[4] = gc_env.r[29] + 0; // addi r4, r29, 0x0
    gc_mem_write32(gc_env.ram, gc_env.r[30] + 0x20, gc_env.r[3]);
    gc_env.r[3] = gc_env.r[31] + 12; // addi r3, r31, 0xc
    gc_mem_write32(gc_env.ram, gc_env.r[30] + 0x24, gc_env.r[0]);
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[30] + 0x310);
    gc_mem_write32(gc_env.ram, gc_env.r[30] + 0x28, gc_env.r[0]);
    lbVector_Add();
    gc_env.r[5] = gc_mem_read32(gc_env.ram, gc_env.r[28] + 0x0);
    gc_env.r[4] = gc_env.r[27]; // Move register
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[28] + 0x4);
    gc_env.r[3] = gc_env.r[31] + 36; // addi r3, r31, 0x24
    gc_mem_write32(gc_env.ram, gc_env.r[30] + 0x38, gc_env.r[5]);
    gc_mem_write32(gc_env.ram, gc_env.r[30] + 0x3c, gc_env.r[0]);
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[28] + 0x8);
    gc_mem_write32(gc_env.ram, gc_env.r[30] + 0x40, gc_env.r[0]);
    lbVector_Add();
    gc_env.r[27] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x14); // lmw r27, 0x14(r1)
    gc_env.r[28] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x18); // lmw r27, 0x14(r1)
    gc_env.r[29] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x1C); // lmw r27, 0x14(r1)
    gc_env.r[30] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x20); // lmw r27, 0x14(r1)
    gc_env.r[31] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x24); // lmw r27, 0x14(r1)
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x2c);
    gc_env.r[1] += 40; // addi r1, r1, 0x28
    gc_env.lr = gc_env.r[0]; // Move to link register
    return;
}

// Function: fn_8002FBA0
void fn_8002FBA0(void) {
    gc_env.r[0] = gc_env.lr; // Move from link register
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x4, gc_env.r[0]);
    gc_mem_write32(gc_env.ram, gc_env.r[1] + -0x28, gc_env.r[1]);
    gc_env.r[1] = gc_env.r[1] + -0x28;
    uint64_t temp;
    memcpy(&temp, &gc_env.f[31], sizeof(double));
    gc_mem_write64(gc_env.ram, gc_env.r[1] + 0x20, temp); // stfd f31, 0x20(r1)
    uint64_t temp;
    memcpy(&temp, &gc_env.f[30], sizeof(double));
    gc_mem_write64(gc_env.ram, gc_env.r[1] + 0x18, temp); // stfd f30, 0x18(r1)
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x14, gc_env.r[31]);
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x10, gc_env.r[30]);
    gc_env.r[30] = gc_env.r[3]; // Move register
    Stage_GetCamBoundsLeftOffset();
    gc_env.f[31] = gc_env.f[1]; // fmr f31, f1
    Stage_GetCamBoundsRightOffset();
    gc_env.f[1] = (float)gc_env.f[1] + (float)gc_env.f[31]; // fadds f1, f1, f31
    gc_env.f[0] = cm_804D7E30; // lfs f0, cm_804D7E30@sda21(r0)
    gc_env.f[30] = (float)gc_env.f[0] * (float)gc_env.f[1]; // fmuls f30, f0, f1
    Stage_GetCamBoundsLeftOffset();
    gc_env.f[31] = gc_env.f[1]; // fmr f31, f1
    Stage_GetCamBoundsRightOffset();
    gc_env.f[1] = (float)gc_env.f[1] - (float)gc_env.f[31]; // fsubs f1, f1, f31
    gc_env.f[0] = cm_804D7E30; // lfs f0, cm_804D7E30@sda21(r0)
    gc_env.r[3] = ((uint32_t)&cm_803BCCA0 >> 16) & 0xFFFF; // lis r3, cm_803BCCA0@ha
    gc_env.r[31] = gc_env.r[3] + ((uint32_t)&cm_803BCCA0 & 0xFFFF); // addi r31, r3, cm_803BCCA0@l
    gc_env.f[1] = (float)gc_env.f[0] * (float)gc_env.f[1]; // fmuls f1, f0, f1
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[31] + 0xAC); // lfs f0, 0xAC(r31)
    gc_env.f[0] = *(float*)&temp;
    gc_env.f[0] = (float)gc_env.f[0] * (float)gc_env.f[1]; // fmuls f0, f0, f1
    gc_env.f[1] = (float)gc_env.f[30] + (float)gc_env.f[0]; // fadds f1, f30, f0
    gc_env.f[0] = (float)gc_env.f[30] - (float)gc_env.f[0]; // fsubs f0, f30, f0
    float temp = (float)gc_env.f[1]; // stfs f1, 0xC(r30)
    gc_mem_write32(gc_env.ram, gc_env.r[30] + 0xC, *(uint32_t*)&temp);
    float temp = (float)gc_env.f[0]; // stfs f0, 0x8(r30)
    gc_mem_write32(gc_env.ram, gc_env.r[30] + 0x8, *(uint32_t*)&temp);
    Stage_GetCamBoundsBottomOffset();
    gc_env.f[31] = gc_env.f[1]; // fmr f31, f1
    Stage_GetCamBoundsTopOffset();
    gc_env.f[1] = (float)gc_env.f[1] + (float)gc_env.f[31]; // fadds f1, f1, f31
    gc_env.f[0] = cm_804D7E30; // lfs f0, cm_804D7E30@sda21(r0)
    gc_env.f[30] = (float)gc_env.f[0] * (float)gc_env.f[1]; // fmuls f30, f0, f1
    Stage_GetCamBoundsBottomOffset();
    gc_env.f[31] = gc_env.f[1]; // fmr f31, f1
    Stage_GetCamBoundsTopOffset();
    gc_env.f[2] = (float)gc_env.f[1] - (float)gc_env.f[31]; // fsubs f2, f1, f31
    gc_env.f[1] = cm_804D7E30; // lfs f1, cm_804D7E30@sda21(r0)
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[31] + 0xB0); // lfs f0, 0xB0(r31)
    gc_env.f[0] = *(float*)&temp;
    gc_env.r[3] = 0x1;
    gc_env.f[1] = (float)gc_env.f[1] * (float)gc_env.f[2]; // fmuls f1, f1, f2
    gc_env.f[0] = (float)gc_env.f[0] * (float)gc_env.f[1]; // fmuls f0, f0, f1
    gc_env.f[1] = (float)gc_env.f[30] + (float)gc_env.f[0]; // fadds f1, f30, f0
    gc_env.f[0] = (float)gc_env.f[30] - (float)gc_env.f[0]; // fsubs f0, f30, f0
    float temp = (float)gc_env.f[1]; // stfs f1, 0x0(r30)
    gc_mem_write32(gc_env.ram, gc_env.r[30] + 0x0, *(uint32_t*)&temp);
    float temp = (float)gc_env.f[0]; // stfs f0, 0x4(r30)
    gc_mem_write32(gc_env.ram, gc_env.r[30] + 0x4, *(uint32_t*)&temp);
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x2c);
    uint64_t temp = gc_mem_read64(gc_env.ram, gc_env.r[1] + 0x20); // lfd f31, 0x20(r1)
    gc_env.d[31] = *(double*)&temp;
    uint64_t temp = gc_mem_read64(gc_env.ram, gc_env.r[1] + 0x18); // lfd f30, 0x18(r1)
    gc_env.d[30] = *(double*)&temp;
    gc_env.r[31] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x14);
    gc_env.r[30] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x10);
    gc_env.r[1] += 40; // addi r1, r1, 0x28
    gc_env.lr = gc_env.r[0]; // Move to link register
    return;
}

// Function: Camera_8002FC7C
void Camera_8002FC7C(void) {
    gc_env.r[0] = gc_env.lr; // Move from link register
    // Unknown opcode: extsb r3 r3
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x4, gc_env.r[0]);
    gc_env.r[5] = ((uint32_t)&cm_80452C68 >> 16) & 0xFFFF; // lis r5, cm_80452C68@ha
    gc_env.r[0] = 0x5;
    gc_mem_write32(gc_env.ram, gc_env.r[1] + -0x28, gc_env.r[1]);
    gc_env.r[1] = gc_env.r[1] + -0x28;
    gc_env.r[3] = gc_env.r[3] - 1;
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x14, gc_env.r[27]); // stmw r27, 0x14(r1)
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x18, gc_env.r[28]); // stmw r27, 0x14(r1)
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x1C, gc_env.r[29]); // stmw r27, 0x14(r1)
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x20, gc_env.r[30]); // stmw r27, 0x14(r1)
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x24, gc_env.r[31]); // stmw r27, 0x14(r1)
    gc_env.r[30] = gc_env.r[5] + ((uint32_t)&cm_80452C68 & 0xFFFF); // addi r30, r5, cm_80452C68@l
    gc_env.r[27] = gc_env.r[4] + 0; // addi r27, r4, 0x0
    gc_env.r[4] = 0x1;
    gc_mem_write32(gc_env.ram, gc_env.r[30] + 0x4, gc_env.r[0]);
    Camera_8002BA00();
    // Unknown opcode: extsb r0 r3
    gc_env.r[28] = gc_env.r[30] + 772; // addi r28, r30, 0x304
    gc_mem_write8(gc_env.ram, gc_env.r[30] + 0x304, gc_env.r[0]);
    gc_env.r[3] = ((uint32_t)&cm_803BCCA0 >> 16) & 0xFFFF; // lis r3, cm_803BCCA0@ha
    gc_env.r[31] = gc_env.r[3] + ((uint32_t)&cm_803BCCA0 & 0xFFFF); // addi r31, r3, cm_803BCCA0@l
    gc_mem_write8(gc_env.ram, gc_env.r[30] + 0x305, gc_env.r[27]);
    gc_env.r[29] = gc_env.r[30] + 812; // addi r29, r30, 0x32c
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[31] + 0x40); // lfs f0, 0x40(r31)
    gc_env.f[0] = *(float*)&temp;
    float temp = (float)gc_env.f[0]; // stfs f0, 0x32C(r30)
    gc_mem_write32(gc_env.ram, gc_env.r[30] + 0x32C, *(uint32_t*)&temp);
    Stage_GetCamBoundsLeftOffset();
    float temp = (float)gc_env.f[1]; // stfs f1, 0x2D8(r30)
    gc_mem_write32(gc_env.ram, gc_env.r[30] + 0x2D8, *(uint32_t*)&temp);
    Stage_GetCamBoundsRightOffset();
    float temp = (float)gc_env.f[1]; // stfs f1, 0x2DC(r30)
    gc_mem_write32(gc_env.ram, gc_env.r[30] + 0x2DC, *(uint32_t*)&temp);
    Stage_GetCamBoundsTopOffset();
    float temp = (float)gc_env.f[1]; // stfs f1, 0x2D0(r30)
    gc_mem_write32(gc_env.ram, gc_env.r[30] + 0x2D0, *(uint32_t*)&temp);
    Stage_GetCamBoundsBottomOffset();
    float temp = (float)gc_env.f[1]; // stfs f1, 0x2D4(r30)
    gc_mem_write32(gc_env.ram, gc_env.r[30] + 0x2D4, *(uint32_t*)&temp);
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[31] + 0xA8); // lfs f0, 0xA8(r31)
    gc_env.f[0] = *(float*)&temp;
    float temp = (float)gc_env.f[0]; // stfs f0, 0x2E0(r30)
    gc_mem_write32(gc_env.ram, gc_env.r[30] + 0x2E0, *(uint32_t*)&temp);
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[31] + 0xA4); // lfs f0, 0xA4(r31)
    gc_env.f[0] = *(float*)&temp;
    float temp = (float)gc_env.f[0]; // stfs f0, 0x2E4(r30)
    gc_mem_write32(gc_env.ram, gc_env.r[30] + 0x2E4, *(uint32_t*)&temp);
    Stage_GetCamAngleRadiansUp();
    float temp = (float)gc_env.f[1]; // stfs f1, 0x2E8(r30)
    gc_mem_write32(gc_env.ram, gc_env.r[30] + 0x2E8, *(uint32_t*)&temp);
    Stage_GetCamAngleRadiansDown();
    float temp = (float)gc_env.f[1]; // stfs f1, 0x2EC(r30)
    gc_mem_write32(gc_env.ram, gc_env.r[30] + 0x2EC, *(uint32_t*)&temp);
    Stage_GetCamAngleRadiansRight();
    float temp = (float)gc_env.f[1]; // stfs f1, 0x2F0(r30)
    gc_mem_write32(gc_env.ram, gc_env.r[30] + 0x2F0, *(uint32_t*)&temp);
    Stage_GetCamAngleRadiansLeft();
    float temp = (float)gc_env.f[1]; // stfs f1, 0x2F4(r30)
    gc_mem_write32(gc_env.ram, gc_env.r[30] + 0x2F4, *(uint32_t*)&temp);
    gc_env.r[3] = ((uint32_t)&fn_8002FBA0 >> 16) & 0xFFFF; // lis r3, fn_8002FBA0@ha
    gc_env.r[0] = gc_env.r[3] + ((uint32_t)&fn_8002FBA0 & 0xFFFF); // addi r0, r3, fn_8002FBA0@l
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[29] + 0x0); // lfs f3, 0x0(r29)
    gc_env.f[3] = *(float*)&temp;
    gc_env.r[29] = gc_env.r[30] + 788; // addi r29, r30, 0x314
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[31] + 0x8C); // lfs f2, 0x8C(r31)
    gc_env.f[2] = *(float*)&temp;
    gc_env.r[27] = gc_env.r[30] + 800; // addi r27, r30, 0x320
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[31] + 0x90); // lfs f1, 0x90(r31)
    gc_env.f[1] = *(float*)&temp;
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[31] + 0x94); // lfs f0, 0x94(r31)
    gc_env.f[0] = *(float*)&temp;
    gc_env.f[2] = (float)gc_env.f[3] * (float)gc_env.f[2] + (float)gc_env.f[1]; // fmadds f2, f3, f2, f1
    gc_env.f[0] = (float)gc_env.f[2] * (float)gc_env.f[0]; // fmuls f0, f2, f0
    float temp = (float)gc_env.f[0]; // stfs f0, 0x2F8(r30)
    gc_mem_write32(gc_env.ram, gc_env.r[30] + 0x2F8, *(uint32_t*)&temp);
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[31] + 0x98); // lfs f0, 0x98(r31)
    gc_env.f[0] = *(float*)&temp;
    gc_env.f[0] = (float)gc_env.f[2] * (float)gc_env.f[0]; // fmuls f0, f2, f0
    float temp = (float)gc_env.f[0]; // stfs f0, 0x2FC(r30)
    gc_mem_write32(gc_env.ram, gc_env.r[30] + 0x2FC, *(uint32_t*)&temp);
    gc_mem_write32(gc_env.ram, gc_env.r[30] + 0x300, gc_env.r[0]);
    gc_env.r[0] = gc_mem_read8(gc_env.ram, gc_env.r[28] + 0x0);
    gc_env.f[1] = cm_804D7E14; // lfs f1, cm_804D7E14@sda21(r0)
    gc_env.cr[0] = (gc_env.r[0] == 0xa) ? 0 : (gc_env.r[0] < 0xa ? -1 : 1); // Compare with immediate
    float temp = (float)gc_env.f[1]; // stfs f1, 0x31C(r30)
    gc_mem_write32(gc_env.ram, gc_env.r[30] + 0x31C, *(uint32_t*)&temp);
    float temp = (float)gc_env.f[1]; // stfs f1, 0x318(r30)
    gc_mem_write32(gc_env.ram, gc_env.r[30] + 0x318, *(uint32_t*)&temp);
    float temp = (float)gc_env.f[1]; // stfs f1, 0x314(r30)
    gc_mem_write32(gc_env.ram, gc_env.r[30] + 0x314, *(uint32_t*)&temp);
    float temp = (float)gc_env.f[1]; // stfs f1, 0x320(r30)
    gc_mem_write32(gc_env.ram, gc_env.r[30] + 0x320, *(uint32_t*)&temp);
    gc_env.f[0] = cm_804D7E90; // lfs f0, cm_804D7E90@sda21(r0)
    float temp = (float)gc_env.f[0]; // stfs f0, 0x324(r30)
    gc_mem_write32(gc_env.ram, gc_env.r[30] + 0x324, *(uint32_t*)&temp);
    gc_env.f[0] = cm_804D7E94; // lfs f0, cm_804D7E94@sda21(r0)
    float temp = (float)gc_env.f[0]; // stfs f0, 0x328(r30)
    gc_mem_write32(gc_env.ram, gc_env.r[30] + 0x328, *(uint32_t*)&temp);
    float temp = (float)gc_env.f[1]; // stfs f1, 0x334(r30)
    gc_mem_write32(gc_env.ram, gc_env.r[30] + 0x334, *(uint32_t*)&temp);
    gc_env.f[0] = cm_804D7E04; // lfs f0, cm_804D7E04@sda21(r0)
    float temp = (float)gc_env.f[0]; // stfs f0, 0x338(r30)
    gc_mem_write32(gc_env.ram, gc_env.r[30] + 0x338, *(uint32_t*)&temp);
    float temp = (float)gc_env.f[1]; // stfs f1, 0x33C(r30)
    gc_mem_write32(gc_env.ram, gc_env.r[30] + 0x33C, *(uint32_t*)&temp);
    if (gc_env.cr[0] != 0) goto L_8002FDB0;
    gc_env.f[0] = cm_804D7E98; // lfs f0, cm_804D7E98@sda21(r0)
    gc_env.f[0] = (float)gc_env.f[0] * (float)gc_env.f[2]; // fmuls f0, f0, f2
    float temp = (float)gc_env.f[0]; // stfs f0, 0x330(r30)
    gc_mem_write32(gc_env.ram, gc_env.r[30] + 0x330, *(uint32_t*)&temp);
    goto L_8002FDB4;
    L_8002FDB0:
    float temp = (float)gc_env.f[2]; // stfs f2, 0x330(r30)
    gc_mem_write32(gc_env.ram, gc_env.r[30] + 0x330, *(uint32_t*)&temp);
    L_8002FDB4:
    gc_env.f[1] = cm_804D7E14; // lfs f1, cm_804D7E14@sda21(r0)
    Camera_8002BAA8();
    gc_env.f[1] = cm_804D7E14; // lfs f1, cm_804D7E14@sda21(r0)
    gc_env.f[2] = gc_env.f[1]; // fmr f2, f1
    Camera_8002BD88();
    gc_env.f[1] = cm_804D7E14; // lfs f1, cm_804D7E14@sda21(r0)
    gc_env.f[2] = gc_env.f[1]; // fmr f2, f1
    Camera_8002C010();
    gc_env.r[3] = gc_mem_read32(gc_env.ram, gc_env.r[30] + 0x308);
    gc_env.r[31] = gc_env.r[30] + 20; // addi r31, r30, 0x14
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[30] + 0x30c);
    gc_env.r[28] = gc_env.r[30] + 32; // addi r28, r30, 0x20
    gc_env.r[4] = gc_env.r[29] + 0; // addi r4, r29, 0x0
    gc_mem_write32(gc_env.ram, gc_env.r[30] + 0x20, gc_env.r[3]);
    gc_env.r[3] = gc_env.r[31] + 12; // addi r3, r31, 0xc
    gc_mem_write32(gc_env.ram, gc_env.r[30] + 0x24, gc_env.r[0]);
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[30] + 0x310);
    gc_mem_write32(gc_env.ram, gc_env.r[30] + 0x28, gc_env.r[0]);
    lbVector_Add();
    gc_env.r[5] = gc_mem_read32(gc_env.ram, gc_env.r[28] + 0x0);
    gc_env.r[4] = gc_env.r[27]; // Move register
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[28] + 0x4);
    gc_env.r[3] = gc_env.r[31] + 36; // addi r3, r31, 0x24
    gc_mem_write32(gc_env.ram, gc_env.r[30] + 0x38, gc_env.r[5]);
    gc_mem_write32(gc_env.ram, gc_env.r[30] + 0x3c, gc_env.r[0]);
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[28] + 0x8);
    gc_mem_write32(gc_env.ram, gc_env.r[30] + 0x40, gc_env.r[0]);
    lbVector_Add();
    gc_env.r[27] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x14); // lmw r27, 0x14(r1)
    gc_env.r[28] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x18); // lmw r27, 0x14(r1)
    gc_env.r[29] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x1C); // lmw r27, 0x14(r1)
    gc_env.r[30] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x20); // lmw r27, 0x14(r1)
    gc_env.r[31] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x24); // lmw r27, 0x14(r1)
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x2c);
    gc_env.r[1] += 40; // addi r1, r1, 0x28
    gc_env.lr = gc_env.r[0]; // Move to link register
    return;
}

// Function: Camera_8002FE38
void Camera_8002FE38(void) {
    gc_env.r[3] = ((uint32_t)&cm_80452C68 >> 16) & 0xFFFF; // lis r3, cm_80452C68@ha
    gc_env.r[4] = gc_env.r[3] + ((uint32_t)&cm_80452C68 & 0xFFFF); // addi r4, r3, cm_80452C68@l
    gc_env.r[0] = 0x6;
    gc_mem_write32(gc_env.ram, gc_env.r[4] + 0x4, gc_env.r[0]);
    gc_env.r[3] = 0x0;
    gc_env.r[0] = gc_mem_read8(gc_env.ram, gc_env.r[4] + 0x341);
    uint32_t rotated = gc_env.r[3] << 5; // rlwimi r0, r3, 5, 25, 26
    gc_env.r[0] = (gc_env.r[0] & ~0x60) | (rotated & 0x60);
    gc_mem_write8(gc_env.ram, gc_env.r[4] + 0x341, gc_env.r[0]);
    gc_env.r[0] = gc_mem_read8(gc_env.ram, gc_env.r[4] + 0x341);
    uint32_t rotated = gc_env.r[3] << 3; // rlwimi r0, r3, 3, 27, 28
    gc_env.r[0] = (gc_env.r[0] & ~0x18) | (rotated & 0x18);
    gc_mem_write8(gc_env.ram, gc_env.r[4] + 0x341, gc_env.r[0]);
    gc_env.r[0] = gc_mem_read8(gc_env.ram, gc_env.r[4] + 0x341);
    uint32_t rotated = gc_env.r[3] << 1; // rlwimi r0, r3, 1, 29, 30
    gc_env.r[0] = (gc_env.r[0] & ~0x6) | (rotated & 0x6);
    gc_mem_write8(gc_env.ram, gc_env.r[4] + 0x341, gc_env.r[0]);
    gc_env.r[0] = gc_mem_read8(gc_env.ram, gc_env.r[4] + 0x341);
    uint32_t rotated = gc_env.r[3] << 0; // rlwimi r0, r3, 0, 31, 31
    gc_env.r[0] = (gc_env.r[0] & ~0x1) | (rotated & 0x1);
    gc_mem_write8(gc_env.ram, gc_env.r[4] + 0x341, gc_env.r[0]);
    gc_env.r[3] = gc_mem_read32(gc_env.ram, gc_env.r[4] + 0x14);
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[4] + 0x18);
    gc_mem_write32(gc_env.ram, gc_env.r[4] + 0x350, gc_env.r[3]);
    gc_mem_write32(gc_env.ram, gc_env.r[4] + 0x354, gc_env.r[0]);
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[4] + 0x1c);
    gc_mem_write32(gc_env.ram, gc_env.r[4] + 0x358, gc_env.r[0]);
    gc_env.r[3] = gc_mem_read32(gc_env.ram, gc_env.r[4] + 0x350);
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[4] + 0x354);
    gc_mem_write32(gc_env.ram, gc_env.r[4] + 0x20, gc_env.r[3]);
    gc_mem_write32(gc_env.ram, gc_env.r[4] + 0x24, gc_env.r[0]);
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[4] + 0x358);
    gc_mem_write32(gc_env.ram, gc_env.r[4] + 0x28, gc_env.r[0]);
    gc_env.r[3] = gc_mem_read32(gc_env.ram, gc_env.r[4] + 0x2c);
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[4] + 0x30);
    gc_mem_write32(gc_env.ram, gc_env.r[4] + 0x368, gc_env.r[3]);
    gc_mem_write32(gc_env.ram, gc_env.r[4] + 0x36c, gc_env.r[0]);
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[4] + 0x34);
    gc_mem_write32(gc_env.ram, gc_env.r[4] + 0x370, gc_env.r[0]);
    gc_env.r[3] = gc_mem_read32(gc_env.ram, gc_env.r[4] + 0x368);
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[4] + 0x36c);
    gc_mem_write32(gc_env.ram, gc_env.r[4] + 0x38, gc_env.r[3]);
    gc_mem_write32(gc_env.ram, gc_env.r[4] + 0x3c, gc_env.r[0]);
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[4] + 0x370);
    gc_mem_write32(gc_env.ram, gc_env.r[4] + 0x40, gc_env.r[0]);
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[4] + 0x44); // lfs f0, 0x44(r4)
    gc_env.f[0] = *(float*)&temp;
    float temp = (float)gc_env.f[0]; // stfs f0, 0x374(r4)
    gc_mem_write32(gc_env.ram, gc_env.r[4] + 0x374, *(uint32_t*)&temp);
    float temp = (float)gc_env.f[0]; // stfs f0, 0x48(r4)
    gc_mem_write32(gc_env.ram, gc_env.r[4] + 0x48, *(uint32_t*)&temp);
    return;
}

// Function: Camera_8002FEEC
void Camera_8002FEEC(void) {
    gc_env.r[0] = gc_env.lr; // Move from link register
    gc_env.r[4] = ((uint32_t)&cm_80452C68 >> 16) & 0xFFFF; // lis r4, cm_80452C68@ha
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x4, gc_env.r[0]);
    gc_mem_write32(gc_env.ram, gc_env.r[1] + -0x48, gc_env.r[1]);
    gc_env.r[1] = gc_env.r[1] + -0x48;
    uint64_t temp;
    memcpy(&temp, &gc_env.f[31], sizeof(double));
    gc_mem_write64(gc_env.ram, gc_env.r[1] + 0x40, temp); // stfd f31, 0x40(r1)
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x3c, gc_env.r[31]);
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x38, gc_env.r[30]);
    gc_env.r[30] = gc_env.r[4] + ((uint32_t)&cm_80452C68 & 0xFFFF); // addi r30, r4, cm_80452C68@l
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x34, gc_env.r[29]);
    gc_env.r[29] = gc_env.r[3] + 0; // addi r29, r3, 0x0
    Player_GetEntity();
    gc_env.cr[0] = ((uint32_t)gc_env.r[3] == 0x0) ? 0 : ((uint32_t)gc_env.r[3] < 0x0 ? -1 : 1); // Logical compare with immediate
    if (gc_env.cr[0] == 0) goto L_8003004C;
    gc_env.r[3] = gc_env.r[29]; // Move register
    Player_GetEntity();
    ftLib_80086B74();
    gc_env.r[31] = gc_env.r[3]; // Move register
    if (gc_env.cr[0] == 0) goto L_8003004C;
    gc_env.r[3] = gc_env.r[30] + 4; // addi r3, r30, 0x4
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[30] + 0x4);
    gc_env.cr[0] = (gc_env.r[0] == 0x7) ? 0 : (gc_env.r[0] < 0x7 ? -1 : 1); // Compare with immediate
    if (gc_env.cr[0] == 0) goto L_8003004C;
    gc_env.cr[0] = ((uint32_t)gc_env.r[0] == 0x1) ? 0 : ((uint32_t)gc_env.r[0] < 0x1 ? -1 : 1); // Logical compare with immediate
    if (gc_env.cr[0] & 0x4) goto L_8002FF50; // bgt .L_8002FF50
    gc_mem_write32(gc_env.ram, gc_env.r[30] + 0x39c, gc_env.r[0]);
    L_8002FF50:
    gc_env.r[0] = 0x7;
    gc_mem_write32(gc_env.ram, gc_env.r[3] + 0x0, gc_env.r[0]);
    gc_mem_write32(gc_env.ram, gc_env.r[30] + 0x3a0, gc_env.r[29]);
    gc_env.f[1] = cm_804D7E60; // lfs f1, cm_804D7E60@sda21(r0)
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[30] + 0x48); // lfs f0, 0x48(r30)
    gc_env.f[0] = *(float*)&temp;
    gc_env.f[1] = (float)gc_env.f[1] * (float)gc_env.f[0]; // fmuls f1, f1, f0
    tanf();
    gc_env.f[3] = cm_804D7EA8; // lfs f3, cm_804D7EA8@sda21(r0)
    gc_env.r[4] = gc_env.r[1] + 24; // addi r4, r1, 0x18
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[31] + 0x3C); // lfs f2, 0x3C(r31)
    gc_env.f[2] = *(float*)&temp;
    gc_env.f[0] = cm_804D7E14; // lfs f0, cm_804D7E14@sda21(r0)
    gc_env.f[2] = (float)gc_env.f[3] * (float)gc_env.f[2]; // fmuls f2, f3, f2
    float temp = (float)gc_env.f[0]; // stfs f0, 0x3AC(r30)
    gc_mem_write32(gc_env.ram, gc_env.r[30] + 0x3AC, *(uint32_t*)&temp);
    gc_env.f[31] = (float)gc_env.f[2] / (float)gc_env.f[1]; // fdivs f31, f2, f1
    float temp = (float)gc_env.f[0]; // stfs f0, 0x3A8(r30)
    gc_mem_write32(gc_env.ram, gc_env.r[30] + 0x3A8, *(uint32_t*)&temp);
    float temp = (float)gc_env.f[0]; // stfs f0, 0x3A4(r30)
    gc_mem_write32(gc_env.ram, gc_env.r[30] + 0x3A4, *(uint32_t*)&temp);
    gc_env.r[3] = gc_mem_read32(gc_env.ram, gc_env.r[30] + 0x0);
    gc_env.r[29] = gc_mem_read32(gc_env.ram, gc_env.r[3] + 0x28);
    gc_env.r[3] = gc_env.r[29]; // Move register
    HSD_CObjGetInterest();
    gc_env.r[3] = gc_env.r[29] + 0; // addi r3, r29, 0x0
    gc_env.r[4] = gc_env.r[1] + 36; // addi r4, r1, 0x24
    HSD_CObjGetEyePosition();
    gc_env.r[3] = gc_env.r[29]; // Move register
    HSD_CObjGetFov();
    gc_env.r[4] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x18);
    gc_env.r[31] = gc_env.r[30] + 944; // addi r31, r30, 0x3b0
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x1c);
    gc_env.r[5] = gc_env.r[31] + 0; // addi r5, r31, 0x0
    gc_env.r[3] = gc_env.r[1] + 36; // addi r3, r1, 0x24
    gc_mem_write32(gc_env.ram, gc_env.r[30] + 0x3bc, gc_env.r[4]);
    gc_env.r[4] = gc_env.r[1] + 24; // addi r4, r1, 0x18
    gc_mem_write32(gc_env.ram, gc_env.r[30] + 0x3c0, gc_env.r[0]);
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x20);
    gc_mem_write32(gc_env.ram, gc_env.r[30] + 0x3c4, gc_env.r[0]);
    gc_env.r[6] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x24);
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x28);
    gc_mem_write32(gc_env.ram, gc_env.r[30] + 0x3c8, gc_env.r[6]);
    gc_mem_write32(gc_env.ram, gc_env.r[30] + 0x3cc, gc_env.r[0]);
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x2c);
    gc_mem_write32(gc_env.ram, gc_env.r[30] + 0x3d0, gc_env.r[0]);
    float temp = (float)gc_env.f[1]; // stfs f1, 0x3D4(r30)
    gc_mem_write32(gc_env.ram, gc_env.r[30] + 0x3D4, *(uint32_t*)&temp);
    lbVector_Diff();
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[31] + 0x0); // lfs f1, 0x0(r31)
    gc_env.f[1] = *(float*)&temp;
    gc_env.r[29] = gc_env.r[30] + 948; // addi r29, r30, 0x3b4
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[30] + 0x3B4); // lfs f0, 0x3B4(r30)
    gc_env.f[0] = *(float*)&temp;
    gc_env.f[1] = (float)gc_env.f[1] * (float)gc_env.f[1]; // fmuls f1, f1, f1
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[30] + 0x3B8); // lfsu f2, 0x3B8(r30)
    gc_env.f[2] = *(float*)&temp;
    gc_env.r[30] = gc_env.r[30] + 0x3B8;
    gc_env.f[0] = (float)gc_env.f[0] * (float)gc_env.f[0]; // fmuls f0, f0, f0
    gc_env.f[2] = (float)gc_env.f[2] * (float)gc_env.f[2]; // fmuls f2, f2, f2
    gc_env.f[0] = (float)gc_env.f[1] + (float)gc_env.f[0]; // fadds f0, f1, f0
    gc_env.f[1] = (float)gc_env.f[2] + (float)gc_env.f[0]; // fadds f1, f2, f0
    sqrtf__Ff();
    gc_env.f[1] = (float)gc_env.f[31] / (float)gc_env.f[1]; // fdivs f1, f31, f1
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[31] + 0x0); // lfs f0, 0x0(r31)
    gc_env.f[0] = *(float*)&temp;
    gc_env.f[0] = (float)gc_env.f[0] * (float)gc_env.f[1]; // fmuls f0, f0, f1
    float temp = (float)gc_env.f[0]; // stfs f0, 0x0(r31)
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x0, *(uint32_t*)&temp);
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[29] + 0x0); // lfs f0, 0x0(r29)
    gc_env.f[0] = *(float*)&temp;
    gc_env.f[0] = (float)gc_env.f[0] * (float)gc_env.f[1]; // fmuls f0, f0, f1
    float temp = (float)gc_env.f[0]; // stfs f0, 0x0(r29)
    gc_mem_write32(gc_env.ram, gc_env.r[29] + 0x0, *(uint32_t*)&temp);
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[30] + 0x0); // lfs f0, 0x0(r30)
    gc_env.f[0] = *(float*)&temp;
    gc_env.f[0] = (float)gc_env.f[0] * (float)gc_env.f[1]; // fmuls f0, f0, f1
    float temp = (float)gc_env.f[0]; // stfs f0, 0x0(r30)
    gc_mem_write32(gc_env.ram, gc_env.r[30] + 0x0, *(uint32_t*)&temp);
    L_8003004C:
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x4c);
    uint64_t temp = gc_mem_read64(gc_env.ram, gc_env.r[1] + 0x40); // lfd f31, 0x40(r1)
    gc_env.d[31] = *(double*)&temp;
    gc_env.r[31] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x3c);
    gc_env.r[30] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x38);
    gc_env.r[29] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x34);
    gc_env.r[1] += 72; // addi r1, r1, 0x48
    gc_env.lr = gc_env.r[0]; // Move to link register
    return;
}

// Function: Camera_8003006C
void Camera_8003006C(void) {
    gc_env.r[0] = gc_env.lr; // Move from link register
    gc_env.r[3] = ((uint32_t)&cm_80452C68 >> 16) & 0xFFFF; // lis r3, cm_80452C68@ha
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x4, gc_env.r[0]);
    gc_mem_write32(gc_env.ram, gc_env.r[1] + -0x20, gc_env.r[1]);
    gc_env.r[1] = gc_env.r[1] + -0x20;
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x1c, gc_env.r[31]);
    gc_env.r[31] = gc_env.r[3] + ((uint32_t)&cm_80452C68 & 0xFFFF); // addi r31, r3, cm_80452C68@l
    gc_env.r[3] = gc_env.r[31] + 4; // addi r3, r31, 0x4
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x18, gc_env.r[30]);
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[31] + 0x4);
    gc_env.cr[0] = (gc_env.r[0] == 0x8) ? 0 : (gc_env.r[0] < 0x8 ? -1 : 1); // Compare with immediate
    if (gc_env.cr[0] == 0) goto L_800300D8;
    gc_env.cr[0] = ((uint32_t)gc_env.r[0] == 0x1) ? 0 : ((uint32_t)gc_env.r[0] < 0x1 ? -1 : 1); // Logical compare with immediate
    if (gc_env.cr[0] & 0x4) goto L_800300A4; // bgt .L_800300A4
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x39c, gc_env.r[0]);
    L_800300A4:
    gc_env.r[0] = 0x8;
    gc_mem_write32(gc_env.ram, gc_env.r[3] + 0x0, gc_env.r[0]);
    gc_env.r[4] = gc_env.r[31] + 984; // addi r4, r31, 0x3d8
    gc_env.r[3] = gc_mem_read32(gc_env.ram, gc_env.r[31] + 0x0);
    gc_env.r[30] = gc_mem_read32(gc_env.ram, gc_env.r[3] + 0x28);
    gc_env.r[3] = gc_env.r[30]; // Move register
    HSD_CObjGetInterest();
    gc_env.r[3] = gc_env.r[30] + 0; // addi r3, r30, 0x0
    gc_env.r[4] = gc_env.r[31] + 996; // addi r4, r31, 0x3e4
    HSD_CObjGetEyePosition();
    gc_env.r[3] = gc_env.r[30]; // Move register
    HSD_CObjGetFov();
    float temp = (float)gc_env.f[1]; // stfs f1, 0x3F0(r31)
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x3F0, *(uint32_t*)&temp);
    L_800300D8:
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x24);
    gc_env.r[31] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x1c);
    gc_env.r[30] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x18);
    gc_env.r[1] += 32; // addi r1, r1, 0x20
    gc_env.lr = gc_env.r[0]; // Move to link register
    return;
}

// Function: Camera_800300F0
void Camera_800300F0(void) {
    gc_env.r[3] = ((uint32_t)&cm_80453004 >> 16) & 0xFFFF; // lis r3, cm_80453004@ha
    gc_env.r[4] = gc_env.r[3] + ((uint32_t)&cm_80453004 & 0xFFFF); // addi r4, r3, cm_80453004@l
    gc_env.r[3] = ((uint32_t)&cm_80452C68 >> 16) & 0xFFFF; // lis r3, cm_80452C68@ha
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[4] + 0x0);
    gc_env.r[3] = gc_env.r[3] + ((uint32_t)&cm_80452C68 & 0xFFFF); // addi r3, r3, cm_80452C68@l
    gc_mem_write32(gc_env.ram, gc_env.r[3] + 0x4, gc_env.r[0]);
    return;
}

// Function: Camera_8003010C
void Camera_8003010C(void) {
    gc_env.r[3] = ((uint32_t)&cm_80452C68 >> 16) & 0xFFFF; // lis r3, cm_80452C68@ha
    gc_env.r[3] = gc_env.r[3] + ((uint32_t)&cm_80452C68 & 0xFFFF); // addi r3, r3, cm_80452C68@l
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[3] + 0x4);
    gc_env.cr[0] = (gc_env.r[0] == 0x5) ? 0 : (gc_env.r[0] < 0x5 ? -1 : 1); // Compare with immediate
    if (gc_env.cr[0] != 0) goto L_80030128;
    gc_env.r[3] = 0x1;
    return;
    L_80030128:
    gc_env.r[3] = 0x0;
    return;
}

// Function: Camera_80030130
void Camera_80030130(void) {
    gc_env.r[3] = ((uint32_t)&cm_80452C68 >> 16) & 0xFFFF; // lis r3, cm_80452C68@ha
    gc_env.r[3] = gc_env.r[3] + ((uint32_t)&cm_80452C68 & 0xFFFF); // addi r3, r3, cm_80452C68@l
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[3] + 0x4);
    gc_env.cr[0] = (gc_env.r[0] == 0x6) ? 0 : (gc_env.r[0] < 0x6 ? -1 : 1); // Compare with immediate
    if (gc_env.cr[0] != 0) goto L_8003014C;
    gc_env.r[3] = 0x1;
    return;
    L_8003014C:
    gc_env.r[3] = 0x0;
    return;
}

// Function: Camera_80030154
void Camera_80030154(void) {
    gc_env.r[3] = ((uint32_t)&cm_80452C68 >> 16) & 0xFFFF; // lis r3, cm_80452C68@ha
    gc_env.r[3] = gc_env.r[3] + ((uint32_t)&cm_80452C68 & 0xFFFF); // addi r3, r3, cm_80452C68@l
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[3] + 0x4);
    gc_env.cr[0] = (gc_env.r[0] == 0x7) ? 0 : (gc_env.r[0] < 0x7 ? -1 : 1); // Compare with immediate
    if (gc_env.cr[0] != 0) goto L_80030170;
    gc_env.r[3] = 0x1;
    return;
    L_80030170:
    gc_env.r[3] = 0x0;
    return;
}

// Function: Camera_80030178
void Camera_80030178(void) {
    gc_env.r[3] = ((uint32_t)&cm_80452C68 >> 16) & 0xFFFF; // lis r3, cm_80452C68@ha
    gc_env.r[3] = gc_env.r[3] + ((uint32_t)&cm_80452C68 & 0xFFFF); // addi r3, r3, cm_80452C68@l
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[3] + 0x4);
    gc_env.cr[0] = (gc_env.r[0] == 0x8) ? 0 : (gc_env.r[0] < 0x8 ? -1 : 1); // Compare with immediate
    if (gc_env.cr[0] != 0) goto L_80030194;
    gc_env.r[3] = 0x1;
    return;
    L_80030194:
    gc_env.r[3] = 0x0;
    return;
}

// Function: Camera_8003019C
void Camera_8003019C(void) {
    gc_env.r[0] = gc_env.lr; // Move from link register
    gc_env.r[3] = ((uint32_t)&cm_80453004 >> 16) & 0xFFFF; // lis r3, cm_80453004@ha
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x4, gc_env.r[0]);
    gc_env.r[3] = gc_env.r[3] + ((uint32_t)&cm_80453004 & 0xFFFF); // addi r3, r3, cm_80453004@l
    gc_mem_write32(gc_env.ram, gc_env.r[1] + -0x8, gc_env.r[1]);
    gc_env.r[1] = gc_env.r[1] + -0x8;
    gc_env.r[3] = gc_mem_read32(gc_env.ram, gc_env.r[3] + 0x4);
    Player_GetEntity();
    ftLib_80086B74();
    gc_env.r[3] += 28; // addi r3, r3, 0x1c
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0xc);
    gc_env.r[1] += 8; // addi r1, r1, 0x8
    gc_env.lr = gc_env.r[0]; // Move to link register
    return;
}

// Function: fn_800301D0
void fn_800301D0(void) {
    gc_env.r[0] = gc_env.lr; // Move from link register
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x4, gc_env.r[0]);
    gc_mem_write32(gc_env.ram, gc_env.r[1] + -0x60, gc_env.r[1]);
    gc_env.r[1] = gc_env.r[1] + -0x60;
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x4C, gc_env.r[27]); // stmw r27, 0x4C(r1)
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x50, gc_env.r[28]); // stmw r27, 0x4C(r1)
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x54, gc_env.r[29]); // stmw r27, 0x4C(r1)
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x58, gc_env.r[30]); // stmw r27, 0x4C(r1)
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x5C, gc_env.r[31]); // stmw r27, 0x4C(r1)
    gc_env.r[29] = gc_env.r[3]; // Move register
    gc_env.r[27] = gc_mem_read32(gc_env.ram, gc_env.r[3] + 0x28);
    gc_env.r[3] = ((uint32_t)&cm_80452C68 >> 16) & 0xFFFF; // lis r3, cm_80452C68@ha
    gc_env.r[28] = gc_env.r[3] + ((uint32_t)&cm_80452C68 & 0xFFFF); // addi r28, r3, cm_80452C68@l
    gc_env.r[3] = gc_env.r[27] + 0; // addi r3, r27, 0x0
    lbRefract_8002247C();
    gc_env.r[3] = gc_env.r[29]; // Move register
    Camera_8002A4AC();
    gc_env.r[30] = gc_env.r[28] + 921; // addi r30, r28, 0x399
    gc_env.r[3] = gc_mem_read8(gc_env.ram, gc_env.r[28] + 0x399);
    gc_env.r[3] = gc_env.r[3] & 0x1; // clrlwi r3, r3, 31
    lbShadow_8000F38C();
    gc_env.r[3] = gc_env.r[27]; // Move register
    HSD_CObjSetCurrent();
    gc_env.cr[0] = (gc_env.r[3] == 0x0) ? 0 : (gc_env.r[3] < 0x0 ? -1 : 1); // Compare with immediate
    if (gc_env.cr[0] == 0) goto L_800304CC;
    gc_env.r[0] = gc_mem_read8(gc_env.ram, gc_env.r[28] + 0x398);
    gc_env.r[31] = gc_env.r[28] + 920; // addi r31, r28, 0x398
    gc_env.r[0] = (gc_env.r[0] >> 2) & 0x1; // extrwi r0, r0, 1, 29
    gc_env.cr[0] = (gc_env.r[0] == 0) ? 0x2 : ((int32_t)gc_env.r[0] < 0 ? 0x8 : 0x4);
    if (gc_env.cr[0] != 0) goto L_80030248;
    gc_env.r[3] = gc_mem_read8(gc_env.ram, gc_env.r[28] + 0x8);
    gc_env.r[6] = 0xff;
    gc_env.r[4] = gc_mem_read8(gc_env.ram, gc_env.r[28] + 0x9);
    gc_env.r[5] = gc_mem_read8(gc_env.ram, gc_env.r[28] + 0xa);
    HSD_SetEraseColor();
    goto L_8003025C;
    L_80030248:
    gc_env.r[3] = 0x0;
    gc_env.r[4] = 0x0;
    gc_env.r[5] = 0x0;
    gc_env.r[6] = 0xff;
    HSD_SetEraseColor();
    L_8003025C:
    gc_env.r[3] = gc_env.r[27] + 0; // addi r3, r27, 0x0
    gc_env.r[4] = 0x1;
    gc_env.r[5] = 0x0;
    gc_env.r[6] = 0x0;
    HSD_CObjEraseScreen();
    gc_env.r[3] = gc_env.r[27]; // Move register
    Ground_801C4FAC();
    gc_env.r[3] = 0x0;
    HSD_LObjDeleteCurrentAll();
    gc_env.r[3] = 0x2;
    Camera_800310A0();
    gc_env.r[0] = gc_mem_read8(gc_env.ram, gc_env.r[31] + 0x0);
    gc_env.r[0] = (gc_env.r[0] >> 5) & 0x1; // extrwi r0, r0, 1, 26
    gc_env.cr[0] = (gc_env.r[0] == 0) ? 0x2 : ((int32_t)gc_env.r[0] < 0 ? 0x8 : 0x4);
    if (gc_env.cr[0] == 0) goto L_800302A0;
    gc_env.r[4] = 0x0;
    gc_env.r[3] = gc_env.r[4] + 0; // addi r3, r4, 0x0
    goto L_800302A8;
    L_800302A0:
    gc_env.r[4] = 0x8;
    gc_env.r[3] = 0x0;
    L_800302A8:
    gc_env.r[0] = gc_mem_read8(gc_env.ram, gc_env.r[31] + 0x0);
    gc_env.r[0] = (gc_env.r[0] >> 3) & 0x1; // extrwi r0, r0, 1, 28
    gc_env.cr[0] = (gc_env.r[0] == 0) ? 0x2 : ((int32_t)gc_env.r[0] < 0 ? 0x8 : 0x4);
    if (gc_env.cr[0] == 0) goto L_800302C0;
    gc_env.r[0] = 0x0;
    gc_env.r[5] = gc_env.r[0]; // Move register
    goto L_800302C8;
    L_800302C0:
    gc_env.r[0] = 0x1;
    gc_env.r[5] = 0x0;
    L_800302C8:
    gc_env.r[0] = gc_env.r[0] | gc_env.r[4]; // or r0, r0, r4
    gc_mem_write32(gc_env.ram, gc_env.r[29] + 0x24, gc_env.r[0]);
    gc_env.r[0] = gc_env.r[5] | gc_env.r[3]; // or r0, r5, r3
    gc_env.r[3] = gc_env.r[29] + 0; // addi r3, r29, 0x0
    gc_mem_write32(gc_env.ram, gc_env.r[29] + 0x20, gc_env.r[0]);
    gc_env.r[4] = 0x7;
    HSD_GObj_80390ED0();
    gc_env.r[3] = 0x1;
    Camera_800310A0();
    gc_env.r[0] = gc_mem_read8(gc_env.ram, gc_env.r[31] + 0x0);
    gc_env.r[0] = (gc_env.r[0] >> 5) & 0x1; // extrwi r0, r0, 1, 26
    gc_env.cr[0] = (gc_env.r[0] == 0) ? 0x2 : ((int32_t)gc_env.r[0] < 0 ? 0x8 : 0x4);
    if (gc_env.cr[0] == 0) goto L_80030304;
    gc_env.r[3] = 0x0;
    gc_env.r[0] = gc_env.r[3] + 0; // addi r0, r3, 0x0
    goto L_8003030C;
    L_80030304:
    gc_env.r[3] = 0x8;
    gc_env.r[0] = 0x0;
    L_8003030C:
    gc_mem_write32(gc_env.ram, gc_env.r[29] + 0x24, gc_env.r[3]);
    gc_env.r[3] = gc_env.r[29] + 0; // addi r3, r29, 0x0
    gc_env.r[4] = 0x7;
    gc_mem_write32(gc_env.ram, gc_env.r[29] + 0x20, gc_env.r[0]);
    HSD_GObj_80390ED0();
    gc_env.r[3] = 0x0;
    Camera_800310A0();
    gc_env.r[0] = gc_mem_read8(gc_env.ram, gc_env.r[31] + 0x0);
    gc_env.r[0] = (gc_env.r[0] >> 5) & 0x1; // extrwi r0, r0, 1, 26
    gc_env.cr[0] = (gc_env.r[0] == 0) ? 0x2 : ((int32_t)gc_env.r[0] < 0 ? 0x8 : 0x4);
    if (gc_env.cr[0] == 0) goto L_80030340;
    gc_env.r[3] = 0x0;
    gc_env.r[0] = gc_env.r[3] + 0; // addi r0, r3, 0x0
    goto L_80030348;
    L_80030340:
    gc_env.r[3] = 0x8;
    gc_env.r[0] = 0x0;
    L_80030348:
    gc_mem_write32(gc_env.ram, gc_env.r[29] + 0x24, gc_env.r[3]);
    gc_env.r[3] = gc_env.r[29] + 0; // addi r3, r29, 0x0
    gc_env.r[4] = 0x3;
    gc_mem_write32(gc_env.ram, gc_env.r[29] + 0x20, gc_env.r[0]);
    HSD_GObj_80390ED0();
    lbRefract_80022560();
    gc_env.r[0] = gc_mem_read8(gc_env.ram, gc_env.r[31] + 0x0);
    gc_env.r[0] = (gc_env.r[0] >> 3) & 0x1; // extrwi r0, r0, 1, 28
    gc_env.cr[0] = (gc_env.r[0] == 0) ? 0x2 : ((int32_t)gc_env.r[0] < 0 ? 0x8 : 0x4);
    if (gc_env.cr[0] == 0) goto L_80030378;
    gc_env.r[6] = 0x0;
    gc_env.r[5] = gc_env.r[6] + 0; // addi r5, r6, 0x0
    goto L_80030380;
    L_80030378:
    gc_env.r[6] = 0x1;
    gc_env.r[5] = 0x0;
    L_80030380:
    gc_env.r[3] = gc_env.r[29]; // Move register
    Camera_800311EC();
    gc_env.r[3] = 0x0;
    Camera_80031074();
    gc_env.r[0] = gc_mem_read8(gc_env.ram, gc_env.r[31] + 0x0);
    gc_env.r[0] = (gc_env.r[0] >> 5) & 0x1; // extrwi r0, r0, 1, 26
    gc_env.cr[0] = (gc_env.r[0] == 0) ? 0x2 : ((int32_t)gc_env.r[0] < 0 ? 0x8 : 0x4);
    if (gc_env.cr[0] == 0) goto L_800303A8;
    gc_env.r[4] = 0x0;
    gc_env.r[3] = gc_env.r[4] + 0; // addi r3, r4, 0x0
    goto L_800303B0;
    L_800303A8:
    gc_env.r[4] = 0x8;
    gc_env.r[3] = 0x0;
    L_800303B0:
    gc_env.r[0] = gc_mem_read8(gc_env.ram, gc_env.r[31] + 0x0);
    gc_env.r[0] = (gc_env.r[0] >> 3) & 0x1; // extrwi r0, r0, 1, 28
    gc_env.cr[0] = (gc_env.r[0] == 0) ? 0x2 : ((int32_t)gc_env.r[0] < 0 ? 0x8 : 0x4);
    if (gc_env.cr[0] == 0) goto L_800303C8;
    gc_env.r[0] = 0x0;
    gc_env.r[5] = gc_env.r[0]; // Move register
    goto L_800303D0;
    L_800303C8:
    gc_env.r[0] = 0x1;
    gc_env.r[5] = 0x0;
    L_800303D0:
    gc_env.r[0] = gc_env.r[0] | gc_env.r[4]; // or r0, r0, r4
    gc_mem_write32(gc_env.ram, gc_env.r[29] + 0x24, gc_env.r[0]);
    gc_env.r[0] = gc_env.r[5] | gc_env.r[3]; // or r0, r5, r3
    gc_env.r[3] = gc_env.r[29] + 0; // addi r3, r29, 0x0
    gc_mem_write32(gc_env.ram, gc_env.r[29] + 0x20, gc_env.r[0]);
    gc_env.r[4] = 0x4;
    HSD_GObj_80390ED0();
    gc_env.r[0] = gc_mem_read8(gc_env.ram, gc_env.r[31] + 0x0);
    gc_env.r[0] = (gc_env.r[0] >> 3) & 0x1; // extrwi r0, r0, 1, 28
    gc_env.cr[0] = (gc_env.r[0] == 0) ? 0x2 : ((int32_t)gc_env.r[0] < 0 ? 0x8 : 0x4);
    if (gc_env.cr[0] == 0) goto L_80030404;
    gc_env.r[6] = 0x0;
    gc_env.r[5] = gc_env.r[6] + 0; // addi r5, r6, 0x0
    goto L_8003040C;
    L_80030404:
    gc_env.r[6] = 0x1;
    gc_env.r[5] = 0x0;
    L_8003040C:
    gc_env.r[3] = gc_env.r[29]; // Move register
    Camera_80031328();
    gc_env.r[3] = 0x0;
    HSD_FogSet();
    gc_env.r[0] = gc_mem_read8(gc_env.ram, gc_env.r[31] + 0x0);
    gc_env.r[0] = (gc_env.r[0] >> 4) & 0x1; // extrwi r0, r0, 1, 27
    gc_env.cr[0] = (gc_env.r[0] == 0) ? 0x2 : ((int32_t)gc_env.r[0] < 0 ? 0x8 : 0x4);
    if (gc_env.cr[0] == 0) goto L_80030434;
    gc_env.r[3] = 0x0;
    gc_env.r[0] = gc_env.r[3] + 0; // addi r0, r3, 0x0
    goto L_8003043C;
    L_80030434:
    gc_env.r[3] = 0x80;
    gc_env.r[0] = 0x0;
    L_8003043C:
    gc_mem_write32(gc_env.ram, gc_env.r[29] + 0x24, gc_env.r[3]);
    gc_env.r[3] = gc_env.r[29] + 0; // addi r3, r29, 0x0
    gc_env.r[4] = 0x7;
    gc_mem_write32(gc_env.ram, gc_env.r[29] + 0x20, gc_env.r[0]);
    HSD_GObj_80390ED0();
    gc_env.r[3] = 0x3;
    Camera_800310A0();
    gc_env.r[0] = gc_mem_read8(gc_env.ram, gc_env.r[31] + 0x0);
    gc_env.r[0] = (gc_env.r[0] >> 5) & 0x1; // extrwi r0, r0, 1, 26
    gc_env.cr[0] = (gc_env.r[0] == 0) ? 0x2 : ((int32_t)gc_env.r[0] < 0 ? 0x8 : 0x4);
    if (gc_env.cr[0] == 0) goto L_80030470;
    gc_env.r[3] = 0x0;
    gc_env.r[0] = gc_env.r[3] + 0; // addi r0, r3, 0x0
    goto L_80030478;
    L_80030470:
    gc_env.r[3] = 0x8;
    gc_env.r[0] = 0x0;
    L_80030478:
    gc_mem_write32(gc_env.ram, gc_env.r[29] + 0x24, gc_env.r[3]);
    gc_env.r[3] = gc_env.r[29] + 0; // addi r3, r29, 0x0
    gc_env.r[4] = 0x7;
    gc_mem_write32(gc_env.ram, gc_env.r[29] + 0x20, gc_env.r[0]);
    HSD_GObj_80390ED0();
    Camera_80030AC4();
    gc_env.cr[0] = (gc_env.r[3] == 0x0) ? 0 : (gc_env.r[3] < 0x0 ? -1 : 1); // Compare with immediate
    if (gc_env.cr[0] == 0) goto L_800304C8;
    Camera_80030A78();
    gc_env.cr[0] = (gc_env.r[3] == 0x0) ? 0 : (gc_env.r[3] < 0x0 ? -1 : 1); // Compare with immediate
    if (gc_env.cr[0] == 0) goto L_800304A8;
    mpLib_8005A2DC();
    L_800304A8:
    gc_env.r[0] = gc_mem_read8(gc_env.ram, gc_env.r[30] + 0x0);
    gc_env.r[0] = (gc_env.r[0] >> 3) & 0x1; // extrwi r0, r0, 1, 28
    gc_env.cr[0] = (gc_env.r[0] == 0) ? 0x2 : ((int32_t)gc_env.r[0] < 0 ? 0x8 : 0x4);
    if (gc_env.cr[0] == 0) goto L_800304B8;
    mpLib_8005A340();
    L_800304B8:
    Camera_80030BA8();
    gc_env.cr[0] = (gc_env.r[3] == 0x0) ? 0 : (gc_env.r[3] < 0x0 ? -1 : 1); // Compare with immediate
    if (gc_env.cr[0] == 0) goto L_800304C8;
    mpLib_8005A220();
    L_800304C8:
    HSD_CObjEndCurrent();
    L_800304CC:
    gc_env.r[27] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x4C); // lmw r27, 0x4C(r1)
    gc_env.r[28] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x50); // lmw r27, 0x4C(r1)
    gc_env.r[29] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x54); // lmw r27, 0x4C(r1)
    gc_env.r[30] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x58); // lmw r27, 0x4C(r1)
    gc_env.r[31] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x5C); // lmw r27, 0x4C(r1)
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x64);
    gc_env.r[1] += 96; // addi r1, r1, 0x60
    gc_env.lr = gc_env.r[0]; // Move to link register
    return;
}

// Function: Camera_800304E0
void Camera_800304E0(void) {
    gc_env.r[0] = gc_env.lr; // Move from link register
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x4, gc_env.r[0]);
    gc_mem_write32(gc_env.ram, gc_env.r[1] + -0x40, gc_env.r[1]);
    gc_env.r[1] = gc_env.r[1] + -0x40;
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x3c, gc_env.r[31]);
    gc_env.r[31] = gc_env.r[3]; // Move register
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x38, gc_env.r[30]);
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x34, gc_env.r[29]);
    gc_env.r[29] = gc_mem_read32(gc_env.ram, gc_env.r[3] + 0x28);
    gc_env.r[3] = ((uint32_t)&cm_80452C68 >> 16) & 0xFFFF; // lis r3, cm_80452C68@ha
    gc_env.r[30] = gc_env.r[3] + ((uint32_t)&cm_80452C68 & 0xFFFF); // addi r30, r3, cm_80452C68@l
    gc_env.r[3] = gc_env.r[29] + 0; // addi r3, r29, 0x0
    HSD_CObjSetCurrent();
    gc_env.cr[0] = (gc_env.r[3] == 0x0) ? 0 : (gc_env.r[3] < 0x0 ? -1 : 1); // Compare with immediate
    if (gc_env.cr[0] == 0) goto L_8003066C;
    gc_env.r[3] = gc_mem_read8(gc_env.ram, gc_env.r[30] + 0x8);
    gc_env.r[6] = 0x1;
    gc_env.r[4] = gc_mem_read8(gc_env.ram, gc_env.r[30] + 0x9);
    gc_env.r[5] = gc_mem_read8(gc_env.ram, gc_env.r[30] + 0xa);
    HSD_SetEraseColor();
    gc_env.r[3] = gc_env.r[29] + 0; // addi r3, r29, 0x0
    gc_env.r[4] = 0x1;
    gc_env.r[5] = 0x0;
    gc_env.r[6] = 0x0;
    HSD_CObjEraseScreen();
    gc_env.r[3] = gc_env.r[29]; // Move register
    Ground_801C4FAC();
    gc_env.r[3] = 0x0;
    HSD_LObjDeleteCurrentAll();
    gc_env.r[3] = 0x2;
    Camera_800310A0();
    gc_env.r[0] = gc_mem_read8(gc_env.ram, gc_env.r[30] + 920); // lbzu r0, 920(r30)
    gc_env.r[30] = gc_env.r[30] + 920;
    gc_env.r[0] = (gc_env.r[0] >> 5) & 0x1; // extrwi r0, r0, 1, 26
    gc_env.cr[0] = (gc_env.r[0] == 0) ? 0x2 : ((int32_t)gc_env.r[0] < 0 ? 0x8 : 0x4);
    if (gc_env.cr[0] == 0) goto L_80030570;
    gc_env.r[4] = 0x0;
    gc_env.r[3] = gc_env.r[4] + 0; // addi r3, r4, 0x0
    goto L_80030578;
    L_80030570:
    gc_env.r[4] = 0x8;
    gc_env.r[3] = 0x0;
    L_80030578:
    gc_env.r[0] = gc_mem_read8(gc_env.ram, gc_env.r[30] + 0x0);
    gc_env.r[0] = (gc_env.r[0] >> 3) & 0x1; // extrwi r0, r0, 1, 28
    gc_env.cr[0] = (gc_env.r[0] == 0) ? 0x2 : ((int32_t)gc_env.r[0] < 0 ? 0x8 : 0x4);
    if (gc_env.cr[0] == 0) goto L_80030590;
    gc_env.r[0] = 0x0;
    gc_env.r[5] = gc_env.r[0]; // Move register
    goto L_80030598;
    L_80030590:
    gc_env.r[0] = 0x1;
    gc_env.r[5] = 0x0;
    L_80030598:
    gc_env.r[0] = gc_env.r[0] | gc_env.r[4]; // or r0, r0, r4
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x24, gc_env.r[0]);
    gc_env.r[0] = gc_env.r[5] | gc_env.r[3]; // or r0, r5, r3
    gc_env.r[3] = gc_env.r[31] + 0; // addi r3, r31, 0x0
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x20, gc_env.r[0]);
    gc_env.r[4] = 0x7;
    HSD_GObj_80390ED0();
    gc_env.r[3] = 0x1;
    Camera_800310A0();
    gc_env.r[0] = gc_mem_read8(gc_env.ram, gc_env.r[30] + 0x0);
    gc_env.r[0] = (gc_env.r[0] >> 5) & 0x1; // extrwi r0, r0, 1, 26
    gc_env.cr[0] = (gc_env.r[0] == 0) ? 0x2 : ((int32_t)gc_env.r[0] < 0 ? 0x8 : 0x4);
    if (gc_env.cr[0] == 0) goto L_800305D4;
    gc_env.r[3] = 0x0;
    gc_env.r[0] = gc_env.r[3] + 0; // addi r0, r3, 0x0
    goto L_800305DC;
    L_800305D4:
    gc_env.r[3] = 0x8;
    gc_env.r[0] = 0x0;
    L_800305DC:
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x24, gc_env.r[3]);
    gc_env.r[3] = gc_env.r[31] + 0; // addi r3, r31, 0x0
    gc_env.r[4] = 0x7;
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x20, gc_env.r[0]);
    HSD_GObj_80390ED0();
    gc_env.r[3] = 0x0;
    Camera_800310A0();
    gc_env.r[0] = gc_mem_read8(gc_env.ram, gc_env.r[30] + 0x0);
    gc_env.r[0] = (gc_env.r[0] >> 5) & 0x1; // extrwi r0, r0, 1, 26
    gc_env.cr[0] = (gc_env.r[0] == 0) ? 0x2 : ((int32_t)gc_env.r[0] < 0 ? 0x8 : 0x4);
    if (gc_env.cr[0] == 0) goto L_80030610;
    gc_env.r[3] = 0x0;
    gc_env.r[0] = gc_env.r[3] + 0; // addi r0, r3, 0x0
    goto L_80030618;
    L_80030610:
    gc_env.r[3] = 0x8;
    gc_env.r[0] = 0x0;
    L_80030618:
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x24, gc_env.r[3]);
    gc_env.r[3] = gc_env.r[31] + 0; // addi r3, r31, 0x0
    gc_env.r[4] = 0x7;
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x20, gc_env.r[0]);
    HSD_GObj_80390ED0();
    gc_env.r[0] = 0x70;
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x24, gc_env.r[0]);
    gc_env.r[30] = 0x0;
    gc_env.r[3] = gc_env.r[31] + 0; // addi r3, r31, 0x0
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x20, gc_env.r[30]);
    gc_env.r[4] = 0x7;
    HSD_GObj_80390ED0();
    gc_env.r[3] = 0x0;
    HSD_FogSet();
    gc_env.r[0] = 0x80;
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x24, gc_env.r[0]);
    gc_env.r[3] = gc_env.r[31] + 0; // addi r3, r31, 0x0
    gc_env.r[4] = 0x7;
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0x20, gc_env.r[30]);
    HSD_GObj_80390ED0();
    HSD_CObjEndCurrent();
    L_8003066C:
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x44);
    gc_env.r[31] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x3c);
    gc_env.r[30] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x38);
    gc_env.r[29] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x34);
    gc_env.r[1] += 64; // addi r1, r1, 0x40
    gc_env.lr = gc_env.r[0]; // Move to link register
    return;
}

// Function: Camera_80030688
void Camera_80030688(void) {
    gc_env.r[0] = gc_env.lr; // Move from link register
    gc_env.r[3] = 0x10;
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x4, gc_env.r[0]);
    gc_env.r[4] = 0x12;
    gc_env.r[5] = 0x0;
    gc_mem_write32(gc_env.ram, gc_env.r[1] + -0x18, gc_env.r[1]);
    gc_env.r[1] = gc_env.r[1] + -0x18;
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x14, gc_env.r[31]);
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x10, gc_env.r[30]);
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0xc, gc_env.r[29]);
    GObj_Create();
    gc_env.r[4] = ((uint32_t)&cm_803BCB64 >> 16) & 0xFFFF; // lis r4, cm_803BCB64@ha
    gc_env.r[5] = ((uint32_t)&cm_80452C68 >> 16) & 0xFFFF; // lis r5, cm_80452C68@ha
    gc_env.r[30] = gc_env.r[3] + 0; // addi r30, r3, 0x0
    gc_env.r[31] = gc_env.r[4] + ((uint32_t)&cm_803BCB64 & 0xFFFF); // addi r31, r4, cm_803BCB64@l
    gc_mem_write32(gc_env.ram, gc_env.r[5] + cm_80452C68@l, gc_env.r[30]);
    gc_env.r[3] = gc_env.r[31]; // Move register
    lb_80013B14();
    gc_env.r[29] = gc_env.r[3] + 0; // addi r29, r3, 0x0
    gc_env.r[3] = gc_env.r[31] + 0; // addi r3, r31, 0x0
    lb_80013B14();
    gc_mem_write32(gc_env.ram, gc_env.r[0] + cm_804D6464@sda21, gc_env.r[3]);
    gc_env.r[5] = gc_env.r[29]; // Move register
    gc_env.r[4] = gc_mem_read8(gc_env.ram, gc_env.r[0] + HSD_GObj_804D784B@sda21);
    gc_env.r[3] = gc_env.r[30]; // Move register
    HSD_GObjObject_80390A70();
    gc_env.r[3] = ((uint32_t)&fn_800301D0 >> 16) & 0xFFFF; // lis r3, fn_800301D0@ha
    gc_env.r[4] = gc_env.r[3] + ((uint32_t)&fn_800301D0 & 0xFFFF); // addi r4, r3, fn_800301D0@l
    gc_env.r[3] = gc_env.r[30] + 0; // addi r3, r30, 0x0
    gc_env.r[5] = 0x2;
    GObj_SetupGXLinkMax();
    gc_env.r[3] = ((uint32_t)&fn_8002F360 >> 16) & 0xFFFF; // lis r3, fn_8002F360@ha
    gc_env.r[4] = gc_env.r[3] + ((uint32_t)&fn_8002F360 & 0xFFFF); // addi r4, r3, fn_8002F360@l
    gc_env.r[3] = gc_env.r[30] + 0; // addi r3, r30, 0x0
    gc_env.r[5] = 0x12;
    HSD_GObjProc_8038FD54();
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x1c);
    gc_env.r[31] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x14);
    gc_env.r[30] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x10);
    gc_env.r[29] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0xc);
    gc_env.r[1] += 24; // addi r1, r1, 0x18
    gc_env.lr = gc_env.r[0]; // Move to link register
    return;
}

// Function: Camera_80030730
void Camera_80030730(void) {
    gc_env.r[3] = ((uint32_t)&cm_803BCCA0 >> 16) & 0xFFFF; // lis r3, cm_803BCCA0@ha
    gc_env.r[3] = gc_env.r[3] + ((uint32_t)&cm_803BCCA0 & 0xFFFF); // addi r3, r3, cm_803BCCA0@l
    float temp = (float)gc_env.f[1]; // stfs f1, 0x40(r3)
    gc_mem_write32(gc_env.ram, gc_env.r[3] + 0x40, *(uint32_t*)&temp);
    return;
}

// Function: Camera_80030740
void Camera_80030740(void) {
    gc_env.r[6] = ((uint32_t)&cm_80452C68 >> 16) & 0xFFFF; // lis r6, cm_80452C68@ha
    gc_env.r[6] = gc_env.r[6] + ((uint32_t)&cm_80452C68 & 0xFFFF); // addi r6, r6, cm_80452C68@l
    gc_mem_write8(gc_env.ram, gc_env.r[6] + 0x8, gc_env.r[3]);
    gc_mem_write8(gc_env.ram, gc_env.r[6] + 0x9, gc_env.r[4]);
    gc_mem_write8(gc_env.ram, gc_env.r[6] + 0xa, gc_env.r[5]);
    return;
}

// Function: Camera_80030758
void Camera_80030758(void) {
    gc_env.r[3] = ((uint32_t)&cm_80452C68 >> 16) & 0xFFFF; // lis r3, cm_80452C68@ha
    gc_mem_write32(gc_env.ram, gc_env.r[1] + -0x10, gc_env.r[1]);
    gc_env.r[1] = gc_env.r[1] + -0x10;
    gc_env.r[3] = gc_env.r[3] + ((uint32_t)&cm_80452C68 & 0xFFFF); // addi r3, r3, cm_80452C68@l
    gc_env.r[0] = gc_mem_read8(gc_env.ram, gc_env.r[3] + 0x8);
    gc_mem_write8(gc_env.ram, gc_env.r[1] + 0x8, gc_env.r[0]);
    gc_env.r[0] = gc_mem_read8(gc_env.ram, gc_env.r[3] + 0x9);
    gc_mem_write8(gc_env.ram, gc_env.r[1] + 0x9, gc_env.r[0]);
    gc_env.r[0] = gc_mem_read8(gc_env.ram, gc_env.r[3] + 0xa);
    gc_mem_write8(gc_env.ram, gc_env.r[1] + 0xa, gc_env.r[0]);
    gc_env.r[3] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x8);
    gc_env.r[1] += 16; // addi r1, r1, 0x10
    return;
}

// Function: Camera_80030788
void Camera_80030788(void) {
    gc_env.r[4] = ((uint32_t)&cm_80452C68 >> 16) & 0xFFFF; // lis r4, cm_80452C68@ha
    gc_env.r[5] = gc_env.r[4] + ((uint32_t)&cm_80452C68 & 0xFFFF); // addi r5, r4, cm_80452C68@l
    gc_env.r[4] = gc_mem_read32(gc_env.ram, gc_env.r[5] + 0x2c);
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[5] + 0x30);
    gc_mem_write32(gc_env.ram, gc_env.r[3] + 0x0, gc_env.r[4]);
    gc_mem_write32(gc_env.ram, gc_env.r[3] + 0x4, gc_env.r[0]);
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[5] + 0x34);
    gc_mem_write32(gc_env.ram, gc_env.r[3] + 0x8, gc_env.r[0]);
    return;
}

// Function: Camera_800307AC
void Camera_800307AC(void) {
    gc_env.r[4] = ((uint32_t)&cm_80452C68 >> 16) & 0xFFFF; // lis r4, cm_80452C68@ha
    gc_env.r[5] = gc_env.r[4] + ((uint32_t)&cm_80452C68 & 0xFFFF); // addi r5, r4, cm_80452C68@l
    gc_env.r[4] = gc_mem_read32(gc_env.ram, gc_env.r[5] + 0x14);
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[5] + 0x18);
    gc_mem_write32(gc_env.ram, gc_env.r[3] + 0x0, gc_env.r[4]);
    gc_mem_write32(gc_env.ram, gc_env.r[3] + 0x4, gc_env.r[0]);
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[5] + 0x1c);
    gc_mem_write32(gc_env.ram, gc_env.r[3] + 0x8, gc_env.r[0]);
    return;
}

// Function: Camera_800307D0
void Camera_800307D0(void) {
    gc_env.r[0] = gc_env.lr; // Move from link register
    gc_env.r[6] = ((uint32_t)&cm_80452C68 >> 16) & 0xFFFF; // lis r6, cm_80452C68@ha
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x4, gc_env.r[0]);
    gc_env.r[6] = gc_env.r[6] + ((uint32_t)&cm_80452C68 & 0xFFFF); // addi r6, r6, cm_80452C68@l
    gc_mem_write32(gc_env.ram, gc_env.r[1] + -0x80, gc_env.r[1]);
    gc_env.r[1] = gc_env.r[1] + -0x80;
    uint64_t temp;
    memcpy(&temp, &gc_env.f[31], sizeof(double));
    gc_mem_write64(gc_env.ram, gc_env.r[1] + 0x78, temp); // stfd f31, 0x78(r1)
    uint64_t temp;
    memcpy(&temp, &gc_env.f[30], sizeof(double));
    gc_mem_write64(gc_env.ram, gc_env.r[1] + 0x70, temp); // stfd f30, 0x70(r1)
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x5C, gc_env.r[27]); // stmw r27, 0x5C(r1)
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x60, gc_env.r[28]); // stmw r27, 0x5C(r1)
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x64, gc_env.r[29]); // stmw r27, 0x5C(r1)
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x68, gc_env.r[30]); // stmw r27, 0x5C(r1)
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x6C, gc_env.r[31]); // stmw r27, 0x5C(r1)
    gc_env.r[27] = gc_env.r[3] + 0; // addi r27, r3, 0x0
    gc_env.r[28] = gc_env.r[4] + 0; // addi r28, r4, 0x0
    gc_env.r[29] = gc_env.r[5] + 0; // addi r29, r5, 0x0
    gc_env.r[6] = gc_mem_read32(gc_env.ram, gc_env.r[6] + 0x0);
    gc_env.r[31] = gc_mem_read32(gc_env.ram, gc_env.r[6] + 0x28);
    gc_env.r[3] = gc_env.r[31] + 0; // addi r3, r31, 0x0
    HSD_CObjGetAspect();
    gc_env.f[30] = gc_env.f[1]; // fmr f30, f1
    gc_env.r[3] = gc_env.r[31]; // Move register
    HSD_CObjGetFov();
    gc_env.f[2] = cm_804D7E60; // lfs f2, cm_804D7E60@sda21(r0)
    gc_env.r[3] = gc_env.r[31]; // Move register
    gc_env.d[0] = cm_804D7E78; // lfd f0, cm_804D7E78@sda21(r0)
    gc_env.r[4] = gc_env.r[1] + 48; // addi r4, r1, 0x30
    gc_env.f[1] = (float)gc_env.f[2] * (float)gc_env.f[1]; // fmuls f1, f2, f1
    gc_env.r[30] = 0x1;
    gc_env.f[1] = (float)gc_env.f[1] * (float)gc_env.f[30]; // fmuls f1, f1, f30
    // Unknown opcode: fmul f31 f0 f1
    gc_env.f[31] = (float)gc_env.f[31]; // frsp f31, f31
    HSD_CObjGetEyePosition();
    gc_env.r[3] = gc_env.r[31] + 0; // addi r3, r31, 0x0
    gc_env.r[4] = gc_env.r[1] + 72; // addi r4, r1, 0x48
    HSD_CObjGetEyeVector();
    gc_env.r[3] = gc_env.r[31] + 0; // addi r3, r31, 0x0
    gc_env.r[4] = gc_env.r[1] + 60; // addi r4, r1, 0x3c
    HSD_CObjGetInterest();
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x48); // lfs f1, 0x48(r1)
    gc_env.f[1] = *(float*)&temp;
    gc_env.f[0] = cm_804D7E14; // lfs f0, cm_804D7E14@sda21(r0)
    gc_env.cr[0] = isnan(gc_env.f[1]) || isnan(gc_env.f[0]) ? 0x1 : (gc_env.f[1] < gc_env.f[0] ? 0x8 : (gc_env.f[1] > gc_env.f[0] ? 0x4 : 0x2)); // fcmpo cr0, f1, f0
    if (gc_env.cr[0] >= 0) goto L_8003086C;
    gc_env.f[1] = -gc_env.f[1]; // fneg f1, f1
    L_8003086C:
    gc_env.d[0] = cm_804D7EE8; // lfd f0, cm_804D7EE8@sda21(r0)
    gc_env.cr[0] = isnan(gc_env.f[1]) || isnan(gc_env.f[0]) ? 0x1 : (gc_env.f[1] < gc_env.f[0] ? 0x8 : (gc_env.f[1] > gc_env.f[0] ? 0x4 : 0x2)); // fcmpo cr0, f1, f0
    if (gc_env.cr[0] & (0x8 | 0x2)) goto L_80030A14; // ble .L_80030A14
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x50); // lfs f1, 0x50(r1)
    gc_env.f[1] = *(float*)&temp;
    gc_env.f[0] = cm_804D7E14; // lfs f0, cm_804D7E14@sda21(r0)
    gc_env.cr[0] = isnan(gc_env.f[1]) || isnan(gc_env.f[0]) ? 0x1 : (gc_env.f[1] < gc_env.f[0] ? 0x8 : (gc_env.f[1] > gc_env.f[0] ? 0x4 : 0x2)); // fcmpo cr0, f1, f0
    if (gc_env.cr[0] >= 0) goto L_8003088C;
    gc_env.f[1] = -gc_env.f[1]; // fneg f1, f1
    L_8003088C:
    gc_env.d[0] = cm_804D7EE8; // lfd f0, cm_804D7EE8@sda21(r0)
    gc_env.cr[0] = isnan(gc_env.f[1]) || isnan(gc_env.f[0]) ? 0x1 : (gc_env.f[1] < gc_env.f[0] ? 0x8 : (gc_env.f[1] > gc_env.f[0] ? 0x4 : 0x2)); // fcmpo cr0, f1, f0
    if (gc_env.cr[0] & (0x8 | 0x2)) goto L_80030A14; // ble .L_80030A14
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x48); // lfs f0, 0x48(r1)
    gc_env.f[0] = *(float*)&temp;
    gc_env.f[1] = gc_env.f[31]; // fmr f1, f31
    gc_env.f[2] = cm_804D7E10; // lfs f2, cm_804D7E10@sda21(r0)
    gc_env.f[0] = (float)gc_env.f[0] * (float)gc_env.f[2]; // fmuls f0, f0, f2
    float temp = (float)gc_env.f[0]; // stfs f0, 0x48(r1)
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x48, *(uint32_t*)&temp);
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x4C); // lfs f0, 0x4C(r1)
    gc_env.f[0] = *(float*)&temp;
    gc_env.f[0] = (float)gc_env.f[0] * (float)gc_env.f[2]; // fmuls f0, f0, f2
    float temp = (float)gc_env.f[0]; // stfs f0, 0x4C(r1)
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x4C, *(uint32_t*)&temp);
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x50); // lfs f0, 0x50(r1)
    gc_env.f[0] = *(float*)&temp;
    gc_env.f[0] = (float)gc_env.f[0] * (float)gc_env.f[2]; // fmuls f0, f0, f2
    float temp = (float)gc_env.f[0]; // stfs f0, 0x50(r1)
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x50, *(uint32_t*)&temp);
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x38); // lfs f2, 0x38(r1)
    gc_env.f[2] = *(float*)&temp;
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x50); // lfs f0, 0x50(r1)
    gc_env.f[0] = *(float*)&temp;
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x48); // lfs f3, 0x48(r1)
    gc_env.f[3] = *(float*)&temp;
    gc_env.f[2] = (float)gc_env.f[2] / (float)gc_env.f[0]; // fdivs f2, f2, f0
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x30); // lfs f0, 0x30(r1)
    gc_env.f[0] = *(float*)&temp;
    gc_env.f[0] = -((float)gc_env.f[3] * (float)gc_env.f[2] - (float)gc_env.f[0]); // fnmsubs f0, f3, f2, f0
    float temp = (float)gc_env.f[0]; // stfs f0, 0x0(r28)
    gc_mem_write32(gc_env.ram, gc_env.r[28] + 0x0, *(uint32_t*)&temp);
    sinf();
    gc_env.f[30] = gc_env.f[1]; // fmr f30, f1
    gc_env.f[1] = gc_env.f[31]; // fmr f1, f31
    cosf();
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x48); // lfs f4, 0x48(r1)
    gc_env.f[4] = *(float*)&temp;
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x50); // lfs f5, 0x50(r1)
    gc_env.f[5] = *(float*)&temp;
    gc_env.f[2] = (float)gc_env.f[4] * (float)gc_env.f[30]; // fmuls f2, f4, f30
    gc_env.f[0] = cm_804D7E14; // lfs f0, cm_804D7E14@sda21(r0)
    gc_env.f[3] = (float)gc_env.f[5] * (float)gc_env.f[30]; // fmuls f3, f5, f30
    gc_env.f[2] = (float)gc_env.f[5] * (float)gc_env.f[1] - (float)gc_env.f[2]; // fmsubs f2, f5, f1, f2
    gc_env.f[3] = (float)gc_env.f[4] * (float)gc_env.f[1] + (float)gc_env.f[3]; // fmadds f3, f4, f1, f3
    gc_env.cr[0] = isnan(gc_env.f[2]) || isnan(gc_env.f[0]) ? 0x1 : (gc_env.f[2] < gc_env.f[0] ? 0x8 : (gc_env.f[2] > gc_env.f[0] ? 0x4 : 0x2)); // fcmpo cr0, f2, f0
    if (gc_env.cr[0] >= 0) goto L_8003091C;
    gc_env.f[1] = -gc_env.f[2]; // fneg f1, f2
    goto L_80030920;
    L_8003091C:
    gc_env.f[1] = gc_env.f[2]; // fmr f1, f2
    L_80030920:
    gc_env.d[0] = cm_804D7EE8; // lfd f0, cm_804D7EE8@sda21(r0)
    gc_env.cr[0] = isnan(gc_env.f[1]) || isnan(gc_env.f[0]) ? 0x1 : (gc_env.f[1] < gc_env.f[0] ? 0x8 : (gc_env.f[1] > gc_env.f[0] ? 0x4 : 0x2)); // fcmpo cr0, f1, f0
    if (gc_env.cr[0] & (0x8 | 0x2)) goto L_80030954; // ble .L_80030954
    gc_env.f[1] = (float)gc_env.f[5] * (float)gc_env.f[2]; // fmuls f1, f5, f2
    gc_env.d[0] = cm_804D7EF0; // lfd f0, cm_804D7EF0@sda21(r0)
    gc_env.cr[0] = isnan(gc_env.f[1]) || isnan(gc_env.f[0]) ? 0x1 : (gc_env.f[1] < gc_env.f[0] ? 0x8 : (gc_env.f[1] > gc_env.f[0] ? 0x4 : 0x2)); // fcmpo cr0, f1, f0
    if (gc_env.cr[0] & (0x8 | 0x2)) goto L_80030954; // ble .L_80030954
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x38); // lfs f1, 0x38(r1)
    gc_env.f[1] = *(float*)&temp;
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x30); // lfs f0, 0x30(r1)
    gc_env.f[0] = *(float*)&temp;
    gc_env.f[1] = (float)gc_env.f[1] / (float)gc_env.f[2]; // fdivs f1, f1, f2
    gc_env.f[0] = -((float)gc_env.f[3] * (float)gc_env.f[1] - (float)gc_env.f[0]); // fnmsubs f0, f3, f1, f0
    float temp = (float)gc_env.f[0]; // stfs f0, 0x0(r27)
    gc_mem_write32(gc_env.ram, gc_env.r[27] + 0x0, *(uint32_t*)&temp);
    goto L_80030974;
    L_80030954:
    gc_env.f[0] = cm_804D7E14; // lfs f0, cm_804D7E14@sda21(r0)
    gc_env.cr[0] = isnan(gc_env.f[3]) || isnan(gc_env.f[0]) ? 0x1 : (gc_env.f[3] < gc_env.f[0] ? 0x8 : (gc_env.f[3] > gc_env.f[0] ? 0x4 : 0x2)); // fcmpo cr0, f3, f0
    if (gc_env.cr[0] & (0x8 | 0x2)) goto L_8003096C; // ble .L_8003096C
    gc_env.f[0] = cm_804D7EF8; // lfs f0, cm_804D7EF8@sda21(r0)
    float temp = (float)gc_env.f[0]; // stfs f0, 0x0(r27)
    gc_mem_write32(gc_env.ram, gc_env.r[27] + 0x0, *(uint32_t*)&temp);
    goto L_80030974;
    L_8003096C:
    gc_env.f[0] = cm_804D7EFC; // lfs f0, cm_804D7EFC@sda21(r0)
    float temp = (float)gc_env.f[0]; // stfs f0, 0x0(r27)
    gc_mem_write32(gc_env.ram, gc_env.r[27] + 0x0, *(uint32_t*)&temp);
    L_80030974:
    gc_env.f[30] = -gc_env.f[31]; // fneg f30, f31
    gc_env.f[1] = gc_env.f[30]; // fmr f1, f30
    sinf();
    gc_env.f[31] = gc_env.f[1]; // fmr f31, f1
    gc_env.f[1] = gc_env.f[30]; // fmr f1, f30
    cosf();
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x48); // lfs f4, 0x48(r1)
    gc_env.f[4] = *(float*)&temp;
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x50); // lfs f5, 0x50(r1)
    gc_env.f[5] = *(float*)&temp;
    gc_env.f[2] = (float)gc_env.f[4] * (float)gc_env.f[31]; // fmuls f2, f4, f31
    gc_env.f[0] = cm_804D7E14; // lfs f0, cm_804D7E14@sda21(r0)
    gc_env.f[3] = (float)gc_env.f[5] * (float)gc_env.f[31]; // fmuls f3, f5, f31
    gc_env.f[2] = (float)gc_env.f[5] * (float)gc_env.f[1] - (float)gc_env.f[2]; // fmsubs f2, f5, f1, f2
    gc_env.f[3] = (float)gc_env.f[4] * (float)gc_env.f[1] + (float)gc_env.f[3]; // fmadds f3, f4, f1, f3
    gc_env.cr[0] = isnan(gc_env.f[2]) || isnan(gc_env.f[0]) ? 0x1 : (gc_env.f[2] < gc_env.f[0] ? 0x8 : (gc_env.f[2] > gc_env.f[0] ? 0x4 : 0x2)); // fcmpo cr0, f2, f0
    if (gc_env.cr[0] >= 0) goto L_800309B8;
    gc_env.f[1] = -gc_env.f[2]; // fneg f1, f2
    goto L_800309BC;
    L_800309B8:
    gc_env.f[1] = gc_env.f[2]; // fmr f1, f2
    L_800309BC:
    gc_env.d[0] = cm_804D7EE8; // lfd f0, cm_804D7EE8@sda21(r0)
    gc_env.cr[0] = isnan(gc_env.f[1]) || isnan(gc_env.f[0]) ? 0x1 : (gc_env.f[1] < gc_env.f[0] ? 0x8 : (gc_env.f[1] > gc_env.f[0] ? 0x4 : 0x2)); // fcmpo cr0, f1, f0
    if (gc_env.cr[0] & (0x8 | 0x2)) goto L_800309F0; // ble .L_800309F0
    gc_env.f[1] = (float)gc_env.f[5] * (float)gc_env.f[2]; // fmuls f1, f5, f2
    gc_env.d[0] = cm_804D7EF0; // lfd f0, cm_804D7EF0@sda21(r0)
    gc_env.cr[0] = isnan(gc_env.f[1]) || isnan(gc_env.f[0]) ? 0x1 : (gc_env.f[1] < gc_env.f[0] ? 0x8 : (gc_env.f[1] > gc_env.f[0] ? 0x4 : 0x2)); // fcmpo cr0, f1, f0
    if (gc_env.cr[0] & (0x8 | 0x2)) goto L_800309F0; // ble .L_800309F0
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x38); // lfs f1, 0x38(r1)
    gc_env.f[1] = *(float*)&temp;
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x30); // lfs f0, 0x30(r1)
    gc_env.f[0] = *(float*)&temp;
    gc_env.f[1] = (float)gc_env.f[1] / (float)gc_env.f[2]; // fdivs f1, f1, f2
    gc_env.f[0] = -((float)gc_env.f[3] * (float)gc_env.f[1] - (float)gc_env.f[0]); // fnmsubs f0, f3, f1, f0
    float temp = (float)gc_env.f[0]; // stfs f0, 0x0(r29)
    gc_mem_write32(gc_env.ram, gc_env.r[29] + 0x0, *(uint32_t*)&temp);
    goto L_80030A30;
    L_800309F0:
    gc_env.f[0] = cm_804D7E14; // lfs f0, cm_804D7E14@sda21(r0)
    gc_env.cr[0] = isnan(gc_env.f[3]) || isnan(gc_env.f[0]) ? 0x1 : (gc_env.f[3] < gc_env.f[0] ? 0x8 : (gc_env.f[3] > gc_env.f[0] ? 0x4 : 0x2)); // fcmpo cr0, f3, f0
    if (gc_env.cr[0] & (0x8 | 0x2)) goto L_80030A08; // ble .L_80030A08
    gc_env.f[0] = cm_804D7EF8; // lfs f0, cm_804D7EF8@sda21(r0)
    float temp = (float)gc_env.f[0]; // stfs f0, 0x0(r29)
    gc_mem_write32(gc_env.ram, gc_env.r[29] + 0x0, *(uint32_t*)&temp);
    goto L_80030A30;
    L_80030A08:
    gc_env.f[0] = cm_804D7EFC; // lfs f0, cm_804D7EFC@sda21(r0)
    float temp = (float)gc_env.f[0]; // stfs f0, 0x0(r29)
    gc_mem_write32(gc_env.ram, gc_env.r[29] + 0x0, *(uint32_t*)&temp);
    goto L_80030A30;
    L_80030A14:
    gc_env.f[0] = cm_804D7EFC; // lfs f0, cm_804D7EFC@sda21(r0)
    gc_env.r[30] = 0x0;
    float temp = (float)gc_env.f[0]; // stfs f0, 0x0(r27)
    gc_mem_write32(gc_env.ram, gc_env.r[27] + 0x0, *(uint32_t*)&temp);
    gc_env.f[0] = cm_804D7EF8; // lfs f0, cm_804D7EF8@sda21(r0)
    float temp = (float)gc_env.f[0]; // stfs f0, 0x0(r29)
    gc_mem_write32(gc_env.ram, gc_env.r[29] + 0x0, *(uint32_t*)&temp);
    gc_env.f[0] = cm_804D7E14; // lfs f0, cm_804D7E14@sda21(r0)
    float temp = (float)gc_env.f[0]; // stfs f0, 0x0(r28)
    gc_mem_write32(gc_env.ram, gc_env.r[28] + 0x0, *(uint32_t*)&temp);
    L_80030A30:
    gc_env.r[3] = gc_env.r[30]; // Move register
    gc_env.r[27] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x5C); // lmw r27, 0x5C(r1)
    gc_env.r[28] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x60); // lmw r27, 0x5C(r1)
    gc_env.r[29] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x64); // lmw r27, 0x5C(r1)
    gc_env.r[30] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x68); // lmw r27, 0x5C(r1)
    gc_env.r[31] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x6C); // lmw r27, 0x5C(r1)
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x84);
    uint64_t temp = gc_mem_read64(gc_env.ram, gc_env.r[1] + 0x78); // lfd f31, 0x78(r1)
    gc_env.d[31] = *(double*)&temp;
    uint64_t temp = gc_mem_read64(gc_env.ram, gc_env.r[1] + 0x70); // lfd f30, 0x70(r1)
    gc_env.d[30] = *(double*)&temp;
    gc_env.r[1] += 128; // addi r1, r1, 0x80
    gc_env.lr = gc_env.r[0]; // Move to link register
    return;
}

// Function: Camera_80030A50
void Camera_80030A50(void) {
    gc_env.r[3] = ((uint32_t)&cm_80452C68 >> 16) & 0xFFFF; // lis r3, cm_80452C68@ha
    gc_env.r[3] = gc_env.r[3] + ((uint32_t)&cm_80452C68 & 0xFFFF); // addi r3, r3, cm_80452C68@l
    gc_env.r[3] = gc_mem_read32(gc_env.ram, gc_env.r[3] + 0x0);
    return;
}

// Function: Camera_80030A60
void Camera_80030A60(void) {
    gc_env.r[4] = ((uint32_t)&cm_80452C68 >> 16) & 0xFFFF; // lis r4, cm_80452C68@ha
    gc_env.r[4] = gc_env.r[4] + ((uint32_t)&cm_80452C68 & 0xFFFF); // addi r4, r4, cm_80452C68@l
    gc_env.r[0] = gc_mem_read8(gc_env.ram, gc_env.r[4] + 0x399);
    uint32_t rotated = gc_env.r[3] << 4; // rlwimi r0, r3, 4, 27, 27
    gc_env.r[0] = (gc_env.r[0] & ~0x10) | (rotated & 0x10);
    gc_mem_write8(gc_env.ram, gc_env.r[4] + 0x399, gc_env.r[0]);
    return;
}

// Function: Camera_80030A78
void Camera_80030A78(void) {
    gc_env.r[3] = ((uint32_t)&cm_80452C68 >> 16) & 0xFFFF; // lis r3, cm_80452C68@ha
    gc_env.r[3] = gc_env.r[3] + ((uint32_t)&cm_80452C68 & 0xFFFF); // addi r3, r3, cm_80452C68@l
    gc_env.r[3] = gc_mem_read8(gc_env.ram, gc_env.r[3] + 0x399);
    gc_env.r[3] = (gc_env.r[3] >> 4) & 0x1; // extrwi r3, r3, 1, 27
    return;
}

// Function: Camera_80030A8C
void Camera_80030A8C(void) {
    gc_env.r[4] = ((uint32_t)&cm_80452C68 >> 16) & 0xFFFF; // lis r4, cm_80452C68@ha
    gc_env.r[4] = gc_env.r[4] + ((uint32_t)&cm_80452C68 & 0xFFFF); // addi r4, r4, cm_80452C68@l
    gc_env.r[0] = gc_mem_read8(gc_env.ram, gc_env.r[4] + 0x399);
    uint32_t rotated = gc_env.r[3] << 3; // rlwimi r0, r3, 3, 28, 28
    gc_env.r[0] = (gc_env.r[0] & ~0x8) | (rotated & 0x8);
    gc_mem_write8(gc_env.ram, gc_env.r[4] + 0x399, gc_env.r[0]);
    return;
}

// Function: Camera_80030AA4
void Camera_80030AA4(void) {
    // Unknown opcode: cntlzw r0 r3
    gc_env.r[3] = ((uint32_t)&cm_80452C68 >> 16) & 0xFFFF; // lis r3, cm_80452C68@ha
    gc_env.r[3] = gc_env.r[3] + ((uint32_t)&cm_80452C68 & 0xFFFF); // addi r3, r3, cm_80452C68@l
    gc_env.r[4] = (gc_env.r[0] >> 5) & 0xFF; // extrwi r4, r0, 8, 19
    gc_env.r[0] = gc_mem_read8(gc_env.ram, gc_env.r[3] + 0x399);
    uint32_t rotated = gc_env.r[4] << 2; // rlwimi r0, r4, 2, 29, 29
    gc_env.r[0] = (gc_env.r[0] & ~0x4) | (rotated & 0x4);
    gc_mem_write8(gc_env.ram, gc_env.r[3] + 0x399, gc_env.r[0]);
    return;
}

// Function: Camera_80030AC4
void Camera_80030AC4(void) {
    gc_env.r[3] = ((uint32_t)&cm_80452C68 >> 16) & 0xFFFF; // lis r3, cm_80452C68@ha
    gc_env.r[3] = gc_env.r[3] + ((uint32_t)&cm_80452C68 & 0xFFFF); // addi r3, r3, cm_80452C68@l
    gc_env.r[0] = gc_mem_read8(gc_env.ram, gc_env.r[3] + 0x399);
    gc_env.r[0] = (gc_env.r[0] >> 2) & 0x1; // extrwi r0, r0, 1, 29
    // Unknown opcode: cntlzw r0 r0
    gc_env.r[3] = gc_env.r[0] >> 5; // srwi r3, r0, 5
    return;
}

// Function: Camera_80030AE0
void Camera_80030AE0(void) {
    gc_env.r[4] = ((uint32_t)&cm_80452C68 >> 16) & 0xFFFF; // lis r4, cm_80452C68@ha
    gc_env.r[4] = gc_env.r[4] + ((uint32_t)&cm_80452C68 & 0xFFFF); // addi r4, r4, cm_80452C68@l
    gc_env.r[0] = gc_mem_read8(gc_env.ram, gc_env.r[4] + 0x399);
    uint32_t rotated = gc_env.r[3] << 5; // rlwimi r0, r3, 5, 26, 26
    gc_env.r[0] = (gc_env.r[0] & ~0x20) | (rotated & 0x20);
    gc_mem_write8(gc_env.ram, gc_env.r[4] + 0x399, gc_env.r[0]);
    return;
}

// Function: Camera_80030AF8
void Camera_80030AF8(void) {
    gc_env.r[3] = ((uint32_t)&cm_80452C68 >> 16) & 0xFFFF; // lis r3, cm_80452C68@ha
    gc_env.r[3] = gc_env.r[3] + ((uint32_t)&cm_80452C68 & 0xFFFF); // addi r3, r3, cm_80452C68@l
    gc_env.r[3] = gc_mem_read8(gc_env.ram, gc_env.r[3] + 0x399);
    gc_env.r[3] = (gc_env.r[3] >> 5) & 0x1; // extrwi r3, r3, 1, 26
    return;
}

// Function: Camera_80030B0C
void Camera_80030B0C(void) {
    gc_env.r[4] = ((uint32_t)&cm_80452C68 >> 16) & 0xFFFF; // lis r4, cm_80452C68@ha
    gc_env.r[4] = gc_env.r[4] + ((uint32_t)&cm_80452C68 & 0xFFFF); // addi r4, r4, cm_80452C68@l
    gc_env.r[0] = gc_mem_read8(gc_env.ram, gc_env.r[4] + 0x399);
    uint32_t rotated = gc_env.r[3] << 0; // rlwimi r0, r3, 0, 31, 31
    gc_env.r[0] = (gc_env.r[0] & ~0x1) | (rotated & 0x1);
    gc_mem_write8(gc_env.ram, gc_env.r[4] + 0x399, gc_env.r[0]);
    return;
}

// Function: Camera_80030B24
void Camera_80030B24(void) {
    gc_env.r[3] = ((uint32_t)&cm_80452C68 >> 16) & 0xFFFF; // lis r3, cm_80452C68@ha
    gc_env.r[3] = gc_env.r[3] + ((uint32_t)&cm_80452C68 & 0xFFFF); // addi r3, r3, cm_80452C68@l
    gc_env.r[3] = gc_mem_read8(gc_env.ram, gc_env.r[3] + 0x399);
    gc_env.r[3] = gc_env.r[3] & 0x1; // clrlwi r3, r3, 31
    return;
}

// Function: Camera_80030B38
void Camera_80030B38(void) {
    gc_env.r[4] = ((uint32_t)&cm_80452C68 >> 16) & 0xFFFF; // lis r4, cm_80452C68@ha
    gc_env.r[4] = gc_env.r[4] + ((uint32_t)&cm_80452C68 & 0xFFFF); // addi r4, r4, cm_80452C68@l
    gc_env.r[0] = gc_mem_read8(gc_env.ram, gc_env.r[4] + 0x39a);
    uint32_t rotated = gc_env.r[3] << 7; // rlwimi r0, r3, 7, 24, 24
    gc_env.r[0] = (gc_env.r[0] & ~0x80) | (rotated & 0x80);
    gc_mem_write8(gc_env.ram, gc_env.r[4] + 0x39a, gc_env.r[0]);
    return;
}

// Function: Camera_80030B50
void Camera_80030B50(void) {
    gc_env.r[3] = ((uint32_t)&cm_80452C68 >> 16) & 0xFFFF; // lis r3, cm_80452C68@ha
    gc_env.r[3] = gc_env.r[3] + ((uint32_t)&cm_80452C68 & 0xFFFF); // addi r3, r3, cm_80452C68@l
    gc_env.r[3] = gc_mem_read8(gc_env.ram, gc_env.r[3] + 0x39a);
    gc_env.r[3] = (gc_env.r[3] >> 7) & 0x1; // extrwi r3, r3, 1, 24
    return;
}

// Function: Camera_80030B64
void Camera_80030B64(void) {
    gc_env.r[4] = ((uint32_t)&cm_80452C68 >> 16) & 0xFFFF; // lis r4, cm_80452C68@ha
    gc_env.r[4] = gc_env.r[4] + ((uint32_t)&cm_80452C68 & 0xFFFF); // addi r4, r4, cm_80452C68@l
    gc_env.r[0] = gc_mem_read8(gc_env.ram, gc_env.r[4] + 0x39a);
    uint32_t rotated = gc_env.r[3] << 6; // rlwimi r0, r3, 6, 25, 25
    gc_env.r[0] = (gc_env.r[0] & ~0x40) | (rotated & 0x40);
    gc_mem_write8(gc_env.ram, gc_env.r[4] + 0x39a, gc_env.r[0]);
    return;
}

// Function: Camera_80030B7C
void Camera_80030B7C(void) {
    gc_env.r[3] = ((uint32_t)&cm_80452C68 >> 16) & 0xFFFF; // lis r3, cm_80452C68@ha
    gc_env.r[3] = gc_env.r[3] + ((uint32_t)&cm_80452C68 & 0xFFFF); // addi r3, r3, cm_80452C68@l
    gc_env.r[3] = gc_mem_read8(gc_env.ram, gc_env.r[3] + 0x39a);
    gc_env.r[3] = (gc_env.r[3] >> 6) & 0x1; // extrwi r3, r3, 1, 25
    return;
}

// Function: Camera_80030B90
void Camera_80030B90(void) {
    gc_env.r[4] = ((uint32_t)&cm_80452C68 >> 16) & 0xFFFF; // lis r4, cm_80452C68@ha
    gc_env.r[4] = gc_env.r[4] + ((uint32_t)&cm_80452C68 & 0xFFFF); // addi r4, r4, cm_80452C68@l
    gc_env.r[0] = gc_mem_read8(gc_env.ram, gc_env.r[4] + 0x39a);
    uint32_t rotated = gc_env.r[3] << 5; // rlwimi r0, r3, 5, 26, 26
    gc_env.r[0] = (gc_env.r[0] & ~0x20) | (rotated & 0x20);
    gc_mem_write8(gc_env.ram, gc_env.r[4] + 0x39a, gc_env.r[0]);
    return;
}

// Function: Camera_80030BA8
void Camera_80030BA8(void) {
    gc_env.r[3] = ((uint32_t)&cm_80452C68 >> 16) & 0xFFFF; // lis r3, cm_80452C68@ha
    gc_env.r[3] = gc_env.r[3] + ((uint32_t)&cm_80452C68 & 0xFFFF); // addi r3, r3, cm_80452C68@l
    gc_env.r[3] = gc_mem_read8(gc_env.ram, gc_env.r[3] + 0x39a);
    gc_env.r[3] = (gc_env.r[3] >> 5) & 0x1; // extrwi r3, r3, 1, 26
    return;
}

// Function: Camera_80030BBC
void Camera_80030BBC(void) {
    gc_env.r[0] = gc_env.lr; // Move from link register
    gc_env.r[5] = ((uint32_t)&cm_80452C68 >> 16) & 0xFFFF; // lis r5, cm_80452C68@ha
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x4, gc_env.r[0]);
    gc_env.r[5] = gc_env.r[5] + ((uint32_t)&cm_80452C68 & 0xFFFF); // addi r5, r5, cm_80452C68@l
    gc_env.r[6] = 0x1;
    gc_mem_write32(gc_env.ram, gc_env.r[1] + -0x58, gc_env.r[1]);
    gc_env.r[1] = gc_env.r[1] + -0x58;
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x54, gc_env.r[31]);
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x50, gc_env.r[30]);
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x4c, gc_env.r[29]);
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x48, gc_env.r[28]);
    gc_env.r[28] = gc_env.r[4]; // Move register
    gc_env.r[4] = gc_env.r[3] + 0; // addi r4, r3, 0x0
    gc_env.r[5] = gc_mem_read32(gc_env.ram, gc_env.r[5] + 0x0);
    gc_env.r[31] = gc_mem_read32(gc_env.ram, gc_env.r[5] + 0x28);
    gc_env.r[5] = gc_env.r[1] + 40; // addi r5, r1, 0x28
    gc_env.r[3] = gc_env.r[31] + 0; // addi r3, r31, 0x0
    lbVector_WorldToScreen();
    gc_env.cr[0] = ((uint32_t)gc_env.r[3] == 0x0) ? 0 : ((uint32_t)gc_env.r[3] < 0x0 ? -1 : 1); // Logical compare with immediate
    if (gc_env.cr[0] != 0) goto L_80030C10;
    gc_env.r[3] = 0x0;
    goto L_80030CB8;
    L_80030C10:
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x28); // lfs f2, 0x28(r1)
    gc_env.f[2] = *(float*)&temp;
    gc_env.f[1] = cm_804D7F00; // lfs f1, cm_804D7F00@sda21(r0)
    gc_env.cr[0] = isnan(gc_env.f[2]) || isnan(gc_env.f[1]) ? 0x1 : (gc_env.f[2] < gc_env.f[1] ? 0x8 : (gc_env.f[2] > gc_env.f[1] ? 0x4 : 0x2)); // fcmpo cr0, f2, f1
    if (gc_env.cr[0] & 0x4) goto L_80030C40; // bgt .L_80030C40
    gc_env.f[0] = cm_804D7F04; // lfs f0, cm_804D7F04@sda21(r0)
    gc_env.cr[0] = isnan(gc_env.f[2]) || isnan(gc_env.f[0]) ? 0x1 : (gc_env.f[2] < gc_env.f[0] ? 0x8 : (gc_env.f[2] > gc_env.f[0] ? 0x4 : 0x2)); // fcmpo cr0, f2, f0
    if (gc_env.cr[0] & 0x8) goto L_80030C40; // blt .L_80030C40
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x2C); // lfs f3, 0x2C(r1)
    gc_env.f[3] = *(float*)&temp;
    gc_env.cr[0] = isnan(gc_env.f[3]) || isnan(gc_env.f[1]) ? 0x1 : (gc_env.f[3] < gc_env.f[1] ? 0x8 : (gc_env.f[3] > gc_env.f[1] ? 0x4 : 0x2)); // fcmpo cr0, f3, f1
    if (gc_env.cr[0] & 0x4) goto L_80030C40; // bgt .L_80030C40
    gc_env.cr[0] = isnan(gc_env.f[3]) || isnan(gc_env.f[0]) ? 0x1 : (gc_env.f[3] < gc_env.f[0] ? 0x8 : (gc_env.f[3] > gc_env.f[0] ? 0x4 : 0x2)); // fcmpo cr0, f3, f0
    if (gc_env.cr[0] >= 0) goto L_80030C48;
    L_80030C40:
    gc_env.r[3] = 0x0;
    goto L_80030CB8;
    L_80030C48:
    // Unknown opcode: fctiwz f1 f2
    gc_env.cr[0] = ((uint32_t)gc_env.r[28] == 0x0) ? 0 : ((uint32_t)gc_env.r[28] < 0x0 ? -1 : 1); // Logical compare with immediate
    // Unknown opcode: fctiwz f0 f3
    uint64_t temp;
    memcpy(&temp, &gc_env.f[1], sizeof(double));
    gc_mem_write64(gc_env.ram, gc_env.r[1] + 0x40, temp); // stfd f1, 0x40(r1)
    uint64_t temp;
    memcpy(&temp, &gc_env.f[0], sizeof(double));
    gc_mem_write64(gc_env.ram, gc_env.r[1] + 0x38, temp); // stfd f0, 0x38(r1)
    gc_env.r[30] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x44);
    gc_env.r[29] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x3c);
    if (gc_env.cr[0] == 0) goto L_80030C70;
    gc_mem_write32(gc_env.ram, gc_env.r[28] + 0x0, gc_env.r[30]);
    gc_mem_write32(gc_env.ram, gc_env.r[28] + 0x4, gc_env.r[29]);
    L_80030C70:
    gc_env.r[3] = gc_env.r[31] + 0; // addi r3, r31, 0x0
    gc_env.r[4] = gc_env.r[1] + 32; // addi r4, r1, 0x20
    HSD_CObjGetScissor();
    gc_env.r[0] = gc_mem_read16(gc_env.ram, gc_env.r[1] + 0x20);
    gc_env.cr[0] = (int32_t)gc_env.r[30] < (int32_t)gc_env.r[0] ? 0x8 : ((int32_t)gc_env.r[30] > (int32_t)gc_env.r[0] ? 0x4 : 0x2); // cmpw r30, r0
    if (gc_env.cr[0] & 0x8) goto L_80030CAC; // blt .L_80030CAC
    gc_env.r[0] = gc_mem_read16(gc_env.ram, gc_env.r[1] + 0x22);
    gc_env.cr[0] = (int32_t)gc_env.r[30] < (int32_t)gc_env.r[0] ? 0x8 : ((int32_t)gc_env.r[30] > (int32_t)gc_env.r[0] ? 0x4 : 0x2); // cmpw r30, r0
    if (gc_env.cr[0] >= 0) goto L_80030CAC;
    gc_env.r[0] = gc_mem_read16(gc_env.ram, gc_env.r[1] + 0x24);
    gc_env.cr[0] = (int32_t)gc_env.r[29] < (int32_t)gc_env.r[0] ? 0x8 : ((int32_t)gc_env.r[29] > (int32_t)gc_env.r[0] ? 0x4 : 0x2); // cmpw r29, r0
    if (gc_env.cr[0] & 0x8) goto L_80030CAC; // blt .L_80030CAC
    gc_env.r[0] = gc_mem_read16(gc_env.ram, gc_env.r[1] + 0x26);
    gc_env.cr[0] = (int32_t)gc_env.r[29] < (int32_t)gc_env.r[0] ? 0x8 : ((int32_t)gc_env.r[29] > (int32_t)gc_env.r[0] ? 0x4 : 0x2); // cmpw r29, r0
    if (gc_env.cr[0] & 0x8) goto L_80030CB4; // blt .L_80030CB4
    L_80030CAC:
    gc_env.r[3] = 0x0;
    goto L_80030CB8;
    L_80030CB4:
    gc_env.r[3] = 0x1;
    L_80030CB8:
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x5c);
    gc_env.r[31] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x54);
    gc_env.r[30] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x50);
    gc_env.r[29] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x4c);
    gc_env.r[28] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x48);
    gc_env.r[1] += 88; // addi r1, r1, 0x58
    gc_env.lr = gc_env.r[0]; // Move to link register
    return;
}

// Function: Camera_80030CD8
void Camera_80030CD8(void) {
    gc_env.r[0] = gc_env.lr; // Move from link register
    gc_env.r[3] += 28; // addi r3, r3, 0x1c
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x4, gc_env.r[0]);
    gc_mem_write32(gc_env.ram, gc_env.r[1] + -0x8, gc_env.r[1]);
    gc_env.r[1] = gc_env.r[1] + -0x8;
    Camera_80030BBC();
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0xc);
    gc_env.r[1] += 8; // addi r1, r1, 0x8
    gc_env.lr = gc_env.r[0]; // Move to link register
    return;
}

// Function: Camera_80030CFC
void Camera_80030CFC(void) {
    gc_env.r[0] = gc_env.lr; // Move from link register
    gc_env.r[4] = ((uint32_t)&cm_80452C68 >> 16) & 0xFFFF; // lis r4, cm_80452C68@ha
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x4, gc_env.r[0]);
    gc_mem_write32(gc_env.ram, gc_env.r[1] + -0x70, gc_env.r[1]);
    gc_env.r[1] = gc_env.r[1] + -0x70;
    uint64_t temp;
    memcpy(&temp, &gc_env.f[31], sizeof(double));
    gc_mem_write64(gc_env.ram, gc_env.r[1] + 0x68, temp); // stfd f31, 0x68(r1)
    gc_env.f[31] = gc_env.f[1]; // fmr f31, f1
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x64, gc_env.r[31]);
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x60, gc_env.r[30]);
    gc_env.r[30] = gc_env.r[3] + 0; // addi r30, r3, 0x0
    gc_env.r[5] = gc_mem_read32(gc_env.ram, gc_env.r[4] + cm_80452C68@l);
    gc_env.r[4] = gc_env.r[1] + 80; // addi r4, r1, 0x50
    gc_env.r[31] = gc_mem_read32(gc_env.ram, gc_env.r[5] + 0x28);
    gc_env.r[3] = gc_env.r[31]; // Move register
    HSD_CObjGetEyePosition();
    gc_env.r[3] = gc_env.r[31] + 0; // addi r3, r31, 0x0
    gc_env.r[4] = gc_env.r[1] + 68; // addi r4, r1, 0x44
    HSD_CObjGetInterest();
    gc_env.r[3] = gc_env.r[1] + 68; // addi r3, r1, 0x44
    gc_env.r[4] = gc_env.r[1] + 80; // addi r4, r1, 0x50
    gc_env.r[5] = gc_env.r[30] + 28; // addi r5, r30, 0x1c
    gc_env.r[6] = gc_env.r[1] + 56; // addi r6, r1, 0x38
    lbVector_8000E838();
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[30] + 0x3C); // lfs f0, 0x3C(r30)
    gc_env.f[0] = *(float*)&temp;
    gc_env.f[0] = (float)gc_env.f[0] + (float)gc_env.f[31]; // fadds f0, f0, f31
    gc_env.cr[0] = isnan(gc_env.f[1]) || isnan(gc_env.f[0]) ? 0x1 : (gc_env.f[1] < gc_env.f[0] ? 0x8 : (gc_env.f[1] > gc_env.f[0] ? 0x4 : 0x2)); // fcmpo cr0, f1, f0
    if (gc_env.cr[0] >= 0) goto L_80030D6C;
    gc_env.r[3] = 0x1;
    goto L_80030DC8;
    L_80030D6C:
    gc_env.r[3] = gc_env.r[1] + 56; // addi r3, r1, 0x38
    gc_env.r[4] = gc_env.r[30] + 28; // addi r4, r30, 0x1c
    gc_env.r[5] = gc_env.r[1] + 32; // addi r5, r1, 0x20
    lbVector_Diff();
    gc_env.r[3] = gc_env.r[1] + 32; // addi r3, r1, 0x20
    lbVector_Normalize();
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[30] + 0x3C); // lfs f1, 0x3C(r30)
    gc_env.f[1] = *(float*)&temp;
    gc_env.r[3] = gc_env.r[1] + 32; // addi r3, r1, 0x20
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x20); // lfs f0, 0x20(r1)
    gc_env.f[0] = *(float*)&temp;
    gc_env.r[4] = gc_env.r[30] + 28; // addi r4, r30, 0x1c
    gc_env.f[1] = (float)gc_env.f[1] + (float)gc_env.f[31]; // fadds f1, f1, f31
    gc_env.f[0] = (float)gc_env.f[0] * (float)gc_env.f[1]; // fmuls f0, f0, f1
    float temp = (float)gc_env.f[0]; // stfs f0, 0x20(r1)
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x20, *(uint32_t*)&temp);
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x24); // lfs f0, 0x24(r1)
    gc_env.f[0] = *(float*)&temp;
    gc_env.f[0] = (float)gc_env.f[0] * (float)gc_env.f[1]; // fmuls f0, f0, f1
    float temp = (float)gc_env.f[0]; // stfs f0, 0x24(r1)
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x24, *(uint32_t*)&temp);
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x28); // lfs f0, 0x28(r1)
    gc_env.f[0] = *(float*)&temp;
    gc_env.f[0] = (float)gc_env.f[0] * (float)gc_env.f[1]; // fmuls f0, f0, f1
    float temp = (float)gc_env.f[0]; // stfs f0, 0x28(r1)
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x28, *(uint32_t*)&temp);
    lbVector_Add();
    gc_env.r[3] = gc_env.r[1] + 32; // addi r3, r1, 0x20
    gc_env.r[4] = 0x0;
    Camera_80030BBC();
    L_80030DC8:
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x74);
    uint64_t temp = gc_mem_read64(gc_env.ram, gc_env.r[1] + 0x68); // lfd f31, 0x68(r1)
    gc_env.d[31] = *(double*)&temp;
    gc_env.r[31] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x64);
    gc_env.r[30] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x60);
    gc_env.r[1] += 112; // addi r1, r1, 0x70
    gc_env.lr = gc_env.r[0]; // Move to link register
    return;
}

// Function: Camera_80030DE4
void Camera_80030DE4(void) {
    gc_env.r[3] = ((uint32_t)&cm_80452C68 >> 16) & 0xFFFF; // lis r3, cm_80452C68@ha
    gc_env.r[3] = gc_env.r[3] + ((uint32_t)&cm_80452C68 & 0xFFFF); // addi r3, r3, cm_80452C68@l
    float temp = (float)gc_env.f[1]; // stfs f1, 0x84(r3)
    gc_mem_write32(gc_env.ram, gc_env.r[3] + 0x84, *(uint32_t*)&temp);
    float temp = (float)gc_env.f[2]; // stfs f2, 0x88(r3)
    gc_mem_write32(gc_env.ram, gc_env.r[3] + 0x88, *(uint32_t*)&temp);
    return;
}

// Function: Camera_80030DF8
void Camera_80030DF8(void) {
    gc_env.r[3] = ((uint32_t)&cm_80452C68 >> 16) & 0xFFFF; // lis r3, cm_80452C68@ha
    gc_env.f[0] = cm_804D7E14; // lfs f0, cm_804D7E14@sda21(r0)
    gc_env.r[3] = gc_env.r[3] + ((uint32_t)&cm_80452C68 & 0xFFFF); // addi r3, r3, cm_80452C68@l
    float temp = (float)gc_env.f[0]; // stfs f0, 0x88(r3)
    gc_mem_write32(gc_env.ram, gc_env.r[3] + 0x88, *(uint32_t*)&temp);
    float temp = (float)gc_env.f[0]; // stfs f0, 0x84(r3)
    gc_mem_write32(gc_env.ram, gc_env.r[3] + 0x84, *(uint32_t*)&temp);
    return;
}

// Function: Camera_80030E10
void Camera_80030E10(void) {
    gc_env.r[3] = ((uint32_t)&cm_80452C68 >> 16) & 0xFFFF; // lis r3, cm_80452C68@ha
    gc_env.r[3] = gc_env.r[3] + ((uint32_t)&cm_80452C68 & 0xFFFF); // addi r3, r3, cm_80452C68@l
    gc_env.r[0] = (int32_t)(int16_t)gc_mem_read16(gc_env.ram, gc_env.r[3] + 0x2B8); // lha r0, 0x2B8(r3)
    gc_env.cr[0] = (gc_env.r[0] == 0x1) ? 0 : (gc_env.r[0] < 0x1 ? -1 : 1); // Compare with immediate
    if (gc_env.cr[0] >= 0) goto L_80030E2C;
    gc_env.f[1] = cm_804D7F08; // lfs f1, cm_804D7F08@sda21(r0)
    return;
    L_80030E2C:
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[3] + 0x2B0); // lfs f1, 0x2B0(r3)
    gc_env.f[1] = *(float*)&temp;
    return;
}

// Function: Camera_80030E34
void Camera_80030E34(void) {
    gc_env.r[3] = ((uint32_t)&cm_80452C68 >> 16) & 0xFFFF; // lis r3, cm_80452C68@ha
    gc_env.r[3] = gc_env.r[3] + ((uint32_t)&cm_80452C68 & 0xFFFF); // addi r3, r3, cm_80452C68@l
    float temp = (float)gc_env.f[1]; // stfs f1, 0xAC(r3)
    gc_mem_write32(gc_env.ram, gc_env.r[3] + 0xAC, *(uint32_t*)&temp);
    return;
}

// Function: Camera_80030E44
void Camera_80030E44(void) {
    gc_env.r[0] = gc_env.lr; // Move from link register
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x4, gc_env.r[0]);
    gc_mem_write32(gc_env.ram, gc_env.r[1] + -0x20, gc_env.r[1]);
    gc_env.r[1] = gc_env.r[1] + -0x20;
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x1c, gc_env.r[31]);
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x18, gc_env.r[30]);
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x14, gc_env.r[29]);
    gc_env.r[29] = gc_env.r[4] + 0; // addi r29, r4, 0x0
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x10, gc_env.r[28]);
    gc_env.r[28] = gc_env.r[3] + 0; // addi r28, r3, 0x0
    gc_env.cr[0] = (gc_env.r[28] == 0x3) ? 0 : (gc_env.r[28] < 0x3 ? -1 : 1); // Compare with immediate
    gc_env.r[3] = ((uint32_t)&cm_80452C68 >> 16) & 0xFFFF; // lis r3, cm_80452C68@ha
    gc_env.r[31] = gc_env.r[3] + ((uint32_t)&cm_80452C68 & 0xFFFF); // addi r31, r3, cm_80452C68@l
    if (gc_env.cr[0] == 0) goto L_80030ECC;
    if (gc_env.cr[0] >= 0) goto L_80030E8C;
    gc_env.cr[0] = (gc_env.r[28] == 0x1) ? 0 : (gc_env.r[28] < 0x1 ? -1 : 1); // Compare with immediate
    if (gc_env.cr[0] == 0) goto L_80030E98;
    if (gc_env.cr[0] >= 0) goto L_80030EBC;
    goto L_80030EE8;
    L_80030E8C:
    gc_env.cr[0] = (gc_env.r[28] == 0x5) ? 0 : (gc_env.r[28] < 0x5 ? -1 : 1); // Compare with immediate
    if (gc_env.cr[0] >= 0) goto L_80030EE8;
    goto L_80030EDC;
    L_80030E98:
    gc_env.r[30] = gc_env.r[31] + 160; // addi r30, r31, 0xa0
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[31] + 0xa0);
    gc_env.cr[0] = ((uint32_t)gc_env.r[0] == 0x0) ? 0 : ((uint32_t)gc_env.r[0] < 0x0 ? -1 : 1); // Logical compare with immediate
    if (gc_env.cr[0] != 0) goto L_80030EB4;
    gc_env.r[3] = gc_env.r[28]; // Move register
    grLib_801C9CEC();
    gc_mem_write32(gc_env.ram, gc_env.r[30] + 0x0, gc_env.r[3]);
    L_80030EB4:
    gc_env.r[4] = 0xa;
    goto L_80030EE8;
    L_80030EBC:
    gc_env.r[3] = gc_env.r[28]; // Move register
    grLib_801C9CEC();
    gc_env.r[4] = 0x16;
    goto L_80030EE8;
    L_80030ECC:
    gc_env.r[3] = gc_env.r[28]; // Move register
    grLib_801C9CEC();
    gc_env.r[4] = 0x16;
    goto L_80030EE8;
    L_80030EDC:
    gc_env.r[3] = gc_env.r[28]; // Move register
    grLib_801C9CEC();
    gc_env.r[4] = 0x16;
    L_80030EE8:
    gc_env.r[0] = gc_env.r[28] << 2; // slwi r0, r28, 2
    gc_env.r[3] = gc_env.r[31] + gc_env.r[0];
    gc_mem_write32(gc_env.ram, gc_env.r[3] + 0x8c, gc_env.r[4]);
    gc_env.r[0] = 0x4;
    gc_env.ctr = gc_env.r[0]; // Move to count register
    gc_env.r[4] = 0x0;
    gc_env.f[0] = cm_804D7E14; // lfs f0, cm_804D7E14@sda21(r0)
    L_80030F04:
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[31] + 0xbc);
    gc_env.cr[0] = (gc_env.r[0] == 0x0) ? 0 : (gc_env.r[0] < 0x0 ? -1 : 1); // Compare with immediate
    if (gc_env.cr[0] != 0) goto L_80030F44;
    gc_env.cr[0] = ((uint32_t)gc_env.r[29] == 0x0) ? 0 : ((uint32_t)gc_env.r[29] < 0x0 ? -1 : 1); // Logical compare with immediate
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0xbc, gc_env.r[28]);
    if (gc_env.cr[0] == 0) goto L_80030F38;
    gc_env.r[3] = gc_mem_read32(gc_env.ram, gc_env.r[29] + 0x0);
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[29] + 0x4);
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0xb0, gc_env.r[3]);
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0xb4, gc_env.r[0]);
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[29] + 0x8);
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0xb8, gc_env.r[0]);
    goto L_80030F44;
    L_80030F38:
    float temp = (float)gc_env.f[0]; // stfs f0, 0xB8(r31)
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0xB8, *(uint32_t*)&temp);
    float temp = (float)gc_env.f[0]; // stfs f0, 0xB4(r31)
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0xB4, *(uint32_t*)&temp);
    float temp = (float)gc_env.f[0]; // stfs f0, 0xB0(r31)
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0xB0, *(uint32_t*)&temp);
    L_80030F44:
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[31] + 0xcc);
    gc_env.r[31] += 16; // addi r31, r31, 0x10
    gc_env.cr[0] = (gc_env.r[0] == 0x0) ? 0 : (gc_env.r[0] < 0x0 ? -1 : 1); // Compare with immediate
    if (gc_env.cr[0] != 0) goto L_80030F88;
    gc_env.cr[0] = ((uint32_t)gc_env.r[29] == 0x0) ? 0 : ((uint32_t)gc_env.r[29] < 0x0 ? -1 : 1); // Logical compare with immediate
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0xbc, gc_env.r[28]);
    if (gc_env.cr[0] == 0) goto L_80030F7C;
    gc_env.r[3] = gc_mem_read32(gc_env.ram, gc_env.r[29] + 0x0);
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[29] + 0x4);
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0xb0, gc_env.r[3]);
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0xb4, gc_env.r[0]);
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[29] + 0x8);
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0xb8, gc_env.r[0]);
    goto L_80030F88;
    L_80030F7C:
    float temp = (float)gc_env.f[0]; // stfs f0, 0xB8(r31)
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0xB8, *(uint32_t*)&temp);
    float temp = (float)gc_env.f[0]; // stfs f0, 0xB4(r31)
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0xB4, *(uint32_t*)&temp);
    float temp = (float)gc_env.f[0]; // stfs f0, 0xB0(r31)
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0xB0, *(uint32_t*)&temp);
    L_80030F88:
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[31] + 0xcc);
    gc_env.r[31] += 16; // addi r31, r31, 0x10
    gc_env.r[4] += 1; // addi r4, r4, 0x1
    gc_env.cr[0] = (gc_env.r[0] == 0x0) ? 0 : (gc_env.r[0] < 0x0 ? -1 : 1); // Compare with immediate
    if (gc_env.cr[0] != 0) goto L_80030FD0;
    gc_env.cr[0] = ((uint32_t)gc_env.r[29] == 0x0) ? 0 : ((uint32_t)gc_env.r[29] < 0x0 ? -1 : 1); // Logical compare with immediate
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0xbc, gc_env.r[28]);
    if (gc_env.cr[0] == 0) goto L_80030FC4;
    gc_env.r[3] = gc_mem_read32(gc_env.ram, gc_env.r[29] + 0x0);
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[29] + 0x4);
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0xb0, gc_env.r[3]);
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0xb4, gc_env.r[0]);
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[29] + 0x8);
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0xb8, gc_env.r[0]);
    goto L_80030FD0;
    L_80030FC4:
    float temp = (float)gc_env.f[0]; // stfs f0, 0xB8(r31)
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0xB8, *(uint32_t*)&temp);
    float temp = (float)gc_env.f[0]; // stfs f0, 0xB4(r31)
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0xB4, *(uint32_t*)&temp);
    float temp = (float)gc_env.f[0]; // stfs f0, 0xB0(r31)
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0xB0, *(uint32_t*)&temp);
    L_80030FD0:
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[31] + 0xcc);
    gc_env.r[31] += 16; // addi r31, r31, 0x10
    gc_env.r[4] += 1; // addi r4, r4, 0x1
    gc_env.cr[0] = (gc_env.r[0] == 0x0) ? 0 : (gc_env.r[0] < 0x0 ? -1 : 1); // Compare with immediate
    if (gc_env.cr[0] != 0) goto L_80031018;
    gc_env.cr[0] = ((uint32_t)gc_env.r[29] == 0x0) ? 0 : ((uint32_t)gc_env.r[29] < 0x0 ? -1 : 1); // Logical compare with immediate
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0xbc, gc_env.r[28]);
    if (gc_env.cr[0] == 0) goto L_8003100C;
    gc_env.r[3] = gc_mem_read32(gc_env.ram, gc_env.r[29] + 0x0);
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[29] + 0x4);
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0xb0, gc_env.r[3]);
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0xb4, gc_env.r[0]);
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[29] + 0x8);
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0xb8, gc_env.r[0]);
    goto L_80031018;
    L_8003100C:
    float temp = (float)gc_env.f[0]; // stfs f0, 0xB8(r31)
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0xB8, *(uint32_t*)&temp);
    float temp = (float)gc_env.f[0]; // stfs f0, 0xB4(r31)
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0xB4, *(uint32_t*)&temp);
    float temp = (float)gc_env.f[0]; // stfs f0, 0xB0(r31)
    gc_mem_write32(gc_env.ram, gc_env.r[31] + 0xB0, *(uint32_t*)&temp);
    L_80031018:
    gc_env.r[31] += 16; // addi r31, r31, 0x10
    gc_env.r[4] += 1; // addi r4, r4, 0x1
    gc_env.ctr -= 1;
    if (gc_env.ctr != 0) goto L_80030F04;
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x24);
    gc_env.r[31] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x1c);
    gc_env.r[30] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x18);
    gc_env.r[29] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x14);
    gc_env.r[28] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x10);
    gc_env.r[1] += 32; // addi r1, r1, 0x20
    gc_env.lr = gc_env.r[0]; // Move to link register
    return;
}

// Function: Camera_80031044
void Camera_80031044(void) {
    gc_env.r[4] = ((uint32_t)&cm_80452C68 >> 16) & 0xFFFF; // lis r4, cm_80452C68@ha
    gc_env.r[4] = gc_env.r[4] + ((uint32_t)&cm_80452C68 & 0xFFFF); // addi r4, r4, cm_80452C68@l
    gc_env.r[0] = gc_env.r[3] << 2; // slwi r0, r3, 2
    gc_env.r[3] = gc_env.r[4] + gc_env.r[0];
    gc_env.r[0] = 0x0;
    gc_mem_write32(gc_env.ram, gc_env.r[3] + 0x8c, gc_env.r[0]);
    return;
}

// Function: Camera_80031060
void Camera_80031060(void) {
    gc_env.r[3] = ((uint32_t)&cm_80452C68 >> 16) & 0xFFFF; // lis r3, cm_80452C68@ha
    gc_env.r[3] = gc_env.r[3] + ((uint32_t)&cm_80452C68 & 0xFFFF); // addi r3, r3, cm_80452C68@l
    gc_env.r[3] = gc_mem_read8(gc_env.ram, gc_env.r[3] + 0x398);
    gc_env.r[3] = gc_env.r[3] & 0x3; // clrlwi r3, r3, 30
    return;
}

// Function: Camera_80031074
void Camera_80031074(void) {
    gc_env.r[4] = ((uint32_t)&cm_80452C68 >> 16) & 0xFFFF; // lis r4, cm_80452C68@ha
    gc_env.r[4] = gc_env.r[4] + ((uint32_t)&cm_80452C68 & 0xFFFF); // addi r4, r4, cm_80452C68@l
    gc_env.r[0] = gc_mem_read8(gc_env.ram, gc_env.r[4] + 0x398);
    uint32_t rotated = gc_env.r[3] << 0; // rlwimi r0, r3, 0, 30, 31
    gc_env.r[0] = (gc_env.r[0] & ~0x3) | (rotated & 0x3);
    gc_mem_write8(gc_env.ram, gc_env.r[4] + 0x398, gc_env.r[0]);
    return;
}

// Function: Camera_8003108C
void Camera_8003108C(void) {
    gc_env.r[3] = ((uint32_t)&cm_80452C68 >> 16) & 0xFFFF; // lis r3, cm_80452C68@ha
    gc_env.r[3] = gc_env.r[3] + ((uint32_t)&cm_80452C68 & 0xFFFF); // addi r3, r3, cm_80452C68@l
    gc_env.r[3] = gc_mem_read8(gc_env.ram, gc_env.r[3] + 0x399);
    gc_env.r[3] = (gc_env.r[3] >> 6) & 0x3; // extrwi r3, r3, 2, 24
    return;
}

// Function: Camera_800310A0
void Camera_800310A0(void) {
    gc_env.r[4] = ((uint32_t)&cm_80452C68 >> 16) & 0xFFFF; // lis r4, cm_80452C68@ha
    gc_env.r[4] = gc_env.r[4] + ((uint32_t)&cm_80452C68 & 0xFFFF); // addi r4, r4, cm_80452C68@l
    gc_env.r[0] = gc_mem_read8(gc_env.ram, gc_env.r[4] + 0x399);
    uint32_t rotated = gc_env.r[3] << 6; // rlwimi r0, r3, 6, 24, 25
    gc_env.r[0] = (gc_env.r[0] & ~0xC0) | (rotated & 0xC0);
    gc_mem_write8(gc_env.ram, gc_env.r[4] + 0x399, gc_env.r[0]);
    return;
}

// Function: Camera_800310B8
void Camera_800310B8(void) {
    gc_env.r[0] = gc_env.lr; // Move from link register
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x4, gc_env.r[0]);
    gc_mem_write32(gc_env.ram, gc_env.r[1] + -0x8, gc_env.r[1]);
    gc_env.r[1] = gc_env.r[1] + -0x8;
    gc_env.r[3] = gc_mem_read32(gc_env.ram, gc_env.r[0] + cm_804D6464@sda21);
    HSD_CObjSetMtxDirty();
    gc_env.r[3] = gc_mem_read32(gc_env.ram, gc_env.r[0] + cm_804D6464@sda21);
    HSD_CObjSetupViewingMtx();
    gc_env.r[3] = gc_mem_read32(gc_env.ram, gc_env.r[0] + cm_804D6464@sda21);
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0xc);
    gc_env.r[1] += 8; // addi r1, r1, 0x8
    gc_env.lr = gc_env.r[0]; // Move to link register
    return;
}

// Function: Camera_800310E8
void Camera_800310E8(void) {
    gc_env.r[3] = ((uint32_t)&cm_80452C68 >> 16) & 0xFFFF; // lis r3, cm_80452C68@ha
    gc_env.r[3] = gc_env.r[3] + ((uint32_t)&cm_80452C68 & 0xFFFF); // addi r3, r3, cm_80452C68@l
    gc_env.r[4] = gc_env.r[3] + 920; // addi r4, r3, 0x398
    gc_env.r[0] = gc_mem_read8(gc_env.ram, gc_env.r[3] + 0x398);
    gc_env.r[3] = 0x0;
    uint32_t rotated = gc_env.r[3] << 7; // rlwimi r0, r3, 7, 24, 24
    gc_env.r[0] = (gc_env.r[0] & ~0x80) | (rotated & 0x80);
    gc_mem_write8(gc_env.ram, gc_env.r[4] + 0x0, gc_env.r[0]);
    gc_env.r[0] = gc_mem_read8(gc_env.ram, gc_env.r[4] + 0x0);
    uint32_t rotated = gc_env.r[3] << 6; // rlwimi r0, r3, 6, 25, 25
    gc_env.r[0] = (gc_env.r[0] & ~0x40) | (rotated & 0x40);
    gc_mem_write8(gc_env.ram, gc_env.r[4] + 0x0, gc_env.r[0]);
    gc_env.r[0] = gc_mem_read8(gc_env.ram, gc_env.r[4] + 0x0);
    uint32_t rotated = gc_env.r[3] << 5; // rlwimi r0, r3, 5, 26, 26
    gc_env.r[0] = (gc_env.r[0] & ~0x20) | (rotated & 0x20);
    gc_mem_write8(gc_env.ram, gc_env.r[4] + 0x0, gc_env.r[0]);
    gc_env.r[0] = gc_mem_read8(gc_env.ram, gc_env.r[4] + 0x0);
    uint32_t rotated = gc_env.r[3] << 4; // rlwimi r0, r3, 4, 27, 27
    gc_env.r[0] = (gc_env.r[0] & ~0x10) | (rotated & 0x10);
    gc_mem_write8(gc_env.ram, gc_env.r[4] + 0x0, gc_env.r[0]);
    gc_env.r[0] = gc_mem_read8(gc_env.ram, gc_env.r[4] + 0x0);
    uint32_t rotated = gc_env.r[3] << 3; // rlwimi r0, r3, 3, 28, 28
    gc_env.r[0] = (gc_env.r[0] & ~0x8) | (rotated & 0x8);
    gc_mem_write8(gc_env.ram, gc_env.r[4] + 0x0, gc_env.r[0]);
    gc_env.r[0] = gc_mem_read8(gc_env.ram, gc_env.r[4] + 0x0);
    uint32_t rotated = gc_env.r[3] << 2; // rlwimi r0, r3, 2, 29, 29
    gc_env.r[0] = (gc_env.r[0] & ~0x4) | (rotated & 0x4);
    gc_mem_write8(gc_env.ram, gc_env.r[4] + 0x0, gc_env.r[0]);
    return;
}

// Function: Camera_80031144
void Camera_80031144(void) {
    gc_env.r[3] = ((uint32_t)&cm_80452C68 >> 16) & 0xFFFF; // lis r3, cm_80452C68@ha
    gc_env.r[3] = gc_env.r[3] + ((uint32_t)&cm_80452C68 & 0xFFFF); // addi r3, r3, cm_80452C68@l
    uint32_t temp = gc_mem_read32(gc_env.ram, gc_env.r[3] + 0x2BC); // lfs f1, 0x2BC(r3)
    gc_env.f[1] = *(float*)&temp;
    return;
}

// Function: Camera_80031154
void Camera_80031154(void) {
    gc_env.r[0] = gc_env.lr; // Move from link register
    gc_env.r[4] = 0x0;
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x4, gc_env.r[0]);
    gc_mem_write32(gc_env.ram, gc_env.r[1] + -0x8, gc_env.r[1]);
    gc_env.r[1] = gc_env.r[1] + -0x8;
    Camera_80029124();
    gc_env.cr[0] = ((uint32_t)gc_env.r[3] == 0x0) ? 0 : ((uint32_t)gc_env.r[3] < 0x0 ? -1 : 1); // Logical compare with immediate
    if (gc_env.cr[0] != 0) goto L_80031178;
    gc_env.r[3] = 0x1;
    goto L_8003117C;
    L_80031178:
    gc_env.r[3] = 0x0;
    L_8003117C:
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0xc);
    gc_env.r[1] += 8; // addi r1, r1, 0x8
    gc_env.lr = gc_env.r[0]; // Move to link register
    return;
}

// Function: Camera_8003118C
void Camera_8003118C(void) {
    gc_env.r[0] = gc_env.lr; // Move from link register
    // Unknown opcode: fctiwz f0 f1
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x4, gc_env.r[0]);
    gc_mem_write32(gc_env.ram, gc_env.r[1] + -0x18, gc_env.r[1]);
    gc_env.r[1] = gc_env.r[1] + -0x18;
    uint64_t temp;
    memcpy(&temp, &gc_env.f[0], sizeof(double));
    gc_mem_write64(gc_env.ram, gc_env.r[1] + 0x10, temp); // stfd f0, 0x10(r1)
    gc_env.r[4] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x14);
    Camera_80029124();
    gc_env.cr[0] = ((uint32_t)gc_env.r[3] == 0x0) ? 0 : ((uint32_t)gc_env.r[3] < 0x0 ? -1 : 1); // Logical compare with immediate
    if (gc_env.cr[0] != 0) goto L_800311B8;
    gc_env.r[3] = 0x1;
    goto L_800311BC;
    L_800311B8:
    gc_env.r[3] = 0x0;
    L_800311BC:
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x1c);
    gc_env.r[1] += 24; // addi r1, r1, 0x18
    gc_env.lr = gc_env.r[0]; // Move to link register
    return;
}

// Function: Camera_800311CC
void Camera_800311CC(void) {
    gc_env.r[3] = ((uint32_t)&cm_80452C68 >> 16) & 0xFFFF; // lis r3, cm_80452C68@ha
    gc_env.r[3] = gc_env.r[3] + ((uint32_t)&cm_80452C68 & 0xFFFF); // addi r3, r3, cm_80452C68@l
    float temp = (float)gc_env.f[1]; // stfs f1, 0x10(r3)
    gc_mem_write32(gc_env.ram, gc_env.r[3] + 0x10, *(uint32_t*)&temp);
    return;
}

// Function: Camera_800311DC
void Camera_800311DC(void) {
    gc_env.r[3] = ((uint32_t)&cm_80452C68 >> 16) & 0xFFFF; // lis r3, cm_80452C68@ha
    gc_env.r[3] = gc_env.r[3] + ((uint32_t)&cm_80452C68 & 0xFFFF); // addi r3, r3, cm_80452C68@l
    float temp = (float)gc_env.f[1]; // stfs f1, 0xC(r3)
    gc_mem_write32(gc_env.ram, gc_env.r[3] + 0xC, *(uint32_t*)&temp);
    return;
}

// Function: Camera_800311EC
void Camera_800311EC(void) {
    gc_env.r[0] = gc_env.lr; // Move from link register
    gc_env.r[4] = ((uint32_t)&cm_80452C68 >> 16) & 0xFFFF; // lis r4, cm_80452C68@ha
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x4, gc_env.r[0]);
    gc_env.r[4] = gc_env.r[4] + ((uint32_t)&cm_80452C68 & 0xFFFF); // addi r4, r4, cm_80452C68@l
    gc_mem_write32(gc_env.ram, gc_env.r[1] + -0x30, gc_env.r[1]);
    gc_env.r[1] = gc_env.r[1] + -0x30;
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x2c, gc_env.r[31]);
    gc_env.r[31] = gc_env.r[4] + 920; // addi r31, r4, 0x398
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x28, gc_env.r[30]);
    gc_env.r[30] = gc_env.r[3]; // Move register
    gc_env.r[0] = gc_mem_read8(gc_env.ram, gc_env.r[4] + 0x398);
    gc_env.r[4] = 0x1;
    uint32_t rotated = gc_env.r[4] << 0; // rlwimi r0, r4, 0, 30, 31
    gc_env.r[0] = (gc_env.r[0] & ~0x3) | (rotated & 0x3);
    gc_mem_write8(gc_env.ram, gc_env.r[31] + 0x0, gc_env.r[0]);
    gc_env.r[0] = gc_mem_read8(gc_env.ram, gc_env.r[31] + 0x0);
    gc_env.r[0] = (gc_env.r[0] >> 6) & 0x1; // extrwi r0, r0, 1, 25
    gc_env.cr[0] = (gc_env.r[0] == 0) ? 0x2 : ((int32_t)gc_env.r[0] < 0 ? 0x8 : 0x4);
    if (gc_env.cr[0] == 0) goto L_80031238;
    gc_env.r[3] = 0x0;
    gc_env.r[4] = gc_env.r[3] + 0; // addi r4, r3, 0x0
    goto L_80031240;
    L_80031238:
    gc_env.r[3] = 0x40;
    gc_env.r[4] = 0x0;
    L_80031240:
    gc_env.r[0] = gc_mem_read8(gc_env.ram, gc_env.r[31] + 0x0);
    gc_env.r[0] = (gc_env.r[0] >> 7) & 0x1; // extrwi r0, r0, 1, 24
    gc_env.cr[0] = (gc_env.r[0] == 0) ? 0x2 : ((int32_t)gc_env.r[0] < 0 ? 0x8 : 0x4);
    if (gc_env.cr[0] == 0) goto L_80031258;
    gc_env.r[0] = 0x0;
    gc_env.r[7] = gc_env.r[0]; // Move register
    goto L_80031260;
    L_80031258:
    gc_env.r[0] = 0x20;
    gc_env.r[7] = 0x0;
    L_80031260:
    gc_env.r[0] = gc_env.r[6] | gc_env.r[0]; // or r0, r6, r0
    gc_env.r[0] = gc_env.r[0] | gc_env.r[3]; // or r0, r0, r3
    gc_env.r[3] = gc_env.r[5] | gc_env.r[7]; // or r3, r5, r7
    gc_mem_write32(gc_env.ram, gc_env.r[30] + 0x24, gc_env.r[0]);
    gc_env.r[0] = gc_env.r[3] | gc_env.r[4]; // or r0, r3, r4
    gc_mem_write32(gc_env.ram, gc_env.r[30] + 0x20, gc_env.r[0]);
    gc_env.r[3] = gc_env.r[30] + 0; // addi r3, r30, 0x0
    gc_env.r[4] = 0x3;
    HSD_GObj_80390ED0();
    gc_env.r[0] = gc_mem_read8(gc_env.ram, gc_env.r[31] + 0x0);
    gc_env.r[3] = 0x0;
    uint32_t rotated = gc_env.r[3] << 0; // rlwimi r0, r3, 0, 30, 31
    gc_env.r[0] = (gc_env.r[0] & ~0x3) | (rotated & 0x3);
    gc_mem_write8(gc_env.ram, gc_env.r[31] + 0x0, gc_env.r[0]);
    gc_env.r[0] = gc_mem_read8(gc_env.ram, gc_env.r[31] + 0x0);
    gc_env.r[0] = (gc_env.r[0] >> 7) & 0x1; // extrwi r0, r0, 1, 24
    gc_env.cr[0] = (gc_env.r[0] == 0) ? 0x2 : ((int32_t)gc_env.r[0] < 0 ? 0x8 : 0x4);
    if (gc_env.cr[0] == 0) goto L_800312A8;
    gc_env.r[4] = gc_env.r[3]; // Move register
    goto L_800312AC;
    L_800312A8:
    gc_env.r[4] = 0x20;
    L_800312AC:
    gc_env.r[0] = gc_mem_read8(gc_env.ram, gc_env.r[31] + 0x0);
    gc_env.r[0] = (gc_env.r[0] >> 3) & 0x1; // extrwi r0, r0, 1, 28
    gc_env.cr[0] = (gc_env.r[0] == 0) ? 0x2 : ((int32_t)gc_env.r[0] < 0 ? 0x8 : 0x4);
    if (gc_env.cr[0] == 0) goto L_800312C4;
    gc_env.r[6] = 0x0;
    gc_env.r[5] = gc_env.r[6] + 0; // addi r5, r6, 0x0
    goto L_800312CC;
    L_800312C4:
    gc_env.r[6] = 0x10;
    gc_env.r[5] = 0x0;
    L_800312CC:
    gc_env.r[0] = gc_mem_read8(gc_env.ram, gc_env.r[31] + 0x0);
    gc_env.r[0] = (gc_env.r[0] >> 6) & 0x1; // extrwi r0, r0, 1, 25
    gc_env.cr[0] = (gc_env.r[0] == 0) ? 0x2 : ((int32_t)gc_env.r[0] < 0 ? 0x8 : 0x4);
    if (gc_env.cr[0] == 0) goto L_800312E4;
    gc_env.r[8] = 0x0;
    gc_env.r[7] = gc_env.r[8] + 0; // addi r7, r8, 0x0
    goto L_800312EC;
    L_800312E4:
    gc_env.r[8] = 0x40;
    gc_env.r[7] = 0x0;
    L_800312EC:
    gc_env.r[0] = gc_env.r[6] | gc_env.r[4]; // or r0, r6, r4
    gc_env.r[0] = gc_env.r[8] | gc_env.r[0]; // or r0, r8, r0
    gc_env.r[3] = gc_env.r[5] | gc_env.r[3]; // or r3, r5, r3
    gc_mem_write32(gc_env.ram, gc_env.r[30] + 0x24, gc_env.r[0]);
    gc_env.r[0] = gc_env.r[7] | gc_env.r[3]; // or r0, r7, r3
    gc_mem_write32(gc_env.ram, gc_env.r[30] + 0x20, gc_env.r[0]);
    gc_env.r[3] = gc_env.r[30] + 0; // addi r3, r30, 0x0
    gc_env.r[4] = 0x3;
    HSD_GObj_80390ED0();
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x34);
    gc_env.r[31] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x2c);
    gc_env.r[30] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x28);
    gc_env.r[1] += 48; // addi r1, r1, 0x30
    gc_env.lr = gc_env.r[0]; // Move to link register
    return;
}

// Function: Camera_80031328
void Camera_80031328(void) {
    gc_env.r[0] = gc_env.lr; // Move from link register
    gc_env.r[4] = ((uint32_t)&cm_80452C68 >> 16) & 0xFFFF; // lis r4, cm_80452C68@ha
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x4, gc_env.r[0]);
    gc_env.r[4] = gc_env.r[4] + ((uint32_t)&cm_80452C68 & 0xFFFF); // addi r4, r4, cm_80452C68@l
    gc_env.r[7] = 0x0;
    gc_mem_write32(gc_env.ram, gc_env.r[1] + -0x8, gc_env.r[1]);
    gc_env.r[1] = gc_env.r[1] + -0x8;
    gc_env.r[10] = gc_env.r[4] + 920; // addi r10, r4, 0x398
    gc_env.r[0] = gc_mem_read8(gc_env.ram, gc_env.r[4] + 0x398);
    uint32_t rotated = gc_env.r[7] << 0; // rlwimi r0, r7, 0, 30, 31
    gc_env.r[0] = (gc_env.r[0] & ~0x3) | (rotated & 0x3);
    gc_mem_write8(gc_env.ram, gc_env.r[4] + 0x398, gc_env.r[0]);
    gc_env.r[0] = gc_mem_read8(gc_env.ram, gc_env.r[4] + 0x398);
    gc_env.r[0] = (gc_env.r[0] >> 7) & 0x1; // extrwi r0, r0, 1, 24
    gc_env.cr[0] = (gc_env.r[0] == 0) ? 0x2 : ((int32_t)gc_env.r[0] < 0 ? 0x8 : 0x4);
    if (gc_env.cr[0] == 0) goto L_80031364;
    gc_env.r[4] = gc_env.r[7]; // Move register
    goto L_80031368;
    L_80031364:
    gc_env.r[4] = 0x20;
    L_80031368:
    gc_env.r[0] = gc_mem_read8(gc_env.ram, gc_env.r[10] + 0x0);
    gc_env.r[0] = (gc_env.r[0] >> 3) & 0x1; // extrwi r0, r0, 1, 28
    gc_env.cr[0] = (gc_env.r[0] == 0) ? 0x2 : ((int32_t)gc_env.r[0] < 0 ? 0x8 : 0x4);
    if (gc_env.cr[0] == 0) goto L_80031380;
    gc_env.r[9] = 0x0;
    gc_env.r[8] = gc_env.r[9] + 0; // addi r8, r9, 0x0
    goto L_80031388;
    L_80031380:
    gc_env.r[9] = 0x10;
    gc_env.r[8] = 0x0;
    L_80031388:
    gc_env.r[0] = gc_mem_read8(gc_env.ram, gc_env.r[10] + 0x0);
    gc_env.r[0] = (gc_env.r[0] >> 6) & 0x1; // extrwi r0, r0, 1, 25
    gc_env.cr[0] = (gc_env.r[0] == 0) ? 0x2 : ((int32_t)gc_env.r[0] < 0 ? 0x8 : 0x4);
    if (gc_env.cr[0] == 0) goto L_800313A0;
    gc_env.r[11] = 0x0;
    gc_env.r[10] = gc_env.r[11] + 0; // addi r10, r11, 0x0
    goto L_800313A8;
    L_800313A0:
    gc_env.r[11] = 0x40;
    gc_env.r[10] = 0x0;
    L_800313A8:
    gc_env.r[0] = gc_env.r[6] | gc_env.r[9]; // or r0, r6, r9
    gc_env.r[0] = gc_env.r[0] | gc_env.r[4]; // or r0, r0, r4
    gc_env.r[4] = gc_env.r[5] | gc_env.r[8]; // or r4, r5, r8
    gc_env.r[0] = gc_env.r[11] | gc_env.r[0]; // or r0, r11, r0
    gc_env.r[4] = gc_env.r[4] | gc_env.r[7]; // or r4, r4, r7
    gc_mem_write32(gc_env.ram, gc_env.r[3] + 0x24, gc_env.r[0]);
    gc_env.r[0] = gc_env.r[10] | gc_env.r[4]; // or r0, r10, r4
    gc_mem_write32(gc_env.ram, gc_env.r[3] + 0x20, gc_env.r[0]);
    gc_env.r[4] = 0x4;
    HSD_GObj_80390ED0();
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0xc);
    gc_env.r[1] += 8; // addi r1, r1, 0x8
    gc_env.lr = gc_env.r[0]; // Move to link register
    return;
}

// Function: Camera_800313E0
void Camera_800313E0(void) {
    gc_env.r[0] = gc_env.lr; // Move from link register
    gc_env.r[4] = ((uint32_t)&cm_80452C68 >> 16) & 0xFFFF; // lis r4, cm_80452C68@ha
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x4, gc_env.r[0]);
    gc_env.r[4] = gc_env.r[4] + ((uint32_t)&cm_80452C68 & 0xFFFF); // addi r4, r4, cm_80452C68@l
    gc_mem_write32(gc_env.ram, gc_env.r[1] + -0x40, gc_env.r[1]);
    gc_env.r[1] = gc_env.r[1] + -0x40;
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x3c, gc_env.r[31]);
    gc_env.r[31] = gc_env.r[4] + 920; // addi r31, r4, 0x398
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x38, gc_env.r[30]);
    gc_env.r[30] = gc_env.r[5] + 0; // addi r30, r5, 0x0
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x34, gc_env.r[29]);
    gc_env.r[29] = gc_env.r[6] + 0; // addi r29, r6, 0x0
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x30, gc_env.r[28]);
    gc_env.r[28] = gc_env.r[3] + 0; // addi r28, r3, 0x0
    gc_env.r[0] = gc_mem_read8(gc_env.ram, gc_env.r[4] + 0x398);
    gc_env.r[4] = 0x1;
    uint32_t rotated = gc_env.r[4] << 0; // rlwimi r0, r4, 0, 30, 31
    gc_env.r[0] = (gc_env.r[0] & ~0x3) | (rotated & 0x3);
    gc_mem_write8(gc_env.ram, gc_env.r[31] + 0x0, gc_env.r[0]);
    gc_env.r[0] = gc_mem_read8(gc_env.ram, gc_env.r[31] + 0x0);
    gc_env.r[0] = (gc_env.r[0] >> 6) & 0x1; // extrwi r0, r0, 1, 25
    gc_env.cr[0] = (gc_env.r[0] == 0) ? 0x2 : ((int32_t)gc_env.r[0] < 0 ? 0x8 : 0x4);
    if (gc_env.cr[0] == 0) goto L_8003143C;
    gc_env.r[3] = 0x0;
    gc_env.r[4] = gc_env.r[3] + 0; // addi r4, r3, 0x0
    goto L_80031444;
    L_8003143C:
    gc_env.r[3] = 0x40;
    gc_env.r[4] = 0x0;
    L_80031444:
    gc_env.r[0] = gc_mem_read8(gc_env.ram, gc_env.r[31] + 0x0);
    gc_env.r[0] = (gc_env.r[0] >> 7) & 0x1; // extrwi r0, r0, 1, 24
    gc_env.cr[0] = (gc_env.r[0] == 0) ? 0x2 : ((int32_t)gc_env.r[0] < 0 ? 0x8 : 0x4);
    if (gc_env.cr[0] == 0) goto L_8003145C;
    gc_env.r[0] = 0x0;
    gc_env.r[5] = gc_env.r[0]; // Move register
    goto L_80031464;
    L_8003145C:
    gc_env.r[0] = 0x20;
    gc_env.r[5] = 0x0;
    L_80031464:
    gc_env.r[0] = gc_env.r[29] | gc_env.r[0]; // or r0, r29, r0
    gc_env.r[0] = gc_env.r[0] | gc_env.r[3]; // or r0, r0, r3
    gc_env.r[3] = gc_env.r[30] | gc_env.r[5]; // or r3, r30, r5
    gc_mem_write32(gc_env.ram, gc_env.r[28] + 0x24, gc_env.r[0]);
    gc_env.r[0] = gc_env.r[3] | gc_env.r[4]; // or r0, r3, r4
    gc_mem_write32(gc_env.ram, gc_env.r[28] + 0x20, gc_env.r[0]);
    gc_env.r[3] = gc_env.r[28] + 0; // addi r3, r28, 0x0
    gc_env.r[4] = 0x3;
    HSD_GObj_80390ED0();
    gc_env.r[0] = gc_mem_read8(gc_env.ram, gc_env.r[31] + 0x0);
    gc_env.r[3] = 0x0;
    uint32_t rotated = gc_env.r[3] << 0; // rlwimi r0, r3, 0, 30, 31
    gc_env.r[0] = (gc_env.r[0] & ~0x3) | (rotated & 0x3);
    gc_mem_write8(gc_env.ram, gc_env.r[31] + 0x0, gc_env.r[0]);
    gc_env.r[0] = gc_mem_read8(gc_env.ram, gc_env.r[31] + 0x0);
    gc_env.r[0] = (gc_env.r[0] >> 7) & 0x1; // extrwi r0, r0, 1, 24
    gc_env.cr[0] = (gc_env.r[0] == 0) ? 0x2 : ((int32_t)gc_env.r[0] < 0 ? 0x8 : 0x4);
    if (gc_env.cr[0] == 0) goto L_800314AC;
    gc_env.r[4] = gc_env.r[3]; // Move register
    goto L_800314B0;
    L_800314AC:
    gc_env.r[4] = 0x20;
    L_800314B0:
    gc_env.r[0] = gc_mem_read8(gc_env.ram, gc_env.r[31] + 0x0);
    gc_env.r[0] = (gc_env.r[0] >> 3) & 0x1; // extrwi r0, r0, 1, 28
    gc_env.cr[0] = (gc_env.r[0] == 0) ? 0x2 : ((int32_t)gc_env.r[0] < 0 ? 0x8 : 0x4);
    if (gc_env.cr[0] == 0) goto L_800314C8;
    gc_env.r[6] = 0x0;
    gc_env.r[5] = gc_env.r[6] + 0; // addi r5, r6, 0x0
    goto L_800314D0;
    L_800314C8:
    gc_env.r[6] = 0x10;
    gc_env.r[5] = 0x0;
    L_800314D0:
    gc_env.r[0] = gc_mem_read8(gc_env.ram, gc_env.r[31] + 0x0);
    gc_env.r[0] = (gc_env.r[0] >> 6) & 0x1; // extrwi r0, r0, 1, 25
    gc_env.cr[0] = (gc_env.r[0] == 0) ? 0x2 : ((int32_t)gc_env.r[0] < 0 ? 0x8 : 0x4);
    if (gc_env.cr[0] == 0) goto L_800314E8;
    gc_env.r[8] = 0x0;
    gc_env.r[7] = gc_env.r[8] + 0; // addi r7, r8, 0x0
    goto L_800314F0;
    L_800314E8:
    gc_env.r[8] = 0x40;
    gc_env.r[7] = 0x0;
    L_800314F0:
    gc_env.r[0] = gc_env.r[6] | gc_env.r[4]; // or r0, r6, r4
    gc_env.r[0] = gc_env.r[8] | gc_env.r[0]; // or r0, r8, r0
    gc_env.r[3] = gc_env.r[5] | gc_env.r[3]; // or r3, r5, r3
    gc_mem_write32(gc_env.ram, gc_env.r[28] + 0x24, gc_env.r[0]);
    gc_env.r[0] = gc_env.r[7] | gc_env.r[3]; // or r0, r7, r3
    gc_mem_write32(gc_env.ram, gc_env.r[28] + 0x20, gc_env.r[0]);
    gc_env.r[3] = gc_env.r[28] + 0; // addi r3, r28, 0x0
    gc_env.r[4] = 0x3;
    HSD_GObj_80390ED0();
    gc_env.r[0] = gc_mem_read8(gc_env.ram, gc_env.r[31] + 0x0);
    gc_env.r[4] = 0x0;
    uint32_t rotated = gc_env.r[4] << 0; // rlwimi r0, r4, 0, 30, 31
    gc_env.r[0] = (gc_env.r[0] & ~0x3) | (rotated & 0x3);
    gc_mem_write8(gc_env.ram, gc_env.r[31] + 0x0, gc_env.r[0]);
    gc_env.r[0] = gc_mem_read8(gc_env.ram, gc_env.r[31] + 0x0);
    gc_env.r[0] = (gc_env.r[0] >> 7) & 0x1; // extrwi r0, r0, 1, 24
    gc_env.cr[0] = (gc_env.r[0] == 0) ? 0x2 : ((int32_t)gc_env.r[0] < 0 ? 0x8 : 0x4);
    if (gc_env.cr[0] == 0) goto L_80031538;
    gc_env.r[3] = gc_env.r[4]; // Move register
    goto L_8003153C;
    L_80031538:
    gc_env.r[3] = 0x20;
    L_8003153C:
    gc_env.r[0] = gc_mem_read8(gc_env.ram, gc_env.r[31] + 0x0);
    gc_env.r[0] = (gc_env.r[0] >> 3) & 0x1; // extrwi r0, r0, 1, 28
    gc_env.cr[0] = (gc_env.r[0] == 0) ? 0x2 : ((int32_t)gc_env.r[0] < 0 ? 0x8 : 0x4);
    if (gc_env.cr[0] == 0) goto L_80031554;
    gc_env.r[6] = 0x0;
    gc_env.r[5] = gc_env.r[6] + 0; // addi r5, r6, 0x0
    goto L_8003155C;
    L_80031554:
    gc_env.r[6] = 0x10;
    gc_env.r[5] = 0x0;
    L_8003155C:
    gc_env.r[0] = gc_mem_read8(gc_env.ram, gc_env.r[31] + 0x0);
    gc_env.r[0] = (gc_env.r[0] >> 6) & 0x1; // extrwi r0, r0, 1, 25
    gc_env.cr[0] = (gc_env.r[0] == 0) ? 0x2 : ((int32_t)gc_env.r[0] < 0 ? 0x8 : 0x4);
    if (gc_env.cr[0] == 0) goto L_80031574;
    gc_env.r[8] = 0x0;
    gc_env.r[7] = gc_env.r[8] + 0; // addi r7, r8, 0x0
    goto L_8003157C;
    L_80031574:
    gc_env.r[8] = 0x40;
    gc_env.r[7] = 0x0;
    L_8003157C:
    gc_env.r[0] = gc_env.r[29] | gc_env.r[6]; // or r0, r29, r6
    gc_env.r[0] = gc_env.r[0] | gc_env.r[3]; // or r0, r0, r3
    gc_env.r[3] = gc_env.r[30] | gc_env.r[5]; // or r3, r30, r5
    gc_env.r[0] = gc_env.r[8] | gc_env.r[0]; // or r0, r8, r0
    gc_env.r[3] = gc_env.r[3] | gc_env.r[4]; // or r3, r3, r4
    gc_mem_write32(gc_env.ram, gc_env.r[28] + 0x24, gc_env.r[0]);
    gc_env.r[0] = gc_env.r[7] | gc_env.r[3]; // or r0, r7, r3
    gc_mem_write32(gc_env.ram, gc_env.r[28] + 0x20, gc_env.r[0]);
    gc_env.r[3] = gc_env.r[28] + 0; // addi r3, r28, 0x0
    gc_env.r[4] = 0x4;
    HSD_GObj_80390ED0();
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x44);
    gc_env.r[31] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x3c);
    gc_env.r[30] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x38);
    gc_env.r[29] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x34);
    gc_env.r[28] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0x30);
    gc_env.r[1] += 64; // addi r1, r1, 0x40
    gc_env.lr = gc_env.r[0]; // Move to link register
    return;
}
