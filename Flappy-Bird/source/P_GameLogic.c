#include "P_GameLogic.h"
#include "P_Map16x16.h"
#include "P_Score.h"

float Birdx = DefaultBirdxPos;
float Birdy = DefaultBirdyPos;
float gravity = -9.8f;
int strength = 5;
float BirdySpeed;
float GameSpeedx = 0.5f;

int Gameplay_state;
int Gameplay_playerScore;
char *Gameplay_playerName;
int keys;
float tubesAx[tubesA] = {100, 110, 120, 130, 140, 150, 160, 170, 180, 190};
float tubesAy[tubesA] = {50, 50, 50, 50, 50, 50, 50, 50, 50, 50};
float tubesBx[tubesB] = {100, 110, 120, 130, 140, 150, 160, 170, 180, 190, 200, 210, 220, 230, 240};
float tubesBy[tubesB] = {50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50};


//Time variables (for the chronometer)
int min = 0, sec = 0, msec = 0;

//Timer 2 ISR (chronometer)
void TIMER0_ISR()
{
	msec = (msec + 1) % 1000;
	if(!msec)
	{
		sec = (sec + 1) % 60;
		if(!sec)
			min++;
	}
}

//Update the chronometer every VBlank
void VBLANK_ISR()
{
	updateChronoDisp_Sub(min,sec,msec);
}

// Initializes the game
//  - Loads the sprites
//  - Loads the background
//  - Initializes the bird position

void P_GL_initGame()
{
    // MAIN and SUB engine configuration
    P_Graphics_setup_main();
    P_Map16x16_Init(16, 12);
    min = sec = msec = 0;
    TIMER_DATA(0) = TIMER_FREQ_1024(1000);
    TIMER0_CR = TIMER_ENABLE | TIMER_DIV_1024 | TIMER_IRQ_REQ;
    irqSet(IRQ_TIMER0, &TIMER0_ISR);
    irqEnable(IRQ_TIMER0);
    irqSet(IRQ_VBLANK, &VBLANK_ISR);
    irqEnable(IRQ_VBLANK);

    //Audio_Init();

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
            mmEffect(SFX_JUMP);
        }
    }
    else if (Gameplay_state == 1)
    {

        // Modify position of the sprite accordingly
        if ((keys & KEY_UP))
        {
            BirdySpeed = -3;
            mmEffect(SFX_JUMP);
        }

        if (BirdySpeed < 4)
            BirdySpeed += 0.1;
        if (
            (Birdy < 0) ||
            (Birdy > 192 - 32))
        {
            Gameplay_state = 2;
        }
        else
        {
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
               true,                       // Hide this sprite
               false, false,               // Horizontal or vertical flip
               false                       // Mosaic
        );
        oamSet(&oamMain,                   // oam handler
               1,                          // Number of sprite
               0, 0,                       // Coordinates
               0,                          // Priority
               0,                          // Palette to use
               SpriteSize_64x32,           // Sprite size
               SpriteColorFormat_256Color, // Color format
               over,                       // Loaded graphic to display
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