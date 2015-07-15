//
//  203 Remove Linked List Element-recursive,so slow.cpp
//  
//
//  Created by Apple on 15/7/15.
//
//

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if(!head) return NULL;
        head->next = removeElements(head->next,val);
        return head->val==val?head->next:head;
        
    }
};