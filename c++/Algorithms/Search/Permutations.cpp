#include "../../Utils/utils.h"
#include <iostream>

/**
 * Permutations is a means to give as many possible
 * combinations of a collection as possible. This can
 * be used often with problems that state getting the 
 * following:
 * 
 *      * Unique structures
 *      * All possible combinations
 *      * All variants of a string
 * 
 * This is commonly used with Arrays, Linked Lists,
 * Binary Trees, & Vectors.
 * 
 */

/**
 * Swaps two values using pointers
 * 
 * @param a: char pointer
 * @param b: char pointer
 */
void swap(char *a, char *b){
    char tmp = *a;
    *a = *b;
    *b = tmp;
}

/**
 * Prints every possible permutation of a char array
 * 
 * @param arr: char array
 * @param l: starting index
 * @param r: ending index
 * @param N: arr length
 * 
 */
void permutations(char *arr, int l, int r, int N){
    // using static so this is only declared once
    // to protect it's value and retain it over the scope
    // of the continued recursive calls
    static int cnt = 0;
    // once the left index exceeds the array size,
    // the permutation can be stored, printed, counted,
    // etc. 
    if (l == r) {
        cnt++;
        printf(" %d\t- ",cnt);
        // prints the 
        printf("%s\n", arr);
    }
    
    else{
        // loop through the given index range
        for (int i=l; i<=r; i++) {
            // swaps the first value with 
            // that iteration of index i
            swap(&arr[i],&arr[l]);
            // recursively runs the same swapping
            // progressively to the end of the array
            permutations(arr, l+1,r, N);
            // swaps with the initial value again
            // as a final clean up check
            swap(&arr[i],&arr[l]);
        }
    }
}

int main() {
    char arr[] = {'a','b','c'};
    int N = sizeof(arr)/sizeof(arr[0]);
    printf("input: ");
    printArray_Chr(arr,N);
    printf("\n");
    permutations(arr,0,N-1, N);
    return 0;
}