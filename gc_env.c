#include "gc_env.h"
#include <stdlib.h>
#include <string.h>

// Global environment instance
GameCubeEnv gc_env;

void gc_env_init(void) {
    // Initialize registers to 0
    memset(gc_env.r, 0, sizeof(gc_env.r));
    memset(gc_env.f, 0, sizeof(gc_env.f));
    gc_env.lr = 0;
    memset(gc_env.cr, 0, sizeof(gc_env.cr));
    gc_env.ctr = 0;
    gc_env.msr = 0; // Initialize Machine State Register
    gc_env.xer = 0; // Initialize Fixed-Point Exception Register
    gc_env.hid0 = 0; // Initialize HID0
    gc_env.l2cr = 0; // Initialize L2CR
    gc_env.dec = 0; // Initialize Decrementer
    gc_env.hid2 = 0; // Initialize HID2
    gc_env.srr0 = 0; // Initialize SRR0
    gc_env.srr1 = 0; // Initialize SRR1
    memset(gc_env.ibatu, 0, sizeof(gc_env.ibatu));
    gc_env.dar = 0; // Initialize Data Address Register
    memset(gc_env.sprg, 0, sizeof(gc_env.sprg));
    memset(gc_env.dbatu, 0, sizeof(gc_env.dbatu));
    gc_env.fpscr = 0; // Initialize FPSCR
    gc_env.tb = 0; // Initialize Time Base

    // Allocate RAM
    gc_env.ram = (uint8_t*)calloc(GC_RAM_SIZE, 1);
    if (!gc_env.ram) {
        // Handle allocation failure
        exit(1);
    }

    // Set stack pointer (r1) to top of RAM (simplified)
    gc_env.r[1] = GC_RAM_BASE + GC_RAM_SIZE - 4; // 4-byte aligned
    gc_env.sp = &gc_env.r[1];
}

void gc_env_cleanup(void) {
    // Free RAM
    if (gc_env.ram) {
        free(gc_env.ram);
        gc_env.ram = NULL;
    }
}