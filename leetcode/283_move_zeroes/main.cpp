/*
iven an array nums, write a function to move all 0's to the end of it while maintaining 
the relative order of the non-zero elements.

For example, given nums = [0, 1, 0, 3, 12], after calling your function, nums should 
be [1, 3, 12, 0, 0].

Note:
You must do this in-place without making a copy of the array.
Minimize the total number of operations.
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
    	int idx = 0;
    	for(int num : nums){
    		if(num){
    			nums[idx] = num;
    			++idx;
    		}
    	}

    	for(int i = idx; i < (int)nums.size(); ++i){
    		nums[i] = 0;
    	}       
    }

    void print(vector<int> &nums){
    	for(int num : nums){
    		cout << num << " ";
    	}
    	cout << endl;
    }
};


int main(){
	vector<int> v = {0, 1, 0, 0, 3, 12};
	Solution sol;
	sol.moveZeroes(v);
	sol.print(v);
}