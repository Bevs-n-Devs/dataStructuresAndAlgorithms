Trees 7
# Lowest Common Ancestor of a Binary Search Tree
## Company: Amazon
### Level: Medium

Given a binary search tree (BST), find the lowest common ancestor (LCA) node of two given nodes in the BST.

According to the [definition of LCA on Wikipedia](https://en.wikipedia.org/wiki/Lowest_common_ancestor): “The lowest common ancestor is defined between two nodes `p` and `q` as the lowest node in `T` that has both `p` and `q` as descendants (where we allow a node to be a descendant of itself).”

***Break It Down For Me...***
*We have a binary search tree (BST) and two nodes in which we will use to find the lowest common ancestor (of the two nodes).*
*The Lowest Common Ancestor of the two nodes is the lowest node in the tree that has both nodes as decendants.*

## Example 1
```
Input: root = [6, 2, 8, 0, 4, 7, 9, null, null, 3, 5], p = 2, q = 8
Output: 6 
```
**Explanation:** The LCA of nodes 2 and 8 is 6.

## Example 2
```
Input: root = [6, 2, 8, 0, 4, 7, 9, null, null, 3, 5], p = 2, q = 4
Output: 2
```
**Explanation:** The LCA of nodes 2 and 4 is 2, since a node can be a descendant of itself according to the LCA definition.

## Example 3
```
Input: root = [2, 1], p = 2, q = 1
Output: 2
```

### Python
```
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def lowestCommonAncestor(
        self, root: "TreeNode", p: "TreeNode", q: "TreeNode"
    ) -> "TreeNode":
        # Loop until we find the lowest common ancestor
        while True:
            # If both nodes p and q are greater than root, move to the right subtree
            if root.val < p.val and root.val < q.val:
                root = root.right
            # If both nodes p and q are less than root, move to the left subtree
            elif root.val > p.val and root.val > q.val:
                root = root.left
            # If neither of the above conditions are true, we have found the lowest common ancestor
            else:
                return root
```

### JavaScript
```
var lowestCommonAncestor = function(root, p, q) {
    // Check if both p and q are less than the current root's value
    const isGreater = (p.val < root.val) && (q.val < root.val);
    if (isGreater) {
        // If true, move to the left subtree
        return lowestCommonAncestor(root.left, p, q);
    }

    // Check if both p and q are greater than the current root's value
    const isLess = (root.val < p.val) && (root.val < q.val);
    if (isLess) {
        // If true, move to the right subtree
        return lowestCommonAncestor(root.right, p, q);
    }

    // If neither of the above conditions are true, we have found the lowest common ancestor
    return root;
};
```

### Go
```
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val   int
 *     Left  *TreeNode
 *     Right *TreeNode
 * }
 */

func lowestCommonAncestor(root, p, q *TreeNode) *TreeNode {
    // Check if both p and q are greater than the root's value
    if p.Val > root.Val && q.Val > root.Val {
        // If true, move to the right subtree
        return lowestCommonAncestor(root.Right, p, q)
    }

    // Check if both p and q are less than the root's value
    if p.Val < root.Val && q.Val < root.Val {
        // If true, move to the left subtree
        return lowestCommonAncestor(root.Left, p, q)
    }

    // If neither of the above conditions is true, 
    // it means the current root is the lowest common ancestor
    return root
}
```