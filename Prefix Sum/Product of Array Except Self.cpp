#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();

        vector<int> ans(n);
        vector<int> pre(n, 1), suf(n, 1);

        for(int i = 1 ; i < n ; i++){
            pre[i] = pre[i-1] * nums[i-1];
        }

        for(int i = n-2 ; i >= 0 ; i--){
            suf[i] = suf[i+1] * nums[i+1];
        }

        for(int i = 0 ; i < n ; i++){
            ans[i] = pre[i] * suf[i];
        }

        return ans;
    }
};

int main() {
    Solution sol;

    // Test Case 1: [1, 2, 3, 4] -> Expected: [24, 12, 8, 6]
    vector<int> nums1 = {1, 2, 3, 4};
    vector<int> result1 = sol.productExceptSelf(nums1);

    cout << "Input: [1, 2, 3, 4]\nOutput: [";
    for (int i = 0; i < result1.size(); ++i) {
        cout << result1[i] << (i < result1.size() - 1 ? ", " : "");
    }
    cout << "]" << endl;

    // Test Case 2: [-1, 1, 0, -3, 3] -> Expected: [0, 0, 9, 0, 0]
    vector<int> nums2 = {-1, 1, 0, -3, 3};
    vector<int> result2 = sol.productExceptSelf(nums2);

    cout << "\nInput: [-1, 1, 0, -3, 3]\nOutput: [";
    for (int i = 0; i < result2.size(); ++i) {
        cout << result2[i] << (i < result2.size() - 1 ? ", " : "");
    }
    cout << "]" << endl;

    return 0;
}