#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

bool canPartition(vector<int>& nums) {
    unordered_set<int> set;
    set.insert(0);
    int sum = 0;

    for (int i = nums.size() - 1; i >=0; i--) {
        sum += nums[i];
        unordered_set<int> aux_set = set;
        for (int j : set) {
            if (set.find(j + nums[i]) == set.end()) {
                aux_set.insert(j + nums[i]);
            }
        }
        set.swap(aux_set);
    }

    if (sum % 2 == 1) {
        return false;
    }

    if (set.find(sum / 2) == set.end()) {
        return false;
    }

    return true;
}

int main() {
    vector<int> nums = {1,5,11,5};

    cout << canPartition(nums) << endl;

    return 0;
}
