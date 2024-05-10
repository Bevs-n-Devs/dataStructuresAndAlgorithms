package main

import (
	"fmt"
	"sort"
)

func threeSum(nums []int) [][]int {
	num := len(nums)

	// Sort the given array
	sort.Ints(nums)

	var result [][]int
	for num1Idx := 0; num1Idx < num-2; num1Idx++ {
		// Skip all duplicates from left
		// num1Idx>0 ensures this check is made only from 2nd element onwards
		if num1Idx > 0 && nums[num1Idx] == nums[num1Idx-1] {
			continue
		}

		num2Idx := num1Idx + 1
		num3Idx := num - 1
		for num2Idx < num3Idx {
			sum := nums[num2Idx] + nums[num3Idx] + nums[num1Idx]
			if sum == 0 {
				// Add triplet to result
				result = append(result, []int{nums[num1Idx], nums[num2Idx], nums[num3Idx]})

				num3Idx--

				// Skip all duplicates from right
				for num2Idx < num3Idx && nums[num3Idx] == nums[num3Idx+1] {
					num3Idx--
				}
			} else if sum > 0 {
				// Decrement num3Idx to reduce sum value
				num3Idx--
			} else {
				// Increment num2Idx to increase sum value
				num2Idx++
			}
		}
	}
	return result
}

// implementation

func main() {
	fmt.Println("Leetcode 15: 3 Sum\n")

	// Example 1
	example1 := []int{-1, 0, 1, 2, -1, -4}
	fmt.Printf("Example 1: nums = %v\n", example1)
	fmt.Println("Output:", threeSum(example1))

	// Example 2
	example2 := []int{0, 1, 1}
	fmt.Printf("Example 2: nums = %v\n", example2)
	fmt.Println("Output:", threeSum(example2))

	// Excample 3
	example3 := []int{0, 0, 0}
	fmt.Printf("Example 3: nums = %v\n", example3)
	fmt.Println("Output:", threeSum(example3))
}
