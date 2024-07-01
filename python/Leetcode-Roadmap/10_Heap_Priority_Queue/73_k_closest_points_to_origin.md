Heap / Priority Queue 3
# K Closest Points to Origin
## Company: Meta 
### Level: Medium

Given an array of `points` where `points[i] = [xi, yi]` represents a point on the X-Y plane and an integer `k`, return the `k` closest points to the origin `(0, 0)`.

The distance between two points on the X-Y plane is the Euclidean distance (i.e., `√(x1 - x2)2 + (y1 - y2)2`).

You may return the answer in any order. The answer is guaranteed to be unique (except for the order that it is in).

***Break It Down For Me...***
*We have a list of points. Each point has an X and Y coordinate (like `(3, 4)` or `(-1, 2)`).*
*We need to find the k points that are closest to the origin (which is `(0, 0)`).*

Click [here](https://leetcode.com/problems/k-closest-points-to-origin/description/)for the question on Leetcode.

Click [here](https://www.youtube.com/watch?v=rI2EBUEMfTk) for the solution on [Neetcode](https://neetcode.io/) **(which I would strongly reccomed you to get familiar with.)**

To solve this challenge we will use a [Heap](https://www.studysmarter.co.uk/explanations/computer-science/data-structures/heap-data-structure/#:~:text=A%20heap%20data%20structure%20is%20a%20type%20of%20binary%20tree,priority%20queues%2C%20or%20scheduling%20programs.) data structure in Python, JavaScript and Go.


### Example 1
![Example 1 Pic](https://assets.leetcode.com/uploads/2021/03/03/closestplane1.jpg)
```
Input: points = [[1, 3], [-2, 2]], k = 1
Output: [[-2, 2]]

# Explanation:
# The distance between (1, 3) and the origin is sqrt(10).
# The distance between (-2, 2) and the origin is sqrt(8).
# Since sqrt(8) < sqrt(10), (-2, 2) is closer to the origin.
# We only want the closest k = 1 points from the origin, so the answer is just [[-2,2]].
```

### Example 2
```
Input: points = [[3,3], [5,-1], [-2,4]], k = 2
Output: [[3,3], [-2,4]]

Explanation: The answer [[-2,4], [3,3]] would also be accepted.
```

## Python
```
class Solution:
    def kClosest(self, points: List[List[int]], k: int) -> List[List[int]]:
        # Initialize an empty list to use as a min-heap
        minHeap = []

        # Loop through each point in the list of points
        for x, y in points:
            # Calculate the squared distance from the origin (0, 0) to the point (x, y)
            # We use squared distance to avoid computing the square root, which is not necessary for comparison
            dist = (x ** 2) + (y ** 2)
            # Add the distance and point coordinates to the min-heap
            minHeap.append((dist, x, y))
        
        # Convert the list into a heap in-place
        heapq.heapify(minHeap)
        
        # Initialize an empty list to store the k closest points
        res = []
        # Extract the k smallest elements from the heap
        for _ in range(k):
            # Pop the smallest element from the heap, which includes the distance and point coordinates
            _, x, y = heapq.heappop(minHeap)
            # Add the point coordinates (x, y) to the result list
            res.append((x, y))
        
        # Return the list of k closest points
        return res
```

## JavaScript
```
var kClosest = function (points, k) {
    // Sort the array with a custom lambda comparator function
    points.sort((a, b) => squaredDistance(a) - squaredDistance(b));

    // Return the first k elements of the sorted array
    return points.slice(0, k);
};

// Calculate and return the squared Euclidean distance
const squaredDistance = ([x, y]) => x ** 2 + y ** 2;
```

## Go
```
// Define a structure to store the distance and coordinates of a point
type PointEntry struct {
    dist int  // distance from the origin
    x    int  // x-coordinate of the point
    y    int  // y-coordinate of the point
}

// Define a type for a slice of PointEntry pointers
type PointHeap []*PointEntry

// Implement the sort.Interface for PointHeap
func (h PointHeap) Len() int           { return len(h) }                    // Return the number of elements in the heap
func (h PointHeap) Less(i, j int) bool { return h[i].dist < h[j].dist }     // Compare the distances of two points
func (h PointHeap) Swap(i, j int)      { h[i], h[j] = h[j], h[i] }          // Swap two points in the heap

// Push a new element onto the heap
func (h *PointHeap) Push(x interface{}) {
    *h = append(*h, x.(*PointEntry))
}

// Pop the smallest element from the heap
func (h *PointHeap) Pop() interface{} {
    old := *h
    n := len(old)
    x := old[n-1]               // Get the last element
    *h = old[0 : n-1]           // Remove the last element from the slice
    return x                    // Return the popped element
}

const X = 0  // Constant for x-coordinate index
const Y = 1  // Constant for y-coordinate index

// Function to find the k closest points to the origin
func kClosest(points [][]int, k int) [][]int {
    // Convert the points to PointEntry and calculate their distances
    _pts := make([]*PointEntry, 0, len(points))
    for _, point := range points {
        dist := (pow(abs(point[X] - 0), 2) + pow(abs(point[Y] - 0), 2)) // Calculate squared distance
        _pts = append(_pts, &PointEntry{dist: dist, x: point[X], y: point[Y]}) // Add to the list
    }
    pts := PointHeap(_pts)  // Create a PointHeap from the list
    
    res := make([][]int, 0) // Result list to store k closest points
    heap.Init(&pts)         // Initialize the heap
    for i := 0; i < k; i++ {
        pointEntry := heap.Pop(&pts).(*PointEntry) // Pop the smallest element from the heap
        res = append(res, []int{pointEntry.x, pointEntry.y}) // Add the point to the result list
    }
    return res  // Return the k closest points
}

// Function to return the absolute value of an integer
func abs(a int) int {
    if a < 0 {
        return -a
    }
    return a
}

// Function to calculate the power of an integer
func pow(x, n int) int {
    if n == 0 {
        return 1
    } else if n == 1 {
        return x
    } else {
        return pow(x, n/2) * pow(x, (n + 1)/2)
    }
}
```