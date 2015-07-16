//
//  237 Delete Node in a Linked List-faster.cpp
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
    
    // leaking memory!!!!
    void deleteNode(ListNode* node) {
        node->val = node->next->val;
        node->next = node->next->next?node->next->next:NULL;
    }
    
    // leaking memory!!!!
    void deleteNode(ListNode* node) {
        *node = *(node->next);
    }
    
    
    // avoid leaking memory!!!!
    void deleteNode(ListNode* node) {
        ListNode* nextNode = node->next;
        *node = *nextNode;
        delete nextNode;
    }
};