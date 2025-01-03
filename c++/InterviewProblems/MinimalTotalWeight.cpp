#include <iostream>
#include <algorithm>
#include<bits/stdc++.h>
#include "../Utils/utils.h"

/**
 * 3. Minimum Total Weight
 * 
 * There are n chocolates and the weight of the chocolates is given as
 * an array of integers weights[n], where weights[i] denote the weight
 * of the ith chocolate. Every day, one can pick on chocolate, eat half
 * of it, and put the remaining half back. Find the minimum possible total
 * weight of the remaining chocolates after d days.
 * 
 * NOTE: One can eat the same chocolate multiple times. The weight of
 * the part eaten can be calculated as floor (weights[i]/2). 
 * 
 */


/**
 * Test struct to store tests to validate the solution
 */
struct Test {
    int* weights;
    int N;
    int days;
    int expectedResult;
};

/**
 * Collection of tests
 */
Test TestCases[] = {
    Test{new int[3]{30,20,25}, 3, 4, 31},
    Test{new int[3]{0, 0, 0}, 3, 5, 0},
    Test{new int[3]{10,8,5}, 3, 10, 3},
    Test{new int[3]{13,100,18}, 3, 5, 29},
};

/**
 * Gets the minimum weight in chocolates after eating
 * as much as possible within the given amount of days
 * 
 * @param arr : bag of chocolates represented by their weights
 * @param N : Number of chocolates/items in the bag/array
 * @param D : number of days available to eat chocolates
 */
int getRemainingWeight(int *arr, int N, int D){
    int res = 0;
    int lst = N-1; 
    if (!N) return res;
    std::sort(arr, arr+N);
    
    for (int i=0;i<D;i++){
        if (!arr[lst]) return 0;
        arr[lst]-=arr[lst]/2;
        std::sort(arr, arr+N);
        if (!arr[lst]) lst-=1;
    }

    for (int i=0; i<N;i++) res+=arr[i];
    
    return res;
}

int main(){
    std::cout << " -- Runnin solution for Interview Question: Minimal Total Weight --" << std::endl;
    
    Test test;
    for (int i = 0; i < sizeof(TestCases)/sizeof(TestCases[0]);i++){
        test = TestCases[i];
        std::cout << "input: { weights: ";
        printArray_Int(test.weights, test.N);
        std::cout << ", expectedResult: " << test.expectedResult << "}" << std::endl;
        int ans = getRemainingWeight(test.weights, test.N, test.days);
        std::cout << " weights after " << test.days << " : ";
        printArray_Int(test.weights, test.N);
        std::cout << std::endl;
        assert(test.expectedResult == ans);
    }
    
}