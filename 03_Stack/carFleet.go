package main

import (
	"fmt"
	"sort"
)

// carFleet calculates the number of car fleets that reach the target destination.
// Parameters:
//   - target: the target position.
//   - position: an array of positions of cars.
//   - speed: an array of speeds of cars.
//
// Returns:
//   - The number of car fleets.
func carFleet(target int, position []int, speed []int) int {
	// Define a struct to hold position and speed of each car
	pair := []carInfo{}
	// Define a stack to store time taken for each car to reach the target
	stack := []float32{}

	// Populate the carInfo struct with position and speed data
	for i, _ := range position {
		pair = append(pair, carInfo{position[i], speed[i]})
	}

	// Sort the cars based on their position
	sort.Slice(pair, func(i, j int) bool {
		return pair[i].pos < pair[j].pos
	})

	// Calculate the time taken for each car to reach the target
	for i := len(pair) - 1; i >= 0; i-- {
		stack = append(stack, float32(target-pair[i].pos)/float32(pair[i].spd))
		// Check if there are multiple cars at the same position
		// If a car behind can reach the target earlier than the car in front,
		// remove the car in front from the stack
		if len(stack) >= 2 && stack[len(stack)-1] <= stack[len(stack)-2] {
			stack = stack[:len(stack)-1]
		}
	}

	// The number of car fleets is equal to the number of elements in the stack
	return len(stack)
}

// Define a struct to hold position and speed information of a car
type carInfo struct {
	pos int // Position of the car
	spd int // Speed of the car
}

// implementation

func main() {
	fmt.Println("Leetcode 853: Car Fleet\n")

	// Example 1
	target1 := 12
	position1 := []int{10, 8, 0, 5, 3}
	speed1 := []int{2, 4, 1, 1, 3}
	fmt.Printf("Example 1: target = %v, position = %v, speed = %v\n", target1, position1, speed1)
	fmt.Println("Output:", carFleet(target1, position1, speed1))

	// Example 2
	target2 := 10
	position2 := []int{3}
	speed2 := []int{3}
	fmt.Printf("Example 1: target = %v, position = %v, speed = %v\n", target2, position2, speed2)
	fmt.Println("Output:", carFleet(target2, position2, speed2))

	// Example 3
	target3 := 100
	position3 := []int{0, 2, 4}
	speed3 := []int{4, 2, 1}
	fmt.Printf("Example 1: target = %v, position = %v, speed = %v\n", target3, position3, speed3)
	fmt.Println("Output:", carFleet(target3, position3, speed3))
}
