#include <iostream>
#include <vector>

using namespace std;

int coinChange(vector<int>& coins, int amount) {
    vector<int> dp(amount + 1);
    dp[0] = 0;
    dp[amount] = -1;

    for (int i = 1; i <= amount; i++) {
        int minVal = 1e9;
        for (int j = 0; j < coins.size(); j++) {
            if (i - coins[j] >= 0) {
                minVal = min(minVal, dp[i - coins[j]]);
            }
        }

        dp[i] = 1 + minVal;
    }

    return dp[amount] == 1e9 + 1 ? -1 : dp[amount];
}

int main() {
    vector<int> coins = {2};
    int amount = 3;

    cout << coinChange(coins, amount) << endl;

    return 0;
}
