#include <iostream>

/**
 * Binary Trees are collections of nodes that can point to
 * a maximum of two other child nodes.
 * 
 *                  P      <-- Root (Parent)
 *                 / \
 *                L   R    <-- Child Nodes (new parents)
 *               /   / \
 *              L   L   R  < --- Leaf Nodes
 * 
 * - The first node in the tree is called the "root"
 * - Each child that doesn't have hildren, is a "leaf" node
 *  
 * Full Tree:
 * Every node has either 0 or 2 child nodes
 * Prefect Tree:
 * Every node has either 0 or 2 child nodes & every 
 * level it completely full 
 * Complete Trees:
 * Every level has no gaps in leaves going from left 
 * to right
 * 
*/

/**
 * Enum for trying to generate different Binary Tree
 * confurations.
*/
enum TREE {
    BALANCED = 0,
    UNBALANCED_LEFT = 1,
    LOOSE_LEAVES = 2,
};

/**
 * Binary Tree Nodes can only have two "child" nodes:
 * left & right. 
*/
class Node {
    public:
        int data;
        Node* left;
        Node* right;
        Node (int value) {
            this->data = value;
            this->left = this->right = nullptr;
        }
};

/**
 * Generates a Binary Tree
 * 
 * @param tree_type enum for a TREE type to generate
*/
Node* generateTree (TREE tree_type = BALANCED) {
    Node* root;
    switch (tree_type) {
        case BALANCED:
            /**
             *               0
             *            /     \
             *          1         2
             *        /   \     /   \
             *      3      4   5     6
             *     / \    / \ / \   / \
             *   NULL --------------------
            */ 
            root = new Node(0);
            root->left = new Node(1);
            root->right = new Node(2);
            root->left->left = new Node(3);
            root->left->right = new Node(4);
            root->right->left = new Node(5);
            root->right->right = new Node(6);
            break;

        case UNBALANCED_LEFT:
            /**
             *               0
             *            /     \
             *          1         2
             *        /   \     /   \
             *      3      4  NULL  NULL
             *     / \    / \ 
             *   NULL ---------
            */ 
            root = new Node(0);
            root->left = new Node(1);
            root->right = new Node(2);
            root->left->left = new Node(3);
            root->left->right = new Node(4);
            break;

        case LOOSE_LEAVES:
            /**
             *               0
             *            /     \
             *          1         2
             *        /   \     /   \
             *     NULL    3 NULL    4
             *     / \    / \       / \ 
             *  NULL NULL --------------        
            */ 
            root = new Node(0);
            root->left = new Node(1);
            root->right = new Node(2);
            root->left->left = new Node(3);
            root->left->right = new Node(4);
            root->right->right = new Node(5);
            root->left->left->left = new Node(6);
            break;

        default:
            break;
    }

    return root;
}

int main () {
    std::cout << "Practicing with Binary Trees" << std::endl;
    std::cout << "===============================================================" << std::endl;
    


    return 0;
}