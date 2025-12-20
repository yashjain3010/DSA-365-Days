#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int left = 0, right = 0;
        // Use long long for product to prevent integer overflow with large inputs
        long long product = 1; 
        int count = 0;

        int n = nums.size();

        // Edge case: Since nums[i] >= 1, product is always >= 1.
        // If k <= 1, product < k is impossible.
        if(k <= 1) return 0;

        while(right < n){
            // Expand window
            product *= nums[right];

            // Shrink window if product is too large
            while(product >= k) {
                product /= nums[left++];
            }

            // Count subarrays ending at 'right'
            // The number of valid subarrays ending at index 'right' is exactly the window size.
            count += (right - left + 1);
            
            right++;
        }
        return count;
    }
};

int main() {
    Solution sol;

    // Test Case 1: Standard Example
    // nums = [10, 5, 2, 6], k = 100
    // Expected: 8
    // Explanation: [10], [5], [2], [6], [10,5], [5,2], [2,6], [5,2,6]
    vector<int> nums1 = {10, 5, 2, 6};
    int k1 = 100;

    cout << "Test Case 1:" << endl;
    cout << "Input: [ ";
    for(int n : nums1) cout << n << " ";
    cout << "], k: " << k1 << endl;
    cout << "Count: " << sol.numSubarrayProductLessThanK(nums1, k1) << endl;
    cout << "-----------------" << endl;

    // Test Case 2: Edge case k=0
    // nums = [1, 2, 3], k = 0
    // Expected: 0
    vector<int> nums2 = {1, 2, 3};
    int k2 = 0;

    cout << "Test Case 2:" << endl;
    cout << "Input: [ ";
    for(int n : nums2) cout << n << " ";
    cout << "], k: " << k2 << endl;
    cout << "Count: " << sol.numSubarrayProductLessThanK(nums2, k2) << endl;

    return 0;
}