//
//  226 Invert Binary Tree-itear.cpp
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
        stack<TreeNode*> S;
        S.push(root);
        TreeNode* temp = root;
        while(!S.empty()){
            if((S.top()->left != temp)&&(S.top()->right != temp)){
                while(temp = S.top()){
                    if(temp->right) S.push(temp->right);
                    if(temp->left) S.push(temp->left);
                    if(temp == S.top()) break;
                }
            }
            temp = S.top();
            S.pop();
            swap(temp->left, temp->right);
        }
        return root;
    }
    
    TreeNode* invertTree(TreeNode* root) {
        if(!root) return NULL;
        stack<TreeNode*> S;
        S.push(root);
        TreeNode* temp = root;
        while(!S.empty()){
            temp = S.top();
            S.pop();
            swap(temp->left, temp->right);
            if(temp->right) S.push(temp->right);
            if(temp->left) S.push(temp->left);
        }
        return root;
    }
};