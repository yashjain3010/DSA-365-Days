#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        // Safety check: if array is smaller than k, no subarray of size k exists
        if(arr.size() < k) return 0;
        
        int l = 0, r = k, cnt = 0;

        long long sum = 0;
        // Initialize the first window
        for(int i = 0 ; i < r ; i++){
            sum += arr[i];
        }

        // Check the first window
        // Note: Integer division sum/k works for this problem because if sum/k >= threshold,
        // then sum >= k * threshold is implied.
        if(sum/k >= threshold) cnt++;

        // Slide the window
        while(r < arr.size()){
            // Add new element, remove old element
            sum += arr[r] - arr[l];
            
            if(sum/k >= threshold) cnt++;
            l++;
            r++;
        }
        return cnt;
    }
};

int main() {
    Solution sol;

    // Test Case 1: [2,2,2,2,5,5,5,8], k=3, threshold=4
    // [2,5,5] (avg 4), [5,5,5] (avg 5), [5,5,8] (avg 6) -> 3 valid subarrays
    vector<int> arr1 = {2, 2, 2, 2, 5, 5, 5, 8};
    int k1 = 3;
    int t1 = 4;
    cout << "Input: arr=[2,2,2,2,5,5,5,8], k=3, threshold=4" << endl;
    cout << "Output: " << sol.numOfSubarrays(arr1, k1, t1) << endl; 

    // Test Case 2: [1,1,1,1,1], k=1, threshold=0
    // All 5 elements have avg >= 0
    vector<int> arr2 = {1, 1, 1, 1, 1};
    int k2 = 1;
    int t2 = 0;
    cout << "\nInput: arr=[1,1,1,1,1], k=1, threshold=0" << endl;
    cout << "Output: " << sol.numOfSubarrays(arr2, k2, t2) << endl; 

    return 0;
}