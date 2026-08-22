#include "calculation.h"
#include "test.h"
#include <math.h>
#include <stdio.h>

void RunTest(double a, double b, double c, int nRootsRef, double x1Ref, double x2Ref)
{
    double x1 = NAN, x2 = NAN;
    int nRoots = NAN;

    nRoots = solveQuadraticEquation(a, b, c, &x1, &x2);

    if(nRoots == nRootsRef){
        switch (nRoots)
        {
            case 0:
                if (!(isnan(x1) && isnan(x2)))
                {
                    ErrorMesage(a, b, c, nRootsRef, x1Ref, x2Ref, nRoots, x1, x2);
                }
                break;
            case 1:
                //printf("%d",!(isZero(x1-x1Ref) && isnan(x2)));
                if(!(isZero(x1-x1Ref) && isnan(x2)))
                {
                    ErrorMesage(a, b, c, nRootsRef, x1Ref, x2Ref, nRoots, x1, x2);
                }
                
                break;
            case 2:
                if(!((isZero(x1-x1Ref) && isZero(x2-x2Ref)) || (isZero(x2-x1Ref) && isZero(x1-x2Ref))))
                {
                    ErrorMesage(a, b, c, nRootsRef, x1Ref, x2Ref, nRoots, x1, x2);
                }
                break;
            case INFINIT:
                if (!(isnan(x1) && isnan(x2)))
                {   
                    ErrorMesage(a, b, c, nRootsRef, x1Ref, x2Ref, nRoots, x1, x2);
                }
                
                break;
            default:
                break;
        }
    }
    else
    {
        ErrorMesage(a, b, c, nRootsRef, x1Ref, x2Ref, nRoots, x1, x2);
    }

}
void ErrorMesage(double a, double b, double c, int nRootsRef, double x1Ref, double x2Ref, int nRoots, double x1, double x2)
{
    printf("Test FAILED: a=%lg, b=%lg, c=%lg\n"
            "Expected x1=%lg, x2=%lg, nRoots=%d\n"
            "got:     x1=%lg, x2=%lg, nRoots=%d\n", 
            a, b, c, x1Ref, x2Ref, nRootsRef, x1, x2, nRoots);
    
}