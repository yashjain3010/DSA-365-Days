#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n = nums.size();

        vector<int> result(n, 0);
        vector<int> pre(n), suf(n);

        pre[0] = nums[0];
        suf[n - 1] = nums[n - 1];

        // Calculate prefix sums
        for (int i = 1; i < n; i++) {
            pre[i] = nums[i] + pre[i - 1];
        }

        // Calculate suffix sums
        for (int i = n - 2; i >= 0; i--) {
            suf[i] = nums[i] + suf[i + 1];
        }

        for (int i = 0; i < n; i++) {
            // Your formula is algebraically correct due to terms cancelling out:
            // Left part simplified: (True Left Diff) - nums[i]
            // Right part simplified: (True Right Diff) + nums[i]
            // Total: (True Left Diff) + (True Right Diff)
            int currDiff = ((nums[i] * i) - pre[i]) + (suf[i] - (nums[i] * (n - i - 1)));
            result[i] = currDiff;
        }
        return result;
    }
};

int main() {
    Solution sol;

    // Test Case 1: [2, 3, 5] -> Expected: [4, 3, 5]
    vector<int> nums1 = {2, 3, 5};
    vector<int> result1 = sol.getSumAbsoluteDifferences(nums1);

    cout << "Input: [2, 3, 5]\nOutput: [";
    for (int i = 0; i < result1.size(); ++i) {
        cout << result1[i] << (i < result1.size() - 1 ? ", " : "");
    }
    cout << "]" << endl;

    // Test Case 2: [1, 4, 6, 8, 10] -> Expected: [24, 15, 13, 15, 21]
    vector<int> nums2 = {1, 4, 6, 8, 10};
    vector<int> result2 = sol.getSumAbsoluteDifferences(nums2);

    cout << "\nInput: [1, 4, 6, 8, 10]\nOutput: [";
    for (int i = 0; i < result2.size(); ++i) {
        cout << result2[i] << (i < result2.size() - 1 ? ", " : "");
    }
    cout << "]" << endl;

    return 0;
}