#ifndef __TASKS_H__
#define __TASKS_H__
#include "stdint.h"

#define MAX_TASK_NUMBER 10
#define TaskId(n)   (n + 1)

int gReturnCode = 0;

int Tasks_AddTask(int(*task)(), int time);
int Tasks_DelTask(int taskId);
int Tasks_Run();

#endif // !__TASKS_H__
