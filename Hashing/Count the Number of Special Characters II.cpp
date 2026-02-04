#include <iostream>
#include <vector>
#include <string>
#include <algorithm> // For min

using namespace std;

class Solution {
public:
    int numberOfSpecialChars(string word) {
        int n = word.length();
        
        // low stores {count, last_index}
        // Initialize last_index to -1 (meaning not found)
        vector<pair<int, int>> low(26, {0, -1});
        
        // up stores {count, first_index}
        // Initialize first_index to n (infinity, essentially) so min() works
        vector<pair<int, int>> up(26, {0, n});

        for(int i = 0 ; i < n ; i++){
            char ch = word[i];
            if(islower(ch)){
                // For lowercase, we want the LAST position.
                // Just overwrite the index every time we see it.
                low[ch-'a'].first++;
                low[ch-'a'].second = i;
            } else {
                // For uppercase, we want the FIRST position.
                // Keep the minimum index.
                up[ch-'A'].first++;
                up[ch-'A'].second = min(up[ch-'A'].second, i);
            }
        }

        int ans = 0;

        for(int i = 0 ; i < 26 ; i++){
            // Condition 1: Both lowercase and uppercase must exist (count > 0)
            if(low[i].first > 0 && up[i].first > 0){
                // Condition 2: The LAST lowercase must be before the FIRST uppercase
                if(low[i].second < up[i].second) {
                    ans++;
                }
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;

    // Test Case 1: Valid
    // 'a' (index 0) is before 'A' (index 4). Valid.
    // 'b' (index 1) is before 'B' (index 3). Valid.
    // "cC" -> 'c' (index 2) is before 'C' (index 5). Valid.
    string word1 = "abcBCA";
    cout << "Test Case 1 (" << word1 << "): " << sol.numberOfSpecialChars(word1) << endl; 
    // Expected Output: 3

    // Test Case 2: Invalid Order
    // 'a' appears at 0 and 2. 'A' appears at 1.
    // Last 'a' (2) is NOT before first 'A' (1). Invalid.
    string word2 = "aAab";
    cout << "Test Case 2 (" << word2 << "): " << sol.numberOfSpecialChars(word2) << endl;
    // Expected Output: 0

    return 0;
}