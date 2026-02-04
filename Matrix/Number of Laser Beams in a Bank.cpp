#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int numberOfBeams(vector<string>& A) {
        // 'prev' stores the count of devices in the previous row that had devices.
        // Initialize to 0. 
        int prev = 0;
        int res = 0;

        for(int i = 0; i < A.size(); i++) {
            int cnt = 0;
            string s = A[i];
            
            // Count devices ('1') in the current row
            for(int j = 0; j < s.length(); j++) {
                if(s[j] == '1') cnt++;
            }

            // If the current row has no devices, beams just pass through it.
            // We do NOT update 'prev', so the connection continues to the next valid row.
            if(cnt == 0) continue;

            // If there was a previous row with devices, calculate beams
            // Beams = (devices in prev row) * (devices in curr row)
            res += prev * cnt;

            // Update prev to be the current row's count for the next iteration
            prev = cnt;
        }
        return res;
    }
};

int main() {
    Solution sol;

    // Test Case 1: Standard Example
    // Row 0: "011001" -> 3 devices
    // Row 1: "000000" -> 0 devices (Skipped)
    // Row 2: "010100" -> 2 devices. Beams: 3 * 2 = 6. Prev becomes 2.
    // Row 3: "001000" -> 1 device.  Beams: 6 + (2 * 1) = 8. Prev becomes 1.
    vector<string> bank1 = {
        "011001",
        "000000",
        "010100",
        "001000"
    };

    cout << "Test Case 1:" << endl;
    cout << "Total Beams: " << sol.numberOfBeams(bank1) << endl;
    cout << "-----------------" << endl;

    // Test Case 2: No beams
    // Row 0: 0 devices
    // Row 1: 0 devices
    // Row 2: 0 devices
    vector<string> bank2 = {
        "000",
        "111",
        "000"
    };
    // Row 0: 0
    // Row 1: 3. (Prev was 0, so res += 0*3). Prev becomes 3.
    // Row 2: 0.
    // Result: 0

    cout << "Test Case 2:" << endl;
    cout << "Total Beams: " << sol.numberOfBeams(bank2) << endl;

    return 0;
}