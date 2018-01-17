/*
 * Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.
Note:
You may assume that nums1 has enough space (size that is greater or equal to m + n) 
to hold additional elements from nums2. The number of elements initialized 
in nums1 and nums2 are m and n respectively.
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
        void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
            int idx1 = m - 1;
            int idx2 = n - 1;
            int size = m + n;
            int idx = size - 1;

            nums1.resize(size);

            while(idx1 > -1 && idx2 > -1){
                if(nums1[idx1] >= nums2[idx2]){
                    nums1[idx] = nums1[idx1];
                    --idx1;
                }
                else{
                    nums1[idx] = nums2[idx2];
                    --idx2;
                }
                --idx;
            }
            
            if(idx1 == -1){
                while(idx2 > -1){
                    nums1[idx] = nums2[idx2];
                    --idx2;
                    --idx;
                }
            }
        }

        vector<int> merge(vector<int>& nums1, vector<int>& nums2) {
            int m = nums1.size();
            int n = nums2.size();
            vector<int> result;

            int idx1 = 0;
            int idx2 = 0;

            while(idx1 < m && idx2 < n){
                if(nums1[idx1] <= nums2[idx2]){
                    result.push_back(nums1[idx1]);
                    ++idx1;
                }
                else{
                    result.push_back(nums2[idx2]);
                    ++idx2;
                }
            }

            if(idx1 == m){
                while(idx2 < n){
                    result.push_back(nums2[idx2]);
                    ++idx2;
                }
            }

            if(idx2 == n){
                while(idx1 < m){
                    result.push_back(nums1[idx1]);
                    ++idx1;
                }
            }

            return result;            
        }


        void print(const vector<int> &vec){
            for(int item : vec){
                cout << item << " " << flush;
            }
            cout << endl;
        }
};


int main(){

    vector<int> v1 = {3, 7, 12, 34, 66, 88, 122, 177};
    vector<int> v2 = {1, 8, 22, 32, 78, 99};
    vector<int> result;
    Solution mysol;
    
    mysol.print(v1);
    mysol.print(v2);
    cout << endl;

    mysol.merge(v1, v1.size(), v2, v2.size());
    mysol.print(v1);   
    cout << endl;

    v1 = {3, 7, 12, 34, 66, 88, 122, 177};
    
    result = mysol.merge(v1, v2);

    mysol.print(result);
    
    return 0;
}

