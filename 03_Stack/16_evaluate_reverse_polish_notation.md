Stack 3
# Evaluate Reverse Polish Notation
## Company: Amazon
### Level: Medium

You are given an array of string `tokens` that represent an arithmetic expression in a [Reverse Polish Notation](https://en.wikipedia.org/wiki/Reverse_Polish_notation).

Evaluate the expression. Return an *integer* that represents the value of the expression.

**Please note:**
- The valid operators are `+`, `-`, `*`, and `/`.
- Each operand may be an integer or another expression.
- The division between two integers always **truncate twoards zero**.
- There will not be any division of zero.
- The input represents a valid arithmetic expression in a reverse polish notation.
- The answer and all the intermediate calculations can be represented in a **32-bit** integer.

***Break It Down For Me...***
*What we bascially need to do is find the value of a given erxpression.*
*We only have to deal with addition, subtraction, multiplication and division.*
*The expressionm is written in Reverse Polish Notation which means the operators come after their operands.*
*All numbers are integers, and the division truncates towards zero.*
*The final answer has to be within the 32-bit range.*


Click [here](https://leetcode.com/problems/evaluate-reverse-polish-notation/description/) for the question on Leetcode.

Click [here](https://www.youtube.com/watch?v=iu0082c4HDE) for the solution on [Neetcode](https://neetcode.io/) **(which I would strongly reccomed you to get familiar with.)**

To solve this challenge we will use a [Stack](https://www.geeksforgeeks.org/introduction-to-stack-data-structure-and-algorithm-tutorials/) and [HashMap](https://stackoverflow.com/questions/2592043/what-is-a-hash-map-in-programming-and-where-can-it-be-used) in Pythopn, JavaScript and Go.

### Example 1
```
Input: tokens = ["2", "1", "+", "3", "*"]
Output: 9
```
**Explanation:** `((2 + 1) * 3) = 9`

### Example 2
```
Input: tokens = ["4", "13", "5", "/", "+"]
Output: 6
```
**Explanation:** `(4 + (13 / 5)) = 6`

### Example 3
```
Input: tokens = ["10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"] 
Output: 22
```

## Python
```
stack = []
for c in tokens:
    if c == "+":
        stack.append(stack.pop() + stack.pop())
    elif c == "-":
        a, b = stack.pop(), stack.pop()
        stack.append(b - a)
    elif c == "*":
        stack.append(stack.pop() * stack.pop())
    elif c == "/":
        a, b = stack.pop(), stack.pop()
        stack.append(int(b / a))
    else:
        stack.append(int(c))
return stack[0]

# Code comments casn be found in evaluate_reverse_polish_notation.py
```

## JavaScript
```
var evalRPN = function (tokens, stack = []) {
    for (const char of tokens) {
        const isOperation = char in OPERATORS;
        if (isOperation) {
            const value = performOperation(char, stack);

            stack.push(value);    

            continue;
        }

        stack.push(Number(char)); 
    }

    return stack.pop();
}

var OPERATORS = {
    '+': (a, b) => a + b,
    '-': (a, b) => a - b,
    '*': (a, b) => a * b,
    '/': (a, b) => Math.trunc(a / b)
};

// Code comments can be found in evaluateReversePolishNotation.js
```

## Go
```
func evalRPN(tokens []string) int {
	var stack []int
	var a, b int
	for _, c := range tokens {
		switch c {
		case "+":
			a, b, stack = getAndPopLastOperand(stack)
			stack = append(stack, (a + b))
		case "-":
			a, b, stack = getAndPopLastOperand(stack)
			stack = append(stack, (a - b))
		case "*":
			a, b, stack = getAndPopLastOperand(stack)
			stack = append(stack, (a * b))
		case "/":
			a, b, stack = getAndPopLastOperand(stack)
			stack = append(stack, (a / b))
		default:
			i, _ := strconv.Atoi(c)
			stack = append(stack, i)
		}
	}
	return stack[0]
}

func getAndPopLastOperand(stack []int) (int, int, []int) {
	a := stack[len(stack)-2]
	b := stack[len(stack)-1]
	stack = stack[:len(stack)-2]

	return a, b, stack
}

// Code comments can be found in evaluateReversePolishNotation.go
```