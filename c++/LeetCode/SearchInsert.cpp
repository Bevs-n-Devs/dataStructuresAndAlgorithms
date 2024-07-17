#include <iostream>
#include <math.h>
#include <vector>

/**
 * Search Insert Position
 * 
 * Given a sorted array of distinct integers and a target value, return the 
 * index if the target is found. If not, return the index where it would be 
 * if it were inserted in order. You must write an algorithm with O(log n) 
 * runtime complexity.
 * 
 * Constraints:
 *      * 1 <= nums.length <= 104
 *      * -104 <= nums[i] <= 104
 *      * nums contains distinct values sorted in ascending order.
 *      * -104 <= target <= 104
 * 
 */


/**
 * Test Object
 */
struct Test {
    std::vector<int> nums;
    int target;
    int expectedResult;
    /**
     * Prints the test vector
     */
    void printVector() {
        std::cout << "[";
        for (auto n : nums) {
            if (n == nums.front()) std::cout << n;
            else std::cout << ", " << n;
        }

        std::cout << "]";
    }
};

/**
 * Array of Tests to run
 */
Test TestCases[] = {
    Test{{1,3,5},2,1},
    Test{{1,3,5,6},5,2},
    Test{{1,3,5,6},2,1},
    Test{{1,3,5,6},7,4},
};

int searchInsert(std::vector<int>& nums, int target) {
    // check constraints
    if (nums.size() < 1 || nums.size() > pow(10,4)) return -1;
    if (target < -1*(pow(10, 4)) || target > pow(10,4)) return -1;
    if (nums[0] < -1*(pow(10, 4)) || nums[0] > pow(10,4)) return -1;
    
    int mid = nums.size()/2;
    int pos = 0;
    
    // catch out of bounds
    if (target < nums[0]) return pos;
    if (target > nums[nums.size()-1]) return nums.size();
    
    while (nums.size() > 1){
        // check contraints
        if (nums[0] < -1*(pow(10, 4)) || nums[0] > pow(10,4)) return -1;
        if (nums[0] > nums[1]) return -1;
        
        // check for matching value
        if (target == nums[0]) return pos;
        if (target == nums[mid]) return pos+mid;
        if (target == nums[nums.size()-1]) return pos+nums.size()-1;
        // catch out of bounds
        
        
        // split vector in half by mid point
        if (target > nums[mid-1]){
            pos += mid;
            nums = {nums.begin()+mid, nums.end()};
        }
        else {
            nums = {nums.begin(), nums.begin()+mid};
        }
        
        mid = nums.size()/2;
    }
    
    // if the value was not found, return last known position
    return pos;
}

int main() {
    std::cout << "--- Running Search Insert Problem ---" << std::endl;
    int i = 0;
    for (auto test: TestCases) {
        std::cout << "Test " << i << std::endl;
        std::cout << "\tinput:\t";
        test.printVector();
        std::cout << ", target: " << test.target << ", Expected Result: " << test.expectedResult << std::endl;
        int result = searchInsert(test.nums, test.target);
        std::cout << "\tRESULT: " << result << std::endl;
        std::cout << "===============================================================\n" << std::endl;
        i+=1;
    }
    return 0;
}