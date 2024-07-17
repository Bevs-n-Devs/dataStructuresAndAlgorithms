#include <iostream>
#include <vector>

/**
 * Test Object
 */
struct Test {
    std::vector<int> digits;
    std::vector<int> expectedResult;

    /**
     * Prints the digits vector
     * 
     * @param isResult: bool to print the result or input vector
     */
    void printVector(bool isResult=0) {
        std::vector<int> v;
        if (isResult) v = expectedResult;
        else v = digits;
        std::cout << "[";
        for (auto n: v) {
            if (v.front() == n) std::cout << n;
            else std::cout << "," << n;
        }

        std::cout << "]";
    }
};

/**
 * Test Cases
 */
Test TestCases[] = {
    Test{{0},{1}},
    Test{{9},{1,0}},
    Test{{1,2,3},{1,2,4}},
    Test{{4,3,2,1},{4,3,2,2}},
};

/**
* Adds 1 to the int vector and returns the result 
*
* @param digits : int vector storing the long integer
*
* @return int vector of new incremented long number
*
*/
std::vector<int> plusOne(std::vector<int>& digits) {
    // check constraints
    if (digits.size() < 1) return {1};
    if (digits.size() > 100) return {};
    if (!digits[0] & digits.size() > 1) return {};
    
    int i = digits.size()-1;
    int c = (digits[i]+1)/10; // gets carry over value
    digits[i] = (digits[i]+1) - 10*c; // stores single's digit
    
    
    while (c) {
        // check constraints
        if(digits[i] < 0 || digits[i] > 9) return {};
        
        // catch beginning of vector
        if (!i) {
            digits.insert(digits.begin(), c);
            return digits;
        }
        
        i-=1;
        c = (digits[i]+1)/10; // gets carry over value
        digits[i] = (digits[i]+1) - 10*c;
        
    }
    
    return digits;
}

int main(){
    std::cout << "--- Running Plus One Problem ---" << std::endl;
    int i = 1;
    for (auto test: TestCases) {
        std::cout << "Test " << i << std::endl;
        std::cout << "\tinput: ";
        test.printVector();
        std::cout << ", Expected Result: ";
        test.printVector(1);
        test.digits = plusOne(test.digits);
        std::cout << "\n\tRESULT: ";
        test.printVector();
        std::cout << "\n========================================================\n" << std::endl;
        i+=1;
    }

}