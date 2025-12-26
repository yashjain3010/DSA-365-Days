#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens,
                                            vector<int>& king) {
        // Create an 8x8 board initialized with "-"
        vector<vector<string>> chessboard(8, vector<string>(8, "-"));

        // Place Queens on the board
        for (int i = 0; i < queens.size(); i++) {
            chessboard[queens[i][0]][queens[i][1]] = "Q";
        }

        int ki = king[0];
        int kj = king[1];
        chessboard[ki][kj] = "K"; // Technically not needed for logic, but good for visualization

        vector<vector<int>> strPos;

        // 1. Left-Traversal
        for (int j = kj - 1; j >= 0; j--) {
            if (chessboard[ki][j] == "Q") {
                strPos.push_back({ki, j});
                break; // Found the first queen in this direction, stop.
            }
        }

        // 2. Right-Traversal
        for (int j = kj + 1; j < 8; j++) {
            if (chessboard[ki][j] == "Q") {
                strPos.push_back({ki, j});
                break;
            }
        }

        // 3. Up-Traversal
        for (int i = ki - 1; i >= 0; i--) {
            if (chessboard[i][kj] == "Q") {
                strPos.push_back({i, kj});
                break;
            }
        }

        // 4. Down-Traversal
        for (int i = ki + 1; i < 8; i++) {
            if (chessboard[i][kj] == "Q") {
                strPos.push_back({i, kj});
                break;
            }
        }

        // 5. Diagonal Left-Up
        int x = ki - 1;
        int y = kj - 1;
        for (int i = x; i >= 0; i--) {
            if (y < 0) break;
            if (chessboard[i][y] == "Q") {
                strPos.push_back({i, y});
                break;
            }
            y--;
        }

        // 6. Diagonal Right-Down
        int xd = ki + 1;
        int yd = kj + 1;
        for (int i = xd; i < 8; i++) {
            if (yd >= 8) break;
            if (chessboard[i][yd] == "Q") {
                strPos.push_back({i, yd});
                break;
            }
            yd++;
        }

        // 7. Diagonal Right-Up
        int xR = ki - 1;
        int yR = kj + 1;
        for (int i = xR; i >= 0; i--) {
            if (yR >= 8) break;
            if (chessboard[i][yR] == "Q") {
                strPos.push_back({i, yR});
                break;
            }
            yR++;
        }

        // 8. Diagonal Left-Down
        int lx = ki + 1;
        int ly = kj - 1;
        for (int i = lx; i < 8; i++) {
            if (ly < 0) break;
            if (chessboard[i][ly] == "Q") {
                strPos.push_back({i, ly});
                break;
            }
            ly--;
        }

        return strPos;
    }
};

// Helper function to print the result
void printResult(const vector<vector<int>>& queens) {
    cout << "[";
    for (size_t i = 0; i < queens.size(); ++i) {
        cout << "[" << queens[i][0] << "," << queens[i][1] << "]";
        if (i < queens.size() - 1) cout << ", ";
    }
    cout << "]" << endl;
}

int main() {
    Solution sol;

    // Test Case 1: Standard Example
    // King at [0,0]. Queens at various spots.
    // Expected: [[0,1], [1,0], [3,3]] (Order may vary depending on traversal order)
    vector<vector<int>> queens1 = {{0,1}, {1,0}, {4,0}, {0,4}, {3,3}, {2,4}};
    vector<int> king1 = {0, 0};

    cout << "Test Case 1:" << endl;
    vector<vector<int>> result1 = sol.queensAttacktheKing(queens1, king1);
    printResult(result1);
    cout << "-----------------" << endl;

    // Test Case 2: King in the middle
    // King at [3,3]. Surrounded by 8 queens.
    vector<vector<int>> queens2 = {
        {3,0}, {3,2}, {3,4}, {3,5}, // Horizontal
        {0,3}, {1,3}, {4,3}, {5,3}, // Vertical
        {0,0}, {1,1}, {2,2}, {4,4}, {5,5}, {6,6}, {7,7} // Diagonals
    };
    vector<int> king2 = {3, 3};
    // Should detect the closest ones: {3,2}, {3,4}, {1,3}, {4,3}, {2,2}, {4,4}

    cout << "Test Case 2:" << endl;
    vector<vector<int>> result2 = sol.queensAttacktheKing(queens2, king2);
    printResult(result2);

    return 0;
}