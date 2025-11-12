#include <iostream>
#include <vector>

using namespace std;

void dfs_mark(vector<vector<char>>& board, int i, int j) {
    int n = board.size(), m = board[0].size();

    if (i < 0 || i >= n || j < 0 || j >= m || board[i][j] != 'O') {
        return;
    }

    board[i][j] = '#';

    dfs_mark(board, i + 1, j);
    dfs_mark(board, i - 1, j);
    dfs_mark(board, i, j + 1);
    dfs_mark(board, i, j - 1);
}

void solve(vector<vector<char>>& board) {
    int n = board.size(), m = board[0].size();
    
    if (n == 0 || m == 0) {
        return;
    }

    for (int i = 0; i < n; i++) {
        if (board[i][0] == 'O') {
            dfs_mark(board, i, 0);
        }

        if (board[i][m - 1] == 'O') {
            dfs_mark(board, i, m - 1);
        }
    }

    for (int j = 0; j < m; j++) {
        if (board[0][j] == 'O') {
            dfs_mark(board, 0, j);
        }

        if (board[n - 1][j] == 'O') {
            dfs_mark(board, n - 1, j);
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (board[i][j] == 'O') {
                board[i][j] = 'X';
            } else if (board[i][j] == '#') {
                board[i][j] = 'O';
            }
        }
    }
}

int main() {
    vector<vector<char>> board = {{'X','O','X'},{'X','O','X'},{'X','O','X'}};

    solve(board);

    for (const auto& row : board) {
        for (const auto& column : row) {
            cout << column << " ";
        }
        cout << endl;
    }

    return 0;
}
