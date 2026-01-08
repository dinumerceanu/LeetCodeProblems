#include <iostream>
#include <vector>

using namespace std;

bool dfs(vector<vector<char>>& board, int i, int j, int index, string& word) {
    int n = board.size(), m = board[0].size();
    
    if (index == word.length()) {
        return true;
    }

    if (i < 0 || i >= n || j < 0 || j >= m || board[i][j] != word[index]) {
        return false;
    }

    char c = board[i][j];
    board[i][j] = '#';

    if (dfs(board, i + 1, j, index + 1, word) ||
        dfs(board, i - 1, j, index + 1, word) ||
        dfs(board, i, j + 1, index + 1, word) ||
        dfs(board, i, j - 1, index + 1, word)) {
        return true;
    }

    board[i][j] = c;

    return false;
}

bool exist(vector<vector<char>>& board, string word) {
    int n = board.size(), m = board[0].size();
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (board[i][j] == word[0]) {
                int index = 0;

                if (dfs(board, i, j, index, word)) {
                    return true;
                }
            }
        }
    }

    return false;
}

int main() {
    vector<vector<char>> board = {{'A','B','C','E'}, {'S','F','C','S'}, {'A','D','E','E'}};
    string word = "ABCCED";

    cout << exist(board, word) << endl;

    return 0;
}
