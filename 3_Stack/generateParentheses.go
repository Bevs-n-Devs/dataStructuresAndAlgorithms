package main

import (
	"fmt"
	"strings"
)

// generateParenthesis generates all combinations of well-formed parentheses for given n pairs.
func generateParenthesis(n int) []string {
	var stack []string // stack to track current combination
	var res []string   // result to store valid combinations

	// backtrack recursively generates combinations
	var backtrack func(int, int)
	backtrack = func(openN int, closedN int) {
		// If both open and closed parentheses count reach n, add the combination to result
		if openN == n && closedN == n && openN == closedN {
			res = append(res, strings.Join(stack, ""))
			return
		}
		// If there are less than n open parentheses, add one and backtrack
		if openN < n {
			stack = append(stack, "(")
			backtrack(openN+1, closedN)
			pop(&stack) // remove the last element added (backtrack)
		}
		// If there are less closed parentheses than open ones, add one and backtrack
		if closedN < openN {
			stack = append(stack, ")")
			backtrack(openN, closedN+1)
			pop(&stack) // remove the last element added (backtrack)
		}
	}
	backtrack(0, 0) // start backtrack with 0 open and closed parentheses
	return res
}

// pop removes the last element from the slice (similar to pop() in other languages)
func pop(list *[]string) {
	length := len(*list)
	*list = (*list)[:length-1]
}

// implementation
func main() {
	fmt.Println("Leetcode 22: Generate Parentheses\n")

	// Example 1
	example1 := 3
	fmt.Printf("Example 1: n = %d\n", example1)
	fmt.Println("Output:", generateParenthesis(example1))

	// Example 2
	example2 := 1
	fmt.Printf("Example 2: n = %d\n", example2)
	fmt.Println("Output:", generateParenthesis(example2))
}
