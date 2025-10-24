#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int eraseOverlapIntervals(vector<vector<int>>& intervals) {
    if (intervals.empty()) {
        return 0;
    }

    sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {return a[1] < b[1];});

    int count_non_overlapping = 0; 
    long long last_end = LLONG_MIN; 

    for (const auto& interval : intervals) {
        int current_start = interval[0];

        if (current_start >= last_end) {
            count_non_overlapping++;
            last_end = interval[1];
        }
    }

    return intervals.size() - count_non_overlapping;
}

int main() {
    vector<vector<int>> intervals = {{1, 2}, {2, 3}, {3, 4}, {1, 3}};

    cout << eraseOverlapIntervals(intervals) << endl;

    return 0;
}
