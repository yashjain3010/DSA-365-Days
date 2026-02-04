#include <iostream>
#include <vector>
#include <cmath> // For abs

using namespace std;

class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size();
        int n = board[0].size();

        // Corrected syntax for directions array
        vector<vector<int>> dirs = {
            {1,0}, {-1,0}, {0,-1}, {0,1}, 
            {1,1}, {1,-1}, {-1,1}, {-1,-1}
        };

        for (int i = 0 ; i < m ; i++) {
            for(int j = 0 ; j < n ; j++){
                int liveNeighbors = 0;
                
                // Count neighbors
                for(auto& d : dirs){
                    int x = i + d[0];
                    int y = j + d[1];
                    
                    // Check bounds
                    // abs(board[x][y]) == 1 handles cells that are currently 1 
                    // OR cells that were 1 but marked as -1 (dying)
                    if(x >= 0 && x < m && y >= 0 && y < n && abs(board[x][y]) == 1){
                        liveNeighbors++;
                    }
                }

                // Rule 1 & 3: Live cell dies (<2 or >3 neighbors)
                // We mark it as -1. It is currently "Live" (abs(-1)=1) but will become "Dead".
                if(board[i][j] == 1 && (liveNeighbors < 2 || liveNeighbors > 3)){
                    board[i][j] = -1;
                }

                // Rule 4: Dead cell becomes live (3 neighbors)
                // We mark it as 2. It is currently "Dead" (abs(2)!=1) but will become "Live".
                if(board[i][j] == 0 && liveNeighbors == 3){
                    board[i][j] = 2;
                }
            }
        }

        // Final Pass: Convert temporary states back to 0 or 1
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                // If value is 1 or 2, it ends up alive.
                // If value is 0 or -1, it ends up dead.
                board[i][j] = board[i][j] > 0 ? 1 : 0;
            }
        }
    }
};

// Helper function to print the board
void printBoard(const vector<vector<int>>& board) {
    cout << "[" << endl;
    for (const auto& row : board) {
        cout << "  [ ";
        for (int x : row) {
            cout << x << " ";
        }
        cout << "]" << endl;
    }
    cout << "]" << endl;
}

int main() {
    Solution sol;

    // Test Case 1: Standard Example
    // Input: 
    // [0,1,0]
    // [0,0,1]
    // [1,1,1]
    // [0,0,0]
    
    // Expected Output:
    // [0,0,0]
    // [1,0,1]
    // [0,1,1]
    // [0,1,0]
    
    vector<vector<int>> board = {
        {0, 1, 0},
        {0, 0, 1},
        {1, 1, 1},
        {0, 0, 0}
    };

    cout << "Original Board:" << endl;
    printBoard(board);

    sol.gameOfLife(board);

    cout << "Next State:" << endl;
    printBoard(board);

    return 0;
}