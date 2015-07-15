//
//  203 Remove Linked List Element-persudo head.cpp
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
        ListNode * persudo_head = new ListNode(0);
        persudo_head->next = head;
        ListNode * cur = persudo_head;
        while(cur){
            if( cur->next && (cur->next->val == val))
                cur->next = cur->next->next;
            else
                cur = cur->next;
        }
        return persudo_head->next;
    }
};