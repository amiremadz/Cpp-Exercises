/*
Given a binary tree, determine if it is a valid binary search tree (BST).

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
Example 1:
    2
   / \
  1   3
Binary tree [2,1,3], return true.
Example 2:
    1
   / \
  2   3
  */


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
    bool isValidBST(TreeNode* root) {
        if(root == nullptr){
            return true;
        }
  		
  		return helper(root, LONG_MIN, LONG_MAX);        
    }

	bool helper(TreeNode *root, long min, long max){
        if(root == nullptr){
            return true;
        }
        
        if((root->val >= max) || (root->val <= min)){
            return false;
        }
        
        bool left  = helper(root->left, min, root->val);
        bool right = helper(root->right, root->val, max);
		
        return left && right;
    }
};