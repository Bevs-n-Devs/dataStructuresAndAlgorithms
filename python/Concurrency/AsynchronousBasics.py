import asyncio

"""
Asynchronous : 
Uses a single-threaded, event-driven model to run multiple tasks concurrently.

Concurrency: Achieved by non-blocking I/O operations, allowing other tasks to 
run while waiting.

NOTE : Functions that utilize async features or call async coroutines, have to
be preceded with a "async" declaration; making them coroutines. 

NOTE : The await keyword can only be used on awaitable objects/methods, so 
time.sleep cannot be used. Hence asyncio.sleep is used.
"""

async def task(id: int) -> None:
    """
    Serves as a async task to execute

    @param id: the id number for the task executing this coroutine
    @type id: int
    """
    print(f"Task {id} is running.")
    # when this sleep is called, another coroutine/task can run
    # while this one is awaiting sleep to complete
    await asyncio.sleep(1)
    print(f"Task {id} is finished.")

async def main() -> None:
    """
    Creates the async tasks to execute
    """

    # There are two approaches to async runs:
    # Apprach 1 : Creating indivual tasks then running
    # each one
    
    # Creating a list of tasks
    tasks = []

    # Creating 3 tasks in a loop
    for i in range(3):
        # when creating tasks, they are called so arguments
        # can be passed in at creation
        tasks.append(asyncio.create_task(task(i+1)))

    # Now the tasks are awaited one by one
    for t in tasks:
        await t
    
    # Approach 2 : Running in batches, where gather is called
    # to execute all the tasks explicitly called out with 
    # arguments (if applicable)
    # batch = asyncio.gather(task(1), task(2), task(3))
    # await batch

asyncio.run(main())