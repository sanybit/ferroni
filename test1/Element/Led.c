#include "Led.h"

uint8_t greenLight = 0;
uint8_t redLight = 0;
uint16_t countLightTimeG = 0;
uint16_t countLightTimeR = 0;
uint16_t m = 1;
uint16_t n = 0;
uint8_t x = 1;

extern volatile uint8_t soundSuccess;
extern volatile uint8_t soundError;

void lightLed() {
    if (greenLight) {
        if (greenLight == 1) {
            countLightTimeG++;
            if (countLightTimeG == 1) {
                HAL_GPIO_WritePin(GPIOA, GREEN_LED_Pin, GPIO_PIN_SET);
                soundSuccess = 1;
            }
            if (countLightTimeG > 1000) {
                HAL_GPIO_WritePin(GPIOA, GREEN_LED_Pin, GPIO_PIN_RESET);
                countLightTimeG = 0;
                greenLight = 0;
            }
        }
        if (greenLight == 2) {
            countLightTimeG++;
            if (countLightTimeG == 1) {
                HAL_GPIO_WritePin(GPIOA, GREEN_LED_Pin, GPIO_PIN_SET);
                soundSuccess = 1;
            }
            if (countLightTimeG == 1000) {
                HAL_GPIO_WritePin(GPIOA, GREEN_LED_Pin, GPIO_PIN_RESET);
            }
            if (countLightTimeG == 2000) {
                HAL_GPIO_WritePin(GPIOA, GREEN_LED_Pin, GPIO_PIN_SET);
                soundSuccess = 1;
            }
            if (countLightTimeG > 3000) {
                HAL_GPIO_WritePin(GPIOA, GREEN_LED_Pin, GPIO_PIN_RESET);
                countLightTimeG = 0;
                greenLight = 0;
            }
        }
        if (greenLight == 3) {
            countLightTimeG++;
            if (countLightTimeG == 1) {
                HAL_GPIO_WritePin(GPIOA, GREEN_LED_Pin, GPIO_PIN_SET);
                soundSuccess = 1;
            }
            if (countLightTimeG == 1000) {
                HAL_GPIO_WritePin(GPIOA, GREEN_LED_Pin, GPIO_PIN_RESET);
            }
            if (countLightTimeG == 2000) {
                HAL_GPIO_WritePin(GPIOA, GREEN_LED_Pin, GPIO_PIN_SET);
                soundSuccess = 1;
            }
            if (countLightTimeG == 3000) {
                HAL_GPIO_WritePin(GPIOA, GREEN_LED_Pin, GPIO_PIN_RESET);
            }
            if (countLightTimeG == 4000) {
                HAL_GPIO_WritePin(GPIOA, GREEN_LED_Pin, GPIO_PIN_SET);
                soundSuccess = 1;
            }
            if (countLightTimeG > 5000 ) {
                HAL_GPIO_WritePin(GPIOA, GREEN_LED_Pin, GPIO_PIN_RESET);
                countLightTimeG = 0;
                greenLight = 0;
            }
        }
    }
    if (redLight) {
        if (redLight == 1) {
            countLightTimeR++;
            if (countLightTimeR == 1) {
                HAL_GPIO_WritePin(GPIOA, RED_LED_Pin, GPIO_PIN_SET);
                soundError = 1;
            }
            if (countLightTimeR > 1500) {
                HAL_GPIO_WritePin(GPIOA, RED_LED_Pin, GPIO_PIN_RESET);
                countLightTimeR = 0;
                redLight = 0;
            }
        }
    }
}

void lightLedStart() {
    if (greenLight == 4) {
        
        if (x) countLightTimeG++;
        else countLightTimeG--;
            
        if (countLightTimeG == (142*m)) {
                
            if (x) m++;
            else m--;
                
            n = m;
        }
        if (n != 0){
            HAL_GPIO_WritePin(GPIOA, GREEN_LED_Pin, GPIO_PIN_SET);
            n--;
        }else {
            HAL_GPIO_WritePin(GPIOA, GREEN_LED_Pin, GPIO_PIN_RESET);
        }
        if (countLightTimeG == 20164) {
            x = 0;
            m = 141;
        }
        if (m == 0) {
            countLightTimeG = 0;
            greenLight = 0;
            m = 1;
            x = 1;
        }
    }
}
