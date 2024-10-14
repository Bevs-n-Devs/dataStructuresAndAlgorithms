#include <iostream>
#include "../Utils/utils.h"

/**
 * 125. Valid Palindrome
 * 
 * A phrase is a palindrome if, after converting all uppercase letters into 
 * lowercase letters and removing all non-alphanumeric characters, it reads 
 * the same forward and backward. Alphanumeric characters include letters and 
 * numbers. Given a string s, return true if it is a palindrome, or false otherwise.
 * 
 * Constraints:
 *      * 1 <= s.length <= 2 * 10^5
 *      * s consists only of printable ASCII characters.
 * 
 */

/**
 * Test object
 */
struct Test {
    std::string str;
    bool expectedResult;
};

/**
 * List of test cases
 */
Test TestCases[] = {
    Test{"A man, a plan, a canal: Panama", true},
    Test{"race a car", false},
    Test{" ", true},
    Test{"0P", false},
};

/**
 * Validates if an alphanumeric string is a valid 
 * 
 * @param s : string to validate
 * 
 * @return true is valid palidrone, and false if not
 * 
 */
bool isPalindrome(std::string s) {
    // Check constraints
    if (s.length() > 2*std::pow(10,5)) return false;
    if (s.length() < 2) return true;
    
    // create left & right index "pointers"
    int l = 0;
    int r = s.size()-1;
    
    // loop until the left and right pointers overlap 
    while (l<r) {
        char l_char, r_char;
        if (!(s[l] >= 'A' & s[l] <= 'Z') & 
            !(s[l] >= 'a' & s[l] <= 'z') &
            !(s[l] >= '0' & s[l] <= '9')) l+=1;
        else s[l] < 'a' ? l_char = s[l]+0x20 : l_char = s[l];
        
        if (!(s[r] >= 'A' & s[r] <= 'Z') & 
            !(s[r] >= 'a' & s[r] <= 'z') &
            !(s[r] >= '0' & s[r] <= '9')) r-=1;
        else s[r] < 'a' ? r_char = s[r]+0x20 : r_char = s[r];
        
        
        if (l_char & r_char){
            if(l_char != r_char) return false;
            l+=1;
            r-=1;
        }
    }

    return true;
}

int main() {
    std::cout << " ---- LeetCode:: 125. Valid Palindrome ---- " << std::endl;
    for (int i=0;i<sizeof(TestCases)/sizeof(TestCases[0]);i++){
        std::cout << "Test " << i+1 << std::endl;
        std::cout << "Input: {string: \""<< TestCases[i].str << "\", expectedResult: " << std::boolalpha << TestCases[i].expectedResult << "}" << std::endl;

        bool ans = isPalindrome(TestCases[i].str);
        std::cout << "\nActual Result:  " << std::boolalpha << ans << std::endl;
        std::cout << "=========================================================\n" << std::endl;
    }
    return 0;
}