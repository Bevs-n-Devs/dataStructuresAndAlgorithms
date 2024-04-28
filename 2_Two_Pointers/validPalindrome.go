package main

import (
	"fmt"
	"strings"
)

func isPalindrome(s string) bool {
	// Create an empty string to store letters
	var newStr strings.Builder

	// Loop through each letter of the string
	for _, char := range s {
		// Check if letter is alphanumeric
		if (char >= 'a' && char <= 'z') || (char >= 'A' && char <= 'Z') || (char >= '0' && char <= '9') {
			// Add letter to the empty string
			newStr.WriteRune(char)
		}
	}

	// Convert the string builder to a string
	str := newStr.String()

	// Reverse the letters to see if it's a palindrome
	return strings.ToLower(str) == reverseString(str)
}

// Function to reverse a string
func reverseString(s string) string {
	runes := []rune(s)
	for i, j := 0, len(runes)-1; i < j; i, j = i+1, j-1 {
		runes[i], runes[j] = runes[j], runes[i]
	}
	return string(runes)
}

// implementation

func main() {
	fmt.Println("Leetcode 125: Valid Palindrome\n")

	// Example 1
	example1 := "A man, a plan, a canal: Panama"
	fmt.Printf("Example 1: s = '%s'\n", example1)
	fmt.Println("Output:", isPalindrome(example1))

	// Example 2
	example2 := "race a car"
	fmt.Printf("Example 2: s = '%s'\n", example2)
	fmt.Println("Output:", isPalindrome(example2))

	// Example 3
	example3 := " "
	fmt.Printf("Example 3: '%s'\n", example3)
	fmt.Println("Output:", isPalindrome(example3))
}
