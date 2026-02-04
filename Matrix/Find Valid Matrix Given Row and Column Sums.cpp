#include <iostream>
#include <vector>
#include <algorithm> // For min

using namespace std;

class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        int rows = rowSum.size();
        int cols = colSum.size();

        // Initialize matrix with 0s
        vector<vector<int>> matrix(rows, vector<int>(cols, 0));

        for(int i = 0 ; i < rows ; i++){
            for(int j = 0 ; j < cols ; j++){
                // Greedy Strategy:
                // Assign the maximum possible value to the current cell (i, j).
                // The max value is limited by the remaining sum of the row or the column.
                matrix[i][j] = min(rowSum[i], colSum[j]);
                
                // Subtract the assigned value from the respective row and column sums
                // so the remaining sum is accurate for the next iterations.
                rowSum[i] -= matrix[i][j];
                colSum[j] -= matrix[i][j];
            }
        }
        return matrix;
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

    // Test Case 1
    // rowSum = [3, 8], colSum = [4, 7]
    // Expected Output: [[3, 0], [1, 7]] (One possible valid solution)
    // Explanation: 
    // Row 0 sum: 3+0 = 3
    // Row 1 sum: 1+7 = 8
    // Col 0 sum: 3+1 = 4
    // Col 1 sum: 0+7 = 7
    vector<int> rowSum1 = {3, 8};
    vector<int> colSum1 = {4, 7};

    cout << "Test Case 1:" << endl;
    cout << "rowSum: [3, 8], colSum: [4, 7]" << endl;
    vector<vector<int>> res1 = sol.restoreMatrix(rowSum1, colSum1);
    printMatrix(res1);
    cout << "-----------------" << endl;

    // Test Case 2
    // rowSum = [5, 7, 10], colSum = [8, 6, 8]
    vector<int> rowSum2 = {5, 7, 10};
    vector<int> colSum2 = {8, 6, 8};

    cout << "Test Case 2:" << endl;
    cout << "rowSum: [5, 7, 10], colSum: [8, 6, 8]" << endl;
    vector<vector<int>> res2 = sol.restoreMatrix(rowSum2, colSum2);
    printMatrix(res2);

    return 0;
}