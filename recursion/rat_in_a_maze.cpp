#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int new_row;
int new_col;
int n, m;

vector<vector<int>> directions = {
    {0, -1},   // Left
    {0, 1},    // Right
    {1, 0},    // Down
    {-1, 0}    // Up
};

vector<char> moves = {'L', 'R', 'D', 'U'};

void solve(int row, int col,
           vector<vector<int>>& maze,
           vector<string>& ans,
           string &s) {

    if (row == n - 1 && col == m - 1) {
        ans.push_back(s);
        return;
    }

    maze[row][col] = 0;

    for (int i = 0; i < 4; i++) {

        new_row = row + directions[i][0];
        new_col = col + directions[i][1];

        if (new_row >= 0 && new_row < n &&
            new_col >= 0 && new_col < m &&
            maze[new_row][new_col] == 1) {

            s.push_back(moves[i]);

            solve(new_row, new_col, maze, ans, s);

            s.pop_back();
        }
    }

    maze[row][col] = 1;
}

vector<string> ratInMaze(vector<vector<int>>& maze) {

    n = maze.size();
    m = maze[0].size();

    vector<string> ans;
    string s;

    if (maze[0][0] == 0)
        return ans;

    solve(0, 0, maze, ans, s);

    sort(ans.begin(), ans.end());

    return ans;
}

int main() {

    vector<vector<int>> maze = {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {1, 1, 0, 0},
        {0, 1, 1, 1}
    };

    vector<string> ans = ratInMaze(maze);

    for (auto path : ans) {
        cout << path << endl;
    }

    return 0;
}