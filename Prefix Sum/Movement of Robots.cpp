#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>

using namespace std;

class Solution {
public:
    int sumDistance(vector<int>& nums, string s, int d) {
        vector<long long> newNums;
        long long mod = 1e9 + 7;

        // Calculate final positions directly into the long long vector
        for(int i = 0; i < nums.size(); i++){
            if(s[i] == 'L'){
                newNums.push_back((long long)nums[i] - d);
            } else{
                newNums.push_back((long long)nums[i] + d); 
            }
        }

        sort(newNums.begin(), newNums.end());

        long long distance = 0, prefixSum = 0;

        for(int i = 0 ; i < newNums.size() ; i++){
            long long currentPos = newNums[i];
            
            // 1. Calculate term: (i * currentPos - prefixSum)
            // We use (a - b) % mod = (a%mod - b%mod + mod) % mod
            
            // (i * currentPos) % mod, handling potential negative currentPos
            long long a = (1LL * i * (currentPos % mod + mod)) % mod; 
            long long b = prefixSum; // prefixSum is already in [0, mod-1]
            
            long long term = (a - b + mod) % mod;
            
            // 2. Add to total distance
            distance = (distance + term) % mod;
            
            // 3. Update prefixSum, handling potential negative currentPos
            // (a + b) % mod = (a%mod + b%mod) % mod
            prefixSum = (prefixSum + (currentPos % mod + mod) % mod) % mod;
        }
        return (int)distance;
    }
};

int main() {
    Solution sol;

    // Test Case 1: [-2, 0, 2], s = "RLL", d = 3
    // Final pos: [-2+3, 0-3, 2-3] = [1, -3, -1]
    // Sorted: [-3, -1, 1]
    // Distances: |-1 - (-3)| = 2
    //            | 1 - (-3)| = 4
    //            | 1 - (-1)| = 2
    // Total = 2 + 4 + 2 = 8
    vector<int> nums1 = {-2, 0, 2};
    string s1 = "RLL";
    int d1 = 3;
    cout << "Input: [-2, 0, 2], \"RLL\", 3\nOutput: " << sol.sumDistance(nums1, s1, d1) << endl;

    // Test Case 2: [1, 0], s = "RL", d = 2
    // Final pos: [1+2, 0-2] = [3, -2]
    // Sorted: [-2, 3]
    // Distance: |3 - (-2)| = 5
    vector<int> nums2 = {1, 0};
    string s2 = "RL";
    int d2 = 2;
    cout << "Input: [1, 0], \"RL\", 2\nOutput: " << sol.sumDistance(nums2, s2, d2) << endl;

    return 0;
}