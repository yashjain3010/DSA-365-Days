#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& nums, int L, int R) {
        int ans = 0, left = -1, right = -1;
        for(int i = 0 ; i < nums.size() ; i++){
            // Case 1: Value is too big (> R). 
            // It breaks the valid subarray chain. 'left' moves to this index.
            if(nums[i] > R){
                left = i;
            }
            
            // Case 2: Value is in the valid range [L, R] (or bigger).
            // This becomes the new "anchor" for valid subarrays.
            if(nums[i] >= L){
                right = i;
            }
            
            // Calculate valid subarrays ending at i.
            // If the current element is < L, we reuse the previous 'right' anchor.
            // If right <= left (meaning we haven't seen a valid max since the last reset), this adds 0.
            ans += right - left;
        }
        return ans;
    }
};

int main() {
    Solution sol;

    // Test Case 1: Standard Example
    // nums = [2, 1, 4, 3], L = 2, R = 3
    // Valid subarrays: [2], [2, 1], [3]. Count = 3.
    // [4] is invalid (> R). [1] is invalid (< L).
    vector<int> nums1 = {2, 1, 4, 3};
    int L1 = 2;
    int R1 = 3;

    cout << "Test Case 1:" << endl;
    cout << "Input: [ ";
    for(int n : nums1) cout << n << " ";
    cout << "], L: " << L1 << ", R: " << R1 << endl;
    cout << "Count: " << sol.numSubarrayBoundedMax(nums1, L1, R1) << endl;
    cout << "-----------------" << endl;

    // Test Case 2: Larger range
    // nums = [2, 9, 2, 5, 6], L = 2, R = 8
    // 9 breaks the array.
    // Left part: [2]
    // Right part: [2, 5, 6] -> [2], [5], [6], [2,5], [5,6], [2,5,6]. (Wait, [2] is valid? Yes max is 2 >= L).
    vector<int> nums2 = {2, 9, 2, 5, 6};
    int L2 = 2;
    int R2 = 8;

    cout << "Test Case 2:" << endl;
    cout << "Input: [ ";
    for(int n : nums2) cout << n << " ";
    cout << "], L: " << L2 << ", R: " << R2 << endl;
    cout << "Count: " << sol.numSubarrayBoundedMax(nums2, L2, R2) << endl;

    return 0;
}