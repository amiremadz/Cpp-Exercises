#include <iostream>
#include "Bits.hpp"

using namespace std;

int main(){

    int x = 1;
    int y = 4;
    int z = 19;

    Bits manip(x, y);

    cout << "Hamming distance between " << x << " and " << y << ": " << manip.hamming() << endl; 

    cout << "Number of set bits in " << x << ": " << Bits::count_setbits(x) << endl;
    cout << "Number of set bits in " << y << ": " << Bits::count_setbits(y) << endl;
    cout << "Number of set bits in " << z << ": " << Bits::count_setbits(z) << endl;

    cout << "Reverse bits of " << x << ": " << manip.reverse(x) << endl;
    cout << "Reverse bits of " << y << ": " << manip.reverse(y) << endl;
    cout << "Reverse bits of " << z << ": " << manip.reverse(z) << endl;

    cout << "Number of bits in " << z << ": " << Bits::log2(z) << endl;

   return 0;
}
