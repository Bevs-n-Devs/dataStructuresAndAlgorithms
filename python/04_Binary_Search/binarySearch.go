package main

import "fmt"

// Function to perform binary search on a sorted array
func search(nums []int, target int) int {
	left := 0              // Pointer for the leftmost index of the search range
	right := len(nums) - 1 // Pointer for the rightmost index of the search range

	// Continue searching as long as the left pointer doesn't surpass the right pointer
	for left <= right {
		middle := (left + right) / 2 // Calculate the middle index of the current search range

		// Check if the middle element is equal to the target
		if nums[middle] == target {
			return middle // Return the index where the target is found
		} else if nums[middle] < target {
			left = middle + 1 // If the target is greater than the middle element, search the right half
		} else {
			right = middle - 1 // If the target is less than the middle element, search the left half
		}
	}
	return -1 // Return -1 if the target is not found in the list
}

// implementation
func main() {
	fmt.Println("Leetcode 704: Binary Search")
	nums := []int{-1, 0, 3, 5, 9, 12}

	// Example 1
	target1 := 9
	fmt.Printf("Example 1: nums = %v, target = %v\n", nums, target1)
	fmt.Println("Output:", search(nums, target1))

	// Example 2
	target2 := 2
	fmt.Printf("Example 2: nums = %v, target = %v\n", nums, target2)
	fmt.Println("Output:", search(nums, target2))
}
