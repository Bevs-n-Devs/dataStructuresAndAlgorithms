1-Dymanic Programming 5
# Longest Palendromic Substring
## Company: Google
### Level: Medium

Given a string `s`, return the longest [palindromic](https://www.dictionary.com/e/palindromic-word/) substring in `s`.

***Break It Down For Me...***
*A palindrome is a word that reads the same forward and backward. For example, "madam" and "racecar" are palindromes.

Your task is to find the longest part of the string s that is a palindrome.

Return this longest palindrome.*

Click [here](https://leetcode.com/problems/longest-palindromic-substring/description/)for the question on Leetcode.

Click [here](https://www.youtube.com/watch?v=XYQecbcd6_c) for the solution on [Neetcode](https://neetcode.io/) **(which I would strongly reccomed you to get familiar with.)**

To solve this challenge we will use [Dynamic Programming](https://www.geeksforgeeks.org/dynamic-programming/) in Python, JavaScript & Go.

### Example 1
```
Input: s = "babad"
Output: "bab"
```
**Explanation:** `aba` is also a valid answer.

### Example 2
```
Input: s = "cbbd"
Output: "bb"
```

## Python
```
class Solution:
    def longestPalindrome(self, s: str) -> str:
        # Initialize result variables
        res = ""
        resLen = 0

        # Iterate over each character in the string
        for i in range(len(s)):
            # Check for odd-length palindromes centered at i
            l, r = i, i
            while l >= 0 and r < len(s) and s[l] == s[r]:
                if (r - l + 1) > resLen:  # Update the result if a longer palindrome is found
                    res = s[l : r + 1]
                    resLen = r - l + 1
                l -= 1  # Expand to the left
                r += 1  # Expand to the right

            # Check for even-length palindromes centered between i and i+1
            l, r = i, i + 1
            while l >= 0 and r < len(s) and s[l] == s[r]:
                if (r - l + 1) > resLen:  # Update the result if a longer palindrome is found
                    res = s[l : r + 1]
                    resLen = r - l + 1
                l -= 1  # Expand to the left
                r += 1  # Expand to the right

        return res  # Return the longest palindromic substring
```

## JavaScript
```
var longestPalindrome = (s) => {
    // Check if the string is empty
    const isEmpty = s.length === 0;
    if (isEmpty) return '';
  
    // Search for the longest palindrome
    const [ left, right ] = search(s);/* Time O(N * N) */

    // Return the longest palindromic substring
    return s.slice(left, (right + 1));/* Time O(N * N) | Ignore Auxillary Space (N) */
}1111

// Function to search for the longest palindrome
const search = (s, left = 0, right = 0) => {
    // Iterate over each character in the string
    for (let index = 0; index < s.length; index++) {/* Time O(N) */
        const len1 = getLength(s, index, index);        /* Time O(N) */
        const len2 = getLength(s, index, (index + 1));  /* Time O(N) */
        const [ length, window ] = [ (Math.max(len1, len2)), (right - left) ];

        const canSkip = (length <= window);
        if (canSkip) continue;

        // Update the left and right pointers for the longest palindrome found
        left = (index - ((length - 1) >> 1));
        right = (index + (length >> 1));
    }

    return [ left, right ];
}

// Function to get the length of the palindrome centered at left and right
const getLength = (s, left, right) => {
    const canExpand = () => ((0 <= left) && (right < s.length));
    const isSame = () => (s[left] === s[right]);

    const isPalindrome = () => (canExpand() && isSame());
    while (isPalindrome()) { left--; right++; }/* Time O(N) */

    const window = ((right - left) - 1);

    return window;
}
```

## Go
```
func longestPalindrome(s string) string {
	// Initialize result variables
	res, resLen := "", 0

	// Iterate over each character in the string
	for i := 0; i < len(s); i++ {
		// Check for odd-length palindromes centered at i
		l, r := i, i
		for l >= 0 && r < len(s) && s[l] == s[r] {
			if (r - l + 1) > resLen { // Update the result if a longer palindrome is found
				res = s[l : r+1]
				resLen = r - l + 1
			}
			l-- // Expand to the left
			r++ // Expand to the right
		}

		// Check for even-length palindromes centered between i and i+1
		l, r = i, i+1
		for l >= 0 && r < len(s) && s[l] == s[r] {
			if (r - l + 1) > resLen { // Update the result if a longer palindrome is found
				res = s[l : r+1]
				resLen = r - l + 1
			}
			l-- // Expand to the left
			r++ // Expand to the right
		}
	}

	return res // Return the longest palindromic substring
}
```