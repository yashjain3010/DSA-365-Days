#include <iostream>
#include <vector>
#include <set>
#include <iterator> // Required for std::next and std::prev

using namespace std;

class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        // Initialize the sliding window with the first k elements
        multiset<int> window(nums.begin(), nums.begin() + k);
        
        // Find the middle element iterator
        auto mid = next(window.begin(), k / 2);
        vector<double> res;

        for (int i = k;; i++) {
            // Calculate median based on whether k is odd or even
            if (k % 2)
                res.push_back((double)*mid);
            else {
                res.push_back(((double)*mid + *prev(mid)) / 2.0);
            }

            // Break if we have processed all elements
            if (i == nums.size())
                break;
            
            // Insert the new element coming into the window
            window.insert(nums[i]);

            // Adjust mid pointer if the new element is smaller than current mid
            if (nums[i] < *mid) {
                mid--;
            }

            // Adjust mid pointer if the element leaving the window was smaller or equal to current mid
            if (nums[i - k] <= *mid) {
                mid++;
            }

            // Remove the element leaving the window
            // Note: We use lower_bound to find the iterator to remove only ONE instance 
            // of the value (in case of duplicates)
            window.erase(window.lower_bound(nums[i - k]));
        }
        return res;
    }
};

int main() {
    Solution sol;

    // Test Case: Based on standard LeetCode example
    vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;

    cout << "Input Array: ";
    for(int n : nums) cout << n << " ";
    cout << "\nWindow Size (k): " << k << endl;

    // Run the function
    vector<double> result = sol.medianSlidingWindow(nums, k);

    // Print results
    cout << "Output Medians: ";
    cout << "[ ";
    for (size_t i = 0; i < result.size(); i++) {
        cout << result[i];
        if(i < result.size() - 1) cout << ", ";
    }
    cout << " ]" << endl;

    return 0;
}