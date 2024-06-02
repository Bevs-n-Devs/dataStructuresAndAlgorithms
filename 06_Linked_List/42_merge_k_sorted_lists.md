Linked List 10
# Merge k Sorted Lists
## Company: Meta
### Level: Hard

You are given an array of `k` linked-lists `lists`, each linked-list is sorted in ascending order.

Merge all the linked-lists into one sorted linked-list and return it.

***Break It Down For Me...***
*We are given several sorted linked lists.*
*Our task is to combine all of these linked lists into one big sorted linked list.*

Click [here](https://leetcode.com/problems/merge-k-sorted-lists/description/)for the question on Leetcode.

Click [here](https://www.youtube.com/watch?v=q5a5OiGbT6Q) for the solution on [Neetcode](https://neetcode.io/) **(which I would strongly reccomed you to get familiar with.)**

To solve this challenge we will use a [Linked List](https://www.geeksforgeeks.org/introduction-to-linked-list-data-structure-and-algorithm-tutorial/) in Python, JavaScript and Go.

### Example 1
```
Input: lists = [[1, 4, 5], [1, 3, 4], [2, 6]]
Output: [1, 1, 2, 3, 4, 4, 5, 6]
```
**Exaplanation*:* The linked-lists are:
```
[
  1->4->5,
  1->3->4,
  2->6
]
```
merging them into one sorted list:
`1->1->2->3->4->4->5->6`

### Example 2
```
Input: lists = []
Output: []
```
### Example 3
```
Input: lists = [[]]
Output: []
```

## Python
```
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def mergeKLists(self, lists: List[ListNode]) -> ListNode:
        # If the input is empty or contains no lists, return None
        if not lists or len(lists) == 0:
            return None

        # While there is more than one list in the lists array
        while len(lists) > 1:
            mergedLists = []
            # Merge pairs of lists
            for i in range(0, len(lists), 2):
                l1 = lists[i]  # First list
                l2 = lists[i + 1] if (i + 1) < len(lists) else None  # Second list, if it exists
                mergedLists.append(self.mergeList(l1, l2))  # Merge the two lists and append the result
            lists = mergedLists  # Update lists with the merged lists
        return lists[0]  # Return the merged list

    def mergeList(self, l1, l2):
        dummy = ListNode()  # Create a dummy node to act as the head of the merged list
        tail = dummy  # Tail points to the last node in the merged list

        # While neither l1 nor l2 is exhausted
        while l1 and l2:
            if l1.val < l2.val:  # If the value in l1 is less than in l2
                tail.next = l1  # Append l1 node to the merged list
                l1 = l1.next  # Move l1 to the next node
            else:
                tail.next = l2  # Append l2 node to the merged list
                l2 = l2.next  # Move l2 to the next node
            tail = tail.next  # Move tail to the next position

        # If there are remaining nodes in l1, append them
        if l1:
            tail.next = l1
        # If there are remaining nodes in l2, append them
        if l2:
            tail.next = l2
        return dummy.next  # Return the merged list, which is next to the dummy node
```
## JavaScript
```
var mergeKLists = function(lists) {
    let previous = null;  // Initialize the previous merged list to null

    // Iterate through each list in the lists array
    for (let i = 0; i < lists.length; i++) {
        // Merge the previous merged list with the current list
        previous = mergeTwoLists(previous, lists[i]);
    }

    return previous;  // Return the final merged list
};

var mergeTwoLists = function(list1, list2) {
    let sentinel = tail = new ListNode(0);  // Create a sentinel node to act as the head of the merged list

    // Iterate through both lists until one is exhausted
    while (list1 && list2) {
        // Check if the value in list1 is less than or equal to the value in list2
        const canAddL1 = list1.val <= list2.val;
        if (canAddL1) {
            // Add list1 node to the merged list
            tail.next = list1;
            list1 = list1.next;  // Move list1 to the next node
        } else {
            // Add list2 node to the merged list
            tail.next = list2;
            list2 = list2.next;  // Move list2 to the next node
        }

        tail = tail.next;  // Move tail to the next position
    }

    // Append any remaining nodes from list1 or list2 to the merged list
    tail.next = list1 || list2;

    return sentinel.next;  // Return the merged list, which is next to the sentinel node
};
```

## Go
```
func mergeKLists(lists []*ListNode) *ListNode {
    // If the input list is empty, return nil
    if lists == nil || len(lists) == 0 {
        return nil
    }
    
    // Continue merging until there is only one list left
    for len(lists) > 1 {
        var mergedLists []*ListNode
        
        // Merge lists in pairs
        for i := 0; i < len(lists); i += 2 {
            l1 := lists[i]
            var l2 *ListNode
            // Check if there is a second list to merge
            if (i + 1) < len(lists) {
                l2 = lists[i + 1]
            }
            // Merge the two lists and add the result to mergedLists
            mergedLists = append(mergedLists, mergeList(l1, l2))
        }
        // Update lists with the newly merged lists
        lists = mergedLists
    }
    
    // Return the final merged list
    return lists[0]
}

func mergeList(l1, l2 *ListNode) *ListNode {
    // Create a dummy node to serve as the head of the merged list
    dummy := &ListNode{}
    tail := dummy
    
    // Merge the lists until one of them is exhausted
    for l1 != nil && l2 != nil {
        // Add the smaller value to the merged list
        if l1.Val < l2.Val {
            tail.Next = l1
            l1 = l1.Next
        } else {
            tail.Next = l2
            l2 = l2.Next
        }
        // Move the tail to the last node in the merged list
        tail = tail.Next
    }
    
    // Append any remaining nodes from l1
    if l1 != nil {
        tail.Next = l1
    }
    
    // Append any remaining nodes from l2
    if l2 != nil {
        tail.Next = l2
    }
    
    // Return the merged list, starting from the node next to the dummy
    return dummy.Next
}
```