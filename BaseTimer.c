#include "BaseTimer.h"

//��ͣ��ʱ����������ʱ��
static uint8_t sLock = 1;
volatile int16_t gBaseTimer_RunTimes;
static int16_t sBaseTimer_RunCount = 0;

//����һ��ʱ�䵥Ԫ ��ʱ��仯�����ô˽ӿ�
void BaseTimer_RunAUnit()
{

    if (sBaseTimer_RunCount || sLock)
    {
        return;
    }
    gBaseTimer_RunTimes++;
}
void BaseTimer_Reset()
{
    sBaseTimer_RunCount = 0;
    gBaseTimer_RunTimes = 0;
}
void BaseTimer_Start()
{
    if (sBaseTimer_RunCount)
    {
        gBaseTimer_RunTimes = sBaseTimer_RunCount;
        sBaseTimer_RunCount = 0;
    }
    sLock = 0;
}
void BaseTimer_Stop()
{
    sLock = 1;
    BaseTimer_Reset();
}
void BaseTimer_Pause()
{
    sBaseTimer_RunCount = gBaseTimer_RunTimes;
    gBaseTimer_RunTimes = 0;
}