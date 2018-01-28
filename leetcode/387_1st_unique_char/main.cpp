/*
387. First Unique Character in a String

Given a string, find the first non-repeating character in it and return it's index. If it doesn't exist, return -1.

Examples:

s = "leetcode"
return 0.

s = "loveleetcode",
return 2.
*/

class Solution {
private:
    unordered_map<char, int> m_map;
public:
    int firstUniqChar(string s) {
        for(char ch : s){
            if(m_map.find(ch) == m_map.end()){
                m_map[ch] = 1;
            }
            else{
                ++m_map[ch];
            }
        }
        
        for(int idx = 0; idx < s.size(); ++idx){
            char ch = s[idx];
            if(m_map[ch] == 1){
                return idx;
            }
        }
        
        return -1;
    }
};

class Solution {
private:
    unordered_map<char, pair<int, int>> m_map;
public:
    int firstUniqChar(string s) {
        int result = s.size();
        
        for(int idx = 0; idx < s.size(); ++idx){
            char ch = s[idx];
            m_map[ch].first++;
            m_map[ch].second = idx;
        }
        
        for(auto item : m_map){
            if(item.second.first == 1){
                if(item.second.second < result){
                    result = item.second.second;
                }
            }
        }  
      
        return result == s.size() ? -1 : result;
    }
};