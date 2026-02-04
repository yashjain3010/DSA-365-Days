#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set> // Included for the optimization tip

using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        // Your original approach using Map
        unordered_map<int, int> mpp;

        for (int it : nums){
            if(mpp[it] >= 1){
                return true;
            }
            mpp[it]++;
        }
        return false;
    }
    
    // Optimization Tip: Use unordered_set to save memory overhead
    bool containsDuplicateOptimized(vector<int>& nums) {
        unordered_set<int> seen;
        for (int num : nums) {
            // .count() checks if it exists in O(1)
            if (seen.count(num)) {
                return true;
            }
            seen.insert(num);
        }
        return false;
    }
};

int main() {
    Solution sol;

    // Test Case 1: Duplicates exist
    vector<int> nums1 = {1, 2, 3, 1};
    cout << "Test Case 1 (Expected True): " << (sol.containsDuplicate(nums1) ? "True" : "False") << endl;

    // Test Case 2: No duplicates
    vector<int> nums2 = {1, 2, 3, 4};
    cout << "Test Case 2 (Expected False): " << (sol.containsDuplicate(nums2) ? "True" : "False") << endl;

    // Test Case 3: Multiple duplicates
    vector<int> nums3 = {1, 1, 1, 3, 3, 4, 3, 2, 4, 2};
    cout << "Test Case 3 (Expected True): " << (sol.containsDuplicate(nums3) ? "True" : "False") << endl;

    return 0;
}