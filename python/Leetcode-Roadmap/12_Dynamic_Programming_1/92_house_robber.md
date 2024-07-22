1-Dymanic Programming 3
# House Robber
## Company: Google
### Level: Medium 

You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected and **it will automatically contact the police if two adjacent houses were broken into on the same night.**

Given an integer array `nums` representing the amount of money of each house, return the maximum amount of money you can rob tonight **without alerting the police.**

***Break It Down For Me...***
*We are robbers planning to steal money from houses along a street. Each house has a certain amount of money.*
*However, we cannot rob two houses that are next to each other because their security systems are connected.*
*If we rob two adjacent houses, the alarm will go off, and the police will be alerted.*

*We are given a list of numbers where each `number` represents the amount of money in a house. We need to figure out the maximum amount of money we can steal without triggering the alarm.*

Click [here](https://leetcode.com/problems/house-robber/description/)for the question on Leetcode.

Click [here](https://www.youtube.com/watch?v=73r3KWiEvyk) for the solution on [Neetcode](https://neetcode.io/) **(which I would strongly reccomed you to get familiar with.)**

To solve this challenge we will use [Dynamic Programming](https://www.geeksforgeeks.org/dynamic-programming/) in Python, JavaScript & Go.

### Example 1
```
Input: nums = [1,2,3,1]
Output: 4

# Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
# Total amount you can rob = 1 + 3 = 4.
```
### Example 2
```
Input: nums = [2,7,9,3,1]
Output: 12

# Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).
# Total amount you can rob = 2 + 9 + 1 = 12.
```

## Python
```
class Solution:
    def rob(self, nums: List[int]) -> int:
        # Initialize two variables to store the maximum money robbed up to the two previous houses
        rob1, rob2 = 0, 0

        # Iterate through each house
        for n in nums:
            # Calculate the maximum money that can be robbed if the current house is included
            temp = max(n + rob1, rob2)
            # Update rob1 to be the value of rob2 for the next iteration
            rob1 = rob2
            # Update rob2 to be the maximum amount calculated for the current house
            rob2 = temp
        # The maximum amount robbed will be stored in rob2
        return rob2
```

## JavaScript
```
var rob = (nums, i = 0) => {
    // Base case: if we have gone through all the houses
    const isBaseCase = nums.length <= i;
    if (isBaseCase) return 0;

    // Get the next two indices
    const [ next, nextNext ] = [ (i + 1), (i + 2) ];
    // Current house's money
    const right = nums[i];
    // Calculate the money if we skip the current house
    const mid = rob(nums, next);     /* Time O(2^N) | Space O(N) */
    // Calculate the money if we rob the current house and move to the house after the next
    const left = rob(nums, nextNext);/* Time O(2^N) | Space O(N) */
    // Total money if we rob the current house
    const house = left + right;

    // Return the maximum money between robbing the current house and skipping it
    return Math.max(house, mid);
};
```

## Go
```
func rob(nums []int) int {
    // Initialize a slice to store the maximum money robbed up to each house
    dp := make([]int, len(nums)+2)
    
    // Iterate through each house starting from the third element in dp (index 2)
    for i := 2; i < len(dp); i++ {
        // Calculate the maximum money that can be robbed if the current house is included
        if dp[i-1] > dp[i-2] + nums[i-2] {
            dp[i] = dp[i-1]
        } else {
            dp[i] = dp[i-2] + nums[i-2]
        }
    }
    
    // The maximum amount robbed will be stored in the last element of dp
    return dp[len(dp)-1]
}
```