
#include <nds.h>
#include <stdio.h>
#include "P_GameLogic.h"
#include "chrono_display.h"
#define SCREEN_WIDTH 256
#define SCREEN_HEIGHT 192

#define SPRITE_WIDTH 32
#define SPRITE_HEIGHT 32


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


int main(void)
{
    P_GL_initGame();
    //Enable Interrupt for the timers and Vblank and set the handlers
	initChronoDisp_Sub();
	changeColorDisp_Sub(ARGB16(1,31,0,0));
	irqInit();
	min = sec = msec = 0;
	TIMER_DATA(0) = TIMER_FREQ_1024(1000);
	TIMER0_CR = TIMER_ENABLE | TIMER_DIV_1024 | TIMER_IRQ_REQ;
	irqSet(IRQ_TIMER0, &TIMER0_ISR);
	irqEnable(IRQ_TIMER0);
    irqSet(IRQ_VBLANK, &VBLANK_ISR);
	irqEnable(IRQ_VBLANK);

    while (1)
    {
        P_GL_updateGame();
        swiWaitForVBlank();
        // Update the sprites
        oamUpdate(&oamMain);
    }

    return 0;
}
