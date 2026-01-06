#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <cmath> // For abs

using namespace std;

class Solution {
public:
    // Your Original Approach: Two Maps
    int findPermutationDifference(string s, string t) {
        unordered_map<char, int> mp1, mp2;

        // Store indices for both strings
        for(int i = 0 ; i < s.size() ; i++){
            mp1[s[i]] = i;
            mp2[t[i]] = i;
        }

        int diff = 0;

        // Calculate absolute difference for every character
        for(auto& c : s){
            diff += abs(mp1[c] - mp2[c]);
        }
        return diff;
    }

    // OPTIMIZED APPROACH: Single Array
    // 1. We only need to store indices of 't' because we iterate through 's'.
    // 2. We can use an array int[26] instead of unordered_map for speed.
    int findPermutationDifferenceOptimized(string s, string t) {
        int indices[26] = {0}; // Array is faster than Map

        // Map the indices of characters in 't'
        for(int i = 0; i < t.size(); i++) {
            indices[t[i] - 'a'] = i;
        }

        int diff = 0;
        // Iterate through 's'
        for(int i = 0; i < s.size(); i++) {
            // Get index of current char s[i] in string t
            int indexInT = indices[s[i] - 'a'];
            
            // Current index i is the index in s
            diff += abs(i - indexInT);
        }
        return diff;
    }
};

int main() {
    Solution sol;

    // Test Case 1:
    // s = "abc", t = "bac"
    // 'a': index 0 in s, index 1 in t -> abs(0-1) = 1
    // 'b': index 1 in s, index 0 in t -> abs(1-0) = 1
    // 'c': index 2 in s, index 2 in t -> abs(2-2) = 0
    // Total = 2
    string s1 = "abc";
    string t1 = "bac";

    cout << "Test Case 1:" << endl;
    cout << "Result: " << sol.findPermutationDifference(s1, t1) << endl;
    cout << "-----------------" << endl;

    // Test Case 2:
    // s = "abcde", t = "edbac"
    string s2 = "abcde";
    string t2 = "edbac";

    cout << "Test Case 2 (Optimized Function):" << endl;
    cout << "Result: " << sol.findPermutationDifferenceOptimized(s2, t2) << endl;

    return 0;
}