/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution1 {
public:
    int numOfLevels(TreeNode *root){
        if(root == nullptr){
            return 0;
        }
        int nl = numOfLevels(root->left);
        int nr = numOfLevels(root->right);
        
        if(nl > nr){
            return ( 1 + nl );
        }
        return (1 + nr);
    }
    
    void helper(TreeNode *root, int crnt, int level, double &sum, int &N){
        if(root == nullptr){
            return;
        }
      
        if(crnt == level){
            sum += root->val;
            ++N;
        }
        
        helper(root->left, crnt + 1, level, sum, N);
        helper(root->right, crnt + 1, level, sum, N);
    }
    
    vector<double> averageOfLevels(TreeNode* root) {
        int n_levels = numOfLevels(root);
        vector<double> result(n_levels, -5);
        for(int level = 0; level < n_levels; ++level){
            double sum = 0;
            int N = 0;
            helper(root, 0, level, sum, N);
            result[level] = sum / N;
        }
        
        return result;
    }
};

class Solution2 {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> sum;
        vector<int> count;
        vector<double> result;
        
        dfs(root, 0, sum, count);
        
        for(int i = 0; i < (int)sum.size(); ++i){
            result.push_back(sum[i] / count[i]);
        }
        
        return result;
    }
    
    void dfs(TreeNode *root, int level, vector<double> &sum, vector<int> &count){
        if(root == nullptr){
            return;
        }
                
        if(level < (int)sum.size()){
            sum[level] += root->val;
            count[level] += 1;    
        }
        else{        
            sum.push_back(root->val);
            count.push_back(1);
        }
        
        dfs(root->left, level + 1, sum, count);
        dfs(root->right, level + 1, sum, count);
    }
};

//bfs
class Solution4 {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> result;
        queue<TreeNode *> q;
        queue<TreeNode *> temp;
        int count = 0;
        double sum = 0;
        
        if(root == nullptr){
            return result;
        }
        
        q.push(root);
        
        while(!q.empty()){
            TreeNode *front = q.front();
            q.pop();
            
            sum += front->val;
            ++count;
                
            if(front->left){
                temp.push(front->left);
            }
            
            if(front->right){
                temp.push(front->right);
            }
            
            if(q.empty()){
                while(!temp.empty()){
                    q.push(temp.front());
                    temp.pop();
                }
                
                result.push_back(sum / count);
                sum = 0;
                count = 0;
            }
        }
        
        return result;
    }
};