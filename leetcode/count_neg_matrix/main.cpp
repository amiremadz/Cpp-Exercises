/*
Given a ro/comun-wise soreted matrix, count the number of
negative integeres.
*/
#include <vector>
#include <iostream>

using namespace std;

int count(vector<vector<int>> mat){
	int count = 0;
    int num_rows = mat.size();
    int num_cols = mat[0].size();
    
    int row = 0;
    int col = num_cols - 1;
    
    while(row < num_rows){
        while(col >= 0 && mat[row][col] > 0){
            --col;
        }
        if(col >= 0){
            count += (col + 1);
        }
        else{
            break;
        }
        ++row;
    }

	return count;
}

int count(vector<vector<int>> mat){
    int count = 0;
    int num_rows = mat.size();
    int num_cols = mat[0].size();
    
    int row = 0;
    int col = num_cols - 1;
    
    while(row < num_rows && col >= 0){
        if(mat[row][col] < 0){
            count += (col + 1);
            ++row;
        }
        else{
            --col;
        }
    }

    return count;
}

int main(){
	vector<vector<int>> mat1 = { {-3, -2, -1, 1},
								 {-2, 2, 3, 4},
								 {4, 5, 7, 8} };

	vector<vector<int>> mat2 = { {3, 4, 5, 6},
								 {4, 5, 6, 7},
								 {5, 6, 7, 8} };

    vector<vector<int>> mat3 = { {-3, 2, 1, 1},
								 {1, 2, 3, 4},
								 {4, 5, 7, 8} };

    vector<vector<int>> mat4 = { {-4, -3, -2, -1},
                                 {1, 2, 3, 4},
                                 {4, 5, 7, 8} };

    cout << count(mat1) << endl;
    cout << count(mat2) << endl;
    cout << count(mat3) << endl;
    cout << count(mat4) << endl;

	return 0;
}