
Demostration of MsgQ


MsgQ documentation :

msgQLib - message queue library

ROUTINES

msgQCreate( ) - create and initialize a message queue
msgQDelete( ) - delete a message queue
msgQSend( ) - send a message to a message queue
msgQReceive( ) - receive a message from a message queue
msgQNumMsgs( ) - get the number of messages queued to a message queue
DESCRIPTION

This library contains routines for creating and using message queues, the primary intertask communication mechanism within a single CPU. Message queues allow a variable number of messages (varying in length) to be queued in first-in-first-out (FIFO) order. Any task or interrupt service routine can send messages to a message queue. Any task can receive messages from a message queue. Multiple tasks can send to and receive from the same message queue. Full-duplex communication between two tasks generally requires two message queues, one for each direction.

To provide message queue support for a system, VxWorks must be configured with the INCLUDE_MSG_Q component.

Source:
http://www.vxdev.com/docs/vx55man/vxworks/ref/msgQLib.html
Refer : VxWork Programmer Developement Guide