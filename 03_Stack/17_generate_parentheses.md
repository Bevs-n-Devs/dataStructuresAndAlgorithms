Stack 4
# Generate Parentheses
## Company: Amazon
### Level: Medium

Given `n` pairs on parentheses, write a function to generate all combnations of well-formed parentheses.

***Break It Down For Me...***
*Our task is to figure out all the possible ways we can stack them so that they are well formed - meaning every `(` has a matching `)`.*
*The goal is to find all possible arrangements of parentheses where each `(` has a corresponding `)` and to return them as a list of strings.*

Click [here](https://leetcode.com/problems/generate-parentheses/description/) for the question on Leetcode.

Click [here](https://www.youtube.com/watch?v=s9fokUqJ76A) for the solution on [Neetcode](https://neetcode.io/) **(which I would strongly reccomed you to get familiar with.)**

To solve this challenge we will use a [Stack](https://www.geeksforgeeks.org/introduction-to-stack-data-structure-and-algorithm-tutorials/) in Python, JavaScript and Go.

### Example 1
```
Input: n = 3
Output: ["((()))", "(()())", "(())()", "()(())", "()()()"]
```

### Example 2
```
Input: n = 1
Output: ["()"]
```

## Python
```
stack = []

res = []

def backtrack(openN, closedN):
    if openN == closedN == n:
        res.append("".join(stack))
        return

    if openN < n:
        stack.append("(")
        backtrack(openN + 1, closedN)
        stack.pop()

    if closedN < openN:
        stack.append(")")
        backtrack(openN, closedN + 1)
        stack.pop()

backtrack(0, 0)

return res

# Code comments can be found in generate_parentheses.py
```

## JavaScript
```
// Function to generate all valid combinations of parentheses for a given value of n
var generateParenthesis = (n, combos = []) => {
    // Check if the base case is reached (no remaining parentheses to add)
    const isBaseCase = (n === 0);

    // If it is the base case, add an empty string to the combinations and return
    if (isBaseCase) {
        combos.push('');
        return combos;
    }

    // Iterate through possible values of c, where c represents the number of parentheses on the left
    for (let c = 0; c < n; c++) {
        // Recursively generate combinations for the left and right parts
        for (const left of generateParenthesis(c)) {
            for (const right of generateParenthesis((n - 1) - c)) {
                // Combine the left and right parts and add to the combinations
                combos.push(`(${left})${right}`);
            }
        }
    }

    // Return the list of valid combinations
    return combos;
};

// Code comments can be found in generateParentheses.js
```

## Go
```
package main

import "strings"

func generateParenthesis(n int) []string {
	var stack []string
	var res []string

	var backtrack func(int, int)
	backtrack = func(openN int, closedN int) {
		if openN == n && closedN == n && openN == closedN {
			res = append(res, strings.Join(stack, ""))
			return
		}
		if openN < n {
			stack = append(stack, "(")
			backtrack(openN+1, closedN)
			pop(&stack)
		}
		if closedN < openN {
			stack = append(stack, ")")
			backtrack(openN, closedN+1)
			pop(&stack)
		}
	}
	backtrack(0, 0)
	return res

}

func pop(list *[]string) {
	length := len(*list)
	*list = (*list)[:length-1]
}

// Code comments can be found in generateParentheses.go
```