#include <math.h>
#include <stdio.h>

#include "calculation.h"
#include "test.h"

void RunAllTests()
{
    testUnit TestMat[] = { { 1, 2, 1, 1, -1, NAN},
                          {1, -2, 1, 1, 1, NAN},
                          {1, 5, 6, 2, -2, -3},
                          {1, 0, -81, 2, -9, 9},
                          {1, 0, 81, 0, NAN, NAN},
                          {0, 10, 90, 1, -9, NAN},
                          {1, 10, 0, 2, -10, 0},
                          {0, 0, 0, INFINIT, NAN, NAN},
                          {0, 0, 3, 0, NAN, NAN},
                          {2, 10, 12, 2, -1, -2},
                          {1, 0, 0, 1, 0, NAN} };

    int NumWrongTest = 0;
    size_t TestSize = sizeof(TestMat) / sizeof(TestMat[0]);

    for (size_t i = 0; i < TestSize; i++)
    {
        NumWrongTest += RunTest(TestMat[i]);
    }

    if (NumWrongTest > 0)
    {
        printf("Something Go Wrong\n"
               "Num errors %d\n"
               "Num Test %lld\n",
                NumWrongTest, TestSize);
    }
    else
    {
        printf("all test was complite");
    }
}

int RunTest(testUnit TestMat)
{
    double x1 = NAN, x2 = NAN;
    int nRoots = NAN;

    nRoots = solveQuadraticEquation(TestMat.a, TestMat.b, TestMat.c, &x1, &x2);

    if (!(nRoots == TestMat.nRoots && ((doubleComparsion(x1, TestMat.x1) && doubleComparsion(x2, TestMat.x2)) ||
                                       (doubleComparsion(x2, TestMat.x1) && doubleComparsion(x1, TestMat.x2)))))
    {
        ErrorMesage(TestMat, nRoots, x1, x2);
        return 1;
    }
    return 0;
}

void ErrorMesage(testUnit TestMat, int nRoots, double x1, double x2)
{
    printf("\033[31mTest FAILED: a=%lg, b=%lg, c=%lg\n"
           "Expected x1=%lg, x2=%lg, nRoots=%d\n"
           "got:     x1=%lg, x2=%lg, nRoots=%d\n\033[0m",
           TestMat.a, TestMat.b, TestMat.c, TestMat.x1, TestMat.x2, TestMat.nRoots, x1, x2, nRoots);
}