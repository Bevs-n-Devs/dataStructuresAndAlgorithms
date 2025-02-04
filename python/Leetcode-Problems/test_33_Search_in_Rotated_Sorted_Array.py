import pytest

"""
33. Search in Rotated Sorted Array

There is an integer array nums sorted in ascending order (with distinct values).

Prior to being passed to your function, nums is possibly rotated at an unknown pivot index k (1 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3 and become [4,5,6,7,0,1,2].

Given the array nums after the possible rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.

You must write an algorithm with O(log n) runtime complexity.

 

Example 1:

Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4
Example 2:

Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1
Example 3:

Input: nums = [1], target = 0
Output: -1
 

Constraints:

    * 1 <= nums.length <= 5000
    * -10^4 <= nums[i] <= 10^4
    * All values of nums are unique.
    * nums is an ascending array that is possibly rotated.
    * -10^4 <= target <= 10^4
"""
class TESTCASE:
    def __init__(self, nums:int, target:int, expectedResult:int) -> int:
        self.nums = nums
        self.target = target
        self.expectedResult = expectedResult

TestCases = [
    TESTCASE([4,5,6,7,0,1,2], 0, 4),
    TESTCASE([4,5,6,7,0,1,2], 3, -1),
    TESTCASE([1], 0, -1),
    TESTCASE([8,9,2,3,4], 9, 1),
    TESTCASE([5,1,2,3,4], 1, 1),
    TESTCASE([1,3,5], 3, 1),
    TESTCASE([3,5,1], 1, 2),
]
class Solution:
    def search(nums: list[int], target: int) -> int:
        if len(nums) < 1 or len(nums) > 5000:
            return -1
        if target < -(10**4) or target > 10**4:
            return -1


        l = 0
        r = len(nums)-1

        while l <= r :
            if target > nums[r] and target < nums[l]:
                return -1
            if (nums[l] == target):
                return l
            if (nums[r] == target):
                return r

            if r-l < 2:
                return -1
            
            c = (r+l)//2
            if nums[c] == target:
                return c

            if nums[l] <= nums[c]:
                if target < nums[l] or target > nums[c]:
                    l = c+1
                    r-=1
                else:
                    r = c-1
                    l+=1 
            else:
                if target < nums[c] or target > nums[r]:
                    r = c-1
                    l+=1 
                else:  
                    l = c+1
                    r-=1 
            
            
        return -1

def test_solution():
    for test in TestCases:
        assert test.expectedResult == Solution.search(nums=test.nums, target=test.target), "solution did not match expected result"