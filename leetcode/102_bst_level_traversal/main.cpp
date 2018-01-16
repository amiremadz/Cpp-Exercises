/*
Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its level order traversal as:
[
  [3],
  [9,20],
  [15,7]
]
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        queue<TreeNode *> myq;
        
        if(root == nullptr){
            return result;
        }
        
        myq.push(root);

        queue<TreeNode *> qlvl;
        vector<int> this_level;
            
        while(!myq.empty()){
        
            TreeNode *front = myq.front();
            this_level.push_back(front->val);

            if(front->left){
        		qlvl.push(front->left);
        	}
        	if(front->right){
        		qlvl.push(front->right);
        	}
            
        	myq.pop();
            
            if(myq.empty()){
                result.push_back(this_level);
                this_level.clear();
                
                while(!qlvl.empty()){
                    TreeNode *fr = qlvl.front();
                    myq.push(fr);
                    qlvl.pop();
                }
            }
        }

        return result;
    }
};