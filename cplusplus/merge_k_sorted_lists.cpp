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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode prehead = ListNode(9999);
        ListNode* prev = & prehead;
        merge_k_lists(lists, prev);
        return prehead.next;
    }
    void merge_k_lists(vector<ListNode*>& lists, ListNode* prev){
        int null_size = 0;
        int minval = INT_MAX;
        int node_index;
        for (int i = 0; i < lists.size(); i++){
            if (lists[i] != NULL){
                if (minval > lists[i]->val){
                    minval = lists[i]->val;
                    node_index = i;
                }
            }
            else{
                null_size++;
            }
        }
        if (null_size == lists.size()){
            return;
        }
        else{
            prev->next = lists[node_index];
            lists[node_index] = lists[node_index]->next;
        }
        merge_k_lists(lists, prev->next);
    }
};