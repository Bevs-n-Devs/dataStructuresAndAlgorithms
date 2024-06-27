#include <iostream>
#include <math.h>

class Node {
    public:
        std::string key;
        int value;
        Node* next;

        Node (std::string key, int value) {
            this->key = key;
            this->value = value;
            this->next = nullptr;
        }
};

class HashTable {
    private:
        // static means this constant is only made once
        // so if there are two instances of this class
        // they both use the same SIZE constant
        static const int SIZE = 7;
        Node* dataMap[SIZE];

    public:

        int hash (std::string key) {
            int hash = 0;
            for (int i = 0; i < key.length(); i++) {
                // turning the key into a letter
                int asciiValue = int(key[i]);
                hash = (hash + asciiValue * 23);
            }
        }

        void printTable () {
            for (int i = 0; i < this->SIZE; i++) {
                std::cout << i << ":" << std::endl;
                if (dataMap[i]) {
                    Node* temp = dataMap[i];
                    while (temp) {
                        std::cout << "   {" << temp->key << ", " << temp->value << "}" << std::endl;
                        temp = temp->next;
                    }
                }
            }
        }
};

int main () {

    HashTable* myHashTable = new HashTable();
    myHashTable->printTable();
    
    return 0;
}