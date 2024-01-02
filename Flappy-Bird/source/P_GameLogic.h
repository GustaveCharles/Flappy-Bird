
#include <nds.h>
#include "P_Graphics.h"

#define DefaultBirdxPos 50
#define DefaultBirdyPos 80

extern int Gameplay_state;
extern int Gameplay_playerScore;
extern char* Gameplay_playerName;
extern int keys;

void P_GL_initGame();

void P_GL_updateGame();

void P_GL_endGame();
