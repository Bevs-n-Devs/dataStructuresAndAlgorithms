#include "../Utils/utils.h"

/**
 * Given the head of a sorted linked list, delete all duplicates 
 * such that each element appears only once. Return the linked 
 * list sorted as well.
 * 
 * Constraints:
 *      * The number of nodes in the list is in the range [0, 300].
 *      * -100 <= Node.val <= 100
 *      * The list is guaranteed to be sorted in ascending order.
 */

struct Test {
    LListNode* head = nullptr;
    LListNode* expectedResult = {};
};

Test TestCases[] = {
    Test{new LListNode({1,1,1}),new LListNode({1})},
    Test{new LListNode(std::vector<int>{1,1,2,3}),new LListNode(std::vector<int>{1,2,3})},
    Test{new LListNode(std::vector<int>{1,1,2,3,3}),new LListNode(std::vector<int>{1,2,3})},
};

/**
 * Deletes duplicate within a Linked List
 * 
 * @param head: LListNode representing a Linked List
 * 
 * @return LListNode with removed duplicates
 */
LListNode* deleteDuplicates(LListNode* head) {
    // capture the null condition
    if (head == nullptr || !head->next) return head;
    
    // recursively call the function skipping the duplicates if found
    if (head->value == head->next->value) head =  deleteDuplicates(head->next);
    else head->next =  deleteDuplicates(head->next);
    
    return head;
}

int main(){
    std::cout << "--- Running Remove Duplicates from sorted Linked List Problem ---" << std::endl;
    
    int i = 1;
    for (auto test: TestCases) {
        std::cout << "Test " << i << std::endl;
        std::cout << "\tinput: ";
        test.head->print();
        std::cout << std::endl;
        std::cout << ", Expected Result: ";
        test.expectedResult->print();
        std::cout << "\n\tRESULT: ";
        test.head = deleteDuplicates(test.head);
        test.head->print();
        std::cout << "\n========================================================\n" << std::endl;
        i+=1;
    }
}