#ifndef __STEPMOTOR_H
#define __STEPMOTOR_H

#include "sys.h"

void stepmotor_init(void);

void stepmotor_step(int steps);

#define SM_DIR_P GPIO_PIN_SET
#define SM_DIR_N GPIO_PIN_RESET
void stepmotor_dir(GPIO_PinState dir);

void stepmotor_set_speed(u32 speed);

#define SM_FULLSTEP 0x00
#define SM_2_MICROSTEP 0x01
#define SM_4_MICROSTEP 0x02
#define SM_8_MICROSTEP 0x03
#define SM_16_MICROSTEP 0x04
#define SM_32_MICROSTEP 0x05
void stepmotor_microstep(u8 microstep);

#define SM_SLEEP GPIO_PIN_RESET
#define SM_ACTIVE GPIO_PIN_SET
void stepmotor_sleep(GPIO_PinState sleep);

#define SM_ENABLE GPIO_PIN_RESET
#define SM_DISABLE GPIO_PIN_SET
void stepmotor_enable(GPIO_PinState state);

void stepmotor_reset(void);


u8 stepmotor_get_busy_flag(void);
void stepmotor_set_busy_flag(u8 flag)；

int stepmotor_get_current_step(void);
void stepmotor_set_current_step(int step);

u8 stepmotor_get_zero_flag(void);
void stepmotor_set_zero_flag(u8 flag);

void stepmotor_set_zero(void);


#endif


