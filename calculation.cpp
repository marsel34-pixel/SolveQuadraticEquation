
#include <math.h>
#include <assert.h>
#include <stdio.h>
#include "calculation.h"


bool isZero(double num)
{
    const double epsilon = 1e-9;
    return fabs(num) < epsilon;
}

bool areDoubleEqual(double compare1, double compare2)
{
    return (isZero(compare1 - compare2) || (isnan(compare1) && isnan(compare2)));
}

int solveQuadraticEquation(double a, double b, double c, double *x1, double *x2)
{
    assert(x1);
    assert(x2);

    if (!isZero(a))
    {
        if (isZero(c) && !isZero(b))
        {
            *x1 = 0;
            return solveLinearEquation(a, b, x2) + 1;
        }
        return solveQuadraticEquationWithDiscriminant(a, b, c, x1, x2);
    }
    else
    {
        return solveLinearEquation(b, c, x1);
    }
}

int solveLinearEquation(double k, double b, double *x)
{
    assert(x);

    if (isZero(k))
    {
        return isZero(b) ? InfRoots : NoRoots;
    }
    else
    {
        *x = -b / k;
        return OneRoot;
    }
}

int solveQuadraticEquationWithDiscriminant(double a, double b, double c, double *x1, double *x2)
{
    assert(x1);
    assert(x2);

    double D = b * b - 4 * a * c;
    if (isZero(D))
    {
        *x1 = (-b) / (2 * a);
        return OneRoot;
    }
    else if (D < 0)
    {
        return NoRoots;
    }
    else
    {
        *x1 = (-b + sqrt(D)) / (2 * a);
        *x2 = (-b - sqrt(D)) / (2 * a);
        return TwoRoots;
    }
}
