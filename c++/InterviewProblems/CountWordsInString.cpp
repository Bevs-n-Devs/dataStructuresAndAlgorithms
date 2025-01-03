#include <iostream>
#include <assert.h>
#include <string>

/**
 * Test struct to store tests to validate the solution
 */
struct Test {
    std::string s;
    int expectedResult;
};

/**
 * Collection of tests
 */
Test TestCases[] = {
    Test{"Hello world", 2},
    Test{"", 0},
    Test{"   ", 0},
    Test{"   This is my tester   ", 4},
};

/**
 * Function to count the number of words in a string
 * 
 * @param s: string to parse
 * 
 * @return number of words
 */
int countWordsInString(std::string s){
    // constraints check
    if (!s.size()) return 0;

    // clean leading and trailing spaces
    while (s.front() == ' ') s = {s.begin()+1, s.end()};
    while (s.back() == ' ') s = {s.begin(), s.begin()+s.size()-1};
    
    // check after cleaning the string
    if (!s.size()) return 0;

    int cnt = 0;
    // get the position of spaces, to get the number of words
    while (s.find(' ') != -1){
        s = {s.begin()+s.find(' ')+1, s.end()};
        cnt+=1;
    }

    return cnt+1;
}

int main(int argc, char **kwargs) {
    std::cout << " -- Running the CountWordsInString Solution -- "  << std::endl;
    Test test;
    
    for (int i=0;i<sizeof(TestCases)/sizeof(TestCases[0]);i++){
        test = TestCases[i];
        std::cout << "Test " << i+1 << std::endl;
        std::cout << "input: {string: \"" << test.s << "\", expectedResult: " << test.expectedResult << "}" << std::endl;
        assert(test.expectedResult == countWordsInString(test.s));
    }
}