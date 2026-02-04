#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<int> findIntersectionValues(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();

        // Create Hash Sets for O(1) lookups
        // s1 contains unique elements from nums1
        // s2 contains unique elements from nums2
        unordered_set<int> s1(nums1.begin(), nums1.end());
        unordered_set<int> s2(nums2.begin(), nums2.end());

        int answer1 = 0, answer2 = 0;

        // Calculate answer1: Count elements in nums1 that exist in set s2
        for(int i = 0 ; i < n ; i++){
            // We iterate over the original array nums1 to account for duplicates
            if(s2.find(nums1[i]) != s2.end()){
                answer1++;
            }
        }

        // Calculate answer2: Count elements in nums2 that exist in set s1
        for(int i = 0 ; i < m ; i++){
            if(s1.find(nums2[i]) != s1.end()){
                answer2++;
            }
        }

        return {answer1, answer2};
    }
};

// Helper function to print vector
void printVector(const vector<int>& v) {
    cout << "[ ";
    for (int x : v) cout << x << " ";
    cout << "]" << endl;
}

int main() {
    Solution sol;

    // Test Case 1: Standard Intersection
    // nums1 = [4,3,2,3,1], nums2 = [2,2,5,2,3,6]
    // Common elements in s2 (2, 5, 3, 6): 4(no), 3(yes), 2(yes), 3(yes), 1(no) -> answer1 = 3
    // Common elements in s1 (4, 3, 2, 1): 2(yes), 2(yes), 5(no), 2(yes), 3(yes), 6(no) -> answer2 = 4
    vector<int> nums1 = {4, 3, 2, 3, 1};
    vector<int> nums2 = {2, 2, 5, 2, 3, 6};

    cout << "Test Case 1:" << endl;
    vector<int> result1 = sol.findIntersectionValues(nums1, nums2);
    printVector(result1);
    cout << "-----------------" << endl;

    // Test Case 2: No Intersection
    vector<int> nums3 = {3, 4, 2, 3};
    vector<int> nums4 = {1, 5};

    cout << "Test Case 2:" << endl;
    vector<int> result2 = sol.findIntersectionValues(nums3, nums4);
    printVector(result2);

    return 0;
}