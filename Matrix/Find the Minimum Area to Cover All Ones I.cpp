#include <iostream>
#include <vector>
#include <algorithm> // For min, max
#include <climits>   // For INT_MAX, INT_MIN

using namespace std;

class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int left = INT_MAX, right = INT_MIN;
        int upper = INT_MAX, lower = INT_MIN;

        bool found = false;

        for(int i = 0 ; i < grid.size() ; i++){
            for(int j = 0 ; j < grid[0].size() ; j++){
                if(grid[i][j] == 1){
                    found = true;
                    left = min(left, j);
                    right = max(right, j);
                    upper = min(upper, i);
                    lower = max(lower, i);
                }
            }
        }
        
        // Handle case where grid has no 1s (though problem constraints usually guarantee one)
        if (!found) return 0;

        return (right - left + 1) * (lower - upper + 1);
    }
};

int main() {
    Solution sol;

    // Test Case 1: Scattered 1s
    // 0 1 0
    // 1 0 1
    // The box must cover (0,1), (1,0), (1,2).
    // Rows: 0 to 1 (Height 2)
    // Cols: 0 to 2 (Width 3)
    // Area: 2 * 3 = 6
    vector<vector<int>> grid1 = {
        {0, 1, 0},
        {1, 0, 1}
    };

    cout << "Test Case 1:" << endl;
    cout << "Minimum Area: " << sol.minimumArea(grid1) << endl;
    cout << "-----------------" << endl;

    // Test Case 2: Single 1
    // Area should be 1*1 = 1
    vector<vector<int>> grid2 = {
        {0, 0},
        {0, 1}
    };

    cout << "Test Case 2:" << endl;
    cout << "Minimum Area: " << sol.minimumArea(grid2) << endl;
    cout << "-----------------" << endl;

    // Test Case 3: Square Block
    // 1 1
    // 1 1
    // Area: 2*2 = 4
    vector<vector<int>> grid3 = {
        {1, 1},
        {1, 1}
    };

    cout << "Test Case 3:" << endl;
    cout << "Minimum Area: " << sol.minimumArea(grid3) << endl;

    return 0;
}