Linked List 7
# Add Two Numbers
## Company: Amazon
### Level: Medium

You are given two non-empty linked lists representing two non-negative integers. The digits are stored in **reverse order**, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

***Break It Down For Me***
*There are two linked lists.*
*Each linked list represents a number, but the digits are in reverse order.*
*For example, the number 123 is stored as 3 -> 2 -> 1 in the linked list.*
*What we need to do is add the two numbers together as if you were adding two regular numbers.*
*Then return the result as a linked list, also in reverse order.*

Click [here](https://leetcode.com/problems/add-two-numbers/description/)for the question on Leetcode.

Click [here](https://www.youtube.com/watch?v=wgFPrzTjm7s) for the solution on [Neetcode](https://neetcode.io/) **(which I would strongly reccomed you to get familiar with.)**

To solve this challenge we will use a [Linked List](https://www.geeksforgeeks.org/introduction-to-linked-list-data-structure-and-algorithm-tutorial/) in Python, JavaScript and Go.

### Example 1
```
Input: l1 = [2, 4, 3], l2 = [5, 6, 4]
Output: [7, 0, 8]
```
**Explanation:** `342 + 465 = 807`.

### Example 2
```
Input: l1 = [0], l2 = [0]
Output: [0]
```

### Example 3
```
Input: l1 = [9, 9, 9, 9, 9, 9, 9], l2 = [9, 9, 9, 9]
Output: [8, 9, 9, 9, 0, 0, 0, 1] 
```

## Python
```
# Definition for a Node.
class Node:
    def __init__(self, x: int, next: 'Node' = None, random: 'Node' = None):
        self.val = int(x)  # Initialize the value of the node
        self.next = next  # Initialize the next pointer
        self.random = random  # Initialize the random pointer

class Solution:
    def copyRandomList(self, head: "Node") -> "Node":
        # Dictionary to map original nodes to their copies
        oldToCopy = {None: None}

        # First pass: Create all the nodes and store them in the dictionary
        cur = head
        while cur:
            # Create a copy of the current node
            copy = Node(cur.val)
            # Map the original node to its copy
            oldToCopy[cur] = copy
            # Move to the next node in the original list
            cur = cur.next
        
        # Second pass: Assign next and random pointers for the copied nodes
        cur = head
        while cur:
            # Retrieve the copy of the current node
            copy = oldToCopy[cur]
            # Set the next pointer of the copied node
            copy.next = oldToCopy[cur.next]
            # Set the random pointer of the copied node
            copy.random = oldToCopy[cur.random]
            # Move to the next node in the original list
            cur = cur.next
        
        # Return the head of the copied list
        return oldToCopy[head]
```

## JavaScript
```
var addTwoNumbers = function(l1, l2, carry = 0) {
    // Create a dummy node to act as the start of the resulting linked list
    let sentinel = tail = new ListNode();

    // Loop through both lists until there are no more nodes and no carry value
    while (l1 || l2 || carry) {  /* Time O(MAX(N, M)) */
        // Calculate the sum of the current digits and the carry
        const sum = (l1?.val || 0) + (l2?.val || 0) + carry;
        
        // The new value is the sum modulo 10 (i.e., the last digit of the sum)
        const val = sum % 10;
        
        // The new carry is the sum divided by 10 (i.e., the tens place digit of the sum)
        carry = Math.floor(sum / 10);

        // Create a new node with the computed value and append it to the result list
        tail.next = new ListNode(val);
        tail = tail.next;

        // Move to the next nodes in the input lists, or null if at the end
        l1 = l1?.next || null;
        l2 = l2?.next || null;
    }

    // Return the head of the resulting linked list, skipping the dummy node
    return sentinel.next;
};
```

## Go
```
func addTwoNumbers(l1 *ListNode, l2 *ListNode) *ListNode {
    // Create a dummy node to act as the start of the resulting linked list
    var dummy = new(ListNode)
    // l3 is a pointer to a pointer to a ListNode, initially pointing to the dummy node
    var l3 **ListNode = &dummy
    // Initialize carry to handle sums greater than 9
    var carry int
    list1 := l1
    list2 := l2

    // Loop through both lists until there are no more nodes in both lists
    for (list1 != nil) || (list2 != nil) {
        // Move l3 to point to the next node in the result list
        l3 = &((*l3).Next)
        // Create a new node for the next digit
        *l3 = new(ListNode)
        var sum int

        // If list1 is not nil, add its value to sum and move to the next node
        if list1 != nil {
            sum += list1.Val
            list1 = list1.Next
        }

        // If list2 is not nil, add its value to sum and move to the next node
        if list2 != nil {
            sum += list2.Val
            list2 = list2.Next
        }

        // Set the value of the current node in the result list
        // The value is the sum of the current digits plus carry, modulo 10
        (*l3).Val = (sum + carry) % 10
        // Update carry to be the sum of the current digits plus carry, divided by 10
        carry = (sum + carry) / 10
    }

    // If there is a carry left after the final addition, add a new node with the carry value
    if carry > 0 {
        l3 = &((*l3).Next)
        *l3 = new(ListNode)
        (*l3).Val = carry
    }

    // Return the next node of the dummy, which is the head of the resulting linked list
    return dummy.Next
}
```