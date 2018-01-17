/*
Write a function that takes a string as input and returns the string reversed.

Example:
Given s = "hello", return "olleh".
*/

class Solution {
public:
    string reverseString(string s) {
        string result;
        string::iterator itt;
        for(itt = s.end() - 1; itt != s.begin() - 1; --itt){
            result.push_back(*itt);
        }
        return result;  
    }
};