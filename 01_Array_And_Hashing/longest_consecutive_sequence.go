package main

import "fmt"

func longestConsecutive(nums []int) int {
	// Initialize a map 'set' to store unique integers as keys
	// and boolean values to indicate presence in the set.
	set := map[int]bool{}

	// Iterate through each number in 'nums' slice.
	for _, num := range nums {
		// Add the current number to the set.
		set[num] = true
	}

	// Initialize a variable 'result' to store the longest consecutive sequence length.
	result := 0

	// Iterate through each number in 'nums' slice again.
	for _, num := range nums {
		// Check if the previous number (num-1) exists in the set.
		// If it does, it means 'num' is not the starting point of a sequence, so skip.
		if set[num-1] {
			continue
		}

		// Initialize 'sequence' to 1, as the current number is the start of a sequence.
		sequence := 1
		// Initialize 'temp' with the next number after 'num'.
		temp := num + 1

		// Loop to find consecutive numbers in the set, starting from 'temp'.
		for set[temp] {
			// Increment 'sequence' for each consecutive number found.
			sequence++
			temp++
		}

		// If the current sequence is longer than the stored result, update 'result'.
		if sequence > result {
			result = sequence
		}
	}

	// Return the longest consecutive sequence length.
	return result
}

// implementation

func main() {
	fmt.Println("Leetcode 128: Longest Consecutive Sequence\n")

	example1 := []int{100, 4, 200, 1, 3, 2}
	fmt.Printf("Example 1: mums = %v\n", example1)
	fmt.Println("Output:", longestConsecutive(example1))

	example2 := []int{0, 3, 7, 2, 5, 8, 4, 6, 0, 1}
	fmt.Printf("Example 1: mums = %v\n", example2)
	fmt.Println("Output:", longestConsecutive(example2))
}
