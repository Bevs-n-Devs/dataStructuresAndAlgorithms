package main

import "fmt"

func isAnagram(s string, t string) bool {
	// check if the length of both words are equal
	if len(s) != len(t) {
		return false
	}

	// create 2 hashmaps for s & t
	countS := make(map[byte]int)
	countT := make(map[byte]int)

	// loop through strings adding to hashmap
	for char := 0; char < len(s); char++ {
		countS[s[char]]++
		countT[t[char]]++
	}

	// check if both hasmaps are NOT equal
	for char, count := range countS {
		if count != countT[char] {
			return false
		}
	}
	// return true if equal
	return true
}

// implementation

func main() {
	fmt.Println("Leetcode 242: Valid Anagram \n")

	// Example 1
	s1 := "anagram"
	t1 := "nagaram"
	fmt.Printf("Example 1: s = '%s', t = '%s' \n", s1, t1)
	fmt.Println("Output:", isAnagram(s1, t1))

	// Example 2
	s2 := "rat"
	t2 := "car"
	fmt.Printf("Example 1: s = '%s', t = '%s' \n", s2, t2)
	fmt.Println("Output:", isAnagram(s2, t2))
}
