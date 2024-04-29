package main

import "fmt"

func twoSum(numbers []int, target int) []int {
	// Initialize two pointers, p1 at the start of the array and p2 at the end of the array
	p1 := 0
	p2 := len(numbers) - 1

	// Loop until p1 is less than p2
	for p1 < p2 {
		// Calculate the sum of the numbers at positions p1 and p2
		n := numbers[p1] + numbers[p2]

		// If the sum equals the target, return the indices (adding 1 because indices are 1-indexed)
		if n == target {
			return []int{p1 + 1, p2 + 1}
		}

		// If the sum is greater than the target, move p2 to the left to decrease the sum
		if n > target {
			p2--
		} else { // If the sum is less than the target, move p1 to the right to increase the sum
			p1++
		}
	}

	// If no solution is found, return [0, 0]
	return []int{0, 0}
}

// implementation

func main() {
	fmt.Println("Leetcode 167: Two Sum 2 - Input Array is Sorted\n")

	// Example 1
	example1 := []int{2, 7, 11, 15}
	target1 := 9
	fmt.Printf("Example 1: nums = %v, target = %d\n", example1, target1)
	fmt.Println("Output:", twoSum(example1, target1))

	// Example 2
	example2 := []int{2, 3, 4}
	target2 := 6
	fmt.Printf("Example 2: nums = %v, target = %d\n", example2, target2)
	fmt.Println("Output:", twoSum(example2, target2))

	// Example 3
	example3 := []int{-1, 0}
	target3 := -1
	fmt.Printf("Example 3: nums = %v, target = %d\n", example3, target3)
	fmt.Println("Output:", twoSum(example3, target3))
}
