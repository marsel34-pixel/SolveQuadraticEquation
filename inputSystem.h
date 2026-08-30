#ifndef INPUT_SYSTEM_H
#define INPUT_SYSTEM_H

/**
 * @brief Reads a single double coefficient from the console, retrying until a valid number is entered.
 * @param[out] a Pointer to store the read value.
 */
void readSingleCoeficient(double *a);

/**
 * @brief Finds the power of x adjacent to a number in the equation string.
 *
 * Examines the vicinity of a number (from StartN to endN) to determine if an x-term
 * (with or without exponent) is present. If found, records its power and the coefficient value.
 *
 * @param[in] EquationStr The equation string to analyze.
 * @param[in] StartN Starting index of the number.
 * @param[in] endN Ending index of the number.
 * @param[out] termWasFound Set to true if an x-term is found next to the number.
 * @param[out] foundPowerX The exponent of the found term (2 for x^2, 1 for x).
 * @param[in] buffCoef Pointer to the numeric value of the number to be added.
 * @param[in] side Direction: true for left side, false for right side.
 * @retval 0 Success.
 * @retval 1 Error while parsing the equation.
 */
int findPowerX(char *EquationStr, int StartN, int endN, bool *termWasFound, int *foundPowerX, double *buffCoef, bool side);

/**
 * @brief Helper: checks for an x-term to the left of the given index.
 *
 * If a term is found, the index is advanced to skip the whole term, and its power is recorded.
 *
 * @param[in] EquationStr The equation string.
 * @param[in,out] IndexStrForCheck On input, the position to check; on output, updated to point after the term if found.
 * @param[out] foundPowerX The exponent of the found term (2 or 1).
 * @param[out] xWasFound True if a term was found, false otherwise.
 * @retval 0 Success.
 * @retval 1 Parsing error.
 */
int checkLeftForPower(char *EquationStr, int *IndexStrForCheck, int *foundPowerX, bool *xWasFound);

/**
 * @brief Helper: checks for an x-term to the right of the given index.
 *
 * If a term is found, the index is advanced to skip the whole term, and its power is recorded.
 *
 * @param[in] EquationStr The equation string.
 * @param[in,out] IndexStrForCheck On input, the position to check; on output, updated to point after the term if found.
 * @param[out] foundPowerX The exponent of the found term (2 or 1).
 * @param[out] xWasFound True if a term was found, false otherwise.
 * @retval 0 Success.
 * @retval 1 Parsing error.
 */
int checkRightForPower(char *EquationStr, int *IndexStrForCheck, int *foundPowerX, bool *xWasFound);

/**
 * @brief Adds the number value to the appropriate coefficient based on the adjacent x-term.
 *
 * For a number located from startN to endN, this function checks for an x-term on either side.
 * Based on the power of that term, it adds the number to:
 *   - a (coefficient for x^2) if power == 2,
 *   - b (coefficient for x)   if power == 1,
 *   - c (constant term)       if no term is found.
 *
 * @param[in] EquationStr The equation string.
 * @param[in] startN Starting index of the number.
 * @param[in] endN Ending index of the number.
 * @param[in] buffCoof Pointer to the numeric value to be added.
 * @param[out] a Coefficient for x^2.
 * @param[out] b Coefficient for x.
 * @param[out] c Constant term.
 * @retval 0 Success.
 * @retval 1 Error while parsing.
 */
int setCoef(char *EquationStr, int startN, int endN, double *buffCoof, double *a, double *b, double *c);

/**
 * @brief Parses the equation string to extract coefficients a, b, and c.
 *
 * Scans the entire string for numbers, and for each number calls setCoef to add its value
 * to the appropriate coefficient based on any adjacent x-terms. The resulting coefficients
 * satisfy a*x^2 + b*x + c = 0.
 *
 * @param[in] EquationStr The equation string (e.g., "2x^2 + 3x - 5 = 0").
 * @param[out] a Coefficient for x^2.
 * @param[out] b Coefficient for x.
 * @param[out] c Constant term.
 * @retval 0 Success.
 * @retval 1 Error (invalid format).
 */
int findCoefsFromStr(char *EquationStr, double *a, double *b, double *c);

/**
 * @brief Reads three coefficients from the console sequentially.
 *
 * Each coefficient is read using readSingleCoeficient. The user is expected to enter numbers
 * separated by whitespace or newlines.
 *
 * @param[out] a First coefficient.
 * @param[out] b Second coefficient.
 * @param[out] c Third coefficient.
 */
void readCoefs(double *a, double *b, double *c);

/**
 * @brief Reads an entire equation line from the console and extracts the coefficients.
 *
 * The line is expected to contain a quadratic equation in the form "ax² + bx + c = 0".
 * It then calls findCoefsFromStr to parse the coefficients.
 *
 * @param[out] a Coefficient for x^2.
 * @param[out] b Coefficient for x.
 * @param[out] c Constant term.
 * @retval 0 Success.
 * @retval 1 Parsing error (invalid equation format).
 */
int readCoeficientsFromEquation(double *a, double *b, double *c);

/**
 * @brief Asks a Y/N question and returns the answer.
 *
 * Displays the given prompt and waits for a single character input. Repeats until a valid
 * answer (Y/y or N/n) is given.
 *
 * @param text The question prompt (e.g., "Do you want to continue? (Y/N): ").
 * @return true if user answered Y or y, false if N or n.
 */
bool askAboutChoise(const char *text);

/**
 * @brief Clears the input buffer up to the next newline.
 *
 * Discards all characters from the standard input buffer until and including the next '\n'.
 * Used to clean up after invalid input.
 */
void clearInput();

#endif