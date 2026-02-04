#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        // Use 'ans' as the source of truth for the previous state
        vector<vector<int>> ans = grid;

        while (k != 0) {
            // 1. Shift elements horizontally (right)
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n - 1; j++) {
                    grid[i][j + 1] = ans[i][j];
                }
            }

            // 2. Move last column element to the first column of the next row
            for(int i = 0 ; i < m - 1 ; i++){
                grid[i + 1][0] = ans[i][n - 1];
            }

            // 3. Move the bottom-right element to the top-left
            grid[0][0] = ans[m - 1][n - 1];

            // Update the source 'ans' to the newly shifted 'grid'
            ans = grid;

            k--;
        }
        return grid;
    }
};

// Helper to print grid
void printGrid(const vector<vector<int>>& grid) {
    cout << "[" << endl;
    for (const auto& row : grid) {
        cout << "  [ ";
        for (int x : row) cout << x << " ";
        cout << "]" << endl;
    }
    cout << "]" << endl;
}

int main() {
    Solution sol;

    // Test Case 1: Standard
    // [[1,2,3],[4,5,6],[7,8,9]], k = 1
    // Expected: [[9,1,2],[3,4,5],[6,7,8]]
    vector<vector<int>> grid1 = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int k1 = 1;

    cout << "Test Case 1 (k=1):" << endl;
    printGrid(grid1);
    
    vector<vector<int>> res1 = sol.shiftGrid(grid1, k1);
    
    cout << "Result:" << endl;
    printGrid(res1);
    cout << "-----------------" << endl;

    // Test Case 2: Wrap around
    // [[1],[2],[3],[4]], k = 2
    // Shift 1: [4,1,2,3] (vertical view)
    // Shift 2: [3,4,1,2]
    vector<vector<int>> grid2 = {{1}, {2}, {3}, {4}};
    int k2 = 2;

    cout << "Test Case 2 (k=2):" << endl;
    printGrid(grid2);
    
    vector<vector<int>> res2 = sol.shiftGrid(grid2, k2);
    
    cout << "Result:" << endl;
    printGrid(res2);

    return 0;
}