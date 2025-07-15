#include "all_headers.h"
#include "auto_05_8001A680_data.h"
#include <stdint.h>
#include <stdio.h>

#include "gc_env.h"
#include <stdlib.h>

// Global variables
extern double lbl_8001F0A0;
extern double lbl_8001F0A8;
extern double lbl_8001F0B0;
extern double lbl_8001F0B8;
extern double lbl_8001F0C0;
extern double lbl_8001F0C8;
extern double lbl_8001F0D0;
extern uint32_t AlarmQueue_8001EE88;
extern uint32_t AreWeInitialized_8001EE74;
extern uint32_t BI2DebugFlagHolder_8001EE70;
extern uint32_t BI2DebugFlag_8001EE6C;
extern uint32_t BootInfo_8001EE68;
extern uint32_t CurrTvMode_8001F024;
extern uint32_t DBVerbose;
extern uint32_t InterruptHandlerTable_8001EE98;
extern uint32_t OSExceptionTable_8001EE78;
extern uint32_t Reschedule_8001EEE8;
extern uint32_t ResetFunctionQueue_8001EEC0;
extern uint32_t RunQueueBits_8001EEE0;
extern uint32_t RunQueueHint_8001EEE4;
extern uint32_t SamplingRate_8001EF10;
extern uint32_t Si_8001B088;
extern uint32_t TRK_mainError_8001EDD8;
extern uint32_t __DBInterface;
extern uint32_t __DVDLongFileNameFlag;
extern uint32_t __OSArenaHi_8001EE90;
extern uint32_t __OSArenaLo_8001EE08;
extern uint32_t __OSInIPL;
extern uint32_t __OSLastInterruptSrr0;
extern uint32_t __OSLastInterruptTime;
extern uint32_t __OSLastInterruptTime+0x4;
extern uint32_t __OSStartTime;
extern uint32_t __OSStartTime+0x4;
extern uint32_t __PADSpec;
extern uint32_t __global_destructor_chain;
extern uint32_t lbl_8001C8C0;
extern uint32_t lbl_8001CE78;
extern uint32_t lbl_8001E848;
extern uint32_t lbl_8001EE00;
extern uint32_t lbl_8001EE18;
extern uint32_t lbl_8001EE20;
extern uint32_t lbl_8001EE40;
extern uint32_t lbl_8001EE44;
extern uint32_t lbl_8001EE48;
extern uint32_t lbl_8001EE50;
extern uint32_t lbl_8001EE60;
extern uint32_t lbl_8001EE64;
extern uint32_t lbl_8001EEB0;
extern uint32_t lbl_8001EEB4;
extern uint32_t lbl_8001EEB8;
extern uint32_t lbl_8001EEC8;
extern uint32_t lbl_8001EECC;
extern uint32_t lbl_8001EED0;
extern uint32_t lbl_8001EED8;
extern uint32_t lbl_8001EEDC;
extern uint32_t lbl_8001EEF0;
extern uint32_t lbl_8001EEF4;
extern uint32_t lbl_8001EEF8;
extern uint32_t lbl_8001EEFC;
extern uint32_t lbl_8001EF08;
extern uint32_t lbl_8001EF20;
extern uint32_t lbl_8001EF24;
extern uint32_t lbl_8001EF28;
extern uint32_t lbl_8001EF2C;
extern uint32_t lbl_8001EF30;
extern uint32_t lbl_8001EF34;
extern uint32_t lbl_8001EF38;
extern uint32_t lbl_8001EF3C;
extern uint32_t lbl_8001EF40;
extern uint32_t lbl_8001EF44;
extern uint32_t lbl_8001EF48;
extern uint32_t lbl_8001EF50;
extern uint32_t lbl_8001EF54;
extern uint32_t lbl_8001EF58;
extern uint32_t lbl_8001EF5C;
extern uint32_t lbl_8001EF60;
extern uint32_t lbl_8001EF64;
extern uint32_t lbl_8001EF68;
extern uint32_t lbl_8001EF6C;
extern uint32_t lbl_8001EF70;
extern uint32_t lbl_8001EF74;
extern uint32_t lbl_8001EF88;
extern uint32_t lbl_8001EF8C;
extern uint32_t lbl_8001EF90;
extern uint32_t lbl_8001EF94;
extern uint32_t lbl_8001EF98;
extern uint32_t lbl_8001EF9C;
extern uint32_t lbl_8001EFA0;
extern uint32_t lbl_8001EFA4;
extern uint32_t lbl_8001EFA8;
extern uint32_t lbl_8001EFAC;
extern uint32_t lbl_8001EFB0;
extern uint32_t lbl_8001EFB4;
extern uint32_t lbl_8001EFB8;
extern uint32_t lbl_8001EFBC;
extern uint32_t lbl_8001EFC0;
extern uint32_t lbl_8001EFC4;
extern uint32_t lbl_8001EFC8;
extern uint32_t lbl_8001EFCC;
extern uint32_t lbl_8001EFD0;
extern uint32_t lbl_8001EFD4;
extern uint32_t lbl_8001EFD8;
extern uint32_t lbl_8001EFE0;
extern uint32_t lbl_8001EFE4;
extern uint32_t lbl_8001EFF0;
extern uint32_t lbl_8001EFF4;
extern uint32_t lbl_8001EFF8;
extern uint32_t lbl_8001F000;
extern uint32_t lbl_8001F008;
extern uint32_t lbl_8001F00C;
extern uint32_t lbl_8001F010;
extern uint32_t lbl_8001F018;
extern uint32_t lbl_8001F01C;
extern uint32_t lbl_8001F020;
extern uint32_t lbl_8001F028;
extern uint32_t lbl_8001F02C;
extern uint32_t lbl_8001F058;
extern uint32_t lbl_8001F064;
extern uint32_t lbl_8001F068;
extern uint32_t lbl_8001F070;
extern uint32_t lbl_8001F074;
extern uint32_t lbl_8001F078;
extern uint32_t lbl_8001F07C;
extern uint32_t lbl_8001F080;
extern uint8_t lbl_8001EE58;

// Data section: lbl_8001A680
// Address: 0x8001A680
uint32_t lbl_8001A680[] = {
    0x000000B4, // .4byte 0x000000B4
    0x00000080, // .4byte 0x00000080
    0x00000080, // .4byte 0x00000080
    0x000000A2, // .4byte 0x000000A2
    0x0000002C, // .4byte 0x0000002C
    0x0000008E, // .4byte 0x0000008E
    0x00000083, // .4byte 0x00000083
    0x0000009C, // .4byte 0x0000009C
    0x0000002C, // .4byte 0x0000002C
    0x00000070, // .4byte 0x00000070
    0x00000048, // .4byte 0x00000048
    0x0000003A, // .4byte 0x0000003A
    0x00000054, // .4byte 0x00000054
    0x000000B8, // .4byte 0x000000B8
    0x000000C6, // .4byte 0x000000C6
    0x00000041, // .4byte 0x00000041
    0x00000064, // .4byte 0x00000064
    0x000000D4, // .4byte 0x000000D4
    0x00000023, // .4byte 0x00000023
    0x000000D4, // .4byte 0x000000D4
    0x00000072, // .4byte 0x00000072
    0x00000010, // .4byte 0x00000010
    0x00000080, // .4byte 0x00000080
    0x00000080, // .4byte 0x00000080
};

// Data section: @73_8001A6E0
// Address: 0x8001A6E0
uint32_t @73_8001A6E0[] = {
    // Unrecognized: .string "\nDolphin OS $Revision: 49 $.\n"
};

// Data section: gap_05_8001A6FE_data
// Address: 0x8001A6FE
uint32_t gap_05_8001A6FE_data[] = {
    0x00004B65, // .4byte 0x00004B65
    0x726E656C, // .4byte 0x726E656C
    0x20627569, // .4byte 0x20627569
    0x6C74203A, // .4byte 0x6C74203A
    0x20257320, // .4byte 0x20257320
    0x25730A00, // .4byte 0x25730A00
    0x00004465, // .4byte 0x00004465
    0x63203137, // .4byte 0x63203137
    0x20323030, // .4byte 0x20323030
    0x31003138, // .4byte 0x31003138
    0x3A34363A, // .4byte 0x3A34363A
    0x34350000, // .4byte 0x34350000
    0x0000436F, // .4byte 0x0000436F
    0x6E736F6C, // .4byte 0x6E736F6C
    0x65205479, // .4byte 0x65205479
    0x7065203A, // .4byte 0x7065203A
    0x20005265, // .4byte 0x20005265
    0x7461696C, // .4byte 0x7461696C
    0x2025640A, // .4byte 0x2025640A
    0x00004D61, // .4byte 0x00004D61
    0x6320456D, // .4byte 0x6320456D
    0x756C6174, // .4byte 0x756C6174
    0x6F720A00, // .4byte 0x6F720A00
    0x00005043, // .4byte 0x00005043
    0x20456D75, // .4byte 0x20456D75
    0x6C61746F, // .4byte 0x6C61746F
    0x720A0000, // .4byte 0x720A0000
    0x00004550, // .4byte 0x00004550
    0x50432041, // .4byte 0x50432041
    0x72746875, // .4byte 0x72746875
    0x720A0000, // .4byte 0x720A0000
    0x00004550, // .4byte 0x00004550
    0x5043204D, // .4byte 0x5043204D
    0x696E6E6F, // .4byte 0x696E6E6F
    0x770A0000, // .4byte 0x770A0000
    0x00004465, // .4byte 0x00004465
    0x76656C6F, // .4byte 0x76656C6F
    0x706D656E, // .4byte 0x706D656E
    0x74204857, // .4byte 0x74204857
    0x25640A00, // .4byte 0x25640A00
    0x00004D65, // .4byte 0x00004D65
    0x6D6F7279, // .4byte 0x6D6F7279
    0x20256420, // .4byte 0x20256420
    0x4D420A00, // .4byte 0x4D420A00
    0x00004172, // .4byte 0x00004172
    0x656E6120, // .4byte 0x656E6120
    0x3A203078, // .4byte 0x3A203078
    0x2578202D, // .4byte 0x2578202D
    0x20307825, // .4byte 0x20307825
    0x780A0000, // .4byte 0x780A0000
    0x00000000, // .4byte 0x00000000
    0x01000000, // .4byte 0x01000000
    0x02000000, // .4byte 0x02000000
    0x03000000, // .4byte 0x03000000
    0x04000000, // .4byte 0x04000000
    0x05000000, // .4byte 0x05000000
    0x06000000, // .4byte 0x06000000
    0x07000000, // .4byte 0x07000000
    0x08000000, // .4byte 0x08000000
    0x09000000, // .4byte 0x09000000
    0x0C000000, // .4byte 0x0C000000
    0x0D000000, // .4byte 0x0D000000
    0x0F000000, // .4byte 0x0F000000
    0x13000000, // .4byte 0x13000000
    0x14000000, // .4byte 0x14000000
    0x1700496E, // .4byte 0x1700496E
    0x7374616C, // .4byte 0x7374616C
    0x6C696E67, // .4byte 0x6C696E67
    0x204F5344, // .4byte 0x204F5344
    0x42496E74, // .4byte 0x42496E74
    0x65677261, // .4byte 0x65677261
    0x746F720A, // .4byte 0x746F720A
    0x00003E3E, // .4byte 0x00003E3E
    0x3E204F53, // .4byte 0x3E204F53
    0x494E4954, // .4byte 0x494E4954
    0x3A206578, // .4byte 0x3A206578
    0x63657074, // .4byte 0x63657074
    0x696F6E20, // .4byte 0x696F6E20
    0x25642063, // .4byte 0x25642063
    0x6F6D6D61, // .4byte 0x6F6D6D61
    0x6E646565, // .4byte 0x6E646565
    0x72656420, // .4byte 0x72656420
    0x62792054, // .4byte 0x62792054
    0x524B0A00, // .4byte 0x524B0A00
    0x00003E3E, // .4byte 0x00003E3E
    0x3E204F53, // .4byte 0x3E204F53
    0x494E4954, // .4byte 0x494E4954
    0x3A206578, // .4byte 0x3A206578
    0x63657074, // .4byte 0x63657074
    0x696F6E20, // .4byte 0x696F6E20
    0x25642076, // .4byte 0x25642076
    0x6563746F, // .4byte 0x6563746F
    0x72656420, // .4byte 0x72656420
    0x746F2064, // .4byte 0x746F2064
    0x65627567, // .4byte 0x65627567
    0x6765720A, // .4byte 0x6765720A
    0x00004578, // .4byte 0x00004578
    0x63657074, // .4byte 0x63657074
    0x696F6E73, // .4byte 0x696F6E73
    0x20696E69, // .4byte 0x20696E69
    0x7469616C, // .4byte 0x7469616C
    0x697A6564, // .4byte 0x697A6564
    0x2E2E2E0A, // .4byte 0x2E2E2E0A
    0x00000000, // .4byte 0x00000000
    // Unrecognized: .2byte 0x0000
};

// Data section: DSPInitCode_8001A8A0
// Address: 0x8001A8A0
uint32_t DSPInitCode_8001A8A0[] = {
    0x029F0010, // .4byte 0x029F0010
    0x029F0033, // .4byte 0x029F0033
    0x029F0034, // .4byte 0x029F0034
    0x029F0035, // .4byte 0x029F0035
    0x029F0036, // .4byte 0x029F0036
    0x029F0037, // .4byte 0x029F0037
    0x029F0038, // .4byte 0x029F0038
    0x029F0039, // .4byte 0x029F0039
    0x12061203, // .4byte 0x12061203
    0x12041205, // .4byte 0x12041205
    0x00808000, // .4byte 0x00808000
    0x0088FFFF, // .4byte 0x0088FFFF
    0x00841000, // .4byte 0x00841000
    0x0064001D, // .4byte 0x0064001D
    0x02180000, // .4byte 0x02180000
    0x81001C1E, // .4byte 0x81001C1E
    0x00441B1E, // .4byte 0x00441B1E
    0x00840800, // .4byte 0x00840800
    0x00640027, // .4byte 0x00640027
    0x191E0000, // .4byte 0x191E0000
    0x00DEFFFC, // .4byte 0x00DEFFFC
    0x02A08000, // .4byte 0x02A08000
    0x029C0028, // .4byte 0x029C0028
    0x16FC0054, // .4byte 0x16FC0054
    0x16FD4348, // .4byte 0x16FD4348
    0x002102FF, // .4byte 0x002102FF
    0x02FF02FF, // .4byte 0x02FF02FF
    0x02FF02FF, // .4byte 0x02FF02FF
    0x02FF02FF, // .4byte 0x02FF02FF
    0x00000000, // .4byte 0x00000000
    0x00000000, // .4byte 0x00000000
    0x00000000, // .4byte 0x00000000
};

// Data section: @69_8001A920
// Address: 0x8001A920
uint32_t @69_8001A920[] = {
    // Unrecognized: .string ">>> L2 INVALIDATE : SHOULD NEVER HAPPEN\n"
};

// Data section: gap_05_8001A949_data
// Address: 0x8001A949
uint32_t gap_05_8001A949_data[] = {
    0x0000004D, // .4byte 0x0000004D
    0x61636869, // .4byte 0x61636869
    0x6E652063, // .4byte 0x6E652063
    0x6865636B, // .4byte 0x6865636B
    0x20726563, // .4byte 0x20726563
    0x65697665, // .4byte 0x65697665
    0x640A0048, // .4byte 0x640A0048
    0x49443220, // .4byte 0x49443220
    0x3D203078, // .4byte 0x3D203078
    0x25782020, // .4byte 0x25782020
    0x20535252, // .4byte 0x20535252
    0x31203D20, // .4byte 0x31203D20
    0x30782578, // .4byte 0x30782578
    0x0A00004D, // .4byte 0x0A00004D
    0x61636869, // .4byte 0x61636869
    0x6E652063, // .4byte 0x6E652063
    0x6865636B, // .4byte 0x6865636B
    0x20776173, // .4byte 0x20776173
    0x206E6F74, // .4byte 0x206E6F74
    0x20444D41, // .4byte 0x20444D41
    0x2F6C6F63, // .4byte 0x2F6C6F63
    0x6B656420, // .4byte 0x6B656420
    0x63616368, // .4byte 0x63616368
    0x65207265, // .4byte 0x65207265
    0x6C617465, // .4byte 0x6C617465
    0x640A0044, // .4byte 0x640A0044
    0x4D414572, // .4byte 0x4D414572
    0x726F7248, // .4byte 0x726F7248
    0x616E646C, // .4byte 0x616E646C
    0x65722829, // .4byte 0x65722829
    0x3A20416E, // .4byte 0x3A20416E
    0x20657272, // .4byte 0x20657272
    0x6F72206F, // .4byte 0x6F72206F
    0x63637572, // .4byte 0x63637572
    0x72656420, // .4byte 0x72656420
    0x7768696C, // .4byte 0x7768696C
    0x65207072, // .4byte 0x65207072
    0x6F636573, // .4byte 0x6F636573
    0x73696E67, // .4byte 0x73696E67
    0x20444D41, // .4byte 0x20444D41
    0x2E0A0054, // .4byte 0x2E0A0054
    0x68652066, // .4byte 0x68652066
    0x6F6C6C6F, // .4byte 0x6F6C6C6F
    0x77696E67, // .4byte 0x77696E67
    0x20657272, // .4byte 0x20657272
    0x6F727320, // .4byte 0x6F727320
    0x68617665, // .4byte 0x68617665
    0x20626565, // .4byte 0x20626565
    0x6E206465, // .4byte 0x6E206465
    0x74656374, // .4byte 0x74656374
    0x65642061, // .4byte 0x65642061
    0x6E642063, // .4byte 0x6E642063
    0x6C656172, // .4byte 0x6C656172
    0x6564203A, // .4byte 0x6564203A
    0x0A000009, // .4byte 0x0A000009
    0x2D205265, // .4byte 0x2D205265
    0x71756573, // .4byte 0x71756573
    0x74656420, // .4byte 0x74656420
    0x61206C6F, // .4byte 0x61206C6F
    0x636B6564, // .4byte 0x636B6564
    0x20636163, // .4byte 0x20636163
    0x68652074, // .4byte 0x68652074
    0x61672074, // .4byte 0x61672074
    0x68617420, // .4byte 0x68617420
    0x77617320, // .4byte 0x77617320
    0x616C7265, // .4byte 0x616C7265
    0x61647920, // .4byte 0x61647920
    0x696E2074, // .4byte 0x696E2074
    0x68652063, // .4byte 0x68652063
    0x61636865, // .4byte 0x61636865
    0x0A000009, // .4byte 0x0A000009
    0x2D20444D, // .4byte 0x2D20444D
    0x41206174, // .4byte 0x41206174
    0x74656D70, // .4byte 0x74656D70
    0x74656420, // .4byte 0x74656420
    0x746F2061, // .4byte 0x746F2061
    0x63636573, // .4byte 0x63636573
    0x73206E6F, // .4byte 0x73206E6F
    0x726D616C, // .4byte 0x726D616C
    0x20636163, // .4byte 0x20636163
    0x68650A00, // .4byte 0x68650A00
    0x00000009, // .4byte 0x00000009
    0x2D20444D, // .4byte 0x2D20444D
    0x41206D69, // .4byte 0x41206D69
    0x73736564, // .4byte 0x73736564
    0x20696E20, // .4byte 0x20696E20
    0x64617461, // .4byte 0x64617461
    0x20636163, // .4byte 0x20636163
    0x68650A00, // .4byte 0x68650A00
    0x00000009, // .4byte 0x00000009
    0x2D20444D, // .4byte 0x2D20444D
    0x41207175, // .4byte 0x41207175
    0x65756520, // .4byte 0x65756520
    0x6F766572, // .4byte 0x6F766572
    0x666C6F77, // .4byte 0x666C6F77
    0x65640A00, // .4byte 0x65640A00
    0x0000004C, // .4byte 0x0000004C
    0x3120692D, // .4byte 0x3120692D
    0x63616368, // .4byte 0x63616368
    0x65732069, // .4byte 0x65732069
    0x6E697469, // .4byte 0x6E697469
    0x616C697A, // .4byte 0x616C697A
    0x65640A00, // .4byte 0x65640A00
    0x0000004C, // .4byte 0x0000004C
    0x3120642D, // .4byte 0x3120642D
    0x63616368, // .4byte 0x63616368
    0x65732069, // .4byte 0x65732069
    0x6E697469, // .4byte 0x6E697469
    0x616C697A, // .4byte 0x616C697A
    0x65640A00, // .4byte 0x65640A00
    0x0000004C, // .4byte 0x0000004C
    0x32206361, // .4byte 0x32206361
    0x63686520, // .4byte 0x63686520
    0x696E6974, // .4byte 0x696E6974
    0x69616C69, // .4byte 0x69616C69
    0x7A65640A, // .4byte 0x7A65640A
    0x0000004C, // .4byte 0x0000004C
    0x6F636B65, // .4byte 0x6F636B65
    0x64206361, // .4byte 0x64206361
    0x63686520, // .4byte 0x63686520
    0x6D616368, // .4byte 0x6D616368
    0x696E6520, // .4byte 0x696E6520
    0x63686563, // .4byte 0x63686563
    0x6B206861, // .4byte 0x6B206861
    0x6E646C65, // .4byte 0x6E646C65
    0x7220696E, // .4byte 0x7220696E
    0x7374616C, // .4byte 0x7374616C
    0x6C65640A, // .4byte 0x6C65640A
    0x00000000, // .4byte 0x00000000
    // Unrecognized: .byte 0x00, 0x00, 0x00
};

// Data section: lbl_8001AB50
// Address: 0x8001AB50
uint32_t lbl_8001AB50[] = {
    0x2D2D2D2D, // .4byte 0x2D2D2D2D
    0x2D2D2D2D, // .4byte 0x2D2D2D2D
    0x2D2D2D2D, // .4byte 0x2D2D2D2D
    0x2D2D2D2D, // .4byte 0x2D2D2D2D
    0x2D2D2D2D, // .4byte 0x2D2D2D2D
    0x2D2D2D2D, // .4byte 0x2D2D2D2D
    0x2D20436F, // .4byte 0x2D20436F
    0x6E746578, // .4byte 0x6E746578
    0x74203078, // .4byte 0x74203078
    0x25303878, // .4byte 0x25303878
    0x202D2D2D, // .4byte 0x202D2D2D
    0x2D2D2D2D, // .4byte 0x2D2D2D2D
    0x2D2D2D2D, // .4byte 0x2D2D2D2D
    0x2D2D2D2D, // .4byte 0x2D2D2D2D
    0x2D2D2D2D, // .4byte 0x2D2D2D2D
    0x2D2D2D2D, // .4byte 0x2D2D2D2D
    0x2D2D0A00, // .4byte 0x2D2D0A00
    0x72252D32, // .4byte 0x72252D32
    0x6420203D, // .4byte 0x6420203D
    0x20307825, // .4byte 0x20307825
    0x30387820, // .4byte 0x30387820
    0x28253134, // .4byte 0x28253134
    0x64292020, // .4byte 0x64292020
    0x72252D32, // .4byte 0x72252D32
    0x6420203D, // .4byte 0x6420203D
    0x20307825, // .4byte 0x20307825
    0x30387820, // .4byte 0x30387820
    0x28253134, // .4byte 0x28253134
    0x64290A00, // .4byte 0x64290A00
    0x4C522020, // .4byte 0x4C522020
    0x203D2030, // .4byte 0x203D2030
    0x78253038, // .4byte 0x78253038
    0x78202020, // .4byte 0x78202020
    0x20202020, // .4byte 0x20202020
    0x20202020, // .4byte 0x20202020
    0x20202020, // .4byte 0x20202020
    0x20202020, // .4byte 0x20202020
    0x43522020, // .4byte 0x43522020
    0x203D2030, // .4byte 0x203D2030
    0x78253038, // .4byte 0x78253038
    0x780A0000, // .4byte 0x780A0000
    0x53525230, // .4byte 0x53525230
    0x203D2030, // .4byte 0x203D2030
    0x78253038, // .4byte 0x78253038
    0x78202020, // .4byte 0x78202020
    0x20202020, // .4byte 0x20202020
    0x20202020, // .4byte 0x20202020
    0x20202020, // .4byte 0x20202020
    0x20202020, // .4byte 0x20202020
    0x53525231, // .4byte 0x53525231
    0x203D2030, // .4byte 0x203D2030
    0x78253038, // .4byte 0x78253038
    0x780A0000, // .4byte 0x780A0000
    0x0A475152, // .4byte 0x0A475152
    0x732D2D2D, // .4byte 0x732D2D2D
    0x2D2D2D2D, // .4byte 0x2D2D2D2D
    0x2D2D2D0A, // .4byte 0x2D2D2D0A
    0x00000000, // .4byte 0x00000000
    0x67717225, // .4byte 0x67717225
    0x64203D20, // .4byte 0x64203D20
    0x30782530, // .4byte 0x30782530
    0x38782009, // .4byte 0x38782009
    0x20677172, // .4byte 0x20677172
    0x2564203D, // .4byte 0x2564203D
    0x20307825, // .4byte 0x20307825
    0x3038780A, // .4byte 0x3038780A
    0x00000000, // .4byte 0x00000000
    0x0A0A4650, // .4byte 0x0A0A4650
    0x52732D2D, // .4byte 0x52732D2D
    0x2D2D2D2D, // .4byte 0x2D2D2D2D
    0x2D2D2D2D, // .4byte 0x2D2D2D2D
    0x0A000000, // .4byte 0x0A000000
    0x66722564, // .4byte 0x66722564
    0x20093D20, // .4byte 0x20093D20
    0x25642009, // .4byte 0x25642009
    0x20667225, // .4byte 0x20667225
    0x6420093D, // .4byte 0x6420093D
    0x2025640A, // .4byte 0x2025640A
    0x00000000, // .4byte 0x00000000
    0x0A0A5053, // .4byte 0x0A0A5053
    0x46732D2D, // .4byte 0x46732D2D
    0x2D2D2D2D, // .4byte 0x2D2D2D2D
    0x2D2D2D2D, // .4byte 0x2D2D2D2D
    0x0A000000, // .4byte 0x0A000000
    0x70732564, // .4byte 0x70732564
    0x20093D20, // .4byte 0x20093D20
    0x30782578, // .4byte 0x30782578
    0x20092070, // .4byte 0x20092070
    0x73256420, // .4byte 0x73256420
    0x093D2030, // .4byte 0x093D2030
    0x7825780A, // .4byte 0x7825780A
    0x00000000, // .4byte 0x00000000
    0x0A416464, // .4byte 0x0A416464
    0x72657373, // .4byte 0x72657373
    0x3A202020, // .4byte 0x3A202020
    0x20202042, // .4byte 0x20202042
    0x61636B20, // .4byte 0x61636B20
    0x43686169, // .4byte 0x43686169
    0x6E202020, // .4byte 0x6E202020
    0x204C5220, // .4byte 0x204C5220
    0x53617665, // .4byte 0x53617665
    0x0A000000, // .4byte 0x0A000000
    0x30782530, // .4byte 0x30782530
    0x38783A20, // .4byte 0x38783A20
    0x20203078, // .4byte 0x20203078
    0x25303878, // .4byte 0x25303878
    0x20202020, // .4byte 0x20202020
    0x30782530, // .4byte 0x30782530
    0x38780A00, // .4byte 0x38780A00
};

// Data section: @74_8001AD04
// Address: 0x8001AD04
uint32_t @74_8001AD04[] = {
    // Unrecognized: .string "FPU-unavailable handler installed\n"
};

// Data section: gap_05_8001AD27_data
// Address: 0x8001AD27
uint32_t gap_05_8001AD27_data[] = {
    // Unrecognized: .byte 0x00
};

// Data section: @10_8001AD28
// Address: 0x8001AD28
uint32_t @10_8001AD28[] = {
    // Unrecognized: .string " in \"%s\" on line %d.\n"
};

// Data section: gap_05_8001AD3E_data
// Address: 0x8001AD3E
uint32_t gap_05_8001AD3E_data[] = {
    0x00000A41, // .4byte 0x00000A41
    0x64647265, // .4byte 0x64647265
    0x73733A20, // .4byte 0x73733A20
    0x20202020, // .4byte 0x20202020
    0x20426163, // .4byte 0x20426163
    0x6B204368, // .4byte 0x6B204368
    0x61696E20, // .4byte 0x61696E20
    0x2020204C, // .4byte 0x2020204C
    0x52205361, // .4byte 0x52205361
    0x76650A00, // .4byte 0x76650A00
    0x00003078, // .4byte 0x00003078
    0x25303878, // .4byte 0x25303878
    0x3A202020, // .4byte 0x3A202020
    0x30782530, // .4byte 0x30782530
    0x38782020, // .4byte 0x38782020
    0x20203078, // .4byte 0x20203078
    0x25303878, // .4byte 0x25303878
    0x0A004E6F, // .4byte 0x0A004E6F
    0x6E2D7265, // .4byte 0x6E2D7265
    0x636F7665, // .4byte 0x636F7665
    0x7261626C, // .4byte 0x7261626C
    0x65204578, // .4byte 0x65204578
    0x63657074, // .4byte 0x63657074
    0x696F6E20, // .4byte 0x696F6E20
    0x25640000, // .4byte 0x25640000
    0x0000556E, // .4byte 0x0000556E
    0x68616E64, // .4byte 0x68616E64
    0x6C656420, // .4byte 0x6C656420
    0x45786365, // .4byte 0x45786365
    0x7074696F, // .4byte 0x7074696F
    0x6E202564, // .4byte 0x6E202564
    0x00000A44, // .4byte 0x00000A44
    0x53495352, // .4byte 0x53495352
    0x203D2030, // .4byte 0x203D2030
    0x78253038, // .4byte 0x78253038
    0x78202020, // .4byte 0x78202020
    0x20202020, // .4byte 0x20202020
    0x20202020, // .4byte 0x20202020
    0x20202020, // .4byte 0x20202020
    0x20202020, // .4byte 0x20202020
    0x44415220, // .4byte 0x44415220
    0x203D2030, // .4byte 0x203D2030
    0x78253038, // .4byte 0x78253038
    0x780A0000, // .4byte 0x780A0000
    0x00005442, // .4byte 0x00005442
    0x203D2030, // .4byte 0x203D2030
    0x78253031, // .4byte 0x78253031
    0x366C6C78, // .4byte 0x366C6C78
    0x0A000A49, // .4byte 0x0A000A49
    0x6E737472, // .4byte 0x6E737472
    0x75637469, // .4byte 0x75637469
    0x6F6E2061, // .4byte 0x6F6E2061
    0x74203078, // .4byte 0x74203078
    0x25782028, // .4byte 0x25782028
    0x72656164, // .4byte 0x72656164
    0x2066726F, // .4byte 0x2066726F
    0x6D205352, // .4byte 0x6D205352
    0x52302920, // .4byte 0x52302920
    0x61747465, // .4byte 0x61747465
    0x6D707465, // .4byte 0x6D707465
    0x6420746F, // .4byte 0x6420746F
    0x20616363, // .4byte 0x20616363
    0x65737320, // .4byte 0x65737320
    0x696E7661, // .4byte 0x696E7661
    0x6C696420, // .4byte 0x6C696420
    0x61646472, // .4byte 0x61646472
    0x65737320, // .4byte 0x65737320
    0x30782578, // .4byte 0x30782578
    0x20287265, // .4byte 0x20287265
    0x61642066, // .4byte 0x61642066
    0x726F6D20, // .4byte 0x726F6D20
    0x44415229, // .4byte 0x44415229
    0x0A000A41, // .4byte 0x0A000A41
    0x7474656D, // .4byte 0x7474656D
    0x70746564, // .4byte 0x70746564
    0x20746F20, // .4byte 0x20746F20
    0x66657463, // .4byte 0x66657463
    0x6820696E, // .4byte 0x6820696E
    0x73747275, // .4byte 0x73747275
    0x6374696F, // .4byte 0x6374696F
    0x6E206672, // .4byte 0x6E206672
    0x6F6D2069, // .4byte 0x6F6D2069
    0x6E76616C, // .4byte 0x6E76616C
    0x69642061, // .4byte 0x69642061
    0x64647265, // .4byte 0x64647265
    0x73732030, // .4byte 0x73732030
    0x78257820, // .4byte 0x78257820
    0x28726561, // .4byte 0x28726561
    0x64206672, // .4byte 0x64206672
    0x6F6D2053, // .4byte 0x6F6D2053
    0x52523029, // .4byte 0x52523029
    0x0A000A49, // .4byte 0x0A000A49
    0x6E737472, // .4byte 0x6E737472
    0x75637469, // .4byte 0x75637469
    0x6F6E2061, // .4byte 0x6F6E2061
    0x74203078, // .4byte 0x74203078
    0x25782028, // .4byte 0x25782028
    0x72656164, // .4byte 0x72656164
    0x2066726F, // .4byte 0x2066726F
    0x6D205352, // .4byte 0x6D205352
    0x52302920, // .4byte 0x52302920
    0x61747465, // .4byte 0x61747465
    0x6D707465, // .4byte 0x6D707465
    0x6420746F, // .4byte 0x6420746F
    0x20616363, // .4byte 0x20616363
    0x65737320, // .4byte 0x65737320
    0x756E616C, // .4byte 0x756E616C
    0x69676E65, // .4byte 0x69676E65
    0x64206164, // .4byte 0x64206164
    0x64726573, // .4byte 0x64726573
    0x73203078, // .4byte 0x73203078
    0x25782028, // .4byte 0x25782028
    0x72656164, // .4byte 0x72656164
    0x2066726F, // .4byte 0x2066726F
    0x6D204441, // .4byte 0x6D204441
    0x52290A00, // .4byte 0x52290A00
    0x00000A50, // .4byte 0x00000A50
    0x726F6772, // .4byte 0x726F6772
    0x616D2065, // .4byte 0x616D2065
    0x78636570, // .4byte 0x78636570
    0x74696F6E, // .4byte 0x74696F6E
    0x203A2050, // .4byte 0x203A2050
    0x6F737369, // .4byte 0x6F737369
    0x626C6520, // .4byte 0x626C6520
    0x696C6C65, // .4byte 0x696C6C65
    0x67616C20, // .4byte 0x67616C20
    0x696E7374, // .4byte 0x696E7374
    0x72756374, // .4byte 0x72756374
    0x696F6E2F, // .4byte 0x696F6E2F
    0x6F706572, // .4byte 0x6F706572
    0x6174696F, // .4byte 0x6174696F
    0x6E206174, // .4byte 0x6E206174
    0x206F7220, // .4byte 0x206F7220
    0x61726F75, // .4byte 0x61726F75
    0x6E642030, // .4byte 0x6E642030
    0x78257820, // .4byte 0x78257820
    0x28726561, // .4byte 0x28726561
    0x64206672, // .4byte 0x64206672
    0x6F6D2053, // .4byte 0x6F6D2053
    0x52523029, // .4byte 0x52523029
    0x0A004149, // .4byte 0x0A004149
    0x20444D41, // .4byte 0x20444D41
    0x20416464, // .4byte 0x20416464
    0x72657373, // .4byte 0x72657373
    0x203D2020, // .4byte 0x203D2020
    0x20307825, // .4byte 0x20307825
    0x30347825, // .4byte 0x30347825
    0x3034780A, // .4byte 0x3034780A
    0x00004152, // .4byte 0x00004152
    0x414D2044, // .4byte 0x414D2044
    0x4D412041, // .4byte 0x4D412041
    0x64647265, // .4byte 0x64647265
    0x7373203D, // .4byte 0x7373203D
    0x20307825, // .4byte 0x20307825
    0x30347825, // .4byte 0x30347825
    0x3034780A, // .4byte 0x3034780A
    0x00004449, // .4byte 0x00004449
    0x20444D41, // .4byte 0x20444D41
    0x20416464, // .4byte 0x20416464
    0x72657373, // .4byte 0x72657373
    0x203D2020, // .4byte 0x203D2020
    0x20307825, // .4byte 0x20307825
    0x3038780A, // .4byte 0x3038780A
    0x00000A4C, // .4byte 0x00000A4C
    0x61737420, // .4byte 0x61737420
    0x696E7465, // .4byte 0x696E7465
    0x72727570, // .4byte 0x72727570
    0x74202825, // .4byte 0x74202825
    0x64293A20, // .4byte 0x64293A20
    0x53525230, // .4byte 0x53525230
    0x203D2030, // .4byte 0x203D2030
    0x78253038, // .4byte 0x78253038
    0x78202054, // .4byte 0x78202054
    0x42203D20, // .4byte 0x42203D20
    0x30782530, // .4byte 0x30782530
    0x31366C6C, // .4byte 0x31366C6C
    0x780A0000, // .4byte 0x780A0000
    // Unrecognized: .2byte 0x0000
};

// Data section: @43_8001B004
// Address: 0x8001B004
uint32_t @43_8001B004[] = {
    // Unrecognized: .4byte __OSUnhandledException+0x1CC
    // Unrecognized: .4byte __OSUnhandledException+0x1CC
    // Unrecognized: .4byte __OSUnhandledException+0x124
    // Unrecognized: .4byte __OSUnhandledException+0x13C
    // Unrecognized: .4byte __OSUnhandledException+0x1CC
    // Unrecognized: .4byte __OSUnhandledException+0x150
    // Unrecognized: .4byte __OSUnhandledException+0x168
    // Unrecognized: .4byte __OSUnhandledException+0x1CC
    // Unrecognized: .4byte __OSUnhandledException+0x1CC
    // Unrecognized: .4byte __OSUnhandledException+0x1CC
    // Unrecognized: .4byte __OSUnhandledException+0x1CC
    // Unrecognized: .4byte __OSUnhandledException+0x1CC
    // Unrecognized: .4byte __OSUnhandledException+0x1CC
    // Unrecognized: .4byte __OSUnhandledException+0x1CC
    // Unrecognized: .4byte __OSUnhandledException+0x1CC
    // Unrecognized: .4byte __OSUnhandledException+0x180
};

// Data section: gap_05_8001B044_data
// Address: 0x8001B044
uint32_t gap_05_8001B044_data[] = {
    0x00000000, // .4byte 0x00000000
};

// Data section: lbl_8001B048
// Address: 0x8001B048
uint32_t lbl_8001B048[] = {
    0x00000100, // .4byte 0x00000100
    0x00000040, // .4byte 0x00000040
    0xF8000000, // .4byte 0xF8000000
    0x00000200, // .4byte 0x00000200
    0x00000080, // .4byte 0x00000080
    0x00003000, // .4byte 0x00003000
    0x00000020, // .4byte 0x00000020
    0x03FF8C00, // .4byte 0x03FF8C00
    0x04000000, // .4byte 0x04000000
    0x00004000, // .4byte 0x00004000
    0xFFFFFFFF, // .4byte 0xFFFFFFFF
    0x00000000, // .4byte 0x00000000
};

// Data section: ResetFunctionInfo_8001B078
// Address: 0x8001B078
uint32_t ResetFunctionInfo_8001B078[] = {
    // Unrecognized: .4byte fn_80007FE0
    0x0000007F, // .4byte 0x0000007F
    0x00000000, // .4byte 0x00000000
    0x00000000, // .4byte 0x00000000
};

// Data section: Si_8001B088
// Address: 0x8001B088
uint32_t Si_8001B088[] = {
    0xFFFFFFFF, // .4byte 0xFFFFFFFF
    0x00000000, // .4byte 0x00000000
    0x00000000, // .4byte 0x00000000
    0x00000000, // .4byte 0x00000000
    0x00000000, // .4byte 0x00000000
};

// Data section: Type_8001B09C
// Address: 0x8001B09C
uint32_t Type_8001B09C[] = {
    0x00000008, // .4byte 0x00000008
    0x00000008, // .4byte 0x00000008
    0x00000008, // .4byte 0x00000008
    0x00000008, // .4byte 0x00000008
};

// Data section: gap_05_8001B0AC_data
// Address: 0x8001B0AC
uint32_t gap_05_8001B0AC_data[] = {
    0x4E6F2072, // .4byte 0x4E6F2072
    0x6573706F, // .4byte 0x6573706F
    0x6E736500, // .4byte 0x6E736500
    0x4E363420, // .4byte 0x4E363420
    0x636F6E74, // .4byte 0x636F6E74
    0x726F6C6C, // .4byte 0x726F6C6C
    0x65720000, // .4byte 0x65720000
    0x4E363420, // .4byte 0x4E363420
    0x6D696372, // .4byte 0x6D696372
    0x6F70686F, // .4byte 0x6F70686F
    0x6E650000, // .4byte 0x6E650000
    0x4E363420, // .4byte 0x4E363420
    0x6B657962, // .4byte 0x6B657962
    0x6F617264, // .4byte 0x6F617264
    0x00000000, // .4byte 0x00000000
    0x4E363420, // .4byte 0x4E363420
    0x6D6F7573, // .4byte 0x6D6F7573
    0x65000000, // .4byte 0x65000000
    0x47616D65, // .4byte 0x47616D65
    0x426F7920, // .4byte 0x426F7920
    0x41647661, // .4byte 0x41647661
    0x6E636500, // .4byte 0x6E636500
    0x5374616E, // .4byte 0x5374616E
    0x64617264, // .4byte 0x64617264
    0x20636F6E, // .4byte 0x20636F6E
    0x74726F6C, // .4byte 0x74726F6C
    0x6C657200, // .4byte 0x6C657200
    0x57697265, // .4byte 0x57697265
    0x6C657373, // .4byte 0x6C657373
    0x20726563, // .4byte 0x20726563
    0x65697665, // .4byte 0x65697665
    0x72000000, // .4byte 0x72000000
    0x57617665, // .4byte 0x57617665
    0x42697264, // .4byte 0x42697264
    0x20636F6E, // .4byte 0x20636F6E
    0x74726F6C, // .4byte 0x74726F6C
    0x6C657200, // .4byte 0x6C657200
    0x4B657962, // .4byte 0x4B657962
    0x6F617264, // .4byte 0x6F617264
    0x00000000, // .4byte 0x00000000
    0x53746565, // .4byte 0x53746565
    0x72696E67, // .4byte 0x72696E67
    0x00000000, // .4byte 0x00000000
};

// Data section: XYNTSC_8001B158
// Address: 0x8001B158
uint32_t XYNTSC_8001B158[] = {
    0x00F60200, // .4byte 0x00F60200
    0x000F1200, // .4byte 0x000F1200
    0x001E0900, // .4byte 0x001E0900
    0x002C0600, // .4byte 0x002C0600
    0x00340500, // .4byte 0x00340500
    0x00410400, // .4byte 0x00410400
    0x00570300, // .4byte 0x00570300
    0x00570300, // .4byte 0x00570300
    0x00570300, // .4byte 0x00570300
    0x00830200, // .4byte 0x00830200
    0x00830200, // .4byte 0x00830200
    0x00830200, // .4byte 0x00830200
};

// Data section: gap_05_8001B188_data
// Address: 0x8001B188
uint32_t gap_05_8001B188_data[] = {
    0x01280200, // .4byte 0x01280200
    0x000F1500, // .4byte 0x000F1500
    0x001D0B00, // .4byte 0x001D0B00
    0x002D0700, // .4byte 0x002D0700
    0x00340600, // .4byte 0x00340600
    0x003F0500, // .4byte 0x003F0500
    0x004E0400, // .4byte 0x004E0400
    0x00680300, // .4byte 0x00680300
    0x00680300, // .4byte 0x00680300
    0x00680300, // .4byte 0x00680300
    0x00680300, // .4byte 0x00680300
    0x009C0200, // .4byte 0x009C0200
    0x53495365, // .4byte 0x53495365
    0x7453616D, // .4byte 0x7453616D
    0x706C696E, // .4byte 0x706C696E
    0x67526174, // .4byte 0x67526174
    0x653A2075, // .4byte 0x653A2075
    0x6E6B6E6F, // .4byte 0x6E6B6E6F
    0x776E2054, // .4byte 0x776E2054
    0x5620666F, // .4byte 0x5620666F
    0x726D6174, // .4byte 0x726D6174
    0x2E205573, // .4byte 0x2E205573
    0x65206465, // .4byte 0x65206465
    0x6661756C, // .4byte 0x6661756C
    0x742E0000, // .4byte 0x742E0000
    0x00000000, // .4byte 0x00000000
};

// Data section: lbl_8001B1F0
// Address: 0x8001B1F0
uint32_t lbl_8001B1F0[] = {
    // Unrecognized: .string "DBExceptionDestination\n"
};

// Data section: lbl_8001B208
// Address: 0x8001B208
uint32_t lbl_8001B208[] = {
    0x61707020, // .4byte 0x61707020
    0x626F6F74, // .4byte 0x626F6F74
    0x65642076, // .4byte 0x65642076
    0x6961204A, // .4byte 0x6961204A
    0x5441470A, // .4byte 0x5441470A
    0x00000000, // .4byte 0x00000000
    0x6C6F6164, // .4byte 0x6C6F6164
    0x20667374, // .4byte 0x20667374
    0x0A000000, // .4byte 0x0A000000
    0x61707020, // .4byte 0x61707020
    0x626F6F74, // .4byte 0x626F6F74
    0x65642066, // .4byte 0x65642066
    0x726F6D20, // .4byte 0x726F6D20
    0x626F6F74, // .4byte 0x626F6F74
    0x726F6D0A, // .4byte 0x726F6D0A
    0x00000000, // .4byte 0x00000000
    0x626F6F74, // .4byte 0x626F6F74
    0x726F6D0A, // .4byte 0x726F6D0A
    0x00000000, // .4byte 0x00000000
};

// Data section: jumptable_8001B254
// Address: 0x8001B254
uint32_t jumptable_8001B254[] = {
    // Unrecognized: .4byte fn_8000E240+0x218
    // Unrecognized: .4byte fn_8000E240+0xD8
    // Unrecognized: .4byte fn_8000E240+0xF0
    // Unrecognized: .4byte fn_8000E240+0x108
    // Unrecognized: .4byte fn_8000E240+0x138
    // Unrecognized: .4byte fn_8000E240+0x1FC
    // Unrecognized: .4byte fn_8000E240+0x150
    // Unrecognized: .4byte fn_8000E240+0x120
};

// Data section: jumptable_8001B274
// Address: 0x8001B274
uint32_t jumptable_8001B274[] = {
    // Unrecognized: .4byte fn_8000E488+0x2B0
    // Unrecognized: .4byte fn_8000E488+0x6C
    // Unrecognized: .4byte fn_8000E488+0xC8
    // Unrecognized: .4byte fn_8000E488+0xEC
    // Unrecognized: .4byte fn_8000E488+0x6C
    // Unrecognized: .4byte fn_8000E488+0x40
    // Unrecognized: .4byte fn_8000E488+0x10C
    // Unrecognized: .4byte fn_8000E488+0x170
    // Unrecognized: .4byte fn_8000E488+0x19C
    // Unrecognized: .4byte fn_8000E488+0x1D0
    // Unrecognized: .4byte fn_8000E488+0x1F4
    // Unrecognized: .4byte fn_8000E488+0x218
    // Unrecognized: .4byte fn_8000E488+0x23C
    // Unrecognized: .4byte fn_8000E488+0x260
    // Unrecognized: .4byte fn_8000E488+0x288
    // Unrecognized: .4byte fn_8000E488+0xFC
};

// Data section: jumptable_8001B2B4
// Address: 0x8001B2B4
uint32_t jumptable_8001B2B4[] = {
    // Unrecognized: .4byte fn_8000EFC0+0x50
    // Unrecognized: .4byte fn_8000EFC0+0x50
    // Unrecognized: .4byte fn_8000EFC0+0x70
    // Unrecognized: .4byte fn_8000EFC0+0xB4
    // Unrecognized: .4byte fn_8000EFC0+0x100
    // Unrecognized: .4byte fn_8000EFC0+0x17C
    // Unrecognized: .4byte fn_8000EFC0+0x17C
    // Unrecognized: .4byte fn_8000EFC0+0x17C
    // Unrecognized: .4byte fn_8000EFC0+0x17C
    // Unrecognized: .4byte fn_8000EFC0+0x248
    // Unrecognized: .4byte fn_8000EFC0+0x248
    // Unrecognized: .4byte fn_8000EFC0+0x50
    // Unrecognized: .4byte fn_8000EFC0+0x17C
};

// Data section: jumptable_8001B2E8
// Address: 0x8001B2E8
uint32_t jumptable_8001B2E8[] = {
    // Unrecognized: .4byte fn_8000F238+0x98
    // Unrecognized: .4byte fn_8000F238+0xA0
    // Unrecognized: .4byte fn_8000F238+0x90
    // Unrecognized: .4byte fn_8000F238+0x90
    // Unrecognized: .4byte fn_8000F238+0x98
    // Unrecognized: .4byte fn_8000F238+0x98
    // Unrecognized: .4byte fn_8000F238+0x98
    // Unrecognized: .4byte fn_8000F238+0x98
    // Unrecognized: .4byte fn_8000F238+0x98
    // Unrecognized: .4byte fn_8000F238+0xA0
    // Unrecognized: .4byte fn_8000F238+0x90
    // Unrecognized: .4byte fn_8000F238+0x90
    // Unrecognized: .4byte fn_8000F238+0x98
};

// Data section: gap_05_8001B31C_data
// Address: 0x8001B31C
uint32_t gap_05_8001B31C_data[] = {
    0x00000000, // .4byte 0x00000000
};

// Data section: lbl_8001B320
// Address: 0x8001B320
uint32_t lbl_8001B320[] = {
    0x00000000, // .4byte 0x00000000
    0x00023A00, // .4byte 0x00023A00
    0x00062800, // .4byte 0x00062800
    0x00030200, // .4byte 0x00030200
    0x00031100, // .4byte 0x00031100
    0x00052000, // .4byte 0x00052000
    0x00052001, // .4byte 0x00052001
    0x00052100, // .4byte 0x00052100
    0x00052400, // .4byte 0x00052400
    0x00052401, // .4byte 0x00052401
    0x00052402, // .4byte 0x00052402
    0x000B5A01, // .4byte 0x000B5A01
    0x00056300, // .4byte 0x00056300
    0x00020401, // .4byte 0x00020401
    0x00020400, // .4byte 0x00020400
    0x00040800, // .4byte 0x00040800
    0x00100007, // .4byte 0x00100007
    0x00000000, // .4byte 0x00000000
};

// Data section: lbl_8001B368
// Address: 0x8001B368
uint32_t lbl_8001B368[] = {
    0x20204761, // .4byte 0x20204761
    0x6D65204E, // .4byte 0x6D65204E
    0x616D6520, // .4byte 0x616D6520
    0x2E2E2E20, // .4byte 0x2E2E2E20
    0x25632563, // .4byte 0x25632563
    0x25632563, // .4byte 0x25632563
    0x0A000000, // .4byte 0x0A000000
    0x2020436F, // .4byte 0x2020436F
    0x6D70616E, // .4byte 0x6D70616E
    0x79202E2E, // .4byte 0x79202E2E
    0x2E2E2E20, // .4byte 0x2E2E2E20
    0x25632563, // .4byte 0x25632563
    0x0A000000, // .4byte 0x0A000000
    0x20204469, // .4byte 0x20204469
    0x736B2023, // .4byte 0x736B2023
    0x202E2E2E, // .4byte 0x202E2E2E
    0x2E2E2E20, // .4byte 0x2E2E2E20
    0x25640A00, // .4byte 0x25640A00
    0x20204761, // .4byte 0x20204761
    0x6D652076, // .4byte 0x6D652076
    0x6572202E, // .4byte 0x6572202E
    0x2E2E2E20, // .4byte 0x2E2E2E20
    0x25640A00, // .4byte 0x25640A00
    0x20205374, // .4byte 0x20205374
    0x7265616D, // .4byte 0x7265616D
    0x696E6720, // .4byte 0x696E6720
    0x2E2E2E20, // .4byte 0x2E2E2E20
    0x25730A00, // .4byte 0x25730A00
};

// Data section: lbl_8001B3D8
// Address: 0x8001B3D8
uint32_t lbl_8001B3D8[] = {
    0x060000F0, // .4byte 0x060000F0
    0x00180019, // .4byte 0x00180019
    0x00030002, // .4byte 0x00030002
    0x0C0D0C0D, // .4byte 0x0C0D0C0D
    0x02080207, // .4byte 0x02080207
    0x02080207, // .4byte 0x02080207
    0x020D01AD, // .4byte 0x020D01AD
    0x404769A2, // .4byte 0x404769A2
    0x01757A00, // .4byte 0x01757A00
    0x019C0600, // .4byte 0x019C0600
    0x00F00018, // .4byte 0x00F00018
    0x00180004, // .4byte 0x00180004
    0x00040C0C, // .4byte 0x00040C0C
    0x0C0C0208, // .4byte 0x0C0C0208
    0x02080208, // .4byte 0x02080208
    0x0208020E, // .4byte 0x0208020E
    0x01AD4047, // .4byte 0x01AD4047
    0x69A20175, // .4byte 0x69A20175
    0x7A00019C, // .4byte 0x7A00019C
    0x0500011F, // .4byte 0x0500011F
    0x00230024, // .4byte 0x00230024
    0x00010000, // .4byte 0x00010000
    0x0D0C0B0A, // .4byte 0x0D0C0B0A
    0x026B026A, // .4byte 0x026B026A
    0x0269026C, // .4byte 0x0269026C
    0x027101B0, // .4byte 0x027101B0
    0x404B6AAC, // .4byte 0x404B6AAC
    0x017C8500, // .4byte 0x017C8500
    0x01A40500, // .4byte 0x01A40500
    0x011F0021, // .4byte 0x011F0021
    0x00210002, // .4byte 0x00210002
    0x00020D0B, // .4byte 0x00020D0B
    0x0D0B026B, // .4byte 0x0D0B026B
    0x026D026B, // .4byte 0x026D026B
    0x026D0270, // .4byte 0x026D0270
    0x01B0404B, // .4byte 0x01B0404B
    0x6AAC017C, // .4byte 0x6AAC017C
    0x850001A4, // .4byte 0x850001A4
    0x060000F0, // .4byte 0x060000F0
    0x00180019, // .4byte 0x00180019
    0x00030002, // .4byte 0x00030002
    0x100F0E0D, // .4byte 0x100F0E0D
    0x02060205, // .4byte 0x02060205
    0x02040207, // .4byte 0x02040207
    0x020D01AD, // .4byte 0x020D01AD
    0x404E70A2, // .4byte 0x404E70A2
    0x01757A00, // .4byte 0x01757A00
    0x019C0600, // .4byte 0x019C0600
    0x00F00018, // .4byte 0x00F00018
    0x00180004, // .4byte 0x00180004
    0x0004100E, // .4byte 0x0004100E
    0x100E0206, // .4byte 0x100E0206
    0x02080206, // .4byte 0x02080206
    0x0208020E, // .4byte 0x0208020E
    0x01AD404E, // .4byte 0x01AD404E
    0x70A20175, // .4byte 0x70A20175
    0x7A00019C, // .4byte 0x7A00019C
    0x0C0001E0, // .4byte 0x0C0001E0
    0x00300030, // .4byte 0x00300030
    0x00060006, // .4byte 0x00060006
    0x18181818, // .4byte 0x18181818
    0x040E040E, // .4byte 0x040E040E
    0x040E040E, // .4byte 0x040E040E
    0x041A01AD, // .4byte 0x041A01AD
    0x404769A2, // .4byte 0x404769A2
    0x01757A00, // .4byte 0x01757A00
    0x019C0C00, // .4byte 0x019C0C00
    0x01E0002C, // .4byte 0x01E0002C
    0x002C000A, // .4byte 0x002C000A
    0x000A1818, // .4byte 0x000A1818
    0x1818040E, // .4byte 0x1818040E
    0x040E040E, // .4byte 0x040E040E
    0x040E041A, // .4byte 0x040E041A
    0x01AD4047, // .4byte 0x01AD4047
    0x69A8017B, // .4byte 0x69A8017B
    0x7A00019C, // .4byte 0x7A00019C
    0x01F001DC, // .4byte 0x01F001DC
    0x01AE0174, // .4byte 0x01AE0174
    0x012900DB, // .4byte 0x012900DB
    0x008E0046, // .4byte 0x008E0046
    0x000C00E2, // .4byte 0x000C00E2
    0x00CB00C0, // .4byte 0x00CB00C0
    0x00C400CF, // .4byte 0x00C400CF
    0x00DE00EC, // .4byte 0x00DE00EC
    0x00FC0008, // .4byte 0x00FC0008
    0x000F0013, // .4byte 0x000F0013
    0x0013000F, // .4byte 0x0013000F
    0x000C0008, // .4byte 0x000C0008
    0x00010000, // .4byte 0x00010000
};

// Data section: jumptable_8001B53C
// Address: 0x8001B53C
uint32_t jumptable_8001B53C[] = {
    // Unrecognized: .4byte fn_8000FC30+0x28
    // Unrecognized: .4byte fn_8000FC30+0x30
    // Unrecognized: .4byte fn_8000FC30+0x68
    // Unrecognized: .4byte fn_8000FC30+0x70
    // Unrecognized: .4byte fn_8000FC30+0x38
    // Unrecognized: .4byte fn_8000FC30+0x40
    // Unrecognized: .4byte fn_8000FC30+0x88
    // Unrecognized: .4byte fn_8000FC30+0x88
    // Unrecognized: .4byte fn_8000FC30+0x58
    // Unrecognized: .4byte fn_8000FC30+0x60
    // Unrecognized: .4byte fn_8000FC30+0x88
    // Unrecognized: .4byte fn_8000FC30+0x88
    // Unrecognized: .4byte fn_8000FC30+0x88
    // Unrecognized: .4byte fn_8000FC30+0x88
    // Unrecognized: .4byte fn_8000FC30+0x88
    // Unrecognized: .4byte fn_8000FC30+0x88
    // Unrecognized: .4byte fn_8000FC30+0x78
    // Unrecognized: .4byte fn_8000FC30+0x80
    // Unrecognized: .4byte fn_8000FC30+0x88
    // Unrecognized: .4byte fn_8000FC30+0x88
    // Unrecognized: .4byte fn_8000FC30+0x48
    // Unrecognized: .4byte fn_8000FC30+0x50
};

// Data section: gap_05_8001B594_data
// Address: 0x8001B594
uint32_t gap_05_8001B594_data[] = {
    0x2A2A2A2A, // .4byte 0x2A2A2A2A
    0x2A2A2A2A, // .4byte 0x2A2A2A2A
    0x2A2A2A2A, // .4byte 0x2A2A2A2A
    0x2A2A2A2A, // .4byte 0x2A2A2A2A
    0x2A2A2A2A, // .4byte 0x2A2A2A2A
    0x2A2A2A2A, // .4byte 0x2A2A2A2A
    0x2A2A2A2A, // .4byte 0x2A2A2A2A
    0x2A2A2A2A, // .4byte 0x2A2A2A2A
    0x2A2A2A2A, // .4byte 0x2A2A2A2A
    0x2A2A2A0A, // .4byte 0x2A2A2A0A
    0x00000000, // .4byte 0x00000000
    0x20212021, // .4byte 0x20212021
    0x20212043, // .4byte 0x20212043
    0x20412055, // .4byte 0x20412055
    0x20542049, // .4byte 0x20542049
    0x204F204E, // .4byte 0x204F204E
    0x20212021, // .4byte 0x20212021
    0x20212020, // .4byte 0x20212020
    0x20202020, // .4byte 0x20202020
    0x20202020, // .4byte 0x20202020
    0x2020200A, // .4byte 0x2020200A
    0x00000000, // .4byte 0x00000000
    0x54686973, // .4byte 0x54686973
    0x20545620, // .4byte 0x20545620
    0x666F726D, // .4byte 0x666F726D
    0x61742022, // .4byte 0x61742022
    0x44454255, // .4byte 0x44454255
    0x475F5041, // .4byte 0x475F5041
    0x4C222069, // .4byte 0x4C222069
    0x73206F6E, // .4byte 0x73206F6E
    0x6C792066, // .4byte 0x6C792066
    0x6F72200A, // .4byte 0x6F72200A
    0x00000000, // .4byte 0x00000000
    0x74656D70, // .4byte 0x74656D70
    0x6F726172, // .4byte 0x6F726172
    0x7920736F, // .4byte 0x7920736F
    0x6C757469, // .4byte 0x6C757469
    0x6F6E2075, // .4byte 0x6F6E2075
    0x6E74696C, // .4byte 0x6E74696C
    0x2050414C, // .4byte 0x2050414C
    0x20444143, // .4byte 0x20444143
    0x20626F61, // .4byte 0x20626F61
    0x7264200A, // .4byte 0x7264200A
    0x00000000, // .4byte 0x00000000
    0x69732061, // .4byte 0x69732061
    0x7661696C, // .4byte 0x7661696C
    0x61626C65, // .4byte 0x61626C65
    0x2E20506C, // .4byte 0x2E20506C
    0x65617365, // .4byte 0x65617365
    0x20646F20, // .4byte 0x20646F20
    0x4E4F5420, // .4byte 0x4E4F5420
    0x75736520, // .4byte 0x75736520
    0x74686973, // .4byte 0x74686973
    0x2020200A, // .4byte 0x2020200A
    0x00000000, // .4byte 0x00000000
    0x6D6F6465, // .4byte 0x6D6F6465
    0x20696E20, // .4byte 0x20696E20
    0x7265616C, // .4byte 0x7265616C
    0x2067616D, // .4byte 0x2067616D
    0x65732121, // .4byte 0x65732121
    0x21202020, // .4byte 0x21202020
    0x20202020, // .4byte 0x20202020
    0x20202020, // .4byte 0x20202020
    0x20202020, // .4byte 0x20202020
    0x2020200A, // .4byte 0x2020200A
    0x00000000, // .4byte 0x00000000
    0x00000000, // .4byte 0x00000000
};

// Data section: lbl_8001B6A0
// Address: 0x8001B6A0
uint32_t lbl_8001B6A0[] = {
    0x00000000, // .4byte 0x00000000
    0x028001E0, // .4byte 0x028001E0
    0x01E00028, // .4byte 0x01E00028
    0x00000280, // .4byte 0x00000280
    0x01E00000, // .4byte 0x01E00000
    0x00000001, // .4byte 0x00000001
    0x00000606, // .4byte 0x00000606
    0x06060606, // .4byte 0x06060606
    0x06060606, // .4byte 0x06060606
    0x06060606, // .4byte 0x06060606
    0x06060606, // .4byte 0x06060606
    0x06060606, // .4byte 0x06060606
    0x06060000, // .4byte 0x06060000
    0x15161500, // .4byte 0x15161500
    0x00000000, // .4byte 0x00000000
    0x00000000, // .4byte 0x00000000
};

// Data section: __files
// Address: 0x8001B6E0
uint32_t __files[] = {
    0x00000000, // .4byte 0x00000000
    0x08800000, // .4byte 0x08800000
    0x00000000, // .4byte 0x00000000
    // Label: L_8001B6EC:
    0x00000000, // .4byte 0x00000000
    0x00000000, // .4byte 0x00000000
    0x00000000, // .4byte 0x00000000
    // Unrecognized: .rel __files, .L_8001B6EC
    0x00000001, // .4byte 0x00000001
    // Unrecognized: .rel __files, .L_8001B6EC
    0x00000000, // .4byte 0x00000000
    0x00000000, // .4byte 0x00000000
    0x00000000, // .4byte 0x00000000
    0x00000000, // .4byte 0x00000000
    0x00000000, // .4byte 0x00000000
    // Unrecognized: .4byte fn_800140D4
    // Unrecognized: .4byte fn_8001403C
    // Unrecognized: .4byte fn_80014034
    0x00000000, // .4byte 0x00000000
    0x00000000, // .4byte 0x00000000
    0x10800000, // .4byte 0x10800000
    0x00000000, // .4byte 0x00000000
    // Label: L_8001B734:
    0x00000000, // .4byte 0x00000000
    0x00000000, // .4byte 0x00000000
    0x00000000, // .4byte 0x00000000
    // Unrecognized: .rel __files, .L_8001B734
    0x00000001, // .4byte 0x00000001
    // Unrecognized: .rel __files, .L_8001B734
    0x00000000, // .4byte 0x00000000
    0x00000000, // .4byte 0x00000000
    0x00000000, // .4byte 0x00000000
    0x00000000, // .4byte 0x00000000
    0x00000000, // .4byte 0x00000000
    // Unrecognized: .4byte fn_800140D4
    // Unrecognized: .4byte fn_8001403C
    // Unrecognized: .4byte fn_80014034
    0x00000000, // .4byte 0x00000000
    0x00000000, // .4byte 0x00000000
    0x10800000, // .4byte 0x10800000
    0x00000000, // .4byte 0x00000000
    // Label: L_8001B77C:
    0x00000000, // .4byte 0x00000000
    0x00000000, // .4byte 0x00000000
    0x00000000, // .4byte 0x00000000
    // Unrecognized: .rel __files, .L_8001B77C
    0x00000001, // .4byte 0x00000001
    // Unrecognized: .rel __files, .L_8001B77C
    0x00000000, // .4byte 0x00000000
    0x00000000, // .4byte 0x00000000
    0x00000000, // .4byte 0x00000000
    0x00000000, // .4byte 0x00000000
    0x00000000, // .4byte 0x00000000
    // Unrecognized: .4byte fn_800140D4
    // Unrecognized: .4byte fn_8001403C
    // Unrecognized: .4byte fn_80014034
    0x00000000, // .4byte 0x00000000
};

// Data section: @1009_8001B7B8
// Address: 0x8001B7B8
uint32_t @1009_8001B7B8[] = {
    // Unrecognized: .4byte longlong2str_80013554+0xF8
    // Unrecognized: .4byte longlong2str_80013554+0x108
    // Unrecognized: .4byte longlong2str_80013554+0x108
    // Unrecognized: .4byte longlong2str_80013554+0x108
    // Unrecognized: .4byte longlong2str_80013554+0x108
    // Unrecognized: .4byte longlong2str_80013554+0x108
    // Unrecognized: .4byte longlong2str_80013554+0x108
    // Unrecognized: .4byte longlong2str_80013554+0x108
    // Unrecognized: .4byte longlong2str_80013554+0x108
    // Unrecognized: .4byte longlong2str_80013554+0x108
    // Unrecognized: .4byte longlong2str_80013554+0x108
    // Unrecognized: .4byte longlong2str_80013554+0x108
    // Unrecognized: .4byte longlong2str_80013554+0x98
    // Unrecognized: .4byte longlong2str_80013554+0x108
    // Unrecognized: .4byte longlong2str_80013554+0x108
    // Unrecognized: .4byte longlong2str_80013554+0x108
    // Unrecognized: .4byte longlong2str_80013554+0x108
    // Unrecognized: .4byte longlong2str_80013554+0x98
    // Unrecognized: .4byte longlong2str_80013554+0x108
    // Unrecognized: .4byte longlong2str_80013554+0x108
    // Unrecognized: .4byte longlong2str_80013554+0x108
    // Unrecognized: .4byte longlong2str_80013554+0x108
    // Unrecognized: .4byte longlong2str_80013554+0x108
    // Unrecognized: .4byte longlong2str_80013554+0xD0
    // Unrecognized: .4byte longlong2str_80013554+0x108
    // Unrecognized: .4byte longlong2str_80013554+0x108
    // Unrecognized: .4byte longlong2str_80013554+0x108
    // Unrecognized: .4byte longlong2str_80013554+0x108
    // Unrecognized: .4byte longlong2str_80013554+0x108
    // Unrecognized: .4byte longlong2str_80013554+0xE4
    // Unrecognized: .4byte longlong2str_80013554+0x108
    // Unrecognized: .4byte longlong2str_80013554+0x108
    // Unrecognized: .4byte longlong2str_80013554+0xF8
};

// Data section: jumptable_8001B83C
// Address: 0x8001B83C
uint32_t jumptable_8001B83C[] = {
    // Unrecognized: .4byte long2str_80013834+0xA8
    // Unrecognized: .4byte long2str_80013834+0xB4
    // Unrecognized: .4byte long2str_80013834+0xB4
    // Unrecognized: .4byte long2str_80013834+0xB4
    // Unrecognized: .4byte long2str_80013834+0xB4
    // Unrecognized: .4byte long2str_80013834+0xB4
    // Unrecognized: .4byte long2str_80013834+0xB4
    // Unrecognized: .4byte long2str_80013834+0xB4
    // Unrecognized: .4byte long2str_80013834+0xB4
    // Unrecognized: .4byte long2str_80013834+0xB4
    // Unrecognized: .4byte long2str_80013834+0xB4
    // Unrecognized: .4byte long2str_80013834+0xB4
    // Unrecognized: .4byte long2str_80013834+0x70
    // Unrecognized: .4byte long2str_80013834+0xB4
    // Unrecognized: .4byte long2str_80013834+0xB4
    // Unrecognized: .4byte long2str_80013834+0xB4
    // Unrecognized: .4byte long2str_80013834+0xB4
    // Unrecognized: .4byte long2str_80013834+0x70
    // Unrecognized: .4byte long2str_80013834+0xB4
    // Unrecognized: .4byte long2str_80013834+0xB4
    // Unrecognized: .4byte long2str_80013834+0xB4
    // Unrecognized: .4byte long2str_80013834+0xB4
    // Unrecognized: .4byte long2str_80013834+0xB4
    // Unrecognized: .4byte long2str_80013834+0x88
    // Unrecognized: .4byte long2str_80013834+0xB4
    // Unrecognized: .4byte long2str_80013834+0xB4
    // Unrecognized: .4byte long2str_80013834+0xB4
    // Unrecognized: .4byte long2str_80013834+0xB4
    // Unrecognized: .4byte long2str_80013834+0xB4
    // Unrecognized: .4byte long2str_80013834+0x98
    // Unrecognized: .4byte long2str_80013834+0xB4
    // Unrecognized: .4byte long2str_80013834+0xB4
    // Unrecognized: .4byte long2str_80013834+0xA8
};

// Data section: jumptable_8001B8C0
// Address: 0x8001B8C0
uint32_t jumptable_8001B8C0[] = {
    // Unrecognized: .4byte parse_format_80013A58+0x3B0
    // Unrecognized: .4byte parse_format_80013A58+0x490
    // Unrecognized: .4byte parse_format_80013A58+0x39C
    // Unrecognized: .4byte parse_format_80013A58+0x490
    // Unrecognized: .4byte parse_format_80013A58+0x490
    // Unrecognized: .4byte parse_format_80013A58+0x490
    // Unrecognized: .4byte parse_format_80013A58+0x490
    // Unrecognized: .4byte parse_format_80013A58+0x490
    // Unrecognized: .4byte parse_format_80013A58+0x490
    // Unrecognized: .4byte parse_format_80013A58+0x490
    // Unrecognized: .4byte parse_format_80013A58+0x490
    // Unrecognized: .4byte parse_format_80013A58+0x490
    // Unrecognized: .4byte parse_format_80013A58+0x490
    // Unrecognized: .4byte parse_format_80013A58+0x490
    // Unrecognized: .4byte parse_format_80013A58+0x490
    // Unrecognized: .4byte parse_format_80013A58+0x490
    // Unrecognized: .4byte parse_format_80013A58+0x490
    // Unrecognized: .4byte parse_format_80013A58+0x490
    // Unrecognized: .4byte parse_format_80013A58+0x490
    // Unrecognized: .4byte parse_format_80013A58+0x31C
    // Unrecognized: .4byte parse_format_80013A58+0x490
    // Unrecognized: .4byte parse_format_80013A58+0x490
    // Unrecognized: .4byte parse_format_80013A58+0x490
    // Unrecognized: .4byte parse_format_80013A58+0x490
    // Unrecognized: .4byte parse_format_80013A58+0x490
    // Unrecognized: .4byte parse_format_80013A58+0x490
    // Unrecognized: .4byte parse_format_80013A58+0x490
    // Unrecognized: .4byte parse_format_80013A58+0x490
    // Unrecognized: .4byte parse_format_80013A58+0x490
    // Unrecognized: .4byte parse_format_80013A58+0x490
    // Unrecognized: .4byte parse_format_80013A58+0x414
    // Unrecognized: .4byte parse_format_80013A58+0x31C
    // Unrecognized: .4byte parse_format_80013A58+0x3B0
    // Unrecognized: .4byte parse_format_80013A58+0x364
    // Unrecognized: .4byte parse_format_80013A58+0x39C
    // Unrecognized: .4byte parse_format_80013A58+0x490
    // Unrecognized: .4byte parse_format_80013A58+0x31C
    // Unrecognized: .4byte parse_format_80013A58+0x490
    // Unrecognized: .4byte parse_format_80013A58+0x490
    // Unrecognized: .4byte parse_format_80013A58+0x490
    // Unrecognized: .4byte parse_format_80013A58+0x490
    // Unrecognized: .4byte parse_format_80013A58+0x478
    // Unrecognized: .4byte parse_format_80013A58+0x31C
    // Unrecognized: .4byte parse_format_80013A58+0x3F0
    // Unrecognized: .4byte parse_format_80013A58+0x490
    // Unrecognized: .4byte parse_format_80013A58+0x490
    // Unrecognized: .4byte parse_format_80013A58+0x44C
    // Unrecognized: .4byte parse_format_80013A58+0x490
    // Unrecognized: .4byte parse_format_80013A58+0x31C
    // Unrecognized: .4byte parse_format_80013A58+0x490
    // Unrecognized: .4byte parse_format_80013A58+0x490
    // Unrecognized: .4byte parse_format_80013A58+0x31C
};

// Data section: jumptable_8001B990
// Address: 0x8001B990
uint32_t jumptable_8001B990[] = {
    // Unrecognized: .4byte parse_format_80013A58+0xC4
    // Unrecognized: .4byte parse_format_80013A58+0x100
    // Unrecognized: .4byte parse_format_80013A58+0x100
    // Unrecognized: .4byte parse_format_80013A58+0xDC
    // Unrecognized: .4byte parse_format_80013A58+0x100
    // Unrecognized: .4byte parse_format_80013A58+0x100
    // Unrecognized: .4byte parse_format_80013A58+0x100
    // Unrecognized: .4byte parse_format_80013A58+0x100
    // Unrecognized: .4byte parse_format_80013A58+0x100
    // Unrecognized: .4byte parse_format_80013A58+0x100
    // Unrecognized: .4byte parse_format_80013A58+0x100
    // Unrecognized: .4byte parse_format_80013A58+0xB8
    // Unrecognized: .4byte parse_format_80013A58+0x100
    // Unrecognized: .4byte parse_format_80013A58+0xAC
    // Unrecognized: .4byte parse_format_80013A58+0x100
    // Unrecognized: .4byte parse_format_80013A58+0x100
    // Unrecognized: .4byte parse_format_80013A58+0xE8
};

// Data section: gap_05_8001B9D4_data
// Address: 0x8001B9D4
uint32_t gap_05_8001B9D4_data[] = {
    0x00000000, // .4byte 0x00000000
};

// Data section: lbl_8001B9D8
// Address: 0x8001B9D8
uint32_t lbl_8001B9D8[] = {
    // Unrecognized: .4byte fn_80015418
    // Unrecognized: .4byte fn_80015440
    // Unrecognized: .4byte fn_80015468
    // Unrecognized: .4byte fn_800154B8
    // Unrecognized: .4byte fn_800154E8
    // Unrecognized: .4byte fn_8001566C
    // Unrecognized: .4byte fn_80015748
    // Unrecognized: .4byte fn_80015418
    // Unrecognized: .4byte fn_80015418
    // Unrecognized: .4byte fn_80015418
    // Unrecognized: .4byte fn_80015418
    // Unrecognized: .4byte fn_80015418
    // Unrecognized: .4byte fn_80015418
    // Unrecognized: .4byte fn_80015418
    // Unrecognized: .4byte fn_80015418
    // Unrecognized: .4byte fn_80015418
    // Unrecognized: .4byte fn_8001598C
    // Unrecognized: .4byte fn_80015B74
    // Unrecognized: .4byte fn_80015D70
    // Unrecognized: .4byte fn_80015F74
    // Unrecognized: .4byte fn_80015418
    // Unrecognized: .4byte fn_80015418
    // Unrecognized: .4byte fn_8001617C
    // Unrecognized: .4byte fn_80015418
    // Unrecognized: .4byte fn_800162B4
    // Unrecognized: .4byte fn_80016318
    // Unrecognized: .4byte fn_8001651C
    // Unrecognized: .4byte fn_80015418
    // Unrecognized: .4byte fn_80015418
    // Unrecognized: .4byte fn_80015418
    // Unrecognized: .4byte fn_80015418
    // Unrecognized: .4byte fn_80015418
    0x00000000, // .4byte 0x00000000
    0x00000000, // .4byte 0x00000000
};

// Data section: jumptable_8001BA60
// Address: 0x8001BA60
uint32_t jumptable_8001BA60[] = {
    // Unrecognized: .4byte fn_8001598C+0x194
    // Unrecognized: .4byte fn_8001598C+0x1B4
    // Unrecognized: .4byte fn_8001598C+0x18C
    // Unrecognized: .4byte fn_8001598C+0x1B4
    // Unrecognized: .4byte fn_8001598C+0x19C
    // Unrecognized: .4byte fn_8001598C+0x1A4
    // Unrecognized: .4byte fn_8001598C+0x1AC
};

// Data section: jumptable_8001BA7C
// Address: 0x8001BA7C
uint32_t jumptable_8001BA7C[] = {
    // Unrecognized: .4byte fn_80015B74+0x1A8
    // Unrecognized: .4byte fn_80015B74+0x1C8
    // Unrecognized: .4byte fn_80015B74+0x1A0
    // Unrecognized: .4byte fn_80015B74+0x1C8
    // Unrecognized: .4byte fn_80015B74+0x1B0
    // Unrecognized: .4byte fn_80015B74+0x1B8
    // Unrecognized: .4byte fn_80015B74+0x1C0
};

// Data section: lbl_8001BA98
// Address: 0x8001BA98
uint32_t lbl_8001BA98[] = {
    // Unrecognized: .byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
    // Unrecognized: .byte 0x00, 0x00, 0x00, 0x00
};

// Data section: gTRKExceptionStatus_8001BAA4
// Address: 0x8001BAA4
uint32_t gTRKExceptionStatus_8001BAA4[] = {
    0x00000000, // .4byte 0x00000000
    0x00000000, // .4byte 0x00000000
    0x00000000, // .4byte 0x00000000
    0x01000000, // .4byte 0x01000000
};

// Data section: lbl_8001BAB4
// Address: 0x8001BAB4
uint32_t lbl_8001BAB4[] = {
    0x00000000, // .4byte 0x00000000
    0x00000000, // .4byte 0x00000000
    0x00000000, // .4byte 0x00000000
    0x00000000, // .4byte 0x00000000
    0x00000000, // .4byte 0x00000000
};

// Data section: lbl_8001BAC8
// Address: 0x8001BAC8
uint32_t lbl_8001BAC8[] = {
    0x00000100, // .4byte 0x00000100
    0x00000200, // .4byte 0x00000200
    0x00000300, // .4byte 0x00000300
    0x00000400, // .4byte 0x00000400
    0x00000500, // .4byte 0x00000500
    0x00000600, // .4byte 0x00000600
    0x00000700, // .4byte 0x00000700
    0x00000800, // .4byte 0x00000800
    0x00000900, // .4byte 0x00000900
    0x00000C00, // .4byte 0x00000C00
    0x00000D00, // .4byte 0x00000D00
    0x00000F00, // .4byte 0x00000F00
    0x00001300, // .4byte 0x00001300
    0x00001400, // .4byte 0x00001400
    0x00001700, // .4byte 0x00001700
    0x00000000, // .4byte 0x00000000
};

// Data section: gDBCommTable
// Address: 0x8001BB08
uint32_t gDBCommTable[] = {
    0x00000000, // .4byte 0x00000000
    0x00000000, // .4byte 0x00000000
    0x00000000, // .4byte 0x00000000
    0x00000000, // .4byte 0x00000000
    0x00000000, // .4byte 0x00000000
    0x00000000, // .4byte 0x00000000
    0x00000000, // .4byte 0x00000000
};

// Data section: gap_05_8001BB24_data
// Address: 0x8001BB24
uint32_t gap_05_8001BB24_data[] = {
    0x00000000, // .4byte 0x00000000
};

// Data section: lbl_8001BB28
// Address: 0x8001BB28
uint32_t lbl_8001BB28[] = {
    // Unrecognized: .string "Can't select EXI2 port!\n"
};
