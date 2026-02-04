#include <iostream>
#include <vector>
#include <algorithm>
#include <climits> // For LLONG_MAX

using namespace std;

class Solution {
public:
    long long minCost(vector<int>& nums, vector<int>& cost) {
        int n = nums.size();
        // Store (num, cost) pairs to sort them together
        vector<pair<int, int>> v(n);
        for (int i = 0; i < n; i++) {
            v[i] = {nums[i], cost[i]};
        }

        // Sort by the number
        sort(v.begin(), v.end());

        // pref[i] = cost to move all elements 0...i-1 to position v[i].first
        vector<long long> pref(n, 0);
        long long base = v[0].second;
        for (int i = 1; i < n; i++) {
            pref[i] = pref[i - 1] + base * (long long)(v[i].first - v[i - 1].first);
            base += v[i].second;
        }

        // suf[i] = cost to move all elements i+1...n-1 to position v[i].first
        vector<long long> suf(n, 0);
        base = v[n - 1].second;
        for (int i = n - 2; i >= 0; i--) {
            suf[i] = suf[i + 1] + base * (long long)(v[i + 1].first - v[i].first);
            base += v[i].second;
        }

        // The total cost to converge at v[i] is pref[i] + suf[i]
        // Find the minimum total cost
        long long ans = -1; // Or LLONG_MAX
        for (int i = 0; i < n; i++) {
            long long totalCost = pref[i] + suf[i];
            if (ans == -1 || totalCost < ans) {
                ans = totalCost;
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;

    // Test Case 1: [1, 3, 5, 2], cost = [2, 3, 1, 14]
    // Sorted pairs: (1, 2), (2, 14), (3, 3), (5, 1)
    // Converge at 1: 0 + 14*(2-1) + 3*(3-1) + 1*(5-1) = 0 + 14 + 6 + 4 = 24
    // Converge at 2: 2*(2-1) + 0 + 3*(3-2) + 1*(5-2) = 2 + 0 + 3 + 3 = 8
    // Converge at 3: 2*(3-1) + 14*(3-2) + 0 + 1*(5-3) = 4 + 14 + 0 + 2 = 20
    // Converge at 5: 2*(5-1) + 14*(5-2) + 3*(5-3) + 0 = 8 + 42 + 6 + 0 = 56
    // Min cost = 8
    vector<int> nums1 = {1, 3, 5, 2};
    vector<int> cost1 = {2, 3, 1, 14};
    cout << "Input: nums=[1,3,5,2], cost=[2,3,1,14]\nOutput: " << sol.minCost(nums1, cost1) << endl;

    // Test Case 2: [2, 2, 2], cost = [4, 2, 8]
    // All are already at 2. Cost = 0
    vector<int> nums2 = {2, 2, 2};
    vector<int> cost2 = {4, 2, 8};
    cout << "\nInput: nums=[2,2,2], cost=[4,2,8]\nOutput: " << sol.minCost(nums2, cost2) << endl;

    return 0;
}