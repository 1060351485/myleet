//
//  2 Add Two Numbers.cpp
//  
//
//  Created by Apple on 15/7/27.
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* preHead = new ListNode(0), *last = preHead;
        ListNode* temp1 = l1, *temp2 = l2;
        int carry = 0;
        while(l1||l2||carry){
            if(l1){
                temp1 = l1;
                l1 = l1->next;
            }else
                temp1->val = 0;
            if(l2){
                temp2 = l2;
                l2 = l2->next;
            }else
                temp2->val = 0;
            last->next = new ListNode((temp1->val + temp2->val + carry)%10);
            last = last->next;
            carry = (temp1->val + temp2->val + carry)/10;
        }
        return preHead->next;
    }
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* preHead = new ListNode(0), *last = preHead;
        ListNode* temp1 = l1, *temp2 = l2;
        int sum = 0;
        while(l1||l2){
            sum /= 10;
            if(l1){
                sum += l1->val;
                l1 = l1->next;
            }
            if(l2){
                sum += l2->val;
                l2 = l2->next;
            }
            last->next = new ListNode(sum%10);
            last = last->next;
        }
        if(sum/10){
            last->next = new ListNode(1);
        }
        return preHead->next;
    }
    
};