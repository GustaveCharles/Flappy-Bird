#include "P_GameLogic.h"

float Birdx = DefaultBirdxPos;
float Birdy = DefaultBirdyPos;
float gravity = -9.8f;
int strength = 5;
float BirdySpeed;
float GameSpeedx = 0.3f;

int Gameplay_state;
int Gameplay_playerScore;
char *Gameplay_playerName;
int keys;
float tubesAx[tubesA] = {100, 110, 120, 130, 140, 150, 160, 170, 180, 190};
float tubesAy[tubesA] = {50, 50, 50, 50, 50, 50, 50, 50, 50, 50};
float tubesBx[tubesB] = {100, 110, 120, 130, 140, 150, 160, 170, 180, 190, 200, 210, 220, 230, 240};
float tubesBy[tubesB] = {50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50};

// Initializes the game
//  - Loads the sprites
//  - Loads the background
//  - Initializes the bird position

void P_GL_initGame()
{
    // MAIN and SUB engine configuration
    REG_DISPCNT = MODE_0_2D | DISPLAY_BG0_ACTIVE;
    REG_DISPCNT_SUB = MODE_5_2D | DISPLAY_BG0_ACTIVE;

    // Configure and fill BG0
    P_Graphics_setup_main();
    P_Graphics_setup_sub();

    // Configure sprites
    P_Graphics_setup_sprites();
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

    for (int i = 0; i < 1; i++)
    {
        if (tubesAx[i] < 256 && tubesAx[i] > 0)
        {
        oamSet(&oamMain,                   // oam handler
               2,                          // Number of sprite
               tubesAx[i], tubesAy[i],               // Coordinates
               0,                          // Priority
               2,                          // Palette to use
               SpriteSize_16x32,           // Sprite size
               SpriteColorFormat_256Color, // Color format
               tube,                        // Loaded graphic to display
               -1,                         // Affine rotation to use (-1 none)
               false,                      // Double size if rotating
               false,                      // Hide this sprite
               false, false,               // Horizontal or vertical flip
               false                       // Mosaic
        );
        } else {
            oamSet(&oamMain,                   // oam handler
               2,                          // Number of sprite
               tubesAx[i], tubesAy[i],               // Coordinates
               0,                          // Priority
               2,                          // Palette to use
               SpriteSize_16x32,           // Sprite size
               SpriteColorFormat_256Color, // Color format
               tube,                        // Loaded graphic to display
               -1,                         // Affine rotation to use (-1 none)
               false,                      // Double size if rotating
               true,                      // Hide this sprite
               false, false,               // Horizontal or vertical flip
               false                       // Mosaic
        );
        }
    }

    Gameplay_state = 0;
    Gameplay_playerScore = 0;
    Gameplay_playerName = "Player";
}

// Updates the game logic during the game:
//  - Updates the position of the bird
//  - Checks for collisions and game over
//  - Updates the tubes

void P_GL_updateGame()
{
    // Read held keys
    scanKeys();
    keys = keysDown();

    if (Gameplay_state == 0)
    {

        // P_GL_updateGameStart();
        if (keys & KEY_DOWN)
        {
            Gameplay_state = 1;
        }
    }
    else if (Gameplay_state == 1)
    {

        // Modify position of the sprite accordingly
        if ((keys & KEY_UP))
        {
            BirdySpeed = -3;
        }

        if (BirdySpeed < 4)
            BirdySpeed += 0.1;
        if (
            (Birdy < 0) ||
            (Birdy > 192 - 32))
        {
            Gameplay_state = 2;
        } else {
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

        for (int i = 0; i < tubesA; i++) {
            tubesAx[i] -= GameSpeedx;
        }
        if (tubesAx[0] < 256 && tubesAx[0] > -16)
        {
        oamSet(&oamMain,                   // oam handler
               2,                          // Number of sprite
               tubesAx[0], tubesAy[0],               // Coordinates
               0,                          // Priority
               2,                          // Palette to use
               SpriteSize_16x32,           // Sprite size
               SpriteColorFormat_256Color, // Color format
               tube,                        // Loaded graphic to display
               -1,                         // Affine rotation to use (-1 none)
               false,                      // Double size if rotating
               false,                      // Hide this sprite
               false, false,               // Horizontal or vertical flip
               false                       // Mosaic
        );
        } else {
            oamSet(&oamMain,                   // oam handler
               2,                          // Number of sprite
               tubesAx[0], tubesAy[0],               // Coordinates
               0,                          // Priority
               2,                          // Palette to use
               SpriteSize_16x32,           // Sprite size
               SpriteColorFormat_256Color, // Color format
               tube,                        // Loaded graphic to display
               -1,                         // Affine rotation to use (-1 none)
               false,                      // Double size if rotating
               true,                      // Hide this sprite
               false, false,               // Horizontal or vertical flip
               false                       // Mosaic
        );
        }


        }
    }
    else if (Gameplay_state == 2)
    {
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
               true,                      // Hide this sprite
               false, false,               // Horizontal or vertical flip
               false                       // Mosaic
        );
        oamSet(&oamMain,                   // oam handler
           1,                          // Number of sprite
           0, 0,               // Coordinates
           0,                          // Priority
           1,                          // Palette to use
           SpriteSize_64x32,           // Sprite size
           SpriteColorFormat_256Color, // Color format
           over,                        // Loaded graphic to display
           -1,                         // Affine rotation to use (-1 none)
           false,                      // Double size if rotating
           false,                      // Hide this sprite
           false, false,               // Horizontal or vertical flip
           false                       // Mosaic
    );
       // P_GL_updateGameOver();
    }
}

void P_GL_endGame();