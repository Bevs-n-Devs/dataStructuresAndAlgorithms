#include <iostream>
#include <math.h>
#include "../Utils/utils.h"

/**
 * Median of Two Sorted Arrays
 * 
 * Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.
 * The overall run time complexity should be O(log (m+n)).
 * 
 * 
 * Constraints:
 *      nums1.length == m
 *      nums2.length == n
 *      0 <= m <= 1000
 *      0 <= n <= 1000
 *      1 <= m + n <= 2000
 *      -10^6 <= nums1[i], nums2[i] <= 10^6
 */

/**
 * Test Object
 */
typedef struct{
    std::vector<int> nums1, nums2;
    double expectedResult;
}Test;

/**
 * Test Cases to validate solution
 */
Test TestCases[] = {
    Test{{},{1},1.00},
    Test{{1,3},{2},2.00},
    Test{{1,2},{3,4},2.50},
};
    
/**
 * Merges two vectors
 *
 * @param nums1: vector 1
 * @param nums2: vector 2
 *
 * @return a vector of doubles
 *
 */
std::vector<int> merge(std::vector<int> nums1, std::vector<int> nums2) {
    if (!nums2.size()) return nums1;
    if (!nums1.size()) return nums2;
    std::vector<int> v = {};
    while (nums1.size() && nums2.size()){
        // constraints check
        if (nums1[0] < std::pow(10,6)*-1 || nums1[0] > std::pow(10,6)) return {};
        if (nums2[0] < std::pow(10,6)*-1 || nums2[0] > std::pow(10,6)) return {};
        if (nums1[0] < nums2[0]) {
            v.push_back(nums1[0]);
            nums1.erase(nums1.begin());
        } else {
            v.push_back(nums2[0]);
            nums2.erase(nums2.begin());
        }
    }
    
    while (nums1.size()) {
        // constraints check
        if (nums1[0] < -1*pow(10,6) || nums1[0] > pow(10,6)) return {};
        v.push_back(nums1[0]);
        nums1.erase(nums1.begin());
    }
    
    while (nums2.size()) {
        // constraints check
        if (nums2[0] < -1*pow(10,6) || nums2[0] > pow(10,6)) return {};
        v.push_back(nums2[0]);
        nums2.erase(nums2.begin());
    }
    
    return v;
}

/**
 * Finds the median value of two sorted vectors/arrays
 *
 * @param nums1: vector of integers
 * @param nums2: vector of integers
 *
 * @return value of the median as a double
 * 
 */
double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) {
    // constraints check
    if (!nums1.size() && !nums2.size()) return 0.00;
    if (nums1.size() > 1000 || nums1.size() > 1000) return 0.00;
    if (nums1.size() + nums2.size() > 2000) return 0.00;
    
    // merge the vetors into one large vector
    std::vector<int> vec = merge(nums1,nums2);
    
    // if there was a constraints violation the 
    // merge would return an empty vector
    if (!vec.size()) return 0.00;
    
    // get the middle index of the vector
    int m = vec.size()/2;
    
    // if the vector is odd, return the value 
    // at the middle index of the vector
    if (vec.size()%2) return vec[m];
    // if the vector has an even size, get the average
    // value between the two middle indices
    else return (((double)vec[m]+(double)vec[m-1])/2);
}

int main() {
    std::cout << " --- Running Median Two Sorted Arrays LeetCode Problem --- " << std::endl;
    for (int i=0;i<sizeof(TestCases)/sizeof(TestCases[0]);i++){
        std::cout << "Test: " << i+1 << std::endl;
        std::cout << "input: {nums1: ";
        printVector_Int(TestCases[i].nums1);
        std::cout << ", nums2: ";
        printVector_Int(TestCases[i].nums2); 
        std::cout << ",\n\tExpected Result: " << TestCases[i].expectedResult << std::endl;
        double ans = findMedianSortedArrays(TestCases[i].nums1,TestCases[i].nums2);
        std::cout << "\t Actual Restul: " << ans << std::endl;
        std::cout << "==================================================================\n" << std::endl;
    }

    return 0;
}