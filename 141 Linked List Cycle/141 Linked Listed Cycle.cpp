//
//  141. Linked Listed Cycle.cpp
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
    bool hasCycle(ListNode *head) {
        if(!head||!head->next) return false;
        ListNode* fast = head, *slow = head;
        while(fast->next&&fast->next->next){
            fast = fast->next->next;
            slow = slow->next;
            if(fast == slow)
                return true;
        }
        return false;
    }
};