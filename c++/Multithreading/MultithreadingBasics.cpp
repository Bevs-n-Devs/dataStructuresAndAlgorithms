#include <windows.h>
#include <iostream>
#include <thread>

void chew_gum(char* gum_brand, void (*callback)(char* msg)){
    for (int i=0;i<5;i++){
        std::cout << "Chewing: " << gum_brand << std::endl;
        // usleep(1000000);
    }
    callback((char*)"chewing gum");
}
void walk_now(char* city, void (*callback)(char* msg)){
    for (int i=0;i<5;i++){
        std::cout << "Walking in " << city << std::endl;
        // usleep(2000000);
    }
    callback((char*)"walking");
}

void alert(char* msg){
    std::cout << "\t--- Finished " << msg << std::endl;
}

int main() {
    std::cout << "--- Testing Multithreading ---" << std::endl;

    // walk_now((char*)"San Francisco", alert);
    std::thread t1(walk_now, (char*)"San Francisco", alert);
    std::thread t2(chew_gum, (char*)"Bazooka", alert);
    t1.join();
    t2.join();
    return 0;
}