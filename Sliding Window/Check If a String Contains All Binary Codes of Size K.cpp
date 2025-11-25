#include <iostream>
#include <string>
#include <unordered_set>
#include <cmath> // For pow

using namespace std;

class Solution {
public:
    bool hasAllCodes(string s, int k) {
        // Safety check: if s is shorter than k, it can't contain any code of length k
        // Also prevents underflow in the loop condition below since s.size() is unsigned
        if(s.size() < k) return false;

        unordered_set<string> set;

        // Iterate through all substrings of length k
        for(int i = 0 ; i <= s.size()-k ; i++){
            set.insert(s.substr(i,k));
        }

        // Check if we found all 2^k distinct codes
        return (set.size() == pow(2,k));
    }
};

int main() {
    Solution sol;
    cout << boolalpha; // Print "true" or "false"

    // Test Case 1: s = "00110110", k = 2
    // Codes needed: 00, 01, 10, 11 (Total 4)
    // Substrings found: 00, 01, 11, 10, 01, 11, 10
    // Unique: {00, 01, 10, 11}. Count = 4.
    string s1 = "00110110";
    int k1 = 2;
    cout << "Input: s=\"00110110\", k=2\nOutput: " << sol.hasAllCodes(s1, k1) << endl; // Expected: true

    // Test Case 2: s = "0110", k = 1
    // Codes needed: 0, 1 (Total 2)
    // Unique found: {0, 1}. Count = 2.
    string s2 = "0110";
    int k2 = 1;
    cout << "\nInput: s=\"0110\", k=1\nOutput: " << sol.hasAllCodes(s2, k2) << endl; // Expected: true

    // Test Case 3: s = "0110", k = 2
    // Codes needed: 00, 01, 10, 11
    // Unique found: {01, 11, 10}. Count = 3. Missing "00".
    string s3 = "0110";
    int k3 = 2;
    cout << "\nInput: s=\"0110\", k=2\nOutput: " << sol.hasAllCodes(s3, k3) << endl; // Expected: false

    return 0;
}