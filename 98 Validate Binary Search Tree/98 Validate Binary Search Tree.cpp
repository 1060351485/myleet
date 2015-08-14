//
//  98 Validate Binary Search Tree.cpp
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
    
    //12 ms fast, but it's wrong, shouldn't rely on INT_MIN and INT_MAX
    bool isValidBST(TreeNode* root){
        if(!root) return true;
        return isValidBST(root, INT64_MIN, INT64_MAX);
    }
    
    bool isValidBST(TreeNode* root, long long min, long long max) { // long long to extend limits
        if(!root->left&&!root->right) return true;
        int leftmax = (root->val < max)?root->val: max;
        int rightmin = (root->val > min)?root->val: min;
        if(!root->left){
            // min = (root->val > min)?root->val: min;   
            if((root->right->val > rightmin)&&(root->right->val < max))
                return isValidBST(root->right, rightmin, max);
            else 
                return false;
        }
        if(!root->right){
            // max = (root->val < max)?root->val: max;
            if((root->left->val > min)&&(root->left->val < leftmax))
                return isValidBST(root->left, min, leftmax);
            else
                return false;
        }

        if((root->left->val < leftmax)&&(root->left->val > min)&&(root->right->val < max)&&(root->right->val > rightmin))
            return isValidBST(root->right, rightmin, max)&&isValidBST(root->left, min, leftmax);
        else
            return false;
    }

 	// use !root is shorter than previous method!!!!!!!!!, and it's also wrong
 	bool isValidBST(TreeNode* root){
        if(!root) return true;
        return isValidBST(root, INT64_MIN, INT64_MAX);
    }

    bool isValidBST(TreeNode* root, long long min, long long max) { // long long to extend limits
        if(!root) return true;
        if(root->val <= min || root->val >= max) return false;
        return isValidBST(root->left, min, root->val)&&isValidBST(root->right, root->val, max);
    }

	// good solution, use null instead of INT_MAX
    bool isValidBST(TreeNode* root) {
        return isValidBST(root, NULL, NULL);
    }
    bool isValidBST(TreeNode* root, TreeNode* minnode, TreeNode* maxnode) {
        if(!root) return true;
        if(minnode&&(minnode->val >= root->val) || maxnode&&(maxnode->val <= root->val))
            return false;
        return isValidBST(root->left, minnode, root)&&isValidBST(root->right, root, maxnode);
    }

    //If we use in-order traversal to serialize a binary search tree, we can get a list of values in ascending order.
    // It can be proved with the definition of BST. 
    //And here I use the reference of TreeNode pointer prev as a global variable to mark the address of previous node in the list.
    //“In-order Traversal”: https://en.wikipedia.org/wiki/Tree_traversal#In-order
    bool isValidBST(TreeNode* root) {
        TreeNode* prev = NULL;
        return isValidBST(root, prev);
    }
    bool isValidBST(TreeNode* root, TreeNode*& prev) {
        if(!root) return true;
        if(!isValidBST(root->left, prev)) return false;
        if((prev != NULL)&&(prev->val >= root->val)) return false;
        prev = root;
        return isValidBST(root->right, prev);
    }

};
