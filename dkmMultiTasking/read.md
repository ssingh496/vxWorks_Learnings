Objectives
The following are the primary objectives of this experiment:
• To teach the student how to initiate multiple processes using Vxworks tasking
routines.
Description
Multitasking creates the appearance of many threads of execution running concurrently
when, in fact, the kernel interleaves their execution on a basis of ascheduling algorithm.
Each apparently independent program is called a task. Each task has its own context,
which is the CPU environment and system resources that the task sees each time it is
scheduled to run by the kernel.
On a context switch, a task's context is saved in the Task Control Block(TCB). A task's 
context includes:
• a thread of execution, that is, the task's program counter
• the CPU registers and floating-point registers if necessary
• a stack of dynamic variables and return addresses of function calls
• I/O assignments for standard input, output, error
• a delay timer
• a timeslice timer
• kernel control structures
• signal handlers
• debugging and performance monitoring values
1. Task Creation and Activation
The routine taskSpawn creates the new task context, which includes allocating and
setting up the task environment to call the main routine(an ordinary subroutine) with the
specified arguments. The new task begins at the entry to the specified routine.
The arguments to taskSpawn() are the new task's name(an ASCII string), priority, an
"options" word(also hex value), stack size(int), main routine address(also main routine
name), and 10 integer arguments to be passed to the main routine as startup parameters.
2. Syntax
id = taskSpawn(name,priority,options,stacksize,function, arg1,..,arg10); 