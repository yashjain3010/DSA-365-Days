#include <iostream>
#include <vector>
#include <algorithm> // For max

using namespace std;

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int left = 0, zeroes = 0, maxlen = 0;

        for(int right = 0 ; right < nums.size() ; right++){
            if(nums[right] == 0) zeroes++;

            // Shrink window if we have more than 1 zero
            while(zeroes > 1){
                if(nums[left] == 0) zeroes--;
                left++;
            }

            // Calculate length
            // Normally window size is (right - left + 1).
            // But we MUST delete exactly one element.
            // So the length of 1s is (right - left + 1) - 1 = (right - left).
            maxlen = max(maxlen, right - left);
        }
       return maxlen;
    }
};

int main() {
    Solution sol;

    // Test Case 1: Standard Example
    // [1,1,0,1] -> delete the 0 -> [1,1,1] -> length 3
    vector<int> nums1 = {1, 1, 0, 1};
    cout << "Test Case 1: [1, 1, 0, 1]" << endl;
    cout << "Result: " << sol.longestSubarray(nums1) << endl;
    cout << "-----------------" << endl;

    // Test Case 2: All 1s
    // [1,1,1] -> Must delete one element -> [1,1] -> length 2
    vector<int> nums2 = {1, 1, 1};
    cout << "Test Case 2: [1, 1, 1]" << endl;
    cout << "Result: " << sol.longestSubarray(nums2) << endl;
    cout << "-----------------" << endl;

    // Test Case 3: Multiple zeros
    // [0,1,1,1,0,1,1,0,1]
    // Best is [1,1,1,0,1,1] -> delete 0 -> length 5
    vector<int> nums3 = {0, 1, 1, 1, 0, 1, 1, 0, 1};
    cout << "Test Case 3: [0, 1, 1, 1, 0, 1, 1, 0, 1]" << endl;
    cout << "Result: " << sol.longestSubarray(nums3) << endl;

    return 0;
}