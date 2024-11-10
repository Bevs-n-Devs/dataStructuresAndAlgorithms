#include <iostream>
#include <math.h>
#include "../Utils/utils.h"

typedef struct{
    long long A, B, expectedResult;
} Test;

Test TestCases[] = {
    Test{1, 11, 10},
    Test{75, 300, 5},
    Test{75, 350, 6},
    Test{999999999999, 999999999999, 1},
    Test{1, 9, 9},
};

long long getUniformIntegerCountInInterval(long long A, long long B) {
    /**
     * Gets the number of uniform integers from A to B inclusively
     * 
     * @param A : first integer to consider
     * @param B : second integer to 
     * 
     * @return number of unique integers as a long long
     * 
     */

    // Check constraints
    if (A < 1 | A > B) return 0;
    if (B > pow(10,12)) return 0;
    
    // base condition
    if (A == B) return 1;
    
    // set variables to store the result
    // and track A & B digit counts & lower 
    // limits
    long long res = 0;
    long long la = 1;
    long long numd_a = 1;
    
    // there are 9 'uniform' values for each digit 
    // place: e.g. single digits 1-9, 
    // 10's : 11, 22, 33, 44, 55, 66, 77, 88, 99
    // 100's : 111, 222, ... 999 etc
    
    // if B < 10, return the difference in A & B
    // as they are all uniform
    if (B<10) return (B-A+1);
    
    // Get the lower limit of A & its number of digits
    if (A>9) {
        // Dividing by the next digits place, returns the 
        // first digit in A, otherwise it's a 0. Loop this
        // until that digit is a non-zero value
        while (A/(la*9+1)){
            la*=10;
            la+=1;
            numd_a+=1;
        }
    } 

    // since B >= A, to save time we can ignore the
    // lower limits before it byt starting with A's
    long long lb = la;
    long long numd_b = numd_a;
    // Get the lower limit of B & its number of digits
    while (B/(lb*9+1)){
        lb*=10;
        lb+=1;
        numd_b+=1;
    }
    
    // Adjust A & B to be uniform if they're not already uniform
    if ((A/la)*la != A )
        A = ((A/la)+1)*la;
    if ((B/lb)*lb != B )
        B = (B/lb)*lb;
    
    // If A & B have the same number of digits
    // return their difference divided by the 
    // lower limit
    if (numd_b==numd_a) return (B-A)/la+1;
    
    // Get the uniform numbers from A to it's upper limit
    res+=(la*9-A)/la+1;
    // Get the digit's place in between A & B
    res+=((numd_b-numd_a-1)*9);
    // Get the uniform numbers from B to it's upper limit
    res+=(B-lb)/lb+1;

    return res;

}

int main(){
    std::cout << " --- Running Meta's Code Puzzle: Uniform Integers Solution --- " << std::endl;
    Test test;
    long long ans;
    for (int i=0;i<sizeof(TestCases)/sizeof(TestCases[0]);i++){
        test = TestCases[i];
        std::cout << "Test " << i+1 << std::endl;
        std::cout << "input: {A: " << test.A << ", B: " << test.B << ", expectedResult: " << test.expectedResult << "}" << std::endl;
        ans = getUniformIntegerCountInInterval(test.A, test.B);
        std::cout << "Actual Result: " << ans << std::endl;
        std::cout << "\n====================================================================================\n" << std::endl;
    }
}