#include <iostream>
#include <vector>
#include <climits>    // For INT_MIN
#include <algorithm>  // For max

using namespace std;

class Solution {
public:
    vector<vector<int>> modifiedMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        // Create a copy of the matrix for the answer
        vector<vector<int>> ans = matrix;

        // Store the maximum value of each column
        vector<int> colMax(n, INT_MIN);

        // 1. Find the max value for every column
        for(int j = 0 ; j < n ; j++){
            for(int i = 0 ; i < m ; i++){
                colMax[j] = max(colMax[j], matrix[i][j]);
            }
        }

        // 2. Replace -1s with the column max
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                if(matrix[i][j] == -1){
                    ans[i][j] = colMax[j];
                }
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;

    // Test Case:
    // Input Matrix:
    // [ 1, 2, -1 ]
    // [ 4, -1, 6 ]
    // [ 7, 8, 9 ]
    
    // Logic:
    // Col 0 Max: 7 (no -1s to replace)
    // Col 1 Max: 8 (replace -1 at [1][1] with 8)
    // Col 2 Max: 9 (replace -1 at [0][2] with 9)
    
    vector<vector<int>> matrix = {
        {1, 2, -1},
        {4, -1, 6},
        {7, 8, 9}
    };

    cout << "Original Matrix:" << endl;
    for(const auto& row : matrix) {
        cout << "[ ";
        for(int x : row) cout << x << "\t";
        cout << "]" << endl;
    }

    // Run solution
    vector<vector<int>> result = sol.modifiedMatrix(matrix);

    cout << "\nModified Matrix:" << endl;
    for(const auto& row : result) {
        cout << "[ ";
        for(int x : row) cout << x << "\t";
        cout << "]" << endl;
    }

    return 0;
}