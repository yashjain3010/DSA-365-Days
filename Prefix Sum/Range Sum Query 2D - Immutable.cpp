#include <iostream>
#include <vector>

using namespace std;

class NumMatrix {
public:
    vector<vector<int>> ps;
    NumMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = n ? matrix[0].size() : 0;
        // Assign a (n+1) x (m+1) 2D vector, initialized to 0
        ps.assign(n + 1, vector<int>(m + 1, 0));

        // Calculate the 2D prefix sums
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                ps[i + 1][j + 1] = matrix[i][j] + ps[i][j + 1] + ps[i + 1][j] - ps[i][j];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        // Apply the 2D prefix sum formula
        return ps[row2 + 1][col2 + 1] - ps[row1][col2 + 1] - ps[row2 + 1][col1] + ps[row1][col1];
    }
};

int main() {
    // Example from LeetCode
    vector<vector<int>> matrix = {
        {3, 0, 1, 4, 2},
        {5, 6, 3, 2, 1},
        {1, 2, 0, 1, 5},
        {4, 1, 0, 1, 7},
        {1, 0, 3, 0, 5}
    };

    NumMatrix* obj = new NumMatrix(matrix);

    // Test case 1: sumRegion(2, 1, 4, 3)
    // Submatrix:
    // [2, 0, 1]
    // [1, 0, 1]
    // [0, 3, 0]
    // Sum = 8
    cout << "sumRegion(2, 1, 4, 3): " << obj->sumRegion(2, 1, 4, 3) << endl;

    // Test case 2: sumRegion(1, 1, 2, 2)
    // Submatrix:
    // [6, 3]
    // [2, 0]
    // Sum = 11
    cout << "sumRegion(1, 1, 2, 2): " << obj->sumRegion(1, 1, 2, 2) << endl;

    // Test case 3: sumRegion(1, 2, 2, 4)
    // Submatrix:
    // [3, 2, 1]
    // [0, 1, 5]
    // Sum = 12
    cout << "sumRegion(1, 2, 2, 4): " << obj->sumRegion(1, 2, 2, 4) << endl;

    delete obj;
    return 0;
}