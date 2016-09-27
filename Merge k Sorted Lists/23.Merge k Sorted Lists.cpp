ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
   ListNode * newHead = new ListNode(0);
   ListNode * newTemp = newHead;
   while( l1 && l2  ){
      if (l1->val >= l2->val){
         newTemp->next = l2;
         l2 = l2->next;
      }else {
         newTemp->next = l1;
         l1 = l1->next;
      }
      newTemp = newTemp->next;
   }
   newTemp->next = l1?l1:l2;
   return newHead->next;
}

ListNode* helper(vector<ListNode*>& lists, int start, int end) {
   if (end == start)
    return nullptr;
   if (end-start == 1)
    return lists[start];
   ListNode* l1 = helper(lists, start, (end+start)/2);
   ListNode* l2 = helper(lists, (end+start)/2, end);
   return mergeTwoLists(l1, l2);
}

ListNode* mergeKLists(vector<ListNode*>& lists) {
   return helper(lists, 0, (int)lists.size());
}
