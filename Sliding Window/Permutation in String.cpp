#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1 = s1.length();
        int n2 = s2.length();

        // If s1 is longer than s2, it can't be included
        if (n1 > n2) return false;

        vector<int> freq1(26, 0);
        vector<int> freq2(26, 0);

        // 1. Initialize the first window (length of s1)
        for (int i = 0; i < n1; i++) {
            freq1[s1[i] - 'a']++;
            freq2[s2[i] - 'a']++;
        }

        // Check if the first window matches
        if (freq1 == freq2) return true;

        // 2. Slide the window across s2
        // We start sliding from the character immediately after the first window
        for (int i = n1; i < n2; i++) {
            // Add the new character (right side of window)
            freq2[s2[i] - 'a']++;
            
            // Remove the old character (left side of window)
            // The character leaving is at index (i - n1)
            freq2[s2[i - n1] - 'a']--;

            // Check if frequencies match
            if (freq1 == freq2) return true;
        }

        return false;
    }
};

int main() {
    Solution sol;
    cout << boolalpha; // Print "true" or "false"

    // Test Case 1: s1="ab", s2="eidbaooo"
    // "ba" is a permutation of "ab" and is present in s2.
    string s1_1 = "ab";
    string s2_1 = "eidbaooo";
    cout << "Input: s1=\"ab\", s2=\"eidbaooo\"" << endl;
    cout << "Output: " << sol.checkInclusion(s1_1, s2_1) << endl; // Expected: true

    // Test Case 2: s1="ab", s2="eidboaoo"
    // No permutation of "ab" exists as a substring (they are separated).
    string s1_2 = "ab";
    string s2_2 = "eidboaoo";
    cout << "\nInput: s1=\"ab\", s2=\"eidboaoo\"" << endl;
    cout << "Output: " << sol.checkInclusion(s1_2, s2_2) << endl; // Expected: false

    return 0;
}