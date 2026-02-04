#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int count = 0;

        // Use a map to store the frequency of each row.
        // Key: The row (vector<int>), Value: Frequency
        // Note: vector<int> is a valid key for std::map (it compares lexicographically).
        map<vector<int>, int> mpp;

        // 1. Store all rows in the map
        for(int r = 0 ; r < m ; r++){
            mpp[grid[r]]++;
        }

        // 2. Iterate through columns and check against the map
        for(int c = 0 ; c < n ; c++){
            vector<int> temp;

            // Construct the current column vector
            for(int r = 0 ; r < m ; r++){
                temp.push_back(grid[r][c]);
            }

            // If this column vector exists as a row, add its frequency to the count
            // mpp[temp] will return 0 if the key doesn't exist.
            count += mpp[temp];
        }
        return count;
    }
};

int main() {
    Solution sol;

    // Test Case 1
    // Rows: [3,2,1], [1,7,6], [2,7,7]
    // Cols: [3,1,2], [2,7,7], [1,6,7]
    // Match: Row 2 [2,7,7] and Col 1 [2,7,7] match.
    // Result: 1
    vector<vector<int>> grid1 = {
        {3, 2, 1},
        {1, 7, 6},
        {2, 7, 7}
    };

    cout << "Test Case 1:" << endl;
    cout << "Input: [[3,2,1],[1,7,6],[2,7,7]]" << endl;
    cout << "Equal Pairs: " << sol.equalPairs(grid1) << endl;
    cout << "-----------------" << endl;

    // Test Case 2
    // Rows: [3,1,2,2], [1,4,4,5], [2,4,2,2], [2,4,2,2]
    // Cols: [3,1,2,2], [1,4,4,4], [2,4,2,2], [2,5,2,2]
    // Matches:
    // 1. Row 0 matches Col 0 (1 pair)
    // 2. Row 2 matches Col 2 (1 pair)
    // 3. Row 3 matches Col 2 (1 pair)
    // Result: 3
    vector<vector<int>> grid2 = {
        {3, 1, 2, 2},
        {1, 4, 4, 5},
        {2, 4, 2, 2},
        {2, 4, 2, 2}
    };

    cout << "Test Case 2:" << endl;
    cout << "Input: [[3,1,2,2],[1,4,4,5],[2,4,2,2],[2,4,2,2]]" << endl;
    cout << "Equal Pairs: " << sol.equalPairs(grid2) << endl;

    return 0;
}