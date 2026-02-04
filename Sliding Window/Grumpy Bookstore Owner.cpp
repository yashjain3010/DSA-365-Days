#include <iostream>
#include <vector>
#include <algorithm> // For max

using namespace std;

class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int res = 0, curr = 0;

        // 1. Calculate the base satisfaction (satisfied customers when owner is NOT grumpy)
        for(int i = 0 ; i < customers.size() ; i++){
            if(grumpy[i] == 0){
                res += customers[i];
            }
        }

        // 2. Initial Window: Calculate potential gain for the first 'minutes' window
        // We only care about customers lost due to grumpiness (grumpy[i] == 1)
        for(int i = 0 ; i < minutes ; i++){
            if(grumpy[i] == 1){
                curr += customers[i];
            }
        }

        int addi = curr;

        // 3. Sliding Window: Slide across the rest of the array
        for(int i = minutes ; i < customers.size() ; i++){
            // Remove the element leaving the window (if the owner was grumpy then)
            if(grumpy[i - minutes]) 
                curr -= customers[i - minutes];
            
            // Add the new element entering the window (if the owner is grumpy now)
            if(grumpy[i]) 
                curr += customers[i];
            
            // Track the maximum additional satisfied customers we can get
            addi = max(addi, curr);
        }
        
        // Total = Base Satisfaction + Max Additional Gain from Technique
        return res + addi;
    }
};

int main() {
    Solution sol;

    // Test Case 1: Standard Example
    // customers = [1,0,1,2,1,1,7,5], grumpy = [0,1,0,1,0,1,0,1], minutes = 3
    // Base satisfied: 1 (idx 0) + 1 (idx 2) + 1 (idx 4) + 7 (idx 6) = 10
    // Windows of size 3 for recovering grumpy customers:
    // [0,1,2]: recovers customers at idx 1 (0) -> gain 0
    // [1,2,3]: recovers idx 1(0), 3(2) -> gain 2
    // ...
    // Best window is usually covering the '5' at the end or the '2'.
    // Actually, looking at indices:
    // Window [5,6,7]: Indices 5,6,7. Grumpy is [1,0,1]. Customers [1,7,5].
    // Recover idx 5 (1 cust) and idx 7 (5 cust). Total gain = 6.
    // Total = 10 + 6 = 16.
    
    vector<int> customers = {1, 0, 1, 2, 1, 1, 7, 5};
    vector<int> grumpy =    {0, 1, 0, 1, 0, 1, 0, 1};
    int minutes = 3;

    cout << "Test Case 1:" << endl;
    cout << "Customers: [ ";
    for(int c : customers) cout << c << " ";
    cout << "]" << endl;
    cout << "Grumpy:    [ ";
    for(int g : grumpy) cout << g << " ";
    cout << "]" << endl;
    cout << "Minutes: " << minutes << endl;

    int result = sol.maxSatisfied(customers, grumpy, minutes);
    cout << "Max Satisfied Customers: " << result << endl;

    return 0;
}