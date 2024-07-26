1-Dymanic Programming 7
# Decode Ways
## Company: Google
### Level: Medium 

You have intercepted a secret message encoded as a string of numbers. The message is decoded via the following mapping:

- "1" -> 'A'
- "2" -> 'B'
- "25" -> 'Y'
- "26" -> 'Z'

However, while decoding the message, you realize that there are many different ways you can decode the message because some codes are contained in other codes ("2" and "5" vs "25").

For example, "11106" can be decoded into:

"`AAJF`" with the grouping `(1, 1, 10, 6)`
"`KJF`" with the grouping `(11, 10, 6)`
The grouping `(1, 11, 06)` is invalid because "06" is not a valid code (only "`6`" is valid).
Note: there may be strings that are impossible to decode.

**Given a string s containing only digits, return the number of ways to decode it. If the entire string cannot be decoded in any valid way, return `0`.**

The test cases are generated so that the answer fits in a 32-bit integer.

***Break It Down For Me...***
*You have a secret message that is just a string of numbers. Each number can be turned into a letter based on these rules:*

- *"`1`" turns into '`A`'*
- *"`2`" turns into '`B`'*
- *"`25`" turns into '`Y`'*
- *"`26`" turns into '`Z`'*
*But there's a catch: there are many ways to break up the string into these numbers, and some ways are not allowed.*

*F*or example, "11106" can be turned into:*

*"`AAJF`" by breaking it into "`1, 1, 10, 6"`*
*"`KJF`" by breaking it into "`11, 10, 6`"*

Click [here](https://leetcode.com/problems/decode-ways/description/) for the question on Leetcode.

Click [here](https://www.youtube.com/watch?v=6aEyTjOwlJU) for the solution on [Neetcode](https://neetcode.io/) **(which I would strongly reccomed you to get familiar with.)**

To solve this challenge we will use [Dynamic Programming](https://www.geeksforgeeks.org/dynamic-programming/) in Python, JavaScript & Go.

### Example 1
```
Input: s = "12"

Output: 2
```
**Exaplanation:** "`12`" could be decoded as "`AB`" `(1 2)` or "`L`" `(12)`.


### Example 2
```
Input: s = "226"

Output: 3
```
**Exaplanation:** "`226`" could be decoded as "`BZ`" `(2 26)`, "`VF`" `(22 6)`, or "`BBF`" `(2 2 6)`.


### Example 3
```
Input: s = "06"

Output: 0
```
**Exaplanation:** "`06`" cannot be mapped to "`F`" because of the leading zero ("`6`" is different from "`06`"). In this case, the string is not a valid encoding, so return `0`.


## Python
```
class Solution:
    def numDecodings(self, s: str) -> int:
        # Memoization approach to store already computed results
        dp = {len(s): 1}  # Base case: An empty string has one way to be decoded

        def dfs(i):
            if i in dp:  # If the result for this index is already computed, return it
                return dp[i]
            if s[i] == "0":  # If the current character is '0', it can't be decoded
                return 0

            # Recursive call to decode the substring starting from the next character
            res = dfs(i + 1)

            # Check if the current character and the next character together form a valid number
            if i + 1 < len(s) and (s[i] == "1" or (s[i] == "2" and s[i + 1] in "0123456")):
                # If valid, add the result of decoding the substring starting from the character after the next one
                res += dfs(i + 2)

            dp[i] = res  # Store the result in the dictionary to avoid recomputation
            return res

        return dfs(0)  # Start the recursion from the first character

        # Dynamic Programming approach
        dp = {len(s): 1}  # Base case: An empty string has one way to be decoded
        for i in range(len(s) - 1, -1, -1):  # Iterate from the end of the string to the beginning
            if s[i] == "0":  # If the current character is '0', it can't be decoded
                dp[i] = 0
            else:
                dp[i] = dp[i + 1]  # Decode the substring starting from the next character

            # Check if the current character and the next character together form a valid number
            if i + 1 < len(s) and (s[i] == "1" or (s[i] == "2" and s[i + 1] in "0123456")):
                # If valid, add the result of decoding the substring starting from the character after the next one
                dp[i] += dp[i + 2]

        return dp[0]  # The result for the whole string is stored in dp[0]
``` 

## JavaScriptt
```
// Function to determine the number of ways to decode the string
var numDecodings = (str, index = 0, memo = new Map()) => {
    // Base case 1: If the string is empty or starts with '0', there are no valid decodings
    const isBaseCase1 = !str.length || (str[index] === '0');
    if (isBaseCase1) return 0;

    // Base case 2: If we have reached the end of the string, there is one valid decoding
    const isBaseCase2 = index === str.length;
    if (isBaseCase2) return 1;

    // If the result for this index is already computed, return it from memoization
    if (memo.has(index)) return memo.get(index);

    // Call the helper function to perform the depth-first search and calculate the result
    return dfs(str, index, memo);
};

// Helper function to perform depth-first search
const dfs = (str, index, memo) => {
    // Initialize the count by considering the single digit decoding
    let count = numDecodings(str, (index + 1), memo);

    // If the current and next characters together form a valid two-digit number, add its decoding count
    if (isTwoDigit(str, index)) {
        count += numDecodings(str, (index + 2), memo);
    }

    // Store the result in memoization to avoid recomputation
    memo.set(index, count);

    // Return the total count of decodings for the current index
    return count;
};

// Helper function to check if the current and next characters form a valid two-digit number (10 to 26)
var isTwoDigit = (str, index) => {
    const twoDigit = Number(str.slice(index, (index + 2))); // Get the two-digit number

    // Return true if the number is between 10 and 26, inclusive
    return (10 <= twoDigit) && (twoDigit <= 26);
}
```

## Go
```
// Function to count the number of ways to decode a string using memoization
func numDecodingsMemoization(s string) int {
    // Create a DP array to store results of subproblems
    dp := make([]int, len(s) + 1)
    dp[len(s)] = 1 // Base case: There's one way to decode an empty string
    
    // Helper function for depth-first search with memoization
    var dfs func(i int) int
    dfs = func(i int) int {
        // If the result is already computed, return it
        if dp[i] != 0 {
            return dp[i]
        // If the current character is '0', it cannot be decoded
        } else if s[i] == '0' {
            return 0
        }
        
        // Start with decoding the current single digit
        res := dfs(i + 1)
        
        // Check if the next two digits form a valid character (10-26)
        if i + 1 < len(s) && (
            s[i] == '1' || s[i] == '2' && (s[i + 1] >= '0' && s[i + 1] <= '6')) {
            res += dfs(i + 2)
        }
        
        // Store the result in the DP array and return it
        dp[i] = res
        return res
    }
    
    // Start the DFS from the first character
    return dfs(0)
}

// Function to count the number of ways to decode a string using tabulation
func numDecodingsTabulation(s string) int {
    // Create a DP array to store results of subproblems
    dp := make([]int, len(s) + 1)
    dp[len(s)] = 1 // Base case: There's one way to decode an empty string
    
    // Iterate over the string from the end to the beginning
    for i := len(s) - 1; i >= 0; i-- {
        // If the current character is '0', it cannot be decoded
        if s[i] == '0' {
            dp[i] = 0
        // Otherwise, start with decoding the current single digit
        } else {
            dp[i] = dp[i + 1]
        }
        
        // Check if the next two digits form a valid character (10-26)
        if i + 1 < len(s) && (
            s[i] == '1' || s[i] == '2' && (s[i + 1] >= '0' && s[i + 1] <= '6')) {
            dp[i] += dp[i + 2]
        }
    }
    
    // The result for the entire string is stored in dp[0]
    return dp[0]
}
```