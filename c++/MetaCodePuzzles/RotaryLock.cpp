#include <iostream>
#include "../Utils/utils.h"

/**
 * You're trying to open a lock. The lock comes with a wheel which has the integers 
 * from 1 to N arranged in a circle in order around it (with integers 1 and N adjacent 
 * to one another). The wheel is initially pointing at 1.
 * 
 * It takes 1 second to rotate the wheel by 1 unit to an adjacent integer in either 
 * direction, and it takes no time to select an integer once the wheel is pointing 
 * at it.
 * 
 * The lock will open if you enter a certain code. The code consists of a sequence of
 * M integers, the ith of which is C(i). Determine the minimum number of seconds 
 * required to select all M of the code's integers in order.
 * 
 * Constraints
 *      * 3 ≤ N ≤ 50,000,000
 *      * 1 ≤ M ≤ 1,000
 *      * 1 ≤ C(i) ≤N
 * 
 */

typedef struct {
    int N, M;
    std::vector<int> C;
    long long expectedResult;
} Test;

Test TestCases[] = {
    Test{3, 3, {1, 2, 3}, 2},
    Test{10, 4, {9, 4, 4, 8}, 11},
};

/**
 * Determines the minimum time needed to rotate through the rotary lock
 * 
 * @param N: number of whole number values on the lock
 * @param M: the number of value in the sequence to unlock the lock
 * @param C: the sequence of values to unlock the lock
 */
long long getMinCodeEntryTime(int N, int M, std::vector<int> C) {
  // check constraints
  if (N < 3 | N > 50000000) return 0;
  if (M < 1 | M > 1000) return 0;
  
  // declare seconds variable for the answer
  // and a current value to subtract to get the 
  // rotation with the least rotation time
  long long sec = 0;
  long long curr = 1;

  // loop through the values in the sequence
  // adding the smaller rotation time to the result
  for (int c: C){
    // constraints check
    if (c < 1 | c > N) return 0;

    // store the left & right rotation values
    long long l, r;
    l = (curr-c)%N;
    r = (c-curr)%N;

    // account for values above N after modulo math above
    if (l < 0) l+=N;
    if (r < 0) r+=N;

    // get the min value and add the time
    sec+=std::min(l,r);

    // update the current variable to the 
    // c value that was just considered
    curr = c;
  }

  return sec;
}

int main() {
    std::cout << " --- Running Meta Code Puzzle: Rotary Lock Code --- " << std::endl;
    Test test;
    long long ans;
    for (int i=0; i<sizeof(TestCases)/sizeof(TestCases[0]);i++){
        test = TestCases[i];
        std::cout << "Test " << i+1 << std::endl;
        std::cout << "input: {N: " << test.N << ", M: " << test.M << ", C: ";
        printVector_Int(test.C);
        std::cout << ", expectedResult: " << test.expectedResult << "}" << std::endl;
        ans = getMinCodeEntryTime(test.N, test.M, test.C);
        std::cout << "Actual Result: " << ans << std::endl;
        std::cout << "\n===========================================================\n" << std::endl;
    }
}