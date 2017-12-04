#include <iostream>
#include "Bits.hpp"

using namespace std;

int main(){

    int x = 1;
    int y = 4;
    Bits manip(x, y);

    cout << "Hamming distance between " << x << " and " << y << ": " << manip.hamming() << endl; 

    return 0;
}
