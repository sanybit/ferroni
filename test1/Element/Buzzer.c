#include "Buzzer.h"

uint8_t soundSuccess = 0;
uint8_t soundError = 0;
uint16_t timerSound = 0;

void soundBuzzerSuccess() {
    
    if (soundSuccess) {
        timerSound++;
        HAL_GPIO_TogglePin(BF_P_GPIO_Port,BF_P_Pin);
        HAL_GPIO_TogglePin(BF_G_GPIO_Port,BF_G_Pin);
        if (timerSound == 280) { /*время звучания 350мС/1,250мС=280 */
            timerSound = 0;
            soundSuccess = 0;
        }
    }
}

void soundBuzzerError() {
    
    if (soundError) {
        timerSound++;
        HAL_GPIO_TogglePin(BF_P_GPIO_Port,BF_P_Pin);
        HAL_GPIO_TogglePin(BF_G_GPIO_Port,BF_G_Pin);
        if (timerSound == 812) { /*время звучания 650мС/0,8мС=812,5 */
            timerSound = 0;
            soundError = 0;
        }
    }
}
