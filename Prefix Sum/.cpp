#include <iostream>
#include <vector>
#include <numeric> // For std::partial_sum

using namespace std;

class Solution {
public:
    int numberOfPoints(vector<vector<int>>& nums) {
        int n = nums.size();
        // Array to store changes, +1 at start, -1 at (end + 1)
        // Size 102 to handle points 1 to 100, and the (end+1) for point 100
        vector<int> v(102); 
        int count = 0, ans = 0;

        for (int i = 0; i < n; i++) {
            v[nums[i][0]]++;
            v[nums[i][1] + 1]--;
        }

        // Calculate prefix sum and count points
        // Start from index 1 since points are 1-based
        for (int i = 1; i < 102; i++) {
            // count represents the number of active intervals covering point i
            count += v[i];
            if (count > 0) {
                // If count > 0, this point is covered by at least one interval
                ans++;
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;

    // Test Case 1: {{3, 6}, {1, 5}, {4, 7}}
    // Covered: [1, 2, 3, 4, 5] + [3, 4, 5, 6] + [4, 5, 6, 7]
    // Union: [1, 2, 3, 4, 5, 6, 7]
    // Total points: 7
    vector<vector<int>> nums1 = {{3, 6}, {1, 5}, {4, 7}};
    cout << "Input: {{3, 6}, {1, 5}, {4, 7}}\nOutput: " << sol.numberOfPoints(nums1) << endl;

    // Test Case 2: {{1, 3}, {5, 8}}
    // Covered: [1, 2, 3] + [5, 6, 7, 8]
    // Union: [1, 2, 3, 5, 6, 7, 8]
    // Total points: 7
    vector<vector<int>> nums2 = {{1, 3}, {5, 8}};
    cout << "\nInput: {{1, 3}, {5, 8}}\nOutput: " << sol.numberOfPoints(nums2) << endl;
    
    // Test Case 3: {{1, 100}}
    // Covered: [1...100]
    // Total points: 100
    vector<vector<int>> nums3 = {{1, 100}};
    cout << "\nInput: {{1, 100}}\nOutput: " << sol.numberOfPoints(nums3) << endl;

    return 0;
}