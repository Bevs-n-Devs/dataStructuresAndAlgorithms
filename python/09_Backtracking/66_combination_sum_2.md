Backtracking 5
# Combination Sum 2
## Company: Amazon
### Level: Medium 

Given a collection of candidate numbers (`candidates`) and a target number (`target`), find all unique combinations in `candidates` where the candidate numbers sum to `target`.

Each number in `candidates` may only be used once in the combination.

Note: The solution set must not contain duplicate combinations.


***Break It Down For Me...***
*We have a list of numbers called `candidates` and a target number called `target`.*
*Our goal is to find all the different groups of numbers from candidates that add up to target.*
*Each number in candidates can be used only once in each group.*
*Also, we cannot have any duplicate groups in the final answer.*


Click [here](https://leetcode.com/problems/combination-sum-ii/description/)for the question on Leetcode.

Click [here](https://www.youtube.com/watch?v=rSA3t6BDDwg) for the solution on [Neetcode](https://neetcode.io/) **(which I would strongly reccomed you to get familiar with.)**

To solve this challenge we will use a [Backtracking Algorithm](https://www.simplilearn.com/tutorials/data-structure-tutorial/backtracking-algorithm#:~:text=Backtracking%20is%20an%20algorithmic%20technique,meet%20them%20will%20be%20removed.) data structure in Python, JavaScript and Go.

### Example 1
```
Input: candidates = [10, 1, 2, 7, 6, 1, 5], target = 8
Output: 
[
[1,1,6],
[1,2,5],
[1,7],
[2,6]
]
```

### Example 2
```
Input: candidates = [2, 5, 2, 1, 2], target = 5
Output: 
[
[1,2,2],
[5]
]
```

### Python
```
class Solution:
    def combinationSum2(self, candidates: List[int], target: int) -> List[List[int]]:
        candidates.sort() # Sort the candidates list to handle duplicates easily
        res = [] # Initialize the result list

        def backtrack(cur, pos, target):
            if target == 0: # If the target is zero, add the current combination to the result
                res.append(cur.copy())
                return
            if target < 0: # If the target is negative, return
                return

            prev = -1
            for i in range(pos, len(candidates)):
                if candidates[i] == prev: # Skip duplicates
                    continue
                cur.append(candidates[i]) # Add the current number to the combination
                backtrack(cur, i + 1, target - candidates[i]) # Recur with the next index and updated target
                cur.pop() # Remove the last number from the combination (backtrack)
                prev = candidates[i] # Update the previous number to the current number

        backtrack([], 0, target) # Start the backtracking process
        return res
```

### JavaScript
```
var combinationSum2 = function(candidates, target) {
    candidates.sort((a, b) => a - b); // Sort the candidates array to handle duplicates easily

    return dfs(candidates, target);
};

const dfs = (candidates, target, index = 0, combination = [], combinations = []) => {
    if (target < 0) return combinations; // If the target becomes negative, return

    if (target === 0) { // If the target is zero, add the combination to the result
        if (combination.length) combinations.push(combination.slice());
        return combinations;
    }

    for (let i = index; i < candidates.length; i++) {
        if (index < i && candidates[i - 1] === candidates[i]) continue; // Skip duplicates

        backTrack(candidates, target, i, combination, combinations);
    }

    return combinations;
}

const backTrack = (candidates, target, i, combination, combinations) => {
    combination.push(candidates[i]); // Add the current number to the combination
    dfs(candidates, target - candidates[i], i + 1, combination, combinations); // Recur with the next index and updated target
    combination.pop(); // Remove the last number from the combination (backtrack)
}
```

### Go
```
package main

import "sort"

func combinationSum2(candidates []int, target int) [][]int {
    ans := make([][]int, 0) // Initialize the result list
    curr := make([]int, 0)  // Initialize the current combination list
    sort.Ints(candidates)   // Sort the candidates list to handle duplicates easily

    var backtrack func(idx int, currSum int, curr []int)
    backtrack = func(idx int, currSum int, curr []int) {
        if currSum == target { // If the current sum equals the target, add the current combination to the result
            ans = append(ans, append([]int{}, curr...))
            return
        }
        if currSum > target { // If the current sum exceeds the target, return
            return
        }
        for i := idx; i < len(candidates); i++ {
            if i > idx && candidates[i] == candidates[i-1] { // Skip duplicates
                continue
            }
            curr = append(curr, candidates[i]) // Add the current number to the combination
            backtrack(i+1, currSum+candidates[i], curr) // Recur with the next index and updated sum
            curr = curr[:len(curr)-1] // Remove the last number from the combination (backtrack)
        }
    }
    backtrack(0, 0, curr) // Start the backtracking process
    return ans
}
```