#include <nds.h>
#include "P_Graphics.h"
#include "sky.h"
#include "bird.h"
#include "over.h"

//Pointer to the graphic buffer where to store the sprite
u16* gfx;
u16* over;

void P_Graphics_setup_main(){
    	//Activate and configure VRAM bank to work in background mode
	VRAM_A_CR = VRAM_ENABLE | VRAM_A_MAIN_BG;

	//BG0 configuration for the background
	BGCTRL[0] = BG_COLOR_256 | BG_MAP_BASE(0) | BG_TILE_BASE(1) | BG_32x32;

	//Copy data to display background (tiles, palette and map)
	swiCopy(skyTiles, BG_TILE_RAM(1), skyTilesLen/2);
	swiCopy(skyPal, BG_PALETTE, skyPalLen/2);
	swiCopy(skyMap, BG_MAP_RAM(0), skyMapLen/2);
}

void P_Graphics_setup_sub(){
        //Activate and configure VRAM bank to work in background mode
    VRAM_C_CR = VRAM_ENABLE | VRAM_C_SUB_BG;
    // Sub BG0 configuration for the background
    BGCTRL_SUB[0] = BG_COLOR_256 | BG_MAP_BASE(0) | BG_TILE_BASE(1) | BG_32x32;

    //Copy data to display background (tiles, palette and map)
    swiCopy(skyTiles, BG_TILE_RAM_SUB(1), skyTilesLen/2);
    swiCopy(skyPal, BG_PALETTE_SUB, skyPalLen/2);
    swiCopy(skyMap, BG_MAP_RAM_SUB(0), skyMapLen/2);
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
	over = oamAllocateGfx(&oamMain, SpriteSize_64x32, SpriteColorFormat_256Color);

	//Copy data for the graphic (palette and bitmap)
	swiCopy(birdPal, SPRITE_PALETTE, birdPalLen/2);
	swiCopy(birdTiles, gfx, birdTilesLen/2);

	swiCopy(overPal, &SPRITE_PALETTE[birdPalLen/2], overPalLen/2);
	swiCopy(overTiles, over, overTilesLen/2);
}