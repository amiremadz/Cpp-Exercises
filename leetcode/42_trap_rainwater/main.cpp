/*
42. Trapping Rain Water

Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.

For example, 
Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.
*/

class Solution {
public:
    int trap(vector<int>& height) {
        int result = 0;
        int len = height.size();
        
        if(len <= 2){
            return result;
        }
        
        vector<int> left(len, -1);
        vector<int> right(len, -1);
        
        int max = height[0];
        
        for(int idx = 1; idx < len; ++idx){
            if(height[idx] > max){
                max = height[idx];
            }
            left[idx] = max;
        }
        
        max = height[len - 1];
        
        for(int idx = len - 2; idx >= 0; --idx){
            if(height[idx] > max){
                max = height[idx];
            }
            right[idx] = max;
        }
        
        for(int idx = 0; idx < len; ++idx){
            int cap = min(left[idx], right[idx]) - height[idx];
            if(cap > 0){
                result += cap;
            }
        }
        
        return result;
    }
};

/* instead of calculating area by height*width, we can think it in a cumulative way. 
In other words, sum water amount of each bin(width=1).
Search from left to right and maintain a max height of left and right separately, 
which is like a one-side wall of partial container. Fix the higher one and flow water 
from the lower part. For example, if current height of left is lower, we fill water in 
the left bin. Until left meets right, we filled the whole container.
*/
class Solution {
public:
    int trap(vector<int>& height) {
        int result = 0;
        
        int left = 0;
        int right = height.size() - 1;
        
        int max_left  = 0;
        int max_right = 0;
        
        while(left <= right){
            if(height[left] <= height[right]){
                if(height[left] < max_left){
                    result += (max_left - height[left]);
                }
                else{
                     max_left = height[left];    
                }                
                ++left;
            }
            else{
                if(height[right] < max_right){
                    result += (max_right - height[right]);
                }
                else{
                    max_right = height[right];
                }
                --right;
            }            
        }
        
        return result;
    }
};
























