#include <iostream>
#include <vector>

using namespace std;

bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
    if (triplets.empty()) return false;
    vector<int> res = {0, 0, 0};
    for (int i = 0; i < triplets.size(); i++) {
        if (!(triplets[i][0] > target[0] || triplets[i][1] > target[1] || triplets[i][2] > target[2]))
            res = {max(res[0], triplets[i][0]), max(res[1], triplets[i][1]), max(res[2], triplets[i][2])};
    }
    return res == target;
}

int main() {
    vector<vector<int>> triplets = {{2, 6, 6}, {10, 5, 1}, {8, 9, 2}, {7, 2, 9}, {5, 10, 6}};
    vector<int> target = {10, 6, 6};
    cout<<mergeTriplets(triplets, target);

    return 0;
}