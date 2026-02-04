#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm> // For max

using namespace std;

class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        int i = 0, j = 0;
        int sum = 0;
        int maxSum = 0;

        unordered_map<int, int> mpp;

        while(j < n){
            // Add current element to the window
            mpp[nums[j]]++;
            sum += nums[j];

            // If duplicate found, shrink window from left until duplicate is removed
            while(mpp[nums[j]] > 1){
                mpp[nums[i]]--;
                sum -= nums[i];
                i++;
            }
            
            // Update max sum found so far
            maxSum = max(sum, maxSum);
            j++;
        }
        return maxSum;
    }
};

int main() {
    Solution sol;

    // Test Case 1: Standard Example
    // nums = [4,2,4,5,6]
    // Subarrays: [4,2], [2,4,5,6] (sum 17). 
    // The duplicate 4 forces the window to reset past the first 4.
    vector<int> nums1 = {4, 2, 4, 5, 6};
    
    cout << "Test Case 1:" << endl;
    cout << "Input: [ ";
    for(int n : nums1) cout << n << " ";
    cout << "]" << endl;
    cout << "Maximum Unique Subarray Sum: " << sol.maximumUniqueSubarray(nums1) << endl;
    cout << "-----------------" << endl;

    // Test Case 2: Many duplicates
    // nums = [5,2,1,2,5,2,1,2,5]
    // Max should be [5,2,1] (8) or [1,2,5] (8).
    vector<int> nums2 = {5, 2, 1, 2, 5, 2, 1, 2, 5};

    cout << "Test Case 2:" << endl;
    cout << "Input: [ ";
    for(int n : nums2) cout << n << " ";
    cout << "]" << endl;
    cout << "Maximum Unique Subarray Sum: " << sol.maximumUniqueSubarray(nums2) << endl;

    return 0;
}