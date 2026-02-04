#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool canMakeSquare(vector<vector<char>>& grid) {
        // A 3x3 grid has four 2x2 sub-squares.
        // We iterate through the top-left corner (i, j) of each possible 2x2 square.
        // i goes from 0 to 1, j goes from 0 to 1.
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                int white = 0;
                int black = 0;

                // Check the 4 cells in the current 2x2 square
                // Top-Left
                if (grid[i][j] == 'W') white++; else black++;
                // Top-Right
                if (grid[i][j+1] == 'W') white++; else black++;
                // Bottom-Left
                if (grid[i+1][j] == 'W') white++; else black++;
                // Bottom-Right
                if (grid[i+1][j+1] == 'W') white++; else black++;

                // If any color dominates (3 or 4 cells), we can solve it.
                if (white >= 3 || black >= 3) return true;
            }
        }
        return false;
    }
};

int main() {
    Solution sol;

    // Test Case 1: Can make a square
    // The top-left 2x2 square has 3 'B's and 1 'W'.
    // Changing (0,0) to 'B' makes a solid black square.
    vector<vector<char>> grid1 = {
        {'W', 'B', 'B'},
        {'B', 'B', 'W'},
        {'W', 'B', 'W'}
    };

    cout << "Test Case 1: " << (sol.canMakeSquare(grid1) ? "True" : "False") << endl;

    // Test Case 2: Cannot make a square
    // Checkerboard pattern -> no 2x2 square has >= 3 matching colors.
    vector<vector<char>> grid2 = {
        {'B', 'W', 'B'},
        {'W', 'B', 'W'},
        {'B', 'W', 'B'}
    };

    cout << "Test Case 2: " << (sol.canMakeSquare(grid2) ? "True" : "False") << endl;

    return 0;
}