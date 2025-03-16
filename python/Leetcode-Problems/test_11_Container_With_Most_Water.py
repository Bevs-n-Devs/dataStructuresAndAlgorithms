import pytest

"""
11. Container With Most Water (Medium)
You are given an integer array height of length n. There are n vertical lines 
drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]). 
Find two lines that together with the x-axis form a container, such that the 
container contains the most water.

Return the maximum amount of water a container can store.

Notice that you may not slant the container.

Example 1:
    Input: height = [1,8,6,2,5,4,8,3,7]
    Output: 49
    Explanation: The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the container can contain is 49.

Example 2:

    Input: height = [1,1]
    Output: 1
 

Constraints:

    * n == height.length
    * 2 <= n <= 10^5
    * 0 <= height[i] <= 10^4
"""

class Test:
    """
    Test Class used to validate problem solutions
    """
    # The following is needed to remedy warning message
    # for this class being named "Test" but not being a 
    # pytest Test object
    __test__ = False
    def __init__(self, height: list[int], expectedResult: int):
        self.height = height
        self.expectedResult = expectedResult

TestCases = [
    Test(height=[1,8,6,2,5,4,8,3,7],expectedResult=49),
    Test(height=[1,1],expectedResult=1),
    Test(height=[8,7,2,1],expectedResult=7),
    Test(height=[2,3,4,5,18,17,6],expectedResult=17),
]

class Solution:
    def maxArea(self, height: list[int]) -> int:
        """
        Finds largest area, represented as a container of water

        @param height: collections of heights
        @type height: list[int]

        @rtype int
        """
        M = h = 0   # storing max area, and the smallest height
        l, r = 0,len(height)-1  # storing index pointers

        # Constraints Check 
        if r+1 < 2 or r+1 > 10**5: return M 
        
        # Loop from left to right, shrinking the window
        # inward
        while l < r:
            # Constraints checks
            if height[l] < 0 or height[l] > 10**4: return 0
            if height[r] < 0 or height[r] > 10**4: return 0
            
            #get the minimum height between to the two heights
            h = min(height[l],height[r])
            # Calculate the current area, and compare it to the
            # previous max area
            M = max(M,h*(r-l)) 

            # If the right pointer is larger, shift the left pointer  
            if height[r] > height[l]: l+=1
            # If the left pointer is larger or equal, shift the right pointer
            else: r-=1


        return M
    
def test_solution():
    S = Solution()
    for test in TestCases:
        assert test.expectedResult == S.maxArea(test.height), "Solution did not match the expected result"