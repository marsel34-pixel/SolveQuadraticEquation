#ifndef CALCULATION_H
#define CALCULATION_H

enum NumRoots
{
    NoRoots = 0,
    OneRoot = 1,
    TwoRoots = 2,
    InfRoots = -1
};


int solveQuadraticEquationWithDiscriminant(double a, double b, double c, double *x1, double *x2);

int solveQuadraticEquation(double a, double b, double c, double *x1, double *x2);

bool isZero(double num);

int solveLinearEquation(double b, double c, double *x);

bool areDoubleEqual(double compare1, double compare2);

#endif
