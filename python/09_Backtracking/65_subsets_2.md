Backtracking 4
# Subsets 2
## Company: Meta 
### Level: Medium

Given an integer array `nums` that may contain duplicates, return all possible **subsets** (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.

***Break It Down For Me...***
**

### Example 1
```
Input: nums = [1, 2, 2]
Output: [[], [1], [1, 2], [1, 2, 2], [2], [2, 2]]
```

### Example 2
```
Input: nums = [0]
Output: [[], [0]]
```

## Python 
```
class Solution:
    def subsetsWithDup(self, nums: List[int]) -> List[List[int]]:
        res = []
        nums.sort()  # Sort the numbers to handle duplicates

        def backtrack(i, subset):
            if i == len(nums):  # Base case: if we've considered all numbers
                res.append(subset[::])  # Add a copy of the current subset to the results
                return

            # Include nums[i] in the current subset
            subset.append(nums[i])
            backtrack(i + 1, subset)
            subset.pop()  # Backtrack and remove nums[i] from the current subset

            # Skip duplicates
            while i + 1 < len(nums) and nums[i] == nums[i + 1]:
                i += 1
            # Exclude nums[i] from the current subset and move to the next number
            backtrack(i + 1, subset)

        backtrack(0, [])  # Start the backtracking process
        return res
```

## JavaScript
```
var subsetsWithDup = function(nums) {
    nums.sort((a, b) => a - b);  // Sort the numbers to handle duplicates

    return dfs(nums);
};

const dfs = (nums, index = 0, set = [], subset = []) => {
    subset.push(set.slice())  // Add a copy of the current set to the subset

    for (let i = index; i < nums.length; i++) {
        const isDuplicate = (index < i) && (nums[i - 1] === nums[i])
        if (isDuplicate) continue;  // Skip duplicates

        backTrack(nums, i, set, subset);
    }

    return subset
}

const backTrack = (nums, i, set, subset) => {
    set.push(nums[i]);  // Include nums[i] in the current set
    dfs(nums, (i + 1), set, subset);  // Recurse with the next number
    set.pop();  // Backtrack and remove nums[i] from the current set
}
```

## Go
```
package main

import "sort"

func subsetsWithDup(nums []int) [][]int {
	n := len(nums)
	ans := make([][]int, 0, 1<<n)  // Initialize the result list with capacity for all subsets
	curr := make([]int, 0, n)  // Current subset being built
	sort.Ints(nums)  // Sort the numbers to handle duplicates
	var backtrack func(idx int)
	backtrack = func(idx int) {
		ans = append(ans, append([]int{}, curr...))  // Add a copy of the current subset to the results
		for i := idx; i < n; i++ {
			if i > idx && nums[i] == nums[i-1] {  // Skip duplicates
				continue
			}
			curr = append(curr, nums[i])  // Include nums[i] in the current subset
			backtrack(i + 1)  // Recurse with the next number
			curr = curr[:len(curr)-1]  // Backtrack and remove nums[i] from the current subset
		}
	}
	backtrack(0)  // Start the backtracking process
	return ans
}
```