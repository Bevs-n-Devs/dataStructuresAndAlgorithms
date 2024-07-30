#include <iostream>
#include <vector>

/**
 * Heaps can be represented as complete Binary Trees
 * 
 * i.e. every node has 0 or 2 children
 * 
 * Max Heap:
 * Every child must to be smaller than the parent
 * 
 * Min Heap:
 * Every child must to be greater than the parent
 * 
 * left child equation: 2*parentIndex
 * right child equation 2*parentIndex+1
 * > NOTE : The root is referred to as index 1
 * 
 */
struct Node{
    int value;
    int index;
    Node* left;
    Node* right;

    /**
     * Instantiates Node Object with default value of 0
     */
    Node() {
        value = 0;
        index = 1;
        left = right = nullptr;
    }

    /**
     * Instiatiates Node Object w/ provided value
     * 
     * @param val: integer value to store in node
     */
    Node(int val) {
        value = val;
        index = 1;
        left = right = nullptr;
    }

    Node(std::vector<int> vec) {
        if (vec.size()) value = vec[0];
        else value = 0;

        if (vec.size() > 2) {
            left = new Node(vec[1]);
            right = new Node(vec[2]);
        }
    }

    void insert(int val) {

    }
};

/**
 * Heap object
 */
class MaxHeap {
    private:
    std::vector<int> heap;

    /**
     * Returns left child index
     *  
     * @param index: int va
     * 
     * @return integer index value 
    */
    int leftChild(int index) {
        return 2*index+1;
    }

    /**
     * Returns right child index
     *  
     * @param index: int va
     * 
     * @return integer index value 
    */
    int rightChild(int index) {
        return 2*index+2;
    }

    /**
     * Returns the parent node's index 
     * 
     * @param index: integer index value of item tp retrieve the parent of
     * 
     * @return integer index value of parent
     */
    int parent(int index) {
        return (index-1) / 2;
    }

    /**
     * Swaps heap values
     * 
     * @param index1: 1st index value of item to swap
     * @param index2: 2nd index value of item to swap
     */
    void swap(int index1, int index2) {
        int temp = heap[index1];
        heap[index1] = heap[index2];
        heap[index2] = temp;
    }

    /**
     * Drops the new root down to the appropriate location
     * after removing a value
     */
    void sinkDown(int index) {
        int maxIndex = index;

        while (true) {
            int leftIndex = leftChild(index);
            int rightIndex = rightChild(index);
            if (leftIndex < heap.size() && heap[leftIndex] > heap[maxIndex]) maxIndex = leftIndex;
            if (rightIndex < heap.size() && heap[rightIndex] > heap[maxIndex]) maxIndex = rightIndex;
            if (maxIndex != index) {
                swap(index, maxIndex);
                index = maxIndex;
            } else {
                return;
            }
        }
    }

    public:
    MaxHeap(std::vector<int> vals) {
        for (auto v: vals) insert(v);
    }

    /**
     * Prints all the values in the heap
     */
    void printHeap() {
        std::cout << "[" << heap[0];
        for (int e: std::vector<int>{heap.begin()+1, heap.end()}) {
            std::cout << "," << e;
        }
        std::cout << "]";
    }

    /**
     * Insert a new value to the heap
     * 
     * @param value : integer value to add to the heap
     */
    virtual void insert(int value) {
        heap.push_back(value);
        int current = heap.size() - 1;
        while (current && heap[current] > heap[parent(current)]) {
            swap(current, parent(current));
            current = parent(current);
        }
    }

    /**
     * Removes the first value in the heap & returns its value
     * 
     * @return integer value of the removed element
     */
    int remove() {
        if (heap.empty()) return INT32_MIN;

        int maxValue = heap.front();

        if (heap.size() == 1) {
            heap.pop_back();
        } else {
            heap[0] = heap.back();
            heap.pop_back();
            sinkDown(0);
        }

        return maxValue;
    }
};

int main() {
    // Instantiates Max Heap object w/ vector values
    MaxHeap* heap = new MaxHeap({99,72,61,58});
    std::cout << "the heap: ";
    heap->printHeap();
    std::cout << std::endl;

    heap->insert(100);
    std::cout << "the heap: ";
    heap->printHeap();
    std::cout << std::endl;

    heap->insert(75);
    std::cout << "the heap: ";
    heap->printHeap();
    std::cout << std::endl;

    heap->remove();
    std::cout << "the heap: ";
    heap->printHeap();
    std::cout << std::endl;

    heap->remove();
    std::cout << "the heap: ";
    heap->printHeap();
    std::cout << std::endl;
}