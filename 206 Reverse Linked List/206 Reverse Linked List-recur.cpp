//
//  206 Reverse Linked List-recur.cpp
//  
//
//  Created by Apple on 15/7/16.
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
    ListNode* reverseList(ListNode* head) {
        if(!head||!head->next) return head;
        ListNode* temp = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;  // circle
        return temp;
    }
};