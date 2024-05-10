package main

import (
	"fmt"
	"strconv"
)

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

func main() {
	fmt.Println("Leetcode 150: Evaluate Reverse Polish Notation\n")

	// Example 1
	example1 := []string{"2", "1", "+", "3", "*"}
	fmt.Printf("Example 1: tokens = %v\n", example1)
	fmt.Println("Output", evalRPN(example1))

	// Example 2
	example2 := []string{"4", "13", "5", "/", "+"}
	fmt.Printf("Example 2: tokens = %v\n", example2)
	fmt.Println("Output", evalRPN(example2))

	// Example 3
	example3 := []string{"10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"}
	fmt.Printf("Example 3: tokens = %v\n", example3)
	fmt.Println("Output", evalRPN(example3))
}
