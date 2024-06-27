Trees 5
# Same Tree
## Company: Amazon
### Level: Easy

Given the roots of two binary trees `p` and `q`, write a function to check if they are the same or not.

Two binary trees are considered the same if they are structurally identical, and the nodes have the same value.

***Break It Down For Me...***
*We have two binary trees.*
*Our task is  to write a function that checks if the two trees are exactly the same.*
*They can only be the same if they have the same structure and they have the same node values at each position.*

Click [here](https://leetcode.com/problems/same-tree/description/)for the question on Leetcode.

Click [here](https://www.youtube.com/watch?v=vRbbcKXCxOw) for the solution on [Neetcode](https://neetcode.io/) **(which I would strongly reccomed you to get familiar with.)**

To solve this challenge we will use a [Tree](https://www.geeksforgeeks.org/introduction-to-tree-data-structure-and-algorithm-tutorials/) data structure in Python, JavaScript and Go.

### Example 1
```
Input: p = [1, 2, 3], q = [1, 2, 3]
Output: true
```

### Example 2
```
Input: p = [1, 2], q = [1, null, 2]
Output: false
```

### Example 3
```
Input: p = [1, 2, 1], q = [1, 1, 2]
Output: false
``` 

## Python
```
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def isSameTree(self, p: TreeNode, q: TreeNode) -> bool:
        # If both trees are empty, they are the same
        if not p and not q:
            return True
        
        # If both trees are non-empty, check the current node values and recursively check subtrees
        if p and q and p.val == q.val:
            # Recursively check the left subtrees and right subtrees
            return self.isSameTree(p.left, q.left) and self.isSameTree(p.right, q.right)
        
        # If one tree is empty and the other is not, or the values do not match, they are not the same
        else:
            return False
```

## JavaScript
```
var isSameTree = function(p, q) {
    // Base case: Both nodes are null
    const isBaseCase = !(p || q);
    if (isBaseCase) return true;

    // If one node is null and the other is not, trees are not the same
    const isBalanced = (p && q);
    if (!isBalanced) return false;

    // If the values of the current nodes do not match, trees are not the same
    const isSame = p.val === q.val;
    if (!isSame) return false;

    // Continue to recursively check the left and right subtrees
    return dfs(p, q);
};

const dfs = (p, q) => {
    // Recursively check the left subtrees
    const left = isSameTree(p.left, q.left);
    // Recursively check the right subtrees
    const right = isSameTree(p.right, q.right);

    // Trees are the same if both left and right subtrees are the same
    return left && right;
}
```

## Go
```
// isSameTree checks if two binary trees are identical
func isSameTree(p *TreeNode, q *TreeNode) bool {
    // Base case: Both nodes are nil, which means we've reached the end of both trees at the same position
    if p == nil && q == nil {
        return true
    }

    // If one node is nil and the other is not, or if the values of the nodes do not match, the trees are not the same
    if p == nil || q == nil || p.Val != q.Val {
        return false
    }

    // Recursively check the left and right subtrees
    return isSameTree(p.Left, q.Left) && isSameTree(p.Right, q.Right)
}
```