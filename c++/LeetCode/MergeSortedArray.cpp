#include <iostream>
#include <vector>
#include <math.h>

/**
 * Merge Sorted Array
 * 
 * You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, 
 * and two integers m and n, representing the number of elements in nums1 and nums2 
 * respectively.
 * 
 * Merge nums1 and nums2 into a single array sorted in non-decreasing order.
 * 
 * The final sorted array should not be returned by the function, but instead be 
 * stored inside the array nums1. To accommodate this, nums1 has a length of m + n, 
 * where the first m elements denote the elements that should be merged, and the 
 * last n elements are set to 0 and should be ignored. nums2 has a length of n.
 * 
 * Constraints:
 *    * nums1.length == m + n
 *    * nums2.length == n
 *    * 0 <= m, n <= 200
 *    * 1 <= m + n <= 200
 *    * -10^9 <= nums1[i], nums2[j] <= 10^9
 */

/**
 * Test structure 
 * 
 * Used to store different test objects
 */
struct Test {
    std::vector<int> nums1;
    int m;
    std::vector<int> nums2;
    int n;

    /**
     * Prints one or both test vectors
     * 
     * @param isResult : boolean value to print result is true (only nums1), otherwise print both vectors
     */
    void printVectors(bool isResult=false) {
        if (isResult) std::cout << " - RESULT - \t" << " [";
        else std::cout << " - input - \tm:" << m << " [";
        for (auto i: nums1){
            if (i == nums1.front()) std::cout << i;
            else std::cout << "," << i ;
        }
        std::cout<< "]";
        if (isResult) std::cout << std::endl;
        else { 
            std::cout << ", n:" << n << " [";
            for (auto i: nums2){
                if (i == nums2.front()) std::cout << i;
                else std::cout << "," << i ;
            }
            std::cout<< "]" << std::endl;
        }
    }

    /**
     * Prints the result vector only
     */
    void printResult() {
        printVectors(true);
    }
};

/**
 * Array of Tests
 */
Test TestCases[] = {
    Test{
        {1,2,3,0,0,0}, 
        3, 
        {2,5,6},
        3
    },
    Test{
        {1}, 
        1, 
        {},
        0
    },
    Test{
        {0}, 
        0, 
        {1},
        1
    },
};

/**
 * Simple Solution
 * 
 * @param nums1 : vector of integers
 * @param m : integer repesenting number of filled spaces in nums1
 * @param nums2 : vector of integers
 * @param n : integer repesenting number elements in nums2
 */
void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n) {
    if (nums1.size() != m+n) return;
    if (nums2.size() != n) return;
    if (m < 0 || n > 200) return;
    if (m+n < 1 || m+n > 200) return;
    int ulmt = pow(10, 9);
    int llmt = pow(-10, 9);
    
    int i = 0;
    while (nums2.size()) {
        if (nums2[0] > ulmt) return;
        if (i >= m) {
            nums1[i] = nums2[0];
            nums2.erase(nums2.begin());
        }
        else if (nums2[0] < nums1[i]) {
            if (nums1[i] < llmt) return;
            
            nums1.insert(nums1.begin()+i, nums2[0]);
            nums1.pop_back();
            nums2.erase(nums2.begin());
            m+=1;
        }
        i+=1;
    }
}

int main() {
    int i = 0;
    std::cout << "--- Merge Sorted Array Problem ---" << std::endl;
    for(auto test: TestCases) {
        std::cout << "Running test case : " << i+1 << std::endl;
        test.printVectors();
        merge(test.nums1, test.m, test.nums2, test.n);
        test.printResult();
        std::cout << "=====================================" << std::endl;
        i+=1;
    }
    return 0;
}