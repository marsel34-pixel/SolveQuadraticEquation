#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <cctype>
#include <math.h>
#include <windows.h>

#include "calculation.h"
#include "inputSystem.h"
#include "test.h"
#include "outputSystem.h"
#include "AI.h"


int main(int argc, char *argv[])
{

    if (argc == 1)
    {
        basicInput();
    }
    else if (!strcmp(argv[1], "startTest") && argc == 2)
    {
        RunAllAvaiaibleTests();
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



// желательно (в последнюю очередь (меньший приоритет)) подумать над читаемостью ifов

// обработка аргументов командной строки с помощью getopt_long()
// в режиме ии -  текст печатается с задержкой в реальном времени и *озвучка (TXLib??)
//  сделать чтение юнит - тестов из .txt файла 1 -5 6 2 2 3