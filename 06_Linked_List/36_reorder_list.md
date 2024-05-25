Linked List 4
# Reorder List
## Company: LinkedIn
### Company: Medium

You are given the head of a singly linked-list. The list can be represented as:
```
L0 → L1 → … → Ln - 1 → Ln
```

Reorder the list to be on the following form:
```
L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …
```

You may not modify the values in the list's nodes. Only nodes themselves may be changed.


***Break It Down For Me...***
*We have a singly linked list. Imagine this list is made up of nodes that are connected in a straight line.*
*This means we start with the first node, then take the last node, then take the second node, then the second last node, and so on.*

Click [here](https://leetcode.com/problems/reorder-list/description/)for the question on Leetcode.

Click [here](https://www.youtube.com/watch?v=S5bfdUTrKLM) for the solution on [Neetcode](https://neetcode.io/) **(which I would strongly reccomed you to get familiar with.)**

To solve this challenge we will use a [Linked List](https://www.geeksforgeeks.org/introduction-to-linked-list-data-structure-and-algorithm-tutorial/) and in Pythopn, JavaScript and Go.

### Example 1
```
Input: head = [1, 2, 3, 4]
Output: [1, 4, 2, 3]
```

### Example 2
```
Input: head = [1, 2, 3, 4, 5]
Output: [1, 5, 2, 4, 3]
```

## Python
```
class Solution:
    def reorderList(self, head: ListNode) -> None:
        # Step 1: Find the middle of the linked list using the slow and fast pointers
        slow, fast = head, head.next
        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next

        # Step 2: Reverse the second half of the list
        second = slow.next
        prev = slow.next = None  # Cut the list into two halves
        while second:
            tmp = second.next  # Temporarily store the next node
            second.next = prev  # Reverse the current node's pointer
            prev = second  # Move prev one step forward
            second = tmp  # Move second one step forward

        # Step 3: Merge the two halves
        first, second = head, prev
        while second:
            # Temporarily store the next nodes
            tmp1, tmp2 = first.next, second.next
            # Link the current nodes
            first.next = second
            second.next = tmp1
            # Move first and second one step forward
            first, second = tmp1, tmp2
```

## JavaScript
```
var reorderList = function(head) {
    // Find the middle of the linked list
    const mid = getMid(head);          // Time O(N)
    // Reverse the second half of the linked list starting from the middle
    const reversedFromMid = reverse(mid); // Time O(N)
    // Merge the two halves to reorder the list
    reorder(head, reversedFromMid);    // Time O(N)
};

const getMid = (head) => {
    let [slow, fast] = [head, head];

    // Use slow and fast pointers to find the middle node
    while (fast && fast.next) {        // Time O(N)
        slow = slow.next;
        fast = fast.next.next;
    }

    return slow;
};

const reverse = (head) => {
    let [prev, curr, next] = [null, head, null];

    // Reverse the linked list
    while (curr) {                     // Time O(N)
        next = curr.next;  // Store the next node
        curr.next = prev;  // Reverse the current node's pointer
        prev = curr;       // Move prev one step forward
        curr = next;       // Move curr one step forward
    }

    return prev;
};

const reorder = (l1, l2) => {
    let [first, next, second] = [l1, null, l2];

    // Merge the two halves
    while (second.next) {              // Time O(N)
        // Temporarily store the next nodes
        next = first.next;
        // Link the current nodes from the first half
        first.next = second;
        first = next;

        // Temporarily store the next nodes
        next = second.next;
        // Link the current nodes from the second half
        second.next = first;
        second = next;
    }
};
```

## Go
```
func reorderList(head *ListNode)  {
    // Initialize slow and fast pointers to find the middle of the list
    slow := head
    fast := head.Next
    
    // Move slow pointer by 1 step and fast pointer by 2 steps to find the middle
    for fast != nil && fast.Next != nil {
        fast = fast.Next.Next
        slow = slow.Next
    }
    
    // Reverse the second half of the list starting from the node after the middle
    reversed := reverse(slow.Next)
    // Disconnect the first half from the second half
    slow.Next = nil
    
    // Initialize a pointer to traverse the list from the head
    curr := head
    
    // Merge the first half and the reversed second half
    for curr != nil && reversed != nil {
        // Store the next nodes to avoid losing references
        next := curr.Next
        revNext := reversed.Next
        // Link the current node to the next node from the reversed second half
        curr.Next = reversed
        // Link the reversed node to the next node from the first half
        reversed.Next = next
        // Move current pointer to the next node in the first half
        curr = next
        // Move reversed pointer to the next node in the reversed second half
        reversed = revNext
    }
}

func reverse(node *ListNode) *ListNode {
    var prev, curr *ListNode = nil, node
    
    // Traverse the list and reverse the pointers
    for curr != nil {
        // Store the next node to avoid losing reference
        next := curr.Next
        // Reverse the current node's pointer
        curr.Next = prev
        // Move prev pointer to the current node
        prev = curr
        // Move curr pointer to the next node
        curr = next
    }
    
    // Return the new head of the reversed list
    return prev
}
```