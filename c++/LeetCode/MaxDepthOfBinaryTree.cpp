#include <iostream>
#include "../Utils/utils.h"

/**
 * 104. Maximum Depth of Binary Tree
 * 
 * Given the root of a binary tree, return its maximum depth. A binary tree's maximum 
 * depth is the number of nodes along the longest path from the root node down to the 
 * farthest leaf node.
 * 
 * Constraints:
 *      * The number of nodes in the tree is in the range [0, 104].
 *      * -100 <= Node.val <= 100
 * 
 */

/**
 * Test object
 */
struct Test {
    private:
    BinaryTree* tree;

    public:
    int expectedResult;

    Test (std::vector<int> vals, int res) {
        this->tree =  new BinaryTree(vals);
        this->expectedResult = res;
    }

    BinaryTreeNode* root(){
        return this->tree->root;
    }

    void show_vals(){
        this->tree->printTree();
    }
};

/**
 * List of test cases
 */
Test TestCases[] = {
    Test{{3,9,20,NULL,NULL,15,7}, 3},
    Test{{1,NULL,2}, 2},
};

/**
 * Gets the max depth of a binary tree
 * 
 * @param root: Binary tree root node
 * 
 * @return number of levels to tree
 * 
 */
int maxDepth(BinaryTreeNode* root) {
    int depth = 0;
    if (!root) return depth;
    // Check constraints
    if (root->left && root->left->data < -100 | root->left->data > 100) return 0;
    if (root->right && root->right->data < -100 | root->right->data > 100) return 0;
    
    // increase depth
    depth+=1;
    // recursively get left & right depths, then return which side has the max
    return std::max(depth+maxDepth(root->left),depth+maxDepth(root->right));
}

int main(){
    std::cout << " ---- LeetCode:: 104. Maximum Depth of Binary Tree ---- " << std::endl;
    for (int i=0;i<sizeof(TestCases)/sizeof(TestCases[0]);i++){
        std::cout << "Test " << i+1 << std::endl;
        std::cout << "Input: {tree: ";
        TestCases[i].show_vals();
        std::cout << ", expectedResult: " << TestCases[i].expectedResult << "}" << std::endl;

        int ans = maxDepth(TestCases[i].root());
        std::cout << "\nActual Result:  " << ans << std::endl;
        std::cout << "=========================================================\n" << std::endl;
    }
    return 0;
}