Trees 10
# Count Good Nodes in Binary Tree
## Company: Microsoft
### Level: Medium

Given a binary tree `root`, a node X in the tree is named **good** if in the path from root to X there are no nodes with a value greater than X.

Return the number of **good** nodes in the binary tree.

***Break It Down For Me...***
*Given a binary tree root, we call a node "``good``" if all the nodes on the path from the root to that node have values that are not greater than the value of that node.*
*Our task is to count how many "`good`" nodes are in the binary tree.*

Click [here](https://leetcode.com/problems/count-good-nodes-in-binary-tree/description/)for the question on Leetcode.

Click [here](https://www.youtube.com/watch?v=7cp5imvDzl4) for the solution on [Neetcode](https://neetcode.io/) **(which I would strongly reccomed you to get familiar with.)**

To solve this challenge we will use a [Tree](https://www.geeksforgeeks.org/introduction-to-tree-data-structure-and-algorithm-tutorials/) data structure in Python, JavaScript and Go.

### Example 1
![Example1 Image](https://assets.leetcode.com/uploads/2020/04/02/test_sample_1.png) 
```
Input: root = [3, 1, 4, 3, null, 1, 5]
Output: 4
```
**Explanation:** Nodes in blue are good.
Root Node `(3)` is always a good node.
Node 4 -> `(3,4)` is the maximum value in the path starting from the root.
Node 5 -> `(3,4,5)` is the maximum value in the path
Node 3 -> `(3,1,3)` is the maximum value in the path.

### Example 2
```
Input: root = [3, 3, null, 4, 2]
Output: 3
```
**Explanation:** Node` 2 -> (3, 3, 2)` is not good, because `3` is higher than it.

### Example 3
```
Input: root = [1]
Output: 1
```
**Explanation:** Root is considered as good.

## Python
```
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def goodNodes(self, root: TreeNode) -> int:
        # Helper function to perform a depth-first search (DFS)
        def dfs(node, maxVal):
            # If the node is None, return 0 (base case)
            if not node:
                return 0

            # Initialize result counter
            # Increment counter if the current node's value is greater than or equal to maxVal
            res = 1 if node.val >= maxVal else 0

            # Update maxVal to the maximum value encountered so far
            maxVal = max(maxVal, node.val)

            # Recursively perform DFS on the left and right children
            # Add the number of good nodes found in the left and right subtrees to the result counter
            res += dfs(node.left, maxVal)
            res += dfs(node.right, maxVal)

            # Return the total number of good nodes found in the subtree rooted at the current node
            return res

        # Start the DFS from the root node with the initial maxVal set to the root's value
        return dfs(root, root.val)
```

## JavaScript
```
// Function to count the number of good nodes in the binary tree
var goodNodes = function(root, max = -Infinity, total = [0]) {
    // Start counting good nodes from the root
    count(root, max, total);
    // Return the total number of good nodes found
    return total[0];
};

// Helper function to perform depth-first search and count good nodes
const count = (root, max, total) => {
    // Base case: if the node is null, return
    const isBaseCase = root === null;
    if (isBaseCase) return 0;

    // Call dfs to continue the search
    return dfs(root, max, total);
};

// Depth-first search function to traverse the tree
const dfs = (root, max, total) => {
    // Check if the current node is a good node
    const isGood = max <= root.val;
    if (isGood) total[0]++;

    // Update the max value to the maximum value encountered so far
    max = Math.max(max, root.val);

    // Recursively search the left and right subtrees
    count(root.left, max, total);
    count(root.right, max, total);
};
```

## Go
``// Definition for a binary tree node.
// type TreeNode struct {
//     Val int
//     Left *TreeNode
//     Right *TreeNode
// }

// Function to count the number of good nodes in the binary tree
func goodNodes(root *TreeNode) int {
    // Start counting good nodes from the root with the initial value of the root node
    return goodNodesUtil(root, root.Val)
}

// Helper function to perform depth-first search and count good nodes
func goodNodesUtil(root *TreeNode, parent int) int {
    // Base case: if the node is null, return 0
    if root == nil {
        return 0
    }
    
    // Initialize the result counter to 1 (assuming the current node is good)
    res := 1
    // Track the maximum value encountered so far
    max := root.Val
    
    // Check if the current node is not a good node
    if parent > root.Val {
        res = 0
        max = parent
    }
    
    // Recursively search the left and right subtrees
    res += goodNodesUtil(root.Left, max)
    res += goodNodesUtil(root.Right, max)
    
    // Return the total number of good nodes found
    return res
}
```