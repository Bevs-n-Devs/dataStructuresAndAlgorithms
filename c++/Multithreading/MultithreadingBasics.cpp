#include <iostream>
#include <thread>   // needed for threads
#include <unistd.h> // needed for sleep
#include <ctime>    // needed for current time
#include <string.h>

/**
 * Callback function that runs when a thread is finished
 * 
 * @param msg: char array string to print when the thread have completed
 */
void c_alert(char* msg){
    std::cout << "\t--- Finished " << msg << " ---" << std::endl;
}

/**
 * Gets the current time
 * 
 * @return formatted time stamp
 */
// char* get_ctime(){
//     sleep(1);
//     return cln_ct;
// }

/**
 * Thread Task to simulate chewing gum
 * 
 * @param gum_brand: char pointer string
 * @param callback: function to call once the thread has completed
 */
void t_chew_gum(char* gum_brand, void (*callback)(char* msg)){
    for (int i=0;i<5;i++){
        std::time_t t = std::time(0);
        char* ct = std::ctime(&t);
        char* cln_ct = strtok(ct, "\n");
        std::cout << "Chewing: " << gum_brand << "\t@" << cln_ct << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    callback((char*)"chewing gum");
}

/**
 * Thread Task to simulate walking
 * 
 * @param city: char pointer string
 * @param callback: function to call once the thread has completed
 */
void t_walk_now(char* city, void (*callback)(char* msg)){
    for (int i=0;i<5;i++){
        std::time_t t = std::time(0);
        char* ct = std::ctime(&t);
        char* cln_ct = strtok(ct, "\n");
        std::cout << "Walking in " << city << "\t@" << cln_ct << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(2));
    }

    callback((char*)"walking");
}



int main() {
    std::cout << "--- Testing Multithreading ---" << std::endl;
    
    // creates the thread instances 
    std::thread t1(t_walk_now, (char*)"Miami", c_alert);
    std::thread t2(t_chew_gum, (char*)"Bazooka", c_alert);

    // join the threads to the main thread, the main thread
    // will not continue until threads end
    t1.join();
    t2.join();

    return 0;
}