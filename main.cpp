#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <cctype>
#include <math.h>

#include "calculation.h"
#include "inputSystem.h"
#include "test.h"

void printRoots(int nRoots, double x1, double x2);

//---------------------------------------------------------------

int main()
{   
    bool isTestNow = 1;
    if(!isTestNow)
        {
        bool keepSolving = 1;
        double a = 0, b = 0, c = 0;       //FIXME
        double x1 = NAN, x2 = NAN;

        while (keepSolving)
        {

            //readCooficients(&a,&b,&c);     //FIXME
            readCoofs(&a, &b, &c);
            int nRoots = solveQuadraticEquation(a, b, c, &x1, &x2);

            printRoots(nRoots, x1, x2);

            keepSolving = needContinue();

            clearInput();
        }
    }
    else
    {
        // double TestMat[][6] = {{1,2,1,1,-1,NAN},
        //                         {1,-2,1,1,1,NAN},
        //                         {1,5,6, 2, -2,-3},
        //                         {1,2,-89, 1, -1, 67},
        //                         {0,0,0,INFINIT,0,0},
        //                         {0,0,3,INFINIT,12,3}};

        double TestMat[][6] = {{1,2,1,1,-1,NAN},
                                {1,-2,1,1,1,NAN},
                                {1,5,6, 2, -2,-3},
                                {1,0,-81, 2, -9, 9},
                                {1,0,81, 0, 0, 0},
                                {0,10,90, 1, -9, 0},
                                {1,10,0, 2, -10, 0},
                                {0,0,0,INFINIT,0,0},
                                {0,0,3,0,NAN,NAN}};
                                
        for(int i = 0; i < (int)(sizeof(TestMat)/sizeof(TestMat[0])); i++)
        {
            RunTest(TestMat[i][0], TestMat[i][1], TestMat[i][2], (int)TestMat[i][3], TestMat[i][4], TestMat[i][5]);
        }

    }
    return 0;
}

//---------------------------------------------------------------

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

//---------------------------------------------------------------
