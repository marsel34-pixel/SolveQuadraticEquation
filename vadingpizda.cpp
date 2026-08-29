#include <stdio.h>

struct vector
{
    double x, y, z;
};

struct circle
{
    double x, y, z, rad;
};

int draw()
{
    circle Circle = {};
    Circle.x = 10;
    Circle.y = 0;
    Circle.z = 0;
    Circle.rad = 3;
    vector camPos = {};
    char toDraw[100] = {};
    for (int x = 0; x < 100; x++)
    {
        for (int y = 0; y < 50; y++)
        {
            vector look = {};
            double t = 0;
            
        }
    }
}