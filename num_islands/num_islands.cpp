class Solution {
    struct Node{
        int row;
        int col;
    };
    
    int nrows;
    int ncols;
    vector<vector<bool>> visited;
    vector<vector<int>>  grid;
    
    vector<int> row_diff{0, 1,  0, -1};
    vector<int> col_diff{1, 0, -1,  0};
    
    bool isvalid(int row, int col)
    {
        if (row < 0 || row >= nrows || col < 0 || col >= ncols || visited[row][col] || grid[row][col] == 0)
        {
            return false;
        }
        
        return true;
    }
    
public:
    int findCircleNum(vector<vector<int>>& M) {
        nrows = M.size();
        ncols = M[0].size();
        grid = M;
        
        visited = vector(nrows, vector<bool>(ncols, false));
        
        stack<Node> stk;
        
        int count{0};
        
        for (int row = 0; row < nrows; ++row)
        {
            for (int col = 0; col < ncols; ++col)
            {
                if (isvalid(row, col))
                {
                    ++count;
                    stk.push(Node{row, col});
                    
                    while (!stk.empty())
                    {
                        Node curr = stk.top(); stk.pop();
                        visited[curr.row][curr.col] = true;
                        
                        for (int dir = 0; dir < 4; ++dir)
                        {
                            int newrow = curr.row + row_diff[dir];
                            int newcol = curr.col + col_diff[dir];
                            
                            if (isvalid(newrow, newcol))
                            {
                                stk.push(Node{newrow, newcol});
                            }
                        }
                    }
                }
            }
        }
        
        
        return count;
    }    
};