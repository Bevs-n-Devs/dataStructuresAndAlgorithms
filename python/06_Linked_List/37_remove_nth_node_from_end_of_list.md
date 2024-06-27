Linked List 5
# Remove Nth Node From End Of List
## Company: Oracle
### Level: Medium

Given the `head` of a linked list, remove the `n`th node from the end of the list and return its head.

***Break It Down For Me...***
*Imagine we have a list of items, and we want to remove a specific item based onm its position from the end of the list.*
*We need to find and remove the `n`th node counting from the end of the linked list.*
*After removing this node, we need to return the head of the modified list.*

Click [here](https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/)for the question on Leetcode.

Click [here](https://www.youtube.com/watch?v=XVuQxVej6y8) for the solution on [Neetcode](https://neetcode.io/) **(which I would strongly reccomed you to get familiar with.)**

To solve this challenge we will use a [Linked List](https://www.geeksforgeeks.org/introduction-to-linked-list-data-structure-and-algorithm-tutorial/) in Python, JavaScript and Go.

### Example 1
```
Input: head = [1, 2, 3, 4, 5], n = 2
Output: [1, 2, 3, 5]
```

### Example 2
```
Input: head = [1], n = 1
Output: []
```

### Example 3
```
Input: head = [1, 2], n = 1
Output: [1]
```

## Python
```
# Definition for singly-linked list.
# A ListNode is a class that represents a single node in a linked list.
# Each node has a value (val) and a pointer to the next node (next).
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def hasCycle(self, head: ListNode) -> bool:
        # Initialize two pointers, both starting at the head of the list.
        # The slow pointer will move one step at a time, while the fast pointer will move two steps at a time.
        slow, fast = head, head

        # Loop until the fast pointer reaches the end of the list.
        # If there is no cycle, fast will eventually be None or fast.next will be None.
        while fast and fast.next:
            # Move the slow pointer one step forward.
            slow = slow.next
            # Move the fast pointer two steps forward.
            fast = fast.next.next
            # If the slow pointer and the fast pointer meet, it means there is a cycle in the list.
            if slow == fast:
                return True
        
        # If we reach here, it means there is no cycle in the list.
        return False
```

## JavaScript
```
var removeNthFromEnd = function(head, n) {
    // Create a sentinel (dummy) node that points to the head of the list.
    // This helps to easily handle edge cases like removing the first node.
    const sentinel = new ListNode();
    sentinel.next = head;

    // Move the fast pointer n + 1 steps ahead to create a gap of n nodes between slow and fast pointers.
    const fast = moveFast(sentinel, n);  /* Time O(N) */
    // Move both slow and fast pointers until the fast pointer reaches the end.
    const slow = moveSlow(sentinel, fast);/* Time O(N) */

    // Remove the nth node from the end by changing the next pointer of the slow node.
    slow.next = slow.next.next || null;

    // Return the head of the modified list.
    return sentinel.next;
};

// Helper function to move the fast pointer n + 1 steps ahead.
const moveFast = (fast, n) => {
    for (let i = 1; i <= (n + 1); i++) {  /* Time O(N) */
        fast = fast.next;
    }
    return fast;
}

// Helper function to move both slow and fast pointers until fast reaches the end.
const moveSlow = (slow, fast) => {
    while (fast) {  /* Time O(N) */
        slow = slow.next;
        fast = fast.next;
    }
    return slow;
}
```

## Go
```
func removeNthFromEnd(head *ListNode, n int) *ListNode {
    // If the head is nil, return nil as there is no list to process.
    if head == nil {
        return head
    }
    
    // Initialize two pointers, slow and fast, both starting at the head of the list.
    slow, fast := head, head
    
    // Move the fast pointer n steps ahead.
    for n > 0 {
        fast = fast.Next
        n--
    }
    
    // If fast is nil, it means we need to remove the head node itself.
    if fast == nil {
        return slow.Next
    }
    
    // Move both slow and fast pointers one step at a time until fast reaches the end of the list.
    // This will place slow at the node just before the one we want to remove.
    for fast.Next != nil {
        slow = slow.Next
        fast = fast.Next
    }
    
    // Skip the nth node from the end by changing the next pointer of the slow node.
    slow.Next = slow.Next.Next
    
    // Return the head of the modified list.
    return head
}
```