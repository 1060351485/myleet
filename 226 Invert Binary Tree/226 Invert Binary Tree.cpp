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


//The above solution is correct, but it is also bound to the application stack, which means that it's no so much scalable - (you can find the problem size that will overflow the stack and crash your application), so more robust solution would be to use stack data structure.


class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(!root) return NULL;
        TreeNode* lc = root->left;
        root->left = invertTree(root->right);
        root->right =  invertTree(lc);
        return root;
    }
    
    TreeNode* invertTree(TreeNode* root) {
        if(!root) return NULL;
        invertTree(root->left);
        invertTree(root->right);
        swap(root->left, root->right);
        return root;
    }
};