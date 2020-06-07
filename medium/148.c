/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* merge(struct ListNode* list1, struct ListNode* list2)
{
    if(!list1 && !list2)
        return NULL;
    if(!list1)
        return list2;
    if(!list2)
        return list1;
    
    struct ListNode* head = NULL;
    struct ListNode* p = NULL;
    
    if(list1->val < list2->val)
    {
        head = list1;
        list1 = list1->next;
    }
    else
    {
        head = list2;
        list2 = list2->next;
    }
    p = head;
    
    while(list1 && list2)
    {
        if(list1->val < list2->val)
        {
            p->next = list1;
            list1 = list1->next;
        }
        else
        {
            p->next = list2;
            list2 = list2->next;
        }
        p = p->next;
    }
    
    if(list1)
        p->next = list1;
    if(list2)
        p->next = list2;
    return head;
}

struct ListNode* sortList(struct ListNode* head){
    if(!head || !head->next)
        return head;
    
    struct ListNode* slow = head;
    struct ListNode* fast = head;
    struct ListNode* ptr = NULL;
    
    while(fast && fast->next)
    {
        ptr = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    ptr->next = NULL;
    
    return merge(sortList(head), sortList(slow));
}
