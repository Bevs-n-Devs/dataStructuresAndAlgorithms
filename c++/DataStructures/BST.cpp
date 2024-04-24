#include <iostream>

/**
 * Binary Tree Node
 * contain a value & 2 child nodes: left and right
*/
class Node {
    public:
        int value;
        Node* left;
        Node* right;

        Node (int value) {
            this->value = value;
            this->left = this->right = nullptr;
        }
};

/**
 *               47
 *            /     \
 *          21       76
 *        /   \     /   \
 *      18    27   52    82
 *     / \    / \       / \ 
 *  NULL NULL --------------
 * 
 * BST : Binary Search Tree
 * - The values of the nodes follow a specific
 *   order; values less than the parent go to 
 *   the left child node and values greater than
 *   the parent node go to the right child node.        
*/ 
class BinarySearchTree {
    // private:
    //     Node* root;

    public:
        Node* root;
        /**
         * Constructor for the Binary Search Tree that does not 
         * require an initial value.
        */
        BinarySearchTree () {
            this->root = nullptr;
        }

        /**
         * Constructor for the Binary Search Tree that accepts 
         * an initial root node value.
         * 
         * @param value value for the root node to store.
        */
        BinarySearchTree (int value) {
            this->insert(value);
        }

        /**
         * Inserts new node in the Binary Search Tree
         * 
         * @param value
         * @return boolean value; true if insert was successful, otherwise false 
        */
        bool insert (int value) {
            Node* newNode = new Node(value);
            if (this->root == nullptr) {
                this->root = newNode;
                return true;
            }

            Node* temp = this->root;
            while (true) {
                if (newNode->value == temp->value) return false;
                if (newNode->value < temp->value) {
                    if (temp->left == nullptr) {
                        temp->left = newNode;
                        return true;
                    }

                    temp = temp->left;
                } else {
                    if (temp->right == nullptr) {
                        temp->right = newNode;
                        return true;
                    }

                    temp = temp->right;
                }
            }
        }

        /**
         * Checks if a value is in the Binary Search Tree
         * 
         * @param value value to search for
        */
        bool contains (int value) {
            Node* temp = this->root;
            while (temp) {
                if (temp->value == value) return true;
                if (value < temp->value) temp = temp->left;
                else  temp = temp->right;
            }

            return false;
        }
};

int main () {
    std::cout << "Practicing w/ Binary Search Trees" << std::endl;
    std::cout << "===============================================================" << std::endl;
    BinarySearchTree* myBST = new BinarySearchTree();
    int nodeArr[] = {47,21,76,18,27,52,82};
    int N = sizeof(nodeArr)/sizeof(nodeArr[0]);
    for (auto n: nodeArr) {
        myBST->insert(n);
    }

    std::cout << "BST root: " << myBST->root->value << std::endl;
    std::cout << "BST contains 88: " << myBST->contains(88) << std::endl;
    std::cout << "BST contains 18: " << myBST->contains(18) << std::endl;
    return 0;
}