//
//  Minimum Depth of Binary Tree.cpp
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
    
    // 12ms fast
    int minDepth(TreeNode* root) {
//        if(!root) return 0; // this line can be here
        return minDepth(root, 1, INT32_MAX);
    }
    
    int minDepth(TreeNode* root, int tempDep, int minDep) {
        // no root
        if(!root) return 0;
        // have root, and it's a leaf
        if((!root->left)&&(!root->right)){
            minDep = min(tempDep, minDep);
            return minDep;
        }
        // no leaf, either left or right exist, go to that side
        if(root->left) minDep = minDepth(root->left, tempDep+1, minDep);
        if(root->right) minDep = minDepth(root->right, tempDep+1, minDep);
        return minDep;
    }
    
    // 12ms
    int minDepth(TreeNode* root) {
        // no root
        if(!root) return 0;
        // have both left and right child, return min one
        if((root->left)&&(root->right)) return 1+min(minDepth(root->left),minDepth(root->right));
        //only have one side or this node is leaf
        if(root->left) return 1+minDepth(root->left);
        if(root->right) return 1+minDepth(root->right);
        // this node is leaf
        return 1;
    }
    
    // 12ms
    int minDepth(TreeNode* root) {
        // no root
        if(!root) return 0;
        // have one child?
        if(!root->left) return 1+minDepth(root->right);
        if(!root->right) return 1+minDepth(root->left);
        // have 2 child
        return 1+min(minDepth(root->left),minDepth(root->right));
    }
};