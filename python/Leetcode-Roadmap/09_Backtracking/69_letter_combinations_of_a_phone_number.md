Backtracking 8
# Letter Cominations of a Phone Number
## Company: Amazon
### Level: Medium

Given a string containing digits from `2-9` inclusive, return all possible letter combinations that the number could represent. Return the answer in **any order**.

A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.

***Break It Down For Me...***
*We have a string made of numbers from 2 to 9. Each number on a phone keypad represents some letters.*
*For example, 2 can be "a", "b", or "c". Your task is to find all the possible combinations of letters that the numbers can make. 
*The order of the combinations doesn't matter.*

Click [here](https://leetcode.com/problems/palindrome-partitioning/description/)for the question on Leetcode.

Click [here](https://www.youtube.com/watch?v=3jvWodd7ht0) for the solution on [Neetcode](https://neetcode.io/) **(which I would strongly reccomed you to get familiar with.)**

To solve this challenge we will use a [Backtracking Algorithm](https://www.simplilearn.com/tutorials/data-structure-tutorial/backtracking-algorithm#:~:text=Backtracking%20is%20an%20algorithmic%20technique,meet%20them%20will%20be%20removed.) data structure in Python, JavaScript and Go.

### Example 1
![Example 1 Image](https://assets.leetcode.com/uploads/2022/03/15/1200px-telephone-keypad2svg.png)
```
Input: digits = "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"]
```

### Example 2
```
Input: digits = ""
Output: []
```


### Example 3
```
Input: digits = "2"
Output: ["a", "b", "c"]
```

## Python
```
class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        res = []  # This will store the final list of letter combinations
        # Mapping of digits to corresponding letters
        digitToChar = {
            "2": "abc",
            "3": "def",
            "4": "ghi",
            "5": "jkl",
            "6": "mno",
            "7": "pqrs",
            "8": "tuv",
            "9": "wxyz",
        }

        # Helper function for backtracking
        def backtrack(i, curStr):
            if len(curStr) == len(digits):  # Base case: if the current string's length matches the digits' length
                res.append(curStr)  # Add the current string to the result list
                return
            for c in digitToChar[digits[i]]:  # Iterate through possible characters for the current digit
                backtrack(i + 1, curStr + c)  # Move to the next digit and add the current character

        if digits:  # If digits string is not empty
            backtrack(0, "")  # Start the backtracking process from the first digit

        return res  # Return the list of all possible letter combinations
```

## JavaScript
```
var letterCombinations = function(digits, combination = [], combinations = []) {
    const isBaseCase = !digits;  // Base case: if no digits left
    if (isBaseCase) {
        if (combination.length) combinations.push(combination.join(''));  // Join and push the current combination to results
        return combinations;  // Return the list of combinations
    }

    const letters = phoneButtons[digits[0]];  // Get the letters corresponding to the current digit

    for (const char of letters) {  // Iterate over each letter
        backTrack(digits, char, combination, combinations);  // Backtrack with the current letter
    }

    return combinations;  // Return the list of all combinations
};

const backTrack = (digits, char, combination, combinations) => {
    combination.push(char);  // Add the current character to the combination
    letterCombinations(digits.slice(1), combination, combinations);  // Move to the next digit
    combination.pop();  // Remove the last character to backtrack
}

const phoneButtons = ({
    2: ['a', 'b', 'c'],
    3: ['d', 'e', 'f'],
    4: ['g', 'h', 'i'],
    5: ['j', 'k', 'l'],
    6: ['m', 'n', 'o'],
    7: ['p', 'q', 'r', 's'],
    8: ['t', 'u', 'v'],
    9: ['w', 'x', 'y', 'z'],
});
```

## Go
```
package main

func letterCombinations(digits string) []string {
    ans := make([]string, 0)  // This will store the final list of letter combinations
    if len(digits) == 0 {
        return ans  // Return empty list if there are no digits
    }
    // Mapping of digits to corresponding letters
    m := make(map[byte]string)
    m['2'] = "abc"
    m['3'] = "def"
    m['4'] = "ghi"
    m['5'] = "jkl"
    m['6'] = "mno"
    m['7'] = "pqrs"
    m['8'] = "tuv"
    m['9'] = "wxyz"
    curr := ""  // This will store the current combination of letters
    // Helper function for backtracking
    var backtrack func(idx int)
    backtrack = func(idx int) {
        if len(curr) == len(digits) {  // Base case: if the current string's length matches the digits' length
            ans = append(ans, curr)  // Add the current string to the result list
            return
        }
        dig := digits[idx]  // Get the current digit
        str := m[dig]  // Get the corresponding letters for the current digit
        for i := 0; i < len(str); i++ {  // Iterate through possible characters for the current digit
            curr += string(str[i])  // Add the current character to the combination
            backtrack(idx + 1)  // Move to the next digit
            curr = curr[:len(curr)-1]  // Remove the last character to backtrack
        }
    }
    backtrack(0)  // Start the backtracking process from the first digit
    return ans  // Return the list of all possible letter combinations
}
```