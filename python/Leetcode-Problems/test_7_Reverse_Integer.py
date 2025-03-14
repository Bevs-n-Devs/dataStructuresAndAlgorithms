import pytest

"""
7. Reverse Integer (Medium)

Given a signed 32-bit integer x, return x with its digits 
reversed. If reversing x causes the value to go outside the 
signed 32-bit integer range [-2^31, 2^31 - 1], then return 0.

Assume the environment does not allow you to store 64-bit 
integers (signed or unsigned).

Example 1:

    Input: x = 123
    Output: 321

Example 2:

    Input: x = -123
    Output: -321

Example 3:

    Input: x = 120
    Output: 21
 

Constraints:
    * -2^31 <= x <= 2^31 - 1
"""

class Test:
    """
    Test Class used to validate problem solutions
    """
    # The following is needed to remedy warning message
    # for this class being named "Test" but not being a 
    # pytest Test object
    __test__ = False
    def __init__(self, x: int, expectedResult: int):
        self.x = x
        self.expectedResult = expectedResult

TestCases = [
    Test(x=123,expectedResult=321),
    Test(x=-123,expectedResult=-321),
    Test(x=120,expectedResult=21),
    Test(x=1534236469,expectedResult=0),
]

class Solution:
    def reverse(self, x: int) -> int:
        """
        Reverses a integer's digits

        @param x: integer to reverse
        @ptype x: int

        @rtype int
        """
        # Constraints Check
        if x < -(2**31) or x >= 2**31: return 0

        # Base case check
        if x < 10 and x > -10: return x
        
        # using negative flag to simplify algo
        isNegative = x < 0
        if isNegative: x*=-1
        
        n = 0
        while x > 0:
            # Constraints check
            if n >= 2**31: return 0
            d=x%10 # get 1's digit
            n*=10  # shifts value by 1 digit's place <-
            n+=d
            x-=d
            x//=10 # shifts value by 1 digit's place ->
        
         # Constraints check
        if n >= 2**31: return 0

        if isNegative: return -n
        return n 

def test_solution():
    S = Solution()
    for test in TestCases:
        assert test.expectedResult == S.reverse(x=test.x), "solution did not match result"