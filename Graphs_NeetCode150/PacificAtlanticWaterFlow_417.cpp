#include <iostream>
#include <vector>

using namespace std;

void print_matrix(vector<vector<int>> matrix) {
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[0].size(); j++) {
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
}

void dfs(vector<vector<int>> &heights, int i, int j, bool &atlantic_reached, bool &pacific_reached, vector<vector<bool>> visited) {
    int n = heights.size();
    int m = heights[0].size();
    if (atlantic_reached == true && pacific_reached == true) {
        return;
    }
    visited[i][j] = true;
    if (i == 0 || j == 0) {
        pacific_reached = true;
    }
    if (i == heights.size() - 1 || j == heights[0].size() - 1) {
        atlantic_reached = true;
    }
    if (i == 0 && j == heights[0].size() - 1) {
        pacific_reached = true;
        atlantic_reached = true;
        return;
    }
    if (i == heights.size() - 1 && j == 0) {
        pacific_reached = true;
        atlantic_reached = true;
        return;
    }
    if (i + 1 < n && heights[i + 1][j] <= heights[i][j] && visited[i + 1][j] == false)
        dfs(heights, i + 1, j, atlantic_reached, pacific_reached, visited);
    if (i - 1 >= 0 && heights[i - 1][j] <= heights[i][j] && visited[i - 1][j] == false)
        dfs(heights, i - 1, j, atlantic_reached, pacific_reached, visited);
    if (j + 1 < m && heights[i][j + 1] <= heights[i][j] && visited[i][j + 1] == false)
        dfs(heights, i, j + 1, atlantic_reached, pacific_reached, visited);
    if (j - 1 >= 0 && heights[i][j - 1] <= heights[i][j] && visited[i][j - 1] == false)
        dfs(heights, i, j - 1, atlantic_reached, pacific_reached, visited);
}

vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
    vector<vector<int>> solution;
    int n = heights.size();
    int m = heights[0].size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            bool atlantic_reached = false;
            bool pacific_reached = false;
            vector<vector<bool>> visited(n, vector<bool>(m, false));
            dfs(heights, i, j, atlantic_reached, pacific_reached, visited);
            if (atlantic_reached && pacific_reached) {
                solution.push_back({i, j});
            }
        }
    }
    return solution;
}

int main() {
    // vector<vector<int>> heights = {{1,2,2,3,5},{3,2,3,4,4},{2,4,5,3,1},{6,7,1,4,5},{5,1,1,2,4}};
    vector<vector<int>> heights = {{1}};
    print_matrix(pacificAtlantic(heights));

    return 0;
}