#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int change(int amount, vector<int>& coins) {
    int n = coins.size();
    sort(coins.begin(), coins.end());
    vector<vector<unsigned long long>> dp(n + 1, vector<unsigned long long>(amount + 1, 0));

    for (int i = 0; i < n; i++) {
        dp[i][0] = 1;
    }

    for (int j = 1; j <= amount; j++) {
        for (int i = n - 1; i >= 0; i--) {
            if (j - coins[i] < 0) {
                dp[i][j] = 0;
            } else {
                dp[i][j] = dp[i + 1][j] + dp[i][j - coins[i]];
            }
        }
    }

    return dp[0][amount];
}

int main() {
    vector<int> coins = {99,1};
    int amount = 100;

    cout << change(amount, coins) << endl;

    return 0;
}
