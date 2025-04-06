#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int coinChange(vector<int>& coins, int amount) {
    vector<int> dp(1 + amount, 1e9);
    dp[0] = 0;
    for (int i = 0; i < coins.size(); ++i) {
        for (int curr = 0; curr + coins[i] <= amount; ++curr) {
            dp[curr + coins[i]] = min(dp[curr + coins[i]], dp[curr] + 1);
        }
    }
    if (dp[amount] == 1e9)
        return -1;
    return dp[amount];
}

int main() {
    vector<int> coins = {1, 2, 5};
    int amount = 11;
    cout<<coinChange(coins, amount);

    return 0;
}