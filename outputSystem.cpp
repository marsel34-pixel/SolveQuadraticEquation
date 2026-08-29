#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <string.h>
#include <windows.h>

#include "outputSystem.h"
#include "calculation.h"

//char StaticPlotArray[Y_SIZE][X_SIZE] = {};



void printRoots(int nRoots, double x1, double x2)
{
    switch (nRoots)
    {
    case NoRoots:
        printf("No roots\n");
        break;

    case OneRoot:
        printf("One root x = %lg\n", x1);
        break;

    case TwoRoots:
        printf("Two roots x1 = %lg, x2 = %lg\n", x1, x2); 
        break;

    case InfRoots:
        printf("any number\n");
        break;

    default:
        break;
    }
}

void plotQuadratics(double a, double b, double c, double x1, double x2)
{
    char StaticPlotArray[Y_SIZE][X_SIZE] = {};
    StaticPlotInit(StaticPlotArray);

    int xCoord = 0;
    int yCoord = 0;

    for (double i = 0; i < X_SIZE; i += step)
    {
        calcParabolaPoints(&xCoord, &yCoord, i, a, b, c);
        StaticPlotArray[yCoord][xCoord] = symbolForParabola; 
    }
    
    DrawNumberOnPlot(StaticPlotArray, "x=", x1, roundInBounds(x1 + ZeroX,X_SIZE), ZeroY + 2);
    DrawNumberOnPlot(StaticPlotArray, "x=", x2, roundInBounds(x2 + ZeroX,X_SIZE), ZeroY - 2);

    drawGraphicFromArray(StaticPlotArray);
}

int roundInBounds(double x, int board) 
{
    if (x > 0 && x < board)
    {
        return (int)round(x);
    }
    return 0;
}

void DrawNumberOnPlot(char StaticPlotArray[][X_SIZE], const char *TextBeforeNumber, double NumberValue, int x, int y)
{
    assert(TextBeforeNumber);

    char buffer[NumLen] = {};

    if (!isnan(NumberValue))
    {
        int lenTextToDraw = snprintf(buffer, sizeof(buffer), "%s%lg", TextBeforeNumber, NumberValue);
        int indexDrawnLetters = 0; 

        for (int i = x - lenTextToDraw / 2; i < X_SIZE && buffer[indexDrawnLetters] != '\0'; i++) 
        {
            StaticPlotArray[y][i] = buffer[indexDrawnLetters];
            indexDrawnLetters++;
        }
    }
}

void drawGraphicFromArray(char StaticPlotArray[][X_SIZE])
{
    for (int y = Y_SIZE; y > 0; y--)
    {
        for (int x = 0; x < X_SIZE; x++)
        {
            if (StaticPlotArray[y][x] == symbolForParabola)
            {
                printf("greenColor%cBaseColor", symbolForParabola);
            }
            else
            {
                putchar(StaticPlotArray[y][x]);
            }
        }
        printf("\n");
    }
}

void drawAnimationGraph(double a, double b, double c)
{
    char toDraw[(Y_SIZE + 1) * (X_SIZE + 1) + 1] = {};

    animationPlotInit(toDraw);

    int xCoord = 0;
    int yCoord = 0;

    for (double i = 0; i < X_SIZE; i += step)
    {
        calcParabolaPoints(&xCoord, &yCoord, i, a, b, c);

        if (toDraw[GetIndexFor1dArrayFromXandY(xCoord, yCoord)] == symbolForParabola || yCoord == 0)
        {
            continue;
        }
        
        toDraw[GetIndexFor1dArrayFromXandY(xCoord, yCoord)] = symbolForParabola; 
        
        printf(returnToStart);
        
        fwrite(toDraw, sizeof(toDraw[0]), (Y_SIZE + 1) * X_SIZE + 1, stdout);
        Sleep(20);
    }    
}

void StaticPlotInit(char StaticPlotArray[][X_SIZE])
{
    for (int y = 0; y < Y_SIZE; y++)  
    {
        for (int x = 0; x < X_SIZE; x++)
        {
           StaticPlotArray[y][x] = ' ';
        }
    }

    for (int i = 0; i < X_SIZE; i++)
    {
        StaticPlotArray[ZeroY][i] = '_';
    }

    for (int i = 0; i < Y_SIZE; i++)
    {
        StaticPlotArray[i][ZeroX] = '|';
    } 
}

void animationPlotInit(char *toDraw)
{
    for (int y = 0; y < Y_SIZE + 1; y++)  
    {
        for (int x = 0; x < X_SIZE + 1; x++)
        {
           toDraw[GetIndexFor1dArrayFromXandY(x, y)] = ' ';
        }
    }

    for (int y = Y_SIZE - 1; y > -1; y--)
    {
        toDraw[GetIndexFor1dArrayFromXandY(X_SIZE, y)] = '\n';
    }

    for (int i = 0; i < X_SIZE; i++)
    {
        toDraw[GetIndexFor1dArrayFromXandY(i, ZeroY)] = '_';
    }

    for (int i = 0; i < Y_SIZE; i++)
    {
        toDraw[GetIndexFor1dArrayFromXandY(ZeroX, i)] = '|';
    } 
}

void calcParabolaPoints(int *xCoord, int *yCoord, double x, double a, double b, double c)
{
    *xCoord = roundInBounds(x, X_SIZE);
    *yCoord = roundInBounds(a * (x - ZeroX) * (x - ZeroX) + b * (x - ZeroX) + c + ZeroY, Y_SIZE);
    //*yCoord = roundInBounds(a * exp(x-ZeroX) + ZeroY, Y_SIZE);
}

int GetIndexFor1dArrayFromXandY(int x, int y)
{
    return y * (X_SIZE + 1) + x;
}

void gameStep(double a, double b, double c, enemy enemyArray[])
{
    char gameScreen[(Y_SIZE + 1) * (X_SIZE + 1) + 1] = {};
    int xCoord = 0, yCoord = 0;

    animationPlotInit(gameScreen);

    for (int i = 0; i < numEnemy; i++)
    {
        if (enemyArray[i].isAlive)
        {
            setEnemy(gameScreen, '@', enemyArray[i]);
        }
    }

    for (double x = 0; x < X_SIZE; x += step)
    {
        calcParabolaPoints(&xCoord, &yCoord, x, a, b, c);
        
        int NowIndex = GetIndexFor1dArrayFromXandY(xCoord, yCoord);
        if (gameScreen[NowIndex] == symbolForParabola || yCoord == 0)
        {
            continue;
        }
        else if (gameScreen[NowIndex] == '@')
        {
            int indexNearestEnemy = findNearestEnemyToPoint(enemyArray, xCoord, yCoord);

            setEnemy(gameScreen, ' ', enemyArray[indexNearestEnemy]);
            enemyArray[indexNearestEnemy].isAlive = 0;

            makePlotBounce(&a, &b, &c, yCoord);
        }

        gameScreen[NowIndex] = symbolForParabola; 
        
        printf(returnToStart);
        fwrite(gameScreen, sizeof(gameScreen[0]), (Y_SIZE + 1) * X_SIZE + 1, stdout);
        Sleep(20);
    }    
}

void setEnemy(char gameScreen[], char setSymbol, enemy Enemy)
{
    for (int i = 0; i < maxEnemySize; i++)
    {
        gameScreen[GetIndexFor1dArrayFromXandY(Enemy.x + Enemy.enemyPointsArray[i][0], Enemy.y + Enemy.enemyPointsArray[i][1])] = setSymbol;
    }
}

int findNearestEnemyToPoint(enemy enemyArray[], int x, int y)
{
    double minDistToEnemy = 12000;
    int indexNearestEnemy = 0;

    for (int j = 0; j < numEnemy; j++)
    {
        if(enemyArray[j].isAlive)
        {
            double thisDist = (x - enemyArray[j].x) * (x - enemyArray[j].x) + (y - enemyArray[j].y) * (y - enemyArray[j].y);
            if (thisDist < minDistToEnemy)
            {
                indexNearestEnemy = j;
                minDistToEnemy = thisDist;
            }
        }
    }

    return indexNearestEnemy;
}

void gameStepTwoPlayer(double a, double b, double c, enemy firstPlayerGuys[], enemy secondPlayerGuys[], 
                        char firstPlayerAttackSymbol, char secondPlayerAttackSymbol, char firstPlayerGuysSymbol, char secondPlayerGuysSymbol, bool isFirstStep)
{
    char gameScreen[(Y_SIZE + 1) * (X_SIZE + 1) + 1] = {};
    int xCoord = 0, yCoord = 0;
    
    animationPlotInit(gameScreen);

    for (int i = 0; i < numEnemy; i++)
    {
        if (firstPlayerGuys[i].isAlive)
        {
            setEnemy(gameScreen, firstPlayerGuysSymbol, firstPlayerGuys[i]);
        }
    }
    for (int i = 0; i < numEnemy; i++)
    {
        if (secondPlayerGuys[i].isAlive)
        {
            setEnemy(gameScreen, secondPlayerGuysSymbol, secondPlayerGuys[i]);
        }
    }

    for (double i = 0; i < X_SIZE; i += step)
    {
        calcParabolaPoints(&xCoord, &yCoord, i, a, b, c);
        
        
        int NowIndex = GetIndexFor1dArrayFromXandY(xCoord, yCoord);
        if (gameScreen[NowIndex] == (isFirstStep ? firstPlayerAttackSymbol : secondPlayerAttackSymbol) || yCoord == 0)
        {
            continue;
        }
        else if (gameScreen[NowIndex] == firstPlayerGuysSymbol)
        {
            int indexNearestEnemy = findNearestEnemyToPoint(firstPlayerGuys, xCoord, yCoord);

            setEnemy(gameScreen, ' ', firstPlayerGuys[indexNearestEnemy]);
            firstPlayerGuys[indexNearestEnemy].isAlive = 0;
            makePlotBounce(&a, &b, &c, yCoord);
        }
        else if (gameScreen[NowIndex] == secondPlayerGuysSymbol)
        {
            int indexNearestEnemy = findNearestEnemyToPoint(secondPlayerGuys, xCoord, yCoord);

            setEnemy(gameScreen, ' ', secondPlayerGuys[indexNearestEnemy]);
            secondPlayerGuys[indexNearestEnemy].isAlive = 0;
            makePlotBounce(&a, &b, &c, yCoord);
        }
        
        gameScreen[NowIndex] = isFirstStep ? firstPlayerAttackSymbol : secondPlayerAttackSymbol; 
        
        printf(returnToStart);
        fwrite(gameScreen, sizeof(gameScreen[0]), (Y_SIZE + 1) * X_SIZE + 1, stdout);
        //Beep(-(yCoord-ZeroY)*150,20);
        Sleep(20);
    }    
}

void makePlotBounce(double *a, double *b, double *c, int yCoord)
{
    *a = -*a;
    *c = -*c;
    *b = -*b;
    *c += 2*(yCoord-ZeroY);
}