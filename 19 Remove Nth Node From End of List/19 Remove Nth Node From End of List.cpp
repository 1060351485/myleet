//
//  19 Remove Nth Node From End of List.cpp
//  
//
//  Created by Apple on 15/6/27.
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int size = sizeList(head);
        if ( n == size ){
            if( size == 1 )
                return NULL;
            else
                return head->next;
        }
        ListNode *temp = head;
        for( int i = 0 ; i < size-n-1 ; i++ ){
            temp = temp->next;
        }
        temp->next = temp->next->next;
        return head;
    }
    
    int sizeList( ListNode * temp ){
        int sz = 1;
        while(1){
            if( temp->next ){
                temp = temp->next;
                sz++;
            }else
                return sz;
        }
    }
};