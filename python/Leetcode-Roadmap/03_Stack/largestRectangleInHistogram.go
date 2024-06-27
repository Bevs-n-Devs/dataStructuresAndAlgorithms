package main

import "fmt"

type StackValue struct {
	index  int // Index of the bar in the histogram
	height int // Height of the bar
}

func largestRectangleArea(heights []int) int {
	stack := []StackValue{} // Stack to track indices and heights of bars
	maxArea := 0            // Initialize maximum area
	var start int           // Variable to store the starting index of the rectangle

	// Iterate through each bar in the histogram
	for i, h := range heights {
		start = i // Update start index for the current bar
		// While stack is not empty and the height of the current bar is less than the height of the bar at the top of the stack
		for len(stack) != 0 && stack[len(stack)-1].height > h {
			// Pop the top bar from the stack
			index, height := stack[len(stack)-1].index, stack[len(stack)-1].height
			stack = stack[0 : len(stack)-1] // Pop operation
			// Calculate the area formed by the popped bar
			maxArea = max(maxArea, height*(i-index))
			start = index // Update start index for the rectangle
		}
		stack = append(stack, StackValue{start, h}) // Push the current bar to the stack
	}

	// Process any remaining bars in the stack
	for _, h := range stack {
		// Calculate the area formed by the remaining bars
		maxArea = max(maxArea, h.height*(len(heights)-h.index))
	}
	return maxArea // Return the maximum area
}

// Function to find the maximum of two integers
func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

// implementation
func main() {
	fmt.Println("Leetcode 84: Largest Rectangle in Histogram\n")

	// Example 1
	example1 := []int{2, 1, 5, 6, 2, 3}
	fmt.Printf("Example 1: heights = %v\n", example1)
	fmt.Println("Output:", largestRectangleArea(example1))

	// Example 2
	example2 := []int{2, 4}
	fmt.Printf("Example 2: heights = %v\n", example2)
	fmt.Println("Output:", largestRectangleArea(example2))
}
