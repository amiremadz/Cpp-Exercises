/*
Given a set of distinct integers, nums, return all possible subsets (the power set).

Note: The solution set must not contain duplicate subsets.

For example,
If nums = [1,2,3], a solution is:

[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Iterative {
public:
    vector<vector<int>> subsets_1(vector<int>& nums) {
        vector<vector<int>> subs(1, vector<int>());
        sort(nums.begin(), nums.end());
        
        for(int num : nums){
            int n = subs.size();
            for(int idx = 0; idx < n; ++idx){
                vector<int> new_sub = subs[idx];
                new_sub.push_back(num);
                subs.push_back(new_sub);        
            }
        }
              
        return subs;
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> subs(1, vector<int>());
        sort(nums.begin(), nums.end());
        
        for(int num : nums){
            int n = subs.size();
            for(int idx = 0; idx < n; ++idx){
                subs.push_back(subs[idx]);
                subs.back().push_back(num);
            }
        }
              
        return subs;
    }


    void print(vector<int> vec){
    	for(int x : vec){
    		cout << x << " " << flush;
    	}
    	cout << endl;
    }

    void print(vector<vector<int>> sets){
    	for(auto set : sets){
    		if(set.empty()){
    			cout << "[]" << endl;
    			continue;
    		}

    		for(int num : set){
    			cout << num << " " << flush;
    		}
    		cout << endl;
    	}
    	cout << endl;
    }
};

class Solution_bitmanip {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        const int num_subs = (1 << nums.size());
        vector<vector<int>> subs(num_subs, vector<int>());
        
        for(int idx_num = 0; idx_num < nums.size(); ++idx_num){
            for(int idx_sub = 0; idx_sub < num_subs; ++idx_sub){
                if ((idx_sub >> idx_num) & 1){
                    subs[idx_sub].push_back(nums[idx_num]);
                }
            }
        }
        
        return subs;
    }
};


class Solution_backtrack {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result(1, vector<int>());
        vector<int> sub;
        
        helper(nums, 0, sub, result);
        
        return result;        
    }
    
    void helper(vector<int> &nums, int idx, vector<int> sub, vector<vector<int>> &result){
        for(int i = idx; i < nums.size(); ++i){
            sub.push_back(nums[i]);
            result.push_back(sub);
            
            helper(nums, i + 1, sub, result);
            sub.pop_back();            
        }
    }
    
};

int main(){

	vector<int> vec = {1, 2, 3};
	vector<vector<int>> subsets;
	Iterative sol_itt; 

	subsets = sol_itt.subsets(vec);
	
	sol_itt.print(vec);
	cout << endl;
    sol_itt.print(subsets);

	return 0;
}
