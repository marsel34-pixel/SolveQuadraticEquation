#ifndef OUTPUT_SYSTEM_H
#define OUTPUT_SYSTEM_H

#include "setting.h"

void makePlotBounce(double *a, double *b, double *c, int yCoord);

int findNearestEnemyToPoint(enemy enemyArray[], int x, int y);

void setEnemy(char gameScreen[], char setSymbol, enemy Enemy);

int GetIndexFor1dArrayFromXandY(int x, int y);

void animationPlotInit(char *toDraw);

void calcParabolaPoints(int *xCoord, int *yCoord, double x, double a, double b, double c);

void drawAnimationGraph(double a, double b, double c);

int roundInBounds(double x, int board);

void StaticPlotInit(char StaticPlotArray[][X_SIZE]);

void DrawNumberOnPlot(char StaticPlotArray[][X_SIZE], const char *adding, double value, int x, int y);

void drawGraphicFromArray(char StaticPlotArray[][X_SIZE]);

void plotQuadratics(double a, double b, double c, double x1, double x2);

void printRoots(int nRoots, double x1, double x2);

void gameStep(double a, double b, double c, enemy enemyArray[]);

void gameStepTwoPlayer(double a, double b, double c, enemy firstPlayerGuys[], enemy secondPlayerGuys[], 
                        char firstPlayerAttackSymbol, char secondPlayerAttackSymbol, char firstPlayerGuysSymbol, char secondPlayerGuysSymbol, bool isFirstStep);

#endif