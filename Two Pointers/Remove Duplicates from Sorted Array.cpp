#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) {
            return 0;
        }

        int j = 0;
        for (int i = 1; i < n; i++) {
            if (nums[i] != nums[j]) {
                j++;
                nums[j] = nums[i];
            }
        }
        return j + 1;
    }
};

int main() {
    Solution sol;

    vector<int> nums = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    
    cout << "Original Array: [";
    for (int k = 0; k < nums.size(); ++k) {
        cout << nums[k];
        if (k < nums.size() - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;

    int newLength = sol.removeDuplicates(nums);

    cout << "New Length: " << newLength << endl;

    cout << "Array after removing duplicates: [";
    for (int k = 0; k < newLength; ++k) {
        cout << nums[k];
        if (k < newLength - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;

    return 0;
}