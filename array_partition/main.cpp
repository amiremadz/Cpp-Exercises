/*
Given an array of 2n integers, your task is to group these 
integers into n pairs of integer, say (a1, b1), (a2, b2), ..., (an, bn) 
which makes sum of min(ai, bi) for all i from 1 to n as large as possible.
*/

class Solution {
static bool func(int &l, int &r) { return (l < r); }    
public:
    // O(nlog n): sort
    int arrayPairSum(vector<int>& nums) {
        int sum = 0;
        sort(nums.begin(), nums.end(), Solution::func);
        for(int i = 0; i < nums.size(); ++i){
            if(!(i % 2)){
                sum += nums[i];
            }
        }
        return sum;
    }

    // O(n): hash
    int arrayPairSum(vector<int>& nums) {
        const int MAX = 10000;
        const int size_hash = 2 * MAX + 1;
        int hash[size_hash]{0};
        int size_nums = nums.size();
        
        int sum = 0;
        //int counter = 0;
        bool flag = false;
        
        for(int item : nums){
            int idx = item + MAX;
            ++hash[idx];
        }
        
        for(int idx = 0; idx < size_hash; ++idx){
            while(hash[idx]){
                //++counter;
                flag = !flag;
                --hash[idx];
                //if(counter % 2){
                if(flag){    
                    int value = idx - MAX;
                    sum += value;
                }
            }
        }
        return sum;
    }
};