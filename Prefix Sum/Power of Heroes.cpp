#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

class Solution {
public:
    typedef long long ll;
    int mod = 1e9 + 7;
    int sumOfPower(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int n = nums.size();
        // ans must be long long to avoid overflow during accumulation
        ll ans = 0; 
        // result should store long long for squared values
        vector<ll> result(n); 

        for(int i = 0 ; i < n ; i++){
            ll x = nums[i];
            ll y = (x * x) % mod;
            result[i] = y;
            ll z = (y * x) % mod;
            ans = (ans + z) % mod;
        }

        ll prev = nums[0];
        for(int i = 1 ; i < n ; i++){
            // (sum of mins of all subseqs ending before i) * (nums[i]^2)
            ll temp = (prev * result[i]) % mod;
            ans = (ans + temp) % mod;
            // Update prev to be sum of mins of all subseqs ending at or before i
            prev = (prev * 2 + nums[i]) % mod;
        }
        // Return final answer cast to int
        return (int)ans;
    }
};

int main() {
    Solution sol;

    // Test Case 1: [2, 1, 4]
    // Sorted: [1, 2, 4]
    // Subsequences:
    // [1]: max=1, min=1. P=1^2*1 = 1
    // [2]: max=2, min=2. P=2^2*2 = 8
    // [4]: max=4, min=4. P=4^2*4 = 64
    // [1, 2]: max=2, min=1. P=2^2*1 = 4
    // [1, 4]: max=4, min=1. P=4^2*1 = 16
    // [2, 4]: max=4, min=2. P=4^2*2 = 32
    // [1, 2, 4]: max=4, min=1. P=4^2*1 = 16
    // Total = 1 + 8 + 64 + 4 + 16 + 32 + 16 = 141
    vector<int> nums1 = {2, 1, 4};
    cout << "Input: [2, 1, 4] | Output: " << sol.sumOfPower(nums1) << endl;

    // Test Case 2: [1, 1]
    // Sorted: [1, 1]
    // [1]: P=1
    // [1]: P=1
    // [1, 1]: P=1
    // Total = 3
    vector<int> nums2 = {1, 1};
    cout << "Input: [1, 1] | Output: " << sol.sumOfPower(nums2) << endl;

    return 0;
}