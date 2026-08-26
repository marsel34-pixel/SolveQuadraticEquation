#ifndef TEST_H
#define TEST_H

const char redColor[] = "\033[31m";
const char BaseColor[] = "\033[m";

const int MaxTestLen = 1000;

struct testUnit
{
    double a, b, c;
    int nRoots;
    double x1, x2;
};

ssize_t ReadTestsUnitFromFile(testUnit *TestArray);

void RunAllTestsFromArray(testUnit *TestMat, size_t TestSize);

void ErrorMesage(testUnit TestMat, int nRoots, double x1, double x2);

int RunTest(struct testUnit TestMat);

int RunAllAvaiaibleTests();

#endif