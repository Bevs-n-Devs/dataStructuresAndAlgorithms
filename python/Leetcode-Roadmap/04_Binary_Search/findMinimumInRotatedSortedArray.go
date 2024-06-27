package main

import "fmt"

func findMin(nums []int) int {
	res := nums[0]         // Initialize the result variable with the first element.
	l, r := 0, len(nums)-1 // Initialize left and right pointers.

	for l <= r { // Continue the loop until left pointer is less than or equal to right pointer.
		p := (l + r) / 2        // Calculate the middle index.
		if nums[p] >= nums[0] { // If the middle element is greater than or equal to the first element.
			l = p + 1 // Update the left pointer.
		} else { // If the middle element is less than the first element.
			if nums[p] < res { // If the middle element is less than the current minimum.
				res = nums[p] // Update the result.
			}
			r = p - 1 // Update the right pointer.
		}
	}

	return res // Return the minimum element.
}

// implementation
func main() {
	fmt.Println("Leetcode 153: Find Minimum In Rotated Sorted Array\n")

	// Example 1
	example1 := []int{3, 4, 5, 1, 2}
	fmt.Printf("Example 1: nums = %v\n", example1)
	fmt.Println("Output:", findMin(example1))

	// Example 2
	example2 := []int{4, 5, 6, 7, 0, 1, 2}
	fmt.Printf("Example 2: nums = %v\n", example2)
	fmt.Println("Output:", findMin(example2))

	// Example 3
	example3 := []int{11, 13, 15, 17}
	fmt.Printf("Example 3: nums = %v\n", example3)
	fmt.Println("Output:", findMin(example3))
}
