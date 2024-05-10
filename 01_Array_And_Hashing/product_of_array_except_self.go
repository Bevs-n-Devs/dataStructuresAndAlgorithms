package main

import "fmt"

func productExceptSelf(nums []int) []int {
	// craete a list object same length as nums
	result := make([]int, len(nums))
	// initialise the result with all elements set to 1
	for index := range result {
		result[index] = 1
	}

	// calculate the prefix products and update the result array
	for index := 1; index < len(nums); index++ {
		result[index] = result[index-1] * nums[index-1]
	}

	// create a postfix variable to store postfix product
	postfix := 1

	// update the result of the array with the postfix products
	for index := len(nums) - 1; index >= 0; index-- {
		result[index] *= postfix
		postfix *= nums[index]
	}

	// return the final result array
	return result
}

// implementation
func main() {
	fmt.Println("Leetcode 238: Product of Array Except Self\n")

	// Example 1
	example1 := []int{1, 2, 3, 4}
	fmt.Printf("Example 1: nums = %v\n", example1)
	fmt.Println("Output:", productExceptSelf(example1))

	// Example 2
	example2 := []int{-1, 1, 0, -3, 3}
	fmt.Printf("Example 1: nums = %v\n", example2)
	fmt.Println("Output:", productExceptSelf(example2))
}
