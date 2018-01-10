#include "MA.hpp"

std::ostream& operator<<(std::ostream &out, const MovingAverage &ma){
    out << "Moving average: " << ma.m_avg;
    return out;    
}

void MovingAverage::next(int value){
    m_q.push(value);
    size_t size = m_q.size();
    m_sum += value;
    
    if(size <= m_size){
        m_avg = static_cast<float>(m_sum) / size;
        return;
    }
    
    m_sum -= m_q.front();
    m_q.pop();
    m_avg = static_cast<float>(m_sum) / m_size;
}
