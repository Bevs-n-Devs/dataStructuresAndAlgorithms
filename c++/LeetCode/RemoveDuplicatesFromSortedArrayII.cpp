#include "../Utils/utils.h"
#include <math.h>
#include <assert.h>

/**
 * Given an integer array nums sorted in non-decreasing order, 
 * remove some duplicates in-place such that each unique 
 * element appears at most twice. The relative order of the 
 * elements should be kept the same.
 * 
 * Since it is impossible to change the length of the array in 
 * some languages, you must instead have the result be placed 
 * in the first part of the array nums. More formally, if there 
 * are k elements after removing the duplicates, then the first 
 * k elements of nums should hold the final result. It does not 
 * matter what you leave beyond the first k elements.
 * 
 * Return k after placing the final result in the first k slots 
 * of nums.
 * 
 * Do not allocate extra space for another array. You must do 
 * this by modifying the input array in-place with O(1) extra 
 * memory.
 * 
 * Constraints:
 *      * 1 <= nums.length <= 3 * 104
 *      * -104 <= nums[i] <= 104
 *      * nums is sorted in non-decreasing order.
 * 
 */

/**
 * Test Object
 */
typedef struct {
    std::vector<int> nums;
    std::vector<int> expectedResult;
} Test;

/**
 * Collection of Test Cases
 */
Test TestCases[]{
    Test{{1,1,1,2,2,3},{1,1,2,2,3}},
    Test{{0,0,1,1,1,1,2,3,3},{0,0,1,1,2,3,3}},
};

/**
 * Removes values that repeat more than twice
 * 
 * @param nums: vector of integers to check
 * 
 * @return the number of elements left after removing duplicates
 * 
 */
int removeDuplicates(std::vector<int>& nums) {
    // check constraints
    if (nums.size() < 3 || nums.size() > 3*pow(10,4)) return nums.size();
    
    int i = 0;
    while(i+2<nums.size()){
        // check constraints
        if(nums[i] < -1*pow(10,4) || nums[i] > pow(10,4)) return nums.size();
        
        // if a duplicate is found, delete it
        // from the vector, and recursively call
        // the function
        if(nums[i] == nums[i+2]){
            nums.erase(nums.begin()+i+2);
            return removeDuplicates(nums);
        } 

        // if no duplicates found, continue iterating through the
        // vector
        i++;
    }
    
    return nums.size();
}

int main(){
    std::cout << "--- Running Remove Duplicates from sorted Linked List Problem ---" << std::endl;
    
    int i = 1;
    for (auto test: TestCases) {
        std::cout << "Test " << i << std::endl;
        std::cout << "\tinput: ";
        printVector_Int(test.nums);
        std::cout << std::endl;
        std::cout << ", Expected Result: ";
        printVector_Int(test.expectedResult);
        std::cout << "\n\tRESULT: ";
        removeDuplicates(test.nums);
        assert (test.expectedResult==test.nums);
        printVector_Int(test.nums);
        std::cout << "\n========================================================\n" << std::endl;
        i+=1;
    }

    return 0;
}