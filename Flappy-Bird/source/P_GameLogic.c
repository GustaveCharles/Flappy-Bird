#include "P_GameLogic.h"

float Birdx = DefaultBirdxPos;
float Birdy = DefaultBirdyPos;
float gravity = -9.8f;
int strength = 5;
float BirdySpeed;
int keys;

void P_GL_initGame();

void P_GL_updateGame()
{
    // Read held keys
    scanKeys();
    keys = keysDown();

    // Modify position of the sprite accordingly
    if ((keys & KEY_UP))
    {
        BirdySpeed = -3;
    }

    if (BirdySpeed < 4)
        BirdySpeed += 0.1;

    Birdy += BirdySpeed;

    oamSet(&oamMain,                   // oam handler
           0,                          // Number of sprite
           Birdx, Birdy,               // Coordinates
           0,                          // Priority
           0,                          // Palette to use
           SpriteSize_32x32,           // Sprite size
           SpriteColorFormat_256Color, // Color format
           gfx,                        // Loaded graphic to display
           -1,                         // Affine rotation to use (-1 none)
           false,                      // Double size if rotating
           false,                      // Hide this sprite
           false, false,               // Horizontal or vertical flip
           false                       // Mosaic
    );
}

void P_GL_endGame();