#include "main.h"
#include "stm32f1xx_it.h"

uint16_t timerButton = 0;
uint16_t timerSuccess = 0;
uint16_t timerError = 0;
uint16_t timerMain = 0;
uint16_t timerMainADC = 0;

extern DMA_HandleTypeDef hdma_adc1;
extern ADC_HandleTypeDef hadc1;
extern TIM_HandleTypeDef htim1;

void scanButton(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin);
void soundBuzzerSuccess();
void soundBuzzerError();
void lightLed();
void lightLedStart();


/**
  * @brief This function handles System tick timer.
  */
void SysTick_Handler(void)
{
  HAL_IncTick();
}
/**
  * @brief This function handles DMA1 channel1 global interrupt.
  */
void DMA1_Channel1_IRQHandler(void)
{
  HAL_DMA_IRQHandler(&hdma_adc1);
}

/**
  * @brief This function handles ADC1 and ADC2 global interrupts.
  */
void ADC1_2_IRQHandler(void)
{
  HAL_ADC_IRQHandler(&hadc1);
}

/**
  * @brief This function handles TIM1 update interrupt.
  */
void TIM1_UP_IRQHandler(void)
{
    /*счётчики 50 мкС*/
  timerSuccess++;
  timerError++;
  timerButton++;
    
  lightLedStart(); /*функция плавного зажигания зелёного светодиода*/
    
  if (timerSuccess >= 25) { /*время проверки 1,25 мС*/
      soundBuzzerSuccess(); /*проверяем флаг успех*/
      timerSuccess = 0;
  }
  if (timerButton >= 20) { /*время проверки 1 мС*/
      timerMain++;
      timerMainADC++;
      scanButton(GPIOA, GPIO_PIN_4); /*проверяем состояние кнопки*/
      lightLed(); /*проверка включения светодиодов*/
      timerButton = 0;
  }
  if (timerError >= 16) { /*время проверки 0,8 мС*/
      soundBuzzerError(); /*проверяем флаг ошибка*/
      timerError = 0;
  }
  HAL_TIM_IRQHandler(&htim1);
}
