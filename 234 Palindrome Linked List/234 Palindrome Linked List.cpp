//
//  234 Palindrome Linked List.cpp
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
    ListNode* reverseList( ListNode* head ){
        ListNode *persudo_head = NULL, *nextNode = NULL;
        while( head ){
            nextNode = head->next;
            head->next = persudo_head;
            persudo_head = head;
            head = nextNode;
        }
        return persudo_head;
    }
    
    bool isPalindrome(ListNode* head) {
        if(!head) return true;
        ListNode* midNode = head;
        ListNode* lastNode = head;
        // find mid
        while( lastNode ){
            if(lastNode->next){
                lastNode = lastNode->next;
                if( lastNode->next )
                    lastNode = lastNode->next;
                else
                    break;
            }else
                break;
            midNode = midNode->next;
        }
        
        ListNode* newHead = reverseList(midNode);
        ListNode* temp = head;
        while( temp ){
            if( temp->val != newHead->val )
                return false;
            temp = temp->next;
            newHead = newHead->next;
        }
        return true;
        
    }
};