 /*@file		signals.c
  *@breif       vxWorks Signals
 * @author		Sandeep Pratap Singh
 * @date		10 Aug 2018
 */
/* includes */
#include "vxWorks.h"
#include "sigLib.h"
#include "taskLib.h"
#include "stdio.h" 
/* function prototypes */
void catchSIGINT(int);
void sigCatcher(void);

/* globals */
#define NO_OPTIONS 0
#define ITER1 100
#define LONG_TIME 1000000
#define HIGHPRIORITY 100
#define LOWPRIORITY 101
int ownId;
void sigGenerator(void) /* task to generate the SIGINT signal */
{
	int i, j, taskId;
	STATUS taskAlive;
	if ((taskId = taskSpawn("signal", 100, 0x100, 20000, (FUNCPTR) sigCatcher,
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0)) == ERROR)
		printf("taskSpawn sigCatcher failed\n");
	ownId = taskIdSelf(); /* get sigGenerator's task id */
	taskDelay(30); /* allow time to get sigCatcher to run */
	for (i = 0; i < ITER1; i++) {
		if ((taskAlive = taskIdVerify(taskId)) == OK) {
			printf("+++++++++++++++++++++++++++++++SIGINT sinal generated\n");
			kill(taskId, SIGINT); /* generate signal */
			/* lower sigGenerator priority to allow sigCatcher to run */
			taskPrioritySet(ownId, LOWPRIORITY);
		} else
			/* sigCatcher is dead */
			break;
	}
	printf("\n***************sigGenerator Exited***************\n");
}
void sigCatcher(void) /* task to handle the SIGINT signal */
{
	struct sigaction newAction;
	int i, j;
	newAction.sa_handler = catchSIGINT; /* set the new handler */
	sigemptyset(&newAction.sa_mask); /* no other signals blocked */
	newAction.sa_flags = NO_OPTIONS; /* no special options */
	if (sigaction(SIGINT, &newAction, NULL) == -1)
		printf("Could not install signal handler\n");
	for (i = 0; i < ITER1; i++) {
		for (j = 0; j < LONG_TIME; j++)
			;
		printf("Normal processing in sigCatcher\n");
	}

	printf("\n+++++++++++++++sigCatcher Exited+++++++++++++++\n");
}
void catchSIGINT(int signal) /* signal handler code */
{
	printf("-------------------------------SIGINT signal caught\n");
	/* increase sigGenerator priority to allow sigGenerator to run */
	taskPrioritySet(ownId, HIGHPRIORITY);
}
