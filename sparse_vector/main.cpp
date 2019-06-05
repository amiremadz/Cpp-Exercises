#include <iostream>
#include <vector>
#include <exception>

/*
 * Implement a sparse vector class.

A sparse vector is similar to a sparse matrix, except that it's restricted to having only 1 dimension. 
 * Your sparse vector should be constructed from a size and vector of index/value pairs, and should 
 * implement a dot product method with another sparse vector.
 * 
*/

using namespace std;

struct SizeException : public exception {
    const char* what() const throw () override {
        return "Different size arrays!";
    }
};
    
class SparseVector {
private:
    vector<int>    m_index;
    vector<double> m_value;    
protected:
    size_t m_size;
private:
    int find(int idx) const
    {
        for (size_t i = 0; i < m_index.size(); ++i)
            if (m_index[i] == idx)
               return i;
        return -1;
    }
public:
    SparseVector(size_t size) : m_size(size) {}
    
    void SetElements(const std::vector<std::pair<size_t, double>>& elements) {        
        for (auto const& item : elements)
        {
            m_index.push_back(item.first);
            m_value.push_back(item.second);
        }
    }
    
    size_t size() const
    {
        return m_size;
    }
    
    double Dot(const SparseVector& b) const {
        if (m_size != b.size())
            throw SizeException();
        
        double sum{0};
        for (size_t i = 0; i < m_index.size(); ++i)
        {
            auto bindex = b.m_index;
            int  idx = b.find(m_index[i]);
            
            if (idx != -1)
                sum += (b.m_value[idx] * m_value[i]);
        }
        
        return sum;
    }
};

int main()
{
     // Make some sparse vectors.
    SparseVector a(100);
    a.SetElements({
        {1, 3.0},
        {3, 200.0},
        {5, 2.0},
        {27, 1.0},
        //{3, 5.0},
    });

    std::vector<std::pair<size_t, double>> b_elements;
    for (size_t i = 0; i < 100; ++i) {
        b_elements.emplace_back(i, i);
    }
    SparseVector b(100);
    b.SetElements(b_elements);

    SparseVector c(99);
    c.SetElements({{27, 5.0}});
    
    SparseVector d(99);
    d.SetElements({{130, 1.0}});

    // Test some dot products.
    try{
        std::cout << "a dot b: " << a.Dot(b) << std::endl;
        std::cout << "b dot a: " << b.Dot(a) << std::endl;
        std::cout << "c dot d: " << c.Dot(d) << std::endl;
        std::cout << "a dot c: " << a.Dot(c) << std::endl;
    } catch (SizeException& e){
        cout << e.what() << endl;
    }
    
    cout << "end!" << endl;
    
    getchar();
    
    return 0;
}
