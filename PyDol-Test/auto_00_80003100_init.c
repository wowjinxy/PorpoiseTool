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

int main() {
    return 0;
}
