/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

typedef struct ListNode listNode;
struct ListNode* reverseList(struct ListNode* head){
    listNode *i = head;
    listNode *j = NULL;
    listNode *k = NULL;
    
    while(i)
    {
        j = i->next;
        i->next = k;
        k = i;
        i = j;
    }
    return k;
}
