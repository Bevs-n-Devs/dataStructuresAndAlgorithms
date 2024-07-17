#include <iostream>
#include <math.h>
#include <string>

/**
 * Length of the last word
 * 
 * Given a string s consisting of words and spaces, return the 
 * length of the last word in the string. A word is a maximal 
 * substring consisting of non-space characters only.
 * 
 * Constraints:
 *      * 1 <= s.length <= 104
 *      * s consists of only English letters and spaces ' '.
 *      * There will be at least one word in s.
 * 
 */

/**
 * Test Object
 */
struct Test{
    std::string s;
    int expectedResult;
};

/**
 * Test Cases 
 */
Test TestCases[] = {
    Test{"a", 1},
    Test{"", -1},
    Test{"Hello World", 5},
    Test{"   fly me   to   the moon  ", 4},
    Test{"luffy is still joyboy", 6},
};

/**
 * Solution function to find the length of the last word in a string
 * 
 * @param s: string to parse
 * 
 * @return length of last word, or -1 is no word found
 * 
 */
int lengthOfLastWord(std::string s) {
    // check constraints
    if (s.size() < 1 || s.size() > pow(10,4)) return -1;
    
    const char sp = ' ';
    int l = 0;
    // working from the end of the string for empty spaces
    if (s[s.size()-1] == sp) while (s[s.size()-1] == sp) s.pop_back();
    // remove chars until a space is found
    while (s.size() && s[s.size()-1] != sp) {
        // check constraint
        if (s[s.size()-1] < 'a' &&
            s[s.size()-1] > 'z' &&
            s[s.size()-1] < 'A' &&
            s[s.size()-1] > 'Z' &&
            s[s.size()-1] != sp) return -1;
        l+=1;
        s.pop_back();
    }
    
    return l;
}

int main() {
    std::cout << "--- Running Length of Last Word ---" << std::endl;

    int i = 1;
    for (auto test: TestCases){
        std::cout << "Test " << i << std::endl;
        std::cout << "\tinput: " << test.s << ", Expected Result: " << test.expectedResult << std::endl;
        int result = lengthOfLastWord(test.s);
        std::cout << "\tRESULT: " << result << std::endl;
        std::cout << "========================================\n" << std::endl;
        i+=1;
    }

    return 0;
}