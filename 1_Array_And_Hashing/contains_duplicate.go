package main

import "fmt"

func containsDuplicate(nums []int) bool {
	// initialise boolean variable
	var isDuplicate bool

	// Loop through nums list by creating a right pointer
	for right := 0; right < len(nums); right++ {
		// Loop through the right pointer by creating a left pointer
		for left := 0; left < right; left++ {
			// In each loop, check if the numbers match
			if nums[left] == nums[right] {
				// Set isDuplicate to true if there is a match
				isDuplicate = true
				// Break out of the loop once a duplicate is found
				break
			}
		}
		// Break out of the outer loop if a duplicate is found
		if isDuplicate {
			break
		}
	}
	return isDuplicate
}

// implementation

func main() {
	fmt.Println("Leetcode 217: Contains Duplicate\n")

	example1 := []int{1, 2, 3, 1}
	fmt.Printf("Example 1: nums = %v\n", example1)
	fmt.Println("Outcome:", containsDuplicate(example1))

	example2 := []int{1, 2, 3, 4}
	fmt.Printf("Example 2: nums = %v\n", example2)
	fmt.Println("Outcome:", containsDuplicate(example2))

	example3 := []int{1, 1, 1, 3, 3, 4, 3, 2, 4, 1}
	fmt.Printf("Example 3: nums = %v\n", example3)
	fmt.Println("Outcome:", containsDuplicate(example3))

}
