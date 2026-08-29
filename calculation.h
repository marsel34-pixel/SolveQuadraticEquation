#ifndef CALCULATION_H
#define CALCULATION_H

#include "setting.h"



/**
 * @brief 
Solves a quadratic equation that requires the use of the discriminant
 *
 * 
 * 
 *
 * @param a coeficient a for equation
 * @param b coeficient b for equation
 * @param c coeficient c for equation
 * @param[out] x1 A pointer to the variable where the equation's root is stored makes no difference in the case where there are no roots.
 * @param[out] x2 The pointer to the variable where the equation's root is stored makes no difference in the case of no roots or a single root.
 *
 * @return number of roots
 */
int solveQuadraticEquationWithDiscriminant(double a, double b, double c, double *x1, double *x2);

/**
 * @brief Solves a quadratic equation over the real numbers.
 *
 * @param a coeficient a for equation
 * @param b coeficient b for equation
 * @param c coeficient c for equation
 * @param[out] x1 A pointer to the variable where the equation's root is stored makes no difference in the case where there are no roots.
 * @param[out] x2 The pointer to the variable where the equation's root is stored makes no difference in the case of no roots or a single root.
 *
 * @return numberof roots
 */
int solveQuadraticEquation(double a, double b, double c, double *x1, double *x2);

/**
 * @brief Checks whether a double-precision number is zero, with a precision of 1e-9.
 *
 * @param num numer for check
 *
 * @return 1 if zero, else 0
 */
bool isZero(double num);

/**
 * @brief Solves linear equation
 *
 * @param k coeficient k for equation
 * @param b coeficient b for equation
 * @param[out] x A pointer to the variable where the equation's root is stored makes no difference in the case where there are no roots.
 *
 * @return number of roots
 */
int solveLinearEquation(double k, double b, double *x);

/**
 * @brief compare two double number
 *
 * @param compare1 fisrt number
 * @param compare2 second number
 *
 * @return 1 if equal, else 0
 */
bool areDoubleEqual(double compare1, double compare2);

#endif
