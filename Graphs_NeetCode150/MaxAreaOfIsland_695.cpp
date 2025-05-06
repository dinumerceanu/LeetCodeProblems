#include <iostream>
#include <vector>
#include <fstream>
#include <queue>
#include <stack>

using namespace std;

void dfs(vector<vector<int>> &grid, int i, int j, int &size) {
    int n = grid.size();
    int m = grid[0].size();
    
    if (i >= n || i < 0 || j >= m || j < 0 || grid[i][j] == 0) {
        return;
    }

    grid[i][j] = 0;
    size++;
    dfs(grid, i + 1, j, size);
    dfs(grid, i - 1, j, size);
    dfs(grid, i, j + 1, size);
    dfs(grid, i, j - 1, size);
}

int maxAreaOfIsland(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    int size = 0, max_size = 0;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 1) {
                size = 0;
                dfs(grid, i, j, size);
                if (size > max_size) {
                    max_size = size;
                }
            }
        }
    }
    
    return max_size;
}

int main() {
    ifstream fin("file.in");
    ofstream fout("file.out");

    int n, m;
    fin >> n >> m;
    vector<vector<int>> grid(n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int c;
            fin>>c;
            grid[i].push_back(c);
        }
    }

    fout<<maxAreaOfIsland(grid);

    return 0;
}
