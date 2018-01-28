/*
33. Search in Rotated Sorted Array

Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

You are given a target value to search. If found in the array return its 
index, otherwise return -1.

You may assume no duplicate exists in the array.
*/

#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int len = nums.size();
        int left = 0;
        int right = len - 1;
        
        while(left <= right){
            int mid = (left + right) / 2;
        
            if(nums[mid] == target){
                return mid;
            }
            
            // left side is sorted
            if(nums[left] <= nums[mid]){
                if((target >= nums[left]) && (target <= nums[mid])){
                    right = mid - 1;
                }
                else{
                    left = mid + 1;
                }
            }
            else{
                if(target >= nums[mid] && (target <= nums[right])){
                    left = mid + 1;
                }
                else{
                    right = mid - 1;
                }
            }
        }
               
        return -1;
    }
};


int main(){
	vector<int> arr= {3, 4, 5, 6, 1, 2};
	int k = 2;
	Solution sol;

	cout << sol.search(arr, k) << endl;

	return 0;
}

