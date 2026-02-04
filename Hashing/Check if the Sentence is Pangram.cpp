#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set> // For optimization tip

using namespace std;

class Solution {
public:
    bool checkIfPangram(string sentence) {
        unordered_map<char, int> mpp;

        // Step 1: Count occurrences of each character
        for (auto x : sentence) {
            mpp[x]++;
        }

        // Step 2: If we have found at least 26 unique keys, it contains every letter.
        if (mpp.size() >= 26) {
            return true;
        }
        return false;
    }

    // OPTIMIZATION: Use a Boolean Array (Vector) or Set
    // Since we only care *if* a letter appears (not how many times),
    // and we know the range is strictly 'a'-'z'.
    bool checkIfPangramOptimized(string sentence) {
        if (sentence.length() < 26) return false; // Early exit

        // 0 = 'a', 25 = 'z'
        // Using int or bool array is faster than a HashMap
        bool seen[26] = {false};
        int uniqueCount = 0;

        for (char c : sentence) {
            int index = c - 'a';
            // If we haven't seen this letter before
            if (!seen[index]) {
                seen[index] = true;
                uniqueCount++;
            }
            
            // Optimization: If we found all 26, we can stop early
            if (uniqueCount == 26) return true;
        }
        return false;
    }
};

int main() {
    Solution sol;

    // Test Case 1: Pangram
    // "thequickbrownfoxjumpsoverthelazydog" contains every letter a-z
    string s1 = "thequickbrownfoxjumpsoverthelazydog";
    cout << "Test Case 1: " << (sol.checkIfPangram(s1) ? "True" : "False") << endl;

    // Test Case 2: Not a Pangram
    // Missing 'x', 'z', etc.
    string s2 = "leetcode";
    cout << "Test Case 2: " << (sol.checkIfPangram(s2) ? "True" : "False") << endl;

    return 0;
}