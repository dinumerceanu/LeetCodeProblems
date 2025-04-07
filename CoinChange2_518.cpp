#include <iostream>
#include <vector>

using namespace std;

int change(int amount, vector<int>& coins) {
    using ull = unsigned long long;
    vector<ull> dp(amount + 1, 0);
    dp[0] = 1;

    for (int coin : coins) {
        for (int i = coin; i <= amount; ++i) {
            dp[i] += dp[i - coin];
        }
    }

    return dp[amount];
}

int main() {
    int amount = 5;
    vector<int> coins = {1, 2, 5};
    cout<<change(amount, coins)<<endl;
    return 0;
}
