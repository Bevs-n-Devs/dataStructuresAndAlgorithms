#ifndef __UtilsHelper__
#define __UtilsHelper__

#include <iostream>
#include <math.h>
#include <queue>
#include <vector>
#include <unordered_map>

/**
 * Linked List Object
 */
struct LListNode {
    int value;
    LListNode* next;

    /**
     * Creates Linked List with initial value
     * 
     * @param v: integer value for the node to store
     */
    LListNode(int v=0);

    /**
     * Creates Linked List with initial value
     * 
     * @param v: integer value for the main node to store
     * @param n: integer value for the next node to store
     */
    LListNode(int v, int n);

    /**
     * Creates Linked List with initial value
     * 
     * @param vals: vector of integer values for the remaining nodes to store
     */
    LListNode(std::vector<int> vals);

    /**
     * Destructor to free memory
     */
    ~LListNode();

    /**
     * Prints the LList values
     */
    void print();
};

/**
 * Doubly Linked List Object
 */
struct DLListNode {
    int value;
    DLListNode* prev;
    DLListNode* next;

    /**
     * Creates Doubly Linked List with initial value
     * 
     * @param v: integer value for the node to store
     */
    DLListNode(int v);

    /**
     * Creates Doubly Linked List with initial value
     * 
     * @param v: integer value for the main node to store
     * @param n: integer value for the next node to store
     */
    DLListNode(int v, int n);

    /**
     * Creates Doubly Linked List with initial value
     * 
     * @param v: integer value for the main node to store
     * @param p: integer value for the prev node to store
     * @param n: integer value for the next node to store
     */
    DLListNode(int v, int p, int n);

    /**
     * Creates Doubly Linked List with initial value
     * 
     * @param v: integer value for the main node to store
     * @param vals: vector of integer values for the remaining nodes to store
     */
    DLListNode(int v, std::vector<int> vals);

    /**
     * Destructor to free memory
     */
    ~DLListNode();

    /**
     * Prints the DLList values
     */
    void print();
};

struct LList {
    LListNode* head;
    LListNode* tail;
    int size;

    /**
     * LList Constructor
     * 
     * @param head: LListNode 
     * 
     */
    LList(LListNode* head);

    /**
     * Prints the Llist values
     */
    void printLLst();
};

struct BinaryTreeNode {
    int data;
    BinaryTreeNode* left;
    BinaryTreeNode* right;

    /**
     * Default constructor
     */
    BinaryTreeNode();

    /**
     * Creates Binary Tree Node with initial value
     * 
     * @param v: integer value for the node to store
     */
    BinaryTreeNode(int v);

    /**
     * Creates Binary Tree Node with initial value
     * 
     * @param v: integer value for the main node to store
     * @param n: integer value for the next node to store
     */
    BinaryTreeNode(int v, int n);
};



/**
 * Binary Tree of Nodes
 */
struct BinaryTree{
    
    
    // private:
    

    // public:
    // root of the binary tree
    BinaryTreeNode* root;

    /**
     * Default constructor
     */
    BinaryTree();

    /**
     * Creates Binary Tree with array of values
     * 
     * @param arr : Integer array to create binary tree
     * @param N : number of elements in array
     * 
     */
    BinaryTree(int* arr, int N);

    /**
     * Creates Binary Tree with array of values
     * 
     * @param vec : Integer vector to create binary tree
     * 
     */
    BinaryTree(std::vector<int> vec);

    /**
     * Add children
     * 
     * @param node : to add children to
     * @param vec : vector of node values to store
     * @param p : parent node index
     * 
     */
    void add_children_vec(BinaryTreeNode *node, std::vector<int> vec, int p = 0);

    /**
     * Add children
     * 
     * @param node : to add children to
     * @param arr : int array of node values to store
     * @param N : size of array
     * @param p : parent node index
     * 
     */
    void add_children_arr(BinaryTreeNode *node, int* arr, int N, int p = 0);

    /**
     * Prints all nodes in the binary tree
     * following Breadth First Search
     */
    void printTree();
};

/**
 * Prints vector of Integers
 * 
 * @param v: Vector of integers
 */
void printVector_Int(std::vector<int> v);

/**
 * Prints vector of Long Long's
 * 
 * @param v: Vector of integers
 */
void printVector_LngLng(std::vector<long long> v);

/**
 * Prints vector of Characters
 * 
 * @param v: Vector of characters
 */
void printVector_Chr(std::vector<char> v);

/**
 * Prints vector of Strings
 * 
 * @param v: Vector of strings
 */
void printVector_Str(std::vector<char*> v);

/**
 * Prints Array of Integers
 * 
 * @param v: Array of integers
 * @param N: Number of elements in the array
 */
void printArray_Int(int *arr, int N);

/**
 * Prints Array of Characters
 * 
 * @param arr: Array of characters
 * @param N: Number of elements in the array
 */
void printArray_Chr(char *arr, int N);

/**
 * Prints Array of Bytes
 * 
 * @param arr: Array of bytes
 * @param N: Number of elements in the array
 */
void printArray_Bytes(uint8_t *arr, int N);

/**
 * Prints a Matrix of Integers
 * 
 * @param matrix : the 2 dimensional array of integers
 * @param w : width of the matrix (number of columns/number of internal elements of each internal array)
 * @param h : height of the matrix (number of rows/internal arrays) 
 */
void printMatrix_Int(int **matrix, int w, int h);

/**
 * Prints a Vector Matrix of Integers
 * 
 * @param matrix : the 2 dimensional vector of integers
 * @param w : width of the matrix (number of columns/number of internal elements of each internal array)
 * @param h : height of the matrix (number of rows/internal arrays) 
 */
void printMatrix_Vector_Int(std::vector<std::vector<int>> matrix);

#endif