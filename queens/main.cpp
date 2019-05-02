#include <iostream>
#include <string>
#include <vector>

class IPrintable{
    friend std::ostream& operator<<(std::ostream& os, const IPrintable& obj);
public:
    virtual void print(std::ostream &os) const = 0;
    virtual ~IPrintable() = default;
};

void IPrintable::print(std::ostream& os) const {
    os << "Hi!";
}

std::ostream& operator<<(std::ostream& os, const IPrintable& obj){
    obj.print(os);
    return os;
}

class Queens : public IPrintable {
private:    
    std::vector<std::string> m_board;
    std::vector<std::vector<std::string>> m_result;
    int m_numQueens;
public:
    Queens(int num_Queens);
    virtual void print(std::ostream& os) const override; 
    void solve();    
public:
    virtual ~Queens() = default;
private:
    void explore(int col);
    bool isValid(int row, int col) const;    
};

Queens::Queens(int num_Queens) : m_numQueens{num_Queens} {
    m_board.resize(num_Queens, std::string(num_Queens, '.'));
}

void Queens::print(std::ostream& os) const {
    for (const auto& board : m_result)
    {
        for (int row = 0; row < m_numQueens; ++row)
        {    
            for (int col = 0; col < m_numQueens; ++col)
                os << board[row][col] << " ";
            os << std::endl;
        }
        os << std::endl;
    }
}

void Queens::solve() {
    explore(0);
}

void Queens::explore(int col) {
    if (col == m_numQueens)
    {
        m_result.push_back(m_board);
        return;
    }
        
    for (int row = 0; row < m_numQueens; ++row)
    {
        if (isValid(row, col))
        {
            m_board[row][col] = 'Q';
            explore(col + 1);
            m_board[row][col] = '.';
        }
    }
}

bool Queens::isValid(int row, int col) const {
    for (int i = 0; i < col; ++i)
        if (m_board[row][i] == 'Q')
            return false;
            
    for (int i = 0; row - i >= 0 && col - i >= 0; ++i)
        if (m_board[row - i][col - i] == 'Q')
            return false;
    
    for (int i = 0; row + i < m_numQueens && col - i >= 0; ++i)
        if (m_board[row + i][col - i] == 'Q')
            return false;
    
    return true;
}

int main()
{
    Queens *q = new Queens{4};
    q->solve();
    std::cout << *q;
  
    Queens q1 = Queens{4};
    q1.solve();
    std::cout << q1;
  
    std::getchar();
    
	return 0;
}
