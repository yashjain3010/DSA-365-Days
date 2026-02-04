#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int n = nums.size();

        // This is a convoluted way to do it, but it matches the user's logic.
        // It modifies nums AND builds ans at the same time.
        
        // 1. Apply operations to nums
        for(int i = 0 ; i < n-1 ; i++){
            if(nums[i] == nums[i+1]){
                nums[i] = nums[i]*2;
                nums[i+1] = 0;
            }
        }
        
        // 2. Move zeros to the end in nums
        vector<int> ans(n, 0);
        int i = 0;
        for(int j = 0 ; j < n ; j++){
            if(nums[j] != 0){
                ans[i] = nums[j];
                i++;
            }
        }
        
        return ans;
    }
};

int main() {
    Solution sol;

    vector<int> nums = {1, 2, 2, 1, 1, 0};
    
    cout << "Original Array: [";
    for (int i = 0; i < nums.size(); ++i) {
        cout << nums[i];
        if (i < nums.size() - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;

    vector<int> result = sol.applyOperations(nums);

    cout << "Result Array: [";
    for (int i = 0; i < result.size(); ++i) {
        cout << result[i];
        if (i < result.size() - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;

    return 0;
}