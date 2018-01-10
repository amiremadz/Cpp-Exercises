/*
Give a string s, count the number of non-empty (contiguous) substrings that have the same number of 0's and 1's, and all the 0's and all the 1's in these substrings are grouped consecutively.

Substrings that occur multiple times are counted the number of times they occur.

Example 1:
Input: "00110011"
Output: 6
Explanation: There are 6 substrings that have equal number of consecutive 1's and 0's: "0011", "01", "1100", "10", "0011", and "01".

Notice that some of these substrings repeat and are counted the number of times they occur.

Also, "00110011" is not a valid substring because all the 0's (and 1's) are not grouped together.
Example 2:
Input: "10101"
Output: 4
Explanation: There are 4 substrings: "10", "01", "10", "01" that have equal number of consecutive 1's and 0's.
*/

#include <iostream>
#include <vector>
#include <string>
#include <climits>
using namespace std;

class Solution1 {
public:
    int countBinarySubstrings(string s) {
        int result = 0;
        int idx = 0;
        vector<int> len;
        while(idx < (int)s.size()){
            int beg = idx;
            while(idx < (int)s.size() - 1 && s[idx] == s[idx+1]){
                ++idx;
            }
            len.push_back(idx - beg + 1);
            ++idx;
        }
        
        for(idx = 0; idx < (int)s.size(); ++idx){
            result += min(len[idx], len[idx+1]);
        }
        
        return result;
    }
};

class Solution {
public:
    int countBinarySubstrings(string s) {
        int result = 0;
        int idx = 0;
        int len_prev = 0;
        while(idx < (int)s.size()){
            int beg = idx;
            while(idx < (int)s.size() - 1 && s[idx] == s[idx + 1]){
                ++idx;
            }
            int len_curr = (idx - beg + 1);
            result += min(len_prev, len_curr);
            len_prev = len_curr;
            ++idx;
        }
        return result;
    }
};

int main(){

	string str1 = "00110011";
	string str2 = "10101";
	string str3 = "00110";

	Solution sol;

	cout << sol.countBinarySubstrings(str1) << endl;
	cout << sol.countBinarySubstrings(str2) << endl;
	cout << sol.countBinarySubstrings(str3) << endl;

	return 0;
}