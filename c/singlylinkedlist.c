#include "stdio.h"

typedef struct {
    int val;
    struct ListNode* next;
} ListNode;

typedef struct {
    ListNode* head;
    int size;
} MyLinkedList;


MyLinkedList* myLinkedListCreate() {
    MyLinkedList* list = (MyLinkedList*) malloc(sizeof(MyLinkedList));
    list->head = NULL;
    list->size = 0;
    return list;
}

int myLinkedListGet(MyLinkedList* obj, int index) {
    if((index < 0) || (index >= obj->size)){
        return -1;
    }
    ListNode* curr = obj->head;
    for(int i = 0; i<index; i++)
    {
        curr = curr->next;
    }
    return curr->val;
}

void myLinkedListAddAtHead(MyLinkedList* obj, int val) {
    ListNode* new_node = (ListNode*) malloc(sizeof(ListNode));
    new_node->val = val;
    new_node->next = obj->head;
    obj->head = new_node;
    obj->size++;
}

void myLinkedListAddAtTail(MyLinkedList* obj, int val) {
    ListNode* new_node = (ListNode*) malloc(sizeof(ListNode));
    new_node->val = val;
    new_node->next = NULL;
    if (obj->head == NULL){
        obj->head = new_node;
    }
    else{
        ListNode* curr = obj->head;
        while(curr->next != NULL){
            curr = curr->next;
        }
        curr->next = new_node;
    }
    obj->size++;
}

void myLinkedListAddAtIndex(MyLinkedList* obj, int index, int val) {
    if((index > obj->size)){
        return;
    }
    if(index <= 0)
    {
        myLinkedListAddAtHead(obj, val);
        return;
    }
    ListNode* new_node = (ListNode*) malloc(sizeof(ListNode));
    new_node->val = val;
    ListNode* prev = obj->head;
    for(int i = 0; i < index -1; i++){
        prev = prev->next;
    }
    new_node->next = prev->next;
    prev->next = new_node;
    obj->size++;
}

void myLinkedListDeleteAtIndex(MyLinkedList* obj, int index) {
    if((index < 0) || (index >= obj->size)){
        return;
    }
    if(index == 0){
        ListNode* temp = obj->head;
        obj->head = temp->next;
        free(temp);
    }
    else{
        ListNode* prev = obj->head;
        for(int i =0; i < index-1; i++){
            prev=prev->next;
        }
        ListNode* temp = prev->next;
        prev->next = temp->next;
        free(temp);               
    }
    obj->size--;  
}

void myLinkedListFree(MyLinkedList* obj) {
    ListNode* curr = obj->head;
    while (curr != NULL){
        ListNode* temp = curr;
        curr = curr->next;
        free(temp);
    }
}

/**
 * Your MyLinkedList struct will be instantiated and called as such:
 * MyLinkedList* obj = myLinkedListCreate();
 * int param_1 = myLinkedListGet(obj, index);
 
 * myLinkedListAddAtHead(obj, val);
 
 * myLinkedListAddAtTail(obj, val);
 
 * myLinkedListAddAtIndex(obj, index, val);
 
 * myLinkedListDeleteAtIndex(obj, index);
 
 * myLinkedListFree(obj);
*/