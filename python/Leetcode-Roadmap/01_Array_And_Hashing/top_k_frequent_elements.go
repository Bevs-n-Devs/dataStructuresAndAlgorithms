package main

import (
	"fmt"
)

func topKFrequent(nums []int, k int) []int {
	// Dictionary to store the count of each number
	count := make(map[int]int)

	// List to store numbers grouped by frequency
	freq := make([][]int, len(nums)+1)

	// Count the occurrences of each number in the input list
	for _, num := range nums {
		count[num]++
	}

	// Group numbers by frequency in the 'freq' list
	for index, num := range count {
		freq[num] = append(freq[num], index)
	}

	// Result list to store the top k frequent numbers
	result := make([]int, 0, k)

	// Iterate through the 'freq' list in reverse order
	for index := len(freq) - 1; index > 0; index-- {
		// Iterate through the numbers in the current frequency group
		for _, num := range freq[index] {
			// Append the number to the result list
			result = append(result, num)
			// Check if the result list has reached the desired length k
			if len(result) == k {
				return result
			}
		}
	}

	// The function will only reach this point if k is greater than the number of unique elements in the input list
	return result
}

// implementation

func main() {
	fmt.Println("Leetcode 347: Top K Frequent Elements\n")

	// Example 1
	example1 := []int{1, 1, 1, 2, 2, 3}
	k1 := 2
	fmt.Printf("Example 1: nums = %v, k = %v\n", example1, k1)
	fmt.Println("Output:", topKFrequent(example1, k1))

	// Example 2
	example2 := []int{1}
	k2 := 1
	fmt.Printf("Example 1: nums = %v, k = %v\n", example2, k2)
	fmt.Println("Output:", topKFrequent(example2, k2))

}
