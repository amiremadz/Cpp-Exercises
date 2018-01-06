/*
Given a word, you need to judge whether the usage of capitals in it is right or not.

We define the usage of capitals in a word to be right when one of the following cases holds:

All letters in this word are capitals, like "USA".
All letters in this word are not capitals, like "leetcode".
Only the first letter in this word is capital if it has more than one letter, like "Google".
Otherwise, we define that this word doesn't use capitals in a right way.
Example 1:
Input: "USA"
Output: True
Example 2:
Input: "FlaG"
Output: False
Note: The input will be a non-empty word consisting of uppercase and lowercase latin letters.
*/

class Solution {
public:
    bool detectCapitalUse(string word) {
        if(word.size() <= 1){
            return true;
        }
        
        bool first = isCapital(word[0]);
        
        if(first){
            bool second = isCapital((word[1]));
            if(second){
                int idx = 2;
                while(idx < word.size()){
                    if(!isCapital(word[idx])){
                        return false;
                    }
                    ++idx;
                }
            }
            else{
                int idx = 1;
                while(idx < word.size()){
                    if(isCapital(word[idx])){
                        return false;
                    }
                    ++idx;
                }
            }
        }
        else{
            int idx = 1;
            while(idx < word.size()){
                if(isCapital(word[idx])){
                    return false;
                }
                ++idx;
            }
        }
        return true;
    }

private:
    bool isCapital(char ch){
        return (ch >= 'A' && ch <= 'Z');
    }
};

