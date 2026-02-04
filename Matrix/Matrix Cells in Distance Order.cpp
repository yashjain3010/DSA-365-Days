#include <iostream>
#include <vector>
#include <cmath>      // For abs
#include <algorithm>  // For sort
#include <utility>    // For pair

using namespace std;

class Solution {
public:
    vector<vector<int>> allCellsDistOrder(int rows, int cols, int rCenter, int cCenter) {
        vector<vector<int>> ans;
        
        // Store pairs of: {distance, {row, col}}
        // This allows us to sort based on the first element (distance) automatically.
        vector<pair<int, pair<int, int>>> v;

        for(int i = 0 ; i < rows ; i++){
            for(int j = 0 ; j < cols ; j++){
                // Calculate Manhattan Distance
                int distance = abs(i - rCenter) + abs(j - cCenter);
                v.push_back({distance, {i, j}});
            }
        }

        // Sort based on distance (ascending)
        sort(v.begin(), v.end());

        // Extract the coordinates into the final answer vector
        for(int i = 0 ; i < v.size() ; i++){
            ans.push_back({v[i].second.first, v[i].second.second});
        }
        return ans;
    }
};

// Helper to print output
void printResult(const vector<vector<int>>& result) {
    cout << "[";
    for(size_t i = 0; i < result.size(); ++i) {
        cout << "[" << result[i][0] << "," << result[i][1] << "]";
        if(i < result.size() - 1) cout << ", ";
    }
    cout << "]" << endl;
}

int main() {
    Solution sol;

    // Test Case 1: 1x2 matrix, center (0,0)
    // Distances: (0,0)->0, (0,1)->1
    cout << "Test Case 1 (rows=1, cols=2, rc=0, cc=0):" << endl;
    vector<vector<int>> res1 = sol.allCellsDistOrder(1, 2, 0, 0);
    printResult(res1);
    cout << "-----------------" << endl;

    // Test Case 2: 2x2 matrix, center (0,1)
    // (0,0) dist 1
    // (0,1) dist 0
    // (1,0) dist 2
    // (1,1) dist 1
    // Sorted order: (0,1) [0], then (0,0) or (1,1) [1], then (1,0) [2]
    cout << "Test Case 2 (rows=2, cols=2, rc=0, cc=1):" << endl;
    vector<vector<int>> res2 = sol.allCellsDistOrder(2, 2, 0, 1);
    printResult(res2);
    cout << "-----------------" << endl;

    // Test Case 3: 2x3 matrix, center (1,2)
    cout << "Test Case 3 (rows=2, cols=3, rc=1, cc=2):" << endl;
    vector<vector<int>> res3 = sol.allCellsDistOrder(2, 3, 1, 2);
    printResult(res3);

    return 0;
}