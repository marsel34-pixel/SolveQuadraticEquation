#include <stdio.h>
#include <assert.h>
#include <cctype>

#include "inputSystem.h"

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


//---------------------------------------------------------------

int checkLefterN(char *str, int startN, bool *termFromLeft, int *findX, double *buffCoof)
{
    for (int j = startN - 1; j > -1; j--)
    {
        if(str[j] == '*' )
        {
            *termFromLeft = 1;
            continue;
        }
        else if(str[j] == '+')
        {
            break;
        }
        else if(str[j] == '-')
        {
            *buffCoof = -*buffCoof;
        }

        if (*termFromLeft)
        {
            if(str[j] == '+' || str[j] == '-' || str[j] == '*')
            {
                printf("badInput+ %d\n", startN);
                return 1;
            }
            else if (j>1 && str[j] == '2' && str[j-1] == '^' && str[j-2] == 'x')
            {
                *findX = 2;
                break;
            }
            else if( str[j] == 'x')
            {
                *findX = 1;
                break;
            }
            else if (isdigit(str[j]))
            {
                printf("badInputD %d\n", startN);
                        return 1;
            }
                    
        }
    }
    return 0;
}

int checkRitghterN(char *str, int endN, bool *termFromRight, int *findX)
{
    for (int j = endN; j < 256; j++)
    {
       if(str[j] == '*' )
        {
            *termFromRight = 1;
            continue;
        }
        else if(str[j] == '+' || str[j] == '-')
        {
            break;
        }
        if (termFromRight)
        {
            if (str[j] == '+' || str[j] == '-' || str[j] == '*')
            {
               printf("badInput+ %d\n", endN);
               return 1;
            }
            else if (str[j] == 'x')
            {
                if (str[j+1] == '^' && str[j+2] == '2')
                {
                    *findX = 2;
                    break;
                    }
                else if (str[j+1] != '^')
                {
                    *findX = 1;
                    break;
                }
                else{
                    printf("wrongX");
                    return 1;
                }
                }
                    
            else if (isdigit(str[j]))
            {
                printf("badInputD %d %d\n", endN, j);//1*x^2+x*1
                return 1;
            }
                    
       }
    }
    return 0;
}

int setCoof(char *str, int startN, int endN, double *buffCoof, double *a, double *b, double *c)
{
    bool termFromLeft = 0;
    bool termFromRight = 0;
    int findX = 0;

    if (checkLefterN(str,startN,&termFromLeft,&findX,buffCoof)) return 1;
            
    if (checkRitghterN(str,endN,&termFromRight,&findX)) return 1;

    if (termFromLeft && termFromRight)
    {
        printf("okrugily");
        return 1;
    }
    if (!termFromLeft && !termFromRight)
    {
        *c+=*buffCoof;
    }
    else 
    {
        if(findX == 1){
            *b+=*buffCoof;
        }
        else
        {
            *a+=*buffCoof;
        }
    }
    return 0;
}



int findCoofsFromStr(char *str, double *a, double *b, double *c)
{
    double buffCoof = 0;
    char *endPtr = NULL;

    int startN = 0;
    int endN = 0;
    
    for (int i = 0; i < 256; i++)
    {
        if (str[i] == ' ' || str[i] == '+'||str[i] == '-'||str[i] == 'x'||str[i] == '^' || str[i] == '*' || str[i] == '.')
        {
            continue;
        }
        else if(i>1 && str[i] == '2' && str[i-1] == '^')
        {
            //fixme
        }
        else if (isdigit(str[i]))
        {
            buffCoof = strtod(str+i, &endPtr);
            startN = i;
            //printf("%d",i);
            i = (int)(endPtr - str);
            //printf("%d",i);
            endN = i;
            if (setCoof(str, startN, endN, &buffCoof, a, b, c)){return 1;}    
            
            
        }
        else if(str[i] == '\n' || str[i] == '\0')
        {
            break;
        }
        else
        {
            printf("badWord %d\n",str[i]);
            return 1;
        }
    }
    return 0;
}



int readCooficients(double *a, double *b, double *c)
{
    *a = 0; *b = 0; *c = 0;
    
    char str[256] = {};
    
    printf("Enter equation\n");
    fgets(str,256,stdin); //FIXME
        
    return findCoofsFromStr(str, a, b, c);
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

