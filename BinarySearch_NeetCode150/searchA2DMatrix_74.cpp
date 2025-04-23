#include <iostream>
#include <vector>

using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int rows = matrix.size(), cols = matrix[0].size(), left = 0, right = rows * cols - 1, mid, mid2;

    while (left <= right) {
        mid = (left + right) / 2;
        mid2 = matrix[mid / cols][mid % cols];
        if (mid2 == target)
            return true;
        if (mid2 < target)
            left = mid + 1;
        else
            right = mid - 1;
    }

    return false;
}

int main() {
    vector<vector<int>> matrix = {{1,3,5,7},{10,11,16,20},{23,30,34,60}};
    cout<<searchMatrix(matrix, 3);

    return 0;
}