#include <stdio.h>
#include <math.h>

#include "calculation.h"
#include "marcel_test.h"


int one_run_test(TestData test)
{
    double x1 = NAN, x2 = NAN;
    int nRoots = solveQuadraticEquation(test.a, test.b, test.c, &x1, &x2);

    if (nRoots == test.nRootsres && ((areDoubleEqual(test.x1_res, x1) || areDoubleEqual(test.x2_res, x2)) || (areDoubleEqual(test.x1_res, x2) || areDoubleEqual(test.x2_res, x1))))
    {
        printf("Test OK: a = %lf, b = %lf, c= %lf\n"
               "Expected: %d roots, x1_res = %lf, x2_res = %lf\n"
               "Has:      %d roots, x1     = %lf, x2     = %lf\n\n\n\n",
                test.a, test.b, test.c, test.nRootsres, test.x1_res, test.x2_res, nRoots, x1, x2);
        return 1;
    }

    else
    {
        printf("Test Failed: a = %lf, b = %lf, c= %lf\n"
               "Expected: %d roots, x1_res = %lf, x2_res = %lf\n"
               "Has:      %d roots, x1     = %lf, x2     = %lf\n\n\n\n",
                test.a, test.b, test.c, test.nRootsres, test.x1_res, test.x2_res, nRoots, x1, x2);
        return 0;
    }
}

void run_all_tests()
{
    TestData test1 {.a =  0, .b =  0, .c =  0, .nRootsres =  -1, NAN, NAN};      //infinity
    TestData test2 {.a =  0, .b =  0, .c =  2, .nRootsres =   0, NAN, NAN};      //no roots
    TestData test3 {.a =  0, .b =  1, .c =  2, .nRootsres =   1,  -2,   0};      //infinity
    TestData test4 {.a =  1, .b =  2, .c =  1, .nRootsres =   1,  -1,  -1};      //one roots
    TestData test5 {.a =  1, .b =  3, .c =  2, .nRootsres =   2,  -1,  -2};     //two roots
    TestData test6 {.a =  4, .b =  1, .c =  3, .nRootsres =   0, NAN, NAN};      //no roots

    int all_tests[]=
    {
        one_run_test(test1),
        one_run_test(test2),
        one_run_test(test3),
        one_run_test(test4),
        one_run_test(test5),
        one_run_test(test6)
    };

    int count_tests = sizeof(all_tests)/sizeof(int);

    int good_test = 0;

    for (int i = 0; i < count_tests; i++)
    {
        if(all_tests[i] == 1)
        {
            good_test++;
        }
    }

    if (good_test == count_tests)
    {
        printf("All tests are successfull\n");
    }
    else 
    {
        printf("%d of %d are successfull\n\n", good_test, count_tests);
    }
}

