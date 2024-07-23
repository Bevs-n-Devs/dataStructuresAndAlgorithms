#include <iostream>
#include <math.h>

/**
 * Finding Square Root
 * 
 * Given a non-negative integer x, return the square root of x rounded 
 * down to the nearest integer. The returned integer should be non-negative 
 * as well. You must not use any built-in exponent function or operator. 
 * For example, do not use pow(x, 0.5) in c++ or x ** 0.5 in python.
 * 
 * Constraints
 *      * 0 <= x <= 231 - 1
 * 
 */

/**
 * Test Object
 */
struct Test {
    long long x;
    long long expectedResult;
};

/**
 * List of Tests to execute
 */
Test TestCases[] {
    Test{1, 1},
    Test{4, 2},
    Test{10,3},
    // TODO :: resolve conflict between leet code and local machine
    // Test{2147395599, 46339},
};

/**
* Returns the closest whole value square root of a given number
*
* @param x : int to find the square root of
* 
* @return whole number for the closest square root value, if not exact
*/
long long mySqrt(long long x) {
    // constraints check
    if (x<0 || x > pow(2,31)-1) return 0;
    
    // catch lower limit condition
    if (x <= 1) return x;
    
    // use binary search approach tracking left, middle, & right
    long l, m, r, res;
    l = 0;
    r = x;
    
    while(l<=r) {
        m = l + (r-l)/2;
        // catch even answer
        if (m*m == x) return m;
        // move left or right limits based on square of current mid
        else if (m*m < x) {
            res = m;
            l = m+1;
        } else r = m-1;
    }
    
    return res;
}

int main() {
    int i = 1;
    std::cout << "--- Running Square Root Problem ---" << std::endl;
    for (auto test: TestCases) {
        std::cout << "Test " << i << std::endl;
        std::cout << "\tinput: {x: " << test.x << "}, Expected Result: " << test.expectedResult << std::endl;
        long long result = mySqrt(test.x);
        std::cout << "\tRESULT: " << result << std::endl; 
        std::cout << "\n====================================================================================\n" << std::endl;
        i+=1;
    }
    return 1;
}