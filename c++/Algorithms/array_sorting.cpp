#include <iostream>
#include <cstring>

enum ALGOS {
    BUBBLE = 1,
    INSERTION = 2,
    QUICK_SORT = 3,
};

ALGOS ALGO = BUBBLE;
bool recursion = false; 

void insertion_sort(int arr[], int N) {
    if (N <= 1) {
        return;
    }

    int idx = 0;
    for (int i = idx; i < N; i++) {
        
    }
}

/**
 * Uses the bubble sort alorithm to sort arrays
 * 
 * Time Complexity : O(N^2)
 * 
 * @param arr the integer array
 * @param N number of items in the array
*/
void bubble_sort (int arr[], int N) {
    if (N <= 1) {
        return;
    }

    int ValA, ValB;
    bool swapped = false;
    for (int i = 0; i < N; i++) {
        swapped = false;
        for (int n = i+1; n < N; n++) {
            if (arr[i] > arr[n]) {
                std::swap(arr[i], arr[n]);
                swapped = true;
            }
        }

        if (!swapped) {
            break;
        }
    }
}

/**
 * Uses the bubble sort alorithm to sort arrays w/ recursion
 * 
 * Time Complexity : O(N^2)
 * 
 * @param arr the integer array
 * @param N number of items in the array
 * @param i index of 
*/
void bubble_sort_recursive (int arr[], int N, int i=0) {
    if (N <= 1) {
        return;
    }
    
    bool swapped = false;
    swapped = false;
    for (int n = i+1; n < N; n++) {
        if (arr[i] > arr[n]) {
            std::swap(arr[i], arr[n]);
            swapped = true;
        }
    }

    if (!swapped) {
        return;
    } else {
        bubble_sort_recursive(arr, N, i+1);
    }
}

void printArray (int arr[], int N) {
    std::cout << " [" ;

    for (int i = 0; i < N; i++) {
        std::cout << arr[i];
        if (i < N-1) {
            std::cout << ", ";
        }
    }

    std::cout << "]" << std::endl;
}

void parseArgs (char **arr, int N) {
    if (N == 1) {
        return;
    }
    // std::cout << "number of args: " << N-1 << std::endl;
    // std::cout << " [" ;

    for (int i = 1; i < N; i++) {
        // std::cout << arr[i] << " " ;
        // if (i < N-1) {
        //     std::cout << ", ";
        // }

        if (!strcmp(arr[i], "--algo") || !strcmp(arr[i], "-a")) {
            std::string key = arr[i+1];
            if (key == "bubble") {
                ALGO = BUBBLE;
            } else if (key == "insertion") {
                ALGO = INSERTION;
            } else if (key == "quick-sort") {
                ALGO = QUICK_SORT;
            }
        } else if (!strcmp(arr[i], "-r")) {
            std::cout << " recursion " ;
            recursion = true;
        } 
    }

    // std::cout << "]" << std::endl;
}

int main (int argc, char **argv) {
    parseArgs(argv, argc);
    int arr[] = {6,5,4,3,2,1};
    int N = sizeof(arr)/sizeof(arr[0]);
    std::cout << "original array:" << std::endl;
    printArray(arr, N);
    switch (ALGO) {
        case BUBBLE:
            if (recursion) {
                std::cout << " Running Bubble Sort algorithm w/ recursion." << std::endl;
                bubble_sort_recursive(arr, N);
            } else {
                std::cout << " Running Bubble Sort algorithm." << std::endl;
                bubble_sort(arr, N);
            }
    }
    printArray(arr, N);

    return 0;
}