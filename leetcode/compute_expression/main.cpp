/*
 * Only supports + and * operators.
*/ 

#include<iostream>
#include<vector>
#include<string>

using namespace std;

int compute(string str){
    int result = 0;
    vector<int> numbers;
    int size = 0;

    string num;
    bool multiply = false;

    for(char ch:str){
        if(ch != '+' && ch != '*'){
            num += ch;
        }
        else{
            numbers.push_back(atoi(num.c_str()));
            ++size;
            num.clear();
            
            if(multiply){
                numbers[size - 2] *= numbers[size - 1];
                numbers.pop_back();
                --size;
            }

            if(ch == '*'){
                multiply = true;
            }
            else{
                multiply = false;
            }
        }
    }

    numbers.push_back(atoi(num.c_str()));
    ++size;

    if(multiply){
        numbers[size - 2] *= numbers[size - 1];
        numbers.pop_back();
        --size;
    }

    for(int item:numbers){
        result += item;
    }
    return result;
}


int main(){
    string str1 = "120+12*10*2+33";
    string str2 = "123+45*10+66";
    string str3 = "120+5*10*2";
    cout << compute(str1) << "-" << 120 + 12*10*2 + 33 << endl;
    cout << compute(str2) << "-" << 123 + 45*10 + 66 << endl;
    cout << compute(str3) << "-" << 120 + 5*10*2 << endl;

    return 0;
}
