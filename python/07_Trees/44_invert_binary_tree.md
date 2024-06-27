Trees 1
# Invert Binary Tree
## Company: Google
### Level: Easy

Given the `root` of a binary tree, invert the tree, and return its root.

***Break It Down For Me...***
*We have a binary tree, which is a structure where each node has at most two children (left and right).*
*Our task is to "invert" the tree, meaning we should swap the left and right children of all nodes in the tree.* *After we invert the tree, return the root of the tree.*

Click [here](https://leetcode.com/problems/invert-binary-tree/description/)for the question on Leetcode.

Click [here](https://www.youtube.com/watch?v=OnSn2XEQ4MY) for the solution on [Neetcode](https://neetcode.io/) **(which I would strongly reccomed you to get familiar with.)**

To solve this challenge we will use a [Tree](https://www.geeksforgeeks.org/introduction-to-tree-data-structure-and-algorithm-tutorials/) data structure in Python, JavaScript and Go.

### Example 1
```
Input: root = [4, 2, 7, 1, 3, 6, 9]
Output: [4, 7, 2, 9, 6, 3, 1]
```

### Example 2
```
Input: root = [2, 1, 3]
Output: [2, 3, 1]
```

### Example 3
```
Input: root = []
Output: []
```

## Python
```
class Solution:
    def invertTree(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        # If the tree is empty (base case), return None
        if not root:
            return None
        
        # Swap the left and right children of the current node
        root.left, root.right = root.right, root.left
        
        # Recursively invert the left subtree
        self.invertTree(root.left)
        
        # Recursively invert the right subtree
        self.invertTree(root.right)
        
        # Return the root of the inverted tree
        return root
```

## JavaScript
```
var invertTree = (root) => {
    // Base case: if the current node is null, return null
    const isBaseCase = root === null;
    if (isBaseCase) return root;

    // Call the helper function to perform DFS and invert the tree
    return dfs(root);
}

const dfs = (root) => {
    // Recursively invert the left subtree
    const left = invertTree(root.left);
    
    // Recursively invert the right subtree
    const right = invertTree(root.right);
    
    // Swap the left and right children of the current node
    root.left = right;
    root.right = left;
    
    // Return the current node (root) after inverting its children
    return root;
}
```

## Go
```
// Definition for a binary tree node.
type TreeNode struct {
    Val   int
    Left  *TreeNode
    Right *TreeNode
}

func invertTree(root *TreeNode) *TreeNode {
    // Base case: if the current node is nil, return nil
    if root == nil {
        return root
    }

    // Recursively invert the left subtree and store the result in the left variable
    left := invertTree(root.Left)

    // Recursively invert the right subtree and assign it to the left child of the current node
    root.Left = invertTree(root.Right)

    // Assign the previously stored left subtree to the right child of the current node
    root.Right = left

    // Return the current node (root) after inverting its children
    return root
}
```