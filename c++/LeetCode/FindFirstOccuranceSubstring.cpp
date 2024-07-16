#include <iostream>
#include <string>
#include <math.h>

/**
 * Find the Index of the First Occurrence in a String
 * 
 * Given two strings needle and haystack, return the 
 * index of the first occurrence of needle in haystack, 
 * or -1 if needle is not part of haystack.
 * 
 * 
 * Constraints:
 *      * 1 <= haystack.length, needle.length <= 104
 *      * haystack and needle consist of only lowercase English characters.
 */

/**
 * Test object
 */
struct Test {
    std::string haystack;
    std::string needle;
};

/**
 * List of test cases
 */
Test TestCases[] = {
    Test{"sadbutsad", "sad"},
    Test{"leetcode", "leeto"},
    Test{"mississippi", "issip"},
    Test{"mississippi", "pi"},
};

/**
 * Solution Function to find first occurance of substring in string
 * 
 * If the needle (substring) is not found in the haystack (main string)
 * the function returns -1, otherwise it returns the start position where 
 * the substring was found in the main string.
 * 
 * @param haystack: string to search
 * @param needle: substring to search for in the haystack
 * 
 * @return substring occurance position
 */
int strStr(std::string haystack, std::string needle) {
    // constraint checks
    if (haystack.size() < 1) return -1;
    if (needle.size() > pow(10,4)) return -1;
    if (needle.size() > haystack.size()) return -1;
    
    // maintain the left position while shifting the search characters
    int l = 0;
    // constraint check on needle
    for (auto c: needle) if (c < 'a' || c > 'z') return -1;
    while (l<haystack.size()) {
        // get substring of search window
        std::string ss1 = haystack.substr(l, needle.size());
        // constraint check on substring
        for (auto c: ss1) if (c < 'a' || c > 'z') return -1;
        // check for matching substring and exit with position
        if (ss1 == needle) return l;
        // increment left holder
        l+=1;
    }
    
    return -1;
}

int main() {
    std::cout << "--- Running Find First Occurance Substring Problem ---" << std::endl;
    int i = 1;
    for (auto test: TestCases) {
        std::cout << "Test Case " << i << std::endl;
        std::cout << "\tinput-> {haystack: " << test.haystack << ", needle: " << test.needle << "}" << std::endl;
        int result = strStr(test.haystack, test.needle);
        std::cout << "\tRESULT: " << result << std::endl;
        std::cout << "========================================\n" << std::endl;
    }

    return 0;
}