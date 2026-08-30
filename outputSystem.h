#ifndef OUTPUT_SYSTEM_H
#define OUTPUT_SYSTEM_H

#include "setting.h"

/**
 * @brief Modifies coefficients to make the plot bounce at a given y-coordinate.
 * @param[out] a Coefficient a of the quadratic.
 * @param[out] b Coefficient b.
 * @param[out] c Coefficient c.
 * @param yCoord The y-coordinate where the bounce occurs.
 */
void makePlotBounce(double *a, double *b, double *c, int yCoord);

/**
 * @brief Finds the index of the enemy closest to a given point.
 * @param enemyArray Array of enemies.
 * @param x X-coordinate of the point.
 * @param y Y-coordinate of the point.
 * @return Index of the nearest enemy in the array.
 */
int findNearestEnemyToPoint(enemy enemyArray[], int x, int y);

/**
 * @brief Places an enemy symbol on the game screen.
 * @param gameScreen The game screen buffer (1D array).
 * @param setSymbol The character to represent the enemy.
 * @param Enemy The enemy to place.
 */
void setEnemy(char gameScreen[], char setSymbol, enemy Enemy);

/**
 * @brief Converts 2D coordinates (x, y) to a 1D array index.
 * @param x X-coordinate.
 * @param y Y-coordinate.
 * @return The corresponding 1D index.
 */
int GetIndexFor1dArrayFromXandY(int x, int y);

/**
 * @brief Initializes the buffer for animation plot.
 * @param toDraw Pointer to the buffer to initialize.
 */
void animationPlotInit(char *toDraw);

/**
 * @brief Calculates the (x, y) point on a parabola given x and coefficients.
 * @param[out] xCoord Resulting x-coordinate (usually same as input x, but may be adjusted).
 * @param[out] yCoord Resulting y-coordinate.
 * @param x The x value to evaluate.
 * @param a Coefficient a.
 * @param b Coefficient b.
 * @param c Coefficient c.
 */
void calcParabolaPoints(int *xCoord, int *yCoord, double x, double a, double b, double c);

/**
 * @brief Draws an animated graph of the parabola defined by coefficients.
 * @param a Coefficient a.
 * @param b Coefficient b.
 * @param c Coefficient c.
 */
void drawAnimationGraph(double a, double b, double c);

/**
 * @brief Rounds a double to the nearest integer and clamps it within [0, board].
 * @param x The value to round.
 * @param board The upper bound (exclusive). If the rounded value is outside [0, board], returns 0.
 * @return Rounded integer clamped to [0, board]. Returns 0 if out of bounds.
 */
int roundInBounds(double x, int board);

/**
 * @brief Initializes a static plot array with empty spaces.
 * @param StaticPlotArray 2D array representing the plot.
 */
void StaticPlotInit(char StaticPlotArray[][X_SIZE]);

/**
 * @brief Draws a numeric value on a static plot at a given position.
 * @param StaticPlotArray The plot array.
 * @param adding A prefix string to display before the value.
 * @param value The numeric value to display.
 * @param x X-coordinate for the text.
 * @param y Y-coordinate for the text.
 */
void DrawNumberOnPlot(char StaticPlotArray[][X_SIZE], const char *adding, double value, int x, int y);

/**
 * @brief Renders the static plot array to the screen.
 * @param StaticPlotArray The plot array to draw.
 */
void drawGraphicFromArray(char StaticPlotArray[][X_SIZE]);

/**
 * @brief Draws the plot of a quadratic equation with given roots.
 * @param a Coefficient a.
 * @param b Coefficient b.
 * @param c Coefficient c.
 * @param x1 First root.
 * @param x2 Second root.
 */
void plotQuadratics(double a, double b, double c, double x1, double x2);

/**
 * @brief Prints the number of roots and their values.
 * @param nRoots Number of roots (0, 1, or 2).
 * @param x1 First root (valid if nRoots >= 1).
 * @param x2 Second root (valid if nRoots == 2).
 */
void printRoots(int nRoots, double x1, double x2);

/**
 * @brief Performs one step of the game for a single player.
 * @param a Coefficient a from the step.
 * @param b Coefficient b.
 * @param c Coefficient c.
 * @param enemyArray Array of enemy units.
 */
void gameStep(double a, double b, double c, enemy enemyArray[]);

/**
 * @brief Performs one step of the game for two players.
 * @param a Coefficient a.
 * @param b Coefficient b.
 * @param c Coefficient c.
 * @param firstPlayerGuys Array of units for player 1.
 * @param secondPlayerGuys Array of units for player 2.
 * @param firstPlayerAttackSymbol Symbol used for player 1's attacks.
 * @param secondPlayerAttackSymbol Symbol used for player 2's attacks.
 * @param firstPlayerGuysSymbol Symbol representing player 1's units.
 * @param secondPlayerGuysSymbol Symbol representing player 2's units.
 * @param isFirstStep Flag indicating if this is the first step.
 */
void gameStepTwoPlayer(double a, double b, double c, enemy firstPlayerGuys[], enemy secondPlayerGuys[], 
                        char firstPlayerAttackSymbol, char secondPlayerAttackSymbol, char firstPlayerGuysSymbol, char secondPlayerGuysSymbol, bool isFirstStep);

//void drawAnimationTwoGraph(double a1, double b1, double c1, double a2, double b2, double c2);
//void TwoPlotQuadratics(double a1, double b1, double c1, double a2, double b2, double c2, double x1, double x2);

#endif