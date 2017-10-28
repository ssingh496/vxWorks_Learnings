/*************************************************************************          
    * msgQ.c : Program to show how MsgQ works.    *   
    *                                                                    *   
    * Author:  Sandeep P, Singh                                          *   
    *                                                                    *   
    * Purpose:  Demonstration of a simple program,						 *
	* to show how MSGQ works. Used VxWork Enviroment    				 *			 *
    *                                                                    *   
    * Usage:                                               				 *   
    *      Runs the program and the task will send a recieve message     *
	*      with easch other over MsgQ. Refer MsgQ docummentation in 
    * (VxWorks Env)*      			    
    *********************************************************************/  
	
	
#include "vxWorks.h"
#include "msgQLib.h"
#include <taskLib.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_MESSAGES 100 
#define MAX_MESSAGE_LENGTH 250000


MSG_Q_ID mesgQueueId;

void message(void) 
{
	
int taskIdOne, taskIdTwo;
/* create message queue */
if ((mesgQueueId = msgQCreate(MAX_MESSAGES,MAX_MESSAGE_LENGTH,MSG_Q_FIFO))
 == NULL)
	printf("msgQCreate in failed\n");
/* spawn the two tasks that will use the message queue */
if((taskIdOne = taskSpawn("t1",100,VX_FP_TASK,500000,(FUNCPTR)taskOne,0,0,0,0,0,0,0,
 0,0,0)) == ERROR)
	printf("taskSpawn taskOne failed\n");
if((taskIdTwo = taskSpawn("t2",1,VX_FP_TASK,500000,(FUNCPTR)taskTwo,0,0,0,0,0,0,0,
 0,0,0)) == ERROR)
	printf("taskSpawn taskTwo failed\n");
}


void taskOne(void) 
{
	char message[MAX_MESSAGE_LENGTH]="Received message from taskOne";
	while (1)
	{
		for (int i=0; i<100;i++)
		{
			
		if ((msgQSend(mesgQueueId, message, MAX_MESSAGE_LENGTH, WAIT_FOREVER,
		MSG_PRI_NORMAL)) == ERROR)
			printf("msgQSend in taskOne failed\n");
		}
		taskDelay(5000);
	}
}


void taskTwo(void) 

{
char msgBuf[MAX_MESSAGE_LENGTH];
	while (1) 
	{
		if (msgQReceive(mesgQueueId, msgBuf, MAX_MESSAGE_LENGTH,
				WAIT_FOREVER) == ERROR)
			printf("msgQReceive in taskTwo failed\n");
		else
			printf("taskTwo %s\n", msgBuf);
	}


}
