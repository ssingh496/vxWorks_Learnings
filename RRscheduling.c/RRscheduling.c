 /*@file		RRScheduling.c
  *@breif       round robin scheduling
 * @author		Sandeep Pratap Singh
 * @date		10 Aug 2018
 */

/* includes */
#include "vxWorks.h"
#include "taskLib.h"
#include "kernelLib.h"
#include "sysLib.h"
#include "logLib.h"
#include "stdio.h"
/* function prototypes */
void taskOne(void);
void taskTwo(void);
void taskThree(void);
/* globals */
#define ITER1 100
#define ITER2 10
#define PRIORITY 101
#define TIMESLICE sysClkRateGet()
#define LONG_TIME 1000000
void sched(void) /* function to create the three tasks */
{
int taskIdOne, taskIdTwo, taskIdThree;
if(kernelTimeSlice(TIMESLICE) == OK) /* turn round-robin on */
 printf("\n\n\n\n\t\t\tTIMESLICE = %d seconds\n\n\n", TIMESLICE/60);
/* spawn the three tasks */
if((taskIdOne = taskSpawn("task1",PRIORITY,0x100,20000,(FUNCPTR)taskOne,0,0,0,0,0,0,0,
 0,0,0)) == ERROR)
 printf("taskSpawn taskOne failed\n");
if((taskIdTwo = taskSpawn("task2",PRIORITY,0x100,20000,(FUNCPTR)taskTwo,0,0,0,0,0,0,0,
 0,0,0)) == ERROR)
 printf("taskSpawn taskTwo failed\n");
if((taskIdThree =
taskSpawn("task3",PRIORITY,0x100,20000,(FUNCPTR)taskThree,0,0,0,0,0,0,0,
 0,0,0)) == ERROR)
 printf("taskSpawn taskThree failed\n");
}
void taskOne(void)
{
int i,j;
for (i=0; i < ITER1; i++)
 {
 for (j=0; j < ITER2; j++) 
 logMsg("\n",0,0,0,0,0,0); /* log messages */
 for (j=0; j < LONG_TIME; j++); /* allow time for context switch */
 }
}
void taskTwo(void)
{
int i,j;
for (i=0; i < ITER1; i++)
 {
 for (j=0; j < ITER2; j++)
 logMsg("\n",0,0,0,0,0,0); /* log messages */
 for (j=0; j < LONG_TIME; j++); /* allow time for context switch */
 }
}
void taskThree(void)
{
int i,j;
for (i=0; i < ITER1; i++)
 {
 for (j=0; j < ITER2; j++)
 logMsg("\n",0,0,0,0,0,0); /* log messages */
 for (j=0; j < LONG_TIME; j++); /* allow time for context switch */
 }
} 
