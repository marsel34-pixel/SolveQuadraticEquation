#ifndef INPUT_SYSTEM_H
#define INPUT_SYSTEM_H

const int MaxInputLen = 256;

void readSingleCoeficient(double *a);

int checkLeftForPower(char *EquationStr, int *IndexStrForCheck, int *foundPowerX, bool *xWasFound);

int findPowerX(char *EquationStr, int StartN, int endN, bool *termWasFound, int *foundPowerX, double *buffCoef, bool Left);

int checkRightForPower(char *EquationStr, int *IndexStrForCheck, int *foundPowerX, bool *xWasFound);

int setCoef(char *EquationStr, int startN, int endN, double *buffCoof, double *a, double *b, double *c);

int findCoefsFromStr(char *EquationStr, double *a, double *b, double *c);

void readCoefs(double *a, double *b, double *c);

int readCoeficients(double *a, double *b, double *c);

bool askAboutChoise(const char *text);

void clearInput();

#endif
