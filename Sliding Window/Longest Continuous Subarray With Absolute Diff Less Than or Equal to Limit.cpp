#include <iostream>
#include <vector>
#include <algorithm> // For max, min, abs
#include <cmath>     // For abs

using namespace std;

class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int left = 0, right = 0, size = 0, least, most;

        // Initialize min and max with the first element
        least = most = nums[left];

        while(left < nums.size() && right < nums.size()){
            // Check if adding the current element keeps us within the limit
            if(abs(nums[right]- most) <= limit && abs(nums[right]- least) <= limit){
                least = min(least, nums[right]);
                most = max(most, nums[right]);
                right++;
            } else{
                // Current window is invalid.
                // 1. Update the max size found so far
                size = max(size, right-left);
                
                // 2. Reset the window to try and exclude the element that broke the limit.
                // NOTE: This logic resets 'right' to 'left', which effectively restarts the search.
                // This makes the solution O(N^2) in the worst case.
                if(abs(nums[right]- most) > limit){
                    while(nums[left] != most){
                        left++;
                    }
                    while(nums[left] == most && left < nums.size()){ // Added bounds check
                        left++;
                    }

                    if(left < nums.size()) {
                        right = left;
                        least = most = nums[left];
                    } else {
                        break; 
                    }
                }
                else{
                    while(nums[left] != least){
                        left++;
                    } 
                    while(nums[left] == least && left < nums.size()){ // Added bounds check
                        left++;
                    }

                    if(left < nums.size()) {
                        right = left;
                        least = most = nums[left];
                    } else {
                        break;
                    }
                }
            }
        }
        // Final check for the last window
        size = max(size, right-left);
        return size;
    }
};

int main() {
    Solution sol;

    // Test Case 1: Standard Example
    // nums = [8,2,4,7], limit = 4
    // Valid subarrays: [2,4] (diff 2), [2,4,7] (diff 5 > 4 NO), [4,7] (diff 3).
    // Max length should be 2.
    vector<int> nums1 = {8, 2, 4, 7};
    int limit1 = 4;

    cout << "Test Case 1:" << endl;
    cout << "Input: [ ";
    for(int n : nums1) cout << n << " ";
    cout << "], Limit: " << limit1 << endl;
    cout << "Longest Subarray: " << sol.longestSubarray(nums1, limit1) << endl;
    cout << "-----------------" << endl;

    // Test Case 2: nums = [10,1,2,4,7,2], limit = 5
    // [2,4,7,2] -> min 2, max 7, diff 5. Length 4.
    vector<int> nums2 = {10, 1, 2, 4, 7, 2};
    int limit2 = 5;

    cout << "Test Case 2:" << endl;
    cout << "Input: [ ";
    for(int n : nums2) cout << n << " ";
    cout << "], Limit: " << limit2 << endl;
    cout << "Longest Subarray: " << sol.longestSubarray(nums2, limit2) << endl;

    return 0;
}