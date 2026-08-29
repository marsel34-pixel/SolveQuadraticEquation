//#define TX_USE_SPEAK
//#include "TXLib.h"
#include <stdio.h>
#include <getopt.h>
#include <random>
#include <time.h>
#include <windows.h>

#include "marcel_test.h"
#include "test.h"
#include "programMods.h"

enum selectedMode
{
    basic = 0,
    test = 1,
    AI = 2,
    game = 3,
    gameForTwo = 4,
    another = 5
};

int selectMode(int argc, char *argv[]);


int main(int argc, char *argv[])
{
    system("echo Hello from C program!");
    srand((int)time(0));
    
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

        case gameForTwo:
            gameTwoPlyerMode();
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
    int flag_GameForTwo = 0;

    const char* short_options = "at";
    
    const option long_options[] = { { "AI", no_argument, &flag_AI, 1 },
		                            { "Test", no_argument, &flag_Test, 1 },
                                    { "Game", no_argument, &flag_Game, 1 },
                                    { "GameForTwo", no_argument, &flag_GameForTwo, 1 },
		                            { NULL, no_argument, NULL, 0} };

    while (getopt_long(argc, argv, short_options,
		long_options, NULL)!=-1);

    if (!flag_AI && !flag_Test && !flag_Game && !flag_GameForTwo)
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
    else if (flag_GameForTwo)
    {
        return gameForTwo;
    }
    return another;
}
//---------------------------------------------------------------



// желательно (в последнюю очередь (меньший приоритет)) подумать над читаемостью ifов



// перекрестное тестирование + doxygen