#ifndef SETTINGS_H
#define SETTINGS_H

const int X_SIZE = 100;
const int Y_SIZE = 53;
const int ZeroX = 50;
const int ZeroY = 26;

#define greenColor "\033[32m"
#define blueColor "\033[34m"

#define BaseColor "\033[m"
#define returnToStart "\033[H"
const int NumLen = 100;
const double step = 0.01;

const char symbolForParabola = '#';

const char symbolForSecondParabola = '@';

const int MaxTestLen = 100;
const int MaxInputLen = 256;

const int maxEnemySize = 30;

const int numEnemy = 8; 

/**
 * @brief used for saving test
 */
struct testUnit
{
    double a, b, c;
    int nRoots;
    double x1, x2;
};

/**
 * @brief used for saving enemy
 */
struct enemy 
{
    int x = 0;
    int y = 0;
    bool isAlive = 1;
    int enemyPointsArray[maxEnemySize][2] = {};
};

/**
 * @brief Values ​​indicating the number of roots of a quadratic equation
 */
enum NumRoots
{
    NoRoots = 0, 
    OneRoot = 1, 
    TwoRoots = 2,
    InfRoots = -1
};

// char vadim[][5] = {"ebal"};
// char sigma[][1][25] = {{"                       \n",
//                         "                       \                               n",
//                         "                       \n",
//                         "                       \n",
//                         "~~~~~~~~~~~~~~~~~~~~~~~\n",
//                         "/|///||//||/|||//|//|/|\n"}};

//                     {{"     @@@               \n"},
//                      {"                       \n"},
//                      {"                       \n"},
//                      {"                       \n"},
//                      {"~~~~~~~~~~~~~~~~~~~~~~~\n"},
//                      {"|/||////|||/|/|||///||/\n"}},

//                     {{"    @@@@@              \n"},
//                      {"     @@@               \n"},
//                      {"                       \n"},
//                      {"                       \n"},
//                      {"~~~~~~~~~~~~~~~~~~~~~~~\n"},
//                      {"/|///||//||/|||//|//|/|\n"}},
                    
//                     {{"     @@@               \n"},
//                      {"    @@@@@              \n"},
//                      {"     @@@               \n"},
//                      {"                       \n"},
//                      {"~~~~~~~~~~~~~~~~~~~~~~~\n"},
//                      {"|/||////|||/|/|||///||/\n"}},

//                     {{"                       \n"},
//                      {"     @@@               \n"},
//                      {"    @@@@@              \n"},
//                      {"     @@@               \n"},
//                      {"~~~~~~~~~~~~~~~~~~~~~~~\n"},
//                      {"|/||////|||/|/|||///||/\n"}}
//                 };

#endif