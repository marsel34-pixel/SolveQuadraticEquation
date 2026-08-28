//#define TX_USE_SPEAK
//#include "TXLib.h"
#include <stdio.h>
#include <getopt.h>
#include <random>
#include <time.h>

#include "marcel_test.h"
#include "test.h"
#include "programMods.h"

enum selectedMode
{
    basic = 0,
    test = 1,
    AI = 2,
    game = 3,
    another = 4
};

int selectMode(int argc, char *argv[]);


int main(int argc, char *argv[])
{
    srand(time(0));
    switch (selectMode(argc, argv))
    {
        case basic:
            basicProgramm();
            break;   

        case test:
            RunAllAvaiaibleTests();
            break;

        case AI:
            AIUltraProgramm();
            break;
        case game:
            gameMode();
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
    int flag_Game = 0;

    const char* short_options = "at";
    
    const option long_options[] = { { "AI", no_argument, &flag_AI, 1 },
		                            { "Test", no_argument, &flag_Test, 1 },
                                    { "Game", no_argument, &flag_Game, 1 },
		                            { NULL, no_argument, NULL, 0} };

    while (getopt_long(argc, argv, short_options,
		long_options, NULL)!=-1);

    if (!flag_AI && !flag_Test && !flag_Game)
    {
        return basic;
    }
    else if (flag_AI)
    {
        return AI;
    }
    else if (flag_Test)
    {
        return test;
    }
    else if (flag_Game)
    {
        return game;
    }
    return another;
}
//---------------------------------------------------------------



// желательно (в последнюю очередь (меньший приоритет)) подумать над читаемостью ifов



// перекрестное тестирование + doxygen