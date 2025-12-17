#include <iostream>
#include <vector>
#include <string>
#include <algorithm> // For max

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        // Using a boolean array to track characters in the current window
        // 128 covers standard ASCII characters
        vector<bool> arr(128, false);
        int maxLen = 0, l = 0, r = 0;

        while(r < s.size()){
            // If the character at 'r' is NOT in the current window
            if(!arr[s[r]]){
                arr[s[r]] = true;           // Mark it as present
                maxLen = max(maxLen, r - l + 1); // Update max length
                r++;                        // Expand window to the right
            } 
            // If the character IS in the window (duplicate found)
            else{
                arr[s[l]] = false;          // Remove the character at 'l'
                l++;                        // Shrink window from the left
            }
        }
        return maxLen;
    }
};

int main() {
    Solution sol;

    // Test Case 1: Standard example
    string s1 = "abcabcbb";
    cout << "Test Case 1: " << s1 << endl;
    cout << "Max Length: " << sol.lengthOfLongestSubstring(s1) << endl; 
    cout << "-----------------" << endl;

    // Test Case 2: All same characters
    string s2 = "bbbbb";
    cout << "Test Case 2: " << s2 << endl;
    cout << "Max Length: " << sol.lengthOfLongestSubstring(s2) << endl;
    cout << "-----------------" << endl;

    // Test Case 3: Substring inside
    string s3 = "pwwkew";
    cout << "Test Case 3: " << s3 << endl;
    cout << "Max Length: " << sol.lengthOfLongestSubstring(s3) << endl;

    return 0;
}