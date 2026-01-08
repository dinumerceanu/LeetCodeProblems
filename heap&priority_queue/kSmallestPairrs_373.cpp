#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
    vector<vector<int>> res;
    if (nums1.empty() || nums2.empty() || k <= 0) return res;

    typedef pair<int, pair<int, int>> Node;
    priority_queue<Node, vector<Node>, greater<Node>> pq;

    for (int i = 0; i < nums1.size() && i < k; i++) {
        pq.push({nums1[i] + nums2[0], {i, 0}});
    }

    while (k-- > 0 && !pq.empty()) {
        auto top = pq.top();
        pq.pop();

        int i = top.second.first;
        int j = top.second.second;

        res.push_back({nums1[i], nums2[j]});

        if (j + 1 < nums2.size()) {
            pq.push({nums1[i] + nums2[j + 1], {i, j + 1}});
        }
    }

    return res;
}

int main() {
    vector<int> nums1 = {1, 7, 11};
    vector<int> nums2 = {2, 4, 100};
    int k = 3;

    vector<vector<int>> res = kSmallestPairs(nums1, nums2, k);
    for (const auto& row : res) {
        for (int x : row) {
            cout << x << " ";
        }
        cout << endl;
    }

    return 0;
}
