/*************************************************************************          
    * countingSemaphore.c : Program to show how Binary Semaphore works.    *   
    *                                                                    *   
    * Author:  Sandeep P, Singh                                          *   
    *                                                                    *   
    * Purpose:  Demonstration of a simple program,						 *
	* to show how Counting Semaphore works. Used VxWork Enviroment    							 *
    *                                                                    *   
    * Usage:                                               				 *   
    *      Runs the program and the task runs synchronously with counting*
    *      semaphore (semSync).Also created a new counting semaphore semComplete*
	* 	   which is there to syn when tasks finish
    * (VxWorks Env)*      			    
    *********************************************************************/  
	
	/* includes */
#include "vxWorks.h"
#include "taskLib.h"
#include "semLib.h"
#include "stdio.h"

/* function Declaration */
void taskOne(void);
void taskTwo(void);

#define NO_WAIT		0
#define WAIT_FOREVER	(-1U)
#define COUNTING      4

/* globals variables*/
#define ITERATION 10
SEM_ID semSync,semComplete;
int global = 0;

void binary(void)
{
int tidOne, tidTwo;

//TASK being created will blocking count numbers
semSync = semCCreate(SEM_EVENTSEND_ERR_NOTIFY, 0);
semComplete = semCCreate(SEM_EVENTSEND_ERR_NOTIFY, COUNTING);


/* spawn the two tasks */
tidOne = taskSpawn("t1",90,0x100,2000,(FUNCPTR)taskOne,0,0,0,0,0,0,0,0,0,0);
tidTwo = taskSpawn("t2",90,0x100,2000,(FUNCPTR)taskTwo,0,0,0,0,0,0,0,0,0,0);
}


void taskOne(void)
{
int i;
for (i=0; i < ITERATION; i++)
	{
	/* wait indefinitely for semaphore */
	semTake(semSync, WAIT_FOREVER);
	printf("I am taskOne and global = %d......................\n", ++global);
	/* give up semaphore */
	semGive(semSync); 
	} 

int j =0;

/*Waiting to get the semaphore for the count */
semTake(semComplete, j);
printf ("Counting Sempahure is being taken %d times\n", j);

}

void taskTwo(void)
{
int i;
/* Give up semaphore(Make tasks run synchronously) */
semGive(semSync); 
for (i=0; i < ITERATION; i++)
	{
	/* wait indefinitely for semaphore */
	semTake(semSync, WAIT_FOREVER); 
	printf("I am taskTwo and global = %d----------------------\n", ++global);
	global -=2;
	 /* give up semaphore */
	semGive(semSync);
	} 

/*Giving the semaphore for the count */
for (int j =0; j<COUNTING; j++){
	
	semGive(semComplete);
}
printf ("Counting Sempahure is being Given %d times\n", COUNTING);

}
