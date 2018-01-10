/*
In MATLAB, there is a very useful function called 'reshape', which can reshape 
a matrix into a new one with different size but keep its original data.

You're given a matrix represented by a two-dimensional array, and two positive 
integers r and c representing the row number and column number of the wanted reshaped matrix, respectively.

The reshaped matrix need to be filled with all the elements of the original matrix 
in the same row-traversing order as they were.

If the 'reshape' operation with given parameters is possible and legal, output the 
new reshaped matrix; Otherwise, output the original matrix.

Example 1:
Input: 
nums = 
[[1,2],
 [3,4]]
r = 1, c = 4
Output: 
[[1,2,3,4]]
Explanation:
The row-traversing of nums is [1,2,3,4]. The new reshaped matrix is a 1 * 4 matrix, 
fill it row by row by using the previous list.
Example 2:
Input: 
nums = 
[[1,2],
 [3,4]]
r = 2, c = 4
Output: 
[[1,2],
 [3,4]]
Explanation:
There is no way to reshape a 2 * 2 matrix to a 2 * 4 matrix. So output the original matrix.
Note:
The height and width of the given matrix is in range [1, 100].
The given r and c are all positive.
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
        vector<vector<int>> matrixReshape1(vector<vector<int>>& nums, int r, int c) {
            int rows = nums.size();
            int cols = nums[0].size();

            if(r * c != rows * cols){
                return nums;
            }

            vector<vector<int>> result(r, vector<int>(c, 0));

            int idx_r = 0;
            int idx_c = 0;

            for(int i = 0; i < rows; ++i){
                for(int j = 0; j < cols; ++j){
                    result[idx_r][idx_c] = nums[i][j];
                    idx_c = (idx_c + 1) % c;
                    if(idx_c == 0){
                        ++idx_r;
                    }
                }
            }
            return result;
        }
        
        vector<vector<int>> matrixReshape2(vector<vector<int>>& nums, int r, int c) {
            int rows = nums.size();
            int cols = nums[0].size();

            if(r * c != rows * cols){
                return nums;
            }

            vector<vector<int>> result(r, vector<int>(c, 0));
    
            for(int i = 0; i < r * c; ++i){
                result[i / c][i % c] = nums[i / cols][i % cols];
            }

           return result;
        }


        void print(const vector<vector<int>> &nums){
            int rows = nums.size();
            int cols = nums[0].size();

            for(int r = 0; r < rows; ++r){
                for(int c = 0; c < cols; ++c){
                    cout << nums[r][c] << " " << flush;
                }
                cout << endl;
            }
            cout << endl;
        }
};

int main(){

    int r = 2;
    int c = 2;
    vector<vector<int>> input = {{1, 2}, {3, 4}};
    vector<vector<int>> output;    
    Solution sol;

    sol.print(input);
    
    output = sol.matrixReshape1(input, r, c);
    sol.print(output);
    output = sol.matrixReshape2(input, r, c);
    sol.print(output);
    
    output = sol.matrixReshape1(input, 1, 4);
    sol.print(output);
    output = sol.matrixReshape2(input, 1, 4);
    sol.print(output);

    output = sol.matrixReshape1(input, 4, 1);
    sol.print(output);
    output = sol.matrixReshape2(input, 4, 1);
    sol.print(output);


    return 0;
}

