
@{{BLOCK(bird)

@=======================================================================
@
@	bird, 32x32@8, 
@	Transparent color : 95,F9,CB
@	+ palette 256 entries, not compressed
@	+ 16 tiles not compressed
@	Total size: 512 + 1024 = 1536
@
@	Time-stamp: 2024-01-03, 12:02:48
@	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
@	( http://www.coranac.com/projects/#grit )
@
@=======================================================================

	.section .rodata
	.align	2
	.global birdTiles		@ 1024 unsigned chars
	.hidden birdTiles
birdTiles:
	.word 0x294D4D21,0x29292929,0x29292929,0x29292929,0x2929294D,0x29292929,0x29292929,0x29292929
	.word 0x29292929,0x29292929,0x29292929,0x29292929,0x2929294D,0x44292929,0x29292929,0x3C212929
	.word 0x29292929,0x29292929,0x29292929,0x29292929,0x29292929,0x29292929,0x29292929,0x29292929
	.word 0x3F292929,0x29292929,0x562E2929,0x2929073F,0x473C1C2E,0x1C40243A,0x3705052D,0x05050A0A
	.word 0x294D2929,0x29292929,0x29292929,0x29292929,0x21292929,0x29292921,0x29292929,0x29292929
	.word 0x21292929,0x29292929,0x21292929,0x29292121,0x29482E2E,0x29212129,0x2E050505,0x2929292E
	.word 0x29294D4D,0x214D2929,0x29292929,0x29292929,0x29292929,0x29292929,0x29292929,0x29292929
	.word 0x29292929,0x29292929,0x29292929,0x29292929,0x29292929,0x4D292929,0x29292929,0x29292929

	.word 0x29292921,0x24212929,0x29292929,0x29292129,0x29292929,0x29292929,0x29292929,0x29292929
	.word 0x29292929,0x29292929,0x2929294D,0x3C24241C,0x2929294D,0x2E3A3640,0x29292929,0x35372739
	.word 0x37373746,0x223A3A37,0x1F392E2E,0x3A3D3A3A,0x49203929,0x163A3A3A,0x56202429,0x16163A3A
	.word 0x1E20202E,0x2E16063A,0x2036203C,0x1016573A,0x2020203C,0x3E160620,0x3F243F3C,0x16161C3F
	.word 0x22223A22,0x29292E22,0x003A3A3A,0x4D3C3A3A,0x3A3A1616,0x2E053A3A,0x3A162A39,0x393F513A
	.word 0x16162F22,0x22220B40,0x16163C3F,0x54154F39,0x16164C4C,0x50505039,0x16161616,0x1B1B4E39
	.word 0x29292929,0x29292929,0x29292929,0x21292929,0x29292929,0x29292929,0x29292948,0x29292929
	.word 0x29291D1C,0x29292929,0x29042B54,0x29292929,0x29293913,0x29292929,0x29292939,0x29212929

	.word 0x29292929,0x243C2724,0x2929294D,0x0D2E3C29,0x29292929,0x203C2929,0x29292929,0x023C2921
	.word 0x29292929,0x24212129,0x29292929,0x21212121,0x29292929,0x21212929,0x29292929,0x29292929
	.word 0x3A3A052E,0x162E2222,0x3A3A3A3A,0x16391A3A,0x3A3A2020,0x162E373A,0x37202020,0x16262E20
	.word 0x3F2E2E2E,0x1643453C,0x18182E0E,0x43434343,0x033C2929,0x19323131,0x502E290C,0x0F531C24
	.word 0x16161616,0x40161616,0x16161616,0x39161616,0x16161616,0x39181616,0x16161616,0x29511816
	.word 0x43431616,0x29044018,0x43434343,0x29291740,0x013B1455,0x29254A24,0x083C0F0F,0x292E2C54
	.word 0x29292121,0x29292929,0x29292121,0x29292929,0x29292129,0x29292929,0x29292929,0x29292929
	.word 0x29212929,0x29292929,0x29292929,0x29212929,0x29292929,0x29292929,0x2929294D,0x29292929

	.word 0x29292929,0x30294729,0x29292929,0x38383823,0x29292121,0x29292929,0x29292929,0x29292929
	.word 0x2929294D,0x29292929,0x29292929,0x29292929,0x21212929,0x29292121,0x21212929,0x29292921
	.word 0x093C5229,0x2812343F,0x11114252,0x33333342,0x42423333,0x4242334B,0x29292929,0x29292929
	.word 0x29292929,0x29292929,0x29292929,0x29292929,0x29292929,0x29292929,0x29292929,0x2929294D
	.word 0x3F214242,0x290C242E,0x28424233,0x38334211,0x33333328,0x29333333,0x29292929,0x29292929
	.word 0x29212129,0x29292929,0x29212129,0x29292929,0x29292929,0x29292929,0x29294D29,0x29294D4D
	.word 0x29292937,0x29292929,0x29294138,0x29292929,0x29212929,0x29212929,0x29292929,0x4D292929
	.word 0x29292929,0x4D292929,0x29292929,0x4D4D2929,0x29294D29,0x4D292929,0x294D4D4D,0x4D4D4D29

	.section .rodata
	.align	2
	.global birdPal		@ 512 unsigned chars
	.hidden birdPal
birdPal:
	.hword 0x63B1,0x4DC8,0x1E53,0x5B5B,0x5AF4,0x5BCC,0x7BFA,0x3E0E
	.hword 0x7E4C,0x4129,0x0F18,0x72EA,0x63D5,0x3371,0x1427,0x52B3
	.hword 0x1F78,0x0867,0x16F4,0x2446,0x3DF4,0x7F69,0x7FFE,0x318C
	.hword 0x4F9F,0x4697,0x6FD8,0x724E,0x1429,0x1CA7,0x53D0,0x16D6
	.hword 0x1338,0x67D6,0x7FFF,0x26F3,0x1428,0x63F5,0x5EB8,0x12B5
	.hword 0x1714,0x67D5,0x1C69,0x730E,0x7F6D,0x5BAD,0x1828,0x312E
	.hword 0x16F7,0x579E,0x3A34,0x1B15,0x2F33,0x5BCE,0x1339,0x1318
	.hword 0x1AF4,0x1829,0x5BCD,0x4929,0x1848,0x5FCD,0x2778,0x1448

	.hword 0x1849,0x1EF4,0x1715,0x539F,0x1CC7,0x3E36,0x1674,0x1718
	.hword 0x67F6,0x53F1,0x1447,0x1AF5,0x2399,0x67F5,0x724F,0x7F8A
	.hword 0x7E6C,0x1449,0x16F5,0x56B3,0x7F6A,0x4A97,0x53F0,0x7BFB
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000

	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000

	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000

@}}BLOCK(bird)