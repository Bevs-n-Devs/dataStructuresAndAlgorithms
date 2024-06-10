Trees 9
# Binary Tree Risght Side View
## Company: Meta
### Level: Medium

Given the `root` of a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

***Break It Down For Me...***
*Imagine we are standing on the right side of a binary tree.*
*Given the root of the tree, return the values of the nodes that we can see from top to bottom.*

Click [here](https://leetcode.com/problems/binary-tree-right-side-view/description/)for the question on Leetcode.

Click [here](https://www.youtube.com/watch?v=d4zLyf32e3I) for the solution on [Neetcode](https://neetcode.io/) **(which I would strongly reccomed you to get familiar with.)**

To solve this challenge we will use a [Tree](https://www.geeksforgeeks.org/introduction-to-tree-data-structure-and-algorithm-tutorials/) data structure in Python, JavaScript and Go.

### Example 1
```
Input: root = [1, 2, 3, null, 5, null, 4]
Output: [1, 3, 4]
```

### Example 2
```
Input: root = [1, null, 3]
Output: [1, 3]
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
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def rightSideView(self, root: TreeNode) -> List[int]:
        res = []  # This will store the values of nodes visible from the right side
        q = collections.deque([root])  # Initialize the queue with the root node

        # Loop until there are no more nodes in the queue
        while q:
            rightSide = None  # This will store the rightmost node at the current level
            qLen = len(q)  # Number of nodes at the current level

            # Process all nodes at the current level
            for i in range(qLen):
                node = q.popleft()  # Get the next node in the queue
                if node:  # If the node is not None
                    rightSide = node  # Update the rightmost node at this level
                    q.append(node.left)  # Add the left child to the queue
                    q.append(node.right)  # Add the right child to the queue

            # If there's a rightmost node at this level, add its value to the result
            if rightSide:
                res.append(rightSide.val)

        return res  # Return the list of values visible from the right side
```

## JavaScript
```
var rightSideView = function(root, level = 0, rightSide = []) {
    // Base case: if the current node is null, return the accumulated right side view
    const isBaseCase = root === null;
    if (isBaseCase) return rightSide;

    // If this is the first time we reach this level, add the current node's value to the right side view
    const isLastNode = level === rightSide.length;
    if (isLastNode) rightSide.push(root.val);

    // Continue the depth-first search
    return dfs(root, level, rightSide);
}

const dfs = (root, level, rightSide) => {
    // First, traverse the right subtree
    if (root.right) rightSideView(root.right, level + 1, rightSide);
    // Then, traverse the left subtree
    if (root.left) rightSideView(root.left, level + 1, rightSide);

    // Return the accumulated right side view
    return rightSide;
}
```

## Go
```
func rightSideView(root *TreeNode) []int {
    // Initialize the result slice to store the values of nodes visible from the right side
    res := make([]int, 0)
    // Initialize the queue with the root node
    q := []*TreeNode{root}
    
    // Loop until the queue is empty
    for len(q) != 0 {
        var rightSide *TreeNode
        qLen := len(q)
        
        // Process each level of the tree
        for i := 0; i < qLen; i++ {
            // Dequeue the front node
            node := q[0]
            q = q[1:]
            
            // If the node is not nil, process it
            if node != nil {
                rightSide = node // Keep track of the last node processed at this level
                // Enqueue the left and right children of the node
                q = append(q, node.Left)
                q = append(q, node.Right)
            }
        }
        
        // If there was a node processed at this level, add its value to the result
        if rightSide != nil {
            res = append(res, rightSide.Val)
        }
    }
    
    // Return the result containing the values of nodes visible from the right side
    return res
} 
```