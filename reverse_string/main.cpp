/*
Given a string, you need to reverse the order of characters 
in each word within a sentence while still preserving 
whitespace and initial word order.
*/

class Solution {
public:
    string reverse(string s){
        int l = 0;
        int r = s.size() - 1;
        while(l < r){
            char temp = s[l];
            s[l] = s[r];
            s[r] = temp;
            l++;
            r--;
        }
        return s;
    }
    
    string reverseWords(string s) {
        string word;
        string rev;
        string result;
        
        for(char ch : s){
            if(ch != ' '){
                word.push_back(ch);
            }
            else{
                rev = reverse(word);
                result.append(rev);
                result.push_back(' ');
                word.clear();
            } 
        } 
        rev = reverse(word);
        result.append(rev);
        return result;
    }
};