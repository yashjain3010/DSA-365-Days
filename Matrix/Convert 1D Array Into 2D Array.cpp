#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        // Validation: Check if the total elements match the dimensions
        if(m * n != original.size()) return {};
        
        // Initialize the result matrix
        vector<vector<int>> result(m, vector<int>(n));

        for(int i = 0 ; i < original.size() ; i++){
            // Logic to map 1D index 'i' to 2D coordinates [row][col]
            int row = i / n;
            int col = i % n;

            result[row][col] = original[i];
        }
        return result;
    }
};

int main() {
    Solution sol;

    // Test Case 1: Standard Example
    // Input: original = [1,2,3,4], m = 2, n = 2
    // Expected: [[1,2], [3,4]]
    vector<int> original1 = {1, 2, 3, 4};
    int m1 = 2;
    int n1 = 2;

    cout << "Test Case 1:" << endl;
    cout << "Input: [ ";
    for(int x : original1) cout << x << " ";
    cout << "], m: " << m1 << ", n: " << n1 << endl;

    vector<vector<int>> res1 = sol.construct2DArray(original1, m1, n1);

    if(res1.empty()) {
        cout << "Result: []" << endl;
    } else {
        cout << "Result:" << endl;
        cout << "[" << endl;
        for(const auto& row : res1) {
            cout << "  [";
            for(size_t i = 0; i < row.size(); i++) {
                cout << row[i] << (i < row.size() - 1 ? "," : "");
            }
            cout << "]" << endl;
        }
        cout << "]" << endl;
    }
    cout << "-----------------" << endl;

    // Test Case 2: Invalid Dimensions
    // Input: original = [1,2], m = 1, n = 1
    // Expected: [] (Because 1*1 != 2)
    vector<int> original2 = {1, 2};
    int m2 = 1;
    int n2 = 1;

    cout << "Test Case 2:" << endl;
    cout << "Input: [ ";
    for(int x : original2) cout << x << " ";
    cout << "], m: " << m2 << ", n: " << n2 << endl;

    vector<vector<int>> res2 = sol.construct2DArray(original2, m2, n2);

    if(res2.empty()) {
        cout << "Result: []" << endl;
    } else {
        // This block shouldn't run for this test case
        for(const auto& row : res2) {
             for(int x : row) cout << x << " ";
             cout << endl;
        }
    }

    return 0;
}