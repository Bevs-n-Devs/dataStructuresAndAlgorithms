Backtracking 2
# Combination Sum
## Company: Amazon
### Level: Medium

Given an array of distinct integers candidates and a target integer target, return a list of all unique combinations of candidates where the chosen numbers sum to target. You may return the combinations in any order.

The same number may be chosen from candidates an unlimited number of times. Two combinations are unique if the 
frequency
 of at least one of the chosen numbers is different.

The test cases are generated such that the number of unique combinations that sum up to target is less than 150 combinations for the given input.

 ***Break It Down For Me...***
 **

 Click [here](https://leetcode.com/problems/subsets/description/)for the question on Leetcode.

Click [here](https://www.youtube.com/watch?v=REOH22Xwdkk) for the solution on [Neetcode](https://neetcode.io/) **(which I would strongly reccomed you to get familiar with.)**

To solve this challenge we will use a [Backtracking Algorithm](https://www.simplilearn.com/tutorials/data-structure-tutorial/backtracking-algorithm#:~:text=Backtracking%20is%20an%20algorithmic%20technique,meet%20them%20will%20be%20removed.) data structure in Python, JavaScript and Go.

### Example 1
```
Input: candidates = [2, 3, 6, 7], target = 7
Output: [[2, 2, 3], [7]]
```
**Explanation:** `2` and `3` are candidates, and `2 + 2 + 3 = 7`. Note that `2` can be used multiple times.
`7` is a candidate, and `7 = 7`. These are the only two combinations.

### Example 2
```
Input: candidates = [2, 3, 5], target = 8
Output: [[2, 2, 2, 2], [2, 3, 3], [3, 5]]
``` 

### Example 3
```
Input: candidates = [2], target = 1
Output: []
```

## Python
```
class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        res = []

        # Define the depth-first search (dfs) function
        def dfs(i, cur, total):
            # If the total equals the target, add the current combination to the result
            if total == target:
                res.append(cur.copy())
                return
            # If the index is out of bounds or the total exceeds the target, return early
            if i >= len(candidates) or total > target:
                return

            # Include the current candidate in the combination
            cur.append(candidates[i])
            # Recursively call dfs with the updated total
            dfs(i, cur, total + candidates[i])
            # Backtrack by removing the last element
            cur.pop()
            # Move to the next candidate
            dfs(i + 1, cur, total)

        # Start the dfs process from index 0, empty combination, and sum 0
        dfs(0, [], 0)
        return res
```

## JavaScript
```
var combinationSum = function (candidates, target, index = 0, combination = [], combinations = []) {
    // Base case: if the target becomes negative, return the combinations array
    const isBaseCase = target < 0;
    if (isBaseCase) return combinations;

    // Base case: if the target is 0, add the current combination to the combinations array
    const isTarget = target === 0;
    if (isTarget) return combinations.push(combination.slice());

    // Iterate through the candidates starting from the current index
    for (let i = index; i < candidates.length; i++) {
        backTrack(candidates, target, i, combination, combinations);
    }

    return combinations;
}

const backTrack = (candidates, target, i, combination, combinations) => {
    // Add the current candidate to the combination
    combination.push(candidates[i]);
    // Recursively call the combinationSum function with the updated target and combination
    combinationSum(candidates, (target - candidates[i]), i, combination, combinations);
    // Remove the last element to try the next candidate
    combination.pop();
}
```

## Go
```
package main

func combinationSum(candidates []int, target int) [][]int {
    // Initialize the result array to store all the combinations
    ans := make([][]int, 0)
    // Initialize a temporary array to store the current combination
    curr := make([]int, 0)

    // Define the backtrack function
    var backtrack func(idx int, currSum int, curr []int)
    backtrack = func(idx int, currSum int, curr []int) {
        // If the current sum equals the target, add the current combination to the result
        if currSum == target {
            ans = append(ans, append([]int{}, curr...))
            return
        }
        // If the current sum exceeds the target, return early
        if currSum > target {
            return
        }
        // Iterate through the candidates starting from the current index
        for i := idx; i < len(candidates); i++ {
            // Add the current candidate to the current combination
            curr = append(curr, candidates[i])
            // Recursively call the backtrack function with the updated sum and combination
            backtrack(i, currSum + candidates[i], curr)
            // Remove the last element to try the next candidate
            curr = curr[:len(curr) - 1]
        }
    }

    // Start the backtracking process from index 0 and sum 0
    backtrack(0, 0, curr)
    return ans
}
```