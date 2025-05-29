#ifndef __AUTO_00_80003100_INIT_H__
#define __AUTO_00_80003100_INIT_H__

#include <stdint.h>

// Function declarations
void __check_pad3(void);
void __start(void);
void __init_registers(void);
void __init_data(void);
void __init_hardware(void);
void __flush_cache(void);
void memset(void);
//void __fill_mem(void);
//void memcpy(void);
//void fn_800034C8(void);
//void fn_800034EC(void);
//void gap_00_8000351C_init(void);
//void fn_80005450(void);

#endif // __AUTO_00_80003100_INIT_H__