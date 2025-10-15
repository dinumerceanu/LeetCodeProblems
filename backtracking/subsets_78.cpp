#include <iostream>
#include <vector>

using namespace std;

void backtrack(int start_index, vector<int>& nums, vector<int>& current_subset, vector<vector<int>>& results) {
    results.push_back(current_subset); 

    for (int i = start_index; i < nums.size(); i++) {
        current_subset.push_back(nums[i]);

        backtrack(i + 1, nums, current_subset, results);
        
        current_subset.pop_back();
    }
}

int main() {
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> results;
    vector<int> current_subset;
    int start_index = 0;

    backtrack(start_index, nums, current_subset, results);

    for (int i = 0; i < results.size(); i++) {
        for (int j = 0; j < results[i].size(); j++) {
            cout << results[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
