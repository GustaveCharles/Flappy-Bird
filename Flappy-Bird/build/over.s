
@{{BLOCK(over)

@=======================================================================
@
@	over, 64x32@8, 
@	Transparent color : 00,00,00
@	+ palette 256 entries, not compressed
@	+ 32 tiles not compressed
@	Total size: 512 + 2048 = 2560
@
@	Time-stamp: 2024-01-03, 17:30:21
@	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
@	( http://www.coranac.com/projects/#grit )
@
@=======================================================================

	.section .rodata
	.align	2
	.global overTiles		@ 2048 unsigned chars
	.hidden overTiles
overTiles:
	.word 0x16000000,0x37B551CC,0x350A0000,0x6DB545D2,0x31335B00,0xAA18D2DB,0xD1CC04D6,0xAC05EBFC
	.word 0x1BB55137,0x0000CDE4,0x5151D251,0x0A26000A,0x6D373737,0x1600000A,0x37515137,0x0000000A
	.word 0xBC5E5EDB,0x002E3771,0x4D4D3737,0x002EBC37,0xDE92DEDE,0x00166161,0x19191919,0x24001919
	.word 0x00000000,0x00000000,0x21214A4A,0x002EB821,0x51515151,0x002E2937,0x51899A4C,0x002E514D
	.word 0x00000000,0xBC455EF5,0x2E2E0000,0xDB89A612,0x0FD30000,0x61E3374D,0x89D8A2EA,0xBF25794A
	.word 0xBA37A6A7,0x00C9AABB,0x37376CF2,0x00000086,0x515151E2,0x00000052,0x3751377E,0xA9D0A989
	.word 0x4BF55EE9,0x00001600,0x0A1E3737,0x0000002E,0x33BA37E3,0x000000B0,0xE008752D,0x24C51C28
	.word 0x518D5D01,0x00C06DBC,0x518D0000,0x26274D51,0x4D151624,0x24E12951,0x374D5080,0x00E15151

	.word 0xCCCCCC3B,0x000000A9,0x3737370A,0x000A0A37,0x4D37370A,0x166CA6BA,0x37373711,0x9633374D
	.word 0x297D7DC3,0x819BA3A6,0x3737370A,0x37CF2A33,0x374D4D0A,0x4DCD485E,0x3737370A,0xBA0A004D
	.word 0x5E8C0000,0x16545E80,0x37C5C34B,0x165E4D37,0x4D4DCC0A,0x0A5E4D4D,0x373737C5,0x164D3737
	.word 0x37F7DCA3,0x16443737,0x37992A71,0x0AA63737,0x37D51780,0x0A5E3737,0x370A165E,0x1637370F
	.word 0x80D0AB00,0x545E5480,0x4D378400,0x53894D4D,0x37518400,0x926B9951,0x3737B400,0x70BFCB37
	.word 0x374D7616,0x00249637,0x374D5800,0x12BDB837,0x374D8400,0x37BACC37,0x374DB400,0xC68F0B37
	.word 0x4D538971,0xF0373737,0x4D9B374D,0x3F535347,0x5D5D5D36,0x825D5D7C,0x709C7070,0x2E7070BF
	.word 0x00000000,0x00002600,0xE1E11259,0x000023E1,0x379B4D9B,0x0024C037,0xC6C6C6C6,0x0000F49A

	.word 0x6D51A637,0x0000002E,0x9B899DDE,0x00194DBC,0x80E79E9E,0xCA0C45A6,0x48301600,0x6D33816D
	.word 0x192E0000,0xB4586E58,0x4B000000,0xAAFE4817,0x16000000,0x00160000,0x00000000,0x00000000
	.word 0x51CCBEF3,0x002E3737,0xBA7F0A00,0x002E4D37,0x378035CA,0x002E5151,0x37375137,0x000A5751
	.word 0x6262C158,0x000A385C,0x61616161,0x000A3061,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0x513751FA,0x51374D37,0x513737FA,0xDEAA612D,0x373737E2,0x9E9E9EA4,0x37373785,0x0000006F
	.word 0x5858B466,0x00000009,0xDEDEAA78,0x00000039,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0x37373737,0x00E13737,0x51EEB1DE,0x0041374D,0x3715CE9E,0x00E1A637,0x37152400,0xC7975137
	.word 0xB4A40000,0x0066B458,0x921D0000,0x0040925D,0x00000000,0x00000000,0x00000000,0x00000000

	.word 0x3737370A,0xD20A0051,0x373737C8,0x4816169B,0x3737372E,0xCE000037,0x3737370A,0x0000166D
	.word 0xB3065C56,0x000000B3,0x6192610A,0x00006A17,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0x370A1637,0x0AE0370F,0x372E0030,0x0A4F3731,0x378C00CE,0x164D4D0F,0x370A0000,0x0A373729
	.word 0x59600000,0x16C1AE5C,0xFE190000,0x1692DEFE,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0x4D4D7600,0xB2B2DD4D,0x3737FC16,0x00004E37,0x3737B416,0xCA351437,0x4D4D5800,0x37A64D4D
	.word 0xB4B44600,0x8AAE58B4,0x5D5D6900,0x5D5D5D5D,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0xB2B2B2B2,0x00006869,0x00000000,0x00000000,0x3B223535,0x2EAC3B3B,0x4D373729,0x14895129
	.word 0x5858C162,0x95585858,0x5D5D5D5D,0x825D5D5D,0x00000000,0x00000000,0x00000000,0x00000000

	.word 0x00000000,0x00000000,0xFB000000,0x63FBFBFB,0x51801600,0x513771A3,0xA66D1916,0x37375180
	.word 0x51B6375E,0xAA92AA9D,0x4D37374D,0x0A0A0AAC,0x5137374D,0x00160016,0x51373737,0x00000016
	.word 0x00000000,0x00000000,0x00000016,0x00000000,0xF9893737,0x00002416,0x29D2374D,0x004B0A2E
	.word 0x377161AA,0x002E371B,0x4DCC2E0A,0x002E3751,0x375E0A00,0x002E4D51,0x379B0A00,0x242E3751
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x8937338B,0x000000EC,0x373737FD,0x000000EC
	.word 0xA647378B,0x240000B0,0x3737377E,0x000000B0,0x3737377E,0x000024F8,0x2951377E,0x0083641F
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x37440000,0x4BBDBCDB,0x37150000,0x00E23737
	.word 0xA3440000,0x00975129,0xA6A11600,0x24023737,0x37154B00,0x00973737,0x511AE5ED,0x00E1294D

	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x5E5E5E0A,0x4DE99BB9,0x37373A0A,0xCCCC5003
	.word 0x374D4D16,0x6B5DE49B,0x374545B7,0x160A0A10,0x3737370A,0x0000004D,0x3737372E,0xE5D406D2
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x5E5E5E9B,0x16714D5E,0x71545454,0x16D04D89
	.word 0x925D5D5D,0x0017DE92,0x0A0A0A0A,0x000A0A16,0x00000000,0x00000000,0x64646464,0x00000AE5
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x5E5EC100,0x897D545E,0x4D4D2F00,0x9B33374D
	.word 0x45372B7A,0x74619A45,0xA6378400,0x0A0A04A6,0x4D4DFC16,0x0000044D,0x3737B400,0x00006737
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x37374D9B,0x000065DB,0x4D4D3A53,0x0A2E1429
	.word 0x13305D6B,0x945E51D2,0x282E0A0A,0x94373737,0xD8160000,0x3F373737,0x1AC491E8,0x3F373737

	.word 0x6D373737,0x0000000A,0x37373737,0x0000000A,0x6D513737,0x00000016,0xD29B379B,0x0016000A
	.word 0x37A3549B,0x2222C30C,0xBA9BAA7C,0xBA29BABA,0xAE870A00,0xAEAEAEAE,0xAD070A00,0x929292AD
	.word 0x515E1600,0x002E374D,0x6D5E1600,0x002E5137,0x514D1600,0x002EA34D,0xDB5E1600,0x000A33BC
	.word 0x37CCCA22,0x002E2C50,0x9B6D516D,0x0016309D,0xC1AEAEAE,0x0000162E,0x92DE9292,0x00000016
	.word 0x4D2929E2,0x16FF5E37,0x51C44C7B,0xD0CCA34D,0x29E67743,0xA6514D5E,0xFE420000,0x474D5179
	.word 0x5A900000,0xA39B2C9F,0x00000000,0xD175B140,0x00000000,0xAE094B63,0x00000000,0x5DC90000
	.word 0xD2A3D2F8,0x00023737,0x37D93A5E,0x007B9A32,0xA60337A6,0x0043D775,0xAA7293BA,0x0000AF78
	.word 0x5ADF805E,0x00000090,0x003492E6,0x00000000,0x00160066,0x00000000,0x000000EF,0x00000000

	.word 0x37373719,0x9B4D376D,0x37374D22,0xC6C60D5C,0x31310F8E,0xD7D77731,0x3737A6C8,0x2400006D
	.word 0x3737372E,0x358C117D,0x3737370A,0x4D4D3A03,0xC187870A,0xC1C15C0E,0x5D92DE16,0x5D5D3636
	.word 0x47373737,0x0000165E,0xC6C6C6C6,0x0000164C,0xA0D7D7D7,0x000016DA,0x00000000,0x00000000
	.word 0x22222222,0x16222222,0x3737376C,0x0A513737,0x8A878A8A,0x16F18A8A,0x5D92925D,0x00FE5D5D
	.word 0x3737B400,0x00006737,0x374DB400,0xEBA9CC37,0x374D2B00,0x89557137,0x3737B400,0x135D9937
	.word 0x374DB400,0x8A5A8837,0xA3BA5800,0x3E0088A3,0x8A8A4616,0x63243C8A,0x5D5DF624,0x0000CE5D
	.word 0x514DA800,0xC04D4D37,0x494D45F9,0x20C6A5A5,0x49894D4D,0xCED7A042,0x6D374D89,0x00007398
	.word 0x374D373D,0xC2C39429,0x29101348,0x734D4D4D,0x87875F4B,0x95383887,0x5D5D3E26,0x825D5D5D

	.section .rodata
	.align	2
	.global overPal		@ 512 unsigned chars
	.hidden overPal
overPal:
	.hword 0x0000,0x4C07,0x5A03,0x6F60,0x4122,0x1C00,0x7A66,0x6C09
	.hword 0x7724,0x6608,0x0800,0x6983,0x2860,0x6867,0x6E06,0x7342
	.hword 0x7366,0x28A1,0x6E66,0x7AC7,0x4D82,0x6280,0x0400,0x686A
	.hword 0x6C48,0x1000,0x7723,0x7745,0x5646,0x5807,0x6E68,0x7B03
	.hword 0x3803,0x7283,0x1840,0x3D44,0x0001,0x5565,0x0020,0x6686
	.hword 0x6EC5,0x7363,0x7566,0x7B27,0x7B24,0x7208,0x0C00,0x7AE8
	.hword 0x6C4A,0x7341,0x69E3,0x7B63,0x40C9,0x2040,0x6C2A,0x7763
	.hword 0x7AA9,0x2C22,0x7783,0x1020,0x4544,0x7B25,0x608A,0x51A2

	.hword 0x5088,0x6245,0x5469,0x3486,0x6AC1,0x7742,0x7A6A,0x7364
	.hword 0x6C6A,0x6945,0x7265,0x0401,0x68A6,0x7764,0x3CE1,0x7303
	.hword 0x7B47,0x7762,0x6665,0x7784,0x7B46,0x6F61,0x0C20,0x7740
	.hword 0x7EE9,0x7244,0x2022,0x1C82,0x7A87,0x700B,0x7B65,0x7ACC
	.hword 0x2041,0x704B,0x7EA8,0x0801,0x7288,0x4DC5,0x6E4A,0x4543
	.hword 0x2C66,0x608B,0x0420,0x6C2B,0x7782,0x7761,0x7EE7,0x6687
	.hword 0x1001,0x7B44,0x7DA9,0x51A4,0x6C0C,0x7247,0x7F48,0x588A
	.hword 0x4867,0x7667,0x1061,0x4CA6,0x740B,0x7785,0x6A66,0x7F65

	.hword 0x7B66,0x7340,0x3804,0x61E9,0x7F08,0x72C7,0x6264,0x7AC9
	.hword 0x5143,0x7B64,0x7AC8,0x6E87,0x1C60,0x6A81,0x0820,0x6886
	.hword 0x1822,0x768A,0x702B,0x7365,0x55C2,0x5986,0x2CA0,0x6AA7
	.hword 0x7343,0x6D66,0x68A7,0x7765,0x0C01,0x7069,0x2C43,0x7A28
	.hword 0x5489,0x6EE1,0x4185,0x7360,0x6A45,0x6888,0x7362,0x76C5
	.hword 0x7729,0x7B67,0x704A,0x7F09,0x1400,0x742B,0x7EC8,0x0002
	.hword 0x6666,0x744B,0x60AB,0x7225,0x7EE8,0x7B42,0x7B60,0x3546
	.hword 0x72A4,0x7B61,0x7361,0x6DC4,0x7743,0x6A88,0x60AA,0x1401

	.hword 0x51A3,0x7EC9,0x1841,0x2081,0x7A88,0x2CA1,0x6887,0x0021
	.hword 0x1420,0x5047,0x2060,0x4943,0x7B45,0x708A,0x2823,0x75A6
	.hword 0x7F66,0x7381,0x7760,0x72A6,0x72A7,0x68C8,0x4103,0x548A
	.hword 0x7305,0x7380,0x5089,0x7744,0x7383,0x6967,0x702A,0x724A
	.hword 0x7B43,0x6A87,0x6A86,0x7226,0x6C49,0x7289,0x7A68,0x7F44
	.hword 0x0421,0x7746,0x4966,0x7F68,0x6667,0x5A09,0x6EC1,0x54AA
	.hword 0x59A6,0x7EAA,0x72E4,0x60CC,0x3843,0x7269,0x58AA,0x7B83
	.hword 0x6646,0x7F67,0x6EA7,0x0C21,0x7B07,0x6A67,0x700A,0x6E67

@}}BLOCK(over)