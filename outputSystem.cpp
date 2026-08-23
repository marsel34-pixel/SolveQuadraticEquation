#include <stdio.h>
#include <math.h>
#include <assert.h>
#include "outputSystem.h"
#include "calculation.h"

int mass[Y_SIZE][X_SIZE] = {};

void printRoots(int nRoots, double x1, double x2)
{
    switch (nRoots)
    {
    case 0:
        printf("No roots\n");
        break;

    case 1:
        printf("x = %lg\n", x1);
        break;

    case 2:
        printf("x1 = %lg, x2 = %lg\n", x1, x2); // enum?
        break;

    case INFINIT:
        printf("any number\n");
        break;

    default:
        break;
    }
}

void drawPenis(double a, double b, double c)
{
    for (double i = 0; i < X_SIZE; i += 0.01)
    {
        mass[org(i, X_SIZE)][org(a * (i - ZeroX) * (i - ZeroX) + b * (i - ZeroX) + c + ZeroY, Y_SIZE)] = 1;
    }
    double x1 = NAN, x2 = NAN;
    solveQuadraticEquation(a, b, c, &x1, &x2);

    char buffer[100];
    int len1 = 0;
    int len2 = 0;
    if(!isnan(x1))
    {
        len1 = snprintf(buffer, sizeof(buffer), "%lg", x1);
    }
    
    if(!isnan(x2))
    {
        len2 = snprintf(buffer, sizeof(buffer), "%lg", x2);
    }

    drawGraphicFromMass(x1,x2,len1,len2);

    for (int y = 0; y < Y_SIZE; y++)
    {
        for (int x = 0; x < X_SIZE; x++)
        {
            mass[y][x] = 0;
        }
    }
}

int org(double x, int board)//ebal
{
    if (x > 0 && x < board)
    {
        return (int)round(x);
    }
    return 0;
}


void drawNumbers(int *x, int *y, double x1, int len, int up)
{
    len += 2;
    if (!isnan(x1) && (*y == (ZeroY + up) && org(x1 + ZeroX - len / 2, X_SIZE) == *x))
    {
        *x += printf("x=%lg", x1);
    }
}

void drawGraphicFromMass(double x1, double x2, int len1, int len2)
{
    for (int y = Y_SIZE; y > 0; y--)
    {
        for (int x = 0; x < X_SIZE; x++)
        {
            drawNumbers(&x, &y, x1, len1, 2);
            drawNumbers(&x, &y, x2, len2, -2);
            if (mass[x][y])
            {
                printf("#");
            }
            else if (x == ZeroX)
            {
                if (y == 0 || y == Y_SIZE-1)
                {
                    printf("0");
                }
                else if (y == ZeroY+1)
                {
                    printf("1");
                }
                else
                {
                    printf("|");
                }
            }
            else if (y == ZeroY)
            {
                if (x == 0 || x == X_SIZE-1)
                {
                    printf("0");
                }
                else if (x == ZeroX + 1)
                {
                    printf("1");
                }
                else
                {
                    printf("_");
                }
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
    }
}