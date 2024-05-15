package main

import (
	"fmt"
	"math"
)

func findMedianSortedArrays(nums1 []int, nums2 []int) float64 {
	// Assign the arrays to A and B, ensuring A is the smaller array
	A, B := nums1, nums2
	if len(B) < len(A) {
		A, B = B, A
	}

	// Calculate total number of elements and the half-point
	total := len(A) + len(B)
	half := (total + 1) / 2

	// Initialize variables to store partition elements
	var Aleft, Aright, Bleft, Bright float64

	// Initialize binary search bounds
	l, r := 0, len(A)-1
	for {
		// Calculate partition indices for A and B
		i := (l + r) >> 1 // A's partition index
		j := half - i - 2 // B's partition index

		// Set Aleft and Aright based on partition index
		if i >= 0 {
			Aleft = float64(A[i])
		} else {
			Aleft = math.Inf(-1) // -∞ if no left part
		}

		if (i + 1) < len(A) {
			Aright = float64(A[i+1])
		} else {
			Aright = math.Inf(1) // +∞ if no right part
		}

		// Set Bleft and Bright based on partition index
		if j >= 0 {
			Bleft = float64(B[j])
		} else {
			Bleft = math.Inf(-1) // -∞ if no left part
		}

		if (j + 1) < len(B) {
			Bright = float64(B[j+1])
		} else {
			Bright = math.Inf(1) // +∞ if no right part
		}

		// Check if partitions are correct
		if Aleft <= Bright && Bleft <= Aright {
			// Odd total number of elements
			if total%2 == 1 {
				return max(Aleft, Bleft)
			}
			// Even total number of elements
			return (max(Aleft, Bleft) + min(Aright, Bright)) / 2
		} else if Aleft > Bright {
			// Aleft is too big, move left partition left
			r = i - 1
		} else {
			// Bleft is too big, move left partition right
			l = i + 1
		}
	}
}

// Helper functions to get max and min of two float64 numbers
func max(a, b float64) float64 {
	if a > b {
		return a
	}
	return b
}

func min(a, b float64) float64 {
	if a < b {
		return a
	}
	return b
}

// implementation

func main() {
	fmt.Print("Leetcode 4: Median of Two Sorted Ararys\n")

	// Example 1
	nums1 := []int{1, 3}
	nums2 := []int{2}
	fmt.Printf("Example 1: nums1 = %v, nums2 = %v\n", nums1, nums2)
	fmt.Println("Output:", findMedianSortedArrays(nums1, nums2))

	// Example 2
	nums3 := []int{1, 2}
	nums4 := []int{3, 4}
	fmt.Printf("Example 2: nums1 = %v, nums2 = %v\n", nums3, nums4)
	fmt.Println("Output:", findMedianSortedArrays(nums3, nums4))
}
