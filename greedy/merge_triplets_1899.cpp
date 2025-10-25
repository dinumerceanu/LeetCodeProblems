#include <iostream>
#include <vector>

using namespace std;

bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
    if (triplets.empty()) {
        return false;
    }
    
    vector<int> res = {0, 0, 0};

    for (const auto& triplet : triplets) {
        if (!(triplet[0] > target[0] || triplet[1] > target[1] || triplet[2] > target[2])) {
            res = {max(triplet[0], res[0]), max(triplet[1], res[1]), max(triplet[2], res[2])};
        }
    }

    return res == target;
}

int main() {
    vector<vector<int>> triplets = {{2,5,3},{1,8,4},{1,7,5}};
    vector<int> target = {2,7,5};

    if (mergeTriplets(triplets, target)) {
        cout << "TRUE\n";
    } else {
        cout << "FALSE\n";
    }

    return 0;
}
