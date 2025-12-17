#include <iostream>
#include <vector>
#include <string>
#include <algorithm> // For max

using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        int maxLen = 0;
        int start = 0;
        int n = s.length();
        // Frequency array for uppercase English letters 'A' - 'Z'
        int freqArr[26] = {0};
        int maxFreq = 0;

        for(int i = 0 ; i < n ; i++){

            // 1. Expand the window & update frequency
            freqArr[s[i]-'A']++;
            
            // maxFreq keeps track of the count of the most frequent character 
            // *within the current window history*. This is a clever optimization.
            maxFreq = max(maxFreq, freqArr[s[i]-'A']);

            // 2. Check validity
            // Window Size (i - start + 1) - Most Frequent Count (maxFreq) = Number of replacements needed
            // If replacements needed > k, the window is invalid.
            if((i - start + 1) - maxFreq > k){
                // Slide the window ahead: remove the start char and increment start pointer
                freqArr[s[start]-'A']--;
                start++;
            }

            // At this point, the window [start...i] is either valid, OR it has the same size 
            // as the previously largest valid window (because we incremented start if it was invalid).
            maxLen = max(maxLen, i - start + 1);
        }
        return maxLen;
    }
};

int main() {
    Solution sol;

    // Test Case 1: "ABAB", k = 2
    // Replace the two 'A's with 'B's (or vice versa) -> "BBBB" (len 4)
    string s1 = "ABAB";
    int k1 = 2;
    cout << "Test Case 1:" << endl;
    cout << "String: " << s1 << ", k: " << k1 << endl;
    cout << "Max Length: " << sol.characterReplacement(s1, k1) << endl;
    cout << "-----------------" << endl;

    // Test Case 2: "AABABBA", k = 1
    // Replace the middle 'B' with 'A' -> "AAAABBA" (len 4 is "AAAA")
    string s2 = "AABABBA";
    int k2 = 1;
    cout << "Test Case 2:" << endl;
    cout << "String: " << s2 << ", k: " << k2 << endl;
    cout << "Max Length: " << sol.characterReplacement(s2, k2) << endl;

    return 0;
}