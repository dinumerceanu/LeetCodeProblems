#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<vector<int>> twoSum2(vector<int>& nums, int target, int start) {
    unordered_map<int, int> map;
    vector<vector<int>> pairs;
    
    for (int i = start; i < nums.size(); i++) {
        int diff = target - nums[i];
        if (map.find(diff) != map.end()) {
            pairs.push_back({map[diff], i});
        }
        map[nums[i]] = i;
    }
    return pairs;
}


vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> res;
    sort(nums.begin(), nums.end());
    
    for (int i = 0; i < nums.size(); i++) {
        if (i > 0 && nums[i] == nums[i - 1]) {
            continue;
        }
        
        int target = -nums[i];
        vector<vector<int>> pairs = twoSum2(nums, target, i + 1);
        
        for (auto &p : pairs) {
            vector<int> triplet = {nums[i], nums[p[0]], nums[p[1]]};
            sort(triplet.begin(), triplet.end());
            
            if (res.empty() || triplet != res.back()) {
                res.push_back(triplet);
            }
        }
    }

    return res;
}

int main() {
    vector<int> input = {-1,0,1,2,-1,-4};
    vector<vector<int>> res = threeSum(input);
    for (int i = 0; i < res.size(); i++) {
        for (int j = 0; j < res[i].size(); j++) {
            printf("%d ", res[i][j]);
        }
        printf("\n");
    }

    return 0;
}
