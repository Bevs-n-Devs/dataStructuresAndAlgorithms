#include <iostream>
#include <math.h>
#include <string>
#include <vector>

// Test struct to store sample tests
struct Test {
    std::string s;
    bool expectedResult;
};

Test TestCases[] = {
    {"", false},    // negative test
    {"2", false},   // negative test
    {"()", true},
    {"})", false},
    {"()", true},
    {"()[]{}", true},
};

/**
 * Validates if the provided string has matching opening & closing
 * parenthesis, brackets, and braces
 * 
 * @param s the string to parse 
 * 
 * @return boolean value, true if valid or false if not
 */
bool isValid(std::string s) {
    // check constraints
    if (s.size() < 2 || s.size() > pow(10,4)) return false;
    // if the strings isn't even, it cannot be valid
    if (!(s.size()-1 % 2)) return false;
    
    // Using a vector as a stack to track matching characters
    std::vector<char> stk;

    // looping through each char in the string
    for (char c: s) {
        // if a target opening character is found, the corresponding
        // closing character is added to the stack to look for the match 
        if (c == '(') stk.push_back(')');
        else if (c == '{') stk.push_back('}');
        else if (c == '[') stk.push_back(']');
        // if we see the matching closing character, we remove it
        // from the stack
        else if (!stk.empty() && stk.back() == c) stk.pop_back();
        // if we have an empty stack, we have not found a valid character
        // so we can exit and return false
        else if (stk.empty() || stk.back() != c) return false;
    }
    return stk.empty();
}

int main() {
    int test_case = 1;
    for (auto test: TestCases) {
        std::cout << "Test Case " << test_case << ": \""  << test.s << "\"" << std::endl;
        bool res = isValid(test.s);
        std::cout << "\t - Result: " << res << std::boolalpha << std::endl;
        test_case++;
        std::cout << "=========================================================\n" << std::endl;
    }
    return 0;
}