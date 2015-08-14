//
//  114 Flatten Binary Tree to Linked List.cpp
//  
//
//  Created by Apple on 15/8/14.
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
	// 8ms fast, O(n) space
    void flatten(TreeNode* root) {
        if(!root) return;
        TreeNode* prehead = new TreeNode(0);
        stack<TreeNode*> s;
        s.push(root);
        TreeNode *pre = prehead, *temp;
        while(!s.empty()){
            temp = s.top();
            s.pop();
            pre->right = temp;
            pre->left = NULL;
            pre = temp;
            if(temp->right) s.push(temp->right);
            if(temp->left) s.push(temp->left);
        }
        pre->right = NULL;
        pre->left = NULL;
        prehead->right = NULL;
    }

    // better solution, better than mine, also need to change correct exsist list,
    // draw a pic may have a better learn, it's beautiful
    // O(1) space
    void flatten(TreeNode* root) {
        TreeNode* temp = root;
        while(temp){
            if(temp->left){
                TreeNode* mid = temp->left;
                while(mid->right)
                    mid = mid->right;
                mid->right = temp->right;
                temp->right = temp->left;
                temp->left = NULL;
            }
            temp = temp->right;
        }
    }

    // recursive
    TreeNode * prev = NULL;
    void flatten(TreeNode* root) {
        if(!root) return;
        flatten(root->right);
        flatten(root->left);
        root->right = prev;
        root->left = NULL;
        prev = root;
    }
};