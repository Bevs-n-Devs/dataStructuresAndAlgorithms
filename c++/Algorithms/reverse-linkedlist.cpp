#include <iostream>

/**
 * Node object for a linked list
 */
struct Node{
    public:
    int32_t val;
    Node *next;

    /**
     * Method to print all nodes in the linked list
     */
    void print(){
        std::cout << " " << val;
        Node *nxt = next;
        // loop until nxt is a nullptr
        while (nxt) {
            std::cout << "->" << nxt->val;
            nxt = nxt->next;
        }

        std::cout << "->NULL" << std::endl;
    }
} ;

/**
 * Reverses a Linked List
 * 
 * @param n: 1rst node of linked list
 * @type n: Node
 * 
 * @return The 1rst node of the reversed linked list
 */
Node* reverse_llist(Node* n) {
    Node* prev = nullptr;
    Node* curr = n;
    Node* next = n->next;

    while (next) {
        curr->next = prev;
        prev = curr;
        curr = next;
        next = next->next;
    }

    curr->next = prev;
    return curr;
}

int main(){
    std::cout << "Will attempt to reverse the following Linked List:" << std::endl;
    Node *llist = new Node{1, nullptr};
    llist->next = new Node{2, nullptr};
    llist->next->next = new Node{3, nullptr};
    llist->next->next->next = new Node{4, nullptr};
    llist->next ->next->next->next= new Node{5, nullptr}; 
    llist->print();
    llist = reverse_llist(llist);
    std::cout << "Linked List after reversal:" << std::endl;
    llist->print();
}