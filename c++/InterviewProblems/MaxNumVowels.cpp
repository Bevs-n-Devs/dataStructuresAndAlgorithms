#include <iostream>
#include <math.h>
#include <map>

// Creating Test Structure
struct TestSet {
    std::string str;
    int substr_len;
};

// Creating different Test Sets
TestSet tests[] = {
    TestSet {"abciiidef", 3},
    TestSet {"abciiidef", 4},
    TestSet {"leetcode", 3},
} ;

void print_substr(std::string s, int l, int r){
    for (int i = l; l <= r; l++) {
        std::cout << s[l];
    }
}

// Solution function
int get_max_num_vowels(std::string s, int k) {
    int result = 0;
    std::map<char,int> mp;

    // catching constraint conditions
    if (s.size() < 1 || s.size() > pow(10,5)) return result;
    if (k >= s.size()) return result;
    
    // Using sliding window algo
    // Get the initial k size window index 0 to k-1 [ 0 1 ... k ]
    for (int i=0; i < k; i++) {
        // check for individual char errors
        if (s[i] < 'a' || s[i] > 'z') return 0;
        
        // count every lower case value in a map object
        if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') {
            mp[s[i]]++;
        }
    } 
    ;
    result = mp['a'] + mp['e'] + mp['i'] + mp['o'] + mp['u'];
    std::cout << "substring: [";
    print_substr(s,0,k-1); 
    std::cout << "] : " << result << std::endl;

    // shift the window by one, only subtracting the last initial
    // substring char and adding the new last sunstring char
    for (int i = 0; i < s.size()-k; i++) {
        if (s[i] < 'a' || s[i] > 'z') return 0;
        if (s[i+k] < 'a' || s[i+k] > 'z') return 0;
        mp[s[i]]--;
        mp[s[i+k]]++;
        int max = mp['a'] + mp['e'] + mp['i'] + mp['o'] + mp['u'];
        result = std::max(result, max);
        
        std::cout << "substring: [";
        print_substr(s,i+1, i+k);
        std::cout << "] : " << max << std::endl;
    }
    return result;
}

int main() {
    std::cout << "\nRunning Max Number of Vowels Leetcode Problem" << std::endl;
    std::cout << "===============================================" << std::endl;
    // Looping through tests
    for (auto test: tests){
        int ans1 = get_max_num_vowels(test.str, test.substr_len);
        std::cout << "For a string \"" << test.str <<"\", the max number of \n" \
                 "vowels in a given substring of " << test.substr_len <<" characters is: " \
                 << ans1  << "\n" << std::endl;
        
    std::cout << "===============================================" << std::endl;
    }

    
    return 1;
}