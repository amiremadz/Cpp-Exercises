/*
215. Kth Largest Element in an Array

Find the kth largest element in an unsorted array. Note that it is the kth largest element in the sorted order, not the kth distinct element.
For example,
Given [3,2,1,5,6,4] and k = 2, return 5.

Note: 
You may assume k is always valid, 1 ≤ k ≤ array's length.
*/
class Solution {
private:
    class Comparator{
        public:
            bool operator() (const int &l, const int &r){
            return (l >= r);
        }    
    };
public:
    
    /*
     * use min heap: push the first k element in it.
     * compare the rest top its top. 
     * if bigger, pop top, and push element.
     */
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, Comparator> pq;
        
        for(int i = 0; i < k; ++i){
            pq.push(nums[i]);
        }
        
        for(int i = k; i < nums.size(); ++i){
            if(nums[i] >= pq.top()){
                pq.pop();
                pq.push(nums[i]);
            }
        }
        
        return pq.top();        
    }
};