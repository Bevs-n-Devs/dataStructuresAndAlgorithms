#include "../../Utils/utils.h"
/**
 * Boyer-Moore Majority Voting Algorithm
 * 
 * The Boyer-Moore voting algorithm is one of the popular optimal algorithms 
 * which is used to find the majority element among the given elements that 
 * have more than N/ 2 occurrences. This works perfectly fine for finding the 
 * majority element which takes 2 traversals over the given elements, which 
 * works in O(N) time complexity and O(1) space complexity.
 * 
 */

/**
 * Returns the most frequently used value in the array
 * 
 * @param arr : array of integers
 * @param N : size of array
 * 
 * @return the most frequently used integer
 * 
 */
int mooresvoting(int* arr, int N){
    // declare a frequency id in the array
    // to point to the last most frequent value;
    // we start with the 0 index for the 1st element
    int f_idx = 0;
    // the count will be initiated with one as each number
    // appears at least once in the array
    int count = 1;

    // loop through every element
    for (int i=0;i<N;i++){
        // if we reach a count greater than half
        // of the length of the array, we exit early
        // as that is the most frequent
        if (count > N/2) return arr[i];
        
        // we compare each value to the most frequent
        // if it is the same we increase the count
        // otherwise we decrement it 
        if (arr[i] == arr[f_idx]) {
            count++;
        } else count--;

        // after decrementing enough we hit a 0 value
        // then we can reset the counter and shift the 
        // frequency index
        if (!count){
            count = 1;
            f_idx = i;
        }
    }

    return arr[f_idx];
}
int main(){
    // int arr[] = {3,0,5,6,5,3,2,8,3,2};
    int arr[] = {9,5,4,5,5,1,6,9,2,9};
    int N = 10;
    int ans = mooresvoting(arr,N);
    printf("Most Frequent number is: %d\n", ans);
}