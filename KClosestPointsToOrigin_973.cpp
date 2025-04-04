#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

double computeDistance(vector<int> a) {
    return sqrt(a[0] * a[0] + a[1] * a[1]);
}

vector<vector<int>> slice(vector<vector<int>>& v, int start, int end) {
    if (start < 0) start = 0;
    if (end > v.size()) end = v.size();
    if (start > end) return {};

    return vector<vector<int>>(v.begin() + start, v.begin() + end);
}

vector<vector<int>> merge(vector<vector<int>>a, vector<vector<int>> b) {
    int i = 0, j = 0;
    vector<vector<int>> aux;
    while (i < a.size() && j < b.size()) {
        if (computeDistance(a[i]) < computeDistance(b[j])) {
            aux.push_back(a[i]);
            i++;
        } else if (computeDistance(a[i]) > computeDistance(b[j])) {
            aux.push_back(b[j]);
            j++;
        } else {
            aux.push_back(a[i]);
            aux.push_back(b[j]);
            i++;
            j++;
        }
    }
    while (i < a.size()) {
        aux.push_back(a[i++]);
    }
    while (j < b.size()) {
        aux.push_back(b[j++]);
    }

    return aux;
}

vector<vector<int>> mergesort(vector<vector<int>> array) {
    if (array.size() <= 1) return array;

    int m = array.size() / 2;
    vector<vector<int>> left = mergesort(slice(array, 0, m));
    vector<vector<int>> right = mergesort(slice(array, m, array.size()));

    return merge(left, right);
}

vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
    vector<vector<int>> sorted_points = mergesort(points);
    return slice(sorted_points, 0, k);
}

int main() {
    vector<vector<int>> array = {{3, 3}, {5, -1}, {-2, 4}}, res;
    int k = 2;
    res = kClosest(array, k);
    for (int i = 0; i < res.size(); i++) {
        cout<<res[i][0]<<" "<<res[i][1]<<"   ";
    }

    return 0;
}
