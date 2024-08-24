#include "../Utils/utils.h"
#include <math.h>
#include <stdexcept>

/**
 * 
 * Design a data structure that follows the constraints of a Least Recently Used (LRU) cache.
 * 
 * Implement the LRUCache class:
 * 
 * LRUCache(int capacity) Initialize the LRU cache with positive size capacity.
 * int get(int key) Return the value of the key if the key exists, otherwise return -1.
 * void put(int key, int value) Update the value of the key if the key exists. Otherwise, 
 * add the key-value pair to the cache. If the number of keys exceeds the capacity from 
 * this operation, evict the least recently used key.
 * 
 * The functions get and put must each run in O(1) average time complexity.
 */

/**
 * Data Structure that maintains a 
 * given capacity of cached values.
 */
class LRUCache {
private:
    // protecting the capacity so it cannot be
    // rewritten
    int capacity;
    
    // Using a Doubly Linked List Node
    // for faster traversal
    struct Node{
        int key;
        int data;
        Node* prev;
        Node* next;
        /**
         * Node Constructor
         * 
         * @param key : the key that will be used to reference the node
         * @param data : the value the node will contain
         * 
         */
        Node(int key, int data){
            this->key = key;
            this->data = data;
            prev = next = nullptr;
        }
    };
    
    /**
     * Doubly Linked List used to manage the cache 
     * order
     */
    struct DoublyLinkedList {
        private:
        // protecting the size so it
        // cannot be externally changed
        int size;
        
        public:
        // head track the last accessed node
        // tail will track the least accessed node
        Node* head;
        Node* tail;
        
        /**
         * Doubly Linked List Constructor
         * initializes with a size of 0, and
         * the head & tail are nullptr's
         */
        DoublyLinkedList(){
            size = 0;
            head = tail = nullptr;
        }

        /**
         * Gets the current size of the Doubly Linked List
         * 
         * @return integer value of the Doubly Linked List's current size
         * 
         */
        int get_size() {return size;}
        
        /**
         * Adds a new node, to the front of the Doubly Linked List
         * and it will be the new "head"
         * 
         * @param key : key value used to reference the node
         * @param data : the value the node stores
         * 
         * @return the newly created node
         * 
         */
        Node* prepend(int key, int data){
            Node* n = new Node(key, data);
            if(!size) {
                head = n;
                tail = n;
            } else {
                head->prev = n;
                n->next = head;
                head = n;
            }
            
            size++;
            // printDLLst();
            return n;
        }
        
        /**
         * Adds a node to the end of the Doubly Linked List
         * making it the new tail.
         * 
         * @param key : key value used to reference the node
         * @param data : the value the node stores
         * 
         * @return the newly created node
         * 
         */
        Node* append(int key, int data){
            if(!size) {
                return prepend(key, data);
                size++;
            }
            
            Node* n = new Node(key, data);
            tail->next = n;
            n->next = head;
            head = n;
            
            size++;
            return n;
        }
        
        /**
         * Deletes the current head node
         * 
         * @return boolean value of deletion success
         * 
         */
        bool remove_head(){
            if (!size) return false;
            Node* tmp = head;
            
            if (head == tail) {
                head = nullptr;
                tail = nullptr;
            } else {
                tmp->next->prev = nullptr;
                head = tmp->next;
            }
            
            delete tmp;
            size--;
            
            return true;
        }
        
        /**
         * Deletes the current tail node
         * 
         * @return boolean value of deletion success
         * 
         */
        bool remove_tail(){
            if (!size) return false;
            if (head == tail) return remove_head();
            Node* prv = tail->prev;
            Node* tmp = tail;
            if (prv) prv->next = nullptr;
            tail = prv;
            delete tmp;
            size--;
            
            return true;
        }
        
        /**
         * Deletes a specific node
         * 
         * @param n: Node to delete
         * 
         * @return boolean value of deletion success
         * 
         */
        bool deleteNode(Node* n){
            if (n == head) return remove_head();
            if (n == tail) return remove_tail();
            // std::cout << n << std::endl;
            n->prev->next = n->next;
            n->next->prev = n->prev;
            delete n;
            size--;
            return true;
        } 
        
        /**
         * Prints the Doubly Linked List's current order
         * from head-> tail, for helpful debug.
         */
        void printDLLst(){
            std::cout<<"[";
            Node* tmp = head;
            while(tmp){
                if (tmp == head) std::cout << "(" << tmp->key << ")" << tmp->data;
                else std::cout << "<->" << "(" << tmp->key << ")" << tmp->data;
                tmp = tmp->next;
            }
            std::cout <<"]\n";
        }
        
        ~DoublyLinkedList(){
            // while(remove_head());
        }
    };
    
    // using hashmap for mapping position of 
    std::unordered_map<int, Node*> mp;
    DoublyLinkedList *dllst;
    
public:
    /**
     * Constructor for LRUCache
     * 
     * @param capacity : the max number of values the cache can store
     * 
     */
    LRUCache(int capacity) {
        // constraints check
        if (capacity < 1 || capacity > 3000) throw std::invalid_argument("Invalid capacity provided");
        this->capacity = capacity;
        dllst = new DoublyLinkedList();
    }
    
    /**
     * Get the value for a cache entry if available
     * 
     * @param key : the key referencing the cache entry
     * 
     * @return integer value for the cache entry if found, otherwise -1 
     * 
     */
    int get(int key) {
        printf("get (%d)\n", key);
        // constraints check
        if (key < 0 || key > pow(10,4)) return -1;
        
        if(!mp.size() || mp.find(key) == mp.end()) return -1;
        if (mp[key] == dllst->head) return dllst->head->data;
        else {
            int val = mp[key]->data;
            dllst->deleteNode(mp[key]);
            mp[key] = dllst->prepend(key, val);
        }
        dllst->printDLLst();
        return dllst->head->data;
    }
    
    /**
     * Enters a new cache entry
     * 
     * @param key : key value used to reference the cache entry
     * @param data : the value the cache entry stores
     * 
     */
    void put(int key, int value) {
        printf("put (%d)%d\n", key, value);
        // constraints check
        if (key < 0 || key > pow(10,4)) return;
        
        // if found, delete the old key and node
        if (mp.find(key) != mp.end()) {
            dllst->deleteNode(mp[key]);
        }
        
        else if (dllst->get_size() == capacity) {
            mp.erase(dllst->tail->key);
            dllst->remove_tail();
        }
        
        mp[key] = dllst->prepend(key, value);
        dllst->printDLLst();
    }
    
    /**
     * Destructor of LRUCache
     * to clean the remaining memory
     */
    ~LRUCache(){
        // clean up memory;
        delete dllst;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

int main() {
    LRUCache* lRUCache = new LRUCache(2);
    int n = 0;
    lRUCache->put(1, 1); // cache is {1=1}
    lRUCache->put(2, 2); // cache is {1=1, 2=2}
    n = lRUCache->get(1);    // return 1
    std::printf("return get for key 1: %d\n", n);
    lRUCache->put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
    n = lRUCache->get(2);    // returns -1 (not found)
    std::printf("return get for key 2: %d\n", n);
    lRUCache->put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
    n = lRUCache->get(1);    // return -1 (not found)
    std::printf("return get for key 1: %d\n", n);
    n = lRUCache->get(3);    // return 3
    std::printf("return get for key 3: %d\n", n);
    n = lRUCache->get(4);    // return 4
    std::printf("return get for key 4: %d\n", n);
    return 0;
}