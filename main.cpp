#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <cctype>
#include <math.h>

#include "calculation.h"
#include "inputSystem.h"
#include "test.h"
#include "outputSystem.h"
#include "AI.h"

//---------------------------------------------------------------

int main(int argc, char *argv[])
{
    // bool isTestNow = 1;
    if (argc == 1)
    {       
        WithoutAI();
    }
    else if (!strcmp(argv[1], "startTest") && argc == 2)
    {
        RunAllTests();
    }
    else if (!strcmp(argv[1], "AI") && argc == 2)
    {
        aiInput();
    }
    else
    {
        printf("unknown command");
    }

    return 0;
}

//---------------------------------------------------------------


//еще раз пройтись по коду и проверить кодстайл, названия имен и принтфы
// попробовать убрать копипаст в input
// output (либо массив char[][]??) либо твои предложения
// сделать чтение юнит - тестов из .txt файла 1 -5 6 2 2 3

