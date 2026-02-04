#include <iostream>
#include <vector>
#include <algorithm> // For min, max
#include <climits>   // For INT_MAX, INT_MIN

using namespace std;

class Solution {
public:
    vector<int> luckyNumbers(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        // Step 1: Find the minimum of each row
        vector<int> rowMin;
        for(int i = 0 ; i < m ; i++){
            int rMin = INT_MAX;
            for(int j = 0 ; j < n ; j++){
                rMin = min(rMin, matrix[i][j]);
            }
            rowMin.push_back(rMin);
        }

        // Step 2: Find the maximum of each column
        vector<int> colMax;
        for(int i = 0 ; i < n ; i++){
            int cMax = INT_MIN;
            for(int j = 0 ; j < m ; j++){
                cMax = max(cMax, matrix[j][i]);
            }
            colMax.push_back(cMax);
        }

        // Step 3: Check intersection
        // A lucky number is both a row minimum and a column maximum
        vector<int> ans;
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                if(matrix[i][j] == rowMin[i] && matrix[i][j] == colMax[j]){
                    ans.push_back(matrix[i][j]);
                }
            }
        }
        return ans;
    }
};

// Helper function to print results
void printVector(const vector<int>& v) {
    cout << "[ ";
    for (int x : v) cout << x << " ";
    cout << "]" << endl;
}

int main() {
    Solution sol;

    // Test Case 1
    // Matrix:
    // 3  7  8  (Min: 3)
    // 9  11 13 (Min: 9)
    // 15 16 17 (Min: 15)
    // Col Maxs: 15, 16, 17
    // Intersection: 15 (It is min in row 2, max in col 0)
    vector<vector<int>> matrix1 = {
        {3, 7, 8},
        {9, 11, 13},
        {15, 16, 17}
    };

    cout << "Test Case 1:" << endl;
    vector<int> res1 = sol.luckyNumbers(matrix1);
    printVector(res1);
    cout << "-----------------" << endl;

    // Test Case 2
    // Matrix:
    // 1  10 4  2  (Min: 1)
    // 9  3  8  7  (Min: 3)
    // 15 16 17 12 (Min: 12)
    // Col Maxs: 15, 16, 17, 12
    // Intersection: 12 (Min in row 2, Max in col 3)
    vector<vector<int>> matrix2 = {
        {1, 10, 4, 2},
        {9, 3, 8, 7},
        {15, 16, 17, 12}
    };

    cout << "Test Case 2:" << endl;
    vector<int> res2 = sol.luckyNumbers(matrix2);
    printVector(res2);
    cout << "-----------------" << endl;

    // Test Case 3: Unique Values
    // 7 is min in row (7,8) and max in col (3,7)
    vector<vector<int>> matrix3 = {
        {3, 7, 8},
        {9, 11, 13},
        {15, 16, 17}
    };
    // Re-using matrix 1 data for structure verification

    return 0;
}