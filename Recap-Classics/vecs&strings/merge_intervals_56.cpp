#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> merge(vector<vector<int>>& intervals) {
    vector<vector<int>> res;
    vector<int> current_interval;

    if (intervals.size() < 2) {
        return intervals;
    }

    sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {return a[0] < b[0];});

    current_interval = intervals[0];
    for (int i = 1; i < intervals.size(); i++) {
        if (current_interval[1] >= intervals[i][0]) {
            current_interval[1] = max(current_interval[1], intervals[i][1]);
            if (i == intervals.size() - 1) {
                res.push_back(current_interval);
            }
        } else {
            res.push_back(current_interval);
            current_interval = intervals[i];
            if (i == intervals.size() - 1) {
                res.push_back(intervals[intervals.size() - 1]);
            }
        }
    }

    return res;
}

int main() {
    vector<vector<int>> intervals = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    vector<vector<int>> res = merge(intervals);

    for (int i = 0; i < res.size(); i++) {
        for (int j = 0; j < res[i].size(); j++) {
            printf("%d ", res[i][j]);
        }
        printf("\n");
    }

    return 0;
}
