#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <cctype>
#include <math.h>

#include "calculation.h"
#include "inputSystem.h"
#include "test.h"
#include "outputSystem.h"


//---------------------------------------------------------------

int main(int argc, char *argv[])
{   
    //bool isTestNow = 1;
    if(argc == 1)
    {
        bool keepSolving = 1;
        double a = 0, b = 0, c = 0;       //FIXME
        double x1 = NAN, x2 = NAN;
        
       
        //printf("epta");
        while (keepSolving)
        {
            if (readCooficients(&a,&b,&c) == 1) {continue;}
            //readCooficients(&a,&b,&c);     //FIXME
            //readCoofs(&a, &b, &c);
            int nRoots = solveQuadraticEquation(a, b, c, &x1, &x2);

            printRoots(nRoots, x1, x2);

            keepSolving = needContinue();

            clearInput();
        }
    }
    else
    {
        // double TestMat[][6] = {{1,2,1,1,-1,NAN},
        //                         {1,-2,1,1,1,NAN},
        //                         {1,5,6, 2, -2,-3},
        //                         {1,2,-89, 1, -1, 67},
        //                         {0,0,0,INFINIT,0,0},
        //                         {0,0,3,INFINIT,12,3}};
        struct testUnit TestMat[] = { { 1,2,1,1,-1,NAN    },
                                { 1,-2,1,1,1,NAN    },
                                { 1,5,6, 2, -2,-3   },
                                { 1,0,-81, 2, -9, 9 },
                                { 1,0,81, 0, NAN, NAN   },
                                { 0,10,90, 1, -9, NAN },
                                { 1,10,0, 2, -10, 0 },
                                { 0,0,0,INFINIT,NAN,NAN },
                                { 0,0,3,0,NAN,NAN   } };

        int TestSize = (int)(sizeof(TestMat)/sizeof(TestMat[0]));

        for(int i = 0; i < TestSize; i++)
        {
            RunTest(TestMat[i]);
        }

    }
    return 0;
}

//---------------------------------------------------------------
