#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    // Helper to rotate the grid 90 degrees clockwise
    // This allows us to reuse the horizontal splitting logic for vertical splits
    vector<vector<int>> rotateClockwise(vector<vector<int>>& grid){
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> rotateGrid(n, vector<int> (m));

        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                rotateGrid[j][m-i-1] = grid[i][j];
            }
        }
        return rotateGrid;
    }
    
    // Calculate the bounding box area of 1s within the specified limits
    int minArea(int startRow, int endRow, int startCol, int endCol,
            vector<vector<int>>& grid) { 
            
            int maxRow = -1; 
            int maxCol = -1;
            int minRow = INT_MAX; 
            int minCol = INT_MAX;
            
            bool found = false;

            for(int i = startRow ; i < endRow ; i++){
                for(int j = startCol ; j < endCol ; j++){
                    if(grid[i][j] == 1){
                        found = true;
                        maxRow = max(maxRow, i);
                        maxCol = max(maxCol, j);
                        minRow = min(minRow, i);
                        minCol = min(minCol, j);
                    }
                }
            }
            // If no 1s are found in this partition, the area contribution is 0
            if (!found) return 0;
            
            return (maxRow - minRow + 1) * (maxCol - minCol + 1);
    }

    // Tries all possible cut combinations for a given orientation
    int helper(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int result = INT_MAX;

        // Pattern 1: One Horizontal Cut + One Vertical Cut (T-Shape)
        for (int rs = 1; rs < m; rs++) {     // rs - rows splitter
            for (int cs = 1; cs < n; cs++) { // cs - column splitter
                
                // Case A: Top rectangle, Bottom split into Left/Right
                // [  TOP  ]
                // [BL | BR]
                int top = minArea(0, rs, 0, n, grid);
                int bottomLeft = minArea(rs, m, 0, cs, grid);
                int bottomRight = minArea(rs, m , cs, n, grid);
                
                // Check for overflow or invalid partitions
                if (top + bottomLeft + bottomRight > 0) 
                    result = min(result, top + bottomLeft + bottomRight);

                // Case B: Top split into Left/Right, Bottom rectangle
                // [TL | TR]
                // [  BOT  ]
                int topLeft = minArea(0, rs, 0, cs, grid);
                int topRight = minArea(0, rs, cs, n, grid);
                int bottom = minArea(rs, m, 0, n, grid);

                if (topLeft + topRight + bottom > 0)
                    result = min(result, topLeft + topRight + bottom);
            }
        }

        // Pattern 2: Two Horizontal Cuts (Three Horizontal Strips)
        // [ TOP ]
        // [ MID ]
        // [ BOT ]
        for(int rs1 = 1 ; rs1 < m ; rs1++){
            for(int rs2 = rs1+1 ; rs2 < m ; rs2++){
                int top = minArea(0, rs1, 0, n, grid);
                int middle = minArea(rs1, rs2, 0, n, grid);
                int bottom = minArea(rs2, m, 0, n, grid);

                if (top + middle + bottom > 0)
                    result = min(result, top + middle + bottom);
            }
        }
        return result;
    }

    int minimumSum(vector<vector<int>>& grid) { 
        // 1. Check patterns in original orientation:
        //    - 3 Horizontal Strips
        //    - T-Cut (Horizontal then Vertical)
        int result = helper(grid); 

        // 2. Check patterns in rotated orientation:
        //    - Rotating 90 deg converts "3 Horizontal Strips" check into "3 Vertical Strips" check
        //    - Converts "Horizontal then Vertical" T-Cut into "Vertical then Horizontal" T-Cut
        vector<vector<int>> rotateGrid = rotateClockwise(grid);
        
        result = min(result, helper(rotateGrid));

        return result;
    }
};

int main() {
    Solution sol;

    // Test Case:
    // 1 0 1
    // 1 1 1
    // 0 1 0
    // Optimal Split: 3 rectangles covering the 1s.
    vector<vector<int>> grid = {
        {1, 0, 1},
        {1, 1, 1},
        {0, 1, 0}
    };

    cout << "Minimum Sum of 3 Sub-areas: " << sol.minimumSum(grid) << endl;

    return 0;
}