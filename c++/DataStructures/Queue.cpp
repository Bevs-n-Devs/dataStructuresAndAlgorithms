#include <iostream>

class Node {
    public:
        int value;
        Node* next;

        Node (int value) {
            this->value = value;
            next = nullptr;
        }
};

/**
 * Queues work as FIFO data structures
 * 
 * FIFO : First In First Out
 * 
 * [LAST] [VALUE] [VALUE] [VALUE] [FIRST]
 * 
*/
class Queue {
    private:
        int length;
        Node* first;
        Node* last;

    public:
        /**
         * Constructor for Queue Class
         * 
         * @param value value for the initial node to store
        */
        Queue (int value) {
            this->first = new Node(value);
            this->last = this->first;
            this->length = 1;
        }

        /**
         * Adds a new node to the queue
         * 
         * @param value value for the new enqueued node to store
        */
        void enqueue (int value) {
            Node* temp = new Node(value);
            if (this->length == 0) {
                this->first = temp;
            } else {
                this->last->next = temp;
            }

            this->last = temp;
            this->length+=1;
        }

        /**
         * Dequeue's the oldest node in the Queue (First-In)
         * 
         * @return value that was stored in the dequeued node
        */
        int dequeue () {
            if (this->length == 0) {
                return INT32_MIN;
            }

            Node* temp = this->first;
            int value = temp->value;
            this->first = temp->next;
            this->length-=1;
            delete temp;
            return value;
        }

        /**
         * Gets the first node in the Queue
        */
        Node* getFirst () {
            return this->first;
        }

        /**
         * Gets the last node in the Queue
        */
        Node* getLast () {
            return this->last;
        }

        /**
         * Gets the length of the Queue
        */
        int getLength () {
            return this->length;
        }

        void printQueue () {
            Node* temp = this->first;
            while (temp) {
                std::cout << temp->value << "->";
                temp = temp->next;
            }

            std::cout << "NULL" << std::endl;
        }

        /**
         * Deconstructor, to delete all nodes
        */
        ~Queue () {
            while (this->first) {
                this->dequeue();
            }
        }
};

int main () {
    std::cout << "Practicing Queues w/ Pointers." << std::endl;
    std::cout << "===========================================================" << std::endl;
    Queue* queue = new Queue(1);
    for (int i = 2; i < 6; i++) {
        queue->enqueue(i);
    }

    queue->printQueue();
    std::cout << "The last Value: " << queue->getLast()->value << std::endl;
    std::cout << "The first (First-In) Value: " << queue->getFirst()->value << std::endl;
    std::cout << "The queue has a length of : " << queue->getLength() << " Nodes." << std::endl;
    
    std::cout << "\n===========================================================\n" << std::endl;
    std::cout << "Dequeueing the value: " << queue->dequeue() << std::endl;
    std::cout << "Dequeueing the value: " << queue->dequeue() << std::endl;
    std::cout << "The new first (First-In) Value: " << queue->getFirst()->value << std::endl;
    std::cout << "The queue has a new length of : " << queue->getLength() << " Nodes." << std::endl;
    queue->printQueue();
    
    delete queue;

    return 0;
}