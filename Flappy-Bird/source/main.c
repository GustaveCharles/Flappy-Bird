
#include <nds.h>
#include <stdio.h>
#include "P_Graphics.h"
#include "P_GameLogic.h"

#define SCREEN_WIDTH 256
#define SCREEN_HEIGHT 192

#define SPRITE_WIDTH 32
#define SPRITE_HEIGHT 32

int main(void)
{

    // MAIN and SUB engine configuration
    REG_DISPCNT = MODE_0_2D | DISPLAY_BG0_ACTIVE;
    REG_DISPCNT_SUB = MODE_5_2D | DISPLAY_BG0_ACTIVE;

    // Configure and fill BG0
    P_Graphics_setup_main();
    P_Graphics_setup_sub();

    // Configure sprites
    P_Graphics_setup_sprites();

    while (1)
    {
        P_GL_updateGame();
        swiWaitForVBlank();
        // Update the sprites
        oamUpdate(&oamMain);
    }
}
