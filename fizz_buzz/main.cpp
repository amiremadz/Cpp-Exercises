/*
Write a program that outputs the string representation of numbers from 1 to n.

But for multiples of three it should output “Fizz” instead of the number and for 
the multiples of five output “Buzz”. For numbers which are multiples of both three 
and five output “FizzBuzz”.

Example:

n = 15,

Return:
[
    "1",
    "2",
    "Fizz",
    "4",
    "Buzz",
    "Fizz",
    "7",
    "8",
    "Fizz",
    "Buzz",
    "11",
    "Fizz",
    "13",
    "14",
    "FizzBuzz"
]
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
    public:
        vector<string> fizzBuzz(int n) {
            vector<string> result;
            for(int i = 1; i <= n; ++i){
                bool mult_3 = !(i % 3);
                bool mult_5 = !(i % 5);
                if(mult_3 && !mult_5){
                    result.push_back("Fizz");
                    continue;
                }
                if(mult_5 && !mult_3){
                    result.push_back("Buzz");
                    continue;
                }
                if(mult_3 && mult_5){
                    result.push_back("FizzBuzz");
                    continue;
                }

                result.push_back(to_string(i));
            }
            return result;
        }
};


int main(){

    Solution sol;

    vector<string> result = sol.fizzBuzz(15);

    for(auto item : result){
        cout << item << endl;
    }

    return 0;
}
