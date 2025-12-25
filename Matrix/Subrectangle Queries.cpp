class SubrectangleQueries {
    vector<vector<int>> rect;
    // Store updates as: {row1, col1, row2, col2, newValue}
    vector<vector<int>> updates; 
    
public:
    SubrectangleQueries(vector<vector<int>>& rectangle) {
        rect = rectangle;
    }
    
    // Time Complexity: O(1)
    void updateSubrectangle(int row1, int col1, int row2, int col2, int newValue) {
        updates.push_back({row1, col1, row2, col2, newValue});
    }
    
    // Time Complexity: O(K) where K is number of updates
    int getValue(int row, int col) {
        // Check updates from LATEST to OLDEST
        for (int i = updates.size() - 1; i >= 0; --i) {
            int r1 = updates[i][0];
            int c1 = updates[i][1];
            int r2 = updates[i][2];
            int c2 = updates[i][3];
            int val = updates[i][4];
            
            // If the requested (row, col) is inside this update box, return the value
            if (row >= r1 && row <= r2 && col >= c1 && col <= c2) {
                return val;
            }
        }
        // If no update covers this cell, return the original value
        return rect[row][col];
    }
};