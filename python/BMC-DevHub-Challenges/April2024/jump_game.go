package main

import "fmt"

func canJump(nums []int) bool {
	// the goal is to reach the last index of the list
	goal := len(nums) - 1

	// iterate backwards through the list from 2nd-last to 1st list item
	for index := len(nums) - 2; index >= 0; index-- {
		// check if index + maximum jump from index can reach or surpass the goal
		if index+nums[index] >= goal {
			//  if so, update the goal to this index
			goal = index
		}
	}
	// now check if the goal is equal to 0
	// if so you have reached your goal
	return goal == 0
}

// implementation:
func main() {
	example1 := []int{2, 3, 1, 1, 4}
	fmt.Println(canJump(example1))

	example2 := []int{3, 2, 1, 0, 4}
	fmt.Println(canJump(example2))
}
