#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    // Helper function to check if player 'p' has won
    bool win(vector<string>& b, char p) {
        // Check Rows and Columns
        for (int i = 0; i < 3; ++i){
            // Row i check || Col i check
            if ((b[i][0] == p && b[i][1] == p && b[i][2] == p) ||
                (b[0][i] == p && b[1][i] == p && b[2][i] == p))
                return true;
        }
        // Check Diagonals
        return (b[0][0] == p && b[1][1] == p && b[2][2] == p) ||
               (b[0][2] == p && b[1][1] == p && b[2][0] == p); 
    }

    bool validTicTacToe(vector<string>& board) {
        int X = 0, O = 0;
        
        // Count the number of Xs and Os
        for (int i = 0; i < 3; ++i){
            for (int j = 0; j < 3; ++j) {
                if (board[i][j] == 'X') ++X;
                else if (board[i][j] == 'O') ++O;
            }
        }

        // Rule 1: 'X' goes first.
        // So 'X' count must be either equal to 'O' (after O moves)
        // or one greater than 'O' (after X moves).
        if (O > X || X - O > 1) return false;

        // Check who won
        bool xWin = win(board, 'X');
        bool oWin = win(board, 'O');

        // Rule 2: Both cannot win simultaneously 
        // (The game ends as soon as one wins)
        if (xWin && oWin) return false;

        // Rule 3: If X wins, X must have made the last move.
        // Therefore, X count must be exactly O count + 1.
        if (xWin && X != O + 1) return false;

        // Rule 4: If O wins, O must have made the last move.
        // Therefore, X count must be exactly equal to O count.
        if (oWin && X != O) return false;

        return true;
    }
};

int main() {
    Solution sol;

    // Test Case 1: Valid Game (X wins)
    // X X X
    // . O O
    // . . .
    vector<string> board1 = {"XXX", " OO", "   "};
    cout << "Test Case 1 (X wins): " << (sol.validTicTacToe(board1) ? "True" : "False") << endl;

    // Test Case 2: Invalid Game (O wins but X moved again)
    // X O X
    // O X O
    // X O X
    // Here X=5, O=4. X wins diagonal. OK. But wait, count is fine.
    // Let's try: O wins, but X has more moves.
    // O O O
    // X X .
    // X . .
    // X=3, O=3. Valid? Yes.
    // X=4, O=3. Invalid if O wins.
    vector<string> board2 = {"OOO", "XX ", "X  "}; // X=3, O=3. O wins. Valid.
    cout << "Test Case 2 (O wins): " << (sol.validTicTacToe(board2) ? "True" : "False") << endl;

    // Test Case 3: Invalid (X moved after O won)
    vector<string> board3 = {"OOO", "XX ", "XX "}; // X=4, O=3. O wins. INVALID.
    cout << "Test Case 3 (O wins, X kept playing): " << (sol.validTicTacToe(board3) ? "True" : "False") << endl;

    // Test Case 4: Invalid (Moves out of order)
    // X plays twice in a row initially?
    vector<string> board4 = {"XX ", "   ", "   "}; // X=2, O=0. Invalid.
    cout << "Test Case 4 (X played twice): " << (sol.validTicTacToe(board4) ? "True" : "False") << endl;

    return 0;
}