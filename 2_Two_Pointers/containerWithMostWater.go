package main

import "fmt"

// maxArea calculates the maximum area of water that can be held by two lines in the array.
func maxArea(height []int) int {
	// Initialize two pointers, left at the start of the array and right at the end of the array.
	left := 0
	right := len(height) - 1

	// Initialize a variable to store the maximum area.
	res := 0

	// Loop until the left pointer is less than the right pointer.
	for left < right {
		// Calculate the area of the current container using the minimum height of the two lines multiplied by the distance between them.
		area := min(height[left], height[right]) * (right - left)

		// Update the maximum area if the current area is greater.
		if area > res {
			res = area
		}

		// Move the pointer pointing to the shorter line towards the center.
		// If the height of the line at the left pointer is greater than the height of the line at the right pointer, move the right pointer to the left.
		// Otherwise, move the left pointer to the right.
		if height[left] > height[right] {
			right--
		} else {
			left++
		}
	}

	// Return the maximum area.
	return res
}

// min returns the minimum of two integers.
func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

// implementation
func main() {
	fmt.Println("Hello world, hello Yaw!")
	fmt.Println("Leetcode 11: Container With Most Water\n")

	// Example 1
	example1 := []int{1, 8, 6, 2, 5, 4, 8, 3, 7}
	fmt.Printf("Example 1: height = %v\n", example1)
	fmt.Println("Output:", maxArea(example1))

	// Example 2
	example2 := []int{1, 1}
	fmt.Printf("Example 2: height = %v\n", example2)
	fmt.Println("Output", maxArea(example2))
}
