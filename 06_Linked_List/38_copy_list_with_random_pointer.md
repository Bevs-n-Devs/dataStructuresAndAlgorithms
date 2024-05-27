Linked List 6
# Copy List with Random Pointer
## Company: Amazon
### Level: Medium

A linked list of length `n` is given such that each node contains an additional random pointer, which could point to any node in the list, or `null`.

Construct a [deep copy of](https://en.wikipedia.org/wiki/Object_copying#Deep_copy) the list. The deep copy should consist of exactly `n` brand new nodes, where each new node has its value set to the value of its corresponding original node. Both the `next` and `random` pointer of the new nodes should point to new nodes in the copied list such that the pointers in the original list and copied list represent the same list state. **None of the pointers in the new list should point to nodes in the original list.**

For example, if there are two nodes `X` and `Y` in the original list, where `X.random --> Y`, then for the corresponding two nodes `x` and `y` in the copied list, `x.random --> y`.

Return the head of the copied linked list.

The linked list is represented in the input/output as a list of `n` nodes. Each node is represented as a pair of `[val, random_index]` where:

- `val`: an integer representing `Node.val`
- `random_index`: the index of the node (range from `0` to `n-1`) that the `random` pointer points to, or `null` if it does not point to any node.

Your code will only be given the `head` of the original linked list.

***Break It Down For Me...***
*We start with a linked list where each node points to another node (next pointer) and possibly another random node (random pointer).*
*We have to create an entirely new list that mirrors the original list, meaning:*
- *Each new node has the same value as the corresponding original node.*
- *Each new node's next and random pointers should point to new nodes that correspond to the original nodes' next and random pointers.*

Click [here](https://leetcode.com/problems/copy-list-with-random-pointer/description/)for the question on Leetcode.

Click [here](https://www.youtube.com/watch?v=5Y2EiZST97Y) for the solution on [Neetcode](https://neetcode.io/) **(which I would strongly reccomed you to get familiar with.)**

To solve this challenge we will use a [Linked List](https://www.geeksforgeeks.org/introduction-to-linked-list-data-structure-and-algorithm-tutorial/) and in Pythopn, JavaScript and Go.

### Example 1
```
Input: head = [[7,null], [13,0], [11,4], [10,2], [1,0]]
Output: [[7,null], [13,0], [11,4], [10,2], [1,0]]
```

### Example 2
```
Input: head = [[1,1], [2,1]]
Output: [[1,1], [2,1]]
```

### Example 3
```
Input: head = [[3,null], [3,0], [3,null]]
Output: [[3,null], [3,0], [3,null]]
```

## Python
```
# Definition for a Node.
class Node:
    def __init__(self, x: int, next: 'Node' = None, random: 'Node' = None):
        self.val = int(x)
        self.next = next
        self.random = random

class Solution:
    def copyRandomList(self, head: "Node") -> "Node":
        # Dictionary to map original nodes to their copies.
        # Initialize with None to handle the case where the next or random pointer is None.
        oldToCopy = {None: None}

        # First pass: Create a copy of each node and store it in the dictionary.
        cur = head
        while cur:
            # Create a new node (copy) with the same value as the current node.
            copy = Node(cur.val)
            # Map the original node to the copied node.
            oldToCopy[cur] = copy
            # Move to the next node in the original list.
            cur = cur.next

        # Reset the current pointer to the head of the list.
        cur = head
        # Second pass: Set the next and random pointers for each copied node.
        while cur:
            # Get the copied node corresponding to the current original node.
            copy = oldToCopy[cur]
            # Set the next pointer of the copied node.
            copy.next = oldToCopy[cur.next]
            # Set the random pointer of the copied node.
            copy.random = oldToCopy[cur.random]
            # Move to the next node in the original list.
            cur = cur.next

        # Return the head of the copied list.
        return oldToCopy[head]
```

## JavaScript
```
var copyRandomList = function(head, map = new Map()) {
    // If head is null, return null
    if (!head) return null;
    // If the node is already cloned, return the cloned node
    if (map.has(head)) return map.get(head);

    // Create a new node (clone) with the same value as the current node
    const clone = new Node(head.val);

    // Map the original node to the cloned node
    map.set(head, clone);
    // Recursively clone the next node and set it to the next of the cloned node
    clone.next = copyRandomList(head.next, map);
    // Recursively clone the random node and set it to the random of the cloned node
    clone.random = copyRandomList(head.random, map);

    // Return the cloned node
    return clone;
}
```

## Go
```
// Definition for a Node.
type Node struct {
    Val    int
    Next   *Node
    Random *Node
}

func copyRandomList(head *Node) *Node {
    // Create a map to hold the original nodes as keys and the new cloned nodes as values
    oldToCopy := make(map[*Node]*Node)
    
    // First pass: create a new node for each original node and store the mapping
    cur := head
    for cur != nil {
        // Create a clone of the current node with the same value
        clone := &Node{Val: cur.Val}
        // Map the original node to the cloned node
        oldToCopy[cur] = clone
        // Move to the next node in the original list
        cur = cur.Next
    }

    // Reset the current pointer to the head of the list
    cur = head
    // Second pass: assign next and random pointers for the cloned nodes
    for cur != nil {
        // Get the cloned node corresponding to the current original node
        clone := oldToCopy[cur]
        // Set the next pointer of the cloned node
        clone.Next = oldToCopy[cur.Next]
        // Set the random pointer of the cloned node
        clone.Random = oldToCopy[cur.Random]
        // Move to the next node in the original list
        cur = cur.Next
    }

    // Return the head of the cloned list
    return oldToCopy[head]
}
```