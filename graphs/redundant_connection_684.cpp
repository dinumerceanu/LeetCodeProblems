#include <iostream>
#include <vector>

using namespace std;

int find(int x, vector<int>& parent) {
    if (parent[x] != x) {
        parent[x] = find(parent[x], parent);
    }

    return parent[x];
}

void unite(int x, int y, vector<int>& parent) {
    parent[find(y, parent)] = find(x, parent);
}

vector<int> findRedundantConnection(vector<vector<int>>& edges) {
    int n = edges.size();
    vector<int> parent(n + 1);
    vector<int> res;

    for (int i = 0; i <= n; i++) {
        parent[i] = i;
    }

    for (const auto& edge : edges) {
        if (find(edge[0], parent) == find(edge[1], parent)) {
            res = edge;
        } else {
            unite(edge[0], edge[1], parent);
        }
    }

    return res;
}

int main() {
    vector<vector<int>> edges = {{1,2}, {2,3}, {3,4}, {1,4}, {1, 5}};

    vector<int> res = findRedundantConnection(edges);

    cout << res[0] << " " << res[1] << endl;

    return 0;
}
