#ifndef OUTPUT_SYSTEM_H
#define OUTPUT_SYSTEM_H

const int X_SIZE = 100;
const int Y_SIZE = 53;
const int ZeroX = 50;
const int ZeroY = 26;

int roundInBounds(double x, int board);

void plotInit();

void DrawNumberOnPlot(const char *adding, double value, int x, int y);

void drawGraphicFromArray();

void plotQuadratics(double a, double b, double c, double x1, double x2);

void printRoots(int nRoots, double x1, double x2);

#endif