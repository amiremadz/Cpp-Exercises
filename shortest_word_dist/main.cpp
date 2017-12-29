/*
Given a list of words and two words word1 and word2, return the shortest distance 
between these two words in the list.

For example,
Assume that words = ["practice", "makes", "perfect", "coding", "makes"].

Given word1 = “coding”, word2 = “practice”, return 3.
Given word1 = "makes", word2 = "coding", return 1.

Note:
You may assume that word1 does not equal to word2, and word1 and word2 are both in the list.
*/

class Solution{
public:
	int shortestDistance1(vector<string>& words, string word1, string word2) {
		vector<int> idx1;
		vector<int> idx2;
		int dist = INT_MAX;
		int idx = -1;
		
		for(string word : words){
			++idx;
			if(word == word1){
				idx1.push_back(idx);
			}
			if(word == word2){
				idx2.push_back(idx);
			}
		}
		for(int i = 0; i < idx1.size(); ++i){
			for(int j = 0; j < idx2.size; ++j){
				dist = min(dist, abs(idx1[i] - idx2[j]));
			}
		}	
		return dist;
	}

	int shortestDistance2(vector<string>& words, string word1, string word2) {
		int idx1 = -1;
		int idx2 = -1;
		int dist = INT_MAX;
		int idx = -1;
		
		for(string word : words){
			++idx;
			if(word == word1){
				idx1 = idx;
				if(idx2 != -1){
					dist = min(dist, idx1 - idx2);
				}
			}
			if(word == word2){
				idx2 = idx;
				if(idx1 != -1){
					dist = min(dist, idx2 - idx1);
				}
			}
		}
		return dist;
	}
};