#include "sterringengine.h"

extern TIM_HandleTypeDef htim2;

void sterringengine_init(void){
    HAL_TIM_Base_Start(&htim2);
    HAL_TIM_PWM_Start(&htim2,TIM_CHANNEL_1);
    HAL_TIM_PWM_Start(&htim2,TIM_CHANNEL_2);
    HAL_TIM_PWM_Start(&htim2,TIM_CHANNEL_3);
    __HAL_TIM_SET_COMPARE(&htim2,SE_CH1,SE_CH1_DISABLE);
    __HAL_TIM_SET_COMPARE(&htim2,SE_CH2,SE_CH2_DISABLE);
    __HAL_TIM_SET_COMPARE(&htim2,SE_CH3,SE_CH3_DISABLE);
}

void sterringengine_rotate(u32 channel,u32 position){
    if(position > 1998) position = 1998;
    __HAL_TIM_SET_COMPARE(&htim2,channel,position);
}

void sterringengine_action(u32 CH1_action,u32 CH2_action,u32 CH3_action){
    sterringengine_rotate(SE_CH1,CH1_action);
    sterringengine_rotate(SE_CH2,CH2_action);
    sterringengine_rotate(SE_CH3,CH3_action);
}

