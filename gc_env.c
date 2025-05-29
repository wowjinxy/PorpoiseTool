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