#include <iostream>
#include <vector>
#include <algorithm> // For max
#include <limits>    // For numeric_limits

using namespace std;

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double sum = 0;
        // Initialize to lowest possible double to handle cases where all averages are negative
        double MaxSumAv = numeric_limits<double>::lowest();

        for(int i = 0 ; i < nums.size() ; i++){
            // Add current element to the window sum
            sum += nums[i];

            // Check if window has reached size k
            if(i >= k-1){
                // Update maximum average
                MaxSumAv = max(MaxSumAv, sum/k);
                
                // Remove the element that is sliding out of the window
                // The window ending at 'i' starts at 'i - k + 1'.
                // We remove that element to prepare 'sum' for the next iteration.
                sum -= nums[i-k+1];
            }
        }
        return MaxSumAv;
    }
};

int main() {
    Solution sol;

    // Test Case 1: [1, 12, -5, -6, 50, 3], k = 4
    // Windows:
    // [1, 12, -5, -6] -> sum = 2, avg = 0.5
    // [12, -5, -6, 50] -> sum = 51, avg = 12.75
    // [-5, -6, 50, 3] -> sum = 42, avg = 10.5
    // Max avg = 12.75
    vector<int> nums1 = {1, 12, -5, -6, 50, 3};
    int k1 = 4;
    cout << "Input: [1, 12, -5, -6, 50, 3], k=4" << endl;
    cout << "Output: " << sol.findMaxAverage(nums1, k1) << endl; 

    // Test Case 2: [5], k = 1
    vector<int> nums2 = {5};
    int k2 = 1;
    cout << "\nInput: [5], k=1" << endl;
    cout << "Output: " << sol.findMaxAverage(nums2, k2) << endl; 

    // Test Case 3: [-1], k = 1
    vector<int> nums3 = {-1};
    int k3 = 1;
    cout << "\nInput: [-1], k=1" << endl;
    cout << "Output: " << sol.findMaxAverage(nums3, k3) << endl;

    return 0;
}