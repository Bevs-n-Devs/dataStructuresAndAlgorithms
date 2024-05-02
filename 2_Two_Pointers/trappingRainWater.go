package main

import "fmt"

func trap(height []int) int {
	// Check if the input height array is nil
	if height == nil {
		return 0
	}

	// Initialize two pointers, left and right, at the beginning and end of the array.
	left, right := 0, len(height)-1

	// Initialize variables to store the maximum height of bars on the left and right sides.
	leftMax, rightMax := height[left], height[right]

	// Initialize a variable to store the total amount of trapped water.
	res := 0

	// Loop until the left pointer is less than the right pointer.
	for left < right {
		// If the height of the left bar is less than the height of the right bar,
		if leftMax < rightMax {
			// Move the left pointer to the right and update the maximum height of bars on the left side.
			left += 1
			leftMax = max(leftMax, height[left])
			// Calculate and add the trapped water between the left and right pointers.
			res += leftMax - height[left]
		} else {
			// Otherwise, move the right pointer to the left and update the maximum height of bars on the right side.
			right -= 1
			rightMax = max(rightMax, height[right])
			// Calculate and add the trapped water between the left and right pointers.
			res += rightMax - height[right]
		}
	}
	// Return the total amount of trapped water.
	return res
}

// max returns the maximum of two integers.
func max(a int, b int) int {
	if a > b {
		return a
	}
	return b
}

// implementation
func main() {
	fmt.Println("Leetcode 42: Trapping Rain Water\n")

	// Example 1
	example1 := []int{0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1}
	fmt.Printf("Example 1: height = %v\n", example1)
	fmt.Println("Output:", trap(example1))

	// Example 2
	example2 := []int{4, 2, 0, 3, 2, 5}
	fmt.Printf("Example 2: height = %v\n", example2)
	fmt.Println("Output:", trap(example2))
}
