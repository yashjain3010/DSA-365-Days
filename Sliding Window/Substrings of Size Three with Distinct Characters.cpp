#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int countGoodSubstrings(string s) {
        int count = 0;
        int n = s.size();

        // Loop up to n-2 because we access i, i+1, and i+2
        // If n < 3, the loop condition (i < n-2) correctly prevents execution
        for(int i = 0 ; i < n-2 ; i++){
            // Check if all three characters in the window are unique
            if(s[i] != s[i+1] && s[i] != s[i+2] && s[i+1] != s[i+2]){
                count++;
            }
        }
        return count;
    }
};

int main() {
    Solution sol;

    // Test Case 1
    // Substrings size 3: "xyz", "yzz", "zza", "zaz"
    // "xyz" -> Distinct -> Good
    // "yzz" -> 'z' repeats -> Bad
    // "zza" -> 'z' repeats -> Bad
    // "zaz" -> 'z' repeats -> Bad
    // Total: 1
    string s1 = "xyzzaz";
    cout << "Input: \"xyzzaz\" | Output: " << sol.countGoodSubstrings(s1) << endl;

    // Test Case 2
    // Substrings: "aab", "aba", "bab", "abc", "bca", "cab", "abc"
    // Good ones: "abc", "bca", "cab", "abc"
    // Total: 4
    string s2 = "aababcabc";
    cout << "Input: \"aababcabc\" | Output: " << sol.countGoodSubstrings(s2) << endl;

    return 0;
}