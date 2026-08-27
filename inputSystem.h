#ifndef INPUT_SYSTEM_H
#define INPUT_SYSTEM_H

const int MaxInputLen = 256;

/**
* @brief Entry point
* @param argc Number of arguments
* @param argv List of arguments
* @return Program exit status
*/
void readSingleCoeficient(double *a);

/**
 * @brief Entry point
 *
 * Execution of the program
 * starts here.
 *
 * @param argc Number of arguments
 * @param argv List of arguments
 *
 * @return Program exit status
 */
int checkLeftForPower(char *EquationStr, int *IndexStrForCheck, int *foundPowerX, bool *xWasFound);

/**
 * @brief Entry point
 *
 * Execution of the program
 * starts here.
 *
 * @param argc Number of arguments
 * @param argv List of arguments
 *
 * @return Program exit status
 */
int findPowerX(char *EquationStr, int StartN, int endN, bool *termWasFound, int *foundPowerX, double *buffCoef, bool Left);

int checkRightForPower(char *EquationStr, int *IndexStrForCheck, int *foundPowerX, bool *xWasFound);

int setCoef(char *EquationStr, int startN, int endN, double *buffCoof, double *a, double *b, double *c);

int findCoefsFromStr(char *EquationStr, double *a, double *b, double *c);

void readCoefs(double *a, double *b, double *c);

int readCoeficientsFromEquation(double *a, double *b, double *c);

/**
 * @brief Entry point
 *
 * Execution of the program
 * starts here.
 *
 * @param argc Number of arguments
 * @param argv List of arguments
 *
 * @return Program exit status
 */
bool askAboutChoise(const char *text);

void clearInput();

#endif
