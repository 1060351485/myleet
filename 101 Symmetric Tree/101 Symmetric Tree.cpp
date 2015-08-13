//
//  101 Symmetric Tree.cpp
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
    
    // 4 ms
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        TreeNode* leftNode = root->left, *rightNode = root->right;
        stack<TreeNode*> ls, rs;
        while(leftNode||rightNode){ // more than one is not NULL
            if(!leftNode||!rightNode||(leftNode->val != rightNode->val)) // if one is NULL or left != equal
                return false;
            // traversal, !!!!! ||rightNode->left, if not, when leftNode->right == NULL, but rightNode->left!=NULL, ls and rs would be empty, and got WA
            if(leftNode->right||rightNode->left){
                ls.push(leftNode->right);
                rs.push(rightNode->left);
            }
            if(leftNode->left||rightNode->right){
                ls.push(leftNode->left);
                rs.push(rightNode->right);
            }
            if(!ls.empty()&&!rs.empty()){
                leftNode = ls.top();
                rightNode = rs.top();
                ls.pop();
                rs.pop();
            }else if(ls.empty()&&rs.empty()){
                return true;
            }else{
                return false;
            }
        }
        return true; // only has root
    }
    
    // another thought
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        TreeNode* leftNode = root->left, *rightNode = root->right;
        stack<TreeNode*> ls, rs;
        ls.push(leftNode);
        rs.push(rightNode);
        while(!ls.empty()&&!rs.empty()){
            leftNode = ls.top();
            rightNode = rs.top();
            ls.pop();
            rs.pop();
            if(!leftNode&&!rightNode) continue;
            if(!leftNode||!rightNode||(leftNode->val != rightNode->val)) return false;
            ls.push(leftNode->right);
            ls.push(leftNode->left);
            rs.push(rightNode->left);
            rs.push(rightNode->right);
        }
        return true; // only has root
    }
    
    // recursive 4ms
    bool isSymmetricHelper(TreeNode* node1, TreeNode* node2){
        if(!node1&&!node2) return true;
        if(!node1||!node2||(node1->val != node2->val))  return false;
        return isSymmetricHelper(node1->left, node2->right)&&isSymmetricHelper(node1->right, node2->left);
    }
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        return isSymmetricHelper(root->left, root->right);
    }
    };