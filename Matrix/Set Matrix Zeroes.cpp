#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        // Auxiliary arrays to store which rows and cols need to be zeroed
        // Space Complexity: O(m + n)
        vector<bool> rows(m, 0);
        vector<bool> cols(n, 0);

        // Pass 1: Mark the rows and columns that contain 0
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                if(matrix[i][j] == 0){
                    rows[i] = 1;
                    cols[j] = 1;
                }
            }
        }

        // Pass 2: Set elements to 0 if their row OR col was marked
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                if(rows[i] || cols[j]){
                    matrix[i][j] = 0;
                }
            }
        }
    }
};

// Helper function to print the matrix
void printMatrix(const vector<vector<int>>& matrix) {
    cout << "[" << endl;
    for (const auto& row : matrix) {
        cout << "  [ ";
        for (int x : row) {
            cout << x << " ";
        }
        cout << "]" << endl;
    }
    cout << "]" << endl;
}

int main() {
    Solution sol;

    // Test Case 1: Standard Example
    // Input: [[1,1,1],[1,0,1],[1,1,1]]
    // Expected: [[1,0,1],[0,0,0],[1,0,1]]
    vector<vector<int>> matrix1 = {
        {1, 1, 1},
        {1, 0, 1},
        {1, 1, 1}
    };

    cout << "Test Case 1 - Original:" << endl;
    printMatrix(matrix1);

    sol.setZeroes(matrix1);

    cout << "Test Case 1 - Modified:" << endl;
    printMatrix(matrix1);
    cout << "-----------------" << endl;

    // Test Case 2: Zero at corner
    // Input: [[0,1,2,0],[3,4,5,2],[1,3,1,5]]
    vector<vector<int>> matrix2 = {
        {0, 1, 2, 0},
        {3, 4, 5, 2},
        {1, 3, 1, 5}
    };

    cout << "Test Case 2 - Original:" << endl;
    printMatrix(matrix2);

    sol.setZeroes(matrix2);

    cout << "Test Case 2 - Modified:" << endl;
    printMatrix(matrix2);

    return 0;
}