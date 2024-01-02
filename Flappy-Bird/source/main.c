
#include <nds.h>
#include <stdio.h>
#include "field.h"
#include "ball.h"

#define SCREEN_WIDTH	256
#define	SCREEN_HEIGHT	192

#define	SPRITE_WIDTH	32
#define	SPRITE_HEIGHT	32


#define DefaultBirdxPos 50
#define DefaultBirdyPos 80

//Pointer to the graphic buffer where to store the sprite
u16* gfx;
float Birdx = DefaultBirdxPos;
float  Birdy = DefaultBirdyPos;
float gravity = -9.8f;
int strength = 5;
float BirdySpeed;

void configureBG0() {
	//Activate and configure VRAM bank to work in background mode
	VRAM_A_CR = VRAM_ENABLE | VRAM_A_MAIN_BG;

	//BG0 configuration for the background
	BGCTRL[0] = BG_COLOR_256 | BG_MAP_BASE(0) | BG_TILE_BASE(1) | BG_32x32;

	//Copy data to display background (tiles, palette and map)
	swiCopy(fieldTiles, BG_TILE_RAM(1), fieldTilesLen/2);
	swiCopy(fieldPal, BG_PALETTE, fieldPalLen/2);
	swiCopy(fieldMap, BG_MAP_RAM(0), fieldMapLen/2);
}

void configureBG1() {
    //Activate and configure VRAM bank to work in background mode
    VRAM_C_CR = VRAM_ENABLE | VRAM_C_SUB_BG;
    // Sub BG0 configuration for the background
    BGCTRL_SUB[0] = BG_COLOR_256 | BG_MAP_BASE(0) | BG_TILE_BASE(1) | BG_32x32;

    //Copy data to display background (tiles, palette and map)
    swiCopy(fieldTiles, BG_TILE_RAM_SUB(1), fieldTilesLen/2);
    swiCopy(fieldPal, BG_PALETTE_SUB, fieldPalLen/2);
    swiCopy(fieldMap, BG_MAP_RAM_SUB(0), fieldMapLen/2);
}


void configureSprites() {
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

int main(void) {

	//MAIN engine
	REG_DISPCNT = MODE_0_2D | DISPLAY_BG0_ACTIVE ;
    REG_DISPCNT_SUB = MODE_5_2D | DISPLAY_BG0_ACTIVE;

	//Configure and fill BG0
	configureBG0();
    configureBG1();

	//Configure sprites and fill graphics
	configureSprites();

	//Position
	int keys;
    while(1){
    	//Read held keys
    	scanKeys();
    	keys = keysDown();

    	//Modify position of the sprite accordingly
    	if((keys & KEY_UP)){
            BirdySpeed = -3;
        } 

        if (BirdySpeed < 4)
				BirdySpeed += 0.1;

			Birdy += BirdySpeed;

    	oamSet(&oamMain, 	// oam handler
    		0,				// Number of sprite
    		Birdx, Birdy,			// Coordinates
    		0,				// Priority
    		0,				// Palette to use
    		SpriteSize_32x32,			// Sprite size
    		SpriteColorFormat_256Color,	// Color format
    		gfx,			// Loaded graphic to display
    		-1,				// Affine rotation to use (-1 none)
    		false,			// Double size if rotating
    		false,			// Hide this sprite
    		false, false,	// Horizontal or vertical flip
    		false			// Mosaic
    		);
    	swiWaitForVBlank();
    	//Update the sprites
		oamUpdate(&oamMain);
    }
}

void updateSprite(){

}
