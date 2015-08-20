//
//  94 Binary Tree Inorder Trversal.cpp
//  
//
//  Created by Apple on 15/8/20.
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
    
    // recursive
    vector<int> v;
    vector<int> inorderTraversal(TreeNode* root) {
        if(!root) return v;
        inorderTraversal(root->left);
        v.push_back(root->val);
        inorderTraversal(root->right);
        return v;
    }
    
    
    // iterate, use stack
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> v;
        if(!root) return v;
        TreeNode* temp = root;
        stack<TreeNode*> s;
        while(true){
            while(temp){
                s.push(temp);
                temp = temp->left;
            }
            if(s.empty()) break;
            temp = s.top();
            s.pop();
            v.push_back(temp->val);
            temp = temp->right;
        }
        return v;
    }
    
    
    // iterate, morris traversal, without stack
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> v;
        if(!root) return v;
        TreeNode* temp = root, *prev;
        while(temp){
            if(!temp->left){
                v.push_back(temp->val);
                temp = temp->right;
            }else{
                prev = temp->left;
                while(prev->right&&(prev->right != temp))
                    prev = prev->right;
                if(!prev->right){
                    prev->right = temp;
                    temp = temp->left;
                }else{
                    v.push_back(temp->val);
                    prev->right = NULL;
                    temp = temp->right;
                }
            }
        }
    }
};