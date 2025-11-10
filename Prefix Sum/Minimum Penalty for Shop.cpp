#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.size();
        vector<int> pre(n+1), suf(n+1);

        pre[0] = 0;
        for(int i = 0 ; i < n ; i++){
            pre[i+1] = pre[i] + (customers[i] == 'N' ? 1 : 0);
        }

        suf[n] = 0;
        for(int i = n-1 ; i >= 0 ; i--){
            suf[i] = suf[i+1] + (customers[i] == 'Y' ? 1 : 0);
        }

        int minPenalty = n+1;
        int time = 0;
        
        for(int i = 0 ; i <= n ; i++){
            pre[i] += suf[i];
            if(pre[i] < minPenalty){
                minPenalty = pre[i];
                time = i;
            }
        }
        return time;
    }
};

int main() {
    Solution sol;

    // Test Case 1: "YYNY" -> Expected: 2
    string customers1 = "YYNY";
    cout << "Customers: " << customers1 << " | Best Closing Time: " << sol.bestClosingTime(customers1) << endl;

    // Test Case 2: "NNNNN" -> Expected: 0
    string customers2 = "NNNNN";
    cout << "Customers: " << customers2 << " | Best Closing Time: " << sol.bestClosingTime(customers2) << endl;

    // Test Case 3: "YYYY" -> Expected: 4
    string customers3 = "YYYY";
    cout << "Customers: " << customers3 << " | Best Closing Time: " << sol.bestClosingTime(customers3) << endl;

    return 0;
}