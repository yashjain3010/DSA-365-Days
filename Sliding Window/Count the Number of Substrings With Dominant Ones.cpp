#include <iostream>
#include <vector>
#include <string>
#include <algorithm> // For min

using namespace std;

class Solution {
public:
    int numberOfSubstrings(string s) {
        // pre[i] stores the index of the nearest zero preceding index i (1-based mapping)
        vector<int> pre(s.length() + 1);
        pre[0] = -1;

        // Build the 'previous zero' array
        for(int i = 0 ; i < s.length() ; i++){
            if(i == 0 || (i > 0 && s[i-1] == '0')) 
                pre[i+1] = i;
            else 
                pre[i+1] = pre[i];
        }

        int res = 0;
        
        // Iterate through all possible ending positions of substrings
        for(int i = 1 ; i <= s.length() ; i++){
            int cnt0 = s[i-1] == '0'; // Check if current char is 0
            int j = i; // Pointer to traverse backwards via 'pre' array

            // Iterate backwards jumping between zeros
            // Stop if count of zeros squared exceeds total length (optimization)
            while(j > 0 && cnt0 * cnt0 <= s.length()){
                // Calculate ones in the current range
                // (i - pre[j]) is the total length of the segment between current zero and next zero to the left
                int cnt1 = (i - pre[j]) - cnt0;
                
                if(cnt0 * cnt0 <= cnt1){
                    // Add valid substrings found in this segment
                    res += min(j - pre[j], cnt1 - cnt0 * cnt0 + 1);
                }

                // Jump to the previous zero index
                j = pre[j];
                cnt0++;
            }
        }
        return res;
    }
};

int main() {
    Solution sol;

    // Test Case 1: "00011"
    // Expected: 5 
    // ("1", "1", "11", "011", "011") -> checking ones >= zeros^2
    string s1 = "00011";
    cout << "Test Case 1: " << s1 << endl;
    cout << "Count: " << sol.numberOfSubstrings(s1) << endl;
    cout << "-----------------" << endl;

    // Test Case 2: "101101"
    // A mix of 1s and 0s
    string s2 = "101101";
    cout << "Test Case 2: " << s2 << endl;
    cout << "Count: " << sol.numberOfSubstrings(s2) << endl;

    return 0;
}