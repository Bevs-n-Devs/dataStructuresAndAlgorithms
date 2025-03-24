import pytest

"""
53. Maximum Subarray (Medium)

Given an integer array nums, find the subarray with the largest sum, 
and return its sum. 

Example 1:
    Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
    Output: 6
    Explanation: The subarray [4,-1,2,1] has the largest sum 6.

Example 2:
    Input: nums = [1]
    Output: 1
    Explanation: The subarray [1] has the largest sum 1.

Example 3:
    Input: nums = [5,4,-1,7,8]
    Output: 23
    Explanation: The subarray [5,4,-1,7,8] has the largest sum 23.
 

Constraints:
    * 1 <= nums.length <= 10^5
    * -10^4 <= nums[i] <= 10^4
 
Follow up: If you have figured out the O(n) solution, try coding 
another solution using the divide and conquer approach, which is 
more subtle.
"""

class Test:
    """
    Test Class used to validate problem solutions
    """
    # The following is needed to remedy warning message
    # for this class being named "Test" but not being a 
    # pytest Test object
    __test__ = False
    def __init__(self, nums: list[int], expectedResult: int):
        self.nums = nums
        self.expectedResult = expectedResult

TestCases = [
    Test(nums=[-2,1,-3,4,-1,2,1,-5,4],expectedResult=6),
    Test(nums=[1],expectedResult=1),
    Test(nums=[5,4,-1,7,8],expectedResult=23),
    Test(nums=[-1],expectedResult=-1),
    Test(nums=[-2,-1],expectedResult=-1),
]

class Solution:
    def maxSubArray(self, nums: list[int]) -> int:
        """
        Finds the max subarray sum within a given 
        array. This approach uses Kadane's Algorithm

        @param nums: list of integer values to consider
        @ptype nums: list[int]

        @return the maximum subarray sum 
        """
        # Constraints Check
        if len(nums) == 0 or len(nums) > pow(10,5): return 0
        
        maxSum = -pow(10,5)
        curSum = 0
        for i in range(len(nums)):
            # Constraints Check
            if nums[i] < -pow(10,4) or nums[i] > pow(10,5): return 0

            curSum+=nums[i]
            # if the new value decreases the currSum below 0,
            # set the curSum to the new array value at index i
            # the negating values are not valuable as they don't
            # encourage finding the MAXIMUM SUM
            curSum = max(nums[i],curSum)
            maxSum = max(curSum,maxSum) # compares curSum to maxSum
        
        return maxSum

def test_solution():
    S = Solution()
    for test in TestCases:
        assert test.expectedResult == S.maxSubArray(nums=test.nums), "solution did not match result"