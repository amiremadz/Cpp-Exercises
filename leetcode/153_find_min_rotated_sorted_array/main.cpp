/*
153. Find Minimum in Rotated Sorted Array

Suppose an array sorted in ascending order is rotated at some pivot unknown to 
you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

Find the minimum element.

You may assume no duplicate exists in the array.
*/

#include <vector>
#include <iostream>
#include <climits>

using namespace std;

class Solution1 {
public:
    int findMin(vector<int>& nums) {
        int minval = INT_MAX;
        int left = 0;
        int right = nums.size() - 1;
        
        while(left <= right){
            int mid = (left + right) / 2;
            
            if(nums[left] <= nums[mid]){
                minval = min(minval, nums[left]);
                left = mid + 1;
            }            
            else{
                minval = min(minval, nums[mid]);
                right = mid - 1;
            }
        }        
               
        return minval;
    }
};

/*
In this problem, we have only three cases.

Case 1. The leftmost value is less than the rightmost value in the list: This 
means that the list is not rotated.
e.g> [1 2 3 4 5 6 7 ]

Case 2. The value in the middle of the list is greater than the leftmost and 
rightmost values in the list.
e.g> [ 4 5 6 7 0 1 2 3 ]

Case 3. The value in the middle of the list is less than the leftmost and rightmost 
values in the list.
e.g> [ 5 6 7 0 1 2 3 4 ]

As you see in the examples above, if we have case 1, we just return the leftmost 
value in the list. If we have case 2, we just move to the right side of the list. 
If we have case 3 we need to move to the left side of the list.
*/
class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        
        while(left < right){
            if(nums[left] < nums[right]){
                return nums[left];    
            }
            
            int mid = (left + right) / 2;
            
            if(nums[mid] >= nums[left]){
                left = mid + 1;
            }
            else{
                right = mid;
            }
        }        
               
        return nums[left];
    }
};

int main(){

    Solution sol;
    vector<int> arr = {2, 1};
    
    cout << sol.findMin(arr) << endl;

	return 0;
}
