//
//  226 Invert Binary Tree.cpp
//  
//
//  Created by Apple on 15/7/17.
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
    TreeNode* invertTree(TreeNode* root) {
        if(!root) return NULL;
        TreeNode* lc = root->left;
        root->left = invertTree(root->right);
        root->right =  invertTree(lc);
        return root;
    }
};