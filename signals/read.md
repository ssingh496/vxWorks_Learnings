Objectives
The following are the primary objectives of this experiment:
• To demonstrate VxWorks' implementation of POSIX signal routines. 
Description
The signal facility provides a set of 31 distinct signals(see VxWorks Manual). A signal
can be raised by calling kill(), which is analogous to an interrupt or hardware exception.
A signal is bound to a particular signal with sigaction(). While the signal handler is
running, other signals are blocked from delivery. Tasks can block the occurence of
certain signals with sigprocmask(); if a signal is blocked when it is raised, its handler
routine will be called when the signal becomes unblocked.
Signal handlers are typically defined as:
void sigHandlerFunction(int signalNumber)
{
.............. /* signal handler code */
..............
..............
}
where signalNumber is the signal number for which sigHandlerFunction is to be invoked
for.
The sigaction function installs signal handlers for a task:
• int sigaction(int signo, const struct sigaction *pAct, struct sigaction *pOact)
A data structure of type struct sigaction holds the handler information. The sigaction
call has three parameters: the signal number to be caught, a pointer to the new handler
structure(of type struct sigaction), and a pointer to the old structure(also of type struct
sigaction). If the program does not need the value of the old handler(*pOact), pass a
NULL pointer for *pOact.
To direct a specific signal to a specific task, the kill(int, int) call is made where the first
argument the task id to send signal to, and the second argument is the signal to send to
the task . 