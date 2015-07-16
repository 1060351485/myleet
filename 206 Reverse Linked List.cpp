//
//  206 Reverse Linked List.cpp
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
        ListNode *persudo_head = NULL, *nextNode = NULL;
        while( head ){
            nextNode = head->next;
            head->next = persudo_head;
            persudo_head = head;
            head = nextNode;
        }
        return persudo_head;
    }
};