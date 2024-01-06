#include <nds.h>
#include "P_Graphics.h"
#include "bird.h"
#include "over.h"

// Pointer to the graphic buffer where to store the sprite
u16 *gfx;
u16 *over;

void P_Graphics_setup_main()
{
    // Graphics (Part 3)
    // Enable a proper RAM memory bank for the main engine
    VRAM_A_CR = VRAM_ENABLE       // Enable
                | VRAM_A_MAIN_BG; // Bank for the main engine

    // Configure the main engine in mode 0 (2D) and activate Backgrounds 3 and 0
    REG_DISPCNT = MODE_0_2D | DISPLAY_BG0_ACTIVE | DISPLAY_BG3_ACTIVE;

    // Enable a proper RAM memory bank for sub engine
    VRAM_C_CR = VRAM_ENABLE | VRAM_C_SUB_BG;
    // Configure the sub engine in mode 5 (2D) and activate Backgrounds 2 and 0
    REG_DISPCNT_SUB = MODE_5_2D | DISPLAY_BG2_ACTIVE | DISPLAY_BG0_ACTIVE;
}


void P_Graphics_setup_sprites()
{
	// Set up memory bank to work in sprite mode (offset since we are using VRAM A for backgrounds)
	VRAM_B_CR = VRAM_ENABLE | VRAM_B_MAIN_SPRITE_0x06400000;

	// Initialize sprite manager and the engine
	oamInit(&oamMain, SpriteMapping_1D_32, false);

	// Allocate space for the graphic to show in the sprite
	gfx = oamAllocateGfx(&oamMain, SpriteSize_32x32, SpriteColorFormat_256Color);
	over = oamAllocateGfx(&oamMain, SpriteSize_64x32, SpriteColorFormat_256Color);

	// Copy data for the graphic (palette and bitmap)
	swiCopy(birdPal, SPRITE_PALETTE, birdPalLen / 2);
	swiCopy(birdTiles, gfx, birdTilesLen / 2);

	swiCopy(overPal, SPRITE_PALETTE + birdPalLen, overPalLen / 2);
	swiCopy(overTiles, over, overTilesLen / 2);

}

// void initChronoDisp_Sub()
// {
// 	// VRAM_C_CR = VRAM_ENABLE | VRAM_C_SUB_BG;

// 	REG_DISPCNT_SUB = MODE_0_2D | DISPLAY_BG0_ACTIVE;

// 	BGCTRL_SUB[0] = BG_32x32 | BG_COLOR_256 | BG_MAP_BASE(0) | BG_TILE_BASE(1);
// 	//BG_PRIORITY_SUB[0] = 3;

// 	swiCopy(numbersTiles, BG_TILE_RAM_SUB(1), numbersTilesLen);
// 	swiCopy(numbersPal, BG_PALETTE_SUB, numbersPalLen);
// 	BG_PALETTE_SUB[0] = ARGB16(1, 31, 31, 0);
// 	BG_PALETTE_SUB[1] = ARGB16(1, 0, 0, 0);
// 	memset(BG_MAP_RAM_SUB(0), 32, 32 * 32 * 2);
// 	updateChronoDisp_Sub(-1, -1, -1);
// }

// void printDigit(u16 *map, int number, int x, int y)
// {
// 	int i, j;
// 	if (number < 10)
// 		for (i = 0; i < 8; i++)
// 			for (j = 0; j < 4; j++)
// 				if (number >= 0)
// 					map[(i + y) * 32 + j + x] = (u16)(i * 4 + j) + 32 * number;
// 				else
// 					map[(i + y) * 32 + j + x] = 32;
// 	if (number == 10)
// 		for (i = 0; i < 8; i++)
// 			for (j = 0; j < 2; j++)
// 				map[(i + y) * 32 + j + x] = (u16)(i * 4 + j) + 32 * 10 + 2;
// 	if (number == 11)
// 		for (i = 0; i < 8; i++)
// 			for (j = 0; j < 2; j++)
// 				map[(i + y) * 32 + j + x] = (u16)(i * 4 + j) + 32 * 10;
// }

// void updateChronoDisp(u16 *map, int min, int sec, int msec)
// {
// 	int x = 0, y = 0;
// 	int number;

// 	/*****MINUTES******/
// 	number = min;
// 	if (min > 59)
// 		min = number = -1;
// 	// First digit
// 	x = 0;
// 	y = 2;
// 	if (min >= 0)
// 		number = min / 10;
// 	printDigit(map, number, x, y);
// 	// Second digit
// 	x = 1;
// 	y = 2;
// 	if (min >= 0)
// 		number = min % 10;
// 	printDigit(map, number, x, y);

// 	/*****POINTS******/
// 	x = 3;
// 	y = 2;
// 	number = 10;
// 	printDigit(map, number, x, y);

// 	/*****SECONDS******/
// 	number = sec;
// 	if (sec > 59)
// 		sec = number = -1;
// 	// First digit
// 	x = 5;
// 	y = 2;
// 	if (sec >= 0)
// 		number = sec / 10;
// 	printDigit(map, number, x, y);
// 	// Second digit
// 	x = 6;
// 	y = 2;
// 	if (sec >= 0)
// 		number = sec % 10;
// 	printDigit(map, number, x, y);

// 	/*****POINT MSEC******/
// 	x = 18;
// 	y = 2;
// 	number = 11;
// 	printDigit(map, number, x, y);

// 	/*****M.SECONDS******/
// 	number = msec;
// 	if (msec > 999)
// 		msec = number = -1;
// 	// First digit
// 	x = 20;
// 	y = 2;
// 	if (msec >= 0)
// 		number = msec / 100;
// 	printDigit(map, number, x, y);

// 	// Second digit
// 	x = 24;
// 	y = 2;
// 	if (msec >= 0)
// 		number = (msec % 100) / 10;
// 	printDigit(map, number, x, y);

// 	// // Third digit
// 	// x = 28;
// 	// y = 2;
// 	// if (msec >= 0)
// 	// 	number = (msec % 10) % 10;
// 	// printDigit(map, number, x, y);
// }

// void updateChronoDisp_Sub(int min, int sec, int msec)
// {
// 	updateChronoDisp(BG_MAP_RAM_SUB(0), min, sec, msec);
// }

// void changeColorDisp_Sub(uint16 c)
// {
// 	BG_PALETTE_SUB[0] = c;
// }