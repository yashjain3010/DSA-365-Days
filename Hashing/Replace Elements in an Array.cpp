#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> arrayChange(vector<int>& nums, vector<vector<int>>& operations) {
        // Map to store value -> index
        // This allows us to find WHERE a number is in O(1) time
        unordered_map<int, int> mpp;

        // Step 1: Initialize the map
        for(int i = 0 ; i < nums.size() ; i++){
            mpp[nums[i]] = i;
        }

        // Step 2: Process operations
        for(int i = 0 ; i < operations.size() ; i++){
            int oldVal = operations[i][0];
            int newVal = operations[i][1];

            // 1. Find the index of the number to be replaced
            int position = mpp[oldVal];

            // 2. Update the actual array
            nums[position] = newVal;

            // 3. Update the map:
            // The new value is now at 'position'
            mpp[newVal] = position;
            
            // Optional: Remove the old value from map to save memory
            // mpp.erase(oldVal); 
        }
        return nums;
    }
};

// Helper to print vector
void printVector(const vector<int>& v) {
    cout << "[ ";
    for (int x : v) cout << x << " ";
    cout << "]" << endl;
}

int main() {
    Solution sol;

    // Test Case 1
    // nums = [1,2,4,6], operations = [[1,3],[4,7],[6,1]]
    // 1 -> 3 : [3, 2, 4, 6]
    // 4 -> 7 : [3, 2, 7, 6]
    // 6 -> 1 : [3, 2, 7, 1]
    vector<int> nums = {1, 2, 4, 6};
    vector<vector<int>> operations = {{1, 3}, {4, 7}, {6, 1}};

    cout << "Test Case 1:" << endl;
    vector<int> res = sol.arrayChange(nums, operations);
    printVector(res);

    return 0;
}