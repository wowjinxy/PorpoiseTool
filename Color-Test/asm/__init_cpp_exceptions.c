#include "all_headers.h"
#include "__init_cpp_exceptions.h"
#include <stdint.h>
#include <stdio.h>

#include "gc_env.h"

// Data section: __destroy_global_chain_reference
// Address: 0x8001A440
uint32_t __destroy_global_chain_reference[] = {
    (uint32_t)&__destroy_global_chain, // .4byte __destroy_global_chain
};
