#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        if (n == 0) return;

        k = k % n;
        if (k == 0) return;

        // Using reverse
        // 1. Reverse the whole array
        reverse(nums.begin(), nums.end());
        // 2. Reverse the first k elements
        reverse(nums.begin(), nums.begin() + k);
        // 3. Reverse the remaining n-k elements
        reverse(nums.begin() + k, nums.end());
        
        /* // Your original logic (which also works, but reverse is more common)
        vector<int> temp(n-k, 0);

        for(int i = 0 ; i < n-k ; i++){
            temp[i] = nums[i];
        } 

        for(int i = n-k ; i < n ; i++){
            nums[i-n+k] = nums[i];
        }

        for(int i = k ; i < n ; i++){
            nums[i] = temp[i-k];
        }
        */
    }
};

int main() {
    Solution sol;

    vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
    int k = 3;
    
    cout << "Original Array: [";
    for (int i = 0; i < nums.size(); ++i) {
        cout << nums[i];
        if (i < nums.size() - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;
    
    cout << "K: " << k << endl;

    sol.rotate(nums, k);

    cout << "Rotated Array: [";
    for (int i = 0; i < nums.size(); ++i) {
        cout << nums[i];
        if (i < nums.size() - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;

    return 0;
}