#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> goodIndices(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> left(n, 1), right(n, 1), ans;
        
        int count = 1;
        // Calculate non-increasing sequence lengths ending at i
        for (int i = 1; i < n; i++) {
            if (nums[i] <= nums[i - 1])
                count++;
            else
                count = 1;
            left[i] = count;
        }

        count = 1;
        // Calculate non-decreasing sequence lengths starting at i
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] <= nums[i + 1])
                count++;
            else
                count = 1;
            right[i] = count;
        }

        // Check condition for each possible index
        // Range is [k, n-k), meaning i goes from k up to n-k-1 inclusive.
        for (int i = k; i < n - k; i++) {
            if (left[i - 1] >= k && right[i + 1] >= k)
                ans.push_back(i);
        }
        return ans;
    }
};

int main() {
    Solution sol;

    // Test Case 1
    // nums = [2,1,1,1,3,4,1], k = 2
    // Index 2: left[1] (length of [2,1]) is 2 >= k. right[3] (length of [1,3,4]) is 3 >= k. -> Good
    // Index 3: left[2] (length of [2,1,1]) is 3 >= k. right[4] (length of [3,4]) is 2 >= k. -> Good
    vector<int> nums1 = {2, 1, 1, 1, 3, 4, 1};
    int k1 = 2;
    vector<int> result1 = sol.goodIndices(nums1, k1);

    cout << "Input: [2,1,1,1,3,4,1], k=2\nOutput: [";
    for (int i = 0; i < result1.size(); ++i) {
        cout << result1[i] << (i < result1.size() - 1 ? ", " : "");
    }
    cout << "]" << endl;

    // Test Case 2
    // nums = [2,1,1,2], k = 1
    vector<int> nums2 = {2, 1, 1, 2};
    int k2 = 1;
    vector<int> result2 = sol.goodIndices(nums2, k2);

    cout << "\nInput: [2,1,1,2], k=1\nOutput: [";
    for (int i = 0; i < result2.size(); ++i) {
        cout << result2[i] << (i < result2.size() - 1 ? ", " : "");
    }
    cout << "]" << endl;

    return 0;
}