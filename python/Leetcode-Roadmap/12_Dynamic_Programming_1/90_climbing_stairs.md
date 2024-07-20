1-Dymanic Programming 1
# Climbing Stairs
## Company: Amazon
### Level: Easy

You are climbing a staircase. It takes `n` steps to reach the top.

Each time you can either climb `1` or `2` steps. In how many distinct ways can you climb to the top?

***Break It Down For Me...***
*We need to climb a staircase that has `n` steps.*
*Each time we climb, you can either take `1` step or `2` steps.*
*We need to figure out how many different ways can we reach the top of the staircase.*

Click [here](https://leetcode.com/problems/climbing-stairs/description/)for the question on Leetcode.

Click [here](https://www.youtube.com/watch?v=Y0lT9Fck7qI) for the solution on [Neetcode](https://neetcode.io/) **(which I would strongly reccomed you to get familiar with.)**

To solve this challenge we will use [Dynamic Programming](https://www.geeksforgeeks.org/dynamic-programming/) in Python, JavaScript & Go.

### Example 1
```
Input: n = 2
Output: 2

# Explanation: There are two ways to climb to the top.
# 1. 1 step + 1 step
# 2. 2 steps
```

### Example 2
```
Input: n = 3
Output: 3

# Explanation: There are three ways to climb to the top.
# 1. 1 step + 1 step + 1 step
# 2. 1 step + 2 steps
# 3. 2 steps + 1 step
```

## Python
```
class Solution:
    def climbStairs(self, n: int) -> int:
        # If the number of steps is 3 or less, return n directly
        if n <= 3:
            return n

        # Initialize the number of ways to reach step 2 and step 3
        n1, n2 = 2, 3

        # Calculate the number of ways to reach each step from 4 to n
        for i in range(4, n + 1):
            # The number of ways to reach the current step is the sum of the
            # ways to reach the two previous steps
            temp = n1 + n2

            # Move the pointers one step up
            n1 = n2
            n2 = temp

        # Return the number of ways to reach the nth step
        return n2
```

## JavaScript
```
/**
 * DP - Fibonacci Number
 * Time O(N) | Space O(1)
 * https://leetcode.com/problems/climbing-stairs/
 * @param {number} n
 * @return {number}
 */
var climbStairs = (n) => {
    // Base case: if there is only one step, there is only one way to climb it
    const isBaseCase = (n === 1);
    if (isBaseCase) return 1;

    // Initialize the number of ways to reach the first two steps
    let [ next, nextNext ] = [ 1, 2 ];

    // Calculate the number of ways to reach each step from 3 to n
    for (let index = 3; (index <= n); index++) {
        // The number of ways to reach the current step is the sum of the
        // ways to reach the two previous steps
        const temp = (next + nextNext);

        // Move the pointers one step up
        next = nextNext;
        nextNext = temp;
    }

    // Return the number of ways to reach the nth step
    return nextNext;
};
```

## Go
```
func climbStairs(n int) int {
    // Initialize two variables to represent the number of ways to reach
    // the last step (one) and the second-to-last step (two).
    one, two := 1, 1

    // Loop from 0 to n-2, since we have already initialized the first two steps.
    for i := 0; i < n-1; i++ {
        // Calculate the number of ways to reach the current step by summing
        // the ways to reach the previous two steps.
        sum := one + two
        // Update the values of 'one' and 'two' to move to the next step.
        one, two = two, sum
    }

    // Return the number of ways to reach the top step.
    return two
}
```