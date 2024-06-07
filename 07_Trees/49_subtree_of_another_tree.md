Trees 6
# Subtree of Another Tree
## Company: Amazon
### Level: Easy

Given the roots of two binary trees `root` and `subRoot`, return `true` if there is a subtree of root with the same structure and node values of `subRoot` and `false` otherwise.

A subtree of a binary tree `tree` is a tree that consists of a node in `tree` and all of this node's descendants. The tree tree could also be considered as a subtree of itself.

***Break It Down For Me***
**

Click [here](https://leetcode.com/problems/subtree-of-another-tree/description/)for the question on Leetcode.

Click [here](https://www.youtube.com/watch?v=E36O5SWp-LE) for the solution on [Neetcode](https://neetcode.io/) **(which I would strongly reccomed you to get familiar with.)**

To solve this challenge we will use a [Tree](https://www.geeksforgeeks.org/introduction-to-tree-data-structure-and-algorithm-tutorials/) data structure in Python, JavaScript and Go.

### Example 1
```
Input: root = [3, 4, 5, 1, 2], subRoot = [4, 1, 2]
Output: true
```

### Example 2
```
Input: root = [3, 4, 5, 1, 2, null, null, null, null, 0], subRoot = [4, 1, 2]
Output: false
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
    def isSubtree(self, s: TreeNode, t: TreeNode) -> bool:
        # If t is None, it is considered a subtree of any tree including an empty tree
        if not t:
            return True
        # If s is None but t is not, t cannot be a subtree of s
        if not s:
            return False

        # Check if the trees rooted at s and t are identical
        if self.sameTree(s, t):
            return True
        
        # Otherwise, recursively check if t is a subtree of either the left or right subtree of s
        return self.isSubtree(s.left, t) or self.isSubtree(s.right, t)

    def sameTree(self, s: TreeNode, t: TreeNode) -> bool:
        # If both s and t are None, they are considered identical
        if not s and not t:
            return True
        # If both s and t are not None, check if the values are the same and the left and right subtrees are identical
        if s and t and s.val == t.val:
            return self.sameTree(s.left, t.left) and self.sameTree(s.right, t.right)
        # If one of s or t is None or the values do not match, the trees are not identical
        return False
```

## JavaScript
```
var isSubtree = function(root, subRoot) {
    // Base case: if root is null, subRoot cannot be a subtree
    if (!root) return false;

    // Check if the current trees rooted at root and subRoot are identical
    if (isSame(root, subRoot)) return true;

    // Recursively check the left and right subtrees of root
    const hasLeftTree = isSubtree(root.left, subRoot);
    const hasRightTree = isSubtree(root.right, subRoot);

    // Return true if subRoot is a subtree of either left or right subtree
    return hasLeftTree || hasRightTree;
};

const isSame = (root, subRoot) => {
    // Base case: if either tree is null, they are the same if both are null
    const hasReachedEnd = !(root && subRoot);
    if (hasReachedEnd) return root === subRoot;

    // If the values of the current nodes do not match, the trees are not the same
    const isMismatch = root.val !== subRoot.val;
    if (isMismatch) return false;

    // Recursively check if the left and right subtrees are identical
    const isLeftSame = isSame(root.left, subRoot.left);
    const isRightSame = isSame(root.right, subRoot.right);

    // Return true if both left and right subtrees are identical
    return isLeftSame && isRightSame;
};

const hash = (val) => require('crypto')
    .createHash('md5')
    .update(val)
    .digest('hex');

const merkle = (root) => {
    // Base case: if the node is null, return a hash for null
    if (!root) return '#';

    const { left, val, right } = root;

    // Compute the Merkle hash for the left and right subtrees
    const leftMerkle = merkle(left);
    const rightMerkle = merkle(right);

    // Combine the hashes of left subtree, current node value, and right subtree
    const merkleVal = [leftMerkle, val, rightMerkle].join('');
    const merkleHash = hash(merkleVal);

    // Assign the computed Merkle hash to the current node
    root.merkle = merkleHash;

    return root.merkle;
};

const search = (root, subRoot) => {
    // Base case: if the node is null, subRoot cannot be found
    if (!root) return false;

    // Check if the current node's Merkle hash matches the subRoot's Merkle hash
    const hasSamePath = root.merkle === subRoot.merkle;
    if (hasSamePath) return true;

    // Recursively search the left and right subtrees
    const left = search(root.left, subRoot);
    const right = search(root.right, subRoot);

    // Return true if subRoot is found in either left or right subtree
    return left || right;
};

var isSubtree = function(root, subRoot) {
    // Compute the Merkle hash for all nodes in both root and subRoot trees
    [root, subRoot].forEach(merkle);

    // Search if subRoot is a subtree of root using Merkle hash
    return search(root, subRoot);
};

const hashify = (root, hash, postOrderKey) => {
    // Base case: if the node is null, return a hash for null
    if (!root) return '#';

    // Compute the hash for the left and right subtrees
    const left = hashify(root.left, hash, postOrderKey);
    const right = hashify(root.right, hash, postOrderKey);

    // Combine the hashes of left subtree, current node value, and right subtree
    const key = [left, root.val, right].join('');

    // Assign a unique key to the combined hash if it doesn't already exist
    if (!hash.has(key)) {
        hash.set(key, postOrderKey[0]);
        postOrderKey[0]++;
    }

    return hash.get(key);
};

var isSubtree = function(root, subRoot, hash = new Map(), postOrderKey = [0]) {
    // Compute and store the hash values for all nodes in the root tree
    hashify(root, hash, postOrderKey);

    // Compute the hash key for the subRoot tree
    const hashKey = [
        hashify(subRoot.left, hash, postOrderKey),
        subRoot.val,
        hashify(subRoot.right, hash, postOrderKey)
    ].join('');

    // Check if the computed hash key for subRoot exists in the hash map of root
    return hash.has(hashKey);
};
```

## Go
```
// Function to check if subRoot is a subtree of root
func isSubtree(root *TreeNode, subRoot *TreeNode) bool {
    // If the main tree root is null, subRoot cannot be a subtree
    if root == nil {
        return false
    }

    // Check if the current trees rooted at root and subRoot are identical
    // or recursively check the left and right subtrees of root
    return equals(root, subRoot) || isSubtree(root.Left, subRoot) || isSubtree(root.Right, subRoot)
}

// Function to check if two trees are identical
func equals(s *TreeNode, t *TreeNode) bool {
    // If both trees are null, they are identical
    if s == nil && t == nil {
        return true
    }

    // If one of the trees is null or the values of the current nodes do not match, they are not identical
    if s == nil || t == nil || s.Val != t.Val {
        return false
    }

    // Recursively check if the left and right subtrees are identical
    return equals(s.Left, t.Left) && equals(s.Right, t.Right)
}
```