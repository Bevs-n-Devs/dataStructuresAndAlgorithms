Sliding Window 6
# Sliding Window Maximum
## Company: Google
### Level: Hard

You are given an array of integers `nums` and an integer `k`. There is a sliding window of size k that starts at the left edge of the array. The window slides one position to the right until it reaches the right edge of the array.

Return a list that contains the maximum element in the window at each step.

***Break It Down For Me***
*We have an array of numbers and a window that can look at `k` numbers at a time.*
*This window moves from the start of the array to the end, one number at a time.*
*We need to find the biggest number in the window each time it moves.*

Click [here](https://leetcode.com/problems/sliding-window-maximumum)for the question on Leetcode.

Click [here](https://www.youtube.com/watch?v=DfljaUwZsOk) for the solution on [Neetcode](https://neetcode.io/) **(which I would strongly reccomed you to get familiar with.)**

To solve this challenge we will use a [Sliding Window](https://builtin.com/data-science/sliding-window-algorithm) and in Pythopn, JavaScript and Go.

### Example 1
```
Input: nums = [1,2,1,0,4,2,6], k = 3
Output: [2,2,4,4,6]
```

## Python
```
import collections
from typing import List

class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        output = []  # List to store the maximum values for each sliding window
        q = collections.deque()  # Deque to store the indices of elements in the current window
        l = r = 0  # Left and right pointers for the sliding window
        
        # Loop through the array
        while r < len(nums):
            # Remove indices of smaller values from the deque from the right
            while q and nums[q[-1]] < nums[r]:
                q.pop()
            q.append(r)  # Add the current index to the deque
            
            # Remove leftmost index from the deque if it's out of the current window
            if l > q[0]:
                q.popleft()
            
            # Once the window size is equal to k
            if (r + 1) >= k:
                output.append(nums[q[0]])  # Append the maximum value in the window to the output
                l += 1  # Move the left pointer to the right to slide the window
            r += 1  # Move the right pointer to the right to expand the window
        
        return output  # Return the list of maximum values for each sliding window
```

## JavaScript
```
// Define a Node class for creating doubly linked list nodes
function Node(value) {
    this.value = value; // Value of the node
    this.prev = null; // Pointer to the previous node
    this.next = null; // Pointer to the next node
}

// Define a Deque class for implementing a double-ended queue
function Deque() {
    this.left = null; // Pointer to the left end of the deque
    this.right = null; // Pointer to the right end of the deque
    this.size = 0; // Size of the deque

    // Method to add an element to the right end of the deque
    this.pushRight = function (value) {
        const node = new Node(value); // Create a new node
        if (this.size == 0) {
            // If the deque is empty, set both left and right pointers to the new node
            this.left = node;
            this.right = node;
        } else {
            // Otherwise, append the new node to the right end of the deque
            this.right.next = node;
            node.prev = this.right;
            this.right = node;
        }
        this.size++; // Increment the size of the deque
        return this.size; // Return the updated size
    };

    // Method to remove an element from the right end of the deque
    this.popRight = function () {
        if (this.size == 0) return null; // If the deque is empty, return null
        const removedNode = this.right; // Store the node to be removed
        this.right = this.right.prev; // Update the right pointer
        if (this.right) this.right.next = null; // Set the next pointer of the new right node to null
        this.size--; // Decrement the size of the deque
        return removedNode; // Return the removed node
    };

    // Method to add an element to the left end of the deque
    this.pushLeft = function (value) {
        const node = new Node(value); // Create a new node
        if (this.size == 0) {
            // If the deque is empty, set both left and right pointers to the new node
            this.left = node;
            this.right = node;
        } else {
            // Otherwise, prepend the new node to the left end of the deque
            this.left.prev = node;
            node.next = this.left;
            this.left = node;
        }
        this.size++; // Increment the size of the deque
        return this.size; // Return the updated size
    };

    // Method to remove an element from the left end of the deque
    this.popLeft = function () {
        if (this.size == 0) return null; // If the deque is empty, return null
        const removedNode = this.left; // Store the node to be removed
        this.left = this.left.next; // Update the left pointer
        if (this.left) this.left.prev = null; // Set the previous pointer of the new left node to null
        this.size--; // Decrement the size of the deque
        return removedNode; // Return the removed node
    };
}

// Function to find the maximum value in each sliding window of size k in the given array nums
var maxSlidingWindow = function (nums, k) {
    const output = []; // Initialize an empty array to store the maximum values
    let deque = new Deque(); // Create a deque to store indices of elements
    let left = 0; // Pointer for the left end of the current window
    let right = 0; // Pointer for the right end of the current window

    while (right < nums.length) {
        // Pop smaller values from the deque's right end
        while (deque.right && nums[deque.right.value] < nums[right])
            deque.popRight();
        deque.pushRight(right); // Push the current index to the deque

        // Remove leftmost index from the deque if it's outside the window
        if (left > deque.left.value) deque.popLeft();

        // If the current window is of size k, store the maximum value
        if (right + 1 >= k) {
            output.push(nums[deque.left.value]); // Store the maximum value
            left++; // Move the left pointer to slide the window
        }
        right++; // Move the right pointer to slide the window
    }
    return output; // Return the array of maximum values for each sliding window
};
```

## Go
```
func maxSlidingWindow(nums []int, k int) []int {
	// output will store the maximum values for each sliding window
	output := []int{}
	// q will store the indices of elements in nums, acting as a deque
	q := make([]int, 0)
	// l and r are the left and right pointers for the sliding window
	l, r := 0, 0

	for r < len(nums) {
		// Remove elements from the deque's back if they are smaller than the current element
		for len(q) != 0 && nums[q[len(q)-1]] < nums[r] {
			q = q[:len(q)-1]
		}
		// Add the current element's index to the deque
		q = append(q, r)

		// Remove the leftmost index if it's out of the current window's range
		if l > q[0] {
			q = q[1:]
		}

		// Once the window has reached size k, add the maximum element (at the front of the deque) to output
		if (r + 1) >= k {
			output = append(output, nums[q[0]])
			// Move the left pointer to slide the window
			l++
		}
		// Move the right pointer to expand the window
		r++
	}
	// Return the list of maximum values for each sliding window
	return output
}
```