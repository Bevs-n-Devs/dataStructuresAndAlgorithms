#include <iostream>
#include <Windows.h>
#include <thread>

void threadFunction(int id) {
    std::cout << "Hello from thread " << id << std::endl;
}

int main() {
    thread t1(threadFunction, 1);
    thread t2(threadFunction, 2);

    t1.join();
    t2.join();

    return 0;
}