#include "Buttons.h"

int8_t Button_press = 0;
int8_t status = 0;
int16_t count_ms = 50;
uint16_t button_up = 0;
uint16_t button_down = 0;

void scanButton(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin) {
    if (HAL_GPIO_ReadPin(GPIOx, GPIO_Pin) == GPIO_PIN_SET) {
          count_ms++;
          if (count_ms > 50) {
              count_ms = 50;
              button_up++;
              if (button_down != 0) {
                  if (button_down < 300) {
                      status++;
                      if (status > 3) status = 5;
                  }
                  if (button_down > 4950 && button_down < 9950) status = 4;
                  if (button_down > 10000) status = 5;
                  button_down = 0;
              }
          }
      }else {
          count_ms--;
          if (count_ms < 0) {
              count_ms = 0;
              button_down++;
              button_up = 0;
          }
      }
      if (button_up > 350) {
          if (Button_press == 0) Button_press = status;
          status = 0;
          button_up = 0;
      }
}
