#ifndef TEST_H
#define TEST_H

struct testUnit
{
    double a, b, c;
    int nRoots;
    double x1, x2;
};

bool doubleComparsion(double compare1, double compare2);

void ErrorMesage(double a, double b, double c, int nRootsRef, double x1Ref, double x2Ref, int nRoots, double x1, double x2);

void RunTest(struct testUnit TestMat);

#endif