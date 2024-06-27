Trees 15
# Serialize And Deserialize Binary Tree
## Company: Amazon
### Level: Hard

Serialization is the process of converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed later in the same or another computer environment.

Design an algorithm to serialize and deserialize a binary tree. There is no restriction on how your serialization/deserialization algorithm should work. You just need to ensure that a binary tree can be serialized to a string and this string can be deserialized to the original tree structure.

**Clarification:** The input/output format is the same as [how LeetCode serializes a binary tree](https://support.leetcode.com/hc/en-us/articles/360011883654-What-does-1-null-2-3-mean-in-binary-tree-representation). You do not necessarily need to follow this format, so please be creative and come up with different approaches yourself.

 ***Break It Down For Me...***
 *Serialization is a way to change a data structure or object into a format that can be easily stored or sent to another place. This format can be changed back into the original data structure or object later.*

*Our task is to create a method to serialize (convert into a string) and deserialize (convert back from the string) a binary tree. There are no rules on how we must do this; just make sure that the tree can be turned into a string and then back into the same tree.*

Click [here](https://leetcode.com/problems/serialize-and-deserialize-binary-tree/description/)for the question on Leetcode.

Click [here](https://www.youtube.com/watch?v=u4JAi2JJhI8) for the solution on [Neetcode](https://neetcode.io/) **(which I would strongly reccomed you to get familiar with.)**

To solve this challenge we will use a [Tree](https://www.geeksforgeeks.org/introduction-to-tree-data-structure-and-algorithm-tutorials/) data structure in Python, JavaScript and Go.

### Example 1
![Example 1 Image](https://assets.leetcode.com/uploads/2020/09/15/serdeser.jpg)
```
Input: root = [1, 2, 3, null, null, 4, 5]
Output: [1, 2, 3, null, null, 4, 5]
```

### Example 2
```
Input: root = []
Output: []
```

## Python
```
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Codec:
    # Function to serialize the binary tree
    def serialize(self, root):
        res = []

        # Helper function to perform DFS for serialization
        def dfs(node):
            if not node:
                res.append("N")  # Use "N" to denote null nodes
                return
            res.append(str(node.val))  # Add the value of the node to the result
            dfs(node.left)  # Recurse on the left child
            dfs(node.right)  # Recurse on the right child

        dfs(root)  # Start the DFS from the root
        return ",".join(res)  # Join the result list into a single string

    # Function to deserialize the string back to a binary tree
    def deserialize(self, data):
        vals = data.split(",")  # Split the input string by commas
        self.i = 0

        # Helper function to perform DFS for deserialization
        def dfs():
            if vals[self.i] == "N":
                self.i += 1  # Move to the next value
                return None  # Return None for null nodes
            node = TreeNode(int(vals[self.i]))  # Create a new tree node
            self.i += 1  # Move to the next value
            node.left = dfs()  # Recurse on the left child
            node.right = dfs()  # Recurse on the right child
            return node

        return dfs()  # Start the DFS from the beginning of the list
```

## JavaScript
```
// Function to serialize the binary tree
var serialize = function(root, result = []) {
    serial(root, result);

    return result;
};

// Helper function to handle the base case for serialization
const serial = (root, result) => {
    const isBase = root === null;
    if (isBase) return result.push(null);  // Use null to denote null nodes

    dfsSerialize(root, result);  // Start DFS serialization
}

// Helper function to perform DFS for serialization
const dfsSerialize = (node, result) => {
    result.push(node.val);  // Add the value of the node to the result
    serial(node.left, result);  // Recurse on the left child
    serial(node.right, result);  // Recurse on the right child
};
```

## Go
```
type Codec struct {
}

// Constructor function to initialize the Codec struct
func Constructor() Codec {
    return Codec{}
}

// Function to serialize the binary tree
func (this *Codec) serialize(root *TreeNode) string {
    res := make([]string, 0)  // Initialize the result list
    
    // Helper function to perform DFS for serialization
    var dfs func(node* TreeNode)
    dfs = func(node *TreeNode) {
        if node == nil {
            res = append(res, "N")  // Use "N" to denote null nodes
            return
        }
        res = append(res, strconv.Itoa(node.Val))  // Add the value of the node to the result
        dfs(node.Left)  // Recurse on the left child
        dfs(node.Right)  // Recurse on the right child
    }
    
    dfs(root)  // Start the DFS from the root
    return strings.Join(res, ",")  // Join the result list into a single string
}

// Function to deserialize the string back to a binary tree
func (this *Codec) deserialize(data string) *TreeNode {    
    vals := strings.Split(data, ",")  // Split the input string by commas
    i := 0
    
    // Helper function to perform DFS for deserialization
    var dfs func() *TreeNode
    dfs = func() *TreeNode {
        if vals[i] == "N" {
            i += 1  // Move to the next value
            return nil  // Return nil for null nodes
        }
        val, _ := strconv.Atoi(vals[i])  // Convert string to integer
        node := &TreeNode{Val: val}  // Create a new tree node
        i += 1  // Move to the next value
        node.Left = dfs()  // Recurse on the left child
        node.Right = dfs()  // Recurse on the right child
        return node
    }
    
    return dfs()  // Start the DFS from the beginning of the list
}
```