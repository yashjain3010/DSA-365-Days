#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        // Use a new matrix for the answer to avoid modifying the input while reading it
        vector<vector<int>> ans(m, vector<int>(n, 0));

        // Step 1: Calculate (onesRow - zerosRow) for all rows
        vector<int> rows(m, 0);
        for(int i = 0 ; i < m ; i++){
            int cnt1 = 0;
            int cnt0 = 0;
            for(int j = 0 ; j < n ; j++){
                if(grid[i][j] == 1) cnt1++;
                else cnt0++;
            }
            rows[i] = cnt1 - cnt0;
        }

        // Step 2: Calculate (onesCol - zerosCol) for all columns
        vector<int> cols(n, 0);
        for(int i = 0 ; i < n ; i++){
            int cnt1 = 0;
            int cnt0 = 0;
            for(int j = 0 ; j < m ; j++){
                if(grid[j][i] == 1) cnt1++;
                else cnt0++;
            }
            cols[i] = cnt1 - cnt0;
        }

        // Step 3: Fill the difference matrix
        // diff[i][j] = (onesRow - zerosRow) + (onesCol - zerosCol)
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                ans[i][j] = rows[i] + cols[j];
            }
        }
        return ans;
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
    // Input: [[0,1,1],[1,0,1],[0,0,1]]
    // Expected: [[0,0,4],[0,0,4],[-2,-2,2]]
    vector<vector<int>> grid1 = {
        {0, 1, 1},
        {1, 0, 1},
        {0, 0, 1}
    };

    cout << "Test Case 1:" << endl;
    cout << "Input:" << endl;
    printMatrix(grid1);

    vector<vector<int>> res1 = sol.onesMinusZeros(grid1);

    cout << "Output:" << endl;
    printMatrix(res1);
    cout << "-----------------" << endl;

    // Test Case 2: All ones
    // Input: [[1,1],[1,1]]
    // Row diffs: 1s=2, 0s=0 -> +2
    // Col diffs: 1s=2, 0s=0 -> +2
    // Total = 4 for all cells
    vector<vector<int>> grid2 = {
        {1, 1},
        {1, 1}
    };

    cout << "Test Case 2 (All Ones):" << endl;
    vector<vector<int>> res2 = sol.onesMinusZeros(grid2);
    printMatrix(res2);

    return 0;
}