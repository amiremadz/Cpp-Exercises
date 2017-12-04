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
