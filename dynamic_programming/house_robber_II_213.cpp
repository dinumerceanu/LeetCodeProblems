#include <iostream>
#include <vector>

using namespace std;

int rob_aux(vector<int>& nums) {
    int n = nums.size();
    vector<int> dp(n + 2);
    dp[0] = 0;
    dp[1] = 0;

    for (int i = 2; i < n + 2; i++) {
        dp[i] = max(dp[i - 2] + nums[i - 2], dp[i - 1]);
    }

    return dp[n + 1];
}

int rob(vector<int>& nums) {
    if (nums.size() == 1) {
        return nums[0];
    }
    
    vector<int> all_but_first(nums.begin() + 1, nums.end());
    vector<int> all_but_last(nums.begin(), nums.end() - 1);
    
    return max(rob_aux(all_but_first), rob_aux(all_but_last));
}

int main() {
    vector<int> nums = {2,3,2};

    cout << rob(nums) << endl;

    return 0;
}
