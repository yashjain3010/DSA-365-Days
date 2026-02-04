#include <iostream>
#include <vector>
#include <numeric>
#include <cmath>

using namespace std;

class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();
        int left = 0, right = 0;
        vector<int> ans(n,0);
        
        for(int i = 1 ; i < n ; i++){
            right += nums[i];
        }

        for(int i=0 ; i < n ; i++){
            ans[i] = abs(left - right);
            
            left += nums[i];
            
            if(i+1 < n) {
                right -= nums[i+1];
            } else {
                right = 0;
            }
        }
      return ans;
    }
};

int main() {
    Solution sol;

    vector<int> nums = {10, 4, 8, 3};
    
    cout << "Input Array: [";
    for (int i = 0; i < nums.size(); ++i) {
        cout << nums[i] << (i < nums.size() - 1 ? ", " : "");
    }
    cout << "]" << endl;

    vector<int> result = sol.leftRightDifference(nums);

    cout << "Result Array: [";
    for (int i = 0; i < result.size(); ++i) {
        cout << result[i] << (i < result.size() - 1 ? ", " : "");
    }
    cout << "]" << endl;

    return 0;
}