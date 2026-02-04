#include <iostream>
#include <vector>
#include <numeric> // For std::partial_sum

using namespace std;

class Solution {
public:

    // Helper function implementing the difference array technique
    vector<int> difference_array_technique(vector<vector<int>>& queries, int n) {
        vector<int> diff(n, 0);

        for (const auto& q : queries) {
            int l = q[0];
            int r = q[1];
            int val = q[2];

            diff[l] += val;
            if (r + 1 < n) {
                diff[r + 1] -= val;
            }
        }

        // Convert the difference array into the prefix sum array
        for (int i = 1; i < n; i++) {
            diff[i] += diff[i - 1];
        }

        return diff;
    }
    
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        // The problem states locations are [0, 1000]
        const int n_locations = 1001; 
        
        vector<vector<int>> queries;

        for (auto& trip : trips) {
            int passengers = trip[0];
            int start = trip[1];
            // The drop-off location is exclusive, so the last stop with
            // these passengers is (end - 1).
            int end = trip[2] - 1; 

            queries.push_back({start, end, passengers});
        }

        // Get the passenger count at each location from 0 to 1000
        vector<int> passenger_counts = difference_array_technique(queries, n_locations);

        // Check if any location exceeds capacity
        for (int p : passenger_counts) {
            if (p > capacity) return false;
        }
        return true;
    }
};

int main() {
    Solution sol;
    cout << boolalpha; // Print "true" or "false" instead of 1 or 0

    // Test Case 1: Fails (5 passengers at time 3)
    // [[2,1,5], [3,3,7]], capacity = 4
    // Loc 1-4: 2 pass
    // Loc 3-6: 3 pass
    // Loc 3-4: 2+3 = 5 pass -> > 4
    vector<vector<int>> trips1 = {{2, 1, 5}, {3, 3, 7}};
    int capacity1 = 4;
    cout << "Input: {{2,1,5}, {3,3,7}}, capacity=4\nOutput: " << sol.carPooling(trips1, capacity1) << endl;

    // Test Case 2: Succeeds
    // [[2,1,5], [3,3,7]], capacity = 5
    // Max passengers is 5, which is <= 5
    vector<vector<int>> trips2 = {{2, 1, 5}, {3, 3, 7}};
    int capacity2 = 5;
    cout << "\nInput: {{2,1,5}, {3,3,7}}, capacity=5\nOutput: " << sol.carPooling(trips2, capacity2) << endl;

    // Test Case 3: Fails
    // [[3,2,7], [3,7,9], [8,3,9]], capacity = 11
    // Loc 2: 3
    // Loc 3-6: 3 + 8 = 11
    // Loc 7-8: 3 + 8 = 11 (trip 1 ends at 7, trip 2 starts at 7)
    // Oh, trip 1 ends AT 7, so loc 6 is last.
    // Loc 2: 3
    // Loc 3-6: 3 + 8 = 11
    // Loc 7-8: 3 + 8 = 11
    // Wait, end is exclusive. trip[1]=7, trip[2]=9. Means loc 7, 8.
    // Let's re-trace:
    // Trip 1: {3, 2, 7} -> +3 at loc 2, -3 at loc 7. Covers loc [2, 3, 4, 5, 6]
    // Trip 2: {3, 7, 9} -> +3 at loc 7, -3 at loc 9. Covers loc [7, 8]
    // Trip 3: {8, 3, 9} -> +8 at loc 3, -8 at loc 9. Covers loc [3, 4, 5, 6, 7, 8]
    //
    // Loc 2: 3
    // Loc 3: 3 + 8 = 11
    // Loc 4: 3 + 8 = 11
    // Loc 5: 3 + 8 = 11
    // Loc 6: 3 + 8 = 11
    // Loc 7: 3 + 8 = 11 (Trip 1 ends, Trip 2 starts) -> ERROR in trace.
    // Let's use the code's logic:
    // T1: {start=2, end=6, val=3}
    // T2: {start=7, end=8, val=3}
    // T3: {start=3, end=8, val=8}
    //
    // diff[2] += 3
    // diff[7] -= 3
    // diff[7] += 3
    // diff[9] -= 3
    // diff[3] += 8
    // diff[9] -= 8
    //
    // diff[2] = 3
    // diff[3] = 8
    // diff[7] = 0
    // diff[9] = -11
    //
    // Prefix sum:
    // ps[0] = 0
    // ps[1] = 0
    // ps[2] = 3
    // ps[3] = 3+8 = 11
    // ps[4] = 11
    // ps[5] = 11
    // ps[6] = 11
    // ps[7] = 11+0 = 11
    // ps[8] = 11
    // ps[9] = 11-11 = 0
    // Max is 11. Capacity is 11. Should be TRUE.
    vector<vector<int>> trips3 = {{3, 2, 7}, {3, 7, 9}, {8, 3, 9}};
    int capacity3 = 11;
    cout << "\nInput: {{3,2,7}, {3,7,9}, {8,3,9}}, capacity=11\nOutput: " << sol.carPooling(trips3, capacity3) << endl;

    return 0;
}