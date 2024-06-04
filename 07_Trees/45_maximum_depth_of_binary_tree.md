Trees 2
# Maximum Depth of Binary Tree
## Company: Google
### Level: Easy

Given the `root` of a binary tree, return its maximum depth.

A binary tree's **maximum depth** is the number of nodes along the longest path from the root node down to the farthest leaf node.

**Break It Down For Me...**
*We have a binary tree, which is a structure where each node has at most two children (left and right).*
*Our task is to find the "maximum depth" of this tree.*
*The **maximum depth** is the number of nodes along the longest path from the root node (the top node of the tree) down to the farthest leaf node (a node with no children).*

Click [here](https://leetcode.com/problems/maximum-depth-of-binary-tree/description/)for the question on Leetcode.

Click [here](https://www.youtube.com/watch?v=bkxqA8Rfv04) for the solution on [Neetcode](https://neetcode.io/) **(which I would strongly reccomed you to get familiar with.)**

To solve this challenge we will use a [Tree](https://www.geeksforgeeks.org/introduction-to-tree-data-structure-and-algorithm-tutorials/) data structure in Python, JavaScript and Go.

### Example 1
```
Input: root = [3, 9, 20, null, null, 15, 7]
Output: 3
```

### Example 2
```
Input: root = [1, null, 2]
Output: 2
```

## Python
```
class Solution:
    def maxDepth(self, root: TreeNode) -> int:
        # Initialize a stack with the root node and its depth (1)
        stack = [[root, 1]]
        
        # Initialize the result to keep track of the maximum depth
        res = 0

        # Iterate while there are nodes in the stack
        while stack:
            # Pop the last node and its depth from the stack
            node, depth = stack.pop()

            if node:
                # Update the result with the maximum depth found so far
                res = max(res, depth)
                # Add the left child and its depth to the stack
                stack.append([node.left, depth + 1])
                # Add the right child and its depth to the stack
                stack.append([node.right, depth + 1])
        
        # Return the maximum depth found
        return res
```

## JavaScript
```
var maxDepth = function(root) {
    // Check for the base case: if the root is null, the depth is 0
    const isBaseCase = root === null;
    if (isBaseCase) return 0;

    // Call the depth-first search (dfs) function to compute the depth
    return dfs(root);
};

const dfs = (root) => {
    // Recursively find the maximum depth of the left subtree
    const left = maxDepth(root.left);
    // Recursively find the maximum depth of the right subtree
    const right = maxDepth(root.right);

    // Compute the height by taking the maximum depth of left and right subtrees
    const height = Math.max(left, right);

    // Add 1 to account for the current node and return the height
    return height + 1;
};
```

## Go
```
func maxDepth(root *TreeNode) int {
    // Base case: if the current node is nil, the depth is 0
    if root == nil {
        return 0
    }

    // Recursively find the maximum depth of the left subtree
    left := maxDepth(root.Left)
    // Recursively find the maximum depth of the right subtree
    right := maxDepth(root.Right)

    // Compare the depths of the left and right subtrees
    if left > right {
        // If the left subtree is deeper, add 1 for the current node and return
        return 1 + left
    }

    // If the right subtree is deeper or they are equal, add 1 for the current node and return
    return 1 + right
}
```