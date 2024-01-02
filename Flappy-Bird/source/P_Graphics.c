#include <nds.h>
#include "P_Graphics.h"
#include "field.h"
#include "ball.h"

//Pointer to the graphic buffer where to store the sprite
u16* gfx;

void P_Graphics_setup_main(){
    	//Activate and configure VRAM bank to work in background mode
	VRAM_A_CR = VRAM_ENABLE | VRAM_A_MAIN_BG;

	//BG0 configuration for the background
	BGCTRL[0] = BG_COLOR_256 | BG_MAP_BASE(0) | BG_TILE_BASE(1) | BG_32x32;

	//Copy data to display background (tiles, palette and map)
	swiCopy(fieldTiles, BG_TILE_RAM(1), fieldTilesLen/2);
	swiCopy(fieldPal, BG_PALETTE, fieldPalLen/2);
	swiCopy(fieldMap, BG_MAP_RAM(0), fieldMapLen/2);
}

void P_Graphics_setup_sub(){
        //Activate and configure VRAM bank to work in background mode
    VRAM_C_CR = VRAM_ENABLE | VRAM_C_SUB_BG;
    // Sub BG0 configuration for the background
    BGCTRL_SUB[0] = BG_COLOR_256 | BG_MAP_BASE(0) | BG_TILE_BASE(1) | BG_32x32;

    //Copy data to display background (tiles, palette and map)
    swiCopy(fieldTiles, BG_TILE_RAM_SUB(1), fieldTilesLen/2);
    swiCopy(fieldPal, BG_PALETTE_SUB, fieldPalLen/2);
    swiCopy(fieldMap, BG_MAP_RAM_SUB(0), fieldMapLen/2);
}

void P_Graphics_setup_menu();

void P_Graphics_setup_start();

void P_Graphics_setup_sprites(){
    	//Set up memory bank to work in sprite mode (offset since we are using VRAM A for backgrounds)
	VRAM_B_CR = VRAM_ENABLE | VRAM_B_MAIN_SPRITE_0x06400000;

	//Initialize sprite manager and the engine
	oamInit(&oamMain, SpriteMapping_1D_32, false);

	//Allocate space for the graphic to show in the sprite
	gfx = oamAllocateGfx(&oamMain, SpriteSize_32x32, SpriteColorFormat_256Color);

	//Copy data for the graphic (palette and bitmap)
	swiCopy(ballPal, SPRITE_PALETTE, ballPalLen/2);
	swiCopy(ballTiles, gfx, ballTilesLen/2);
}