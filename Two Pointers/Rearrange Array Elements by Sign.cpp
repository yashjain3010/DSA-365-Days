#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        int posIndex = 0;
        int negIndex = 1;

        vector<int> ans(n, 0);

        for (int i = 0; i < n; i++) {
            if (nums[i] >= 0) {
                ans[posIndex] = nums[i];
                posIndex += 2;
            } else{
                ans[negIndex] = nums[i];
                negIndex += 2;
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;

    vector<int> nums = {3, 1, -2, -5, 2, -4};
    
    cout << "Original Array: [";
    for (int k = 0; k < nums.size(); ++k) {
        cout << nums[k];
        if (k < nums.size() - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;

    vector<int> result = sol.rearrangeArray(nums);

    cout << "Rearranged Array: [";
    for (int k = 0; k < result.size(); ++k) {
        cout << result[k];
        if (k < result.size() - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;

    return 0;
}

