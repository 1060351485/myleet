//
//  Binary Tree Postrder Traversal.cpp
//  
//
//  Created by Apple on 15/8/22.
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
    
    vector<int> v;
    vector<int> postorderTraversal(TreeNode* root) {
        if(!root)
            if(root->left) postorderTraversal(root->left);
        if(root->right) postorderTraversal(root->right);
        v.push_back(root->val);
    }
    
    
};