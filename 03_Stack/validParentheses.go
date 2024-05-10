package main

import "fmt"

func isValid(s string) bool {
	// Define pairs of opening and closing brackets.
	pairs := map[byte]byte{
		'}': '{',
		']': '[',
		')': '(',
	}

	// Initialize a stack to keep track of opening brackets.
	stack := make([]byte, 0)

	// Loop through each character in the input string.
	for _, char := range []byte(s) {
		// Check if the character is a closing bracket.
		pair, ok := pairs[char]
		if !ok {
			// If it's not a closing bracket, it's an opening bracket, so push it onto the stack.
			stack = append(stack, char)
			continue
		}

		// If it's a closing bracket, but the stack is empty, there's no matching opening bracket, so return false.
		if len(stack) == 0 {
			return false
		}

		// Check if the top of the stack (last element) matches the corresponding opening bracket.
		if stack[len(stack)-1] != pair {
			return false
		}

		// If they match, pop the opening bracket from the stack.
		stack = stack[:len(stack)-1]
	}

	// After looping through all characters, if the stack is empty, all opening brackets have been closed, so return true.
	return len(stack) == 0
}

// implementation

func main() {
	fmt.Println("Leetcode 20: Valid Paretheses\n")

	// Example 1
	example1 := "()"
	fmt.Printf("Example 1: s = %s\n", example1)
	fmt.Print("Output:", isValid(example1))

	// Example 2
	example2 := "()[]{}"
	fmt.Printf("Example 2: s = %s\n", example2)
	fmt.Println("Output:", isValid(example2))

	// Example 3
	example3 := "(]"
	fmt.Printf("Example 3: s = %s\n", example3)
	fmt.Println("Output:", isValid(example3))
}
