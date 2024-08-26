#include "../Utils/utils.h"
#include <math.h>

/**
 * Given the head of a linked list, rotate the list to the right by k places.
 * 
 * Constraints:
 *      * The number of nodes in the list is in the range [0, 500].
 *      * -100 <= Node.val <= 100
 *      * 0 <= k <= 2 * 109
 * 
 */

struct Test{
    LListNode* head;
    LListNode* expectedResult;
    int k;
    /**
     * Test Constructor
     * 
     * @param arr : vector of integers for the Linked List
     * @param rot : number of rotations to execute
     * @param res : vector of integers for the expected result Linked List 
     * 
     */
    Test(std::vector<int> arr, int rot, std::vector<int> res){
        head = new LListNode(arr);
        expectedResult = new LListNode(res);
        k = rot;
    }
};

/**
 * Test Cases for the Solution
 */
struct Test TestCases[] = {
    Test{{1,2,3,4,5}, 2, {4,5,1,2,3}},
    Test{{0,1,2}, 4, {2,0,1}},
    Test{{1,2,3}, 2000000000, {2,3,1}},
};

/**
 * Pushes the tail node to the head
 * 
 * @param v : vector of LListNodes
 * 
 * @return the adjusted vector
 * 
 */
std::vector<LListNode*> swap(std::vector<LListNode*> v){
    LListNode* tmp  = *(std::end(v)-1);
    v.insert(v.begin(), tmp);
    v.erase(std::end(v)-1);
    v.front()->next = v[1];
    v.back()->next = nullptr;
    return v;
}
/**
 * Rotates a linked list by a given amount
 *
 * @param head : Linked List 
 * @param k : number of times to rotate
 * 
 * @return rotated Linked List
 * 
 */
LListNode* rotateRight(LListNode* head, int k) {
    // constraints check
    if (!head || !head->next || !k) return head;
    if (head->value < -100 || head->value > 100) return head;
    long a = 2*(long)(std::pow(10,9)+1);
    if (k < 0 || (long)k > a) return head;
    
    // creating a vector to track the linked list nodes
    // this helps avoids traversing the linked list
    // more than once
    std::vector<LListNode*> v;
    
    LListNode* tmp = head;
    
    // loop until the end node, storing all the nodes
    // in a vector
    while (tmp){
        // constraints check
        if (tmp->value < -100 || tmp->value > 100) return head;
        v.push_back(tmp);
        
        // constraints check
        if (v.size() > 500) return head;
        
        tmp = tmp->next;
    }
    
    // using the modulo operator as eventually 
    // the rotation will be duplicated if the rotation
    // equals the number of elements in the Linked List
    // This ignores redundant rotations
    // Then we only rotate based on the number of reduced
    // iterations
    k = (long)k%(long)v.size();
    
    while (k) {
        // calling a helper function to rotate the tail
        // node to the head
        v = swap(v);
        k-=1;
    }
    
    return v.front();
}

int main() {
    std::cout << " --- Rotate List Leetcode Problem --- " << std::endl;
    for (int i=0; i<sizeof(TestCases)/sizeof(TestCases[0]);i++){
        Test test = TestCases[i];
        std::cout << "Test " << i+1 << std::endl;
        std::cout << "input: { linkedlist: ";
        test.head->print();
        std::cout << ", number of rotations: " << test.k;
        std::cout << ", expectedResult: ";
        test.expectedResult->print();
        std::cout << "}" << std::endl;
        LListNode* ans = rotateRight(test.head, test.k);
        std::cout << "\tActual Result: ";
        ans->print();
        std::cout << "\n=========================================================\n" << std::endl;
    }
    return 0;
}