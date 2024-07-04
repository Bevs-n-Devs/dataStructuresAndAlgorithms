Heap / Priority Queue 6
# Find Median From Data Stream
## Company: Microsoft
### Level: Hard

The **median** is the middle value in an ordered integer list. If the size of the list is even, there is no middle value, and the median is the mean of the two middle values.

- For example, for `arr = [2,3,4]`, the median is `3`.
- For example, for `arr = [2,3]`, the median is `(2 + 3) / 2 = 2.5`.
Implement the MedianFinder class:

- `MedianFinder()` initializes the MedianFinder object.
- `void addNum(int num)` adds the integer `num` from the data stream to the data structure.
- `double findMedian()` returns the median of all elements so far. Answers within `10-5` of the actual answer will be accepted.


***Break It Down For Me...***
*You need to create a class called `MedianFinder` that helps you find the median of a list of numbers.*

*The median is the middle number in a list of numbers sorted in order. If the list has an even number of elements, the median is the average of the two middle numbers.*

*For example:*

- *For the list [2, 3, 4], the median is 3.*
- *For the list [2, 3], the median is (2 + 3) / 2 = 2.5.*
*You need to write three methods:*

1. `MedianFinder()`: *This method initializes the MedianFinder object.*
2. `addNum(int num)`: *This method adds a number to the data structure.*
3. `findMedian()`: *This method returns the median of all numbers added so far.*
*Our answer should be accurate within a small margin of error (0.00001).*

Click [here](https://leetcode.com/problems/find-median-from-data-stream/description/)for the question on Leetcode.

Click [here](https://www.youtube.com/watch?v=itmhHWaHupI) for the solution on [Neetcode](https://neetcode.io/) **(which I would strongly reccomed you to get familiar with.)**

To solve this challenge we will use a [Heap](https://www.studysmarter.co.uk/explanations/computer-science/data-structures/heap-data-structure/#:~:text=A%20heap%20data%20structure%20is%20a%20type%20of%20binary%20tree,priority%20queues%2C%20or%20scheduling%20programs.) data structure in Python, JavaScript and Go.

## Example 1
```
Input
["MedianFinder", "addNum", "addNum", "findMedian", "addNum", "findMedian"]
[[], [1], [2], [], [3], []]
Output
[null, null, null, 1.5, null, 2.0]

# Explanation
# MedianFinder medianFinder = new MedianFinder();
# medianFinder.addNum(1);    // arr = [1]
# medianFinder.addNum(2);    // arr = [1, 2]
# medianFinder.findMedian(); // return 1.5 (i.e., (1 + 2) / 2)
# medianFinder.addNum(3);    // arr[1, 2, 3]
# medianFinder.findMedian(); // return 2.0
```

## Python
```
import heapq

class MedianFinder:
    def __init__(self):
        """
        Initialize your data structure here.
        """
        # We will use two heaps: small and large
        # `small` will be a max-heap to store the smaller half of the numbers (inverted min-heap)
        # `large` will be a min-heap to store the larger half of the numbers
        self.small = []  # maxHeap (inverted minHeap in Python)
        self.large = []  # minHeap

    def addNum(self, num: int) -> None:
        """
        Adds a number into the data structure.
        """
        # If the number is larger than the smallest number in `large`, add it to `large`
        if self.large and num > self.large[0]:
            heapq.heappush(self.large, num)
        else:
            # Otherwise, add it to `small` (inverted to maintain max-heap property)
            heapq.heappush(self.small, -num)

        # Balance the heaps if `small` has more than one extra element compared to `large`
        if len(self.small) > len(self.large) + 1:
            # Move the largest number from `small` to `large`
            val = -heapq.heappop(self.small)
            heapq.heappush(self.large, val)
        # Balance the heaps if `large` has more than one extra element compared to `small`
        elif len(self.large) > len(self.small) + 1:
            # Move the smallest number from `large` to `small`
            val = heapq.heappop(self.large)
            heapq.heappush(self.small, -val)

    def findMedian(self) -> float:
        """
        Returns the median of all elements so far.
        """
        # If `small` has more elements, the median is the largest element in `small`
        if len(self.small) > len(self.large):
            return -self.small[0]
        # If `large` has more elements, the median is the smallest element in `large`
        elif len(self.large) > len(self.small):
            return self.large[0]
        # If both heaps have the same number of elements, the median is the average of the largest
        # element in `small` and the smallest element in `large`
        return (-self.small[0] + self.large[0]) / 2.0
```

## JavaScript
```
class MedianFinder {
    constructor () {
        // Initialize two heaps: maxHeap to store the smaller half of the numbers and minHeap to store the larger half
        this.maxHeap = new MaxPriorityQueue();
        this.minHeap = new MinPriorityQueue();
    }

    /* Time O(log(N)) | Space O(N) */
    // Public method to insert a number into the data structure
    insertNum (num) {
        this.addNum(num);
    }

    // Private method to add a number to the appropriate heap and then rebalance the heaps if necessary
    addNum (num, heap = this.getHeap(num)) {
        heap.enqueue(num);
        this.rebalance();
    }

    // Determine which heap the number should be added to
    getHeap (num, { maxHeap, minHeap } = this) {
        const isFirst = maxHeap.isEmpty(); // Check if maxHeap is empty
        const isGreater = num <= this.top(maxHeap); // Check if the number is less than or equal to the maxHeap's top element
        const isMaxHeap = (isFirst || isGreater); // Determine if the number should go into maxHeap
        return (isMaxHeap) ? maxHeap : minHeap; // Return the appropriate heap
    }

    // Rebalance the heaps to ensure their sizes differ by at most one element
    rebalance ({ maxHeap, minHeap } = this) {
        const canShiftMax = (minHeap.size() + 1) < maxHeap.size(); // Check if maxHeap has more than one extra element
        if (canShiftMax) return minHeap.enqueue(maxHeap.dequeue().element); // Move the top element from maxHeap to minHeap

        const canShiftMin = maxHeap.size() < minHeap.size(); // Check if minHeap has more elements than maxHeap
        if (canShiftMin) return maxHeap.enqueue(minHeap.dequeue().element); // Move the top element from minHeap to maxHeap
    }

    /* Time O(1) | Space O(1) */
    // Public method to find the median of the numbers added so far
    findMedian ({ maxHeap, minHeap } = this) {
        const isEven = maxHeap.size() === minHeap.size(); // Check if the total number of elements is even
        return (isEven) ? this.average(maxHeap, minHeap) : this.top(maxHeap); // Return the average of the top elements of both heaps if even, otherwise return the top element of maxHeap
    }

    // Helper method to calculate the average of the top elements of both heaps
    average (maxHeap, minHeap) {
        return (this.top(maxHeap) + this.top(minHeap)) / 2;
    }

    // Helper method to get the top element of a heap
    top (heap) {
        return heap.front()?.element || 0; // Return the top element or 0 if the heap is empty
    }
}
```

## Go
```
import (
	"container/heap"
)

// IntHeap is a type alias for a slice of integers. It implements the heap.Interface.
type IntHeap []int

// Len returns the number of elements in the heap.
func (h IntHeap) Len() int {
	return len(h)
}

// Less compares the elements at indices i and j. It returns true if h[i] is less than h[j].
func (h IntHeap) Less(i, j int) bool {
	return h[i] < h[j]
}

// Swap swaps the elements at indices i and j.
func (h IntHeap) Swap(i, j int) {
	h[i], h[j] = h[j], h[i]
}

// Push adds an element to the heap.
func (h *IntHeap) Push(x interface{}) {
	*h = append(*h, x.(int))
}

// Pop removes and returns the last element from the heap.
func (h *IntHeap) Pop() interface{} {
	old := *h
	n := len(old)
	x := old[n-1]
	*h = old[0 : n-1]
	return x
}

// MedianFinder struct holds two heaps: small and large.
type MedianFinder struct {
	small IntHeap // Max-heap to store the smaller half of the numbers
	large IntHeap // Min-heap to store the larger half of the numbers
}

// Constructor initializes a new MedianFinder object.
func Constructor() MedianFinder {
	return MedianFinder{small: IntHeap{}, large: IntHeap{}}
}

// AddNum adds a number into the data structure.
func (this *MedianFinder) AddNum(num int) {
	// Add to large if it is greater than the smallest element in large heap
	if len(this.large) > 0 && num > this.large[0] {
		heap.Push(&this.large, num)
	} else {
		// Add to small by inverting the number (to maintain a max-heap)
		heap.Push(&this.small, -num)
	}

	// Balance the heaps if necessary
	if len(this.small) > len(this.large)+1 {
		val := -heap.Pop(&this.small).(int)
		heap.Push(&this.large, val)
	}
	if len(this.large) > len(this.small)+1 {
		val := heap.Pop(&this.large).(int)
		heap.Push(&this.small, -val)
	}
}

// FindMedian returns the median of all elements added so far.
func (this *MedianFinder) FindMedian() float64 {
	// If small heap has more elements, return the top of the small heap
	if len(this.small) > len(this.large) {
		return float64(-this.small[0])
	} else if len(this.large) > len(this.small) {
		// If large heap has more elements, return the top of the large heap
		return float64(this.large[0])
	}
	// If both heaps have the same number of elements, return the average of the tops
	return float64(-this.small[0]+this.large[0]) / 2
}
```