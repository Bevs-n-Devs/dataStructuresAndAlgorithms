package main

import "fmt"

// canEat checks if all bananas can be eaten within the time limit at a given speed.
// It returns true if possible, false otherwise.
func canEat(piles []int, timeLimit, speed int) bool {
	timeNeed := 0
	// Calculate total time needed to eat all bananas at the given speed
	for _, banana := range piles {
		timeNeed += (banana + speed - 1) / speed // Divide bananas by speed, rounding up
		if timeNeed > timeLimit {
			return false // If time exceeds limit, return false
		}
	}
	return true
}

// minEatingSpeed calculates the minimum eating speed required to finish all bananas within given hours.
func minEatingSpeed(piles []int, h int) int {
	lo, hi, ans := 1, 1000000000, 1 // Initial range for eating speed
	// Binary search for the minimum speed
	for lo <= hi {
		mid := (lo + hi) / 2 // Calculate mid speed
		if canEat(piles, h, mid) {
			ans = mid // If eating is possible, update answer and try slower speeds
			hi = mid - 1
		} else {
			lo = mid + 1 // Otherwise, try faster speeds
		}
	}
	return ans
}

// implementation
func main() {
	fmt.Println("Leetcode 875: Koko Eating Bananas\n")

	// Example 1
	piles1 := []int{3, 6, 7, 11}
	hours1 := 8
	fmt.Printf("Example 1: piles = %v, h = %v\n", piles1, hours1)
	fmt.Println("Output:", minEatingSpeed(piles1, hours1))

	// Example 2
	piles2 := []int{30, 11, 23, 4, 20}
	hours2 := 5
	fmt.Printf("Example 2: piles = %v, h = %v\n", piles2, hours2)
	fmt.Println("Output:", minEatingSpeed(piles2, hours2))

	// ExAMPLE 3
	hours3 := 6
	fmt.Printf("Example 3: piles = %v, h = %v\n", piles2, hours3)
	fmt.Println("Output:", minEatingSpeed(piles2, hours3))
}
