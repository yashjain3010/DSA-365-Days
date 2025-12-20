#include <iostream>
#include <vector>
#include <climits> // For INT_MAX
#include <algorithm> // For min

using namespace std;

class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        // Use a vector as a direct-address table (like a hash map)
        // Size is 10^6 + 1 based on typical constraint that values <= 10^6
        // Initialize with -1 to indicate card has not been seen yet
        vector<int> m(1e6+1, -1);
        
        int ans = INT_MAX;
        
        for(int i = 0; i < cards.size(); i++)
        {
            // If we have seen this card value before
            if(m[cards[i]] != -1)
            {
                // Calculate the distance: current_index - last_seen_index + 1
                // This represents the number of consecutive cards we'd need to pick up
                ans = min(ans, i - m[cards[i]] + 1);
            }
            
            // Update the last seen index of the current card to 'i'
            m[cards[i]] = i;
        }
        
        return ans == INT_MAX ? -1 : ans;
    }
};

int main() {
    Solution sol;

    // Test Case 1: Standard Example
    // Input: [3, 4, 2, 3, 4, 7]
    // Pairs: 3 (indices 0 and 3 -> len 4), 4 (indices 1 and 4 -> len 4)
    // Expected: 4
    vector<int> cards1 = {3, 4, 2, 3, 4, 7};
    cout << "Test Case 1: [3, 4, 2, 3, 4, 7]" << endl;
    cout << "Minimum Cards: " << sol.minimumCardPickup(cards1) << endl;
    cout << "-----------------" << endl;

    // Test Case 2: No duplicates
    // Input: [1, 0, 5, 3]
    // Expected: -1
    vector<int> cards2 = {1, 0, 5, 3};
    cout << "Test Case 2: [1, 0, 5, 3]" << endl;
    cout << "Minimum Cards: " << sol.minimumCardPickup(cards2) << endl;
    cout << "-----------------" << endl;

    // Test Case 3: Closer pair
    // Input: [1, 2, 3, 2, 1]
    // Pair 2 (indices 1,3 -> len 3). Pair 1 (indices 0,4 -> len 5).
    // Expected: 3
    vector<int> cards3 = {1, 2, 3, 2, 1};
    cout << "Test Case 3: [1, 2, 3, 2, 1]" << endl;
    cout << "Minimum Cards: " << sol.minimumCardPickup(cards3) << endl;

    return 0;
}