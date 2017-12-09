/*
Given a List of words, return the words that can be typed 
using letters of alphabet on only one row's of American keyboard 
*/

class Solution {
public:
    bool belongs(string word, string row){
        for(char ch : word){
            if(row.find(ch) == string::npos){
                return false;
            }
        }
        return true;
    }
    
    bool check(string word){
        string row1 = "zxcvbnm";
        string row2 = "asdfghjkl";
        string row3 = "qwertyuiop";
        
        word = lower(word);
        
        if( belongs(word, row1) || belongs(word, row2) || belongs(word, row3) ){
            return true;
        }
        return false;
    }
        
    string lower(string s){
        for(int i = 0; i < s.size(); ++i){
            s[i] = tolower(s[i]);
        }
        return s;
    }
    
    vector<string> findWords(vector<string>& words) {
        
        vector<string> result;
        
        for(string item : words){
            if(check(item)){
                result.push_back(item);
            }
        }
        return result;
    }
};