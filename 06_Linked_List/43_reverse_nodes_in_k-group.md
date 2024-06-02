Linked Lists 11
# Reserse Nodes in k-Group
## Company: Microsoft
### Level: Hard

Given the `head` of a linked list, reverse the nodes of the list `k` at a time, and return the modified list.

`k` is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of `k` then left-out nodes, in the end, should remain as it is.

You may not alter the values in the list's nodes, only nodes themselves may be changed.

***Break It Down For Me...***
*Given a linked list, reverse the nodes in groups of `k`.*
*If the number of nodes is not a multiple of `k`, leave the remaining nodes as they are.*

Click [here](https://leetcode.com/problems/reverse-nodes-in-k-group/description/)for the question on Leetcode.

Click [here](https://www.youtube.com/watch?v=1UOPsfP85V4) for the solution on [Neetcode](https://neetcode.io/) **(which I would strongly reccomed you to get familiar with.)**

To solve this challenge we will use a [Linked List](https://www.geeksforgeeks.org/introduction-to-linked-list-data-structure-and-algorithm-tutorial/) in Python, JavaScript and Go.

### Example 1
```
Input: head = [1, 2, 3, 4, 5], k = 2
Output: [2, 1, 4, 3, 5]
```

### Example 2
```
Input: head = [1, 2, 3, 4, 5], k = 3
Output: [3, 2, 1, 4, 5]
```

## Python
```
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def reverseKGroup(self, head: ListNode, k: int) -> ListNode:
        # Create a dummy node that points to the head of the list
        dummy = ListNode(0, head)
        # Initialize groupPrev as the dummy node
        groupPrev = dummy

        while True:
            # Find the kth node from groupPrev
            kth = self.getKth(groupPrev, k)
            # If there's no kth node, we've reached the end of the list
            if not kth:
                break
            # Store the next node after the kth node
            groupNext = kth.next

            # Initialize pointers for reversing the group
            prev, curr = kth.next, groupPrev.next
            # Reverse the nodes in the current group
            while curr != groupNext:
                # Store the next node
                tmp = curr.next
                # Reverse the current node's pointer
                curr.next = prev
                # Move prev and curr one step forward
                prev = curr
                curr = tmp

            # Adjust the pointers to connect the reversed group to the main list
            tmp = groupPrev.next
            groupPrev.next = kth
            groupPrev = tmp

        # Return the new head of the reversed list
        return dummy.next

    def getKth(self, curr, k):
        # Traverse k nodes from the current node
        while curr and k > 0:
            curr = curr.next
            k -= 1
        # Return the kth node (or None if less than k nodes remain)
        return curr
```

## JavaScript
```
/**
 * https://leetcode.com/problems/reverse-nodes-in-k-group/
 * Time O(N) | Space O(N)
 * @param {ListNode} head
 * @param {number} k
 * @return {ListNode}
 */
var reverseKGroup = function(head, k) {
    // Create a sentinel (dummy) node that points to the head of the list
    const sentinel = tail = new ListNode(0, head);

    while (true) {
        // Find the start and end nodes of the current group of k nodes
        let [ start, last ] = moveNode(tail, k);
        if (!last) break; // If less than k nodes remain, break the loop

        // Reverse the nodes in the current group
        reverse([ start, tail.next, start ]);

        // Adjust the pointers to connect the reversed group to the main list
        const next = tail.next; // Store the node following the reversed group
        tail.next = last;       // Connect the tail of the reversed group to the next part of the list
        tail = next;            // Move the tail pointer to the end of the reversed group
    }

    // Return the new head of the reversed list
    return sentinel.next;
};

// Function to move k nodes from the current node and return the start and end nodes of the group
const moveNode = (curr, k) => {
    // Helper function to check if we can move to the next node
    const canMove = () => k && curr;
    while (canMove()) {
        curr = curr.next; // Move to the next node
        k--;              // Decrement k
    }

    // Return the start of the next group and the current node (end of the group)
    return [ (curr?.next || null), curr ];
}

// Function to reverse the nodes in the group
const reverse = ([ prev, curr, start ]) => {
    // Helper function to check if we have reached the start node
    const isSame = () => curr === start;
    while (!isSame()) {
        const next = curr.next; // Store the next node
        curr.next = prev;       // Reverse the current node's pointer

        // Move prev and curr pointers one step forward
        prev = curr;
        curr = next;
    }
}
```

## Go
```
func reverseKGroup(head *ListNode, k int) *ListNode {
    // Create a dummy node that points to the head of the list
    dummy := &ListNode{Val: 0, Next: head}
    // Initialize groupPrev to the dummy node
    groupPrev := dummy
    
    for true {
        // Find the k-th node from groupPrev
        kth := getKth(groupPrev, k)
        if kth == nil {
            break // If less than k nodes remain, break the loop
        }
        // Store the node following the k-th node
        groupNext := kth.Next
        
        // Reverse the nodes in the current group
        prev, curr := kth.Next, groupPrev.Next
        for curr != groupNext {
            tmp := curr.Next // Store the next node
            curr.Next = prev // Reverse the current node's pointer
            prev = curr      // Move prev pointer one step forward
            curr = tmp       // Move curr pointer one step forward
        }
        
        // Adjust the pointers to connect the reversed group back to the main list
        tmp := groupPrev.Next
        groupPrev.Next = kth
        groupPrev = tmp
    }
    // Return the new head of the reversed list
    return dummy.Next
}

// Helper function to find the k-th node from the current node
func getKth(curr *ListNode, k int) *ListNode {
    // Move k nodes from the current node
    for curr != nil && k > 0 {
        curr = curr.Next
        k -= 1
    }
    // Return the k-th node or nil if less than k nodes remain
    return curr
}
```