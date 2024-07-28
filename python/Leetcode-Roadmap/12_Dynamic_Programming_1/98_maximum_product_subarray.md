1-Dymanic Programming 8
# Maximum Product Subarray 
## Company: Amazon
### Level: Medium

Given an integer array `nums`, find a *subarray* that has the largest product, and return the product.

The test cases are generated so that the answer will fit in a 32-bit integer.

***Break It Down For Me...***
*We have an array of numbers called `nums`. The task is to find a part of this array (called a subarray) that gives the highest product when we multiply all its numbers together.*
*Then, return that highest product.*
*For example, if `nums` is `[2, 3, -2, 4]`, the best part of the array would be `[2, 3]`, because `2 * 3 = 6`, and `6` is the highest product we can get from any part of this array.*
*The answer will always fit in a **32-bit integer**, which means it won't be too large or too small.*

Click [here](https://leetcode.com/problems/maximum-product-subarray/description/) for the question on Leetcode.

Click [here](https://www.youtube.com/watch?v=lXVy6YWFcRM) for the solution on [Neetcode](https://neetcode.io/) **(which I would strongly reccomed you to get familiar with.)**

To solve this challenge we will use [Dynamic Programming](https://www.geeksforgeeks.org/dynamic-programming/) in Python, JavaScript & Go.

### Example 1
```
Input: nums = [2,3,-2,4]
Output: 6

# Explanation: [2,3] has the largest product 6.
```

### Example 2
```
Input: nums = [-2,0,-1]
Output: 0

# Explanation: The result cannot be 2, because [-2,-1] is not a subarray.
```

## Python
```
class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        # Initialize the result with the first element in the array
        res = nums[0]
        # Initialize curMin and curMax to handle the product of subarrays
        curMin, curMax = 1, 1

        for n in nums:
            # Temporary variable to store the current maximum product
            tmp = curMax * n
            # Update curMax to be the maximum of three options:
            # 1. The current number times the current maximum product
            # 2. The current number times the current minimum product
            # 3. The current number itself
            curMax = max(n * curMax, n * curMin, n)
            # Update curMin to be the minimum of three options:
            # 1. The temporary maximum product (curMax * n)
            # 2. The current number times the current minimum product
            # 3. The current number itself
            curMin = min(tmp, n * curMin, n)
            # Update the result to be the maximum of the result and the current maximum product
            res = max(res, curMax)
        return res
```

## JavaScript
```
var maxProduct = (nums) => {
    // Check if the array is empty and return 0 if it is
    const isEmpty = nums.length === 0;
    if (isEmpty) return 0;

    return linearSearch(nums); // Call the linear search function to find the maximum product subarray
}

const linearSearch = (nums, max = nums[0]) => {
    // Loop through each element in the array
    for (let index = 0; index < nums.length; index++) {
        max = getMax(nums, index, max); // Update the maximum product found so far
    }

    return max;
}

const getMax = (nums, index, max, product = 1) => {
    // Loop through the subarray starting from the current index
    for (let num = index; num < nums.length; num++) {
        product *= nums[num]; // Calculate the product of the subarray
        max = Math.max(max, product); // Update the maximum product found so far
    }

    return max;
}
```

## Go
```
func maxProduct(nums []int) int {
    // Initialize the result, current minimum, and current maximum
    res, curMin, curMax := nums[0], 1, 1
    
    for i := 0; i < len(nums); i++ {
        // Temporary variable to store the current maximum product
        temp := curMax * nums[i]
        // Update curMax to be the maximum of three options:
        // 1. The current number times the current maximum product
        // 2. The current number times the current minimum product
        // 3. The current number itself
        curMax = max(max(nums[i] * curMax, nums[i] * curMin), nums[i])
        // Update curMin to be the minimum of three options:
        // 1. The temporary maximum product (curMax * nums[i])
        // 2. The current number times the current minimum product
        // 3. The current number itself
        curMin = min(min(temp, nums[i] * curMin), nums[i])
        // Update the result to be the maximum of the result and the current maximum product
        res = max(res, curMax)
    }
    return res
}

// Helper function to find the maximum of two integers
func max(a int, b int) int {
    if (a > b) {
        return a
    }
    return b
}

// Helper function to find the minimum of two integers
func min(a int, b int) int {
    if (a < b) {
        return a
    }
    return b
}
```