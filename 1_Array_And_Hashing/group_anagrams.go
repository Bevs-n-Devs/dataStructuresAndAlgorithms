package main

import (
	"fmt"
	"sort"
)

func groupAnagrams(strs []string) [][]string {
	groupedAnagrams := make(map[string][]string)

	for _, str := range strs {
		// Convert string to slice of bytes
		slice := []byte(str)
		// Sort the slice of bytes
		sort.Slice(slice, func(i, j int) bool {
			return slice[i] < slice[j]
		})
		// Convert the sorted slice back to string
		sortedStr := string(slice)

		// If the sorted string is not in the map, initialize a new slice
		if _, ok := groupedAnagrams[sortedStr]; !ok {
			groupedAnagrams[sortedStr] = []string{}
		}
		// Append the original string to the slice in the map
		groupedAnagrams[sortedStr] = append(groupedAnagrams[sortedStr], str)
	}

	// Convert map values to slice of slices
	result := make([][]string, 0, len(groupedAnagrams))
	for _, v := range groupedAnagrams {
		result = append(result, v)
	}

	return result
}

func main() {
	fmt.Println("Group Anagrams\n")

	// Example 1
	example1 := []string{"eat", "tea", "tan", "ate", "nat", "bat"}
	fmt.Println("Example 1: strs = ['eat', 'tea', 'tan', 'ate', 'nat', 'bat']")
	fmt.Println("Output:", groupAnagrams(example1))

	// Example 2
	example2 := []string{""}
	fmt.Println("Example 2: strs = ['']")
	fmt.Println("Output:", groupAnagrams(example2))

	// Example 3
	example3 := []string{"a"}
	fmt.Println("Example 2: strs = ['a']")
	fmt.Println("Output:", groupAnagrams(example3))
}
