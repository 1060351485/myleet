//
//  Same Tree.cpp
//  
//
//  Created by Apple on 15/8/8.
//
//

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    
    //even find false, go through all branches
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // none
        if(!p&&!q) return true;
        //
        if(p&&q&&(p->val == q->val))
            return min(isSameTree(p->left, q->left), isSameTree(p->right, q->right));
        return false;
    }
    
    // find false, break
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // none
        if(!p&&!q) return true;
        //
        if(p&&q&&(p->val == q->val))
            return isSameTree(p->left, q->left)&&isSameTree(p->right, q->right);
        return false;
    }
    
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return (!p&&!q)||(p&&q&&(p->val == q->val))&&isSameTree(p->left, q->left)&&isSameTree(p->right, q->right);
    }
};