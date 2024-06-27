Sliding Window 3
# Longest Repeating Character Replacement
## Company: Google
### Level: Medium

You are given a string `s` and an integer `k`. You can choose any character of the string and change it to any other uppercase English character. You can perform this operation at most `k` times.

*Return the length of the longest substring containing the same letter you can get after performing the above operations.*

***Break It Down For Me...***
*Use the sliding window technique to find the longest substring where the number of changes needed to make all characters the same is less than or equal to `k`. Adjust the window size dynamically by counting character frequencies and shrinking the window when necessary.*

### Eaxmple 1
```
Input: s = "ABAB", k = 2
Output: 4
```

### Example 2
```
Input: s = "AABABBA", k = 1
Output: 4
```

## Python
```
class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        # create hashmap to count each letter
        count = {}
        
        # initialise left pointer & resut to 0
        l = 0
        maxf = 0

        # use the right pointer to loop through the letters
        for r in range(len(s)):
            # update the hashmap for each letter found
            count[s[r]] = 1 + count.get(s[r], 0)
            # update result
            maxf = max(maxf, count[s[r]])

            # check if the number of replacements needed is greater than the allowed limit (k)
            # if so, we need to shift the left pointer and adjust the counts accordingly
            # the idea is to maintain a window with the maximum repeating character within the window
            # and replace the rest, so the window length - count of the most frequent character will give us
            # the number of replacements needed

            if (r - l + 1) - maxf > k:
                # decrement the count of the character at the left pointer
                count[s[l]] -= 1
                # move the left pointer to the right
                l += 1

        # the maximum valid window length is given by the difference between the right and left pointers
        return (r - l + 1)
```

## JavaScript
```
var characterReplacement = function(s, k) {
    // create hashmap to store letters
    let hashmap = new Map();
    // initialise pointers and result
    let left = 0, maxSubstring = 0;
    
    // create right pointer to loop through each letter
    for (let right = 0; right < s.length; right++) {
        let maxWindowLength = right - left + 1;
        
        // update existing letter in hashmap or add new value
        // we use the letter of each string as the key and the value
        // is the count of each letter
        // if the key is not in the hashmap we add 0 to 1 (1 + 0))
        hashmap.set(s[right], 1 + (hashmap.get(s[right]) || 0));
        
        // check if number of replacements needed is greater than the limit
        if ((maxWindowLength - Math.max(...hashmap.values())) > k) {
            // decrement the count of the left pointer letter in hashmap
            hashmap.set(s[left], hashmap.get(s[left]) - 1);
            // move the left pointer to next letter
            left++;
        }
        // recalculate the new max window and then the max substring 
        maxWindowLength = right - left + 1;
        maxSubstring = Math.max(maxSubstring, maxWindowLength);
    }
    // return the result
    return maxSubstring;
};

const s = "ABAB", k = 2;
console.log(characterReplacement(s, k));
console.log('\nYaw Akoto');
```

## Go
```
func characterReplacement(s string, k int) int {
    // Initialize a map to count the frequency of characters in the current window
    count := make(map[byte]int)
    // Variable to store the result, i.e., the maximum length of the substring found
    res := 0
    
    // Left pointer of the sliding window
    l := 0
    // Variable to keep track of the maximum frequency of any single character in the current window
    maxf := 0
    
    // Iterate over the string with the right pointer
    for r := 0; r < len(s); r++ {
        // Increment the frequency count of the current character
        count[s[r]] = 1 + count[s[r]]
        // Update maxf to be the maximum frequency of any character in the current window
        maxf = max(maxf, count[s[r]])
        
        // If the number of changes needed exceeds k, shrink the window from the left
        if (r - l + 1) - maxf > k {
            count[s[l]] -= 1  // Decrement the count of the leftmost character
            l++               // Move the left pointer to the right
        }
        
        // Update the result with the maximum length of the valid window found
        res = max(res, r - l + 1)
    }
    
    // Return the maximum length of the substring found
    return res
}

// Helper function to return the maximum of two integers
func max(a, b int) int {
    if a > b {
        return a
    }
    return b
}
```