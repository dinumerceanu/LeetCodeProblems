#include <iostream>
#include <vector>

using namespace std;

vector<int> spiralOrder(vector<vector<int>>& matrix) {
    vector<int> res;
    
    if (matrix.empty()) {
        return res;
    }

    int top = 0, bottom = matrix.size() - 1;
    int left = 0, right = matrix[0].size() - 1;

    while (top <= bottom && left <= right) {
        for (int j = left; j <= right; j++) {
            res.push_back(matrix[top][j]);
        }
        top++;

        for (int i = top; i <= bottom; i++) {
            res.push_back(matrix[i][right]);
        }
        right--;

        if (top <= bottom) {
            for (int j = right; j >= left; j--) {
                res.push_back(matrix[bottom][j]);
            }
            bottom--;
        }

        if (left <= right) {
            for (int i = bottom; i >= top; i--) {
                res.push_back(matrix[i][left]);
            }
            left++;
        }
    }

    return res;
}

int main() {
    vector<vector<int>> matrix = {{1,2,3,4}, {5,6,7,8}, {9,10,11,12}};
    vector<int> spiral = spiralOrder(matrix);

    for (const auto& num : spiral) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
