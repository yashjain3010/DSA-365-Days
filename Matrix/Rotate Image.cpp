#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();

        // Create a temporary matrix to store rotated values
        // Space Complexity: O(N^2)
        vector<vector<int>> temp(n, (vector<int>(n, 0)));

        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n ; j++){
                // Logic: 
                // The element at [i][j] moves to [j][n-1-i]
                // Example: Top-Left (0,0) moves to Top-Right (0, n-1)
                temp[j][n - 1 - i] = matrix[i][j];
            }
        }
        
        // Copy the rotated matrix back to the original
        matrix = temp;
    }
};

// Helper function to print matrix
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

    // Test Case 1: 3x3 Matrix
    // Input: [[1,2,3],[4,5,6],[7,8,9]]
    // Expected: [[7,4,1],[8,5,2],[9,6,3]]
    vector<vector<int>> matrix1 = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    cout << "Original Matrix:" << endl;
    printMatrix(matrix1);

    sol.rotate(matrix1);

    cout << "Rotated Matrix:" << endl;
    printMatrix(matrix1);
    cout << "-----------------" << endl;

    // Test Case 2: 4x4 Matrix
    // Input: [[5,1,9,11],[2,4,8,10],[13,3,6,7],[15,14,12,16]]
    // Expected: [[15,13,2,5],[14,3,4,1],[12,6,8,9],[16,7,10,11]]
    vector<vector<int>> matrix2 = {
        {5, 1, 9, 11},
        {2, 4, 8, 10},
        {13, 3, 6, 7},
        {15, 14, 12, 16}
    };

    cout << "Original Matrix (4x4):" << endl;
    printMatrix(matrix2);

    sol.rotate(matrix2);

    cout << "Rotated Matrix:" << endl;
    printMatrix(matrix2);

    return 0;
}