/*soundBuzzerSuccess функция вызывается с переодичностью 1,25 мС (800 Гц)
*soundBuzzerError функция вызывается с переодичностью 0,8 мС (1250 Гц)
*soundSuccess запускается звучание установкой в 1
*soundError запускается звучание установкой 1 */

#include "main.h"

uint8_t soundSuccess; /*флаг запуска звучания успех*/
uint8_t soundError; /*флаг запуска звучания ошибка*/
uint16_t timerSound; /*таймер для отсчёта времени звучания*/

void soundBuzzerSuccess(); /*функция звучания успех*/
void soundBuzzerError(); /*функция звучания ошибка*/
