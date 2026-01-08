#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    string originalDigits(string s) {
        // Optimization: Use a vector instead of map for speed
        // map<char, int> is O(N log K), vector is O(N)
        vector<int> count(26, 0);
        for(char c : s){
            count[c - 'a']++;
        }

        vector<int> nums(10, 0);

        // 1. Identify numbers with unique characters
        nums[0] = count['z' - 'a']; // Zero
        nums[2] = count['w' - 'a']; // tWo
        nums[4] = count['u' - 'a']; // foUr
        nums[6] = count['x' - 'a']; // siX
        nums[8] = count['g' - 'a']; // eiGht

        // 2. Identify numbers based on remaining characters
        // 'h' is in "three" and "eight"
        nums[3] = count['h' - 'a'] - nums[8]; 
        
        // 'f' is in "five" and "four"
        nums[5] = count['f' - 'a'] - nums[4]; 
        
        // 's' is in "seven" and "six"
        nums[7] = count['s' - 'a'] - nums[6]; 
        
        // 'o' is in "one", "zero", "two", "four"
        nums[1] = count['o' - 'a'] - nums[0] - nums[2] - nums[4]; 
        
        // 'n' is in "nine" (twice), "one", "seven"
        nums[9] = (count['n' - 'a'] - nums[1] - nums[7]) / 2;

        // 3. Construct the result string
        string ans;
        for(int i = 0; i < 10; i++){
            // Append the digit 'i' exactly nums[i] times
            // string(count, char) constructor is cleaner than a loop
            ans += string(nums[i], i + '0');
        }
        return ans;
    }
};

int main() {
    Solution sol;

    // Test Case 1: "owoztneoer" -> "012"
    // z(0), w(2), o-0-2=1
    string s1 = "owoztneoer";
    cout << "Test Case 1: " << sol.originalDigits(s1) << endl;

    // Test Case 2: "fviefuro" -> "45"
    // u(4), f-4=5
    string s2 = "fviefuro";
    cout << "Test Case 2: " << sol.originalDigits(s2) << endl;

    return 0;
}