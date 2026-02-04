#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> temp; // Stores the sum of subarray of size k starting at each index
        int sum = 0;

        // Calculate all window sums of size k
        for(int i = 0, j = 0; i < n; i++){
            sum += nums[i];
            if(i - j + 1 == k){
                temp.push_back(sum);
                sum -= nums[j];
                j++;
            }
        }
        
        // n is now the number of valid windows
        n = temp.size();
        
        // left[i] stores the index of the max sum window in range [0...i]
        // right[i] stores the index of the max sum window in range [i...n-1]
        vector<int> left(n, 0), right(n, 0), ans;
        int leftSum = 0, rightSum = 0;

        // Fill left and right arrays (Dynamic Programming)
        for(int i = 0; i < n; i++){
            // For Left: we want lexicographically smallest index, so strictly > updates
            if(temp[i] > leftSum){
                left[i] = i;
                leftSum = temp[i];
            }
            else {
                left[i] = left[i-1];
            }
            
            // For Right: iterating backwards. 
            // If sums are equal, we want the smaller index (which is the current one, n-i-1), 
            // so >= is correct here because we are moving leftwards.
            if(temp[n - i - 1] >= rightSum){
                right[n - i - 1] = n - i - 1;
                rightSum = temp[n - i - 1];
            }
            else {
                right[n - i - 1] = right[n - i];
            }
        }

        sum = 0;
        // Iterate through possible positions for the MIDDLE subarray
        // The middle subarray can start from index k to n-k-1 (in terms of window indices)
        // to ensure room for left and right subarrays.
        for(int i = k; i < n - k; i++){
            int tempSum = temp[i] + temp[left[i - k]] + temp[right[i + k]];
            if(tempSum > sum){
                ans = {left[i - k], i, right[i + k]};
                sum = tempSum;
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;

    // Test Case: [1,2,1,2,6,7,5,1], k = 2
    // Expected triplets: [1,2] (sum 3), [2,6] (sum 8), [7,5] (sum 12)? No.
    // Optimal: [1,2] (idx 0), [6,7] (idx 3), [5,1] (idx 5)? Sum: 3 + 13 + 6 = 22
    // Or: [1,2], [2,6], [7,5] -> 3+8+12 = 23. Indices: 0, 3, 5.
    vector<int> nums = {1, 2, 1, 2, 6, 7, 5, 1};
    int k = 2;

    cout << "Input Array: ";
    cout << "[ ";
    for(int n : nums) cout << n << " ";
    cout << "]" << endl;
    cout << "k: " << k << endl;

    // Run the function
    vector<int> result = sol.maxSumOfThreeSubarrays(nums, k);

    // Print results
    cout << "Output Indices: [ ";
    for (size_t i = 0; i < result.size(); i++) {
        cout << result[i];
        if(i < result.size() - 1) cout << ", ";
    }
    cout << " ]" << endl;

    return 0;
}