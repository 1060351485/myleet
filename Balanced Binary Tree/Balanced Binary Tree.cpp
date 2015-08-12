//
//  Balanced Binary Tree.cpp
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
    
    // 16ms
    bool isBalanced(TreeNode* root) {
        if(!root) return true;
        // either one is ok
        if(root->left||root->right)
            // left node balanced and right node balanced,and root is balanced
            return isBalanced(root->left)&&isBalanced(root->right)&&(abs(getHeight(root->left) - getHeight(root->right)) <= 1)?true:false;
        return true;
    }
    
    int getHeight(TreeNode* root){
        return root?1+max(getHeight(root->left), getHeight(root->right)):0;
    }
    
    // 12ms use root->val to save height
    bool isBalanced(TreeNode* root) {
        if(!root) return true;
        if(root->left&&root->right){
            if(isBalanced(root->left)&&isBalanced(root->right)){
                root->val = 1+max(root->left->val, root->right->val);
                return (abs(root->left->val-root->right->val)<=1);
            }else return false;
        }
        if(root->left){
            if(isBalanced(root->left)){
                root->val = root->left->val+1;
                return (root->left->val <= 1);
            }else return false;
        }
        if(root->right){
            if(isBalanced(root->right)){
                root->val = root->right->val+1;
                return (root->right->val <= 1);
            }else return false;
        }
        root->val = 1;
        return 1;
    }
};