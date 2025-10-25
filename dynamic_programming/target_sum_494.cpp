#include <iostream>
#include <vector>

using namespace std;

int findTargetSumWays(vector<int>& nums, int target) {
    int sum = 0, n = nums.size();

    for (int i = 0; i < n; i++) {
        sum += nums[i];
    }

    if (target > sum || target < -sum) {
        return 0;
    }

    vector<vector<int>> dp(n + 1, vector<int>(2 * sum + 1, 0));
    dp[0][sum] = 1;

    for (int i = 1; i <= n; i++) {
        int curr_num = nums[i - 1];

        for (int j = 0; j < 2 * sum + 1; j++) {
            if (j - curr_num >= 0) {
                dp[i][j] += dp[i - 1][j - curr_num];
            }

            if (j + curr_num < 2 * sum + 1) {
                dp[i][j] += dp[i - 1][j + curr_num];
            }
        }
    }

    return dp[n][target + sum];
}

int main() {
    vector<int> nums = {1,1,1,1,1};
    int target = 3;

    cout << findTargetSumWays(nums, target) << endl;

    return 0;
}
