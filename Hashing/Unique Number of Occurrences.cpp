#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        // Step 1: Count frequency of each number
        // Map: Number -> Count
        unordered_map<int, int> mpp;
        for(int it : arr){
            mpp[it]++;
        }

        // Step 2: Check if all frequencies are unique
        // Set: Stores the frequencies seen so far
        unordered_set<int> freq;

        for(auto& occ : mpp){
            int count = occ.second;
            
            // If we have seen this count before, return false
            if(freq.count(count)){
                return false;
            }
            freq.insert(count);
        }
        return true;
    }
};

int main() {
    Solution sol;

    // Test Case 1: Unique Occurrences
    // 1 appears 3 times, 2 appears 2 times, 3 appears 1 time.
    // Counts: {3, 2, 1} -> All unique.
    vector<int> arr1 = {1, 2, 2, 1, 1, 3};
    cout << "Test Case 1: " << (sol.uniqueOccurrences(arr1) ? "True" : "False") << endl;

    // Test Case 2: Duplicate Occurrences
    // 1 appears 2 times, 2 appears 2 times.
    // Counts: {2, 2} -> Duplicate count found.
    vector<int> arr2 = {1, 2};
    cout << "Test Case 2: " << (sol.uniqueOccurrences(arr2) ? "True" : "False") << endl;

    // Test Case 3: Negative numbers
    // -3 appears 3 times, 0 appears 1 time.
    // Counts: {3, 1} -> Unique.
    vector<int> arr3 = {-3, 0, 1, -3, 1, 1, 1, -3, 10, 0}; 
    // Wait, let's trace carefully: 
    // -3: 3 times
    // 0: 2 times
    // 1: 4 times
    // 10: 1 time
    // Counts: {3, 2, 4, 1} -> Unique.
    cout << "Test Case 3: " << (sol.uniqueOccurrences(arr3) ? "True" : "False") << endl;

    return 0;
}