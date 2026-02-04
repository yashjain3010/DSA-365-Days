#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        long long maxSum = 0, sum = 0;
        int i = 0, j = 0;

        unordered_map<int, int> mpp;

        while(j < n){
            sum += nums[j];
            mpp[nums[j]]++;

            if(j - i + 1 < k){
                j++;
            } else if(j - i + 1 == k){
                // If map size is k, it means all elements in the window are distinct
                if(mpp.size() == k){
                    maxSum = max(sum, maxSum);
                }

                // Slide the window: remove the element at i
                sum -= nums[i];
                mpp[nums[i]]--;
                if(mpp[nums[i]] == 0){
                    mpp.erase(nums[i]);
                }
                i++;
                j++;
            }
        }
        return maxSum;
    }
};

int main() {
    Solution sol;

    // Test Case 1: [1,5,4,2,9,9,9], k = 3
    // Windows of size 3:
    // [1,5,4] -> distinct (sum 10) -> max 10
    // [5,4,2] -> distinct (sum 11) -> max 11
    // [4,2,9] -> distinct (sum 15) -> max 15
    // [2,9,9] -> not distinct
    // [9,9,9] -> not distinct
    vector<int> nums1 = {1, 5, 4, 2, 9, 9, 9};
    int k1 = 3;
    cout << "Input: nums=[1,5,4,2,9,9,9], k=3" << endl;
    cout << "Output: " << sol.maximumSubarraySum(nums1, k1) << endl; // Expected: 15

    // Test Case 2: [4,4,4], k = 3
    // [4,4,4] -> not distinct
    vector<int> nums2 = {4, 4, 4};
    int k2 = 3;
    cout << "\nInput: nums=[4,4,4], k=3" << endl;
    cout << "Output: " << sol.maximumSubarraySum(nums2, k2) << endl; // Expected: 0

    // Test Case 3: [1,1,1,7,8,9], k = 3
    // [1,1,1] -> no
    // [1,1,7] -> no
    // [1,7,8] -> distinct (sum 16)
    // [7,8,9] -> distinct (sum 24)
    vector<int> nums3 = {1, 1, 1, 7, 8, 9};
    int k3 = 3;
    cout << "\nInput: nums=[1,1,1,7,8,9], k=3" << endl;
    cout << "Output: " << sol.maximumSubarraySum(nums3, k3) << endl; // Expected: 24

    return 0;
}