from multiprocessing import Process
from datetime import datetime as dt 
import time

"""
Multiprocessing: 
Uses multiple processes, each with its own Python interpreter and memory space.

This form of concurrency is true parallelism i.e. two or more things at the same
time. This is possible by using multicore systems; multicore means a processor 
has more than one central processing unit (2 brains are better than 1).

The downside to multiprocessing is that the memory is not shared between processes,
this is referring to the variables used in the code itself. There is memory allocated 
to each process, so the goal is to treat processes as different "entities" or "people" 
alltogether.
"""

def task(id: int) -> None:
    """
    Example task to run for each process that loops 3 times

    @param id: the process id
    @type id: int
    """
    for i in range(3):
        print(f"I'm running in process {id} @ {dt.now().strftime('%H:%M:%S')}")
        time.sleep(1)


"""
Key Points for Windows
Use if __name__ == "__main__"::

On Windows, multiprocessing uses the "spawn" start method by default, which re-imports the main script in child processes.
Without the if __name__ == "__main__": guard, this can lead to infinite process creation.
Avoid Mutable Global State:

Changes to variables in one process won't reflect in others due to separate memory spaces.
Use multiprocessing.Manager or shared objects if inter-process communication is needed.
"""
if __name__ == '__main__': 
    # Creating a list to hold the processes
    processes = []

    # Creating 3 processes
    for i in range(3):
        # Instantiating a Process object with a target
        # pointing to a function to run, and a tuple of 
        # arguments (if necessary)
        # NOTE: The function should not be called, but simply pointed to, so
        # the parenthesis after the function name should not be included. The 
        # arguments for that function are passed in a tuple; if only 1 it must be
        # followed by a comma to indicate a tuple object
        p = Process(target=task, args=(i+1,))
        # The process is started
        p.start()
        # the process is added to the processes list
        processes.append(p)

    # After starting the processes, join is called
    # so the the code does not exit until all processes
    # have completed
    for p in processes:
        p.join()

