#include <iostream>
#include <vector>

using namespace std;

class NumMatrix {
public:
    NumMatrix(vector<vector<int>>& matrix) {
        a = matrix;
        m = sumMatrix(a);
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        row1++, col1++, row2++, col2++;

        return m[row2][col2] - m[row1 - 1][col2] - m[row2][col1 - 1] + m[row1 - 1][col1 - 1];
    }

private:
    vector<vector<int>> a, m;

    vector<vector<int>> sumMatrix(vector<vector<int>>& a) {
        int n = a.size(), m = a[0].size();
        vector<vector<int>> sum(n + 2, vector<int>(m + 2, 0));

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + a[i - 1][j - 1];
            }
        }

        return sum;
    }
};

int main() {
    vector<vector<int>> matrix = {{3, 0, 1, 4, 2}, {5, 6, 3, 2, 1}, {1, 2, 0, 1, 5}, {4, 1, 0, 1, 7}, {1, 0, 3, 0, 5}};

    NumMatrix* obj = new NumMatrix(matrix);
    cout << obj->sumRegion(2, 1, 4, 3) << endl;
    cout << obj->sumRegion(1, 1, 2, 2) << endl;
    cout << obj->sumRegion(1, 2, 2, 4) << endl;

    return 0;
}
