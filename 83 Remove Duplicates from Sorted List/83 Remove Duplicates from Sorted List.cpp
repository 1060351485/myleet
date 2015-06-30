//
//  83 Remove Duplicates from Sorted List.cpp
//  
//
//  Created by Apple on 15/6/30.
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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode * temp = head;
        while( temp ){
            if( temp->next ){
                if( temp->val == temp->next->val )
                    temp->next = temp->next->next;
                else
                    temp = temp->next;
            }else
                break;
        }
        return head;
    }
};