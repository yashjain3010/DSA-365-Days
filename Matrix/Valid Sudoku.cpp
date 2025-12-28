#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // Use maps to track counts for rows and columns
        // Optimization Tip: vector<int> counts(10, 0) is faster than unordered_map
        vector<unordered_map<char, int>> rmp(9);
        vector<unordered_map<char, int>> cmp(9);

        // Pass 1: Check Rows and Columns
        for(int i = 0 ; i < 9 ; i++){
            for(int j = 0 ; j < 9 ; j++){
                if(board[i][j] != '.'){
                    char val = board[i][j];
                    rmp[i][val]++;
                    cmp[j][val]++;

                    // If count > 1, it's invalid
                    if(rmp[i][val] > 1 || cmp[j][val] > 1){
                        return false;
                    }
                }
            }
        }

        // Pass 2: Check 3x3 Sub-grids
        for(int i = 0 ; i < 9 ; i++){
            for(int j = 0 ; j < 9 ; j++){
                if(board[i][j] != '.'){
                    // Calculate top-left corner of the 3x3 block
                    int r = 3 * (i / 3);
                    int c = 3 * (j / 3);

                    // Iterate through the 3x3 block
                    for(int x = r ; x < r + 3 ; x++){
                        for(int y = c ; y < c + 3 ; y++){
                            // Logic Note: Your condition (x != i && y != j) skips:
                            // 1. The cell itself
                            // 2. Cells in the same row within the box (already checked in Pass 1)
                            // 3. Cells in the same col within the box (already checked in Pass 1)
                            // This effectively checks only diagonal neighbors inside the box.
                            // This is valid ONLY because Pass 1 ran first.
                            if(x != i && y != j){
                                if(board[i][j] == board[x][y]){
                                    return false;
                                }
                            }
                        }
                    }
                }
            }
        }
        return true;
    }
};

int main() {
    Solution sol;

    // Test Case 1: Valid Board
    vector<vector<char>> board1 = {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };

    cout << "Test Case 1 (Valid): " << (sol.isValidSudoku(board1) ? "True" : "False") << endl;

    // Test Case 2: Invalid (Duplicate '8' in top-left 3x3 sub-box)
    // Note: Row 0 has '5', Row 1 has '5' in same column? No.
    // Let's force an error: Change (0,0) to '8' and (1,1) to '8'. 
    // They are in same box but different row/col.
    vector<vector<char>> board2 = board1;
    board2[0][0] = '8'; 
    board2[1][1] = '8'; 

    cout << "Test Case 2 (Invalid Box): " << (sol.isValidSudoku(board2) ? "True" : "False") << endl;

    return 0;
}