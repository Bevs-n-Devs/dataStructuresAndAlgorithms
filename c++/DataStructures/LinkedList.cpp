#include <iostream>

class Node {
    public:
        int value;
        Node* next;

        Node(int value) {
            this->value = value;
            this->next = nullptr;
        }
};

class LinkedList {
    private:
        int count;
        Node* firstNode;
        Node* lastNode;
    
    public:
        /**
         * Linked List Constructor
         * 
         * @param value to create the first node with.
        */
        LinkedList (int value) {
            this->firstNode = new Node(value);
            this->lastNode = this->firstNode;
            this->count = 1;
        }

        /**
         * Adds a node to the end of the Linked List
         * 
         * @param value value for the newly appended node to store
        */
        void append (int value) {
            Node* temp = new Node(value); 
            if (this->count == 0) {
                this->firstNode = temp;
                this->lastNode = temp;
            } else {
                this->lastNode->next = temp;
                this->lastNode = temp;
            }

            this->count+=1;
        }

        /**
         * Adds a node to the beginning of the Linked List
         * 
         * @param value value to be stored in the new node.
        */
        void prepend (int value) {
            Node* temp = new Node(value);
            if (this->count == 0) {
                this->lastNode = temp;
            } else {
                temp->next = this->firstNode;
            }

            this->firstNode = temp;
            this->count+=1;
        }
       
        /**
         * Gets a node at a specific index
         * 
         * @param idx index value to search for node
         * @return the node pointer at the given index, of a nullptr
        */
        Node* getNode(int idx) {
            if (idx >= this->count || idx < 0) {
                return nullptr;
            }
            if (idx == 0) {
                return this->firstNode;
            }
            if (idx == this->count-1) {
                return this->lastNode;
            }
        
            Node* temp = this->firstNode->next;
            int i = 1; 
            while (temp) {
                if (i == idx) {
                    return temp;
                }
                temp = temp->next;
                i+=1;
            }
            
            return temp;
        }

        /**
         * Inserts a node at a specific index
         * 
         * @param idx index where the new node should be inserted.
         * @param value value to store in newly inserted node. 
        */
        void insertNode (int idx, int value) {
            if (idx < 0 || idx > this->count) {
                return;
            }

            if (idx == 0) {
                this->prepend(value);
            } else if (idx == this->count) {
                this->append(value);
            } else {
                Node* node = new Node(value);
                Node* prev = this->getNode(idx-1);
                Node* next = this->getNode(idx);
                node->next = next;
                prev->next = node;
                this->count+=1;
            }
        }

        /**
         * Removes node at a specific index in the Linked List
         * 
         * @param idx index position of node in Linked List.
        */
        void removeNode (int idx) {
            if (idx < 0 || idx >= this->count) {
                return;
            }
            if (idx == 0) {
                this->removeFirstNode();
            } else if (idx == this->count-1) {
                this->removeLastNode();
            } else {
                Node* prev = this->getNode(idx-1);
                Node* curr = this->getNode(idx);
                prev->next = curr->next;
                delete curr;
                this->count-=1;
            }
        }

        /**
         * Deletes the first node in the Linked List
         * 
         * @return boolean value of true is a node was removed, and false if not
        */
        bool removeFirstNode () {
            if (this->count == 0) {
                return false;
            }

            Node* temp = this->firstNode;
            if (this->count == 1) {
                this->lastNode = nullptr;
            } 

            this->firstNode = temp->next;
            delete temp;
            this->count-=1;
            return true;
        }

        /**
         * Removes last node in the Linked List
         * 
         * @return boolean value of true is a node was removed, and false if not
        */
        bool removeLastNode () {
            if (this->count == 0) {
                return false;
            }

            Node* temp = this->firstNode; 
            if (this->count == 1) {
                this->firstNode = nullptr;
                this->lastNode = nullptr;
            } else {
                Node* next = temp->next;
                while (next) {
                    temp = next;
                    next = temp->next;
                }
                delete next;
                this->lastNode = temp;
            }

            this->count-=1;
            return true;
        }
        
        /**
         * Provides the first Node in the linked list
         * 
         * @return Node pointer for the first node 
        */
        Node* getFirstNode () {
            return this->firstNode;
        }

        /**
         * Provides the last Node in the linked list
         * 
         * @return Node pointer for the last node
        */
        Node* getLastNode () {
            return this->lastNode;
        }

        /**
         * Provides the number of nodes in the linked list
         * 
         * @return integer value for the number of nodes in the linked list
        */
        int getSize () {
            return this->count;
        }

        /**
         * Prints all the nodes in the Linked List
         * 
        */
        void printLinkedList () {
            Node* temp = this->firstNode;
            std::cout << "[" << this->count << "]\t";
            while (temp) {
                std::cout << "(" <<  temp->value << ")->";
                temp = temp->next;
            }

            std::cout << "NULL" << std::endl;
        }

        /**
         * Reverses the Linked List's order
         * 
        */
        void reverseLList () {
            if (this->count <= 1) {
                return;
            }

            Node* prev = nullptr;
            Node* curr = this->firstNode;
            Node* next = curr->next;
            this->lastNode = curr;
            while (next) {
                curr->next = prev;
                prev = curr;
                curr = next;
                next = curr->next;
            }

            curr->next = prev;
            this->firstNode = curr;
        }

        /**
         * Deconstructor Removes all child nodes when the object is deleted 
        */
        ~LinkedList () {
            while (this->firstNode) {
                this->removeFirstNode();
            }
        }
};


int main() {
    std::cout << "---- Creating a Linked List. ----" << std::endl;
    // Instantiates a new linked list with the the first node
    // storing the value 1.
    LinkedList* lList = new LinkedList(1);
    lList->printLinkedList();
    // appending 4 nodes to the linked list
    // with values 2-5. 
    std::cout << "===============================================================" << std::endl;
    std::cout << "Appending 4 new nodes to the Linked List.\n" << std::endl; 
    for (int i = 2; i < 6; i++){
        lList->append(i);
    }
    lList->printLinkedList();
    std::cout << "===============================================================" << std::endl;
    std::cout << "Prepending a new node to the Linked List.\n" << std::endl;
    lList->prepend(0);
    lList->printLinkedList();

    int idx = 3;
    std::cout << "===============================================================" << std::endl; 
    std::cout << "Getting node at Index " << idx << ".\n" << std::endl;
    Node* n = lList->getNode(idx); 
    std::cout << "Node at index " << idx << " is " << n->value << std::endl;
    std::cout << "First Node\t: " << lList->getFirstNode()->value << std::endl;
    std::cout << "Last Node\t: " << lList->getLastNode()->value << std::endl;

    std::cout << "===============================================================" << std::endl;
    std::cout << "Inserting a node at index 2 with a value of 22.\n" << std::endl;
    // Insert new node w/ value of 22 at Linked List index 2
    lList->insertNode(2, 22);
    lList->printLinkedList();

    std::cout << "===============================================================" << std::endl;
    std::cout << "Removing the node at index 2.\n" << std::endl;
    // Remove node at index 2
    lList->removeNode(2);
    lList->printLinkedList();

    std::cout << "===============================================================" << std::endl;
    std::cout << "Reversing the linked list.\n" << std::endl;
    lList->reverseLList();
    lList->printLinkedList();
    delete lList;
}