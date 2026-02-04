#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size();
        vector<int> ans(n, 0);

        int startIndex = 0;
        int endIndex = n - 1;

        // One pass to place elements smaller than pivot
        for (int i = 0; i < n; i++) {
            if (nums[i] < pivot) {
                ans[startIndex] = nums[i];
                startIndex++;
            }
        }

        // One pass to place elements larger than pivot (from the end)
        for (int j = n - 1; j >= 0; j--) {
            if (nums[j] > pivot) {
                ans[endIndex] = nums[j];
                endIndex--;
            }
        }

        // Fill the remaining space with the pivot
        while (startIndex <= endIndex) {
            ans[startIndex] = pivot;
            startIndex++;
        }
        return ans;
    }
};

int main() {
    Solution sol;

    vector<int> nums = {9, 12, 5, 10, 14, 3, 10};
    int pivot = 10;
    
    cout << "Original Array: [";
    for (int k = 0; k < nums.size(); ++k) {
        cout << nums[k];
        if (k < nums.size() - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;
    
    cout << "Pivot: " << pivot << endl;

    vector<int> result = sol.pivotArray(nums, pivot);

    cout << "Pivoted Array: [";
    for (int k = 0; k < result.size(); ++k) {
        cout << result[k];
        if (k < result.size() - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;

    return 0;
}