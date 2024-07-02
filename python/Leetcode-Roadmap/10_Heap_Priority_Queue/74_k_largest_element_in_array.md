Heap / Priority Queue 4
# K Largest Element In Array
## Company: Microsoft
### Level: Medium

Given an integer array nums and an integer k, return the kth largest element in the array.

Note that it is the kth largest element in the sorted order, not the kth distinct element.

Can you solve it without sorting?

***Break It Down For Me...***
*You have a list of numbers called nums and a number k. Your job is to find the kth biggest number in the list.

Here are some important points to remember:

We want the kth biggest number if we arranged the list from biggest to smallest.
We don't care if some numbers are the same (not distinct).
Try to solve the problem without sorting the entire list.*

Click [here]()for the question on Leetcode.

Click [here]() for the solution on [Neetcode](https://neetcode.io/) **(which I would strongly reccomed you to get familiar with.)**

To solve this challenge we will use a [Heap](https://www.studysmarter.co.uk/explanations/computer-science/data-structures/heap-data-structure/#:~:text=A%20heap%20data%20structure%20is%20a%20type%20of%20binary%20tree,priority%20queues%2C%20or%20scheduling%20programs.) data structure in Python, JavaScript and Go.


### Example 1
```
Input: nums = [3, 2, 1, 5, 6, 4], k = 2
Output: 5
```

### Example 2
```
Input: nums = [3, 2, 3, 1, 2, 4, 5, 5, 6], k = 4
Output: 4
```

## Python
```
class Solution1:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        # Sort the list in ascending order
        nums.sort()
        # Return the k-th largest element
        # Since the list is sorted in ascending order, the k-th largest is at index len(nums) - k
        return nums[len(nums) - k]
```

## JavaScript
```
var findKthLargest = function(nums, k) {
    // Create a min-heap (a priority queue that keeps the smallest element at the top)
    const minHeap = new MinPriorityQueue();

    // Iterate through each number in the input array
    for (const num of nums) {
        // Add the current number to the min-heap
        minHeap.enqueue(num);

        // Check if the heap has more than k elements
        const isAtCapacity = k < minHeap.size();
        if (isAtCapacity) {
            // If it does, remove the smallest element (the top of the heap)
            minHeap.dequeue();
        }
    }

    // The root of the heap (the smallest element in the heap) is the k-th largest element
    return minHeap.front().element;
};
```

## Go
```
func findKthLargest(nums []int, k int) int {
    // Sort the array in ascending order
    sort.Ints(nums)
    
    // Return the k-th largest element
    // The k-th largest element is at the index len(nums) - k
    return nums[len(nums)-k]
}
```