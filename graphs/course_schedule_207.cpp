#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool is_kahn_sort_possible(int n, vector<vector<int>>& adj, vector<int>& in_degrees) {
    int count = 0;
    queue<int> q;

    for (int i = 0; i < n; i++) {
        if (in_degrees[i] == 0) {
            q.push(i);
        }
    }

    while (!q.empty()) {
        int first = q.front();
        q.pop();

        count++;

        for (int neighbor : adj[first]) {
            if (--in_degrees[neighbor] == 0) {
                q.push(neighbor);
            }
        }
    }

    return count == n;
}

bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    vector<vector<int>> adj(numCourses);
    vector<int> in_degrees(numCourses, 0);

    for (const auto& prerequisit : prerequisites) {
        adj[prerequisit[1]].push_back(prerequisit[0]);
        in_degrees[prerequisit[0]]++;
    }

    return is_kahn_sort_possible(numCourses, adj, in_degrees);
}

int main() {
    int numCourses = 2;
    vector<vector<int>> prereqs = {{1, 0}, {0, 1}};

    if (canFinish(numCourses, prereqs)) {
        cout << "true\n";
    } else {
        cout << "false\n";
    }

    return 0;
}
