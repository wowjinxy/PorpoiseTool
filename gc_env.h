#ifndef __GC_ENV_H__
#define __GC_ENV_H__

#include <stdint.h>

// GameCube memory layout
#define GC_RAM_SIZE (24 * 1024 * 1024) // 24 MB main RAM
#define GC_RAM_BASE 0x80000000 // MEM1 base address

// GameCube environment structure
typedef struct {
    // General-purpose registers (r0-r31)
    uint32_t r[32];
    // Floating-point registers (f0-f31)
    double f[32];
    // Special registers
    uint32_t lr; // Link register
    uint32_t cr[8]; // Condition register fields (cr0-cr7, 4 bits each)
    uint32_t ctr; // Count register
    uint32_t msr; // Machine State Register
    uint32_t xer; // Fixed-Point Exception Register (for carry/overflow)
    uint32_t hid0; // Hardware Implementation Dependent Register 0
    uint32_t l2cr; // Level 2 Cache Control Register
    uint32_t dec; // Decrementer Register
    uint32_t hid2; // Hardware Implementation Dependent Register 2
    uint32_t srr0; // Save/Restore Register 0
    uint32_t srr1; // Save/Restore Register 1
    uint32_t ibatu[4]; // Instruction BAT Upper registers
    // Main RAM (24 MB)
    uint8_t* ram;
    // Stack pointer (r1 alias for convenience)
    uint32_t* sp; // Points to r[1]
} GameCubeEnv;

// Global environment instance
extern GameCubeEnv gc_env;

// Initialize the environment
void gc_env_init(void);
// Cleanup the environment
void gc_env_cleanup(void);

// Memory access functions
static inline uint32_t gc_mem_read32(uint8_t* ram, uint32_t addr) {
    if (addr < GC_RAM_BASE || addr + 3 >= GC_RAM_BASE + GC_RAM_SIZE) {
        return 0;
    }
    addr -= GC_RAM_BASE;
    return (ram[addr] << 24) | (ram[addr + 1] << 16) | (ram[addr + 2] << 8) | ram[addr + 3];
}

static inline void gc_mem_write32(uint8_t* ram, uint32_t addr, uint32_t data) {
    if (addr < GC_RAM_BASE || addr + 3 >= GC_RAM_BASE + GC_RAM_SIZE) {
        return;
    }
    addr -= GC_RAM_BASE;
    ram[addr] = (data >> 24) & 0xFF;
    ram[addr + 1] = (data >> 16) & 0xFF;
    ram[addr + 2] = (data >> 8) & 0xFF;
    ram[addr + 3] = data & 0xFF;
}

static inline uint16_t gc_mem_read16(uint8_t* ram, uint32_t addr) {
    if (addr < GC_RAM_BASE || addr + 1 >= GC_RAM_BASE + GC_RAM_SIZE) {
        return 0;
    }
    addr -= GC_RAM_BASE;
    return (ram[addr] << 8) | ram[addr + 1];
}

static inline void gc_mem_write16(uint8_t* ram, uint32_t addr, uint16_t data) {
    if (addr < GC_RAM_BASE || addr + 1 >= GC_RAM_BASE + GC_RAM_SIZE) {
        return;
    }
    addr -= GC_RAM_BASE;
    ram[addr] = (data >> 8) & 0xFF;
    ram[addr + 1] = data & 0xFF;
}

static inline uint8_t gc_mem_read8(uint8_t* ram, uint32_t addr) {
    if (addr < GC_RAM_BASE || addr >= GC_RAM_BASE + GC_RAM_SIZE) {
        return 0;
    }
    addr -= GC_RAM_BASE;
    return ram[addr];
}

static inline void gc_mem_write8(uint8_t* ram, uint32_t addr, uint8_t data) {
    if (addr < GC_RAM_BASE || addr >= GC_RAM_BASE + GC_RAM_SIZE) {
        return;
    }
    addr -= GC_RAM_BASE;
    ram[addr] = data;
}

#endif // __GC_ENV_H__