/*
200. Number of Islands

Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

Example 1:

11110
11010
11000
00000
Answer: 1

Example 2:

11000
11000
00100
00011
Answer: 3
*/

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int result = 0;
        
        if(grid.empty()){
            return result;
        }
        
        int m = grid.size();
        int n = grid[0].size();
        
        for(int row = 0; row < m; ++row){
            for(int col = 0; col < n; ++col){
                if(grid[row][col] == '1'){
                    ++result;
                    dfs(grid, row, col);
                    //bfs(grid, row, col);
                }
            }
        }
        
        return result;        
    }
private:    
    void dfs(vector<vector<char>> &grid, int row, int col){
        int m = grid.size();
        int n = grid[0].size();
        
        grid[row][col] = 'x';
        
        int row_mv[4] = {0, -1,  0, 1};
        int col_mv[4] = {1,  0, -1, 0};
        
        for(int idx_mv = 0; idx_mv < 4; ++idx_mv){
            int row_next = row + row_mv[idx_mv];
            int col_next = col + col_mv[idx_mv];
            
            bool valid = (row_next >= 0) && (row_next < m) && (col_next >= 0) && (col_next < n) && (grid[row_next][col_next] == '1');
            
            if(valid){
                dfs(grid, row_next, col_next);
            }               
        }                
    }

    void bfs(vector<vector<char>> &grid, int row, int col){
        queue<pair<int, int>> myq;
        
        int m = grid.size();
        int n = grid[0].size();
                
        myq.push(make_pair(row, col));
        
        int row_mv[4] = {0, -1,  0, 1};
        int col_mv[4] = {1,  0, -1, 0};
        
        while(!myq.empty()){
            int r = myq.front().first;
            int c = myq.front().second;
            myq.pop();
            
            bool valid = (r >= 0) && (r < m) && (c >= 0) && (c < n) && (grid[r][c] == '1');
            
            if(valid){
                grid[r][c] = 'x';
                for(int idx_mv = 0; idx_mv < 4; ++idx_mv){
                    int row_next = r + row_mv[idx_mv];
                    int col_next = c + col_mv[idx_mv];
                    myq.push(make_pair(row_next,col_next));
                }
            }
        }
    }
};