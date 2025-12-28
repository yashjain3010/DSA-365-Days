#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        int count = 0;
        int maxOnes = 0;
        int ansIndex = 0;

        for(int i = 0 ; i < m ; i++){
            count = 0;
            // Sum the current row to count 1s
            for(int j = 0 ; j < n ; j++){
                count += mat[i][j];
            }

            // Logic Check:
            // We use strictly greater (>) so that if we find a row with the SAME number of 1s,
            // we keep the smaller index (the one we found first).
            if(count > maxOnes){
                maxOnes = count;
                ansIndex = i;
            }
        }
        return {ansIndex, maxOnes};
    }
};

int main() {
    Solution sol;

    // Test Case 1: Standard
    // Row 0: 0 ones
    // Row 1: 1 one
    // Expected: [1, 1]
    vector<vector<int>> mat1 = {
        {0, 0},
        {1, 0}
    };

    cout << "Test Case 1:" << endl;
    vector<int> res1 = sol.rowAndMaximumOnes(mat1);
    cout << "Row Index: " << res1[0] << ", Count: " << res1[1] << endl;
    cout << "-----------------" << endl;

    // Test Case 2: Tie breaking
    // Row 0: 0, 1, 1 (2 ones)
    // Row 1: 0, 1, 1 (2 ones) -> Should be ignored because we want smallest index
    // Row 2: 1, 1, 1 (3 ones) -> New max
    vector<vector<int>> mat2 = {
        {0, 1, 1},
        {0, 1, 1},
        {1, 1, 1}
    };

    cout << "Test Case 2:" << endl;
    vector<int> res2 = sol.rowAndMaximumOnes(mat2);
    cout << "Row Index: " << res2[0] << ", Count: " << res2[1] << endl;

    return 0;
}