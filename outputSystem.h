#ifndef OUTPUT_SYSTEM_H
#define OUTPUT_SYSTEM_H

const int X_SIZE = 100;
const int Y_SIZE = 100;
const int ZeroX = 50;
const int ZeroY = 50;

int org(double x, int board);

void drawNumbers(int *x, int *y,double x1,int len, int up);

void drawGraphicFromMass(double x1, double x2, int len1, int len2);

void drawPenis(double a, double b, double c);

void printRoots(int nRoots, double x1, double x2);


#endif