Trees 8
# Binary Tree Level Order Traversal
## Company: Meta
### Level: Medium

Given the `root` of a binary tree, return the level order traversal of its nodes' values. (i.e., from left to right, level by level).

***Break It Down For Me***
*We have a binary tree, and we want to collect the values of its nodes level by level, from left to right.*
*Imagine we are looking at the tree from top to bottom, and we want to list all the values we see at each level.*

Click [here](https://leetcode.com/problems/binary-tree-level-order-traversal/description/)for the question on Leetcode.

Click [here](https://www.youtube.com/watch?v=6ZnyEApgFYg) for the solution on [Neetcode](https://neetcode.io/) **(which I would strongly reccomed you to get familiar with.)**

To solve this challenge we will use a [Tree](https://www.geeksforgeeks.org/introduction-to-tree-data-structure-and-algorithm-tutorials/) data structure in Python, JavaScript and Go.

### Example 1
```
Input: root = [3, 9, 20, null, null, 15, 7]
Output: [[3], [9, 20], [15, 7]]
```

### Example 2
```
Input: root = [1]
Output: [[1]]
```

### Example 3
```
Input: root = []
Output: []
```

## Python
```
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

import collections

class Solution:
    def levelOrder(self, root: TreeNode) -> List[List[int]]:
        # Result list to store the level order traversal
        res = []
        
        # Queue to help with the level order traversal
        q = collections.deque()
        
        # Start by adding the root node to the queue if it's not None
        if root:
            q.append(root)
        
        # Continue the traversal until the queue is empty
        while q:
            # List to store the values of nodes at the current level
            val = []
            
            # Iterate through the nodes at the current level
            for i in range(len(q)):
                # Pop the node from the left side of the queue
                node = q.popleft()
                # Add the node's value to the current level's list
                val.append(node.val)
                
                # If the node has a left child, add it to the queue
                if node.left:
                    q.append(node.left)
                # If the node has a right child, add it to the queue
                if node.right:
                    q.append(node.right)
            
            # Add the current level's list of values to the result list
            res.append(val)
        
        # Return the final result list containing level order traversal
        return res
```

## JavaScript
```
var levelOrder = function(root) {
    // Base case: If the root is null, return an empty array
    const isBaseCase = root === null;
    if (isBaseCase) return [];

    // Start the breadth-first search with the root node
    return bfs([root]);
};

const bfs = (queue /* Space O(W) */, levels = []) => {
    // Continue the traversal while there are nodes in the queue
    while (queue.length) { // Time O(N)
        // Array to hold the values of nodes at the current level
        const level = [];

        // Iterate over the nodes at the current level
        for (let i = (queue.length - 1); 0 <= i; i--) {
            // Remove the node from the front of the queue (Time O(N) ... This can be O(1) if we use an actual queue data structure)
            const node = queue.shift();

            // If the node has a left child, add it to the queue
            if (node.left) queue.push(node.left);
            // If the node has a right child, add it to the queue
            if (node.right) queue.push(node.right);

            // Add the node's value to the current level array
            level.push(node.val);
        }

        // Add the current level array to the levels array
        levels.push(level.slice());
    }

    // Return the levels array containing level order traversal
    return levels;
};
```

## GO
```
func levelOrder(root *TreeNode) [][]int {
    // Check if the root is nil, if so return nil
    if root == nil {
        return nil
    }

    // Initialize the result slice which will store the final level order traversal
    var result [][]int
    // Initialize the level counter to keep track of the current level
    level := 0
    // Initialize the queue with the root node
    q := make([]*TreeNode, 1)
    q[0] = root

    // While there are nodes in the queue
    for len(q) > 0 {
        // Get the number of nodes at the current level
        curLen := len(q)
        // Iterate over each node in the current level
        for i := 0; i < curLen; i++ {
            // Remove the front node from the queue
            node := q[0]
            q = q[1:]

            // If the result slice does not have a sub-slice for the current level, create one
            if len(result) <= level {
                // Create a new sub-slice with the first value of the current level and append to result
                result = append(result, []int{node.Val})
            } else {
                // Add the node's value to the existing sub-slice for the current level
                result[level] = append(result[level], node.Val)
            }

            // Add the left child to the queue if it exists
            if node.Left != nil {
                q = append(q, node.Left)
            }
            // Add the right child to the queue if it exists
            if node.Right != nil {
                q = append(q, node.Right)
            }
        }
        // Increment the level counter after processing all nodes at the current level
        level++
    }

    // Return the result which contains the level order traversal
    return result
}
```