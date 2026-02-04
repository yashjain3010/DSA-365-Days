#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // Check if placing a piece of 'color' at (rMove, cMove) is a legal move
    // A move is legal if it captures at least one opponent piece line.
    bool checkMove(vector<vector<char>>& board, int rMove, int cMove, char color) {
        // Directions: Right, Down, Left, Up, and 4 Diagonals
        static const int dx[8] = {0, 1, 0, -1, -1, 1, 1, -1};
        static const int dy[8] = {1, 0, -1, 0, 1, 1, -1, -1};

        // Determine opponent's color
        char opp = (color == 'B') ? 'W' : 'B';

        // Check all 8 directions
        for(int d = 0 ; d < 8 ; d++){
            int x = rMove + dx[d];
            int y = cMove + dy[d];
            bool seen_opp = false;

            // Traverse in the current direction
            // We need to find at least one opponent piece, followed immediately by our color.
            while(x >= 0 && y >= 0 && x < 8 && y < 8 && board[x][y] != '.'){
                if(board[x][y] == opp) {
                    seen_opp = true;
                }
                else if (board[x][y] == color) {
                    // We found our own color. 
                    // If we saw opponent pieces in between, this is a valid line.
                    if (seen_opp) return true;
                    // If we didn't see opponent pieces (immediate neighbor is same color),
                    // this direction is invalid.
                    else break; 
                }
                else {
                    // Should not hit this else block given board[x][y] != '.' condition
                    break;
                }
                
                // Move further in the direction
                x += dx[d];
                y += dy[d];
            }
        }
        return false;
    }
};

// Helper function to print the board
void printBoard(const vector<vector<char>>& board) {
    cout << "  0 1 2 3 4 5 6 7" << endl;
    for (int i = 0; i < 8; ++i) {
        cout << i << " ";
        for (int j = 0; j < 8; ++j) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    Solution sol;

    // Test Case 1: Standard Capture
    // Board state where placing 'W' at (4, 4) captures 'B's
    // Row 4: ... W B B . ... -> Place W at (4,4) -> ... W B B W ... (Valid)
    vector<vector<char>> board1(8, vector<char>(8, '.'));
    board1[4][3] = 'B';
    board1[4][2] = 'B';
    board1[4][1] = 'W'; // Anchor

    cout << "Test Case 1 (Row 4 has 'W B B .'):" << endl;
    printBoard(board1);
    cout << "Check Move (W at 4,4): " << (sol.checkMove(board1, 4, 4, 'W') ? "True" : "False") << endl;
    cout << "-----------------" << endl;

    // Test Case 2: Immediate Neighbor is Same Color (Invalid)
    // Board: W .
    // Place W at (0, 1). Neighbor is W. No sandwich.
    board1[0][0] = 'W';
    cout << "Test Case 2 (W at 0,1, neighbor is W): " << (sol.checkMove(board1, 0, 1, 'W') ? "True" : "False") << endl;
    cout << "-----------------" << endl;

    // Test Case 3: Empty space in between (Invalid)
    // Board: W . B .
    // Place W at (0, 3). Line is W . B W. The dot breaks the line.
    vector<vector<char>> board3(8, vector<char>(8, '.'));
    board3[0][0] = 'W';
    board3[0][2] = 'B';
    
    cout << "Test Case 3 (Gap in line 'W . B .'):" << endl;
    // Trying to place W at 0,3
    cout << "Check Move (W at 0,3): " << (sol.checkMove(board3, 0, 3, 'W') ? "True" : "False") << endl;

    return 0;
}