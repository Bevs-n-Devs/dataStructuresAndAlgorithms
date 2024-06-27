package main

import "fmt"

// Function to search for a target integer in a 2D matrix
func searchMatrix(matrix [][]int, target int) bool {
	ROWS := len(matrix)       // Get the number of rows in the matrix
	COLUMNS := len(matrix[0]) // Get the number of columns in the matrix

	top := 0        // Initialize a pointer for the top row
	bot := ROWS - 1 // Initialize a pointer for the bottom row

	// Binary search for the row containing the target value
	for top <= bot {
		row := (top + bot) / 2 // Calculate the middle row index
		// If target is greater than the last element of the current row, move to the next row
		if target > matrix[row][COLUMNS-1] {
			top = row + 1
		} else if target < matrix[row][0] { // If target is less than the first element of the current row, move to the previous row
			bot = row - 1
		} else { // If target is within the current row, break the loop
			break
		}
	}

	// If the top pointer is greater than the bottom pointer, target is not found
	if !(top <= bot) {
		return false
	}

	row := (top + bot) / 2 // Set the row index where the target might be present
	left := 0              // Initialize a pointer for the leftmost column
	right := COLUMNS - 1   // Initialize a pointer for the rightmost column

	// Binary search for the target within the selected row
	for left <= right {
		middle := (left + right) / 2 // Calculate the middle column index
		// If target is greater than the middle element, move to the right half
		if target > matrix[row][middle] {
			left = middle + 1
		} else if target < matrix[row][middle] { // If target is less than the middle element, move to the left half
			right = middle - 1
		} else { // If target is found, return true
			return true
		}
	}
	return false // Return false if target is not found
}

// implementation
func main() {
	fmt.Println("Leetcode 74: Search A 2D Matrix\n")
	matrix := [][]int{
		{1, 3, 5, 7},
		{10, 11, 16, 20},
		{23, 30, 34, 60},
	}

	// Example 1
	target1 := 3
	fmt.Printf("Example 1: matrix = %v, target = %v\n", matrix, target1)
	fmt.Println("Output:", searchMatrix(matrix, target1))

	// Example 2
	target2 := 13
	fmt.Printf("Example 2: matrix = %v, target = %v\n", matrix, target2)
	fmt.Println("Output:", searchMatrix(matrix, target2))

}
