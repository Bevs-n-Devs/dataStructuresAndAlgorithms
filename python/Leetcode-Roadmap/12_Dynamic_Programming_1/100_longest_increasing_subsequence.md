1-Dymanic Programming 11
# Longest Increasing Subsequence
## Company: Google
### Level: Medium 

Given an integer array `nums`, return the length of the **longest strictly increasing subsequence**.

***Break It Down For Me...***
*Imagine we have a list of numbers (like a shopping list).*
*Each number in the list represents an item.*
*Now, we want to find the longest sequence of numbers where each number is bigger than the one before it.*
*It’s like finding the longest chain of steps going up a staircase, where each step is higher than the previous*


Click [here](https://leetcode.com/problems/longest-increasing-subsequence/description/) for the question on Leetcode.

Click [here](https://www.youtube.com/watch?v=cjWnW0hdF1Y) for the solution on [Neetcode](https://neetcode.io/) **(which I would strongly reccomed you to get familiar with.)**

To solve this challenge we will use [Dynamic Programming](https://www.geeksforgeeks.org/dynamic-programming/) in Python, JavaScript & Go.

### Example 1
```
Input: nums = [10,9,2,5,3,7,101,18]
Output: 4

# Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.

```

### Example 2
```
Input: nums = [0,1,0,3,2,3]
Output: 4
```

### Example 3
```
Input: nums = [7,7,7,7,7,7,7]
Output: 1
```

## Python
```
class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        # Initialize an array to store the length of the longest increasing subsequence (LIS)
        LIS = [1] * len(nums)

        # Iterate through the array in reverse order
        for i in range(len(nums) - 1, -1, -1):
            # Compare the current element with all subsequent elements
            for j in range(i + 1, len(nums)):
                # If the current element is less than the subsequent element,
                # update the LIS value for the current element
                if nums[i] < nums[j]:
                    LIS[i] = max(LIS[i], 1 + LIS[j])

        # Return the maximum LIS value
        return max(LIS)
```

## JavaScript
```
var lengthOfLIS = (nums) => {
    // Initialize an array called 'tabu' with the same length as 'nums'
    // Each element represents the length of the longest increasing subsequence (LIS) ending at that index
    const tabu = initTabu(nums); /* Space O(N) */

    // Perform a nested loop to compare elements and update 'tabu'
    linearSearch(nums, tabu); /* Time O(N^2) | Space O(N) */

    // Return the maximum value in the 'tabu' array, which represents the overall length of the LIS
    return Math.max(...tabu); /* Time O(N) */
};

// Initialize the 'tabu' array with all elements set to 1
const initTabu = (nums) => new Array(nums.length).fill(1);

// Function to update 'tabu' based on comparisons between elements
var linearSearch = (nums, tabu) => {
    for (let right = 1; right < nums.length; right++) { /* Time O(N) */
        for (let left = 0; left < right; left++) { /* Time O(N) */
            const canUpdate = nums[left] < nums[right];
            if (!canUpdate) continue;

            // Calculate the potential new LIS length for the current 'right' index
            const [ _left, _right ] = [ tabu[left] + 1, tabu[right] ];
            tabu[right] = Math.max(_right, _left); /* Space O(N) */
        }
    }
}
```

## Go
```
func lengthOfLIS(nums []int) int {
	// Initialize an array called 'cache' to store the length of the longest increasing subsequence (LIS)
	cache := make([]int, len(nums))

	// Initialize a variable 'LIS' to keep track of the maximum LIS length
	LIS := 0

	// Iterate through the 'nums' array
	for i := range nums {
		// Initialize a variable 'curMax' to track the maximum LIS length ending at index 'i'
		curMax := 0

		// Compare 'nums[i]' with all previous elements (from index 0 to 'i')
		for j := 0; j < i+1; j++ {
			if nums[j] < nums[i] {
				// If 'nums[j]' is less than 'nums[i]', update 'curMax' if necessary
				if curMax < cache[j] {
					curMax = cache[j]
				}
			}
		}

		// Update the 'cache' value for the current index 'i'
		cache[i] = curMax + 1

		// Update 'LIS' if the current LIS value is greater than the previous maximum
		if cache[i] > LIS {
			LIS = cache[i]
		}
	}

	// Return the overall maximum LIS length
	return LIS
}
```