#ifndef INPUT_SYSTEM_H
#define INPUT_SYSTEM_H

const int lenStr = 256;
void readSingleCooficient(double *a);

int checkLefterN(char *str, int startN, bool *termFromLeft, int *findX, double *buffCoof);

int checkRitghterN(char *str, int endN, bool *termFromRight, int *findX);

int setCoof(char *str, int startN, int endN, double *buffCoof, double *a, double *b, double *c);

int findCoofsFromStr(char *str, double *a, double *b, double *c);

void readCoofs(double *a, double *b, double *c);

int readCooficients(double *a, double *b, double *c);

bool askForSomething(char *text);

void clearInput();

#endif
