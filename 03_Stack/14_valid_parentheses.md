Stack 1
# Valid Parentheses
## Company:
### Level: Easy

Given a string `s` containing just the characters `(`, `)`, `{`, `}`, `[` and `]`,
determine if the input string is valid.

An input string is valid if:

1. Open brackets must be closed by the same type of brackets.
2. Open brackets must be closed in the correct order.
3. Every closed bracket has a corresponding open bracket of the same type.


Click [here](https://leetcode.com/problems/valid-parentheses/description/) for the question on Leetcode.

Click [here](https://www.youtube.com/watch?v=WTzjTskDFMg) for the solution on [Neetcode](https://neetcode.io/) **(which I would strongly reccomed you to get familiar with.)**

To solve this challenge we will use a [Stack](https://www.geeksforgeeks.org/introduction-to-stack-data-structure-and-algorithm-tutorials/) and [HashMap](https://stackoverflow.com/questions/2592043/what-is-a-hash-map-in-programming-and-where-can-it-be-used) in Pythopn, JavaScript and Go.

### Example 1
```
Input: s = "()"
Output: true
```

### Example 2
```
Input: s = "()[]{}"
Output: true
```

### Example 3
```
Output: s = "(]"
Input: false
```

## Python
```
Map = {")": "(", "]": "[", "}": "{"}
stack = []

for c in s:
    if c not in Map:
        stack.append(c)    # add to stack
        continue
    
    if not stack or stack[-1] != Map[c]:
        return False
    
    stack.pop()

return not stack

# Code comments can be found in valid_parentheses.py
```

## JavaScript
```
const hashmap = {'}':'{', ']':'[', ')':'('};
let stack = [];

for (let index = 0; index < s.length; index++) {
    let char = s[index];
    
    if (!(char in hashmap)) {
        stack.push(char);
        continue;
    }
    
    if (stack.length === 0 || stack[stack.length- 1] !== hashmap[char]) {
        return false;
    }
    
    stack.pop();
}
return stack.length === 0;

// Code comments can be found in validParentheses.js
```

## Go
```
func isValid(s string) bool {

	pairs := map[byte]byte{
		'}': '{',
		']': '[',
		')': '(',
	}

	stack := make([]byte, 0)

	for _, char := range []byte(s) {
		pair, ok := pairs[char]
		if !ok {
			stack = append(stack, char)
			continue
		}

		if len(stack) == 0 {
			return false
		}

		if stack[len(stack) - 1] != pair {
			return false
		}

		stack = stack[:len(stack) - 1]
	}

	return len(stack) == 0
}

// Code comments can be found in validParentheses.go
```
