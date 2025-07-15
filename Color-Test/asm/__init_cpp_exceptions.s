.include "macros.inc"
.file "__init_cpp_exceptions.cpp"

# 0x8001A440..0x8001A444 | size: 0x4
.section .dtors, "a"
.balign 4

# .dtors:0x0 | 0x8001A440 | size: 0x4
.obj __destroy_global_chain_reference, global
	.4byte __destroy_global_chain
.endobj __destroy_global_chain_reference
