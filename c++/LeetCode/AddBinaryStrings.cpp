#include <iostream>
#include <string>
#include <math.h>

/**
 * Adding Binary Strings
 * 
 * Given two binary strings a and b, return their sum as a binary string.
 * 
 * Constraints:
 *      * 1 <= a.length, b.length <= 104
 *      * a and b consist only of '0' or '1' characters.
 *      * Each string does not contain leading zeros except for the zero itself.
 * 
 */

/**
 * Test Object
 */
struct Test {
    std::string a;
    std::string b;
    std::string expectedResult;
};

/**
 * List of Tests to execute
 */
Test TestCases[] = {
    Test{"11","1","100"},
    Test{"1010","1011","10101"},
};

/**
 * Add Binary strings and return the results
 * 
 * @param a: string for first binary string
 * @param b: string for second binary string
 * 
 * @return sum of a & b as a string
 *  
 */
std::string addBinary(std::string a, std::string b) {
    // check constraints
    if (a.size() < 1) return "";
    if (b.size() > pow(10, 4)) return "";
    
    std::string res = "";    // store result string
    bool c = false;     // track carry over
    while (a.size() || b.size()) {
        char l = '0';
        char r = '0';
        if (a.size()) {
            l = a[a.size()-1];
            // constraints check
            if (l != '0' && l != '1') return "";
            a.pop_back();
        }
        if (b.size()) {
            r = b[b.size()-1];
            // constraints check
            if (r != '0' && r != '1') return "";
            b.pop_back();
        }
        
        if (l == '1' && r == '1') {
            if (c) res = '1' + res;
            else res = '0' + res;
            c = true;
        } else if (l == '1' || r == '1') {
            if (c) {
                res = '0' + res;
            }
            else {
                res = '1' + res;
            }
        } else {
            if (c) {
                res = '1' + res;
                c = false;
            } else {
                res = '0' + res;
            }
        }
    }
    if (c) res = '1' + res;
    
    return res;
}

int main() {
    std::cout << "--- Running Add Binary LeetCode Problem ---" << std::endl;
    int i = 1;
    for (auto test: TestCases) {
        std::cout << "Test " << i << std::endl;
        std::cout << "\tinput: {a: \"" << test.a << "\", b: \"" << test.b << "\"}, Expected Result: \"" << test.expectedResult << "\"" << std::endl;
        std::string result = addBinary(test.a, test.b);
        std::cout << "\tRESULT: \"" << result << "\"" << std::endl; 
        std::cout << "\n====================================================================================\n" << std::endl;
        i+=1;
    }
}