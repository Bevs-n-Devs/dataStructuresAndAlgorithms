1-Dymanic Programming 10
# Word Break
## Company: Google
### Level: Medium 

Given a string `s` and a dictionary of strings `wordDict`, return `true` if `s` can be segmented into a space-separated sequence of one or more dictionary words.

Note that the same word in the dictionary may be reused multiple times in the segmentation.

***Break It Down For Me...***
*We have a string `s` and a list of words called `wordDict`.*
*Our task is to find out if we can break the string `s` into smaller pieces, where each piece is a word from `wordDict`.*
*We can use the same word from `wordDict` as many times as we need.*
*Return `true` if we can break the string into words from the list.*
*Return `false` if we cannot.*

Click [here](https://leetcode.com/problems/word-break/description/) for the question on Leetcode.

Click [here](https://www.youtube.com/watch?v=Sx9NNgInc3A) for the solution on [Neetcode](https://neetcode.io/) **(which I would strongly reccomed you to get familiar with.)**

To solve this challenge we will use [Dynamic Programming](https://www.geeksforgeeks.org/dynamic-programming/) in Python, JavaScript & Go.

### Example 1
```
Input: s = "leetcode", wordDict = ["leet","code"]
Output: true

# Explanation: Return true because "leetcode" can be segmented as "leet code".
```

### Example 2
```
Input: s = "applepenapple", wordDict = ["apple","pen"]
Output: true

# Explanation: Return true because "applepenapple" can be segmented as "apple pen apple".
Note that you are allowed to reuse a dictionary word.
```

### Example 3
```
Input: s = "catsandog", wordDict = ["cats","dog","sand","and","cat"]
Output: false
```

## Python
```
class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:
        # Create a boolean array dp with size len(s) + 1
        # dp[i] will be True if we can break the substring s[i:] into words from wordDict
        dp = [False] * (len(s) + 1)
        
        # Base case: an empty substring can always be segmented
        dp[len(s)] = True

        # Iterate over the string s from the end to the beginning
        for i in range(len(s) - 1, -1, -1):
            # Check each word in wordDict
            for w in wordDict:
                # If the word w fits into the substring starting at index i
                # and matches the substring s[i:i+len(w)]
                if (i + len(w)) <= len(s) and s[i : i + len(w)] == w:
                    # Set dp[i] to dp[i + len(w)], which tells if the rest of the string can be segmented
                    dp[i] = dp[i + len(w)]
                # If we found a valid segmentation, no need to check further
                if dp[i]:
                    break

        # The result is whether we can segment the entire string starting from index 0
        return dp[0]
```

## JavaScript
```
var wordBreak = (s, wordDict) => {
    // Convert wordDict to a set for quick lookup
    const wordSet = new Set(wordDict);           /* Time O(N)         | Space O(N) */
    
    // Initialize a memoization array to store results for subproblems
    const memo = new Array(s.length).fill(null); /*                   | Space O(N) */
    
    const start = 0;  // Start index for checking the string

    // Call the helper function to check if the string can be segmented
    return canBreak(s, wordSet, start, memo);    /* Time O(N * N * N) | Space O(N) */
}

var canBreak = (s, wordSet, start, memo) => {
    // Base case: if start index reaches the end of the string, return true
    const isBaseCase1 = (s.length === start);
    if (isBaseCase1) return true;

    // If the result for this start index is already computed, return it
    const hasSeen = (memo[start] !== null);
    if (hasSeen) return memo[start];

    // Call dfs function to check for segmentation starting from current index
    return dfs(s, wordSet, start, memo);         /* Time O(N * N * N) | Space O(N) */
}

var dfs = (s, wordSet, start, memo) => {
    // Iterate over possible end indices for the current substring
    for (let end = (start + 1); (end <= s.length); end++) {/* Time O(N) */
        // Get the current substring from start to end
        const word = s.slice(start, end);                  /* Time O(N) | Space O(N) */

        // Check if the current word is in the wordSet and recursively check the rest of the string
        const _canBreak = wordSet.has(word)
            && canBreak(s, wordSet, end, memo);            /* Time O(N * N) */
        if (_canBreak) {
            // If a valid segmentation is found, store the result and return true
            memo[start] = true;
            return true;
        }
    }

    // If no valid segmentation is found, store the result as false
    memo[start] = false;
    return false;
}
```

## Go
```
func wordBreak(s string, wordDict []string) bool {
    // Create a boolean array dp with size len(s) + 1
    // dp[i] will be true if we can break the substring s[i:] into words from wordDict
    dp := make([]bool, len(s) + 1)
    
    // Base case: an empty substring can always be segmented
    dp[len(s)] = true
    
    // Iterate over the string s from the end to the beginning
    for i := len(s) - 1; i >= 0; i-- {
        // Check each word in wordDict
        for _, w := range wordDict {
            // If the word w fits into the substring starting at index i
            // and matches the substring s[i:i+len(w)]
            if (i + len(w)) <= len(s) && s[i : i + len(w)] == w {
                // Set dp[i] to dp[i + len(w)], which tells if the rest of the string can be segmented
                dp[i] = dp[i + len(w)]
            }
            // If we found a valid segmentation, no need to check further
            if dp[i] {
                break
            }
        }
    }
    // The result is whether we can segment the entire string starting from index 0
    return dp[0]
}
```