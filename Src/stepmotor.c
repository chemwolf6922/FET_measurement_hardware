#include "stepmotor.h"

extern TIM_HandleTypeDef htim4;

int steps_to_go = 0;
int current_step = 0;
int target_step = 0;
u8 sm_busy_flag = 0;

void stepmotor_sleep(GPIO_PinState sleep){
	HAL_GPIO_WritePin (SM_SLEEP_GPIO_Port, SM_SLEEP_Pin, sleep);
}

void stepmotor_enable(GPIO_PinState state){
	HAL_GPIO_WritePin (SM_ENABLE_GPIO_Port, SM_ENABLE_Pin, state);
}


void stepmotor_dir(GPIO_PinState dir){
	HAL_GPIO_WritePin (SM_DIR_GPIO_Port, SM_DIR_Pin, dir);
}

void stepmotor_reset(void){
	HAL_GPIO_WritePin (SM_RESET_GPIO_Port, SM_RESET_Pin, GPIO_PIN_RESET);
	HAL_Delay(1);
	HAL_GPIO_WritePin (SM_RESET_GPIO_Port, SM_RESET_Pin, GPIO_PIN_SET);
}

void stepmotor_microstep(u8 microstep){
	switch(microstep){
		case SM_2_MICROSTEP:
			HAL_GPIO_WritePin (SM_MODE0_GPIO_Port, SM_MODE0_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin (SM_MODE1_GPIO_Port, SM_MODE1_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin (SM_MODE2_GPIO_Port, SM_MODE2_Pin, GPIO_PIN_RESET);
			break;
		case SM_4_MICROSTEP:
			HAL_GPIO_WritePin (SM_MODE0_GPIO_Port, SM_MODE0_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin (SM_MODE1_GPIO_Port, SM_MODE1_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin (SM_MODE2_GPIO_Port, SM_MODE2_Pin, GPIO_PIN_RESET);
			break;
		case SM_8_MICROSTEP:
			HAL_GPIO_WritePin (SM_MODE0_GPIO_Port, SM_MODE0_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin (SM_MODE1_GPIO_Port, SM_MODE1_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin (SM_MODE2_GPIO_Port, SM_MODE2_Pin, GPIO_PIN_RESET);
			break;
		case SM_16_MICROSTEP:
			HAL_GPIO_WritePin (SM_MODE0_GPIO_Port, SM_MODE0_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin (SM_MODE1_GPIO_Port, SM_MODE1_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin (SM_MODE2_GPIO_Port, SM_MODE2_Pin, GPIO_PIN_SET);
			break;
		case SM_32_MICROSTEP:
			HAL_GPIO_WritePin (SM_MODE0_GPIO_Port, SM_MODE0_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin (SM_MODE1_GPIO_Port, SM_MODE1_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin (SM_MODE2_GPIO_Port, SM_MODE2_Pin, GPIO_PIN_SET);
			break;
		default:
			HAL_GPIO_WritePin (SM_MODE0_GPIO_Port, SM_MODE0_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin (SM_MODE1_GPIO_Port, SM_MODE1_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin (SM_MODE2_GPIO_Port, SM_MODE2_Pin, GPIO_PIN_RESET);
			break;
	}
}

void stepmotor_init(void){
	stepmotor_reset();
	stepmotor_microstep(SM_32_MICROSTEP);
	stepmotor_sleep(SM_ACTIVE);
	stepmotor_enable(SM_DISABLE);
	stepmotor_dir(SM_DIR_P);
    HAL_TIM_Base_Start(&htim4);
}

void stepmotor_step(int steps){
    if(steps>0){
        stepmotor_dir(SM_DIR_P);
        steps_to_go = steps;
    }else{
        stepmotor_dir(SM_DIR_N);
        steps_to_go = -steps;
    }
    sm_busy_flag = 1;
    HAL_TIM_PWM_Start_IT(&htim4,TIM_CHANNEL_3);
}


