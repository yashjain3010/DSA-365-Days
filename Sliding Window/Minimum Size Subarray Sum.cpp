#include <iostream>
#include <vector>
#include <algorithm> // For min
#include <climits>   // For INT_MAX

using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0, right = 0;
        int currentSum = 0;
        int minLength = INT_MAX;

        while(right < nums.size()){
            // Expand the window by adding the element at 'right'
            currentSum += nums[right];
            right++; // Note: 'right' is incremented here, so window length is simply (right - left) later

            // Shrink the window while the condition is met
            while(currentSum >= target){
                minLength = min(minLength, right - left);
                currentSum -= nums[left];
                left++;
            }
        }

        // If minLength was never updated, it means no valid subarray was found
        return minLength == INT_MAX ? 0 : minLength;
    }
};

int main() {
    Solution sol;

    // Test Case 1: Standard Example
    // target = 7, nums = [2,3,1,2,4,3]
    // Expected Output: 2 (Subarray [4,3] has sum 7)
    vector<int> nums1 = {2, 3, 1, 2, 4, 3};
    int target1 = 7;

    cout << "Test Case 1:" << endl;
    cout << "Target: " << target1 << endl;
    cout << "Nums: [ ";
    for(int n : nums1) cout << n << " ";
    cout << "]" << endl;
    cout << "Min Subarray Length: " << sol.minSubArrayLen(target1, nums1) << endl;
    cout << "-----------------" << endl;

    // Test Case 2: Target not reachable
    // target = 11, nums = [1,1,1,1,1,1,1,1] -> Sum is 8
    // Expected Output: 0
    vector<int> nums2 = {1, 1, 1, 1, 1, 1, 1, 1};
    int target2 = 11;

    cout << "Test Case 2:" << endl;
    cout << "Target: " << target2 << endl;
    cout << "Nums: [ ";
    for(int n : nums2) cout << n << " ";
    cout << "]" << endl;
    cout << "Min Subarray Length: " << sol.minSubArrayLen(target2, nums2) << endl;

    return 0;
}