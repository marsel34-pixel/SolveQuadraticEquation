#ifndef INPUT_SYSTEM_H
#define INPUT_SYSTEM_H

void readSingleCooficient(double *a);
void findNumbersAndX(char *str, struct x *powers,struct number *coofs, int *numDigit, int *numX);
void findLeftPower(int *leftMostPower, int indexNum, struct number *coofs, struct x *powers,int *numX);
void findRightPower(int *rightMostPower, int indexNum, struct number *coofs, struct x *powers, int *numX);
void findPowerCoofs(char *str, struct number *coofs, struct x *powers, int *numDigit, int *numX,
                                                        double *a, double *b, double *c);
int checkLefterN(char *str, int startN, bool *termFromLeft, int *findX, double *buffCoof);
int checkRitghterN(char *str, int endN, bool *termFromRight, int *findX);
int setCoof(char *str, int startN, int endN, double *buffCoof, double *a, double *b, double *c);
int findCoofsFromStr(char *str, double *a, double *b, double *c);
void readCoofs(double *a, double *b, double *c);
int readCooficients(double *a, double *b, double *c);
bool needContinue();
void clearInput();

#endif
