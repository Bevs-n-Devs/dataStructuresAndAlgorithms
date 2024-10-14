#include "../Utils/utils.h"

/**
 * Given the root of a binary tree, invert the tree, and return its root.
 *    
 *         1                           1
 *       /   \                       /   \
 *      2     3           =>        3     2
 *    /  \   /  \                 /  \   /  \ 
 *   4    5 6    7               7    6 4    5
 * 
 * Constraints: 
 *      * The number of nodes in the tree is in the range [0, 100].
 *      * -100 <= Node.val <= 100
 * 
 */

/**
 * Test Objects to store test input
 */
struct Test{
    BinaryTree* head;
    BinaryTree* expectedResult;
    Test(std::vector<int> vec1, std::vector<int> vec2){
        std::printf("%d",vec1[0]);
        head = new BinaryTree(vec1);
        expectedResult = new BinaryTree(vec2);
    }
};

/**
 * Collection of Test Cases to run against the solution
 */
Test TestCases[] = {
    Test{{4,2,7,1,3,6,9},{4,7,2,9,6,3,1}},
    Test{{2,1,3},{2,3,1}},
    // Test{{},{}},
};

BinaryTreeNode* invertTree(BinaryTreeNode* root) {
    if (!root) return root;
    
    std::swap(root->left, root->right);
    invertTree(root->left);
    invertTree(root->right);
    return root;
}

void my_bfs(BinaryTreeNode* root){
    if (root == NULL)
        return;

    // Create an empty queue for level order traversal
    std::queue<BinaryTreeNode*> q;

    // Enqueue Root and initialize height
    q.push(root);

    while (q.empty() == false) {
        
        // Print front of queue and remove it from queue
        BinaryTreeNode* node = q.front();
        std::cout << node->data << " ";
        q.pop();

        // Enqueue left child
        if (node->left != NULL)
            q.push(node->left);

        // Enqueue right child
        if (node->right != NULL)
            q.push(node->right);
    }
}

int main() {
    std::cout << " --- Running Invert Binary Tree LeetCode Problem --- " << std::endl;
    for (int i = 0; i< sizeof(TestCases)/sizeof(TestCases[0]);i++){
        Test test = TestCases[i];
        std::cout << "Test " << i+1 << std::endl;
        std::cout << "input: { binary tree: ";
        test.head->printTree();
        std::cout << ", expectedResult: ";
        test.expectedResult->printTree();
        std::cout << "}" << std::endl;
        BinaryTreeNode* ans = invertTree(test.head->root);
        test.head->printTree();
        std::cout << "\n=============================================================\n" << std::endl;
    } 
    return 0;
}