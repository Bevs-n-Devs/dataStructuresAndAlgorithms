Sliding Window 5
# Minimum Window Substring
## Company: Airbnb
### Level: Hard

Given two strings `s` and `t` of lengths `m` and `n` respectively, return the ***minimum window substring*** of `s` such that every character in `t` (including duplicates) is included in the window. If there is no such substring, return the empty string `""`.

The testcases will be generated such that the answer is **unique**.

***Break It Down For Me...***
*You have two strings, `s` and `t`. You need to find the smallest substring in `s` that contains all the characters from `t` (including any duplicates).*
*If you can't find such a substring, you should return an empty string.*

Click [here](https://leetcode.com/problems/minimum-window-substring/description/)for the question on Leetcode.

Click [here](https://www.youtube.com/watch?v=jSto0O4AJbM) for the solution on [Neetcode](https://neetcode.io/) **(which I would strongly reccomed you to get familiar with.)**

To solve this challenge we will use a [Sliding Window](https://builtin.com/data-science/sliding-window-algorithm) in Python, JavaScript and Go.

### Example 1
```
Input: S = "ADOBECODEBANC", t = "ABC"
Output: "BANC"
```
**Explanation:** The minimum window substring `BANC` includes `A`, `B`, and `C` from string `t`.

### Example 2
```
Input: s = "a", t = "a"
Output: "a"
```
**Explanation:** The entire string `s` is the minimum window.

### Example 3
```
Input: s = "a", t = "aa"
Output: ""
```
**Explanation:** Both `a`'s from `t` must be included in the window.
Since the largest window of `s` only has one `a`, return empty string.

## Python
```
class Solution:
    def minWindow(self, s: str, t: str) -> str:
        # Check if t is an empty string
        if t == "":
            return ""

        # Initialize dictionaries to store the count of characters in the current window and the target string t
        countT, window = {}, {}

        # Count the occurrences of characters in t
        for c in t:
            countT[c] = 1 + countT.get(c, 0)

        # Initialize variables for the number of characters we have in the current window and the number of characters we need
        have, need = 0, len(countT)

        # Initialize variables to store the result substring and its length
        res, resLen = [-1, -1], float("infinity")

        # Initialize left pointer
        l = 0

        # Iterate through the string s with the right pointer
        for r in range(len(s)):
            c = s[r]
            window[c] = 1 + window.get(c, 0)

            # Check if a character in the current window reaches the required count
            if c in countT and window[c] == countT[c]:
                have += 1

            # While we have all the required characters in the current window
            while have == need:
                # Update the result if the current window is shorter than the previous result
                if (r - l + 1) < resLen:
                    res = [l, r]
                    resLen = r - l + 1

                # Pop the leftmost character from the window
                window[s[l]] -= 1

                # Check if the removal affects the count of a character in t
                if s[l] in countT and window[s[l]] < countT[s[l]]:
                    have -= 1

                # Move the left pointer to expand the window
                l += 1

        # Extract the result substring from the indices in res
        l, r = res
        return s[l : r + 1] if resLen != float("infinity") else ""
```

## JavaScript
```
// Function to find the minimum window substring of s that contains all characters of 
var minWindow = function (s, t) {
    // Check if either s or t is an empty string
    const isMissingArgs = !s.length || !t.length;
    if (isMissingArgs) return '';

    // Initialize the frequency map for characters in t
    const frequencyMap = getFrequencyMap(t);

    // Get the window pointers for the minimum window substring
    const { start, end } = getWindowPointers(s, t, frequencyMap);

    // Get the minimum window substring using the indices from the window pointers
    return getSubString(s, start, end);
};

// Function to create a frequency map for characters in a string
const getFrequencyMap = (str, frequencyMap = new Map()) => {
    for (const char of str) {
        frequencyMap.set(char, (frequencyMap.get(char) || 0) + 1);
    }

    return frequencyMap;
};

// Function to find the window pointers for the minimum window substring
const getWindowPointers = (s, t, frequencyMap) => {
    let [left, right, matched, start, end] = [0, 0, 0, 0, s.length + 1];

    // Iterate through the string s with the right pointer
    while (right < s.length) {
        // Update the matched count and frequency map for the right character
        matched = addRightFrequency(s, right, frequencyMap, matched);

        // Check if the window can slide
        const canSlide = () => matched === t.length;
        while (canSlide()) {
            const window = right - left + 1;

            // Update the start and end indices if the current window is smaller than the previous minimum
            const isSmaller = window < end;
            if (isSmaller) {
                [start, end] = [left, window];
            }

            // Update the matched count and frequency map for the left character
            matched = subtractLeftFrequency(s, left, frequencyMap, matched);
            left++;
        }

        // Move the right pointer to expand the window
        right++;
    }

    return { start, end };
};

// Function to add the frequency of the right character in the window
const addRightFrequency = (s, right, frequencyMap, matched) => {
    const char = s[right];

    // Check if the character is in t
    if (frequencyMap.has(char)) {
        // Update the frequency map and check if the character is within the window
        frequencyMap.set(char, frequencyMap.get(char) - 1);
        const isInWindow = 0 <= frequencyMap.get(char);
        if (isInWindow) matched++;
    }

    return matched;
};

// Function to subtract the frequency of the left character from the window
const subtractLeftFrequency = (s, left, frequencyMap, matched) => {
    const char = s[left];

    // Check if the character is in t
    if (frequencyMap.has(char)) {
        // Check if the character is leaving the window and update the frequency map
        const isOutOfWindow = frequencyMap.get(char) === 0;
        if (isOutOfWindow) matched--;

        frequencyMap.set(char, frequencyMap.get(char) + 1);
    }

    return matched;
};

// Function to extract the substring from s using start and end indices
const getSubString = (s, start, end) =>
    end <= s.length ? s.slice(start, start + end) : '';
```

## Go
```
func minWindow(s string, t string) string {
	// Initialize start and end pointers for the sliding window
	start, end := 0, 0
	
	// Maps to store the frequency of characters in t and the current window in s
	targetCharacterFrequency := make(map[uint8]int)
	currentCharacterFrequency := make(map[uint8]int)
	
	// Count of distinct characters that have the required frequency in the current window
	distinctCharacterCount := 0
	
	// Variable to store the minimum substring
	minSubstring := ""

	// Populate the targetCharacterFrequency map with the frequency of each character in t
	for index := range t {
		targetCharacterFrequency[t[index]]++
	}

	// Expand the window by moving the end pointer to the right
	for end < len(s) {
		// Increment the frequency of the current character in the currentCharacterFrequency map
		currentCharacterFrequency[s[end]]++
		
		// If the current character's frequency matches its required frequency in t
		if targetCharacterFrequency[s[end]] != 0 &&
			targetCharacterFrequency[s[end]] == currentCharacterFrequency[s[end]] {
			distinctCharacterCount++
		}

		// While the window is valid (contains all characters of t with required frequency)
		for distinctCharacterCount == len(targetCharacterFrequency) {
			// If minSubstring is empty or the current window is smaller than the previously found minimum window
			if minSubstring == "" {
				minSubstring = s[start:end+1]
			}
			if end - start + 1 < len(minSubstring) {
				minSubstring = s[start:end+1]
			}

			// Before moving the start pointer, decrement the frequency of the character at the start
			currentCharacterFrequency[s[start]]--
			
			// If the character's frequency is now less than required, decrement the distinctCharacterCount
			if currentCharacterFrequency[s[start]] < targetCharacterFrequency[s[start]] {
				distinctCharacterCount--
			}

			// Move the start pointer to the right to try and find a smaller valid window
			start++
		}

		// Move the end pointer to the right to expand the window
		end++
	}

	// Return the minimum substring found
	return minSubstring
}
```