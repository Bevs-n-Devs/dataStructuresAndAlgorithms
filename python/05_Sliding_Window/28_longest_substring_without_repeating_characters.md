Sliding Window 2
# Longest Substring Without Repeating Characters
## Company: Meta
### Level: Medium

Given a string `s`, find the length of the longest **substring** without repeating characters.

***Break It Down For Me...***
*A substring is a sequence of letters that occur consecutively within a string.*
*A substring without repeating characters means that in the sequence, the letters should appear no more than once.*

Click [here](https://leetcode.com/problems/longest-substring-without-repeating-characters/)for the question on Leetcode.

Click [here](https://www.youtube.com/watch?v=wiGpQwVHdE0) for the solution on [Neetcode](https://neetcode.io/) **(which I would strongly reccomed you to get familiar with.)**

To solve this challenge we will use a [Sliding Window](https://builtin.com/data-science/sliding-window-algorithm) in Python, JavaScript and Go.

### Example 1
```
Input: s = "abcabcbb"
Output: 3
```
**Explanation:** The answer is `abc`, with the length of `3`.

### Example 2
```
Input: s = "bbbbb"
Output: 1
```
**Explanation:** The answer is `b`, with the length of `1`.

### Example 3
```
Input: s = "pwwkew"
Output: 3
```
**Explanation:** The answer is `wke`, with the length of `3`. Notice that the answer has to be a substring, `pwke` is a subsequence and not a substring.

## Python
```
class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        # create a set to store letters
        charSet = set()
        # set left pointer to 0 (which will be first letter)
        l = 0
        # set result to 0
        res = 0

        # loop through each letter in string using right pointer
        for r in range(len(s)):
            # if the letter is in the set..
            while s[r] in charSet:
                # remove the letter from set
                charSet.remove(s[l])
                # move left pointer to next letter
                l += 1
            # add each letter to the set using right pointer
            charSet.add(s[r])
            # find max num of letters by calculating distance between left & right pointer
            res = max(res, r - l + 1)
        
        # return the result 
        return res
```

## JavaScript
```
var lengthOfLongestSubstring = function(s) {
    // create a set to store each letter from string
    let charSet = new Set();
    // create pointers to iterate through each letter
    let left = 0;
    // initialise result to 0
    let numOfLetters = 0;
    
    // Use the loop through each letter using the right pointer.
    // We add each letter to the set, after checking if there's a 
    // duplicate already in the set.  If it is, we remove the duplicate
    // from the set.
    
    for (let right = 0; right < s.length; right++) {
        // check if letter is in set
        while (charSet.has(s[right])) {
            charSet.delete(s[left]);
            // move left pointer to next letter
            left++;
        }
        // add each letter to the set using the right pointer
        charSet.add(s[right]);
        // update result
        numOfLetters = Math.max(numOfLetters, charSet.size);
    }
    // return result
    return numOfLetters;
};
```

## Go
```
// Function to find the length of the longest substring without repeating characters
func lengthOfLongestSubstring(s string) int {
    // Create a set (using a map with bool values) to store characters in the current window
    charSet := make(map[byte]bool)
    // Initialize the left pointer of the window to 0
    l := 0
    // Variable to store the maximum length of substring found
    res := 0
    
    // Iterate over the string with the right pointer
    for r := 0; r < len(s); r++ {
        // If the character at the right pointer is already in the set,
        // move the left pointer to the right until the character is removed from the set
        for charSet[s[r]] {
            // Remove the character at the left pointer from the set
            delete(charSet, s[l])
            // Move the left pointer to the right
            l++
        }
        // Add the character at the right pointer to the set
        charSet[s[r]] = true
        // Update the result with the maximum length of the current window
        res = max(res, r - l + 1)
    }
    // Return the maximum length of substring found
    return res
}

// Helper function to find the maximum of two integers
func max(a, b int) int {
    if a > b {
        return a
    }
    return b
}
```