#ifndef AI_H
#define AI_H

#include "setting.h"

/**
* @brief AI makes move
*
* @param EnemyArray[] array of enemy for AI
* @param[out] a put coeficient from AI in
* @param[out] b put coeficient from AI in
* @param[out] c put coeficient from AI in
*/
void AIEnemy(enemy EnemyArray[], double *a, double *b, double *c);

/**
* @brief checks whether the game should end
*
* @param firstPlayerGuys[] Player 1's array of guys
* @param secondPlayerGuys[] Player 2'nd array of guys
* @return 1 if game end, else 0
*/
bool checkEndGameForTwoPlayer(enemy firstPlayerGuys[], enemy secondPlayerGuys[]);

/**
* @brief write text, ask for symbol
*
* @param text write this text
* @return char symbol what was write
*/
char askForSymbolToGame(const char text[]);

/**
* @brief init enemy
*
* @param enemyArray[] to init
*/
void enemyInit(enemy enemyArray[]);

/**
* @brief calculate how many alive enemy reamin
*
* @param enemyArray array to calculate
* @return number of alive enemy
*/
int calcHowManyRemain(enemy enemyArray[]);

/**
* @brief return random number in range [min, max)
*/
int randomNumberInRange(int min, int max);

/**
 * @brief start game for one player
 */
void gameMode();

/**
 * @brief writes the text character by character with a delay
 * @param Text text to write
 */
void AIWriteText(const char *Text);

/**
 * @brief checks and reduces the number of tokens
 * @param[in, out] tokens number of rokens
 */
void checkTokens(int *tokens);

/**
 * @brief ask quastion and always dint unnderstand this
 * @param[in, out] tokens number of tokens
 */
void infinityDontUnderstand(int *tokens);

/**
 * @brief basic version of program
 */
void basicProgramm();

/**
 * @brief AI version of program
 */
void AIUltraProgramm();

/**
 * @brief start game for two player
 */
void gameTwoPlyerMode();

#endif