Objectives
The following are the primary objectives of this experiment:
• To demonstrate VxWorks' priority inversion avoidance mechanisms.
Description
To address the problem of priority inversion, VxWorks provides an additional option
when using mutual exclusion semaphores. This option is SEM_INVERSION_SAFE which
enables a priority inheritance algorithm. This algorithm insures that the task that owns 
a resource executes at the priority of the highest priority task blocked on that resource.
When execution is complete, the task relinquishes the resource and returns to its
normal priority. Therefore, the inheriting task is protected from preemption by an
intermediate priority task. This option must be used in conjunction with
SEM_Q_PRIORITY:
semId = semMCreate(SEM_Q_PRIORITY | SEM_INVERSION_SAFE); 