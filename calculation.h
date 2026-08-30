#ifndef CALCULATION_H
#define CALCULATION_H

#include "setting.h"

/**
 * @brief Solves a quadratic equation using the discriminant.
 *
 * This function computes the real roots of the equation a*x^2 + b*x + c = 0
 * by evaluating the discriminant. The number of real roots is returned.
 *
 * @param a Coefficient of x^2.
 * @param b Coefficient of x.
 * @param c Constant term.
 * @param[out] x1 Pointer to store the first root (if it exists).
 * @param[out] x2 Pointer to store the second root (if it exists).
 *
 * @return The number of real roots (0, 1, or 2).
 */
int solveQuadraticEquationWithDiscriminant(double a, double b, double c, double *x1, double *x2);

/**
 * @brief Solves a quadratic equation over the real numbers.
 *
 * This function finds the real roots of the equation a*x^2 + b*x + c = 0.
 *
 * @param a Coefficient of x^2.
 * @param b Coefficient of x.
 * @param c Constant term.
 * @param[out] x1 Pointer to store the first root (if it exists).
 * @param[out] x2 Pointer to store the second root (if it exists).
 *
 * @return The number of real roots (0, 1, or 2).
 */
int solveQuadraticEquation(double a, double b, double c, double *x1, double *x2);

/**
 * @brief Checks whether a double-precision number is zero within a tolerance.
 *
 * The comparison uses an epsilon of 1e-9.
 *
 * @param num The number to check.
 *
 * @return 1 if the number is considered zero, otherwise 0.
 */
bool isZero(double num);

/**
 * @brief Solves a linear equation of the form k*x + b = 0.
 *
 * @param k Coefficient of x.
 * @param b Constant term.
 * @param[out] x Pointer to store the root (if it exists).
 *
 * @return The number of real roots.
 */
int solveLinearEquation(double k, double b, double *x);

/**
 * @brief Compares two double-precision numbers for equality within a tolerance.
 *
 * The comparison uses an epsilon of 1e-9.
 *
 * @param compare1 The first number.
 * @param compare2 The second number.
 *
 * @return 1 if the numbers are considered equal, otherwise 0.
 */
bool areDoubleEqual(double compare1, double compare2);

#endif