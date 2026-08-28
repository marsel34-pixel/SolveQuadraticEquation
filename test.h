#ifndef TEST_H
#define TEST_H

#include "setting.h"

ssize_t ReadTestsUnitFromFile(testUnit *TestArray);

void RunAllTestsFromArray(testUnit *TestMat, size_t TestSize);

void ErrorMesage(testUnit TestMat, int nRoots, double x1, double x2);

int RunTest(struct testUnit TestMat);

int RunAllAvaiaibleTests();

#endif