#include <iostream>
#include <vector>

using namespace std;

bool canPartition(vector<int>& nums) {
    int sum = 0;
    for (int x : nums) sum += x;

    if (sum % 2 != 0) return false;
    int target = sum / 2;

    vector<bool> dp(target + 1, false);
    dp[0] = true;

    for (int num : nums) {
        for (int i = target; i >= num; --i) {
            dp[i] = dp[i] || dp[i - num];
        }
    }

    return dp[target];
}

int main() {
    vector<int> nums = {1, 5, 11, 5};
    cout<<canPartition(nums);

    return 0;
}