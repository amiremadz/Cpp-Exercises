/*
Given a non-empty 2D array grid of 0's and 1's, an island is a group 
of 1's (representing land) connected 4-directionally (horizontal or vertical.) 
You may assume all four edges of the grid are surrounded by water.

Find the maximum area of an island in the given 2D array. (If there is no island, 
the maximum area is 0.)

Example 1:
[[0,0,1,0,0,0,0,1,0,0,0,0,0],
 [0,0,0,0,0,0,0,1,1,1,0,0,0],
 [0,1,1,0,1,0,0,0,0,0,0,0,0],
 [0,1,0,0,1,1,0,0,1,0,1,0,0],
 [0,1,0,0,1,1,0,0,1,1,1,0,0],
 [0,0,0,0,0,0,0,0,0,0,1,0,0],
 [0,0,0,0,0,0,0,1,1,1,0,0,0],
 [0,0,0,0,0,0,0,1,1,0,0,0,0]]
Given the above grid, return 6. Note the answer is not 11, because the island must 
be connected 4-directionally.
Example 2:
[[0,0,0,0,0,0,0,0]]
Given the above grid, return 0.
Note: The length of each dimension in the given grid does not exceed 50.
*/

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        int max_area = 0;
        
        for(int row = 0; row < m; ++row){
            for(int col = 0; col < n; ++col){
                if(grid[row][col]){
                	int area = dfs(row, col, grid);
                	if(area > max_area){
                    	max_area = area;
                	}
                }
            }
        }
        
        return max_area;
    }
private:
    int dfs(int row, int col, vector<vector<int>> &grid){
    	int num_rows = grid.size();
    	int num_cols = grid[0].size();
    	int area = 1;

    	grid[row][col] = 2;

    	int row_move[4] = {-1, 0, 1, 0};
    	int col_move[4] = {0, -1, 0, 1};

    	for(int i = 0; i < 4; ++i){
    		int r = row + row_move[i];
    		int c = col + col_move[i];

    		bool cond = (r >= 0) && (r < num_rows) && (col >=0) && (col < num_cols) && (grid[r][c] == 1);
     		if(cond){
     			area += dfs(r, c, grid);
     		}
    	}
    	return area;        
    }    

    int bfs(int row, int col, vector<vector<int>> &grid){
    	int num_rows = grid.size();
    	int num_cols = grid[0].size();
    	int area = 0;

		int row_move[4] = {-1, 0, 1, 0};
    	int col_move[4] = {0, -1, 0, 1};

    	queue<pair<int, int>> myq;
    	myq.push(make_pair(row, col));

    	while(!myq.empty()){
    		int r = myq.front().first;
    		int c = myq.front().second;
    		myq.pop();

    		bool cond = (r >= 0) && (r < num_rows) && 
    					(c >=0) && (c < num_cols) && (grid[r][c] == 1);

	    	if(cond){
	    		grid[r][c] = 2;
	    		++area;
	    		for(int i = 0; i < 4; ++i){
	    			myq.push({r + row_move[i], c + col_move[i]});
	    		}
	    	}
    	}
    	return area;
    }
};
