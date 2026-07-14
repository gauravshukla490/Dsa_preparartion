#include <bits/stdc++.h>
using namespace std;

bool isValid(vector<vector<char>>& board, int row, int col, char c) {

    for (int i = 0; i < 9; i++) {

        // Row Check
        if (board[row][i] == c)
            return false;

        // Column Check
        if (board[i][col] == c)
            return false;

        // 3x3 Block Check
        if (board[3 * (row / 3) + (i / 3)][3 * (col / 3) + (i % 3)] == c)
            return false;
    }

    return true;
}

bool solve(vector<vector<char>>& board) {

    for (int row = 0; row < 9; row++) {

        for (int col = 0; col < 9; col++) {

            // Empty cell
            if (board[row][col] == '.') {

                // Try 1 to 9
                for (char c = '1'; c <= '9'; c++) {

                    if (isValid(board, row, col, c)) {

                        // Choose
                        board[row][col] = c;

                        // Explore
                        if (solve(board))
                            return true;

                        // Undo
                        board[row][col] = '.';
                    }
                }

                // No number fits
                return false;
            }
        }
    }

    // Sudoku Solved
    return true;
}

int main() {

    vector<vector<char>> board = {
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

    solve(board);

    cout << "Solved Sudoku:\n\n";

    for (auto row : board) {
        for (auto cell : row)
            cout << cell << " ";
        cout << endl;
    }

    return 0;
}