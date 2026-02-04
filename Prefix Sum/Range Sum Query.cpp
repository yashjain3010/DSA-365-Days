#include <iostream>
#include <vector>

using namespace std;

class NumArray {
public:
    vector<int> a;
    
    NumArray(vector<int>& nums) {
        if (nums.empty()) return;
        
        // Precompute prefix sums
        a.push_back(nums[0]);
        for(int i = 1 ; i < nums.size() ; i++){
            a.push_back(a[i-1] + nums[i]);
        }
    }
    
    int sumRange(int left, int right) {
        if(left == 0){
            return a[right];
        }
        return a[right] - a[left-1];
    }
};

int main() {
    // Example usage matching LeetCode's typical test case
    vector<int> nums = {-2, 0, 3, -5, 2, -1};
    cout << "Input Array: [";
    for (int i = 0; i < nums.size(); ++i) {
        cout << nums[i] << (i < nums.size() - 1 ? ", " : "");
    }
    cout << "]" << endl;

    NumArray* obj = new NumArray(nums);
    
    // Test case 1: sumRange(0, 2) -> (-2) + 0 + 3 = 1
    cout << "sumRange(0, 2): " << obj->sumRange(0, 2) << endl;
    
    // Test case 2: sumRange(2, 5) -> 3 + (-5) + 2 + (-1) = -1
    cout << "sumRange(2, 5): " << obj->sumRange(2, 5) << endl;
    
    // Test case 3: sumRange(0, 5) -> Total sum = -3
    cout << "sumRange(0, 5): " << obj->sumRange(0, 5) << endl;

    delete obj;
    return 0;
}