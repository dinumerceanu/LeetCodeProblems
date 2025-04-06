#include <iostream>
#include <vector>

using namespace std;

int lengthOfLIS(vector<int>& nums) {
    int n = nums.size();
    if (n == 0) return 0;

    vector<int> dp(n, 1);

    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (nums[j] < nums[i]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    int sol = 0;
    for (int len : dp)
        sol = max(sol, len);
 
	return sol;
}

int main() {
    vector<int> nums = {0,1,0,3,2,3};
    cout<<lengthOfLIS(nums);

    return 0;
}