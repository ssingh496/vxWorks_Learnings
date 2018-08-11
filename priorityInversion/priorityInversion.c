 /*@file		priorityInversion.c
  *@breif       priority Inversion
 * @author		Sandeep Pratap Singh
 * @date		10 Aug 2018
 */

/* includes */
#include "vxWorks.h"
#include "taskLib.h"
#include "semLib.h"
/* function prototypes */
void prioHigh(void);
void prioMedium(void);
void prioLow(void);
/* globals */
#define ITER 3
#define HIGH 102 /* high priority */
#define MEDIUM 103 /* medium priority */
#define LOW 104 /* low priority */
#define LONG_TIME 1000000
SEM_ID semMutex;
void inversion(void) /* function to create the three tasks */
{
	int i, low, medium, high;
	printf(
			"\n\n....................##RUNNING##.........................\n\n\n");
	/* create semaphore */
	semMutex = semMCreate(SEM_Q_PRIORITY); /* priority based semaphore */
	/* spawn the three tasks */
	if ((low = taskSpawn("task1", LOW, 0x100, 20000, (FUNCPTR) prioLow, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0)) == ERROR)
		printf("taskSpawn prioHigh failed\n");
	if ((medium = taskSpawn("task2", MEDIUM, 0x100, 20000, (FUNCPTR) prioMedium,
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0)) == ERROR)
		printf("taskSpawn prioMedium failed\n");
	if ((high = taskSpawn("task3", HIGH, 0x100, 20000, (FUNCPTR) prioHigh, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0)) == ERROR)
		printf("taskSpawn prioLow failed\n");
}
void prioLow(void) {
	int i, j;
	for (i = 0; i < ITER; i++) {
		semTake(semMutex, WAIT_FOREVER); /* wait indefinitely for semaphore */
		printf("Low priority task locks semaphore\n");
		for (j = 0; j < LONG_TIME; j++)
			;
		printf("Low priority task unlocks semaphore\n");
		semGive(semMutex); /* give up semaphore */
	}
	printf(
			"..........................................Low priority task exited\n");
}
void prioMedium(void) {
	int i;
	taskDelay(20);/* allow time for task with the lowest priority to seize semaphore */
	for (i = 0; i < LONG_TIME * 10; i++) {
		if ((i % LONG_TIME) == 0)
			printf("Medium task running\n");
	}
	printf(
			"------------------------------------------Medium priority task exited\n");
}
void prioHigh(void) {
	int i, j;
	taskDelay(30);/* allow time for task with the lowest priority to seize semaphore */
	for (i = 0; i < ITER; i++) {
		printf("High priority task trys to lock semaphore\n");
		semTake(semMutex, WAIT_FOREVER); /* wait indefinitely for semaphore */
		printf("High priority task locks semaphore\n");
		for (j = 0; j < LONG_TIME; j++)
			;
		printf("High priority task unlocks semaphore\n");
		semGive(semMutex); /* give up semaphore */
	}
	printf(
			"..........................................High priority task exited\n");
}
