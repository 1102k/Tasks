#ifndef __BASE_TIMER_H__
#define __BASE_TIMER_H__
#include "stdint.h"
extern volatile int16_t gBaseTimer_RunTimes;

void BaseTimer_RunAUnit();
void BaseTimer_Reset();
void BaseTimer_Start();
void BaseTimer_Stop();
void BaseTimer_Pause();

#endif // !__BASE_TIMER_H__
