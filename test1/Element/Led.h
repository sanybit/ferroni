/* lightLed() функция должна запускаться каждую мС
* lightLedStart() функция должна запускаться каждые 50 мкС
* greenLight запускает зелёный светодиод:
* 1 - один раз моргает
* 2 - два раза моргает
* 3 - три раза моргает
* 4 - плавно включается и плавно выключается
* redLight 1 запускает однократное моргание красным светодиодом*/

#include "main.h"

uint8_t greenLight; /*флаг включения зелёного светодиода*/
uint8_t redLight; /*флаг включения красного светодиода*/
uint16_t countLightTimeG; /*таймер зелёного светодиода*/
uint16_t countLightTimeR; /*таймер красного светодиода*/

void lightLed(); /*функция включения светодиодов*/
void lightLedStart(); /*функция плавного зажигания зелёного светодиода*/ 