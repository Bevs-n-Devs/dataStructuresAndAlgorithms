Heap / Priority Queue 1
# Kth Largest Element in a Stream
## Company: Amazon
### Level: Easy

Design a class to find the `kth` largest element in a stream. Note that it is the `kth` largest element in the sorted order, not the `kth` distinct element.

Implement `KthLargest` class:

- `KthLargest(int k, int[] nums)` Initializes the object with the integer `k` and the stream of integers `nums`.
- `int add(int val)` Appends the integer `val` to the stream and returns the element representing the `kth` largest element in the stream.

***Break It Down For Me...***
*We need to design a class that helps find the `k-th` largest number in a list of numbers that we keep adding to.*
*The `k-th` largest number means the number that is the `k-th` biggest when you sort all the numbers.*
*We need to create a class called `KthLargest` with these functions:*
- *`KthLargest(int k, int[] nums)`: This is the setup function. It takes an integer k and a list of numbers nums. It sets up the class with these values.*
- *`int add(int val)`: This function adds a new number val to the list of numbers. It returns the `k-th` largest number in the list after adding the new number.*

Click [here](https://leetcode.com/problems/kth-largest-element-in-a-stream/description/)for the question on Leetcode.

Click [here](https://www.youtube.com/watch?v=hOjcdrqMoQ8) for the solution on [Neetcode](https://neetcode.io/) **(which I would strongly reccomed you to get familiar with.)**

To solve this challenge we will use a [Heap](https://www.studysmarter.co.uk/explanations/computer-science/data-structures/heap-data-structure/#:~:text=A%20heap%20data%20structure%20is%20a%20type%20of%20binary%20tree,priority%20queues%2C%20or%20scheduling%20programs.) data structure in Python, JavaScript and Go.

### Example 1
```
["KthLargest", "add", "add", "add", "add", "add"]
[[3, [4, 5, 8, 2]], [3], [5], [10], [9], [4]]
Output
[null, 4, 5, 5, 8, 8]
```

## Python
```
import heapq
from typing import List

class KthLargest:
    def __init__(self, k: int, nums: List[int]):
        # Initialize the class with k and nums
        self.minHeap, self.k = nums, k
        heapq.heapify(self.minHeap)  # Convert nums into a heap in-place
        # Maintain the size of the heap to be at most k
        while len(self.minHeap) > k:
            heapq.heappop(self.minHeap)  # Remove the smallest element

    def add(self, val: int) -> int:
        heapq.heappush(self.minHeap, val)  # Add the new value to the heap
        if len(self.minHeap) > self.k:
            heapq.heappop(self.minHeap)  # Ensure the heap size remains k
        return self.minHeap[0]  # The k-th largest element is the smallest in the heap
```

## JavaScript
```
class KthLargest {
    /**
     * Initialize the class with k and nums
     * @param {number} k
     * @param {number[]} nums
     */
    constructor(k, nums) {
        this.k = k;
        this.minHeap = new MinPriorityQueue();  // Use a min-heap to store the k largest elements

        nums.forEach((num) => this.add(num));  // Add each number to the heap
    }

    /**
     * Add a new value to the heap and return the k-th largest element
     * @param {number} val
     * @return {number}
     */
    add(val, { minHeap } = this) {
        if (minHeap.size() < this.k) {  // If the heap is not full, add the new value
            minHeap.enqueue(val);
            return this.top();  // Return the smallest element in the heap
        }

        if (this.top() < val) {  // If the new value is larger than the smallest in the heap
            minHeap.dequeue();  // Remove the smallest element
            minHeap.enqueue(val);  // Add the new value
        }

        return this.top();  // Return the k-th largest element
    }

    /**
     * Get the smallest element in the heap
     * @return {number}
     */
    top({ minHeap } = this) {
        return minHeap.front()?.element || 0;  // The k-th largest element is the smallest in the heap
    }
}
```

## Go
```
package main

import (
	"container/heap"
)

// IntHeap is a min-heap of integers
type IntHeap []int

func (h IntHeap) Len() int           { return len(h) }
func (h IntHeap) Less(i, j int) bool { return h[i] < h[j] }
func (h IntHeap) Swap(i, j int)      { h[i], h[j] = h[j], h[i] }
func (h *IntHeap) Push(x interface{}) { *h = append(*h, x.(int)) }
func (h *IntHeap) Pop() interface{} {
	old := *h
	n := len(old)
	x := old[n-1]
	*h = old[0 : n-1]
	return x
}

// KthLargest is the structure for the class
type KthLargest struct {
    minHeap *IntHeap
    k int
}

// Constructor initializes the class with k and nums
func Constructor(k int, nums []int) KthLargest {
    h := IntHeap(nums)
    heap.Init(&h)  // Initialize the heap with nums
    for len(h) > k {
        heap.Pop(&h)  // Maintain the heap size to be at most k
    }
    return KthLargest{minHeap: &h, k: k}
}

// Add appends the integer val to the stream and returns the k-th largest element
func (this *KthLargest) Add(val int) int {
    heap.Push(this.minHeap, val)  // Add the new value to the heap
    if len(*this.minHeap) > this.k {
        heap.Pop(this.minHeap)  // Ensure the heap size remains k
    }
    return (*this.minHeap)[0]  // The k-th largest element is the smallest in the heap
}
```