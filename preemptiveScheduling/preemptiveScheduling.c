 /*@file		preemptiveScheduling.c
  *@breif       preemptive scheduling
 * @author		Sandeep Pratap Singh
 * @date		10 Aug 2018
 */

/* includes */
#include "vxWorks.h"
#include "taskLib.h"
#include "logLib.h"
/* function prototypes */
void taskOne(void);
void taskTwo(void);
void taskThree(void);
/* globals */
#define ITER1 100
#define ITER2 1
#define LONG_TIME 1000000
#define HIGH 100 /* high priority */
#define MID 101 /* medium priority */
#define LOW 102 /* low priority */ 
#define TIMESLICE sysClkRateGet()
void sched(void) /* function to create the two tasks */
{
	int taskIdOne, taskIdTwo, taskIdThree;
	if (kernelTimeSlice(0) == OK) /* turn round-robin off */
		printf("\n\n\n\n\t\t\tTIMESLICE = %d seconds\n\n\n", TIMESLICE / 60);
	printf("\n\n\n\n\n");
	/* spawn the three tasks */
	if ((taskIdOne = taskSpawn("task1", LOW, 0x100, 20000, (FUNCPTR) taskOne, 0,
			0, 0, 0, 0, 0, 0, 0, 0, 0)) == ERROR)
		printf("taskSpawn taskOne failed\n");
	if ((taskIdTwo = taskSpawn("task2", MID, 0x100, 20000, (FUNCPTR) taskTwo, 0,
			0, 0, 0, 0, 0, 0, 0, 0, 0)) == ERROR)
		printf("taskSpawn taskTwo failed\n");
	if ((taskIdThree = taskSpawn("task3", HIGH, 0x100, 20000,
			(FUNCPTR) taskThree, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)) == ERROR)
		printf("taskSpawn taskThree failed\n");
}
void taskOne(void) {
	int i, j;
	for (i = 0; i < ITER1; i++) {
		for (j = 0; j < ITER2; j++)
			logMsg("\n", 0, 0, 0, 0, 0, 0);
		for (j = 0; j < LONG_TIME; j++)
			;
	}
}
void taskTwo(void) {
	int i, j;
	for (i = 0; i < ITER1; i++) {
		for (j = 0; j < ITER2; j++)
			logMsg("\n", 0, 0, 0, 0, 0, 0);
		for (j = 0; j < LONG_TIME; j++)
			;
	}
}
void taskThree(void) {
	int i, j;
	for (i = 0; i < ITER1; i++) {
		for (j = 0; j < ITER2; j++)
			logMsg("\n", 0, 0, 0, 0, 0, 0);
		for (j = 0; j < LONG_TIME; j++)
			;
	}
}
