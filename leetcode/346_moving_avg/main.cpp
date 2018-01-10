/*
Given a stream of integers and a window size, calculate the
moving average of all integers in the sliding window.
For example,

MovingAverage m = new MovingAverage(3);
m.next(1) = 1
m.next(10) = (1 + 10) / 2
m.next(3) = (1 + 10 + 3) / 3
m.next(5) = (10 + 3 + 5) / 3
*/

#include "MA.hpp"
#include <iostream>

using namespace std;

int main(){

    MovingAverage mavg(3);
    
    mavg.next(2);
    cout << mavg << endl; 
    
    mavg.next(10);
    cout << mavg << endl;

    mavg.next(3);
    cout << mavg << endl;  

    mavg.next(5);
    cout << mavg << endl; 

    return 0;
}

