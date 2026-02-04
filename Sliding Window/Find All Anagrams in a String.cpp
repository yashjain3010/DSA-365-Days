#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> res;
        // Frequency arrays for 'a'-'z'
        vector<int> freq1(26, 0);
        vector<int> freq2(26, 0);

        if(s.length() < p.length()){
            return res;
        }

        // Initialize the first window
        for(int i = 0 ; i < p.length() ; i++){
            freq1[p[i] - 'a']++;
            freq2[s[i] - 'a']++;
        }

        // Check the first window (indices 0 to p.length()-1)
        if(freq1 == freq2) res.push_back(0);

        // Slide the window across s
        for(int i = p.length() ; i < s.length() ; i++){
            // Remove the character going out of the window (left side)
            freq2[s[i-p.length()]-'a']--;
            
            // Add the character coming into the window (right side)
            freq2[s[i]-'a']++;

            // Compare frequencies
            if(freq2 == freq1){
                // The current window starts at index (i - p.length() + 1)
                res.push_back(i-p.length()+1);
            }
        }
        return res;
    }
};

int main() {
    Solution sol;

    // Test Case 1: s = "cbaebabacd", p = "abc"
    // Anagrams of "abc" are "cba" (at 0) and "bac" (at 6)
    string s1 = "cbaebabacd";
    string p1 = "abc";
    vector<int> result1 = sol.findAnagrams(s1, p1);

    cout << "Input: s=\"cbaebabacd\", p=\"abc\"" << endl;
    cout << "Output: [";
    for (size_t i = 0; i < result1.size(); ++i) {
        cout << result1[i] << (i < result1.size() - 1 ? ", " : "");
    }
    cout << "]" << endl; // Expected: [0, 6]

    // Test Case 2: s = "abab", p = "ab"
    // Anagrams of "ab": "ab" (at 0), "ba" (at 1), "ab" (at 2)
    string s2 = "abab";
    string p2 = "ab";
    vector<int> result2 = sol.findAnagrams(s2, p2);

    cout << "\nInput: s=\"abab\", p=\"ab\"" << endl;
    cout << "Output: [";
    for (size_t i = 0; i < result2.size(); ++i) {
        cout << result2[i] << (i < result2.size() - 1 ? ", " : "");
    }
    cout << "]" << endl; // Expected: [0, 1, 2]

    return 0;
}