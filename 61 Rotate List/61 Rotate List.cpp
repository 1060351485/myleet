//
//  Rotate List.cpp
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
    
    // 12ms mid
    // a  b  c  d  e  f  k=2
    // fast go until k==0
    // then newEnd go, if k>len,
    ListNode* rotateRight(ListNode* head, int k) {
        if((k == 0)||!head) return head;
        ListNode* fast = head, *newEnd = head;
        int lenCnt = 1;
        // fast and new end find the position to cut, fast.index-end.index = k, if fast comes to fin, end comes to new last
        while(k){
            if(fast->next){
                fast = fast->next;
                k--;
                lenCnt++;
            }else{
                k = (k-1)%lenCnt;
                if(k == 0) return head;  // k%len == 0, no need to rotate
                fast = head;
            }
        }
        while(fast->next){
            newEnd = newEnd->next;
            fast = fast->next;
        }
        ListNode* newHead = newEnd->next;
        newEnd->next = NULL;
        fast->next = head;
        return newHead;
    }
    
    // simple thought, connect the list into a cycle
    ListNode *rotateRight(ListNode *head, int k) {
        if (head == NULL || head->next == NULL || k == 0) return head;
        int len = 1;
        ListNode *tail = head;
        
        /* find the end of list */
        while (tail->next != NULL) {
            tail = tail->next;
            len++;
        }
        
        /* form a circle */
        tail->next = head;
        k = k % len;
        for (int i = 0; i < len - k; i++) {
            tail = tail->next;
        }
        head = tail->next;
        tail->next = NULL;
        return head;
    }
};