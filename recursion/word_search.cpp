#include <iostream>
#include <vector>
#include <string>
using namespace std;

int m;
int n;

vector<vector<int>> directions = {
    {0, 1},   // Right
    {0, -1},  // Left
    {1, 0},   // Down
    {-1, 0}   // Up
};

bool find(int i, int j,
          vector<vector<char>> &board,
          int idx,
          string &word) {

    // Word found
    if (idx == word.length()) {
        return true;
    }

    // Invalid cell
    if (i >= m || j >= n || i < 0 || j < 0 ||
        board[i][j] == '&' ||
        board[i][j] != word[idx]) {

        return false;
    }

    // Mark visited
    char temp = board[i][j];
    board[i][j] = '&';

    // Explore all 4 directions
    for (auto &dir : directions) {

        int new_i = i + dir[0];
        int new_j = j + dir[1];

        if (find(new_i, new_j, board, idx + 1, word)) {
            return true;
        }
    }

    // Backtrack
    board[i][j] = temp;

    return false;
}

bool exist(vector<vector<char>> &board, string word) {

    m = board.size();
    n = board[0].size();

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {

            if (board[i][j] == word[0] &&
                find(i, j, board, 0, word)) {

                return true;
            }
        }
    }

    return false;
}

int main() {

    vector<vector<char>> board = {
        {'A', 'B', 'C', 'E'},
        {'S', 'F', 'C', 'S'},
        {'A', 'D', 'E', 'E'}
    };

    string word = "ABCCED";

    if (exist(board, word))
        cout << "Word Found\n";
    else
        cout << "Word Not Found\n";

    return 0;
}