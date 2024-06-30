Heap / Priority Queue
# Last Stone Weight
## Copany: Google
### Level: Easy

You are given an array of integers stones where `stones[i]` is the weight of the `ith` stone.

We are playing a game with the stones. On each turn, we choose the heaviest two stones and smash them together. Suppose the heaviest two stones have weights `x` and `y` with `x <= y`. The result of this smash is:

- If x == y, both stones are destroyed, and
- If x != y, the stone of weight x is destroyed, and the stone of weight `y` has new weight `y - x`.
- At the end of the game, there is at most one stone left.

Return the weight of the last remaining stone. If there are no stones left, return 0.

***Break It Down For Me...***
*We have an array of numbers called `stones`. Each number in the array represents the weight of a stone.*
*Here's the game we play with the stones:*
1. *Every turn, we pick the two heaviest stones.*
2. *If the two heaviest stones have the same weight, they both get destroyed (removed).*
3. *If the two heaviest stones have different weights, the lighter stone gets destroyed, and the heavier stone loses weight equal to the lighter stone's weight.*
*Keep doing this until there is at most one stone left.*
*If there are no stones left at the end, return `0`. If there is one stone left, return its weight.*
**Our task is to write a function that returns the weight of the last remaining stone (or 0 if no stones are left).**

Click [here](https://leetcode.com/problems/last-stone-weight/description/)for the question on Leetcode.

Click [here](https://www.youtube.com/watch?v=B-QCq79-Vfw) for the solution on [Neetcode](https://neetcode.io/) **(which I would strongly reccomed you to get familiar with.)**

To solve this challenge we will use a [Heap](https://www.studysmarter.co.uk/explanations/computer-science/data-structures/heap-data-structure/#:~:text=A%20heap%20data%20structure%20is%20a%20type%20of%20binary%20tree,priority%20queues%2C%20or%20scheduling%20programs.) data structure in Python, JavaScript and Go.

### Example 1
```
Input: stones = [2,7,4,1,8,1]
Output: 1

# Explanation: 
# We combine 7 and 8 to get 1 so the array converts to [2,4,1,1,1] then,
# we combine 2 and 4 to get 2 so the array converts to [2,1,1,1] then,
# we combine 2 and 1 to get 1 so the array converts to [1,1,1] then,
# we combine 1 and 1 to get 0 so the array converts to [1] then that's the value of the last stone.
```

### Example 2
```
Input: stones = [1]
Output: 1
```

## Python
```
import heapq
from typing import List

class Solution:
    def lastStoneWeight(self, stones: List[int]) -> int:
        # Convert all stone weights to negative to use min-heap as max-heap
        stones = [-s for s in stones]
        # Create a heap from the list of stones
        heapq.heapify(stones)

        # Continue smashing stones until only one or none are left
        while len(stones) > 1:
            # Pop the two heaviest stones (smallest in min-heap)
            first = heapq.heappop(stones)
            second = heapq.heappop(stones)
            # If the stones are not of equal weight, push the difference back to the heap
            if second > first:
                heapq.heappush(stones, first - second)

        # If no stones are left, return 0; otherwise, return the absolute value of the remaining stone
        stones.append(0)
        return abs(stones[0])

```

## JavaScript
```
var lastStoneWeight = function (stones) {
    const maxHeap = getMaxHeap(stones)

    shrink(maxHeap)

    return !maxHeap.isEmpty()
        ? maxHeap.front().element
        : 0
};

const getMaxHeap = (stones, maxHeap = new MaxPriorityQueue()) => {
    for (const stone of stones) {
        maxHeap.enqueue(stone)
    }

    return maxHeap
}

const shrink = (maxHeap) => {
    while (1 < maxHeap.size()) {
        const [ x, y ] = [ maxHeap.dequeue().element, maxHeap.dequeue().element ]
        const difference = x - y;

        const isPositive = 0 < difference
        if (isPositive) maxHeap.enqueue(difference);
    }
}
```

## Go
```
// Define a custom heap type
type IntHeap []int

// Implement the heap.Interface methods for IntHeap
func (h IntHeap) Len() int           { return len(h) }                 // Return the length of the heap
func (h IntHeap) Less(i, j int) bool { return h[i] < h[j] }            // Compare elements (for min-heap)
func (h IntHeap) Swap(i, j int)      { h[i], h[j] = h[j], h[i] }       // Swap elements in the heap
func (h *IntHeap) Push(x interface{}) {*h = append(*h, x.(int))}       // Add an element to the heap
func (h *IntHeap) Pop() interface{} {                                  // Remove and return the smallest element from the heap
	old := *h
	n := len(old)
	x := old[n-1]
	*h = old[0 : n-1]
	return x
}

// Define the KthLargest struct
type KthLargest struct {
    minHeap *IntHeap
    k int
}

// lastStoneWeight function computes the weight of the last remaining stone
func lastStoneWeight(_stones []int) int {
    // Negate all the stone weights to use a min-heap as a max-heap
    for s := 0; s < len(_stones); s++ {
        _stones[s] *= -1
    }

    // Initialize the heap with the negated stone weights
    stones := IntHeap(_stones)
    heap.Init(&stones)
    
    // Simulate the process of smashing the two heaviest stones
    for len(stones) > 1 {
        first, _ := heap.Pop(&stones).(int)   // Pop the heaviest stone
        second, _ := heap.Pop(&stones).(int)  // Pop the second heaviest stone
        if second > first {
            heap.Push(&stones, first - second) // Push the difference back to the heap
        }
    }

    // If there are no stones left, return 0; otherwise, return the absolute value of the remaining stone
    stones = append(stones, 0)
    return abs(stones[0])
}

// abs function returns the absolute value of an integer
func abs(x int) int {
    if x < 0 {
        return -x
    }
    return x
}
```