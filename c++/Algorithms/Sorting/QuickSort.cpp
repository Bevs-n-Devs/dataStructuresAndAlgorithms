#include <iostream>
#include "../../Utils/utils.h"

/**
 * Quick Sort Algorithm 
 * 
 * Time Complexity O(log(n))
 * 
 * Each element is touched at least once, so N 
 * is the number of elements in the array, but the
 * array is constantly split in half recursively.
 * 
 * 
 */

/**
 * Test Case Structure
 */
typedef struct {
    int* arr;
    int N;
    int* expectedResult;
} TestCase;

/**
 * Test Cases to validate the algorithm functionality
 */
TestCase TestCases[] = {
    TestCase{new int[6]{1,2,3,0,7,10}, 6, new int[6]{0,1,2,3,7,10}},
    TestCase{new int[5]{5,4,3,2,1}, 5, new int[5]{1,2,3,4,5}},
    TestCase{new int[6]{21,45,112,2,0,500}, 6, new int[6]{0,2,21,45,112,500}},
};

/**
 * Swaps array values
 * 
 * @param arr: array to swap values within
 * @param i1: index in array of value 1
 * @param i2: index in array of value 2
 * 
 */
void swap(int* arr, int i1, int i2) {
    int tmp = arr[i2];
    arr[i2] = arr[i1];
    arr[i1] = tmp; 
}

/**
 * Loops from pivot array index to the end
 * array index swapping values in ascending 
 * order
 * 
 * @param arr: the array to check
 * @param pvt_i: the pivot index
 * @param end_i: the end index to stop looping
 * 
 * @return pivot index when finished looping 
 */
int pivot(int* arr, int pvt_i, int end_i) {
    // start by tracking the last swapped index
    // starting at the initial pivot point, as 
    // we do not want to go beyond an index
    // that has already been sorted
    int swap_i = pvt_i;

    // loop through the array from the starting 
    // index (pvt_i) to the ending index (end_i)
    // comparing values until we find an unsorted 
    // pair to swap
    for (int i= pvt_i+1; i<=end_i; i++) {
        if (arr[i] < arr[pvt_i]) {
            // increment the swap index
            swap_i+=1;
            
            // swap the values
            swap(arr, swap_i, i);
        }
    }

    // swap the 
    swap(arr, pvt_i, swap_i);
    return swap_i;
}

/**
 * Quick Sort Algorithm main call
 * 
 * @param arr: Integer Array to sort
 * @param lft_i: starting index for sorting
 * @param rht_i: ending index for sorting
 * 
 */
void quicksort(int* arr, int lft_i, int rht_i) {
    // Catch when the left index exceeds or 
    // equals the right index indicating the
    // end of sorting or an empty array
    if (lft_i >= rht_i) return;
    
    // The pivot index is set based on the last
    // sorted array index
    int pvt_i = pivot(arr, lft_i, rht_i);
    
    // recursively call on the left side of the array
    quicksort(arr, lft_i, pvt_i-1);
    
    // recursively call on the right side of the array
    quicksort(arr, pvt_i+1, rht_i);
}

int main() {
    std::cout << " --- Running Quick Sort Algorithm --- " << std::endl;
    for (int i=0;i<sizeof(TestCases)/sizeof(TestCases[0]);i++) {
        std::cout << "\nTest " << i << std::endl;
        std::cout << "input -> ";
        printArray_Int(TestCases[i].arr, TestCases[i].N);
        std::cout << ", Expected Result: ";
        printArray_Int(TestCases[i].expectedResult, TestCases[i].N);
        // NOTE: Start with the last index, not the array size
        quicksort(TestCases[i].arr, 0, TestCases[i].N-1);
        std::cout << "\n Result: ";
        printArray_Int(TestCases[i].arr, TestCases[i].N);
        std::cout << "\n=====================================================" << std::endl;
    }
}