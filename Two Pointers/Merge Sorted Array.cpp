#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1; 
        int j = n - 1;
        int r = m + n - 1;

        while(j >= 0){
            if(i >= 0 && nums1[i] > nums2[j]){
                nums1[r] = nums1[i];
                i--;
            } 
            else {
                nums1[r] = nums2[j]; 
                j--;
            }
            r--; 
        }
    }
};

int main() {
    Solution sol;
    vector<int> nums1 = {1, 2, 3, 0, 0, 0};
    int m = 3;
    vector<int> nums2 = {2, 5, 6};
    int n = 3;

    sol.merge(nums1, m, nums2, n);
    cout << "Merged Array (in nums1):" << endl;
    cout << "[";
    for (int k = 0; k < nums1.size(); ++k) {
        cout << nums1[k];
        if (k < nums1.size() - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;
   
    return 0; 
}

