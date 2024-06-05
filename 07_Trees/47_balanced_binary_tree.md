Trees 4
# Balanced Binary Tree
## Company: Amazon
### Level: Easy

Given a binary tree, determine if it is **height-balanced**.

**Break It Down For Me...**
*Given the root of a binary tree, check if the tree is height-balanced.*
*A tree is height-balanced if the height difference between the left and right subtrees of any node is no more than 1.*
*Calculate the height of the left and right subtrees for each node.
Check the height difference for each node.*
*If the height difference for any node is more than 1, the tree is not height-balanced.*
*If the height difference for all nodes is at most 1, the tree is height-balanced.*

Click [here](https://leetcode.com/problems/balanced-binary-tree/description/)for the question on Leetcode.

Click [here](https://www.youtube.com/watch?v=QfJsau0ItOY) for the solution on [Neetcode](https://neetcode.io/) **(which I would strongly reccomed you to get familiar with.)**

To solve this challenge we will use a [Tree](https://www.geeksforgeeks.org/introduction-to-tree-data-structure-and-algorithm-tutorials/) data structure in Python, JavaScript and Go.

### Example 1
```
Input: root = [3, 9, 20, null, null, 15, 7]
Output: true
```

### Example 2
```
Input: root = [1, 2, 2, 3, 3, null, null, 4, 4]
Output: false
```

### Example 3
```
Input: root = []
Output: true
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
    def isBalanced(self, root: Optional[TreeNode]) -> bool:
        # Helper function to perform depth-first search (dfs)
        def dfs(root):
            # Base case: if the node is null, it is balanced with height 0
            if not root:
                return [True, 0]

            # Recursively check the left subtree
            left = dfs(root.left)
            # Recursively check the right subtree
            right = dfs(root.right)
            
            # Check if the current node is balanced:
            # - left[0] and right[0] ensure left and right subtrees are balanced
            # - abs(left[1] - right[1]) <= 1 ensures the height difference is at most 1
            balanced = left[0] and right[0] and abs(left[1] - right[1]) <= 1
            
            # Return a list where:
            # - balanced indicates if the current subtree is balanced
            # - 1 + max(left[1], right[1]) is the height of the current subtree
            return [balanced, 1 + max(left[1], right[1])]

        # Start the dfs from the root and return whether the tree is balanced
        return dfs(root)[0]
```
## JavaScript
```
var isBalanced = function (root) {
    // Get the height and balance status of the root
    const [ _height, _isBalanced ] = isRootBalanced(root);

    // Return whether the tree is balanced
    return _isBalanced;
};

var isRootBalanced = (root) => {
    // Base case: if the node is null, it has a height of -1 and is balanced
    const isBaseCase = root === null
    if (isBaseCase) return [ -1, true ];

    // Otherwise, perform a depth-first search
    return dfs(root)
}

var dfs = (root) => {
    // Recursively get the height and balance status of the left subtree
    const [ left, isLeftBalanced ] = isRootBalanced(root.left);
    // Recursively get the height and balance status of the right subtree
    const [ right, isRightBalanced ] = isRootBalanced(root.right);

    // Calculate the height and the difference in heights of the subtrees
    const [ height, difference ]  = [ Math.max(left, right), Math.abs(left - right) ];

    // Check if the height difference is acceptable (i.e., <= 1)
    const isAcceptableHeight = difference <= 1;
    // Check if both left and right subtrees are balanced
    const _isBalanced = isLeftBalanced && isRightBalanced;

    // The current node is balanced if both subtrees are balanced and the height difference is acceptable
    const _isRootBalanced = _isBalanced && isAcceptableHeight;

    // Return the height of the current node and whether it is balanced
    return [ (height + 1), _isRootBalanced ];
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

// BalanceTree struct is used to store the balance status and height of a tree
type BalanceTree struct {
	Balance bool // Indicates if the tree is balanced
	Height  int  // Height of the tree
}

// isBalanced function checks if the binary tree is height-balanced
func isBalanced(root *TreeNode) bool {
	// Perform depth-first search and return the balance status of the root
	return dfs(root).Balance
}

// dfs function performs depth-first search to check balance and compute height
func dfs(root *TreeNode) BalanceTree {
	// Base case: if the root is nil, it's balanced with a height of 0
	if root == nil {
		return BalanceTree{true, 0}
	}

	// Recursively check the left and right subtrees
	left, right := dfs(root.Left), dfs(root.Right)
	// Check if the current node is balanced
	balanced := (left.Balance && right.Balance && int(math.Abs(float64(left.Height)-float64(right.Height))) <= 1)

	// Return the balance status and height of the current node
	return BalanceTree{balanced, 1 + max(left.Height, right.Height)}
}

// max function returns the maximum of two integers
func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}
```