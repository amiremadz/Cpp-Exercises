/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */


class Solution{
public:
	void inorder(TreeNode *root){
		if(root == nullptr){
			return;
		}
		inorder(root->left);
		cout << root->value << endl;
		inorder(root->right);
	}

	void preorder(TreeNode *root){
		if(root == nullptr){
			return;
		}
		cout << root->value << endl;
		preorder(root->left);
		preorder(root->right);
	}

	void postorder(TreeNode *root){
		if(root == nullptr){
			return;
		}
		postorder(root->left);
		postoder(root->right);
		cout << root->value << endl;
	}
};