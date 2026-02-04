#include <iostream>
#include <vector>
#include <algorithm> // For sort, max

using namespace std;

class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        // Sorting is crucial: it allows us to use a sliding window efficiently.
        // We always try to make all elements in the window equal to the largest element (nums[r]).
        sort(nums.begin(), nums.end());

        long long total = 0;
        int l = 0, res = 0;
        int r = 0;

        while(r < nums.size()){
            total += nums[r];
            
            // Validity Check:
            // The cost to make all elements in the window [l...r] equal to nums[r] is:
            // (window_length * nums[r]) - (sum of window elements)
            // If this cost > k, the window is invalid, so shrink from the left.
            while((long long)nums[r] * (r - l + 1) > total + k){
                total -= nums[l];
                l++;
            }
            
            res = max(res, r - l + 1);
            r += 1;
        }
        return res;
    }
};

int main() {
    Solution sol;

    // Test Case 1: Standard Example
    // nums = [1,2,4], k = 5
    // Sorted: [1,2,4]
    // Target 4: Change 1->4 (cost 3), Change 2->4 (cost 2). Total cost 5.
    // Result: 3 elements (all become 4).
    vector<int> nums1 = {1, 2, 4};
    int k1 = 5;

    cout << "Test Case 1:" << endl;
    cout << "Input: [ ";
    for(int n : nums1) cout << n << " ";
    cout << "], k: " << k1 << endl;
    cout << "Max Frequency: " << sol.maxFrequency(nums1, k1) << endl;
    cout << "-----------------" << endl;

    // Test Case 2: nums = [1,4,8,13], k = 5
    // Result: 2 (Make [4,8] into [8,8] cost 4. Cannot include 1, cost would be 4+7=11 > 5).
    vector<int> nums2 = {1, 4, 8, 13};
    int k2 = 5;

    cout << "Test Case 2:" << endl;
    cout << "Input: [ ";
    for(int n : nums2) cout << n << " ";
    cout << "], k: " << k2 << endl;
    cout << "Max Frequency: " << sol.maxFrequency(nums2, k2) << endl;
    cout << "-----------------" << endl;

    // Test Case 3: nums = [3,9,6], k = 2
    // Sorted: [3,6,9]. Target 6 cost 3 (too high). Target 9 cost 3 (too high).
    // Result: 1.
    vector<int> nums3 = {3, 9, 6};
    int k3 = 2;
    
    cout << "Test Case 3:" << endl;
    cout << "Input: [ ";
    for(int n : nums3) cout << n << " ";
    cout << "], k: " << k3 << endl;
    cout << "Max Frequency: " << sol.maxFrequency(nums3, k3) << endl;

    return 0;
}