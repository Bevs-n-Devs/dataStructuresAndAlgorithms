#include <iostream>
#include <vector>
#include "../../Utils/utils.h"

/**
 * Merge Sort Algorithm 
 * 
 * Time Complexity O(n*log(n))
 * 
 * Each element is touched at least once, so N 
 * is the number of elements in the array
 * 
 * Then the array is split in 2 (binary approach) which is 
 * log base 2 of N
 * 
 */

int testArr0[] = {1,2,3,0,7,10};
int testArr1[] = {5,4,3,2,1};
int testArr2[] = {21,45,112,2,0,500};

/**
 * Breaks an array in half, and sorts the values in ascending order
 * 
 * @param arr: the integer array
 * @param l: the integer left index to start the first array half
 * @param m: the integer middle index to end the first half array & start the second half array
 * @param r: the integer right index to end the second array half 
 * 
 */
void mergeArrays(int arr[], int l, int m, int r) {
    int lSize = m-l+1;
    int rSize = r-m;
    // create two arrays from the main array
    int lArr[lSize];
    int rArr[rSize];
    // left side
    for (int i=0;i< lSize; i++)
        lArr[i] = arr[l+i];
    // right side
    for (int i=0;i< rSize; i++)
        rArr[i] = arr[m+1+i];

    // three different index variables for the array:
    // main array index, the left side index, and the right side index
    int idx = l;
    int idxL = 0;
    int idxR = 0;

    // loops through both left & right arrays, entering their
    // respective values are place in the main array based on 
    // value 
    while (idxL < lSize && idxR < rSize) {
        if (lArr[idxL] <= rArr[idxR]) {
            arr[idx] = lArr[idxL];
            idx++;
            // the left index only increments when the respective array's value is less
            idxL++;
        } else {
            arr[idx] = rArr[idxR];
            idx++;
            // the right index only increments when the respective array's value is less
            idxR++;
        }
    }

    // In the event that one side of the array has more values
    // than the other, we continue adding the values until it's empty
    while (idxL < lSize) {
        arr[idx] = lArr[idxL];
        idx++;
        idxL++;
    }
    while (idxR < rSize){
        arr[idx] = rArr[idxR];
        idx++;
        idxR++;
    }

}

/**
 * Splits the array recursively
 * 
 * @param arr: array of integers
 * @param l: left index
 * @param r: right index
 */
void mergeSort(int arr[], int l, int r) {
    if (l>=r) return;
    int m = l + (r-l)/2; 
    mergeSort(arr, l, m); 
    mergeSort(arr, m+1, r);
    mergeArrays(arr, l, m, r);
}


int main() {
    std::cout << " --- Running Merge Sort Algo --" << std::endl;
    
    int N;
    for (int i=0;i<3;i++){
        std::cout << " input: ";
        switch(i) {
            case 0:
                N = sizeof(testArr0)/sizeof(testArr0[0]);
                printArray_Int(testArr0, N);
                mergeSort(testArr0, 0, N); 
                std::cout << "\n result: ";
                printArray_Int(testArr0, N);
                std::cout << "\n";
                break;
            case 1:
                N = sizeof(testArr1)/sizeof(testArr1[0]);
                printArray_Int(testArr1, N);
                mergeSort(testArr1, 0, N); 
                std::cout << "\n result: ";
                printArray_Int(testArr1, N);
                std::cout << "\n";
                break;
            case 2:
                N = sizeof(testArr2)/sizeof(testArr2[0]);
                printArray_Int(testArr2, N);
                mergeSort(testArr2, 0, N); 
                std::cout << "\n result: ";
                printArray_Int(testArr2, N);
                std::cout << "\n";
                break;
        }
        std::printf("=====================================================================\n");
    }
    return 0;
}