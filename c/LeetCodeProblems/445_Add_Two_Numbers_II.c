/**
 * 445. Add Two Numbers II
 * (Medium)
 * 
 * You are given two non-empty linked lists representing two 
 * non-negative integers. The most significant digit comes 
 * first and each of their nodes contains a single digit. Add 
 * the two numbers and return the sum as a linked list.
 * 
 * You may assume the two numbers do not contain any leading 
 * zero, except the number 0 itself.
 * 
 * Example 1:
 * Input: l1 = [7,2,4,3], l2 = [5,6,4]
 * Output: [7,8,0,7]
 * 
 * Example 2:
 * Input: l1 = [2,4,3], l2 = [5,6,4]
 * Output: [8,0,7]
 * 
 * Example 3:
 * Input: l1 = [0], l2 = [0]
 * Output: [0]
 * 
 * Constraints:
 *      * The number of nodes in each linked list is in the range [1, 100].
 *      * 0 <= Node.val <= 9
 * 
 *  It is guaranteed that the list represents a number that does not have 
 *  leading zeros.
 */

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>

#define nullptr ((void*)0)

/**
 * ListNode for Singly Linked List
 */
struct ListNode {
    int val;
    struct ListNode* next;
};

/**
 * Helper Function to print the linked list
 * 
 * @param head : ListNode head for linked list
 * 
 */
void printLL(struct ListNode* head){
    
    struct ListNode* next = head;
    while (next){
        printf("%d->", next->val);
        next = next->next;
    }

    printf("NULL");
}

/**
 * Allocates memory for a ListNode
 * 
 * @param val: value to store in the ListNode
 * 
 * @return New ListNode
 */
struct ListNode* createListNode(int val){
    struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
    node->val = val;
    node->next = nullptr;
    return node;
}

typedef struct Stack{
    struct ListNode* top;
    int height;
    int capacity;
}Stack;

Stack* createStack(int capacity){
    Stack* s = (Stack*)malloc(sizeof(Stack));
    if (!s) {
        printf("Failed to allocated memory\n");
        return nullptr;
    }

    s->top = nullptr;
    s->height = 0;
    s->capacity = capacity;
    return s;
}

bool empty(Stack* stack){
    return !stack->height;
}

bool push(Stack* stack, int val){
    if (stack->height == stack->capacity) return false;
    
    struct ListNode* node = createListNode(val);
    if (!node){
        printf("Failed to allocate memory\n");
        return false;
    }

    if (!empty(stack)) node->next = stack->top;
    
    stack->top = node;
    stack->height+=1;
    return true;
}

int pop(Stack* stack){
    if (empty(stack)) return INT_MIN;

    int v = stack->top->val;
    struct ListNode* n = stack->top;
    stack->top = n->next;
    free(n);
    stack->height-=1;
    return v;
}

/**
 * Test object to store testcase values
 */
typedef struct TestCase{
    struct ListNode *l1;
    struct ListNode *l2;
    struct ListNode *expectedResult;
}TestCase;

/**
 * Creates LinkedList for Test Cases
 * 
 * @param arr : arr of int values
 * @param N : array size
 * 
 * @return head of new LinkedList
 */
struct ListNode* createLinkedList(int* arr, int N){
    struct ListNode* head = createListNode(arr[0]);
    struct ListNode* tmp = head;
    for (int i=1;i<N;i++){
        tmp->next = createListNode(arr[i]);
        tmp = tmp->next;
    }

    return head;
}

/**
 * Creates Test Case
 * 
 * @param arr1: array1 of integers to store in linked lists
 * @param N1: length of array1
 * @param arr2: array2 of integers to store in linked lists
 * @param N2: length of array2
 * @param arr3: array3 of integers to store in linked lists
 * @param N3: length of array3
 * 
 * @return Test Case data structure
 */
TestCase* createTestCase(int* arr1, int N1, int* arr2, int N2,int* arr3, int N3){
    TestCase* tc = (TestCase*)malloc(sizeof(TestCase));
    tc->l1 = createLinkedList(arr1, N1);
    tc->l2 = createLinkedList(arr2, N2);
    tc->expectedResult = createLinkedList(arr3, N3);

    return tc;
}

/**
 * Validates if two Linked lists are the same
 * 
 * @param: first linked list to compare
 * @param: second linked list to compare
 * 
 * @return true or false if the lists have identical values 
 */
bool actualEqExpected(struct ListNode* l1, struct ListNode* l2){
    if (!l1 && !l2) return true;
    if (!l1 || !l2) return false;

    while (l1&&l2){
        if (l1->val != l2->val) return false;
        l1 = l1->next;
        l2 = l2->next;
    }

    if (l1 || l2) return false;

    return true;
}

/**
 * Reverses a Linked List
 * 
 * @param node: head of LinkedList
 * 
 * @return head of reversed Linked List
 */
struct ListNode* reverseLL(struct ListNode *node){
    struct ListNode* prev = nullptr;
    struct ListNode* curr = node;
    struct ListNode* next = node->next;
    int cnt = 0;

    while (next){
        // constraints check
        if (curr->val < 0 | curr->val > 9) return nullptr;
        curr->next = prev;
        prev = curr;
        curr = next;
        next = curr->next;
        cnt+=1;

        //constraints check
        if (cnt >100) return nullptr;
    }
    
    curr->next = prev;

    return curr;
}



/**
 * Adds two numbers represented as two Linked Lists
 * 
 * @param l1 : first value to add
 * @param l2 : second value to add
 * 
 * @return linked list representing the result
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    // base case catches
    if (!l1 & !l2) return nullptr;
    if (!l1) return l2;
    if (!l2) return l1;

    // using reversal method 
    l1 = reverseLL(l1);
    l2 = reverseLL(l2);

    // if the reversal catches a constraints 
    // violation, return nullptr
    if (!l1 || !l2) return nullptr;

    // create ListNode Holders to track sums
    struct ListNode* l3;
    struct ListNode* prev = nullptr;
    // bool to track sum carry over
    bool car = false;

    // loop through reverse lists adding each
    // set of values
    while(l1 || l2){
        l3 = createListNode(-1);
        l3->next = prev;
        if (l1 && l2){
            l3->val = (l2->val+l1->val + car)%10;
            car = (l2->val+l1->val + car)/10;
        } else if (!l1) {
            l3->val = (l2->val+car)%10;
            car = (l2->val + car)/10;
        } else {
            l3->val = (l1->val+car)%10;
            car = (l1->val + car)/10;
        }

        prev=l3;
        if(l1) l1 = l1->next;
        if(l2) l2 = l2->next;
    }

    // final carry check
    if (car) {
        prev = l3;
        l3 = createListNode(1);
        l3->next = prev;
    }

    return l3;
}

/**
 * Adds two numbers represented as two Linked Lists
 * (Stack approach)
 * 
 * @param l1 : first value to add
 * @param l2 : second value to add
 * 
 * @return linked list representing the result
 */
struct ListNode* addTwoNumbers_stack(struct ListNode* l1, struct ListNode* l2) {
    if (!l1 & !l2) return nullptr;
    if (!l1) return l2;
    if (!l2) return l1;

    bool carry = false;
    struct ListNode* l3 = nullptr; 
    struct ListNode* prev = nullptr; 
    Stack* s1 = createStack(100);
    Stack* s2 = createStack(100);
    while (l1){
        if(!push(s1,l1->val)) return false;
        l1 = l1->next;
    }
    while (l2){
        if(!push(s2,l2->val)) return false;
        l2 = l2->next;
    }
    
    while (!empty(s1) || !empty(s2)){
        l3 = createListNode(-1);
        l3->next = prev;
        if (!empty(s1) && !empty(s2)) l3->val = pop(s1) + pop(s2) + carry;
        else if (empty(s1)) l3->val = pop(s2) + carry;
        else l3->val = pop(s1) + carry;

        carry = l3->val / 10;
        l3->val%=10;
        prev = l3;
    }

    if (carry) {
        l3 = createListNode(carry);
        l3->next = prev;
    }
    return l3;
}

int main(int argc, char** kwargs){
    int l1_0[] = {7,2,4,3};
    int l2_0[] = {5,6,4};
    int l3_0[] = {7,8,0,7};

    int l1_1[] = {2,4,3};
    int l2_1[] = {5,6,4};
    int l3_1[] = {8,0,7};
    
    int l1_2[] = {0};
    int l2_2[] = {0};
    int l3_2[] = {0};
    TestCase *TestCases_0 = createTestCase(l1_0,4,l2_0,3,l3_0,4);
    TestCase *TestCases_1 = createTestCase(l1_1,3,l2_1,3,l3_1,3);
    TestCase *TestCases_2 = createTestCase(l1_2,1,l2_2,1,l3_2,1);
    TestCase *TestCases[3] = {
        TestCases_0,    
        TestCases_1,
        TestCases_2,
    }; 
    
    TestCase *tc;
    for (int i=0; i < sizeof(TestCases)/sizeof(TestCases[0]);i++){
        tc = TestCases[i];
        printf("--- Test Case %d---\n", i+1);
        printf("Input: {l1: ");
        printLL(tc->l1);
        printf(", l2: ");
        printLL(tc->l2);
        printf(", expectedResult: ");
        printLL(tc->expectedResult);
        printf("}\n");

        struct ListNode* ans = addTwoNumbers(tc->l1, tc->l2);
        printf("Actual Result: ");
        printLL(ans);
        printf("\n");
        assert(actualEqExpected(tc->expectedResult, ans));
    }
    return 0;
}