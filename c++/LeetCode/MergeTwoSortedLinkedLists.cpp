#include <iostream>
#include <vector>

/**
 * Merge Two Sorted (Linked) Lists
 * 
 * You are given the heads of two sorted linked lists list1 and list2.
 * Merge the two lists into one sorted list. The list should be made by splicing together the nodes of the first two lists.
 * Return the head of the merged linked list.
 * 
 * Constraints:
 *    - The number of nodes in both lists is in the range [0, 50].
 *    - -100 <= Node.val <= 100
 *    - Both list1 and list2 are sorted in non-decreasing order.
 */



/**
 * Linked List Node object
 */
struct LListNode {
    int val;
    LListNode* next;
    /**
     * Default Constructor
     */
    LListNode() {
        val = 0;
        next = nullptr;
    }

    /**
     * Constructor to include a value when instantiated
     * 
     * @param x : integer value for the node to store
     */
    LListNode(int x) {
        val = x;
        next = nullptr;
    }

    /**
     * Constructor to include a value and next node when instantiated
     * 
     * @param x : integer value for the node to store
     * @param n : Linked List Node to point to next
     */
    LListNode(int x, LListNode* node) {
        val = x;
        next = node;
    }

    /**
     * Constructor that creates a full linked list with a give vector of integers
     * 
     * @param vals : vector of integer values
     */
    LListNode(std::vector<int> vals) {
        val = vals[0];
        vals.erase(vals.begin());
        if (vals.size() > 1) next = new LListNode(vals);
        else next = new LListNode(vals[0]);
    }

    /**
     * Prints the Linked list values
     */
    void printLList() {
        if (!next) std::cout << val;
        else {
            LListNode* tmp = next;
            std::cout << val << ",";
            while (tmp->next) {
                std::cout << tmp->val << ",";
                tmp = tmp->next;
            }
            std::cout << tmp->val;
        }
    }
};

// Test Object
struct Test {
    LListNode *lLst1;
    LListNode *lLst2;
} ;

// Test Cases
Test TestCases[] = {
    Test{
        new LListNode(std::vector<int>{1,2,4}), 
        new LListNode(std::vector<int>{1,3,4})
    },
    Test{
        nullptr, 
        nullptr
    },
    Test{
        nullptr, 
        new LListNode(0)
    },
};

/**
 * Solution to merge the linked lists
 * 
 * This is a recursive approach (function that calls itself until a condition is met)
 * 
 * @param list1 : 1st linked list
 * @param list2 : 2nd linked list 
 */
LListNode* mergeTwoLists(LListNode* list1, LListNode* list2) {
    if (!list1) return list2;
    if (!list2) return list1;
    
    
    if (list1->val <= list2->val) {
        // constraint checks
        if (list1->next && (list1->val > list1->next->val)) return nullptr;
        if (list1->val < -100 || list1->val > 100) return nullptr;
        list1->next = mergeTwoLists(list1->next, list2);
        return list1;
    } else {
        // constraint checks
        if (list2->next && (list2->val > list2->next->val)) return nullptr;
        if (list2->val < -100 || list2->val > 100) return nullptr;
        list2->next = mergeTwoLists(list1, list2->next);
        return list2;
    }
    
}

int main() {
    int i = 1;
    for (auto test: TestCases) {
        std::cout << "Test Case " << i << ": [";
        if (test.lLst1) test.lLst1->printLList();
        std::cout << "], [";
        if (test.lLst2) test.lLst2->printLList();
        std::cout << "]" << std::endl;

        LListNode *sol = mergeTwoLists(test.lLst1, test.lLst2);
        std::cout << "\t- Result: [";
        if(sol) sol->printLList();
        std::cout << "]\n" << std::endl;
        i+=1;
    }
}