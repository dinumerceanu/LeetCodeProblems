#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> kahn(int n, vector<vector<int>>& adj, vector<int>& in_degrees) {
    vector<int> sorted;
    vector<int> empty;
    queue<int> q;

    for (int i = 0; i < n; i++) {
        if (in_degrees[i] == 0) {
            q.push(i);
        }
    }

    while (!q.empty()) {
        int first = q.front();
        q.pop();

        sorted.push_back(first);

        for (int neighbor : adj[first]) {
            if (--in_degrees[neighbor] == 0) {
                q.push(neighbor);
            }
        }
    }

    if (sorted.size() == n) {
        return sorted;
    } else {
        return empty;
    }
}

vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    vector<vector<int>> adj(numCourses);
    vector<int> in_degrees(numCourses, 0);

    for (const auto& prerequisit : prerequisites) {
        adj[prerequisit[1]].push_back(prerequisit[0]);
        in_degrees[prerequisit[0]]++;
    }

    return kahn(numCourses, adj, in_degrees);
}

int main() {
    int numCourses = 4;
    vector<vector<int>> prereqs = {{1, 0}, {2, 0}, {3, 1}, {3, 2}};

    vector<int> order = findOrder(numCourses, prereqs);

    for (int i = 0; i < order.size(); i++) {
        cout << order[i] << " ";
    }
    cout << endl;

    return 0;
}
