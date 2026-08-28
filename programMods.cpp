//#define TX_USE_SPEAK
//#include "TXLib.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
#include <windows.h>


#include "programMods.h"
#include "inputSystem.h"
#include "calculation.h"
#include "outputSystem.h"


const int cartMinNumber = 1000000;
const int waitingForLetterTime = 30;

void checkTokens(int *tokens)
{
    assert(tokens);

    Sleep(randomNumberInRange(0,3000));

    *tokens -= randomNumberInRange(10, 150);

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

        *tokens += randomNumberInRange(20, 300);
    }
}

void AIUltraProgramm()
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

    while (readCoeficientsFromEquation(&a, &b, &c))
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

    for (int i = 0;; i++)
    {
        putchar(Text[i]);
        //txSpeak("%s%s", "\a", Text[i]);
        Sleep(waitingForLetterTime);

        if (Text[i] == '\n' || Text[i] == '\0')
        {
            putchar('\n');
            break;
        }
    }
}
void basicProgramm()
{
    bool keepSolving = 1;
    double a = NAN, b = NAN, c = NAN;
    double x1 = NAN, x2 = NAN;

    while (keepSolving)
    {
        if (readCoeficientsFromEquation(&a, &b, &c) == 1)
        {
            continue;
        }
        printf("Your Equation: %lg*x^2 + %lg*x + %lg\n", a, b, c);
        int nRoots = solveQuadraticEquation(a, b, c, &x1, &x2);

        printRoots(nRoots, x1, x2);

        if (askAboutChoise("Do you want see graphic"))
        {
            drawAnimationGraph(-a / 2, -b / 2, -c / 2);
            plotQuadratics(a / 2, b / 2, c / 2, x1, x2);
        }

        keepSolving = askAboutChoise("Do you want continue?");

        clearInput();
    }
}

int randomNumberInRange(int min, int max)
{
    return min +  rand() % (max - min);
}
void gameMode()
{
    double a = NAN, b = NAN, c = NAN;
    bool isPlay = 1;
    
    const int numEnemy = 10; 

    enemy enemyArray[numEnemy];

    enemyInit(enemyArray, numEnemy);
    
    gameStep(0.5, 0, 0, enemyArray, numEnemy);

    while (isPlay)
    {
        
        if (readCoeficientsFromEquation(&a, &b, &c) == 1 )
        {
            continue;
        }
        if (isZero(a))
        {
            printf("Its to easy, try make parabola");
            continue;
        }

        gameStep(-a / 2, -b / 2, -c / 2, enemyArray, numEnemy);

        isPlay = 0;
        for (int i = 0; i < numEnemy; i++)
        {
            if (enemyArray[i].isAlive)
            {
                isPlay = 1;
            }
        }
    }
}

void enemyInit(enemy enemyArray[], const int numEnemy)
{   
    for (int i = 0; i < numEnemy; i++)
    {
        enemyArray[i].x = randomNumberInRange(5, X_SIZE-5);
        enemyArray[i].y = randomNumberInRange(5, Y_SIZE-5);
        enemyArray[i].isAlive = 1;

        for (int j = 1; j < maxEnemySize; j++)
        {
            int neighborToNewPoint = randomNumberInRange(0, j);

            enemyArray[i].enemyPointsArray[j][0] = enemyArray[i].enemyPointsArray[neighborToNewPoint][0];
            enemyArray[i].enemyPointsArray[j][1] = enemyArray[i].enemyPointsArray[neighborToNewPoint][1];

            switch (randomNumberInRange(0,4))
            {
            case 0:
                enemyArray[i].enemyPointsArray[j][0] += 1;
                break;
            case 1:
                enemyArray[i].enemyPointsArray[j][0] -= 1;
                break;
            case 2:
                enemyArray[i].enemyPointsArray[j][1] += 1;
                break;
            case 3:
                enemyArray[i].enemyPointsArray[j][1] -= 1;
                break;
            default:
                break;
            }
        }
    }
}