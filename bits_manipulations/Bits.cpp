#include "Bits.hpp"

int Bits::hamming(){
    int dist = 0;
    while(m_x || m_y){
        int lsb = (m_x & 1) ^ (m_y & 1);
        if(lsb){
            ++dist;
        }
        m_x >>= 1;
        m_y >>= 1;
    }
    return dist;
}

int Bits::reverse(int x){
    int mask = 1;
    int result = 0;

    while(x){
        result <<= 1;
        result |= (x & mask);
        x >>= 1;
    }
    return result; 
}

int Bits::count_setbits(int x){
    int count = 0;
    while(x){
        ++count;
        x &= (x - 1);
    }
    return count;
}

int Bits::log2(int x){
    int result = 0;
    while(x){
        ++result;
        x >>= 1;
    }
    return result;
}


