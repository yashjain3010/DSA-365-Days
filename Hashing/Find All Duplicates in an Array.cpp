#include <iostream>
#include <vector>
#include <unordered_map>
#include <cmath> // For abs() in the optimized version

using namespace std;

class Solution {
public:
    // Your Solution: Map Approach
    // Time: O(N), Space: O(N)
    vector<int> findDuplicates(vector<int>& nums) {
        unordered_map<int, int> mpp;
        vector<int> ans;

        for(int it : nums){
            mpp[it]++;
        }

        for(auto& pair : mpp){
            // Problem constraint usually says duplicates appear "twice",
            // so checking == 2 is correct.
            if(pair.second == 2){
                ans.push_back(pair.first);
            }
        }
        return ans;
    }

    // INTERVIEW OPTIMIZATION: Index Marking Approach
    // Time: O(N), Space: O(1) (excluding output vector)
    vector<int> findDuplicatesOptimized(vector<int>& nums) {
        vector<int> ans;
        
        for(int i = 0; i < nums.size(); i++) {
            // Get the value as an index (0-based)
            // Use abs() because we might have marked it negative previously
            int index = abs(nums[i]) - 1;

            // If the number at this index is already negative, 
            // it means we have seen 'index + 1' before.
            if(nums[index] < 0) {
                ans.push_back(index + 1);
            } else {
                // Mark it as visited by negating the number at that index
                nums[index] = -nums[index];
            }
        }
        return ans;
    }
};

// Helper to print vectors
void printVector(const vector<int>& v) {
    cout << "[ ";
    for(int x : v) cout << x << " ";
    cout << "]" << endl;
}

int main() {
    Solution sol;

    // Test Case 1
    // 4 appears twice, 3 appears twice, 2 appears twice
    vector<int> nums1 = {4, 3, 2, 7, 8, 2, 3, 1};
    cout << "Test Case 1 (Map Approach):" << endl;
    vector<int> res1 = sol.findDuplicates(nums1);
    printVector(res1);
    cout << "-----------------" << endl;

    // Test Case 2 (Using Optimized O(1) Space)
    // We must pass a copy or reset vector because the optimized function modifies it
    vector<int> nums2 = {4, 3, 2, 7, 8, 2, 3, 1}; 
    cout << "Test Case 1 (Optimized Space Approach):" << endl;
    vector<int> res2 = sol.findDuplicatesOptimized(nums2);
    printVector(res2);

    return 0;
}