1-Dymanic Programming 2
# Min Cost Climbing Stairs
## Company: Google
### Level: Easy

You are given an integer array `cost` where `cost[i]` is the cost of `ith` step on a staircase. Once you pay the cost, you can either climb one or two steps.

You can either start from the step with index `0`, or the step with index `1`.

*Return the minimum cost to reach the top of the floor.*

 ***Break It Down For Me...***
 *We have a list of numbers called `cost`.*
 *Each number in the list tells us how much it costs to step on that step of a staircase.*
*We can start at either the first step (index `0`) or the second step (index `1`).*

*From any step, we can move to the next step or skip one step (moving two steps at once).*
*Our goal is to find the smallest cost needed to reach the top of the staircase.*

Click [here](https://leetcode.com/problems/min-cost-climbing-stairs/description/)for the question on Leetcode.

Click [here](https://www.youtube.com/watch?v=ktmzAZWkEZ0) for the solution on [Neetcode](https://neetcode.io/) **(which I would strongly reccomed you to get familiar with.)**

To solve this challenge we will use [Dynamic Programming](https://www.geeksforgeeks.org/dynamic-programming/) in Python, JavaScript & Go.

### Example 1
```
Input: cost = [10,15,20]
Output: 15

# Explanation: You will start at index 1.
- Pay 15 and climb two steps to reach the top.
# The total cost is 15.
```

### Example 2
```
Input: cost = [1,100,1,1,1,100,1,1,100,1]
Output: 6

# Explanation: You will start at index 0.
- Pay 1 and climb two steps to reach index 2.
- Pay 1 and climb two steps to reach index 4.
- Pay 1 and climb two steps to reach index 6.
- Pay 1 and climb one step to reach index 7.
- Pay 1 and climb two steps to reach index 9.
- Pay 1 and climb one step to reach the top.
# The total cost is 6.
```

## Python
```
class Solution:
    def minCostClimbingStairs(self, cost: List[int]) -> int:
        # Iterate from the third-to-last step to the first step
        for i in range(len(cost) - 3, -1, -1):
            # Update the cost at each step with the minimum cost of stepping to the next step or skipping one step
            cost[i] += min(cost[i + 1], cost[i + 2])

        # The answer is the minimum cost of starting from the first or second step
        return min(cost[0], cost[1])
```

## JavaScript
```
var minCostClimbingStairs = (cost, i = cost.length, memo = new Map()) => {
    // Base case: If the current index is 0 or 1, the cost is 0
    const isBaseCase = i <= 1;
    if (isBaseCase) return 0;

    // If the cost for the current step is already computed, return it
    if (memo.has(i)) return memo.get(i);

    // Calculate the cost of stepping from the previous step and the step before the previous step
    const [prev, prevPrev] = [(i - 1), (i - 2)];
    const downOne = minCostClimbingStairs(cost, prev, memo) + cost[prev];        // Time O(N) | Space O(N)
    const downTwo = minCostClimbingStairs(cost, prevPrev, memo) + cost[prevPrev];// Time O(N) | Space O(N)

    // Store the minimum cost for the current step in the memoization map
    memo.set(i, Math.min(downOne, downTwo));

    // Return the minimum cost for the current step
    return memo.get(i);
}
```

## Go
```
func minCostClimbingStairs(cost []int) int {
    n := len(cost)
    dp := make([]int, n+1)

    // Special case: If there are only two steps, return the minimum cost of the two steps
    if n == 2 {
        return min(cost[0], cost[1])
    }

    // Iterate through each step starting from the second step
    for i := 2; i <= n; i++ {
        // Calculate the cost of stepping from the previous step and the step before the previous step
        a := dp[i-1] + cost[i-1]
        b := dp[i-2] + cost[i-2]

        // Store the minimum cost for the current step
        dp[i] = min(a, b)
    }

    // The answer is the minimum cost to reach the top of the stairs
    return dp[n]
}

// Helper function to return the minimum of two integers
func min(x, y int) int {
    if x > y {
        return y
    }
    return x
}
```