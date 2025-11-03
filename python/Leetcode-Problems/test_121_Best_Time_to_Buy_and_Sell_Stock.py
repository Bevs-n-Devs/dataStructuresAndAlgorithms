import pytest

class Test:
    """
    Test Class used to validate problem solutions
    """
    # The following is needed to remedy warning message
    # for this class being named "Test" but not being a 
    # pytest Test object
    __test__ = False
    def __init__(self, prices: list[int], expectedResult: int):
        self.prices = prices
        self.expectedResult = expectedResult

TestCases = [
    Test(
        prices=[7,1,5,3,6,4],
        expectedResult=5,
    ),
    Test(
        prices=[7,6,4,3,1],
        expectedResult=0,
    ),
]

class Solution:
    def maxProfit(self, prices: list[int]) -> int:
        if len(prices) < 2 or len(prices) > 10**5: return 0

        max_profit = prices[1] - prices[0]
        min_val = prices[0]
        if min_val > 10**4 or min_val < 0: return 0

        for i in range(1, len(prices)):
            val = prices[i]
            if val > 10**4 or val < 0: return 0
            if val < min_val:
                min_val = val

            max_profit = max(max_profit, val-min_val)
            # print()

        return max_profit
    
def test_solution():
    S = Solution()
    for test in TestCases:
        assert test.expectedResult == S.maxProfit(test.prices), "Solution did not match the expected result"
