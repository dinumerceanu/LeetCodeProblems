#include <iostream>
#include <vector>

using namespace std;

void backtracking(vector<int>& nums, vector<vector<int>>& perms, vector<bool>& used, vector<int>& current) {
    if (current.size() == nums.size()) {
        perms.push_back(current);
        return;
    }

    for (int i = 0; i < nums.size(); i++) {
        if (used[i] == false) {
            current.push_back(nums[i]);
            used[i] = true;

            backtracking(nums, perms, used, current);

            used[i] = false;
            current.pop_back();
        }
    }
}

int main() {
    vector<int> nums = {1, 2, 3, 4, 5};
    vector<vector<int>> perms;
    vector<bool> used(nums.size(), false);
    vector<int> current;

    backtracking(nums, perms, used, current);

    for (int i = 0; i < perms.size(); i++) {
        for (int j = 0; j < perms[i].size(); j++) {
            cout << perms[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
