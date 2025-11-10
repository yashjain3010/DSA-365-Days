#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int>& security, int time) {
        int n = security.size();

        vector<int> pre(n, 0), suf(n, 0);
        
        for (int i = 1; i < n; i++) {
            if (security[i] <= security[i - 1]) {
                pre[i] = 1 + pre[i - 1];
            }
        }

        for (int i = n - 2; i >= 0; i--) {
            if (security[i] <= security[i + 1]) {
                suf[i] = 1 + suf[i + 1];
            }
        }

        vector<int> ans;

        for (int i = time; i < n - time; i++) {
            if (pre[i] >= time && suf[i] >= time) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;
    
    // Test Case 1
    vector<int> security1 = {5, 3, 3, 3, 5, 6, 2};
    int time1 = 2;
    vector<int> result1 = sol.goodDaysToRobBank(security1, time1);
    
    cout << "Test Case 1 Result: [";
    for (int i = 0; i < result1.size(); ++i) {
        cout << result1[i] << (i < result1.size() - 1 ? ", " : "");
    }
    cout << "]" << endl; // Expected: [2, 3]

    // Test Case 2
    vector<int> security2 = {1, 1, 1, 1, 1};
    int time2 = 0;
    vector<int> result2 = sol.goodDaysToRobBank(security2, time2);

    cout << "Test Case 2 Result: [";
    for (int i = 0; i < result2.size(); ++i) {
        cout << result2[i] << (i < result2.size() - 1 ? ", " : "");
    }
    cout << "]" << endl; // Expected: [0, 1, 2, 3, 4]

    return 0;
}