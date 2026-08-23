#ifndef TEST_H
#define TEST_H

struct testUnit
{
    double a, b, c;
    int nRoots;
    double x1, x2;
};

void RunAllTests();

void ErrorMesage(testUnit TestMat, int nRoots, double x1, double x2);

int RunTest(struct testUnit TestMat);

#endif