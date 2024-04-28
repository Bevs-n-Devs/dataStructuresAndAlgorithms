Two Pointers 1
# Valid Palindrome
## Company: Spotify
## Level: Easy

A phrase is a **palindrome** if, after converting all uppercase letters into lowercase letters and 
removing all non-alphanumeric characters, ***it reads the same forward and backwards***.
Alphanumeric characters include letters and numbers.

Given a string `s`, return `true` if it a **palindrome**, or `false` otherwise.

***Break It Down For Me...***
*You are given a string of word(s) and need to find out if we reverse the string, it will be spell the same word(s) in reverse order.*

Click [here](https://leetcode.com/problems/longest-consecutive-sequence/) for the question on Leetcode.

Click [here](https://www.youtube.com/watch?v=P6RZZMu_maU) for the solution on [Neetcode](https://neetcode.io/) **(which I would strongly reccomed you to get familiar with.)**

Click [here](https://leetcode.com/problems/valid-palindrome/description/) for the question on Leetcode.

Click [here](https://www.youtube.com/watch?v=jJXJ16kPFWg) for the solution on [Neetcode](https://neetcode.io/) **(which I would strongly reccomed you to get familiar with.)**

### Example 1
Input: `s = "A man, a plan, a canal: Panama"`

Output: `true`

**Explanation:** `amanaplanacanalpanama` is a palindrome.

### Example 2
Input: `s = "race a car`

Output: `false`

**Explanation:**  `raceacar` is not a palindrome.

### Example 3
Input: `s = " "`

Output: `true`

**Explanation:** `s` is an empty string `""` after removing non-alphanumeric characters.
Since an empty string reads the same forward and backward, it is a palindrome.

# Python Solution 1
```
newStr = ""

for letter in s:
    if letter.isalnum():
        newStr += letter.lower()

return newStr == newStr[::-1]

# Code comments can be found in valid_palindrome_1.py
```

# Python Solution 2
```
left, right = 0, len(s) - 1

while left < right:
    while left < right and not self.alphanum(s[left]):
        left += 1
    while left < right and not self.alphanum(s[right]):
        right -= 1
    
    if s[left].lower() != s[right].lower():
        return False
    
    left += 1
    right -= 1
return True

def alphanum(self, c):
    return (
        ord("A") <= ord(c) <= ord("Z")
        or ord("a") <= ord(c) <= ord("z")
        or ord("0") <= ord(c) <= ord("9")
    )

# Code comments can be found in valid_palindrome_2.py
```

# JavaScript Solution 1
```
let newStr = '';

for (let i = 0; i < s.length; i++) {
    const char = s[i]; 
    
    if (/[a-zA-Z0-9]/.test(char)) {
        newStr += char.toLowerCase();
    }
}

return newStr === newStr.split('').reverse().join('');

const palindromeString = isPalindrome('race a car');
console.log(palindromeString);

// Code comments can be found in validPalindrome1.js
```

# JavaScript Solution 2
```
var isPalindrome = function(s) {
    const cleanString = s.toLowerCase().replace(/[^a-z0-9]/g, '');
    
    let leftPointer = 0;
    let rightPointer = cleanString.length - 1;
    
    while (leftPointer < rightPointer) {
        if (cleanString[leftPointer] !== cleanString[rightPointer]) {
            return false;
        }
        
        leftPointer += 1;
        rightPointer -= 1;
    }
    return true;
};

const x = isPalindrome('A man, a plan, a canal: Panama');
console.log(x);

// Code comments can be found in validPalindrome2.js
```

# Go
```
var newStr strings.Builder

for _, char := range s {
    if (char >= 'a' && char <= 'z') || (char >= 'A' && char <= 'Z') || (char >= '0' && char <= '9') {
        newStr.WriteRune(char)
    }
}

str := newStr.String()

return strings.ToLower(str) == reverseString(str)

func reverseString(s string) string {
	runes := []rune(s)
	for i, j := 0, len(runes)-1; i < j; i, j = i+1, j-1 {
		runes[i], runes[j] = runes[j], runes[i]
	}
	return string(runes)
}

// Code comments can be found in validPalindrome.go
```