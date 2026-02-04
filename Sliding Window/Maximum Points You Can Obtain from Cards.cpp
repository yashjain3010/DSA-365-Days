#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int count = 0, l = 0, r = n-1, maxSum = 0, sum = 0;
        
        // Calculate sum of the first k cards from the left
        while(count < k){
            sum = sum + cardPoints[l];
            // Assuming non-negative points, maxSum will be the sum of first k at the end
            maxSum = max(maxSum, sum);
            l++;
            count++;
        }

        count = 0;
        l--; // Move pointer back to the last element included in the left sum
        
        // Slide the window: remove from the left, add from the right
        while(count < k){
            sum = sum + cardPoints[r] - cardPoints[l];
            maxSum = max(maxSum, sum);
            l--;
            r--;
            count++;
        }
        return maxSum;
    }
};

int main() {
    Solution sol;

    // Test Case 1: [1,2,3,4,5,6,1], k=3
    // Options: [1,2,3]=6, [1,2,1]=4, [1,6,1]=8, [5,6,1]=12
    // Max is 12
    vector<int> cards1 = {1, 2, 3, 4, 5, 6, 1};
    int k1 = 3;
    cout << "Input: cardPoints=[1,2,3,4,5,6,1], k=3" << endl;
    cout << "Output: " << sol.maxScore(cards1, k1) << endl; // Expected: 12

    // Test Case 2: [2,2,2], k=2
    // Any 2 cards sum to 4
    vector<int> cards2 = {2, 2, 2};
    int k2 = 2;
    cout << "\nInput: cardPoints=[2,2,2], k=2" << endl;
    cout << "Output: " << sol.maxScore(cards2, k2) << endl; // Expected: 4

    // Test Case 3: [9,7,7,9,7,7,9], k=7
    // Sum of all cards = 55
    vector<int> cards3 = {9, 7, 7, 9, 7, 7, 9};
    int k3 = 7;
    cout << "\nInput: cardPoints=[9,7,7,9,7,7,9], k=7" << endl;
    cout << "Output: " << sol.maxScore(cards3, k3) << endl; // Expected: 55

    return 0;
}