#include <iostream>
#include <vector>
#include <map>
#include <unordered_set>

using namespace std;

vector<int> topKFrequent(vector<int>& nums, int k) {
    map<int, int> num_freq;
    map<int, unordered_set<int>, greater<int>> freq_nums;
    vector<int> res;

    for (int i = 0; i < nums.size(); i++) {
        if (num_freq.find(nums[i]) != num_freq.end()) {
            freq_nums[num_freq[nums[i]]].erase(nums[i]);
            num_freq[nums[i]] += 1;
            freq_nums[num_freq[nums[i]]].insert(nums[i]);
        } else {
            num_freq[nums[i]] = 1;
            freq_nums[num_freq[nums[i]]].insert(nums[i]);
        }
    }

    for (auto p = freq_nums.begin(); p != freq_nums.end() && k > 0; p++) {
        for (int num : p->second) {
            res.push_back(num);
            k--;
        }
    }

    return res;
}

int main() {
    vector<int> nums = {1,1,1,2,2,3};
    int k = 2;
    vector<int> res = topKFrequent(nums, k);

    for (int i = 0; i < res.size(); i++) {
        printf("%d ", res[i]);
    }
    printf("\n");

    return 0;
}
