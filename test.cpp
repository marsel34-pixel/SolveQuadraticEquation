#include <math.h>
#include <stdio.h>

#include "calculation.h"
#include "test.h"

testUnit TestArrayFromFile[MaxTestLen] = {};

size_t ReadTestsUnitFromFile(testUnit *TestArray)
{
    FILE *file = fopen("test.txt", "r");

    size_t sizeTestArray = 0;

    if (file == NULL)
    {
        printf("Read error: cant open file\n");
        return 0;
    }

    for (int i = 0; i < MaxTestLen; i++)
    {
        int sucsesRead = fscanf(file, "%lg %lg %lg %d %lg %lg", &TestArray[i].a, &TestArray[i].b, &TestArray[i].c, 
                                                                &TestArray[i].nRoots, &TestArray[i].x1, &TestArray[i].x2);
        if(sucsesRead < 6)
        {
            if (sucsesRead == -1)
            {
                sizeTestArray = i;
                break;
            }
            sizeTestArray = 0;
            printf("Read error: wrong input format\n");
            break;
        }
    }

    fclose(file);

    return sizeTestArray;
}

void RunAllTestsFromArray(testUnit *TestMat, size_t TestSize)
{

    int NumWrongTest = 0;

    for (size_t i = 0; i < TestSize; i++)
    {
        NumWrongTest += RunTest(TestMat[i]);
    }

    if (NumWrongTest > 0)
    {
        printf("Something Go Wrong\n"
               "Num errors %d\n"
               "Num Test %lld\n\n",
               NumWrongTest, TestSize);
    }
    else
    {
        printf("all test was complite\n\n");
    }
}

int RunTest(testUnit TestMat)
{
    double x1 = NAN, x2 = NAN;
    int nRoots = NAN;

    nRoots = solveQuadraticEquation(TestMat.a, TestMat.b, TestMat.c, &x1, &x2);

    if (!(nRoots == TestMat.nRoots && ((areDoubleEqual(x1, TestMat.x1) && areDoubleEqual(x2, TestMat.x2)) ||
                                       (areDoubleEqual(x2, TestMat.x1) && areDoubleEqual(x1, TestMat.x2)))))
    {
        ErrorMesage(TestMat, nRoots, x1, x2);
        return 1;
    }
    
    return 0;
}

int RunAllAvaiaibleTests()
{
    testUnit TestArrayFromCode[] = { { 1, 2,  1,   1,        -1,  NAN        },
                                     { 1, -2, 1,   1,        1,   NAN        },
                                     { 1, 5,  6,   2,        -2,  -3         },
                                     { 1, 0,  -81, 2,        -9,  9          },
                                     { 1, 0,  81,  0,        NAN, NAN        },
                                     { 0, 10, 90,  1,        -9,  NAN        },
                                     { 1, 10, 0,   2,        -10, 0          },
                                     { 0, 0,  0,   InfRoots, NAN, NAN        },  
                                     { 0, 0,  3,   0,        NAN, NAN        },
                                     { 2, 10, 12,  2,         -1, -2         },
                                     { 1, 0,  0,   1,          0, NAN        } };
        
    size_t testArraySize = ReadTestsUnitFromFile(TestArrayFromFile);

    if (testArraySize > 0)
    {
        printf("Running tests from file\n");
        RunAllTestsFromArray(TestArrayFromFile, testArraySize);
    }
    else
    {
        return 1;
    }

    printf("Running tests from code\n");
    RunAllTestsFromArray(TestArrayFromCode, sizeof(TestArrayFromCode) / sizeof(TestArrayFromCode[0]));

    return 0;
}

void ErrorMesage(testUnit TestMat, int nRoots, double x1, double x2)
{
    printf("%sTest FAILED: a=%lg, b=%lg, c=%lg\n"
           "Expected x1=%lg, x2=%lg, nRoots=%d\n"
           "got:     x1=%lg, x2=%lg, nRoots=%d\n%s", redColor,
           TestMat.a, TestMat.b, TestMat.c, TestMat.x1, TestMat.x2, TestMat.nRoots, x1, x2, nRoots,
            BaseColor);
}