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
    """
    Object to hold TestCases
    """
    def __init__(self, nums:int, target:int, expectedResult:int) -> None:
        """
        Initializes the TestCase object

        @param nums: list of numbers to search
        @param target: value to search for in the list
        @param expectedResult: the correct answer for the TestCase
        """
        self.nums = nums
        self.target = target
        self.expectedResult = expectedResult

"""
List of Test Cases to test the problem solution
"""
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
    """
    Solution for LeetCode Problem
    """
    def search(nums: list[int], target: int) -> int:
        """
        This solution uses a binary search approach to search
        for the given target value.

        @param nums: list of values to search
        @param target: value to search for

        @return index of the given target value if found, -1 will 
        be returne if the target isn't found or invalid params were 
        provided
        """

        # Check Constraints
        if len(nums) < 1 or len(nums) > 5000:
            return -1
        if target < -(10**4) or target > 10**4:
            return -1

        # Set pointers for binary search
        l = 0
        r = len(nums)-1

        # loop until a value is found or until the
        # range has been exceeded
        while l <= r :
            # constraints check
            if target > nums[r] and target < nums[l]:
                return -1
            
            # returns values if found
            if (nums[l] == target):
                return l
            if (nums[r] == target):
                return r

            # catchs condition when there are not values found
            if r-l < 2:
                return -1
            
            # finds the center index
            c = (r+l)//2
            
            # checks the center value for a match
            if nums[c] == target:
                return c

            # checks positions when there is a rotation that
            # has occurred in the list range
            if nums[l] <= nums[c]:
                # If the target is greater than the center
                # value, search the right side of the list
                if target < nums[l] or target > nums[c]:
                    l = c+1
                    r-=1
                # If the target is less than the center
                # value search the left side of the list
                else:
                    r = c-1
                    l+=1 
            else:
                # If the target is greater than the center
                # value, search the right side of the list
                if target < nums[c] or target > nums[r]:
                    r = c-1
                    l+=1 
                # If the target is less than the center
                # value search the left side of the list
                else:  
                    l = c+1
                    r-=1 
            
            
        return -1

def test_solution():
    for test in TestCases:
        assert test.expectedResult == Solution.search(nums=test.nums, target=test.target), "solution did not match expected result"