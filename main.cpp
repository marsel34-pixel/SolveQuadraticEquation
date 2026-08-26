#include "TXLib.h"
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <cctype>
#include <math.h>
#include <windows.h>
#include <getopt.h>


#include "calculation.h"
#include "inputSystem.h"
#include "test.h"
#include "outputSystem.h"
#include "AI.h"


int main(int argc, char *argv[])
{
    txPlaySound("sigma");
    
    int flag_AI = 0;
	int flag_Test = 0;
    const char* short_options = "at";

    const struct option long_options[] = {
		{ "AI", no_argument, &flag_AI, 1 },
		{ "Test", no_argument, &flag_Test, 1 },
		{ NULL, 0, NULL, 0}
	};

    while (getopt_long(argc, argv, short_options,
		long_options, NULL)!=-1);
    
    if (!flag_AI && !flag_Test)
    {
        basicInput();
    }
    else if (flag_Test)
    {
        RunAllAvaiaibleTests();
    }
    else if (flag_AI)
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

// в режиме ии -  текст печатается с задержкой в реальном времени и *озвучка (TXLib??)
// main улучшить
// перекрестное тестирование + doxygen