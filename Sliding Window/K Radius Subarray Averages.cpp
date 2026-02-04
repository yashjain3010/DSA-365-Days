#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n = nums.size();
        
        // Handle empty or small edge cases if necessary, 
        // though the loop logic below naturally handles them.
        if (n == 0) return {};

        // Use long long for prefix sums to prevent integer overflow
        vector<long long> prefixSum(n, 0);

        prefixSum[0] = nums[0];

        for(int i = 1 ; i < n ; i++){
            prefixSum[i] = nums[i] + prefixSum[i-1];
        }

        // Initialize result with -1
        vector<int> ans(n, -1);

        for(int i = 0 ; i < n ; i++){
            // Check if a window of radius k centered at i exists
            // We cast k to 1LL to ensure the addition doesn't overflow if indices were very large,
            // though for standard vector sizes int is usually fine.
            if(i - k >= 0 && i + k < n){
                long long nextSum = prefixSum[i+k];
                long long prevSum = (i-k-1 >= 0 ? prefixSum[i-k-1] : 0);

                // Calculate sum of window [i-k, i+k]
                long long windowSum = nextSum - prevSum;
                
                // Calculate average (integer division truncates towards zero)
                ans[i] = windowSum / (2LL * k + 1);
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;

    // Test Case 1
    // nums = [7,4,3,9,1,8,5,2,6], k = 3
    // n = 9. Window size = 2*3+1 = 7.
    // Center indices that have enough neighbors: 3, 4, 5
    // i=3 (val 9): sum(7+4+3+9+1+8+5) = 37. Avg = 37/7 = 5
    // i=4 (val 1): sum(4+3+9+1+8+5+2) = 32. Avg = 32/7 = 4
    // i=5 (val 8): sum(3+9+1+8+5+2+6) = 34. Avg = 34/7 = 4
    // Result: [-1, -1, -1, 5, 4, 4, -1, -1, -1]
    vector<int> nums1 = {7, 4, 3, 9, 1, 8, 5, 2, 6};
    int k1 = 3;
    vector<int> result1 = sol.getAverages(nums1, k1);

    cout << "Input: nums=[7,4,3,9,1,8,5,2,6], k=3" << endl;
    cout << "Output: [";
    for (size_t i = 0; i < result1.size(); ++i) {
        cout << result1[i] << (i < result1.size() - 1 ? ", " : "");
    }
    cout << "]" << endl; 

    // Test Case 2
    // nums = [100000], k = 0
    // Window size = 1. Center i=0 works. Avg = 100000/1 = 100000.
    vector<int> nums2 = {100000};
    int k2 = 0;
    vector<int> result2 = sol.getAverages(nums2, k2);

    cout << "\nInput: nums=[100000], k=0" << endl;
    cout << "Output: [";
    for (size_t i = 0; i < result2.size(); ++i) {
        cout << result2[i] << (i < result2.size() - 1 ? ", " : "");
    }
    cout << "]" << endl; 

    // Test Case 3
    // nums = [8], k = 100
    // Window too large. Output should be [-1].
    vector<int> nums3 = {8};
    int k3 = 100;
    vector<int> result3 = sol.getAverages(nums3, k3);

    cout << "\nInput: nums=[8], k=100" << endl;
    cout << "Output: [";
    for (size_t i = 0; i < result3.size(); ++i) {
        cout << result3[i] << (i < result3.size() - 1 ? ", " : "");
    }
    cout << "]" << endl; 

    return 0;
}