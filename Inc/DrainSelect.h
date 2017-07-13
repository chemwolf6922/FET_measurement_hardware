#ifndef __DRAIN_SELECT_H
#define __DRAIN_SELECT_H

#include "sys.h"

#define Drain1 DRAIN1_Pin
#define Drain2 DRAIN2_Pin
#define Drain3 DRAIN3_Pin
#define Drain4 DRAIN4_Pin
void drain_select(u16 drain);

void drain_disconnect_all(void);

#endif


