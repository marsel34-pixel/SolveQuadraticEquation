#ifndef AI_H
#define AI_H

#include "setting.h"

void AIEnemy(enemy EnemyArray[], double *a, double *b, double *c);

bool checkEndGameForTwoPlayer(enemy firstPlayerGuys[], enemy secondPlayerGuys[]);

char askForSymbolToGame(const char text[]);

void enemyInit(enemy enemyArray[]);

int calcHowManyRemain(enemy enemyArray[]);

int randomNumberInRange(int min, int max);

void gameMode();

void AIWriteText(const char *Text);

void checkTokens(int *tokens);

void infinityDontUnderstand(int *tokens);

void basicProgramm();

void AIUltraProgramm();

void gameTwoPlyerMode();

#endif