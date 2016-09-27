//
//  21 Merge Two Sorted Lists.cpp
//  
//
//  Created by Apple on 15/6/29.
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode * newHead = new ListNode(0);
        ListNode * newTemp = newHead; //go from pred
        while( l1 && l2  ){
           if (l1->val <= l2->val) {
              newTemp->next = l1;
              l1 = l1->next;
           }else {
              newTemp->next = l2;
              l2 = l2->next;
           }
           newTemp = newTemp->next;
        }
        newTemp->next = l1?l1:l2;

        return newHead->next;
    }
};
