#include <iostream>
#include <vector>
#include <functional>
#include <queue>

using namespace std;

struct Element {
    int val;
    int row;
    int col;

    bool operator>(const Element& other) const {
        return val > other.val;
    };
};

int kthSmallest(vector<vector<int>>& matrix, int k) {
    int n = matrix.size();
    priority_queue<Element, vector<Element>, greater<Element>> minHeap;

    for (int i = 0; i < n; i++) {
        minHeap.push({matrix[i][0], i, 0});
    }

    Element e;
    for (int i = 0; i < k; i++) {
        e = minHeap.top();
        minHeap.pop();

        if (e.col + 1 < n) {
            minHeap.push({matrix[e.row][e.col + 1], e.row, e.col + 1});
        }
    }

    return e.val;
}

int main() {
    vector<vector<int>> matrix = {{1, 5, 9},{10, 11, 13},{12, 13, 15}};
    int k = 8;

    cout << kthSmallest(matrix, k) << endl;

    return 0;
}
