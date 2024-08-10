#include <iostream>
#include "../../Utils/utils.h"

/**
 * The Insertion Sort Algorithm
 * 
 * Time complexity: O(N^2)
 * Reason: each element in the array is compared to all other
 * values in the worst case scenario.
 * 
 */

/**
 * Test Object
 */
typedef struct{
    int* arr;
    int N;
    int* expectedResult;
} Test;

/**
 * Test Cases for proving the Algo
 */
Test TestCases[] = {
    Test{new int[10]{3,0,5,6,5,3,2,3,8,2}, 10, new int[10]{0,2,2,3,3,3,5,5,6,8}},
    Test{new int[11]{1,3,0,5,6,5,3,2,3,8,2}, 11, new int[11]{0,1,2,2,3,3,3,5,5,6,8}},
};

/**
 * Insertion Sort [Recursive Approach]
 * 
 * @param arr: array of integers
 * @param N: Number of values in the array
 * @param idx: the index of the array to use for comparing values
 * 
 */
void insertionSort(int* arr, int N, int idx){
    // condition to catch boundary conditions
    if (N <= 1 || idx >= N) return;

    // temporarily store the value at the idx position
    int tmp = arr[idx];
    
    // Loop through the array comparing the values to tmp
    for (int i=idx-1; i>=0;i--){
        // if a value is greater than tmp, shift it to the right
        if (arr[i] > tmp){
            arr[i+1] = arr[i];
            arr[i] = tmp;
        } else insertionSort(arr, N, idx+1);
    }

    // recursively call the function incrementing the idx value by 1
    insertionSort(arr, N, idx+1);
}

int main() {
    for (int i=0;i<sizeof(TestCases)/sizeof(TestCases[0]);i++){
        std::cout << "Test Number " << i+1 << std::endl;
        std::cout << "input: ";
        printArray_Int(TestCases[i].arr, TestCases[i].N);
        std::cout << ", Expected Result: ";
        printArray_Int(TestCases[i].expectedResult, TestCases[i].N);
        std::cout << std::endl;
        insertionSort(TestCases[i].arr, TestCases[i].N, 1);
        std::cout << "Actual Result: ";
        printArray_Int(TestCases[i].arr, TestCases[i].N);
        std::cout << "\n=====================================================\n" << std::endl;
    }

    return 0;
}