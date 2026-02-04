#include <iostream>
#include <vector>
#include <set>
#include <algorithm> // For max
#include <climits>   // For INT_MIN

using namespace std;

class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
        int ans = INT_MIN, n = points.size(), l = 0, r = 0;

        // Multiset stores the values of (y - x) for the valid window
        multiset<int> st;

        for(; r < n ; r++){
            // Slide the left pointer to ensure the x-distance constraint (xj - xi <= k)
            // points[r][0] is xj, points[l][0] is xi
            while(l < r && (points[r][0] - points[l][0]) > k) {
                // Remove the (y - x) value associated with the left point
                // lower_bound ensures we only remove one instance if duplicates exist
                st.erase(st.lower_bound(points[l][1]-points[l][0]));
                l++;
            }

            // If the set is not empty, calculate the max value for the current point r
            // Equation: yi + yj + |xi - xj|  => (yi - xi) + (yj + xj)
            // We need max(yi - xi), which is *st.rbegin()
            if(!st.empty()){
                ans = max(ans, points[r][0] + points[r][1] + *st.rbegin());
            }

            // Insert the current point's (y - x) into the set for future pairs
            st.insert(points[r][1]-points[r][0]);
        }
        return ans;
    }
};

int main() {
    Solution sol;

    // Test Case: points = [[1,3],[2,0],[5,10],[6,-10]], k = 1
    vector<vector<int>> points = {
        {1, 3},
        {2, 0},
        {5, 10},
        {6, -10}
    };
    int k = 1;

    cout << "Points: ";
    cout << "[ ";
    for(const auto& p : points) {
        cout << "[" << p[0] << "," << p[1] << "] ";
    }
    cout << "]" << endl;
    cout << "k: " << k << endl;

    // Run the function
    int result = sol.findMaxValueOfEquation(points, k);

    // Print result
    cout << "Max Value of Equation: " << result << endl;

    return 0;
}