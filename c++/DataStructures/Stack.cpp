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
 * Stacks work as LIFO data structures
 * 
 * LIFO : Last In First Out
 *      [  Top  ]
 *      [  Val  ]
 *      [  Val  ]
 *      [ Bottom]
*/
class Stack {
    private:
        int height;
        Node* top;
        Node* bottom;

    public:
    /**
     * Stack Constructor 
     * 
     * @param value the value for the initial node to store
    */
        Stack (int value) {
            this->top = new Node(value);
            this->bottom = this->top;
            this->height = 1;
        }

        /**
         * Adds a Node to the stack
         * 
         * @param value the value that the newly added Node will store.
        */
        void push (int value) {
            Node* temp = new Node(value);
            temp->next = this->top;
            this->top = temp;
            this->height+=1;            
        }

        /**
         * Deletes the top Node and returns it's value
         * 
         * @return the value of the Last-In Node (top) 
        */
        int pop () {
            Node* temp = this->top;
            if (this->height == 0) {
                return INT32_MIN;
            }

            this->top = temp->next;
            this->height-=1;
            int value = temp->value;
            delete temp;
            return value;
        }

        /**
         * Gets the top node value (Last-In)
         * 
        */
        Node* getTop () {
            return this->top;
        }

        /**
         * Returns the oldest node in the Stack
        */
        Node* getBottom () {
            return this->bottom;
        }

        /**
         * Returns the height of the Stack
        */
        int getHeight () {
            return this->height;
        }

        /**
         * Prints the values stored in the stack from top to bottom
        */
        void printStack () {
            Node* temp = this->top;
            while (temp) {
                std::cout << temp->value << "->";
                temp = temp->next;
            }

            std::cout << "NULL" << std::endl;
        }

        /**
         * Deconstructor
        */
        ~Stack () {
            while (this->top) {
                this->pop();
            }
        }

};

int main () {
    std::cout << "Practicing Stacks w/ Pointers." << std::endl;
    std::cout << "===========================================================" << std::endl;
    Stack* stack = new Stack(1);
    for (int i = 2; i < 6; i++) {
        stack->push(i);
    }

    stack->printStack();
    std::cout << "The top (Last-In) Value: " << stack->getTop()->value << std::endl;
    std::cout << "The bottom (oldest) Value: " << stack->getBottom()->value << std::endl;
    std::cout << "The stack has a height of : " << stack->getHeight() << " Nodes." << std::endl;
    
    std::cout << "\n===========================================================\n" << std::endl;
    std::cout << "Popping the value: " << stack->pop() << std::endl;
    std::cout << "Popping the value: " << stack->pop() << std::endl;
    std::cout << "The new top (Last-In) Value: " << stack->getTop()->value << std::endl;
    std::cout << "The stack has a new height of : " << stack->getHeight() << " Nodes." << std::endl;
    stack->printStack();
    
    delete stack;
    return 0;
}