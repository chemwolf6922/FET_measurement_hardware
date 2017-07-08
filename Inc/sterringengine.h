#ifndef __STEAR_ENGINE_H
#define __STEAR_ENGINE_H

#include "sys.h"

void sterringengine_init(void);

#define SE_CH1 TIM_CHANNEL_1
#define SE_CH2 TIM_CHANNEL_2
#define SE_CH3 TIM_CHANNEL_3
void sterringengine_rotate(u32 channel,u32 position);

//todo:find the right value for each position
#define SE_CH1_ENABLE
#define SE_CH1_DISABLE
#define SE_CH2_ENABLE
#define SE_CH2_DISABLE
#define SE_CH3_ENABLE
#define SE_CH3_DISABLE
void sterringengine_action(u32 CH1_action,u32 CH2_action,u32 CH3_action);

#endif

