#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        unordered_map<int, int> mpp;

        // Step 1: Count frequency of each number
        for(int it : nums){
            mpp[it]++;
        }

        int sum = 0;

        // Step 2: Sum numbers that appear exactly once
        for(auto& it : mpp){
            if(it.second == 1){
                sum += it.first;
            }
        }
        return sum;
    }
};

int main() {
    Solution sol;

    // Test Case 1: Unique elements are 1 and 3. Sum = 4.
    // [1, 2, 3, 2] -> 2 appears twice. 1 and 3 appear once.
    vector<int> nums1 = {1, 2, 3, 2};
    cout << "Test Case 1: " << sol.sumOfUnique(nums1) << endl;

    // Test Case 2: No unique elements. Sum = 0.
    // [1, 1, 1, 1]
    vector<int> nums2 = {1, 1, 1, 1};
    cout << "Test Case 2: " << sol.sumOfUnique(nums2) << endl;

    // Test Case 3: All unique. Sum = 1+2+3+4+5 = 15.
    vector<int> nums3 = {1, 2, 3, 4, 5};
    cout << "Test Case 3: " << sol.sumOfUnique(nums3) << endl;

    return 0;
}