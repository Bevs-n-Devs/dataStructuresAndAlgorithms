1-Dymanic Programming 7
# Coin Change
## Company: Meta / Facebook
### Level: Medium

You are given an integer array `coins` representing coins of different denominations and an integer `amount` representing a total amount of money.

Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return `-1`.

You may assume that you have an infinite number of each kind of coin.

***Break It Down For Me...***
*We have a list of `coins` with different values, and a number representing a total `amount` of money.*
*Our goal is to find the smallest number of coins needed to make exactly that amount of money.*
*If it's impossible to make that amount with the given coins, return `-1`.*
*We can use as many coins of each type as we need.*

Click [here](https://leetcode.com/problems/coin-change/description/) for the question on Leetcode.

Click [here](https://www.youtube.com/watch?v=H9bfqozjoqs) for the solution on [Neetcode](https://neetcode.io/) **(which I would strongly reccomed you to get familiar with.)**

To solve this challenge we will use [Dynamic Programming](https://www.geeksforgeeks.org/dynamic-programming/) in Python, JavaScript & Go.


### Example 1
```
Input: coins = [1,2,5], amount = 11
Output: 3

# Explanation: 11 = 5 + 5 + 1
```

### Example 2
```
Input: coins = [2], amount = 3
Output: -1
```

### Example 3
```
Input: coins = [1], amount = 0
Output: 0
```

## Python
```
class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        # Initialize a list to store the minimum number of coins needed for each amount
        dp = [amount + 1] * (amount + 1)
        # Base case: 0 coins are needed to make the amount 0
        dp[0] = 0

        # Iterate through each amount from 1 to the given amount
        for a in range(1, amount + 1):
            # Check each coin in the given list of coins
            for c in coins:
                # If the coin can be used (it's not greater than the current amount)
                if a - c >= 0:
                    # Update the number of coins needed to make the current amount
                    dp[a] = min(dp[a], 1 + dp[a - c])
        # If the value for the given amount is still amount + 1, it means it's not possible to make that amount
        return dp[amount] if dp[amount] != amount + 1 else -1
```

## JavaScript
```
var coinChange = (coins, amount, coin = 0) => {
    // Base case: if the amount is 0, no coins are needed
    const isBaseCase1 = amount === 0;
    if (isBaseCase1) return 0;

    // Base case: if no coins are left or amount is negative, return -1
    const isBaseCase2 = !((coin < coins.length) && (0 < amount));
    if (isBaseCase2) return -1;

    // Recursive function to find the minimum number of coins needed
    return dfs(coins, amount, coin);
}

var dfs = (coins, amount, coin) => {
    // Initialize variables to keep track of the maximum number of coins and minimum cost
    let [ max, minCost ] = [ (amount / coins[coin]), Infinity ];

    // Iterate through each possible number of coins for the current denomination
    for (let num = 0; num <= max; num++) {
        // Check if the current number of coins can be used without exceeding the amount
        const caUpdate = ((num * coins[coin]) <= amount);
        if (!caUpdate) continue;

        // Calculate the remaining amount after using the current number of coins
        const product = (num * coins[coin]);
        const difference = amount - product;

        // Recursive call to find the minimum number of coins needed for the remaining amount
        const min = coinChange(coins, difference, (coin + 1));
        const cost = (min + num);

        // Skip invalid solutions
        const isSentinel = (min === -1);
        if (isSentinel) continue;

        // Update the minimum cost if a better solution is found
        minCost = Math.min(minCost, cost);
    }

    // Return the minimum cost found, or -1 if no valid solution exists
    return (minCost !== Infinity)
        ? minCost
        : -1;
}
```

## Go
```
func coinChange(coins []int, amount int) int {
	// Initialize a slice to store the minimum number of coins needed for each amount
	changes := make([]int, amount+1)
	for i := range changes {
		// Set each value to a high number (amount + 1) to represent infinity
		changes[i] = amount + 1
	}
	// Base case: 0 coins are needed to make the amount 0
	changes[0] = 0

	// Iterate through each amount from 1 to the given amount
	for i := 1; i < amount+1; i++ {
		// Check each coin in the given list of coins
		for _, c := range coins {
			// If the coin can be used (it's not greater than the current amount)
			if c <= i {
				// Update the number of coins needed to make the current amount
				changes[i] = min(changes[i], 1+changes[i-c])
			}
		}
	}
	// If the value for the given amount is still amount + 1, it means it's not possible to make that amount
	if changes[amount] != amount+1 {
		return changes[amount]
	}
	// Otherwise, return -1 indicating it's not possible to make the amount with the given coins
	return -1
}

// Helper function to return the minimum of two integers
func min(x, y int) int {
	if x < y {
		return x
	}
	return y
}
```
