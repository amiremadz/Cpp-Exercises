/*
You are given a map in form of a two-dimensional integer grid 
where 1 represents land and 0 represents water. Grid cells are 
connected horizontally/vertically (not diagonally). The grid is 
completely surrounded by water, and there is exactly one 
island (i.e., one or more connected land cells). The island 
doesn't have "lakes" (water inside that isn't connected to the 
water around the island). One cell is a square with side length 1. 
The grid is rectangular, width and height don't exceed 100. 
Determine the perimeter of the island.

Example:

[[0,1,0,0],
 [1,1,1,0],
 [0,1,0,0],
 [1,1,0,0]]

Answer: 16
Explanation: The perimeter is the 16 yellow stripes in the image below:
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
    private:
        int m_rows{0};
        int m_cols{0};
        vector<vector<int>> &m_grid;
    public:
        // Members of reference types can only be initialized in the initializer 
        // list in constructor, because references cannot be rebound. 
        // So they have to be initialized in constructor
        Solution(vector<vector<int>> &grid) : m_grid(grid){
            m_rows= grid.size();
            m_cols = grid[0].size();
            //m_grid = grid; // This isok, if m_grid is not a reference!
        }
    public:
        int islandPerimeter1() {
            int result = 0;

            for(int row = 0; row < m_rows; ++row){
                for(int col = 0; col < m_cols; ++col){
                    if(m_grid[row][col]){
                        int nbs = neighbors(row, col); 
                        result += (4 - nbs);
                    }
                }
            }
            return result;
        }
        
        int islandPerimeter2() {
            int nbs = 0;
            int count = 0;

            for(int row = 0; row < m_rows; ++row){
                for(int col = 0; col < m_cols; ++col){
                    if(m_grid[row][col]){
                        ++count;
                        if(right(row, col)) ++nbs;
                        if(down(row, col))  ++nbs;
                    }
                }
            }
            return (4 * count - 2 * nbs);
        }
 

    private:
        int left(int row, int col){
            if(col - 1 < 0){
                return 0;
            }
            return m_grid[row][col - 1];
        }

        int right(int row, int col){
            if(col + 1 >= m_cols){
                return 0;
            }
            return m_grid[row][col + 1];
        }

        int up(int row, int col){
            if(row - 1 < 0){
                return 0;
            }
            return m_grid[row - 1][col];
        }

        int down(int row, int col){
            if(row + 1 >= m_rows){
                return 0;
            }
            return m_grid[row + 1][col];
        }

        int neighbors(int row, int col){
            int nbs = 0;
                      
            nbs = left(row, col) + right(row, col) + up(row, col) + down(row, col);            

            return nbs;
        }

};


int main(){

    vector<vector<int>> grid = {
                                {0, 1, 0, 0},
                                {1, 1, 1, 0},
                                {0, 1, 0, 0},
                                {1, 1, 0, 0}
                                };
    Solution sol(grid);

    cout << sol.islandPerimeter1()  << endl;
    cout << sol.islandPerimeter2()  << endl;

	return 0;
}
