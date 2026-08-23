#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
#include <windows.h>

#include "AI.h"
#include "inputSystem.h"
#include "calculation.h"
#include "outputSystem.h"

void checkTokens(int *tokens)
{
    Sleep(1000);
    *tokens -= 10 + rand() % 120;
    if (*tokens < 0)
    {
        printf("You do not have enough tokens for this request, please enter your card details\n");
        int number;
        while (scanf("%d", &number) != 1)
        {
            clearInput();
        }
        if (number < 1000000)
        {
            printf("you stupid\n");
            assert(0);
        }
        *tokens += 20 + rand() % 240;
    }
}

void aiInput()
{
    int tokens = 20;

    checkTokens(&tokens);

    printf("Ask something\n");
    scanf(" ");
    clearInput();

    checkTokens(&tokens);
    printf("Solving a quadratic equation means finding its roots. To do that, I need to know the equation, so please write it down\n");

    double a = NAN, b = NAN, c = NAN;
    double x1 = NAN, x2 = NAN;
    // int nRoots = 0;
    while (readCooficients(&a, &b, &c))
    {
        checkTokens(&tokens);
        printf("That is why I cannot understand you. Please try again and be more carefu\n");
    }
    int nRoots = solveQuadraticEquation(a, b, c, &x1, &x2);

    printRoots(nRoots, x1, x2);
    checkTokens(&tokens);
    printf("Do you have any more questions?\n");

    while (1)
    {
        scanf(" ");
        clearInput();
        checkTokens(&tokens);
        printf("i cant understand you\n");
    }
}

void WithoutAI()
{
    bool keepSolving = 1;
    double a = NAN, b = NAN, c = NAN; // FIXME
    double x1 = NAN, x2 = NAN;

    while (keepSolving)
    {
        if (readCooficients(&a, &b, &c) == 1)
        {
            continue;
        }
        printf("Your Equation: %lg*x^2 + %lg*x + %lg\n", a, b, c);
        // readCooficients(&a,&b,&c);     //FIXME
        // readCoofs(&a, &b, &c);
        int nRoots = solveQuadraticEquation(a, b, c, &x1, &x2);

        printRoots(nRoots, x1, x2);
        if (askForSomething("Do you want see graphic"))
        {
            drawPenis(a, b, c);
        }

        keepSolving = askForSomething("Do you want continue?");

        clearInput();
    }
}