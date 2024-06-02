Linked List 8
# Find The Duplicate Number
## Company: Amazon
### Level: Medium

Given an array of integers `nums` containing `n + 1` integers where each integer is in the range `[1, n]` inclusive.

There is **only one repeated number** in `nums`, *return this repeated number*.

You must solve the problem **without** modifying the array `nums` and uses only constant extra space.

***Break It Down FGor Me...***
*We are given an array of integers called `nums`.*
*The array has `n + 1` numbers, and each number is between `1` and `n` (inclusive).*
*This means that there are `n` possible values but `n + 1` numbers in the array.*
*Since there are more numbers than possible unique values, one number must be repeated.*
*The task is to find and return this repeated number.*

Click [here](https://leetcode.com/problems/find-the-duplicate-number/description/)for the question on Leetcode.

Click [here](https://www.youtube.com/watch?v=wjYnzkAhcNk) for the solution on [Neetcode](https://neetcode.io/) **(which I would strongly reccomed you to get familiar with.)**

To solve this challenge we will use a [Linked List](https://www.geeksforgeeks.org/introduction-to-linked-list-data-structure-and-algorithm-tutorial/) in Python, JavaScript and Go.

### Example 1
```
Input: nums = [1, 3, 4, 2, 2]
Output: 2
```
### Example 2
```
Input: nums = [3, 1, 3, 4, 2]
Output: 3
```

### Example 3
```
Input: nums = [3, 3, 3, 3, 3]
Output: 3
```

## Python
```
class Solution:
    def findDuplicate(self, nums: List[int]) -> int:
        # Initialize two pointers: slow and fast
        slow, fast = 0, 0
        
        # Phase 1: Finding the intersection point of the two pointers
        while True:
            slow = nums[slow]             # Move slow pointer one step
            fast = nums[nums[fast]]       # Move fast pointer two steps
            if slow == fast:              # If they meet, there's an intersection
                break

        # Phase 2: Finding the entrance to the cycle
        slow2 = 0
        while True:
            slow = nums[slow]             # Move slow pointer one step
            slow2 = nums[slow2]           # Move slow2 pointer one step
            if slow == slow2:             # If they meet, the entrance to the cycle is found
                return slow               # This is the duplicate number
```

## JavaScript
```
var hasCycle = function(head) {
    // Initialize two pointers: slow and fast, both starting at the head
    let [ slow, fast ] = [ head, head ];

    // Traverse the list with two pointers until we reach the end of the list
    while (fast && fast.next) {
        // Move slow pointer one step at a time
        slow = slow.next;
        // Move fast pointer two steps at a time
        fast = fast.next.next;

        // Check if the slow and fast pointers meet, indicating a cycle
        const hasCycle = slow === fast;
        if (hasCycle) return true; // If they meet, there is a cycle
    }

    // If we reach the end of the list, there is no cycle
    return false;
};
```

## Go
```
func hasCycle(head *ListNode) bool {
    // If the list is empty or has only one node, it can't have a cycle
    if head == nil || head.Next == nil {
        return false
    }
    
    // Initialize two pointers: slow and fast
    slow := head
    fast := head
    
    // Traverse the list with two pointers
    for fast != nil && fast.Next != nil {
        // Move slow pointer one step at a time
        slow = slow.Next
        // Move fast pointer two steps at a time
        fast = fast.Next.Next
        
        // If slow and fast pointers meet, there is a cycle
        if slow == fast {
            return true
        }
    }
    
    // If we reach the end of the list, there is no cycle
    return false
}
```