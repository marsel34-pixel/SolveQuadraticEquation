#ifndef TEST_H
#define TEST_H

#include "setting.h"

/**
* @brief reads tests from file and stores them into the array
*
* @param[out] TestArray array to record tests in
* @return returns the number of successfully read tests, or -1 on error
*/
ssize_t ReadTestsUnitFromFile(testUnit *TestArray);

/**
* @brief runs all tests from the given array
*
* @param[in] TestMat array of test units to run
* @param TestSize number of tests in the array
*/
void RunAllTestsFromArray(testUnit *TestMat, size_t TestSize);

/**
* @brief print error message
*
* @param TestMat test unit where the error occurred
* @param[in] nRoots  actual number of roots
* @param[in] x1      first root (if exists)
* @param[in] x2      second root (if exists)
*/
void ErrorMessage(testUnit TestMat, int nRoots, double x1, double x2);

/**
* @brief runs a single test unit
*
* @param testMat testMat test unit to be executed
* @return returns 1 if the test fails, otherwise 0
*/
int RunTest(struct testUnit TestMat);

/**
* @brief run all tests, from file and program
* @return 1 if read from file go wrong, else 0
*/
int RunAllAvailableTests();

#endif