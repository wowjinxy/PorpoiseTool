#include "gc_env.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

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
    memset(gc_env.sr, 0, sizeof(gc_env.sr));
    gc_env.sdr1 = 0; // Initialize SDR1
    gc_env.tear = 0; // Initialize TEAR
    memset(gc_env.gqr, 0, sizeof(gc_env.gqr));
    gc_env.iabr = 0; // Initialize IABR
    gc_env.srr0 = 0; // Initialize SRR0
    gc_env.srr1 = 0; // Initialize SRR1
    memset(gc_env.ibatu, 0, sizeof(gc_env.ibatu));
    gc_env.dar = 0; // Initialize Data Address Register
    gc_env.dsisr = 0; // Initialize Data Storage Interrupt Status Register
    memset(gc_env.sprg, 0, sizeof(gc_env.sprg));
    memset(gc_env.dbatu, 0, sizeof(gc_env.dbatu));
    gc_env.fpscr = 0; // Initialize FPSCR
    gc_env.tb = 0; // Initialize Time Base

    // Allocate RAM
    gc_env.ram = (uint8_t*)calloc(GC_RAM_SIZE, 1);
    if (!gc_env.ram) {
        // Handle allocation failure
        fprintf(stderr, "Failed to allocate GameCube RAM\n");
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

// Simple definitions for system symbols referenced by generated code
uint32_t stack_base = 0;
uint32_t _stack_addr = 0;
uint32_t _SDA_BASE_ = 0;
uint32_t _SDA2_BASE_ = 0;
uint32_t _rom_copy_info[1] = {0};
uint32_t _bss_init_info[1] = {0};
