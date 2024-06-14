Trees 12
# Kth Smallest Element In a BST
## Company: Amazon
### Level: Medium

Given the root of a binary search tree, and an integer k, return the kth smallest value (1-indexed) of all the values of the nodes in the tree.

***Braek It Down For Me...***
*Given a binary search tree (BST) and a number k, we need to find the kth smallest value in the tree.*
*Note that k is 1-based, meaning that if k = 1, we will need to find the smallest value, if k = 2, the second smallest value, and so on.*

Click [here](https://leetcode.com/problems/kth-smallest-element-in-a-bst/description/)for the question on Leetcode.

Click [here](https://www.youtube.com/watch?v=5LUXSvjmGCw) for the solution on [Neetcode](https://neetcode.io/) **(which I would strongly reccomed you to get familiar with.)**

To solve this challenge we will use a [Tree](https://www.geeksforgeeks.org/introduction-to-tree-data-structure-and-algorithm-tutorials/) data structure in Python, JavaScript and Go.


### Example 1
![Example 1 Image](https://assets.leetcode.com/uploads/2021/01/28/kthtree1.jpg)
```
Input: root = [3, 1, 4, null, 2], k = 1
Output: 1
```

### Example 2
![Example 2 Image](https://assets.leetcode.com/uploads/2021/01/28/kthtree2.jpg)
```
Input: root = [5, 3, 6, 2, 4, null, null, 1], k = 3
Output: 3
```

## Python
```
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def kthSmallest(self, root: TreeNode, k: int) -> int:
        stack = []  # Initialize a stack to help with in-order traversal
        curr = root  # Start with the root node

        # Continue the process while there are nodes to be processed
        while stack or curr:
            # Traverse to the leftmost node
            while curr:
                stack.append(curr)  # Push the current node to the stack
                curr = curr.left  # Move to the left child

            # Pop the node from the stack
            curr = stack.pop()
            k -= 1  # Decrement k for each node visited
            # If k becomes 0, we've found the kth smallest element
            if k == 0:
                return curr.val

            # Move to the right child
            curr = curr.right
```

## JavaScript
```
// Function to find the kth smallest element in a binary search tree
var kthSmallest = function(root, k, inOrder = []) {
    // Base case: if the root is null, return the inOrder array
    if (!root) return inOrder;

    // Perform a depth-first search (DFS) on the tree
    return dfs(root, k, inOrder);
};

// Helper function to perform the DFS
const dfs = (root, k, inOrder) => {
    // Traverse the left subtree
    if (root.left) kthSmallest(root.left, k, inOrder);

    // Add the current node's value to the inOrder array
    inOrder.push(root.val);

    // Traverse the right subtree
    if (root.right) kthSmallest(root.right, k, inOrder);

    // Return the kth smallest element (k is 1-indexed, so subtract 1 for 0-indexed array)
    return inOrder[(k - 1)];
}
```

## Go
```
func kthSmallest(root *TreeNode, k int) int {
    // Initialize a stack to keep track of nodes for in-order traversal
	stack := make([]*TreeNode, 0, k)

	for {
        // Traverse to the leftmost node
		for root != nil {
            // Push the current node to the stack
			stack = append(stack, root)
            // Move to the left child
			root = root.Left
		}

        // Pop the node from the stack
		root = stack[len(stack) - 1]
        stack = stack[:len(stack) - 1]

        // Decrement k for each node visited
		k--
        // If k is zero, we've found the kth smallest element
		if k == 0 {
			return root.Val
		}

        // Move to the right child
		root = root.Right
	}

    // Return -1 if not found (this line will actually never be reached due to the function logic)
	return -1
}
```