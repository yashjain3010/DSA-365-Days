#include <iostream>
#include <string>
#include <algorithm> // For max
#include <vector>

using namespace std;

class Solution {
public:

    bool vowel(char ch){
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }

    int maxVowels(string s, int k) {
        int l = 0, r = 0, count = 0, ans = 0;

        while(r < s.size()){
            // Add right character to window
            if(vowel(s[r])){
                count++;
            }

            // If window size exceeds k, shrink from left
            if(r-l+1 > k){
                if(vowel(s[l])){
                    count--;
                }
                l++;
            }

            // Update max count found so far
            ans = max(ans, count);
            r++;
        }
        return ans;
    }
};

int main() {
    Solution sol;

    // Test Case 1: s = "abciiidef", k = 3
    // Substrings size 3: "abc"(1), "bci"(1), "cii"(2), "iii"(3), "ide"(2)...
    // Max vowels is 3 ("iii")
    string s1 = "abciiidef";
    int k1 = 3;
    cout << "Input: s=\"abciiidef\", k=3\nOutput: " << sol.maxVowels(s1, k1) << endl; 

    // Test Case 2: s = "aeiou", k = 2
    // Any substring of length 2 has 2 vowels (e.g., "ae", "ei", "io", "ou")
    string s2 = "aeiou";
    int k2 = 2;
    cout << "\nInput: s=\"aeiou\", k=2\nOutput: " << sol.maxVowels(s2, k2) << endl; 

    // Test Case 3: s = "leetcode", k = 3
    // "lee"(2), "eet"(2), "ode"(2)
    string s3 = "leetcode";
    int k3 = 3;
    cout << "\nInput: s=\"leetcode\", k=3\nOutput: " << sol.maxVowels(s3, k3) << endl;

    return 0;
}