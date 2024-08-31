#include <iostream>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* sum_root = new ListNode();
        bool carry = false;
        int sum = l1->val + l2->val;
        if (sum > 9){
            carry = true;
            sum_root->val = sum - 10;
        }
        else{
            sum_root->val = sum;
        }
        ListNode* prev = sum_root;
        while (l1->next != NULL || l2->next != NULL) {
            if (l1->next != NULL){
                l1 = l1->next;
            }
            else{
                l1->val = 0;
            }
            if (l2->next != NULL){
                l2 = l2->next;
            }
            else{
                l2->val = 0;
            }
            ListNode* curr = new ListNode();
            prev->next = curr;
            if (carry)
            {
                sum = l1->val + l2->val + 1;
            }
            else{
                sum = l1->val + l2->val;
            }
            if (sum > 9){
                carry = true;
                curr->val = sum - 10;
            }
            else{
                curr->val = sum;
                carry = false;
            }
            prev = curr;
        }
        if (carry){
            ListNode* curr = new ListNode(1);
            prev->next = curr;
        }
        return sum_root;
    }
};