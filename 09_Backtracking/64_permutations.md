Backtracking 3
# Permutations
## Company: Meta & Google
### Level: Medium

Given an array `nums` of distinct integers, return all the possible permutations. You can return the answer in any order.

***Break It Down For Me...***
*We have a list of different numbers called nums. Our task is to find and return all the different ways we can arrange these numbers.*
*The order in which we return these arrangements doesn't matter.*

Click [here](https://leetcode.com/problems/permutations/description/)for the question on Leetcode.

Click [here](https://www.youtube.com/watch?v=s7AvT7cGdSo) for the solution on [Neetcode](https://neetcode.io/) **(which I would strongly reccomed you to get familiar with.)**

To solve this challenge we will use a [Backtracking Algorithm](https://www.simplilearn.com/tutorials/data-structure-tutorial/backtracking-algorithm#:~:text=Backtracking%20is%20an%20algorithmic%20technique,meet%20them%20will%20be%20removed.) data structure in Python, JavaScript and Go.

### Example 1
```
Input: nums = [1, 2, 3]
Output: [[1, 2, 3], [1, 3, 2], [2, 1, 3], [2, 3, 1], [3, 1, 2], [3, 2, 1]]
```

### Example 2
```
Input: nums = [0, 1]
Output: [[0, 1], [1, 0]]
```

### Example 3
```
Input: nums = [1]
Output: [[1]]
```

## Python
```
class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        res = []

        # Base case: if there's only one number left, return it as the only permutation
        if len(nums) == 1:
            return [nums[:]]  # nums[:] is a deep copy of nums

        for i in range(len(nums)):
            # Remove the first number from nums
            n = nums.pop(0)
            # Generate all permutations of the remaining numbers
            perms = self.permute(nums)

            # Add the removed number to the end of each permutation
            for perm in perms:
                perm.append(n)
            # Add these new permutations to the result list
            res.extend(perms)
            # Put the removed number back to its original position in nums
            nums.append(n)
        return res
```

## JavaScript
```
var permute = function(nums) {
    return dfs(nums)
}

var dfs = function(nums, permutation = [], permutations = []) {
    // Base case: if the current permutation is the same length as nums
    if (nums.length === permutation.length) {
        // Add a copy of the current permutation to the results
        permutations.push(permutation.slice())
        return permutations
    }

    // Iterate over each number in nums
    for (let i = 0; i < nums.length; i++) {
        // Skip if the number is already in the current permutation
        if (permutation.includes(nums[i])) continue;

        // Add the current number to the permutation and continue DFS
        backTrack(nums, i, permutation, permutations);
     }

    return permutations;
}

const backTrack = (nums, i, permutation, permutations) => {
    // Add the current number to the permutation
    permutation.push(nums[i])
    // Continue generating permutations with the current number included
    dfs(nums, permutation, permutations)
    // Remove the current number to backtrack
    permutation.pop()
}
```

## Go
```
package main

func permute(nums []int) [][]int {
	n := len(nums)
	ans := make([][]int, 0)
	curr := make([]int, 0, n)
	vis := make(map[int]int)

	var backtrack func(idx int)
	backtrack = func(idx int) {
		// Base case: if the current permutation is complete
		if len(curr) == n {
			// Add a copy of the current permutation to the results
			ans = append(ans, append([]int{}, curr...))
		}
		// Iterate over each number in nums
		for i := 0; i < n; i++ {
			// Skip if the number is already in the current permutation
			if vis[i] == 0 {
				vis[i]++
				// Add the current number to the permutation
				curr = append(curr, nums[i])
				// Continue generating permutations with the current number included
				backtrack(i + 1)
				// Remove the current number to backtrack
				curr = curr[:len(curr)-1]
				vis[i]--
			}
		}
	}
	backtrack(0)
	return ans
}
```