package main

import "fmt"

func dailyTemperatures(temperatures []int) []int {
	// Create a result slice to store the number of days to wait for warmer temperatures
	result := make([]int, len(temperatures))

	// Iterate over the temperatures in reverse order
	for i := len(temperatures) - 1; i >= 0; i-- {
		// Start checking temperatures from the next day
		j := i + 1

		// Keep moving forward until you find a warmer temperature or reach the end of the temperatures
		for j < len(temperatures) && temperatures[j] <= temperatures[i] {
			// If there's no future day with a warmer temperature, break out of the loop
			if result[j] <= 0 {
				break
			}
			// Move to the next day with a potentially warmer temperature based on previous calculations
			j += result[j]
		}

		// If a warmer temperature is found, calculate the number of days to wait and store it in the result
		if j < len(temperatures) && temperatures[j] > temperatures[i] {
			result[i] = j - i
		}

	}
	return result
}

// implementation
func main() {
	fmt.Println("Leetcode 739: Daily Temperatures\n")

	// Example 1
	example1 := []int{73, 74, 75, 71, 69, 72, 76, 73}
	fmt.Printf("Example 1: temperatures = %v\n", example1)
	fmt.Println("Output:", dailyTemperatures(example1))

	// Example 2
	example2 := []int{30, 40, 50, 60}
	fmt.Printf("Example 2: temperatures = %v\n", example2)
	fmt.Println("Output:", dailyTemperatures(example2))

	// Example 3
	example3 := []int{30, 60, 90}
	fmt.Printf("Example 3: temperatures = %v\n", example3)
	fmt.Println("Output:", dailyTemperatures(example3))
}
