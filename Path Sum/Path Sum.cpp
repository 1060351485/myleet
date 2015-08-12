//
//  Path Sum.cpp
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
    
    // these 2 methods are add from 0 to sum, so need tempSum to save temp sum
    // 12ms
    bool hasPathSum(TreeNode* root, int sum) {
        return hasPathSum(root, 0, sum);
    }
    
    bool hasPathSum(TreeNode* root, int tempSum, int sum) {
        if(!root) return false;
        if((!root->right)&&(!root->left))
            return tempSum+root->val == sum;
        if((root->left)&&(root->right))
            return hasPathSum(root->left, tempSum+root->val, sum)||hasPathSum(root->right, tempSum+root->val, sum);
        if(root->left) return hasPathSum(root->left, tempSum+root->val, sum);
        if(root->right) return hasPathSum(root->right, tempSum+root->val, sum);
    }
    
    //12ms
    bool hasPathSum(TreeNode* root, int sum) {
        if(!root) return false;
        return hasPathSum(root, 0, sum);
    }
    
    bool hasPathSum(TreeNode* root, int tempSum, int sum) {
        if(!root) return tempSum == sum;
//        if((!root->right)&&(!root->left))
//            return tempSum+root->val == sum;
        if(!root->left) return hasPathSum(root->right, tempSum+root->val, sum);
        if(!root->right) return hasPathSum(root->left, tempSum+root->val, sum);
        return hasPathSum(root->left, tempSum+root->val, sum)||hasPathSum(root->right, tempSum+root->val, sum);
    }
    
    //minus from sum to zero
    bool hasPathSum(TreeNode* root, int sum) {
        if(!root) return false;
        if(!root->left&&!root->right&&(sum-root->val == 0)) return true;
        return hasPathSum(root->left, sum-root->val)||hasPathSum(root->right, sum-root->val);
    }
};