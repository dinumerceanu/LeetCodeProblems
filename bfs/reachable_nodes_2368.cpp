#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
    vector<vector<int>> adj(n);
    vector<int> visited(n, 0);

    for (int i = 0; i < restricted.size(); i++) {
        visited[restricted[i]] = 2;
    }

    for (int i = 0; i < edges.size(); i++) {
        adj[edges[i][0]].push_back(edges[i][1]);
        adj[edges[i][1]].push_back(edges[i][0]);
    }

    int canBeVisited = 0;
    queue<int> q;
    q.push(0);

    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        canBeVisited++;
        visited[curr] = 1;

        for (const auto& neighbor : adj[curr]) {
            if (visited[neighbor] == 0) {
                q.push(neighbor);
            }
        }
    }

    return canBeVisited;
}

int main() {
    int n = 7;
    vector<vector<int>> edges = {{0, 1}, {1, 2}, {3, 1}, {4, 0}, {0, 5}, {5, 6}};
    vector<int> restricted = {4, 5};

    cout << reachableNodes(n, edges, restricted) << endl;

    return 0;
}
