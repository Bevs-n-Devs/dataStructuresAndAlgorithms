Arrays And Hashing 2
# Valid Anagram
## Company: Uber
### Level: Easy

Given two strings `s` and `t`, return `true` if `t` is an anagram of `s`, and `false` otherwise.

*An anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exaclty once.*

***Break It Down For Me...***

*Lets say we have two words, we would want to check that the first word can be rearranged to create the second word.*
*In order for it to be valid, all letters must be used and none left out.*
*For instance if we had the words `pool` and `polo`, we would want to create an function to check if both words have the same characters.*
*If they do, (and no characters are left out), then we have a valid anagram!*
**Notice how the all the letters are being used in order for the anagram to work. We must not leave out any letters!**

To solve this challenge we will use a **[Hash Map](https://stackoverflow.com/questions/2592043/what-is-a-hash-map-in-programming-and-where-can-it-be-used)** in the Python, JavaScript and Go solution.

Click [here](https://leetcode.com/problems/valid-anagram/) for the question on Leetcode.

Click [here](https://www.youtube.com/watch?v=9UtInBqnCgA) for the solution on [Neetcode](https://neetcode.io/) **(which I would strongly reccomed you to get familiar with.)**

### Example 1
Input: `s = "anagram", t = "nagaram"`

Output: `true`

### Example 2
Input: `s = "rat", t = "car"`

Output: `false`

## Python Solution
```
if len(s) != len(t):
    return False

countS, countT = {}, {}

for i in range(len(s)):
    countS[s[i]] = 1 + countS.get(s[i], 0)
    countT[t[i]] = 1 + countT.get(t[i], 0)

for c in countS:
    if countS[c] != countT.get(c, 0):
        return False

return True

# Code comments can be found in valid_anagram.py
```

## JavaScript Solution
```
if (s.length !== t.length) {
    return false;
}

const countS = {};
const countT = {};

for (let i = 0; i < s.length; i++) {
    countS[s[i]] = 1 + (countS[s[i]] || 0);
    countT[t[i]] = 1 + (countT[t[i]] || 0);
}

for (const char in countS) {
    if (countS[char] !== countT[char]) {
        return false;
    }
}
return true;

// Code comments can be found in valid_anagram.js
```

## Go
```
if len(s) != len(t) {
    return false
}

countS := make(map[byte]int)
countT := make(map[byte]int)

for char :=  0; char < len(s); char++ {
    countS[s[char]]++
    countT[t[char]]++
}

for char, count := range countS {
    if count != countT[char] {
        return false
    }
}
return true

// Code comments can be found in valid_anagram.go
```