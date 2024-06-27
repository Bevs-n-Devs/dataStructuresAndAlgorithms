Trees 3
# Diameter of Binary Tree
## Company: Google
### Level: Easy

Given the `root` of a binary tree, return the length of the **diameter** of the tree.

The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the `root`.

The length of a path between two nodes is represented by the number of edges between them.

***Break It Down For Me...***
*We have a binary tree, which is a tree where each node has at most two children.*
*Our task is to find the diameter of this tree.*
**The diameter of a binary tree is the length of the longest path you can find between any two nodes in the tree.**
**This path can go through the root or not.**
**The length of the path is measured by the number of edges between the nodes.**

Click [here](https://leetcode.com/problems/diameter-of-binary-tree/description/)for the question on Leetcode.

Click [here](https://www.youtube.com/watch?v=bkxqA8Rfv04) for the solution on [Neetcode](https://neetcode.io/) **(which I would strongly reccomed you to get familiar with.)**

To solve this challenge we will use a [Tree](https://www.geeksforgeeks.org/introduction-to-tree-data-structure-and-algorithm-tutorials/) data structure in Python, JavaScript and Go.

## Example 1
```
Input: root = [1, 2, 3, 4, 5]
Output: 3
```
**Explanation:** 3 is the length of the path `[4,2,1,3]` or `[5,2,1,3]`.

## Example 2
```
Input: root = [1, 2]
Output: 1
```

### Python
```
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def diameterOfBinaryTree(self, root: Optional[TreeNode]) -> int:
        # Initialize the result variable to keep track of the maximum diameter found
        res = 0

        # Define a depth-first search (DFS) function to traverse the tree
        def dfs(root):
            nonlocal res  # Allow access to the res variable defined outside the function

            # Base case: if the current node is None, return 0 (no depth)
            if not root:
                return 0
            
            # Recursively calculate the depth of the left and right subtrees
            left = dfs(root.left)
            right = dfs(root.right)
            
            # Update the result with the maximum diameter found so far
            res = max(res, left + right)

            # Return the depth of the current subtree
            return 1 + max(left, right)

        # Call the DFS function starting from the root node
        dfs(root)
        
        # Return the maximum diameter found
        return res
```

### JavaScript
```
// Function to calculate the diameter of a binary tree
var diameterOfBinaryTree = function(root, max = [0]) {
    // Call the diameterOfTree function to start the process and calculate the maximum diameter
    diameterOfTree(root, max);
    
    // Return the maximum diameter found
    return max[0];
};

// Helper function to traverse the tree and calculate depths
const diameterOfTree = (root, max) => {
    // Base case: if the current node is null, return 0 (no depth)
    const isBaseCase = root === null;
    if (isBaseCase) return 0;

    // Call the dfs function to perform depth-first search and calculate the depth of the current subtree
    return dfs(root, max);
}

// Function to perform depth-first search (DFS) on the tree
const dfs = (root, max) => {
    // Recursively calculate the depth of the left subtree
    const left = diameterOfTree(root.left, max);
    // Recursively calculate the depth of the right subtree
    const right = diameterOfTree(root.right, max);

    // Calculate the diameter at the current node (sum of left and right subtree depths)
    const diameter = left + right;
    // Update the maximum diameter found so far
    max[0] = Math.max(max[0], diameter);

    // Calculate the height of the current subtree (1 for the current node plus the maximum depth of its subtrees)
    const height = Math.max(left, right);

    // Return the height of the subtree rooted at the current node
    return height + 1;
}
```

### Go
```
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

// Function to calculate the diameter of the binary tree
func diameterOfBinaryTree(root *TreeNode) int {
    // Initialize maxLength to keep track of the maximum diameter found
    maxLength := 0
    // Call the dfs function to traverse the tree and calculate depths
    dfs(root, &maxLength)
    // Return the maximum diameter found
    return maxLength
}

// Helper function to perform depth-first search (DFS) on the tree
func dfs(t *TreeNode, maxLength *int) int {
    // Base case: if the current node is nil, return 0 (no depth)
    if t == nil {
        return 0
    }

    // Recursively calculate the depth of the left and right subtrees
    left := dfs(t.Left, maxLength)
    right := dfs(t.Right, maxLength)
    
    // Update maxLength with the maximum diameter found so far
    *maxLength = max(*maxLength, left + right)

    // Return the depth of the current subtree (1 for the current node plus the maximum depth of its subtrees)
    return max(left, right) + 1
}

// Helper function to find the maximum of two integers
func max(a, b int) int {
    if a > b {
        return a
    }
    return b
}
```