#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int m = matrix.size();       // Number of rows in original
        int n = matrix[0].size();    // Number of columns in original

        // Initialize new matrix with swapped dimensions:
        // New rows = old columns (n)
        // New columns = old rows (m)
        vector<vector<int>> ans(n, vector<int>(m));

        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                // Standard transpose logic: element at [i][j] moves to [j][i]
                ans[j][i] = matrix[i][j];
            }
        }
        return ans;
    }
};

// Helper function to print a matrix
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

    // Test Case 1: Square Matrix (3x3)
    // Input: [[1,2,3],[4,5,6],[7,8,9]]
    // Expected: [[1,4,7],[2,5,8],[3,6,9]]
    vector<vector<int>> matrix1 = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    cout << "Test Case 1 (Square):" << endl;
    cout << "Original:" << endl;
    printMatrix(matrix1);

    vector<vector<int>> res1 = sol.transpose(matrix1);

    cout << "Transposed:" << endl;
    printMatrix(res1);
    cout << "-----------------" << endl;

    // Test Case 2: Rectangular Matrix (2x3)
    // Input: [[1,2,3],[4,5,6]]
    // Expected: [[1,4],[2,5],[3,6]] (becomes 3x2)
    vector<vector<int>> matrix2 = {
        {1, 2, 3},
        {4, 5, 6}
    };

    cout << "Test Case 2 (Rectangular):" << endl;
    cout << "Original:" << endl;
    printMatrix(matrix2);

    vector<vector<int>> res2 = sol.transpose(matrix2);

    cout << "Transposed:" << endl;
    printMatrix(res2);

    return 0;
}