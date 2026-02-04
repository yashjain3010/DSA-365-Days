#include <iostream>
#include <vector>
#include <string>
#include <algorithm> // for min
#include <climits>   // for INT_MAX

using namespace std;

class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        // Use an array of size 26 for 'a'-'z' to store the minimum frequency seen so far.
        // Initialize with MAX values so the first word effectively sets the baseline.
        vector<int> minFreq(26, INT_MAX);

        for (const string& word : words) {
            // Count frequencies for the current word
            vector<int> charFreq(26, 0);
            for (char c : word) {
                charFreq[c - 'a']++;
            }

            // Update the global minFreq to keep only the intersection
            // If a char is in minFreq 3 times but current word 1 time, common is 1.
            // If a char is in minFreq 2 times but current word 0 times, common is 0.
            for (int i = 0; i < 26; i++) {
                minFreq[i] = min(minFreq[i], charFreq[i]);
            }
        }

        vector<string> ans;
        // Construct the result vector
        for (int i = 0; i < 26; i++) {
            // minFreq[i] tells us how many times character ('a' + i) appears in ALL words
            while (minFreq[i] > 0) {
                // Convert index back to string
                string s(1, i + 'a'); 
                ans.push_back(s);
                minFreq[i]--;
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;

    // Test Case 1
    // "bella": l=2, e=1...
    // "label": l=2, e=1...
    // "roller": l=2, e=1...
    // Common: e, l, l
    vector<string> words1 = {"bella", "label", "roller"};
    
    vector<string> res1 = sol.commonChars(words1);
    
    cout << "Common Characters: ";
    for (const string& s : res1) cout << s << " ";
    cout << endl;

    return 0;
}