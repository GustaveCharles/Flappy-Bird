#include "P_GameLogic.h"

float Birdx = DefaultBirdxPos;
float Birdy = DefaultBirdyPos;
float gravity = -9.8f;
int strength = 5;
float BirdySpeed;

int Gameplay_state;
int Gameplay_playerScore;
char *Gameplay_playerName;
int keys;

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
    else if (Gameplay_state == 2)
    {
       // P_GL_updateGameOver();
    }
}

void P_GL_endGame();