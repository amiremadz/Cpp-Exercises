#ifndef __MA_H__
#define __MA_H__

#include <iostream>
#include <queue>

class MovingAverage{
    private:
        size_t m_size{0};
        int m_sum{0};
        float m_avg{0};
        std::queue<int> m_q;
    public:
        MovingAverage(int size) :  m_size(size) { }
    public:
        void next(int value);
    public:
        friend std::ostream& operator<<(std::ostream &out, const MovingAverage &ma);        
};

#endif
