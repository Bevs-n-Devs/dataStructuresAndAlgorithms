1-Dymanic Programming 2
# House Robber 2
## Company: Google
### Level: Medium 

You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed. All houses at this place are arranged in a circle. That means the first house is the neighbor of the last one. Meanwhile, adjacent houses have a security system connected, and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given an integer array `nums` representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.

***Break It Down For Me...***
*Imagine that we are robbers, and we want to steal money from houses arranged in a circle.*
*Each house has some money, and we can see how much money each house has in a list called `nums`.*

*Here are the rules:*

- *The houses are in a circle, so the first house and the last house are neighbors.*
- *We can't rob two houses next to each other on the same night, because the security system will alert the police.*

*The task is to find out the maximum amount of money we can steal without getting caught by the police.*


Click [here](https://leetcode.com/problems/house-robber-ii/description/)for the question on Leetcode.

Click [here](https://www.youtube.com/watch?v=rWAJCfYYOvM) for the solution on [Neetcode](https://neetcode.io/) **(which I would strongly reccomed you to get familiar with.)**

To solve this challenge we will use [Dynamic Programming](https://www.geeksforgeeks.org/dynamic-programming/) in Python, JavaScript & Go.


### Example 1
```
Input: nums = [2,3,2]
Output: 3

# Explanation: You cannot rob house 1 (money = 2) and then rob house 3 (money = 2), because they are adjacent houses.
```

### Example 2
```
Input: nums = [1,2,3,1]
Output: 4

# Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
# Total amount you can rob = 1 + 3 = 4.
```

## Python
```
class Solution:
    def rob(self, nums: List[int]) -> int:
        # If there is only one house, return the money in that house.
        if len(nums) == 1:
            return nums[0]
        
        # If there are two houses, return the maximum money between the two houses.
        if len(nums) == 2:
            return max(nums[0], nums[1])
        
        # Calculate the maximum money by considering two scenarios:
        # 1. Rob from the first house to the second last house.
        # 2. Rob from the second house to the last house.
        return max(self.helper(nums[1:]), self.helper(nums[:-1]))

    # Helper function to calculate the maximum money in a linear array of houses.
    def helper(self, nums):
        rob1, rob2 = 0, 0

        # Iterate through the houses, updating the max money that can be robbed.
        for n in nums:
            newRob = max(rob1 + n, rob2)
            rob1 = rob2
            rob2 = newRob
        return rob2
```

## JavaScript
```
var rob = (nums) => {
    const isBaseCase1 = (nums.length === 0);
    if (isBaseCase1) return 0;

    const isBaseCase2 = (nums.length === 1);
    if (isBaseCase2) return nums[0]

    // Calculate the maximum money by considering two scenarios:
    // 1. Rob from the first house to the second last house.
    // 2. Rob from the second house to the last house.
    const left = search(nums, 0, (nums.length - 2)); /* Time O(N) */
    const right = search(nums, 1, (nums.length - 1));/* Time O(N) */

    return Math.max(left, right);
};

// Helper function to calculate the maximum money in a linear array of houses.
const search = (nums, start, end) => {
    let [ left, mid ] = [ 0, 0 ];

    // Iterate through the houses, updating the max money that can be robbed.
    for (let i = start; i <= end; i++) {/* Time O(N) */
        const temp = mid;
        const right = nums[i];
        const house = left + right;

        mid = Math.max(mid, house);
        left = temp;
    }

    return mid;
}
```



## Go
```
func rob(nums []int) int {
    n := len(nums)
    
    // If there is only one house, return the money in that house.
    if n == 1 {
        return nums[0]
    }
    
    // If there are two houses, return the maximum money between the two houses.
    if n == 2 {
        return max(nums[0], nums[1])
    }
    
    // Calculate the maximum money by considering two scenarios:
    // 1. Rob from the first house to the second last house.
    // 2. Rob from the second house to the last house.
    return max(robUtil(nums, 0, n-1), robUtil(nums, 1, n))
}

// Helper function to calculate the maximum money in a linear array of houses.
func robUtil(nums []int, st, end int) int {
    dp := make([]int, len(nums))
    dp[st] = nums[st]
    dp[st+1] = max(nums[st], nums[st+1])
    
    // Iterate through the houses, updating the dp array with the maximum money that can be robbed.
    for i := st+2; i < end; i++ {
        dp[i] = max(nums[i] + dp[i-2], dp[i-1])
    }
    
    return dp[end-1]
}

// Function to return the maximum of two integers.
func max(a, b int) int {
    if a > b {
        return a
    }
    return b
}
```