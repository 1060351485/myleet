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
        
        if( !l1 || !l2 ){
            return !l1 ? l2 : l1;
        }
        
        while( l1 && l2 ){a}
        
        if(l1){
            newTemp->next = l1;
        }
        if(l2){
            newTemp->next = l2;
        }
        return newHead->next;
    }
};