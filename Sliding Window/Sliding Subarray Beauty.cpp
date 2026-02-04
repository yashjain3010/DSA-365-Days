#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    // Helper to find the x-th smallest negative number
    int helper(map<int, int>& mpp, int x){
        int count = 0;
        // Map is sorted, so iterating gives us numbers in ascending order (-5, -3, -1...)
        for(auto it : mpp){
            count += it.second;
            if(count >= x){
                return it.first;
            }
        }
        // Return 0 if there are fewer than x negative numbers
        return 0;
    }

    vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {
        int n = nums.size();
        map<int,int> mpp;

        vector<int> ans;

        int i = 0, j = 0;

        while(j < n){
            // Add new element to map ONLY if it is negative
            if(nums[j] < 0){
                mpp[nums[j]]++;
            }

            if(j-i+1 < k){
                j++;
            } else { // Window size is k (using else handles the == k case)
                
                // Find x-th beauty
                int xthElement = helper(mpp, x);
                ans.push_back(xthElement);

                // Remove old element ONLY if it was added (i.e., if it is negative)
                if(nums[i] < 0){
                    mpp[nums[i]]--;
                    if(mpp[nums[i]] == 0){
                        mpp.erase(nums[i]);
                    }
                }
                
                i++;
                j++;
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;

    // Test Case 1: nums = [1, -1, -3, -2, 3], k = 3, x = 2
    // Windows:
    // [1, -1, -3] -> Negatives: [-3, -1]. 2nd smallest is -1.
    // [-1, -3, -2] -> Negatives: [-3, -2, -1]. 2nd smallest is -2.
    // [-3, -2, 3] -> Negatives: [-3, -2]. 2nd smallest is -2.
    vector<int> nums1 = {1, -1, -3, -2, 3};
    int k1 = 3;
    int x1 = 2;
    vector<int> res1 = sol.getSubarrayBeauty(nums1, k1, x1);
    
    cout << "Input: nums=[1, -1, -3, -2, 3], k=3, x=2" << endl;
    cout << "Output: [";
    for(size_t i=0; i<res1.size(); ++i) cout << res1[i] << (i<res1.size()-1?", ":"");
    cout << "]" << endl; // Expected: [-1, -2, -2]

    // Test Case 2: nums = [-1, -2, -3, -4, -5], k = 2, x = 2
    // [-1, -2] -> Sorted [-2, -1]. 2nd is -1.
    // [-2, -3] -> Sorted [-3, -2]. 2nd is -2.
    // [-3, -4] -> Sorted [-4, -3]. 2nd is -3.
    // [-4, -5] -> Sorted [-5, -4]. 2nd is -4.
    vector<int> nums2 = {-1, -2, -3, -4, -5};
    int k2 = 2;
    int x2 = 2;
    vector<int> res2 = sol.getSubarrayBeauty(nums2, k2, x2);

    cout << "\nInput: nums=[-1, -2, -3, -4, -5], k=2, x=2" << endl;
    cout << "Output: [";
    for(size_t i=0; i<res2.size(); ++i) cout << res2[i] << (i<res2.size()-1?", ":"");
    cout << "]" << endl; // Expected: [-1, -2, -3, -4]

    // Test Case 3: nums = [1, 2, 3], k = 2, x = 1
    // No negatives -> 0
    vector<int> nums3 = {1, 2, 3};
    vector<int> res3 = sol.getSubarrayBeauty(nums3, 2, 1);
    cout << "\nInput: nums=[1, 2, 3], k=2, x=1" << endl;
    cout << "Output: [";
    for(size_t i=0; i<res3.size(); ++i) cout << res3[i] << (i<res3.size()-1?", ":"");
    cout << "]" << endl; // Expected: [0, 0]

    return 0;
}