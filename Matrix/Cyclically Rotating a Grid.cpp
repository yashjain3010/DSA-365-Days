#include <iostream>
#include <vector>
#include <algorithm> // For min

using namespace std;

class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        // The number of layers is determined by the smaller dimension
        int layers = min(m, n) / 2;

        for(int curr = 0 ; curr < layers ; curr++){
            // 1. Extract the current layer (ring) into a 1D array
            vector<int> temp;

            // Define boundaries for the current layer
            int row1 = curr, row2 = m - 1 - curr;
            int col1 = curr, col2 = n - 1 - curr;

            // Top Row (Left to Right)
            for(int j = col1 ; j <= col2 ; j++){
                temp.push_back(grid[row1][j]);
            }

            // Right Column (Top to Bottom)
            for(int i = row1 + 1 ; i <= row2 ; i++){
                temp.push_back(grid[i][col2]);
            }

            // Bottom Row (Right to Left)
            for(int j = col2 - 1 ; j >= col1 ; j--){
                temp.push_back(grid[row2][j]);
            }

            // Left Column (Bottom to Top)
            for(int i = row2 - 1 ; i > row1 ; i--){
                temp.push_back(grid[i][col1]);
            }

            // 2. Perform the Rotation on the 1D array
            int len = temp.size();
            // Important optimization: k can be huge, so we only rotate k % len times
            int shift = k % len;

            vector<int> rotateArray(len);

            // Calculate new positions (Counter-Clockwise shift)
            for(int i = 0 ; i < len ; i++){
                rotateArray[i] = temp[(i + shift) % len];
            }

            // 3. Put the values back into the grid
            int index = 0;

            // Top Row
            for(int j = col1 ; j <= col2 ; j++){
                grid[row1][j] = rotateArray[index++];
            }

            // Right Column
            for(int i = row1 + 1 ; i <= row2 ; i++){
                grid[i][col2] = rotateArray[index++];
            }

            // Bottom Row
            for(int j = col2 - 1 ; j >= col1 ; j--){
                grid[row2][j] = rotateArray[index++];
            }

            // Left Column
            for(int i = row2 - 1 ; i > row1 ; i--){
                grid[i][col1] = rotateArray[index++];
            }
        }
        return grid;
    }
};

// Helper function to print grid
void printGrid(const vector<vector<int>>& grid) {
    cout << "[" << endl;
    for (const auto& row : grid) {
        cout << "  [ ";
        for (int x : row) cout << x << "\t"; // used tab for alignment
        cout << "]" << endl;
    }
    cout << "]" << endl;
}

int main() {
    Solution sol;

    // Test Case 1: 4x4 Grid, k=1
    // Outer layer rotates 1 step counter-clockwise
    // Inner layer rotates 1 step counter-clockwise
    vector<vector<int>> grid1 = {
        {1,  2,  3,  4},
        {5,  6,  7,  8},
        {9,  10, 11, 12},
        {13, 14, 15, 16}
    };
    int k1 = 1;

    cout << "Original Grid:" << endl;
    printGrid(grid1);

    vector<vector<int>> res1 = sol.rotateGrid(grid1, k1);

    cout << "Rotated Grid (k=1):" << endl;
    printGrid(res1);
    cout << "-----------------" << endl;

    // Test Case 2: Example with large k
    // k=2 is same as k=10 if layer length is 8
    vector<vector<int>> grid2 = {
        {40, 10},
        {30, 20}
    };
    int k2 = 1; 
    // Layer is [40, 10, 20, 30]. Rotated k=1 -> [10, 20, 30, 40].
    
    cout << "Original Grid:" << endl;
    printGrid(grid2);

    vector<vector<int>> res2 = sol.rotateGrid(grid2, k2);

    cout << "Rotated Grid (k=1):" << endl;
    printGrid(res2);

    return 0;
}