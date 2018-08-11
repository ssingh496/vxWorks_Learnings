
 /* @file		multiTasking.c
 * @brief       MultiTasking tasks creation demo
 * @author		Sandeep Pratap Singh
 * @date		10 Aug 2018
 */

/* includes */
#include <vxWorks.h>
#include <errnoLib.h>
#include <stdio.h>
#include <string.h>
#include <taskLib.h>

#define ITERATIONS 10
void printFunc(void);
void spawn_ten();
void spawn_ten() /* Subroutine to perform the spawning */
{
	int i, taskId;
	for (i = 0; i < ITERATIONS; i++) /* Creates ten tasks */
	{
		taskId = taskSpawn("tprint", 90, 0x100, 2000,(FUNCPTR) printFunc, (_Vx_usr_arg_t)0, 0, 0, 0, 0, 0,0, 0, 0, 0);
		if (taskId == -1) 
		{
			printf("task not created\n");
		}
	}
	return;
}
void printFunc(void) /* Subroutine to be spawned */
{
	printf("Hello, I am task %d\n", taskIdSelf()); /* Print task Id */
}
