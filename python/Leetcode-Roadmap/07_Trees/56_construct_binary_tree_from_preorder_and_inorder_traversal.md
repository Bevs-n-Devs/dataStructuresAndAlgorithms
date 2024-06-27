Trees 13
# Construct Binary Tree From Preorder And Inorder Traversal
## Company: Amazon
### Level: Medium

Given two integer arrays preorder and inorder where preorder is the preorder traversal of a binary tree and inorder is the inorder traversal of the same tree, construct and return the binary tree.

***Break It Down For Me...***
*We have two list numbers.*
*The first list, called `preorder`, shows the order in which nodes of a tree are visited from top to bottom, visiting the root node first, then the left subtree, and finally the right subtree.*
*Our task is to use these two lists to build the tree and return it.*

Click [here](https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/)for the question on Leetcode.

Click [here](https://www.youtube.com/watch?v=ihj4IQGZ2zc) for the solution on [Neetcode](https://neetcode.io/) **(which I would strongly reccomed you to get familiar with.)**

To solve this challenge we will use a [Tree](https://www.geeksforgeeks.org/introduction-to-tree-data-structure-and-algorithm-tutorials/) data structure in Python, JavaScript and Go.

### Example 1
![Example 1 Image](https://assets.leetcode.com/uploads/2021/02/19/tree.jpg)
```
Input: preorder = [3, 9, 20, 15, 7], inorder = [9, 3, 15, 20, 7]
Output: [3, 9, 20, null, null, 15, 7]
```

### Example 2
```
Input: preorder = [-1], inorder = [-1]
Output: [-1]
```

## Python
```
class Solution:
    def buildTree(self, preorder: List[int], inorder: List[int]) -> Optional[TreeNode]:
        # Base case: if there are no nodes to construct the tree
        if not preorder or not inorder:
            return None

        # The first element of preorder is the root node
        root = TreeNode(preorder[0])

        # Find the index of the root in inorder to separate left and right subtrees
        mid = inorder.index(preorder[0])

        # Recursively build the left subtree
        # Elements from start to 'mid' in inorder are part of the left subtree
        # Elements from index 1 to 'mid + 1' in preorder are part of the left subtree
        root.left = self.buildTree(preorder[1 : mid + 1], inorder[:mid])

        # Recursively build the right subtree
        # Elements from 'mid + 1' to end in inorder are part of the right subtree
        # Elements from 'mid + 1' to end in preorder are part of the right subtree
        root.right = self.buildTree(preorder[mid + 1 :], inorder[mid + 1 :])

        # Return the constructed binary tree's root node
        return root
```

## JavaScript
```
// Function to build the binary tree
var buildTree = function(preorder, inorder, max = -Infinity, indices = { preorder: 0, inorder: 0 }) {
    // Base case: if we have processed all elements in inorder array
    const isBaseCase = preorder.length <= indices.inorder;
    if (isBaseCase) return null;

    // If we have reached the end of a subtree in the inorder array
    const isAtEnd = inorder[indices.inorder] === max;
    if (isAtEnd) {
        indices.inorder++; // Move to the next element in inorder
        return null;
    }

    // Call the helper function to construct the tree
    return dfs(preorder, inorder, max, indices);
}

// Helper function to perform the depth-first search and construct the tree
var dfs = (preorder, inorder, max, indices) => {
    // Get the current root value from preorder array
    const val = preorder[indices.preorder++]
    // Create a new tree node with the current value
    const root = new TreeNode(val);

    // Recursively build the left subtree
    // For the left subtree, the maximum value it can have is the current root value
    root.left = buildTree(preorder, inorder, root.val, indices);

    // Recursively build the right subtree
    // For the right subtree, the maximum value it can have remains the original max
    root.right = buildTree(preorder, inorder, max, indices);

    // Return the constructed root node
    return root;
}
```

## Go
```
// Function to build a binary tree from preorder and inorder traversals
func buildTree(preorder []int, inorder []int) *TreeNode {
    // Base case: if either preorder or inorder list is empty, return nil
    if len(preorder) == 0 || len(inorder) == 0 {
        return nil
    }

    // Create the root node with the first value from preorder list
    root := &TreeNode{Val: preorder[0]}
    
    // Find the index of the root value in the inorder list
    mid := index(inorder, preorder[0])
    
    // Recursively build the left subtree
    root.Left = buildTree(preorder[1: mid + 1], inorder[:mid])
    
    // Recursively build the right subtree
    root.Right = buildTree(preorder[mid + 1:], inorder[mid + 1:])
    
    // Return the constructed tree
    return root
}

// Helper function to find the index of a value in a slice
func index(arr []int, val int) int {
    // Iterate through the slice to find the index of the value
    for i, v := range arr {
        if v == val {
            return i
        }
    }
    // Return -1 if the value is not found (although it should always be found in this context)
    return -1
}
```