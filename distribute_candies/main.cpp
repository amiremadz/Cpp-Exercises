/*
Given an integer array with even length, where different numbers in this array represent different 
kinds of candies. Each number means one candy of the corresponding kind. You need to distribute these 
candies equally in number to brother and sister. Return the maximum number of kinds of candies 
the sister could gain.

Example 1:
Input: candies = [1,1,2,2,3,3]
Output: 3
Explanation:
There are three different kinds of candies (1, 2 and 3), and two candies for each kind.
Optimal distribution: The sister has candies [1,2,3] and the brother has candies [1,2,3], too. 
The sister has three different kinds of candies. 
Example 2:
Input: candies = [1,1,2,3]
Output: 2
Explanation: For example, the sister has candies [2,3] and the brother has candies [1,1]. 
The sister has two different kinds of candies, the brother has only one kind of candies. 
Note:

The length of the given array is in range [2, 10,000], and will be even.
The number in given array is in range [-100,000, 100,000].
*/

#include <iostream>
#include <vector>
#include <bitset>

using namespace std;

class Solution {
public:
    int distributeCandies1(vector<int> &candies) {
        int result = 0;
        int length = candies.size();
        const int MAX = 100000;
        
        int sister[2 * MAX + 1]{0};

        for(int i = 0; i < length; ++i){
            int type = candies[i];
            int idx = type + MAX;
            if(!sister[idx]){
                sister[idx] = 1;
                ++result;
                if(result == length / 2){
                    break;
                }
            }
        }
        return result;
    }

    int distributeCandies2(vector<int> &candies) {
        int result = 0;
        int length = candies.size();
        const int MAX = 100000;

        bitset<2 * MAX + 1> sister;

        for(int type :  candies){
            int idx = type + MAX;
            if(!sister[idx]){
                sister.set(idx);
                ++result;
                if(result == length / 2){
                    break;
                }
            }
        }
        return result;
    }
};

int main(){

    vector<int> candies = {1, 1, 2, 2, 3, 3};
	Solution sol;


    cout << sol.distributeCandies1(candies) << endl;
    cout << sol.distributeCandies2(candies) << endl;
    
    candies.clear();
    candies = {1, 1, 2, 3};    

    cout << sol.distributeCandies1(candies) << endl;
    cout << sol.distributeCandies2(candies) << endl;

    return 0;
}
