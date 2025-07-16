    gc_env.r[31] = (uint32_t)&_73_8001A6E0; // lis + addi @73_8001A6E0 (completing pattern)
    gc_env.r[3] = (uint32_t)&__ArenaLo; // lis + addi __ArenaLo (completing pattern)
    gc_env.r[3] = (uint32_t)&_stack_addr; // lis + addi _stack_addr (completing pattern)
    gc_env.r[3] = (uint32_t)&__ArenaHi; // lis + addi __ArenaHi (completing pattern)
    gc_env.r[4] = (uint32_t)&__OSResetSWInterruptHandler; // lis + addi __OSResetSWInterruptHandler (completing pattern)
    gc_env.r[30] = (uint32_t)&__OSEVSetNumber; // lis + addi __OSEVSetNumber (completing pattern)
    gc_env.r[0] = (uint32_t)&__OSDBINTEND; // lis + addi __OSDBINTEND (completing pattern)
    gc_env.r[21] = (uint32_t)&__DBVECTOR; // lis + addi __DBVECTOR (completing pattern)
    gc_env.r[23] = (uint32_t)&OSDefaultExceptionHandler; // lis + addi OSDefaultExceptionHandler (completing pattern)
    // Error in handler for sth: name 'transpiler' is not defined
    gc_env.r[5] = (uint32_t)&OSDefaultExceptionHandler; // lis + addi OSDefaultExceptionHandler (completing pattern)
    __OSUnhandledException();
    gc_env.r[4] = (uint32_t)&DecrementerExceptionHandler; // lis + addi DecrementerExceptionHandler (completing pattern)
    DecrementerExceptionCallback();
    gc_env.r[4] = (uint32_t)&DSPInitCode_8001A8A0; // lis + addi DSPInitCode_8001A8A0 (completing pattern)
    // Error in handler for sth: name 'transpiler' is not defined
    // Error in handler for sth: name 'transpiler' is not defined
    // Error in handler for sth: name 'transpiler' is not defined
    // Error in handler for sth: name 'transpiler' is not defined
    // Error in handler for sth: name 'transpiler' is not defined
    // Error in handler for sth: name 'transpiler' is not defined
    // Error in handler for sth: name 'transpiler' is not defined
    // Error in handler for sth: name 'transpiler' is not defined
    // Error in handler for sth: name 'transpiler' is not defined
    // Error in handler for sth: name 'transpiler' is not defined
    // Error in handler for sth: name 'transpiler' is not defined
    // Error in handler for sth: name 'transpiler' is not defined
    // Error in handler for sth: name 'transpiler' is not defined
    // Error in handler for sth: name 'transpiler' is not defined
    // Error in handler for sth: name 'transpiler' is not defined
    // Error in handler for sth: name 'transpiler' is not defined
    gc_env.r[31] = (uint32_t)&_69_8001A920; // lis + addi @69_8001A920 (completing pattern)
    if (gc_env.cr[1] != 0) goto L_80006B08;
    gc_env.r[31] = (uint32_t)&_69_8001A920; // lis + addi @69_8001A920 (completing pattern)
    gc_env.r[31] = (uint32_t)&_69_8001A920; // lis + addi @69_8001A920 (completing pattern)
    gc_env.r[4] = (uint32_t)&DMAErrorHandler; // lis + addi DMAErrorHandler (completing pattern)
    // Error in handler for sth: name 'transpiler' is not defined
    gc_env.r[4] = ((uint32_t)&OSDisableInterrupts >> 16) & 0xFFFF; // lis r4, OSDisableInterrupts+0x10@ha
    gc_env.r[0] = (uint32_t)&OSDisableInterrupts + 16; // lis + addi OSDisableInterrupts (completing pattern)
    // Error in handler for sth: name 'transpiler' is not defined
    // Error in handler for sth: name 'transpiler' is not defined
    // Error in handler for sth: name 'transpiler' is not defined
    // Error in handler for sth: name 'transpiler' is not defined
    // Error in handler for sth: name 'transpiler' is not defined
    // Error in handler for sth: name 'transpiler' is not defined
    // Error in handler for sth: name 'transpiler' is not defined
    // Error in handler for sth: name 'transpiler' is not defined
    gc_env.r[4] = (uint32_t)&OSSwitchFPUContext; // lis + addi OSSwitchFPUContext (completing pattern)
    if (gc_env.cr[1] != 0) goto L_800074F4;
    vprintf((const char *)gc_env.r[3], (void *)gc_env.r[4]);
    gc_env.r[29] = (uint32_t)&_10_8001AD28; // lis + addi @10_8001AD28 (completing pattern)
    gc_env.r[3] = (uint32_t)&_43_8001B004; // lis + addi @43_8001B004 (completing pattern)
    gc_env.r[4] = (uint32_t)&ExternalInterruptHandler; // lis + addi ExternalInterruptHandler (completing pattern)
    // Error in handler for sth: name 'transpiler' is not defined
    // Error in handler for sth: name 'transpiler' is not defined
    gc_env.r[0] = (uint32_t)&lbl_8001B048; // lis + addi lbl_8001B048 (completing pattern)
    // Error in handler for sth: name 'transpiler' is not defined
    fn_80007C38();
    // Error in handler for sth: name 'transpiler' is not defined
    // Error in handler for sth: name 'transpiler' is not defined
    gc_env.r[3] = (uint32_t)&Config24MB; // lis + addi Config24MB (completing pattern)
    gc_env.r[3] = (uint32_t)&Config48MB; // lis + addi Config48MB (completing pattern)
    // Error in handler for sth: name 'transpiler' is not defined
    // Error in handler for sth: name 'transpiler' is not defined
    gc_env.r[30] = (uint32_t)&MEMIntrruptHandler; // lis + addi MEMIntrruptHandler (completing pattern)
    gc_env.r[3] = (uint32_t)&ResetFunctionInfo_8001B078; // lis + addi ResetFunctionInfo_8001B078 (completing pattern)
    // Error in handler for sth: name 'transpiler' is not defined
    gc_env.r[30] = (uint32_t)&lbl_8001BBA0; // lis + addi lbl_8001BBA0 (completing pattern)
    gc_env.r[3] = (uint32_t)&fn_80008370; // lis + addi fn_80008370 (completing pattern)
    // Error in handler for sth: name 'transpiler' is not defined
    // Error in handler for sth: name 'transpiler' is not defined
    // Error in handler for sth: name 'transpiler' is not defined
    // Error in handler for sth: name 'transpiler' is not defined
    // Error in handler for sth: name 'transpiler' is not defined
    // Error in handler for sth: name 'transpiler' is not defined
    // Error in handler for sth: name 'transpiler' is not defined
    // Error in handler for sth: name 'transpiler' is not defined
    // Error in handler for sth: name 'transpiler' is not defined
    // Error in handler for sth: name 'transpiler' is not defined
    // Error in handler for sth: name 'transpiler' is not defined
    // Error in handler for sth: name 'transpiler' is not defined
    // Error in handler for sth: name 'transpiler' is not defined
    // Error in handler for sth: name 'transpiler' is not defined
    // Error in handler for sth: name 'transpiler' is not defined
    // Error in handler for sth: name 'transpiler' is not defined
    // Error in handler for sth: name 'transpiler' is not defined
    // Error in handler for sth: name 'transpiler' is not defined
    // Error in handler for sth: name 'transpiler' is not defined
    // Error in handler for sth: name 'transpiler' is not defined
    // Error in handler for sth: name 'transpiler' is not defined
    // Error in handler for sth: name 'transpiler' is not defined
    gc_env.r[5] = (uint32_t)&fn_80008A10; // lis + addi fn_80008A10 (completing pattern)
    gc_env.r[3] = (uint32_t)&Scb_8001BBC0; // lis + addi Scb_8001BBC0 (completing pattern)
    // Error in handler for sth: name 'transpiler' is not defined
    // Error in handler for sth: name 'transpiler' is not defined
    // Error in handler for sth: name 'transpiler' is not defined
    gc_env.r[0] = (uint32_t)&_stack_addr; // lis + addi _stack_addr (completing pattern)
    gc_env.r[0] = (uint32_t)&RunQueue_8001BC18; // lis + addi RunQueue_8001BC18 (completing pattern)
    // Error in handler for sth: name 'transpiler' is not defined
    // Error in handler for sth: name 'transpiler' is not defined
    // Error in handler for sth: name 'transpiler' is not defined
    // Error in handler for sth: name 'transpiler' is not defined
    // Error in handler for sth: name 'transpiler' is not defined
    // Error in handler for sth: name 'transpiler' is not defined
    gc_env.r[0] = (uint32_t)&_ctors; // lis + addi _ctors (completing pattern)
    gc_env.r[29] = (uint32_t)&TCIntrruptHandler; // lis + addi TCIntrruptHandler (completing pattern)
    gc_env.r[30] = (uint32_t)&EXTIntrruptHandler; // lis + addi EXTIntrruptHandler (completing pattern)
    gc_env.r[4] = (uint32_t)&Ecb_8001C600; // lis + addi Ecb_8001C600 (completing pattern)
    gc_env.r[0] = (uint32_t)&lbl_8001C800; // lis + addi lbl_8001C800 (completing pattern)
    gc_env.r[0] = (uint32_t)&TypeTime_8001C7E0; // lis + addi TypeTime_8001C7E0 (completing pattern)
    gc_env.r[4] = (uint32_t)&Si_8001B088; // lis + addi Si_8001B088 (completing pattern)
    gc_env.r[23] = (uint32_t)&Packet_8001C6C0; // lis + addi Packet_8001C6C0 (completing pattern)
    gc_env.r[0] = (uint32_t)&Type_8001B09C; // lis + addi Type_8001B09C (completing pattern)
    gc_env.r[5] = (uint32_t)&Si_8001B088; // lis + addi Si_8001B088 (completing pattern)
    gc_env.r[31] = (uint32_t)&XYNTSC_8001B158; // lis + addi XYNTSC_8001B158 (completing pattern)
    fn_8000C32C();
    if (gc_env.cr[1] != 0) goto L_8000C3C8;
    gc_env.r[31] = (uint32_t)&lbl_8001C8C0; // lis + addi lbl_8001C8C0 (completing pattern)
    gc_env.r[7] = (uint32_t)&fn_8000C7A8; // lis + addi fn_8000C7A8 (completing pattern)
    gc_env.r[7] = (uint32_t)&fn_8000C7A8; // lis + addi fn_8000C7A8 (completing pattern)
    gc_env.r[31] = (uint32_t)&lbl_8001C8C0; // lis + addi lbl_8001C8C0 (completing pattern)
    gc_env.r[7] = (uint32_t)&fn_8000C724; // lis + addi fn_8000C724 (completing pattern)
    gc_env.r[7] = (uint32_t)&fn_8000C7A8; // lis + addi fn_8000C7A8 (completing pattern)
    gc_env.r[7] = (uint32_t)&fn_8000C7A8; // lis + addi fn_8000C7A8 (completing pattern)
    gc_env.r[7] = (uint32_t)&fn_8000C7A8; // lis + addi fn_8000C7A8 (completing pattern)
    gc_env.r[7] = (uint32_t)&fn_8000C7A8; // lis + addi fn_8000C7A8 (completing pattern)
    gc_env.r[7] = (uint32_t)&fn_8000C7A8; // lis + addi fn_8000C7A8 (completing pattern)
    gc_env.r[7] = (uint32_t)&fn_8000C7A8; // lis + addi fn_8000C7A8 (completing pattern)
    gc_env.r[7] = (uint32_t)&fn_8000C7A8; // lis + addi fn_8000C7A8 (completing pattern)
    gc_env.r[31] = (uint32_t)&lbl_8001C928; // lis + addi lbl_8001C928 (completing pattern)
    gc_env.r[7] = (uint32_t)&fn_8000C7A8; // lis + addi fn_8000C7A8 (completing pattern)
    gc_env.r[3] = (uint32_t)&fn_8000D44C; // lis + addi fn_8000D44C (completing pattern)
    gc_env.r[3] = (uint32_t)&fn_8000D44C; // lis + addi fn_8000D44C (completing pattern)
    gc_env.r[4] = (uint32_t)&fn_8000D900; // lis + addi fn_8000D900 (completing pattern)
    gc_env.r[3] = (uint32_t)&fn_8000D44C; // lis + addi fn_8000D44C (completing pattern)
    gc_env.r[3] = (uint32_t)&fn_8000D968; // lis + addi fn_8000D968 (completing pattern)
    gc_env.r[3] = (uint32_t)&fn_8000D44C; // lis + addi fn_8000D44C (completing pattern)
    gc_env.r[3] = (uint32_t)&fn_8000D44C; // lis + addi fn_8000D44C (completing pattern)
    gc_env.r[3] = (uint32_t)&fn_8000D44C; // lis + addi fn_8000D44C (completing pattern)
    gc_env.r[3] = (uint32_t)&fn_8000DCD0; // lis + addi fn_8000DCD0 (completing pattern)
    gc_env.r[3] = (uint32_t)&fn_8000DCD0; // lis + addi fn_8000DCD0 (completing pattern)
    gc_env.r[6] = (uint32_t)&fn_8000DDE4; // lis + addi fn_8000DDE4 (completing pattern)
    gc_env.r[3] = (uint32_t)&fn_8000D44C; // lis + addi fn_8000D44C (completing pattern)
    gc_env.r[3] = (uint32_t)&lbl_8001CA20; // lis + addi lbl_8001CA20 (completing pattern)
    gc_env.r[5] = (uint32_t)&lbl_8001C9A0; // lis + addi lbl_8001C9A0 (completing pattern)
    gc_env.r[3] = (uint32_t)&fn_8000D66C; // lis + addi fn_8000D66C (completing pattern)
    gc_env.r[3] = (uint32_t)&fn_8000D66C; // lis + addi fn_8000D66C (completing pattern)
    gc_env.r[3] = (uint32_t)&lbl_8001C9A0; // lis + addi lbl_8001C9A0 (completing pattern)
    gc_env.r[3] = (uint32_t)&fn_8000D66C; // lis + addi fn_8000D66C (completing pattern)
    gc_env.r[3] = (uint32_t)&jumptable_8001B254; // lis + addi jumptable_8001B254 (completing pattern)
    gc_env.r[3] = (uint32_t)&fn_8000D44C; // lis + addi fn_8000D44C (completing pattern)
    gc_env.r[3] = (uint32_t)&jumptable_8001B274; // lis + addi jumptable_8001B274 (completing pattern)
    gc_env.r[6] = (uint32_t)&fn_8000E748; // lis + addi fn_8000E748 (completing pattern)
    gc_env.r[3] = (uint32_t)&fn_8000E748; // lis + addi fn_8000E748 (completing pattern)
    gc_env.r[3] = (uint32_t)&fn_8000E748; // lis + addi fn_8000E748 (completing pattern)
    gc_env.r[3] = (uint32_t)&fn_8000D44C; // lis + addi fn_8000D44C (completing pattern)
    gc_env.r[3] = (uint32_t)&fn_8000D44C; // lis + addi fn_8000D44C (completing pattern)
    gc_env.r[3] = (uint32_t)&fn_8000D66C; // lis + addi fn_8000D66C (completing pattern)
    gc_env.r[0] = (uint32_t)&lbl_8001CA20; // lis + addi lbl_8001CA20 (completing pattern)
    gc_env.r[3] = (uint32_t)&jumptable_8001B2B4; // lis + addi jumptable_8001B2B4 (completing pattern)
    gc_env.r[0] = (uint32_t)&fn_8000E15C; // lis + addi fn_8000E15C (completing pattern)
    gc_env.r[0] = (uint32_t)&lbl_8001CA20; // lis + addi lbl_8001CA20 (completing pattern)
    gc_env.r[4] = (uint32_t)&jumptable_8001B2E8; // lis + addi jumptable_8001B2E8 (completing pattern)
    gc_env.r[3] = (uint32_t)&lbl_8001CA78; // lis + addi lbl_8001CA78 (completing pattern)
    gc_env.r[7] = (uint32_t)&fn_8000F7C8; // lis + addi fn_8000F7C8 (completing pattern)
    gc_env.r[3] = (uint32_t)&lbl_8001CA98; // lis + addi lbl_8001CA98 (completing pattern)
    // Error in handler for sth: name 'transpiler' is not defined
    // Error in handler for sth: name 'transpiler' is not defined
    // Error in handler for sth: name 'transpiler' is not defined
    // Error in handler for sth: name 'transpiler' is not defined
    gc_env.r[5] = (uint32_t)&lbl_8001B3D8; // lis + addi lbl_8001B3D8 (completing pattern)
    gc_env.r[4] = (uint32_t)&jumptable_8001B53C; // lis + addi jumptable_8001B53C (completing pattern)
    // Error in handler for sth: name 'transpiler' is not defined
    // Error in handler for sth: name 'transpiler' is not defined
    // Error in handler for sth: name 'transpiler' is not defined
    // Error in handler for sth: name 'transpiler' is not defined
    // Error in handler for sth: name 'transpiler' is not defined
    // Error in handler for sth: name 'transpiler' is not defined
    // Error in handler for sth: name 'transpiler' is not defined
    // Error in handler for sth: name 'transpiler' is not defined
    // Error in handler for sth: name 'transpiler' is not defined
    // Error in handler for sth: name 'transpiler' is not defined
    // Error in handler for sth: name 'transpiler' is not defined
    // Error in handler for sth: name 'transpiler' is not defined
    // Error in handler for sth: name 'transpiler' is not defined
    // Error in handler for sth: name 'transpiler' is not defined
    // Error in handler for sth: name 'transpiler' is not defined
    // Error in handler for sth: name 'transpiler' is not defined
    // Error in handler for sth: name 'transpiler' is not defined
    // Error in handler for sth: name 'transpiler' is not defined
    // Error in handler for sth: name 'transpiler' is not defined
    // Error in handler for sth: name 'transpiler' is not defined
    // Error in handler for sth: name 'transpiler' is not defined
    // Error in handler for sth: name 'transpiler' is not defined
    // Error in handler for sth: name 'transpiler' is not defined
    // Error in handler for sth: name 'transpiler' is not defined
    // Error in handler for sth: name 'transpiler' is not defined
    // Error in handler for sth: name 'transpiler' is not defined
    // Error in handler for sth: name 'transpiler' is not defined
    // Error in handler for sth: name 'transpiler' is not defined
    // Error in handler for sth: name 'transpiler' is not defined
    // Error in handler for sth: name 'transpiler' is not defined
    // Error in handler for sth: name 'transpiler' is not defined
    // Error in handler for sth: name 'transpiler' is not defined
    // Error in handler for sth: name 'transpiler' is not defined
    // Error in handler for sth: name 'transpiler' is not defined
    // Error in handler for sth: name 'transpiler' is not defined
    // Error in handler for sth: name 'transpiler' is not defined
    // Error in handler for sth: name 'transpiler' is not defined
    // Error in handler for sth: name 'transpiler' is not defined
    // Error in handler for sth: name 'transpiler' is not defined
    // Error in handler for sth: name 'transpiler' is not defined
    // Error in handler for sth: name 'transpiler' is not defined
    // Error in handler for sth: name 'transpiler' is not defined
    // Error in handler for sth: name 'transpiler' is not defined
    // Error in handler for sth: name 'transpiler' is not defined
    // Error in handler for sth: name 'transpiler' is not defined
    // Error in handler for sth: name 'transpiler' is not defined
    // Error in handler for sth: name 'transpiler' is not defined
    // Error in handler for sth: name 'transpiler' is not defined
    // Error in handler for sth: name 'transpiler' is not defined
    // Error in handler for sth: name 'transpiler' is not defined
    // Error in handler for sth: name 'transpiler' is not defined
    // Error in handler for sth: name 'transpiler' is not defined
    // Error in handler for sth: name 'transpiler' is not defined
    // Error in handler for sth: name 'transpiler' is not defined
    // Error in handler for sth: name 'transpiler' is not defined
    // Error in handler for sth: name 'transpiler' is not defined
    // Error in handler for sth: name 'transpiler' is not defined
    gc_env.r[4] = (uint32_t)&fn_8000FA08; // lis + addi fn_8000FA08 (completing pattern)
    // Error in handler for sth: name 'transpiler' is not defined
    gc_env.r[9] = (uint32_t)&lbl_8001CB08; // lis + addi lbl_8001CB08 (completing pattern)
    // Error in handler for sth: name 'transpiler' is not defined
    // Error in handler for sth: name 'transpiler' is not defined
    // Error in handler for sth: name 'transpiler' is not defined
    // Error in handler for sth: name 'transpiler' is not defined
    // Error in handler for sth: name 'transpiler' is not defined
    // Error in handler for sth: name 'transpiler' is not defined
    // Error in handler for sth: name 'transpiler' is not defined
    // Error in handler for sth: name 'transpiler' is not defined
    // Error in handler for sth: name 'transpiler' is not defined
    // Error in handler for sth: name 'transpiler' is not defined
    // Error in handler for sth: name 'transpiler' is not defined
    // Error in handler for sth: name 'transpiler' is not defined
    // Error in handler for sth: name 'transpiler' is not defined
    // Error in handler for sth: name 'transpiler' is not defined
    // Error in handler for sth: name 'transpiler' is not defined
    // Error in handler for sth: name 'transpiler' is not defined
    // Error in handler for sth: name 'transpiler' is not defined
    // Error in handler for sth: name 'transpiler' is not defined
    // Error in handler for sth: name 'transpiler' is not defined
    // Error in handler for sth: name 'transpiler' is not defined
    // Error in handler for sth: name 'transpiler' is not defined
    // Error in handler for sth: name 'transpiler' is not defined
    // Error in handler for sth: name 'transpiler' is not defined
    // Error in handler for sth: name 'transpiler' is not defined
    // Error in handler for sth: name 'transpiler' is not defined
    // Error in handler for sth: name 'transpiler' is not defined
    // Error in handler for sth: name 'transpiler' is not defined
    // Error in handler for sth: name 'transpiler' is not defined
    // Error in handler for sth: name 'transpiler' is not defined
    // Error in handler for sth: name 'transpiler' is not defined
    // Error in handler for sth: name 'transpiler' is not defined
    // Error in handler for sth: name 'transpiler' is not defined
    // Error in handler for sth: name 'transpiler' is not defined
    // Error in handler for sth: name 'transpiler' is not defined
    // Error in handler for sth: name 'transpiler' is not defined
    // Error in handler for sth: name 'transpiler' is not defined
    // Error in handler for sth: name 'transpiler' is not defined
    // Error in handler for sth: name 'transpiler' is not defined
    // Error in handler for sth: name 'transpiler' is not defined
    // Error in handler for sth: name 'transpiler' is not defined
    // Error in handler for sth: name 'transpiler' is not defined
    // Error in handler for sth: name 'transpiler' is not defined
    // Error in handler for sth: name 'transpiler' is not defined
    // Error in handler for sth: name 'transpiler' is not defined
    // Error in handler for sth: name 'transpiler' is not defined
    gc_env.r[4] = (uint32_t)&lbl_8001A460; // lis + ori lbl_8001A460
    if (gc_env.cr[6] >= 0) goto L_80011520;
    // Error in handler for sth: name 'transpiler' is not defined
    gc_env.r[0] = (uint32_t)&lbl_8001A478; // lis + addi lbl_8001A478 (completing pattern)
    // Error in handler for sth: name 'transpiler' is not defined
    if (gc_env.cr[1] != 0) goto L_800126CC;
    gc_env.r[4] = (uint32_t)&__files; // lis + addi __files (completing pattern)
    // Error in handler for sth: name 'transpiler' is not defined
    // Error in handler for sth: name 'transpiler' is not defined
    // Error in handler for sth: name 'transpiler' is not defined
    // Error in handler for sth: name 'transpiler' is not defined
    // Error in handler for sth: name 'transpiler' is not defined
    // Error in handler for sth: name 'transpiler' is not defined
    // Error in handler for sth: name 'transpiler' is not defined
    gc_env.r[5] = (uint32_t)&_1009_8001B7B8; // lis + addi @1009_8001B7B8 (completing pattern)
    gc_env.r[9] = (uint32_t)&jumptable_8001B83C; // lis + addi jumptable_8001B83C (completing pattern)
    gc_env.r[4] = (uint32_t)&jumptable_8001B990; // lis + addi jumptable_8001B990 (completing pattern)
    gc_env.r[5] = (uint32_t)&lbl_8001A500; // lis + addi lbl_8001A500 (completing pattern)
    gc_env.r[5] = (uint32_t)&lbl_8001A500; // lis + addi lbl_8001A500 (completing pattern)
    gc_env.r[3] = (uint32_t)&jumptable_8001B8C0; // lis + addi jumptable_8001B8C0 (completing pattern)
    gc_env.r[3] = (uint32_t)&lbl_8001CE50; // lis + addi lbl_8001CE50 (completing pattern)
    gc_env.r[3] = (uint32_t)&lbl_8001CE50; // lis + addi lbl_8001CE50 (completing pattern)
    gc_env.r[31] = (uint32_t)&gTRKInputPendingPtr; // lis + addi gTRKInputPendingPtr (completing pattern)
    gc_env.r[0] = (uint32_t)&lbl_8001CE80; // lis + addi lbl_8001CE80 (completing pattern)
    gc_env.r[0] = (uint32_t)&lbl_8001CE80; // lis + addi lbl_8001CE80 (completing pattern)
    // Error in handler for sth: name 'transpiler' is not defined
    gc_env.r[4] = (uint32_t)&lbl_8001E830; // lis + addi lbl_8001E830 (completing pattern)
    // Error in handler for sth: name 'transpiler' is not defined
    gc_env.r[3] = (uint32_t)&jumptable_8001BA60; // lis + addi jumptable_8001BA60 (completing pattern)
    // Error in handler for sth: name 'transpiler' is not defined
    gc_env.r[3] = (uint32_t)&jumptable_8001BA7C; // lis + addi jumptable_8001BA7C (completing pattern)
    // Error in handler for sth: name 'transpiler' is not defined
    // Error in handler for sth: name 'transpiler' is not defined
    gc_env.r[4] = (uint32_t)&lbl_8001A630; // lis + addi lbl_8001A630 (completing pattern)
    gc_env.r[4] = (uint32_t)&lbl_8001A630; // lis + addi lbl_8001A630 (completing pattern)
    gc_env.r[0] = (uint32_t)&lbl_8001A630; // lis + addi lbl_8001A630 (completing pattern)
    gc_env.r[5] = (uint32_t)&gTRKExceptionStatus_8001BAA4; // lis + addi gTRKExceptionStatus_8001BAA4 (completing pattern)
    gc_env.r[4] = (uint32_t)&gTRKExceptionStatus_8001BAA4; // lis + addi gTRKExceptionStatus_8001BAA4 (completing pattern)
    gc_env.r[3] = (uint32_t)&lbl_8001BA98; // lis + addi lbl_8001BA98 (completing pattern)
    gc_env.r[3] = (uint32_t)&gTRKCPUState; // lis + addi gTRKCPUState (completing pattern)
    gc_env.r[3] = (uint32_t)&lbl_8001BA98; // lis + addi lbl_8001BA98 (completing pattern)
    gc_env.r[3] = (uint32_t)&lbl_8001CE78; // lis + addi lbl_8001CE78 (completing pattern)
    gc_env.r[2] = (uint32_t)&gTRKState; // lis + ori gTRKState
    gc_env.r[2] = (uint32_t)&TRK_saved_exceptionID_8001E850; // lis + ori TRK_saved_exceptionID_8001E850
    // Error in handler for sth: name 'transpiler' is not defined
    gc_env.r[2] = (uint32_t)&gTRKCPUState; // lis + ori gTRKCPUState
    gc_env.r[2] = (uint32_t)&gTRKCPUState; // lis + ori gTRKCPUState
    gc_env.r[2] = (uint32_t)&gTRKState; // lis + ori gTRKState
    gc_env.r[2] = (uint32_t)&gTRKExceptionStatus_8001BAA4; // lis + ori gTRKExceptionStatus_8001BAA4
    gc_env.r[2] = (uint32_t)&gTRKState; // lis + ori gTRKState
    gc_env.r[2] = (uint32_t)&gTRKSaveState; // lis + ori gTRKSaveState
    gc_env.r[2] = (uint32_t)&TRK_saved_exceptionID_8001E850; // lis + ori TRK_saved_exceptionID_8001E850
    gc_env.r[2] = (uint32_t)&gTRKExceptionStatus_8001BAA4; // lis + ori gTRKExceptionStatus_8001BAA4
    gc_env.r[2] = (uint32_t)&gTRKCPUState; // lis + ori gTRKCPUState
    // Error in handler for sth: name 'transpiler' is not defined
    // Error in handler for sth: name 'transpiler' is not defined
    gc_env.r[2] = (uint32_t)&gTRKExceptionStatus_8001BAA4; // lis + ori gTRKExceptionStatus_8001BAA4
    gc_env.r[2] = (uint32_t)&gTRKState; // lis + ori gTRKState
    TRKPostInterruptEvent();
    gc_env.r[2] = (uint32_t)&gTRKExceptionStatus_8001BAA4; // lis + ori gTRKExceptionStatus_8001BAA4
    // Error in handler for sth: name 'transpiler' is not defined
    gc_env.r[2] = (uint32_t)&gTRKExceptionStatus_8001BAA4; // lis + ori gTRKExceptionStatus_8001BAA4
    gc_env.r[3] = (uint32_t)&gTRKState; // lis + addi gTRKState (completing pattern)
    gc_env.r[3] = (uint32_t)&gTRKCPUState; // lis + addi gTRKCPUState (completing pattern)
    gc_env.r[3] = (uint32_t)&gTRKState; // lis + ori gTRKState
    gc_env.r[2] = (uint32_t)&gTRKState; // lis + ori gTRKState
    gc_env.r[2] = (uint32_t)&gTRKState; // lis + ori gTRKState
    gc_env.r[2] = (uint32_t)&gTRKExceptionStatus_8001BAA4; // lis + ori gTRKExceptionStatus_8001BAA4
    gc_env.r[2] = (uint32_t)&gTRKCPUState; // lis + ori gTRKCPUState
    gc_env.r[2] = (uint32_t)&gTRKState; // lis + ori gTRKState
    TRKPostInterruptEvent();
    gc_env.r[3] = (uint32_t)&gTRKCPUState; // lis + addi gTRKCPUState (completing pattern)
    gc_env.r[3] = (uint32_t)&gTRKCPUState; // lis + addi gTRKCPUState (completing pattern)
    gc_env.r[31] = (uint32_t)&gTRKExceptionStatus_8001BAA4; // lis + addi gTRKExceptionStatus_8001BAA4 (completing pattern)
    gc_env.r[3] = (uint32_t)&gTRKExceptionStatus_8001BAA4; // lis + addi gTRKExceptionStatus_8001BAA4 (completing pattern)
    gc_env.r[3] = (uint32_t)&gTRKCPUState; // lis + addi gTRKCPUState (completing pattern)
    gc_env.r[3] = (uint32_t)&gTRKCPUState; // lis + addi gTRKCPUState (completing pattern)
    gc_env.r[5] = (uint32_t)&lbl_8001BAB4; // lis + addi lbl_8001BAB4 (completing pattern)
    gc_env.r[4] = (uint32_t)&gTRKCPUState; // lis + addi gTRKCPUState (completing pattern)
    gc_env.r[31] = (uint32_t)&lbl_8001BAB4; // lis + addi lbl_8001BAB4 (completing pattern)
    gc_env.r[4] = (uint32_t)&lbl_8001BAB4; // lis + addi lbl_8001BAB4 (completing pattern)
    gc_env.r[31] = (uint32_t)&lbl_8001BAB4; // lis + addi lbl_8001BAB4 (completing pattern)
    gc_env.r[3] = (uint32_t)&lbl_8001BAB4; // lis + addi lbl_8001BAB4 (completing pattern)
    gc_env.r[4] = (uint32_t)&lbl_8001BAB4; // lis + addi lbl_8001BAB4 (completing pattern)
    gc_env.r[5] = (uint32_t)&lbl_8001BAB4; // lis + addi lbl_8001BAB4 (completing pattern)
    gc_env.r[3] = (uint32_t)&gTRKCPUState; // lis + addi gTRKCPUState (completing pattern)
    gc_env.r[3] = (uint32_t)&gTRKCPUState; // lis + addi gTRKCPUState (completing pattern)
    gc_env.r[5] = (uint32_t)&gTRKCPUState; // lis + addi gTRKCPUState (completing pattern)
    gc_env.r[3] = (uint32_t)&gTRKState; // lis + addi gTRKState (completing pattern)
    gc_env.r[4] = (uint32_t)&gTRKState; // lis + addi gTRKState (completing pattern)
    gc_env.r[4] = (uint32_t)&lbl_8001E8E8; // lis + addi lbl_8001E8E8 (completing pattern)
    gc_env.r[4] = (uint32_t)&gTRKState; // lis + addi gTRKState (completing pattern)
    gc_env.r[3] = (uint32_t)&gTRKCPUState; // lis + ori gTRKCPUState
    gc_env.r[3] = (uint32_t)&gTRKCPUState; // lis + ori gTRKCPUState
    gc_env.r[1] = (uint32_t)&_db_stack_addr; // lis + ori _db_stack_addr
    TRK_main();
    gc_env.r[4] = (uint32_t)&lbl_8001EDD0; // lis + addi lbl_8001EDD0 (completing pattern)
    gc_env.r[4] = (uint32_t)&gTRKCPUState; // lis + addi gTRKCPUState (completing pattern)
    gc_env.r[0] = (uint32_t)&gTRKInterruptVectorTable; // lis + addi gTRKInterruptVectorTable (completing pattern)
    gc_env.r[31] = (uint32_t)&gTRKState; // lis + addi gTRKState (completing pattern)
    gc_env.r[3] = (uint32_t)&lbl_8001EDD0; // lis + addi lbl_8001EDD0 (completing pattern)
    gc_env.r[2] = (uint32_t)&gTRKCPUState; // lis + ori gTRKCPUState
    gc_env.r[2] = (uint32_t)&gTRKCPUState; // lis + ori gTRKCPUState
    gc_env.r[5] = (uint32_t)&lbl_8001BA98; // lis + ori lbl_8001BA98
    // Error in handler for sth: name 'transpiler' is not defined
    TRKInterruptHandler();
    gc_env.r[3] = (uint32_t)&gDBCommTable; // lis + addi gDBCommTable (completing pattern)
    gc_env.r[3] = (uint32_t)&gDBCommTable; // lis + addi gDBCommTable (completing pattern)
    gc_env.r[3] = (uint32_t)&gDBCommTable; // lis + addi gDBCommTable (completing pattern)
    gc_env.r[5] = (uint32_t)&gDBCommTable; // lis + addi gDBCommTable (completing pattern)
    gc_env.r[5] = (uint32_t)&gDBCommTable; // lis + addi gDBCommTable (completing pattern)
    gc_env.r[3] = (uint32_t)&gDBCommTable; // lis + addi gDBCommTable (completing pattern)
    gc_env.r[3] = (uint32_t)&gDBCommTable; // lis + addi gDBCommTable (completing pattern)
    gc_env.r[4] = (uint32_t)&fn_800190E0; // lis + addi fn_800190E0 (completing pattern)
    gc_env.r[0] = (uint32_t)&fn_8001A048; // lis + addi fn_8001A048 (completing pattern)
    gc_env.r[4] = (uint32_t)&fn_8001A084; // lis + addi fn_8001A084 (completing pattern)
