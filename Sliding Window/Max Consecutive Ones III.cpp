#include <iostream>
#include <vector>
#include <algorithm> // For max

using namespace std;

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left = 0;
        int zeroCount = 0;
        int maxLen = 0;

        for (int right = 0; right < nums.size(); right++) {
            // Add right element to the window
            if (nums[right] == 0)
                zeroCount++;

            // If invalid (too many zeros), shift the window
            // Note: Using 'if' instead of 'while' here is an optimization.
            // We don't need to shrink the window size, just shift it to the right
            // because we are only interested in finding a LARGER window than what we have found so far.
            if (zeroCount > k) {
                if (nums[left] == 0)
                    zeroCount--;
                left++;
            }

            // Update maxLen
            // If the window was invalid and we shifted 'left', the size (right - left + 1)
            // remains unchanged, which is fine.
            maxLen = max(maxLen, right - left + 1);
        }
        return maxLen;
    }
};

int main() {
    Solution sol;

    // Test Case 1: Standard Example
    // [1,1,1,0,0,0,1,1,1,1,0], k = 2
    // Expected: 6 (The subarray is [1,1,1,0,0,1,1,1,1] with the two zeros flipped)
    vector<int> nums1 = {1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0};
    int k1 = 2;

    cout << "Test Case 1:" << endl;
    cout << "Input: [ ";
    for(int n : nums1) cout << n << " ";
    cout << "], k: " << k1 << endl;
    cout << "Max Consecutive Ones: " << sol.longestOnes(nums1, k1) << endl;
    cout << "-----------------" << endl;

    // Test Case 2: K = 0 (No zeros allowed)
    vector<int> nums2 = {0, 0, 1, 1, 0, 1};
    int k2 = 0;
    
    cout << "Test Case 2:" << endl;
    cout << "Input: [ ";
    for(int n : nums2) cout << n << " ";
    cout << "], k: " << k2 << endl;
    cout << "Max Consecutive Ones: " << sol.longestOnes(nums2, k2) << endl;

    return 0;
}