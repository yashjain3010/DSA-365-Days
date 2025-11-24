#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.size();
        // Difference array to store changes
        vector<int> shift(n + 1, 0);

        for (auto& shiftOp : shifts) {
            int start = shiftOp[0], end = shiftOp[1], direction = shiftOp[2];

            // If direction == 1 (forward), add 1
            // If direction == 0 (backward), subtract 1
            int val = (direction == 1 ? 1 : -1);

            shift[start] += val;
            shift[end + 1] -= val;
        }

        int currentShift = 0;

        for (int i = 0; i < n; i++) {
            // Calculate prefix sum to get actual shift value at index i
            currentShift += shift[i];
            
            // Normalize the shift to be within [0, 25]
            // We need (a % n + n) % n to handle negative numbers correctly in C++
            int netShift = (currentShift % 26 + 26) % 26;
            
            // Apply shift
            // (s[i] - 'a') gives 0-25 index
            // + netShift adds the offset
            // % 26 wraps around
            // + 'a' converts back to char
            s[i] = 'a' + (s[i] - 'a' + netShift) % 26;
        }
        return s;
    }
};

int main() {
    Solution sol;

    // Test Case 1
    // s = "abc", shifts = [[0,1,0], [1,2,1]]
    // Op 1 [0,1,0]: shift indices 0-1 backward. 'a'->'z', 'b'->'a'. s="zac"
    // Op 2 [1,2,1]: shift indices 1-2 forward. 'a'->'b', 'c'->'d'. s="zbd"
    string s1 = "abc";
    vector<vector<int>> shifts1 = {{0, 1, 0}, {1, 2, 1}};
    cout << "Input: s=\"abc\", shifts=[[0,1,0], [1,2,1]]" << endl;
    cout << "Output: " << sol.shiftingLetters(s1, shifts1) << endl; // Expected: "zbd"

    // Test Case 2
    // s = "dztz", shifts = [[0,0,0], [1,1,1]]
    // Op 1 [0,0,0]: index 0 back. 'd'->'c'. s="cztz"
    // Op 2 [1,1,1]: index 1 fwd. 'z'->'a'. s="catz"
    string s2 = "dztz";
    vector<vector<int>> shifts2 = {{0, 0, 0}, {1, 1, 1}};
    cout << "\nInput: s=\"dztz\", shifts=[[0,0,0], [1,1,1]]" << endl;
    cout << "Output: " << sol.shiftingLetters(s2, shifts2) << endl; // Expected: "catz"

    return 0;
}