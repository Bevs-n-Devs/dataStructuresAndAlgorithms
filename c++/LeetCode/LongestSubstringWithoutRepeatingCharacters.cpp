#include <iostream>
#include <math.h>
#include <stdio.h>
#include <string>


/**
 * 3. Longest Substring Without Repeating Characters
 * 
 * Given a string s, find the length of the longest substring without repeating characters.
 * 
 * Constraints:
 *      * 0 <= s.length <= 5 * 104
 *      * s consists of English letters, digits, symbols and spaces.
 * 
 */

/**
 * Test Case Object
 */
class Test {
    public:
    std::string s;
    int expectedOutput;
};

/**
 * Test Cases to validate the solution
 */
Test TestCases[] = {
    Test{"   ", 1},
    Test{"eu", 2},
    Test{"abcabcbb", 3},
    Test{"bbbbb", 1},
    Test{"pwwkew", 3},
};

/**
 * Gets the longest substring with non-repeating chars
 * 
 * @param s : string to parse
 * @return longest substring length
 * 
 */
int lengthOfLongestSubstring(std::string s) {
    // Constraints check
    if (s.size() > 5 * std::pow(10,4)) return 0;
    if (s.size() < 2) return s.size();
    /** Using sliding window approach with 
     * left & right index pointers
    */
    int l = 0;
    int r = l+1;
    int max = 1;
    
    while (r < s.size()) {
        std::string ss = {s.begin()+l, s.begin()+r};
        if (ss.find(s[r]) < s.size()){
            // if the next value is found increase the left index pointer
            l+=1;
        } else {
            // if no duplicates found, increase right index pointer and max substring value
            max = std::max(max, r-l+1);
            r+=1;
        }
    }
    
    return max;
}

int main() {
    std::cout << "--- Running 3. Longest Substring Without Repeating Characters Leetcode Solution ---" << std::endl;
    Test test;
    for (int i = 0; i < sizeof(TestCases)/sizeof(TestCases[0]); i++){
        test = TestCases[i];
        std::cout << "Test Case " << i+1 << std::endl;
        std::cout << "Input : { s:\"" << test.s << "\", ExpectedResult: " << test.expectedOutput  << "}"<< std::endl;
        int res = lengthOfLongestSubstring(test.s);
        std::cout << "Actual Result: " << res << std::endl;
        std::cout << "\n===================================================================================\n" << std::endl;
    }
}