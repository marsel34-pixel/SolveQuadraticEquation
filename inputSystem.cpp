#include "inputSystem.h"

#include <stdio.h>
#include <assert.h>
#include <cctype>



struct number
{
    double value;
    int startN;
    int endN;
};

struct x
{
    int power;
    int startN;
    int endN;
};

//---------------------------------------------------------------
void readCoofs(double *a, double *b, double *c)
{

    printf("Enter a:");
    readSingleCooficient(a);

    printf("Enter b:");
    readSingleCooficient(b);

    printf("Enter c:");
    readSingleCooficient(c);
}
void findNumbersAndX(char *str, struct x *powers,struct number *coofs, int *numDigit, int *numX)
{
    char *endptr = NULL;
    for (int i = 0; i < 256; i++)
    {
        if (isdigit(str[i]))
        {
            coofs[*numDigit].value = strtod(str+i, &endptr);
            coofs[*numDigit].startN = i;

            i = (int)(endptr - str);
            coofs[*numDigit].endN = i;
            (*numDigit)++;
        }
        else if(str[i] == 'x')
        {
           if(str[i+1] == '^' && str[i+2] == '2')
           {
                powers[*numX].power = 2;
                powers[*numX].startN = i;
                i+=3;
                powers[*numX].endN = i;

                (*numX)++;
           }
           else
           {
                powers[*numX].power = 1;
                powers[*numX].startN = i;
                i+=1;
                powers[*numX].endN = i;

                (*numX)++;
           }
        }
    }
    //for(int i = 0; i<*numDigit;i++)
    //{
    //    printf("%lf",coofs[i].value);
    //}
}

//---------------------------------------------------------------

void findLeftPower(int *leftMostPower, int indexNum, struct number *coofs, struct x *powers,int *numX)
{
    for(;*leftMostPower < *numX; (*leftMostPower)++)
    {
        if (powers[*leftMostPower].endN > coofs[indexNum].startN)
        {
            leftMostPower--;
            break;
        }
    }
}



void findRightPower(int *rightMostPower, int indexNum, struct number *coofs, struct x *powers, int *numX)
{
    for(; *rightMostPower < *numX; (*rightMostPower)++)
    {
        if (powers[*rightMostPower].startN > coofs[indexNum].endN)
        {
            break;
        }
    }
}



void findPowerCoofs(char *str, struct number *coofs, struct x *powers, int *numDigit, int *numX,
                                                        double *a, double *b, double *c)
{

    for(int i = 0; i< *numDigit; i++)
    {
        int leftMostPower = 0;
        int rightMostPower = 0;

        findLeftPower(&leftMostPower, i, coofs,  powers, numX);           //a, b, c
        findRightPower(&rightMostPower, i, coofs,  powers, numX);


        for(int j = coofs[i].startN-1; j > -1; j--)
        {
            if(str[j] == '-')
            {
                coofs[i].value *= -1;
            }

            if((leftMostPower > -1 && powers[leftMostPower].endN == j) || isdigit(str[j]))
            {
                break;
            }

        }

        for(int j = coofs[i].endN; j < 256; j++)//67*x^2+12+91*x+34+5*x^2
        {   if(rightMostPower < *numX){

            if(str[j] == '*')
            {
                switch(powers[rightMostPower].power)
                {
                    case 1:
                        *b += coofs[i].value;
                        break;
                    case 2:
                        *a += coofs[i].value;
                        break;
                    default:
                        break;
                }

                break;
            }
            if (powers[rightMostPower].endN == j || j == 255|| str[j] == '+' || str[j] == '-')
            {
                *c += coofs[i].value;
                break;
            }
            }
            else
            {
               *c += coofs[i].value;
               break;
            }
        }
    }
}

//---------------------------------------------------------------

void readCooficients(double *a, double *b, double *c)
{
    *a = 0; *b = 0; *c = 0;

    char str[256] = {};

    printf("Enter equation\n");
    fgets(str,256,stdin);

    struct number coofs[20] = {};
    int numDigit = 0;
    struct x powers[20];
    int numX = 0;

    findNumbersAndX(str,powers,coofs,&numDigit,&numX);

    findPowerCoofs(str,coofs,powers,&numDigit,&numX, a, b, c);

    printf("%lg %lg %lg\n",*a,*b,*c);
}

//---------------------------------------------------------------

void readSingleCooficient(double *a)
{
    assert(a);

    int ch;
    int result;

    while (1) {
        result = scanf("%lf", a);

        ch = getchar();

        if (result == 1 && (ch == '\n' || ch == EOF)) {
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

bool needContinue()
{
    char inputLetter;

    printf("Do you want continue?\n");
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

