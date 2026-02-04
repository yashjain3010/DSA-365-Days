#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> res(n, vector<int>(n, 0));
        int m = queries.size();

        // Apply the 2D difference array updates
        for (int i = 0; i < m; i++) {
            int r1 = queries[i][0], c1 = queries[i][1];
            int r2 = queries[i][2], c2 = queries[i][3];

            // Top-left corner gets +1
            ++res[r1][c1];

            // Bottom-right corner (out of bounds) gets +1 to cancel the two -1s
            if (r2 + 1 < n && c2 + 1 < n) ++res[r2 + 1][c2 + 1];
            // Right edge (out of bounds) gets -1 to stop propagation
            if (c2 + 1 < n) --res[r1][c2 + 1];
            // Bottom edge (out of bounds) gets -1 to stop propagation
            if (r2 + 1 < n) --res[r2 + 1][c1];
        }

        // Reconstruct the matrix using 2D prefix sums
        // Pass 1: Propagate horizontally
        for (int i = 0; i < n; i++) {
            for (int j = 1; j < n; j++) {
                res[i][j] += res[i][j - 1];
            }
        }

        // Pass 2: Propagate vertically
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < n; j++) {
                res[i][j] += res[i - 1][j];
            }
        }
        return res;
    }
};

// Helper function to print the matrix
void printMatrix(const vector<vector<int>>& matrix) {
    for (const auto& row : matrix) {
        cout << "[";
        for (int i = 0; i < row.size(); ++i) {
            cout << row[i] << (i < row.size() - 1 ? ", " : "");
        }
        cout << "]" << endl;
    }
}

int main() {
    Solution sol;
    int n = 3;
    vector<vector<int>> queries = {{0, 0, 1, 1}, {1, 1, 2, 2}};

    cout << "Test Case: n=3, queries={{0,0,1,1}, {1,1,2,2}}" << endl;
    cout << "Expected Output:" << endl;
    cout << "[1, 1, 0]" << endl;
    cout << "[1, 2, 1]" << endl;
    cout << "[0, 1, 1]" << endl;

    vector<vector<int>> result = sol.rangeAddQueries(n, queries);

    cout << "\nActual Output:" << endl;
    printMatrix(result);

    return 0;
}