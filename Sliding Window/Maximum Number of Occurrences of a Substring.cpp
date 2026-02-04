#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm> // For max

using namespace std;

class Solution {
public:
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
        unordered_map<string, int> mp2;
        unordered_map<char, int> mp;

        int distinct = 0;
        int i = 0, j = 0;
        int cnt = 0;

        while (j < s.size()) {
            // Add current character to window
            if (mp[s[j]] == 0)
                distinct++;
            mp[s[j]]++;

            // 1. Shrink window if it exceeds maxSize or maxLetters constraint
            while (j - i + 1 > maxSize || distinct > maxLetters) {
                mp[s[i]]--;
                if (mp[s[i]] == 0)
                    distinct--;
                i++;
            }

            // 2. Count valid substrings
            // Note: This inner loop shrinks the window down to minSize while recording valid substrings
            // This works, but it modifies the window 'i' pointer aggressively.
            while (j - i + 1 >= minSize && distinct <= maxLetters) {
                mp2[s.substr(i, j - i + 1)]++;
                
                mp[s[i]]--;
                if (mp[s[i]] == 0)
                    distinct--;
                i++;
            }
            j++;
        }

        for (auto it : mp2) {
            cnt = max(cnt, it.second);
        }
        return cnt;
    }
};

int main() {
    Solution sol;

    // Test Case: s = "aababcaab", maxLetters = 2, minSize = 3, maxSize = 4
    // "aab" has 2 distinct letters ('a', 'b') and size 3. It appears twice.
    string s = "aababcaab";
    int maxLetters = 2;
    int minSize = 3;
    int maxSize = 4;

    cout << "String: " << s << endl;
    cout << "Max Letters: " << maxLetters << ", Min Size: " << minSize << ", Max Size: " << maxSize << endl;

    // Run the function
    int result = sol.maxFreq(s, maxLetters, minSize, maxSize);

    // Print result
    cout << "Max Frequency: " << result << endl;

    return 0;
}