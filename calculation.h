#ifndef CALCULATION_H
#define CALCULATION_H

const int INFINIT = 100;

int solveQuadraticEquationWithDiscriminant(double a, double b, double c, double *x1, double *x2);

int solveQuadraticEquation(double a, double b, double c, double *x1, double *x2);

bool isZero(double num);

int solveLinearEquation(double b, double c, double *x);

bool doubleComparsion(double compare1, double compare2);

#endif
