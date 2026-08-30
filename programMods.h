#ifndef AI_H
#define AI_H

#include "setting.h"

/**
 * @brief Makes a move for the AI.
 *
 * This function computes the coefficients a, b, and c based on the current
 * state of the enemy array to determine the AI's action.
 *
 * @param EnemyArray Array of enemy objects used by the AI for decision making.
 * @param[out] a Pointer to store the first coefficient (AI output).
 * @param[out] b Pointer to store the second coefficient (AI output).
 * @param[out] c Pointer to store the third coefficient (AI output).
 */
void AIEnemy(enemy EnemyArray[], double *a, double *b, double *c);

/**
 * @brief Checks whether the two‑player game should end.
 *
 * The game ends when one player has no alive units left.
 *
 * @param firstPlayerGuys Array of the first player's units.
 * @param secondPlayerGuys Array of the second player's units.
 * @return 1 if the game should end, otherwise 0.
 */
bool checkEndGameForTwoPlayer(enemy firstPlayerGuys[], enemy secondPlayerGuys[]);

/**
 * @brief Displays a text prompt and asks the user to enter a symbol.
 *
 * @param text The prompt text to display.
 * @return The character entered by the user.
 */
char askForSymbolToGame(const char text[]);

/**
 * @brief Initialises the enemy array with default values.
 *
 * @param enemyArray The array to be initialised.
 */
void enemyInit(enemy enemyArray[]);

/**
 * @brief Counts how many enemies are still alive in the array.
 *
 * @param enemyArray The array to examine.
 * @return The number of alive enemies.
 */
int calcHowManyRemain(enemy enemyArray[]);

/**
 * @brief Generates a random integer in the range [min, max).
 *
 * @param min Lower bound (inclusive).
 * @param max Upper bound (exclusive).
 * @return A random integer in the specified range.
 */
int randomNumberInRange(int min, int max);

/**
 * @brief Starts the single‑player game mode.
 */
void gameMode();

/**
 * @brief Prints the given text character by character with a delay,
 *        simulating a typewriter effect.
 *
 * @param Text The text to print.
 */
void AIWriteText(const char *Text);

/**
 * @brief Checks the token count and reduces it if necessary.
 *
 * @param[in, out] tokens Pointer to the current number of tokens.
 */
void checkTokens(int *tokens);

/**
 * @brief Repeatedly asks a question until the user provides an understandable answer.
 *
 * @param[in, out] tokens Pointer to the token count (may be modified).
 */
void infinityDontUnderstand(int *tokens);

/**
 * @brief Runs the basic version of the program (without AI).
 */
void basicProgramm();

/**
 * @brief Runs the advanced version of the program with enhanced AI.
 */
void AIUltraProgramm();

/**
 * @brief Starts the two‑player game mode.
 */
void gameTwoPlyerMode();

// void basicCalc(); // commented out, not used

#endif