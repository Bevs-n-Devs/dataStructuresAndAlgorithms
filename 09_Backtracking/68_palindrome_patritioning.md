Backtracking 7
# Palindrome Patritioning 
## Company: Google
### Level: Medium

Given a string `s`, partition `s` such that every **substring** of the partition is a **palindrome**. *Return all possible palindrome partitioning of `s`.*

***Break It Down For Me...***
*We have a string `s`.*
*Our task is to split this string into parts so that each part is a palindrome (a word that reads the same backward as forward).*
*We have to find all the different ways that we can split the string in this way.*

Click [here](https://leetcode.com/problems/palindrome-partitioning/description/)for the question on Leetcode.

Click [here](https://www.youtube.com/watch?v=3jvWodd7ht0) for the solution on [Neetcode](https://neetcode.io/) **(which I would strongly reccomed you to get familiar with.)**

To solve this challenge we will use a [Backtracking Algorithm](https://www.simplilearn.com/tutorials/data-structure-tutorial/backtracking-algorithm#:~:text=Backtracking%20is%20an%20algorithmic%20technique,meet%20them%20will%20be%20removed.) data structure in Python, JavaScript and Go.

### Example 1
```
Input: s = "aab"
Output: [["a", "a", "b"], ["aa", "b"]]
```

### Example 2
```
Input: s = "a"
Output: [["a"]]
```

## Python
```
class Solution:
    def partition(self, s: str) -> List[List[str]]:
        res, part = [], []  # Resultant list of palindrome partitions and current partition

        # Depth-First Search function to find all partitions
        def dfs(i):
            # If we reach the end of the string, add the current partition to the result
            if i >= len(s):
                res.append(part.copy())
                return
            # Iterate through the string starting from index `i`
            for j in range(i, len(s)):
                # Check if the substring s[i:j+1] is a palindrome
                if self.isPali(s, i, j):
                    # If it's a palindrome, add it to the current partition
                    part.append(s[i : j + 1])
                    # Recur with the next index
                    dfs(j + 1)
                    # Backtrack by removing the last added substring
                    part.pop()

        # Start DFS from the beginning of the string
        dfs(0)
        return res

    # Helper function to check if a substring s[l:r+1] is a palindrome
    def isPali(self, s, l, r):
        while l < r:
            if s[l] != s[r]:
                return False
            l, r = l + 1, r - 1
        return True
```

## JavaScript
```
```
function partition(s, left = 0, _partition = [], partitions = []) {
    // Base case: if the left index reaches the end of the string, add the current partition to the result
    const isBaseCase = s.length <= left
    if (isBaseCase) {
        if (_partition.length) partitions.push(_partition.slice());
        return partitions;
    }

    // Iterate through the string starting from the left index
    for (let right = left; right < s.length; right++) {
        // Skip if the substring s[left:right+1] is not a palindrome
        if (!isPalindrome(s, left, right)) continue;

        // Backtrack by adding the substring and recursing
        backTrack(s, left, right, _partition, partitions);
    }

    return partitions;
}

const backTrack = (s, left, right, _partition, partitions) => {
    // Add the substring s[left:right+1] to the current partition
    _partition.push(s.slice(left, right + 1));
    // Recur with the next index
    partition(s, right + 1, _partition, partitions);
    // Backtrack by removing the last added substring
    _partition.pop();
}

const isPalindrome = (str, left, right) => {
    // Check if the substring str[left:right+1] is a palindrome
    while (left < right) {
        const isSame = str[left] === str[right];
        if (!isSame) return false;

        left++;
        right--;
    }

    return true;
}

## Go
```
package main

func partition(s string) [][]string {
    ans := make([][]string, 0) // Resultant list of palindrome partitions
    curr := make([]string, 0)  // Current partition

    // Backtracking function to find all partitions
    var backtrack func(idx int)
    backtrack = func(idx int) {
        // If we reach the end of the string, add the current partition to the result
        if idx == len(s) {
            ans = append(ans, append([]string{}, curr...))
        }
        // Iterate through the string starting from index `idx`
        for i := idx; i < len(s); i++ {
            // Check if the substring s[idx:i+1] is a palindrome
            if isPalindrome(s[idx : i+1]) {
                // If it's a palindrome, add it to the current partition
                curr = append(curr, s[idx:i+1])
                // Recur with the next index
                backtrack(i + 1)
                // Backtrack by removing the last added substring
                curr = curr[:len(curr)-1]
            }
        }
    }
    // Start backtracking from the beginning of the string
    backtrack(0)
    return ans
}

// Helper function to check if a string is a palindrome
func isPalindrome(s string) bool {
    l := 0
    r := len(s) - 1
    for l < r {
        if s[l] != s[r] {
            return false
        }
        l++
        r--
    }
    return true
}
```