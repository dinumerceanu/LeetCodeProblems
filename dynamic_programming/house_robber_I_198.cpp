#include <iostream>
#include <vector>

using namespace std;

int rob(vector<int>& nums) {
    int n = nums.size();
    vector<int> dp(n + 2);
    dp[0] = 0;
    dp[1] = 0;

    for (int i = 2; i < n + 2; i++) {
        dp[i] = max(dp[i - 2] + nums[i - 2], dp[i - 1]);
    }

    return dp[n + 1];
}

int main() {
    vector<int> nums = {1,2,3,1};

    cout << rob(nums) << endl;

    return 0;
}
