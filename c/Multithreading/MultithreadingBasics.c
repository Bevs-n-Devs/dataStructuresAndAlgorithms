#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <pthread.h>
#include <time.h>
#include <unistd.h>

// defines a callback type
typedef void (*Callback)(char*);

// defines a struct to hold the pthread args
typedef struct PThread_args {
    char *str;
    Callback callback;
}PThread_args;

/**
 * Callback function that runs when a thread is finished
 * 
 * @param msg: char array string to print when the thread have completed
 */
void c_alert(char* msg){
    printf("\t--- Finished %s ---\n", msg);
}

/**
 * Gets the current time and formats it
 */
char* get_ctime(){
    time_t timer;
    int buffer_sz = 26;
    char *time_buffer = (char*)calloc(buffer_sz, sizeof(char));

    if (!time_buffer){
        printf("no space for time buffer\n");
        exit;
    }

    time(&timer);
    struct tm* ct = localtime(&timer);
    strftime(time_buffer, buffer_sz, "%a %b %d %H:%M:%S %Y", ct);

    return time_buffer;
}

/**
 * Thread Task to simulate chewing gum
 * 
 * @param arg: void pointer to hold arguments
 */
void* t_chew_gum(void *arg){
    // Casting args as Pthread_args to access
    // the different arguments directly
    PThread_args* args = (PThread_args*)arg;
    char* gum_brand = args->str;
    
    

    for (int i=0;i<5;i++){
        printf("Chewing: %s\t@%s\n", gum_brand, get_ctime());
        sleep(1);
    }

    args->callback((char*)"chewing gum");
    return NULL;
}

/**
 * Thread Task to simulate walking
 * 
 * @param arg: void pointer to hold arguments
 */
void* t_walk_now(void *arg){
    // Casting args as Pthread_args to access
    // the different arguments directly
    PThread_args *args = (PThread_args *)arg;
    char* city = args->str;

    for (int i=0;i<5;i++){
        printf("Walking in %s\t@%s\n", city, get_ctime());
        sleep(2);
    }

    args->callback((char*)"walking");
    return NULL;
}

int main(int argc, char** kwargs){
    printf("--- Testing Multithreading ---\n");
    
    // allocating memory for threads argument structures
    struct PThread_args *args0 = (PThread_args*)calloc(1,sizeof(PThread_args));
    struct PThread_args *args1 = (PThread_args*)calloc(1,sizeof(PThread_args));
    // assigning pthread arguments
    args0->callback = &c_alert;
    args0->str = "Miami";
    args1->callback = c_alert;
    args1->str = "Bazooka";

    // declaring threads
    pthread_t t0, t1;

    // creating thread instances
    pthread_create(&t0,NULL, t_walk_now, args0);
    pthread_create(&t1,NULL, t_chew_gum, args1);

    // join the threads to the main thread, the main thread
    // will not continue until threads end
    pthread_join(t0, NULL);
    pthread_join(t1, NULL);

    // cleanup - deallocating pointers
    free(args0);
    free(args1);

    return 0;
}