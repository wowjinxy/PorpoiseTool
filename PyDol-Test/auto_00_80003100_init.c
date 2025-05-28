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
    //OSReset();
L_80003130:
    gc_env.r[0] = gc_mem_read32(gc_env.ram, gc_env.r[1] + 0xc);
    gc_env.r[1] = gc_env.r[1] + 0x8;
    gc_env.lr = gc_env.r[0]; // Move to link register
    return;
}

// Function: __start
void __start(void) {
    //__init_registers();
    //__init_hardware();
    gc_env.r[0] = -0x1;
    gc_mem_write32(gc_env.ram, gc_env.r[1] + -0x8, gc_env.r[1]);
    gc_env.r[1] = gc_env.r[1] + -0x8;
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x4, gc_env.r[0]);
    gc_mem_write32(gc_env.ram, gc_env.r[1] + 0x0, gc_env.r[0]);
    //__init_data();
    gc_env.r[0] = 0x0;
    gc_env.r[6] = ((uint32_t)0x8000) << 16;
    gc_env.r[6] = gc_env.r[6] + 0x44;
    gc_mem_write32(gc_env.ram, gc_env.r[6] + 0x0, gc_env.r[0]);
    gc_env.r[6] = ((uint32_t)0x8000) << 16;
    gc_env.r[6] = gc_env.r[6] + 0xf4;
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
    //gc_env.r[6] = ((uint32_t)InitMetroTRK) << 16;
    //gc_env.r[6] = gc_env.r[6] + InitMetroTRK@l;
    gc_env.lr = gc_env.r[6]; // Move to link register
    // Call function at gc_env.lr; // Branch to link register
L_800031AC:
    gc_env.r[6] = ((uint32_t)0x8000) << 16;
    gc_env.r[6] = gc_env.r[6] + 0xf4;
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
    gc_env.r[15] = gc_env.r[6] + 0x4;
    gc_env.ctr = gc_env.r[14]; // Move to count register
L_800031E4:
    gc_env.r[6] = gc_env.r[6] + 0x4;
    gc_env.r[7] = gc_mem_read32(gc_env.ram, gc_env.r[6] + 0x0);
    gc_env.r[7] = gc_env.r[7] + gc_env.r[5];
    gc_mem_write32(gc_env.ram, gc_env.r[6] + 0x0, gc_env.r[7]);
    gc_env.ctr -= 1;
    if (gc_env.ctr != 0) goto L_800031E4;
    gc_env.r[5] = ((uint32_t)0x8000) << 16;
    gc_env.r[5] = gc_env.r[5] + 0x34;
    gc_env.r[7] = gc_env.r[15] & ~((1ULL << 5) - 1); // Clear rightmost 5 bits
    gc_mem_write32(gc_env.ram, gc_env.r[5] + 0x0, gc_env.r[7]);
    goto L_80003214;
L_8000320C:
    gc_env.r[14] = 0x0;
    gc_env.r[15] = 0x0;
L_80003214:
    //DBInit();
    //OSInit();
    gc_env.r[4] = ((uint32_t)0x8000) << 16;
    gc_env.r[4] = gc_env.r[4] + 0x30e6;
    gc_env.r[3] = gc_mem_read16(gc_env.ram, gc_env.r[4] + 0x0);
    gc_env.r[5] = gc_env.r[3] & 0x8000;
    if (gc_env.cr[0] == 0) goto L_8000323C;
    gc_env.r[3] = gc_env.r[3] & 0x7fff;
    gc_env.cr[0] = ((uint32_t)gc_env.r[3] == 0x1) ? 0 : ((uint32_t)gc_env.r[3] < 0x1 ? -1 : 1); // Logical compare with immediate
    if (gc_env.cr[0] != 0) goto L_80003240;
L_8000323C:
    __check_pad3();
L_80003240:
    //__init_user();
    gc_env.r[3] = gc_env.r[14]; // Move register
    gc_env.r[4] = gc_env.r[15]; // Move register
    //main();
    //goto exit;
}

int main() {
    return 0;
}
