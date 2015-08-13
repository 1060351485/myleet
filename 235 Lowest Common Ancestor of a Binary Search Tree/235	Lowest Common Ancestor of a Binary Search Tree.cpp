//
//  235	Lowest Common Ancestor of a Binary Search Tree.cpp
//  
//
//  Created by Apple on 15/8/13.
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
    
    // 44ms
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        while(root){
            if((root->val > p->val)&&(root->val > q->val))
                root = root->left;
            else if((root->val < p->val)&&(root->val < q->val))
                root = root->right;
            else //if(((p->val <= root->val)&&(root->val <= q->val))||((q->val <= root->val)&&(root->val <= p->val)))
            return root;
        }
        return NULL;
    }
    
    //recur lower
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return NULL;
        if((root->val > p->val)&&(root->val > q->val))
            return lowestCommonAncestor(root->left, p ,q);
        else if((root->val < p->val)&&(root->val < q->val))
            return lowestCommonAncestor(root->right, p ,q);
        return root;
    }
};