1-Dymanic Programming 6
# Palendromic Substring
## Company: Google
### Level: Medium

Given a string `s`, return the number of palindromic substrings in it.

**A string is a palindrome when it reads the same backward as forward.**

*A substring is a contiguous sequence of characters within the string.*

***Break It Down For Me...***
*You have a string `s`.*

*A palindrome is a word that reads the same forward and backward. For example, "`madam`" and "`racecar`" are palindromes.*

*A substring is any part of the string that you can make by choosing some characters in order. For example, the substrings of "`abc`" are "`a`", "`b`", "`c`", "`ab`", "`bc`", and "`abc`".*

*Your task is to find out how many substrings of s are palindromes.*

*So, given the string s, you need to return the total number of palindromic substrings in it.*


Click [here](https://leetcode.com/problems/palindromic-substrings/description/) for the question on Leetcode.

Click [here](https://www.youtube.com/watch?v=4RACzI5-du8) for the solution on [Neetcode](https://neetcode.io/) **(which I would strongly reccomed you to get familiar with.)**

To solve this challenge we will use [Dynamic Programming](https://www.geeksforgeeks.org/dynamic-programming/) in Python, JavaScript & Go.



### Example 1
```
Input: s = "abc"
Output: 3

Explanation: Three palindromic strings: "a", "b", "c".
```

### Example 2
```
Input: s = "aaa"
Output: 6

Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".
```

## Python
```
var countSubstrings = (s, count = 0) => {
    // Iterate over each character in the string as the center of the palindrome
    for (let left = 0; left < s.length; left++) {      /* Time O(N) */
        // Expand from the center to find all palindromes
        for (let right = left; right < s.length; right++) {/* Time O(N) */
            count += Number(isPalindrome(s, left, right)); /* Time O(N) */
        }
    }

    return count;
}

const isPalindrome = (s, left, right) => {
    // Check if the substring s[left:right+1] is a palindrome
    while (left < right) {/* Time O(N) */
        const isEqual = (s[left] === s[right]);
        if (!isEqual) return false;

        left++; right--;
    }

    return true;
}
```

## JavaScript
```
var countSubstrings = (s, count = 0) => {
    // Iterate over each character in the string as the center of the palindrome
    for (let left = 0; left < s.length; left++) {      /* Time O(N) */
        // Expand from the center to find all palindromes
        for (let right = left; right < s.length; right++) {/* Time O(N) */
            count += Number(isPalindrome(s, left, right)); /* Time O(N) */
        }
    }

    return count;
}

const isPalindrome = (s, left, right) => {
    // Check if the substring s[left:right+1] is a palindrome
    while (left < right) {/* Time O(N) */
        const isEqual = (s[left] === s[right]);
        if (!isEqual) return false;

        left++; right--;
    }

    return true;
}

```

## Go
```
func countSubstrings(s string) int {
    n := len(s)  // Get the length of the string

    // Helper function to count palindromic substrings centered at l and r
    pal := func(l, r int) int {
        count := 0
        // Expand outwards as long as we have a palindrome
        for l >= 0 && r < n && s[l] == s[r] {
            count++  // We found a palindrome
            l--      // Move left pointer to the left
            r++      // Move right pointer to the right
        }
        return count
    }

    count := 0  // Initialize count of palindromic substrings
    for i := range s {
        count += pal(i, i)    // Count odd-length palindromes centered at i
        count += pal(i, i+1)  // Count even-length palindromes centered at i and i+1
    }
    return count  // Return the total count of palindromic substrings
}
```