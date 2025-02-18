#include <iostream>
#include <thread>
#include <mutex>
#include <semaphore>
#include <condition_variable>

#define BUFFER_SZ 10

// declare mutex
std::mutex buffer_mutex;
// declare semaphores
std::condition_variable emptyBuffer_sem;
std::condition_variable fullBuffer_sem;

int buffer[BUFFER_SZ];
int count = 0;

/**
 * Produces data in the buffer 
 */
void produce(void* arg){
    for(;;){
        int v = rand()%100;
        std::unique_lock lock(buffer_mutex);
        emptyBuffer_sem.wait(lock, []() {return count < BUFFER_SZ;});
        std::cout << "Producing job: " << v << std::endl;
        buffer[count] = v;
        count+=1;
        lock.unlock();
        fullBuffer_sem.notify_one();
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }
}

/**
 * Consumes data in the buffer
 */
void consume(void* arg){
    for(;;){
        std::unique_lock lock(buffer_mutex);
        fullBuffer_sem.wait(lock, []() {return count == BUFFER_SZ;});
        std::cout << "Consuming job: " << buffer[count-1] << std::endl;
        buffer[count-1] = -1;
        count-=1;
        lock.unlock();
        emptyBuffer_sem.notify_one();
        std::this_thread::sleep_for(std::chrono::milliseconds(250));
    }
}

int main(int argc, char** kwargs){
    printf("--- Running Producer-Consumer Problem ---\n");
    
    // initializes threads
    std::thread producer_thread(produce, ((void*)0));
    std::thread consumer_thread(consume, ((void*)0));

    // joins new threads to main thread
    producer_thread.join();
    consumer_thread.join();

    return 0;
}