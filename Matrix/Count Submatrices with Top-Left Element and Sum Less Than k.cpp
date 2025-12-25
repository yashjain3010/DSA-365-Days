#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        // Step 1: Compute Vertical Prefix Sums
        // After this loop, grid[i][j] will store the sum of the column strip from (0,j) to (i,j).
        for(int i = 1 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                grid[i][j] += grid[i-1][j];
            }
        }

        int count = 0;

        // Step 2: Compute Horizontal Prefix Sums on the fly
        // We iterate through every possible bottom-right corner (i, j)
        for(int i = 0 ; i < m ; i++){
            int sum = 0;
            for(int j = 0 ; j < n ; j++){
                // 'sum' now represents the total sum of the submatrix from (0,0) to (i,j)
                // because grid[i][j] already contains the vertical sum of that column.
                sum += grid[i][j];

                // If the sum exceeds k, we can stop checking this row 
                // (assuming grid contains non-negative numbers).
                if(sum > k) break;

                count++;
            }
        }
        return count;
    }
};

int main() {
    Solution sol;

    // Test Case 1: Standard Example
    // Grid:
    // [7, 6, 3]
    // [6, 6, 1]
    // k = 18
    
    // Logic Trace:
    // 1. Vertical Sums:
    //    [7,  6, 3]
    //    [13, 12, 4]
    //
    // 2. Row Processing:
    //    Row 0: 7 (ok), 7+6=13 (ok), 13+3=16 (ok) -> Count = 3
    //    Row 1: 13 (ok), 13+12=25 (>18 break)     -> Count = 1
    // Total = 4
    
    vector<vector<int>> grid1 = {
        {7, 6, 3},
        {6, 6, 1}
    };
    int k1 = 18;

    cout << "Test Case 1 (k=18): " << sol.countSubmatrices(grid1, k1) << endl;
    cout << "-----------------" << endl;

    // Test Case 2: All values small
    vector<vector<int>> grid2 = {
        {7, 2, 9},
        {1, 5, 0},
        {2, 6, 6}
    };
    int k2 = 20;

    cout << "Test Case 2 (k=20): " << sol.countSubmatrices(grid2, k2) << endl;

    return 0;
}