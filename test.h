#ifndef TEST_H
#define TEST_H

#include "setting.h"

/**
* @brief read test from file and records in array 
*
* @param[out] testArray array to record tests in
* @return if read go normal size of testArray, else -1
*/
ssize_t ReadTestsUnitFromFile(testUnit *TestArray);

/**
* @brief read test from file and records in array 
*
* @param[out] testArray array to record tests in
*/
void RunAllTestsFromArray(testUnit *TestMat, size_t TestSize);

/**
* @brief print error message
*
* @param tesMat the test unit where the error occurred
* @param nRoots, x1, x2 wrong test results
*/
void ErrorMesage(testUnit TestMat, int nRoots, double x1, double x2);

/**
* @brief run one test
*
* @param tesMat what testing
* @return 1 if test go wrong, else 0
*/
int RunTest(struct testUnit TestMat);

/**
* @brief run all tests, from file and program
* @return 1 if read from file go wrong, else 0
*/
int RunAllAvaiaibleTests();

#endif