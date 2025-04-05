#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct {
    int a;
    int b;
} interval;

vector<interval> makeIntervals(string s) {
    vector<interval> intervals(26, {-1, -1});

    for (int i = 0; i < s.length(); i++) {
        if (intervals[(int)(s[i] - 97)].a == -1) {
            intervals[(int)(s[i] - 97)].a = i;
            intervals[(int)(s[i] - 97)].b = i;
        } else {
            intervals[(int)(s[i] - 97)].b = i;
        }
    }

    return intervals;
}

static bool cmp(const interval &x, const interval &y) {
    return x.a < y.a;
}

vector<interval> mergeIntervals(vector<interval> intervals) {
    if (intervals.empty()) {
        return {};
    }
    sort(intervals.begin(), intervals.end(), cmp);

    vector<interval> merged;
    merged.push_back(intervals[0]);

    for (int i = 1; i < intervals.size(); ++i) {
        interval &last = merged.back();
        if (intervals[i].a <= last.b) {
            last.b = max(last.b, intervals[i].b);
        } else {
            merged.push_back(intervals[i]);
        }
    }

    return merged;
}

vector<int> partitionLabels(string s) {
    vector<interval> intervals = makeIntervals(s);
    vector<interval> merged = mergeIntervals(intervals);
    vector<int> res;
    for (int i = 0; i < merged.size(); i++) {
        if (merged[i].a != -1 && merged[i].b != -1) {
            res.push_back(merged[i].b - merged[i].a + 1);
        }
    }

    return res;
}

int main() {
    string s = {"eccbbbbdec"};
    vector<int> res = partitionLabels(s);
    for (int i = 0; i < res.size(); i++) {
        cout<<res[i]<<" ";
    }
    cout<<endl;

    return 0;
}