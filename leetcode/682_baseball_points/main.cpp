/*
You're now a baseball game point recorder.

Given a list of strings, each string can be one of the 4 following types:

Integer (one round's score): Directly represents the number of points you get in this round.
"+" (one round's score): Represents that the points you get in this round are the sum of the last two valid round's points.
"D" (one round's score): Represents that the points you get in this round are the doubled data of the last valid round's points.
"C" (an operation, which isn't a round's score): Represents the last valid round's points you get were invalid and should be removed.
Each round's operation is permanent and could have an impact on the round before and the round after.

You need to return the sum of the points you could get in all the rounds.

Example 1:
Input: ["5","2","C","D","+"]
Output: 30
Explanation: 
Round 1: You could get 5 points. The sum is: 5.
Round 2: You could get 2 points. The sum is: 7.
Operation 1: The round 2's data was invalid. The sum is: 5.  
Round 3: You could get 10 points (the round 2's data has been removed). The sum is: 15.
Round 4: You could get 5 + 10 = 15 points. The sum is: 30.
Example 2:
Input: ["5","-2","4","C","D","9","+","+"]
Output: 27
Explanation: 
Round 1: You could get 5 points. The sum is: 5.
Round 2: You could get -2 points. The sum is: 3.
Round 3: You could get 4 points. The sum is: 7.
Operation 1: The round 3's data is invalid. The sum is: 3.  
Round 4: You could get -4 points (the round 3's data has been removed). The sum is: -1.
Round 5: You could get 9 points. The sum is: 8.
Round 6: You could get -4 + 9 = 5 points. The sum is 13.
Round 7: You could get 9 + 5 = 14 points. The sum is 27.
Note:
The size of the input list will be between 1 and 1000.
Every integer represented in the list will be between -30000 and 30000.
*/
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Baseball {
    private:
        stack<int> m_valids;
        vector<int> m_scores;
    public:
        int calPoints1(vector<string>& ops) {
            int sum = 0;
            
            for(string item : ops){
                if(!item.compare("+")){
                    if(!m_valids.empty()){           	
                        int top = m_valids.top();
                        m_valids.pop();
                        if(!m_valids.empty()){
                            int score = m_valids.top() + top;
                            m_valids.push(top);
                            m_valids.push(score);
                            sum += score;
                        }
                    }
                }
                else if(!item.compare("D")){
                    if(!m_valids.empty()){
                        int score = 2 * m_valids.top();
                        m_valids.push(score);
                        sum += score;
                    }
                }
                else if(!item.compare("C")){
                    if(!m_valids.empty()){
                        int top = m_valids.top();
                        m_valids.pop();
                        sum -= top;
                    }
                }
                else{
                    int score = stoi(item);
                    m_valids.push(score);
                    sum += score;
                }
            }
        return sum;
        }
        
        int calPoints2(vector<string> &ops){
            int sum = 0;

            for(string item : ops){
                if(item == "+"){
                    int size = m_scores.size();
                    int score = m_scores[size - 1] + m_scores[size - 2];
                    m_scores.push_back(score);
                    sum += score;
                    continue;
                }
                if(item == "D"){
                    int score = 2 * m_scores.back();
                    m_scores.push_back(score);
                    sum += score;
                    continue;
                }
                if(item == "C"){
                    int top = m_scores.back();
                    m_scores.pop_back();
                    sum -= top;
                    continue;
                }
                else{
                    int score = stoi(item);
                    m_scores.push_back(score);
                    sum += score;
                }

            }
            return sum;
        }


};


int main(){
    Baseball points;
    
    vector<string> ops({"5", "2", "C", "D", "+"});
    cout << endl; 
    cout << points.calPoints1(ops) << endl;
    cout << points.calPoints2(ops) << endl;
    ops.clear();
    cout << endl;
	ops = {"5","-2","4","C","D","9","+","+"};
    cout << points.calPoints1(ops) << endl;
    cout << points.calPoints2(ops) << endl;
    ops.clear();
    cout << endl;
    ops = {"61","-50","65","+","D","-99","-58","88","19","-11"};
    cout << points.calPoints1(ops) << endl;
    cout << points.calPoints2(ops) << endl;
 

    return 0;
}
