#include "P_Audio.h"


void Audio_Init(){
    mmInitDefaultMem((mm_addr)soundbank_bin);
    //mmLoadEffect(SFX_START);
    //mmLoadEffect(SFX_HIT);
    //mmLoadEffect(SFX_POINT);
    mmLoadEffect(SFX_JUMP);
    //mmLoad(SFX_TIMER_END);
    //mmLoad(MOD_MUSIC);
    //mmStart(MOD_MUSIC, MM_PLAY_LOOP);
}