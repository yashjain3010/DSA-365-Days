#include <iostream>
#include <vector>
#include <algorithm> // For max
#include <climits>   // For INT_MIN

using namespace std;

class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int m = accounts.size();
        int n = accounts[0].size();

        int maxi = INT_MIN;

        for(int i = 0 ; i < m ; i++){
            int sum = 0;
            for(int j = 0 ; j < n ; j++){
                sum += accounts[i][j];
            }
            // Optimization: Update max ONLY after calculating the full row sum
            // Doing this inside the inner loop is unnecessary (extra comparisons).
            maxi = max(sum, maxi);
        }
        return maxi;
    }
};

int main() {
    Solution sol;

    // Test Case 1: Standard
    // Customer 1: 1+2+3 = 6
    // Customer 2: 3+2+1 = 6
    // Max: 6
    vector<vector<int>> accounts1 = {
        {1, 2, 3},
        {3, 2, 1}
    };

    cout << "Test Case 1:" << endl;
    cout << "Max Wealth: " << sol.maximumWealth(accounts1) << endl;
    cout << "-----------------" << endl;

    // Test Case 2: Distinct sums
    // Customer 1: 1+5 = 6
    // Customer 2: 7+3 = 10
    // Customer 3: 3+5 = 8
    // Max: 10
    vector<vector<int>> accounts2 = {
        {1, 5},
        {7, 3},
        {3, 5}
    };

    cout << "Test Case 2:" << endl;
    cout << "Max Wealth: " << sol.maximumWealth(accounts2) << endl;

    return 0;
}