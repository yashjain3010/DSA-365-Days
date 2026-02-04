#include <iostream>
#include <vector>
#include <algorithm> // For max, swap
#include <utility>   // For exchange

using namespace std;

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        int ans = 0;
        // basket stores the types of fruits: basket[0] (old), basket[1] (current/newest)
        int basket[2] = {-1, -1};
        // cnt stores the count of fruits in the current valid window logic
        // Note: This specific implementation uses a state-machine approach rather than standard sliding window
        int cnt[2] = {0, 0};

        // Tracks the length of the consecutive run of the CURRENT fruit (basket[1])
        int lastRun = 0;

        for(int i = 0 ; i < n ; i++){
            int x = fruits[i];
            
            if(x == basket[1]){
                // Case 1: Same as the most recent fruit
                cnt[1]++;
                lastRun++;
            } else if(x == basket[0]){
                // Case 2: Same as the other fruit in the basket
                // Swap so that basket[1] always represents the most recently seen fruit type
                swap(basket[0], basket[1]);
                swap(cnt[0], cnt[1]);
                cnt[1]++;
                lastRun = 1; // Reset consecutive run count for this "new" current fruit
            } else{
                // Case 3: A completely new fruit type (3rd type)
                // The new window will consist of the 'lastRun' of the previous fruit
                // plus this new fruit.
                basket[0] = exchange(basket[1], x);
                cnt[0] = exchange(lastRun, 1);
                cnt[1] = 1;
            }

            ans = max(ans, cnt[0] + cnt[1]);
        }
        return ans;
    }
};

int main() {
    Solution sol;

    // Test Case 1: [1,2,1]
    // Expected: 3
    vector<int> fruits1 = {1, 2, 1};
    cout << "Test Case 1: [1, 2, 1]" << endl;
    cout << "Total Fruit: " << sol.totalFruit(fruits1) << endl;
    cout << "-----------------" << endl;

    // Test Case 2: [0,1,2,2]
    // Expected: 3 (We can pick [1,2,2])
    vector<int> fruits2 = {0, 1, 2, 2};
    cout << "Test Case 2: [0, 1, 2, 2]" << endl;
    cout << "Total Fruit: " << sol.totalFruit(fruits2) << endl;
    cout << "-----------------" << endl;

    // Test Case 3: [1,2,3,2,2]
    // Expected: 4 (We can pick [2,3,2,2])
    vector<int> fruits3 = {1, 2, 3, 2, 2};
    cout << "Test Case 3: [1, 2, 3, 2, 2]" << endl;
    cout << "Total Fruit: " << sol.totalFruit(fruits3) << endl;

    return 0;
}