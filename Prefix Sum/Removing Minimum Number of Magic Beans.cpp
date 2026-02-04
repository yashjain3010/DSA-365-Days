#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

class Solution {
public:
    long long minimumRemoval(vector<int>& beans) {
        int n = beans.size();
        // Sort is essential for this approach
        sort(beans.begin(), beans.end());
        
        if(n == 1) return 0;

        vector<long long> pref(n, 0), suf(n, 0);

        // Precompute prefix sums
        pref[0] = beans[0];
        for(int i = 1 ; i < n ; i++){
            pref[i] = pref[i-1] + beans[i];
        }

        // Precompute suffix sums
        suf[n-1] = beans[n-1];
        for(int i = n-2 ; i >= 0 ; i--){
            suf[i] = suf[i+1] + beans[i];
        }

        long long ans = -1; // Initialize with a sentinel or a very large number

        for(int i = 0 ; i < n ; i++){
            // Cost to make everything before index i zero
            long long prevSum = ((i == 0) ? 0 : pref[i-1]);
            // Sum of everything from i onwards
            long long aheadSum = suf[i];
            
            // The cost if we make all remaining bags equal to beans[i]:
            // We keep (n-i) bags, each with beans[i] beans.
            // Total kept = (n-i) * beans[i]
            // Removals needed for ahead part = aheadSum - kept
            // Total removals = prevSum + (aheadSum - kept)
            long long temp = prevSum + aheadSum - (long long)(n-i) * (long long)beans[i];
            
            if (ans == -1 || temp < ans) {
                ans = temp;
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;

    // Test Case 1: [4, 1, 6, 5] -> Expected: 4
    // Sorted: [1, 4, 5, 6]
    // If target is 4: remove 1 (cost 1), reduce 5->4 (cost 1), reduce 6->4 (cost 2). Total = 1+1+2 = 4.
    vector<int> beans1 = {4, 1, 6, 5};
    cout << "Input: [4, 1, 6, 5] | Minimum Removal: " << sol.minimumRemoval(beans1) << endl;

    // Test Case 2: [2, 10, 3, 2] -> Expected: 7
    // Sorted: [2, 2, 3, 10]
    // If target is 2: keep [2, 2], reduce 3->2 (cost 1), reduce 10->2 (cost 8). Total = 0+0+1+8 = 9.
    // If target is 3: remove [2, 2] (cost 4), keep 3, reduce 10->3 (cost 7). Total = 4+0+7 = 11.
    // Wait, optimal is target 3? No, let's re-read problem carefully. 
    // Actually, if target is 2: we keep all 4 bags. Cost = (2-2)+(2-2)+(3-2)+(10-2) = 0+0+1+8 = 9.
    // If target is 3: remove 2, 2. Cost = 2+2 + (3-3) + (10-3) = 4 + 0 + 7 = 11.
    // If target is 10: remove 2,2,3. Cost = 2+2+3 + (10-10) = 7. -> WINNER
    vector<int> beans2 = {2, 10, 3, 2};
    cout << "Input: [2, 10, 3, 2] | Minimum Removal: " << sol.minimumRemoval(beans2) << endl;

    return 0;
}