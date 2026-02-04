#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        // Map to store the difference array: time -> change in flower count
        // Using map automatically sorts the keys (time points)
        map<int, int> eventChanges;
        for(const auto& flower : flowers){
            int start = flower[0];
            // Flower stops blooming at end + 1
            int end = flower[1] + 1;
            eventChanges[start]++;
            eventChanges[end]--;
        }

        // Map to store the prefix sums: time -> total active flowers starting at this time
        map<int, int> bloomCount;
        int currentBloom = 0;
        for(auto [time, change] : eventChanges){
            currentBloom += change;
            bloomCount[time] = currentBloom;
        }

        vector<int> results;
        for(const auto& query : people){
            // Find the first time point strictly greater than the person's arrival time
            auto it = bloomCount.upper_bound(query);
            
            if(it == bloomCount.begin()) {
                // Person arrives before any flower blooms
                results.push_back(0);
            } else {
                // Move back to the time point <= query to get the current state
                --it;
                results.push_back(it->second);
            }   
        }
        return results;
    }
};

int main() {
    Solution sol;

    // Test Case 1
    // Flowers: [1,6], [3,7], [9,12], [4,13]
    // Timeline changes:
    // 1: +1 (Total 1)
    // 3: +1 (Total 2)
    // 4: +1 (Total 3)
    // 7: -1 (Total 2) [Flower 1,6 ends at 6, so at 7 it's gone]
    // 8: -1 (Total 1) [Flower 3,7 ends at 7]
    // 9: +1 (Total 2)
    // 13: -1 (Total 1) [Flower 9,12 ends at 12]
    // 14: -1 (Total 0) [Flower 4,13 ends at 13]
    
    // People: [2, 3, 7, 11]
    // Person at 2: Falls between 1 and 3. State is from time 1 -> 1 flower.
    // Person at 3: Exact match time 3. State is 2 flowers.
    // Person at 7: Exact match time 7. State is 2 flowers.
    // Person at 11: Falls between 9 and 13. State is from time 9 -> 2 flowers.
    
    vector<vector<int>> flowers1 = {{1, 6}, {3, 7}, {9, 12}, {4, 13}};
    vector<int> people1 = {2, 3, 7, 11};
    
    vector<int> result1 = sol.fullBloomFlowers(flowers1, people1);
    
    cout << "Input: flowers={{1,6},{3,7},{9,12},{4,13}}, people={2,3,7,11}" << endl;
    cout << "Output: [";
    for (size_t i = 0; i < result1.size(); ++i) {
        cout << result1[i] << (i < result1.size() - 1 ? ", " : "");
    }
    cout << "]" << endl; // Expected: [1, 2, 2, 2]

    // Test Case 2
    // Flowers: [1, 10], [3, 3]
    // People: [3, 3, 2]
    vector<vector<int>> flowers2 = {{1, 10}, {3, 3}};
    vector<int> people2 = {3, 3, 2};

    vector<int> result2 = sol.fullBloomFlowers(flowers2, people2);

    cout << "\nInput: flowers={{1,10},{3,3}}, people={3,3,2}" << endl;
    cout << "Output: [";
    for (size_t i = 0; i < result2.size(); ++i) {
        cout << result2[i] << (i < result2.size() - 1 ? ", " : "");
    }
    cout << "]" << endl; // Expected: [2, 2, 1]

    return 0;
}