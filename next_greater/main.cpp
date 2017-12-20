/*
You are given two arrays (without duplicates) nums1 and nums2 where nums1’s elements 
are subset of nums2. Find all the next greater numbers for nums1's elements in the 
corresponding places of nums2.

The Next Greater Number of a number x in nums1 is the first greater number to its 
right in nums2. If it does not exist, output -1 for this number.

Example 1:
Input: nums1 = [4,1,2], nums2 = [1,3,4,2].
Output: [-1,3,-1]
Explanation:
    For number 4 in the first array, you cannot find the next greater number for it in 
    the second array, so output -1.
    For number 1 in the first array, the next greater number for it in the second array is 3.
    For number 2 in the first array, there is no next greater number for it in the second 
    array, so output -1.
Example 2:
Input: nums1 = [2,4], nums2 = [1,2,3,4].
Output: [3,-1]
Explanation:
    For number 2 in the first array, the next greater number for it in the second array is 3.
    For number 4 in the first array, there is no next greater number for it in the second 
    array, so output -1.
Note:
All elements in nums1 and nums2 are unique.
The length of both nums1 and nums2 would not exceed 1000.
*/
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
private:
    int find_next1(int value, vector<int> &nums){
        for(int i = 0; i < (int)nums.size(); ++i){
            if(nums[i] == value){
                for(int j = i + 1; j < (int)nums.size(); ++j){
                    if(nums[j] > value){
                       return nums[j];
                    }
                }
            }
        }
        return -1;
    }
    
    int find_next2(int value, vector<int> &nums){
        unordered_map<int, int> value2idx;

        for(int i = 0; i < (int)nums.size(); ++i){
            value2idx[nums[i]] = i;
        }
        
        int idx = value2idx[value];

        for(int i = idx + 1; i < (int)nums.size(); ++i){
            if(nums[i] > value){
                return nums[i];
            }
        }
        return -1;
    }

public:
    vector<int> nextGreaterElement1(vector<int>& findNums, vector<int>& nums) {
        vector<int> result;
           
        for(int f : findNums){
            int next = find_next1(f, nums);
            result.push_back(next);
        }

        return result;        
    }
    vector<int> nextGreaterElement2(vector<int>& findNums, vector<int>& nums) {
        vector<int> result;
           
        for(int f : findNums){
            int next = find_next2(f, nums);
            result.push_back(next);
        }

        return result;        
    }

    void print(vector<int> vec){
        for(auto item : vec){
            cout << item << " " << flush;
        }
        cout << endl;
    }
};


int main(){
    Solution sol;
    vector<int> find1 = {4, 1, 2};
    vector<int> nums1 = {1, 3, 4, 2};
    vector<int> find2 = {2, 4};
    vector<int> nums2 = {1, 2, 3, 4};
    vector<int> result;

    result = sol.nextGreaterElement1(find1, nums1);
    sol.print(result);
    result = sol.nextGreaterElement2(find1, nums1);
    sol.print(result);

    cout << endl;

    result = sol.nextGreaterElement1(find2, nums2);
    sol.print(result);
    result = sol.nextGreaterElement2(find2, nums2);
    sol.print(result);

	return 0;
}
