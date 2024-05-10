// Online Go compiler to run Golang program online
// Print "Try programiz.pro" message

package main

import "fmt"

func twoSum(nums []int, target int) []int {
	// Create hashmap
	hashmap := make(map[int]int)

	for listIndex := 0; listIndex < len(nums); listIndex++ {
		// Get each number from the list
		num := nums[listIndex]
		// Calculate the difference between the target and the current number
		diff := target - num

		// Check if the difference exists in the hashmap
		if _, found := hashmap[diff]; found {
			// If found, return the indices of the two numbers
			return []int{hashmap[diff], listIndex}
		}

		// Update the hashmap
		hashmap[num] = listIndex
	}

	return nil // Return nil if no solution is found
}

// implementation

func main() {
	fmt.Println("Leetcode 1: Two Sum\n") // Printing the requested message

	// Example 1
	example1 := []int{2, 7, 11, 15}
	target1 := 9
	fmt.Printf("Example1: nums = %v, target = %v", example1, target1)
	fmt.Println("\nOutput:", twoSum(example1, target1))

	// Example 2
	example2 := []int{3, 2, 4}
	target2 := 6
	fmt.Printf("Example1: nums = %v, target = %v", example2, target2)
	fmt.Println("\nOutput:", twoSum(example2, target2))

	// Example 3
	example3 := []int{3, 3}
	target3 := 6
	fmt.Printf("Example1: nums = %v, target = %v", example3, target3)
	fmt.Println("\nOutput:", twoSum(example3, target3))

}
