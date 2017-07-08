#include "DrainSelect.h"

void drain_select(u16 drain){
    HAL_GPIO_WritePin(GPIOA,Drain1,GPIO_PIN_RESET);
    HAL_GPIO_WritePin(GPIOA,Drain2,GPIO_PIN_RESET);
    HAL_GPIO_WritePin(GPIOA,Drain3,GPIO_PIN_RESET);
    HAL_GPIO_WritePin(GPIOA,Drain4,GPIO_PIN_RESET);
    HAL_Delay(10);
    HAL_GPIO_WritePin(GPIOA,drain,GPIO_PIN_SET);
    HAL_Delay(10);
}