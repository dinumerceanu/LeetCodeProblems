#include <iostream>
#include <vector>

using namespace std;

int rob(vector<int>& nums) {
    if (nums.size() == 1) return nums[0];
    if (nums.size() == 2) return max(nums[0], nums[1]);
    vector<int> dp(nums.size());
    dp[0] = nums[0];
    dp[1] = nums[1];
    int max_value = max(dp[0], dp[1]);
    for (int i = 2; i < nums.size(); i++) {
        if (i > 2) {
            for (int j = 0 ; j < i - 1; j++) {
                if (dp[j] > max_value) {
                    max_value = dp[j];
                }
            }
            dp[i] = max(max_value + nums[i], nums[i] + dp[i - 2]);
        } else {
            dp[i] = nums[i] + dp[i - 2];
        }
    }
    return max(dp[nums.size() - 1], dp[nums.size() - 2]);
}

int main() {
    vector<int> nums = {1,3,1,3,100};
    cout<<rob(nums);

    return 0;
}