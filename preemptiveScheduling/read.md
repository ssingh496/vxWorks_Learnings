Objectives
The following are the primary objectives of this experiment:
• To demonstrate the use of VxWorks preemptive priority based task scheduling
facilities.
Description
• Preemptive Priority Based Scheduling
With a preemptive priority based scheduler, each task has a priority and the
kernel insures that the CPU is allocated to the highest priority task that is ready 
to run. This scheduling method is preemptive in that if a task that has a higher
priority than the current task becomes ready to run, the kernel immediately
saves the current tasks's context and switches to the context of the higher
priority task.
The Wind kernel has 256 priority levels(0-255). Priority 0 is the highest and
priority 255 is the lowest. Tasks are assigned a priority when created; however,
while executing, a task can change its priority using taskPrioritySet(). 