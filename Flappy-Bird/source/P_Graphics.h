#pragma once

#include <nds.h>
//#define FB0
//#define ROTOSCALE
#define TILES

extern u16* gfx;

void P_Graphics_setup_main();

void P_Graphics_setup_sub();

void P_Graphics_setup_menu();

void P_Graphics_setup_start();

void P_Graphics_setup_sprites();