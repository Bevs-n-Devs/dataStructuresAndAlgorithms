#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

// The compiler did not like this value as 
// a constant variable at the global level
#define BUFFER_SZ 10

#define nullptr ((void*) 0)

typedef struct QueueNode{
    int val;
    struct QueueNode *next;
}QueueNode;

QueueNode* createQueueNode(int val){
    QueueNode *qn = (QueueNode*)malloc(sizeof(QueueNode));
    if(!qn) {
        printf("Failed to allocate memory!\n");
        return nullptr;
    }

    qn->val = val;
    qn->next = nullptr;
    return qn;
}

typedef struct Queue{
    int length;
    int capacity;
    QueueNode *front;
    QueueNode *back;
}Queue;

Queue* createQueue(){
    Queue *q = (Queue*)malloc(sizeof(Queue));
    if(!q) printf("Failed to allocate memory!\n");
    q->front = q->back = nullptr;
    q->length = 0;
    q->capacity = BUFFER_SZ;
    return q;
}

bool empty(Queue* q) { return q->length == 0; }

void printQueue(Queue* q) {

    if (empty(q)) {
        printf("NULL");
        return;
    }

    printf("%d", q->front->val);
    QueueNode *tmp = q->front->next;
    while(tmp){
        printf("->%d", tmp->val);
        tmp = tmp->next;
    }

    printf("->NULL\n");
}

bool enqueue(Queue* q, int val) {
    if (q->length == q->capacity) return false;
    
    QueueNode* n = createQueueNode(val);
    if (!n) return false;

    if (empty(q)) q->front = q->back = n;
    else {
        q->back->next = n;
        q->back = n;
    }
    
    q->length+=1;
    return true;
}

int dequeue(Queue* q){
    if (empty(q)) return -1;

    int val = q->front->val;
    QueueNode * tmp = q->front;
    q->front = tmp->next;
    free(tmp);
    q->length-=1;
    return val;
}

pthread_t producer_thread, consumer_thread;
pthread_mutex_t buffer_mutex;
sem_t sem_occupied, sem_empty;
// Queue *buffer;
int buffer[BUFFER_SZ];
int count = 0;

/**
 * Produces data in the buffer 
 */
void* produce(void* arg){
    printf("Running Producer\n");
    while(1){
        sem_wait(&sem_empty);
        pthread_mutex_lock(&buffer_mutex);
        int v = rand()%100;
        printf("Producing job: %d\n", v);
        buffer[count] = v;
        count+=1;
        usleep(500000);
        pthread_mutex_unlock(&buffer_mutex);
        sem_post(&sem_occupied);
    }
    return NULL;
}

/**
 * Consumes data in the buffer
 */
void* consume(void* arg){
    printf("Running Consumer\n");
    while(1){
        sem_wait(&sem_occupied);
        pthread_mutex_lock(&buffer_mutex);

        printf("Consuming job %d\n", buffer[10-count]);
        buffer[10-count] = -1;
        count-=1;
        usleep(500000);
         
        pthread_mutex_unlock(&buffer_mutex);
        sem_post(&sem_empty);
    }
    return NULL;
}


int main(int argc, char** kwargs){
    printf("--- Running Producer-Consumer Problem ---\n");
    // buffer = createQueue();
    
    // initializes mutex
    pthread_mutex_init(&buffer_mutex, NULL);
    // initializes semaphores
    // sem_init(_semaphore_ptr, _process, _initial_value)
    sem_init(&sem_empty, 0, 10);
    sem_init(&sem_occupied, 0, 0); 

    pthread_create(&consumer_thread, NULL, consume, NULL);
    pthread_create(&producer_thread, NULL, produce, NULL);
    
    
    pthread_join(producer_thread, NULL);
    pthread_join(consumer_thread, NULL);

    // clean up, destroy mutex
    pthread_mutex_destroy(&buffer_mutex);

    sem_destroy(&sem_occupied);
    sem_destroy(&sem_empty);
    return 0;
}