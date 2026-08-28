#ifndef SETTINGS_H
#define SETTINGS_H

const int X_SIZE = 100;
const int Y_SIZE = 53;
const int ZeroX = 50;
const int ZeroY = 26;

const char greenColor[] = "\033[31m";
const char BaseColor[] = "\033[m";

const int NumLen = 100;
const double step = 0.01;

const char symbolForParabola = '#';

const int MaxTestLen = 100;
const int MaxInputLen = 256;

const int maxEnemySize = 30;

struct testUnit
{
    double a, b, c;
    int nRoots;
    double x1, x2;
};

struct enemy 
{
    int x = 0;
    int y = 0;
    bool isAlive = 1;
    int enemyPointsArray[maxEnemySize][2] = {};
};

enum NumRoots
{
    NoRoots = 0, 
    OneRoot = 1, 
    TwoRoots = 2,
    InfRoots = -1
};


#endif