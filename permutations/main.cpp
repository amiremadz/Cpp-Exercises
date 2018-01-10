/*
Given a collection of distinct numbers, return all possible permutations.

For example,
[1,2,3] have the following permutations:
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]
*/

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        
        if(nums.size() == 1){
            result.push_back(nums);
            return result;
        }
        
        for(int i = 0; i < nums.size(); ++i){
            vector<int> rest = nums;
            rest.erase(rest.begin() + i);
            
            vector<vector<int>> perms = permute(rest);
            for(auto perm : perms){
                vector<int>::iterator itt = perm.begin();
                perm.insert(itt, nums[i]);
                result.push_back(perm);
            }
        }
        
        return result;        
    }
};