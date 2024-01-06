
#include <nds.h>
#include <stdio.h>
#include "P_GameLogic.h"
#include "P_Graphics.h"

#define SCREEN_WIDTH 256
#define SCREEN_HEIGHT 192

#define SPRITE_WIDTH 32
#define SPRITE_HEIGHT 32


int main(void)
{
    // Initialize the game    
    P_GL_initGame();

    while (1)
    {
        P_GL_updateGame();
        swiWaitForVBlank();
        // Update the sprites
        oamUpdate(&oamMain);
    }

    return 0;
}
