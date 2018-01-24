// Given a 2d matrix, check if there exists a path from upper-left to lower-right
// moves: right, down

#include <iostream>
#include <vector>

using namespace std;

class Maze{
    private:
        vector<vector<int>> m_maze;
        vector<vector<bool>> m_bools;
        int m_rows{-1};
        int m_cols{-1};

    public:
        Maze(vector<vector<int>> mat) : m_maze(mat) {
            m_rows = m_maze.size();
            m_cols = m_maze[0].size();
            
            m_bools.resize(m_rows + 1, vector<bool>(m_cols + 1, false));
            m_bools[1][1] = true;
        }

    public:
        bool is_solvable();
        void print();
};

bool Maze::is_solvable(){
    for(int row = 1; row < m_rows + 1; ++row){
        for(int col = 1; col < m_cols + 1; ++col){
            bool up   = m_bools[row - 1][col];
            bool left = m_bools[row][col - 1];

            if( (m_maze[row - 1][col - 1]) && (up || left)){
                m_bools[row][col] = true;
            } 
        }
    }
    return m_bools[m_rows][m_cols];     
}

void Maze::print(){
    for(auto row : m_maze){
        for(int item : row){
            cout << item << " " << flush;
        }
        cout << endl;
    }
}

int main(){
    vector<vector<int>> mat = { {1, 0, 0, 1},
                                {1, 1, 0, 1},
                                {0, 1, 1, 1},
                                {0, 1, 0, 1}};

    Maze my_maze(mat);
    my_maze.print();

    cout << my_maze.is_solvable() << endl;

    return 0;
}
