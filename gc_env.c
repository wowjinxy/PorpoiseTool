#include "gc_env.h"
#include <stdlib.h>
#include <string.h>

// Global environment instance
GameCubeEnv gc_env;

static void gc_env_reset_state(void) {
    memset(gc_env.r, 0, sizeof(gc_env.r));
    memset(gc_env.f, 0, sizeof(gc_env.f));
    gc_env.lr = 0;
    memset(gc_env.cr, 0, sizeof(gc_env.cr));
    gc_env.ctr = 0;
    gc_env.msr = 0;
    gc_env.xer = 0;
    gc_env.hid0 = 0;
    gc_env.l2cr = 0;
    gc_env.dec = 0;
    gc_env.hid2 = 0;

    if (gc_env.ram) {
        memset(gc_env.ram, 0, GC_RAM_SIZE);
    }

    gc_env.r[1] = GC_RAM_BASE + GC_RAM_SIZE - 4;
    gc_env.sp = &gc_env.r[1];
}

void gc_env_init(void) {
    gc_env.ram = (uint8_t*)calloc(GC_RAM_SIZE, 1);
    if (!gc_env.ram) {
        exit(1);
    }

    gc_env_reset_state();
}

void gc_env_reset(void) {
    gc_env_reset_state();
}

void gc_env_cleanup(void) {
    // Free RAM
    if (gc_env.ram) {
        free(gc_env.ram);
        gc_env.ram = NULL;
    }
}