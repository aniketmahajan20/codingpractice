#include <iostream>
#include <vector>

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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode prehead = ListNode(99);
        ListNode* prev = &prehead;
        while(l1 != NULL && l2 != NULL) {
            if (l1->val < l2->val){
                prev->next = l1;
                l1 = l1->next;
            }
            else{
                prev->next = l2;
                l2 = l2->next;
            }
            prev = prev->next;
        }
        prev->next = (l1 == NULL)?l2:l1;
        return prehead.next;
    }
};

class Solution_Recursion {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode prehead = ListNode(99);
        ListNode* prev = &prehead;
        merge_two_lists(l1,l2, prev);
        return prehead.next;
    }

    void merge_two_lists(ListNode* l1, ListNode* l2, ListNode* prev) {
        if (l1 == NULL) {
            prev->next = l2;
            return;
        }
        if (l2 == NULL) {
            prev->next =  l1;
            return;
        }
        if (l1->val < l2->val) {
            prev->next = l1;
            merge_two_lists(prev->next->next, l2, prev->next);
        }
        else {
            prev->next = l2;
            merge_two_lists(l1, prev->next->next, prev->next);
        }
    }
};

class Solution_Tail_Recursion {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode prehead = ListNode(99);
        ListNode* prev = &prehead;
        merge_two_lists(l1,l2, prev);
        return prehead.next;
    }

    void merge_two_lists(ListNode* l1, ListNode* l2, ListNode* prev) {
        if (l1 == NULL) {
            prev->next = l2;
            return;
        }
        if (l2 == NULL) {
            prev->next =  l1;
            return;
        }
        if (l1->val < l2->val) {
            prev->next = l1;
            l1 = l1->next;
        }
        else {
            prev->next = l2;
            l2 = l2->next;
        }
        merge_two_lists(l1, l2, prev->next);
    }
};