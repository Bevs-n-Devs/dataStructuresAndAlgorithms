#include "../Utils/utils.h"
#include <set>
#include <math.h>

/**
 * Linked List Cycle
 * Given head, the head of a linked list, determine if the linked list has a cycle in it.
 * There is a cycle in a linked list if there is some node in the list that can be reached 
 * again by continuously following the next pointer. Internally, pos is used to denote the 
 * index of the node that tail's next pointer is connected to. Note that pos is not passed 
 * as a parameter.
 * 
 * Return true if there is a cycle in the linked list. Otherwise, return false.
 * 
 * Constraints:

 *      * The number of the nodes in the list is in the range [0, 104].
 *      * -105 <= Node.val <= 105
 *      * pos is -1 or a valid index in the linked-list.
 * 
 */


/**
 * Test Object
 */
struct Test{
    private:
        LList* llst;
    public:
    LListNode* head;
    int cyclePos;
    bool expectedReult;
    /**
     * Test Object Constructor
     * 
     * @param v : vector of integers for the singly linked list
     * @param pos : position where the cycle occurs
     * @param expectedResult : expected answer of if a cycle it found
     * 
     * */ 
    Test(std::vector<int> v, int pos, bool r){
        head = new LListNode(v);
        llst = new LList(head);
        cyclePos = pos;
        expectedReult = r;

        if (pos >= 0) {
            int i = 0;
            LListNode* tmp = head;
            while (i != pos) {
                tmp = tmp->next;
                i++;
            }
            llst->tail->next = tmp;
        }
    }

    /**
     * prints the linked list
     */
    void printLLst() {
        llst->printLLst();
    }
};

/**
 * Test Cases for the Solution
 */
Test TestCases[] = {
    Test{{3,2,0,-4}, 1, true},
    Test{{1,2},0,true},
    Test{{1},-1, false}
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
bool hasCycle(LListNode *head) {
    if (!head || !head->next) return false;
    std::set<LListNode*> s;
    int cnt = 0;
    while (head) {
        if (head->value < -1*std::pow(10,5) || head->value > std::pow(10,5)) return false;
        if (cnt>std::pow(10,4)) return false;
        head = head->next;
        if (s.find(head) == s.end()) s.insert(head);
        else return true;
        cnt++;
    }
        
    return false;
}

int main() {
    std::cout << " --- Running Linked List Cycle LeetCode Problem --- " << std::endl;
    for (int i=0; i< sizeof(TestCases)/sizeof(TestCases[0]);i++){
        Test test = TestCases[i];
        std::cout << "Test " << i+1 << std::endl;
        std::cout << "input: { linked list: ";
        test.printLLst();
        std::cout << ", cycle pos: " << test.cyclePos << ", expectedResult: " << std::boolalpha << test.expectedReult << " }" << std::endl;
        bool ans = hasCycle(test.head);
        std::cout << "\tActual Result: " << std::boolalpha << ans << std::endl;
        std::cout<< "\n===================================================================\n" << std::endl;
    }
    return 0;
}