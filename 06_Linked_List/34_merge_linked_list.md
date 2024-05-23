Linked List 2
# Merge Two Sorted Lists
## Company: Microsoft
### Level: Easy

You are given the heads of two sorted linked lists `list1` and `list2`.

Merge the two lists into one sorted list. The list should be made by splicing together the nodes of the first two lists.

Return the head of the merged linked list.


***Break It Down For Me...***
*We have two sorted linked lists, and WE need to merge them into one sorted linked list.*
*We should combine the nodes from both lists in such a way that the resulting list is also sorted.*

Click [here](https://leetcode.com/problems/merge-two-sorted-lists/description/)for the question on Leetcode.

Click [here](https://www.youtube.com/watch?v=XIdigk956u0) for the solution on [Neetcode](https://neetcode.io/) **(which I would strongly reccomed you to get familiar with.)**

To solve this challenge we will use a [Linked List](https://www.geeksforgeeks.org/introduction-to-linked-list-data-structure-and-algorithm-tutorial/) and in Pythopn, JavaScript and Go.

### Example 1
```
Input: list1 = [1, 2, 4], list2 = [1, 3, 4]
Output: [1, 1, 2, 3, 4, 4]
```
### Example 2
```
Input: list1 = [], list2 = []
Output: []
```

### Example 3
```
Input: list1 = [], list2 = [0]
Output: [0]
```

## Python
```
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

# Iterative
class Solution:
    def mergeTwoLists(self, list1: ListNode, list2: ListNode) -> ListNode:
    # Create a dummy node to serve as the head of the merged list
    dummy = node = ListNode()

    # Iterate through both lists until at least one of them is empty
    while list1 and list2:
        # Compare the values of the current nodes from both lists
        if list1.val < list2.val:
            # Connect the smaller node to the merged list
            node.next = list1
            # Move to the next node in list1
            list1 = list1.next
        else:
            # Connect the smaller node to the merged list
            node.next = list2
            # Move to the next node in list2
            list2 = list2.next

        # Move to the next node in the merged list
        node = node.next

    # Connect the remaining nodes from the non-empty list
    node.next = list1 or list2

    # Return the merged list starting from the actual head (not the dummy node)
    return dummy.next
```

## JavaScript
```
var mergeTwoLists = function(list1, list2) {
    // create dummy node - this will be the head of the merged list
    let node = new ListNode();
    let dummy = node;
    
    // loop until one is empty
    while (list1 && list2) {
        // compare the val of current nodes
        if (list1.val < list2.val) {
            // add smallest node to merged list
            node.next = list1;
            // move to next node in list1
            list1 = list1.next;
        } else {
            node.next = list2;
            // move to next node in list2
            list2 = list2.next;
        }
        // move to the next node in merged list
        node = node.next;
    }
    // connect the remaining nodes from non-empty list
    node.next = list1 || list2;
    
    // return merged list, starting from actual head (not dummy node)
    return dummy.next;
};
```

## Go
```
// Definition for singly-linked list.
// type ListNode struct {
//     Val  int
//     Next *ListNode
// }

func mergeTwoLists(l1 *ListNode, l2 *ListNode) *ListNode {
	// If the first list is empty, return the second list
	if l1 == nil {
		return l2
	}

	// If the second list is empty, return the first list
	if l2 == nil {
		return l1
	}

	// Initialize pointers for traversing the two lists
	ptr1, ptr2 := l1, l2

	// Create a new ListNode to store the result
	result := new(ListNode)

	// A temporary pointer to build the merged list
	temp := result

	// Traverse both lists until one of them is exhausted
	for ptr1 != nil && ptr2 != nil {
		if ptr1.Val < ptr2.Val { // If the value of the current node in l1 is smaller
			temp.Next = ptr1      // Add the node from l1 to the merged list
			temp = temp.Next      // Move the temp pointer forward
			ptr1 = ptr1.Next      // Move the ptr1 pointer to the next node in l1
		} else {                 // If the value of the current node in l2 is smaller or equal
			temp.Next = ptr2      // Add the node from l2 to the merged list
			temp = temp.Next      // Move the temp pointer forward
			ptr2 = ptr2.Next      // Move the ptr2 pointer to the next node in l2
		}
	}

	// If there are remaining nodes in l1, add them to the merged list
	for ptr1 != nil {
		temp.Next = ptr1
		temp = temp.Next
		ptr1 = ptr1.Next
	}

	// If there are remaining nodes in l2, add them to the merged list
	for ptr2 != nil {
		temp.Next = ptr2
		temp = temp.Next
		ptr2 = ptr2.Next
	}

	// The result starts from the next node of the dummy node
	result = result.Next
	return result
}
```