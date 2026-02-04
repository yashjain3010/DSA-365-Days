#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;

        int left = 0;
        int right = k;

        // Map stores the frequency of elements in the current window
        // Because map is sorted, the last element (--window.end()) is always the maximum
        map<int, int> window;

        // Initialize the first window
        for(int i = 0 ; i < k ; i++){
            ++window[nums[i]];
        }

        // Add the max of the first window
        res.push_back((--window.end()) -> first);

        // Slide the window
        while(right < nums.size()){
            // Remove the element going out of the window (nums[left])
            if(--window[nums[left]] == 0){
                window.erase(nums[left]);
            }

            // Add the new element coming into the window (nums[right])
            ++window[nums[right]];
            
            // Add the current max to results
            res.push_back((--window.end()) -> first);

            ++left;
            ++right;
        }
        return res;
    }
};

int main() {
    Solution sol;

    // Test Case
    vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;

    cout << "Input Array: ";
    for(int n : nums) cout << n << " ";
    cout << "\nWindow Size (k): " << k << endl;

    // Run the function
    vector<int> result = sol.maxSlidingWindow(nums, k);

    // Print results
    cout << "Output Maximums: [ ";
    for (size_t i = 0; i < result.size(); i++) {
        cout << result[i];
        if(i < result.size() - 1) cout << ", ";
    }
    cout << " ]" << endl;

    return 0;
}