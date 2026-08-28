#ifndef AI_H
#define AI_H

#include "setting.h"

void enemyInit(enemy enemyArray[], const int numEnemy);

int randomNumberInRange(int min, int max);

void gameMode();

void AIWriteText(const char *Text);

void checkTokens(int *tokens);

void infinityDontUnderstand(int *tokens);

void basicProgramm();

void AIUltraProgramm();

#endif