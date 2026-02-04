#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int n = nums.size();

        int i = 0, j = n-1;
        while(i < j){
            if(nums[i]%2 == 0){
                i++;
            } else{
                swap(nums[i], nums[j]);
                j--;
            }
        }
        return nums;
    }
};

int main() {
    Solution sol;

    vector<int> nums = {3, 1, 2, 4};
    
    cout << "Original Array: [";
    for (int k = 0; k < nums.size(); ++k) {
        cout << nums[k];
        if (k < nums.size() - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;

    vector<int> result = sol.sortArrayByParity(nums);

    cout << "Sorted Array: [";
    for (int k = 0; k < result.size(); ++k) {
        cout << result[k];
        if (k < result.size() - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;

    return 0;
}