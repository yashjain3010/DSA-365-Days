#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> result(n);

        // Simulate dropping a ball for every column 'i'
        for (int i = 0; i < n; ++i) {
            int current_col = i;
            int current_row = 0;
            bool is_stuck = false;

            // Trace the path of the ball downwards
            while (current_row < m) {
                // Determine direction: 1 (Right) or -1 (Left)
                int direction = grid[current_row][current_col];
                
                // Calculate where the ball wants to go
                int next_col = current_col + direction;

                // CHECK STUCK CONDITIONS:
                // 1. Wall Check: Is next_col out of bounds?
                // 2. 'V' Shape Check: Is the board at next_col different from current_col?
                //    (Example: Current is '\' (1), Next is '/' (-1) -> Stuck)
                if (next_col < 0 || next_col >= n || grid[current_row][next_col] != direction) {
                    is_stuck = true;
                    break;
                }

                // Move ball to the next position (down one row, and to the calculated column)
                current_col = next_col;
                current_row++;
            }

            // If stuck, record -1. Otherwise, record the exit column.
            if (is_stuck) {
                result[i] = -1;
            } else {
                result[i] = current_col;
            }
        }

        return result;
    }
};

// --- Test Driver ---
void printVector(const vector<int>& v) {
    cout << "[";
    for (int i = 0; i < v.size(); ++i) {
        cout << v[i] << (i < v.size() - 1 ? "," : "");
    }
    cout << "]" << endl;
}

int main() {
    Solution sol;

    // Example Grid:
    //  1  1  1 -1 -1
    //  1  1  1 -1 -1
    // -1 -1 -1  1  1
    //  1  1  1  1 -1
    // -1 -1 -1 -1 -1
    vector<vector<int>> grid = {
        {1, 1, 1, -1, -1},
        {1, 1, 1, -1, -1},
        {-1, -1, -1, 1, 1},
        {1, 1, 1, 1, -1},
        {-1, -1, -1, -1, -1}
    };

    vector<int> ans = sol.findBall(grid);
    
    // Expected Output: [1, -1, -1, -1, -1]
    // Ball 0: Ends at col 1
    // Ball 1: Stuck
    // Ball 2: Stuck
    // Ball 3: Stuck
    // Ball 4: Stuck
    cout << "Result: ";
    printVector(ans);

    return 0;
}