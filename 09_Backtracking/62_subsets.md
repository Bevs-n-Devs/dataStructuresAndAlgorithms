Backtracking 1
# Subsets
## CVompany: Meta
### Level: Medium

Given an integer array `nums` of **unique** elements, return all possible subsets (the power set).

The solution set must not contain duplicate subsets. Return the solution in **any order**.

***Break It Down For Me...***
*We have a list of numbers, called `nums`, and each number in the list is different from the others.*
*We need to find all the different groups (subsets) of numbers that we can make from this list.*
*This includes every possible group, from an empty group (with no numbers) to the group that contains all the numbers in the list.*
*The groups should not be repeated.*
*The order of the groups in our answer does not matter.*

Click [here](https://leetcode.com/problems/subsets/description/)for the question on Leetcode.

Click [here](https://www.youtube.com/watch?v=REOH22Xwdkk) for the solution on [Neetcode](https://neetcode.io/) **(which I would strongly reccomed you to get familiar with.)**

To solve this challenge we will use a [Backtracking Algorithm](https://www.simplilearn.com/tutorials/data-structure-tutorial/backtracking-algorithm#:~:text=Backtracking%20is%20an%20algorithmic%20technique,meet%20them%20will%20be%20removed.) data structure in Python, JavaScript and Go.

### Example 1
```
Input: nums = [1, 2, 3]
Output: [[], [1], [2], [1, 2], [3], [1, 3], [2, 3], [1, 2, 3]]
```

### Example 2
```
Input: nums = [0]
Output: [[], [0]]
```

## Python
```
from typing import List

class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        # This will hold all the subsets
        res = []

        # This will hold the current subset we are building
        subset = []

        # Helper function for depth-first search
        def dfs(i):
            # If we've considered all elements
            if i >= len(nums):
                # Add the current subset to the result (make a copy of it)
                res.append(subset.copy())
                return
            # Decision to include nums[i] in the subset
            subset.append(nums[i])
            dfs(i + 1)
            # Decision to not include nums[i] in the subset (backtrack)
            subset.pop()
            dfs(i + 1)

        # Start the DFS from the 0th index
        dfs(0)
        return res
```

## JavaScript
```
// Function to generate all subsets
var subsets = (nums) => {
    // Sort the numbers (not necessary for subset generation, but good practice)
    nums.sort((a, b) => a - b);

    // Start the DFS with initial parameters
    return dfs(nums)
}

// Helper function for depth-first search
var dfs = (nums, level = 0, set = [], subset = []) => {
    // Add the current set (make a copy of it) to the subset list
    subset.push(set.slice());

    // Loop through the numbers starting from the current level
    for (let i = level; i < nums.length; i++){
        // Include nums[i] in the current set and continue the search
        backTrack(nums, i, set, subset);
    }

    return subset
}

// Function to handle the inclusion of nums[i] and the recursive call
const backTrack = (nums, i, set, subset) => {
    // Include nums[i] in the current set
    set.push(nums[i]);
    // Continue the search with the next level
    dfs(nums, (i + 1), set, subset);
    // Remove nums[i] from the current set (backtrack)
    set.pop();
}
```

## Go
```
package main

func subsets(nums []int) [][]int {
    // This will hold all the subsets
    ans := make([][]int, 0)
    
    // This will hold the current subset we are building
    curr := make([]int, 0)
    
    // Helper function for backtracking
    var backtrack func(idx int)
    backtrack = func(idx int) {
        // Add the current subset (make a copy of it) to the result
        ans = append(ans, append([]int{}, curr...))
        
        // If we've considered all elements, return
        if idx == len(nums) {
            return
        }
        
        // Loop through the numbers starting from the current index
        for i := idx; i < len(nums); i++ {
            // Include nums[i] in the current subset
            curr = append(curr, nums[i])
            // Continue the search with the next index
            backtrack(i + 1)
            // Remove nums[i] from the current subset (backtrack)
            curr = curr[:len(curr)-1]
        }
    }
    
    // Start the backtracking from the 0th index
    backtrack(0)
    return ans
}
```