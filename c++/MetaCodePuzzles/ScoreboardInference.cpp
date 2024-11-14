#include <iostream>
#include "../Utils/utils.h"

/**
 * You are spectating a programming contest with N competitors, each trying to 
 * independently solve the same set of programming problems. Each problem has 
 * a point value, which is either 1 or 2.
 * 
 * On the scoreboard, you observe that the ith competitor has attained a score 
 * of S(i), which is a positive integer equal to the sum of the point values 
 * of all the problems they have solved.
 * 
 * The scoreboard does not display the number of problems in the contest, nor 
 * their point values. Using the information available, you would like to determine 
 * the minimum possible number of problems in the contest.
 * 
 * Constraints
 *      * 1 ≤ N ≤ 500,000
 *      * 1 ≤ S ≤ 1,000,000,000
 * 
 */

typedef struct{
    int N;
    std::vector<int> S;
    int expectedResult;
} Test;

Test TestCases[] = {
    Test{6, {1,2,3,4,5,6}, 4},
    Test{4, {4,3,3,4}, 3},
    Test{4, {2,4,6,7}, 4},
};

/**
 * Infers the minimum number of problems solved based on a
 * series of previous scores.
 * 
 * @param N : number of scores
 * @param S : series of scores
 * 
 * @return minimum number of problems solved
 * 
 */
int getMinProblemCount(int N, std::vector<int> S) {
    // Constraints check
    if (N < 1 | N > 500000) return 0;
    
    // There is a pattern of even vs odd scores, that have a 
    // binary sequence of either 1 or 2 points. Even results 
    // can be found by getting the max number of points and 
    // dividing by 2. 
    // If any number is odd, it shifts that division up by an
    // increment of 1.

    // declare the all even boolean
    bool all_even = true;
    // declare the max point value variable
    int max_val = S[0];

    // loop through all scores, searching 
    // for the max value or any odd values
    for (auto s: S) { 
        if (s < 1 | s > 1000000000) return 0;
        if (all_even & s%2) all_even = false;

        // updates the max score constantly comparing to new values
        max_val = std::max(s, max_val);
    }
    
    // if all scores are even return with half of the largest score
    if (all_even) return max_val/2;
    
    // if any value is odd, return with half of the largest score + 1
    return max_val/2+1; 
}

int main() {
    std::cout << " --- Running Meta Code Puzzle: Scoreboard Inference Solution --- " << std::endl;
    Test test;
    int ans;
    for (int i=0; i<sizeof(TestCases)/sizeof(TestCases[0]);i++){
        test = TestCases[i];
        std::cout << "Test " << i+1 << std::endl;
        std::cout << "input: {N: " << test.N << ", S: ";
        printVector_Int(test.S);
        std::cout << ", expectedResult: " << test.expectedResult << "}" << std::endl;
        ans = getMinProblemCount(test.N, test.S);
        std::cout << "Actual Result: " << ans << std::endl;
        std::cout << "\n===========================================================\n" << std::endl;
    }
}