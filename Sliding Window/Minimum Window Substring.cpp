#include <iostream>
#include <string>
#include <vector>
#include <climits> // Required for INT_MAX

using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        // Frequency arrays for extended ASCII
        int need[256] = {0}, has[256] = {0};

        int n = s.size(), m = t.size(), idx = -1, best = INT_MAX;

        // Populate the need map with characters from t
        for(char x : t) need[x]++;
        
        // Sliding window
        for(int l = 0, r = 0, match = 0 ; r < n ; r++){
            // Expand window: Add character at r
            has[s[r]]++;
            
            // If the character is required and we haven't exceeded the required count yet, increment match
            if(need[s[r]] && has[s[r]] <= need[s[r]]) match++;
            
            // Shrink window: While we have all required characters (valid window)
            while(match == m){
                int len = r - l + 1;
                
                // Update best result found so far
                if(len < best){
                    best = len;
                    idx = l;
                }

                // Remove character at l
                has[s[l]]--;
                
                // If the removed character was required and we now have fewer than needed, break validity
                if(need[s[l]] && has[s[l]] < need[s[l]]){
                    match--;
                }
                l++;
            }
        }

        return idx != -1 ? s.substr(idx, best) : "";
    }
};

int main() {
    Solution sol;

    // Test Case 1: Standard Example
    // s = "ADOBECODEBANC", t = "ABC"
    // Expected Output: "BANC"
    string s1 = "ADOBECODEBANC";
    string t1 = "ABC";
    
    cout << "Test Case 1:" << endl;
    cout << "s: " << s1 << "\nt: " << t1 << endl;
    cout << "Min Window: " << "\"" << sol.minWindow(s1, t1) << "\"" << endl;
    cout << "-----------------" << endl;

    // Test Case 2: Impossible case
    // s = "a", t = "aa" -> Expected: "" (not enough 'a's)
    string s2 = "a";
    string t2 = "aa";

    cout << "Test Case 2:" << endl;
    cout << "s: " << s2 << "\nt: " << t2 << endl;
    cout << "Min Window: " << "\"" << sol.minWindow(s2, t2) << "\"" << endl;

    return 0;
}