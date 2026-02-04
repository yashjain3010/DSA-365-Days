#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int ans = 0, count = 0;
        int i = 0, j = 0;

        while(j < nums.size()){
            // If current number is odd, decrement k
            if(nums[j] % 2 != 0){
                k--;
                // Reset count because we have a new odd number, 
                // so previous valid prefix combinations are no longer valid for this new window context
                count = 0;
            }

            // When we have exactly k odd numbers (k becomes 0)
            while(k == 0){
                // If the number at the left pointer is odd, increment k 
                // (effectively saying "if we remove this, we no longer have k odds")
                if(nums[i] % 2 != 0){
                    k++;
                }
                // Count how many valid subarrays start from index 'i' for the current end 'j'
                count++;
                i++;
            }

            // Add the number of valid subarrays found for this position of 'j'
            ans += count;
            j++;
        }
        return ans;
    }
};

int main() {
    Solution sol;

    // Test Case 1: Standard Example
    // [1,1,2,1,1], k = 3
    // Valid subarrays: [1,1,2,1] and [1,2,1,1]
    vector<int> nums1 = {1, 1, 2, 1, 1};
    int k1 = 3;

    cout << "Test Case 1:" << endl;
    cout << "Input: [ ";
    for(int n : nums1) cout << n << " ";
    cout << "], k: " << k1 << endl;
    cout << "Number of Nice Subarrays: " << sol.numberOfSubarrays(nums1, k1) << endl;
    cout << "-----------------" << endl;

    // Test Case 2: Even numbers only
    // [2,4,6], k = 1
    // Expected: 0
    vector<int> nums2 = {2, 4, 6};
    int k2 = 1;

    cout << "Test Case 2:" << endl;
    cout << "Input: [ ";
    for(int n : nums2) cout << n << " ";
    cout << "], k: " << k2 << endl;
    cout << "Number of Nice Subarrays: " << sol.numberOfSubarrays(nums2, k2) << endl;
    cout << "-----------------" << endl;

    // Test Case 3: Mixed
    // [2,2,2,1,2,2,1,2,2,2], k = 2
    // The pattern involves counting the even numbers surrounding the odds.
    vector<int> nums3 = {2, 2, 2, 1, 2, 2, 1, 2, 2, 2};
    int k3 = 2;

    cout << "Test Case 3:" << endl;
    cout << "Input: [ ";
    for(int n : nums3) cout << n << " ";
    cout << "], k: " << k3 << endl;
    cout << "Number of Nice Subarrays: " << sol.numberOfSubarrays(nums3, k3) << endl;

    return 0;
}