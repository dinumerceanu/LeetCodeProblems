#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <algorithm>

using namespace std;

int minimumJumps(vector<int>& forbidden, int a, int b, int x) {
    int LIMIT = 6000;

    vector<bool> blocked(LIMIT + 1, false);

    for (int i = 0; i < forbidden.size(); i++) {
        blocked[forbidden[i]] = true;
    }

    queue<pair<int, int>> q;
    q.push({0, 0});

    vector<vector<bool>> visited(LIMIT + 1, vector<bool>(2, false));
    visited[0][0] = true;

    int level = 0;

    while (!q.empty()) {
        int size = q.size();

        while (size--) {
            auto [pos, back] = q.front();
            q.pop();

            if (pos == x) {
                return level;
            }

            int forward = pos + a;

            if (forward <= LIMIT && !blocked[forward] && !visited[forward][0]) {
                visited[forward][0] = true;
                q.push({forward, 0});
            }

            if (!back) {
                int backward = pos - b;

                if (backward >= 0 && !blocked[backward] && !visited[backward][1]) {
                    visited[backward][1] = true;
                    q.push({backward, 1});
                }
            }
        }
        
        level++;
    }

    return -1;
}

int main() {
    int a = 3, b = 15, x = 9;
    vector<int> forbidden = {14, 4, 18, 1, 15};

    cout << minimumJumps(forbidden, a, b, x) << endl;
    return 0;
}
