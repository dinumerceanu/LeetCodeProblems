#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int maximumJumps(vector<int>& nums, int target) {
    int n = nums.size();
    
    if (n == 0) {
        return -1;
    }

    if (n == 1) {
        return 0;
    }

    vector<vector<int>> adj(n);

    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            long diff = (long)nums[j] - (long)nums[i];
            if (diff <= target && diff >= -target) {
                adj[i].push_back(j);
            }
        }
    }

    vector<int> best(n, INT_MIN);
    queue<pair<int,int>> q;
    q.push({0, 0});
    best[0] = 0;

    int maxJumpsToLast = INT_MIN;

    while (!q.empty()) {
        auto [curr, jumps] = q.front();
        q.pop();

        if (curr == n - 1) {
            if (jumps > maxJumpsToLast) maxJumpsToLast = jumps;
        }

        for (int nxt : adj[curr]) {
            int nxtJumps = jumps + 1;

            if (nxtJumps > best[nxt]) {
                best[nxt] = nxtJumps;
                q.push({nxt, nxtJumps});
            }
        }
    }

    if (maxJumpsToLast == INT_MIN) {
        return -1;
    }
    
    return maxJumpsToLast;
}

int main() {
    vector<int> nums = {1,3,6,4,1,2};
    int target = 3;

    cout << maximumJumps(nums, target) << endl;

    return 0;
}
