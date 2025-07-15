.include "macros.inc"
.file "auto_05_8001A680_data"

# 0x8001A680..0x8001BB41 | size: 0x14C1
.data
.balign 8

# .data:0x0 | 0x8001A680 | size: 0x60
.obj lbl_8001A680, global
	.4byte 0x000000B4
	.4byte 0x00000080
	.4byte 0x00000080
	.4byte 0x000000A2
	.4byte 0x0000002C
	.4byte 0x0000008E
	.4byte 0x00000083
	.4byte 0x0000009C
	.4byte 0x0000002C
	.4byte 0x00000070
	.4byte 0x00000048
	.4byte 0x0000003A
	.4byte 0x00000054
	.4byte 0x000000B8
	.4byte 0x000000C6
	.4byte 0x00000041
	.4byte 0x00000064
	.4byte 0x000000D4
	.4byte 0x00000023
	.4byte 0x000000D4
	.4byte 0x00000072
	.4byte 0x00000010
	.4byte 0x00000080
	.4byte 0x00000080
.endobj lbl_8001A680

# .data:0x60 | 0x8001A6E0 | size: 0x1E
.obj "@73_8001A6E0", global
	.string "\nDolphin OS $Revision: 49 $.\n"
.endobj "@73_8001A6E0"

# .data:0x7E | 0x8001A6FE | size: 0x1A2
.obj gap_05_8001A6FE_data, global
.hidden gap_05_8001A6FE_data
	.4byte 0x00004B65
	.4byte 0x726E656C
	.4byte 0x20627569
	.4byte 0x6C74203A
	.4byte 0x20257320
	.4byte 0x25730A00
	.4byte 0x00004465
	.4byte 0x63203137
	.4byte 0x20323030
	.4byte 0x31003138
	.4byte 0x3A34363A
	.4byte 0x34350000
	.4byte 0x0000436F
	.4byte 0x6E736F6C
	.4byte 0x65205479
	.4byte 0x7065203A
	.4byte 0x20005265
	.4byte 0x7461696C
	.4byte 0x2025640A
	.4byte 0x00004D61
	.4byte 0x6320456D
	.4byte 0x756C6174
	.4byte 0x6F720A00
	.4byte 0x00005043
	.4byte 0x20456D75
	.4byte 0x6C61746F
	.4byte 0x720A0000
	.4byte 0x00004550
	.4byte 0x50432041
	.4byte 0x72746875
	.4byte 0x720A0000
	.4byte 0x00004550
	.4byte 0x5043204D
	.4byte 0x696E6E6F
	.4byte 0x770A0000
	.4byte 0x00004465
	.4byte 0x76656C6F
	.4byte 0x706D656E
	.4byte 0x74204857
	.4byte 0x25640A00
	.4byte 0x00004D65
	.4byte 0x6D6F7279
	.4byte 0x20256420
	.4byte 0x4D420A00
	.4byte 0x00004172
	.4byte 0x656E6120
	.4byte 0x3A203078
	.4byte 0x2578202D
	.4byte 0x20307825
	.4byte 0x780A0000
	.4byte 0x00000000
	.4byte 0x01000000
	.4byte 0x02000000
	.4byte 0x03000000
	.4byte 0x04000000
	.4byte 0x05000000
	.4byte 0x06000000
	.4byte 0x07000000
	.4byte 0x08000000
	.4byte 0x09000000
	.4byte 0x0C000000
	.4byte 0x0D000000
	.4byte 0x0F000000
	.4byte 0x13000000
	.4byte 0x14000000
	.4byte 0x1700496E
	.4byte 0x7374616C
	.4byte 0x6C696E67
	.4byte 0x204F5344
	.4byte 0x42496E74
	.4byte 0x65677261
	.4byte 0x746F720A
	.4byte 0x00003E3E
	.4byte 0x3E204F53
	.4byte 0x494E4954
	.4byte 0x3A206578
	.4byte 0x63657074
	.4byte 0x696F6E20
	.4byte 0x25642063
	.4byte 0x6F6D6D61
	.4byte 0x6E646565
	.4byte 0x72656420
	.4byte 0x62792054
	.4byte 0x524B0A00
	.4byte 0x00003E3E
	.4byte 0x3E204F53
	.4byte 0x494E4954
	.4byte 0x3A206578
	.4byte 0x63657074
	.4byte 0x696F6E20
	.4byte 0x25642076
	.4byte 0x6563746F
	.4byte 0x72656420
	.4byte 0x746F2064
	.4byte 0x65627567
	.4byte 0x6765720A
	.4byte 0x00004578
	.4byte 0x63657074
	.4byte 0x696F6E73
	.4byte 0x20696E69
	.4byte 0x7469616C
	.4byte 0x697A6564
	.4byte 0x2E2E2E0A
	.4byte 0x00000000
	.2byte 0x0000
.endobj gap_05_8001A6FE_data

# .data:0x220 | 0x8001A8A0 | size: 0x80
.obj DSPInitCode_8001A8A0, global
	.4byte 0x029F0010
	.4byte 0x029F0033
	.4byte 0x029F0034
	.4byte 0x029F0035
	.4byte 0x029F0036
	.4byte 0x029F0037
	.4byte 0x029F0038
	.4byte 0x029F0039
	.4byte 0x12061203
	.4byte 0x12041205
	.4byte 0x00808000
	.4byte 0x0088FFFF
	.4byte 0x00841000
	.4byte 0x0064001D
	.4byte 0x02180000
	.4byte 0x81001C1E
	.4byte 0x00441B1E
	.4byte 0x00840800
	.4byte 0x00640027
	.4byte 0x191E0000
	.4byte 0x00DEFFFC
	.4byte 0x02A08000
	.4byte 0x029C0028
	.4byte 0x16FC0054
	.4byte 0x16FD4348
	.4byte 0x002102FF
	.4byte 0x02FF02FF
	.4byte 0x02FF02FF
	.4byte 0x02FF02FF
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x00000000
.endobj DSPInitCode_8001A8A0

# .data:0x2A0 | 0x8001A920 | size: 0x29
.obj "@69_8001A920", global
	.string ">>> L2 INVALIDATE : SHOULD NEVER HAPPEN\n"
.endobj "@69_8001A920"

# .data:0x2C9 | 0x8001A949 | size: 0x207
.obj gap_05_8001A949_data, global
.hidden gap_05_8001A949_data
	.4byte 0x0000004D
	.4byte 0x61636869
	.4byte 0x6E652063
	.4byte 0x6865636B
	.4byte 0x20726563
	.4byte 0x65697665
	.4byte 0x640A0048
	.4byte 0x49443220
	.4byte 0x3D203078
	.4byte 0x25782020
	.4byte 0x20535252
	.4byte 0x31203D20
	.4byte 0x30782578
	.4byte 0x0A00004D
	.4byte 0x61636869
	.4byte 0x6E652063
	.4byte 0x6865636B
	.4byte 0x20776173
	.4byte 0x206E6F74
	.4byte 0x20444D41
	.4byte 0x2F6C6F63
	.4byte 0x6B656420
	.4byte 0x63616368
	.4byte 0x65207265
	.4byte 0x6C617465
	.4byte 0x640A0044
	.4byte 0x4D414572
	.4byte 0x726F7248
	.4byte 0x616E646C
	.4byte 0x65722829
	.4byte 0x3A20416E
	.4byte 0x20657272
	.4byte 0x6F72206F
	.4byte 0x63637572
	.4byte 0x72656420
	.4byte 0x7768696C
	.4byte 0x65207072
	.4byte 0x6F636573
	.4byte 0x73696E67
	.4byte 0x20444D41
	.4byte 0x2E0A0054
	.4byte 0x68652066
	.4byte 0x6F6C6C6F
	.4byte 0x77696E67
	.4byte 0x20657272
	.4byte 0x6F727320
	.4byte 0x68617665
	.4byte 0x20626565
	.4byte 0x6E206465
	.4byte 0x74656374
	.4byte 0x65642061
	.4byte 0x6E642063
	.4byte 0x6C656172
	.4byte 0x6564203A
	.4byte 0x0A000009
	.4byte 0x2D205265
	.4byte 0x71756573
	.4byte 0x74656420
	.4byte 0x61206C6F
	.4byte 0x636B6564
	.4byte 0x20636163
	.4byte 0x68652074
	.4byte 0x61672074
	.4byte 0x68617420
	.4byte 0x77617320
	.4byte 0x616C7265
	.4byte 0x61647920
	.4byte 0x696E2074
	.4byte 0x68652063
	.4byte 0x61636865
	.4byte 0x0A000009
	.4byte 0x2D20444D
	.4byte 0x41206174
	.4byte 0x74656D70
	.4byte 0x74656420
	.4byte 0x746F2061
	.4byte 0x63636573
	.4byte 0x73206E6F
	.4byte 0x726D616C
	.4byte 0x20636163
	.4byte 0x68650A00
	.4byte 0x00000009
	.4byte 0x2D20444D
	.4byte 0x41206D69
	.4byte 0x73736564
	.4byte 0x20696E20
	.4byte 0x64617461
	.4byte 0x20636163
	.4byte 0x68650A00
	.4byte 0x00000009
	.4byte 0x2D20444D
	.4byte 0x41207175
	.4byte 0x65756520
	.4byte 0x6F766572
	.4byte 0x666C6F77
	.4byte 0x65640A00
	.4byte 0x0000004C
	.4byte 0x3120692D
	.4byte 0x63616368
	.4byte 0x65732069
	.4byte 0x6E697469
	.4byte 0x616C697A
	.4byte 0x65640A00
	.4byte 0x0000004C
	.4byte 0x3120642D
	.4byte 0x63616368
	.4byte 0x65732069
	.4byte 0x6E697469
	.4byte 0x616C697A
	.4byte 0x65640A00
	.4byte 0x0000004C
	.4byte 0x32206361
	.4byte 0x63686520
	.4byte 0x696E6974
	.4byte 0x69616C69
	.4byte 0x7A65640A
	.4byte 0x0000004C
	.4byte 0x6F636B65
	.4byte 0x64206361
	.4byte 0x63686520
	.4byte 0x6D616368
	.4byte 0x696E6520
	.4byte 0x63686563
	.4byte 0x6B206861
	.4byte 0x6E646C65
	.4byte 0x7220696E
	.4byte 0x7374616C
	.4byte 0x6C65640A
	.4byte 0x00000000
	.byte 0x00, 0x00, 0x00
.endobj gap_05_8001A949_data

# .data:0x4D0 | 0x8001AB50 | size: 0x1B4
.obj lbl_8001AB50, global
	.4byte 0x2D2D2D2D
	.4byte 0x2D2D2D2D
	.4byte 0x2D2D2D2D
	.4byte 0x2D2D2D2D
	.4byte 0x2D2D2D2D
	.4byte 0x2D2D2D2D
	.4byte 0x2D20436F
	.4byte 0x6E746578
	.4byte 0x74203078
	.4byte 0x25303878
	.4byte 0x202D2D2D
	.4byte 0x2D2D2D2D
	.4byte 0x2D2D2D2D
	.4byte 0x2D2D2D2D
	.4byte 0x2D2D2D2D
	.4byte 0x2D2D2D2D
	.4byte 0x2D2D0A00
	.4byte 0x72252D32
	.4byte 0x6420203D
	.4byte 0x20307825
	.4byte 0x30387820
	.4byte 0x28253134
	.4byte 0x64292020
	.4byte 0x72252D32
	.4byte 0x6420203D
	.4byte 0x20307825
	.4byte 0x30387820
	.4byte 0x28253134
	.4byte 0x64290A00
	.4byte 0x4C522020
	.4byte 0x203D2030
	.4byte 0x78253038
	.4byte 0x78202020
	.4byte 0x20202020
	.4byte 0x20202020
	.4byte 0x20202020
	.4byte 0x20202020
	.4byte 0x43522020
	.4byte 0x203D2030
	.4byte 0x78253038
	.4byte 0x780A0000
	.4byte 0x53525230
	.4byte 0x203D2030
	.4byte 0x78253038
	.4byte 0x78202020
	.4byte 0x20202020
	.4byte 0x20202020
	.4byte 0x20202020
	.4byte 0x20202020
	.4byte 0x53525231
	.4byte 0x203D2030
	.4byte 0x78253038
	.4byte 0x780A0000
	.4byte 0x0A475152
	.4byte 0x732D2D2D
	.4byte 0x2D2D2D2D
	.4byte 0x2D2D2D0A
	.4byte 0x00000000
	.4byte 0x67717225
	.4byte 0x64203D20
	.4byte 0x30782530
	.4byte 0x38782009
	.4byte 0x20677172
	.4byte 0x2564203D
	.4byte 0x20307825
	.4byte 0x3038780A
	.4byte 0x00000000
	.4byte 0x0A0A4650
	.4byte 0x52732D2D
	.4byte 0x2D2D2D2D
	.4byte 0x2D2D2D2D
	.4byte 0x0A000000
	.4byte 0x66722564
	.4byte 0x20093D20
	.4byte 0x25642009
	.4byte 0x20667225
	.4byte 0x6420093D
	.4byte 0x2025640A
	.4byte 0x00000000
	.4byte 0x0A0A5053
	.4byte 0x46732D2D
	.4byte 0x2D2D2D2D
	.4byte 0x2D2D2D2D
	.4byte 0x0A000000
	.4byte 0x70732564
	.4byte 0x20093D20
	.4byte 0x30782578
	.4byte 0x20092070
	.4byte 0x73256420
	.4byte 0x093D2030
	.4byte 0x7825780A
	.4byte 0x00000000
	.4byte 0x0A416464
	.4byte 0x72657373
	.4byte 0x3A202020
	.4byte 0x20202042
	.4byte 0x61636B20
	.4byte 0x43686169
	.4byte 0x6E202020
	.4byte 0x204C5220
	.4byte 0x53617665
	.4byte 0x0A000000
	.4byte 0x30782530
	.4byte 0x38783A20
	.4byte 0x20203078
	.4byte 0x25303878
	.4byte 0x20202020
	.4byte 0x30782530
	.4byte 0x38780A00
.endobj lbl_8001AB50

# .data:0x684 | 0x8001AD04 | size: 0x23
.obj "@74_8001AD04", global
	.string "FPU-unavailable handler installed\n"
.endobj "@74_8001AD04"

# .data:0x6A7 | 0x8001AD27 | size: 0x1
.obj gap_05_8001AD27_data, global
.hidden gap_05_8001AD27_data
	.byte 0x00
.endobj gap_05_8001AD27_data

# .data:0x6A8 | 0x8001AD28 | size: 0x16
.obj "@10_8001AD28", global
	.string " in \"%s\" on line %d.\n"
.endobj "@10_8001AD28"

# .data:0x6BE | 0x8001AD3E | size: 0x2C6
.obj gap_05_8001AD3E_data, global
.hidden gap_05_8001AD3E_data
	.4byte 0x00000A41
	.4byte 0x64647265
	.4byte 0x73733A20
	.4byte 0x20202020
	.4byte 0x20426163
	.4byte 0x6B204368
	.4byte 0x61696E20
	.4byte 0x2020204C
	.4byte 0x52205361
	.4byte 0x76650A00
	.4byte 0x00003078
	.4byte 0x25303878
	.4byte 0x3A202020
	.4byte 0x30782530
	.4byte 0x38782020
	.4byte 0x20203078
	.4byte 0x25303878
	.4byte 0x0A004E6F
	.4byte 0x6E2D7265
	.4byte 0x636F7665
	.4byte 0x7261626C
	.4byte 0x65204578
	.4byte 0x63657074
	.4byte 0x696F6E20
	.4byte 0x25640000
	.4byte 0x0000556E
	.4byte 0x68616E64
	.4byte 0x6C656420
	.4byte 0x45786365
	.4byte 0x7074696F
	.4byte 0x6E202564
	.4byte 0x00000A44
	.4byte 0x53495352
	.4byte 0x203D2030
	.4byte 0x78253038
	.4byte 0x78202020
	.4byte 0x20202020
	.4byte 0x20202020
	.4byte 0x20202020
	.4byte 0x20202020
	.4byte 0x44415220
	.4byte 0x203D2030
	.4byte 0x78253038
	.4byte 0x780A0000
	.4byte 0x00005442
	.4byte 0x203D2030
	.4byte 0x78253031
	.4byte 0x366C6C78
	.4byte 0x0A000A49
	.4byte 0x6E737472
	.4byte 0x75637469
	.4byte 0x6F6E2061
	.4byte 0x74203078
	.4byte 0x25782028
	.4byte 0x72656164
	.4byte 0x2066726F
	.4byte 0x6D205352
	.4byte 0x52302920
	.4byte 0x61747465
	.4byte 0x6D707465
	.4byte 0x6420746F
	.4byte 0x20616363
	.4byte 0x65737320
	.4byte 0x696E7661
	.4byte 0x6C696420
	.4byte 0x61646472
	.4byte 0x65737320
	.4byte 0x30782578
	.4byte 0x20287265
	.4byte 0x61642066
	.4byte 0x726F6D20
	.4byte 0x44415229
	.4byte 0x0A000A41
	.4byte 0x7474656D
	.4byte 0x70746564
	.4byte 0x20746F20
	.4byte 0x66657463
	.4byte 0x6820696E
	.4byte 0x73747275
	.4byte 0x6374696F
	.4byte 0x6E206672
	.4byte 0x6F6D2069
	.4byte 0x6E76616C
	.4byte 0x69642061
	.4byte 0x64647265
	.4byte 0x73732030
	.4byte 0x78257820
	.4byte 0x28726561
	.4byte 0x64206672
	.4byte 0x6F6D2053
	.4byte 0x52523029
	.4byte 0x0A000A49
	.4byte 0x6E737472
	.4byte 0x75637469
	.4byte 0x6F6E2061
	.4byte 0x74203078
	.4byte 0x25782028
	.4byte 0x72656164
	.4byte 0x2066726F
	.4byte 0x6D205352
	.4byte 0x52302920
	.4byte 0x61747465
	.4byte 0x6D707465
	.4byte 0x6420746F
	.4byte 0x20616363
	.4byte 0x65737320
	.4byte 0x756E616C
	.4byte 0x69676E65
	.4byte 0x64206164
	.4byte 0x64726573
	.4byte 0x73203078
	.4byte 0x25782028
	.4byte 0x72656164
	.4byte 0x2066726F
	.4byte 0x6D204441
	.4byte 0x52290A00
	.4byte 0x00000A50
	.4byte 0x726F6772
	.4byte 0x616D2065
	.4byte 0x78636570
	.4byte 0x74696F6E
	.4byte 0x203A2050
	.4byte 0x6F737369
	.4byte 0x626C6520
	.4byte 0x696C6C65
	.4byte 0x67616C20
	.4byte 0x696E7374
	.4byte 0x72756374
	.4byte 0x696F6E2F
	.4byte 0x6F706572
	.4byte 0x6174696F
	.4byte 0x6E206174
	.4byte 0x206F7220
	.4byte 0x61726F75
	.4byte 0x6E642030
	.4byte 0x78257820
	.4byte 0x28726561
	.4byte 0x64206672
	.4byte 0x6F6D2053
	.4byte 0x52523029
	.4byte 0x0A004149
	.4byte 0x20444D41
	.4byte 0x20416464
	.4byte 0x72657373
	.4byte 0x203D2020
	.4byte 0x20307825
	.4byte 0x30347825
	.4byte 0x3034780A
	.4byte 0x00004152
	.4byte 0x414D2044
	.4byte 0x4D412041
	.4byte 0x64647265
	.4byte 0x7373203D
	.4byte 0x20307825
	.4byte 0x30347825
	.4byte 0x3034780A
	.4byte 0x00004449
	.4byte 0x20444D41
	.4byte 0x20416464
	.4byte 0x72657373
	.4byte 0x203D2020
	.4byte 0x20307825
	.4byte 0x3038780A
	.4byte 0x00000A4C
	.4byte 0x61737420
	.4byte 0x696E7465
	.4byte 0x72727570
	.4byte 0x74202825
	.4byte 0x64293A20
	.4byte 0x53525230
	.4byte 0x203D2030
	.4byte 0x78253038
	.4byte 0x78202054
	.4byte 0x42203D20
	.4byte 0x30782530
	.4byte 0x31366C6C
	.4byte 0x780A0000
	.2byte 0x0000
.endobj gap_05_8001AD3E_data

# .data:0x984 | 0x8001B004 | size: 0x40
.obj "@43_8001B004", global
	.4byte __OSUnhandledException+0x1CC
	.4byte __OSUnhandledException+0x1CC
	.4byte __OSUnhandledException+0x124
	.4byte __OSUnhandledException+0x13C
	.4byte __OSUnhandledException+0x1CC
	.4byte __OSUnhandledException+0x150
	.4byte __OSUnhandledException+0x168
	.4byte __OSUnhandledException+0x1CC
	.4byte __OSUnhandledException+0x1CC
	.4byte __OSUnhandledException+0x1CC
	.4byte __OSUnhandledException+0x1CC
	.4byte __OSUnhandledException+0x1CC
	.4byte __OSUnhandledException+0x1CC
	.4byte __OSUnhandledException+0x1CC
	.4byte __OSUnhandledException+0x1CC
	.4byte __OSUnhandledException+0x180
.endobj "@43_8001B004"

# .data:0x9C4 | 0x8001B044 | size: 0x4
.obj gap_05_8001B044_data, global
.hidden gap_05_8001B044_data
	.4byte 0x00000000
.endobj gap_05_8001B044_data

# .data:0x9C8 | 0x8001B048 | size: 0x30
.obj lbl_8001B048, global
	.4byte 0x00000100
	.4byte 0x00000040
	.4byte 0xF8000000
	.4byte 0x00000200
	.4byte 0x00000080
	.4byte 0x00003000
	.4byte 0x00000020
	.4byte 0x03FF8C00
	.4byte 0x04000000
	.4byte 0x00004000
	.4byte 0xFFFFFFFF
	.4byte 0x00000000
.endobj lbl_8001B048

# .data:0x9F8 | 0x8001B078 | size: 0x10
.obj ResetFunctionInfo_8001B078, global
	.4byte fn_80007FE0
	.4byte 0x0000007F
	.4byte 0x00000000
	.4byte 0x00000000
.endobj ResetFunctionInfo_8001B078

# .data:0xA08 | 0x8001B088 | size: 0x14
.obj Si_8001B088, global
	.4byte 0xFFFFFFFF
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x00000000
.endobj Si_8001B088

# .data:0xA1C | 0x8001B09C | size: 0x10
.obj Type_8001B09C, global
	.4byte 0x00000008
	.4byte 0x00000008
	.4byte 0x00000008
	.4byte 0x00000008
.endobj Type_8001B09C

# .data:0xA2C | 0x8001B0AC | size: 0xAC
.obj gap_05_8001B0AC_data, global
.hidden gap_05_8001B0AC_data
	.4byte 0x4E6F2072
	.4byte 0x6573706F
	.4byte 0x6E736500
	.4byte 0x4E363420
	.4byte 0x636F6E74
	.4byte 0x726F6C6C
	.4byte 0x65720000
	.4byte 0x4E363420
	.4byte 0x6D696372
	.4byte 0x6F70686F
	.4byte 0x6E650000
	.4byte 0x4E363420
	.4byte 0x6B657962
	.4byte 0x6F617264
	.4byte 0x00000000
	.4byte 0x4E363420
	.4byte 0x6D6F7573
	.4byte 0x65000000
	.4byte 0x47616D65
	.4byte 0x426F7920
	.4byte 0x41647661
	.4byte 0x6E636500
	.4byte 0x5374616E
	.4byte 0x64617264
	.4byte 0x20636F6E
	.4byte 0x74726F6C
	.4byte 0x6C657200
	.4byte 0x57697265
	.4byte 0x6C657373
	.4byte 0x20726563
	.4byte 0x65697665
	.4byte 0x72000000
	.4byte 0x57617665
	.4byte 0x42697264
	.4byte 0x20636F6E
	.4byte 0x74726F6C
	.4byte 0x6C657200
	.4byte 0x4B657962
	.4byte 0x6F617264
	.4byte 0x00000000
	.4byte 0x53746565
	.4byte 0x72696E67
	.4byte 0x00000000
.endobj gap_05_8001B0AC_data

# .data:0xAD8 | 0x8001B158 | size: 0x30
.obj XYNTSC_8001B158, global
	.4byte 0x00F60200
	.4byte 0x000F1200
	.4byte 0x001E0900
	.4byte 0x002C0600
	.4byte 0x00340500
	.4byte 0x00410400
	.4byte 0x00570300
	.4byte 0x00570300
	.4byte 0x00570300
	.4byte 0x00830200
	.4byte 0x00830200
	.4byte 0x00830200
.endobj XYNTSC_8001B158

# .data:0xB08 | 0x8001B188 | size: 0x68
.obj gap_05_8001B188_data, global
.hidden gap_05_8001B188_data
	.4byte 0x01280200
	.4byte 0x000F1500
	.4byte 0x001D0B00
	.4byte 0x002D0700
	.4byte 0x00340600
	.4byte 0x003F0500
	.4byte 0x004E0400
	.4byte 0x00680300
	.4byte 0x00680300
	.4byte 0x00680300
	.4byte 0x00680300
	.4byte 0x009C0200
	.4byte 0x53495365
	.4byte 0x7453616D
	.4byte 0x706C696E
	.4byte 0x67526174
	.4byte 0x653A2075
	.4byte 0x6E6B6E6F
	.4byte 0x776E2054
	.4byte 0x5620666F
	.4byte 0x726D6174
	.4byte 0x2E205573
	.4byte 0x65206465
	.4byte 0x6661756C
	.4byte 0x742E0000
	.4byte 0x00000000
.endobj gap_05_8001B188_data

# .data:0xB70 | 0x8001B1F0 | size: 0x18
.obj lbl_8001B1F0, global
	.string "DBExceptionDestination\n"
.endobj lbl_8001B1F0

# .data:0xB88 | 0x8001B208 | size: 0x4C
.obj lbl_8001B208, global
	.4byte 0x61707020
	.4byte 0x626F6F74
	.4byte 0x65642076
	.4byte 0x6961204A
	.4byte 0x5441470A
	.4byte 0x00000000
	.4byte 0x6C6F6164
	.4byte 0x20667374
	.4byte 0x0A000000
	.4byte 0x61707020
	.4byte 0x626F6F74
	.4byte 0x65642066
	.4byte 0x726F6D20
	.4byte 0x626F6F74
	.4byte 0x726F6D0A
	.4byte 0x00000000
	.4byte 0x626F6F74
	.4byte 0x726F6D0A
	.4byte 0x00000000
.endobj lbl_8001B208

# .data:0xBD4 | 0x8001B254 | size: 0x20
.obj jumptable_8001B254, global
	.4byte fn_8000E240+0x218
	.4byte fn_8000E240+0xD8
	.4byte fn_8000E240+0xF0
	.4byte fn_8000E240+0x108
	.4byte fn_8000E240+0x138
	.4byte fn_8000E240+0x1FC
	.4byte fn_8000E240+0x150
	.4byte fn_8000E240+0x120
.endobj jumptable_8001B254

# .data:0xBF4 | 0x8001B274 | size: 0x40
.obj jumptable_8001B274, global
	.4byte fn_8000E488+0x2B0
	.4byte fn_8000E488+0x6C
	.4byte fn_8000E488+0xC8
	.4byte fn_8000E488+0xEC
	.4byte fn_8000E488+0x6C
	.4byte fn_8000E488+0x40
	.4byte fn_8000E488+0x10C
	.4byte fn_8000E488+0x170
	.4byte fn_8000E488+0x19C
	.4byte fn_8000E488+0x1D0
	.4byte fn_8000E488+0x1F4
	.4byte fn_8000E488+0x218
	.4byte fn_8000E488+0x23C
	.4byte fn_8000E488+0x260
	.4byte fn_8000E488+0x288
	.4byte fn_8000E488+0xFC
.endobj jumptable_8001B274

# .data:0xC34 | 0x8001B2B4 | size: 0x34
.obj jumptable_8001B2B4, global
	.4byte fn_8000EFC0+0x50
	.4byte fn_8000EFC0+0x50
	.4byte fn_8000EFC0+0x70
	.4byte fn_8000EFC0+0xB4
	.4byte fn_8000EFC0+0x100
	.4byte fn_8000EFC0+0x17C
	.4byte fn_8000EFC0+0x17C
	.4byte fn_8000EFC0+0x17C
	.4byte fn_8000EFC0+0x17C
	.4byte fn_8000EFC0+0x248
	.4byte fn_8000EFC0+0x248
	.4byte fn_8000EFC0+0x50
	.4byte fn_8000EFC0+0x17C
.endobj jumptable_8001B2B4

# .data:0xC68 | 0x8001B2E8 | size: 0x34
.obj jumptable_8001B2E8, global
	.4byte fn_8000F238+0x98
	.4byte fn_8000F238+0xA0
	.4byte fn_8000F238+0x90
	.4byte fn_8000F238+0x90
	.4byte fn_8000F238+0x98
	.4byte fn_8000F238+0x98
	.4byte fn_8000F238+0x98
	.4byte fn_8000F238+0x98
	.4byte fn_8000F238+0x98
	.4byte fn_8000F238+0xA0
	.4byte fn_8000F238+0x90
	.4byte fn_8000F238+0x90
	.4byte fn_8000F238+0x98
.endobj jumptable_8001B2E8

# .data:0xC9C | 0x8001B31C | size: 0x4
.obj gap_05_8001B31C_data, global
.hidden gap_05_8001B31C_data
	.4byte 0x00000000
.endobj gap_05_8001B31C_data

# .data:0xCA0 | 0x8001B320 | size: 0x48
.obj lbl_8001B320, global
	.4byte 0x00000000
	.4byte 0x00023A00
	.4byte 0x00062800
	.4byte 0x00030200
	.4byte 0x00031100
	.4byte 0x00052000
	.4byte 0x00052001
	.4byte 0x00052100
	.4byte 0x00052400
	.4byte 0x00052401
	.4byte 0x00052402
	.4byte 0x000B5A01
	.4byte 0x00056300
	.4byte 0x00020401
	.4byte 0x00020400
	.4byte 0x00040800
	.4byte 0x00100007
	.4byte 0x00000000
.endobj lbl_8001B320

# .data:0xCE8 | 0x8001B368 | size: 0x70
.obj lbl_8001B368, global
	.4byte 0x20204761
	.4byte 0x6D65204E
	.4byte 0x616D6520
	.4byte 0x2E2E2E20
	.4byte 0x25632563
	.4byte 0x25632563
	.4byte 0x0A000000
	.4byte 0x2020436F
	.4byte 0x6D70616E
	.4byte 0x79202E2E
	.4byte 0x2E2E2E20
	.4byte 0x25632563
	.4byte 0x0A000000
	.4byte 0x20204469
	.4byte 0x736B2023
	.4byte 0x202E2E2E
	.4byte 0x2E2E2E20
	.4byte 0x25640A00
	.4byte 0x20204761
	.4byte 0x6D652076
	.4byte 0x6572202E
	.4byte 0x2E2E2E20
	.4byte 0x25640A00
	.4byte 0x20205374
	.4byte 0x7265616D
	.4byte 0x696E6720
	.4byte 0x2E2E2E20
	.4byte 0x25730A00
.endobj lbl_8001B368

# .data:0xD58 | 0x8001B3D8 | size: 0x164
.obj lbl_8001B3D8, global
	.4byte 0x060000F0
	.4byte 0x00180019
	.4byte 0x00030002
	.4byte 0x0C0D0C0D
	.4byte 0x02080207
	.4byte 0x02080207
	.4byte 0x020D01AD
	.4byte 0x404769A2
	.4byte 0x01757A00
	.4byte 0x019C0600
	.4byte 0x00F00018
	.4byte 0x00180004
	.4byte 0x00040C0C
	.4byte 0x0C0C0208
	.4byte 0x02080208
	.4byte 0x0208020E
	.4byte 0x01AD4047
	.4byte 0x69A20175
	.4byte 0x7A00019C
	.4byte 0x0500011F
	.4byte 0x00230024
	.4byte 0x00010000
	.4byte 0x0D0C0B0A
	.4byte 0x026B026A
	.4byte 0x0269026C
	.4byte 0x027101B0
	.4byte 0x404B6AAC
	.4byte 0x017C8500
	.4byte 0x01A40500
	.4byte 0x011F0021
	.4byte 0x00210002
	.4byte 0x00020D0B
	.4byte 0x0D0B026B
	.4byte 0x026D026B
	.4byte 0x026D0270
	.4byte 0x01B0404B
	.4byte 0x6AAC017C
	.4byte 0x850001A4
	.4byte 0x060000F0
	.4byte 0x00180019
	.4byte 0x00030002
	.4byte 0x100F0E0D
	.4byte 0x02060205
	.4byte 0x02040207
	.4byte 0x020D01AD
	.4byte 0x404E70A2
	.4byte 0x01757A00
	.4byte 0x019C0600
	.4byte 0x00F00018
	.4byte 0x00180004
	.4byte 0x0004100E
	.4byte 0x100E0206
	.4byte 0x02080206
	.4byte 0x0208020E
	.4byte 0x01AD404E
	.4byte 0x70A20175
	.4byte 0x7A00019C
	.4byte 0x0C0001E0
	.4byte 0x00300030
	.4byte 0x00060006
	.4byte 0x18181818
	.4byte 0x040E040E
	.4byte 0x040E040E
	.4byte 0x041A01AD
	.4byte 0x404769A2
	.4byte 0x01757A00
	.4byte 0x019C0C00
	.4byte 0x01E0002C
	.4byte 0x002C000A
	.4byte 0x000A1818
	.4byte 0x1818040E
	.4byte 0x040E040E
	.4byte 0x040E041A
	.4byte 0x01AD4047
	.4byte 0x69A8017B
	.4byte 0x7A00019C
	.4byte 0x01F001DC
	.4byte 0x01AE0174
	.4byte 0x012900DB
	.4byte 0x008E0046
	.4byte 0x000C00E2
	.4byte 0x00CB00C0
	.4byte 0x00C400CF
	.4byte 0x00DE00EC
	.4byte 0x00FC0008
	.4byte 0x000F0013
	.4byte 0x0013000F
	.4byte 0x000C0008
	.4byte 0x00010000
.endobj lbl_8001B3D8

# .data:0xEBC | 0x8001B53C | size: 0x58
.obj jumptable_8001B53C, global
	.4byte fn_8000FC30+0x28
	.4byte fn_8000FC30+0x30
	.4byte fn_8000FC30+0x68
	.4byte fn_8000FC30+0x70
	.4byte fn_8000FC30+0x38
	.4byte fn_8000FC30+0x40
	.4byte fn_8000FC30+0x88
	.4byte fn_8000FC30+0x88
	.4byte fn_8000FC30+0x58
	.4byte fn_8000FC30+0x60
	.4byte fn_8000FC30+0x88
	.4byte fn_8000FC30+0x88
	.4byte fn_8000FC30+0x88
	.4byte fn_8000FC30+0x88
	.4byte fn_8000FC30+0x88
	.4byte fn_8000FC30+0x88
	.4byte fn_8000FC30+0x78
	.4byte fn_8000FC30+0x80
	.4byte fn_8000FC30+0x88
	.4byte fn_8000FC30+0x88
	.4byte fn_8000FC30+0x48
	.4byte fn_8000FC30+0x50
.endobj jumptable_8001B53C

# .data:0xF14 | 0x8001B594 | size: 0x10C
.obj gap_05_8001B594_data, global
.hidden gap_05_8001B594_data
	.4byte 0x2A2A2A2A
	.4byte 0x2A2A2A2A
	.4byte 0x2A2A2A2A
	.4byte 0x2A2A2A2A
	.4byte 0x2A2A2A2A
	.4byte 0x2A2A2A2A
	.4byte 0x2A2A2A2A
	.4byte 0x2A2A2A2A
	.4byte 0x2A2A2A2A
	.4byte 0x2A2A2A0A
	.4byte 0x00000000
	.4byte 0x20212021
	.4byte 0x20212043
	.4byte 0x20412055
	.4byte 0x20542049
	.4byte 0x204F204E
	.4byte 0x20212021
	.4byte 0x20212020
	.4byte 0x20202020
	.4byte 0x20202020
	.4byte 0x2020200A
	.4byte 0x00000000
	.4byte 0x54686973
	.4byte 0x20545620
	.4byte 0x666F726D
	.4byte 0x61742022
	.4byte 0x44454255
	.4byte 0x475F5041
	.4byte 0x4C222069
	.4byte 0x73206F6E
	.4byte 0x6C792066
	.4byte 0x6F72200A
	.4byte 0x00000000
	.4byte 0x74656D70
	.4byte 0x6F726172
	.4byte 0x7920736F
	.4byte 0x6C757469
	.4byte 0x6F6E2075
	.4byte 0x6E74696C
	.4byte 0x2050414C
	.4byte 0x20444143
	.4byte 0x20626F61
	.4byte 0x7264200A
	.4byte 0x00000000
	.4byte 0x69732061
	.4byte 0x7661696C
	.4byte 0x61626C65
	.4byte 0x2E20506C
	.4byte 0x65617365
	.4byte 0x20646F20
	.4byte 0x4E4F5420
	.4byte 0x75736520
	.4byte 0x74686973
	.4byte 0x2020200A
	.4byte 0x00000000
	.4byte 0x6D6F6465
	.4byte 0x20696E20
	.4byte 0x7265616C
	.4byte 0x2067616D
	.4byte 0x65732121
	.4byte 0x21202020
	.4byte 0x20202020
	.4byte 0x20202020
	.4byte 0x20202020
	.4byte 0x2020200A
	.4byte 0x00000000
	.4byte 0x00000000
.endobj gap_05_8001B594_data

# .data:0x1020 | 0x8001B6A0 | size: 0x40
.obj lbl_8001B6A0, global
	.4byte 0x00000000
	.4byte 0x028001E0
	.4byte 0x01E00028
	.4byte 0x00000280
	.4byte 0x01E00000
	.4byte 0x00000001
	.4byte 0x00000606
	.4byte 0x06060606
	.4byte 0x06060606
	.4byte 0x06060606
	.4byte 0x06060606
	.4byte 0x06060606
	.4byte 0x06060000
	.4byte 0x15161500
	.4byte 0x00000000
	.4byte 0x00000000
.endobj lbl_8001B6A0

# .data:0x1060 | 0x8001B6E0 | size: 0xD8
.obj __files, global
	.4byte 0x00000000
	.4byte 0x08800000
	.4byte 0x00000000
.L_8001B6EC:
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x00000000
	.rel __files, .L_8001B6EC
	.4byte 0x00000001
	.rel __files, .L_8001B6EC
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte fn_800140D4
	.4byte fn_8001403C
	.4byte fn_80014034
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x10800000
	.4byte 0x00000000
.L_8001B734:
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x00000000
	.rel __files, .L_8001B734
	.4byte 0x00000001
	.rel __files, .L_8001B734
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte fn_800140D4
	.4byte fn_8001403C
	.4byte fn_80014034
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x10800000
	.4byte 0x00000000
.L_8001B77C:
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x00000000
	.rel __files, .L_8001B77C
	.4byte 0x00000001
	.rel __files, .L_8001B77C
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte fn_800140D4
	.4byte fn_8001403C
	.4byte fn_80014034
	.4byte 0x00000000
.endobj __files

# .data:0x1138 | 0x8001B7B8 | size: 0x84
.obj "@1009_8001B7B8", global
	.4byte longlong2str_80013554+0xF8
	.4byte longlong2str_80013554+0x108
	.4byte longlong2str_80013554+0x108
	.4byte longlong2str_80013554+0x108
	.4byte longlong2str_80013554+0x108
	.4byte longlong2str_80013554+0x108
	.4byte longlong2str_80013554+0x108
	.4byte longlong2str_80013554+0x108
	.4byte longlong2str_80013554+0x108
	.4byte longlong2str_80013554+0x108
	.4byte longlong2str_80013554+0x108
	.4byte longlong2str_80013554+0x108
	.4byte longlong2str_80013554+0x98
	.4byte longlong2str_80013554+0x108
	.4byte longlong2str_80013554+0x108
	.4byte longlong2str_80013554+0x108
	.4byte longlong2str_80013554+0x108
	.4byte longlong2str_80013554+0x98
	.4byte longlong2str_80013554+0x108
	.4byte longlong2str_80013554+0x108
	.4byte longlong2str_80013554+0x108
	.4byte longlong2str_80013554+0x108
	.4byte longlong2str_80013554+0x108
	.4byte longlong2str_80013554+0xD0
	.4byte longlong2str_80013554+0x108
	.4byte longlong2str_80013554+0x108
	.4byte longlong2str_80013554+0x108
	.4byte longlong2str_80013554+0x108
	.4byte longlong2str_80013554+0x108
	.4byte longlong2str_80013554+0xE4
	.4byte longlong2str_80013554+0x108
	.4byte longlong2str_80013554+0x108
	.4byte longlong2str_80013554+0xF8
.endobj "@1009_8001B7B8"

# .data:0x11BC | 0x8001B83C | size: 0x84
.obj jumptable_8001B83C, global
	.4byte long2str_80013834+0xA8
	.4byte long2str_80013834+0xB4
	.4byte long2str_80013834+0xB4
	.4byte long2str_80013834+0xB4
	.4byte long2str_80013834+0xB4
	.4byte long2str_80013834+0xB4
	.4byte long2str_80013834+0xB4
	.4byte long2str_80013834+0xB4
	.4byte long2str_80013834+0xB4
	.4byte long2str_80013834+0xB4
	.4byte long2str_80013834+0xB4
	.4byte long2str_80013834+0xB4
	.4byte long2str_80013834+0x70
	.4byte long2str_80013834+0xB4
	.4byte long2str_80013834+0xB4
	.4byte long2str_80013834+0xB4
	.4byte long2str_80013834+0xB4
	.4byte long2str_80013834+0x70
	.4byte long2str_80013834+0xB4
	.4byte long2str_80013834+0xB4
	.4byte long2str_80013834+0xB4
	.4byte long2str_80013834+0xB4
	.4byte long2str_80013834+0xB4
	.4byte long2str_80013834+0x88
	.4byte long2str_80013834+0xB4
	.4byte long2str_80013834+0xB4
	.4byte long2str_80013834+0xB4
	.4byte long2str_80013834+0xB4
	.4byte long2str_80013834+0xB4
	.4byte long2str_80013834+0x98
	.4byte long2str_80013834+0xB4
	.4byte long2str_80013834+0xB4
	.4byte long2str_80013834+0xA8
.endobj jumptable_8001B83C

# .data:0x1240 | 0x8001B8C0 | size: 0xD0
.obj jumptable_8001B8C0, global
	.4byte parse_format_80013A58+0x3B0
	.4byte parse_format_80013A58+0x490
	.4byte parse_format_80013A58+0x39C
	.4byte parse_format_80013A58+0x490
	.4byte parse_format_80013A58+0x490
	.4byte parse_format_80013A58+0x490
	.4byte parse_format_80013A58+0x490
	.4byte parse_format_80013A58+0x490
	.4byte parse_format_80013A58+0x490
	.4byte parse_format_80013A58+0x490
	.4byte parse_format_80013A58+0x490
	.4byte parse_format_80013A58+0x490
	.4byte parse_format_80013A58+0x490
	.4byte parse_format_80013A58+0x490
	.4byte parse_format_80013A58+0x490
	.4byte parse_format_80013A58+0x490
	.4byte parse_format_80013A58+0x490
	.4byte parse_format_80013A58+0x490
	.4byte parse_format_80013A58+0x490
	.4byte parse_format_80013A58+0x31C
	.4byte parse_format_80013A58+0x490
	.4byte parse_format_80013A58+0x490
	.4byte parse_format_80013A58+0x490
	.4byte parse_format_80013A58+0x490
	.4byte parse_format_80013A58+0x490
	.4byte parse_format_80013A58+0x490
	.4byte parse_format_80013A58+0x490
	.4byte parse_format_80013A58+0x490
	.4byte parse_format_80013A58+0x490
	.4byte parse_format_80013A58+0x490
	.4byte parse_format_80013A58+0x414
	.4byte parse_format_80013A58+0x31C
	.4byte parse_format_80013A58+0x3B0
	.4byte parse_format_80013A58+0x364
	.4byte parse_format_80013A58+0x39C
	.4byte parse_format_80013A58+0x490
	.4byte parse_format_80013A58+0x31C
	.4byte parse_format_80013A58+0x490
	.4byte parse_format_80013A58+0x490
	.4byte parse_format_80013A58+0x490
	.4byte parse_format_80013A58+0x490
	.4byte parse_format_80013A58+0x478
	.4byte parse_format_80013A58+0x31C
	.4byte parse_format_80013A58+0x3F0
	.4byte parse_format_80013A58+0x490
	.4byte parse_format_80013A58+0x490
	.4byte parse_format_80013A58+0x44C
	.4byte parse_format_80013A58+0x490
	.4byte parse_format_80013A58+0x31C
	.4byte parse_format_80013A58+0x490
	.4byte parse_format_80013A58+0x490
	.4byte parse_format_80013A58+0x31C
.endobj jumptable_8001B8C0

# .data:0x1310 | 0x8001B990 | size: 0x44
.obj jumptable_8001B990, global
	.4byte parse_format_80013A58+0xC4
	.4byte parse_format_80013A58+0x100
	.4byte parse_format_80013A58+0x100
	.4byte parse_format_80013A58+0xDC
	.4byte parse_format_80013A58+0x100
	.4byte parse_format_80013A58+0x100
	.4byte parse_format_80013A58+0x100
	.4byte parse_format_80013A58+0x100
	.4byte parse_format_80013A58+0x100
	.4byte parse_format_80013A58+0x100
	.4byte parse_format_80013A58+0x100
	.4byte parse_format_80013A58+0xB8
	.4byte parse_format_80013A58+0x100
	.4byte parse_format_80013A58+0xAC
	.4byte parse_format_80013A58+0x100
	.4byte parse_format_80013A58+0x100
	.4byte parse_format_80013A58+0xE8
.endobj jumptable_8001B990

# .data:0x1354 | 0x8001B9D4 | size: 0x4
.obj gap_05_8001B9D4_data, global
.hidden gap_05_8001B9D4_data
	.4byte 0x00000000
.endobj gap_05_8001B9D4_data

# .data:0x1358 | 0x8001B9D8 | size: 0x88
.obj lbl_8001B9D8, global
	.4byte fn_80015418
	.4byte fn_80015440
	.4byte fn_80015468
	.4byte fn_800154B8
	.4byte fn_800154E8
	.4byte fn_8001566C
	.4byte fn_80015748
	.4byte fn_80015418
	.4byte fn_80015418
	.4byte fn_80015418
	.4byte fn_80015418
	.4byte fn_80015418
	.4byte fn_80015418
	.4byte fn_80015418
	.4byte fn_80015418
	.4byte fn_80015418
	.4byte fn_8001598C
	.4byte fn_80015B74
	.4byte fn_80015D70
	.4byte fn_80015F74
	.4byte fn_80015418
	.4byte fn_80015418
	.4byte fn_8001617C
	.4byte fn_80015418
	.4byte fn_800162B4
	.4byte fn_80016318
	.4byte fn_8001651C
	.4byte fn_80015418
	.4byte fn_80015418
	.4byte fn_80015418
	.4byte fn_80015418
	.4byte fn_80015418
	.4byte 0x00000000
	.4byte 0x00000000
.endobj lbl_8001B9D8

# .data:0x13E0 | 0x8001BA60 | size: 0x1C
.obj jumptable_8001BA60, global
	.4byte fn_8001598C+0x194
	.4byte fn_8001598C+0x1B4
	.4byte fn_8001598C+0x18C
	.4byte fn_8001598C+0x1B4
	.4byte fn_8001598C+0x19C
	.4byte fn_8001598C+0x1A4
	.4byte fn_8001598C+0x1AC
.endobj jumptable_8001BA60

# .data:0x13FC | 0x8001BA7C | size: 0x1C
.obj jumptable_8001BA7C, global
	.4byte fn_80015B74+0x1A8
	.4byte fn_80015B74+0x1C8
	.4byte fn_80015B74+0x1A0
	.4byte fn_80015B74+0x1C8
	.4byte fn_80015B74+0x1B0
	.4byte fn_80015B74+0x1B8
	.4byte fn_80015B74+0x1C0
.endobj jumptable_8001BA7C

# .data:0x1418 | 0x8001BA98 | size: 0xC
.obj lbl_8001BA98, global
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00
.endobj lbl_8001BA98

# .data:0x1424 | 0x8001BAA4 | size: 0x10
.obj gTRKExceptionStatus_8001BAA4, global
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x01000000
.endobj gTRKExceptionStatus_8001BAA4

# .data:0x1434 | 0x8001BAB4 | size: 0x14
.obj lbl_8001BAB4, global
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x00000000
.endobj lbl_8001BAB4

# .data:0x1448 | 0x8001BAC8 | size: 0x40
.obj lbl_8001BAC8, global
	.4byte 0x00000100
	.4byte 0x00000200
	.4byte 0x00000300
	.4byte 0x00000400
	.4byte 0x00000500
	.4byte 0x00000600
	.4byte 0x00000700
	.4byte 0x00000800
	.4byte 0x00000900
	.4byte 0x00000C00
	.4byte 0x00000D00
	.4byte 0x00000F00
	.4byte 0x00001300
	.4byte 0x00001400
	.4byte 0x00001700
	.4byte 0x00000000
.endobj lbl_8001BAC8

# .data:0x1488 | 0x8001BB08 | size: 0x1C
.obj gDBCommTable, global
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x00000000
.endobj gDBCommTable

# .data:0x14A4 | 0x8001BB24 | size: 0x4
.obj gap_05_8001BB24_data, global
.hidden gap_05_8001BB24_data
	.4byte 0x00000000
.endobj gap_05_8001BB24_data

# .data:0x14A8 | 0x8001BB28 | size: 0x19
.obj lbl_8001BB28, global
	.string "Can't select EXI2 port!\n"
.endobj lbl_8001BB28
