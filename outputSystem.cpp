#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <string.h>

#include "outputSystem.h"
#include "calculation.h"

char PlotArray[Y_SIZE][X_SIZE] = {};
const int NumLen = 100;
const double step = 0.01;

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
    plotInit();

    int xCoord = 0;
    int yCoord = 0;

    for (double i = 0; i < X_SIZE; i += step)
    {
        xCoord = roundInBounds(i, X_SIZE);
        yCoord = roundInBounds(a * (i - ZeroX) * (i - ZeroX) + b * (i - ZeroX) + c + ZeroY, Y_SIZE);
        PlotArray[yCoord][xCoord] = '#'; 
    }
    
    DrawNumberOnPlot("x=", x1, roundInBounds(x1 + ZeroX,X_SIZE), ZeroY + 2); //const
    DrawNumberOnPlot("x=", x2, roundInBounds(x2 + ZeroX,X_SIZE), ZeroY - 2);

    drawGraphicFromArray();
}


int roundInBounds(double x, int board) 
{
    if (x > 0 && x < board)
    {
        return (int)round(x);
    }
    return 0;
}

void DrawNumberOnPlot(const char *TextBeforeNumber, double NumberValue, int x, int y)
{
    assert(TextBeforeNumber);

    char buffer[NumLen] = {};

    if (!isnan(NumberValue))
    {
        int lenTextToDraw = snprintf(buffer, sizeof(buffer), "%s%lg", TextBeforeNumber, NumberValue);
        int indexDrawnLetters = 0; 

        for (int i = x - lenTextToDraw / 2; i < X_SIZE && buffer[indexDrawnLetters] != '\0'; i++) 
        {
            PlotArray[y][i] = buffer[indexDrawnLetters];
            indexDrawnLetters++;
        }
    }
}

void drawGraphicFromArray()
{
    for (int y = Y_SIZE; y > 0; y--)
    {
        for (int x = 0; x < X_SIZE; x++)
        {
           printf("%c", PlotArray[y][x]);
        }
        printf("\n");
    }
}

void plotInit()
{
    for (int y = 0; y < Y_SIZE; y++)  
    {
        for (int x = 0; x < X_SIZE; x++)
        {
           PlotArray[y][x] = ' ';
        }
    }

    for (int i = 0; i < X_SIZE; i++)
    {
        PlotArray[ZeroY][i] = '_';
    }

    for (int i = 0; i < Y_SIZE; i++)
    {
        PlotArray[i][ZeroX] = '|';
    } 
}