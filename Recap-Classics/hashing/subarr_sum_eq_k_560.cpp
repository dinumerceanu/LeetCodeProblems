#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int subarraySum(vector<int>& nums, int k) {
    unordered_map<int, int> prefix_count;
    int sum = 0, res = 0;
    
    prefix_count[0] = 1;
    for (int i = 0; i < nums.size(); i++) {
        sum += nums[i];
        int diff = sum - k;
        if (prefix_count.find(diff) != prefix_count.end()) {
            res += prefix_count[diff];
        }
        prefix_count[sum] = prefix_count[sum] + 1;
    }

    return res;
}

int main() {
    vector<int> nums = {1,-1,1,1,1,1};
    int k = 3;

    cout << subarraySum(nums, k) << endl;

    return 0;
}
