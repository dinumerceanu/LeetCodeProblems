#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct orange {
    int x, y;
};

void print_grid(vector<vector<int>> &grid) {
    for (auto line : grid) {
        for (auto elem : line) {
            cout << elem << " ";
        }
        cout<<endl;
    }
}

void print_q(queue<orange> q) {
    while (!q.empty()) {
        cout << "{ " << q.front().x << " " << q.front().y <<"} ";
        q.pop();
    }
    cout<<endl;
}

int bfs(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    queue<struct orange> q;
    q.push({0, 0});
    int for_entries = -1;
    int neighbors = 1, neighbors2 = 0;
    for (int i = 0; i < neighbors && !q.empty(); i++) {
        // print_q(q);
        struct orange elem = q.front();
        // cout<<"current elem: {"<<elem.x<<" "<<elem.y<<"}"<<endl;
        q.pop();
        grid[elem.x][elem.y] = 2;
        if (elem.x + 1 < n && grid[elem.x + 1][elem.y] == 1) {
            neighbors2++;
            grid[elem.x + 1][elem.y] = 2;
            q.push({elem.x + 1, elem.y});
        }
        if (elem.x - 1 >= 0 && grid[elem.x - 1][elem.y] == 1) {
            neighbors2++;
            grid[elem.x - 1][elem.y] = 2;
            q.push({elem.x - 1, elem.y});
        }
        if (elem.y + 1 < m && grid[elem.x][elem.y + 1] == 1) {
            neighbors2++;
            grid[elem.x][elem.y + 1] = 2;
            q.push({elem.x, elem.y + 1});
        }
        if (elem.y - 1 >= 0 && grid[elem.x][elem.y - 1] == 1) {
            neighbors2++;
            grid[elem.x][elem.y - 1] = 2;
            q.push({elem.x, elem.y - 1});
        }
        if (i == neighbors - 1) {
            // print_grid(grid);
            // cout<<endl;
            neighbors = neighbors2;
            // cout<<"neighbors2: "<<neighbors2<<endl;
            neighbors2 = 0;
            i = -1;
            for_entries++;
            // cout<<"return value: "<<for_entries<<endl;
        }
    }
    return for_entries;

}

int orangesRotting(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    queue<struct orange> q;
    q.push({0, 0});
    int for_entries = -1;
    int neighbors = 1, neighbors2 = 0;
    for (int i = 0; i < neighbors && !q.empty(); i++) {
        // print_q(q);
        struct orange elem = q.front();
        // cout<<"current elem: {"<<elem.x<<" "<<elem.y<<"}"<<endl;
        q.pop();
        grid[elem.x][elem.y] = 2;
        if (elem.x + 1 < n && grid[elem.x + 1][elem.y] == 1) {
            neighbors2++;
            grid[elem.x + 1][elem.y] = 2;
            q.push({elem.x + 1, elem.y});
        }
        if (elem.x - 1 >= 0 && grid[elem.x - 1][elem.y] == 1) {
            neighbors2++;
            grid[elem.x - 1][elem.y] = 2;
            q.push({elem.x - 1, elem.y});
        }
        if (elem.y + 1 < m && grid[elem.x][elem.y + 1] == 1) {
            neighbors2++;
            grid[elem.x][elem.y + 1] = 2;
            q.push({elem.x, elem.y + 1});
        }
        if (elem.y - 1 >= 0 && grid[elem.x][elem.y - 1] == 1) {
            neighbors2++;
            grid[elem.x][elem.y - 1] = 2;
            q.push({elem.x, elem.y - 1});
        }
        if (i == neighbors - 1) {
            // print_grid(grid);
            cout<<endl;
            neighbors = neighbors2;
            // cout<<"neighbors2: "<<neighbors2<<endl;
            neighbors2 = 0;
            i = -1;
            for_entries++;
            // cout<<"return value: "<<for_entries<<endl;
        }
    }
    int fresh = 0, rotten = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 1) {
                fresh++;
            }
            if (grid[i][j] == 2) {
                rotten++;
            }
        }
    }
    cout<<"rotten: "<<rotten<<endl;
    if (rotten == 0) {
        return 0;
    }
    if (fresh != 0) {
        return -1;
    }
    // return for_entries;
}

int main() {
    // vector<vector<int>> grid = {{2, 1, 1}, {1, 1, 0}, {0, 1, 1}};
    vector<vector<int>> grid = {{1}};
    cout<<orangesRotting(grid);
    // cout<<bfs(grid);

    return 0;
}