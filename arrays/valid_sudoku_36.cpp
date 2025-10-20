#include <iostream>
#include <vector>
#include <unordered_set>
#include <array>

using namespace std;

bool isValidSudoku(vector<vector<char>>& board) {
    array<unordered_set<char>, 9> rows;
    array<unordered_set<char>, 9> cols;
    array<unordered_set<char>, 9> boxes;

    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            char c = board[i][j];

            if (c == '.') {
                continue;
            }

            int box_index = (i / 3) * 3 + (j / 3);

            if (rows[i].count(c)) {
                return false;
            }
            
            if (cols[j].count(c)) {
                return false;
            }

            if (boxes[box_index].count(c)) {
                return false;
            }

            rows[i].insert(c);
            cols[j].insert(c);
            boxes[box_index].insert(c);
        }
    }

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

    cout << isValidSudoku(board) << endl;

    return 0;
}
