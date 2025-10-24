#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> merge_intervals(vector<vector<int>>& intervals) {
    vector<vector<int>> res;
    vector<int> current_interval;

    if (intervals.size() < 2) {
        return intervals;
    }

    sort(intervals.begin(), intervals.end(), 
            [](const vector<int>& a, const vector<int>& b) {return a[0] < b[0];});

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

vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
    intervals.push_back(newInterval);

    vector<vector<int>> res = merge_intervals(intervals);

    return res;
}

int main() {
    vector<vector<int>> intervals = {{1, 5}};
    vector<int> newInterval = {2, 7};

    vector<vector<int>> res = insert(intervals, newInterval);

    for (const auto& interval : res) {
        cout << interval[0] << " " << interval[1] << endl;
    }

    return 0;
}
