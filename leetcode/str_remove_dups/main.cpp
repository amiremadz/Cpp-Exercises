/*
Remove duplicate characters in a given string keeping only 
the first occurrences. For example, if the input is ‘tree traversal’ 
the output will be ‘tre avsl’.
*/

class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> hash(128, 0);
        string result;
        
        for(char ch : s){
            ++hash[ch];
            if(hash[ch] == 1){
                result.push_back(ch);
            }
        }
        
        return result;
    }
};