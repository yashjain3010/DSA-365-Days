#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool checkXMatrix(vector<vector<int>>& grid) {
        int n = grid.size(); // Assuming square matrix as per problem constraints
        
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n ; j++){
                // Check Primary Diagonal (Top-Left to Bottom-Right)
                if(i == j){
                    if(grid[i][j] == 0) return false;
                } 
                // Check Secondary Diagonal (Top-Right to Bottom-Left)
                else if((n - 1 - i) == j){
                    if(grid[i][j] == 0) return false;
                } 
                // Check Non-Diagonal Elements
                else{
                    if(grid[i][j] != 0) return false;
                }
            }
        }
        return true;
    }
};

int main() {
    Solution sol;

    // Test Case 1: Valid X-Matrix
    // [2,0,0,1]
    // [0,3,1,0]
    // [0,5,2,0]
    // [4,0,0,2]
    // Diagonals (2,3,1,5,2,4,2) are non-zero. Rest are zero.
    vector<vector<int>> grid1 = {
        {2, 0, 0, 1},
        {0, 3, 1, 0},
        {0, 5, 2, 0},
        {4, 0, 0, 2}
    };

    cout << "Test Case 1 (Valid): " << (sol.checkXMatrix(grid1) ? "True" : "False") << endl;

    // Test Case 2: Invalid (Zero on diagonal)
    // [5,7,0] -> The 0 at (0,2) is on the secondary diagonal but is 0.
    // [0,3,1]
    // [0,5,0]
    vector<vector<int>> grid2 = {
        {5, 7, 0},
        {0, 3, 1},
        {0, 5, 0}
    };

    cout << "Test Case 2 (Zero on diagonal): " << (sol.checkXMatrix(grid2) ? "True" : "False") << endl;

    // Test Case 3: Invalid (Non-zero off diagonal)
    // [2,0,1] -> The 1 at (0,2) is diagonal. Wait, (0,2) is secondary diagonal.
    // Let's make a clear failure case:
    // [2,0,1]
    // [0,2,0]
    // [1,0,2]
    // This is valid. Let's add noise.
    // [2,1,1] -> The 1 at (0,1) is NOT on any diagonal but is non-zero.
    vector<vector<int>> grid3 = {
        {2, 1, 1},
        {0, 2, 0},
        {1, 0, 2}
    };

    cout << "Test Case 3 (Noise off diagonal): " << (sol.checkXMatrix(grid3) ? "True" : "False") << endl;

    return 0;
}