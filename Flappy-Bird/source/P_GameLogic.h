
#include <nds.h>
#include "P_Graphics.h"
#include "P_Audio.h"

#define DefaultBirdxPos 50
#define DefaultBirdyPos 80
#define tubesA 10
#define tubesB 15

extern int Gameplay_state;
extern int Gameplay_playerScore;
extern char* Gameplay_playerName;
extern int keys;
extern float tubesAx[tubesA];
extern float tubesAy[tubesA];
extern float tubesBx[tubesB];
extern float tubesBy[tubesB];

void P_GL_initGame();

void P_GL_updateGame();

void P_GL_endGame();
