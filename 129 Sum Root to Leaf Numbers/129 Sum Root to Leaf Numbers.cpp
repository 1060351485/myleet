//
//  129 Sum Root to Leaf Numbers.cpp
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

    // 4ms recursive
    int sumNumbers(TreeNode* root) {
        if(!root) return 0;
        return sumNumbers(root, root->val);
    }
    
    int sumNumbers(TreeNode* root, int sum){
        if(!root->left&&!root->right) return sum;
        if(!root->left) return sumNumbers(root->right, sum*10+root->right->val);
        if(!root->right) return sumNumbers(root->left, sum*10+root->left->val);
        return sumNumbers(root->left, sum*10+root->left->val) + sumNumbers(root->right, sum*10+root->right->val);
    }

    // 4ms recursive
    int sumNumbers(TreeNode* root) {
        return sumNumbers(root, 0);
    }
    
    int sumNumbers(TreeNode* root, int sum){
        if(!root) return 0;
        if(!root->left&&!root->right) return sum*10+root->val;
        return sumNumbers(root->left, sum*10+root->val) + sumNumbers(root->right, sum*10+root->val);
    }

};