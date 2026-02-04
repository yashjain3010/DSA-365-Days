#include <iostream>
#include <vector>
#include <algorithm> // For swap

using namespace std;

class Solution {
private:
    // Helper function to simulate gravity within a single row
    // effectively moving stones ('#') to the "right" (which becomes "down" after rotation)
    void solve(vector<char> &s){
        int l = s.size()-1, r = s.size()-1;
        while(l >= 0){
            if(s[l] == '.'){
                l--;
            }
            else if(s[l] == '#'){
                // If we found a stone, swap it to the lowest available position (r)
                if(s[r] == '.'){
                    swap(s[r], s[l]);
                }
                // Move the available position pointer and the scan pointer
                r--;
                l--;
            }
            else if(s[l] == '*'){
                // Obstacle found: stones cannot fall past this.
                // Reset the "available position" pointer 'r' to be immediately left of obstacle
                l--;
                r = l;
            }
        }
    }
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        // Step 1: Simulate gravity for every row
        // We move stones to the RIGHT because that side will become the BOTTOM
        for(int row = 0 ; row < box.size() ; row++){
            solve(box[row]);
        }

        int m = box.size();
        int n = box[0].size();

        // Step 2: Rotate the matrix 90 degrees clockwise
        // New dimensions will be n x m
        vector<vector<char>> ans(n, vector<char> (m));

        for(int row = 0 ; row < m ; row++){
            for(int col = 0 ; col < n ; col++){
                // Coordinate transformation for 90 deg clockwise rotation
                ans[col][m - row - 1] = box[row][col];
            }
        }
        return ans;
    }
};

// Helper function to print the box
void printBox(const vector<vector<char>>& box) {
    cout << "[" << endl;
    for (const auto& row : box) {
        cout << "  [ ";
        for (char c : row) {
            cout << "'" << c << "' ";
        }
        cout << "]" << endl;
    }
    cout << "]" << endl;
}

int main() {
    Solution sol;

    // Test Case 1: Standard
    // Box:
    // [ # . * . ]
    // [ # # * . ]
    // Gravity (to right):
    // [ . # * . ]
    // [ # # * . ]
    // Rotate 90 deg clockwise:
    // [ # . ]
    // [ # # ]
    // [ * * ]
    // [ . . ]
    
    vector<vector<char>> box1 = {
        {'#', '.', '*', '.'},
        {'#', '#', '*', '.'}
    };

    cout << "Original Box:" << endl;
    printBox(box1);

    vector<vector<char>> result1 = sol.rotateTheBox(box1);

    cout << "Rotated Box:" << endl;
    printBox(result1);

    return 0;
}