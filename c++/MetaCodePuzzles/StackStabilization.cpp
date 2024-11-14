#include <iostream>
#include "../Utils/utils.h"

/**
 * There's a stack of N inflatable discs, with the ith disc from the 
 * top having an initial radius of R(i) inches.
 * 
 * The stack is considered unstable if it includes at least one disc 
 * whose radius is larger than or equal to that of the disc directly 
 * under it. In other words, for the stack to be stable, each disc 
 * must have a strictly smaller radius than that of the disc directly 
 * under it.
 * 
 * As long as the stack is unstable, you can repeatedly choose any disc 
 * of your choice and deflate it down to have a radius of your choice 
 * which is strictly smaller than the disc’s prior radius. The new radius 
 * must be a positive integer number of inches.
 * 
 * Determine the minimum number of discs which need to be deflated in 
 * order to make the stack stable, if this is possible at all. If it is 
 * impossible to stabilize the stack, return −1 instead.
 * 
 * Constraints
 *      * 1 ≤ N ≤ 50
 *      * 1 ≤ R ≤ 1,000,000,000
 * 
 */

typedef struct {
    int N;
    std::vector<int> R;
    int expectedResult;
} Test;

Test TestCases[] = {
    Test{5, {  2,  5,  3,  6,  5}, 3},
    Test{3, {100,100,100}, 2},
    Test{4, {  6,  5,  4,  3}, -1},
};

/**
 * Determines the minimum number of Discs to deflate to
 * balance/stabalize the stack of discs.
 * 
 * @param N : number of discs
 * @param R : series of radaii of discs
 * 
 * @return number of deflated discs
 * 
 */
int getMinimumDeflatedDiscCount(int N, std::vector<int> R) {
    // Constraints check
    if (N < 1 | N > 50) return -1;
    // declare initial answer
    int ans = 0;
    // declare to store previous values
    int prev = -1;
    // loop over all elements
    for(int i = N - 1; i >= 0; i--) {
        // check if the index is the last value: R[N-1]
        // & if the current value at index i is
        // greater than the previous value
        if(i != N - 1 && R[i] >= prev) {
        
        // if prev less than or equal to i+1
        if(prev <= i + 1) return -1;

        ans++;
        prev = prev - 1;
        } else prev = R[i]; // sets the initial previous value
        
        
    }

    return ans;
}

int main() {
    std::cout << " --- Running Meta Code Puzzle: Stack Stabilization Solution --- " << std::endl;
    Test test;
    int ans;
    for (int i=0; i<sizeof(TestCases)/sizeof(TestCases[0]);i++){
        test = TestCases[i];
        std::cout << "Test " << i+1 << std::endl;
        std::cout << "input: {N: " << test.N << ", R: ";
        printVector_Int(test.R);
        std::cout << ", expectedResult: " << test.expectedResult << "}" << std::endl;
        ans = getMinimumDeflatedDiscCount(test.N, test.R);
        std::cout << "Actual Result: " << ans << std::endl;
        std::cout << "\n===========================================================\n" << std::endl;
    }
}