#include <iostream>
#include <vector>

using namespace std;

class SubrectangleQueries {
    // We keep the original rectangle as the "base layer"
    vector<vector<int>> rect;
    
    // Store updates as vectors: {row1, col1, row2, col2, newValue}
    // This acts like a history log or layers of paint on a canvas
    vector<vector<int>> updates; 
    
public:
    SubrectangleQueries(vector<vector<int>>& rectangle) {
        rect = rectangle;
    }
    
    // Time Complexity: O(1) - Very fast!
    // We just write down the command to the log.
    void updateSubrectangle(int row1, int col1, int row2, int col2, int newValue) {
        updates.push_back({row1, col1, row2, col2, newValue});
    }
    
    // Time Complexity: O(K) where K is number of updates
    // We check the latest updates first. If we find one that covers our cell,
    // that must be the current value.
    int getValue(int row, int col) {
        // Iterate backwards from LATEST update to OLDEST
        for (int i = updates.size() - 1; i >= 0; --i) {
            int r1 = updates[i][0];
            int c1 = updates[i][1];
            int r2 = updates[i][2];
            int c2 = updates[i][3];
            int val = updates[i][4];
            
            // If the requested (row, col) falls inside this update's boundaries
            if (row >= r1 && row <= r2 && col >= c1 && col <= c2) {
                return val;
            }
        }
        
        // If no updates cover this cell, return the original value from the base layer
        return rect[row][col];
    }
};

int main() {
    // Test Case:
    // Initial Grid:
    // [1, 2, 1]
    // [4, 3, 4]
    // [3, 2, 1]
    // [1, 1, 1]
    vector<vector<int>> rectangle = {
        {1, 2, 1},
        {4, 3, 4},
        {3, 2, 1},
        {1, 1, 1}
    };

    SubrectangleQueries obj(rectangle);

    // Get value at (0, 2) -> Should be 1
    cout << "Value at (0, 2): " << obj.getValue(0, 2) << endl;

    // Update Top-Left 2x2 subrectangle to 5
    // Grid becomes:
    // [5, 5, 1]
    // [5, 5, 4] ...
    cout << "Updating (0,0) to (1,1) with value 5..." << endl;
    obj.updateSubrectangle(0, 0, 1, 1, 5);

    // Get value at (0, 2) -> Should still be 1 (outside update range)
    cout << "Value at (0, 2): " << obj.getValue(0, 2) << endl;

    // Get value at (0, 1) -> Should be 5 (inside update range)
    cout << "Value at (0, 1): " << obj.getValue(0, 1) << endl;

    // Update Bottom-Right to 10
    // Overlap test: Update (1,1) to (2,2) with 10
    // (1,1) was 5, now becomes 10.
    cout << "Updating (1,1) to (2,2) with value 10..." << endl;
    obj.updateSubrectangle(1, 1, 2, 2, 10);

    // Get value at (1, 1) -> Should be 10 (latest update wins)
    cout << "Value at (1, 1): " << obj.getValue(1, 1) << endl;

    // Get value at (0, 1) -> Should be 5 (covered by first update, not second)
    cout << "Value at (0, 1): " << obj.getValue(0, 1) << endl;

    return 0;
}