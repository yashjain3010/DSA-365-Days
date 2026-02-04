#include <iostream>
#include <vector>
#include <algorithm> // For max

using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int target = 0, n = nums.size();

        // Calculate total sum of the array
        for(int num : nums) target += num;
        
        // We want to find the longest subarray with sum = (Total Sum - x)
        // If we find that, the answer is (Total Length - Subarray Length)
        target -= x;

        // If target is 0, it means x equals Total Sum, so we must remove all elements.
        if(target == 0) return n;
        
        // If target is negative (x > total sum), it's impossible.
        if(target < 0) return -1;

        int max_len = 0, cur_sum = 0, left = 0;
        bool found = false; // Helper flag to distinguish between "not found" and "len 0"

        for(int right = 0 ; right < n ; right++){
            cur_sum += nums[right];
            
            // Shrink window if sum exceeds target
            while(left <= right && cur_sum > target){
                cur_sum -= nums[left];
                left++;
            }

            // Check if current window matches target
            if(cur_sum == target){
                found = true;
                max_len = max(max_len, right - left + 1);
            }
        }
        
        // If found is true, return n - max_len. If not found, return -1.
        return found ? n - max_len : -1;
    }
};

int main() {
    Solution sol;

    // Test Case 1: Standard Example
    // nums = [1,1,4,2,3], x = 5
    // Total Sum = 11. Target = 11 - 5 = 6.
    // Longest Subarray with sum 6 is [1, 1, 4] (Length 3).
    // Result operations = 5 - 3 = 2.
    // (Remove 2 and 3 from the right).
    vector<int> nums1 = {1, 1, 4, 2, 3};
    int x1 = 5;

    cout << "Test Case 1:" << endl;
    cout << "Nums: [ ";
    for(int n : nums1) cout << n << " ";
    cout << "], x: " << x1 << endl;
    cout << "Min Operations: " << sol.minOperations(nums1, x1) << endl;
    cout << "-----------------" << endl;

    // Test Case 2: Example 2
    // nums = [5,6,7,8,9], x = 4
    // Target = 35 - 4 = 31.
    // No subarray sums to 31.
    vector<int> nums2 = {5, 6, 7, 8, 9};
    int x2 = 4;

    cout << "Test Case 2:" << endl;
    cout << "Nums: [ ";
    for(int n : nums2) cout << n << " ";
    cout << "], x: " << x2 << endl;
    cout << "Min Operations: " << sol.minOperations(nums2, x2) << endl;
    cout << "-----------------" << endl;

    // Test Case 3: Example 3
    // nums = [3,2,20,1,1,3], x = 10
    // Total = 30. Target = 20.
    // Longest subarray is [20] (len 1)? No, [20] is valid.
    // Wait, [3,2,20,1,1,3] -> remove 3,2 left and 3,1,1 right?
    // Subarray sum 20 is just the element 20. Length 1.
    // Operations = 6 - 1 = 5.
    vector<int> nums3 = {3, 2, 20, 1, 1, 3};
    int x3 = 10;
    
    cout << "Test Case 3:" << endl;
    cout << "Nums: [ ";
    for(int n : nums3) cout << n << " ";
    cout << "], x: " << x3 << endl;
    cout << "Min Operations: " << sol.minOperations(nums3, x3) << endl;

    return 0;
}