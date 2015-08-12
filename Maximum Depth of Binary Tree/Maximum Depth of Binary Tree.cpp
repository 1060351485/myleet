//
//  Maximum Depth of Binary Tree.cpp
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
    
    
    // 8ms
    int maxDepth(TreeNode* root) {
        return maxDepth(root, 1, 0);
    }
    
    int maxDepth(TreeNode* root, int tempDep, int maxDep) {
        if(!root){
            maxDep = max(tempDep-1, maxDep);
            return maxDep;
        }
        maxDep = maxDepth(root->left, tempDep+1, maxDep);
        maxDep = maxDepth(root->right, tempDep+1, maxDep);
        return maxDep;
    }
    
    
    // 8ms
    int maxDepth(TreeNode* root) {
        return root?1+max(maxDepth(root->left),maxDepth(root->right)):0;
    }
};