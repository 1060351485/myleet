//
//  203 Remove Linked List Element.cpp
//  
//
//  Created by Apple on 15/7/14.
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
        
        //empty
        if(!head )
            return NULL;
        
        ListNode* temp = head;
        ListNode* furTemp = NULL;
        
        //if head'val, move head
        while( temp->val == val ){
            if(temp->next)
                temp = temp->next;
            else
                return NULL;
        }
        head = temp;
        if( temp->next )
            furTemp = temp->next;
        
        while(furTemp){
            if( furTemp->val != val ){
                temp->next = furTemp;
                temp = furTemp;
            }
            furTemp = furTemp->next;
        }
        temp->next = NULL;
        
        return head;
    }
};