#ifndef __BITS_H__
#define __BITS_H__

class Bits{
    private:
       int m_x{0};
       int m_y{0};
    public:
        Bits(int x, int y) : m_x(x), m_y(y) {}   
    public:
        int hamming();
        int reverse();
};





#endif
