#include <stdio.h>

#include "outputSystem.h"
#include "calculation.h"

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
            printf("x1 = %lg, x2 = %lg\n", x1, x2);                          // enum?
            break;

        case INFINIT:
            printf("any number\n");
            break;

        default:
            break;
    }
}