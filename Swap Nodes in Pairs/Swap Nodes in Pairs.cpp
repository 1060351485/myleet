//
//  Swap Nodes in Pairs.cpp
//  
//
//  Created by Apple on 15/8/9.
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
    
    // 12ms
    ListNode* swapPairs(ListNode* head) {
        if(!head||!head->next) return head;
        ListNode* prehead = new ListNode(0);
        prehead->next = head->next;
        while(head&&head->next){
            ListNode* temp = head->next->next;
            head->next->next = head;
            if(temp&&temp->next)
                head->next = temp->next; // both exist, to temp->next
            else
                head->next = temp;  // !temp to NULL, temp&&!temp->next to temp
            head = temp;
        }
        return prehead->next;
    }
};