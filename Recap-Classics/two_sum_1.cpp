#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

//O(n^2)
vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> res;

    for (int i = 0; i < nums.size() - 1; i++) {
        for (int j = i + 1; j < nums.size(); j++) {
            if (nums[i] + nums[j] == target) {
                res.push_back(i);
                res.push_back(j);
                return res;
            }
        }
    }

    return res;
}

//O(n)
vector<int> twoSum2(vector<int>& nums, int target) {
    vector<int> res;
    unordered_map<int, int> map;

    for (int i = 0; i < nums.size(); i++) {
        int diff = target - nums[i];
        if (map.find(diff) == map.end()) {
            map.insert({nums[i], i});
        } else {
            res.push_back(map.at(diff));
            res.push_back(i);
        }
    }

    return res;
}

int main() {
    vector<int> input = {3, 2, 4};
    int target = 6;
    vector<int> res = twoSum2(input, target);
    for (int i = 0; i < res.size(); i++) {
        printf("%d ", res[i]);
    }
    printf("\n");
    return 0;
}
