/*
Problem Description:

You are playing the following Flip Game with your friend: Given a string 
that contains only these two characters: + and -, you and your friend take turns 
to flip two consecutive "++" into "--". The game ends when a person can no longer 
make a move and therefore the other person will be the winner.

Write a function to compute all possible states of the string after one valid move.

For example, given s = "++++", after one move, it may become one of the following states:

[
  "--++",
  "+--+",
  "++--"
]
 

If there is no valid move, return an empty list [].
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
        vector<string> generatePossibleNextMoves1(string s) {
            vector<string> result;
            for(int i = 0; i <= (int)s.size() - 2; ++i){
                if(s[i] == '+' && s[i + 1] == '+'){
                    string flipped;
                    for(int j = 0; j < i; ++j){
                        flipped.push_back(s[j]);
                    }
                    flipped += "--";
                    for(int j = i + 2; j < (int)s.size(); ++j){
                        flipped.push_back(s[j]);
                    }
                    result.push_back(flipped);
                }
            }
            return result;
        }

        vector<string> generatePossibleNextMoves2(string s) {
            vector<string> result;
            for(int i = 0; i <= (int)s.size() - 2; ++i){
                if(s[i] == '+' && s[i + 1] == '+'){
                    s[i] = '-';
                    s[i + 1] = '-';
                    result.push_back(s);
                    s[i] = '+';
                    s[i + 1] = '+';
                }
            }
            return result;
        }
};

int main(){
    Solution sol;
    vector<string> result = sol.generatePossibleNextMoves1("++++");
    for(string item : result){
        cout << item << endl;
    }
    cout << endl;
    result = sol.generatePossibleNextMoves2("++++");
    for(string item : result){
        cout << item << endl;
    }


    return 0;
}

