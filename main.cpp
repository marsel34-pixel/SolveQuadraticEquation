//#define TX_USE_SPEAK
//#include "TXLib.h"
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <cctype>
#include <math.h>
#include <windows.h>
#include <getopt.h>

#include "marcel_test.h"
#include "calculation.h"
#include "inputSystem.h"
#include "test.h"
#include "outputSystem.h"
#include "AI.h"

int selectMode(int argc, char *argv[]);


int main(int argc, char *argv[])
{
    switch (selectMode(argc, argv))
    {
        case 0:
            basicProgramm();
            break;    
        case 1:
            RunAllAvaiaibleTests();
            break;
        case 2:
            AIUltraProgramm();
            break;
        default:
            printf("unknown command");
            break;
    }
    return 0;
}


int selectMode(int argc, char *argv[])
{
    int flag_AI = 0;
	int flag_Test = 0;

    const char* short_options = "at";
    
    const option long_options[] = {
		{ "AI", no_argument, &flag_AI, 1 },
		{ "Test", no_argument, &flag_Test, 1 },
		{ NULL, no_argument, NULL, 0}
	};
    while (getopt_long(argc, argv, short_options,
		long_options, NULL)!=-1);

    if (!flag_AI && !flag_Test)
    {
        return 0;
    }
    else if (flag_AI)
    {
        return 1;
    }
    else if (flag_Test)
    {
        return 2;
    }
    return 3;
}
//---------------------------------------------------------------



// желательно (в последнюю очередь (меньший приоритет)) подумать над читаемостью ifов



// перекрестное тестирование + doxygen