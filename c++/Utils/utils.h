#ifndef __UtilsHelper__
#define __UtilsHelper__

#include <iostream>
#include <vector>

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

struct BinaryTreeNode {
    int data;
    BinaryTreeNode* left;
    BinaryTreeNode* right;

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

    /**
     * Creates Doubly Linked List with initial value
     * 
     * @param v: integer value for the main node to store
     * @param vals: vector of integer values for the remaining nodes to store
     */
    BinaryTreeNode(int v, std::vector<int> vals);
};

/**
 * Prints vector of Integers
 * 
 * @param v: Vector of integers
 */
void printVector_Int(std::vector<int> v);

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
 * @param v: Array of characters
 * @param N: Number of elements in the array
 */
void printArray_Chr(char *arr, int N);

/**
 * Prints a Matrix of Integers
 * 
 * @param matrix : the 2 dimensional array of integers
 * @param w : width of the matrix (number of columns/number of internal elements of each internal array)
 * @param h : height of the matrix (number of rows/internal arrays) 
 */
void printMatrix_Int(int **matrix, int w, int h);

#endif