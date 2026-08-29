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

    enemy enemyArray[numEnemy] = {};

    enemyInit(enemyArray);
    
    gameStep(0.5, 0, Y_SIZE - ZeroY, enemyArray);

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

        gameStep(-a / 2, -b / 2, -c / 2, enemyArray);

        isPlay = calcHowManyRemain(enemyArray);
    }
}

void enemyInit(enemy enemyArray[])
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

            switch (randomNumberInRange(0, 4))
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

void gameTwoPlyerMode() 
{
    double a = NAN, b = NAN, c = NAN;
    bool isPlay = 1;
    char firstPlayerAttackSymbol = 0, secondPlayerAttackSymbol = 0, firstPlayerGuysSymbol = 0, secondPlayerGuysSymbol = 0;

    enemy firstPlayerGuys[numEnemy] = {};
    enemy secondPlayerGuys[numEnemy] = {};

    bool isFirst = 1;

    enemyInit(firstPlayerGuys);
    enemyInit(secondPlayerGuys);

    bool isPlayWithAi = askAboutChoise("Do you want play with AI");
    clearInput();

    firstPlayerAttackSymbol = askForSymbolToGame("What symbol will be first player attack: ");
    firstPlayerGuysSymbol = askForSymbolToGame("What symbol will be first player guys: ");
    if (!isPlayWithAi)
    {
        secondPlayerAttackSymbol = askForSymbolToGame("What symbol will be second player attack: ");
        secondPlayerGuysSymbol = askForSymbolToGame("What symbol will be second player guys: ");
    }
    else
    {
        secondPlayerAttackSymbol = '#';
        secondPlayerGuysSymbol = '@';
    }

    gameStepTwoPlayer(0.5, 0, Y_SIZE - ZeroY-1, firstPlayerGuys, secondPlayerGuys, 
                    firstPlayerAttackSymbol, secondPlayerAttackSymbol, firstPlayerGuysSymbol, secondPlayerGuysSymbol, isFirst);

    while (isPlay)
    {
        putchar('\n');
        if (isFirst)
        {
            printf("First player move\n");
        }
        else
        {
            printf("Second player move\n");
        }

        
        if (!isPlayWithAi || isFirst){
            if (readCoeficientsFromEquation(&a, &b, &c) == 1)
            {
                continue;
            }
            if (isZero(a))
            {
                printf("Its to easy, try make parabola");
                continue;
            }
        }
        else
        {
            AIEnemy(firstPlayerGuys, &a, &b, &c);
            printf("a = %lg, b = %lg, c = %lg", a, b, c);
            Sleep(2000);
        }

        gameStepTwoPlayer(-a / 2, -b / 2, -c / 2, firstPlayerGuys, secondPlayerGuys, 
                        firstPlayerAttackSymbol, secondPlayerAttackSymbol, firstPlayerGuysSymbol, secondPlayerGuysSymbol, isFirst);
        isFirst = !isFirst;
        putchar('\n');
        isPlay = checkEndGameForTwoPlayer(firstPlayerGuys, secondPlayerGuys);
    }
}

// void gameTwoAI() 
// {
//     double a = NAN, b = NAN, c = NAN;
//     int winFirst = 0, winSecond = 0;
//     bool isPlay = 1;
//     int bestA = 0;
//     int bestB = 0;
//     int a1, b1, a2,b2;
//     while (1){
        
//     a1 = bestA;
//     b1 = bestB;

//     a2 = randomNumberInRange(0,3000);
//     b2 = randomNumberInRange(0,3000);
//     //double a1, b1, a2,b2,
//     for (int i = 0; i<1000; i++){
        
//         enemy firstPlayerGuys[numEnemy] = {};
//         enemy secondPlayerGuys[numEnemy] = {};
//         bool isFirst = randomNumberInRange(0,2);

//         enemyInit(firstPlayerGuys);
//         enemyInit(secondPlayerGuys);
        

//         while (1)
//         {
//             printf("kruto");
//             if (isFirst)
//             {
//                 AIEnemySet(secondPlayerGuys, &a, &b, &c, 0, a1, 0, b1);
//             }
//             else
//             {
//                 AIEnemySet(firstPlayerGuys, &a, &b, &c, 0, a2, 0, b2);
//             }

//             gameStepTwoPlayer(-a / 2, -b / 2, -c / 2, firstPlayerGuys, secondPlayerGuys, 
//                             '0', '1', '2', '3', isFirst);
//             isFirst = !isFirst;
//             putchar('\n');
//             if (calcHowManyRemain(firstPlayerGuys) == 0)
//             {
//                 winSecond++;
//                 break;
//             }
//             if (calcHowManyRemain(secondPlayerGuys) == 0)
//             {
//                 winFirst++;
//                 break;
//             }
//         }
//         printf("f = %d, s = %d", winFirst, winSecond);

//     }
//     if(winFirst>winSecond)
//     {
//         bestA = a1;
//         bestB = b2;
//     }
//     else
//     {
//         bestA = a2;
//         bestB = b2;
//     }
//     printf("a = %d, b = %d", a1, b1);
//     }
// }

int calcHowManyRemain(enemy enemyArray[])
{
    int howManyReamin = 0;
    for (int i = 0; i < numEnemy; i++)
    {
        if (enemyArray[i].isAlive)
        {
            howManyReamin++;
        }
    }
    return howManyReamin;
}

char askForSymbolToGame(const char text[])
{
    printf("%s",text);
    int ch = getchar();
    while (ch == ' ' || ch == 0 || ch == '|' || ch == '_')
    {
        printf("You cant use this symbol");
        clearInput();
        ch = getchar();
    }
    clearInput();
    putchar('\n');
    return (char)ch;
}

bool checkEndGameForTwoPlayer(enemy firstPlayerGuys[], enemy secondPlayerGuys[])
{
    int howManyRemainFirstGuys = calcHowManyRemain(firstPlayerGuys);
        if (howManyRemainFirstGuys < 3)
        {
            printf("first lose");
            return 0;
        }
        int howManyRemainSecondGuys = calcHowManyRemain(secondPlayerGuys);
        if (howManyRemainSecondGuys < 3)
        {
            printf("second lose");
            return 0;
        }
        
        printf("First player guys: %d\n", howManyRemainFirstGuys);
        printf("Second player guys: %d\n", howManyRemainSecondGuys);
        return 1;
}

void AIEnemy(enemy EnemyArray[], double *a, double *b, double *c)
{
    *a = randomNumberInRange(0,100) / 1000.0;
    *b = randomNumberInRange(0,300) / 100.0;
    for (int i = 0; i < numEnemy; i++)
    {
        if (EnemyArray[i].isAlive)
        {
            printf("%d\n", (EnemyArray[i].x-ZeroX));
            printf("%d\n", (EnemyArray[i].y-ZeroY));
            *c = (-2 * (EnemyArray[i].y-ZeroY) - (EnemyArray[i].x-ZeroX) * (EnemyArray[i].x-ZeroX) * (*a) - (EnemyArray[i].x-ZeroX) * (*b));
            break;
        }
    }
}

void AIEnemySet(enemy EnemyArray[], double *a, double *b, double *c, int MinA, int MaxA, int MinB, int MaxB)
{
    *a = randomNumberInRange(MinA,MaxA) / 1000.0;
    *b = randomNumberInRange(MinB,MaxB) / 100.0;
    for (int i = 0; i < numEnemy; i++)
    {
        if (EnemyArray[i].isAlive)
        {
            *c = (-2 * (EnemyArray[i].y-ZeroY) - (EnemyArray[i].x-ZeroX) * (EnemyArray[i].x-ZeroX) * (*a) - (EnemyArray[i].x-ZeroX) * (*b));
            break;
        }
    }
}

