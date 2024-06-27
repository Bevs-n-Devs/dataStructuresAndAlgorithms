Linked List 3
# Linked List Cycle
## Company: Amazon
### Level: Easy

Given `head`, the head of a linked list, determine if the linked list has a cycle in it.

There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the `next` pointer. 
Internally, `pos` is used to denote the index of the node that tail's `next` pointer is connected to. 
**Note that `pos` is not passed as a parameter.**

Return `true` if there is a cycle in the linked list. Otherwise, return `false`.

***Break It Down For Me...***
*Imagine you have a train track made up of several connected cars (nodes).*
*Each car has a pointer to the next car, creating a linked list.*
*The `head` is the first car in this sequence.*

*A cycle in the linked list means that at some point, a car's next pointer points back to one of the previous cars, creating a loop.* 
*If you keep following the next pointers, you'll eventually end up back at the same car, going around in circles forever.*

Click [here](https://leetcode.com/problems/linked-list-cycle/description/)for the question on Leetcode.

Click [here](https://www.youtube.com/watch?v=gBTe7lFR3vc) for the solution on [Neetcode](https://neetcode.io/) **(which I would strongly reccomed you to get familiar with.)**

To solve this challenge we will use a [Linked List](https://www.geeksforgeeks.org/introduction-to-linked-list-data-structure-and-algorithm-tutorial/) in Python, JavaScript and Go.

### Example 1
```
Input: head = [3, 2, 0, -4], pos = 1
Output: true
```
**Explanation:** There is a cycle in the linked list, where the tail connects to the 1st node (0-indexed).

### Example 2
```
Input: head = [1, 2], pos = 0
Output: true
```
**Explanation:** There is a cycle in the linked list, where the tail connects to the 0th node.

### Example 3
```
Input: head = [1], pos = -1
Output: false
```
**Explanation:** There is no cycle in the linked list.

## Python
```
class Solution:
    def hasCycle(self, head: ListNode) -> bool:
        # Initialize two pointers, slow and fast, both starting at the head of the list
        slow, fast = head, head

        # Traverse the list with the two pointers
        while fast and fast.next:
            # Move slow pointer one step forward
            slow = slow.next
            # Move fast pointer two steps forward
            fast = fast.next.next
            
            # If slow and fast pointers meet, it means there is a cycle
            if slow == fast:
                return True
        
        # If we reach here, it means fast pointer reached the end of the list without meeting slow pointer, so there is no cycle
        return False
```

## JavaScript
```
var hasCycle = function(head, seen = new Set()) {
    // Traverse the list as long as the current node (head) is not null
    while (head) { // Time complexity is O(N), where N is the number of nodes in the list
        // Check if the current node has already been seen
        if (seen.has(head)) return true; // If the node is in the 'seen' set, it means there's a cycle

        // Add the current node to the 'seen' set to keep track of visited nodes
        seen.add(head); // Space complexity is O(N), due to the space needed to store the visited nodes in the set
        // Move to the next node in the list
        head = head.next;
    }

    // If we reach here, it means we've traversed the list without finding a cycle
    return false;
}
```

## Go
```
func hasCycle(head *ListNode) bool {
    // If the list is empty or has only one node, it can't have a cycle
	if head == nil || head.Next == nil {
        return false
    }
    
    // Initialize two pointers, slow and fast, both starting at the head of the list
    slow := head
    fast := head
    
    // Traverse the list with two pointers until the fast pointer reaches the end
    for fast != nil && fast.Next != nil {
        // Move the slow pointer one step at a time
        slow = slow.Next
        // Move the fast pointer two steps at a time
        fast = fast.Next.Next
        
        // If the slow pointer and fast pointer meet, there is a cycle
        if slow == fast {
            return true
        }
    }
    
    // If the fast pointer reaches the end, there is no cycle
    return false
}
```