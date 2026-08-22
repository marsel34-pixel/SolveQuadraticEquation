#include <math.h>
#include <stdio.h>

#include "calculation.h"
#include "test.h"


void RunTest(struct testUnit TestMat)
{
    double x1 = NAN, x2 = NAN;
    int nRoots = NAN;

    nRoots = solveQuadraticEquation(TestMat.a, TestMat.b, TestMat.c, &x1, &x2);
    
    if (!(nRoots == TestMat.nRoots && ((doubleComparsion(x1, TestMat.x1) && doubleComparsion(x2 ,TestMat.x2)) || 
                                (doubleComparsion(x2, TestMat.x1) && doubleComparsion(x1, TestMat.x2)))))
    {
        ErrorMesage(TestMat.a, TestMat.b, TestMat.c, TestMat.nRoots, TestMat.x1, TestMat.x2, nRoots, x1, x2);
    }
}

bool doubleComparsion(double compare1, double compare2)
{
    return (isZero(compare1-compare2) || (isnan(compare1) && isnan(compare2)));
}
void ErrorMesage(double a, double b, double c, int nRootsRef, double x1Ref, double x2Ref, int nRoots, double x1, double x2)
{
    printf("Test FAILED: a=%lg, b=%lg, c=%lg\n"
            "Expected x1=%lg, x2=%lg, nRoots=%d\n"
            "got:     x1=%lg, x2=%lg, nRoots=%d\n", 
            a, b, c, x1Ref, x2Ref, nRootsRef, x1, x2, nRoots);
    
}