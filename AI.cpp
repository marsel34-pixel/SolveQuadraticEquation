#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
#include <windows.h>

#include "AI.h"
#include "inputSystem.h"
#include "calculation.h"
#include "outputSystem.h"

const int cartMinNumber = 1000000;
const int waitingForLetterTime = 30;

void checkTokens(int *tokens)
{
    assert(tokens);

    Sleep(rand() % 3000);

    *tokens -= 10 + rand() % 120;

    if (*tokens < 0)
    {
        AIWriteText("You do not have enough tokens for this request, please enter your card details\n");

        int number = 0;

        while (scanf("%d", &number) != 1)
        {
            clearInput();
        }

        if (number < cartMinNumber)
        {
            printf("you stupid\n");
            assert(0);
        }

        *tokens += 20 + rand() % 240;
    }
}

void aiInput() 
{
    int tokens = 200;

    checkTokens(&tokens);

    AIWriteText("Ask something\n");
    scanf(" ");
    clearInput();

    checkTokens(&tokens);
    AIWriteText("Solving a quadratic equation means finding its roots. To do that, I need to know the equation, so please write it down\n");
    //
    double a = NAN, b = NAN, c = NAN;
    double x1 = NAN, x2 = NAN;

    clearInput();

    while (readCoeficients(&a, &b, &c))
    {
        checkTokens(&tokens);
        AIWriteText("That is why I cannot understand you. Please try again and be more careful\n");
    }
    int nRoots = solveQuadraticEquation(a, b, c, &x1, &x2);

    printRoots(nRoots, x1, x2);
    checkTokens(&tokens);
    AIWriteText("Do you have any more questions?\n");

    infinityDontUnderstand(&tokens);
}

void infinityDontUnderstand(int *tokens)
{
    assert(tokens);

    while (1)
    {
        scanf(" ");
        clearInput();
        checkTokens(tokens);
        AIWriteText("i cant understand you\n");
    } 
}

void AIWriteText(const char *Text)
{
    assert(Text);
    
    for (int i = 0; ; i++)
    {
        putchar(Text[i]);

        Sleep(waitingForLetterTime);

        if (Text[i] == '\n' || Text[i] == '\0')
        {
            putchar('\n');
            break;
        }
    }
}
void basicInput()
{
    bool keepSolving = 1;
    double a = NAN, b = NAN, c = NAN;
    double x1 = NAN, x2 = NAN;

    while (keepSolving)
    {
        if (readCoeficients(&a, &b, &c) == 1)
        {
            continue;
        }
        printf("Your Equation: %lg*x^2 + %lg*x + %lg\n", a, b, c);
        int nRoots = solveQuadraticEquation(a, b, c, &x1, &x2);

        printRoots(nRoots, x1, x2);

        if (askAboutChoise("Do you want see graphic"))
        {
            plotQuadratics(a / 2, b / 2, c / 2, x1, x2);
        }

        keepSolving = askAboutChoise("Do you want continue?");

        clearInput();
    }
}