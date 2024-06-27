Trees 11
# Validate Binary Search Tree
## Company: Amazon
### Level: Medium

Given the `root` of a binary tree, determine if it is a *valid binary search tree* (BST).

A **valid BST** is defined as follows:

- The left subtree of a node contains only nodes with keys less than the node's key.
- The right subtree of a node contains only nodes with keys greater than the node's key.
- Both the left and right subtrees must also be binary search trees.

***Break It Down For Me...***
**

Click [here](https://leetcode.com/problems/validate-binary-search-tree/description/)for the question on Leetcode.

Click [here](https://www.youtube.com/watch?v=s6ATEkipzow) for the solution on [Neetcode](https://neetcode.io/) **(which I would strongly reccomed you to get familiar with.)**

To solve this challenge we will use a [Tree](https://www.geeksforgeeks.org/introduction-to-tree-data-structure-and-algorithm-tutorials/) data structure in Python, JavaScript and Go.

### Example 1
![Example1 Image](https://assets.leetcode.com/uploads/2020/12/01/tree1.jpg)
```
Input: root = [2, 1, 3]
Output: true
```

### Example 2
![Example 2 Image](https://assets.leetcode.com/uploads/2020/12/01/tree2.jpg)
```
Input: root = [5, 1, 4, null, null, 3, 6]
Output: false
```
**Explanation:** The root node's value is `5` but its right child's value is `4`.

### Python
```
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def isValidBST(self, root: TreeNode) -> bool:
        # Helper function to check the validity of the BST
        def valid(node, left, right):
            # Base case: if the node is null, it's a valid BST
            if not node:
                return True
            # Check if the current node's value violates the min/max constraints
            if not (left < node.val < right):
                return False

            # Recursively check the left and right subtrees
            return valid(node.left, left, node.val) and valid(node.right, node.val, right)

        # Initialize the recursive function with the full range of possible values
        return valid(root, float("-inf"), float("inf"))
```

### JavaScript
```
// Function to check if a binary tree is a valid binary search tree (BST)
var isValidBST = function(root, min = -Infinity, max = Infinity) {
    // Base case: if the node is null, it's a valid BST
    const isBaseCase = root === null;
    if (isBaseCase) return true;

    // Check if the current node's value violates the min/max constraints
    const isInvalid = (root.val <= min) || (max <= root.val);
    if (isInvalid) return false;

    // Perform depth-first search to check the subtrees
    return dfs(root, min, max);
};

// Helper function to perform depth-first search
const dfs = (root, min, max) => {
    // Recursively check the left subtree
    const left = isValidBST(root.left, min, root.val);
    // Recursively check the right subtree
    const right = isValidBST(root.right, root.val, max);

    // Return true if both left and right subtrees are valid BSTs
    return left && right;
};
```

### Go
```
// Definition for a binary tree node.
// type TreeNode struct {
//     Val int
//     Left *TreeNode
//     Right *TreeNode
// }

// Function to check if a binary tree is a valid binary search tree (BST)
func isValidBST(root *TreeNode) bool {
    // Start the validation process with no min/max constraints
    return isValid(root, nil, nil)
}

// Helper function to validate the BST
func isValid(root, min, max *TreeNode) bool {
    // Base case: if the node is null, it's a valid BST
    if root == nil {
        return true
    }

    // Check if the current node's value violates the min constraint
    if min != nil && root.Val <= min.Val {
        return false
    }

    // Check if the current node's value violates the max constraint
    if max != nil && root.Val >= max.Val {
        return false
    }

    // Recursively check the left and right subtrees
    return isValid(root.Left, min, root) && isValid(root.Right, root, max)
}
```