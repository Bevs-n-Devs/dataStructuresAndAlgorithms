#include "../Utils/utils.h"
#include <algorithm>
#include <math.h>

/**
 * 189. Rotate Array [Medium]
 * 
 * Given an integer array nums, rotate the array to the right by k steps, where k is non-negative.
 * 
 * Constraints:
 *      * 1 <= nums.length <= 10^5
 *      * -2^31 <= nums[i] <= 2^31 - 1
 *      * 0 <= k <= 10^5
 * 
 */

struct Test{
    std::vector<int> nums, expectedResult;
    int k;
    /**
     * Test Constructor
     * 
     * @param nums : vector of integers
     * @param k : number of rotations to execute
     * @param expectedResult : vector of integers for the expected result rotated
     * 
     */
};

/**
 * Test Cases for the Solution
 */
struct Test TestCases[] = {
    Test{{1,2,3,4,5,6,7}, {5,6,7,1,2,3,4}, 3},
    Test{{1,2}, {1,2}, 2},
    Test{{-1,-100,3,99}, {3,99,-1,-100},2},
};

void rotate(std::vector<int>& nums, int k) {
    /**
     * Rotates a given vector or integers
     * 
     * @param nums : vector of integers to rotate
     * @param k : number of rotations to make
     * 
     */

    // Constraints check
    if (!nums.size() || nums.size() > std::pow(10,5)) return;
    if (k < 0 || k > std::pow(10,5)) return;
    if(nums.front() < -1*std::pow(2,31) || nums.front() >= std::pow(2,31)) return;
    
    // to avoid duplicate rotations, get the remainder of rotations from
    // the size of the vector
    int r = k%nums.size();
    // if the remainder is 0, exit immediately 
    if (!r) return;
    // reverse entire vector
    std::reverse(nums.begin(),nums.end());
    // reverse vector from beginning to the number of rotations index
    std::reverse(nums.begin(),nums.begin()+r);
    // reverse vector from the number of rotations index to the end of the vector
    std::reverse(nums.begin()+r,nums.end());
    
}

int main() {
    std::cout << " --- Rotate Array Leetcode Problem --- " << std::endl;
    for (int i=0; i<sizeof(TestCases)/sizeof(TestCases[0]);i++){
        Test test = TestCases[i];
        std::cout << "Test " << i+1 << std::endl;
        std::cout << "input: { nums: ";
        printVector_Int(test.nums);
        std::cout << ", number of rotations: " << test.k;
        std::cout << ", expectedResult: ";
        printVector_Int(test.expectedResult);
        std::cout << "}" << std::endl;
        rotate(test.nums, test.k);
        std::cout << "\tActual Result: ";
        printVector_Int(test.nums);
        std::cout << "\n=========================================================\n" << std::endl;
    }

    return 0;
}