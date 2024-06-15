Trees 14
# Binary Tree Maximum Path Sum
## Company: Meta
### Level: Hard

A **path** in a binary tree is a sequence of nodes where each pair of adjacent nodes in the sequence has an edge connecting them. A node can only appear in the sequence at most once. Note that the path does not need to pass through the root.

The **path sum** of a path is the sum of the node's values in the path.

Given the `root` of a binary tree, *return the maximum* **path sum** *of any non-empty path*.

***Break It Down For Me...***
*In a binary tree, a path is a way to go from one node to another by moving along the edges that connect them. Each node can only be used once in a path.*
*A path sum is the total of all the node values in that path.*
*We need to find the highest path sum you can get from any path in the tree.*

Click [here](https://leetcode.com/problems/binary-tree-maximum-path-sum/description/)for the question on Leetcode.

Click [here](https://www.youtube.com/watch?v=Hr5cWUld4vU) for the solution on [Neetcode](https://neetcode.io/) **(which I would strongly reccomed you to get familiar with.)**

To solve this challenge we will use a [Tree](https://www.geeksforgeeks.org/introduction-to-tree-data-structure-and-algorithm-tutorials/) data structure in Python, JavaScript and Go.

### Example 1
![Example 1 Image](https://assets.leetcode.com/uploads/2020/10/13/exx1.jpg)
```
Input: root = [1, 2, 3]
Output: 6
```
**Explanation:** The optimal path is `2 -> 1 -> 3` with a path sum of `2 + 1 + 3 = 6`.

### Example 2
![Example 2 Image](https://assets.leetcode.com/uploads/2020/10/13/exx2.jpg)
```
Input: root = [-10, 9, 20, null, null, 15, 7]
Output: 42
```
**Explanation:** The optimal path is `15 -> 20 -> 7` with a path sum of `15 + 20 + 7 = 42`.

## Python
```
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def maxPathSum(self, root: TreeNode) -> int:
        # Initialize the result with the value of the root node in a list to allow updates in dfs
        res = [root.val]

        # Define a helper function for depth-first search (DFS)
        # It returns the maximum path sum without splitting
        def dfs(root):
            if not root:
                # If the current node is None, return 0 as there is no path through None
                return 0

            # Recursively calculate the maximum path sum for the left subtree
            leftMax = dfs(root.left)
            # Recursively calculate the maximum path sum for the right subtree
            rightMax = dfs(root.right)
            # If the left path sum is negative, ignore it by taking 0
            leftMax = max(leftMax, 0)
            # If the right path sum is negative, ignore it by taking 0
            rightMax = max(rightMax, 0)

            # Update the result with the maximum path sum considering the current node as the root
            res[0] = max(res[0], root.val + leftMax + rightMax)
            
            # Return the maximum path sum without splitting (either left or right)
            return root.val + max(leftMax, rightMax)

        # Call the helper function starting from the root
        dfs(root)
        # Return the maximum path sum found
        return res[0]
```

## JavaScript
```
var maxPathSum = function(root, maxValue = [ -Infinity ]) {
    // Initiates the path sum calculation starting from the root
    pathSum(root, maxValue);

    // Returns the maximum path sum found
    return maxValue[0];
};

// Helper function to calculate the path sum
const pathSum = (root, maxValue) => {
    // Base case: if the node is null, return 0 as there is no path
    const isBaseCase = root === null;
    if (isBaseCase) return 0;

    // Calls the DFS function to calculate the path sum
    return dfs(root, maxValue);
}

// DFS function to traverse the tree and calculate the path sum
const dfs = (node, maxValue) => {
    // Recursively calculate the maximum path sum for the left subtree
    const left = Math.max(0, pathSum(node.left, maxValue));
    // Recursively calculate the maximum path sum for the right subtree
    const right = Math.max(0, pathSum(node.right, maxValue));
    // Calculate the total sum including the current node and its left and right subtrees
    const sum = left + right + node.val;

    // Update the maximum path sum found so far
    maxValue[0] = Math.max(maxValue[0], sum);

    // Return the maximum path sum without splitting (either left or right)
    return Math.max(left, right) + node.val;
}
```

## Go
```
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

// Function to calculate the maximum path sum in a binary tree
func maxPathSum(root *TreeNode) int {
    // Initialize an array to store the maximum path sum found so far
    arr := []int{math.MinInt32}
    
    // Call the helper function to compute the path sum starting from the root
    maxPathSumUtil(root, arr)
    
    // Return the maximum path sum found
    return arr[0]
}

// Helper function to calculate the path sum for a given node
func maxPathSumUtil(root *TreeNode, arr []int) int {
    // Base case: if the node is nil, return 0 as there is no path
    if root == nil {
        return 0
    }

    // Recursively calculate the maximum path sum for the left subtree
    left := max(0, maxPathSumUtil(root.Left, arr))
    
    // Recursively calculate the maximum path sum for the right subtree
    right := max(0, maxPathSumUtil(root.Right, arr))
    
    // Update the maximum path sum found so far with the current node included
    arr[0] = max(arr[0], root.Val + left + right)

    // Return the maximum path sum without splitting (either left or right)
    return root.Val + max(left, right)
}

// Helper function to return the maximum of two integers
func max(a, b int) int {
    if a > b {
        return a
    }
    return b
}
```