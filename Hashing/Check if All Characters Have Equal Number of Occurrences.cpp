#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    bool areOccurrencesEqual(string s) {
        // Map char (implicitly cast to int) -> frequency
        unordered_map<int, int> mpp;

        // Step 1: Count frequency of each character
        for(char c : s){
            mpp[c]++;
        }

        // Step 2: Get the frequency of the first character found in the map
        // Note: Using s[0] is safe because constraints usually say s.length >= 1.
        // However, looking at the map's first element is safer if s could be empty.
        int targetFreq = mpp.begin()->second;

        // Step 3: Verify all other characters have the same frequency
        for(auto& pair : mpp){
            if(pair.second != targetFreq){
                return false;
            }
        }
        return true;
    }
};

int main() {
    Solution sol;

    // Test Case 1: "abacbc" -> a:2, b:2, c:2 (All equal)
    string s1 = "abacbc";
    cout << "Test Case 1 (" << s1 << "): " << (sol.areOccurrencesEqual(s1) ? "True" : "False") << endl;

    // Test Case 2: "aaabb" -> a:3, b:2 (Not equal)
    string s2 = "aaabb";
    cout << "Test Case 2 (" << s2 << "): " << (sol.areOccurrencesEqual(s2) ? "True" : "False") << endl;

    // Test Case 3: Single character "a" -> a:1 (Equal)
    string s3 = "a";
    cout << "Test Case 3 (" << s3 << "): " << (sol.areOccurrencesEqual(s3) ? "True" : "False") << endl;

    return 0;
}