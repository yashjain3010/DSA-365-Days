#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size();
        int j = 0;
        for(int i = 0 ; i < n ; i++){
            if(nums[i] != val){
                nums[j] = nums[i];
                j++;
            }
        }
        return j;
    }
};

int main() {
    Solution sol;

    vector<int> nums = {3, 2, 2, 3};
    int val = 3;
    
    cout << "Original Array: [";
    for (int k = 0; k < nums.size(); ++k) {
        cout << nums[k];
        if (k < nums.size() - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;
    
    cout << "Value to remove: " << val << endl;

    int newLength = sol.removeElement(nums, val);

    cout << "New Length: " << newLength << endl;

    cout << "Array after removing element: [";
    for (int k = 0; k < newLength; ++k) {
        cout << nums[k];
        if (k < newLength - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;

    return 0;
}