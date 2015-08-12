//
//  142 Linked List Cycle II.cpp
//  
//
//  Created by Apple on 15/8/12.
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
    // Floyd hare totorise
    ListNode *detectCycle(ListNode *head) {
        if(!head||!head->next) return head;
        bool hasCycle = false;
        ListNode* fast = head, *slow = head;
        while(fast->next&&fast->next->next){
            fast = fast->next->next;
            slow = slow->next;
            if(fast == slow){
                hasCycle = true;
                break;
            }
        }
        if(hasCycle){
            slow = head;
            while(slow != fast){
                slow = slow->next;
                fast = fast->next;
            }
            return slow;
        }
        return NULL;
    }
    
    // slow but short, no advantages
    ListNode *detectCycle(ListNode *head) {
        ListNode *fast = head;
        ListNode *slow = head;
        ListNode *detect = head;
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == detect) return detect;
            if(slow == fast) detect = detect->next;
        }
        return NULL;
    }
};