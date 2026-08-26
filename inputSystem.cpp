#include <stdio.h>
#include <assert.h>
#include <cctype>
#include <math.h>
#include "inputSystem.h"

//---------------------------------------------------------------
enum LeftOrRight
{
    Left = 0,
    Right = 1
};

void readCoefs(double *a, double *b, double *c)
{
    assert(a);
    assert(b);
    assert(c);

    printf("Enter a:");
    readSingleCoeficient(a);

    printf("Enter b:");
    readSingleCoeficient(b);

    printf("Enter c:");
    readSingleCoeficient(c);
}

//---------------------------------------------------------------

int findPowerX(char *EquationStr, int StartN, int endN, bool *termWasFound, int *foundPowerX, double *buffCoef, bool side)
{
    assert(EquationStr);
    assert(termWasFound);
    assert(foundPowerX);
    assert(buffCoef);

    bool xWasFound = 0;

    for (int j = (side == Left) ? StartN - 1 : endN; j > -1 && j < MaxInputLen; (side == Left) ? j-- : j++)
    {
        assert(0 <= j && j < MaxInputLen);

        if (EquationStr[j] == '*' && !*termWasFound)
        {
            *termWasFound = 1;
            continue;
        }
        else if (EquationStr[j] == '+' || EquationStr[j] == '-')
        {
            ((side == Left) && EquationStr[j] == '-') ? *buffCoef *= -1 : 0;
            break;
        }

        if (*termWasFound && !xWasFound)
        {
            if ((side == Left) ? checkLeftForPower(EquationStr, &j, foundPowerX, &xWasFound) : checkRightForPower(EquationStr, &j, foundPowerX, &xWasFound))
            {
                return 1;
            }
            continue;
        }
        if (xWasFound && (EquationStr[j] == 'x' || isdigit(EquationStr[j]) || EquationStr[j] == '^'))
        {
            printf("No sign between term\n");
            return 1;
        }
    }

    if (*termWasFound && foundPowerX == 0)
    {
        printf("Multiply without X\n");
        return 1;
    }

    return 0;
}

//-----------------------------------------------------------------------------

int checkLeftForPower(char *EquationStr, int *strIdx, int *foundPowerX, bool *xWasFound)
{
    assert(EquationStr);
    assert(strIdx);
    assert(foundPowerX);
    assert(xWasFound);

    if (EquationStr[*strIdx] == '+' || EquationStr[*strIdx] == '-' || EquationStr[*strIdx] == '*')
    {
        printf("* without X\n");
        return 1;
    }
    else if (*strIdx > 1 && EquationStr[*strIdx] == '2' && EquationStr[*strIdx - 1] == '^' && EquationStr[*strIdx - 2] == 'x')
    {
        *foundPowerX = 2;
        *xWasFound = 1;
        *strIdx -= 2;
        return 0;
    }
    else if (EquationStr[*strIdx] == 'x')
    {
        *foundPowerX = 1;
        *xWasFound = 1;
        return 0;
    }
    else if (isdigit(EquationStr[*strIdx]))
    {
        printf("You cannot multiply numbers\n");
        return 1;
    }

    return 0;
}

//--------------------------------------------------------------------------

int checkRightForPower(char *EquationStr, int *strIdx, int *foundPowerX, bool *xWasFound)
{
    assert(EquationStr);
    assert(strIdx);
    assert(foundPowerX);
    assert(xWasFound);

    if (EquationStr[*strIdx] == '+' || EquationStr[*strIdx] == '-' || EquationStr[*strIdx] == '*')
    {
        printf("Multiply without X\n");
        return 1;
    }
    else if (EquationStr[*strIdx] == 'x')
    {
        if (EquationStr[*strIdx + 1] == '^' && EquationStr[*strIdx + 2] == '2')
        {
            *foundPowerX = 2;
            *xWasFound = 1;
            *strIdx += 2;
            return 0;
        }
        else if (EquationStr[*strIdx + 1] != '^')
        {
            *foundPowerX = 1;
            *xWasFound = 1;
            return 0;
        }
        else if (isdigit(EquationStr[*strIdx]))
        {
            printf("You cannot use powers other than 2\n");
            return 1;
        }
    }
    else if (isdigit(EquationStr[*strIdx]))
    {
        printf("You cannot multiply numbers\n");
        return 1;
    }
    return 0;
}

//--------------------------------------------------------------------------

int setCoef(char *EquationStr, int startN, int endN, double *buffCoof, double *a, double *b, double *c)
{
    assert(EquationStr);
    assert(buffCoof);
    assert(a);
    assert(b);
    assert(c);

    bool termFromLeft = 0;
    bool termFromRight = 0;
    int foundPowerX = 0;

    if (findPowerX(EquationStr, startN, endN, &termFromLeft, &foundPowerX, buffCoof, Left))
        return 1;

    if (findPowerX(EquationStr, startN, endN, &termFromRight, &foundPowerX, buffCoof, Right))
        return 1;
    
    if (termFromLeft && termFromRight)
    {
        printf("too many multiply\n");
        return 1;
    }
    
    if (!termFromLeft && !termFromRight)
    {
        *c += *buffCoof;
    }
    else
    {
        if (foundPowerX == 1)
        {
            *b += *buffCoof;
        }
        else
        {
            *a += *buffCoof;
        }
    }
    return 0;
}

//--------------------------------------------------------------

int findCoefsFromStr(char *EquationStr, double *a, double *b, double *c)
{
    assert(EquationStr);
    assert(a);
    assert(b);
    assert(c);

    double buffCoof = NAN; 
    char *endPtr = NULL;

    int startN = 0;
    int endN = 0;

    for (int i = 0; i < MaxInputLen; i++)
    {
        assert(0 <= i && i < MaxInputLen);
        
        if (EquationStr[i] == ' ' || EquationStr[i] == '+' || EquationStr[i] == '-' || EquationStr[i] == 'x' || EquationStr[i] == '^' || 
            EquationStr[i] == '*' || EquationStr[i] == '.')
        {
            continue;
        }
        else if (i > 1 && EquationStr[i] == '2' && EquationStr[i - 1] == '^')
        {
            continue;
        }
        else if (isdigit(EquationStr[i]))
        {
            buffCoof = strtod(EquationStr + i, &endPtr);
            startN = i;
            i = (int)(endPtr - EquationStr);
            endN = i;
            if (setCoef(EquationStr, startN, endN, &buffCoof, a, b, c))
            {
                return 1;
            }
        }
        else if (EquationStr[i] == '\n' || EquationStr[i] == '\0')
        {
            break;
        }
        else
        {
            printf("extraneous character in the input\n");
            return 1;
        }
    }
    return 0;
}

//-------------------------------------------------------

int readCoeficients(double *a, double *b, double *c)
{
    assert(a);
    assert(b);
    assert(c);

    *a = 0;
    *b = 0;
    *c = 0;

    char EquationStr[MaxInputLen] = {};

    printf("Enter equation\n");
    fgets(EquationStr, MaxInputLen, stdin);

    return findCoefsFromStr(EquationStr, a, b, c);
}

//---------------------------------------------------------------

void readSingleCoeficient(double *a)
{
    assert(a);

    int ch;
    int result;

    while (1)
    {
        result = scanf("%lf", a);

        ch = getchar();

        if (result == 1 && (ch == '\n' || ch == EOF))
        {
            break;
        }
        else
        {
            clearInput();
            printf("Wrong input\n");
            printf("Try again: ");
        }
    }
}

//---------------------------------------------------------------

bool askAboutChoise(const char *text)
{
    assert(text);
    
    char inputLetter = 0;

    printf("%s\n", text);
    printf("(Y/N)\n");

    while (1)
    {
        scanf(" %c", &inputLetter);

        if (inputLetter == 'N')
            return 0;
        else if (inputLetter == 'Y')
            return 1;

        clearInput();

        printf("Unknown input\n");
        printf("Do you want continue?\n");
        printf("(Y/N)\n");
    }
}

//---------------------------------------------------------------

void clearInput()
{
    int ch = 0;

    while (ch != '\n' && ch != EOF)
    {
        ch = getchar();
    }
}
