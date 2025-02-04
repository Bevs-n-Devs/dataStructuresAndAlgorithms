/**
 * 20. Valid Parentheses
 * 
 * Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', 
 * determine if the input string is valid.
 * 
 * An input string is valid if:
 * Open brackets must be closed by the same type of brackets.
 * Open brackets must be closed in the correct order.
 * Every close bracket has a corresponding open bracket of the same type.
 * 
 * Example 1:
 * Input: s = "()"
 * Output: true
 * 
 * Example 2:
 * Input: s = "()[]{}"
 * Output: true
 * 
 * Example 3:
 * Input: s = "(]"
 * Output: false
 * 
 * Example 4:
 * Input: s = "([])"
 * Output: true
 * 
 * Constraints:
 *  * 1 <= s.length <= 10^4
 *  * s consists of parentheses only '()[]{}'.
*/

#include <iostream>
#include <stack>
#include <math.h>
#include <assert.h>

/**
 * Test Object
 */
struct Test {
    std::string s;
    bool expectedResult;
};

/**
 * List of Tests to execute
 */
Test TestCases[] = {
    Test{"()", true},
    Test{"()[]{}", true},
    Test{"(]", false},
    Test{"([])", true},
    Test{"([}}])", false},
};

/**
 * Determines if a given string is valid for Parentheses
 * 
 * @param s : string to parse
 * 
 * @return true for a valid string, or false for an incvalid string
 */
bool isValid(std::string s) {
    // Checking constraints
    if (s.size() < 1 or s.size() > pow(10,4)) return false;
    // An odd condition would automatically be invalid
    if (s.size() %2) return false;

    // using a stack to track previously found characters
    std::stack<char> stk;

    // looping through all characters
    for (auto c: s){
        // if a closing character is found, remove it
        // from the stack as a vali pair has been found
        if (!stk.empty() && c == stk.top()) stk.pop();
        // for each starting character, add it's matching
        // closing character to the stack
        else if (c == '{') stk.push('}');
        else if (c == '[') stk.push(']');
        else if (c == '(') stk.push(')');
        // if none of the respective characters is found
        // return a false for an invalid character
        else return false;
    }

    // if the stack is empty, all opening characters had a matching
    // closing character in the string, making the string valid
    if (stk.empty()) return true;

    // if the stack isn't empty, there was an inbalance in
    // character pairs. Making the string invalid.
    return false;
}

int main(int argc, char** kwargs){
    Test test;
    int N = sizeof(TestCases)/sizeof(TestCases[0]);
    for (int i=0; i < N;i++){
        std::cout << "==========================================================" << std::endl;
        std::cout << "Test #" << i+1 << std::endl;
        test = TestCases[i];
        std::cout << "Input: { string: " << test.s << ", expectedOutput: " << std::boolalpha << test.expectedResult  << "}" << std::endl;
        bool ans = isValid(test.s);
        std::cout << "Actual Output: " << std::boolalpha << ans << std::endl;
        assert(test.expectedResult==ans);
    }

    std::cout << "==========================================================" << std::endl;
}