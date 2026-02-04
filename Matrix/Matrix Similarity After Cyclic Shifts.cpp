#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int m = mat.size();
        int n = mat[0].size();

        // Optimization: k can be larger than n, so we take modulo
        // If k is a multiple of n, the matrix doesn't change at all.
        k = k % n;
        if (k == 0) return true;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                // Logic:
                // Instead of physically moving elements (which is slow),
                // we just check if the element that *would* land here is equal to the current element.
                //
                // For a Left Shift (Even Rows): New mat[i][j] comes from Old mat[i][(j + k) % n]
                // For a Right Shift (Odd Rows): New mat[i][j] comes from Old mat[i][(j - k + n) % n]
                //
                // Mathematical trick: Since we are checking equality for the whole cycle,
                // checking mat[i][j] == mat[i][(j + k) % n] works for BOTH directions.
                // This is because if A equals B which is k steps away, B also equals A (k steps back).
                
                if (mat[i][j] != mat[i][(j + k) % n]) {
                    return false;
                }
            }
        }
        return true;
    }
};

int main() {
    Solution sol;

    // Test Case 1: Standard Example
    // mat = [[1,2,1,2],[5,5,5,5],[6,3,6,3]], k = 2
    // Row 0 (Even, Left shift 2): [1,2,1,2] -> [1,2,1,2] (Unchanged)
    // Row 1 (Odd, Right shift 2): [5,5,5,5] -> [5,5,5,5] (Unchanged)
    // Row 2 (Even, Left shift 2): [6,3,6,3] -> [6,3,6,3] (Unchanged)
    // Result: true
    vector<vector<int>> mat1 = {
        {1, 2, 1, 2},
        {5, 5, 5, 5},
        {6, 3, 6, 3}
    };
    int k1 = 2;

    cout << "Test Case 1:" << endl;
    cout << "Is Similar: " << (sol.areSimilar(mat1, k1) ? "True" : "False") << endl;
    cout << "-----------------" << endl;

    // Test Case 2: Not Similar
    // mat = [[1,2]], k = 1
    // Row 0 (Left shift 1): [2,1] != [1,2]
    vector<vector<int>> mat2 = {{1, 2}};
    int k2 = 1;

    cout << "Test Case 2:" << endl;
    cout << "Is Similar: " << (sol.areSimilar(mat2, k2) ? "True" : "False") << endl;

    return 0;
}