#include <iostream>
#include <vector>
#include <algorithm> // For min
#include <climits>   // For INT_MAX

using namespace std;

class Solution {
public:
    int minimumOperationsToWriteY(vector<vector<int>>& grid) {
        const int n = grid.size(); 
        const int mid = n / 2;
        
        // cntY stores count of [0, 1, 2] inside the Y shape
        // cntN stores count of [0, 1, 2] outside the Y shape
        int cntY[3] = {0}, cntN[3] = {0};
        
        // Step 1: Scan grid and count frequencies
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                int val = grid[i][j];
                
                // Logic to determine if coordinate (i,j) is part of 'Y'
                bool isY = (i <= mid && (i == j || i + j == n - 1)) || (i > mid && j == mid);
                
                if (isY) ++cntY[val];
                else ++cntN[val];
            }
        }
        
        int totalY = cntY[0] + cntY[1] + cntY[2];
        int totalN = cntN[0] + cntN[1] + cntN[2];
        int res = INT_MAX;
        
        // Step 2: Try all valid permutations (Y_val vs Non_Y_val)
        // Y represents the target value for the Y shape
        // N represents the target value for the background
        for (int Y = 0; Y < 3; ++Y) {
            for (int N = 0; N < 3; ++N) {
                // Determine cost only if the values are different
                if (Y != N) {
                    // Cost = (Total Y cells - Y cells that already match) 
                    //      + (Total Non-Y cells - Non-Y cells that already match)
                    int flips = (totalY - cntY[Y]) + (totalN - cntN[N]);
                    res = min(res, flips);
                }
            }
        }
        return res;
    }
};

int main() {
    Solution sol;

    // Test Case: n = 3
    // [1, 2, 2]
    // [2, 1, 0]
    // [2, 1, 2]
    // Y shape is at (0,0), (0,2), (1,1), (2,1).
    // Y coords values: 1, 2, 1, 1. (Mostly 1s)
    // Background values: 2, 2, 0, 2, 2. (Mostly 2s)
    // Optimal: Turn Y to 1s (cost 1, change the 2), Background to 2s (cost 1, change the 0).
    // Total Ops: 2
    
    vector<vector<int>> grid = {
        {1, 2, 2},
        {2, 1, 0},
        {2, 1, 2}
    };

    cout << "Input Grid:" << endl;
    for(auto& row : grid){
        cout << "[ ";
        for(int x : row) cout << x << " ";
        cout << "]" << endl;
    }

    cout << "Minimum Operations: " << sol.minimumOperationsToWriteY(grid) << endl;

    return 0;
}