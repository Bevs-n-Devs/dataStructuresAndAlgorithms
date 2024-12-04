from threading import Thread
from time import sleep
from datetime import datetime as dt

"""
Multithreading:
Uses multiple threads within a single process.

Concurrency: Achieved by interleaving tasks, but only one thread executes
Python bytecode at a time due to the Global Interpreter Lock (GIL).

Multithreading can be thought of as a really good time management tool for
running code. On a single core, only one thread can run at a time. However 
when a thread sleeps, another thread is picked up and immediately ran while 
the first thread is not executing any logic. There is no time wasted between 
threads, making code execute faster by using time efficiently. 
"""

def print_msg(msg: str) -> None:
    """
    Will be the callback function when a thread's function has 
    finished executing.

    @param msg: the message to include in the callback print statement
    @type msg: str
    """
    print(f"\t--- Finished {msg} ---")

def walk_now(callback: callable) -> None:
    """
    Mimics walking for thread 1

    @param callback: a function to call once this function is ready to finish
    @type callback: callable
    """
    for i in range(6):
        print(f"Step at time: {dt.now().strftime('%H:%M:%S')}")
        # sleeps for 1s after stepping
        sleep(1)

    callback("Walking")

def chew_gum(callback: callable) -> None:
    """
    Mimics chewing gum for thread 2
    
    @param callback: a function to call once this function is ready to finish
    @type callback: callable
    """
    for i in range(5):
        # sleeps for 2s before chewing
        sleep(2)
        print(f"Chew at time: {dt.now().strftime('%H:%M:%S')}")

    callback("Chewing")

# Creating Threads
# target points to the function to run for the thread
# args points to different arguments that will be sent
# to the thread's target function
# NOTE: when passing the target function we point to it
# but not calling it, so the parenthesis after the function
# name are NOT to be included.
t1 = Thread(target=walk_now,args=(print_msg,))
t2 = Thread(target=chew_gum,args=(print_msg,))

# The threads start with the start method
t1.start()
t2.start()

# To stop the main thread from finishing before these threads
# have completed, the join method is used for each thread
t1.join()
t2.join()