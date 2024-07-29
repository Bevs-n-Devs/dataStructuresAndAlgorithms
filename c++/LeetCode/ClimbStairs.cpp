#include <iostream>

/**
 * Climbing Stairs
 * 
 * You are climbing a staircase. It takes n steps to reach the top.
 * Each time you can either climb 1 or 2 steps. In how many distinct 
 * ways can you climb to the top?
 * 
 * Constraints:
 *  * 1 <= n <= 45
 */

/**
 * Test Object
 */
struct Test {
    int n;
    int expectedResult;
};

Test TestCases[] = {
    Test{0,0},
    Test{1,1},
    Test{3,3},
    Test{4,5},
    Test{5,8},
    Test{45,1836311903},
    Test{46,0},
};

/**
* Finds solution of step combinations to reach the provided step number
* 
* @param n: integer value of steps to reach
*
* @return integer value of combinations
*/
int climbStairs(int n) {
    // Constraints Check
    if (n < 1 || n > 45) return 0;
    
    // Capturing Lowest conditions
    if (n < 3) return n;
    
    // 1 & 2 are the only step options
    int x = 1, y = 2;
    
    // 1 & 2 are already captured above
    // so we start with 3 as the solution
    // adding continuously to the previous solution.
    // e.g.
    // climbStairs(5) = climbStairs(4) + climbStairs(3) 
    // climbStairs(6) = climbStairs(5) + climbStairs(4) 
    for (int i = 3; i < n; i++){
        int tmp = y;
        y+=x;
        x = tmp;
    }
    
    return (y+x);
}

int main() {
    int i = 1;
    std::cout << "--- Running Climb Stairs Problem ---" << std::endl;
    for (auto test: TestCases) {
        std::cout << "Test " << i << std::endl;
        std::cout << "\tinput: {n: " << test.n << "}, Expected Result: " << test.expectedResult << std::endl;
        long long result = climbStairs(test.n);
        std::cout << "\tRESULT: " << result << std::endl; 
        std::cout << "\n====================================================================================\n" << std::endl;
        i+=1;
    }
    
    return 0;
}