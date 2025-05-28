#ifndef __REGISTERS_H__
#define __REGISTERS_H__

#include <stdint.h>

// General-purpose registers
extern uint32_t r0, r1, r2, r3, r4, r5, r6, r7, r8, r9, r10, r11, r12;
extern uint32_t r13, r14, r15, r16, r17, r18, r19, r20, r21, r22, r23, r24;
extern uint32_t r25, r26, r27, r28, r29, r30, r31;

// Floating-point registers
extern double f0, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, f12, f13;
extern double f14, f15, f16, f17, f18, f19, f20, f21, f22, f23, f24, f25;
extern double f26, f27, f28, f29, f30, f31;

// Special registers
extern uint32_t lr;  // Link register
extern int32_t cr0;  // Condition register field 0

#endif // __REGISTERS_H__