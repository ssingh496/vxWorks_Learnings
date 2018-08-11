Objectives
The following are the primary objectives of this experiment:
• To demonstrate the use of VxWorks round-robin task scheduling facilities.
Description
• Round-Robin Scheduling
A round-robin scheduling algorithm attempts to share the CPU fairly among all
ready tasks of the same priority. Without round-robin scheduling, when multiple
tasks of equal priority must share the processor, a single task can usurp the
processor by never blocking, thus never giving other equal priority tasks a
chance to run. 
Round-robin scheduling achieves fair allocation of the CPU to tasks of the same
priority by an approach known as time slicing. Each task executes for a defined
interval or time slice; then another task executes for an equal interval, in
rotation. The allocation is fair in that no task of a priority group gets a second
slice of time before the other tasks of a group are given a slice.
Round-robin scheduling can be enabled with routine kernelTimeSlice(), which
takes a parameter for a time slice, or interval. The interval is the amount of time
each task is allowed to run before relinquishing the processor to another equal
priority task.