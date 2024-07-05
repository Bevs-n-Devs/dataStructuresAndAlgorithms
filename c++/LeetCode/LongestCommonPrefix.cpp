#include <iostream>
#include <map>
#include <vector>

/**
 * Write a function to find the longest common prefix string amongst an array of strings.
 * If there is no common prefix, return an empty string ""
 * 
 * 
 * Constraints:
 *  Example 1
 *      Input: strs = ["flower","flow","flight"]
 *      Output: "fl"
 * 
 * Example 2
 *      Input: strs = ["dog","racecar","car"]
 *      Output: ""
 *      Explanation: There is no common prefix among the input strings.
 * 
 * Constraints
 *  1 <= strs.length <= 200
 *  0 <= strs[i].length <= 200
 *  strs[i] consists of only lowercase English letters
 */

// Test struct to store sample tests
struct Test {
    int index;
    std::vector<std::string> strs;
    void printStrs() {
        for (auto s: strs) {
            if (s == strs[s.size()-1]) std::cout << s << " ";
            else std::cout << s << ", ";
        }
    }
};

// Array of tests for this problem
Test Tests[] = { 
    Test{0, {"flower","flow","flight"}},
    Test{1, {"dog","racecar","car"}},
};

// Solution function
std::string longestCommonPrefix(std::vector<std::string>& strs) {
        std::string res = "";
        // Constraints check
        if (strs.size() < 1 || strs.size() > 200) return res;

        // Store the first value as the result 
        res = strs[0];
        
        // Compare all remaining strings to the first string 
        for (int i = 1; i < strs.size(); i++) {
            std::string ss = strs[i];
            // Constraints check
            if (ss.size() < 0 || ss.size() > 200) return "";
            
            // Constraints check
            for (auto c: ss) if (c < 'a' || c > 'z') return "";

            std::string tmp = res;
            // Looping through tmp substrings to check for matches
            // until the temporary string is empty.
            while (tmp.size()) {
                // if the prefix is found in the beginning of the new string
                // break the loop and update the result.
                if (!ss.find(tmp)) {
                    res = tmp;
                    break;
                } 

                // If the substring is not found as a prefix, remove the last 
                // character of the string.
                tmp.pop_back();
            }

            // If the temporary string is empty, there was no match found.
            if (!tmp.size()) return tmp;
        }
        
        return res;
    }

int main() {
    std::cout << " ---- LeetCode::Longest Common Prefix ---- " << std::endl;
    for (auto t: Tests){
        std::cout << "Test (" << t.index << ") - strs" << " [";
        t.printStrs();
        std::cout << "]" << std::endl;

        std::string ans = longestCommonPrefix(t.strs);
        std::cout << "Answer: \"" << ans << "\"" << std::endl;
        std::cout << "=========================================================\n" << std::endl;
    }
    return 0;
}