#include "Tasks.h"

int (*tasks[MAX_TASK_NUMBER])();
unsigned short times[MAX_TASK_NUMBER];
uint8_t taskNumber = 0;

int Tasks_AddTask(int(*task)(), int time)
{
	for (int i = 0; i < MAX_TASK_NUMBER; i++)
	{
		if (tasks[i] == 0)
		{
			tasks[i] = task;
			times[i] = time;
			taskNumber++;
			return TaskId(i);
		}
	}
	return 0;
}

int Tasks_DelTask(int taskId)
{
	if (tasks[taskId - 1])
	{
		//存在任务
		tasks[taskId - 1] = 0;
		taskNumber--;
	}
}
int Tasks_Run()
{
	if (!taskNumber)
	{
		//减少运算量
		return 0;
	}
	for (int i = 0; i < MAX_TASK_NUMBER; i++)
	{
		if (tasks[i] != 0)
		{
			if (!(--times[i]))
			{
				gReturnCode = tasks[i]();
				tasks[i] = 0;
				taskNumber--;
				return TaskId(i);
			}
		}
	}
	return 0;
}