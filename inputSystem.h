#ifndef INPUT_SYSTEM_H
#define INPUT_SYSTEM_H



/**
* @brief цикл пока не получится взять число из консоли
* @param[out] a записыывается полученное значение
*/
void readSingleCoeficient(double *a);

/**
 * @brief 
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
* @brief ищет член для числа 
*
* @param[in] EquationStr анализируемая строка
* @param startN индекс начала числа, для которого ищется член
* @param startN индекс конца числа, для которого ищется член
* @param[out] terWasFound был ли уже найден член
* @param[out] foundPowerX степень найденного члена
* @param[in] buffCoef указатель на значение числа, которое будут прибавляться одному из коэфициентов
* @param side выбор направления проверки лево или право
* @retval 0 Все прошло успешно
* @retval 1 Ошибка в чтении уравнения
*/
int findPowerX(char *EquationStr, int StartN, int endN, bool *termWasFound, int *foundPowerX, double *buffCoef, bool side);

int checkRightForPower(char *EquationStr, int *IndexStrForCheck, int *foundPowerX, bool *xWasFound);

/**
* @brief анализирует соседные для числа члены, и прибавляет нужное значение нужному коэфициенту
*
* @param[in] EquationStr анализируемая строка
* @param startN индекс начала числа, для которого ищется член
* @param startN индекс конца числа, для которого ищется член
* @param[in] buffCoef указатель на значение числа, которое будут прибавляться одному из коэфициентов
* @param[out] a записыывается полученное значение
* @param[out] b записыывается полученное значение
* @param[out] c записыывается полученное значение
*
* 
* @retval 0 Все прошло успешно
* @retval 1 Ошибка в чтении уравнения
*/
int setCoef(char *EquationStr, int startN, int endN, double *buffCoof, double *a, double *b, double *c);

/**
* @brief Ищет числа в строке и записывает их в в нужные коэфициенты, благодаря рядом стоящим членам
*
* @param[in] EquationStr анализируемая строка
* @param[out] a записыывается полученное значение
* @param[out] b записыывается полученное значение
* @param[out] c записыывается полученное значение
*
* @retval 0 Все прошло успешно
* @retval 1 Ошибка в чтении уравнения
*/
int findCoefsFromStr(char *EquationStr, double *a, double *b, double *c);

/**
* @brief Читает пооочередно 3 коэфициента из консоли 
* @param[out] a записыывается полученное значение
* @param[out] b записыывается полученное значение
* @param[out] c записыывается полученное значение
*/
void readCoefs(double *a, double *b, double *c);

/**
* @brief Читает уравнение из консоли и засовывает их в коэфициенты
*
* @param[out] a записыывается полученное значение
* @param[out] b записыывается полученное значение
* @param[out] c записыывается полученное значение
*
* @retval 0 Все прошло успешно
* @retval 1 Ошибка в чтении уравнения
*/
int readCoeficientsFromEquation(double *a, double *b, double *c);

/**
 * @brief Спрашивает Y/N 
 *  Будет работать пока не получит ответа
 *
 * @param text текст перед вопросом
 *
 * @return если Y возвращает 1, если N то 0
 */
bool askAboutChoise(const char *text);

/**
 * @brief Очищает вывод до следуйщего "\n"
 */
void clearInput();

#endif
