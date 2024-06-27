Linked List 1
# Reverse Linked List
## Company: Meta & Google
### Level: Easy

Given the `head` of a singly linked list, reverse the list, and return the reversed list.

***Break It Down For Me...***
*Reversing the list means changing the direction of the pointers so that they point to the previous node instead of the next node.*
*After reversing, the head of the list should become the tail, and the tail should become the new head.*

Click [here](https://leetcode.com/problems/reverse-linked-list/description/)for the question on Leetcode.

Click [here](https://www.youtube.com/watch?v=G0_I-ZF0S38) for the solution on [Neetcode](https://neetcode.io/) **(which I would strongly reccomed you to get familiar with.)**

To solve this challenge we will use a [Linked List](https://www.geeksforgeeks.org/introduction-to-linked-list-data-structure-and-algorithm-tutorial/) in Python, JavaScript and Go.

### Example 1
```
Input: head = [1, 2, 3, 4, 5]
Output: [5, 4, 3, 2, 1]
```

### Example 2
```
Input: head = [1, 2]
Output: [2, 1]
```

### Example 3
```
Input: head = []
Output: []
```

## Python
```
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None


class Solution:
    def reverseList(self, head: ListNode) -> ListNode:
        # create two pointers to loop through the nodes
        prev, curr = None, head

        # Traverse the list while there's a node to process (curr is not None)
        while curr:
            # Store the next node in a temporary variable (temp)
            temp = curr.next            # Reverse the link to the previous node
            curr.next = prev
            # Move prev and curr one step forward
            prev = curr
            curr = temp

        # At the end of the loop, prev will be the new head of the reversed list
        return prev
```
## JavaScript
```
var reverseList = function(head) {
    // create two pointers to loop through the nodes
    let previousNode = null, currentNode = head;
    
    while (currentNode) {
        let tempNode = currentNode.next;
        // reverse the link to the previous node
        currentNode.next = previousNode;
        // move previousNode & currentNode one step forward
        previousNode = currentNode;
        currentNode = tempNode;
    }
    
    return previousNode;
};
```

## Go
```
// Definition for singly-linked list.
type ListNode struct {
    Val  int
    Next *ListNode
}

// reverseList reverses a singly linked list.
func reverseList(head *ListNode) *ListNode {
    // Base case: if the list is empty or has only one node, return the head.
    if head == nil || head.Next == nil {
        return head
    }

    // Recursively reverse the rest of the list.
    reversedListHead := reverseList(head.Next)
    
    // After reversing, head.Next becomes the last node of the reversed sublist.
    // So, head.Next.Next should point to head to reverse the link.
    head.Next.Next = head

    // Set head.Next to nil, making head the new tail of the reversed sublist.
    head.Next = nil

    // Return the head of the reversed list.
    return reversedListHead
}
```