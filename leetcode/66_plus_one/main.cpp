/*
Given a non-negative integer represented as a non-empty array of digits, 
plus one to the integer.

You may assume the integer do not contain any leading zero, except the 
number 0 itself.

The digits are stored such that the most significant digit is at the head 
of the list.
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution1 {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> result;
        vector<int>::iterator itt;
        
        int idx = digits.size() - 1;
        int carry = 1;
        int val = -1;
        
        while(idx >= 0){
            val = digits[idx] + carry;
            
            carry = val / 10;
            val %= 10;
            
            itt = result.begin();
            result.emplace(itt, val);
            --idx;                
        }
        
        if(carry){
            itt = result.begin();
            result.emplace(itt, carry);
        }
        
        return result;    
    }
};


class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        
        int idx = digits.size() - 1;
        int carry = 1;
        int val = -1;
        
        while(idx >= 0){
            val = digits[idx] + carry;
            
            carry = val / 10;
            val %= 10;
            
            digits[idx] = val;

            if(carry == 0){
                return digits;
            }
            --idx;                
        }
        
        if(carry){
            auto itt = digits.begin();
            digits.insert(itt, carry);
        }
        
        return digits;    
    }
};




int main(){
    vector<int> input;
    //input = {1, 0}; //{9}
    input = {9};

    vector<int> output;
    Solution sol;

    output = sol.plusOne(input); 
    
    for(int num : output){
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
